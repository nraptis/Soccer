#include "Soccer_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void Soccer_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xFDEB4457D8FA4765ULL + 0xEFA4B5CEC9BBE644ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x8CA197BF2A9A6D23ULL + 0x95EC0D433552ECEFULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xA37D25D6DA03E7EBULL + 0xB1C16F9583C73599ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x81FEE3C3ECFECCB7ULL + 0xBEBA8F82B36881C4ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xC61669BDC381C161ULL + 0xC06EF1966BE6E4DEULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xE0542EB149A46AC9ULL + 0xA080886B3396D52FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xA87E854EFEC5DAD5ULL + 0xB0E43EA97AA5BA75ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x848AC7B556A9403FULL + 0xDFBC52E69F6385CFULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 37U) ^ RotL64(aNonceWordC, 5U)) ^ RotL64(aNonceWordG, 28U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 2736U)) & S_BLOCK1], 47U) ^ RotL64(mSnow[((aIndex + 2397U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 27U) ^ RotL64(aNonceWordH, 3U)) ^ RotL64(aNonceWordA, 11U));
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 2718U)) & S_BLOCK1], 41U) ^ RotL64(mSnow[((S_BLOCK1 - aIndex + 2443U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCross, 44U)) + (RotL64(aCarry, 5U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (((aWandererF + RotL64(aScatter, 51U)) + RotL64(aCarry, 11U)) + 3339283916456813609U) + RotL64(aNonceWordH, 15U);
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 53U)) + RotL64(aCarry, 47U)) + 11339086426180649584U;
            aOrbiterH = ((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 57U)) + 16819191669329316585U;
            aOrbiterG = ((aWandererB + RotL64(aIngress, 21U)) + 8361916937762630725U) + RotL64(aNonceWordD, 21U);
            aOrbiterJ = (aWandererD + RotL64(aScatter, 27U)) + 18031328374429899857U;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 60U)) + 18261756894092897276U) + aOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aCross, 35U)) + 4250319792907645666U;
            aOrbiterK = (aWandererH + RotL64(aPrevious, 11U)) + 1492411503643460886U;
            aOrbiterA = (aWandererI + RotL64(aIngress, 43U)) + 17369549067879344180U;
            aOrbiterI = (aWandererA + RotL64(aPrevious, 18U)) + 7301713524358676722U;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 39U)) + 2985193736033012535U) + aOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 14086975808140927408U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 10390516547834639800U;
            aOrbiterH = RotL64((aOrbiterH * 11441293212275890819U), 5U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterJ) + 18205555540941493267U) + aOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1]) + RotL64(aNonceWordA, 41U);
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 16967799565443938873U;
            aOrbiterF = RotL64((aOrbiterF * 3009081009044782443U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 9209505304067579944U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 3522631966146762306U;
            aOrbiterB = RotL64((aOrbiterB * 3441982898533162599U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 8811497120829041188U) + aOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 14707301680850257294U;
            aOrbiterG = RotL64((aOrbiterG * 11383709499376464085U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 10080595991787801029U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 6822892187784299166U;
            aOrbiterE = RotL64((aOrbiterE * 7417016898027778287U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 1981637172055758689U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 16463077485583119324U;
            aOrbiterA = RotL64((aOrbiterA * 2876782050665869121U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 8383837717361569465U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 2788511294985017326U;
            aOrbiterC = RotL64((aOrbiterC * 2809163242875130677U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 3529607472855930041U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 8850940802020173766U;
            aOrbiterD = RotL64((aOrbiterD * 7821450253655655943U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 7469160295100147267U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 16973986572163482061U;
            aOrbiterJ = RotL64((aOrbiterJ * 15660743778376905023U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 12371372942863279718U) + RotL64(aNonceWordF, 55U);
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 12098525148034303633U) ^ aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11234127652230231751U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 5138683482859889480U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 3339283916456813609U;
            aOrbiterI = RotL64((aOrbiterI * 10975353228235695455U), 21U);
            //
            aIngress = RotL64(aOrbiterH, 27U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 23U));
            aIngress = aIngress + (RotL64(aOrbiterD, 6U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + RotL64(aOrbiterK, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 5U)) + aOrbiterH) + RotL64(aNonceWordB, 30U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 23U) + aOrbiterJ) + RotL64(aOrbiterA, 46U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 46U) + RotL64(aOrbiterA, 39U)) + aOrbiterB) + aWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 5U) + RotL64(aOrbiterE, 51U)) + aOrbiterH) + aWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 21U) + aOrbiterB) + RotL64(aOrbiterJ, 23U));
            aWandererF = aWandererF + (((RotL64(aIngress, 37U) + RotL64(aOrbiterF, 19U)) + aOrbiterJ) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterA, 54U));
            aWandererC = aWandererC + ((((RotL64(aCross, 40U) + aOrbiterC) + RotL64(aOrbiterB, 27U)) + RotL64(aCarry, 27U)) + RotL64(aNonceWordG, 25U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 53U) + aOrbiterH) + RotL64(aOrbiterG, 3U));
            aWandererG = aWandererG + ((RotL64(aCross, 51U) + aOrbiterG) + RotL64(aOrbiterI, 21U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterI, 11U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 30U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererI, 35U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 57U) ^ RotL64(aNonceWordA, 39U)) ^ RotL64(aNonceWordH, 11U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 6079U)) & S_BLOCK1], 21U) ^ RotL64(mSnow[((aIndex + 5611U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 41U) ^ RotL64(aNonceWordB, 11U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 6420U)) & S_BLOCK1], 29U) ^ RotL64(mSource[((aIndex + 6864U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aPrevious, 51U)) + (RotL64(aCarry, 24U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (((aWandererJ + RotL64(aPrevious, 3U)) + RotL64(aCarry, 19U)) + 12775735908960052604U) + RotL64(aNonceWordA, 27U);
            aOrbiterJ = (aWandererI + RotL64(aIngress, 46U)) + 11791373812080296887U;
            aOrbiterA = (((aWandererE + RotL64(aScatter, 27U)) + RotL64(aCarry, 53U)) + 5537362877706057303U) + RotL64(aNonceWordG, 14U);
            aOrbiterK = ((aWandererA + RotL64(aCross, 43U)) + RotL64(aCarry, 47U)) + 2023912048504189380U;
            aOrbiterG = (aWandererC + RotL64(aScatter, 29U)) + 17668828109963766893U;
            aOrbiterH = ((aWandererF + RotL64(aIngress, 57U)) + 558908629933941224U) + aOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = (aWandererB + RotL64(aPrevious, 37U)) + 1479633119685446888U;
            aOrbiterC = (aWandererG + RotL64(aCross, 21U)) + 15460320397843364063U;
            aOrbiterF = (aWandererH + RotL64(aScatter, 5U)) + 10059749397555469054U;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 41U)) + 9987633811929693924U) + aOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = (aWandererD + RotL64(aIngress, 10U)) + 10087337844580228269U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 4446204415503364254U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 15106063243302192717U) ^ aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13273756657334709803U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 9430197906134676162U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 1226048679997253363U;
            aOrbiterJ = RotL64((aOrbiterJ * 14247538885252664127U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 10611580584157624739U) + RotL64(aNonceWordD, 41U);
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 3137391249289641509U) ^ aOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5462682413239873181U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 9327201928815412810U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 7890659377013147073U;
            aOrbiterE = RotL64((aOrbiterE * 13827717178378062047U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 10675114832750356941U) + aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 8804440385852327267U;
            aOrbiterF = RotL64((aOrbiterF * 8520671775587260601U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 12871947817782057116U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 11015991745792051390U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17152451500505815031U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 6320437975845673731U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 702457937087191287U;
            aOrbiterK = RotL64((aOrbiterK * 17491257114676739589U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 16629064896250312921U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 6054107387816339103U;
            aOrbiterH = RotL64((aOrbiterH * 6983767878966747219U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 13274874838094190290U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 12211422735294360321U;
            aOrbiterC = RotL64((aOrbiterC * 5113738196151089817U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 15338616110718583619U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 1475787183754511373U;
            aOrbiterD = RotL64((aOrbiterD * 10904607643785840003U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 15486810401396777742U) + RotL64(aNonceWordB, 45U);
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 12775735908960052604U;
            aOrbiterI = RotL64((aOrbiterI * 7478156942468930207U), 43U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterE, 27U);
            aIngress = aIngress + (RotL64(aOrbiterA, 60U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 53U));
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aCross, 54U) + aOrbiterC) + RotL64(aOrbiterB, 39U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 41U)) + aOrbiterH);
            aWandererB = aWandererB + ((RotL64(aScatter, 37U) + RotL64(aOrbiterH, 5U)) + aOrbiterC);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 35U)) + aOrbiterE);
            aWandererF = aWandererF + (((RotL64(aScatter, 42U) + aOrbiterB) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterG, 56U)) + aOrbiterA) + aWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 11U)) + aOrbiterA) + RotL64(aNonceWordE, 15U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterJ, 43U)) + aOrbiterK);
            aWandererD = aWandererD + (((RotL64(aCross, 39U) + RotL64(aOrbiterE, 51U)) + aOrbiterD) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterF, 26U)) + aOrbiterH) + aWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 23U)) + aOrbiterI) + RotL64(aNonceWordC, 19U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 14U));
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 54U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 13U) ^ RotL64(aNonceWordB, 47U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 13511U)) & S_BLOCK1], 57U) ^ RotL64(mSnow[((aIndex + 13960U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 42U) ^ RotL64(aNonceWordC, 21U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11734U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 13091U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 30U) + RotL64(aPrevious, 57U)) + (RotL64(aIngress, 43U) ^ RotL64(aCarry, 13U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererE + RotL64(aCross, 60U)) + 17264605017518259932U;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 47U)) + RotL64(aCarry, 37U)) + 15209184354580778643U;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 29U)) + 3299527965014731384U) + RotL64(aNonceWordD, 22U);
            aOrbiterB = (((aWandererA + RotL64(aPrevious, 57U)) + 16293096431816127821U) + aOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1]) + RotL64(aNonceWordH, 37U);
            aOrbiterF = (aWandererJ + RotL64(aScatter, 37U)) + 11031983436878828337U;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 24U)) + 9188018632448236358U;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 39U)) + 13420816400363406556U) + aOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aIngress, 41U)) + 2485063384097917101U;
            aOrbiterI = (aWandererK + RotL64(aScatter, 3U)) + 3089135816938128264U;
            aOrbiterE = ((aWandererI + RotL64(aCross, 19U)) + RotL64(aCarry, 43U)) + 10730544971770435788U;
            aOrbiterC = ((aWandererD + RotL64(aIngress, 27U)) + RotL64(aCarry, 23U)) + 10431767565618874806U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 14883796491656899074U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 13465877783538483706U;
            aOrbiterA = RotL64((aOrbiterA * 14311686051108108503U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 13322163435314643713U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 3307316600284371955U) ^ RotL64(aNonceWordG, 47U);
            aOrbiterD = RotL64((aOrbiterD * 12337846092069506365U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 4950101626975919939U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 2596253994220103666U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7181706961838582889U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 17961706029559914243U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 10321902557977495175U) ^ aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16189559888625084711U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 18146616411403012772U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 8414050129421955787U;
            aOrbiterK = RotL64((aOrbiterK * 14879448948196182863U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 11739172334166341121U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 7936637782633487291U;
            aOrbiterE = RotL64((aOrbiterE * 14940929920543800413U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 3160044627483874242U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 16816384076887379704U;
            aOrbiterG = RotL64((aOrbiterG * 5052772186568301951U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 8101560104988710226U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 8851416379738817624U;
            aOrbiterB = RotL64((aOrbiterB * 16767420038937389027U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 9941784290055185679U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 14495651885701938495U;
            aOrbiterJ = RotL64((aOrbiterJ * 1540692851998143607U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 10599676325220702167U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 16092000942942971187U;
            aOrbiterI = RotL64((aOrbiterI * 2457268192247656817U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 16168470945107928109U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterE) ^ 17264605017518259932U) ^ aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1]) ^ RotL64(aNonceWordE, 3U);
            aOrbiterC = RotL64((aOrbiterC * 15038386057529909273U), 23U);
            //
            aIngress = RotL64(aOrbiterE, 23U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + (RotL64(aOrbiterK, 14U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + RotL64(aOrbiterA, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterG, 23U)) + aOrbiterD);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 11U) + aOrbiterB) + RotL64(aOrbiterC, 60U)) + aWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 43U)) + aOrbiterH) + RotL64(aCarry, 23U)) + RotL64(aNonceWordA, 29U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterG, 11U)) + aOrbiterE);
            aWandererH = aWandererH + ((RotL64(aPrevious, 60U) + aOrbiterK) + RotL64(aOrbiterF, 13U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterG, 51U)) + aOrbiterC);
            aWandererA = aWandererA + (((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterA, 48U)) + RotL64(aNonceWordB, 11U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 53U) + aOrbiterD) + RotL64(aOrbiterA, 39U)) + aWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 53U)) + aOrbiterG) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterI, 35U));
            aWandererI = aWandererI + ((RotL64(aCross, 58U) + RotL64(aOrbiterI, 21U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 34U));
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 21U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 53U) ^ RotL64(aNonceWordA, 21U));
            aIngress = aIngress ^ (RotL64(mSnow[((aIndex + 18347U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18318U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 60U) ^ RotL64(aNonceWordH, 27U)) ^ RotL64(aNonceWordC, 43U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18071U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 19846U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 13U)) + (RotL64(aIngress, 54U) + RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererH + RotL64(aScatter, 53U)) + 5697928251815176134U) + aOrbiterAssignSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aPrevious, 36U)) + 337587740689259575U;
            aOrbiterJ = (((aWandererG + RotL64(aCross, 39U)) + 4927686903263973950U) + aOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1]) + RotL64(aNonceWordF, 35U);
            aOrbiterC = ((aWandererB + RotL64(aIngress, 29U)) + RotL64(aCarry, 43U)) + 3742409032569801033U;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 41U)) + RotL64(aCarry, 47U)) + 1608092659172197650U;
            aOrbiterA = (aWandererA + RotL64(aCross, 3U)) + 15848744267145717509U;
            aOrbiterH = (aWandererF + RotL64(aIngress, 43U)) + 15300174177963339253U;
            aOrbiterF = (aWandererE + RotL64(aScatter, 60U)) + 14162868453323648628U;
            aOrbiterE = (aWandererI + RotL64(aPrevious, 57U)) + 12020167069983729869U;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 47U)) + 16259538291658723956U;
            aOrbiterK = (((aWandererD + RotL64(aCross, 21U)) + RotL64(aCarry, 27U)) + 8516686212464112245U) + RotL64(aNonceWordA, 17U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 3722184575520553132U) + RotL64(aNonceWordD, 41U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 5663609293306386784U;
            aOrbiterJ = RotL64((aOrbiterJ * 14364218128780764749U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 15265344442454471986U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 3050323350098829515U;
            aOrbiterD = RotL64((aOrbiterD * 5890624677162388135U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 1093356813820599238U) + aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 15167726103772238440U;
            aOrbiterA = RotL64((aOrbiterA * 5719466863561311069U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 15170797965325981472U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 17826286701992981628U;
            aOrbiterH = RotL64((aOrbiterH * 11186808881726573677U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 14710892030473425181U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 397194787697553904U;
            aOrbiterF = RotL64((aOrbiterF * 14368930300818752833U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 1273724124862533034U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 13018397560392545616U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4644812473262395329U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 9638716186445643730U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 7255587739807843785U) ^ aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6055682981584011189U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 9272350563697399628U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 1040729335295009339U;
            aOrbiterK = RotL64((aOrbiterK * 17825687660830291443U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 12128124729613601747U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 2285238815562202219U;
            aOrbiterI = RotL64((aOrbiterI * 15398840993074390573U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 6339113298619163493U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 5911895708485037040U;
            aOrbiterB = RotL64((aOrbiterB * 3271006139923200439U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 7601399508218901328U) + RotL64(aNonceWordH, 14U);
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 5697928251815176134U;
            aOrbiterC = RotL64((aOrbiterC * 8184257916861355735U), 53U);
            //
            aIngress = RotL64(aOrbiterJ, 13U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 48U));
            aIngress = aIngress + (RotL64(aOrbiterG, 21U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterA, 53U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 27U)) + aOrbiterB);
            aWandererE = aWandererE + ((RotL64(aCross, 21U) + RotL64(aOrbiterI, 5U)) + aOrbiterE);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterD, 21U)) + aOrbiterA) + aWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 37U) + aOrbiterG) + RotL64(aOrbiterB, 24U)) + RotL64(aNonceWordC, 37U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 53U) + aOrbiterE) + RotL64(aOrbiterA, 11U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 26U) + RotL64(aOrbiterA, 3U)) + aOrbiterG) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 39U) + aOrbiterH) + RotL64(aOrbiterJ, 19U));
            aWandererC = aWandererC + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 37U)) + aOrbiterI) + RotL64(aCarry, 3U)) + RotL64(aNonceWordE, 51U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 51U) + aOrbiterG) + RotL64(aOrbiterC, 57U));
            aWandererA = aWandererA + ((RotL64(aIngress, 60U) + aOrbiterK) + RotL64(aOrbiterG, 35U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterF, 44U)) + aOrbiterJ) + aWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 56U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + RotL64(aWandererJ, 21U);
            aCarry = aCarry + RotL64(aIngress, 58U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 19U) ^ RotL64(aNonceWordD, 46U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 24590U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25251U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 51U) ^ RotL64(aNonceWordG, 28U)) ^ RotL64(aNonceWordH, 3U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22210U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25393U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 18U) ^ RotL64(aIngress, 35U)) + (RotL64(aPrevious, 47U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 39U)) + 11274974230580265396U) + RotL64(aNonceWordC, 61U);
            aOrbiterE = (aWandererE + RotL64(aIngress, 23U)) + 16658438747342741547U;
            aOrbiterG = (aWandererF + RotL64(aScatter, 34U)) + 16612986966106053844U;
            aOrbiterI = (aWandererD + RotL64(aCross, 57U)) + 9329502236843231290U;
            aOrbiterB = (((aWandererC + RotL64(aScatter, 21U)) + RotL64(aCarry, 29U)) + 14088261356708344656U) + aOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aIngress, 41U)) + 13692608802007789581U;
            aOrbiterK = ((aWandererI + RotL64(aCross, 43U)) + RotL64(aCarry, 57U)) + 6824473946645682398U;
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 53U)) + 2072915876348570040U;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 46U)) + 7420507753044460759U) + aOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aIngress, 27U)) + 4677557318688502593U) + RotL64(aNonceWordF, 53U);
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 37U)) + RotL64(aCarry, 11U)) + 15081678577055628459U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 7026792817486507482U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 14871665922943969918U;
            aOrbiterG = RotL64((aOrbiterG * 694073180313083145U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 6807734532159292872U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 17882797335141303280U) ^ aOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15439872930381050291U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 9233542707022629190U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 1205501586581350876U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2596053290311090589U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 10878718669747466677U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 8066049063548639241U;
            aOrbiterF = RotL64((aOrbiterF * 3031382633089381605U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 861295180226875235U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 9134969787937288583U) ^ RotL64(aNonceWordG, 11U);
            aOrbiterA = RotL64((aOrbiterA * 7565008208670843555U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 6726642007159809594U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 8061661744643240470U;
            aOrbiterI = RotL64((aOrbiterI * 6703498926835391813U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 13541412083111962884U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 8617442758729315637U;
            aOrbiterK = RotL64((aOrbiterK * 15471862889276160953U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 16884403561131293362U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 9490680911678221233U;
            aOrbiterC = RotL64((aOrbiterC * 15988763830018001033U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 10486145044311386738U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 10200001044821063684U;
            aOrbiterD = RotL64((aOrbiterD * 16149790736141571017U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 6997073594007878034U) + RotL64(aNonceWordD, 38U);
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 13585783612009989767U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11425303157774550449U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 3847846040256340653U) + aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 11274974230580265396U;
            aOrbiterB = RotL64((aOrbiterB * 13970270689108369205U), 29U);
            //
            aIngress = RotL64(aOrbiterD, 13U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 60U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterF, 23U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterH, 43U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 20U)) + aOrbiterI);
            aWandererH = aWandererH + (((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterJ, 53U)) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterA, 41U)) + aOrbiterI) + RotL64(aNonceWordH, 3U)) + aWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 56U) + aOrbiterH) + RotL64(aOrbiterE, 51U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 21U) + aOrbiterF) + RotL64(aOrbiterE, 27U));
            aWandererF = aWandererF + ((RotL64(aIngress, 37U) + aOrbiterF) + RotL64(aOrbiterJ, 23U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterD, 35U)) + aOrbiterA);
            aWandererA = aWandererA + ((RotL64(aCross, 30U) + RotL64(aOrbiterG, 47U)) + aOrbiterI);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterC, 29U)) + aWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 43U) + RotL64(aOrbiterA, 43U)) + aOrbiterB) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterC, 14U)) + aOrbiterE) + RotL64(aNonceWordB, 51U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 42U));
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererG, 11U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 13U) ^ RotL64(aNonceWordA, 35U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 28311U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32104U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 12U) ^ RotL64(aNonceWordH, 3U)) ^ RotL64(aNonceWordG, 57U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31209U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((aIndex + 28370U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 22U) + RotL64(aCarry, 3U)) ^ (RotL64(aCross, 51U) + RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (((aWandererE + RotL64(aIngress, 13U)) + RotL64(aCarry, 37U)) + 10336802574069791273U) + RotL64(aNonceWordG, 51U);
            aOrbiterA = (((aWandererC + RotL64(aScatter, 53U)) + RotL64(aCarry, 41U)) + 169025388197058936U) + aOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aPrevious, 3U)) + 6541354188379168846U;
            aOrbiterB = ((aWandererG + RotL64(aCross, 23U)) + RotL64(aCarry, 5U)) + 16223920526599306104U;
            aOrbiterI = (aWandererK + RotL64(aIngress, 6U)) + 12756613707692514808U;
            aOrbiterH = ((aWandererI + RotL64(aCross, 47U)) + 5082475548176484035U) + aOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (aWandererD + RotL64(aScatter, 29U)) + 4907435526952698526U;
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 37U)) + 14236627073831834337U;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 18U)) + 11502511046130497584U) + RotL64(aNonceWordH, 11U);
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 35U)) + 3679044835550219497U;
            aOrbiterE = (aWandererH + RotL64(aIngress, 11U)) + 11254838916686736746U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 10582608424233200966U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 10449735026385340313U;
            aOrbiterK = RotL64((aOrbiterK * 7363770199734997411U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 4628253464169957835U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 17664454668473204465U;
            aOrbiterI = RotL64((aOrbiterI * 4234720298731378527U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 3798386391743884889U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 1379331161819246587U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13086160171095077295U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 9816600392407327227U) + RotL64(aNonceWordC, 21U);
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 16781971616348376878U;
            aOrbiterF = RotL64((aOrbiterF * 12503867584828289879U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 4807797577690520554U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 2492057261148595922U;
            aOrbiterJ = RotL64((aOrbiterJ * 9453302540675483005U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 7909676419643119585U) + aOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 256053568910383007U;
            aOrbiterD = RotL64((aOrbiterD * 11965085163352053161U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 16179914439220412472U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 3968867762761955845U;
            aOrbiterG = RotL64((aOrbiterG * 7473632378251893139U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 7474832923901283742U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 4736994731050735779U;
            aOrbiterE = RotL64((aOrbiterE * 9839654409121414047U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 596484364660389193U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 13822222274464306169U;
            aOrbiterC = RotL64((aOrbiterC * 1723502278319885511U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 16307920280681985443U) + aOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 3505106171801702915U;
            aOrbiterA = RotL64((aOrbiterA * 8479675421552861243U), 41U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterC) + 4987142580981135150U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]) + RotL64(aNonceWordF, 43U);
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 10336802574069791273U;
            aOrbiterB = RotL64((aOrbiterB * 2670706512498539705U), 47U);
            //
            aIngress = RotL64(aOrbiterE, 39U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterF, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 39U) + aOrbiterF) + RotL64(aOrbiterA, 40U)) + RotL64(aNonceWordB, 31U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 14U) + RotL64(aOrbiterH, 53U)) + aOrbiterD);
            aWandererB = aWandererB + (((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterE, 47U)) + aWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterD, 23U)) + aOrbiterI) + RotL64(aNonceWordE, 16U));
            aWandererH = aWandererH + (((RotL64(aIngress, 27U) + aOrbiterJ) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterG, 21U)) + aOrbiterK);
            aWandererD = aWandererD + (((RotL64(aPrevious, 12U) + aOrbiterJ) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterK, 42U)) + aOrbiterE) + aWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterJ, 5U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 23U) + aOrbiterC) + RotL64(aOrbiterK, 57U));
            aWandererI = aWandererI + ((RotL64(aCross, 43U) + RotL64(aOrbiterA, 37U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (RotL64(aWandererB, 38U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 41U);
            aCarry = aCarry + RotL64(aIngress, 34U);
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

void Soccer_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x879F006CE9AC59D7ULL + 0xBAC89E542A07CAA3ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x91AA42D21B134971ULL + 0xB0BB98F696A783ABULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x8D1E4FEA774B6553ULL + 0xCAFAE71A1F560B8CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x84607EF7C8B4116BULL + 0xC6394808C5D2ACCEULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA0CFC077B1484AAFULL + 0xAB3B05021C53BA1CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xA4297F6ADDD59945ULL + 0xA584C175CD512771ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xA9E3736EDA11D76FULL + 0xD7B84261C76587EEULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x829FE179095A78C1ULL + 0xD376B7CC88AFFB93ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 39U) ^ RotL64(aNonceWordD, 47U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1518U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7465U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 30U) ^ RotL64(aNonceWordA, 3U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7773U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 955U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCross, 3U)) + (RotL64(aCarry, 37U) + RotL64(aIngress, 54U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererE + RotL64(aIngress, 57U)) + 17264605017518259932U;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 51U)) + RotL64(aCarry, 21U)) + 15209184354580778643U;
            aOrbiterE = (aWandererF + RotL64(aCross, 5U)) + 3299527965014731384U;
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 30U)) + 16293096431816127821U;
            aOrbiterF = (((aWandererI + RotL64(aIngress, 39U)) + RotL64(aCarry, 39U)) + 11031983436878828337U) + RotL64(aNonceWordF, 25U);
            aOrbiterK = ((aWandererH + RotL64(aCross, 23U)) + 9188018632448236358U) + aOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aScatter, 35U)) + 13420816400363406556U) + aOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 11U)) + RotL64(aCarry, 11U)) + 2485063384097917101U;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 18U)) + 3089135816938128264U) + RotL64(aNonceWordH, 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 10730544971770435788U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 10431767565618874806U;
            aOrbiterE = RotL64((aOrbiterE * 4723078464590561545U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 14883796491656899074U) + aOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 13465877783538483706U;
            aOrbiterK = RotL64((aOrbiterK * 14311686051108108503U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 13322163435314643713U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 3307316600284371955U;
            aOrbiterG = RotL64((aOrbiterG * 12337846092069506365U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 4950101626975919939U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 2596253994220103666U;
            aOrbiterC = RotL64((aOrbiterC * 7181706961838582889U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 17961706029559914243U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 10321902557977495175U;
            aOrbiterD = RotL64((aOrbiterD * 16189559888625084711U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 18146616411403012772U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 8414050129421955787U;
            aOrbiterJ = RotL64((aOrbiterJ * 14879448948196182863U), 47U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterD) + 11739172334166341121U) + aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1]) + RotL64(aNonceWordG, 7U);
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 7936637782633487291U;
            aOrbiterA = RotL64((aOrbiterA * 14940929920543800413U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 3160044627483874242U) + RotL64(aNonceWordA, 30U);
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 16816384076887379704U;
            aOrbiterI = RotL64((aOrbiterI * 5052772186568301951U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 8101560104988710226U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 8851416379738817624U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16767420038937389027U), 27U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 34U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 18U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterA, 39U)) + RotL64(aCarry, 37U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 41U) + aOrbiterE) + RotL64(aOrbiterJ, 5U)) + aWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 34U) + RotL64(aOrbiterE, 13U)) + aOrbiterK) + RotL64(aNonceWordB, 11U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterC, 56U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterK, 51U)) + aOrbiterA);
            aWandererE = aWandererE ^ ((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterG, 35U));
            aWandererG = aWandererG + ((RotL64(aScatter, 51U) + RotL64(aOrbiterI, 29U)) + aOrbiterG);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterI, 22U)) + aOrbiterD);
            aWandererC = aWandererC + (((((RotL64(aPrevious, 24U) + RotL64(aOrbiterD, 43U)) + aOrbiterG) + RotL64(aCarry, 13U)) + RotL64(aNonceWordD, 3U)) + aWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (RotL64(aWandererJ, 24U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + RotL64(aWandererH, 51U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 27U) ^ RotL64(aNonceWordD, 58U)) ^ RotL64(aNonceWordA, 43U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 14477U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14577U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 5U) ^ RotL64(aNonceWordH, 13U)) ^ RotL64(aNonceWordF, 27U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9725U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 13251U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCross, 11U)) ^ (RotL64(aCarry, 44U) + RotL64(aIngress, 29U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererA + RotL64(aCross, 51U)) + RotL64(aCarry, 27U)) + 12775735908960052604U;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 19U)) + 11791373812080296887U) + aOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 56U)) + 5537362877706057303U;
            aOrbiterC = ((((aWandererB + RotL64(aScatter, 37U)) + RotL64(aCarry, 11U)) + 2023912048504189380U) + aOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1]) + RotL64(aNonceWordC, 59U);
            aOrbiterK = (aWandererK + RotL64(aIngress, 29U)) + 17668828109963766893U;
            aOrbiterB = (aWandererC + RotL64(aCross, 5U)) + 558908629933941224U;
            aOrbiterG = (((aWandererD + RotL64(aPrevious, 47U)) + RotL64(aCarry, 41U)) + 1479633119685446888U) + RotL64(aNonceWordG, 40U);
            aOrbiterA = (aWandererH + RotL64(aScatter, 60U)) + 15460320397843364063U;
            aOrbiterD = (aWandererE + RotL64(aCross, 11U)) + 10059749397555469054U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 9987633811929693924U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 10087337844580228269U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13817142288940843815U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 4446204415503364254U) + RotL64(aNonceWordA, 57U);
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 15106063243302192717U) ^ aOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13273756657334709803U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 9430197906134676162U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 1226048679997253363U;
            aOrbiterG = RotL64((aOrbiterG * 14247538885252664127U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 10611580584157624739U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 3137391249289641509U;
            aOrbiterA = RotL64((aOrbiterA * 5462682413239873181U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 9327201928815412810U) + RotL64(aNonceWordB, 61U);
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 7890659377013147073U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13827717178378062047U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 10675114832750356941U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 8804440385852327267U;
            aOrbiterI = RotL64((aOrbiterI * 8520671775587260601U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 12871947817782057116U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 11015991745792051390U;
            aOrbiterC = RotL64((aOrbiterC * 17152451500505815031U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 6320437975845673731U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 702457937087191287U;
            aOrbiterB = RotL64((aOrbiterB * 17491257114676739589U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 16629064896250312921U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 6054107387816339103U;
            aOrbiterH = RotL64((aOrbiterH * 6983767878966747219U), 57U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterG, 6U);
            aIngress = aIngress + (RotL64(aOrbiterH, 39U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterJ, 19U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterD, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 37U) + RotL64(aOrbiterJ, 13U)) + aOrbiterC) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 6U) + aOrbiterJ) + RotL64(aOrbiterG, 3U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterB, 57U)) + aOrbiterA) + RotL64(aCarry, 23U)) + RotL64(aNonceWordD, 53U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterI, 48U)) + aOrbiterH);
            aWandererF = aWandererF + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 23U)) + aOrbiterD) + aWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 23U) + aOrbiterK) + RotL64(aOrbiterA, 19U)) + RotL64(aNonceWordF, 7U));
            aWandererC = aWandererC + ((RotL64(aCross, 56U) + RotL64(aOrbiterG, 37U)) + aOrbiterA);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterK, 53U)) + aOrbiterI) + aWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 41U) + RotL64(aOrbiterG, 28U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (RotL64(aWandererB, 34U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 27U) ^ RotL64(aNonceWordF, 53U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 16542U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneA[((aIndex + 19476U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 19U) ^ RotL64(aNonceWordC, 30U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19115U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((aIndex + 23546U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCross, 22U)) ^ (RotL64(aCarry, 53U) + RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererA + RotL64(aScatter, 35U)) + 5697928251815176134U;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 57U)) + RotL64(aCarry, 3U)) + 337587740689259575U;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 6U)) + 4927686903263973950U) + RotL64(aNonceWordB, 39U);
            aOrbiterC = ((aWandererE + RotL64(aCross, 47U)) + 3742409032569801033U) + RotL64(aNonceWordH, 13U);
            aOrbiterB = (((aWandererD + RotL64(aScatter, 27U)) + RotL64(aCarry, 13U)) + 1608092659172197650U) + aOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aIngress, 39U)) + 15848744267145717509U) + aOrbiterAssignSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = (aWandererF + RotL64(aCross, 19U)) + 15300174177963339253U;
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 53U)) + 14162868453323648628U;
            aOrbiterK = ((aWandererH + RotL64(aCross, 12U)) + RotL64(aCarry, 39U)) + 12020167069983729869U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 16259538291658723956U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 8516686212464112245U;
            aOrbiterG = RotL64((aOrbiterG * 4731296903548893627U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 3722184575520553132U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 5663609293306386784U;
            aOrbiterE = RotL64((aOrbiterE * 14364218128780764749U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 15265344442454471986U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 3050323350098829515U;
            aOrbiterC = RotL64((aOrbiterC * 5890624677162388135U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 1093356813820599238U) + aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 15167726103772238440U;
            aOrbiterD = RotL64((aOrbiterD * 5719466863561311069U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 15170797965325981472U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 17826286701992981628U;
            aOrbiterB = RotL64((aOrbiterB * 11186808881726573677U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 14710892030473425181U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = (((aOrbiterA ^ aOrbiterI) ^ 397194787697553904U) ^ aOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1]) ^ RotL64(aNonceWordC, 45U);
            aOrbiterA = RotL64((aOrbiterA * 14368930300818752833U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 1273724124862533034U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 13018397560392545616U;
            aOrbiterI = RotL64((aOrbiterI * 4644812473262395329U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 9638716186445643730U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 7255587739807843785U) ^ RotL64(aNonceWordD, 31U);
            aOrbiterJ = RotL64((aOrbiterJ * 6055682981584011189U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 9272350563697399628U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 1040729335295009339U;
            aOrbiterK = RotL64((aOrbiterK * 17825687660830291443U), 57U);
            //
            aIngress = RotL64(aOrbiterK, 47U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 23U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 26U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 41U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 23U) + aOrbiterK) + RotL64(aOrbiterC, 11U)) + RotL64(aNonceWordG, 15U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterC, 56U)) + aOrbiterA);
            aWandererD = aWandererD + ((((RotL64(aCross, 29U) + aOrbiterD) + RotL64(aOrbiterG, 43U)) + RotL64(aCarry, 27U)) + RotL64(aNonceWordF, 20U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterK, 5U)) + aOrbiterE);
            aWandererC = aWandererC + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterI, 47U)) + aOrbiterD);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterD, 51U)) + aOrbiterC) + aWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterA, 34U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 6U) + aOrbiterB) + RotL64(aOrbiterA, 29U)) + aWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterJ, 21U)) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 54U));
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + RotL64(aWandererG, 23U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 21U) ^ RotL64(aNonceWordD, 13U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 26547U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneB[((aIndex + 32415U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 13U) ^ RotL64(aNonceWordA, 27U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 32596U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneD[((aIndex + 26980U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCross, 27U)) ^ (RotL64(aPrevious, 13U) + RotL64(aCarry, 42U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererC + RotL64(aIngress, 30U)) + RotL64(aCarry, 53U)) + 10336802574069791273U;
            aOrbiterD = (aWandererH + RotL64(aCross, 47U)) + 169025388197058936U;
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 19U)) + RotL64(aCarry, 39U)) + 6541354188379168846U;
            aOrbiterG = (aWandererF + RotL64(aScatter, 13U)) + 16223920526599306104U;
            aOrbiterF = (((aWandererG + RotL64(aIngress, 57U)) + 12756613707692514808U) + aOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1]) + RotL64(aNonceWordG, 19U);
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 53U)) + 5082475548176484035U) + aOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = ((aWandererK + RotL64(aCross, 23U)) + 4907435526952698526U) + RotL64(aNonceWordE, 51U);
            aOrbiterC = ((aWandererA + RotL64(aScatter, 3U)) + RotL64(aCarry, 27U)) + 14236627073831834337U;
            aOrbiterJ = (aWandererE + RotL64(aIngress, 40U)) + 11502511046130497584U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 3679044835550219497U) + RotL64(aNonceWordC, 47U);
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 11254838916686736746U;
            aOrbiterB = RotL64((aOrbiterB * 8631695922983532915U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 10582608424233200966U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 10449735026385340313U;
            aOrbiterF = RotL64((aOrbiterF * 7363770199734997411U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 4628253464169957835U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 17664454668473204465U;
            aOrbiterK = RotL64((aOrbiterK * 4234720298731378527U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 3798386391743884889U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 1379331161819246587U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13086160171095077295U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 9816600392407327227U) + aOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 16781971616348376878U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12503867584828289879U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 4807797577690520554U) + RotL64(aNonceWordH, 15U);
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 2492057261148595922U;
            aOrbiterE = RotL64((aOrbiterE * 9453302540675483005U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 7909676419643119585U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 256053568910383007U;
            aOrbiterC = RotL64((aOrbiterC * 11965085163352053161U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 16179914439220412472U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 3968867762761955845U;
            aOrbiterJ = RotL64((aOrbiterJ * 7473632378251893139U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 7474832923901283742U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 4736994731050735779U;
            aOrbiterD = RotL64((aOrbiterD * 9839654409121414047U), 35U);
            //
            aIngress = RotL64(aOrbiterE, 14U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aCross, 18U) + aOrbiterJ) + RotL64(aOrbiterF, 47U));
            aWandererC = aWandererC ^ ((((RotL64(aScatter, 43U) + aOrbiterE) + RotL64(aOrbiterF, 43U)) + RotL64(aNonceWordB, 55U)) + aWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 29U) + RotL64(aOrbiterD, 39U)) + aOrbiterE) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 37U) + aOrbiterG) + RotL64(aOrbiterB, 24U)) + aWandererUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 57U) + aOrbiterC) + RotL64(aOrbiterE, 13U)) + RotL64(aCarry, 23U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 23U) + aOrbiterC) + RotL64(aOrbiterH, 29U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterE, 3U)) + aOrbiterG) + RotL64(aNonceWordF, 14U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterE, 19U)) + aOrbiterK);
            aWandererD = aWandererD + ((RotL64(aIngress, 6U) + RotL64(aOrbiterH, 34U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 56U));
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void Soccer_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xAED0ECDD1B1F6B87ULL + 0xB6A4D690FBF3E73CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xC7431C39671F7E75ULL + 0xB763C53605DF9BF7ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xF77042A6B06B8945ULL + 0xDF9DFCE07D762271ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x8EF6EE1FA3DB10CBULL + 0xD83243A08DE86D1FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xE4949CD09E7A45FBULL + 0x95C95DFEF2C232F6ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xDC35D7F4811F3603ULL + 0x95FF801D7B30FFC8ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xE862CF7A3BC66105ULL + 0xF86239FC7F0E920CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x89CF5B8261E6AA1FULL + 0xECDEF9C7E331F291ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 5U) ^ RotL64(aNonceWordC, 14U)) ^ RotL64(aNonceWordD, 27U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 74U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneC[((aIndex + 694U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 43U) ^ RotL64(aNonceWordF, 13U)) ^ RotL64(aNonceWordH, 35U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 3406U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneA[((aIndex + 1503U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 19U) ^ RotL64(aPrevious, 50U)) ^ (RotL64(aIngress, 3U) + RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererG + RotL64(aCross, 5U)) + RotL64(aCarry, 43U)) + 12775735908960052604U;
            aOrbiterE = (aWandererA + RotL64(aScatter, 51U)) + 11791373812080296887U;
            aOrbiterC = ((((aWandererE + RotL64(aPrevious, 42U)) + RotL64(aCarry, 23U)) + 5537362877706057303U) + aOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1]) + RotL64(aNonceWordH, 49U);
            aOrbiterB = (((aWandererK + RotL64(aIngress, 21U)) + RotL64(aCarry, 57U)) + 2023912048504189380U) + RotL64(aNonceWordC, 57U);
            aOrbiterF = ((aWandererB + RotL64(aScatter, 29U)) + 17668828109963766893U) + aOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 558908629933941224U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 1479633119685446888U;
            aOrbiterC = RotL64((aOrbiterC * 4447153373540811385U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 15460320397843364063U) + RotL64(aNonceWordE, 9U);
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 10059749397555469054U;
            aOrbiterI = RotL64((aOrbiterI * 8671817118586065469U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 9987633811929693924U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 10087337844580228269U;
            aOrbiterB = RotL64((aOrbiterB * 13817142288940843815U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 4446204415503364254U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterF) ^ 15106063243302192717U) ^ aOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1]) ^ RotL64(aNonceWordB, 6U);
            aOrbiterE = RotL64((aOrbiterE * 13273756657334709803U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 9430197906134676162U) + aOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 1226048679997253363U;
            aOrbiterF = RotL64((aOrbiterF * 14247538885252664127U), 53U);
            //
            aIngress = RotL64(aOrbiterI, 27U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 37U));
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 58U) + aOrbiterC) + RotL64(aOrbiterF, 43U));
            aWandererB = aWandererB + (((RotL64(aIngress, 27U) + aOrbiterI) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 52U)) + aOrbiterB) + RotL64(aNonceWordG, 55U)) + aWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 41U) + aOrbiterE) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 5U)) + RotL64(aNonceWordA, 61U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterI, 27U)) + aWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererG, 43U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 56U) ^ RotL64(aNonceWordD, 37U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 13107U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneD[((aIndex + 16042U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 36U) ^ RotL64(aNonceWordG, 11U)) ^ RotL64(aNonceWordB, 21U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 13235U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 12134U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 37U) + RotL64(aCarry, 52U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (((aWandererG + RotL64(aPrevious, 3U)) + RotL64(aCarry, 5U)) + 3339283916456813609U) + aOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = ((aWandererH + RotL64(aIngress, 46U)) + 11339086426180649584U) + RotL64(aNonceWordF, 59U);
            aOrbiterA = (aWandererK + RotL64(aCross, 21U)) + 16819191669329316585U;
            aOrbiterF = (((aWandererJ + RotL64(aScatter, 29U)) + RotL64(aCarry, 53U)) + 8361916937762630725U) + aOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = (((aWandererB + RotL64(aIngress, 57U)) + RotL64(aCarry, 39U)) + 18031328374429899857U) + RotL64(aNonceWordE, 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 18261756894092897276U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 4250319792907645666U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7053489184750217963U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 1492411503643460886U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterD) ^ 17369549067879344180U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]) ^ RotL64(aNonceWordH, 38U);
            aOrbiterH = RotL64((aOrbiterH * 2947354306696216579U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 7301713524358676722U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 2985193736033012535U) ^ RotL64(aNonceWordA, 49U);
            aOrbiterI = RotL64((aOrbiterI * 7473297294949338265U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 14086975808140927408U) + aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 10390516547834639800U;
            aOrbiterD = RotL64((aOrbiterD * 11441293212275890819U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 18205555540941493267U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 16967799565443938873U) ^ aOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3009081009044782443U), 5U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterF, 3U);
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 35U)) + aOrbiterI) + RotL64(aCarry, 19U)) + aWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 27U)) + aOrbiterI);
            aWandererG = aWandererG + ((((RotL64(aCross, 21U) + aOrbiterA) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 35U)) + RotL64(aNonceWordG, 5U));
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 38U) + aOrbiterA) + RotL64(aOrbiterH, 13U)) + RotL64(aNonceWordC, 31U)) + aWandererUpdateSaltB[((aIndex + 20U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 54U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 29U) ^ RotL64(aNonceWordG, 39U)) ^ RotL64(aNonceWordE, 51U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 21693U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 19450U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 42U) ^ RotL64(aNonceWordC, 21U)) ^ RotL64(aNonceWordH, 3U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 18391U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 18105U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 23U)) ^ (RotL64(aCross, 35U) + RotL64(aPrevious, 10U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((((aWandererB + RotL64(aPrevious, 39U)) + RotL64(aCarry, 51U)) + 11274974230580265396U) + aOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1]) + RotL64(aNonceWordG, 39U);
            aOrbiterE = ((aWandererI + RotL64(aScatter, 19U)) + 16658438747342741547U) + aOrbiterAssignSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aCross, 60U)) + 16612986966106053844U) + RotL64(aNonceWordD, 31U);
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 29U)) + RotL64(aCarry, 39U)) + 9329502236843231290U;
            aOrbiterJ = ((aWandererD + RotL64(aCross, 47U)) + RotL64(aCarry, 27U)) + 14088261356708344656U;
            //
            aOrbiterH = (((aOrbiterH + aOrbiterE) + 13692608802007789581U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]) + RotL64(aNonceWordF, 29U);
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 6824473946645682398U;
            aOrbiterC = RotL64((aOrbiterC * 13619437545775237601U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 2072915876348570040U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 7420507753044460759U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13239288539564571257U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 4677557318688502593U) + RotL64(aNonceWordB, 51U);
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 15081678577055628459U;
            aOrbiterH = RotL64((aOrbiterH * 16659305295251177155U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 7026792817486507482U) + aOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 14871665922943969918U;
            aOrbiterD = RotL64((aOrbiterD * 694073180313083145U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 6807734532159292872U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 17882797335141303280U) ^ aOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15439872930381050291U), 29U);
            //
            aIngress = RotL64(aOrbiterC, 19U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterJ, 51U)) + aOrbiterD) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 48U) + aOrbiterC) + RotL64(aOrbiterE, 12U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterH, 3U)) + aOrbiterD) + RotL64(aNonceWordC, 22U)) + aWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterE, 43U)) + aWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aScatter, 39U) + aOrbiterJ) + RotL64(aOrbiterH, 27U)) + RotL64(aCarry, 57U)) + RotL64(aNonceWordA, 49U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 21U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 12U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 54U) ^ RotL64(aNonceWordH, 23U)) ^ RotL64(aNonceWordF, 3U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 28551U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((aIndex + 31599U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 47U) ^ RotL64(aNonceWordC, 5U)) ^ RotL64(aNonceWordG, 19U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32329U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 25142U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 36U) ^ RotL64(aPrevious, 19U)) + (RotL64(aIngress, 3U) ^ RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererK + RotL64(aIngress, 48U)) + 17264605017518259932U) + RotL64(aNonceWordG, 3U);
            aOrbiterA = ((((aWandererB + RotL64(aPrevious, 29U)) + RotL64(aCarry, 57U)) + 15209184354580778643U) + aOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1]) + RotL64(aNonceWordB, 28U);
            aOrbiterH = ((aWandererI + RotL64(aCross, 3U)) + 3299527965014731384U) + aOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aScatter, 37U)) + RotL64(aCarry, 19U)) + 16293096431816127821U;
            aOrbiterF = ((aWandererE + RotL64(aCross, 21U)) + RotL64(aCarry, 39U)) + 11031983436878828337U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 9188018632448236358U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 13420816400363406556U) ^ aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10958221259662190519U), 29U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterF) + 2485063384097917101U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]) + RotL64(aNonceWordD, 41U);
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 3089135816938128264U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8813152992957361153U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 10730544971770435788U) + RotL64(aNonceWordA, 53U);
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 10431767565618874806U;
            aOrbiterC = RotL64((aOrbiterC * 4723078464590561545U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 14883796491656899074U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 13465877783538483706U;
            aOrbiterA = RotL64((aOrbiterA * 14311686051108108503U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 13322163435314643713U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 3307316600284371955U) ^ aOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12337846092069506365U), 57U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterC, 13U);
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 43U) + aOrbiterC) + RotL64(aOrbiterD, 22U)) + aWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aCross, 5U) + aOrbiterF) + RotL64(aOrbiterC, 41U)) + RotL64(aCarry, 53U)) + RotL64(aNonceWordE, 43U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 21U) + aOrbiterD) + RotL64(aOrbiterF, 3U)) + aWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 52U) + RotL64(aOrbiterA, 57U)) + aOrbiterH) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterA, 13U)) + RotL64(aNonceWordH, 59U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 34U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 5U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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

void Soccer_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xD59B81A806383079ULL + 0xE86CE5BDCC6BF4CFULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x8F639DB80C536ABFULL + 0xB49ED2A28D767875ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xDEEBBB3EFC22110BULL + 0xF5452925E39670E8ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xE7BC55EA1DF4647DULL + 0xDEC58CFEE430F972ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xB3CC0170975A31C5ULL + 0x9ED84B6CA394AA6DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x9F0DA37D35D1612DULL + 0xA76A474926E39D68ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xC8FCC23221038C5BULL + 0xEE93EF41C3868B9FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF90B924F74A69297ULL + 0xC22C8E5E96C172ACULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 52U) ^ RotL64(aNonceWordB, 13U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 5511U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((aIndex + 2255U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 21U) ^ RotL64(aNonceWordE, 57U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4991U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneA[((aIndex + 8035U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 56U) ^ RotL64(aPrevious, 27U)) + (RotL64(aCross, 13U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 35U)) + RotL64(aCarry, 43U)) + 11274974230580265396U;
            aOrbiterA = (aWandererJ + RotL64(aIngress, 5U)) + 16658438747342741547U;
            aOrbiterD = (((aWandererF + RotL64(aCross, 47U)) + RotL64(aCarry, 11U)) + 16612986966106053844U) + RotL64(aNonceWordF, 31U);
            aOrbiterC = ((aWandererA + RotL64(aScatter, 21U)) + 9329502236843231290U) + aOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = ((aWandererE + RotL64(aCross, 60U)) + 14088261356708344656U) + aOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = ((aWandererG + RotL64(aScatter, 29U)) + 13692608802007789581U) + RotL64(aNonceWordC, 19U);
            aOrbiterK = ((aWandererD + RotL64(aIngress, 41U)) + RotL64(aCarry, 27U)) + 6824473946645682398U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 2072915876348570040U) + RotL64(aNonceWordD, 44U);
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 7420507753044460759U;
            aOrbiterD = RotL64((aOrbiterD * 13239288539564571257U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 4677557318688502593U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 15081678577055628459U;
            aOrbiterF = RotL64((aOrbiterF * 16659305295251177155U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 7026792817486507482U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 14871665922943969918U;
            aOrbiterI = RotL64((aOrbiterI * 694073180313083145U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 6807734532159292872U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterD) ^ 17882797335141303280U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]) ^ RotL64(aNonceWordA, 25U);
            aOrbiterK = RotL64((aOrbiterK * 15439872930381050291U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 9233542707022629190U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 1205501586581350876U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2596053290311090589U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 10878718669747466677U) + aOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 8066049063548639241U;
            aOrbiterC = RotL64((aOrbiterC * 3031382633089381605U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 861295180226875235U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 9134969787937288583U) ^ aOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7565008208670843555U), 29U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterD, 35U);
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + RotL64(aOrbiterC, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 27U)) + aOrbiterG);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterD, 43U));
            aWandererA = aWandererA + ((((RotL64(aCross, 41U) + aOrbiterA) + RotL64(aOrbiterF, 11U)) + RotL64(aCarry, 35U)) + aWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterI, 19U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 37U)) + aOrbiterI) + RotL64(aCarry, 19U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 54U) + aOrbiterG) + RotL64(aOrbiterD, 60U)) + RotL64(aNonceWordE, 29U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterG, 53U)) + RotL64(aNonceWordG, 51U)) + aWandererUpdateSaltD[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 18U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + RotL64(aWandererA, 53U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 3U) ^ RotL64(aNonceWordF, 34U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 13128U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 8266U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 51U) ^ RotL64(aNonceWordG, 4U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 16277U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 13123U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCross, 20U)) + (RotL64(aIngress, 47U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (((aWandererJ + RotL64(aIngress, 13U)) + 17264605017518259932U) + aOrbiterAssignSaltC[(((31U - aIndex) + 28U)) & S_SALT1]) + RotL64(aNonceWordD, 43U);
            aOrbiterI = (aWandererK + RotL64(aScatter, 43U)) + 15209184354580778643U;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 21U)) + RotL64(aCarry, 3U)) + 3299527965014731384U;
            aOrbiterD = (aWandererF + RotL64(aCross, 60U)) + 16293096431816127821U;
            aOrbiterH = (((aWandererD + RotL64(aIngress, 5U)) + RotL64(aCarry, 51U)) + 11031983436878828337U) + aOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 53U)) + RotL64(aCarry, 37U)) + 9188018632448236358U;
            aOrbiterC = ((aWandererE + RotL64(aCross, 37U)) + 13420816400363406556U) + RotL64(aNonceWordC, 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 2485063384097917101U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 3089135816938128264U;
            aOrbiterG = RotL64((aOrbiterG * 8813152992957361153U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 10730544971770435788U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 10431767565618874806U) ^ RotL64(aNonceWordH, 24U);
            aOrbiterE = RotL64((aOrbiterE * 4723078464590561545U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 14883796491656899074U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 13465877783538483706U;
            aOrbiterD = RotL64((aOrbiterD * 14311686051108108503U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 13322163435314643713U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 3307316600284371955U;
            aOrbiterI = RotL64((aOrbiterI * 12337846092069506365U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 4950101626975919939U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 2596253994220103666U;
            aOrbiterH = RotL64((aOrbiterH * 7181706961838582889U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 17961706029559914243U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterC) ^ 10321902557977495175U) ^ aOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1]) ^ RotL64(aNonceWordE, 57U);
            aOrbiterJ = RotL64((aOrbiterJ * 16189559888625084711U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 18146616411403012772U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 8414050129421955787U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14879448948196182863U), 43U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterC, 3U);
            aIngress = aIngress + (RotL64(aOrbiterE, 56U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + RotL64(aOrbiterG, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterD, 60U)) + aOrbiterE);
            aWandererF = aWandererF + ((((RotL64(aIngress, 60U) + aOrbiterG) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 27U)) + RotL64(aNonceWordF, 27U));
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 27U) + aOrbiterJ) + RotL64(aOrbiterI, 35U)) + RotL64(aNonceWordA, 13U)) + aWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 19U)) + aOrbiterH);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterC, 41U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 3U)) + aOrbiterE) + RotL64(aCarry, 57U)) + aWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 47U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 34U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + RotL64(aWandererD, 11U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 12U) ^ RotL64(aNonceWordH, 53U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 19679U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((aIndex + 19868U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 36U) ^ RotL64(aNonceWordB, 47U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 22165U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((aIndex + 21470U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 38U) ^ RotL64(aIngress, 21U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 27U)) + RotL64(aCarry, 23U)) + 10336802574069791273U;
            aOrbiterH = (((aWandererH + RotL64(aIngress, 47U)) + RotL64(aCarry, 39U)) + 169025388197058936U) + RotL64(aNonceWordG, 3U);
            aOrbiterA = (aWandererG + RotL64(aCross, 19U)) + 6541354188379168846U;
            aOrbiterI = (((aWandererB + RotL64(aScatter, 13U)) + RotL64(aCarry, 3U)) + 16223920526599306104U) + RotL64(aNonceWordE, 4U);
            aOrbiterB = ((aWandererK + RotL64(aCross, 5U)) + 12756613707692514808U) + aOrbiterAssignSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 37U)) + 5082475548176484035U) + aOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aIngress, 54U)) + 4907435526952698526U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 14236627073831834337U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 11502511046130497584U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3460330807286625917U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 3679044835550219497U) + aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 11254838916686736746U) ^ RotL64(aNonceWordF, 53U);
            aOrbiterH = RotL64((aOrbiterH * 8631695922983532915U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 10582608424233200966U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 10449735026385340313U;
            aOrbiterF = RotL64((aOrbiterF * 7363770199734997411U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 4628253464169957835U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 17664454668473204465U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4234720298731378527U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 3798386391743884889U) + aOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 1379331161819246587U) ^ RotL64(aNonceWordA, 35U);
            aOrbiterB = RotL64((aOrbiterB * 13086160171095077295U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 9816600392407327227U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 16781971616348376878U;
            aOrbiterK = RotL64((aOrbiterK * 12503867584828289879U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 4807797577690520554U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 2492057261148595922U;
            aOrbiterE = RotL64((aOrbiterE * 9453302540675483005U), 27U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 3U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aCross, 47U) + aOrbiterI) + RotL64(aOrbiterF, 35U)) + RotL64(aCarry, 51U)) + RotL64(aNonceWordC, 45U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 11U) + aOrbiterF) + RotL64(aOrbiterB, 51U));
            aWandererH = aWandererH + ((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterE, 18U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 29U) + aOrbiterI) + RotL64(aOrbiterA, 3U));
            aWandererD = aWandererD + ((RotL64(aCross, 39U) + RotL64(aOrbiterE, 43U)) + aOrbiterK);
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterA, 29U)) + RotL64(aNonceWordD, 29U)) + aWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 56U) + RotL64(aOrbiterH, 11U)) + aOrbiterE) + RotL64(aCarry, 37U)) + aWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 58U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 35U) ^ RotL64(aNonceWordD, 3U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 28984U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneB[((aIndex + 30760U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 5U) ^ RotL64(aNonceWordC, 60U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28062U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 26466U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 10U) ^ RotL64(aIngress, 41U)) + (RotL64(aCross, 53U) ^ RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (((aWandererJ + RotL64(aIngress, 41U)) + 3339283916456813609U) + aOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1]) + RotL64(aNonceWordB, 17U);
            aOrbiterF = ((aWandererC + RotL64(aCross, 47U)) + RotL64(aCarry, 23U)) + 11339086426180649584U;
            aOrbiterK = (((aWandererK + RotL64(aScatter, 12U)) + RotL64(aCarry, 39U)) + 16819191669329316585U) + aOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 53U)) + RotL64(aCarry, 3U)) + 8361916937762630725U;
            aOrbiterE = (aWandererE + RotL64(aCross, 21U)) + 18031328374429899857U;
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 29U)) + 18261756894092897276U) + RotL64(aNonceWordE, 11U);
            aOrbiterG = (aWandererB + RotL64(aIngress, 5U)) + 4250319792907645666U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 1492411503643460886U) + RotL64(aNonceWordA, 9U);
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 17369549067879344180U;
            aOrbiterK = RotL64((aOrbiterK * 2947354306696216579U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 7301713524358676722U) + aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 2985193736033012535U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7473297294949338265U), 23U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterJ) + 14086975808140927408U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]) + RotL64(aNonceWordH, 42U);
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 10390516547834639800U;
            aOrbiterF = RotL64((aOrbiterF * 11441293212275890819U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 18205555540941493267U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 16967799565443938873U;
            aOrbiterE = RotL64((aOrbiterE * 3009081009044782443U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 9209505304067579944U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 3522631966146762306U;
            aOrbiterJ = RotL64((aOrbiterJ * 3441982898533162599U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 8811497120829041188U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 14707301680850257294U;
            aOrbiterD = RotL64((aOrbiterD * 11383709499376464085U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 10080595991787801029U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 6822892187784299166U;
            aOrbiterG = RotL64((aOrbiterG * 7417016898027778287U), 51U);
            //
            aIngress = RotL64(aOrbiterF, 47U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 60U));
            aIngress = aIngress + RotL64(aOrbiterE, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 51U)) + aOrbiterA);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 35U)) + aOrbiterJ) + RotL64(aCarry, 39U)) + RotL64(aNonceWordG, 61U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 13U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 5U)) + RotL64(aNonceWordF, 3U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterF, 41U)) + aOrbiterE) + aWandererUpdateSaltA[((aIndex + 24U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterD, 23U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 40U) + RotL64(aOrbiterE, 4U)) + aOrbiterK) + aWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 20U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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

void Soccer_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xA0A5C57F64C9C62BULL + 0xE9AC488A0F1C8242ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x9D06590BC8EFC9F9ULL + 0xBEDF9F8894F1E4F1ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xAFD08C77C7C01D85ULL + 0x8DE7A55764B282F6ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xD5B25D40A3BACE03ULL + 0xB82FC4A96163C791ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xFD38DD805667D86BULL + 0x8AE202E93ADA1EF1ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x9CED5E658CCA1179ULL + 0xD03EFFCE4C549F55ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xC8D4F879434DB10DULL + 0x85B57C954E7203D3ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xDDA407B30BD1E4F7ULL + 0xBEB2D6CD39134153ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 53U) ^ RotL64(aNonceWordD, 13U)) ^ RotL64(aNonceWordH, 3U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 1411U)) & S_BLOCK1], 40U) ^ RotL64(aWorkLaneC[((aIndex + 3892U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 11U) ^ RotL64(aNonceWordG, 19U)) ^ RotL64(aNonceWordA, 51U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 3823U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneA[((aIndex + 3550U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 60U) ^ RotL64(aCross, 11U)) + (RotL64(aCarry, 41U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererJ + RotL64(aScatter, 57U)) + 12775735908960052604U;
            aOrbiterE = (aWandererF + RotL64(aPrevious, 11U)) + 11791373812080296887U;
            aOrbiterG = (((aWandererB + RotL64(aIngress, 21U)) + RotL64(aCarry, 11U)) + 5537362877706057303U) + RotL64(aNonceWordC, 25U);
            aOrbiterH = (((aWandererG + RotL64(aCross, 36U)) + RotL64(aCarry, 27U)) + 2023912048504189380U) + aOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 29U)) + 17668828109963766893U) + RotL64(aNonceWordA, 52U);
            aOrbiterA = (((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 51U)) + 558908629933941224U) + aOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aIngress, 51U)) + 1479633119685446888U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 15460320397843364063U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 10059749397555469054U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8671817118586065469U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 9987633811929693924U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 10087337844580228269U;
            aOrbiterB = RotL64((aOrbiterB * 13817142288940843815U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 4446204415503364254U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 15106063243302192717U) ^ RotL64(aNonceWordG, 49U);
            aOrbiterA = RotL64((aOrbiterA * 13273756657334709803U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 9430197906134676162U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 1226048679997253363U;
            aOrbiterC = RotL64((aOrbiterC * 14247538885252664127U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 10611580584157624739U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 3137391249289641509U) ^ aOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5462682413239873181U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 9327201928815412810U) + RotL64(aNonceWordE, 61U);
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 7890659377013147073U;
            aOrbiterH = RotL64((aOrbiterH * 13827717178378062047U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 10675114832750356941U) + aOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 8804440385852327267U;
            aOrbiterE = RotL64((aOrbiterE * 8520671775587260601U), 57U);
            //
            aIngress = RotL64(aOrbiterC, 43U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 20U) + aOrbiterC) + RotL64(aOrbiterG, 47U)) + aWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterH, 35U)) + aOrbiterC);
            aWandererH = aWandererH + ((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterG, 22U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterA, 41U)) + aOrbiterG);
            aWandererF = aWandererF + (((RotL64(aScatter, 57U) + aOrbiterE) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 35U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterC, 13U)) + aOrbiterI) + RotL64(aNonceWordF, 35U));
            aWandererG = aWandererG + (((((RotL64(aPrevious, 3U) + aOrbiterB) + RotL64(aOrbiterE, 5U)) + RotL64(aCarry, 11U)) + RotL64(aNonceWordH, 19U)) + aWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 56U));
            aCarry = aCarry + RotL64(aWandererG, 39U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 27U) ^ RotL64(aNonceWordG, 41U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 9015U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneD[((aIndex + 10606U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 57U) ^ RotL64(aNonceWordH, 39U)) ^ RotL64(aNonceWordD, 29U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 14275U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 10693U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 29U) ^ RotL64(aIngress, 43U)) ^ (RotL64(aPrevious, 11U) + RotL64(aCross, 56U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 3U)) + 17264605017518259932U) + aOrbiterAssignSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = ((((aWandererB + RotL64(aCross, 35U)) + RotL64(aCarry, 51U)) + 15209184354580778643U) + aOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1]) + RotL64(aNonceWordH, 19U);
            aOrbiterD = (aWandererH + RotL64(aIngress, 43U)) + 3299527965014731384U;
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 27U)) + RotL64(aCarry, 23U)) + 16293096431816127821U;
            aOrbiterJ = (aWandererC + RotL64(aCross, 57U)) + 11031983436878828337U;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 3U)) + 9188018632448236358U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 20U)) + 13420816400363406556U) + RotL64(aNonceWordG, 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 2485063384097917101U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 3089135816938128264U;
            aOrbiterD = RotL64((aOrbiterD * 8813152992957361153U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 10730544971770435788U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 10431767565618874806U;
            aOrbiterI = RotL64((aOrbiterI * 4723078464590561545U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 14883796491656899074U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 13465877783538483706U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14311686051108108503U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 13322163435314643713U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 3307316600284371955U;
            aOrbiterA = RotL64((aOrbiterA * 12337846092069506365U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 4950101626975919939U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 2596253994220103666U;
            aOrbiterJ = RotL64((aOrbiterJ * 7181706961838582889U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 17961706029559914243U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 10321902557977495175U) ^ RotL64(aNonceWordB, 25U);
            aOrbiterB = RotL64((aOrbiterB * 16189559888625084711U), 57U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterH) + 18146616411403012772U) + aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1]) + RotL64(aNonceWordC, 11U);
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 8414050129421955787U) ^ aOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14879448948196182863U), 41U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterD, 35U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + RotL64(aOrbiterF, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterI, 41U)) + RotL64(aCarry, 47U)) + aWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterI, 13U)) + aOrbiterH);
            aWandererH = aWandererH + (((RotL64(aPrevious, 60U) + aOrbiterI) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 19U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 11U) + aOrbiterB) + RotL64(aOrbiterA, 53U)) + aWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 29U) + aOrbiterD) + RotL64(aOrbiterB, 34U)) + RotL64(aNonceWordA, 54U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 23U) + aOrbiterA) + RotL64(aOrbiterJ, 5U)) + RotL64(aNonceWordF, 5U));
            aWandererB = aWandererB + ((RotL64(aIngress, 51U) + RotL64(aOrbiterF, 19U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 60U));
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 41U) ^ RotL64(aNonceWordG, 60U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 19356U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((aIndex + 21748U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 10U) ^ RotL64(aNonceWordB, 19U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 22282U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneC[((aIndex + 19218U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 11U)) + (RotL64(aPrevious, 41U) + RotL64(aCross, 28U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 57U)) + 5697928251815176134U) + aOrbiterAssignSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterI = ((aWandererC + RotL64(aCross, 11U)) + 337587740689259575U) + RotL64(aNonceWordA, 57U);
            aOrbiterB = ((aWandererH + RotL64(aScatter, 41U)) + RotL64(aCarry, 5U)) + 4927686903263973950U;
            aOrbiterA = (aWandererF + RotL64(aIngress, 30U)) + 3742409032569801033U;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 5U)) + RotL64(aCarry, 21U)) + 1608092659172197650U;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 23U)) + 15848744267145717509U) + aOrbiterAssignSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = (((aWandererI + RotL64(aCross, 51U)) + RotL64(aCarry, 41U)) + 15300174177963339253U) + RotL64(aNonceWordD, 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 14162868453323648628U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 12020167069983729869U;
            aOrbiterB = RotL64((aOrbiterB * 2071080217680099017U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 16259538291658723956U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 8516686212464112245U;
            aOrbiterI = RotL64((aOrbiterI * 4731296903548893627U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 3722184575520553132U) + RotL64(aNonceWordG, 21U);
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 5663609293306386784U;
            aOrbiterE = RotL64((aOrbiterE * 14364218128780764749U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 15265344442454471986U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 3050323350098829515U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5890624677162388135U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 1093356813820599238U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 15167726103772238440U) ^ aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5719466863561311069U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 15170797965325981472U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 17826286701992981628U;
            aOrbiterF = RotL64((aOrbiterF * 11186808881726573677U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 14710892030473425181U) + aOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 397194787697553904U) ^ RotL64(aNonceWordF, 11U);
            aOrbiterC = RotL64((aOrbiterC * 14368930300818752833U), 11U);
            //
            aIngress = RotL64(aOrbiterF, 57U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterB, 30U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterB, 37U)) + aOrbiterA) + RotL64(aNonceWordC, 58U));
            aWandererH = aWandererH + (((((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 44U)) + aOrbiterB) + RotL64(aCarry, 47U)) + RotL64(aNonceWordE, 5U)) + aWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterG, 11U));
            aWandererC = aWandererC + ((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterF, 3U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 50U) + RotL64(aOrbiterI, 23U)) + aOrbiterA);
            aWandererD = aWandererD + (((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterI, 57U)) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 29U)) + aOrbiterG) + aWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + (RotL64(aWandererJ, 58U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 30U) ^ RotL64(aNonceWordG, 3U)) ^ RotL64(aNonceWordH, 13U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 26604U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32484U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 47U) ^ RotL64(aNonceWordC, 29U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26321U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 30752U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCross, 5U)) ^ (RotL64(aCarry, 56U) + RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererA + RotL64(aCross, 47U)) + 10336802574069791273U;
            aOrbiterC = (((aWandererC + RotL64(aPrevious, 37U)) + RotL64(aCarry, 11U)) + 169025388197058936U) + aOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aScatter, 29U)) + 6541354188379168846U;
            aOrbiterK = ((((aWandererD + RotL64(aIngress, 53U)) + RotL64(aCarry, 27U)) + 16223920526599306104U) + aOrbiterAssignSaltF[(((31U - aIndex) + 22U)) & S_SALT1]) + RotL64(aNonceWordC, 27U);
            aOrbiterI = ((aWandererF + RotL64(aScatter, 4U)) + 12756613707692514808U) + RotL64(aNonceWordF, 54U);
            aOrbiterD = ((aWandererJ + RotL64(aCross, 23U)) + RotL64(aCarry, 43U)) + 5082475548176484035U;
            aOrbiterG = (aWandererK + RotL64(aIngress, 11U)) + 4907435526952698526U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 14236627073831834337U) + RotL64(aNonceWordG, 41U);
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 11502511046130497584U;
            aOrbiterF = RotL64((aOrbiterF * 3460330807286625917U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 3679044835550219497U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 11254838916686736746U;
            aOrbiterD = RotL64((aOrbiterD * 8631695922983532915U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 10582608424233200966U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 10449735026385340313U;
            aOrbiterC = RotL64((aOrbiterC * 7363770199734997411U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 4628253464169957835U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 17664454668473204465U;
            aOrbiterI = RotL64((aOrbiterI * 4234720298731378527U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 3798386391743884889U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 1379331161819246587U;
            aOrbiterJ = RotL64((aOrbiterJ * 13086160171095077295U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 9816600392407327227U) + aOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 16781971616348376878U) ^ aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12503867584828289879U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 4807797577690520554U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterI) ^ 2492057261148595922U) ^ aOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1]) ^ RotL64(aNonceWordB, 61U);
            aOrbiterG = RotL64((aOrbiterG * 9453302540675483005U), 57U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 39U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterC, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 5U) + RotL64(aOrbiterD, 13U)) + aOrbiterG) + RotL64(aCarry, 13U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 13U) + aOrbiterK) + RotL64(aOrbiterF, 4U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterJ, 19U)) + aOrbiterG) + RotL64(aCarry, 47U)) + RotL64(aNonceWordE, 31U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterI, 29U)) + RotL64(aNonceWordA, 53U));
            aWandererH = aWandererH + (((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterC, 35U)) + aWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 38U) + aOrbiterC) + RotL64(aOrbiterJ, 57U));
            aWandererK = aWandererK + (((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterG, 43U)) + aWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 38U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererK, 23U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

void Soccer_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x80734275D2D94465ULL + 0xE9075C154E9C03ACULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x8725C3A93BDA303DULL + 0xBBB6A7C164BA5790ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x8E7088860A8E623FULL + 0xAF5968B53B6A03C5ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x8134F493E5525B79ULL + 0xEA54F1C3551FD965ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x83214574D77C9D49ULL + 0xBCC86E04B0DE2959ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xC3A023D2000B9FCDULL + 0xABCB59F51117A94EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xEE236C78236295EFULL + 0x87DF32C6FD2627D0ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x9154AE5909DBBAF5ULL + 0xE431811C50895A37ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 37U) ^ RotL64(aNonceWordD, 13U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 5285U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6948U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 13U) ^ RotL64(aNonceWordH, 5U)) ^ RotL64(aNonceWordG, 27U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5186U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneA[((aIndex + 6412U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 40U) ^ RotL64(aCross, 5U)) + (RotL64(aCarry, 19U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererA + RotL64(aCross, 39U)) + 5697928251815176134U;
            aOrbiterD = (((aWandererJ + RotL64(aScatter, 12U)) + RotL64(aCarry, 23U)) + 337587740689259575U) + aOrbiterAssignSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 57U)) + 4927686903263973950U) + RotL64(aNonceWordC, 35U);
            aOrbiterK = (((aWandererE + RotL64(aIngress, 27U)) + RotL64(aCarry, 51U)) + 3742409032569801033U) + aOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aScatter, 47U)) + 1608092659172197650U;
            aOrbiterE = (aWandererG + RotL64(aCross, 19U)) + 15848744267145717509U;
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 37U)) + 15300174177963339253U) + RotL64(aNonceWordD, 37U);
            aOrbiterC = (aWandererB + RotL64(aIngress, 10U)) + 14162868453323648628U;
            aOrbiterI = (aWandererF + RotL64(aCross, 3U)) + 12020167069983729869U;
            aOrbiterG = (aWandererI + RotL64(aScatter, 35U)) + 16259538291658723956U;
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 23U)) + RotL64(aCarry, 37U)) + 8516686212464112245U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 3722184575520553132U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 5663609293306386784U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14364218128780764749U), 13U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterA) + 15265344442454471986U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]) + RotL64(aNonceWordH, 21U);
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 3050323350098829515U;
            aOrbiterE = RotL64((aOrbiterE * 5890624677162388135U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 1093356813820599238U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 15167726103772238440U;
            aOrbiterJ = RotL64((aOrbiterJ * 5719466863561311069U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 15170797965325981472U) + aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 17826286701992981628U;
            aOrbiterK = RotL64((aOrbiterK * 11186808881726573677U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 14710892030473425181U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 397194787697553904U;
            aOrbiterF = RotL64((aOrbiterF * 14368930300818752833U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 1273724124862533034U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 13018397560392545616U;
            aOrbiterI = RotL64((aOrbiterI * 4644812473262395329U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 9638716186445643730U) + aOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 7255587739807843785U;
            aOrbiterH = RotL64((aOrbiterH * 6055682981584011189U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 9272350563697399628U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 1040729335295009339U;
            aOrbiterD = RotL64((aOrbiterD * 17825687660830291443U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 12128124729613601747U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 2285238815562202219U;
            aOrbiterA = RotL64((aOrbiterA * 15398840993074390573U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 6339113298619163493U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 5911895708485037040U) ^ RotL64(aNonceWordB, 55U);
            aOrbiterC = RotL64((aOrbiterC * 3271006139923200439U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 7601399508218901328U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 5697928251815176134U;
            aOrbiterG = RotL64((aOrbiterG * 8184257916861355735U), 23U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterJ, 39U);
            aIngress = aIngress + (RotL64(aOrbiterI, 60U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 43U));
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterH, 53U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((RotL64(aCross, 58U) + aOrbiterA) + RotL64(aOrbiterD, 41U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 24U)) + aOrbiterH);
            aWandererE = aWandererE + ((RotL64(aIngress, 37U) + RotL64(aOrbiterK, 11U)) + aOrbiterH);
            aWandererD = aWandererD ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterA, 37U)) + aOrbiterJ) + RotL64(aNonceWordA, 9U));
            aWandererG = aWandererG + (((RotL64(aIngress, 18U) + RotL64(aOrbiterG, 13U)) + aOrbiterI) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterI, 60U)) + aOrbiterK);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterC, 3U)) + aOrbiterF) + RotL64(aCarry, 37U)) + aWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterJ, 5U)) + aOrbiterF) + RotL64(aNonceWordE, 34U));
            aWandererF = aWandererF + ((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterH, 39U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterK, 19U)) + aWandererUpdateSaltC[((aIndex + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 41U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 46U));
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 21U));
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 30U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 53U) ^ RotL64(aNonceWordG, 27U)) ^ RotL64(aNonceWordF, 5U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 9312U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12066U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 3U) ^ RotL64(aNonceWordH, 14U)) ^ RotL64(aNonceWordE, 37U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14013U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9097U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aIngress, 57U)) ^ (RotL64(aCarry, 43U) + RotL64(aPrevious, 10U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 11U)) + RotL64(aCarry, 35U)) + 12775735908960052604U;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 4U)) + 11791373812080296887U) + aOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 29U)) + RotL64(aCarry, 47U)) + 5537362877706057303U;
            aOrbiterH = ((aWandererC + RotL64(aCross, 23U)) + 2023912048504189380U) + aOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aPrevious, 37U)) + 17668828109963766893U;
            aOrbiterB = ((aWandererE + RotL64(aCross, 57U)) + RotL64(aCarry, 29U)) + 558908629933941224U;
            aOrbiterJ = (aWandererK + RotL64(aIngress, 60U)) + 1479633119685446888U;
            aOrbiterI = ((aWandererD + RotL64(aScatter, 53U)) + 15460320397843364063U) + RotL64(aNonceWordE, 31U);
            aOrbiterC = (aWandererI + RotL64(aCross, 47U)) + 10059749397555469054U;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 21U)) + 9987633811929693924U) + RotL64(aNonceWordD, 14U);
            aOrbiterE = (aWandererG + RotL64(aIngress, 39U)) + 10087337844580228269U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 4446204415503364254U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 15106063243302192717U;
            aOrbiterG = RotL64((aOrbiterG * 13273756657334709803U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 9430197906134676162U) + aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 1226048679997253363U;
            aOrbiterD = RotL64((aOrbiterD * 14247538885252664127U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 10611580584157624739U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 3137391249289641509U) ^ aOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5462682413239873181U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 9327201928815412810U) + RotL64(aNonceWordC, 53U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 7890659377013147073U;
            aOrbiterJ = RotL64((aOrbiterJ * 13827717178378062047U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 10675114832750356941U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 8804440385852327267U;
            aOrbiterC = RotL64((aOrbiterC * 8520671775587260601U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 12871947817782057116U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 11015991745792051390U;
            aOrbiterA = RotL64((aOrbiterA * 17152451500505815031U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 6320437975845673731U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 702457937087191287U;
            aOrbiterH = RotL64((aOrbiterH * 17491257114676739589U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 16629064896250312921U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 6054107387816339103U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6983767878966747219U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 13274874838094190290U) + aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 12211422735294360321U;
            aOrbiterI = RotL64((aOrbiterI * 5113738196151089817U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 15338616110718583619U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 1475787183754511373U;
            aOrbiterK = RotL64((aOrbiterK * 10904607643785840003U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 15486810401396777742U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 12775735908960052604U) ^ RotL64(aNonceWordF, 7U);
            aOrbiterE = RotL64((aOrbiterE * 7478156942468930207U), 35U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterE, 21U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 30U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + (RotL64(aOrbiterG, 41U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 23U));
            aIngress = aIngress + RotL64(aOrbiterH, 46U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterH, 51U)) + aOrbiterG) + aWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterB, 23U)) + RotL64(aCarry, 51U)) + RotL64(aNonceWordA, 23U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 53U) + aOrbiterA) + RotL64(aOrbiterE, 41U));
            aWandererI = aWandererI + (((RotL64(aCross, 50U) + RotL64(aOrbiterE, 57U)) + aOrbiterB) + aWandererUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterJ, 3U)) + aOrbiterF) + RotL64(aNonceWordG, 3U));
            aWandererG = aWandererG + ((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterI, 21U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 13U) + aOrbiterK) + RotL64(aOrbiterC, 6U));
            aWandererF = aWandererF + (((RotL64(aCross, 23U) + RotL64(aOrbiterF, 37U)) + aOrbiterH) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 43U)) + aOrbiterD);
            aWandererK = aWandererK + ((RotL64(aIngress, 10U) + RotL64(aOrbiterD, 47U)) + aOrbiterH);
            aWandererB = aWandererB ^ ((RotL64(aCross, 37U) + aOrbiterF) + RotL64(aOrbiterE, 60U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 4U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 35U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 13U) ^ RotL64(aNonceWordG, 60U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 18532U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19077U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 57U) ^ RotL64(aNonceWordD, 14U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20410U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 17512U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aIngress, 53U)) + (RotL64(aPrevious, 27U) + RotL64(aCross, 10U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (((aWandererC + RotL64(aIngress, 5U)) + 3339283916456813609U) + aOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1]) + RotL64(aNonceWordB, 51U);
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 47U)) + 11339086426180649584U) + aOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = (aWandererH + RotL64(aCross, 21U)) + 16819191669329316585U;
            aOrbiterI = (aWandererB + RotL64(aPrevious, 11U)) + 8361916937762630725U;
            aOrbiterK = ((aWandererA + RotL64(aIngress, 51U)) + RotL64(aCarry, 43U)) + 18031328374429899857U;
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 57U)) + 18261756894092897276U;
            aOrbiterG = (((aWandererD + RotL64(aScatter, 18U)) + RotL64(aCarry, 13U)) + 4250319792907645666U) + RotL64(aNonceWordA, 31U);
            aOrbiterB = ((aWandererI + RotL64(aCross, 37U)) + RotL64(aCarry, 51U)) + 1492411503643460886U;
            aOrbiterF = (aWandererK + RotL64(aScatter, 35U)) + 17369549067879344180U;
            aOrbiterA = (aWandererE + RotL64(aCross, 27U)) + 7301713524358676722U;
            aOrbiterE = (aWandererG + RotL64(aIngress, 40U)) + 2985193736033012535U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 14086975808140927408U) + RotL64(aNonceWordC, 25U);
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 10390516547834639800U;
            aOrbiterD = RotL64((aOrbiterD * 11441293212275890819U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 18205555540941493267U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 16967799565443938873U;
            aOrbiterC = RotL64((aOrbiterC * 3009081009044782443U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 9209505304067579944U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 3522631966146762306U;
            aOrbiterJ = RotL64((aOrbiterJ * 3441982898533162599U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 8811497120829041188U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 14707301680850257294U;
            aOrbiterK = RotL64((aOrbiterK * 11383709499376464085U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 10080595991787801029U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 6822892187784299166U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7417016898027778287U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 1981637172055758689U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 16463077485583119324U;
            aOrbiterA = RotL64((aOrbiterA * 2876782050665869121U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 8383837717361569465U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 2788511294985017326U;
            aOrbiterH = RotL64((aOrbiterH * 2809163242875130677U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 3529607472855930041U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 8850940802020173766U;
            aOrbiterI = RotL64((aOrbiterI * 7821450253655655943U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 7469160295100147267U) + aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 16973986572163482061U;
            aOrbiterG = RotL64((aOrbiterG * 15660743778376905023U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 12371372942863279718U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 12098525148034303633U;
            aOrbiterF = RotL64((aOrbiterF * 11234127652230231751U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 5138683482859889480U) + RotL64(aNonceWordH, 35U);
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 3339283916456813609U;
            aOrbiterE = RotL64((aOrbiterE * 10975353228235695455U), 5U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterC, 35U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 10U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + RotL64(aOrbiterD, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aPrevious, 53U) + aOrbiterG) + RotL64(aOrbiterD, 12U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 26U) + aOrbiterK) + RotL64(aOrbiterI, 39U)) + aWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterH, 5U)) + RotL64(aNonceWordE, 17U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 23U) + aOrbiterJ) + RotL64(aOrbiterH, 27U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 37U)) + aOrbiterD) + RotL64(aCarry, 13U)) + aWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 47U)) + aOrbiterB) + RotL64(aNonceWordF, 56U));
            aWandererA = aWandererA + (((RotL64(aCross, 37U) + RotL64(aOrbiterE, 24U)) + aOrbiterJ) + RotL64(aCarry, 41U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 57U) + aOrbiterC) + RotL64(aOrbiterF, 21U));
            aWandererC = aWandererC + ((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 19U)) + aOrbiterK);
            aWandererE = aWandererE ^ ((RotL64(aCross, 21U) + aOrbiterA) + RotL64(aOrbiterH, 53U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 6U) + RotL64(aOrbiterA, 43U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 28U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (RotL64(aWandererC, 24U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 51U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 42U) ^ RotL64(aNonceWordA, 11U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 26719U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((aIndex + 24915U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 14U) ^ RotL64(aNonceWordE, 23U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26885U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((aIndex + 26554U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 27U) + RotL64(aPrevious, 42U)) ^ (RotL64(aIngress, 5U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (((aWandererG + RotL64(aPrevious, 42U)) + RotL64(aCarry, 35U)) + 10336802574069791273U) + RotL64(aNonceWordG, 35U);
            aOrbiterE = (aWandererI + RotL64(aIngress, 51U)) + 169025388197058936U;
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 13U)) + 6541354188379168846U) + RotL64(aNonceWordH, 37U);
            aOrbiterK = ((aWandererD + RotL64(aCross, 29U)) + RotL64(aCarry, 13U)) + 16223920526599306104U;
            aOrbiterA = (aWandererA + RotL64(aScatter, 5U)) + 12756613707692514808U;
            aOrbiterG = (aWandererH + RotL64(aIngress, 58U)) + 5082475548176484035U;
            aOrbiterD = (aWandererC + RotL64(aCross, 35U)) + 4907435526952698526U;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 23U)) + 14236627073831834337U) + aOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aCross, 21U)) + 11502511046130497584U;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 47U)) + RotL64(aCarry, 29U)) + 3679044835550219497U;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 37U)) + 11254838916686736746U) + aOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 10582608424233200966U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 10449735026385340313U;
            aOrbiterJ = RotL64((aOrbiterJ * 7363770199734997411U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 4628253464169957835U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 17664454668473204465U;
            aOrbiterA = RotL64((aOrbiterA * 4234720298731378527U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 3798386391743884889U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 1379331161819246587U;
            aOrbiterG = RotL64((aOrbiterG * 13086160171095077295U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 9816600392407327227U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 16781971616348376878U;
            aOrbiterD = RotL64((aOrbiterD * 12503867584828289879U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 4807797577690520554U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 2492057261148595922U;
            aOrbiterH = RotL64((aOrbiterH * 9453302540675483005U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 7909676419643119585U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterG) ^ 256053568910383007U) ^ aOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1]) ^ RotL64(aNonceWordB, 23U);
            aOrbiterB = RotL64((aOrbiterB * 11965085163352053161U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 16179914439220412472U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 3968867762761955845U;
            aOrbiterC = RotL64((aOrbiterC * 7473632378251893139U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 7474832923901283742U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 4736994731050735779U) ^ aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9839654409121414047U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 596484364660389193U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 13822222274464306169U;
            aOrbiterF = RotL64((aOrbiterF * 1723502278319885511U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 16307920280681985443U) + aOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 3505106171801702915U) ^ RotL64(aNonceWordD, 25U);
            aOrbiterE = RotL64((aOrbiterE * 8479675421552861243U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 4987142580981135150U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 10336802574069791273U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2670706512498539705U), 11U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterI, 51U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + (RotL64(aOrbiterA, 41U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 56U));
            aIngress = aIngress + RotL64(aOrbiterF, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 47U)) + aOrbiterI);
            aWandererF = aWandererF + ((RotL64(aCross, 3U) + RotL64(aOrbiterA, 44U)) + aOrbiterJ);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterD, 19U)) + aOrbiterK);
            aWandererE = aWandererE + ((RotL64(aScatter, 51U) + RotL64(aOrbiterE, 53U)) + aOrbiterF);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 54U) + aOrbiterB) + RotL64(aOrbiterA, 57U)) + aWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aScatter, 13U) + aOrbiterK) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 19U)) + RotL64(aNonceWordE, 53U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 41U) + aOrbiterD) + RotL64(aOrbiterE, 3U)) + RotL64(aNonceWordF, 34U));
            aWandererG = aWandererG + ((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterE, 21U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 60U) + aOrbiterB) + RotL64(aOrbiterC, 60U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 11U) + aOrbiterK) + RotL64(aOrbiterE, 27U)) + RotL64(aCarry, 51U)) + aWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 13U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + (RotL64(aWandererI, 60U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + RotL64(aWandererG, 41U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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

void Soccer_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xA9DC3A0A09D91EB5ULL + 0xACEB157DFDE734B3ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xF2D673FD411EE97DULL + 0xDD17627BCAEF0C8AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xD4879455D6A04565ULL + 0x946FDE72BAC46667ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xBE836364FE7314E9ULL + 0xC7C5ADA46CC892B9ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xFEE596EFCCF9913DULL + 0xF6EED726811F4A44ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xE80BC71F32A4A255ULL + 0xB228C99F70D8049CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x83F24B6CEAB6F599ULL + 0x9EB884AE08D24069ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x89858669C4F3ADCDULL + 0xBAE71897232B3A00ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 28U) ^ RotL64(aNonceWordE, 47U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 4451U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2275U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 11U) ^ RotL64(aNonceWordG, 50U)) ^ RotL64(aNonceWordF, 19U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 217U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneA[((aIndex + 5132U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aIngress, 27U)) ^ (RotL64(aCarry, 52U) + RotL64(aPrevious, 13U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererC + RotL64(aScatter, 39U)) + 3339283916456813609U;
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 12U)) + RotL64(aCarry, 13U)) + 11339086426180649584U;
            aOrbiterB = (((aWandererK + RotL64(aPrevious, 47U)) + 16819191669329316585U) + aOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1]) + RotL64(aNonceWordA, 49U);
            aOrbiterI = (aWandererD + RotL64(aCross, 57U)) + 8361916937762630725U;
            aOrbiterE = (((aWandererB + RotL64(aScatter, 23U)) + RotL64(aCarry, 39U)) + 18031328374429899857U) + aOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 51U)) + 18261756894092897276U;
            aOrbiterF = (aWandererG + RotL64(aCross, 27U)) + 4250319792907645666U;
            aOrbiterH = (aWandererH + RotL64(aIngress, 18U)) + 1492411503643460886U;
            aOrbiterC = (((aWandererE + RotL64(aCross, 43U)) + RotL64(aCarry, 5U)) + 17369549067879344180U) + RotL64(aNonceWordB, 59U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 7301713524358676722U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 2985193736033012535U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7473297294949338265U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 14086975808140927408U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 10390516547834639800U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11441293212275890819U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 18205555540941493267U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 16967799565443938873U;
            aOrbiterH = RotL64((aOrbiterH * 3009081009044782443U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 9209505304067579944U) + RotL64(aNonceWordD, 15U);
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 3522631966146762306U;
            aOrbiterC = RotL64((aOrbiterC * 3441982898533162599U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 8811497120829041188U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 14707301680850257294U;
            aOrbiterK = RotL64((aOrbiterK * 11383709499376464085U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 10080595991787801029U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 6822892187784299166U;
            aOrbiterI = RotL64((aOrbiterI * 7417016898027778287U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 1981637172055758689U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 16463077485583119324U;
            aOrbiterF = RotL64((aOrbiterF * 2876782050665869121U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 8383837717361569465U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 2788511294985017326U;
            aOrbiterG = RotL64((aOrbiterG * 2809163242875130677U), 43U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterF) + 3529607472855930041U) + aOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1]) + RotL64(aNonceWordH, 16U);
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 8850940802020173766U) ^ aOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7821450253655655943U), 19U);
            //
            aIngress = RotL64(aOrbiterC, 29U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 56U));
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + RotL64(aOrbiterH, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterF, 41U)) + aOrbiterG);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 36U) + RotL64(aOrbiterJ, 27U)) + aOrbiterG) + RotL64(aCarry, 47U)) + aWandererUpdateSaltA[((aIndex + 14U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 29U) + aOrbiterJ) + RotL64(aOrbiterI, 21U)) + RotL64(aNonceWordE, 61U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 43U) + aOrbiterB) + RotL64(aOrbiterE, 46U)) + RotL64(aNonceWordG, 45U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 5U) + aOrbiterF) + RotL64(aOrbiterB, 53U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 37U)) + aOrbiterK);
            aWandererC = aWandererC ^ (((RotL64(aCross, 14U) + aOrbiterJ) + RotL64(aOrbiterH, 3U)) + aWandererUpdateSaltB[((aIndex + 16U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 23U) + aOrbiterH) + RotL64(aOrbiterG, 57U)) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 57U) + aOrbiterC) + RotL64(aOrbiterF, 10U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 54U));
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 13U) ^ RotL64(aNonceWordA, 26U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 7501U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneD[((aIndex + 9581U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 11U) ^ RotL64(aNonceWordH, 34U)) ^ RotL64(aNonceWordG, 43U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 5686U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7105U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 35U)) + (RotL64(aIngress, 50U) + RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (((aWandererA + RotL64(aCross, 53U)) + RotL64(aCarry, 13U)) + 17264605017518259932U) + RotL64(aNonceWordE, 28U);
            aOrbiterE = (aWandererI + RotL64(aScatter, 58U)) + 15209184354580778643U;
            aOrbiterC = (aWandererH + RotL64(aIngress, 43U)) + 3299527965014731384U;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 47U)) + RotL64(aCarry, 21U)) + 16293096431816127821U;
            aOrbiterH = (aWandererF + RotL64(aIngress, 19U)) + 11031983436878828337U;
            aOrbiterK = (aWandererG + RotL64(aCross, 11U)) + 9188018632448236358U;
            aOrbiterI = (((aWandererD + RotL64(aPrevious, 3U)) + 13420816400363406556U) + aOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1]) + RotL64(aNonceWordH, 27U);
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 39U)) + 2485063384097917101U) + aOrbiterAssignSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = ((aWandererC + RotL64(aIngress, 34U)) + RotL64(aCarry, 43U)) + 3089135816938128264U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 10730544971770435788U) + RotL64(aNonceWordA, 35U);
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 10431767565618874806U;
            aOrbiterC = RotL64((aOrbiterC * 4723078464590561545U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 14883796491656899074U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 13465877783538483706U;
            aOrbiterH = RotL64((aOrbiterH * 14311686051108108503U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 13322163435314643713U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 3307316600284371955U;
            aOrbiterI = RotL64((aOrbiterI * 12337846092069506365U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 4950101626975919939U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 2596253994220103666U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7181706961838582889U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 17961706029559914243U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 10321902557977495175U;
            aOrbiterG = RotL64((aOrbiterG * 16189559888625084711U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 18146616411403012772U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 8414050129421955787U;
            aOrbiterA = RotL64((aOrbiterA * 14879448948196182863U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 11739172334166341121U) + RotL64(aNonceWordG, 15U);
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 7936637782633487291U;
            aOrbiterD = RotL64((aOrbiterD * 14940929920543800413U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 3160044627483874242U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 16816384076887379704U;
            aOrbiterK = RotL64((aOrbiterK * 5052772186568301951U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 8101560104988710226U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 8851416379738817624U) ^ aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16767420038937389027U), 19U);
            //
            aIngress = RotL64(aOrbiterD, 23U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterH, 43U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + (RotL64(aOrbiterK, 39U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 18U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterG, 21U)) + RotL64(aCarry, 3U)) + RotL64(aNonceWordC, 7U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 30U)) + aOrbiterB) + RotL64(aNonceWordD, 5U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 28U) + aOrbiterI) + RotL64(aOrbiterD, 3U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 53U) + aOrbiterI) + RotL64(aOrbiterK, 57U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 47U)) + aOrbiterA);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 11U) + aOrbiterA) + RotL64(aOrbiterI, 26U)) + aWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 48U) + aOrbiterD) + RotL64(aOrbiterH, 53U)) + aWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 19U) + aOrbiterH) + RotL64(aOrbiterE, 11U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterD, 35U)) + aOrbiterC) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 18U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 27U) ^ RotL64(aNonceWordE, 5U)) ^ RotL64(aNonceWordD, 37U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 16355U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11289U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 5U) ^ RotL64(aNonceWordA, 29U)) ^ RotL64(aNonceWordB, 56U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 12253U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 11381U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 5U)) + (RotL64(aCross, 27U) ^ RotL64(aIngress, 52U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererK + RotL64(aScatter, 35U)) + RotL64(aCarry, 13U)) + 12775735908960052604U;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 23U)) + RotL64(aCarry, 39U)) + 11791373812080296887U;
            aOrbiterE = (aWandererI + RotL64(aCross, 19U)) + 5537362877706057303U;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 29U)) + 2023912048504189380U) + aOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = (aWandererD + RotL64(aScatter, 52U)) + 17668828109963766893U;
            aOrbiterA = (((aWandererG + RotL64(aCross, 47U)) + RotL64(aCarry, 5U)) + 558908629933941224U) + aOrbiterAssignSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aIngress, 11U)) + 1479633119685446888U) + RotL64(aNonceWordE, 4U);
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 5U)) + 15460320397843364063U) + RotL64(aNonceWordC, 25U);
            aOrbiterD = (aWandererJ + RotL64(aCross, 58U)) + 10059749397555469054U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 9987633811929693924U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 10087337844580228269U) ^ RotL64(aNonceWordF, 53U);
            aOrbiterE = RotL64((aOrbiterE * 13817142288940843815U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 4446204415503364254U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 15106063243302192717U;
            aOrbiterF = RotL64((aOrbiterF * 13273756657334709803U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 9430197906134676162U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 1226048679997253363U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14247538885252664127U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 10611580584157624739U) + aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 3137391249289641509U;
            aOrbiterC = RotL64((aOrbiterC * 5462682413239873181U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 9327201928815412810U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 7890659377013147073U;
            aOrbiterJ = RotL64((aOrbiterJ * 13827717178378062047U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 10675114832750356941U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 8804440385852327267U;
            aOrbiterA = RotL64((aOrbiterA * 8520671775587260601U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 12871947817782057116U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 11015991745792051390U;
            aOrbiterK = RotL64((aOrbiterK * 17152451500505815031U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 6320437975845673731U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 702457937087191287U;
            aOrbiterG = RotL64((aOrbiterG * 17491257114676739589U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 16629064896250312921U) + RotL64(aNonceWordA, 55U);
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 6054107387816339103U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6983767878966747219U), 27U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterC, 36U);
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + RotL64(aOrbiterK, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aCross, 46U) + RotL64(aOrbiterK, 18U)) + aOrbiterE) + RotL64(aCarry, 21U)) + aWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 47U)) + aOrbiterD) + RotL64(aNonceWordD, 3U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 11U) + aOrbiterI) + RotL64(aOrbiterF, 43U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterJ, 53U)) + aOrbiterG) + RotL64(aNonceWordG, 47U));
            aWandererB = aWandererB + (((RotL64(aScatter, 3U) + aOrbiterD) + RotL64(aOrbiterI, 5U)) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterC, 23U));
            aWandererK = aWandererK + ((RotL64(aIngress, 36U) + RotL64(aOrbiterG, 11U)) + aOrbiterK);
            aWandererE = aWandererE ^ ((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterJ, 58U));
            aWandererF = aWandererF + (((RotL64(aIngress, 29U) + aOrbiterD) + RotL64(aOrbiterG, 29U)) + aWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + RotL64(aWandererD, 43U);
            aCarry = aCarry + RotL64(aIngress, 18U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 23U) ^ RotL64(aNonceWordF, 41U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 17672U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneB[((aIndex + 20835U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 56U) ^ RotL64(aNonceWordC, 19U)) ^ RotL64(aNonceWordD, 29U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18977U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneD[((aIndex + 18148U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCross, 35U)) + (RotL64(aCarry, 50U) ^ RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererA + RotL64(aIngress, 57U)) + RotL64(aCarry, 37U)) + 10336802574069791273U;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 51U)) + 169025388197058936U;
            aOrbiterB = (aWandererH + RotL64(aCross, 39U)) + 6541354188379168846U;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 44U)) + RotL64(aCarry, 53U)) + 16223920526599306104U;
            aOrbiterA = (((aWandererG + RotL64(aPrevious, 27U)) + 12756613707692514808U) + aOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1]) + RotL64(aNonceWordD, 25U);
            aOrbiterF = (aWandererI + RotL64(aScatter, 11U)) + 5082475548176484035U;
            aOrbiterC = ((aWandererC + RotL64(aCross, 35U)) + RotL64(aCarry, 5U)) + 4907435526952698526U;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 23U)) + 14236627073831834337U) + RotL64(aNonceWordH, 16U);
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 4U)) + 11502511046130497584U) + aOrbiterAssignSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 3679044835550219497U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 11254838916686736746U;
            aOrbiterB = RotL64((aOrbiterB * 8631695922983532915U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 10582608424233200966U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 10449735026385340313U;
            aOrbiterA = RotL64((aOrbiterA * 7363770199734997411U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 4628253464169957835U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = (((aOrbiterC ^ aOrbiterF) ^ 17664454668473204465U) ^ aOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1]) ^ RotL64(aNonceWordE, 23U);
            aOrbiterC = RotL64((aOrbiterC * 4234720298731378527U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 3798386391743884889U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 1379331161819246587U;
            aOrbiterG = RotL64((aOrbiterG * 13086160171095077295U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 9816600392407327227U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 16781971616348376878U;
            aOrbiterJ = RotL64((aOrbiterJ * 12503867584828289879U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 4807797577690520554U) + aOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 2492057261148595922U) ^ RotL64(aNonceWordC, 11U);
            aOrbiterF = RotL64((aOrbiterF * 9453302540675483005U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 7909676419643119585U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 256053568910383007U;
            aOrbiterD = RotL64((aOrbiterD * 11965085163352053161U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 16179914439220412472U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 3968867762761955845U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7473632378251893139U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 7474832923901283742U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 4736994731050735779U;
            aOrbiterK = RotL64((aOrbiterK * 9839654409121414047U), 35U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterJ, 24U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 41U));
            aIngress = aIngress + (RotL64(aOrbiterD, 27U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterG, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterJ, 43U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 23U)) + aOrbiterA);
            aWandererK = aWandererK + ((((RotL64(aCross, 41U) + RotL64(aOrbiterB, 30U)) + aOrbiterD) + RotL64(aCarry, 53U)) + aWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 14U) + aOrbiterB) + RotL64(aOrbiterG, 19U)) + RotL64(aNonceWordA, 47U)) + aWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterI, 5U)) + aOrbiterD) + RotL64(aCarry, 5U)) + RotL64(aNonceWordG, 17U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterG, 47U)) + aOrbiterK);
            aWandererA = aWandererA + ((RotL64(aScatter, 37U) + aOrbiterC) + RotL64(aOrbiterK, 51U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterC, 14U)) + aOrbiterG);
            aWandererB = aWandererB + ((RotL64(aScatter, 10U) + aOrbiterF) + RotL64(aOrbiterB, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 22U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 35U) ^ RotL64(aNonceWordD, 58U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22809U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((aIndex + 24801U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 12U) ^ RotL64(aNonceWordE, 35U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22818U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((aIndex + 24828U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 44U)) + (RotL64(aIngress, 19U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererA + RotL64(aScatter, 12U)) + RotL64(aCarry, 3U)) + 11274974230580265396U;
            aOrbiterD = (aWandererB + RotL64(aCross, 57U)) + 16658438747342741547U;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 21U)) + 16612986966106053844U) + RotL64(aNonceWordE, 53U);
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 27U)) + 9329502236843231290U) + RotL64(aNonceWordC, 15U);
            aOrbiterH = ((aWandererC + RotL64(aIngress, 39U)) + 14088261356708344656U) + aOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = ((aWandererH + RotL64(aCross, 43U)) + RotL64(aCarry, 11U)) + 13692608802007789581U;
            aOrbiterC = (aWandererG + RotL64(aScatter, 3U)) + 6824473946645682398U;
            aOrbiterK = (((aWandererD + RotL64(aPrevious, 51U)) + RotL64(aCarry, 57U)) + 2072915876348570040U) + aOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aCross, 34U)) + 7420507753044460759U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 4677557318688502593U) + RotL64(aNonceWordD, 59U);
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 15081678577055628459U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16659305295251177155U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 7026792817486507482U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 14871665922943969918U;
            aOrbiterG = RotL64((aOrbiterG * 694073180313083145U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 6807734532159292872U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 17882797335141303280U;
            aOrbiterK = RotL64((aOrbiterK * 15439872930381050291U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 9233542707022629190U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 1205501586581350876U;
            aOrbiterJ = RotL64((aOrbiterJ * 2596053290311090589U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 10878718669747466677U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 8066049063548639241U;
            aOrbiterF = RotL64((aOrbiterF * 3031382633089381605U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 861295180226875235U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 9134969787937288583U;
            aOrbiterE = RotL64((aOrbiterE * 7565008208670843555U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 6726642007159809594U) + aOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 8061661744643240470U;
            aOrbiterC = RotL64((aOrbiterC * 6703498926835391813U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 13541412083111962884U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 8617442758729315637U) ^ aOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15471862889276160953U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 16884403561131293362U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 9490680911678221233U) ^ RotL64(aNonceWordA, 12U);
            aOrbiterH = RotL64((aOrbiterH * 15988763830018001033U), 35U);
            //
            aIngress = RotL64(aOrbiterI, 44U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterG, 37U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterC, 51U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 48U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aScatter, 30U) + aOrbiterH) + RotL64(aOrbiterD, 11U)) + RotL64(aNonceWordG, 25U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 47U) + aOrbiterH) + RotL64(aOrbiterK, 51U)) + aWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 21U) + aOrbiterE) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterC, 60U)) + aWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 26U) + RotL64(aOrbiterJ, 35U)) + aOrbiterD) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 53U) + aOrbiterI) + RotL64(aOrbiterD, 39U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterG, 23U)) + aOrbiterE) + RotL64(aNonceWordF, 51U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterI, 28U));
            aWandererA = aWandererA + ((RotL64(aScatter, 5U) + aOrbiterK) + RotL64(aOrbiterE, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 38U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 23U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 29U) ^ RotL64(aNonceWordC, 39U)) ^ RotL64(aNonceWordH, 3U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31894U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((aIndex + 29082U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 11U) ^ RotL64(aNonceWordD, 3U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30939U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneB[((aIndex + 30862U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aPrevious, 54U)) ^ (RotL64(aIngress, 19U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (((aWandererI + RotL64(aIngress, 53U)) + 5697928251815176134U) + aOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1]) + RotL64(aNonceWordG, 25U);
            aOrbiterB = (aWandererC + RotL64(aCross, 28U)) + 337587740689259575U;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 3U)) + 4927686903263973950U;
            aOrbiterI = (aWandererG + RotL64(aScatter, 11U)) + 3742409032569801033U;
            aOrbiterF = (aWandererJ + RotL64(aIngress, 35U)) + 1608092659172197650U;
            aOrbiterD = ((aWandererA + RotL64(aCross, 40U)) + RotL64(aCarry, 23U)) + 15848744267145717509U;
            aOrbiterH = (((aWandererE + RotL64(aScatter, 57U)) + RotL64(aCarry, 13U)) + 15300174177963339253U) + aOrbiterAssignSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 47U)) + 14162868453323648628U;
            aOrbiterA = (((aWandererK + RotL64(aIngress, 19U)) + RotL64(aCarry, 53U)) + 12020167069983729869U) + RotL64(aNonceWordC, 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 16259538291658723956U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 8516686212464112245U) ^ aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4731296903548893627U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 3722184575520553132U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 5663609293306386784U;
            aOrbiterF = RotL64((aOrbiterF * 14364218128780764749U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 15265344442454471986U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 3050323350098829515U;
            aOrbiterH = RotL64((aOrbiterH * 5890624677162388135U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 1093356813820599238U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 15167726103772238440U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5719466863561311069U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 15170797965325981472U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 17826286701992981628U) ^ aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11186808881726573677U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 14710892030473425181U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 397194787697553904U;
            aOrbiterG = RotL64((aOrbiterG * 14368930300818752833U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 1273724124862533034U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 13018397560392545616U;
            aOrbiterI = RotL64((aOrbiterI * 4644812473262395329U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 9638716186445643730U) + RotL64(aNonceWordF, 22U);
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 7255587739807843785U) ^ RotL64(aNonceWordH, 3U);
            aOrbiterD = RotL64((aOrbiterD * 6055682981584011189U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 9272350563697399628U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 1040729335295009339U;
            aOrbiterB = RotL64((aOrbiterB * 17825687660830291443U), 37U);
            //
            aIngress = RotL64(aOrbiterJ, 52U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 27U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterE, 37U)) + aOrbiterF);
            aWandererA = aWandererA + (((RotL64(aScatter, 23U) + RotL64(aOrbiterG, 19U)) + aOrbiterA) + RotL64(aCarry, 13U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterB, 58U)) + aOrbiterA) + aWandererUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 13U) + RotL64(aOrbiterD, 13U)) + aOrbiterB) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 27U) + aOrbiterI) + RotL64(aOrbiterF, 51U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterI, 5U)) + aOrbiterJ) + aWandererUpdateSaltD[((aIndex + 12U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 4U) + RotL64(aOrbiterD, 43U)) + aOrbiterH) + RotL64(aNonceWordB, 43U));
            aWandererC = aWandererC + ((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterH, 47U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterI, 30U)) + aOrbiterH) + RotL64(aNonceWordE, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 30U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererC, 43U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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

void Soccer_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xA1B5D057E07BFA29ULL + 0xF2BE2D32E86DA865ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x828ED9D5A992088FULL + 0x8503568DC9B76BC2ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xCFB159602B627009ULL + 0xDCFDCB761F98E228ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xA9A94A2D06EF241BULL + 0xCBCA7706759505AEULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xF98163B71CE6374BULL + 0x9670253EFCB3C77EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xB91E449C67F4D195ULL + 0x8CDECE12D6E3E474ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xCFF3148E6EC97979ULL + 0x9143BEB4FE3A9A5AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x9459BAA33FEE32B7ULL + 0x99ADCB5993426D32ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 53U) ^ RotL64(aNonceWordD, 13U)) ^ RotL64(aNonceWordF, 43U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 329U)) & S_BLOCK1], 4U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 2435U)) & W_KEY1], 27U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 44U) ^ RotL64(aNonceWordA, 5U)) ^ RotL64(aNonceWordE, 57U));
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 4299U)) & W_KEY1], 35U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 4481U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCross, 47U)) + (RotL64(aCarry, 6U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterF = ((aWandererB + RotL64(aIngress, 51U)) + 5697928251815176134U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aPrevious, 57U)) + 337587740689259575U;
            aOrbiterD = (aWandererI + RotL64(aCross, 5U)) + 4927686903263973950U;
            aOrbiterJ = (((aWandererA + RotL64(aScatter, 41U)) + RotL64(aCarry, 13U)) + 3742409032569801033U) + RotL64(aNonceWordD, 15U);
            aOrbiterE = (((aWandererK + RotL64(aPrevious, 23U)) + RotL64(aCarry, 57U)) + 1608092659172197650U) + RotL64(aNonceWordC, 45U);
            aOrbiterG = (((aWandererH + RotL64(aIngress, 14U)) + RotL64(aCarry, 39U)) + 15848744267145717509U) + aPhaseAOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aScatter, 29U)) + 15300174177963339253U;
            //
            aOrbiterF = (((aOrbiterF + aOrbiterH) + 14162868453323648628U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1]) + RotL64(aNonceWordE, 43U);
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 12020167069983729869U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2071080217680099017U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 16259538291658723956U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 8516686212464112245U) ^ RotL64(aNonceWordH, 7U);
            aOrbiterE = RotL64((aOrbiterE * 4731296903548893627U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 3722184575520553132U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 5663609293306386784U;
            aOrbiterG = RotL64((aOrbiterG * 14364218128780764749U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 15265344442454471986U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 3050323350098829515U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5890624677162388135U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 1093356813820599238U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 15167726103772238440U;
            aOrbiterF = RotL64((aOrbiterF * 5719466863561311069U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 15170797965325981472U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 17826286701992981628U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11186808881726573677U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 14710892030473425181U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 397194787697553904U;
            aOrbiterH = RotL64((aOrbiterH * 14368930300818752833U), 53U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterD, 58U);
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 21U) + RotL64(aOrbiterE, 47U)) + aOrbiterH) + RotL64(aNonceWordB, 53U)) + aPhaseAWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterG, 41U)) + aOrbiterJ) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 28U) + RotL64(aOrbiterH, 56U)) + aOrbiterK) + aPhaseAWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 29U)) + aOrbiterK);
            aWandererA = aWandererA ^ ((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterD, 19U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 35U)) + aOrbiterD) + RotL64(aCarry, 53U)) + RotL64(aNonceWordG, 46U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 51U) + aOrbiterE) + RotL64(aOrbiterF, 11U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 4U));
            aCarry = aCarry + RotL64(aWandererA, 23U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 24U) ^ RotL64(aNonceWordC, 13U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 5649U)) & S_BLOCK1], 41U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 8390U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 3U) ^ RotL64(aNonceWordE, 11U));
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 7948U)) & W_KEY1], 47U) ^ RotL64(aKeyRowReadB[((aIndex + 6822U)) & W_KEY1], 34U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCross, 40U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterI = (aWandererK + RotL64(aIngress, 13U)) + 10336802574069791273U;
            aOrbiterE = ((aWandererH + RotL64(aScatter, 19U)) + 169025388197058936U) + RotL64(aNonceWordF, 27U);
            aOrbiterF = (((aWandererB + RotL64(aCross, 5U)) + RotL64(aCarry, 37U)) + 6541354188379168846U) + RotL64(aNonceWordC, 59U);
            aOrbiterH = (aWandererA + RotL64(aPrevious, 37U)) + 16223920526599306104U;
            aOrbiterD = (aWandererG + RotL64(aCross, 27U)) + 12756613707692514808U;
            aOrbiterC = (((aWandererF + RotL64(aIngress, 43U)) + RotL64(aCarry, 53U)) + 5082475548176484035U) + aPhaseAOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = (((aWandererC + RotL64(aScatter, 58U)) + RotL64(aCarry, 11U)) + 4907435526952698526U) + aPhaseAOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 14236627073831834337U) + RotL64(aNonceWordB, 9U);
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 11502511046130497584U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3460330807286625917U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 3679044835550219497U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 11254838916686736746U;
            aOrbiterI = RotL64((aOrbiterI * 8631695922983532915U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 10582608424233200966U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 10449735026385340313U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7363770199734997411U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 4628253464169957835U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 17664454668473204465U;
            aOrbiterE = RotL64((aOrbiterE * 4234720298731378527U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 3798386391743884889U) + RotL64(aNonceWordH, 40U);
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 1379331161819246587U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13086160171095077295U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 9816600392407327227U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 16781971616348376878U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12503867584828289879U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 4807797577690520554U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 2492057261148595922U;
            aOrbiterG = RotL64((aOrbiterG * 9453302540675483005U), 27U);
            //
            aIngress = RotL64(aOrbiterF, 57U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + RotL64(aOrbiterI, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 42U) + aOrbiterD) + RotL64(aOrbiterG, 47U)) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterC, 41U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 13U)) + aOrbiterC);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterF, 29U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterD, 53U)) + RotL64(aNonceWordA, 61U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterH, 4U)) + aOrbiterD) + RotL64(aNonceWordD, 21U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 21U) + RotL64(aOrbiterC, 35U)) + aOrbiterI) + RotL64(aCarry, 13U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 52U));
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + RotL64(aWandererB, 23U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 39U) ^ RotL64(aNonceWordD, 11U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 14542U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13125U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 13U) ^ RotL64(aNonceWordB, 58U));
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15937U)) & W_KEY1], 5U) ^ RotL64(aKeyRowReadB[((aIndex + 11406U)) & W_KEY1], 41U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aIngress, 6U)) ^ (RotL64(aPrevious, 51U) + RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterC = ((aWandererF + RotL64(aIngress, 21U)) + 17264605017518259932U) + RotL64(aNonceWordH, 28U);
            aOrbiterH = (aWandererB + RotL64(aPrevious, 35U)) + 15209184354580778643U;
            aOrbiterA = (((aWandererA + RotL64(aScatter, 29U)) + RotL64(aCarry, 35U)) + 3299527965014731384U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (aWandererC + RotL64(aCross, 5U)) + 16293096431816127821U;
            aOrbiterD = (((aWandererE + RotL64(aPrevious, 58U)) + RotL64(aCarry, 51U)) + 11031983436878828337U) + RotL64(aNonceWordF, 57U);
            aOrbiterI = (aWandererI + RotL64(aIngress, 47U)) + 9188018632448236358U;
            aOrbiterE = (((aWandererD + RotL64(aCross, 41U)) + RotL64(aCarry, 5U)) + 13420816400363406556U) + aPhaseAOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 2485063384097917101U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 3089135816938128264U;
            aOrbiterA = RotL64((aOrbiterA * 8813152992957361153U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 10730544971770435788U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = (((aOrbiterH ^ aOrbiterG) ^ 10431767565618874806U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1]) ^ RotL64(aNonceWordB, 25U);
            aOrbiterH = RotL64((aOrbiterH * 4723078464590561545U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 14883796491656899074U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 13465877783538483706U;
            aOrbiterC = RotL64((aOrbiterC * 14311686051108108503U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 13322163435314643713U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 3307316600284371955U;
            aOrbiterG = RotL64((aOrbiterG * 12337846092069506365U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 4950101626975919939U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 2596253994220103666U;
            aOrbiterD = RotL64((aOrbiterD * 7181706961838582889U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 17961706029559914243U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 10321902557977495175U;
            aOrbiterI = RotL64((aOrbiterI * 16189559888625084711U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 18146616411403012772U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterH) ^ 8414050129421955787U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]) ^ RotL64(aNonceWordC, 29U);
            aOrbiterE = RotL64((aOrbiterE * 14879448948196182863U), 35U);
            //
            aIngress = RotL64(aOrbiterD, 57U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + RotL64(aOrbiterE, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterE, 56U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterA, 23U)) + aOrbiterI) + RotL64(aNonceWordE, 21U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 42U) + RotL64(aOrbiterC, 11U)) + aOrbiterG) + RotL64(aCarry, 23U)) + RotL64(aNonceWordG, 7U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterD, 3U)) + aOrbiterG);
            aWandererA = aWandererA + (((RotL64(aCross, 13U) + RotL64(aOrbiterH, 35U)) + aOrbiterA) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterG, 29U));
            aWandererF = aWandererF + (((RotL64(aScatter, 21U) + aOrbiterD) + RotL64(aOrbiterC, 43U)) + aPhaseAWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 40U));
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 13U) ^ RotL64(aNonceWordG, 35U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 17885U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19198U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 39U) ^ RotL64(aNonceWordC, 54U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20049U)) & S_BLOCK1], 19U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 20771U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCross, 11U)) ^ (RotL64(aPrevious, 37U) + RotL64(aCarry, 24U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterC = ((aWandererD + RotL64(aCross, 53U)) + RotL64(aCarry, 57U)) + 11274974230580265396U;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 23U)) + RotL64(aCarry, 23U)) + 16658438747342741547U;
            aOrbiterI = ((aWandererA + RotL64(aIngress, 37U)) + RotL64(aCarry, 11U)) + 16612986966106053844U;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 43U)) + 9329502236843231290U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = (((aWandererC + RotL64(aCross, 5U)) + 14088261356708344656U) + aPhaseAOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1]) + RotL64(aNonceWordF, 28U);
            aOrbiterE = (aWandererK + RotL64(aPrevious, 29U)) + 13692608802007789581U;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 14U)) + 6824473946645682398U) + RotL64(aNonceWordB, 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 2072915876348570040U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 7420507753044460759U;
            aOrbiterI = RotL64((aOrbiterI * 13239288539564571257U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 4677557318688502593U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 15081678577055628459U;
            aOrbiterE = RotL64((aOrbiterE * 16659305295251177155U), 19U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterC) + 7026792817486507482U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]) + RotL64(aNonceWordG, 43U);
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 14871665922943969918U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 694073180313083145U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 6807734532159292872U) + RotL64(aNonceWordE, 11U);
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 17882797335141303280U;
            aOrbiterK = RotL64((aOrbiterK * 15439872930381050291U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 9233542707022629190U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 1205501586581350876U;
            aOrbiterC = RotL64((aOrbiterC * 2596053290311090589U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 10878718669747466677U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 8066049063548639241U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3031382633089381605U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 861295180226875235U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 9134969787937288583U;
            aOrbiterA = RotL64((aOrbiterA * 7565008208670843555U), 11U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterI, 53U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 53U) + aOrbiterA) + RotL64(aOrbiterH, 57U));
            aWandererC = aWandererC + (((RotL64(aIngress, 29U) + RotL64(aOrbiterI, 12U)) + aOrbiterJ) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterK, 29U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 41U) + aOrbiterA) + RotL64(aOrbiterE, 3U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 19U) + aOrbiterC) + RotL64(aOrbiterE, 41U)) + aPhaseAWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererA = aWandererA + (((((RotL64(aCross, 60U) + aOrbiterK) + RotL64(aOrbiterI, 51U)) + RotL64(aCarry, 19U)) + RotL64(aNonceWordC, 49U)) + aPhaseAWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 5U) + aOrbiterK) + RotL64(aOrbiterA, 19U)) + RotL64(aNonceWordA, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 46U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + RotL64(aWandererC, 41U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 12U) ^ RotL64(aNonceWordG, 23U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 24859U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26399U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 34U) ^ RotL64(aNonceWordF, 11U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24216U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((aIndex + 24695U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 50U) + RotL64(aIngress, 23U)) ^ (RotL64(aCross, 11U) + RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterI = (aWandererD + RotL64(aCross, 23U)) + 12775735908960052604U;
            aOrbiterG = (aWandererA + RotL64(aPrevious, 35U)) + 11791373812080296887U;
            aOrbiterC = ((((aWandererE + RotL64(aScatter, 48U)) + RotL64(aCarry, 37U)) + 5537362877706057303U) + aPhaseAOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1]) + RotL64(aNonceWordC, 61U);
            aOrbiterE = (aWandererC + RotL64(aIngress, 57U)) + 2023912048504189380U;
            aOrbiterA = (((aWandererF + RotL64(aCross, 13U)) + RotL64(aCarry, 57U)) + 17668828109963766893U) + RotL64(aNonceWordH, 35U);
            aOrbiterJ = (((aWandererB + RotL64(aIngress, 5U)) + RotL64(aCarry, 13U)) + 558908629933941224U) + aPhaseAOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = (aWandererG + RotL64(aScatter, 41U)) + 1479633119685446888U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 15460320397843364063U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterI) ^ 10059749397555469054U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1]) ^ RotL64(aNonceWordE, 15U);
            aOrbiterC = RotL64((aOrbiterC * 8671817118586065469U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 9987633811929693924U) + RotL64(aNonceWordD, 41U);
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 10087337844580228269U;
            aOrbiterI = RotL64((aOrbiterI * 13817142288940843815U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 4446204415503364254U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 15106063243302192717U;
            aOrbiterE = RotL64((aOrbiterE * 13273756657334709803U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 9430197906134676162U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 1226048679997253363U;
            aOrbiterG = RotL64((aOrbiterG * 14247538885252664127U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 10611580584157624739U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 3137391249289641509U;
            aOrbiterA = RotL64((aOrbiterA * 5462682413239873181U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 9327201928815412810U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 7890659377013147073U;
            aOrbiterJ = RotL64((aOrbiterJ * 13827717178378062047U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 10675114832750356941U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 8804440385852327267U;
            aOrbiterB = RotL64((aOrbiterB * 8520671775587260601U), 51U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 41U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 21U) + aOrbiterC) + RotL64(aOrbiterJ, 29U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterB, 40U)) + RotL64(aCarry, 21U)) + RotL64(aNonceWordB, 39U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 57U)) + aOrbiterI);
            aWandererF = aWandererF + ((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterE, 11U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterE, 23U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterA, 5U)) + aOrbiterB) + RotL64(aCarry, 39U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((((RotL64(aCross, 40U) + aOrbiterG) + RotL64(aOrbiterA, 47U)) + RotL64(aNonceWordG, 10U)) + aPhaseAWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 58U));
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + RotL64(aWandererF, 51U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 48U) ^ RotL64(aNonceWordD, 3U)) ^ RotL64(aNonceWordE, 29U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29016U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((aIndex + 30536U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 29U) ^ RotL64(aNonceWordB, 19U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28584U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27585U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 44U) + RotL64(aIngress, 29U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterK = ((aWandererG + RotL64(aCross, 47U)) + 3339283916456813609U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = ((aWandererB + RotL64(aIngress, 27U)) + RotL64(aCarry, 3U)) + 11339086426180649584U;
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 41U)) + 16819191669329316585U) + RotL64(aNonceWordE, 61U);
            aOrbiterF = ((aWandererK + RotL64(aScatter, 19U)) + RotL64(aCarry, 35U)) + 8361916937762630725U;
            aOrbiterB = ((aWandererC + RotL64(aCross, 57U)) + RotL64(aCarry, 51U)) + 18031328374429899857U;
            aOrbiterJ = (((aWandererF + RotL64(aPrevious, 35U)) + 18261756894092897276U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1]) + RotL64(aNonceWordF, 11U);
            aOrbiterG = (aWandererJ + RotL64(aScatter, 4U)) + 4250319792907645666U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 1492411503643460886U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 17369549067879344180U;
            aOrbiterI = RotL64((aOrbiterI * 2947354306696216579U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 7301713524358676722U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 2985193736033012535U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7473297294949338265U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 14086975808140927408U) + RotL64(aNonceWordC, 41U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 10390516547834639800U;
            aOrbiterJ = RotL64((aOrbiterJ * 11441293212275890819U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 18205555540941493267U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 16967799565443938873U;
            aOrbiterG = RotL64((aOrbiterG * 3009081009044782443U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 9209505304067579944U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 3522631966146762306U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3441982898533162599U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 8811497120829041188U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 14707301680850257294U) ^ RotL64(aNonceWordG, 29U);
            aOrbiterF = RotL64((aOrbiterF * 11383709499376464085U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 10080595991787801029U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 6822892187784299166U;
            aOrbiterH = RotL64((aOrbiterH * 7417016898027778287U), 57U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterH, 60U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + RotL64(aOrbiterG, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 53U) + aOrbiterJ) + RotL64(aOrbiterI, 27U));
            aWandererB = aWandererB + ((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterF, 51U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 5U)) + aOrbiterG) + aPhaseAWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 21U) + RotL64(aOrbiterB, 21U)) + aOrbiterF) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterK, 13U));
            aWandererF = aWandererF + (((((RotL64(aPrevious, 42U) + aOrbiterI) + RotL64(aOrbiterK, 44U)) + RotL64(aCarry, 11U)) + RotL64(aNonceWordH, 52U)) + aPhaseAWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 37U)) + aOrbiterI) + RotL64(aNonceWordA, 17U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 18U));
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererF, 37U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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

void Soccer_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xE2EC7EAD1B73D1C7ULL + 0xB783E018DD74BBE1ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xB45C7D781B8D8867ULL + 0x9A1D4A279D289E88ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xF24235DB0F8C6E5FULL + 0xB265837FAC1EA6DEULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xD76C198B3EC05365ULL + 0xDDB07C6B3ED0306CULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xC19488FD75F92311ULL + 0xA46D3323E73D5F82ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xD68D92B2B37CA787ULL + 0xC5CDE9097F331F56ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xC570A654394A2C95ULL + 0xE21A4A01F76E959CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xCA5C24A540DE6429ULL + 0xBB30F20ECFE49567ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 21U) ^ RotL64(aNonceWordA, 57U)) ^ RotL64(aNonceWordH, 12U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 3561U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneC[((aIndex + 4105U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 47U) ^ RotL64(aNonceWordC, 28U)) ^ RotL64(aNonceWordF, 37U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2976U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 1632U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 47U) ^ RotL64(aIngress, 5U)) + (RotL64(aPrevious, 20U) ^ RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterC = (((aWandererC + RotL64(aPrevious, 19U)) + RotL64(aCarry, 21U)) + 3339283916456813609U) + RotL64(aNonceWordA, 43U);
            aOrbiterH = (((aWandererJ + RotL64(aCross, 58U)) + RotL64(aCarry, 5U)) + 11339086426180649584U) + aPhaseBOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aIngress, 11U)) + 16819191669329316585U) + aPhaseBOrbiterAssignSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = (((aWandererE + RotL64(aScatter, 41U)) + RotL64(aCarry, 37U)) + 8361916937762630725U) + RotL64(aNonceWordD, 18U);
            aOrbiterK = (aWandererF + RotL64(aIngress, 29U)) + 18031328374429899857U;
            //
            aOrbiterC = (((aOrbiterC + aOrbiterH) + 18261756894092897276U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]) + RotL64(aNonceWordB, 29U);
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 4250319792907645666U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7053489184750217963U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 1492411503643460886U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 17369549067879344180U;
            aOrbiterC = RotL64((aOrbiterC * 2947354306696216579U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 7301713524358676722U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 2985193736033012535U;
            aOrbiterD = RotL64((aOrbiterD * 7473297294949338265U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 14086975808140927408U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterK) ^ 10390516547834639800U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]) ^ RotL64(aNonceWordH, 51U);
            aOrbiterH = RotL64((aOrbiterH * 11441293212275890819U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 18205555540941493267U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 16967799565443938873U;
            aOrbiterK = RotL64((aOrbiterK * 3009081009044782443U), 39U);
            //
            aIngress = RotL64(aOrbiterH, 47U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + RotL64(aOrbiterD, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterC, 51U)) + RotL64(aCarry, 53U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterH, 60U)) + aOrbiterD) + RotL64(aNonceWordE, 13U));
            aWandererB = aWandererB + (((RotL64(aScatter, 60U) + RotL64(aOrbiterH, 39U)) + aOrbiterK) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 41U) + aOrbiterC) + RotL64(aOrbiterE, 27U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterE, 5U)) + RotL64(aNonceWordG, 9U)) + aPhaseBWandererUpdateSaltB[((aIndex + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 34U));
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 51U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 35U) ^ RotL64(aNonceWordH, 23U)) ^ RotL64(aNonceWordA, 4U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9189U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 7017U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 30U) ^ RotL64(aNonceWordG, 57U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10774U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((aIndex + 9924U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 60U) + RotL64(aPrevious, 27U)) ^ (RotL64(aCross, 47U) ^ RotL64(aIngress, 13U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterG = (((aWandererB + RotL64(aScatter, 60U)) + RotL64(aCarry, 37U)) + 5697928251815176134U) + RotL64(aNonceWordH, 3U);
            aOrbiterC = (((aWandererG + RotL64(aCross, 21U)) + RotL64(aCarry, 21U)) + 337587740689259575U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (((aWandererC + RotL64(aIngress, 13U)) + 4927686903263973950U) + aPhaseBOrbiterAssignSaltF[((aIndex + 20U)) & S_SALT1]) + RotL64(aNonceWordB, 61U);
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 47U)) + RotL64(aCarry, 57U)) + 3742409032569801033U;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 5U)) + 1608092659172197650U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 15848744267145717509U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 15300174177963339253U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5771922862677667319U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 14162868453323648628U) + RotL64(aNonceWordC, 45U);
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 12020167069983729869U;
            aOrbiterH = RotL64((aOrbiterH * 2071080217680099017U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 16259538291658723956U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 8516686212464112245U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4731296903548893627U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 3722184575520553132U) + RotL64(aNonceWordG, 44U);
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 5663609293306386784U;
            aOrbiterC = RotL64((aOrbiterC * 14364218128780764749U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 15265344442454471986U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 3050323350098829515U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5890624677162388135U), 41U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterG, 13U);
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterD, 52U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterA, 44U)) + aOrbiterD) + aPhaseBWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aCross, 13U) + aOrbiterD) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 3U)) + aPhaseBWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterG, 57U)) + aOrbiterA);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 22U) + aOrbiterC) + RotL64(aOrbiterA, 27U)) + RotL64(aCarry, 27U)) + RotL64(aNonceWordD, 29U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterG, 11U)) + aOrbiterH) + RotL64(aNonceWordE, 55U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 35U) ^ RotL64(aNonceWordG, 43U)) ^ RotL64(aNonceWordC, 13U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13803U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneA[((aIndex + 15236U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 4U) ^ RotL64(aNonceWordF, 13U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15271U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14652U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 24U) + RotL64(aCross, 51U)) ^ (RotL64(aCarry, 5U) + RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterG = (((aWandererF + RotL64(aPrevious, 35U)) + RotL64(aCarry, 5U)) + 10336802574069791273U) + RotL64(aNonceWordD, 47U);
            aOrbiterD = (((aWandererA + RotL64(aIngress, 46U)) + 169025388197058936U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1]) + RotL64(aNonceWordE, 23U);
            aOrbiterC = (aWandererH + RotL64(aScatter, 5U)) + 6541354188379168846U;
            aOrbiterI = ((aWandererE + RotL64(aCross, 13U)) + RotL64(aCarry, 35U)) + 16223920526599306104U;
            aOrbiterK = (((aWandererD + RotL64(aIngress, 57U)) + RotL64(aCarry, 57U)) + 12756613707692514808U) + aPhaseBOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 5082475548176484035U) + RotL64(aNonceWordB, 15U);
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 4907435526952698526U) ^ RotL64(aNonceWordG, 25U);
            aOrbiterC = RotL64((aOrbiterC * 1379692095754989215U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 14236627073831834337U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 11502511046130497584U;
            aOrbiterD = RotL64((aOrbiterD * 3460330807286625917U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 3679044835550219497U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 11254838916686736746U;
            aOrbiterG = RotL64((aOrbiterG * 8631695922983532915U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 10582608424233200966U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 10449735026385340313U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7363770199734997411U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 4628253464169957835U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 17664454668473204465U;
            aOrbiterK = RotL64((aOrbiterK * 4234720298731378527U), 23U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 37U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterK, 5U)) + aOrbiterC) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aCross, 3U) + RotL64(aOrbiterG, 13U)) + aOrbiterD) + RotL64(aCarry, 11U)) + RotL64(aNonceWordC, 38U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterC, 35U)) + aOrbiterD) + RotL64(aNonceWordF, 35U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 54U) + aOrbiterI) + RotL64(aOrbiterG, 51U)) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterG, 22U)) + aOrbiterC) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 48U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + RotL64(aWandererF, 39U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 5U) ^ RotL64(aNonceWordB, 29U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 17574U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21706U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 35U) ^ RotL64(aNonceWordF, 43U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17345U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((aIndex + 21386U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCarry, 29U)) + (RotL64(aPrevious, 12U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterA = (aWandererG + RotL64(aPrevious, 3U)) + 11274974230580265396U;
            aOrbiterC = (((aWandererB + RotL64(aCross, 29U)) + RotL64(aCarry, 29U)) + 16658438747342741547U) + aPhaseBOrbiterAssignSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aIngress, 54U)) + 16612986966106053844U;
            aOrbiterD = (((aWandererF + RotL64(aScatter, 13U)) + RotL64(aCarry, 57U)) + 9329502236843231290U) + RotL64(aNonceWordG, 4U);
            aOrbiterJ = ((((aWandererC + RotL64(aPrevious, 39U)) + RotL64(aCarry, 11U)) + 14088261356708344656U) + aPhaseBOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1]) + RotL64(aNonceWordA, 17U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 13692608802007789581U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 6824473946645682398U;
            aOrbiterK = RotL64((aOrbiterK * 13619437545775237601U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 2072915876348570040U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 7420507753044460759U) ^ RotL64(aNonceWordE, 35U);
            aOrbiterA = RotL64((aOrbiterA * 13239288539564571257U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 4677557318688502593U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 15081678577055628459U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16659305295251177155U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 7026792817486507482U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 14871665922943969918U;
            aOrbiterC = RotL64((aOrbiterC * 694073180313083145U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 6807734532159292872U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterK) ^ 17882797335141303280U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]) ^ RotL64(aNonceWordH, 51U);
            aOrbiterJ = RotL64((aOrbiterJ * 15439872930381050291U), 3U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterD, 13U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + RotL64(aOrbiterC, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterC, 19U)) + aOrbiterK) + aPhaseBWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aScatter, 51U) + aOrbiterA) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 41U)) + RotL64(aNonceWordC, 23U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterD, 60U)) + aOrbiterJ) + RotL64(aNonceWordB, 37U));
            aWandererG = aWandererG + (((RotL64(aCross, 60U) + RotL64(aOrbiterD, 51U)) + aOrbiterA) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 29U)) + aOrbiterD) + aPhaseBWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 56U));
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 29U) ^ RotL64(aNonceWordE, 41U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 23598U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneA[((aIndex + 24844U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 3U) ^ RotL64(aNonceWordF, 56U)) ^ RotL64(aNonceWordB, 41U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23385U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24936U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCross, 24U)) + (RotL64(aCarry, 5U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterE = (((aWandererH + RotL64(aIngress, 29U)) + RotL64(aCarry, 21U)) + 17264605017518259932U) + RotL64(aNonceWordA, 18U);
            aOrbiterF = ((aWandererK + RotL64(aCross, 57U)) + 15209184354580778643U) + aPhaseBOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = (aWandererD + RotL64(aScatter, 37U)) + 3299527965014731384U;
            aOrbiterA = (((aWandererA + RotL64(aPrevious, 18U)) + RotL64(aCarry, 41U)) + 16293096431816127821U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (((aWandererI + RotL64(aCross, 47U)) + RotL64(aCarry, 3U)) + 11031983436878828337U) + RotL64(aNonceWordG, 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 9188018632448236358U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 13420816400363406556U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10958221259662190519U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 2485063384097917101U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 3089135816938128264U;
            aOrbiterK = RotL64((aOrbiterK * 8813152992957361153U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 10730544971770435788U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 10431767565618874806U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4723078464590561545U), 29U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterK) + 14883796491656899074U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1]) + RotL64(aNonceWordF, 41U);
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 13465877783538483706U;
            aOrbiterF = RotL64((aOrbiterF * 14311686051108108503U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 13322163435314643713U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 3307316600284371955U) ^ RotL64(aNonceWordD, 5U);
            aOrbiterA = RotL64((aOrbiterA * 12337846092069506365U), 57U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 39U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + RotL64(aOrbiterE, 14U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterE, 51U)) + RotL64(aCarry, 53U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 26U) + RotL64(aOrbiterK, 27U)) + aOrbiterJ) + RotL64(aNonceWordH, 17U));
            aWandererK = aWandererK + (((((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterF, 43U)) + RotL64(aCarry, 13U)) + RotL64(aNonceWordC, 51U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterK, 14U));
            aWandererH = aWandererH + ((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterJ, 3U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 34U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 21U) ^ RotL64(aNonceWordF, 43U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 29389U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneB[((aIndex + 29333U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 58U) ^ RotL64(aNonceWordD, 5U)) ^ RotL64(aNonceWordG, 19U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28087U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28579U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 19U) + RotL64(aPrevious, 51U)) + (RotL64(aCross, 4U) ^ RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterE = (aWandererJ + RotL64(aIngress, 23U)) + 12775735908960052604U;
            aOrbiterF = (((aWandererI + RotL64(aPrevious, 47U)) + RotL64(aCarry, 13U)) + 11791373812080296887U) + RotL64(aNonceWordD, 7U);
            aOrbiterK = (aWandererA + RotL64(aScatter, 5U)) + 5537362877706057303U;
            aOrbiterD = ((((aWandererE + RotL64(aCross, 35U)) + RotL64(aCarry, 51U)) + 2023912048504189380U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1]) + RotL64(aNonceWordG, 53U);
            aOrbiterG = (((aWandererG + RotL64(aIngress, 14U)) + RotL64(aCarry, 27U)) + 17668828109963766893U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 558908629933941224U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 1479633119685446888U) ^ RotL64(aNonceWordB, 55U);
            aOrbiterK = RotL64((aOrbiterK * 4447153373540811385U), 47U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterE) + 15460320397843364063U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1]) + RotL64(aNonceWordA, 20U);
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 10059749397555469054U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8671817118586065469U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 9987633811929693924U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 10087337844580228269U;
            aOrbiterE = RotL64((aOrbiterE * 13817142288940843815U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 4446204415503364254U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 15106063243302192717U;
            aOrbiterD = RotL64((aOrbiterD * 13273756657334709803U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 9430197906134676162U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 1226048679997253363U;
            aOrbiterG = RotL64((aOrbiterG * 14247538885252664127U), 11U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterK, 5U);
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterG, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterF, 23U)) + aOrbiterD) + RotL64(aNonceWordH, 25U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterG, 57U)) + RotL64(aCarry, 39U)) + RotL64(aNonceWordE, 49U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 29U) + aOrbiterD) + RotL64(aOrbiterK, 13U)) + aPhaseBWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterE, 46U)) + RotL64(aCarry, 23U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 12U) + aOrbiterE) + RotL64(aOrbiterF, 35U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (RotL64(aWandererA, 54U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 13U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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

void Soccer_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xECCDD4D64727BB81ULL + 0x81327E7E432CC052ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x87853BC5CC5FEDD5ULL + 0x898BFBDA5CFCA6A1ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x8B998D3DE6B01A19ULL + 0xA35D5892D91F28FBULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x8E812A2C5D9BFB0BULL + 0xE24D27F7EA7C9345ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xD43713DF5FA149CFULL + 0xFAE2402B396A9C63ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xE20BD9F7D6CD5B4DULL + 0xBD7D6B7A140CD2B8ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xAB8CBB6D20A5CDCFULL + 0xC3BF4A186197B2FCULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xFF75DD8AB9AFD755ULL + 0xED43FC2CB43C9CC3ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 28U) ^ RotL64(aNonceWordA, 37U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 4021U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 6697U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 43U) ^ RotL64(aNonceWordE, 13U)) ^ RotL64(aNonceWordC, 23U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 3428U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((aIndex + 6473U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 24U) ^ RotL64(aIngress, 53U)) + (RotL64(aPrevious, 37U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 51U)) + 5697928251815176134U) + RotL64(aNonceWordG, 19U);
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 57U)) + RotL64(aCarry, 47U)) + 337587740689259575U;
            aOrbiterD = (((aWandererK + RotL64(aScatter, 12U)) + RotL64(aCarry, 37U)) + 4927686903263973950U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = (aWandererH + RotL64(aCross, 47U)) + 3742409032569801033U;
            aOrbiterF = (aWandererB + RotL64(aIngress, 27U)) + 1608092659172197650U;
            aOrbiterB = (aWandererA + RotL64(aScatter, 23U)) + 15848744267145717509U;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 19U)) + RotL64(aCarry, 5U)) + 15300174177963339253U;
            aOrbiterJ = (aWandererC + RotL64(aCross, 3U)) + 14162868453323648628U;
            aOrbiterA = (((aWandererF + RotL64(aPrevious, 38U)) + 12020167069983729869U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 6U)) & S_SALT1]) + RotL64(aNonceWordC, 17U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 16259538291658723956U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 8516686212464112245U;
            aOrbiterD = RotL64((aOrbiterD * 4731296903548893627U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 3722184575520553132U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 5663609293306386784U;
            aOrbiterB = RotL64((aOrbiterB * 14364218128780764749U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 15265344442454471986U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 3050323350098829515U) ^ RotL64(aNonceWordD, 20U);
            aOrbiterJ = RotL64((aOrbiterJ * 5890624677162388135U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 1093356813820599238U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 15167726103772238440U;
            aOrbiterA = RotL64((aOrbiterA * 5719466863561311069U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 15170797965325981472U) + RotL64(aNonceWordH, 31U);
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 17826286701992981628U;
            aOrbiterC = RotL64((aOrbiterC * 11186808881726573677U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 14710892030473425181U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 397194787697553904U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14368930300818752833U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 1273724124862533034U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 13018397560392545616U;
            aOrbiterH = RotL64((aOrbiterH * 4644812473262395329U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 9638716186445643730U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 7255587739807843785U;
            aOrbiterE = RotL64((aOrbiterE * 6055682981584011189U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 9272350563697399628U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 1040729335295009339U;
            aOrbiterF = RotL64((aOrbiterF * 17825687660830291443U), 11U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterH, 47U);
            aIngress = aIngress + (RotL64(aOrbiterB, 6U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterG, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 58U) + aOrbiterF) + RotL64(aOrbiterA, 37U));
            aWandererE = aWandererE + ((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterJ, 60U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 43U)) + aOrbiterF);
            aWandererB = aWandererB + (((RotL64(aPrevious, 5U) + aOrbiterC) + RotL64(aOrbiterB, 23U)) + RotL64(aNonceWordF, 9U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 39U) + aOrbiterA) + RotL64(aOrbiterD, 53U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 12U) + aOrbiterB) + RotL64(aOrbiterE, 10U)) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterC, 47U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 23U) + aOrbiterB) + RotL64(aOrbiterH, 5U)) + RotL64(aCarry, 37U)) + RotL64(aNonceWordE, 7U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterB, 29U)) + aOrbiterG) + aPhaseCWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 60U));
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 53U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 11U) ^ RotL64(aNonceWordG, 19U)) ^ RotL64(aNonceWordF, 29U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9484U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneD[((aIndex + 11046U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 19U) ^ RotL64(aNonceWordD, 27U)) ^ RotL64(aNonceWordB, 57U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 16299U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((aIndex + 11130U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 29U) ^ RotL64(aCarry, 57U)) ^ (RotL64(aIngress, 44U) + RotL64(aCross, 13U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterE = ((aWandererA + RotL64(aScatter, 6U)) + 10336802574069791273U) + aPhaseCOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = (aWandererH + RotL64(aIngress, 57U)) + 169025388197058936U;
            aOrbiterK = (aWandererB + RotL64(aCross, 29U)) + 6541354188379168846U;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 51U)) + 16223920526599306104U;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 21U)) + RotL64(aCarry, 23U)) + 12756613707692514808U;
            aOrbiterB = (((aWandererJ + RotL64(aPrevious, 35U)) + RotL64(aCarry, 11U)) + 5082475548176484035U) + RotL64(aNonceWordH, 43U);
            aOrbiterH = ((aWandererE + RotL64(aScatter, 43U)) + RotL64(aCarry, 41U)) + 4907435526952698526U;
            aOrbiterD = ((aWandererC + RotL64(aCross, 14U)) + 14236627073831834337U) + RotL64(aNonceWordF, 49U);
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 47U)) + 11502511046130497584U) + aPhaseCOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 3679044835550219497U) + RotL64(aNonceWordE, 3U);
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 11254838916686736746U;
            aOrbiterK = RotL64((aOrbiterK * 8631695922983532915U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 10582608424233200966U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 10449735026385340313U;
            aOrbiterA = RotL64((aOrbiterA * 7363770199734997411U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 4628253464169957835U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 17664454668473204465U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4234720298731378527U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 3798386391743884889U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 1379331161819246587U;
            aOrbiterD = RotL64((aOrbiterD * 13086160171095077295U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 9816600392407327227U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 16781971616348376878U) ^ RotL64(aNonceWordG, 42U);
            aOrbiterC = RotL64((aOrbiterC * 12503867584828289879U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 4807797577690520554U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 2492057261148595922U;
            aOrbiterE = RotL64((aOrbiterE * 9453302540675483005U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 7909676419643119585U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 256053568910383007U;
            aOrbiterI = RotL64((aOrbiterI * 11965085163352053161U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 16179914439220412472U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 3968867762761955845U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7473632378251893139U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 7474832923901283742U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 4736994731050735779U;
            aOrbiterJ = RotL64((aOrbiterJ * 9839654409121414047U), 47U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 43U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 37U));
            aIngress = aIngress + (RotL64(aOrbiterC, 51U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterE, 4U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterK, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterE, 38U)) + aOrbiterA);
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterJ, 57U)) + RotL64(aNonceWordC, 35U)) + aPhaseCWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterC, 23U)) + aOrbiterH) + RotL64(aCarry, 57U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterB, 43U)) + aOrbiterD);
            aWandererI = aWandererI + (((RotL64(aScatter, 6U) + aOrbiterC) + RotL64(aOrbiterI, 29U)) + RotL64(aCarry, 13U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 51U)) + aOrbiterA) + RotL64(aNonceWordA, 41U));
            aWandererB = aWandererB + ((RotL64(aCross, 19U) + aOrbiterA) + RotL64(aOrbiterB, 34U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 37U) + aOrbiterA) + RotL64(aOrbiterC, 3U));
            aWandererH = aWandererH + ((RotL64(aScatter, 12U) + aOrbiterK) + RotL64(aOrbiterI, 19U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 60U));
            aCarry = aCarry + RotL64(aWandererH, 27U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 14U) ^ RotL64(aNonceWordH, 47U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 19265U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((aIndex + 17579U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 30U) ^ RotL64(aNonceWordD, 21U)) ^ RotL64(aNonceWordC, 47U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 22653U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((aIndex + 21771U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aPrevious, 21U)) + (RotL64(aIngress, 39U) ^ RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterF = ((aWandererD + RotL64(aScatter, 40U)) + RotL64(aCarry, 21U)) + 12775735908960052604U;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 19U)) + 11791373812080296887U) + RotL64(aNonceWordC, 42U);
            aOrbiterH = (aWandererH + RotL64(aIngress, 27U)) + 5537362877706057303U;
            aOrbiterI = ((aWandererC + RotL64(aCross, 23U)) + 2023912048504189380U) + aPhaseCOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (((aWandererE + RotL64(aIngress, 35U)) + RotL64(aCarry, 3U)) + 17668828109963766893U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aScatter, 46U)) + 558908629933941224U) + RotL64(aNonceWordB, 7U);
            aOrbiterE = (aWandererG + RotL64(aPrevious, 53U)) + 1479633119685446888U;
            aOrbiterD = ((aWandererA + RotL64(aCross, 57U)) + RotL64(aCarry, 35U)) + 15460320397843364063U;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 13U)) + 10059749397555469054U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 9987633811929693924U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 10087337844580228269U;
            aOrbiterH = RotL64((aOrbiterH * 13817142288940843815U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 4446204415503364254U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 15106063243302192717U;
            aOrbiterF = RotL64((aOrbiterF * 13273756657334709803U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 9430197906134676162U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 1226048679997253363U;
            aOrbiterI = RotL64((aOrbiterI * 14247538885252664127U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 10611580584157624739U) + RotL64(aNonceWordG, 11U);
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 3137391249289641509U;
            aOrbiterB = RotL64((aOrbiterB * 5462682413239873181U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 9327201928815412810U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 7890659377013147073U;
            aOrbiterK = RotL64((aOrbiterK * 13827717178378062047U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 10675114832750356941U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 8804440385852327267U;
            aOrbiterC = RotL64((aOrbiterC * 8520671775587260601U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 12871947817782057116U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 11015991745792051390U;
            aOrbiterE = RotL64((aOrbiterE * 17152451500505815031U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 6320437975845673731U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 702457937087191287U;
            aOrbiterD = RotL64((aOrbiterD * 17491257114676739589U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 16629064896250312921U) + RotL64(aNonceWordA, 61U);
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 6054107387816339103U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6983767878966747219U), 23U);
            //
            aIngress = RotL64(aOrbiterH, 6U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + RotL64(aOrbiterF, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterD, 10U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((RotL64(aCross, 23U) + RotL64(aOrbiterD, 47U)) + aOrbiterF);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 56U) + RotL64(aOrbiterI, 27U)) + aOrbiterG) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 39U) + aOrbiterB) + RotL64(aOrbiterH, 57U));
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 27U) + aOrbiterK) + RotL64(aOrbiterE, 14U)) + RotL64(aNonceWordF, 21U)) + aPhaseCWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 43U) + RotL64(aOrbiterC, 53U)) + aOrbiterI) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterE, 41U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 19U) + aOrbiterD) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 4U) + RotL64(aOrbiterE, 35U)) + aOrbiterC) + RotL64(aNonceWordD, 27U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 30U));
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 27U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 39U) ^ RotL64(aNonceWordG, 53U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 30082U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((aIndex + 32164U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 13U) ^ RotL64(aNonceWordD, 23U)) ^ RotL64(aNonceWordB, 51U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32657U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneD[((aIndex + 26334U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCross, 21U)) ^ (RotL64(aPrevious, 37U) + RotL64(aCarry, 50U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterC = (((aWandererI + RotL64(aScatter, 43U)) + RotL64(aCarry, 29U)) + 3339283916456813609U) + aPhaseCOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 3U)) + 11339086426180649584U) + RotL64(aNonceWordE, 12U);
            aOrbiterI = ((aWandererB + RotL64(aCross, 10U)) + RotL64(aCarry, 53U)) + 16819191669329316585U;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 39U)) + 8361916937762630725U) + RotL64(aNonceWordH, 23U);
            aOrbiterA = (aWandererD + RotL64(aPrevious, 51U)) + 18031328374429899857U;
            aOrbiterE = (aWandererF + RotL64(aCross, 27U)) + 18261756894092897276U;
            aOrbiterG = (aWandererK + RotL64(aScatter, 21U)) + 4250319792907645666U;
            aOrbiterF = (((aWandererG + RotL64(aIngress, 35U)) + RotL64(aCarry, 41U)) + 1492411503643460886U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = (aWandererA + RotL64(aCross, 58U)) + 17369549067879344180U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 7301713524358676722U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 2985193736033012535U;
            aOrbiterI = RotL64((aOrbiterI * 7473297294949338265U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 14086975808140927408U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 10390516547834639800U;
            aOrbiterA = RotL64((aOrbiterA * 11441293212275890819U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 18205555540941493267U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 16967799565443938873U;
            aOrbiterG = RotL64((aOrbiterG * 3009081009044782443U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 9209505304067579944U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 3522631966146762306U;
            aOrbiterC = RotL64((aOrbiterC * 3441982898533162599U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 8811497120829041188U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 14707301680850257294U;
            aOrbiterK = RotL64((aOrbiterK * 11383709499376464085U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 10080595991787801029U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 6822892187784299166U) ^ RotL64(aNonceWordF, 15U);
            aOrbiterE = RotL64((aOrbiterE * 7417016898027778287U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 1981637172055758689U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 16463077485583119324U;
            aOrbiterF = RotL64((aOrbiterF * 2876782050665869121U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 8383837717361569465U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterA) ^ 2788511294985017326U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]) ^ RotL64(aNonceWordC, 57U);
            aOrbiterB = RotL64((aOrbiterB * 2809163242875130677U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 3529607472855930041U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 8850940802020173766U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7821450253655655943U), 19U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterC, 35U);
            aIngress = aIngress + (RotL64(aOrbiterF, 51U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterD, 60U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 23U) + aOrbiterF) + RotL64(aOrbiterC, 19U));
            aWandererD = aWandererD + (((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 42U)) + aOrbiterK) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 52U) + aOrbiterE) + RotL64(aOrbiterF, 47U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterE, 57U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 13U) + aOrbiterB) + RotL64(aOrbiterK, 11U)) + aPhaseCWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 51U)) + RotL64(aNonceWordA, 31U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 29U)) + aOrbiterA);
            aWandererI = aWandererI + ((RotL64(aCross, 27U) + aOrbiterA) + RotL64(aOrbiterG, 38U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 6U) + RotL64(aOrbiterB, 51U)) + aOrbiterF) + RotL64(aNonceWordD, 9U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 4U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 47U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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

void Soccer_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xCF5990A49431C00FULL + 0x98E67C416672F9BDULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xE572E5869C7FD21DULL + 0xFD7076C15F3E3EA0ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xB1150B58E7B8B451ULL + 0x9A98AE1A9FAD97E0ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xB30721C4FD509D73ULL + 0xDE8113242B596632ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x909B40E21F54035FULL + 0xCAED8C58A17F8FB2ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xE123E4E58216B7C7ULL + 0x80E5DBE9E239DA64ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xE5677DE0EE86E31FULL + 0xDAEC66EA00444AEBULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xC1673B79DCE882CFULL + 0x9E060B21F43BE386ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 57U) ^ RotL64(aNonceWordA, 43U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 955U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3018U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 41U) ^ RotL64(aNonceWordE, 27U)) ^ RotL64(aNonceWordD, 3U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4508U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneA[((aIndex + 1599U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 26U) + RotL64(aIngress, 5U)) + (RotL64(aCross, 57U) ^ RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterC = (aWandererC + RotL64(aPrevious, 34U)) + 11274974230580265396U;
            aOrbiterH = (aWandererE + RotL64(aIngress, 41U)) + 16658438747342741547U;
            aOrbiterD = (aWandererI + RotL64(aScatter, 5U)) + 16612986966106053844U;
            aOrbiterJ = ((aWandererH + RotL64(aCross, 39U)) + 9329502236843231290U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = (((aWandererJ + RotL64(aScatter, 60U)) + RotL64(aCarry, 47U)) + 14088261356708344656U) + aPhaseDOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aIngress, 51U)) + 13692608802007789581U) + RotL64(aNonceWordG, 27U);
            aOrbiterK = (aWandererB + RotL64(aPrevious, 53U)) + 6824473946645682398U;
            aOrbiterB = ((aWandererK + RotL64(aCross, 27U)) + RotL64(aCarry, 57U)) + 2072915876348570040U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 13U)) + 7420507753044460759U;
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 21U)) + RotL64(aCarry, 5U)) + 4677557318688502593U;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 3U)) + 15081678577055628459U) + RotL64(aNonceWordC, 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 7026792817486507482U) + RotL64(aNonceWordE, 35U);
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 14871665922943969918U;
            aOrbiterD = RotL64((aOrbiterD * 694073180313083145U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 6807734532159292872U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 17882797335141303280U;
            aOrbiterG = RotL64((aOrbiterG * 15439872930381050291U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 9233542707022629190U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 1205501586581350876U;
            aOrbiterC = RotL64((aOrbiterC * 2596053290311090589U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 10878718669747466677U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 8066049063548639241U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3031382633089381605U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 861295180226875235U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 9134969787937288583U) ^ RotL64(aNonceWordA, 45U);
            aOrbiterK = RotL64((aOrbiterK * 7565008208670843555U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 6726642007159809594U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 8061661744643240470U;
            aOrbiterI = RotL64((aOrbiterI * 6703498926835391813U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 13541412083111962884U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 8617442758729315637U;
            aOrbiterA = RotL64((aOrbiterA * 15471862889276160953U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 16884403561131293362U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 9490680911678221233U;
            aOrbiterH = RotL64((aOrbiterH * 15988763830018001033U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 10486145044311386738U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 10200001044821063684U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16149790736141571017U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 6997073594007878034U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 13585783612009989767U;
            aOrbiterB = RotL64((aOrbiterB * 11425303157774550449U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 3847846040256340653U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 11274974230580265396U;
            aOrbiterF = RotL64((aOrbiterF * 13970270689108369205U), 41U);
            //
            aIngress = RotL64(aOrbiterE, 19U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterK, 26U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterG, 58U)) + aOrbiterE);
            aWandererK = aWandererK + ((((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 39U)) + aPhaseDWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 23U) + aOrbiterE) + RotL64(aOrbiterF, 51U)) + aPhaseDWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterE, 53U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 34U) + RotL64(aOrbiterK, 13U)) + aOrbiterB) + RotL64(aNonceWordD, 25U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterD, 21U)) + aOrbiterF);
            aWandererG = aWandererG ^ ((RotL64(aCross, 13U) + aOrbiterJ) + RotL64(aOrbiterF, 27U));
            aWandererB = aWandererB + ((RotL64(aIngress, 11U) + RotL64(aOrbiterA, 10U)) + aOrbiterG);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 52U) + RotL64(aOrbiterC, 37U)) + aOrbiterH) + RotL64(aNonceWordB, 30U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterJ, 43U)) + aOrbiterI) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 21U) + aOrbiterB) + RotL64(aOrbiterH, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 36U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererA, 30U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 43U) ^ RotL64(aNonceWordE, 23U)) ^ RotL64(aNonceWordB, 13U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 5605U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((aIndex + 9540U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 47U) ^ RotL64(aNonceWordD, 13U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7445U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((aIndex + 9290U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCarry, 53U)) + (RotL64(aCross, 27U) ^ RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterF = (aWandererC + RotL64(aIngress, 29U)) + 12775735908960052604U;
            aOrbiterA = (aWandererA + RotL64(aPrevious, 42U)) + 11791373812080296887U;
            aOrbiterD = ((aWandererE + RotL64(aScatter, 3U)) + 5537362877706057303U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = (((aWandererB + RotL64(aCross, 51U)) + RotL64(aCarry, 23U)) + 2023912048504189380U) + RotL64(aNonceWordB, 45U);
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 53U)) + 17668828109963766893U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 19U)) + 558908629933941224U) + RotL64(aNonceWordD, 39U);
            aOrbiterJ = (aWandererG + RotL64(aIngress, 26U)) + 1479633119685446888U;
            aOrbiterK = (aWandererD + RotL64(aCross, 37U)) + 15460320397843364063U;
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 57U)) + RotL64(aCarry, 11U)) + 10059749397555469054U;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 39U)) + RotL64(aCarry, 37U)) + 9987633811929693924U;
            aOrbiterC = (aWandererH + RotL64(aCross, 21U)) + 10087337844580228269U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 4446204415503364254U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 15106063243302192717U;
            aOrbiterD = RotL64((aOrbiterD * 13273756657334709803U), 27U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterG) + 9430197906134676162U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]) + RotL64(aNonceWordC, 46U);
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 1226048679997253363U;
            aOrbiterA = RotL64((aOrbiterA * 14247538885252664127U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 10611580584157624739U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 3137391249289641509U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5462682413239873181U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 9327201928815412810U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 7890659377013147073U;
            aOrbiterJ = RotL64((aOrbiterJ * 13827717178378062047U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 10675114832750356941U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 8804440385852327267U;
            aOrbiterH = RotL64((aOrbiterH * 8520671775587260601U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 12871947817782057116U) + RotL64(aNonceWordF, 51U);
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 11015991745792051390U;
            aOrbiterF = RotL64((aOrbiterF * 17152451500505815031U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 6320437975845673731U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 702457937087191287U;
            aOrbiterI = RotL64((aOrbiterI * 17491257114676739589U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 16629064896250312921U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 6054107387816339103U;
            aOrbiterB = RotL64((aOrbiterB * 6983767878966747219U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 13274874838094190290U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 12211422735294360321U;
            aOrbiterK = RotL64((aOrbiterK * 5113738196151089817U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 15338616110718583619U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 1475787183754511373U;
            aOrbiterE = RotL64((aOrbiterE * 10904607643785840003U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 15486810401396777742U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 12775735908960052604U;
            aOrbiterC = RotL64((aOrbiterC * 7478156942468930207U), 29U);
            //
            aIngress = RotL64(aOrbiterE, 21U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterB, 30U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 53U));
            aIngress = aIngress + RotL64(aOrbiterD, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterJ, 60U));
            aWandererF = aWandererF + ((((RotL64(aCross, 58U) + RotL64(aOrbiterF, 5U)) + aOrbiterD) + RotL64(aCarry, 13U)) + aPhaseDWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterF, 19U)) + aOrbiterE);
            aWandererC = aWandererC + ((RotL64(aIngress, 37U) + aOrbiterB) + RotL64(aOrbiterH, 27U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 39U)) + aOrbiterG) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 53U) + RotL64(aOrbiterB, 21U)) + aOrbiterK);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterK, 37U)) + aOrbiterH);
            aWandererI = aWandererI + ((RotL64(aIngress, 51U) + aOrbiterF) + RotL64(aOrbiterG, 3U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 27U) + aOrbiterC) + RotL64(aOrbiterI, 23U)) + RotL64(aNonceWordH, 29U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 5U) + aOrbiterA) + RotL64(aOrbiterG, 44U)) + RotL64(aCarry, 51U)) + RotL64(aNonceWordE, 9U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterC, 47U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 56U));
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + RotL64(aWandererF, 28U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 28U) ^ RotL64(aNonceWordE, 11U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 13591U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((aIndex + 13704U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 56U) ^ RotL64(aNonceWordA, 19U)) ^ RotL64(aNonceWordF, 37U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12151U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13506U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCross, 51U)) ^ (RotL64(aCarry, 20U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 57U)) + RotL64(aCarry, 3U)) + 17264605017518259932U;
            aOrbiterG = (aWandererA + RotL64(aScatter, 27U)) + 15209184354580778643U;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 35U)) + 3299527965014731384U;
            aOrbiterF = (((aWandererE + RotL64(aCross, 51U)) + RotL64(aCarry, 29U)) + 16293096431816127821U) + RotL64(aNonceWordG, 41U);
            aOrbiterE = ((aWandererI + RotL64(aIngress, 48U)) + 11031983436878828337U) + RotL64(aNonceWordC, 46U);
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 53U)) + 9188018632448236358U) + aPhaseDOrbiterAssignSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aCross, 3U)) + 13420816400363406556U;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 21U)) + RotL64(aCarry, 57U)) + 2485063384097917101U;
            aOrbiterH = ((aWandererJ + RotL64(aCross, 11U)) + 3089135816938128264U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (aWandererK + RotL64(aPrevious, 44U)) + 10730544971770435788U;
            aOrbiterK = (aWandererD + RotL64(aScatter, 19U)) + 10431767565618874806U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 14883796491656899074U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 13465877783538483706U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14311686051108108503U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 13322163435314643713U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 3307316600284371955U;
            aOrbiterI = RotL64((aOrbiterI * 12337846092069506365U), 53U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterB) + 4950101626975919939U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]) + RotL64(aNonceWordB, 53U);
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 2596253994220103666U;
            aOrbiterG = RotL64((aOrbiterG * 7181706961838582889U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 17961706029559914243U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 10321902557977495175U;
            aOrbiterE = RotL64((aOrbiterE * 16189559888625084711U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 18146616411403012772U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 8414050129421955787U) ^ RotL64(aNonceWordA, 15U);
            aOrbiterB = RotL64((aOrbiterB * 14879448948196182863U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 11739172334166341121U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 7936637782633487291U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14940929920543800413U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 3160044627483874242U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 16816384076887379704U;
            aOrbiterJ = RotL64((aOrbiterJ * 5052772186568301951U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 8101560104988710226U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 8851416379738817624U;
            aOrbiterF = RotL64((aOrbiterF * 16767420038937389027U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 9941784290055185679U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 14495651885701938495U;
            aOrbiterD = RotL64((aOrbiterD * 1540692851998143607U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 10599676325220702167U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 16092000942942971187U;
            aOrbiterH = RotL64((aOrbiterH * 2457268192247656817U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 16168470945107928109U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 17264605017518259932U;
            aOrbiterK = RotL64((aOrbiterK * 15038386057529909273U), 39U);
            //
            aIngress = RotL64(aOrbiterC, 29U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 44U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 37U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + RotL64(aOrbiterG, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterI, 58U)) + aOrbiterG);
            aWandererG = aWandererG + ((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterA, 3U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterC, 13U)) + aOrbiterB);
            aWandererF = aWandererF + (((((RotL64(aCross, 60U) + RotL64(aOrbiterI, 29U)) + aOrbiterB) + RotL64(aCarry, 47U)) + RotL64(aNonceWordE, 57U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 13U) + aOrbiterF) + RotL64(aOrbiterB, 5U));
            aWandererI = aWandererI + ((RotL64(aCross, 23U) + aOrbiterB) + RotL64(aOrbiterK, 47U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterH, 51U)) + aOrbiterE) + aPhaseDWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 39U) + RotL64(aOrbiterD, 42U)) + aOrbiterB);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 48U) + aOrbiterF) + RotL64(aOrbiterJ, 53U));
            aWandererA = aWandererA + ((((RotL64(aScatter, 5U) + aOrbiterK) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 35U)) + RotL64(aNonceWordH, 35U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterC, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 50U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 14U));
            aCarry = aCarry + RotL64(aWandererK, 39U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 5U) ^ RotL64(aNonceWordG, 58U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 20616U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((aIndex + 21543U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 11U) ^ RotL64(aNonceWordE, 52U)) ^ RotL64(aNonceWordH, 29U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 17413U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16430U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCarry, 35U)) ^ (RotL64(aIngress, 23U) + RotL64(aCross, 4U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterB = ((aWandererD + RotL64(aScatter, 60U)) + 10336802574069791273U) + RotL64(aNonceWordD, 31U);
            aOrbiterK = (aWandererE + RotL64(aIngress, 53U)) + 169025388197058936U;
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 29U)) + 6541354188379168846U) + aPhaseDOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = ((aWandererJ + RotL64(aCross, 13U)) + RotL64(aCarry, 57U)) + 16223920526599306104U;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 39U)) + RotL64(aCarry, 37U)) + 12756613707692514808U;
            aOrbiterA = (aWandererI + RotL64(aScatter, 19U)) + 5082475548176484035U;
            aOrbiterG = ((aWandererK + RotL64(aCross, 23U)) + 4907435526952698526U) + RotL64(aNonceWordG, 21U);
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 43U)) + RotL64(aCarry, 21U)) + 14236627073831834337U;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 51U)) + 11502511046130497584U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = (aWandererG + RotL64(aIngress, 56U)) + 3679044835550219497U;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 27U)) + 11254838916686736746U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 10582608424233200966U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 10449735026385340313U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7363770199734997411U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 4628253464169957835U) + RotL64(aNonceWordC, 42U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 17664454668473204465U;
            aOrbiterJ = RotL64((aOrbiterJ * 4234720298731378527U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 3798386391743884889U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 1379331161819246587U;
            aOrbiterA = RotL64((aOrbiterA * 13086160171095077295U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 9816600392407327227U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 16781971616348376878U) ^ RotL64(aNonceWordB, 41U);
            aOrbiterG = RotL64((aOrbiterG * 12503867584828289879U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 4807797577690520554U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 2492057261148595922U;
            aOrbiterI = RotL64((aOrbiterI * 9453302540675483005U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 7909676419643119585U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 256053568910383007U;
            aOrbiterF = RotL64((aOrbiterF * 11965085163352053161U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 16179914439220412472U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 3968867762761955845U;
            aOrbiterE = RotL64((aOrbiterE * 7473632378251893139U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 7474832923901283742U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 4736994731050735779U;
            aOrbiterD = RotL64((aOrbiterD * 9839654409121414047U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 596484364660389193U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 13822222274464306169U;
            aOrbiterB = RotL64((aOrbiterB * 1723502278319885511U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 16307920280681985443U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 3505106171801702915U;
            aOrbiterK = RotL64((aOrbiterK * 8479675421552861243U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 4987142580981135150U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 10336802574069791273U;
            aOrbiterH = RotL64((aOrbiterH * 2670706512498539705U), 29U);
            //
            aIngress = RotL64(aOrbiterG, 13U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 36U));
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aScatter, 58U) + aOrbiterA) + RotL64(aOrbiterE, 47U));
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 5U) + aOrbiterG) + RotL64(aOrbiterE, 19U)) + RotL64(aNonceWordF, 35U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterI, 60U)) + aOrbiterC) + RotL64(aCarry, 21U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterK, 21U)) + aOrbiterH);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterB, 53U)) + aOrbiterF) + RotL64(aCarry, 5U)) + RotL64(aNonceWordH, 25U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterC, 3U)) + aOrbiterE);
            aWandererF = aWandererF + ((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterD, 51U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 23U) + aOrbiterJ) + RotL64(aOrbiterF, 56U));
            aWandererA = aWandererA + ((RotL64(aScatter, 42U) + aOrbiterG) + RotL64(aOrbiterH, 27U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterA, 11U)) + aOrbiterG);
            aWandererE = aWandererE + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 29U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 46U));
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + RotL64(aWandererI, 13U);
            aCarry = aCarry + RotL64(aIngress, 48U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 14U) ^ RotL64(aNonceWordE, 23U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 27231U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27075U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 5U) ^ RotL64(aNonceWordF, 13U)) ^ RotL64(aNonceWordG, 21U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 21897U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22948U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 53U)) + (RotL64(aCross, 3U) ^ RotL64(aIngress, 38U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterK = (aWandererI + RotL64(aIngress, 54U)) + 5697928251815176134U;
            aOrbiterC = ((aWandererH + RotL64(aCross, 47U)) + 337587740689259575U) + RotL64(aNonceWordB, 59U);
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 51U)) + 4927686903263973950U) + RotL64(aNonceWordD, 17U);
            aOrbiterI = ((aWandererF + RotL64(aScatter, 37U)) + RotL64(aCarry, 47U)) + 3742409032569801033U;
            aOrbiterH = (((aWandererD + RotL64(aPrevious, 5U)) + RotL64(aCarry, 13U)) + 1608092659172197650U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aIngress, 13U)) + 15848744267145717509U;
            aOrbiterG = (((aWandererK + RotL64(aCross, 19U)) + RotL64(aCarry, 41U)) + 15300174177963339253U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (aWandererA + RotL64(aScatter, 29U)) + 14162868453323648628U;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 60U)) + 12020167069983729869U;
            aOrbiterJ = (aWandererC + RotL64(aCross, 21U)) + 16259538291658723956U;
            aOrbiterF = (aWandererG + RotL64(aIngress, 43U)) + 8516686212464112245U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 3722184575520553132U) + RotL64(aNonceWordF, 43U);
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 5663609293306386784U;
            aOrbiterA = RotL64((aOrbiterA * 14364218128780764749U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 15265344442454471986U) + RotL64(aNonceWordC, 41U);
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 3050323350098829515U;
            aOrbiterD = RotL64((aOrbiterD * 5890624677162388135U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 1093356813820599238U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 15167726103772238440U;
            aOrbiterB = RotL64((aOrbiterB * 5719466863561311069U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 15170797965325981472U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 17826286701992981628U;
            aOrbiterJ = RotL64((aOrbiterJ * 11186808881726573677U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 14710892030473425181U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 397194787697553904U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14368930300818752833U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 1273724124862533034U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 13018397560392545616U;
            aOrbiterI = RotL64((aOrbiterI * 4644812473262395329U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 9638716186445643730U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 7255587739807843785U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6055682981584011189U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 9272350563697399628U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 1040729335295009339U;
            aOrbiterE = RotL64((aOrbiterE * 17825687660830291443U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 12128124729613601747U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 2285238815562202219U;
            aOrbiterF = RotL64((aOrbiterF * 15398840993074390573U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 6339113298619163493U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 5911895708485037040U;
            aOrbiterC = RotL64((aOrbiterC * 3271006139923200439U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 7601399508218901328U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 5697928251815176134U;
            aOrbiterH = RotL64((aOrbiterH * 8184257916861355735U), 35U);
            //
            aIngress = RotL64(aOrbiterE, 24U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 37U));
            aIngress = aIngress + RotL64(aOrbiterC, 18U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterD, 3U)) + aPhaseDWandererUpdateSaltB[((aIndex + 24U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 18U) + aOrbiterC) + RotL64(aOrbiterB, 27U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterI, 5U)) + aOrbiterD) + RotL64(aNonceWordA, 16U));
            aWandererD = aWandererD + (((RotL64(aCross, 39U) + aOrbiterB) + RotL64(aOrbiterJ, 51U)) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 37U) + aOrbiterE) + RotL64(aOrbiterF, 18U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterI, 21U)) + aOrbiterF) + RotL64(aNonceWordG, 7U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 12U) + RotL64(aOrbiterA, 43U)) + aOrbiterJ);
            aWandererI = aWandererI + ((RotL64(aCross, 21U) + RotL64(aOrbiterC, 41U)) + aOrbiterH);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 43U) + aOrbiterF) + RotL64(aOrbiterK, 24U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterF, 37U)) + RotL64(aCarry, 29U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterG, 11U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 30U));
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + (RotL64(aWandererB, 34U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererA, 27U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 51U) ^ RotL64(aNonceWordA, 21U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 32467U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28557U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 39U) ^ RotL64(aNonceWordE, 24U)) ^ RotL64(aNonceWordG, 47U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28038U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((aIndex + 28637U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCross, 6U)) + (RotL64(aIngress, 23U) ^ RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 48U)) + 3339283916456813609U) + RotL64(aNonceWordF, 37U);
            aOrbiterA = (((aWandererJ + RotL64(aIngress, 51U)) + RotL64(aCarry, 21U)) + 11339086426180649584U) + aPhaseDOrbiterAssignSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aScatter, 41U)) + 16819191669329316585U;
            aOrbiterH = ((aWandererF + RotL64(aCross, 53U)) + 8361916937762630725U) + aPhaseDOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aIngress, 21U)) + 18031328374429899857U;
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 29U)) + RotL64(aCarry, 57U)) + 18261756894092897276U;
            aOrbiterK = (aWandererA + RotL64(aScatter, 19U)) + 4250319792907645666U;
            aOrbiterC = ((aWandererK + RotL64(aCross, 27U)) + RotL64(aCarry, 51U)) + 1492411503643460886U;
            aOrbiterB = (aWandererC + RotL64(aScatter, 23U)) + 17369549067879344180U;
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 4U)) + 7301713524358676722U) + RotL64(aNonceWordC, 5U);
            aOrbiterJ = (aWandererH + RotL64(aCross, 57U)) + 2985193736033012535U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 14086975808140927408U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 10390516547834639800U;
            aOrbiterE = RotL64((aOrbiterE * 11441293212275890819U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 18205555540941493267U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 16967799565443938873U;
            aOrbiterD = RotL64((aOrbiterD * 3009081009044782443U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 9209505304067579944U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 3522631966146762306U;
            aOrbiterG = RotL64((aOrbiterG * 3441982898533162599U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 8811497120829041188U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 14707301680850257294U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11383709499376464085U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 10080595991787801029U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 6822892187784299166U;
            aOrbiterC = RotL64((aOrbiterC * 7417016898027778287U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 1981637172055758689U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 16463077485583119324U;
            aOrbiterB = RotL64((aOrbiterB * 2876782050665869121U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 8383837717361569465U) + RotL64(aNonceWordA, 23U);
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 2788511294985017326U;
            aOrbiterI = RotL64((aOrbiterI * 2809163242875130677U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 3529607472855930041U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 8850940802020173766U;
            aOrbiterJ = RotL64((aOrbiterJ * 7821450253655655943U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 7469160295100147267U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 16973986572163482061U;
            aOrbiterF = RotL64((aOrbiterF * 15660743778376905023U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 12371372942863279718U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 12098525148034303633U;
            aOrbiterA = RotL64((aOrbiterA * 11234127652230231751U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 5138683482859889480U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 3339283916456813609U) ^ RotL64(aNonceWordB, 31U);
            aOrbiterH = RotL64((aOrbiterH * 10975353228235695455U), 13U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 23U);
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterK, 46U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 53U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 23U) + aOrbiterH) + RotL64(aOrbiterJ, 54U)) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterE, 5U)) + aOrbiterF);
            aWandererG = aWandererG + ((RotL64(aCross, 21U) + RotL64(aOrbiterK, 23U)) + aOrbiterG);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 3U) + aOrbiterD) + RotL64(aOrbiterI, 19U)) + RotL64(aNonceWordH, 17U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 36U) + aOrbiterJ) + RotL64(aOrbiterI, 26U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterI, 3U)) + aOrbiterE);
            aWandererB = aWandererB + ((RotL64(aCross, 27U) + RotL64(aOrbiterC, 13U)) + aOrbiterA);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterG, 47U)) + aOrbiterB);
            aWandererJ = aWandererJ + (((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterA, 57U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterK, 43U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 48U) + RotL64(aOrbiterH, 41U)) + aOrbiterE) + RotL64(aCarry, 23U)) + RotL64(aNonceWordE, 10U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 60U));
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + RotL64(aWandererC, 48U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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

void Soccer_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x94A4460D3C66D29FULL + 0x880C1DCE6EA0D67CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xB7D5D7D87FDDCC77ULL + 0xB9B0E0D67DC0DFF9ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xCAAA9A63AFCABADDULL + 0xF6A4326A31B950A9ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x8AC401E2559BDE9FULL + 0xC4CE38C13B0B70DFULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xECE74A1C69C6F943ULL + 0xF785ADA2C695EF33ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x80968A8B06E96DA7ULL + 0xC3B8D3C7F6EF6D94ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xACF5C34F3A88A88FULL + 0xF565E0B8EFFFC012ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xB0F21B677D3B91D5ULL + 0xD00CDFD58E1A8225ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 11U) ^ RotL64(aNonceWordC, 3U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 1926U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneC[((aIndex + 1226U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 35U) ^ RotL64(aNonceWordF, 3U)) ^ RotL64(aNonceWordB, 13U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 1882U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 4623U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aIngress, 53U)) ^ (RotL64(aCarry, 5U) + RotL64(aPrevious, 26U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterA = (aWandererH + RotL64(aScatter, 47U)) + 11274974230580265396U;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 53U)) + 16658438747342741547U;
            aOrbiterE = (aWandererK + RotL64(aCross, 39U)) + 16612986966106053844U;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 26U)) + 9329502236843231290U) + RotL64(aNonceWordC, 47U);
            aOrbiterI = (aWandererC + RotL64(aCross, 41U)) + 14088261356708344656U;
            aOrbiterC = (aWandererE + RotL64(aIngress, 3U)) + 13692608802007789581U;
            aOrbiterF = (((aWandererA + RotL64(aScatter, 21U)) + RotL64(aCarry, 21U)) + 6824473946645682398U) + aPhaseEOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 19U)) + RotL64(aCarry, 39U)) + 2072915876348570040U;
            aOrbiterB = (aWandererJ + RotL64(aIngress, 28U)) + 7420507753044460759U;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 43U)) + 4677557318688502593U) + RotL64(aNonceWordH, 23U);
            aOrbiterK = (((aWandererI + RotL64(aCross, 37U)) + RotL64(aCarry, 29U)) + 15081678577055628459U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 7026792817486507482U) + RotL64(aNonceWordG, 29U);
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 14871665922943969918U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 694073180313083145U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 6807734532159292872U) + RotL64(aNonceWordE, 46U);
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 17882797335141303280U;
            aOrbiterC = RotL64((aOrbiterC * 15439872930381050291U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 9233542707022629190U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 1205501586581350876U;
            aOrbiterA = RotL64((aOrbiterA * 2596053290311090589U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 10878718669747466677U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 8066049063548639241U;
            aOrbiterH = RotL64((aOrbiterH * 3031382633089381605U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 861295180226875235U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 9134969787937288583U;
            aOrbiterF = RotL64((aOrbiterF * 7565008208670843555U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 6726642007159809594U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 8061661744643240470U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6703498926835391813U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 13541412083111962884U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 8617442758729315637U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15471862889276160953U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 16884403561131293362U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 9490680911678221233U;
            aOrbiterJ = RotL64((aOrbiterJ * 15988763830018001033U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 10486145044311386738U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 10200001044821063684U;
            aOrbiterI = RotL64((aOrbiterI * 16149790736141571017U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 6997073594007878034U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 13585783612009989767U;
            aOrbiterD = RotL64((aOrbiterD * 11425303157774550449U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 3847846040256340653U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 11274974230580265396U;
            aOrbiterG = RotL64((aOrbiterG * 13970270689108369205U), 19U);
            //
            aIngress = RotL64(aOrbiterF, 6U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterC, 53U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterJ, 26U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterB, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterD, 50U)) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 51U) + aOrbiterJ) + RotL64(aOrbiterF, 5U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 23U) + aOrbiterK) + RotL64(aOrbiterF, 37U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 44U) + RotL64(aOrbiterG, 41U)) + aOrbiterC);
            aWandererC = aWandererC + (((RotL64(aCross, 47U) + RotL64(aOrbiterH, 53U)) + aOrbiterB) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 41U) + aOrbiterA) + RotL64(aOrbiterE, 29U)) + aPhaseEWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 11U) + RotL64(aOrbiterF, 44U)) + aOrbiterH) + RotL64(aNonceWordA, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 27U) + aOrbiterE) + RotL64(aOrbiterH, 13U));
            aWandererK = aWandererK + ((RotL64(aScatter, 37U) + RotL64(aOrbiterD, 39U)) + aOrbiterC);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 3U)) + aOrbiterF);
            aWandererA = aWandererA + (((RotL64(aCross, 60U) + RotL64(aOrbiterI, 35U)) + aOrbiterD) + RotL64(aNonceWordB, 45U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (RotL64(aWandererK, 18U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 23U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 3U) ^ RotL64(aNonceWordG, 58U)) ^ RotL64(aNonceWordE, 13U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 8833U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneD[((aIndex + 9895U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 27U) ^ RotL64(aNonceWordD, 44U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6438U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((aIndex + 8456U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 54U) + RotL64(aIngress, 35U)) ^ (RotL64(aCarry, 23U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterA = ((aWandererE + RotL64(aScatter, 29U)) + 3339283916456813609U) + RotL64(aNonceWordA, 13U);
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 47U)) + 11339086426180649584U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = (aWandererF + RotL64(aCross, 51U)) + 16819191669329316585U;
            aOrbiterB = (aWandererC + RotL64(aIngress, 11U)) + 8361916937762630725U;
            aOrbiterG = (aWandererA + RotL64(aPrevious, 4U)) + 18031328374429899857U;
            aOrbiterD = (((aWandererD + RotL64(aCross, 39U)) + RotL64(aCarry, 43U)) + 18261756894092897276U) + RotL64(aNonceWordH, 61U);
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 41U)) + RotL64(aCarry, 27U)) + 4250319792907645666U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 19U)) + RotL64(aCarry, 19U)) + 1492411503643460886U;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 13U)) + 17369549067879344180U;
            aOrbiterE = (aWandererH + RotL64(aIngress, 35U)) + 7301713524358676722U;
            aOrbiterH = ((aWandererG + RotL64(aCross, 60U)) + 2985193736033012535U) + aPhaseEOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 14086975808140927408U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 10390516547834639800U;
            aOrbiterI = RotL64((aOrbiterI * 11441293212275890819U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 18205555540941493267U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 16967799565443938873U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3009081009044782443U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 9209505304067579944U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 3522631966146762306U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3441982898533162599U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 8811497120829041188U) + RotL64(aNonceWordB, 51U);
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 14707301680850257294U) ^ RotL64(aNonceWordE, 35U);
            aOrbiterC = RotL64((aOrbiterC * 11383709499376464085U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 10080595991787801029U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 6822892187784299166U;
            aOrbiterJ = RotL64((aOrbiterJ * 7417016898027778287U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 1981637172055758689U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 16463077485583119324U;
            aOrbiterA = RotL64((aOrbiterA * 2876782050665869121U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 8383837717361569465U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 2788511294985017326U;
            aOrbiterB = RotL64((aOrbiterB * 2809163242875130677U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 3529607472855930041U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 8850940802020173766U;
            aOrbiterD = RotL64((aOrbiterD * 7821450253655655943U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 7469160295100147267U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 16973986572163482061U;
            aOrbiterK = RotL64((aOrbiterK * 15660743778376905023U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 12371372942863279718U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 12098525148034303633U;
            aOrbiterE = RotL64((aOrbiterE * 11234127652230231751U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 5138683482859889480U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 3339283916456813609U;
            aOrbiterH = RotL64((aOrbiterH * 10975353228235695455U), 41U);
            //
            aIngress = RotL64(aOrbiterG, 5U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 60U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 21U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + RotL64(aOrbiterB, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterE, 23U)) + aOrbiterJ);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 50U) + aOrbiterF) + RotL64(aOrbiterA, 57U));
            aWandererK = aWandererK + (((RotL64(aIngress, 5U) + aOrbiterD) + RotL64(aOrbiterH, 3U)) + aPhaseEWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterC, 11U)) + aOrbiterI);
            aWandererF = aWandererF + ((RotL64(aScatter, 29U) + aOrbiterK) + RotL64(aOrbiterA, 41U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 37U) + aOrbiterI) + RotL64(aOrbiterA, 34U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 23U) + aOrbiterC) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 27U) + aOrbiterK) + RotL64(aOrbiterB, 51U)) + RotL64(aNonceWordC, 52U));
            aWandererI = aWandererI + (((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterC, 39U)) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 18U)) + aOrbiterI) + RotL64(aNonceWordG, 45U));
            aWandererG = aWandererG + ((RotL64(aIngress, 12U) + aOrbiterG) + RotL64(aOrbiterC, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 14U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + RotL64(aWandererH, 20U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 4U) ^ RotL64(aNonceWordF, 51U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 13528U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((aIndex + 15259U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 5U) ^ RotL64(aNonceWordD, 35U)) ^ RotL64(aNonceWordA, 60U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 12708U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneC[((aIndex + 12225U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCarry, 36U)) ^ (RotL64(aPrevious, 19U) ^ RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterE = ((aWandererI + RotL64(aIngress, 47U)) + RotL64(aCarry, 11U)) + 10336802574069791273U;
            aOrbiterI = ((aWandererF + RotL64(aCross, 19U)) + 169025388197058936U) + aPhaseEOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aScatter, 6U)) + 6541354188379168846U;
            aOrbiterB = (((aWandererK + RotL64(aPrevious, 35U)) + RotL64(aCarry, 27U)) + 16223920526599306104U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aIngress, 53U)) + 12756613707692514808U;
            aOrbiterC = (aWandererC + RotL64(aScatter, 39U)) + 5082475548176484035U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 14U)) + RotL64(aCarry, 41U)) + 4907435526952698526U;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 43U)) + 14236627073831834337U) + RotL64(aNonceWordA, 3U);
            aOrbiterG = ((aWandererD + RotL64(aScatter, 3U)) + 11502511046130497584U) + RotL64(aNonceWordG, 20U);
            aOrbiterK = (aWandererE + RotL64(aIngress, 29U)) + 3679044835550219497U;
            aOrbiterH = (aWandererB + RotL64(aCross, 57U)) + 11254838916686736746U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 10582608424233200966U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 10449735026385340313U) ^ RotL64(aNonceWordD, 49U);
            aOrbiterD = RotL64((aOrbiterD * 7363770199734997411U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 4628253464169957835U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 17664454668473204465U;
            aOrbiterC = RotL64((aOrbiterC * 4234720298731378527U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 3798386391743884889U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 1379331161819246587U;
            aOrbiterI = RotL64((aOrbiterI * 13086160171095077295U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 9816600392407327227U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 16781971616348376878U) ^ RotL64(aNonceWordH, 7U);
            aOrbiterF = RotL64((aOrbiterF * 12503867584828289879U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 4807797577690520554U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 2492057261148595922U;
            aOrbiterJ = RotL64((aOrbiterJ * 9453302540675483005U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 7909676419643119585U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 256053568910383007U;
            aOrbiterK = RotL64((aOrbiterK * 11965085163352053161U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 16179914439220412472U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 3968867762761955845U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7473632378251893139U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 7474832923901283742U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 4736994731050735779U;
            aOrbiterB = RotL64((aOrbiterB * 9839654409121414047U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 596484364660389193U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 13822222274464306169U;
            aOrbiterA = RotL64((aOrbiterA * 1723502278319885511U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 16307920280681985443U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 3505106171801702915U;
            aOrbiterG = RotL64((aOrbiterG * 8479675421552861243U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 4987142580981135150U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 10336802574069791273U;
            aOrbiterH = RotL64((aOrbiterH * 2670706512498539705U), 51U);
            //
            aIngress = RotL64(aOrbiterJ, 46U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + (RotL64(aOrbiterA, 29U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterD, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 6U) + aOrbiterJ) + RotL64(aOrbiterA, 23U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 29U) + aOrbiterK) + RotL64(aOrbiterG, 46U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 43U) + aOrbiterC) + RotL64(aOrbiterI, 53U));
            aWandererG = aWandererG + (((RotL64(aScatter, 51U) + RotL64(aOrbiterE, 51U)) + aOrbiterG) + RotL64(aNonceWordC, 41U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterI, 37U)) + aOrbiterF);
            aWandererC = aWandererC + ((RotL64(aScatter, 21U) + aOrbiterB) + RotL64(aOrbiterC, 39U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterD, 35U)) + aOrbiterK) + aPhaseEWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 14U) + aOrbiterC) + RotL64(aOrbiterD, 41U)) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 41U) + aOrbiterJ) + RotL64(aOrbiterB, 28U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterH, 5U)) + RotL64(aCarry, 35U)) + RotL64(aNonceWordB, 23U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 57U)) + aOrbiterD) + aPhaseEWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 60U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + RotL64(aWandererE, 10U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 5U) ^ RotL64(aNonceWordF, 47U)) ^ RotL64(aNonceWordD, 29U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 20247U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 16910U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 22U) ^ RotL64(aNonceWordG, 13U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21712U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 18217U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 44U) ^ RotL64(aIngress, 29U)) ^ (RotL64(aPrevious, 11U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 14U)) + 12775735908960052604U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aIngress, 53U)) + 11791373812080296887U;
            aOrbiterA = (aWandererK + RotL64(aCross, 19U)) + 5537362877706057303U;
            aOrbiterE = (aWandererA + RotL64(aScatter, 3U)) + 2023912048504189380U;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 35U)) + RotL64(aCarry, 43U)) + 17668828109963766893U;
            aOrbiterK = ((aWandererE + RotL64(aCross, 60U)) + 558908629933941224U) + RotL64(aNonceWordF, 37U);
            aOrbiterB = ((aWandererD + RotL64(aScatter, 23U)) + RotL64(aCarry, 23U)) + 1479633119685446888U;
            aOrbiterC = (aWandererB + RotL64(aIngress, 51U)) + 15460320397843364063U;
            aOrbiterD = ((((aWandererI + RotL64(aCross, 27U)) + RotL64(aCarry, 35U)) + 10059749397555469054U) + aPhaseEOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1]) + RotL64(aNonceWordE, 7U);
            aOrbiterF = (aWandererG + RotL64(aPrevious, 41U)) + 9987633811929693924U;
            aOrbiterG = (aWandererC + RotL64(aIngress, 43U)) + 10087337844580228269U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 4446204415503364254U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 15106063243302192717U;
            aOrbiterA = RotL64((aOrbiterA * 13273756657334709803U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 9430197906134676162U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 1226048679997253363U;
            aOrbiterI = RotL64((aOrbiterI * 14247538885252664127U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 10611580584157624739U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 3137391249289641509U;
            aOrbiterK = RotL64((aOrbiterK * 5462682413239873181U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 9327201928815412810U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 7890659377013147073U;
            aOrbiterB = RotL64((aOrbiterB * 13827717178378062047U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 10675114832750356941U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 8804440385852327267U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8520671775587260601U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 12871947817782057116U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 11015991745792051390U;
            aOrbiterD = RotL64((aOrbiterD * 17152451500505815031U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 6320437975845673731U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 702457937087191287U;
            aOrbiterF = RotL64((aOrbiterF * 17491257114676739589U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 16629064896250312921U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 6054107387816339103U) ^ RotL64(aNonceWordG, 13U);
            aOrbiterG = RotL64((aOrbiterG * 6983767878966747219U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 13274874838094190290U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 12211422735294360321U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5113738196151089817U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 15338616110718583619U) + RotL64(aNonceWordH, 55U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 1475787183754511373U;
            aOrbiterJ = RotL64((aOrbiterJ * 10904607643785840003U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 15486810401396777742U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 12775735908960052604U;
            aOrbiterE = RotL64((aOrbiterE * 7478156942468930207U), 41U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterA, 60U);
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 39U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 30U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aScatter, 13U) + aOrbiterH) + RotL64(aOrbiterC, 27U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 21U) + aOrbiterD) + RotL64(aOrbiterI, 39U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterK, 5U)) + aOrbiterD) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 41U) + aOrbiterC) + RotL64(aOrbiterE, 13U)) + RotL64(aNonceWordB, 54U)) + aPhaseEWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterG, 37U)) + RotL64(aCarry, 21U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 34U) + aOrbiterG) + RotL64(aOrbiterC, 22U));
            aWandererK = aWandererK + ((RotL64(aCross, 53U) + RotL64(aOrbiterF, 41U)) + aOrbiterJ);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 27U) + aOrbiterB) + RotL64(aOrbiterH, 51U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterJ, 57U)) + aOrbiterI);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 19U) + aOrbiterF) + RotL64(aOrbiterE, 35U)) + RotL64(aNonceWordC, 3U));
            aWandererA = aWandererA + ((RotL64(aScatter, 6U) + RotL64(aOrbiterA, 44U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererK, 44U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 56U));
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 21U) ^ RotL64(aNonceWordH, 13U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 23598U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneA[((aIndex + 23543U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 46U) ^ RotL64(aNonceWordC, 29U)) ^ RotL64(aNonceWordB, 57U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26086U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27121U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 41U)) ^ (RotL64(aIngress, 24U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterF = ((aWandererE + RotL64(aCross, 13U)) + 5697928251815176134U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aIngress, 10U)) + 337587740689259575U;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 5U)) + 4927686903263973950U) + RotL64(aNonceWordC, 23U);
            aOrbiterB = (aWandererC + RotL64(aScatter, 23U)) + 3742409032569801033U;
            aOrbiterH = (aWandererD + RotL64(aCross, 35U)) + 1608092659172197650U;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 58U)) + RotL64(aCarry, 13U)) + 15848744267145717509U;
            aOrbiterK = (aWandererB + RotL64(aIngress, 51U)) + 15300174177963339253U;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 19U)) + RotL64(aCarry, 53U)) + 14162868453323648628U;
            aOrbiterG = ((aWandererF + RotL64(aScatter, 21U)) + 12020167069983729869U) + RotL64(aNonceWordE, 17U);
            aOrbiterC = ((aWandererJ + RotL64(aCross, 37U)) + 16259538291658723956U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aIngress, 43U)) + RotL64(aCarry, 23U)) + 8516686212464112245U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 3722184575520553132U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 5663609293306386784U;
            aOrbiterA = RotL64((aOrbiterA * 14364218128780764749U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 15265344442454471986U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 3050323350098829515U;
            aOrbiterI = RotL64((aOrbiterI * 5890624677162388135U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 1093356813820599238U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 15167726103772238440U;
            aOrbiterJ = RotL64((aOrbiterJ * 5719466863561311069U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 15170797965325981472U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 17826286701992981628U;
            aOrbiterC = RotL64((aOrbiterC * 11186808881726573677U), 35U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterJ) + 14710892030473425181U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1]) + RotL64(aNonceWordD, 15U);
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 397194787697553904U;
            aOrbiterF = RotL64((aOrbiterF * 14368930300818752833U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 1273724124862533034U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 13018397560392545616U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4644812473262395329U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 9638716186445643730U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 7255587739807843785U;
            aOrbiterK = RotL64((aOrbiterK * 6055682981584011189U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 9272350563697399628U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 1040729335295009339U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17825687660830291443U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 12128124729613601747U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 2285238815562202219U;
            aOrbiterE = RotL64((aOrbiterE * 15398840993074390573U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 6339113298619163493U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 5911895708485037040U;
            aOrbiterD = RotL64((aOrbiterD * 3271006139923200439U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 7601399508218901328U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 5697928251815176134U) ^ RotL64(aNonceWordF, 55U);
            aOrbiterH = RotL64((aOrbiterH * 8184257916861355735U), 47U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterC, 37U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 28U));
            aIngress = aIngress + (RotL64(aOrbiterG, 11U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + RotL64(aOrbiterH, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 29U) + aOrbiterK) + RotL64(aOrbiterJ, 56U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 53U) + aOrbiterC) + RotL64(aOrbiterG, 21U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterG, 41U)) + aOrbiterK) + aPhaseEWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 26U) + aOrbiterH) + RotL64(aOrbiterF, 53U)) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 21U) + aOrbiterI) + RotL64(aOrbiterE, 28U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 51U) + aOrbiterH) + RotL64(aOrbiterC, 51U)) + RotL64(aNonceWordG, 37U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 13U)) + aOrbiterC);
            aWandererJ = aWandererJ + ((RotL64(aCross, 13U) + RotL64(aOrbiterB, 3U)) + aOrbiterD);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 36U) + RotL64(aOrbiterA, 5U)) + aOrbiterG);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 35U)) + aOrbiterB) + RotL64(aCarry, 51U)) + RotL64(aNonceWordA, 36U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterH, 11U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 60U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (RotL64(aWandererB, 21U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererG, 10U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 38U) ^ RotL64(aNonceWordA, 13U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 30597U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30127U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 47U) ^ RotL64(aNonceWordB, 21U)) ^ RotL64(aNonceWordH, 13U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31288U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((aIndex + 30358U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 21U) ^ RotL64(aCarry, 5U)) + (RotL64(aCross, 38U) + RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 11U)) + 17264605017518259932U) + RotL64(aNonceWordH, 31U);
            aOrbiterC = ((aWandererG + RotL64(aScatter, 19U)) + 15209184354580778643U) + RotL64(aNonceWordF, 45U);
            aOrbiterG = ((aWandererD + RotL64(aCross, 3U)) + RotL64(aCarry, 23U)) + 3299527965014731384U;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 47U)) + 16293096431816127821U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = ((aWandererA + RotL64(aScatter, 56U)) + RotL64(aCarry, 5U)) + 11031983436878828337U;
            aOrbiterD = (aWandererK + RotL64(aCross, 21U)) + 9188018632448236358U;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 5U)) + RotL64(aCarry, 51U)) + 13420816400363406556U;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 39U)) + 2485063384097917101U;
            aOrbiterF = ((aWandererI + RotL64(aScatter, 41U)) + 3089135816938128264U) + aPhaseEOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = (aWandererF + RotL64(aIngress, 36U)) + 10730544971770435788U;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 23U)) + 10431767565618874806U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 14883796491656899074U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 13465877783538483706U;
            aOrbiterG = RotL64((aOrbiterG * 14311686051108108503U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 13322163435314643713U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 3307316600284371955U;
            aOrbiterH = RotL64((aOrbiterH * 12337846092069506365U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 4950101626975919939U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 2596253994220103666U;
            aOrbiterD = RotL64((aOrbiterD * 7181706961838582889U), 39U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterH) + 17961706029559914243U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]) + RotL64(aNonceWordD, 41U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 10321902557977495175U;
            aOrbiterJ = RotL64((aOrbiterJ * 16189559888625084711U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 18146616411403012772U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 8414050129421955787U;
            aOrbiterE = RotL64((aOrbiterE * 14879448948196182863U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 11739172334166341121U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 7936637782633487291U;
            aOrbiterF = RotL64((aOrbiterF * 14940929920543800413U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 3160044627483874242U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 16816384076887379704U;
            aOrbiterK = RotL64((aOrbiterK * 5052772186568301951U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 8101560104988710226U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 8851416379738817624U;
            aOrbiterI = RotL64((aOrbiterI * 16767420038937389027U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 9941784290055185679U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 14495651885701938495U;
            aOrbiterB = RotL64((aOrbiterB * 1540692851998143607U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 10599676325220702167U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 16092000942942971187U) ^ RotL64(aNonceWordA, 49U);
            aOrbiterC = RotL64((aOrbiterC * 2457268192247656817U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 16168470945107928109U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 17264605017518259932U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15038386057529909273U), 57U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 5U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 38U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 18U)) + aOrbiterC);
            aWandererD = aWandererD + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 51U)) + aOrbiterJ);
            aWandererK = aWandererK ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterI, 35U)) + aOrbiterJ);
            aWandererI = aWandererI + ((((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 29U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 26U) + aOrbiterJ) + RotL64(aOrbiterC, 43U)) + aPhaseEWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 21U) + RotL64(aOrbiterK, 53U)) + aOrbiterA) + RotL64(aCarry, 47U)) + RotL64(aNonceWordC, 53U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterK, 57U)) + aOrbiterG);
            aWandererB = aWandererB + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 11U)) + aOrbiterD);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 30U) + aOrbiterE) + RotL64(aOrbiterB, 21U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 41U) + aOrbiterA) + RotL64(aOrbiterD, 27U)) + RotL64(aNonceWordG, 40U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 37U) + aOrbiterK) + RotL64(aOrbiterF, 14U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 54U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererI, 10U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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

void Soccer_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xD29C499921DED0EFULL + 0xD3F1D034FCA59496ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x8196C6885F4B1ABFULL + 0x9B83A4619820B78EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x9D6ECD6A86E71C9DULL + 0xF796FFD856578E95ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xCC8DD35EDA052B15ULL + 0xCA83B2D25AEB7DD2ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x867555718544C1BBULL + 0xA614CFE700849E81ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x9138AC5C89CFEA33ULL + 0xA4599A036048D39BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xB4F50EFE4FB20D6FULL + 0xE3F73053DFB71516ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xFFE336269586F15DULL + 0x89183453A6025B60ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 29U) ^ RotL64(aNonceWordE, 20U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 167U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneC[((aIndex + 4188U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 3U) ^ RotL64(aNonceWordD, 11U)) ^ RotL64(aNonceWordC, 21U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 4258U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneA[((aIndex + 541U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCross, 23U)) ^ (RotL64(aCarry, 35U) + RotL64(aPrevious, 48U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 48U)) + 12775735908960052604U;
            aOrbiterF = ((aWandererA + RotL64(aCross, 43U)) + RotL64(aCarry, 23U)) + 11791373812080296887U;
            aOrbiterJ = (aWandererF + RotL64(aScatter, 53U)) + 5537362877706057303U;
            aOrbiterH = ((((aWandererC + RotL64(aIngress, 21U)) + RotL64(aCarry, 3U)) + 2023912048504189380U) + aPhaseFOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1]) + RotL64(aNonceWordE, 27U);
            aOrbiterD = ((aWandererG + RotL64(aScatter, 5U)) + RotL64(aCarry, 47U)) + 17668828109963766893U;
            aOrbiterE = (aWandererI + RotL64(aCross, 3U)) + 558908629933941224U;
            aOrbiterG = (aWandererK + RotL64(aIngress, 14U)) + 1479633119685446888U;
            aOrbiterC = (aWandererH + RotL64(aPrevious, 51U)) + 15460320397843364063U;
            aOrbiterI = ((aWandererD + RotL64(aScatter, 29U)) + 10059749397555469054U) + RotL64(aNonceWordF, 9U);
            aOrbiterB = (aWandererE + RotL64(aCross, 23U)) + 9987633811929693924U;
            aOrbiterK = ((aWandererB + RotL64(aIngress, 39U)) + 10087337844580228269U) + aPhaseFOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 4446204415503364254U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 15106063243302192717U;
            aOrbiterJ = RotL64((aOrbiterJ * 13273756657334709803U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 9430197906134676162U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 1226048679997253363U;
            aOrbiterE = RotL64((aOrbiterE * 14247538885252664127U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 10611580584157624739U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 3137391249289641509U;
            aOrbiterA = RotL64((aOrbiterA * 5462682413239873181U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 9327201928815412810U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 7890659377013147073U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13827717178378062047U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 10675114832750356941U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 8804440385852327267U) ^ RotL64(aNonceWordA, 13U);
            aOrbiterG = RotL64((aOrbiterG * 8520671775587260601U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 12871947817782057116U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 11015991745792051390U;
            aOrbiterI = RotL64((aOrbiterI * 17152451500505815031U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 6320437975845673731U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 702457937087191287U;
            aOrbiterK = RotL64((aOrbiterK * 17491257114676739589U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 16629064896250312921U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 6054107387816339103U) ^ RotL64(aNonceWordC, 35U);
            aOrbiterF = RotL64((aOrbiterF * 6983767878966747219U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 13274874838094190290U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 12211422735294360321U;
            aOrbiterD = RotL64((aOrbiterD * 5113738196151089817U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 15338616110718583619U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 1475787183754511373U;
            aOrbiterC = RotL64((aOrbiterC * 10904607643785840003U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 15486810401396777742U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 12775735908960052604U;
            aOrbiterB = RotL64((aOrbiterB * 7478156942468930207U), 11U);
            //
            aIngress = RotL64(aOrbiterB, 29U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 6U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 39U));
            aIngress = aIngress + RotL64(aOrbiterC, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aCross, 51U) + RotL64(aOrbiterB, 11U)) + aOrbiterD);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterI, 47U)) + aOrbiterK) + aPhaseFWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 37U) + aOrbiterI) + RotL64(aOrbiterG, 26U)) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 27U) + aOrbiterB) + RotL64(aOrbiterJ, 51U)) + RotL64(aNonceWordH, 30U));
            aWandererH = aWandererH + ((RotL64(aScatter, 3U) + aOrbiterK) + RotL64(aOrbiterH, 53U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 42U) + RotL64(aOrbiterA, 21U)) + aOrbiterB);
            aWandererK = aWandererK + (((RotL64(aIngress, 19U) + RotL64(aOrbiterK, 56U)) + aOrbiterE) + RotL64(aCarry, 47U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterG, 13U));
            aWandererE = aWandererE + ((RotL64(aCross, 21U) + aOrbiterG) + RotL64(aOrbiterF, 37U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 13U) + aOrbiterC) + RotL64(aOrbiterH, 29U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 46U) + aOrbiterH) + RotL64(aOrbiterI, 43U)) + RotL64(aNonceWordB, 41U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (RotL64(aWandererI, 26U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + RotL64(aWandererJ, 39U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 60U) ^ RotL64(aNonceWordB, 39U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9145U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneD[((aIndex + 7710U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 4U) ^ RotL64(aNonceWordF, 57U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7016U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8206U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCross, 39U)) ^ (RotL64(aCarry, 3U) + RotL64(aIngress, 18U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = (aWandererI + RotL64(aCross, 34U)) + 11274974230580265396U;
            aOrbiterE = (aWandererB + RotL64(aScatter, 57U)) + 16658438747342741547U;
            aOrbiterJ = (aWandererH + RotL64(aIngress, 41U)) + 16612986966106053844U;
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 51U)) + RotL64(aCarry, 29U)) + 9329502236843231290U;
            aOrbiterA = (aWandererA + RotL64(aScatter, 3U)) + 14088261356708344656U;
            aOrbiterK = (aWandererE + RotL64(aCross, 23U)) + 13692608802007789581U;
            aOrbiterB = (((aWandererF + RotL64(aPrevious, 39U)) + 6824473946645682398U) + aPhaseFOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1]) + RotL64(aNonceWordG, 34U);
            aOrbiterD = ((aWandererD + RotL64(aIngress, 43U)) + 2072915876348570040U) + RotL64(aNonceWordD, 15U);
            aOrbiterC = (((aWandererC + RotL64(aScatter, 13U)) + RotL64(aCarry, 23U)) + 7420507753044460759U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = (aWandererG + RotL64(aIngress, 30U)) + 4677557318688502593U;
            aOrbiterF = ((aWandererK + RotL64(aCross, 47U)) + RotL64(aCarry, 41U)) + 15081678577055628459U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 7026792817486507482U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 14871665922943969918U;
            aOrbiterJ = RotL64((aOrbiterJ * 694073180313083145U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 6807734532159292872U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 17882797335141303280U;
            aOrbiterE = RotL64((aOrbiterE * 15439872930381050291U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 9233542707022629190U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 1205501586581350876U;
            aOrbiterA = RotL64((aOrbiterA * 2596053290311090589U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 10878718669747466677U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 8066049063548639241U;
            aOrbiterB = RotL64((aOrbiterB * 3031382633089381605U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 861295180226875235U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 9134969787937288583U;
            aOrbiterC = RotL64((aOrbiterC * 7565008208670843555U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 6726642007159809594U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 8061661744643240470U;
            aOrbiterI = RotL64((aOrbiterI * 6703498926835391813U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 13541412083111962884U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 8617442758729315637U;
            aOrbiterH = RotL64((aOrbiterH * 15471862889276160953U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 16884403561131293362U) + RotL64(aNonceWordE, 55U);
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 9490680911678221233U) ^ RotL64(aNonceWordC, 43U);
            aOrbiterK = RotL64((aOrbiterK * 15988763830018001033U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 10486145044311386738U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 10200001044821063684U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16149790736141571017U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 6997073594007878034U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 13585783612009989767U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11425303157774550449U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 3847846040256340653U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 11274974230580265396U;
            aOrbiterF = RotL64((aOrbiterF * 13970270689108369205U), 39U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterH, 41U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 54U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + RotL64(aOrbiterC, 26U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 26U) + aOrbiterK) + RotL64(aOrbiterG, 11U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 29U) + aOrbiterB) + RotL64(aOrbiterH, 53U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 41U) + RotL64(aOrbiterF, 43U)) + aOrbiterI) + RotL64(aNonceWordA, 9U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 43U) + RotL64(aOrbiterC, 39U)) + aOrbiterJ);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 39U) + aOrbiterB) + RotL64(aOrbiterJ, 23U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 51U) + RotL64(aOrbiterI, 27U)) + aOrbiterA) + RotL64(aCarry, 27U)) + RotL64(aNonceWordH, 19U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterE, 60U));
            aWandererK = aWandererK + (((RotL64(aCross, 57U) + aOrbiterF) + RotL64(aOrbiterA, 51U)) + RotL64(aCarry, 35U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterK, 3U));
            aWandererE = aWandererE + ((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterD, 47U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 20U) + aOrbiterK) + RotL64(aOrbiterJ, 34U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 34U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 18U));
            aCarry = aCarry + RotL64(aWandererE, 3U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 19U) ^ RotL64(aNonceWordB, 48U)) ^ RotL64(aNonceWordC, 27U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13121U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 16197U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 11U) ^ RotL64(aNonceWordD, 27U)) ^ RotL64(aNonceWordG, 60U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 15408U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneC[((aIndex + 15643U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 13U) ^ RotL64(aCross, 26U)) + (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = (((aWandererE + RotL64(aScatter, 41U)) + RotL64(aCarry, 11U)) + 10336802574069791273U) + aPhaseFOrbiterAssignSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aCross, 57U)) + 169025388197058936U;
            aOrbiterC = (aWandererD + RotL64(aPrevious, 6U)) + 6541354188379168846U;
            aOrbiterB = (aWandererB + RotL64(aIngress, 39U)) + 16223920526599306104U;
            aOrbiterD = (aWandererK + RotL64(aScatter, 37U)) + 12756613707692514808U;
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 13U)) + 5082475548176484035U) + RotL64(aNonceWordF, 29U);
            aOrbiterF = (((aWandererG + RotL64(aCross, 29U)) + RotL64(aCarry, 37U)) + 4907435526952698526U) + RotL64(aNonceWordG, 31U);
            aOrbiterJ = (aWandererC + RotL64(aIngress, 27U)) + 14236627073831834337U;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 19U)) + RotL64(aCarry, 3U)) + 11502511046130497584U;
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 47U)) + 3679044835550219497U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aIngress, 52U)) + 11254838916686736746U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 10582608424233200966U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 10449735026385340313U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7363770199734997411U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 4628253464169957835U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 17664454668473204465U) ^ RotL64(aNonceWordC, 41U);
            aOrbiterG = RotL64((aOrbiterG * 4234720298731378527U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 3798386391743884889U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 1379331161819246587U;
            aOrbiterH = RotL64((aOrbiterH * 13086160171095077295U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 9816600392407327227U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 16781971616348376878U;
            aOrbiterD = RotL64((aOrbiterD * 12503867584828289879U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 4807797577690520554U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 2492057261148595922U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9453302540675483005U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 7909676419643119585U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 256053568910383007U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11965085163352053161U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 16179914439220412472U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 3968867762761955845U;
            aOrbiterI = RotL64((aOrbiterI * 7473632378251893139U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 7474832923901283742U) + RotL64(aNonceWordH, 5U);
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 4736994731050735779U;
            aOrbiterB = RotL64((aOrbiterB * 9839654409121414047U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 596484364660389193U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 13822222274464306169U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1723502278319885511U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 16307920280681985443U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 3505106171801702915U;
            aOrbiterK = RotL64((aOrbiterK * 8479675421552861243U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 4987142580981135150U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 10336802574069791273U;
            aOrbiterE = RotL64((aOrbiterE * 2670706512498539705U), 47U);
            //
            aIngress = RotL64(aOrbiterJ, 5U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterC, 41U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 44U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aCross, 11U) + aOrbiterH) + RotL64(aOrbiterI, 4U)) + aPhaseFWandererUpdateSaltD[((aIndex + 26U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 27U) + aOrbiterK) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterK, 23U)) + aOrbiterF) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 21U)) + aOrbiterK) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 46U) + aOrbiterE) + RotL64(aOrbiterA, 37U));
            aWandererC = aWandererC + ((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterE, 29U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterI, 27U)) + RotL64(aNonceWordE, 30U));
            aWandererG = aWandererG + ((RotL64(aCross, 35U) + RotL64(aOrbiterJ, 13U)) + aOrbiterD);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 60U) + aOrbiterA) + RotL64(aOrbiterI, 41U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 58U)) + aOrbiterB) + RotL64(aNonceWordA, 53U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterC, 19U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 42U));
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererK, 46U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 54U) ^ RotL64(aNonceWordH, 11U)) ^ RotL64(aNonceWordG, 29U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 18150U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((aIndex + 18386U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 29U) ^ RotL64(aNonceWordE, 53U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20748U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneD[((aIndex + 17301U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCross, 21U)) ^ (RotL64(aCarry, 54U) + RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = (aWandererH + RotL64(aIngress, 13U)) + 3339283916456813609U;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 60U)) + RotL64(aCarry, 27U)) + 11339086426180649584U;
            aOrbiterI = ((aWandererF + RotL64(aScatter, 5U)) + 16819191669329316585U) + aPhaseFOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = ((aWandererE + RotL64(aCross, 51U)) + 8361916937762630725U) + RotL64(aNonceWordB, 57U);
            aOrbiterB = ((aWandererG + RotL64(aScatter, 39U)) + 18031328374429899857U) + aPhaseFOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aIngress, 27U)) + RotL64(aCarry, 19U)) + 18261756894092897276U;
            aOrbiterH = (aWandererK + RotL64(aCross, 37U)) + 4250319792907645666U;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 44U)) + 1492411503643460886U) + RotL64(aNonceWordC, 53U);
            aOrbiterE = ((aWandererC + RotL64(aScatter, 47U)) + RotL64(aCarry, 35U)) + 17369549067879344180U;
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 53U)) + 7301713524358676722U;
            aOrbiterJ = (aWandererD + RotL64(aIngress, 35U)) + 2985193736033012535U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 14086975808140927408U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 10390516547834639800U;
            aOrbiterI = RotL64((aOrbiterI * 11441293212275890819U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 18205555540941493267U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 16967799565443938873U;
            aOrbiterB = RotL64((aOrbiterB * 3009081009044782443U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 9209505304067579944U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 3522631966146762306U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3441982898533162599U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 8811497120829041188U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 14707301680850257294U;
            aOrbiterH = RotL64((aOrbiterH * 11383709499376464085U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 10080595991787801029U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 6822892187784299166U;
            aOrbiterG = RotL64((aOrbiterG * 7417016898027778287U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 1981637172055758689U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 16463077485583119324U;
            aOrbiterE = RotL64((aOrbiterE * 2876782050665869121U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 8383837717361569465U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 2788511294985017326U;
            aOrbiterA = RotL64((aOrbiterA * 2809163242875130677U), 57U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterE) + 3529607472855930041U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1]) + RotL64(aNonceWordD, 61U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 8850940802020173766U;
            aOrbiterJ = RotL64((aOrbiterJ * 7821450253655655943U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 7469160295100147267U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 16973986572163482061U;
            aOrbiterK = RotL64((aOrbiterK * 15660743778376905023U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 12371372942863279718U) + RotL64(aNonceWordE, 28U);
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 12098525148034303633U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11234127652230231751U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 5138683482859889480U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 3339283916456813609U;
            aOrbiterD = RotL64((aOrbiterD * 10975353228235695455U), 51U);
            //
            aIngress = RotL64(aOrbiterF, 13U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 6U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + RotL64(aOrbiterE, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterD, 23U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterB, 37U)) + aOrbiterE);
            aWandererK = aWandererK + (((RotL64(aCross, 48U) + aOrbiterF) + RotL64(aOrbiterA, 43U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 23U) + aOrbiterF) + RotL64(aOrbiterE, 13U));
            aWandererE = aWandererE + (((RotL64(aIngress, 21U) + aOrbiterE) + RotL64(aOrbiterC, 29U)) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ ((((RotL64(aCross, 39U) + aOrbiterH) + RotL64(aOrbiterJ, 5U)) + RotL64(aNonceWordA, 39U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 56U)) + aOrbiterI) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterD, 35U)) + aOrbiterC) + RotL64(aNonceWordF, 27U));
            aWandererG = aWandererG + ((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterE, 47U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 12U) + aOrbiterD) + RotL64(aOrbiterE, 11U));
            aWandererD = aWandererD + ((RotL64(aCross, 51U) + RotL64(aOrbiterD, 52U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 48U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 53U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 19U) ^ RotL64(aNonceWordD, 54U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22943U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((aIndex + 24003U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 23U) ^ RotL64(aNonceWordF, 5U)) ^ RotL64(aNonceWordE, 51U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26164U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneA[((aIndex + 22700U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 52U) ^ RotL64(aCross, 21U)) ^ (RotL64(aCarry, 39U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterB = ((aWandererC + RotL64(aScatter, 19U)) + RotL64(aCarry, 3U)) + 5697928251815176134U;
            aOrbiterE = ((aWandererH + RotL64(aCross, 3U)) + 337587740689259575U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = (aWandererE + RotL64(aIngress, 41U)) + 4927686903263973950U;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 39U)) + 3742409032569801033U;
            aOrbiterA = (aWandererJ + RotL64(aCross, 6U)) + 1608092659172197650U;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 23U)) + 15848744267145717509U) + RotL64(aNonceWordG, 7U);
            aOrbiterK = (aWandererI + RotL64(aScatter, 35U)) + 15300174177963339253U;
            aOrbiterF = (aWandererG + RotL64(aIngress, 13U)) + 14162868453323648628U;
            aOrbiterG = (((aWandererD + RotL64(aPrevious, 60U)) + RotL64(aCarry, 11U)) + 12020167069983729869U) + RotL64(aNonceWordH, 53U);
            aOrbiterC = (((aWandererK + RotL64(aCross, 43U)) + RotL64(aCarry, 57U)) + 16259538291658723956U) + aPhaseFOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aIngress, 51U)) + 8516686212464112245U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 3722184575520553132U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 5663609293306386784U;
            aOrbiterI = RotL64((aOrbiterI * 14364218128780764749U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 15265344442454471986U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 3050323350098829515U;
            aOrbiterH = RotL64((aOrbiterH * 5890624677162388135U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 1093356813820599238U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 15167726103772238440U;
            aOrbiterF = RotL64((aOrbiterF * 5719466863561311069U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 15170797965325981472U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 17826286701992981628U;
            aOrbiterC = RotL64((aOrbiterC * 11186808881726573677U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 14710892030473425181U) + RotL64(aNonceWordA, 31U);
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 397194787697553904U;
            aOrbiterB = RotL64((aOrbiterB * 14368930300818752833U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 1273724124862533034U) + RotL64(aNonceWordD, 4U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 13018397560392545616U;
            aOrbiterJ = RotL64((aOrbiterJ * 4644812473262395329U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 9638716186445643730U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 7255587739807843785U;
            aOrbiterK = RotL64((aOrbiterK * 6055682981584011189U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 9272350563697399628U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 1040729335295009339U;
            aOrbiterG = RotL64((aOrbiterG * 17825687660830291443U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 12128124729613601747U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 2285238815562202219U;
            aOrbiterD = RotL64((aOrbiterD * 15398840993074390573U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 6339113298619163493U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 5911895708485037040U;
            aOrbiterE = RotL64((aOrbiterE * 3271006139923200439U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 7601399508218901328U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 5697928251815176134U;
            aOrbiterA = RotL64((aOrbiterA * 8184257916861355735U), 51U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterA, 39U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 54U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterG, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 57U) + RotL64(aOrbiterG, 39U)) + aOrbiterI) + RotL64(aNonceWordF, 59U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 41U) + aOrbiterJ) + RotL64(aOrbiterB, 12U));
            aWandererA = aWandererA + (((RotL64(aCross, 43U) + RotL64(aOrbiterD, 35U)) + aOrbiterC) + aPhaseFWandererUpdateSaltC[((aIndex + 26U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 14U) + RotL64(aOrbiterG, 37U)) + aOrbiterE) + RotL64(aNonceWordB, 21U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 37U) + aOrbiterH) + RotL64(aOrbiterF, 29U)) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterC, 18U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterC, 51U)) + RotL64(aCarry, 21U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 43U)) + aOrbiterE);
            aWandererD = aWandererD + ((RotL64(aScatter, 3U) + aOrbiterB) + RotL64(aOrbiterC, 21U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterI, 53U));
            aWandererB = aWandererB + ((RotL64(aCross, 60U) + aOrbiterC) + RotL64(aOrbiterA, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 60U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 41U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 56U) ^ RotL64(aNonceWordD, 35U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 27548U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((aIndex + 27554U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 35U) ^ RotL64(aNonceWordA, 43U)) ^ RotL64(aNonceWordG, 58U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27583U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 29802U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 56U) ^ RotL64(aPrevious, 13U)) ^ (RotL64(aCross, 29U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = (aWandererC + RotL64(aIngress, 42U)) + 17264605017518259932U;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 19U)) + RotL64(aCarry, 5U)) + 15209184354580778643U;
            aOrbiterJ = (aWandererG + RotL64(aScatter, 13U)) + 3299527965014731384U;
            aOrbiterB = ((aWandererB + RotL64(aCross, 29U)) + 16293096431816127821U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aIngress, 57U)) + RotL64(aCarry, 11U)) + 11031983436878828337U;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 51U)) + 9188018632448236358U;
            aOrbiterA = (aWandererD + RotL64(aScatter, 4U)) + 13420816400363406556U;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 23U)) + RotL64(aCarry, 39U)) + 2485063384097917101U;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 37U)) + 3089135816938128264U) + RotL64(aNonceWordH, 55U);
            aOrbiterC = (aWandererA + RotL64(aScatter, 27U)) + 10730544971770435788U;
            aOrbiterD = (((aWandererI + RotL64(aPrevious, 35U)) + 10431767565618874806U) + aPhaseFOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1]) + RotL64(aNonceWordD, 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 14883796491656899074U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 13465877783538483706U) ^ RotL64(aNonceWordB, 25U);
            aOrbiterJ = RotL64((aOrbiterJ * 14311686051108108503U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 13322163435314643713U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 3307316600284371955U;
            aOrbiterE = RotL64((aOrbiterE * 12337846092069506365U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 4950101626975919939U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 2596253994220103666U) ^ RotL64(aNonceWordF, 7U);
            aOrbiterH = RotL64((aOrbiterH * 7181706961838582889U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 17961706029559914243U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 10321902557977495175U;
            aOrbiterA = RotL64((aOrbiterA * 16189559888625084711U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 18146616411403012772U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 8414050129421955787U;
            aOrbiterF = RotL64((aOrbiterF * 14879448948196182863U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 11739172334166341121U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 7936637782633487291U;
            aOrbiterG = RotL64((aOrbiterG * 14940929920543800413U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 3160044627483874242U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 16816384076887379704U;
            aOrbiterC = RotL64((aOrbiterC * 5052772186568301951U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 8101560104988710226U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 8851416379738817624U;
            aOrbiterD = RotL64((aOrbiterD * 16767420038937389027U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 9941784290055185679U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 14495651885701938495U;
            aOrbiterK = RotL64((aOrbiterK * 1540692851998143607U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 10599676325220702167U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 16092000942942971187U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2457268192247656817U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 16168470945107928109U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 17264605017518259932U;
            aOrbiterB = RotL64((aOrbiterB * 15038386057529909273U), 41U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterF, 51U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 23U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 44U));
            aIngress = aIngress + RotL64(aOrbiterA, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 27U)) + aOrbiterD);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 39U) + aOrbiterI) + RotL64(aOrbiterK, 18U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 24U) + aOrbiterJ) + RotL64(aOrbiterB, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterA, 43U)) + aOrbiterH);
            aWandererF = aWandererF + (((((RotL64(aPrevious, 57U) + RotL64(aOrbiterA, 3U)) + aOrbiterD) + RotL64(aCarry, 19U)) + RotL64(aNonceWordG, 6U)) + aPhaseFWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterD, 11U)) + aOrbiterJ);
            aWandererH = aWandererH + ((RotL64(aScatter, 11U) + aOrbiterJ) + RotL64(aOrbiterC, 5U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 51U) + aOrbiterI) + RotL64(aOrbiterE, 23U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 34U) + aOrbiterF) + RotL64(aOrbiterG, 48U)) + RotL64(aCarry, 39U)) + RotL64(aNonceWordE, 41U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterH, 51U)) + aOrbiterI);
            aWandererK = aWandererK + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterJ, 53U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 10U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 14U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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

void Soccer_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xC900D76FFFA52B05ULL + 0x8B9C8414C11C0010ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xD81D7A52C979F719ULL + 0xA79A31438CF163E3ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x8B0E0997160F7599ULL + 0xBC12DAF1006F7F32ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x9B1C11362496BAA7ULL + 0xB9752E899C224B91ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xD1D80744EEBF6487ULL + 0xF400CF569B3CA484ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x82423706F3CDF431ULL + 0xC10E0602D75ED2A2ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xE6821E09F48C721BULL + 0xA8CD3FCADEF9A627ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xCEDD821E2E94DA5DULL + 0xE2301E66FC93399FULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 13U) ^ RotL64(aNonceWordG, 27U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 3141U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 3475U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 11U) ^ RotL64(aNonceWordF, 34U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 2926U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((aIndex + 946U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aIngress, 23U)) ^ (RotL64(aCross, 3U) + RotL64(aPrevious, 54U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = ((aWandererA + RotL64(aIngress, 11U)) + 11274974230580265396U) + RotL64(aNonceWordC, 18U);
            aOrbiterE = (aWandererB + RotL64(aCross, 5U)) + 16658438747342741547U;
            aOrbiterI = (((aWandererH + RotL64(aPrevious, 24U)) + RotL64(aCarry, 23U)) + 16612986966106053844U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (aWandererD + RotL64(aScatter, 37U)) + 9329502236843231290U;
            aOrbiterA = (aWandererG + RotL64(aPrevious, 35U)) + 14088261356708344656U;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 47U)) + RotL64(aCarry, 41U)) + 13692608802007789581U;
            aOrbiterB = (aWandererC + RotL64(aScatter, 39U)) + 6824473946645682398U;
            aOrbiterD = ((aWandererI + RotL64(aCross, 13U)) + RotL64(aCarry, 19U)) + 2072915876348570040U;
            aOrbiterC = (aWandererE + RotL64(aIngress, 42U)) + 7420507753044460759U;
            aOrbiterF = (((aWandererF + RotL64(aPrevious, 29U)) + 4677557318688502593U) + aPhaseFOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1]) + RotL64(aNonceWordA, 31U);
            aOrbiterJ = (aWandererJ + RotL64(aCross, 3U)) + 15081678577055628459U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 7026792817486507482U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 14871665922943969918U) ^ RotL64(aNonceWordH, 57U);
            aOrbiterI = RotL64((aOrbiterI * 694073180313083145U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 6807734532159292872U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 17882797335141303280U) ^ RotL64(aNonceWordD, 29U);
            aOrbiterG = RotL64((aOrbiterG * 15439872930381050291U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 9233542707022629190U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 1205501586581350876U;
            aOrbiterK = RotL64((aOrbiterK * 2596053290311090589U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 10878718669747466677U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 8066049063548639241U;
            aOrbiterH = RotL64((aOrbiterH * 3031382633089381605U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 861295180226875235U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 9134969787937288583U;
            aOrbiterB = RotL64((aOrbiterB * 7565008208670843555U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 6726642007159809594U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 8061661744643240470U;
            aOrbiterC = RotL64((aOrbiterC * 6703498926835391813U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 13541412083111962884U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 8617442758729315637U;
            aOrbiterJ = RotL64((aOrbiterJ * 15471862889276160953U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 16884403561131293362U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 9490680911678221233U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15988763830018001033U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 10486145044311386738U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 10200001044821063684U;
            aOrbiterA = RotL64((aOrbiterA * 16149790736141571017U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 6997073594007878034U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 13585783612009989767U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11425303157774550449U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 3847846040256340653U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 11274974230580265396U;
            aOrbiterF = RotL64((aOrbiterF * 13970270689108369205U), 53U);
            //
            aIngress = RotL64(aOrbiterC, 18U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + RotL64(aOrbiterE, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aScatter, 21U) + aOrbiterF) + RotL64(aOrbiterH, 48U)) + RotL64(aNonceWordE, 39U));
            aWandererG = aWandererG + ((RotL64(aCross, 5U) + RotL64(aOrbiterB, 23U)) + aOrbiterJ);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 43U)) + aOrbiterC) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 27U)) + aOrbiterK) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterF, 5U)) + aOrbiterB);
            aWandererI = aWandererI + (((RotL64(aIngress, 13U) + aOrbiterD) + RotL64(aOrbiterA, 37U)) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 10U) + RotL64(aOrbiterG, 54U)) + aOrbiterD);
            aWandererD = aWandererD + ((RotL64(aCross, 51U) + aOrbiterE) + RotL64(aOrbiterA, 41U));
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 27U) + aOrbiterC) + RotL64(aOrbiterI, 3U)) + RotL64(aNonceWordG, 55U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 19U) + RotL64(aOrbiterK, 39U)) + aOrbiterG);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 44U) + aOrbiterH) + RotL64(aOrbiterA, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 48U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 46U));
            aCarry = aCarry + RotL64(aWandererE, 35U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 11U) ^ RotL64(aNonceWordD, 21U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 6565U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 5611U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 13U) ^ RotL64(aNonceWordG, 40U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 5972U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 8162U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 60U) ^ RotL64(aPrevious, 13U)) + (RotL64(aIngress, 29U) + RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = (((aWandererH + RotL64(aScatter, 39U)) + RotL64(aCarry, 47U)) + 17264605017518259932U) + RotL64(aNonceWordG, 39U);
            aOrbiterE = ((aWandererG + RotL64(aCross, 30U)) + RotL64(aCarry, 3U)) + 15209184354580778643U;
            aOrbiterD = (aWandererB + RotL64(aPrevious, 19U)) + 3299527965014731384U;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 21U)) + 16293096431816127821U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 47U)) + 11031983436878828337U) + aPhaseFOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = (aWandererI + RotL64(aPrevious, 11U)) + 9188018632448236358U;
            aOrbiterI = (((aWandererE + RotL64(aIngress, 43U)) + RotL64(aCarry, 37U)) + 13420816400363406556U) + RotL64(aNonceWordA, 30U);
            aOrbiterA = (aWandererC + RotL64(aCross, 52U)) + 2485063384097917101U;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 27U)) + 3089135816938128264U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aIngress, 5U)) + 10730544971770435788U;
            aOrbiterF = (aWandererK + RotL64(aPrevious, 35U)) + 10431767565618874806U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 14883796491656899074U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 13465877783538483706U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14311686051108108503U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 13322163435314643713U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 3307316600284371955U;
            aOrbiterE = RotL64((aOrbiterE * 12337846092069506365U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 4950101626975919939U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 2596253994220103666U;
            aOrbiterB = RotL64((aOrbiterB * 7181706961838582889U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 17961706029559914243U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 10321902557977495175U;
            aOrbiterI = RotL64((aOrbiterI * 16189559888625084711U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 18146616411403012772U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 8414050129421955787U) ^ RotL64(aNonceWordC, 29U);
            aOrbiterC = RotL64((aOrbiterC * 14879448948196182863U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 11739172334166341121U) + RotL64(aNonceWordE, 11U);
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 7936637782633487291U;
            aOrbiterH = RotL64((aOrbiterH * 14940929920543800413U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 3160044627483874242U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 16816384076887379704U;
            aOrbiterJ = RotL64((aOrbiterJ * 5052772186568301951U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 8101560104988710226U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 8851416379738817624U;
            aOrbiterG = RotL64((aOrbiterG * 16767420038937389027U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 9941784290055185679U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 14495651885701938495U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1540692851998143607U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 10599676325220702167U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 16092000942942971187U;
            aOrbiterK = RotL64((aOrbiterK * 2457268192247656817U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 16168470945107928109U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 17264605017518259932U;
            aOrbiterF = RotL64((aOrbiterF * 15038386057529909273U), 27U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterJ, 29U);
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + RotL64(aOrbiterG, 54U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aPrevious, 37U) + aOrbiterF) + RotL64(aOrbiterJ, 35U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterC, 21U)) + aOrbiterH) + RotL64(aNonceWordH, 23U));
            aWandererH = aWandererH + (((RotL64(aCross, 47U) + aOrbiterH) + RotL64(aOrbiterE, 46U)) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 10U) + aOrbiterA) + RotL64(aOrbiterD, 43U)) + RotL64(aNonceWordF, 41U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 23U) + aOrbiterA) + RotL64(aOrbiterC, 57U)) + RotL64(aCarry, 57U)) + aPhaseFWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 53U) + aOrbiterJ) + RotL64(aOrbiterH, 53U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterE, 27U)) + aOrbiterG);
            aWandererE = aWandererE ^ ((RotL64(aCross, 57U) + aOrbiterB) + RotL64(aOrbiterH, 18U));
            aWandererD = aWandererD + ((RotL64(aIngress, 18U) + RotL64(aOrbiterD, 3U)) + aOrbiterI);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterK, 13U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 39U) + RotL64(aOrbiterD, 41U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererK, 52U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 38U));
            aCarry = aCarry + RotL64(aWandererJ, 5U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 11U) ^ RotL64(aNonceWordF, 47U)) ^ RotL64(aNonceWordB, 60U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 14431U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((aIndex + 11909U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 41U) ^ RotL64(aNonceWordE, 13U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 14819U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneC[((aIndex + 15799U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 10U) ^ RotL64(aPrevious, 57U)) + (RotL64(aIngress, 27U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterG = ((aWandererD + RotL64(aScatter, 19U)) + 3339283916456813609U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aIngress, 51U)) + 11339086426180649584U;
            aOrbiterC = (aWandererK + RotL64(aCross, 22U)) + 16819191669329316585U;
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 53U)) + 8361916937762630725U) + RotL64(aNonceWordG, 39U);
            aOrbiterE = (aWandererJ + RotL64(aScatter, 5U)) + 18031328374429899857U;
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 3U)) + RotL64(aCarry, 47U)) + 18261756894092897276U;
            aOrbiterI = ((aWandererE + RotL64(aCross, 43U)) + RotL64(aCarry, 19U)) + 4250319792907645666U;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 57U)) + RotL64(aCarry, 5U)) + 1492411503643460886U;
            aOrbiterD = (((aWandererA + RotL64(aScatter, 46U)) + 17369549067879344180U) + aPhaseFOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1]) + RotL64(aNonceWordA, 19U);
            aOrbiterH = (aWandererF + RotL64(aCross, 27U)) + 7301713524358676722U;
            aOrbiterJ = (aWandererB + RotL64(aIngress, 35U)) + 2985193736033012535U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 14086975808140927408U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 10390516547834639800U;
            aOrbiterC = RotL64((aOrbiterC * 11441293212275890819U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 18205555540941493267U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 16967799565443938873U) ^ RotL64(aNonceWordH, 59U);
            aOrbiterB = RotL64((aOrbiterB * 3009081009044782443U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 9209505304067579944U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 3522631966146762306U) ^ RotL64(aNonceWordB, 29U);
            aOrbiterF = RotL64((aOrbiterF * 3441982898533162599U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 8811497120829041188U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 14707301680850257294U;
            aOrbiterE = RotL64((aOrbiterE * 11383709499376464085U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 10080595991787801029U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 6822892187784299166U;
            aOrbiterA = RotL64((aOrbiterA * 7417016898027778287U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 1981637172055758689U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 16463077485583119324U;
            aOrbiterH = RotL64((aOrbiterH * 2876782050665869121U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 8383837717361569465U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 2788511294985017326U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2809163242875130677U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 3529607472855930041U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 8850940802020173766U;
            aOrbiterK = RotL64((aOrbiterK * 7821450253655655943U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 7469160295100147267U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 16973986572163482061U;
            aOrbiterI = RotL64((aOrbiterI * 15660743778376905023U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 12371372942863279718U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 12098525148034303633U;
            aOrbiterD = RotL64((aOrbiterD * 11234127652230231751U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 5138683482859889480U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 3339283916456813609U;
            aOrbiterJ = RotL64((aOrbiterJ * 10975353228235695455U), 3U);
            //
            aIngress = RotL64(aOrbiterA, 24U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 39U));
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 22U));
            aIngress = aIngress + RotL64(aOrbiterB, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterC, 35U)) + aOrbiterE) + RotL64(aNonceWordD, 11U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterI, 5U)) + aOrbiterE);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 24U) + RotL64(aOrbiterJ, 19U)) + aOrbiterC);
            aWandererI = aWandererI + (((RotL64(aCross, 5U) + RotL64(aOrbiterD, 14U)) + aOrbiterF) + RotL64(aCarry, 13U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterB, 47U));
            aWandererF = aWandererF + (((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 37U)) + aOrbiterK) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 37U) + aOrbiterH) + RotL64(aOrbiterA, 39U));
            aWandererH = aWandererH + (((RotL64(aCross, 48U) + RotL64(aOrbiterJ, 51U)) + aOrbiterK) + RotL64(aNonceWordF, 52U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterD, 43U)) + aOrbiterI);
            aWandererJ = aWandererJ + (((RotL64(aCross, 41U) + RotL64(aOrbiterA, 10U)) + aOrbiterD) + aPhaseFWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterG, 41U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 40U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 56U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 54U) ^ RotL64(aNonceWordD, 5U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 16789U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((aIndex + 17962U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 57U) ^ RotL64(aNonceWordF, 14U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19748U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 18911U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aPrevious, 4U)) ^ (RotL64(aIngress, 53U) + RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = (aWandererD + RotL64(aPrevious, 53U)) + 5697928251815176134U;
            aOrbiterA = (aWandererK + RotL64(aCross, 23U)) + 337587740689259575U;
            aOrbiterE = (aWandererI + RotL64(aIngress, 19U)) + 4927686903263973950U;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 51U)) + RotL64(aCarry, 37U)) + 3742409032569801033U;
            aOrbiterI = (((aWandererE + RotL64(aCross, 41U)) + 1608092659172197650U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1]) + RotL64(aNonceWordD, 17U);
            aOrbiterB = (aWandererA + RotL64(aIngress, 44U)) + 15848744267145717509U;
            aOrbiterJ = (aWandererG + RotL64(aScatter, 11U)) + 15300174177963339253U;
            aOrbiterD = (aWandererF + RotL64(aPrevious, 47U)) + 14162868453323648628U;
            aOrbiterC = (((aWandererJ + RotL64(aCross, 27U)) + RotL64(aCarry, 41U)) + 12020167069983729869U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aScatter, 39U)) + 16259538291658723956U;
            aOrbiterF = (((aWandererH + RotL64(aPrevious, 14U)) + RotL64(aCarry, 27U)) + 8516686212464112245U) + RotL64(aNonceWordG, 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 3722184575520553132U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 5663609293306386784U;
            aOrbiterE = RotL64((aOrbiterE * 14364218128780764749U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 15265344442454471986U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 3050323350098829515U;
            aOrbiterI = RotL64((aOrbiterI * 5890624677162388135U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 1093356813820599238U) + RotL64(aNonceWordE, 58U);
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 15167726103772238440U;
            aOrbiterB = RotL64((aOrbiterB * 5719466863561311069U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 15170797965325981472U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 17826286701992981628U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11186808881726573677U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 14710892030473425181U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 397194787697553904U) ^ RotL64(aNonceWordA, 59U);
            aOrbiterD = RotL64((aOrbiterD * 14368930300818752833U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 1273724124862533034U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 13018397560392545616U;
            aOrbiterC = RotL64((aOrbiterC * 4644812473262395329U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 9638716186445643730U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 7255587739807843785U;
            aOrbiterK = RotL64((aOrbiterK * 6055682981584011189U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 9272350563697399628U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 1040729335295009339U;
            aOrbiterF = RotL64((aOrbiterF * 17825687660830291443U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 12128124729613601747U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 2285238815562202219U;
            aOrbiterH = RotL64((aOrbiterH * 15398840993074390573U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 6339113298619163493U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 5911895708485037040U;
            aOrbiterA = RotL64((aOrbiterA * 3271006139923200439U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 7601399508218901328U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 5697928251815176134U;
            aOrbiterG = RotL64((aOrbiterG * 8184257916861355735U), 13U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterJ, 21U);
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterG, 26U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterG, 53U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterD, 27U)) + aOrbiterI) + RotL64(aCarry, 13U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 29U) + aOrbiterJ) + RotL64(aOrbiterG, 18U)) + RotL64(aNonceWordB, 9U));
            aWandererG = aWandererG + (((RotL64(aCross, 27U) + RotL64(aOrbiterK, 47U)) + aOrbiterB) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 57U) + aOrbiterI) + RotL64(aOrbiterF, 13U));
            aWandererH = aWandererH + (((RotL64(aScatter, 23U) + RotL64(aOrbiterE, 39U)) + aOrbiterC) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 20U) + RotL64(aOrbiterB, 57U)) + aOrbiterA) + aPhaseFWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 3U) + aOrbiterF) + RotL64(aOrbiterJ, 60U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterH, 21U)) + aOrbiterJ);
            aWandererE = aWandererE + ((RotL64(aCross, 43U) + RotL64(aOrbiterA, 37U)) + aOrbiterF);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 48U) + RotL64(aOrbiterF, 51U)) + aOrbiterG) + RotL64(aNonceWordC, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 26U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 21U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 53U) ^ RotL64(aNonceWordA, 23U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23681U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneA[((aIndex + 23246U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 28U) ^ RotL64(aNonceWordD, 11U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26585U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneA[((aIndex + 26031U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 50U) + RotL64(aIngress, 35U)) ^ (RotL64(aPrevious, 23U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterJ = (aWandererA + RotL64(aIngress, 43U)) + 10336802574069791273U;
            aOrbiterE = ((aWandererG + RotL64(aCross, 39U)) + 169025388197058936U) + RotL64(aNonceWordB, 5U);
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 48U)) + 6541354188379168846U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aScatter, 13U)) + 16223920526599306104U;
            aOrbiterG = ((aWandererH + RotL64(aCross, 29U)) + RotL64(aCarry, 11U)) + 12756613707692514808U;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 53U)) + 5082475548176484035U) + RotL64(aNonceWordH, 59U);
            aOrbiterK = (aWandererF + RotL64(aIngress, 41U)) + 4907435526952698526U;
            aOrbiterC = (aWandererD + RotL64(aScatter, 4U)) + 14236627073831834337U;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 21U)) + RotL64(aCarry, 3U)) + 11502511046130497584U;
            aOrbiterF = (((aWandererK + RotL64(aScatter, 57U)) + RotL64(aCarry, 53U)) + 3679044835550219497U) + aPhaseFOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aIngress, 51U)) + 11254838916686736746U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 10582608424233200966U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 10449735026385340313U;
            aOrbiterA = RotL64((aOrbiterA * 7363770199734997411U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 4628253464169957835U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 17664454668473204465U;
            aOrbiterI = RotL64((aOrbiterI * 4234720298731378527U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 3798386391743884889U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 1379331161819246587U;
            aOrbiterC = RotL64((aOrbiterC * 13086160171095077295U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 9816600392407327227U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 16781971616348376878U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12503867584828289879U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 4807797577690520554U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 2492057261148595922U;
            aOrbiterJ = RotL64((aOrbiterJ * 9453302540675483005U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 7909676419643119585U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 256053568910383007U;
            aOrbiterD = RotL64((aOrbiterD * 11965085163352053161U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 16179914439220412472U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 3968867762761955845U;
            aOrbiterK = RotL64((aOrbiterK * 7473632378251893139U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 7474832923901283742U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 4736994731050735779U) ^ RotL64(aNonceWordG, 20U);
            aOrbiterB = RotL64((aOrbiterB * 9839654409121414047U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 596484364660389193U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 13822222274464306169U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1723502278319885511U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 16307920280681985443U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 3505106171801702915U;
            aOrbiterE = RotL64((aOrbiterE * 8479675421552861243U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 4987142580981135150U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterF) ^ 10336802574069791273U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1]) ^ RotL64(aNonceWordC, 57U);
            aOrbiterG = RotL64((aOrbiterG * 2670706512498539705U), 41U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterB, 11U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 24U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterG, 37U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterH, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterA, 43U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 13U) + aOrbiterF) + RotL64(aOrbiterG, 24U)) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 19U) + aOrbiterH) + RotL64(aOrbiterE, 57U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 44U) + aOrbiterD) + RotL64(aOrbiterC, 39U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterK, 13U)) + aOrbiterB);
            aWandererB = aWandererB + ((RotL64(aIngress, 11U) + aOrbiterE) + RotL64(aOrbiterI, 37U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterD, 21U)) + aOrbiterG) + RotL64(aNonceWordD, 47U));
            aWandererH = aWandererH + (((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 46U)) + aOrbiterB) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 60U) + RotL64(aOrbiterH, 19U)) + aOrbiterB) + RotL64(aNonceWordF, 15U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterA, 3U)) + aOrbiterH) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 27U) + aOrbiterJ) + RotL64(aOrbiterD, 29U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 60U));
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 39U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 56U) ^ RotL64(aNonceWordH, 5U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29170U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27539U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 48U) ^ RotL64(aNonceWordD, 57U)) ^ RotL64(aNonceWordF, 5U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29154U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((aIndex + 30941U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aIngress, 23U)) ^ (RotL64(aCarry, 52U) ^ RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 6U)) + 12775735908960052604U) + RotL64(aNonceWordA, 49U);
            aOrbiterJ = (aWandererC + RotL64(aScatter, 41U)) + 11791373812080296887U;
            aOrbiterG = ((aWandererD + RotL64(aCross, 23U)) + RotL64(aCarry, 19U)) + 5537362877706057303U;
            aOrbiterF = (aWandererB + RotL64(aIngress, 13U)) + 2023912048504189380U;
            aOrbiterK = (aWandererF + RotL64(aCross, 3U)) + 17668828109963766893U;
            aOrbiterC = (aWandererI + RotL64(aScatter, 51U)) + 558908629933941224U;
            aOrbiterI = (((aWandererK + RotL64(aPrevious, 43U)) + RotL64(aCarry, 13U)) + 1479633119685446888U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aIngress, 57U)) + RotL64(aCarry, 3U)) + 15460320397843364063U;
            aOrbiterB = (aWandererG + RotL64(aPrevious, 21U)) + 10059749397555469054U;
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 60U)) + 9987633811929693924U) + aPhaseFOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aIngress, 35U)) + 10087337844580228269U) + RotL64(aNonceWordG, 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 4446204415503364254U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 15106063243302192717U;
            aOrbiterG = RotL64((aOrbiterG * 13273756657334709803U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 9430197906134676162U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 1226048679997253363U;
            aOrbiterK = RotL64((aOrbiterK * 14247538885252664127U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 10611580584157624739U) + RotL64(aNonceWordH, 47U);
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 3137391249289641509U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5462682413239873181U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 9327201928815412810U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 7890659377013147073U;
            aOrbiterI = RotL64((aOrbiterI * 13827717178378062047U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 10675114832750356941U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 8804440385852327267U;
            aOrbiterA = RotL64((aOrbiterA * 8520671775587260601U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 12871947817782057116U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 11015991745792051390U;
            aOrbiterB = RotL64((aOrbiterB * 17152451500505815031U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 6320437975845673731U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 702457937087191287U) ^ RotL64(aNonceWordD, 34U);
            aOrbiterH = RotL64((aOrbiterH * 17491257114676739589U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 16629064896250312921U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 6054107387816339103U;
            aOrbiterE = RotL64((aOrbiterE * 6983767878966747219U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 13274874838094190290U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 12211422735294360321U;
            aOrbiterD = RotL64((aOrbiterD * 5113738196151089817U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 15338616110718583619U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 1475787183754511373U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10904607643785840003U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 15486810401396777742U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 12775735908960052604U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7478156942468930207U), 47U);
            //
            aIngress = RotL64(aOrbiterE, 28U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterJ, 41U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 44U));
            aIngress = aIngress + RotL64(aOrbiterK, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterG, 39U)) + aOrbiterF) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterB, 21U)) + aOrbiterA);
            aWandererG = aWandererG + ((RotL64(aScatter, 11U) + RotL64(aOrbiterF, 56U)) + aOrbiterA);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 51U)) + aOrbiterJ) + RotL64(aNonceWordF, 5U));
            aWandererH = aWandererH + (((RotL64(aScatter, 30U) + aOrbiterF) + RotL64(aOrbiterE, 23U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 51U) + aOrbiterH) + RotL64(aOrbiterI, 27U));
            aWandererF = aWandererF + (((RotL64(aIngress, 47U) + RotL64(aOrbiterD, 19U)) + aOrbiterI) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 3U) + aOrbiterF) + RotL64(aOrbiterB, 47U));
            aWandererD = aWandererD + (((RotL64(aScatter, 37U) + RotL64(aOrbiterK, 30U)) + aOrbiterJ) + RotL64(aNonceWordE, 41U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterB, 5U)) + aOrbiterC);
            aWandererC = aWandererC + (((RotL64(aPrevious, 6U) + aOrbiterA) + RotL64(aOrbiterI, 53U)) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 48U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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

void Soccer_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 7801U)) & S_BLOCK1], 22U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 1941U)) & W_KEY1], 53U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 6366U)) & W_KEY1], 41U) ^ RotL64(mSource[((aIndex + 5755U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCarry, 13U)) ^ (RotL64(aIngress, 28U) + RotL64(aCross, 43U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = (aWandererI + RotL64(aPrevious, 27U)) + 3339283916456813609U;
            aOrbiterK = (aWandererD + RotL64(aScatter, 5U)) + 11339086426180649584U;
            aOrbiterE = (aWandererB + RotL64(aIngress, 43U)) + 16819191669329316585U;
            aOrbiterJ = (((aWandererJ + RotL64(aCross, 14U)) + RotL64(aCarry, 51U)) + 8361916937762630725U) + aPhaseCOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = (aWandererA + RotL64(aIngress, 35U)) + 18031328374429899857U;
            aOrbiterG = (aWandererC + RotL64(aPrevious, 53U)) + 18261756894092897276U;
            aOrbiterF = (aWandererE + RotL64(aCross, 47U)) + 4250319792907645666U;
            aOrbiterB = (((aWandererG + RotL64(aScatter, 10U)) + RotL64(aCarry, 43U)) + 1492411503643460886U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aIngress, 57U)) + RotL64(aCarry, 19U)) + 17369549067879344180U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 7301713524358676722U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 2985193736033012535U;
            aOrbiterE = RotL64((aOrbiterE * 7473297294949338265U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 14086975808140927408U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 10390516547834639800U;
            aOrbiterG = RotL64((aOrbiterG * 11441293212275890819U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 18205555540941493267U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 16967799565443938873U;
            aOrbiterB = RotL64((aOrbiterB * 3009081009044782443U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 9209505304067579944U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 3522631966146762306U;
            aOrbiterH = RotL64((aOrbiterH * 3441982898533162599U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 8811497120829041188U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 14707301680850257294U;
            aOrbiterI = RotL64((aOrbiterI * 11383709499376464085U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 10080595991787801029U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 6822892187784299166U;
            aOrbiterJ = RotL64((aOrbiterJ * 7417016898027778287U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 1981637172055758689U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 16463077485583119324U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2876782050665869121U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 8383837717361569465U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 2788511294985017326U;
            aOrbiterK = RotL64((aOrbiterK * 2809163242875130677U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 3529607472855930041U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 8850940802020173766U;
            aOrbiterD = RotL64((aOrbiterD * 7821450253655655943U), 23U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 57U);
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + (RotL64(aOrbiterH, 6U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aScatter, 53U) + aOrbiterJ) + RotL64(aOrbiterG, 47U)) + aPhaseCWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 13U) + RotL64(aOrbiterB, 56U)) + aOrbiterD);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 19U) + aOrbiterG) + RotL64(aOrbiterI, 37U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 30U) + aOrbiterB) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 37U) + aOrbiterG) + RotL64(aOrbiterB, 11U));
            aWandererB = aWandererB + (((RotL64(aScatter, 43U) + aOrbiterF) + RotL64(aOrbiterB, 19U)) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterE, 42U)) + aOrbiterG);
            aWandererE = aWandererE + ((RotL64(aCross, 60U) + aOrbiterF) + RotL64(aOrbiterI, 51U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 5U) + aOrbiterH) + RotL64(aOrbiterE, 5U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + (RotL64(aWandererJ, 36U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 23U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 16275U)) & S_BLOCK1], 44U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 8272U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15628U)) & W_KEY1], 48U) ^ RotL64(aKeyRowReadB[((aIndex + 13257U)) & W_KEY1], 39U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aPrevious, 27U)) ^ (RotL64(aIngress, 39U) + RotL64(aCross, 12U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = (aWandererG + RotL64(aScatter, 10U)) + 17264605017518259932U;
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 47U)) + RotL64(aCarry, 19U)) + 15209184354580778643U;
            aOrbiterE = ((aWandererD + RotL64(aIngress, 39U)) + RotL64(aCarry, 37U)) + 3299527965014731384U;
            aOrbiterA = (aWandererJ + RotL64(aCross, 51U)) + 16293096431816127821U;
            aOrbiterD = (aWandererE + RotL64(aIngress, 30U)) + 11031983436878828337U;
            aOrbiterG = (aWandererA + RotL64(aPrevious, 35U)) + 9188018632448236358U;
            aOrbiterJ = (aWandererF + RotL64(aCross, 5U)) + 13420816400363406556U;
            aOrbiterF = (((aWandererB + RotL64(aScatter, 21U)) + RotL64(aCarry, 5U)) + 2485063384097917101U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = ((aWandererC + RotL64(aCross, 57U)) + 3089135816938128264U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 10730544971770435788U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 10431767565618874806U;
            aOrbiterE = RotL64((aOrbiterE * 4723078464590561545U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 14883796491656899074U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 13465877783538483706U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14311686051108108503U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 13322163435314643713U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 3307316600284371955U;
            aOrbiterJ = RotL64((aOrbiterJ * 12337846092069506365U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 4950101626975919939U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 2596253994220103666U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7181706961838582889U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 17961706029559914243U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 10321902557977495175U;
            aOrbiterI = RotL64((aOrbiterI * 16189559888625084711U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 18146616411403012772U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 8414050129421955787U;
            aOrbiterK = RotL64((aOrbiterK * 14879448948196182863U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 11739172334166341121U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 7936637782633487291U;
            aOrbiterA = RotL64((aOrbiterA * 14940929920543800413U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 3160044627483874242U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 16816384076887379704U;
            aOrbiterG = RotL64((aOrbiterG * 5052772186568301951U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 8101560104988710226U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 8851416379738817624U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16767420038937389027U), 43U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 47U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 10U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 53U));
            aIngress = aIngress + RotL64(aOrbiterI, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aCross, 11U) + RotL64(aOrbiterK, 27U)) + aOrbiterG);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterA, 13U)) + aOrbiterE);
            aWandererK = aWandererK + (((RotL64(aPrevious, 58U) + aOrbiterD) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterE, 40U)) + aOrbiterI);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 19U) + aOrbiterG) + RotL64(aOrbiterI, 53U)) + aPhaseCWandererUpdateSaltC[((aIndex + 10U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 51U) + aOrbiterF) + RotL64(aOrbiterH, 35U));
            aWandererC = aWandererC + (((RotL64(aCross, 47U) + aOrbiterI) + RotL64(aOrbiterA, 19U)) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterJ, 4U)) + aOrbiterK);
            aWandererE = aWandererE + (((RotL64(aCross, 6U) + aOrbiterF) + RotL64(aOrbiterK, 47U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 18U));
            aCarry = aCarry + RotL64(aWandererJ, 35U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22182U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneA[((aIndex + 22735U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 20990U)) & W_KEY1], 11U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 24407U)) & W_KEY1], 40U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCross, 22U)) ^ (RotL64(aIngress, 47U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = ((aWandererA + RotL64(aCross, 19U)) + RotL64(aCarry, 47U)) + 5697928251815176134U;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 30U)) + RotL64(aCarry, 13U)) + 337587740689259575U;
            aOrbiterF = (aWandererB + RotL64(aIngress, 41U)) + 4927686903263973950U;
            aOrbiterE = (aWandererF + RotL64(aScatter, 53U)) + 3742409032569801033U;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 47U)) + 1608092659172197650U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = (aWandererE + RotL64(aIngress, 37U)) + 15848744267145717509U;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 3U)) + 15300174177963339253U) + aPhaseCOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aCross, 58U)) + 14162868453323648628U;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 23U)) + RotL64(aCarry, 3U)) + 12020167069983729869U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 16259538291658723956U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 8516686212464112245U;
            aOrbiterF = RotL64((aOrbiterF * 4731296903548893627U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 3722184575520553132U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 5663609293306386784U;
            aOrbiterA = RotL64((aOrbiterA * 14364218128780764749U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 15265344442454471986U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 3050323350098829515U;
            aOrbiterE = RotL64((aOrbiterE * 5890624677162388135U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 1093356813820599238U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 15167726103772238440U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5719466863561311069U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 15170797965325981472U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 17826286701992981628U;
            aOrbiterJ = RotL64((aOrbiterJ * 11186808881726573677U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 14710892030473425181U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 397194787697553904U;
            aOrbiterC = RotL64((aOrbiterC * 14368930300818752833U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 1273724124862533034U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 13018397560392545616U;
            aOrbiterD = RotL64((aOrbiterD * 4644812473262395329U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 9638716186445643730U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 7255587739807843785U;
            aOrbiterH = RotL64((aOrbiterH * 6055682981584011189U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 9272350563697399628U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 1040729335295009339U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17825687660830291443U), 39U);
            //
            aIngress = RotL64(aOrbiterG, 53U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 60U));
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 35U)) + aOrbiterH);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 30U) + RotL64(aOrbiterD, 18U)) + aOrbiterG) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 57U) + RotL64(aOrbiterC, 27U)) + aOrbiterG);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 41U) + aOrbiterG) + RotL64(aOrbiterH, 51U));
            aWandererA = aWandererA + ((RotL64(aCross, 47U) + RotL64(aOrbiterJ, 57U)) + aOrbiterH);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 51U) + aOrbiterE) + RotL64(aOrbiterF, 43U)) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 20U) + aOrbiterA) + RotL64(aOrbiterB, 11U)) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterE, 4U));
            aWandererF = aWandererF + (((RotL64(aCross, 11U) + aOrbiterA) + RotL64(aOrbiterH, 39U)) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 14U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 43U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31012U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((aIndex + 25330U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24792U)) & S_BLOCK1], 50U) ^ RotL64(mSource[((aIndex + 25499U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 50U) ^ RotL64(aPrevious, 5U)) ^ (RotL64(aCross, 35U) + RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = (aWandererB + RotL64(aScatter, 42U)) + 11274974230580265396U;
            aOrbiterJ = (((aWandererJ + RotL64(aIngress, 19U)) + RotL64(aCarry, 5U)) + 16658438747342741547U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aCross, 37U)) + 16612986966106053844U) + aPhaseCOrbiterAssignSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 57U)) + RotL64(aCarry, 47U)) + 9329502236843231290U;
            aOrbiterI = (aWandererC + RotL64(aCross, 47U)) + 14088261356708344656U;
            aOrbiterA = (aWandererE + RotL64(aIngress, 13U)) + 13692608802007789581U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 28U)) + RotL64(aCarry, 21U)) + 6824473946645682398U;
            aOrbiterF = (aWandererF + RotL64(aPrevious, 53U)) + 2072915876348570040U;
            aOrbiterG = (aWandererD + RotL64(aScatter, 23U)) + 7420507753044460759U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 4677557318688502593U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 15081678577055628459U;
            aOrbiterH = RotL64((aOrbiterH * 16659305295251177155U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 7026792817486507482U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 14871665922943969918U;
            aOrbiterI = RotL64((aOrbiterI * 694073180313083145U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 6807734532159292872U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 17882797335141303280U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15439872930381050291U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 9233542707022629190U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 1205501586581350876U;
            aOrbiterB = RotL64((aOrbiterB * 2596053290311090589U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 10878718669747466677U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 8066049063548639241U;
            aOrbiterE = RotL64((aOrbiterE * 3031382633089381605U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 861295180226875235U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 9134969787937288583U;
            aOrbiterA = RotL64((aOrbiterA * 7565008208670843555U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 6726642007159809594U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 8061661744643240470U;
            aOrbiterF = RotL64((aOrbiterF * 6703498926835391813U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 13541412083111962884U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 8617442758729315637U;
            aOrbiterG = RotL64((aOrbiterG * 15471862889276160953U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 16884403561131293362U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 9490680911678221233U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15988763830018001033U), 11U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 23U);
            aIngress = aIngress + (RotL64(aOrbiterK, 56U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 19U) + aOrbiterF) + RotL64(aOrbiterG, 20U)) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 13U)) + aOrbiterE) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 52U) + RotL64(aOrbiterK, 47U)) + aOrbiterI) + aPhaseCWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterE, 3U)) + aOrbiterJ);
            aWandererG = aWandererG + ((RotL64(aCross, 5U) + RotL64(aOrbiterA, 35U)) + aOrbiterB);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterH, 57U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterG, 53U)) + aOrbiterB);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 48U) + RotL64(aOrbiterA, 24U)) + aOrbiterI);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterF, 43U)) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 10U));
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + RotL64(aWandererD, 43U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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

void Soccer_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 3400U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2189U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2135U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((aIndex + 1088U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 27U) + RotL64(aPrevious, 60U)) + (RotL64(aIngress, 13U) ^ RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = (aWandererG + RotL64(aIngress, 35U)) + 11274974230580265396U;
            aOrbiterF = ((aWandererF + RotL64(aScatter, 56U)) + RotL64(aCarry, 53U)) + 16658438747342741547U;
            aOrbiterI = (aWandererA + RotL64(aCross, 3U)) + 16612986966106053844U;
            aOrbiterK = (((aWandererH + RotL64(aPrevious, 19U)) + RotL64(aCarry, 21U)) + 9329502236843231290U) + aPhaseDOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = (((aWandererK + RotL64(aIngress, 11U)) + RotL64(aCarry, 35U)) + 14088261356708344656U) + aPhaseDOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 13692608802007789581U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 6824473946645682398U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13619437545775237601U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 2072915876348570040U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 7420507753044460759U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13239288539564571257U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 4677557318688502593U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 15081678577055628459U;
            aOrbiterK = RotL64((aOrbiterK * 16659305295251177155U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 7026792817486507482U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 14871665922943969918U;
            aOrbiterF = RotL64((aOrbiterF * 694073180313083145U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 6807734532159292872U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 17882797335141303280U;
            aOrbiterG = RotL64((aOrbiterG * 15439872930381050291U), 21U);
            //
            aIngress = RotL64(aOrbiterH, 29U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + RotL64(aOrbiterK, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterF, 47U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterG, 21U)) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 58U) + aOrbiterG) + RotL64(aOrbiterH, 39U));
            aWandererH = aWandererH + ((((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterK, 58U)) + RotL64(aCarry, 39U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 21U) + aOrbiterI) + RotL64(aOrbiterH, 3U)) + aPhaseDWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 28U));
            aCarry = aCarry + RotL64(aWandererF, 37U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 15143U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneD[((aIndex + 11647U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11441U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneB[((aIndex + 11001U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 48U) ^ RotL64(aCarry, 23U)) + (RotL64(aPrevious, 35U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = ((aWandererE + RotL64(aCross, 11U)) + RotL64(aCarry, 53U)) + 17264605017518259932U;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 23U)) + 15209184354580778643U) + aPhaseDOrbiterAssignSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 3U)) + 3299527965014731384U) + aPhaseDOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aScatter, 41U)) + RotL64(aCarry, 5U)) + 16293096431816127821U;
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 54U)) + RotL64(aCarry, 27U)) + 11031983436878828337U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 9188018632448236358U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 13420816400363406556U;
            aOrbiterH = RotL64((aOrbiterH * 10958221259662190519U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 2485063384097917101U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 3089135816938128264U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8813152992957361153U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 10730544971770435788U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 10431767565618874806U;
            aOrbiterK = RotL64((aOrbiterK * 4723078464590561545U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 14883796491656899074U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 13465877783538483706U;
            aOrbiterC = RotL64((aOrbiterC * 14311686051108108503U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 13322163435314643713U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 3307316600284371955U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12337846092069506365U), 19U);
            //
            aIngress = RotL64(aOrbiterK, 52U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + RotL64(aOrbiterC, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 19U)) + aOrbiterC) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 29U) + aOrbiterF) + RotL64(aOrbiterK, 39U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 56U) + RotL64(aOrbiterH, 3U)) + aOrbiterF) + RotL64(aCarry, 23U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterA, 53U)) + aOrbiterH);
            aWandererA = aWandererA + ((RotL64(aCross, 13U) + RotL64(aOrbiterK, 28U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 30U));
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererF, 21U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 18395U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22945U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 23629U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 18739U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aIngress, 54U)) ^ (RotL64(aPrevious, 37U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = (((aWandererG + RotL64(aCross, 46U)) + RotL64(aCarry, 3U)) + 10336802574069791273U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aIngress, 21U)) + RotL64(aCarry, 21U)) + 169025388197058936U;
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 29U)) + 6541354188379168846U;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 13U)) + RotL64(aCarry, 43U)) + 16223920526599306104U;
            aOrbiterA = ((aWandererE + RotL64(aCross, 3U)) + 12756613707692514808U) + aPhaseDOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 5082475548176484035U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 4907435526952698526U;
            aOrbiterK = RotL64((aOrbiterK * 1379692095754989215U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 14236627073831834337U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 11502511046130497584U;
            aOrbiterC = RotL64((aOrbiterC * 3460330807286625917U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 3679044835550219497U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 11254838916686736746U;
            aOrbiterG = RotL64((aOrbiterG * 8631695922983532915U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 10582608424233200966U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 10449735026385340313U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7363770199734997411U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 4628253464169957835U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 17664454668473204465U;
            aOrbiterA = RotL64((aOrbiterA * 4234720298731378527U), 3U);
            //
            aIngress = RotL64(aOrbiterG, 57U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 28U));
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 39U) + aOrbiterF) + RotL64(aOrbiterK, 35U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 51U) + aOrbiterF) + RotL64(aOrbiterG, 27U)) + RotL64(aCarry, 57U)) + aPhaseDWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 19U)) + aOrbiterA) + aPhaseDWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 21U) + RotL64(aOrbiterF, 56U)) + aOrbiterA) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 4U) + RotL64(aOrbiterK, 43U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 22U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 35U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 29336U)) & S_BLOCK1], 24U) ^ RotL64(aOperationLaneB[((aIndex + 26806U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26905U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 29419U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aIngress, 39U)) ^ (RotL64(aCross, 52U) ^ RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = ((aWandererB + RotL64(aCross, 35U)) + RotL64(aCarry, 23U)) + 3339283916456813609U;
            aOrbiterE = ((aWandererC + RotL64(aScatter, 52U)) + 11339086426180649584U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aIngress, 5U)) + RotL64(aCarry, 41U)) + 16819191669329316585U;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 43U)) + RotL64(aCarry, 5U)) + 8361916937762630725U;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 23U)) + 18031328374429899857U) + aPhaseDOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 18261756894092897276U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 4250319792907645666U;
            aOrbiterC = RotL64((aOrbiterC * 7053489184750217963U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 1492411503643460886U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 17369549067879344180U;
            aOrbiterD = RotL64((aOrbiterD * 2947354306696216579U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 7301713524358676722U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 2985193736033012535U;
            aOrbiterK = RotL64((aOrbiterK * 7473297294949338265U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 14086975808140927408U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 10390516547834639800U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11441293212275890819U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 18205555540941493267U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 16967799565443938873U;
            aOrbiterG = RotL64((aOrbiterG * 3009081009044782443U), 41U);
            //
            aIngress = RotL64(aOrbiterD, 13U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 47U)) + aOrbiterD);
            aWandererF = aWandererF + (((RotL64(aScatter, 3U) + aOrbiterD) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterD, 13U)) + aOrbiterK) + aPhaseDWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 36U) + aOrbiterG) + RotL64(aOrbiterK, 5U)) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 27U) + aOrbiterK) + RotL64(aOrbiterC, 56U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 58U));
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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

void Soccer_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 1220U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneC[((aIndex + 5797U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 3999U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneA[((aIndex + 5135U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 21U) ^ RotL64(aCross, 5U)) + (RotL64(aCarry, 34U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = (aWandererE + RotL64(aPrevious, 47U)) + 5697928251815176134U;
            aOrbiterA = (aWandererJ + RotL64(aCross, 57U)) + 337587740689259575U;
            aOrbiterK = (aWandererA + RotL64(aScatter, 11U)) + 4927686903263973950U;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 41U)) + RotL64(aCarry, 27U)) + 3742409032569801033U;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 19U)) + 1608092659172197650U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = (((aWandererK + RotL64(aCross, 3U)) + RotL64(aCarry, 43U)) + 15848744267145717509U) + aPhaseEOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aScatter, 30U)) + RotL64(aCarry, 13U)) + 15300174177963339253U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 14162868453323648628U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 12020167069983729869U;
            aOrbiterK = RotL64((aOrbiterK * 2071080217680099017U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 16259538291658723956U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 8516686212464112245U;
            aOrbiterB = RotL64((aOrbiterB * 4731296903548893627U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 3722184575520553132U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 5663609293306386784U;
            aOrbiterJ = RotL64((aOrbiterJ * 14364218128780764749U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 15265344442454471986U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 3050323350098829515U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5890624677162388135U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 1093356813820599238U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 15167726103772238440U;
            aOrbiterC = RotL64((aOrbiterC * 5719466863561311069U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 15170797965325981472U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 17826286701992981628U;
            aOrbiterI = RotL64((aOrbiterI * 11186808881726573677U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 14710892030473425181U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 397194787697553904U;
            aOrbiterA = RotL64((aOrbiterA * 14368930300818752833U), 5U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterI, 35U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 50U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 23U));
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 43U) + aOrbiterI) + RotL64(aOrbiterK, 21U));
            aWandererD = aWandererD + (((RotL64(aIngress, 5U) + RotL64(aOrbiterA, 29U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 13U) + aOrbiterA) + RotL64(aOrbiterF, 11U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 27U) + aOrbiterC) + RotL64(aOrbiterB, 4U)) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterI, 57U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 35U)) + aOrbiterA) + RotL64(aCarry, 53U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 20U) + RotL64(aOrbiterI, 43U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererC, 14U) ^ aWandererI);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 14803U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneD[((aIndex + 9868U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 10946U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 9972U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCross, 23U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 6U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = (((aWandererC + RotL64(aCross, 43U)) + RotL64(aCarry, 39U)) + 12775735908960052604U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aIngress, 3U)) + 11791373812080296887U;
            aOrbiterD = (aWandererA + RotL64(aScatter, 13U)) + 5537362877706057303U;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 53U)) + 2023912048504189380U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = (aWandererB + RotL64(aScatter, 26U)) + 17668828109963766893U;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 19U)) + RotL64(aCarry, 53U)) + 558908629933941224U;
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 37U)) + RotL64(aCarry, 13U)) + 1479633119685446888U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 15460320397843364063U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 10059749397555469054U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8671817118586065469U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 9987633811929693924U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 10087337844580228269U;
            aOrbiterA = RotL64((aOrbiterA * 13817142288940843815U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 4446204415503364254U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 15106063243302192717U;
            aOrbiterG = RotL64((aOrbiterG * 13273756657334709803U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 9430197906134676162U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 1226048679997253363U;
            aOrbiterH = RotL64((aOrbiterH * 14247538885252664127U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 10611580584157624739U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 3137391249289641509U;
            aOrbiterI = RotL64((aOrbiterI * 5462682413239873181U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 9327201928815412810U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 7890659377013147073U;
            aOrbiterE = RotL64((aOrbiterE * 13827717178378062047U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 10675114832750356941U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 8804440385852327267U;
            aOrbiterB = RotL64((aOrbiterB * 8520671775587260601U), 51U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 57U);
            aIngress = aIngress + (RotL64(aOrbiterA, 29U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aIngress, 21U) + RotL64(aOrbiterG, 51U)) + aOrbiterD);
            aWandererB = aWandererB ^ ((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterH, 13U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterI, 58U)) + aOrbiterB);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 30U) + aOrbiterE) + RotL64(aOrbiterB, 27U));
            aWandererC = aWandererC + ((((RotL64(aIngress, 47U) + aOrbiterH) + RotL64(aOrbiterA, 5U)) + RotL64(aCarry, 23U)) + aPhaseEWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterD, 43U)) + aOrbiterB) + aPhaseEWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 35U)) + aOrbiterI) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 60U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererK, 23U);
            aCarry = aCarry + RotL64(aIngress, 52U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 22946U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24390U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20945U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneC[((aIndex + 21355U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 21U) + RotL64(aCarry, 40U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = ((aWandererK + RotL64(aScatter, 56U)) + RotL64(aCarry, 57U)) + 11274974230580265396U;
            aOrbiterB = (aWandererA + RotL64(aIngress, 47U)) + 16658438747342741547U;
            aOrbiterH = (aWandererG + RotL64(aPrevious, 35U)) + 16612986966106053844U;
            aOrbiterG = ((aWandererC + RotL64(aCross, 41U)) + 9329502236843231290U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 3U)) + RotL64(aCarry, 27U)) + 14088261356708344656U;
            aOrbiterI = (((aWandererF + RotL64(aCross, 29U)) + RotL64(aCarry, 41U)) + 13692608802007789581U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 23U)) + 6824473946645682398U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 2072915876348570040U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 7420507753044460759U;
            aOrbiterH = RotL64((aOrbiterH * 13239288539564571257U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 4677557318688502593U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 15081678577055628459U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16659305295251177155U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 7026792817486507482U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 14871665922943969918U;
            aOrbiterF = RotL64((aOrbiterF * 694073180313083145U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 6807734532159292872U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 17882797335141303280U;
            aOrbiterG = RotL64((aOrbiterG * 15439872930381050291U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 9233542707022629190U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 1205501586581350876U;
            aOrbiterK = RotL64((aOrbiterK * 2596053290311090589U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 10878718669747466677U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 8066049063548639241U;
            aOrbiterI = RotL64((aOrbiterI * 3031382633089381605U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 861295180226875235U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 9134969787937288583U;
            aOrbiterJ = RotL64((aOrbiterJ * 7565008208670843555U), 39U);
            //
            aIngress = RotL64(aOrbiterB, 50U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 39U));
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterG, 29U)) + aOrbiterH) + RotL64(aCarry, 13U)) + aPhaseEWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 39U) + aOrbiterI) + RotL64(aOrbiterJ, 47U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 58U) + RotL64(aOrbiterH, 41U)) + aOrbiterB);
            aWandererF = aWandererF ^ (((RotL64(aCross, 47U) + aOrbiterH) + RotL64(aOrbiterF, 21U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 3U) + aOrbiterK) + RotL64(aOrbiterG, 13U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterH, 3U));
            aWandererK = aWandererK + (((RotL64(aCross, 11U) + RotL64(aOrbiterG, 60U)) + aOrbiterI) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 56U));
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + RotL64(aWandererK, 13U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 28854U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30643U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29459U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneD[((aIndex + 31373U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCarry, 41U)) ^ (RotL64(aCross, 6U) ^ RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = ((aWandererB + RotL64(aScatter, 35U)) + 10336802574069791273U) + aPhaseEOrbiterAssignSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = (aWandererC + RotL64(aPrevious, 43U)) + 169025388197058936U;
            aOrbiterI = (aWandererJ + RotL64(aCross, 5U)) + 6541354188379168846U;
            aOrbiterH = (((aWandererF + RotL64(aIngress, 28U)) + RotL64(aCarry, 39U)) + 16223920526599306104U) + aPhaseEOrbiterAssignSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aScatter, 53U)) + RotL64(aCarry, 51U)) + 12756613707692514808U;
            aOrbiterA = ((aWandererK + RotL64(aCross, 21U)) + RotL64(aCarry, 3U)) + 5082475548176484035U;
            aOrbiterF = (aWandererI + RotL64(aIngress, 11U)) + 4907435526952698526U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 14236627073831834337U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 11502511046130497584U;
            aOrbiterI = RotL64((aOrbiterI * 3460330807286625917U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 3679044835550219497U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 11254838916686736746U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8631695922983532915U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 10582608424233200966U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 10449735026385340313U;
            aOrbiterD = RotL64((aOrbiterD * 7363770199734997411U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 4628253464169957835U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 17664454668473204465U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4234720298731378527U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 3798386391743884889U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 1379331161819246587U;
            aOrbiterG = RotL64((aOrbiterG * 13086160171095077295U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 9816600392407327227U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 16781971616348376878U;
            aOrbiterH = RotL64((aOrbiterH * 12503867584828289879U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 4807797577690520554U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 2492057261148595922U;
            aOrbiterF = RotL64((aOrbiterF * 9453302540675483005U), 3U);
            //
            aIngress = RotL64(aOrbiterA, 5U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + RotL64(aOrbiterB, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aScatter, 19U) + RotL64(aOrbiterG, 29U)) + aOrbiterF);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterH, 21U)) + aOrbiterI);
            aWandererF = aWandererF + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterD, 12U)) + aOrbiterI);
            aWandererC = aWandererC ^ ((RotL64(aCross, 12U) + aOrbiterA) + RotL64(aOrbiterH, 41U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 57U) + aOrbiterH) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 51U)) + aPhaseEWandererUpdateSaltD[((aIndex + 6U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterI, 5U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterB, 51U)) + aOrbiterA) + RotL64(aCarry, 13U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 26U));
            aCarry = aCarry + RotL64(aWandererB, 3U);
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

void Soccer_Arx::Twist_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterK = 0;

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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2068U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneC[((aIndex + 6485U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 8100U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 370U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aIngress, 23U)) ^ (RotL64(aPrevious, 50U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = ((aWandererK + RotL64(aIngress, 29U)) + RotL64(aCarry, 39U)) + 3339283916456813609U;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 47U)) + 11339086426180649584U;
            aOrbiterE = (aWandererC + RotL64(aScatter, 38U)) + 16819191669329316585U;
            aOrbiterF = (((aWandererD + RotL64(aCross, 21U)) + RotL64(aCarry, 3U)) + 8361916937762630725U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = (((aWandererB + RotL64(aScatter, 57U)) + RotL64(aCarry, 19U)) + 18031328374429899857U) + aPhaseFOrbiterAssignSaltB[((aIndex + 20U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 18261756894092897276U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 4250319792907645666U;
            aOrbiterE = RotL64((aOrbiterE * 7053489184750217963U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 1492411503643460886U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 17369549067879344180U;
            aOrbiterC = RotL64((aOrbiterC * 2947354306696216579U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 7301713524358676722U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 2985193736033012535U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7473297294949338265U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 14086975808140927408U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 10390516547834639800U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11441293212275890819U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 18205555540941493267U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 16967799565443938873U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3009081009044782443U), 3U);
            //
            aIngress = RotL64(aOrbiterB, 41U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterC, 53U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 54U) + aOrbiterE) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 43U) + aOrbiterC) + RotL64(aOrbiterE, 13U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterE, 52U)) + aOrbiterF) + RotL64(aCarry, 53U)) + aPhaseFWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterF, 21U)) + aOrbiterG);
            aWandererD = aWandererD + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterC, 37U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererK, 11U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 14037U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneD[((aIndex + 12234U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12194U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((aIndex + 12297U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 4U) + RotL64(aCross, 51U)) + (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = ((aWandererI + RotL64(aCross, 27U)) + RotL64(aCarry, 51U)) + 17264605017518259932U;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 37U)) + 15209184354580778643U;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 46U)) + RotL64(aCarry, 37U)) + 3299527965014731384U;
            aOrbiterD = (((aWandererK + RotL64(aScatter, 57U)) + RotL64(aCarry, 23U)) + 16293096431816127821U) + aPhaseFOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 19U)) + 11031983436878828337U) + aPhaseFOrbiterAssignSaltD[((aIndex + 28U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 9188018632448236358U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 13420816400363406556U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10958221259662190519U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 2485063384097917101U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 3089135816938128264U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8813152992957361153U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 10730544971770435788U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 10431767565618874806U;
            aOrbiterB = RotL64((aOrbiterB * 4723078464590561545U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 14883796491656899074U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 13465877783538483706U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14311686051108108503U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 13322163435314643713U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 3307316600284371955U;
            aOrbiterD = RotL64((aOrbiterD * 12337846092069506365U), 11U);
            //
            aIngress = RotL64(aOrbiterI, 60U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterG, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterD, 42U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterB, 51U)) + aOrbiterC) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterI, 27U)) + aOrbiterB);
            aWandererD = aWandererD + ((((RotL64(aIngress, 12U) + RotL64(aOrbiterG, 13U)) + aOrbiterC) + RotL64(aCarry, 19U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterG, 5U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 40U));
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 29U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 22211U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21302U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18538U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((aIndex + 18847U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 37U) ^ RotL64(aCarry, 11U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCross, 24U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 23U)) + RotL64(aCarry, 51U)) + 11274974230580265396U;
            aOrbiterK = ((aWandererA + RotL64(aIngress, 37U)) + 16658438747342741547U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aScatter, 3U)) + RotL64(aCarry, 3U)) + 16612986966106053844U;
            aOrbiterC = (((aWandererK + RotL64(aCross, 11U)) + RotL64(aCarry, 19U)) + 9329502236843231290U) + aPhaseFOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aPrevious, 56U)) + 14088261356708344656U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 13692608802007789581U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 6824473946645682398U;
            aOrbiterB = RotL64((aOrbiterB * 13619437545775237601U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 2072915876348570040U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 7420507753044460759U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13239288539564571257U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 4677557318688502593U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 15081678577055628459U;
            aOrbiterI = RotL64((aOrbiterI * 16659305295251177155U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 7026792817486507482U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 14871665922943969918U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 694073180313083145U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 6807734532159292872U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 17882797335141303280U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15439872930381050291U), 11U);
            //
            aIngress = RotL64(aOrbiterC, 52U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 23U) + RotL64(aOrbiterI, 57U)) + aOrbiterK) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 58U) + aOrbiterC) + RotL64(aOrbiterB, 26U)) + aPhaseFWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 43U) + RotL64(aOrbiterB, 3U)) + aOrbiterK) + RotL64(aCarry, 23U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterC, 43U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 11U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + RotL64(aWandererE, 58U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 27649U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneB[((aIndex + 29937U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27019U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 31092U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 47U) ^ RotL64(aIngress, 11U)) + (RotL64(aPrevious, 23U) + RotL64(aCarry, 60U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = (((aWandererB + RotL64(aScatter, 47U)) + RotL64(aCarry, 41U)) + 12775735908960052604U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aCross, 58U)) + RotL64(aCarry, 53U)) + 11791373812080296887U;
            aOrbiterF = (aWandererA + RotL64(aIngress, 11U)) + 5537362877706057303U;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 29U)) + RotL64(aCarry, 23U)) + 2023912048504189380U;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 19U)) + 17668828109963766893U) + aPhaseFOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 558908629933941224U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 1479633119685446888U;
            aOrbiterF = RotL64((aOrbiterF * 4447153373540811385U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 15460320397843364063U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 10059749397555469054U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8671817118586065469U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 9987633811929693924U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 10087337844580228269U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13817142288940843815U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 4446204415503364254U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 15106063243302192717U;
            aOrbiterH = RotL64((aOrbiterH * 13273756657334709803U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 9430197906134676162U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 1226048679997253363U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14247538885252664127U), 39U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 41U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 21U) + aOrbiterE) + RotL64(aOrbiterA, 43U)) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 60U) + aOrbiterE) + RotL64(aOrbiterF, 57U));
            aWandererD = aWandererD + ((RotL64(aCross, 51U) + aOrbiterF) + RotL64(aOrbiterH, 4U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 27U)) + aOrbiterF) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 11U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 27U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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

void Soccer_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterI = 0;
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 2465U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 4972U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 2591U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneD[((aIndex + 1223U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 41U)) ^ (RotL64(aCross, 5U) + RotL64(aPrevious, 26U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = ((aWandererD + RotL64(aIngress, 51U)) + RotL64(aCarry, 27U)) + 17264605017518259932U;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 14U)) + RotL64(aCarry, 5U)) + 15209184354580778643U;
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 41U)) + 3299527965014731384U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = (((aWandererF + RotL64(aPrevious, 29U)) + RotL64(aCarry, 53U)) + 16293096431816127821U) + aPhaseGOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aCross, 3U)) + 11031983436878828337U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 9188018632448236358U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 13420816400363406556U;
            aOrbiterJ = RotL64((aOrbiterJ * 10958221259662190519U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 2485063384097917101U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 3089135816938128264U;
            aOrbiterI = RotL64((aOrbiterI * 8813152992957361153U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 10730544971770435788U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 10431767565618874806U;
            aOrbiterD = RotL64((aOrbiterD * 4723078464590561545U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 14883796491656899074U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 13465877783538483706U;
            aOrbiterC = RotL64((aOrbiterC * 14311686051108108503U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 13322163435314643713U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 3307316600284371955U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12337846092069506365U), 3U);
            //
            aIngress = RotL64(aOrbiterJ, 57U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + RotL64(aOrbiterD, 46U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterI, 57U)) + aOrbiterJ);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterD, 19U)) + aOrbiterI) + RotL64(aCarry, 5U)) + aPhaseGWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterC, 4U)) + aOrbiterA);
            aWandererH = aWandererH + (((RotL64(aCross, 10U) + RotL64(aOrbiterI, 27U)) + aOrbiterA) + RotL64(aCarry, 21U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterI, 37U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 56U));
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 3U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15334U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneC[((aIndex + 14197U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 14838U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 8513U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aIngress, 54U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = ((aWandererF + RotL64(aCross, 23U)) + RotL64(aCarry, 53U)) + 10336802574069791273U;
            aOrbiterB = (((aWandererA + RotL64(aPrevious, 5U)) + RotL64(aCarry, 19U)) + 169025388197058936U) + aPhaseGOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = (aWandererH + RotL64(aIngress, 53U)) + 6541354188379168846U;
            aOrbiterG = ((aWandererE + RotL64(aScatter, 14U)) + RotL64(aCarry, 35U)) + 16223920526599306104U;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 43U)) + 12756613707692514808U) + aPhaseGOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 5082475548176484035U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 4907435526952698526U;
            aOrbiterE = RotL64((aOrbiterE * 1379692095754989215U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 14236627073831834337U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 11502511046130497584U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3460330807286625917U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 3679044835550219497U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 11254838916686736746U;
            aOrbiterD = RotL64((aOrbiterD * 8631695922983532915U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 10582608424233200966U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 10449735026385340313U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7363770199734997411U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 4628253464169957835U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 17664454668473204465U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4234720298731378527U), 3U);
            //
            aIngress = RotL64(aOrbiterG, 53U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + RotL64(aOrbiterB, 36U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterK, 30U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 24U) + RotL64(aOrbiterG, 21U)) + aOrbiterD) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 3U)) + aOrbiterG) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterB, 43U)) + aOrbiterG) + aPhaseGWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 43U) + RotL64(aOrbiterK, 51U)) + aOrbiterD) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + RotL64(aWandererE, 43U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 22361U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneD[((aIndex + 16458U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22068U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 21404U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aPrevious, 38U)) ^ (RotL64(aCarry, 51U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 29U)) + 5697928251815176134U) + aPhaseGOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aIngress, 20U)) + RotL64(aCarry, 5U)) + 337587740689259575U;
            aOrbiterE = (aWandererG + RotL64(aScatter, 51U)) + 4927686903263973950U;
            aOrbiterI = (((aWandererF + RotL64(aCross, 5U)) + RotL64(aCarry, 27U)) + 3742409032569801033U) + aPhaseGOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 43U)) + RotL64(aCarry, 43U)) + 1608092659172197650U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 15848744267145717509U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 15300174177963339253U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5771922862677667319U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 14162868453323648628U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 12020167069983729869U;
            aOrbiterA = RotL64((aOrbiterA * 2071080217680099017U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 16259538291658723956U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 8516686212464112245U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4731296903548893627U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 3722184575520553132U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 5663609293306386784U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14364218128780764749U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 15265344442454471986U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 3050323350098829515U;
            aOrbiterG = RotL64((aOrbiterG * 5890624677162388135U), 29U);
            //
            aIngress = RotL64(aOrbiterA, 57U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 11U) + aOrbiterI) + RotL64(aOrbiterG, 57U));
            aWandererD = aWandererD + (((RotL64(aCross, 56U) + RotL64(aOrbiterC, 12U)) + aOrbiterA) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterG, 43U)) + aOrbiterE);
            aWandererG = aWandererG + ((((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 39U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterI, 29U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 60U));
            aCarry = aCarry + RotL64(aWandererG, 39U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 24914U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28808U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29724U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((aIndex + 27580U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCross, 5U)) ^ (RotL64(aPrevious, 54U) ^ RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 51U)) + RotL64(aCarry, 21U)) + 12775735908960052604U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 13U)) + 11791373812080296887U;
            aOrbiterF = (((aWandererF + RotL64(aIngress, 3U)) + RotL64(aCarry, 3U)) + 5537362877706057303U) + aPhaseGOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (((aWandererI + RotL64(aScatter, 21U)) + RotL64(aCarry, 35U)) + 2023912048504189380U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = (aWandererK + RotL64(aCross, 42U)) + 17668828109963766893U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 558908629933941224U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 1479633119685446888U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4447153373540811385U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 15460320397843364063U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 10059749397555469054U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8671817118586065469U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 9987633811929693924U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 10087337844580228269U;
            aOrbiterE = RotL64((aOrbiterE * 13817142288940843815U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 4446204415503364254U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 15106063243302192717U;
            aOrbiterJ = RotL64((aOrbiterJ * 13273756657334709803U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 9430197906134676162U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 1226048679997253363U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14247538885252664127U), 13U);
            //
            aIngress = RotL64(aOrbiterJ, 3U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 53U)) + aOrbiterA);
            aWandererI = aWandererI + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterA, 36U)) + aOrbiterK) + RotL64(aCarry, 11U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 27U)) + aOrbiterF) + aPhaseGWandererUpdateSaltD[((aIndex + 20U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 34U) + aOrbiterE) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterF, 19U)) + aOrbiterJ) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + RotL64(aWandererF, 50U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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

void Soccer_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 7933U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5000U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4432U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 512U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCarry, 23U)) ^ (RotL64(aIngress, 44U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 29U)) + RotL64(aCarry, 3U)) + 17264605017518259932U;
            aOrbiterJ = (((aWandererB + RotL64(aPrevious, 5U)) + RotL64(aCarry, 51U)) + 15209184354580778643U) + aPhaseHOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = ((aWandererD + RotL64(aScatter, 58U)) + RotL64(aCarry, 21U)) + 3299527965014731384U;
            aOrbiterB = (aWandererG + RotL64(aCross, 47U)) + 16293096431816127821U;
            aOrbiterK = ((aWandererC + RotL64(aIngress, 19U)) + 11031983436878828337U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 9188018632448236358U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 13420816400363406556U;
            aOrbiterA = RotL64((aOrbiterA * 10958221259662190519U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 2485063384097917101U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 3089135816938128264U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8813152992957361153U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 10730544971770435788U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 10431767565618874806U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4723078464590561545U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 14883796491656899074U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 13465877783538483706U;
            aOrbiterJ = RotL64((aOrbiterJ * 14311686051108108503U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 13322163435314643713U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 3307316600284371955U;
            aOrbiterK = RotL64((aOrbiterK * 12337846092069506365U), 11U);
            //
            aIngress = RotL64(aOrbiterA, 47U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 12U));
            aIngress = aIngress + RotL64(aOrbiterF, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 3U)) + aOrbiterF) + aPhaseHWandererUpdateSaltA[((aIndex + 24U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 23U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 58U) + RotL64(aOrbiterF, 11U)) + aOrbiterK);
            aWandererC = aWandererC + (((RotL64(aScatter, 5U) + aOrbiterF) + RotL64(aOrbiterA, 19U)) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterA, 50U)) + aOrbiterK) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + RotL64(aWandererG, 47U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 11531U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12888U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9584U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((aIndex + 15467U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 60U)) + (RotL64(aIngress, 47U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (((aWandererD + RotL64(aPrevious, 40U)) + RotL64(aCarry, 43U)) + 3339283916456813609U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = (aWandererI + RotL64(aIngress, 5U)) + 11339086426180649584U;
            aOrbiterF = (((aWandererF + RotL64(aCross, 21U)) + RotL64(aCarry, 27U)) + 16819191669329316585U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aScatter, 53U)) + RotL64(aCarry, 5U)) + 8361916937762630725U;
            aOrbiterI = (aWandererC + RotL64(aCross, 13U)) + 18031328374429899857U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 18261756894092897276U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 4250319792907645666U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7053489184750217963U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 1492411503643460886U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 17369549067879344180U;
            aOrbiterI = RotL64((aOrbiterI * 2947354306696216579U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 7301713524358676722U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 2985193736033012535U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7473297294949338265U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 14086975808140927408U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 10390516547834639800U;
            aOrbiterK = RotL64((aOrbiterK * 11441293212275890819U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 18205555540941493267U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 16967799565443938873U;
            aOrbiterD = RotL64((aOrbiterD * 3009081009044782443U), 13U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterC, 3U);
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterD, 26U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 19U)) + aOrbiterF) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 51U) + aOrbiterF) + RotL64(aOrbiterI, 58U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 27U)) + aOrbiterF) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 14U) + aOrbiterK) + RotL64(aOrbiterD, 47U));
            aWandererI = aWandererI + (((RotL64(aScatter, 41U) + aOrbiterD) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + RotL64(aWandererD, 52U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 17704U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20578U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17191U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19008U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCross, 5U)) ^ (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 22U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = (((aWandererE + RotL64(aPrevious, 19U)) + RotL64(aCarry, 23U)) + 12775735908960052604U) + aPhaseHOrbiterAssignSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = (aWandererC + RotL64(aCross, 56U)) + 11791373812080296887U;
            aOrbiterJ = (((aWandererF + RotL64(aIngress, 39U)) + RotL64(aCarry, 57U)) + 5537362877706057303U) + aPhaseHOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = (aWandererK + RotL64(aScatter, 47U)) + 2023912048504189380U;
            aOrbiterE = ((aWandererA + RotL64(aCross, 5U)) + RotL64(aCarry, 39U)) + 17668828109963766893U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 558908629933941224U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 1479633119685446888U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4447153373540811385U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 15460320397843364063U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 10059749397555469054U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8671817118586065469U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 9987633811929693924U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 10087337844580228269U;
            aOrbiterK = RotL64((aOrbiterK * 13817142288940843815U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 4446204415503364254U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 15106063243302192717U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13273756657334709803U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9430197906134676162U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 1226048679997253363U;
            aOrbiterE = RotL64((aOrbiterE * 14247538885252664127U), 37U);
            //
            aIngress = RotL64(aOrbiterA, 58U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aScatter, 4U) + aOrbiterB) + RotL64(aOrbiterJ, 3U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterJ, 14U)) + aOrbiterE);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterB, 23U)) + RotL64(aCarry, 23U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterA, 41U)) + aPhaseHWandererUpdateSaltF[((aIndex + 16U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 21U) + RotL64(aOrbiterE, 57U)) + aOrbiterB) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 37U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 29959U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24989U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27623U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 27052U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aIngress, 10U)) ^ (RotL64(aPrevious, 27U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = ((aWandererJ + RotL64(aCross, 23U)) + RotL64(aCarry, 51U)) + 10336802574069791273U;
            aOrbiterF = (((aWandererF + RotL64(aScatter, 5U)) + RotL64(aCarry, 39U)) + 169025388197058936U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 51U)) + 6541354188379168846U) + aPhaseHOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aIngress, 43U)) + 16223920526599306104U;
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 60U)) + RotL64(aCarry, 19U)) + 12756613707692514808U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 5082475548176484035U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 4907435526952698526U;
            aOrbiterH = RotL64((aOrbiterH * 1379692095754989215U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 14236627073831834337U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 11502511046130497584U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3460330807286625917U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 3679044835550219497U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 11254838916686736746U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8631695922983532915U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 10582608424233200966U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 10449735026385340313U;
            aOrbiterF = RotL64((aOrbiterF * 7363770199734997411U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 4628253464169957835U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 17664454668473204465U;
            aOrbiterD = RotL64((aOrbiterD * 4234720298731378527U), 53U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterD, 54U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + RotL64(aOrbiterH, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aPrevious, 3U) + aOrbiterB) + RotL64(aOrbiterD, 53U)) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterD, 23U)) + aOrbiterG) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aIngress, 50U) + RotL64(aOrbiterB, 35U)) + aOrbiterF) + RotL64(aCarry, 29U)) + aPhaseHWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 11U) + aOrbiterG) + RotL64(aOrbiterB, 43U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 27U) + aOrbiterG) + RotL64(aOrbiterH, 10U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 44U);
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
