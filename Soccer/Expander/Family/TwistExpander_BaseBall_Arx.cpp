#include "TwistExpander_BaseBall_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_BaseBall_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xCE9C62F5C641BBA3ULL + 0x925AED54A7A6328CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xA62E1FC792E73D87ULL + 0xFDA782A63B494D83ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xD6E73596747CAD9DULL + 0xAED53F453C2B3481ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xD2FA07958BF04DCDULL + 0xCBAB586843017C7BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x889E753261510E77ULL + 0xC167183991290CC3ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x9A60E5A2A65872C9ULL + 0xB26EB60989D2F8AFULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xA8D50530B5D309D9ULL + 0xA3A9C89EB6D20F48ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xB2CCBEE0AB455625ULL + 0x9975A8975D68EC15ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 47U) ^ RotL64(aNonceWordE, 3U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 3184U)) & S_BLOCK1], 37U) ^ RotL64(mSnow[((aIndex + 1300U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 19U) ^ RotL64(aNonceWordD, 30U));
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 648U)) & S_BLOCK1], 3U) ^ RotL64(mSnow[((S_BLOCK1 - aIndex + 891U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aPrevious, 27U)) ^ (RotL64(aCross, 13U) ^ RotL64(aIngress, 60U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererA + RotL64(aCross, 21U)) + 3339283916456813609U;
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 19U)) + 11339086426180649584U) + RotL64(aNonceWordA, 5U);
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 3U)) + 16819191669329316585U) + aOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aScatter, 38U)) + 8361916937762630725U;
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 23U)) + RotL64(aCarry, 27U)) + 18031328374429899857U;
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 11U)) + 18261756894092897276U) + aOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (aWandererG + RotL64(aCross, 53U)) + 4250319792907645666U;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 51U)) + 1492411503643460886U) + RotL64(aNonceWordG, 15U);
            aOrbiterF = (aWandererK + RotL64(aIngress, 29U)) + 17369549067879344180U;
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 41U)) + RotL64(aCarry, 21U)) + 7301713524358676722U;
            aOrbiterE = ((aWandererI + RotL64(aScatter, 56U)) + RotL64(aCarry, 37U)) + 2985193736033012535U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 14086975808140927408U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 10390516547834639800U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11441293212275890819U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 18205555540941493267U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 16967799565443938873U;
            aOrbiterA = RotL64((aOrbiterA * 3009081009044782443U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 9209505304067579944U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 3522631966146762306U;
            aOrbiterK = RotL64((aOrbiterK * 3441982898533162599U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 8811497120829041188U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 14707301680850257294U;
            aOrbiterG = RotL64((aOrbiterG * 11383709499376464085U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 10080595991787801029U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 6822892187784299166U) ^ aOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7417016898027778287U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 1981637172055758689U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 16463077485583119324U) ^ RotL64(aNonceWordC, 46U);
            aOrbiterF = RotL64((aOrbiterF * 2876782050665869121U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 8383837717361569465U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 2788511294985017326U;
            aOrbiterE = RotL64((aOrbiterE * 2809163242875130677U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 3529607472855930041U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 8850940802020173766U;
            aOrbiterJ = RotL64((aOrbiterJ * 7821450253655655943U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 7469160295100147267U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 16973986572163482061U;
            aOrbiterD = RotL64((aOrbiterD * 15660743778376905023U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 12371372942863279718U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 12098525148034303633U;
            aOrbiterH = RotL64((aOrbiterH * 11234127652230231751U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 5138683482859889480U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 3339283916456813609U) ^ RotL64(aNonceWordB, 55U);
            aOrbiterB = RotL64((aOrbiterB * 10975353228235695455U), 41U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 37U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 41U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 18U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + RotL64(aOrbiterD, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 43U)) + aOrbiterI);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterB, 11U)) + aOrbiterK) + RotL64(aNonceWordD, 51U));
            aWandererI = aWandererI + (((RotL64(aCross, 11U) + RotL64(aOrbiterE, 29U)) + aOrbiterH) + aWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 56U) + RotL64(aOrbiterC, 3U)) + aOrbiterB);
            aWandererK = aWandererK + ((RotL64(aCross, 53U) + RotL64(aOrbiterF, 35U)) + aOrbiterD);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterD, 18U));
            aWandererH = aWandererH + ((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterJ, 13U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 30U) + RotL64(aOrbiterA, 37U)) + aOrbiterK);
            aWandererA = aWandererA + ((((RotL64(aCross, 13U) + aOrbiterA) + RotL64(aOrbiterB, 51U)) + RotL64(aCarry, 13U)) + aWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterG, 54U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 37U) + RotL64(aOrbiterJ, 27U)) + aOrbiterF) + RotL64(aCarry, 35U)) + RotL64(aNonceWordF, 31U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 46U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (RotL64(aWandererB, 56U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 13U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 57U) ^ RotL64(aNonceWordF, 35U)) ^ RotL64(aNonceWordH, 3U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 8700U)) & S_BLOCK1], 11U) ^ RotL64(mSnow[((aIndex + 6385U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 35U) ^ RotL64(aNonceWordA, 26U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10465U)) & S_BLOCK1], 53U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 8317U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 14U) + RotL64(aPrevious, 27U)) ^ (RotL64(aCarry, 53U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (((aWandererG + RotL64(aScatter, 37U)) + 2225397913940961213U) + aOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1]) + RotL64(aNonceWordE, 39U);
            aOrbiterC = (aWandererF + RotL64(aIngress, 19U)) + 8342544893601343643U;
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 35U)) + 162922186381417187U;
            aOrbiterF = (((aWandererD + RotL64(aCross, 44U)) + RotL64(aCarry, 51U)) + 11660218373710972210U) + RotL64(aNonceWordC, 53U);
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 53U)) + RotL64(aCarry, 13U)) + 14909034764605802354U;
            aOrbiterI = (aWandererI + RotL64(aPrevious, 3U)) + 16776955237009701511U;
            aOrbiterB = (((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 29U)) + 5834487809188925253U) + aOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aCross, 41U)) + 1498492772767040320U;
            aOrbiterE = (aWandererK + RotL64(aPrevious, 39U)) + 4161765458781579617U;
            aOrbiterG = (aWandererC + RotL64(aScatter, 50U)) + 10511923076962447765U;
            aOrbiterA = (aWandererB + RotL64(aIngress, 21U)) + 8575954471692620021U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 6536325446331340573U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 1790628986900286346U;
            aOrbiterH = RotL64((aOrbiterH * 5262997114200816715U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 2623814807619278590U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 11676970995834706612U;
            aOrbiterC = RotL64((aOrbiterC * 10057461115132434901U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 13836786354224256591U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 6293096163612129260U;
            aOrbiterJ = RotL64((aOrbiterJ * 8977954126326217153U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 4271144764978661248U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 15938494256992560202U;
            aOrbiterB = RotL64((aOrbiterB * 10004841288382726739U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 11038155227307702976U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 12408749795071243930U;
            aOrbiterE = RotL64((aOrbiterE * 5527720475032868855U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 1673665849053496882U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 12866353361497103629U;
            aOrbiterD = RotL64((aOrbiterD * 6041125499398924871U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 10673935802381580966U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 8946776538955520352U;
            aOrbiterF = RotL64((aOrbiterF * 12293084177712710021U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 16294935203370452805U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 4697759331563852212U) ^ RotL64(aNonceWordA, 11U);
            aOrbiterI = RotL64((aOrbiterI * 14407806317275373043U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 17633118874112283386U) + aOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 89602424202721105U;
            aOrbiterK = RotL64((aOrbiterK * 1010654844008668685U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 4019154066191316616U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 15029609435149173243U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3522168783248806167U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 11765990698273078458U) + RotL64(aNonceWordB, 59U);
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 2225397913940961213U) ^ aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8471538922288466221U), 39U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterJ, 11U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (RotL64(aOrbiterB, 26U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aCross, 44U) + aOrbiterE) + RotL64(aOrbiterB, 54U)) + RotL64(aNonceWordD, 60U));
            aWandererA = aWandererA + ((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 35U)) + aOrbiterD);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 41U) + aOrbiterH) + RotL64(aOrbiterI, 47U));
            aWandererG = aWandererG + ((RotL64(aIngress, 23U) + RotL64(aOrbiterE, 39U)) + aOrbiterH);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterE, 19U)) + aOrbiterD) + RotL64(aNonceWordG, 51U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterG, 5U)) + aOrbiterC) + RotL64(aCarry, 19U)) + aWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterJ, 57U)) + aOrbiterA);
            aWandererK = aWandererK + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterJ, 13U)) + aOrbiterF);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 53U) + aOrbiterK) + RotL64(aOrbiterJ, 51U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 14U) + RotL64(aOrbiterJ, 28U)) + aOrbiterG) + RotL64(aCarry, 41U)) + aWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 21U) + aOrbiterH) + RotL64(aOrbiterK, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 14U));
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererJ, 22U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 5U) ^ RotL64(aNonceWordE, 57U)) ^ RotL64(aNonceWordA, 43U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 15533U)) & S_BLOCK1], 13U) ^ RotL64(mSnow[((S_BLOCK1 - aIndex + 15147U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 43U) ^ RotL64(aNonceWordG, 57U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12787U)) & S_BLOCK1], 26U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 12946U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aPrevious, 3U)) ^ (RotL64(aCross, 19U) ^ RotL64(aIngress, 54U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 53U)) + 380024772508948442U) + aOrbiterAssignSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = (aWandererD + RotL64(aScatter, 50U)) + 7649029098162567210U;
            aOrbiterK = (aWandererI + RotL64(aIngress, 43U)) + 5329304598870421851U;
            aOrbiterF = (aWandererG + RotL64(aCross, 3U)) + 12306118665045151326U;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 57U)) + 960751560457324256U) + RotL64(aNonceWordB, 4U);
            aOrbiterJ = (((aWandererE + RotL64(aPrevious, 21U)) + RotL64(aCarry, 23U)) + 3244070254386191876U) + aOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aCross, 13U)) + 15733408571609521746U) + RotL64(aNonceWordH, 19U);
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 29U)) + RotL64(aCarry, 13U)) + 17623448932647018544U;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 41U)) + RotL64(aCarry, 5U)) + 8787759896149035829U;
            aOrbiterC = (aWandererK + RotL64(aPrevious, 27U)) + 14741681792348288162U;
            aOrbiterD = (aWandererF + RotL64(aCross, 18U)) + 8801731213568307302U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 9872248187499779222U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 15407371518644528235U;
            aOrbiterK = RotL64((aOrbiterK * 1245102406469471673U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 4242060317152943062U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 9942784962409917541U;
            aOrbiterJ = RotL64((aOrbiterJ * 888649755587764533U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 7296348796484458631U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 15061417216070157797U) ^ RotL64(aNonceWordD, 25U);
            aOrbiterA = RotL64((aOrbiterA * 10349554676953256231U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 3233185810644297433U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 9241229457641024287U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2728237515724597517U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 8464051359381554575U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 3307872165699029375U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4859663401033023433U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 5482617843966711997U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 4442149210462943872U;
            aOrbiterC = RotL64((aOrbiterC * 8979352218576515647U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 10591636597580147381U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 14925122230279312217U;
            aOrbiterH = RotL64((aOrbiterH * 15038171961638724013U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 9772367878232735350U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 15800661165607190092U;
            aOrbiterF = RotL64((aOrbiterF * 10493976952980533589U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 1571665862499272194U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 3162847040693387901U;
            aOrbiterE = RotL64((aOrbiterE * 2747235335326991399U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 4868791925868749848U) + RotL64(aNonceWordG, 43U);
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 13134549226315884613U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3551955270718495869U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 7830447320021657240U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 380024772508948442U) ^ aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5143324968958616357U), 29U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 11U);
            aIngress = aIngress + (RotL64(aOrbiterC, 60U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterA, 39U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + RotL64(aOrbiterD, 24U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aCross, 3U) + RotL64(aOrbiterB, 29U)) + aOrbiterG);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 10U)) + aOrbiterG);
            aWandererI = aWandererI + (((RotL64(aIngress, 53U) + aOrbiterD) + RotL64(aOrbiterI, 51U)) + RotL64(aCarry, 37U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterH, 57U)) + aOrbiterK);
            aWandererF = aWandererF + (((RotL64(aCross, 10U) + aOrbiterF) + RotL64(aOrbiterG, 27U)) + aWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterK, 43U));
            aWandererG = aWandererG + ((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterB, 3U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterK, 54U)) + aOrbiterG) + RotL64(aNonceWordC, 9U));
            aWandererB = aWandererB + (((RotL64(aScatter, 26U) + RotL64(aOrbiterF, 47U)) + aOrbiterH) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterC, 21U)) + aOrbiterI) + aWandererUpdateSaltA[((aIndex + 12U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterK, 19U)) + RotL64(aNonceWordF, 17U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 44U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 24U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 39U) ^ RotL64(aNonceWordE, 57U)) ^ RotL64(aNonceWordD, 5U));
            aIngress = aIngress ^ (RotL64(mSnow[((aIndex + 16887U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((aIndex + 17806U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 4U) ^ RotL64(aNonceWordA, 57U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16805U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((aIndex + 20942U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 51U) ^ RotL64(aCarry, 4U)) + (RotL64(aIngress, 39U) ^ RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererI + RotL64(aCross, 19U)) + 6318740973868639425U;
            aOrbiterB = ((aWandererE + RotL64(aScatter, 39U)) + 5487840061430920881U) + aOrbiterAssignSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aIngress, 35U)) + 10258706763248072672U;
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 56U)) + 18356875269730338208U;
            aOrbiterA = ((aWandererG + RotL64(aCross, 21U)) + RotL64(aCarry, 57U)) + 12883160282903147010U;
            aOrbiterI = ((((aWandererA + RotL64(aPrevious, 13U)) + RotL64(aCarry, 53U)) + 1010140474942697730U) + aOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1]) + RotL64(aNonceWordB, 49U);
            aOrbiterH = (aWandererH + RotL64(aIngress, 23U)) + 17733939421700898293U;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 4U)) + 13693055887924981201U) + RotL64(aNonceWordC, 19U);
            aOrbiterD = (aWandererD + RotL64(aPrevious, 41U)) + 14574732452793385269U;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 51U)) + RotL64(aCarry, 13U)) + 10832873941223609012U;
            aOrbiterK = (aWandererB + RotL64(aScatter, 29U)) + 8212600587135328040U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 5312744319781971178U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 6173741211706546923U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12854414066390848249U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 3693249147883790810U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 18365859989736602556U;
            aOrbiterA = RotL64((aOrbiterA * 3348463719324104997U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 10645056678337549771U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 1175668356822251045U;
            aOrbiterI = RotL64((aOrbiterI * 6579675292775345579U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 13556844570541823717U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 4790355739411849736U;
            aOrbiterH = RotL64((aOrbiterH * 4083544011788850307U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 14905575502272644116U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 17047244574558476634U) ^ aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2356386971503880047U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 10161614295718414869U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 13413914082651612468U;
            aOrbiterD = RotL64((aOrbiterD * 16224039093981079491U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 6072693130156927774U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 4333656233793103787U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9374745547133955709U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 17209776289202130250U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 11752001118070361543U;
            aOrbiterK = RotL64((aOrbiterK * 4416523594812872339U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 15367365111105608277U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 8650687767097460704U) ^ RotL64(aNonceWordE, 39U);
            aOrbiterE = RotL64((aOrbiterE * 11430451559660578667U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 18074648514448405693U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 10857586858462237581U) ^ RotL64(aNonceWordF, 40U);
            aOrbiterB = RotL64((aOrbiterB * 3722891011080095849U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 17219932344278345591U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 6318740973868639425U;
            aOrbiterJ = RotL64((aOrbiterJ * 8846295038878812229U), 11U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterD, 54U);
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + RotL64(aOrbiterG, 60U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 43U) + aOrbiterK) + RotL64(aOrbiterC, 39U));
            aWandererC = aWandererC + ((RotL64(aScatter, 13U) + RotL64(aOrbiterI, 28U)) + aOrbiterA);
            aWandererK = aWandererK ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterG, 19U)) + aOrbiterB) + RotL64(aNonceWordH, 57U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 40U) + RotL64(aOrbiterA, 13U)) + aOrbiterB) + aWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 53U)) + aOrbiterJ);
            aWandererG = aWandererG + ((RotL64(aIngress, 37U) + aOrbiterK) + RotL64(aOrbiterF, 23U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterD, 37U)) + aOrbiterF);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 51U) + aOrbiterF) + RotL64(aOrbiterH, 43U)) + RotL64(aCarry, 23U)) + aWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 34U) + aOrbiterJ) + RotL64(aOrbiterI, 3U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 30U)) + aOrbiterB) + RotL64(aCarry, 51U)) + RotL64(aNonceWordG, 15U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 19U) + aOrbiterB) + RotL64(aOrbiterE, 57U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 34U));
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + RotL64(aWandererI, 14U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 11U) ^ RotL64(aNonceWordG, 47U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 26679U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((aIndex + 26389U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 3U) ^ RotL64(aNonceWordC, 53U)) ^ RotL64(aNonceWordA, 36U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27069U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25613U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCross, 56U)) ^ (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererF + RotL64(aIngress, 43U)) + 898812731947995389U;
            aOrbiterB = (((aWandererH + RotL64(aPrevious, 13U)) + 8677347622525527167U) + aOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1]) + RotL64(aNonceWordA, 21U);
            aOrbiterI = ((aWandererG + RotL64(aCross, 39U)) + 770321564027567654U) + aOrbiterAssignSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = ((aWandererC + RotL64(aScatter, 20U)) + 11020474858081526395U) + RotL64(aNonceWordB, 15U);
            aOrbiterH = ((aWandererA + RotL64(aCross, 57U)) + RotL64(aCarry, 35U)) + 17289793580414993470U;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 37U)) + RotL64(aCarry, 57U)) + 10111912559295118444U;
            aOrbiterG = (aWandererE + RotL64(aScatter, 23U)) + 8083622125544542011U;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 60U)) + RotL64(aCarry, 13U)) + 7149858558922988240U;
            aOrbiterE = (aWandererD + RotL64(aIngress, 41U)) + 5919683821379905699U;
            aOrbiterF = (aWandererK + RotL64(aScatter, 3U)) + 6860902846079238714U;
            aOrbiterC = (aWandererJ + RotL64(aCross, 53U)) + 15083517836867542075U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 14852868368708376381U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 9860233289028878323U;
            aOrbiterI = RotL64((aOrbiterI * 13418143547952204667U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 772406119079116272U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 7971141501337627589U;
            aOrbiterD = RotL64((aOrbiterD * 10168120622976358617U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 8478568022896691911U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 4027604850785607101U;
            aOrbiterK = RotL64((aOrbiterK * 4826627523578901467U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 17199331557841535430U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 7515957656979776361U) ^ RotL64(aNonceWordG, 11U);
            aOrbiterF = RotL64((aOrbiterF * 5468950152869656599U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 17138249294921502391U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 16236812863923234668U) ^ aOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2925542836624164807U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 16941524155859123682U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 11240343728857342866U;
            aOrbiterA = RotL64((aOrbiterA * 7281012444214294659U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 15163914964139858328U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 6673576554415729652U) ^ aOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1558880328574736975U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 5399050402101642989U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 11806006719060024615U;
            aOrbiterE = RotL64((aOrbiterE * 15782156615926092159U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 9812148913932011655U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 4737919734590584193U;
            aOrbiterC = RotL64((aOrbiterC * 2739737604370936959U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 3415477403346468057U) + RotL64(aNonceWordD, 47U);
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 5922725868927615919U;
            aOrbiterB = RotL64((aOrbiterB * 12390148483052777871U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 17435294951520465659U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 898812731947995389U) ^ aOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17248379279729365007U), 41U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 51U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + (RotL64(aOrbiterD, 21U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 42U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aPrevious, 13U) + aOrbiterF) + RotL64(aOrbiterK, 21U)) + RotL64(aNonceWordE, 14U)) + aWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 56U) + RotL64(aOrbiterI, 43U)) + aOrbiterF);
            aWandererB = aWandererB + ((RotL64(aCross, 11U) + RotL64(aOrbiterH, 29U)) + aOrbiterG);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterG, 37U));
            aWandererK = aWandererK + (((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 34U)) + aOrbiterA) + RotL64(aNonceWordH, 45U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 51U) + aOrbiterH) + RotL64(aOrbiterJ, 51U)) + aWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterE, 3U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 53U) + aOrbiterB) + RotL64(aOrbiterA, 39U));
            aWandererG = aWandererG + (((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 41U)) + aOrbiterA) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 60U) + aOrbiterA) + RotL64(aOrbiterI, 26U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterC, 11U)) + aOrbiterI) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 56U));
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererE, 30U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 48U) ^ RotL64(aNonceWordE, 23U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 27902U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30718U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 35U) ^ RotL64(aNonceWordC, 13U)) ^ RotL64(aNonceWordB, 27U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27321U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneC[((aIndex + 29746U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCross, 3U)) ^ (RotL64(aCarry, 20U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererC + RotL64(aScatter, 41U)) + 11998579547770778580U;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 29U)) + RotL64(aCarry, 21U)) + 8409465187298704610U;
            aOrbiterG = (aWandererD + RotL64(aCross, 6U)) + 3470222286110333500U;
            aOrbiterA = (aWandererB + RotL64(aIngress, 53U)) + 5704486785203069994U;
            aOrbiterE = (aWandererA + RotL64(aScatter, 11U)) + 10334944660253279633U;
            aOrbiterD = ((aWandererE + RotL64(aIngress, 37U)) + 7626852700722567477U) + RotL64(aNonceWordH, 7U);
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 21U)) + 14631310754943209743U) + aOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = (((aWandererK + RotL64(aCross, 51U)) + RotL64(aCarry, 3U)) + 807160297237854120U) + RotL64(aNonceWordF, 13U);
            aOrbiterK = (aWandererJ + RotL64(aScatter, 13U)) + 5624154783624196107U;
            aOrbiterH = ((aWandererH + RotL64(aCross, 44U)) + 4971444394698940423U) + aOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 57U)) + RotL64(aCarry, 27U)) + 6340057638461027062U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 9003019862787819481U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 13632057463595873033U;
            aOrbiterG = RotL64((aOrbiterG * 12575202147280216765U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 12766104026871797746U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 4062118445824915939U;
            aOrbiterE = RotL64((aOrbiterE * 13130770039048080701U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 5258212525426469978U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 9956946981015983939U;
            aOrbiterD = RotL64((aOrbiterD * 8106382657040497669U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 10837606223056473999U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 13292864885504191134U;
            aOrbiterB = RotL64((aOrbiterB * 4445739587553669471U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 166087925900318658U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 6786842221885441388U;
            aOrbiterC = RotL64((aOrbiterC * 4411147600413147773U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 16888086378070246404U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 5240855484445974002U;
            aOrbiterK = RotL64((aOrbiterK * 402652898573422271U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 6874866669211571608U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 732890824978127460U) ^ aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3776365957702257453U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 5541380495707308058U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 17947326584411475765U;
            aOrbiterJ = RotL64((aOrbiterJ * 10920952349981652899U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 15060679340045767910U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 1675974028461383576U;
            aOrbiterI = RotL64((aOrbiterI * 15127962310365242819U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 226889112033170368U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 4290719734244011388U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6453598182035414143U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 7712233480730639084U) + RotL64(aNonceWordG, 11U);
            aOrbiterA = (((aOrbiterA ^ aOrbiterJ) ^ 11998579547770778580U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]) ^ RotL64(aNonceWordA, 38U);
            aOrbiterA = RotL64((aOrbiterA * 11599893373156816375U), 23U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 30U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 37U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + RotL64(aOrbiterA, 56U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 14U)) + aOrbiterG) + RotL64(aNonceWordB, 23U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 56U) + RotL64(aOrbiterG, 27U)) + aOrbiterJ);
            aWandererD = aWandererD + ((RotL64(aScatter, 39U) + aOrbiterG) + RotL64(aOrbiterC, 47U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 41U) + aOrbiterH) + RotL64(aOrbiterK, 51U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 37U) + RotL64(aOrbiterK, 39U)) + aOrbiterI) + RotL64(aCarry, 19U)) + aWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterA, 5U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterE, 60U)) + aOrbiterJ) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterK, 37U)) + aOrbiterF) + aWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 35U) + RotL64(aOrbiterK, 41U)) + aOrbiterB) + RotL64(aNonceWordD, 39U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterC, 23U));
            aWandererA = aWandererA + ((RotL64(aScatter, 24U) + aOrbiterD) + RotL64(aOrbiterF, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 56U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererG, 18U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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

void TwistExpander_BaseBall_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xF3A1BF65A4151DE3ULL + 0xC58C3CCD867F00B3ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x8099E6E46D4AE197ULL + 0xBECE8BE46FABB46CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xD241E10718CF1D13ULL + 0x8E31E99921996155ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xEE206D646360F4F3ULL + 0xB2818888255B9A96ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xB1BA085D3F1A7BD5ULL + 0xFF4AEBF065FB51ADULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xBF8D20D190694F0DULL + 0xCA47475F31F31A93ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xD52C0866DACEDEF5ULL + 0xB320EC6D3FB0AE16ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xF2036A0E07D6FBD3ULL + 0xF335BCD396A7B595ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 57U) ^ RotL64(aNonceWordE, 35U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 3476U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneC[((aIndex + 7903U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 3U) ^ RotL64(aNonceWordF, 54U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2401U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 5534U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aIngress, 48U)) ^ (RotL64(aPrevious, 3U) + RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererH + RotL64(aPrevious, 53U)) + 2225397913940961213U;
            aOrbiterF = ((aWandererI + RotL64(aCross, 57U)) + 8342544893601343643U) + RotL64(aNonceWordA, 51U);
            aOrbiterH = ((aWandererA + RotL64(aIngress, 41U)) + 162922186381417187U) + aOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 13U)) + 11660218373710972210U) + aOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = (aWandererG + RotL64(aPrevious, 4U)) + 14909034764605802354U;
            aOrbiterG = (((aWandererF + RotL64(aScatter, 21U)) + RotL64(aCarry, 37U)) + 16776955237009701511U) + RotL64(aNonceWordB, 19U);
            aOrbiterA = ((aWandererK + RotL64(aCross, 35U)) + RotL64(aCarry, 19U)) + 5834487809188925253U;
            aOrbiterK = ((aWandererC + RotL64(aIngress, 29U)) + RotL64(aCarry, 57U)) + 1498492772767040320U;
            aOrbiterE = (aWandererD + RotL64(aCross, 48U)) + 4161765458781579617U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 10511923076962447765U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 8575954471692620021U;
            aOrbiterH = RotL64((aOrbiterH * 12526744988828982731U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 6536325446331340573U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 1790628986900286346U;
            aOrbiterG = RotL64((aOrbiterG * 5262997114200816715U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 2623814807619278590U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 11676970995834706612U) ^ RotL64(aNonceWordH, 57U);
            aOrbiterK = RotL64((aOrbiterK * 10057461115132434901U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 13836786354224256591U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 6293096163612129260U) ^ RotL64(aNonceWordD, 27U);
            aOrbiterE = RotL64((aOrbiterE * 8977954126326217153U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 4271144764978661248U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 15938494256992560202U) ^ aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10004841288382726739U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 11038155227307702976U) + aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 12408749795071243930U;
            aOrbiterJ = RotL64((aOrbiterJ * 5527720475032868855U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 1673665849053496882U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 12866353361497103629U;
            aOrbiterA = RotL64((aOrbiterA * 6041125499398924871U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 10673935802381580966U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 8946776538955520352U;
            aOrbiterF = RotL64((aOrbiterF * 12293084177712710021U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 16294935203370452805U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 4697759331563852212U) ^ aOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14407806317275373043U), 43U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterK, 40U);
            aIngress = aIngress + (RotL64(aOrbiterC, 51U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterA, 23U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + RotL64(aOrbiterH, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 52U) + RotL64(aOrbiterK, 57U)) + aOrbiterJ) + RotL64(aNonceWordF, 8U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterJ, 6U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 11U) + aOrbiterH) + RotL64(aOrbiterC, 53U)) + RotL64(aNonceWordC, 39U)) + aWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 39U) + aOrbiterE) + RotL64(aOrbiterH, 47U));
            aWandererH = aWandererH + (((RotL64(aCross, 5U) + RotL64(aOrbiterK, 39U)) + aOrbiterI) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 30U) + RotL64(aOrbiterG, 27U)) + aOrbiterH);
            aWandererD = aWandererD + ((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 34U)) + aOrbiterK);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterI, 19U)) + aOrbiterF) + aWandererUpdateSaltB[((aIndex + 16U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 47U) + aOrbiterH) + RotL64(aOrbiterI, 43U)) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 60U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + RotL64(aWandererD, 5U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 12U) ^ RotL64(aNonceWordG, 3U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 9302U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9716U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 23U) ^ RotL64(aNonceWordD, 13U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15884U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10571U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aIngress, 27U)) + (RotL64(aPrevious, 13U) ^ RotL64(aCarry, 60U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererF + RotL64(aIngress, 19U)) + 12222235191147985484U;
            aOrbiterA = (aWandererJ + RotL64(aCross, 13U)) + 16367317014523328414U;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 3U)) + 3511378091284703789U) + RotL64(aNonceWordG, 55U);
            aOrbiterD = ((aWandererE + RotL64(aScatter, 58U)) + 15247492830966725949U) + aOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = ((aWandererD + RotL64(aCross, 47U)) + RotL64(aCarry, 35U)) + 7745995913390407897U;
            aOrbiterC = (aWandererI + RotL64(aScatter, 41U)) + 6463593307540108810U;
            aOrbiterE = (((aWandererK + RotL64(aPrevious, 53U)) + RotL64(aCarry, 43U)) + 1101669311005268630U) + RotL64(aNonceWordF, 23U);
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 23U)) + RotL64(aCarry, 3U)) + 12988052764067518580U;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 30U)) + 17717179747434679772U) + aOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 11662190906682400416U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 6563014073547628748U) ^ aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16967910471722117761U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 13099094932059419219U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 16342730862261868847U;
            aOrbiterK = RotL64((aOrbiterK * 10988124108686164829U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 16855346813127524624U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 6570063128502306944U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4571570049463124831U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 11328352033809240501U) + aOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 11640986648833160901U;
            aOrbiterJ = RotL64((aOrbiterJ * 2895830492089678919U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 2675226158571501666U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 17700531248266458165U;
            aOrbiterF = RotL64((aOrbiterF * 2231403813970188657U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 7729597396731910874U) + aOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 15172374484412053756U;
            aOrbiterG = RotL64((aOrbiterG * 149009041406406517U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 9178769489257842683U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 9020154972097834926U;
            aOrbiterD = RotL64((aOrbiterD * 8910504667566521429U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 1317403761217790562U) + RotL64(aNonceWordE, 56U);
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 17151528554929201571U) ^ RotL64(aNonceWordD, 45U);
            aOrbiterC = RotL64((aOrbiterC * 3735945655450625203U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 11621882033959669977U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 10289504450815075623U;
            aOrbiterA = RotL64((aOrbiterA * 13365982786836243195U), 21U);
            //
            aIngress = RotL64(aOrbiterA, 46U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterB, 60U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterG, 43U)) + aOrbiterE);
            aWandererF = aWandererF + ((((RotL64(aCross, 58U) + RotL64(aOrbiterF, 47U)) + aOrbiterC) + RotL64(aCarry, 29U)) + aWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 35U) + aOrbiterD) + RotL64(aOrbiterJ, 5U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 37U)) + aOrbiterF);
            aWandererE = aWandererE ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterG, 12U)) + aOrbiterA);
            aWandererH = aWandererH + ((((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 21U)) + RotL64(aNonceWordC, 41U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterD, 57U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 39U) + RotL64(aOrbiterE, 51U)) + aOrbiterC);
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 52U) + RotL64(aOrbiterC, 30U)) + aOrbiterK) + RotL64(aNonceWordH, 5U)) + aWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 14U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + RotL64(aWandererH, 5U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 13U) ^ RotL64(aNonceWordD, 43U)) ^ RotL64(aNonceWordA, 21U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 16659U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneA[((aIndex + 19472U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 35U) ^ RotL64(aNonceWordC, 27U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19379U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneC[((aIndex + 19432U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 42U) ^ RotL64(aPrevious, 57U)) ^ (RotL64(aIngress, 5U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererA + RotL64(aCross, 23U)) + 12311607308490066301U;
            aOrbiterJ = (aWandererD + RotL64(aScatter, 35U)) + 13100864684740679846U;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 3U)) + RotL64(aCarry, 23U)) + 13697304189274329704U;
            aOrbiterG = ((((aWandererI + RotL64(aIngress, 28U)) + RotL64(aCarry, 5U)) + 9047976902871216732U) + aOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1]) + RotL64(aNonceWordF, 37U);
            aOrbiterF = (aWandererE + RotL64(aCross, 51U)) + 2147897579538537888U;
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 11U)) + 2072444829390996142U) + RotL64(aNonceWordE, 34U);
            aOrbiterK = ((aWandererF + RotL64(aIngress, 47U)) + 2129307836981020908U) + aOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aScatter, 56U)) + RotL64(aCarry, 57U)) + 10663145333751112064U;
            aOrbiterB = (aWandererG + RotL64(aPrevious, 39U)) + 15019844390503785459U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 5460865577557928142U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 15806522559993224197U;
            aOrbiterI = RotL64((aOrbiterI * 8722932687972240099U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 6361113778657833389U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 8306013884615042570U) ^ RotL64(aNonceWordG, 57U);
            aOrbiterD = RotL64((aOrbiterD * 8234258702656728667U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 4038420580499706912U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 11908091484457158973U) ^ aOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3964111175645156719U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 11133912466611921250U) + aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 2469227904206936928U;
            aOrbiterJ = RotL64((aOrbiterJ * 2704438771198001599U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 13234017916788297295U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 9061117693840451988U;
            aOrbiterF = RotL64((aOrbiterF * 3637440416741459419U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 12013423690843812324U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 14371779015144617412U;
            aOrbiterE = RotL64((aOrbiterE * 3359568073302062667U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 10044883414565441442U) + RotL64(aNonceWordD, 43U);
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 14334898081890462218U;
            aOrbiterK = RotL64((aOrbiterK * 4878939077928220019U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 13788962593988366125U) + aOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 8377887372059713516U;
            aOrbiterH = RotL64((aOrbiterH * 1925913354197206851U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 4584439257847749371U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 13335592911357756498U;
            aOrbiterB = RotL64((aOrbiterB * 6515028218115896375U), 29U);
            //
            aIngress = RotL64(aOrbiterD, 57U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 41U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + RotL64(aOrbiterG, 48U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterJ, 56U)) + aOrbiterG) + RotL64(aNonceWordB, 23U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 27U) + aOrbiterK) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterD, 27U));
            aWandererI = aWandererI + ((((RotL64(aCross, 60U) + aOrbiterB) + RotL64(aOrbiterE, 35U)) + RotL64(aCarry, 5U)) + aWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 37U) + aOrbiterE) + RotL64(aOrbiterF, 19U));
            aWandererF = aWandererF + (((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterG, 51U)) + aWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 11U) + aOrbiterD) + RotL64(aOrbiterF, 12U));
            aWandererE = aWandererE + (((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 47U)) + aOrbiterH) + RotL64(aNonceWordC, 19U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 54U) + aOrbiterB) + RotL64(aOrbiterI, 39U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 22U));
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 13U) ^ RotL64(aNonceWordA, 41U)) ^ RotL64(aNonceWordC, 57U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 31118U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneB[((aIndex + 28290U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 21U) ^ RotL64(aNonceWordD, 51U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29858U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 32310U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 6U) ^ RotL64(aCarry, 57U)) + (RotL64(aCross, 23U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererI + RotL64(aScatter, 34U)) + 16183871922837164759U;
            aOrbiterF = (((aWandererC + RotL64(aIngress, 57U)) + RotL64(aCarry, 37U)) + 7002058258090219055U) + aOrbiterAssignSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 47U)) + RotL64(aCarry, 27U)) + 5650868611888303705U;
            aOrbiterK = (((aWandererB + RotL64(aCross, 21U)) + RotL64(aCarry, 57U)) + 11899839660943876690U) + RotL64(aNonceWordB, 41U);
            aOrbiterE = (aWandererE + RotL64(aScatter, 38U)) + 15349649504488111111U;
            aOrbiterA = (aWandererH + RotL64(aPrevious, 51U)) + 14060149569086744970U;
            aOrbiterD = ((aWandererJ + RotL64(aCross, 27U)) + 12920917574225030112U) + RotL64(aNonceWordA, 59U);
            aOrbiterB = ((aWandererG + RotL64(aIngress, 11U)) + 2831994965175330135U) + aOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = (aWandererF + RotL64(aScatter, 5U)) + 18312543585028439192U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 11657562205118394239U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 10850792819281246052U;
            aOrbiterI = RotL64((aOrbiterI * 10663100544207879337U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 17810371216216125323U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 7963413941144223128U;
            aOrbiterE = RotL64((aOrbiterE * 534217972450595401U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 5498715358793875584U) + RotL64(aNonceWordF, 5U);
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 9256727548911651373U;
            aOrbiterD = RotL64((aOrbiterD * 10498848323914000989U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 17246360111302191699U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 18309978718113983369U;
            aOrbiterC = RotL64((aOrbiterC * 18267472694666221077U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 3100998994319502921U) + aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 8129301860291235970U;
            aOrbiterK = RotL64((aOrbiterK * 17847033539279176187U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 1889641029473279114U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 16538494307002917945U;
            aOrbiterA = RotL64((aOrbiterA * 8081488217920885783U), 27U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterA) + 5432230549146849322U) + aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1]) + RotL64(aNonceWordG, 10U);
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 2634437941396090817U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7612999214758935211U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 16940172599174185058U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 13151669140593952203U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16225319638131723487U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 3995064294869931681U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 913081077665768816U;
            aOrbiterF = RotL64((aOrbiterF * 9299514648768060453U), 35U);
            //
            aIngress = RotL64(aOrbiterG, 51U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterI, 10U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + RotL64(aOrbiterD, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aIngress, 18U) + aOrbiterI) + RotL64(aOrbiterB, 60U)) + RotL64(aNonceWordD, 17U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 47U) + aOrbiterC) + RotL64(aOrbiterF, 53U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterI, 19U)) + aOrbiterF) + aWandererUpdateSaltB[((aIndex + 28U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 39U) + aOrbiterD) + RotL64(aOrbiterC, 13U)) + aWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 57U) + aOrbiterI) + RotL64(aOrbiterA, 43U)) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterB, 23U));
            aWandererH = aWandererH + ((((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 21U)) + RotL64(aNonceWordE, 9U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 24U) + aOrbiterK) + RotL64(aOrbiterA, 3U));
            aWandererF = aWandererF + ((RotL64(aCross, 13U) + RotL64(aOrbiterG, 30U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererH, 14U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_BaseBall_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xD5093DF0FD2A8A8BULL + 0xDF7B52C66C132F09ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x9BDC2900BE4049D1ULL + 0xFBD7B2878F7B169CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xBB38BB1B832990F9ULL + 0xE4B57AAFA3C82B79ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x9E5882C9FC83CD9FULL + 0x957F74EE395CBF1DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xEC7F5B48BFE8CBB9ULL + 0xC23AFF5D638B6BCCULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xF74720E5371058EFULL + 0xF2491E42539B4C1FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x9F67AB2F87E53E09ULL + 0xC6E830FB9FAB328BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xB35D066B4D256417ULL + 0xC71CBD1AC7064EA7ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 3U) ^ RotL64(aNonceWordF, 53U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 2345U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2049U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 3U) ^ RotL64(aNonceWordD, 11U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 262U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 1722U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCross, 53U)) ^ (RotL64(aCarry, 6U) ^ RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererK + RotL64(aIngress, 57U)) + 11450949896247900941U;
            aOrbiterF = ((aWandererD + RotL64(aCross, 47U)) + RotL64(aCarry, 23U)) + 3905542253538116335U;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 19U)) + 9529740545977785305U) + aOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = ((((aWandererI + RotL64(aPrevious, 27U)) + RotL64(aCarry, 53U)) + 1856876631533143492U) + aOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1]) + RotL64(aNonceWordB, 30U);
            aOrbiterJ = (((aWandererH + RotL64(aIngress, 36U)) + RotL64(aCarry, 3U)) + 84253466320181686U) + RotL64(aNonceWordG, 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 12577480918745432444U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 5625703170397704029U) ^ RotL64(aNonceWordF, 25U);
            aOrbiterD = RotL64((aOrbiterD * 13583960724598036659U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 694608607323629282U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 3993981243536262204U) ^ aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2502835860198146381U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 4119215953484892051U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterF) ^ 8785040118556157146U) ^ aOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1]) ^ RotL64(aNonceWordA, 45U);
            aOrbiterI = RotL64((aOrbiterI * 17113521266125471625U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 16234403619456882890U) + aOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 10398727475672860610U;
            aOrbiterF = RotL64((aOrbiterF * 5086871400049644715U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 18327987141759096769U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 2645964788056875452U;
            aOrbiterJ = RotL64((aOrbiterJ * 8778681366114628045U), 43U);
            //
            aIngress = RotL64(aOrbiterD, 47U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 26U));
            aIngress = aIngress + RotL64(aOrbiterB, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 58U)) + aOrbiterJ) + RotL64(aNonceWordH, 31U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterB, 37U)) + aOrbiterD) + aWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 34U) + aOrbiterI) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 5U) + aOrbiterF) + RotL64(aOrbiterI, 29U));
            aWandererD = aWandererD + (((((RotL64(aPrevious, 23U) + RotL64(aOrbiterJ, 13U)) + aOrbiterF) + RotL64(aCarry, 43U)) + RotL64(aNonceWordC, 3U)) + aWandererUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 44U));
            aCarry = aCarry + RotL64(aWandererK, 19U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 53U) ^ RotL64(aNonceWordB, 3U)) ^ RotL64(aNonceWordH, 24U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10545U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneD[((aIndex + 8635U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 5U) ^ RotL64(aNonceWordE, 23U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 11830U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10209U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 6U) + RotL64(aCross, 23U)) ^ (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (((aWandererH + RotL64(aIngress, 30U)) + RotL64(aCarry, 5U)) + 6381335981879993247U) + RotL64(aNonceWordC, 47U);
            aOrbiterI = ((aWandererB + RotL64(aCross, 5U)) + RotL64(aCarry, 51U)) + 15595429101600023172U;
            aOrbiterF = (((aWandererF + RotL64(aScatter, 19U)) + 5449234297249826461U) + aOrbiterAssignSaltB[((aIndex + 12U)) & S_SALT1]) + RotL64(aNonceWordD, 51U);
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 39U)) + RotL64(aCarry, 21U)) + 11213734849329731168U;
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 47U)) + 16438473952464514248U) + aOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 7357872882115186976U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 394402075160738643U) ^ RotL64(aNonceWordB, 40U);
            aOrbiterF = RotL64((aOrbiterF * 11961225338735982661U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 11112941985410283532U) + aOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 14955125011182736212U;
            aOrbiterJ = RotL64((aOrbiterJ * 10711684773326395603U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 14770727009821304070U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 11286366598129204910U) ^ RotL64(aNonceWordH, 41U);
            aOrbiterH = RotL64((aOrbiterH * 15884310771003021989U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 7358400908565425780U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 15635109923749114761U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12415152149408700329U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 13826842523738623579U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 1072811298828325231U) ^ aOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9662800288646215083U), 13U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterI, 35U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aIngress, 27U) + aOrbiterJ) + RotL64(aOrbiterH, 21U)) + aWandererUpdateSaltE[((aIndex + 8U)) & S_SALT1]);
            aWandererF = aWandererF + (((((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 51U)) + RotL64(aNonceWordF, 39U)) + aWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 44U) + aOrbiterF) + RotL64(aOrbiterJ, 11U));
            aWandererH = aWandererH + (((RotL64(aScatter, 57U) + aOrbiterI) + RotL64(aOrbiterB, 47U)) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterF, 34U)) + aOrbiterB) + RotL64(aNonceWordA, 53U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 48U));
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 11U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 58U) ^ RotL64(aNonceWordH, 21U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 17054U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24066U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 43U) ^ RotL64(aNonceWordB, 29U)) ^ RotL64(aNonceWordF, 54U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 16608U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 20703U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 60U) + RotL64(aCross, 47U)) ^ (RotL64(aIngress, 11U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 41U)) + 11410829607777684449U;
            aOrbiterJ = (((aWandererE + RotL64(aIngress, 35U)) + RotL64(aCarry, 29U)) + 7502698839700975347U) + RotL64(aNonceWordG, 19U);
            aOrbiterB = ((((aWandererD + RotL64(aScatter, 27U)) + RotL64(aCarry, 13U)) + 13267685058252106173U) + aOrbiterAssignSaltC[(((31U - aIndex) + 22U)) & S_SALT1]) + RotL64(aNonceWordC, 25U);
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 51U)) + 238242706996630625U) + aOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = (aWandererB + RotL64(aCross, 12U)) + 8184695499511454281U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 12767823220461985403U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 12293198423143850330U) ^ aOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5073886956792823825U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 11149495229952495939U) + RotL64(aNonceWordB, 15U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 7556992689338382800U;
            aOrbiterJ = RotL64((aOrbiterJ * 18232398462716803063U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 3431338808774134649U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 16863099140844995099U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 752376661101787919U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 17872458049880677604U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 16760153457252546974U;
            aOrbiterK = RotL64((aOrbiterK * 11225037229069712805U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 3115544493537438408U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = (((aOrbiterI ^ aOrbiterJ) ^ 4359882942759752958U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]) ^ RotL64(aNonceWordE, 31U);
            aOrbiterI = RotL64((aOrbiterI * 561477566995575801U), 27U);
            //
            aIngress = RotL64(aOrbiterB, 47U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterJ, 34U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aCross, 46U) + aOrbiterI) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 39U)) + RotL64(aNonceWordA, 20U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 57U)) + aOrbiterI);
            aWandererE = aWandererE + (((((RotL64(aPrevious, 37U) + aOrbiterK) + RotL64(aOrbiterB, 4U)) + RotL64(aCarry, 3U)) + RotL64(aNonceWordD, 7U)) + aWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 3U) + aOrbiterF) + RotL64(aOrbiterJ, 21U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterB, 47U)) + aWandererUpdateSaltA[((aIndex + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 56U));
            aCarry = aCarry + RotL64(aWandererI, 21U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 3U) ^ RotL64(aNonceWordH, 40U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 25160U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((aIndex + 26057U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 11U) ^ RotL64(aNonceWordD, 41U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31673U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 31561U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 58U) + RotL64(aPrevious, 41U)) ^ (RotL64(aIngress, 29U) ^ RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 47U)) + 6318740973868639425U) + RotL64(aNonceWordG, 27U);
            aOrbiterE = ((aWandererK + RotL64(aCross, 30U)) + 5487840061430920881U) + RotL64(aNonceWordB, 50U);
            aOrbiterG = (((aWandererB + RotL64(aIngress, 5U)) + RotL64(aCarry, 19U)) + 10258706763248072672U) + aOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = (((aWandererH + RotL64(aScatter, 39U)) + RotL64(aCarry, 35U)) + 18356875269730338208U) + aOrbiterAssignSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aCross, 19U)) + RotL64(aCarry, 5U)) + 12883160282903147010U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 1010140474942697730U) + aOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 17733939421700898293U;
            aOrbiterG = RotL64((aOrbiterG * 9233534157871885251U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 13693055887924981201U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 14574732452793385269U;
            aOrbiterI = RotL64((aOrbiterI * 9373765929885750185U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 10832873941223609012U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterE) ^ 8212600587135328040U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]) ^ RotL64(aNonceWordE, 51U);
            aOrbiterC = RotL64((aOrbiterC * 5334613996794796145U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 5312744319781971178U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 6173741211706546923U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12854414066390848249U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 3693249147883790810U) + aOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 18365859989736602556U) ^ RotL64(aNonceWordA, 39U);
            aOrbiterB = RotL64((aOrbiterB * 3348463719324104997U), 13U);
            //
            aIngress = RotL64(aOrbiterE, 27U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterI, 14U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterB, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 11U) + aOrbiterC) + RotL64(aOrbiterI, 39U)) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterI, 13U)) + RotL64(aNonceWordF, 61U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 34U) + aOrbiterI) + RotL64(aOrbiterE, 51U)) + RotL64(aCarry, 21U)) + RotL64(aNonceWordH, 53U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterG, 27U)) + aWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 19U) + aOrbiterG) + RotL64(aOrbiterE, 4U)) + aWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 60U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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

void TwistExpander_BaseBall_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xEADDCC9670375A75ULL + 0x8C640C42AA1AFAE7ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x9FED970B1CF2112DULL + 0xDB2A8D74721BAAA8ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x84A1746ACB06DD83ULL + 0x9B71A5EC6871E08BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xF0C5A683A3640E75ULL + 0xB3D633C14AF151DAULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xB1322D806284B663ULL + 0x8CAE7B3B89DBE403ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xF44D416CA252DABFULL + 0xBE825BFFC9E89C3EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x92C54FFE728E3E79ULL + 0xDA43DE1A12F111FCULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x927960D94BF85B63ULL + 0xE3211ACE141EEFB3ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 19U) ^ RotL64(aNonceWordB, 41U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 6115U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneC[((aIndex + 6561U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 58U) ^ RotL64(aNonceWordD, 5U)) ^ RotL64(aNonceWordE, 21U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7670U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((aIndex + 2958U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 27U)) ^ (RotL64(aIngress, 52U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (((aWandererD + RotL64(aIngress, 29U)) + RotL64(aCarry, 57U)) + 3970829908171131502U) + aOrbiterAssignSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = ((aWandererC + RotL64(aScatter, 5U)) + RotL64(aCarry, 13U)) + 7040283759419531991U;
            aOrbiterK = ((aWandererI + RotL64(aCross, 23U)) + RotL64(aCarry, 27U)) + 11856292169397052901U;
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 39U)) + 819598588791819022U) + aOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 54U)) + 2176451710970866848U) + RotL64(aNonceWordH, 61U);
            aOrbiterG = (aWandererF + RotL64(aIngress, 47U)) + 6454704928613390494U;
            aOrbiterH = ((aWandererK + RotL64(aCross, 13U)) + 11792122387218053841U) + RotL64(aNonceWordF, 44U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 9254780213489752211U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 16591812589999846482U;
            aOrbiterK = RotL64((aOrbiterK * 5425771603523423167U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 1471246223935074832U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 1424843083106386453U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15020536982657410783U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 1856469958050891629U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterI) ^ 6331743690452052712U) ^ aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1]) ^ RotL64(aNonceWordA, 51U);
            aOrbiterG = RotL64((aOrbiterG * 15327924647897459645U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 10351075711345476487U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 9518585245330480185U) ^ aOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3792179827396760391U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 17787514620244712033U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 14182328067398162557U;
            aOrbiterF = RotL64((aOrbiterF * 18107337388659070197U), 35U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterF) + 12798088948801072444U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]) + RotL64(aNonceWordE, 17U);
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 9563215159275202323U;
            aOrbiterE = RotL64((aOrbiterE * 7058145016617349141U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 9904919772580498232U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 16579777394992143043U;
            aOrbiterI = RotL64((aOrbiterI * 10516761340320196661U), 27U);
            //
            aIngress = RotL64(aOrbiterG, 14U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 53U));
            aIngress = aIngress + (RotL64(aOrbiterF, 21U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 51U) + aOrbiterF) + RotL64(aOrbiterJ, 29U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterG, 4U)) + aOrbiterF) + RotL64(aCarry, 19U)) + aWandererUpdateSaltB[((aIndex + 20U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 11U)) + aOrbiterE);
            aWandererD = aWandererD + ((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterI, 41U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 57U) + aOrbiterE) + RotL64(aOrbiterK, 21U));
            aWandererI = aWandererI + ((((RotL64(aCross, 12U) + RotL64(aOrbiterK, 35U)) + aOrbiterH) + RotL64(aCarry, 57U)) + RotL64(aNonceWordB, 21U));
            aWandererC = aWandererC ^ ((((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 57U)) + aOrbiterG) + RotL64(aNonceWordC, 37U)) + aWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (RotL64(aWandererF, 60U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 5U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 58U) ^ RotL64(aNonceWordH, 27U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9561U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((aIndex + 11795U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 3U) ^ RotL64(aNonceWordD, 35U)) ^ RotL64(aNonceWordG, 48U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12631U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((aIndex + 15461U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 37U) ^ RotL64(aPrevious, 5U)) + (RotL64(aIngress, 52U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 11U)) + 18255347001097480328U) + RotL64(aNonceWordC, 51U);
            aOrbiterC = (aWandererJ + RotL64(aScatter, 60U)) + 13679246790311505735U;
            aOrbiterD = (((aWandererK + RotL64(aIngress, 21U)) + RotL64(aCarry, 27U)) + 10565839529765027116U) + RotL64(aNonceWordD, 53U);
            aOrbiterI = (aWandererI + RotL64(aCross, 35U)) + 14327172566224769901U;
            aOrbiterH = (((aWandererC + RotL64(aScatter, 27U)) + RotL64(aCarry, 47U)) + 16239024612038195174U) + aOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aCross, 5U)) + RotL64(aCarry, 11U)) + 13800012174212131890U;
            aOrbiterE = ((aWandererF + RotL64(aIngress, 53U)) + 13900288860157577583U) + aOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 4144386119777112740U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 3154558262670631372U) ^ RotL64(aNonceWordB, 43U);
            aOrbiterD = RotL64((aOrbiterD * 13236911910092437063U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 7456728543137614001U) + RotL64(aNonceWordG, 21U);
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 11709519851158935384U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7016689518570071587U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 15607438907832240304U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 9276575329661725624U) ^ aOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8879744070762412745U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 6459435969129449226U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 6442382118416542275U;
            aOrbiterC = RotL64((aOrbiterC * 2921027306686588233U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 12117432107282150865U) + aOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 6831279293184793243U) ^ aOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2435360641135249073U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 9520022957804572889U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 8322178689474588679U;
            aOrbiterA = RotL64((aOrbiterA * 1627707191467537115U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 4162401591586869316U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 8994015844714895961U;
            aOrbiterE = RotL64((aOrbiterE * 15421910378057951895U), 29U);
            //
            aIngress = RotL64(aOrbiterA, 21U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + RotL64(aOrbiterE, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aPrevious, 51U) + aOrbiterC) + RotL64(aOrbiterH, 19U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterC, 5U)) + aOrbiterI) + RotL64(aNonceWordE, 6U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 23U) + RotL64(aOrbiterH, 28U)) + aOrbiterI) + RotL64(aCarry, 23U)) + RotL64(aNonceWordF, 15U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 30U) + aOrbiterD) + RotL64(aOrbiterK, 13U)) + aWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 41U)) + aOrbiterE);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterD, 51U)) + aOrbiterA);
            aWandererB = aWandererB + ((((RotL64(aCross, 37U) + RotL64(aOrbiterD, 35U)) + aOrbiterI) + RotL64(aCarry, 43U)) + aWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 34U));
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 41U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 37U) ^ RotL64(aNonceWordE, 53U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 20119U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneA[((aIndex + 18591U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 19U) ^ RotL64(aNonceWordH, 3U)) ^ RotL64(aNonceWordG, 58U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 22172U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((aIndex + 22774U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 29U) ^ RotL64(aCarry, 11U)) + (RotL64(aIngress, 43U) + RotL64(aCross, 58U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (((aWandererK + RotL64(aPrevious, 13U)) + 12426357877879529292U) + aOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1]) + RotL64(aNonceWordD, 57U);
            aOrbiterI = (aWandererA + RotL64(aCross, 21U)) + 12604900366173639176U;
            aOrbiterH = (aWandererB + RotL64(aScatter, 47U)) + 13511119007338929401U;
            aOrbiterK = (((aWandererD + RotL64(aIngress, 5U)) + RotL64(aCarry, 11U)) + 9878720081166788060U) + RotL64(aNonceWordC, 13U);
            aOrbiterB = ((aWandererH + RotL64(aCross, 41U)) + RotL64(aCarry, 29U)) + 15463195409806395076U;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 34U)) + 6407922778852833423U) + aOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 53U)) + RotL64(aCarry, 51U)) + 7690427254160734016U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 18030974031722143619U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 17983938038322737041U) ^ aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12479365337221685413U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 16605512170117753884U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 681802273302348322U;
            aOrbiterI = RotL64((aOrbiterI * 14608920184802647123U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 15550312921312083819U) + RotL64(aNonceWordB, 51U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 17824154101711884508U;
            aOrbiterJ = RotL64((aOrbiterJ * 7358612830654795357U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 1939207786756735430U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 3132864634777826569U;
            aOrbiterK = RotL64((aOrbiterK * 13606281919426730325U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 12822929773923954849U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 16576106045887115660U) ^ RotL64(aNonceWordG, 47U);
            aOrbiterB = RotL64((aOrbiterB * 16370914370769903051U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 2398825881649235260U) + aOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 13700821892926092479U;
            aOrbiterE = RotL64((aOrbiterE * 10830623703416956043U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 2439833784883391606U) + aOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 15870638514107637833U;
            aOrbiterG = RotL64((aOrbiterG * 3797380922767479287U), 41U);
            //
            aIngress = RotL64(aOrbiterB, 41U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + (RotL64(aOrbiterI, 53U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aCross, 21U) + RotL64(aOrbiterI, 19U)) + aOrbiterJ);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 53U)) + aOrbiterG) + RotL64(aNonceWordE, 46U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 35U)) + aOrbiterH) + RotL64(aCarry, 53U)) + aWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 27U) + aOrbiterE) + RotL64(aOrbiterK, 44U)) + RotL64(aNonceWordA, 25U)) + aWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 51U) + RotL64(aOrbiterG, 27U)) + aOrbiterH) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 3U)) + aOrbiterB);
            aWandererK = aWandererK + ((RotL64(aPrevious, 42U) + RotL64(aOrbiterK, 11U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 12U));
            aCarry = aCarry + RotL64(aWandererK, 43U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 48U) ^ RotL64(aNonceWordH, 39U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 26539U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32365U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 57U) ^ RotL64(aNonceWordC, 35U)) ^ RotL64(aNonceWordG, 11U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25971U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneD[((aIndex + 29511U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 19U) + RotL64(aPrevious, 4U)) ^ (RotL64(aCross, 39U) + RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererK + RotL64(aScatter, 38U)) + 252059974543142812U) + aOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 3U)) + 11690823093681457368U) + RotL64(aNonceWordF, 57U);
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 19U)) + RotL64(aCarry, 13U)) + 13282189752890971123U;
            aOrbiterC = ((aWandererC + RotL64(aIngress, 27U)) + RotL64(aCarry, 51U)) + 9507416294305708435U;
            aOrbiterF = ((aWandererE + RotL64(aCross, 53U)) + RotL64(aCarry, 29U)) + 14053038174390776539U;
            aOrbiterG = (aWandererA + RotL64(aPrevious, 11U)) + 14605253312318725009U;
            aOrbiterK = (((aWandererF + RotL64(aScatter, 47U)) + 18138286582677863671U) + aOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1]) + RotL64(aNonceWordD, 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 8530091235978489988U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterA) ^ 14381731677571170073U) ^ aOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1]) ^ RotL64(aNonceWordH, 29U);
            aOrbiterB = RotL64((aOrbiterB * 11675896999665768253U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 13316413456378978456U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 3910529530149320706U;
            aOrbiterG = RotL64((aOrbiterG * 16000139333493588429U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 6302070286831566901U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 12324134652758551396U;
            aOrbiterJ = RotL64((aOrbiterJ * 17136438281540250165U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 4773478557638475048U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 4031153435446078944U;
            aOrbiterF = RotL64((aOrbiterF * 3876928995240982769U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 3114794895962903899U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 3552936509969106796U;
            aOrbiterA = RotL64((aOrbiterA * 16823186892738820299U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 5828754613946145627U) + RotL64(aNonceWordG, 39U);
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 17985241114076114558U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1986669631395606833U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 11319331046368072261U) + aOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 6104267020171882160U;
            aOrbiterK = RotL64((aOrbiterK * 12525117969211576177U), 47U);
            //
            aIngress = RotL64(aOrbiterK, 51U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aCross, 13U) + RotL64(aOrbiterK, 27U)) + aOrbiterF) + RotL64(aCarry, 35U)) + aWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 34U)) + aOrbiterJ);
            aWandererC = aWandererC + (((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 19U) + aOrbiterK) + RotL64(aOrbiterJ, 3U)) + RotL64(aNonceWordB, 45U)) + aWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 34U) + RotL64(aOrbiterJ, 53U)) + aOrbiterB);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 21U)) + aOrbiterA) + RotL64(aNonceWordA, 38U));
            aWandererA = aWandererA + ((RotL64(aScatter, 27U) + RotL64(aOrbiterB, 47U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (RotL64(aWandererA, 18U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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

void TwistExpander_BaseBall_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xC8624BDD99EC2D35ULL + 0xFE6CFF526AA5E305ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x87E1B8D128DFBC01ULL + 0xEDD47FBB8211496BULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xBA0310EF87E13C29ULL + 0xB9CFE9D31718EC9BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xF1C498F055208B63ULL + 0xA2020219C3B3694AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xAB09F8EF442190A5ULL + 0xA85E9EF047209FACULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xBA0A5C5A8000A3CFULL + 0x8B1FB93907B8B6F0ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xE4697954DFA968D5ULL + 0x937C1960ADA7C32FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xBC460601A5BFCD71ULL + 0xFCFAA9278B61519AULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 29U) ^ RotL64(aNonceWordG, 57U)) ^ RotL64(aNonceWordE, 46U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 2728U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 2123U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 38U) ^ RotL64(aNonceWordB, 29U)) ^ RotL64(aNonceWordD, 5U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 2972U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 8106U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aIngress, 5U)) ^ (RotL64(aCross, 39U) + RotL64(aPrevious, 22U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererH + RotL64(aIngress, 27U)) + RotL64(aCarry, 27U)) + 6068543441070417854U;
            aOrbiterG = ((aWandererI + RotL64(aCross, 51U)) + 2995980468193441856U) + aOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = (((aWandererG + RotL64(aPrevious, 35U)) + RotL64(aCarry, 57U)) + 18020277482171594003U) + aOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aScatter, 21U)) + 4293807434721230702U;
            aOrbiterD = (((aWandererE + RotL64(aCross, 41U)) + RotL64(aCarry, 13U)) + 7980599111583893156U) + RotL64(aNonceWordA, 37U);
            aOrbiterA = ((aWandererA + RotL64(aIngress, 13U)) + 8593141111851052016U) + RotL64(aNonceWordH, 53U);
            aOrbiterB = (aWandererC + RotL64(aScatter, 58U)) + 5903487523900084325U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 15112035513447930209U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 9854037263057006439U;
            aOrbiterF = RotL64((aOrbiterF * 396276470208637283U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 16759760289688823193U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 12622628933030601390U) ^ aOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2151912984825538321U), 13U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterD) + 1264668857268123425U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]) + RotL64(aNonceWordF, 8U);
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 16302812053619101593U;
            aOrbiterA = RotL64((aOrbiterA * 18291400055836111547U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 16087995784896123610U) + aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 7970269262800468363U;
            aOrbiterB = RotL64((aOrbiterB * 14924752223305807461U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 5331477046030959632U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 16534913204255550893U) ^ RotL64(aNonceWordD, 21U);
            aOrbiterH = RotL64((aOrbiterH * 1013433634373673565U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 11042821902537871209U) + aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 8069677512345031660U;
            aOrbiterE = RotL64((aOrbiterE * 13622218526054132397U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 5737130058129936372U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 1076627182956662997U;
            aOrbiterG = RotL64((aOrbiterG * 14342191224014199929U), 35U);
            //
            aIngress = RotL64(aOrbiterA, 27U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterF, 51U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + RotL64(aOrbiterG, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 26U) + aOrbiterH) + RotL64(aOrbiterF, 11U)) + aWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterE, 21U)) + RotL64(aCarry, 21U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 41U) + aOrbiterG) + RotL64(aOrbiterA, 35U));
            aWandererE = aWandererE + (((RotL64(aScatter, 35U) + aOrbiterA) + RotL64(aOrbiterF, 50U)) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterE, 3U));
            aWandererC = aWandererC + (((RotL64(aScatter, 19U) + RotL64(aOrbiterB, 57U)) + aOrbiterD) + RotL64(aNonceWordE, 55U));
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 43U)) + aOrbiterE) + RotL64(aNonceWordG, 29U)) + aWandererUpdateSaltC[((aIndex + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 4U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererE, 53U);
            aCarry = aCarry + RotL64(aIngress, 18U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 3U) ^ RotL64(aNonceWordE, 35U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 11730U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 16286U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 3U) ^ RotL64(aNonceWordG, 19U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 9081U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneB[((aIndex + 13732U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aPrevious, 18U)) ^ (RotL64(aIngress, 3U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererI + RotL64(aScatter, 35U)) + 3917730204724097072U;
            aOrbiterD = (((aWandererB + RotL64(aCross, 43U)) + 1874642340716212824U) + aOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1]) + RotL64(aNonceWordG, 21U);
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 26U)) + 6900165757434854160U;
            aOrbiterE = (((aWandererF + RotL64(aIngress, 11U)) + RotL64(aCarry, 39U)) + 12750946097023807161U) + RotL64(aNonceWordC, 19U);
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 19U)) + 6563216048479513594U) + aOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 53U)) + RotL64(aCarry, 3U)) + 14960240191349450795U;
            aOrbiterB = ((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 51U)) + 16306180275951788289U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 6502066618271045547U) + RotL64(aNonceWordH, 3U);
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 6219852857850888738U;
            aOrbiterG = RotL64((aOrbiterG * 10892297250334325283U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 2272931312452845850U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 3028929882263199463U;
            aOrbiterH = RotL64((aOrbiterH * 11005324285856805069U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 6067393030073568112U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 10094809900437037258U) ^ aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 18095564940730322769U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 5962414178157074575U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 15755563045799129417U) ^ aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3692603590609922031U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 6321455513889880590U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 1197435601998121700U;
            aOrbiterC = RotL64((aOrbiterC * 17693996266260557625U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 12496949381666299968U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 6357070235648527030U;
            aOrbiterJ = RotL64((aOrbiterJ * 2931486644220862433U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 8423760160877540210U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = (((aOrbiterB ^ aOrbiterG) ^ 8090246492554850768U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]) ^ RotL64(aNonceWordA, 15U);
            aOrbiterB = RotL64((aOrbiterB * 2949407491181921633U), 37U);
            //
            aIngress = RotL64(aOrbiterJ, 43U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 54U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterG, 11U));
            aWandererH = aWandererH + ((RotL64(aIngress, 60U) + RotL64(aOrbiterB, 43U)) + aOrbiterH);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterD, 5U)) + RotL64(aNonceWordB, 41U));
            aWandererE = aWandererE + (((RotL64(aScatter, 41U) + aOrbiterC) + RotL64(aOrbiterJ, 19U)) + RotL64(aCarry, 23U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 53U) + aOrbiterG) + RotL64(aOrbiterB, 56U));
            aWandererB = aWandererB + ((((RotL64(aCross, 5U) + RotL64(aOrbiterH, 29U)) + aOrbiterJ) + RotL64(aCarry, 43U)) + aWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 35U)) + aOrbiterB) + RotL64(aNonceWordF, 58U)) + aWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 14U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + RotL64(aWandererG, 53U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 35U) ^ RotL64(aNonceWordH, 43U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 17483U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((aIndex + 23207U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 40U) ^ RotL64(aNonceWordE, 19U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 18523U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneC[((aIndex + 20693U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aPrevious, 27U)) + (RotL64(aIngress, 5U) ^ RotL64(aCarry, 44U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererF + RotL64(aScatter, 3U)) + 3199575576585871314U;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 53U)) + 2533378188975571824U) + aOrbiterAssignSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = (((aWandererH + RotL64(aCross, 13U)) + RotL64(aCarry, 29U)) + 6819782112558312658U) + RotL64(aNonceWordD, 9U);
            aOrbiterK = (((aWandererE + RotL64(aIngress, 47U)) + RotL64(aCarry, 13U)) + 12690060987724798497U) + RotL64(aNonceWordE, 37U);
            aOrbiterE = ((aWandererI + RotL64(aScatter, 29U)) + RotL64(aCarry, 41U)) + 7088375139715629606U;
            aOrbiterB = (aWandererK + RotL64(aIngress, 41U)) + 17785618677423695666U;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 22U)) + 1714999280296491277U) + aOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 17611338506932491624U) + aOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 6475727359297421201U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15133348244242438069U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 2347744591204119530U) + aOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 2739317903351401068U;
            aOrbiterH = RotL64((aOrbiterH * 15435029315209475631U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 8663535261373274338U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 8205245127823536479U) ^ RotL64(aNonceWordH, 48U);
            aOrbiterJ = RotL64((aOrbiterJ * 13857005110466856439U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 8916510616749754516U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 3944805940148512932U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 18082271583211389701U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 14094751253118853302U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 14094299829196076311U;
            aOrbiterE = RotL64((aOrbiterE * 6370012560657108493U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 3940673811518673802U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 3015106523254484839U) ^ RotL64(aNonceWordG, 61U);
            aOrbiterB = RotL64((aOrbiterB * 9655401190755573379U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 15404103131982599922U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 1828655763233900875U;
            aOrbiterI = RotL64((aOrbiterI * 13024358077740310049U), 47U);
            //
            aIngress = RotL64(aOrbiterK, 6U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterH, 23U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterE, 51U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 14U) + RotL64(aOrbiterE, 21U)) + aOrbiterJ) + aWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterH, 13U)) + aOrbiterG);
            aWandererC = aWandererC + ((((RotL64(aCross, 57U) + aOrbiterI) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 53U)) + RotL64(aNonceWordA, 15U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterB, 37U));
            aWandererK = aWandererK + ((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterE, 27U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 27U) + aOrbiterG) + RotL64(aOrbiterJ, 51U));
            aWandererB = aWandererB + (((((RotL64(aPrevious, 43U) + aOrbiterK) + RotL64(aOrbiterJ, 58U)) + RotL64(aCarry, 5U)) + RotL64(aNonceWordC, 35U)) + aWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 14U));
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + RotL64(aWandererF, 51U);
            aCarry = aCarry + RotL64(aIngress, 30U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 21U) ^ RotL64(aNonceWordG, 3U)) ^ RotL64(aNonceWordC, 43U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31027U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25711U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 29U) ^ RotL64(aNonceWordD, 47U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29640U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 25401U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 43U) + RotL64(aCross, 27U)) ^ (RotL64(aCarry, 56U) + RotL64(aIngress, 13U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererA + RotL64(aScatter, 41U)) + 1898718075389870739U;
            aOrbiterA = (aWandererK + RotL64(aIngress, 6U)) + 5631794889237247403U;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 13U)) + RotL64(aCarry, 27U)) + 18219714659484524607U;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 35U)) + RotL64(aCarry, 57U)) + 15419581386225732921U;
            aOrbiterE = (((aWandererI + RotL64(aIngress, 29U)) + 9125575431710198210U) + aOrbiterAssignSaltD[(((31U - aIndex) + 20U)) & S_SALT1]) + RotL64(aNonceWordC, 46U);
            aOrbiterF = (((aWandererG + RotL64(aCross, 53U)) + 12205871520544965505U) + aOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1]) + RotL64(aNonceWordD, 19U);
            aOrbiterD = ((aWandererE + RotL64(aScatter, 23U)) + RotL64(aCarry, 39U)) + 7617534300497343422U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 18017579105368135814U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 10693882161946020042U;
            aOrbiterI = RotL64((aOrbiterI * 2326507900303932855U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 11669615701700895306U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 11045110212889232165U;
            aOrbiterF = RotL64((aOrbiterF * 5965171269273719849U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 18019107802806469913U) + RotL64(aNonceWordE, 37U);
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 12315940560472528716U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4505122470351404065U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 4899009736070044310U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 17412253404253730364U;
            aOrbiterE = RotL64((aOrbiterE * 10791901166391946485U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 4826286251927854181U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 4523455921321845084U;
            aOrbiterJ = RotL64((aOrbiterJ * 14534103906736598099U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 4132514462154182215U) + aOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 7164745605985109269U) ^ aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14107325508977225261U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 6297434295807635654U) + aOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 8813887638672996646U) ^ RotL64(aNonceWordH, 59U);
            aOrbiterD = RotL64((aOrbiterD * 17495632530773158201U), 57U);
            //
            aIngress = RotL64(aOrbiterF, 4U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 51U));
            aIngress = aIngress + RotL64(aOrbiterA, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aScatter, 11U) + aOrbiterI) + RotL64(aOrbiterJ, 22U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 27U) + aOrbiterA) + RotL64(aOrbiterD, 41U));
            aWandererE = aWandererE + (((((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterI, 51U)) + RotL64(aCarry, 23U)) + RotL64(aNonceWordA, 61U)) + aWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 4U) + aOrbiterI) + RotL64(aOrbiterC, 3U)) + aWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterI, 11U)) + RotL64(aCarry, 57U)) + RotL64(aNonceWordF, 49U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterF, 57U)) + aOrbiterE);
            aWandererA = aWandererA + ((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterE, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + RotL64(aWandererI, 26U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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

void TwistExpander_BaseBall_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xA33C3AD574028B81ULL + 0xA57CB1C4B8E7B23BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x84B23DF9EF486B37ULL + 0xBBB16C228B147B13ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x99D6410D47F9B871ULL + 0x8FC1F4C98CF21925ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xC6847DBF9810A1E9ULL + 0xDA9BB34278479AE4ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x97863495AA09639FULL + 0xC30CBBC7CE9A6BFAULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x9F5B71C0DD6AC30FULL + 0x93E2A201CF2E2F1DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xEB8DF64E717AEF13ULL + 0xE60D3AC7AD25DE21ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xBE84B70EB6AFD529ULL + 0x9420ED401941E13DULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 39U) ^ RotL64(aNonceWordG, 30U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1965U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((aIndex + 5877U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 35U) ^ RotL64(aNonceWordE, 14U)) ^ RotL64(aNonceWordD, 27U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6034U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 2243U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 54U)) ^ (RotL64(aCross, 29U) ^ RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 21U)) + 14214886793361825363U) + aOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = (aWandererC + RotL64(aCross, 42U)) + 17267959031078766320U;
            aOrbiterA = (aWandererB + RotL64(aIngress, 27U)) + 16436067429484887644U;
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 11U)) + 9885951769332633820U) + aOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = ((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 57U)) + 12971711341813893304U;
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 39U)) + 199970353398450154U;
            aOrbiterF = (((aWandererA + RotL64(aScatter, 51U)) + RotL64(aCarry, 37U)) + 1237341696444162094U) + RotL64(aNonceWordD, 17U);
            aOrbiterB = (aWandererG + RotL64(aIngress, 57U)) + 7991128854417613360U;
            aOrbiterG = (aWandererH + RotL64(aCross, 6U)) + 14809029847149045833U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 23U)) + 2559509556915775947U) + RotL64(aNonceWordG, 53U);
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 29U)) + RotL64(aCarry, 5U)) + 14336829730147834160U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 8853631886733610440U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 13346159398673246914U;
            aOrbiterA = RotL64((aOrbiterA * 13660497151446983393U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 12121095718571872976U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 16239781125815589804U) ^ aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5157009090454962231U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 9051377033794324106U) + aOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 13805815136723461780U) ^ RotL64(aNonceWordC, 7U);
            aOrbiterJ = RotL64((aOrbiterJ * 571129481747181357U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 14849157800322754413U) + RotL64(aNonceWordB, 38U);
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 18116651528452542634U;
            aOrbiterI = RotL64((aOrbiterI * 3638480428016835537U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 4105057226952948599U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 5911714320560994391U;
            aOrbiterF = RotL64((aOrbiterF * 1796514171654961389U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 4439149331729987587U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 10278532228230163632U;
            aOrbiterG = RotL64((aOrbiterG * 17428224919864716517U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 2342456582668741750U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 2360578572554664800U;
            aOrbiterH = RotL64((aOrbiterH * 1108428466956691925U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 12132934875391401246U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 17213278726790245812U;
            aOrbiterD = RotL64((aOrbiterD * 11904899990681410419U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 7994340481560109811U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 13735851271080138255U;
            aOrbiterC = RotL64((aOrbiterC * 12387076892129731557U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 6682417543888875268U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 15642799286975840550U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7861250716882028053U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 9839299346094784067U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 14214886793361825363U;
            aOrbiterE = RotL64((aOrbiterE * 2103132743364916037U), 43U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 19U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterH, 11U)) + aOrbiterF);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterA, 4U)) + aOrbiterH) + aWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 24U) + RotL64(aOrbiterK, 35U)) + aOrbiterB) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 39U) + aOrbiterH) + RotL64(aOrbiterI, 37U)) + RotL64(aNonceWordE, 39U)) + aWandererUpdateSaltA[((aIndex + 20U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 57U) + aOrbiterI) + RotL64(aOrbiterK, 41U)) + RotL64(aCarry, 13U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 21U) + aOrbiterK) + RotL64(aOrbiterD, 13U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 53U) + RotL64(aOrbiterK, 53U)) + aOrbiterC) + RotL64(aNonceWordF, 5U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 39U)) + aOrbiterC);
            aWandererD = aWandererD + ((RotL64(aPrevious, 19U) + aOrbiterD) + RotL64(aOrbiterG, 6U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 50U) + RotL64(aOrbiterF, 51U)) + aOrbiterE);
            aWandererK = aWandererK + ((RotL64(aCross, 11U) + aOrbiterH) + RotL64(aOrbiterK, 57U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 56U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 24U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererK, 27U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 21U) ^ RotL64(aNonceWordD, 35U)) ^ RotL64(aNonceWordH, 5U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 9797U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16104U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 57U) ^ RotL64(aNonceWordG, 21U)) ^ RotL64(aNonceWordB, 3U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13401U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneB[((aIndex + 13789U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aIngress, 11U)) ^ (RotL64(aPrevious, 54U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererF + RotL64(aCross, 11U)) + 4384716820085860551U) + aOrbiterAssignSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aPrevious, 43U)) + 9715780315942116888U;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 57U)) + 15963520052789178632U) + aOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = ((aWandererG + RotL64(aIngress, 51U)) + 14346700690686392938U) + RotL64(aNonceWordC, 21U);
            aOrbiterJ = ((aWandererB + RotL64(aCross, 27U)) + 6005518012489966643U) + RotL64(aNonceWordG, 14U);
            aOrbiterE = ((aWandererI + RotL64(aScatter, 23U)) + RotL64(aCarry, 27U)) + 2506732930310252119U;
            aOrbiterK = (aWandererA + RotL64(aIngress, 14U)) + 16782163084851775826U;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 29U)) + RotL64(aCarry, 41U)) + 823673076571076303U;
            aOrbiterD = (aWandererJ + RotL64(aCross, 21U)) + 1634084509064077736U;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 37U)) + RotL64(aCarry, 35U)) + 1288134975466877686U;
            aOrbiterI = (aWandererE + RotL64(aScatter, 6U)) + 2998220403162908444U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 220430672180734911U) + RotL64(aNonceWordE, 5U);
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 10223923547068528867U;
            aOrbiterC = RotL64((aOrbiterC * 12577370238343872139U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 11696469696177647608U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 6545430420379636963U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8387163146257553773U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 79691451831797107U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 8971444023498649419U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7148919880477390009U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 5624403902454498793U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 9468064161002030997U;
            aOrbiterK = RotL64((aOrbiterK * 8243560528100864595U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 4619361544913629805U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 12682446273369750704U) ^ RotL64(aNonceWordA, 59U);
            aOrbiterD = RotL64((aOrbiterD * 10879074713156075641U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 8728730962617599223U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 9099675924074253030U;
            aOrbiterB = RotL64((aOrbiterB * 5525644236954497523U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 3298303921318288541U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 5953276499411658358U;
            aOrbiterG = RotL64((aOrbiterG * 10565471305001292693U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 6725769507592688539U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 1057277456510215817U;
            aOrbiterE = RotL64((aOrbiterE * 8269412198279297075U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 11317925732206917722U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 17814749417006079067U) ^ aOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4369209051015735925U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 9258362135343403308U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 4873837345446960113U;
            aOrbiterH = RotL64((aOrbiterH * 14223381466269503273U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 7863380865835889675U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 4384716820085860551U;
            aOrbiterI = RotL64((aOrbiterI * 2003891033298374621U), 3U);
            //
            aIngress = RotL64(aOrbiterC, 60U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 46U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 53U)) + aOrbiterC) + RotL64(aCarry, 21U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterK, 19U)) + aOrbiterG);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterD, 60U)) + RotL64(aCarry, 53U)) + aWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 5U) + aOrbiterK) + RotL64(aOrbiterI, 21U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 26U) + RotL64(aOrbiterJ, 41U)) + aOrbiterK) + aWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 21U) + aOrbiterJ) + RotL64(aOrbiterE, 47U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 3U) + aOrbiterF) + RotL64(aOrbiterD, 56U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterF, 29U)) + aOrbiterB);
            aWandererC = aWandererC + ((RotL64(aScatter, 60U) + RotL64(aOrbiterA, 27U)) + aOrbiterD);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterG, 5U)) + aOrbiterI) + RotL64(aNonceWordF, 13U));
            aWandererE = aWandererE + (((RotL64(aCross, 57U) + aOrbiterF) + RotL64(aOrbiterG, 3U)) + RotL64(aNonceWordB, 25U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 54U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + RotL64(aWandererF, 37U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 29U) ^ RotL64(aNonceWordH, 20U)) ^ RotL64(aNonceWordG, 43U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 20039U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23703U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 51U) ^ RotL64(aNonceWordA, 5U)) ^ RotL64(aNonceWordE, 14U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 22680U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneC[((aIndex + 19753U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 6U) ^ RotL64(aIngress, 21U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererG + RotL64(aIngress, 29U)) + RotL64(aCarry, 51U)) + 1866656689936219099U;
            aOrbiterC = ((aWandererH + RotL64(aScatter, 53U)) + RotL64(aCarry, 39U)) + 2312314528139448289U;
            aOrbiterI = (aWandererJ + RotL64(aCross, 5U)) + 3554037526469185237U;
            aOrbiterA = (aWandererB + RotL64(aPrevious, 43U)) + 405707755060974111U;
            aOrbiterF = ((aWandererF + RotL64(aScatter, 22U)) + 1862976326004007697U) + RotL64(aNonceWordB, 6U);
            aOrbiterJ = ((aWandererD + RotL64(aCross, 11U)) + 12992483065443288263U) + aOrbiterAssignSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 41U)) + 3793854946371595197U) + RotL64(aNonceWordA, 55U);
            aOrbiterK = (aWandererK + RotL64(aIngress, 35U)) + 4244007978867369382U;
            aOrbiterG = (aWandererC + RotL64(aPrevious, 19U)) + 10280867500312580308U;
            aOrbiterD = (((aWandererE + RotL64(aCross, 51U)) + RotL64(aCarry, 5U)) + 472563452959164242U) + aOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = (aWandererI + RotL64(aIngress, 24U)) + 12041770406895816553U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 6118634015704900486U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 13637107920449233307U;
            aOrbiterI = RotL64((aOrbiterI * 17712028184714868053U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 16673735670669318830U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 8602681273646630496U) ^ RotL64(aNonceWordD, 31U);
            aOrbiterJ = RotL64((aOrbiterJ * 6995213887710749241U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 7683264695930369476U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 9146674871199188218U;
            aOrbiterC = RotL64((aOrbiterC * 7403427067419261981U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 3012935612827493084U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 1259789268731661945U;
            aOrbiterF = RotL64((aOrbiterF * 2372843620327050137U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 5623690455471160780U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 18355567776031865462U;
            aOrbiterK = RotL64((aOrbiterK * 9553862670107886679U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 7705134893833304792U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 4435192506444773834U;
            aOrbiterD = RotL64((aOrbiterD * 5249651218395299501U), 29U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterB) + 6204683785806409075U) + aOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1]) + RotL64(aNonceWordC, 21U);
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 17886971535016484255U;
            aOrbiterE = RotL64((aOrbiterE * 6047216474762933535U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 4430578901091376829U) + aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 607557685798141547U;
            aOrbiterA = RotL64((aOrbiterA * 12342665567201483107U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 18258994761911545002U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 634391404805006992U) ^ aOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5761143438450180463U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 8528044138264666860U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 3867692060293315964U;
            aOrbiterG = RotL64((aOrbiterG * 8285164562893231087U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 8333438209201978886U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 1866656689936219099U;
            aOrbiterH = RotL64((aOrbiterH * 3935928308329865425U), 11U);
            //
            aIngress = RotL64(aOrbiterF, 11U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 37U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 6U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterJ, 11U)) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 56U) + aOrbiterJ) + RotL64(aOrbiterD, 51U)) + RotL64(aNonceWordF, 27U));
            aWandererK = aWandererK + (((RotL64(aCross, 19U) + RotL64(aOrbiterE, 19U)) + aOrbiterG) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 48U)) + aOrbiterK);
            aWandererE = aWandererE + (((RotL64(aIngress, 47U) + RotL64(aOrbiterD, 29U)) + aOrbiterI) + aWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterE, 39U)) + aOrbiterC);
            aWandererH = aWandererH + (((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterG, 3U)) + aWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 54U) + aOrbiterJ) + RotL64(aOrbiterK, 53U));
            aWandererF = aWandererF + ((RotL64(aIngress, 21U) + RotL64(aOrbiterK, 57U)) + aOrbiterH);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterC, 36U)) + aOrbiterH) + RotL64(aNonceWordG, 47U));
            aWandererD = aWandererD + ((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterD, 23U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (RotL64(aWandererC, 30U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + RotL64(aWandererJ, 35U);
            aCarry = aCarry + RotL64(aIngress, 26U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 13U) ^ RotL64(aNonceWordH, 21U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 25687U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31221U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 58U) ^ RotL64(aNonceWordF, 23U)) ^ RotL64(aNonceWordG, 3U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28773U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneD[((aIndex + 31486U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 6U) + RotL64(aIngress, 57U)) + (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererE + RotL64(aIngress, 41U)) + 7722279280863371124U;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 6U)) + 11584220561732385598U) + aOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 35U)) + RotL64(aCarry, 23U)) + 7834679350105534657U;
            aOrbiterC = (aWandererK + RotL64(aCross, 37U)) + 11347994382444180879U;
            aOrbiterG = (aWandererG + RotL64(aScatter, 51U)) + 9449903188047063431U;
            aOrbiterK = (((aWandererA + RotL64(aCross, 27U)) + RotL64(aCarry, 3U)) + 6516243976652795170U) + RotL64(aNonceWordA, 24U);
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 11U)) + 8420815253991184777U) + RotL64(aNonceWordB, 29U);
            aOrbiterD = (((aWandererB + RotL64(aIngress, 54U)) + RotL64(aCarry, 53U)) + 9081386852515170937U) + aOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = (aWandererC + RotL64(aScatter, 21U)) + 14375955191735286867U;
            aOrbiterJ = (aWandererJ + RotL64(aCross, 43U)) + 880757589768436072U;
            aOrbiterF = (aWandererF + RotL64(aPrevious, 23U)) + 3349856625725164229U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 7826309957607577207U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 8057435761214313635U;
            aOrbiterB = RotL64((aOrbiterB * 4718430712767038607U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 9565237500443303103U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 15893066735310588501U;
            aOrbiterG = RotL64((aOrbiterG * 8457633439171452397U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 3276844534476430842U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 6828644383891274120U;
            aOrbiterK = RotL64((aOrbiterK * 979580351653410157U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 2815676923011504251U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 5030251870850928417U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7075653570570819253U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 13464083008377887034U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 8994560761846897590U) ^ RotL64(aNonceWordF, 53U);
            aOrbiterD = RotL64((aOrbiterD * 9892839554658865143U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 8398813387154468736U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 8136429428340910892U;
            aOrbiterH = RotL64((aOrbiterH * 3348811490733577295U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 418587250696862341U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 4111667833838312094U;
            aOrbiterJ = RotL64((aOrbiterJ * 860949442143849147U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 6075478294190926371U) + RotL64(aNonceWordE, 25U);
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 2208124955874142264U;
            aOrbiterF = RotL64((aOrbiterF * 15741988616251072075U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 4726538724576443010U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 6524078248882840425U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9784875566721689069U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 14521003220464811621U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 16916247868211621303U;
            aOrbiterA = RotL64((aOrbiterA * 1911638054294853877U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 18207293125461843123U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 7722279280863371124U) ^ aOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14303108475807941791U), 35U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 43U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + RotL64(aOrbiterC, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((((RotL64(aCross, 35U) + RotL64(aOrbiterF, 51U)) + aOrbiterB) + RotL64(aNonceWordH, 21U)) + aWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterC, 56U)) + aOrbiterE);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterK, 39U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 10U) + RotL64(aOrbiterB, 19U)) + aOrbiterH) + RotL64(aCarry, 19U)) + aWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 27U) + aOrbiterH) + RotL64(aOrbiterI, 23U));
            aWandererC = aWandererC + ((RotL64(aIngress, 21U) + aOrbiterF) + RotL64(aOrbiterG, 60U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterJ, 47U)) + aOrbiterC) + RotL64(aNonceWordD, 35U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 3U) + RotL64(aOrbiterF, 35U)) + aOrbiterI);
            aWandererB = aWandererB ^ ((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterK, 41U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 48U) + aOrbiterD) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterD, 3U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 10U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 14U));
            aCarry = aCarry + RotL64(aWandererC, 47U);
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

void TwistExpander_BaseBall_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xA93581FF005BE027ULL + 0xAADF6DA9715692C4ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xC02347BF09BDA8B9ULL + 0xEF6006B9829EE5C5ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xF4BA3AC1D37E13D3ULL + 0xAAF49DA4D034FFF0ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xA55F982EE7548291ULL + 0x879650309869A466ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xBF6D5726980DCAF3ULL + 0xEF57421C27D8A190ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xB88E923E518550FFULL + 0xD4AA8D0B8A5BBC7FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x93D9013B161CD177ULL + 0xD7558F30A2F1F4F4ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xEA28E3EFD81A2D81ULL + 0xE6AE63BC6D0015B8ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 40U) ^ RotL64(aNonceWordH, 53U)) ^ RotL64(aNonceWordA, 27U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 4484U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4580U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 13U) ^ RotL64(aNonceWordG, 35U)) ^ RotL64(aNonceWordC, 43U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 3811U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((aIndex + 6U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 5U)) + (RotL64(aIngress, 41U) + RotL64(aCross, 28U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererC + RotL64(aScatter, 40U)) + RotL64(aCarry, 41U)) + 2177539223979303669U;
            aOrbiterG = (aWandererD + RotL64(aIngress, 5U)) + 3962004686551521471U;
            aOrbiterD = (((aWandererG + RotL64(aPrevious, 53U)) + 8457602312617147662U) + aOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1]) + RotL64(aNonceWordG, 27U);
            aOrbiterK = (aWandererI + RotL64(aCross, 27U)) + 18011802451816510632U;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 35U)) + 9046101759168876832U;
            aOrbiterC = ((aWandererK + RotL64(aCross, 47U)) + RotL64(aCarry, 13U)) + 11135620637431969597U;
            aOrbiterB = ((((aWandererE + RotL64(aIngress, 14U)) + RotL64(aCarry, 21U)) + 15913029940697999701U) + aOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1]) + RotL64(aNonceWordB, 53U);
            aOrbiterI = (aWandererF + RotL64(aScatter, 21U)) + 16304193109948135982U;
            aOrbiterF = (aWandererJ + RotL64(aIngress, 57U)) + 13208892298820080981U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 4182377898949419225U) + RotL64(aNonceWordC, 56U);
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 13970137023071326151U;
            aOrbiterD = RotL64((aOrbiterD * 9075061559681739865U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 8402396284835248583U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 8859190834060657829U;
            aOrbiterC = RotL64((aOrbiterC * 13552418608113716117U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 9760005337757990392U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 14108277760135744897U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4474681104256093885U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 12226316121949012350U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 3456392186754113960U;
            aOrbiterF = RotL64((aOrbiterF * 8704729827929941215U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 5004087958637038973U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 7176881295123125567U;
            aOrbiterA = RotL64((aOrbiterA * 15272157962928021009U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 10889800478505074438U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 13728832441482547824U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17588477761978646139U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 17345665880706866772U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 301139993853297566U;
            aOrbiterB = RotL64((aOrbiterB * 5812445396758354505U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 2061389844760610160U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterI) ^ 13631862266139238355U) ^ aOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1]) ^ RotL64(aNonceWordE, 29U);
            aOrbiterG = RotL64((aOrbiterG * 143613352104722701U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 10767186080827509622U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 4893486019456886013U;
            aOrbiterH = RotL64((aOrbiterH * 5194746459545610901U), 47U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterA, 5U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 19U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 48U));
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 54U) + RotL64(aOrbiterF, 53U)) + aOrbiterA);
            aWandererE = aWandererE + ((((RotL64(aIngress, 35U) + aOrbiterB) + RotL64(aOrbiterI, 23U)) + RotL64(aNonceWordD, 15U)) + aWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 42U)) + aOrbiterK) + aWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 13U) + aOrbiterC) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 57U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterK, 5U));
            aWandererI = aWandererI + (((RotL64(aIngress, 19U) + RotL64(aOrbiterA, 19U)) + aOrbiterH) + RotL64(aCarry, 13U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 50U) + RotL64(aOrbiterG, 48U)) + aOrbiterH) + RotL64(aNonceWordH, 3U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 41U) + aOrbiterD) + RotL64(aOrbiterF, 35U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 23U) + aOrbiterB) + RotL64(aOrbiterG, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (RotL64(aWandererA, 48U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + RotL64(aWandererE, 5U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 4U) ^ RotL64(aNonceWordB, 37U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 7907U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 6479U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 27U) ^ RotL64(aNonceWordH, 37U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 8269U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8032U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCross, 4U)) + (RotL64(aCarry, 35U) ^ RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (((aWandererD + RotL64(aCross, 3U)) + 2571116506511057880U) + aOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1]) + RotL64(aNonceWordE, 43U);
            aOrbiterK = (aWandererB + RotL64(aScatter, 43U)) + 13112435411509707292U;
            aOrbiterG = (aWandererG + RotL64(aIngress, 23U)) + 10403251762787357256U;
            aOrbiterE = (((aWandererE + RotL64(aPrevious, 58U)) + RotL64(aCarry, 43U)) + 8461951095541400405U) + RotL64(aNonceWordG, 11U);
            aOrbiterI = (aWandererA + RotL64(aIngress, 29U)) + 9890793478557463815U;
            aOrbiterB = ((aWandererI + RotL64(aCross, 11U)) + RotL64(aCarry, 13U)) + 3030229465991783707U;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 39U)) + RotL64(aCarry, 27U)) + 7273848154043719247U;
            aOrbiterF = (aWandererK + RotL64(aPrevious, 47U)) + 10681774862516028276U;
            aOrbiterH = ((aWandererH + RotL64(aIngress, 52U)) + 7105082755586853104U) + aOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 6588579345319551129U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 14616333550242386092U) ^ RotL64(aNonceWordH, 5U);
            aOrbiterG = RotL64((aOrbiterG * 2934574715879306337U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 15439666290229654921U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 3360304356760164799U) ^ aOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5164191920584106237U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 14438730801970761889U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 14515616787452085729U) ^ aOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2041601927968559821U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 4167853822635132419U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 8950982233003320239U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 887144270884244907U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 12391327853728029953U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 7100871010552394421U;
            aOrbiterH = RotL64((aOrbiterH * 16552349374101955967U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 15381697462381887944U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 6801677551341079401U;
            aOrbiterC = RotL64((aOrbiterC * 13325954438427340703U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 947011315719204867U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 6356920162398333481U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5566721941682667419U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 8910262020598577378U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 8778455415977526457U) ^ RotL64(aNonceWordF, 53U);
            aOrbiterB = RotL64((aOrbiterB * 4092470497616637283U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 5585696961453127223U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 9670655481681494412U;
            aOrbiterK = RotL64((aOrbiterK * 7863197168965036383U), 3U);
            //
            aIngress = RotL64(aOrbiterB, 47U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 14U));
            aIngress = aIngress + RotL64(aOrbiterA, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aCross, 30U) + RotL64(aOrbiterK, 23U)) + aOrbiterI) + aWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 41U) + aOrbiterF) + RotL64(aOrbiterA, 34U)) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 47U)) + aOrbiterF) + RotL64(aNonceWordA, 45U));
            aWandererB = aWandererB + ((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 3U)) + aOrbiterH);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterF, 53U));
            aWandererA = aWandererA + (((RotL64(aScatter, 21U) + RotL64(aOrbiterE, 12U)) + aOrbiterH) + RotL64(aNonceWordC, 60U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterC, 29U)) + aOrbiterB) + aWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 34U) + aOrbiterC) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 11U) + aOrbiterG) + RotL64(aOrbiterE, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererC, 6U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 4U) ^ RotL64(aNonceWordF, 19U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12628U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((aIndex + 11207U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 58U) ^ RotL64(aNonceWordH, 13U)) ^ RotL64(aNonceWordB, 21U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 15515U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 14758U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 47U) ^ RotL64(aCarry, 19U)) ^ (RotL64(aPrevious, 34U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererF + RotL64(aCross, 5U)) + 15910560457440369082U) + RotL64(aNonceWordC, 7U);
            aOrbiterA = (((aWandererA + RotL64(aIngress, 47U)) + RotL64(aCarry, 39U)) + 17953072986407436888U) + RotL64(aNonceWordG, 39U);
            aOrbiterC = (aWandererJ + RotL64(aScatter, 34U)) + 15446940721193538669U;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 13U)) + RotL64(aCarry, 3U)) + 3020785262774422009U;
            aOrbiterH = (((aWandererH + RotL64(aScatter, 57U)) + RotL64(aCarry, 57U)) + 7001288645424994404U) + aOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (aWandererE + RotL64(aPrevious, 51U)) + 13385250665458462689U;
            aOrbiterI = (aWandererG + RotL64(aIngress, 27U)) + 4841895644623005949U;
            aOrbiterB = ((aWandererC + RotL64(aCross, 39U)) + 13053476783239482065U) + aOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aIngress, 22U)) + 641996979335975244U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 16211238020928688299U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterG) ^ 12715448751323279480U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]) ^ RotL64(aNonceWordA, 22U);
            aOrbiterC = RotL64((aOrbiterC * 2116880429675303291U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 17784406727699995290U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 16626339815786580778U;
            aOrbiterG = RotL64((aOrbiterG * 13940754474750138041U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 9035070625716345139U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 6085848172494001945U;
            aOrbiterD = RotL64((aOrbiterD * 10405728912339646693U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 1177103851507561053U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 2281901691017816407U;
            aOrbiterA = RotL64((aOrbiterA * 3142197009403602497U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 9040984343694325070U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 13334258224023902365U;
            aOrbiterH = RotL64((aOrbiterH * 4782523727707164869U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 1079824790138592518U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 14024082692012948652U;
            aOrbiterK = RotL64((aOrbiterK * 3219489374333737903U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 2966776524421278970U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 5510281854029308547U;
            aOrbiterI = RotL64((aOrbiterI * 9275402927591867297U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 7126632329316720048U) + RotL64(aNonceWordF, 51U);
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 1476827035602733472U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2217671289726794033U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 6470212302133184965U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 4172257438373147415U;
            aOrbiterF = RotL64((aOrbiterF * 4449314239630366533U), 57U);
            //
            aIngress = RotL64(aOrbiterK, 42U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterD, 43U)) + aOrbiterF);
            aWandererK = aWandererK + (((RotL64(aIngress, 29U) + RotL64(aOrbiterC, 18U)) + aOrbiterG) + RotL64(aCarry, 13U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 13U) + aOrbiterB) + RotL64(aOrbiterC, 5U));
            aWandererC = aWandererC + (((RotL64(aScatter, 34U) + RotL64(aOrbiterK, 47U)) + aOrbiterI) + aWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterA, 51U)) + aOrbiterI) + RotL64(aNonceWordH, 53U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterH, 30U)) + aOrbiterK) + RotL64(aCarry, 29U)) + aWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 57U) + aOrbiterA) + RotL64(aOrbiterG, 23U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 11U)) + aOrbiterB);
            aWandererG = aWandererG ^ (((RotL64(aCross, 38U) + aOrbiterH) + RotL64(aOrbiterB, 35U)) + RotL64(aNonceWordB, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 58U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 3U) ^ RotL64(aNonceWordE, 58U)) ^ RotL64(aNonceWordH, 23U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 17612U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18986U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 3U) ^ RotL64(aNonceWordC, 37U)) ^ RotL64(aNonceWordA, 19U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18434U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 18160U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 60U) ^ RotL64(aCross, 23U)) ^ (RotL64(aIngress, 37U) + RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererK + RotL64(aIngress, 47U)) + RotL64(aCarry, 21U)) + 12809562813316740345U;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 12U)) + RotL64(aCarry, 51U)) + 17084212535326321199U;
            aOrbiterD = ((aWandererB + RotL64(aCross, 21U)) + RotL64(aCarry, 29U)) + 16074921689983846769U;
            aOrbiterJ = (aWandererG + RotL64(aScatter, 39U)) + 14027986153007120145U;
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 5U)) + 7633455951809250227U) + aOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aCross, 43U)) + 340989348513370174U) + RotL64(aNonceWordB, 53U);
            aOrbiterG = (aWandererC + RotL64(aScatter, 58U)) + 5307820377645020116U;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 35U)) + 5605285015771527274U) + aOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aScatter, 53U)) + 5293500434746182790U) + RotL64(aNonceWordG, 45U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 7263156475892261811U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 10672879570907433005U;
            aOrbiterD = RotL64((aOrbiterD * 2506338667179450741U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 16659226780900986107U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 9774892622769850665U) ^ aOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7487477727543183211U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 10728057184108279042U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 5032485856947407217U;
            aOrbiterG = RotL64((aOrbiterG * 16651577903809154285U), 57U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterG) + 14642241075374862345U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]) + RotL64(aNonceWordA, 19U);
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 8386481273395203518U;
            aOrbiterK = RotL64((aOrbiterK * 11649977733867003445U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 2874153265304098104U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 11519900149177261000U) ^ aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2010158758971864505U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 8885690878540115768U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 4482143389870987714U) ^ RotL64(aNonceWordC, 25U);
            aOrbiterF = RotL64((aOrbiterF * 7105332459437434281U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 17469068567801886615U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 5121422018622394837U;
            aOrbiterA = RotL64((aOrbiterA * 14823827133212643467U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 3130788210672745618U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 6139244627510113216U;
            aOrbiterC = RotL64((aOrbiterC * 2640754184921507389U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 10488511756324474710U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 1760223670304953696U;
            aOrbiterB = RotL64((aOrbiterB * 4007062295003769311U), 39U);
            //
            aIngress = RotL64(aOrbiterF, 23U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 12U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterG, 51U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 51U) + aOrbiterK) + RotL64(aOrbiterB, 35U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 37U) + aOrbiterJ) + RotL64(aOrbiterC, 26U)) + RotL64(aCarry, 57U)) + aWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 14U) + RotL64(aOrbiterK, 39U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 47U)) + aOrbiterF) + RotL64(aNonceWordF, 46U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterC, 43U)) + aOrbiterH);
            aWandererB = aWandererB + ((((RotL64(aScatter, 21U) + RotL64(aOrbiterD, 30U)) + aOrbiterF) + RotL64(aCarry, 35U)) + RotL64(aNonceWordE, 61U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterF, 19U)) + aWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 28U) + RotL64(aOrbiterG, 57U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 54U));
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + RotL64(aWandererE, 19U);
            aCarry = aCarry + RotL64(aIngress, 6U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 57U) ^ RotL64(aNonceWordE, 13U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 26667U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((aIndex + 25295U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 57U) ^ RotL64(aNonceWordA, 35U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22611U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24284U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 13U) + RotL64(aIngress, 29U)) ^ (RotL64(aPrevious, 57U) ^ RotL64(aCross, 42U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererB + RotL64(aScatter, 46U)) + 4259993311776766595U;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 57U)) + 2857813330021126753U) + aOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (((aWandererD + RotL64(aPrevious, 11U)) + RotL64(aCarry, 39U)) + 1345396841329442896U) + RotL64(aNonceWordA, 39U);
            aOrbiterG = ((aWandererA + RotL64(aCross, 5U)) + 320992148982301024U) + aOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aScatter, 29U)) + RotL64(aCarry, 11U)) + 5619109532065293074U;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 23U)) + RotL64(aCarry, 53U)) + 10380157329426706345U;
            aOrbiterD = (aWandererG + RotL64(aPrevious, 40U)) + 12449831150625409695U;
            aOrbiterK = (aWandererC + RotL64(aCross, 53U)) + 7847096607042268396U;
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 19U)) + 11707184096803214678U) + RotL64(aNonceWordB, 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 9893643746186827088U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 333687403830908774U;
            aOrbiterJ = RotL64((aOrbiterJ * 17911256836121454271U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 13837360705077441580U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 4367119682175710689U) ^ RotL64(aNonceWordC, 21U);
            aOrbiterB = RotL64((aOrbiterB * 10295744669174603401U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 1193493435041306784U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 15062951612027370606U;
            aOrbiterK = RotL64((aOrbiterK * 2509383510565136549U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 16000173839235429105U) + aOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 15294482444605409961U;
            aOrbiterH = RotL64((aOrbiterH * 1031800997944302665U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 5720749055549773527U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 17248674962996093668U;
            aOrbiterE = RotL64((aOrbiterE * 15730637462755795591U), 53U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterH) + 16956840483882091059U) + aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1]) + RotL64(aNonceWordF, 57U);
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 9637715107943515594U) ^ aOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8878362378343603463U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 7147495779349862274U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 7508890985889484275U;
            aOrbiterD = RotL64((aOrbiterD * 17728368447504622035U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 4407738164617959366U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 17027017782352660454U;
            aOrbiterF = RotL64((aOrbiterF * 417183060881259295U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 3174658601748235285U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 9779053567370714831U;
            aOrbiterC = RotL64((aOrbiterC * 6383245776181968033U), 5U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterC, 54U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 52U) + aOrbiterD) + RotL64(aOrbiterG, 19U));
            aWandererB = aWandererB + (((RotL64(aCross, 29U) + aOrbiterJ) + RotL64(aOrbiterG, 34U)) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterD, 13U)) + aOrbiterF) + RotL64(aNonceWordD, 51U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterC, 51U)) + aOrbiterE);
            aWandererC = aWandererC ^ ((RotL64(aCross, 35U) + aOrbiterF) + RotL64(aOrbiterE, 29U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 43U)) + aOrbiterC) + aWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 58U) + RotL64(aOrbiterJ, 23U)) + aOrbiterB);
            aWandererG = aWandererG + ((((RotL64(aScatter, 47U) + aOrbiterF) + RotL64(aOrbiterH, 60U)) + RotL64(aCarry, 47U)) + RotL64(aNonceWordH, 26U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 3U)) + aOrbiterK) + aWandererUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 60U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + RotL64(aWandererG, 10U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 27U) ^ RotL64(aNonceWordB, 37U)) ^ RotL64(aNonceWordE, 19U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30118U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30892U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 11U) ^ RotL64(aNonceWordC, 20U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28179U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28861U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 27U)) ^ (RotL64(aIngress, 57U) + RotL64(aCarry, 40U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererF + RotL64(aCross, 4U)) + RotL64(aCarry, 11U)) + 10805654776556844351U;
            aOrbiterI = (aWandererG + RotL64(aPrevious, 43U)) + 582794182442795335U;
            aOrbiterJ = (aWandererE + RotL64(aIngress, 23U)) + 2858343650974681068U;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 19U)) + 8189584049022064284U) + aOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = ((aWandererK + RotL64(aIngress, 39U)) + RotL64(aCarry, 47U)) + 1565100751996962893U;
            aOrbiterD = ((aWandererB + RotL64(aCross, 52U)) + 8062028016947611891U) + RotL64(aNonceWordA, 29U);
            aOrbiterE = ((aWandererI + RotL64(aScatter, 29U)) + RotL64(aCarry, 21U)) + 8280504280578451745U;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 11U)) + 11326869194491655350U) + RotL64(aNonceWordC, 49U);
            aOrbiterG = ((aWandererD + RotL64(aScatter, 57U)) + 1671695656567777163U) + aOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 2349843105293943452U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 13015545152052004254U;
            aOrbiterJ = RotL64((aOrbiterJ * 1316662811685429983U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 16703354404749291869U) + RotL64(aNonceWordB, 17U);
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 8713231044374305801U;
            aOrbiterK = RotL64((aOrbiterK * 9242480982197688625U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 11118401674497783533U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 14857556493734710364U;
            aOrbiterE = RotL64((aOrbiterE * 3452566050389715195U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 12953419670951660965U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 12666121730825089017U;
            aOrbiterH = RotL64((aOrbiterH * 14049925256934142519U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 11075249639473053423U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 9374217688244187867U) ^ aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5261156325627117877U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 17608340953291367867U) + aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 13159437499327086340U;
            aOrbiterF = RotL64((aOrbiterF * 4882100944453534805U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 4304700511322366815U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 10172544755256706767U;
            aOrbiterC = RotL64((aOrbiterC * 4013006212154771797U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 17340067939877432472U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 14130447570008179105U;
            aOrbiterD = RotL64((aOrbiterD * 8178075071208718915U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 2652532710498072378U) + RotL64(aNonceWordF, 57U);
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 10384945384238518296U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17137694272394304045U), 53U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterD, 43U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + RotL64(aOrbiterI, 30U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 48U)) + aOrbiterK) + RotL64(aNonceWordD, 22U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 58U) + RotL64(aOrbiterK, 29U)) + aOrbiterH);
            aWandererF = aWandererF ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterD, 21U)) + aOrbiterI);
            aWandererI = aWandererI + ((((RotL64(aScatter, 19U) + aOrbiterE) + RotL64(aOrbiterF, 43U)) + RotL64(aCarry, 57U)) + aWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterE, 11U)) + aOrbiterD) + aWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 23U) + RotL64(aOrbiterF, 57U)) + aOrbiterG);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterC, 38U)) + aOrbiterK);
            aWandererE = aWandererE + (((RotL64(aPrevious, 10U) + aOrbiterK) + RotL64(aOrbiterD, 53U)) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 27U) + aOrbiterC) + RotL64(aOrbiterE, 5U)) + RotL64(aNonceWordG, 7U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 20U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererJ, 35U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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

void TwistExpander_BaseBall_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xACF1EBA2D8A6F4BBULL + 0x8D392EA904885363ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x961F21E453FCD8E1ULL + 0xBAA7F115BF7E2F12ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x87BCCB03AA10607DULL + 0xE17BA032AA9BEEEAULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB4225AD9F1B8A5EBULL + 0x926FC9284D427802ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xB5A540FEC2CC3A29ULL + 0xC1E82D361CF6F084ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xF5CDE31ACB00BDEBULL + 0xF3B2EB7E315D2FBBULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xFC4303FB118018DFULL + 0x9149BA8162814544ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x8E30350E8E895FC1ULL + 0x83F2B6D5C7A12FE6ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 3U) ^ RotL64(aNonceWordH, 47U)) ^ RotL64(aNonceWordD, 37U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 4199U)) & S_BLOCK1], 28U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 1329U)) & W_KEY1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 36U) ^ RotL64(aNonceWordE, 47U));
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 4573U)) & W_KEY1], 23U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 4164U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aIngress, 21U)) + (RotL64(aCarry, 5U) + RotL64(aPrevious, 38U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterH = (aWandererF + RotL64(aPrevious, 5U)) + 16124889768301047791U;
            aOrbiterB = (((aWandererJ + RotL64(aIngress, 51U)) + RotL64(aCarry, 35U)) + 11912338587186717280U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = ((((aWandererC + RotL64(aScatter, 36U)) + RotL64(aCarry, 23U)) + 8594012868813114354U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1]) + RotL64(aNonceWordE, 7U);
            aOrbiterK = ((aWandererH + RotL64(aCross, 29U)) + RotL64(aCarry, 57U)) + 18281043566156682815U;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 13U)) + 16853106130200942302U) + RotL64(aNonceWordD, 54U);
            aOrbiterD = (aWandererK + RotL64(aCross, 57U)) + 2611212958619673086U;
            aOrbiterF = (aWandererE + RotL64(aIngress, 19U)) + 18039472325066855180U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 14495785571345122046U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 4556063793412832418U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13166927543135467627U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 14896419970271244358U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 880028529183500036U;
            aOrbiterJ = RotL64((aOrbiterJ * 14228281807461251361U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 2379557167489415783U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 11854373946064529806U;
            aOrbiterD = RotL64((aOrbiterD * 150755294320438887U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 1487252775956449964U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 12777924204511625545U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1366019527386994789U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 15998631485222477969U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 8864212892296191613U;
            aOrbiterH = RotL64((aOrbiterH * 579242788050369815U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 17069347835763226743U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterD) ^ 7443008171694679791U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1]) ^ RotL64(aNonceWordG, 41U);
            aOrbiterK = RotL64((aOrbiterK * 748894368884566607U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 17334256152350782002U) + RotL64(aNonceWordC, 37U);
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 8986626119086556393U;
            aOrbiterB = RotL64((aOrbiterB * 2258172145924120235U), 5U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterJ, 58U);
            aIngress = aIngress + (RotL64(aOrbiterB, 37U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 5U) + aOrbiterJ) + RotL64(aOrbiterB, 58U)) + RotL64(aNonceWordA, 23U));
            aWandererC = aWandererC ^ ((((RotL64(aScatter, 39U) + aOrbiterF) + RotL64(aOrbiterJ, 51U)) + RotL64(aNonceWordF, 47U)) + aPhaseAWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterI, 3U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterF, 27U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 20U) + RotL64(aOrbiterI, 35U)) + aOrbiterK) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterD, 19U)) + aOrbiterH);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 53U) + aOrbiterJ) + RotL64(aOrbiterH, 43U)) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 6U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 34U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 43U) ^ RotL64(aNonceWordB, 3U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9728U)) & S_BLOCK1], 27U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 9007U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 13U) ^ RotL64(aNonceWordD, 57U));
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 7584U)) & W_KEY1], 4U) ^ RotL64(aKeyRowReadB[((aIndex + 9155U)) & W_KEY1], 27U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 18U) + RotL64(aCarry, 5U)) ^ (RotL64(aCross, 39U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterC = (aWandererH + RotL64(aCross, 39U)) + 3561491146322798260U;
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 58U)) + 7075025056181885339U) + aPhaseAOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 19U)) + RotL64(aCarry, 57U)) + 9230910887904171613U;
            aOrbiterH = (((aWandererF + RotL64(aScatter, 27U)) + RotL64(aCarry, 37U)) + 4119781172609908917U) + RotL64(aNonceWordH, 41U);
            aOrbiterK = ((aWandererB + RotL64(aCross, 47U)) + 17155609083870983149U) + aPhaseAOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 3U)) + 2423018561430181695U) + RotL64(aNonceWordF, 45U);
            aOrbiterE = ((aWandererK + RotL64(aIngress, 11U)) + RotL64(aCarry, 5U)) + 12957280305617615744U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 2461704174772065813U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 7907123257849391997U) ^ RotL64(aNonceWordE, 21U);
            aOrbiterA = RotL64((aOrbiterA * 9416171962847312179U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 7257868138318960007U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 16425903703085702285U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7996935869077231999U), 23U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterD) + 2990822664594079467U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]) + RotL64(aNonceWordD, 52U);
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 5654819006718953817U;
            aOrbiterH = RotL64((aOrbiterH * 4465096036756887801U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 12183676471235678779U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 15026286960542123922U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17199049329995315279U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 12169080607071830522U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 2906296852254787499U;
            aOrbiterK = RotL64((aOrbiterK * 6754514406846040163U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 3029858695410344584U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 14406410317495954566U;
            aOrbiterD = RotL64((aOrbiterD * 9663780721657983421U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 11048818178401163861U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 13622063920319445043U;
            aOrbiterE = RotL64((aOrbiterE * 2516025554421589857U), 5U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterC, 11U);
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + RotL64(aOrbiterH, 34U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aCross, 54U) + aOrbiterJ) + RotL64(aOrbiterC, 11U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterD, 51U)) + aOrbiterK);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterH, 43U)) + RotL64(aNonceWordA, 31U)) + aPhaseAWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterE, 22U)) + aOrbiterK) + RotL64(aNonceWordC, 29U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterA, 37U)) + RotL64(aCarry, 11U)) + aPhaseAWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 5U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 57U)) + aOrbiterA) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererC, 30U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 39U) ^ RotL64(aNonceWordH, 13U)) ^ RotL64(aNonceWordA, 3U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 11780U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12739U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 41U) ^ RotL64(aNonceWordD, 29U));
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 11927U)) & W_KEY1], 57U) ^ RotL64(aKeyRowReadB[((aIndex + 14146U)) & W_KEY1], 14U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 27U) ^ RotL64(aCarry, 13U)) + (RotL64(aCross, 57U) ^ RotL64(aPrevious, 40U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 21U)) + 12262991801139086177U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aCross, 37U)) + 7963038771924890197U) + RotL64(aNonceWordD, 51U);
            aOrbiterC = (((aWandererG + RotL64(aScatter, 56U)) + RotL64(aCarry, 21U)) + 15540520327933568896U) + RotL64(aNonceWordC, 9U);
            aOrbiterD = (aWandererI + RotL64(aPrevious, 11U)) + 8745565892055020722U;
            aOrbiterB = ((aWandererK + RotL64(aCross, 43U)) + RotL64(aCarry, 39U)) + 16619329199683755286U;
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 29U)) + RotL64(aCarry, 3U)) + 10865705026433867260U;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 3U)) + 2743368697984518059U) + aPhaseAOrbiterAssignSaltE[((aIndex + 24U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 5556006271515473135U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 5355833281353498588U;
            aOrbiterC = RotL64((aOrbiterC * 4190140212757841511U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 8313616108963479829U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 16657121016801866434U;
            aOrbiterG = RotL64((aOrbiterG * 331533349428472477U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 16532226425013000833U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 5800465874932467232U;
            aOrbiterJ = RotL64((aOrbiterJ * 5966395771690704577U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 17882948163883121328U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 15029375310296563175U) ^ RotL64(aNonceWordH, 7U);
            aOrbiterD = RotL64((aOrbiterD * 17021415832288477713U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 10170682648007918739U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 11829089574189398773U) ^ RotL64(aNonceWordB, 27U);
            aOrbiterB = RotL64((aOrbiterB * 15755874363488568849U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 1746524867389196322U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 10217423427886742775U;
            aOrbiterK = RotL64((aOrbiterK * 9166162099575333519U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 1338457710729082656U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 1319981417675542556U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9518448254565489715U), 47U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterD, 35U);
            aIngress = aIngress + (RotL64(aOrbiterB, 18U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 46U) + aOrbiterB) + RotL64(aOrbiterJ, 23U)) + aPhaseAWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 3U) + aOrbiterE) + RotL64(aOrbiterB, 50U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 27U) + aOrbiterK) + RotL64(aOrbiterD, 39U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterJ, 57U)) + RotL64(aNonceWordF, 53U));
            aWandererC = aWandererC + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 29U)) + aOrbiterD) + RotL64(aCarry, 19U)) + RotL64(aNonceWordG, 38U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 39U) + aOrbiterE) + RotL64(aOrbiterK, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 10U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 29U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 23U) ^ RotL64(aNonceWordB, 39U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 17387U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17954U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 11U) ^ RotL64(aNonceWordC, 39U)) ^ RotL64(aNonceWordE, 21U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20859U)) & S_BLOCK1], 57U) ^ RotL64(mSource[((aIndex + 19264U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 10U) + RotL64(aPrevious, 35U)) ^ (RotL64(aCross, 23U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 47U)) + 3970829908171131502U) + aPhaseAOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = ((aWandererH + RotL64(aCross, 41U)) + RotL64(aCarry, 19U)) + 7040283759419531991U;
            aOrbiterE = (aWandererB + RotL64(aIngress, 29U)) + 11856292169397052901U;
            aOrbiterI = (aWandererC + RotL64(aScatter, 5U)) + 819598588791819022U;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 13U)) + 2176451710970866848U) + RotL64(aNonceWordC, 12U);
            aOrbiterF = ((aWandererD + RotL64(aScatter, 60U)) + RotL64(aCarry, 41U)) + 6454704928613390494U;
            aOrbiterC = ((((aWandererK + RotL64(aPrevious, 53U)) + RotL64(aCarry, 57U)) + 11792122387218053841U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1]) + RotL64(aNonceWordG, 7U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 9254780213489752211U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 16591812589999846482U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5425771603523423167U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 1471246223935074832U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 1424843083106386453U;
            aOrbiterF = RotL64((aOrbiterF * 15020536982657410783U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 1856469958050891629U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 6331743690452052712U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15327924647897459645U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 10351075711345476487U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 9518585245330480185U;
            aOrbiterG = RotL64((aOrbiterG * 3792179827396760391U), 23U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterC) + 17787514620244712033U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1]) + RotL64(aNonceWordA, 15U);
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 14182328067398162557U;
            aOrbiterH = RotL64((aOrbiterH * 18107337388659070197U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 12798088948801072444U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 9563215159275202323U;
            aOrbiterI = RotL64((aOrbiterI * 7058145016617349141U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 9904919772580498232U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterG) ^ 16579777394992143043U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1]) ^ RotL64(aNonceWordD, 49U);
            aOrbiterC = RotL64((aOrbiterC * 10516761340320196661U), 35U);
            //
            aIngress = RotL64(aOrbiterH, 57U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterG, 46U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterC, 37U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterC, 41U)) + aOrbiterH) + RotL64(aNonceWordB, 43U));
            aWandererD = aWandererD + (((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 27U)) + aOrbiterC) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 56U) + aOrbiterE) + RotL64(aOrbiterH, 48U));
            aWandererH = aWandererH + ((((RotL64(aCross, 5U) + RotL64(aOrbiterI, 11U)) + aOrbiterE) + RotL64(aNonceWordE, 41U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 11U) + aOrbiterF) + RotL64(aOrbiterC, 3U));
            aWandererK = aWandererK + (((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 19U)) + aOrbiterK) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterK, 57U)) + aOrbiterG) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 12U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 39U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 57U) ^ RotL64(aNonceWordE, 13U)) ^ RotL64(aNonceWordH, 43U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 25850U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22152U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 39U) ^ RotL64(aNonceWordB, 23U)) ^ RotL64(aNonceWordG, 5U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25035U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26952U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 19U)) + (RotL64(aCross, 50U) + RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterC = ((aWandererG + RotL64(aScatter, 26U)) + 9751314027302668907U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aCross, 11U)) + 12175450995523107056U;
            aOrbiterF = (aWandererA + RotL64(aIngress, 39U)) + 17519694958730119552U;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 19U)) + RotL64(aCarry, 11U)) + 9093525527925682263U;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 5U)) + 3713831321786810138U) + RotL64(aNonceWordD, 61U);
            aOrbiterG = ((((aWandererI + RotL64(aCross, 57U)) + RotL64(aCarry, 57U)) + 10108355209191835040U) + aPhaseAOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1]) + RotL64(aNonceWordF, 47U);
            aOrbiterI = ((aWandererF + RotL64(aIngress, 51U)) + RotL64(aCarry, 37U)) + 12956307447311314768U;
            //
            aOrbiterC = (((aOrbiterC + aOrbiterK) + 1904298513945877359U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1]) + RotL64(aNonceWordG, 53U);
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 4658049993308574460U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10482422152074338611U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 9826333658248851902U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 12058666914724365134U;
            aOrbiterC = RotL64((aOrbiterC * 964233873188373939U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 2516574707110528099U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 13335308331049750235U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5880227828760598587U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 8230749255538495304U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 16536559486797811486U) ^ RotL64(aNonceWordA, 59U);
            aOrbiterK = RotL64((aOrbiterK * 7097036838156464969U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 12387639130570188998U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 8459259798142872020U;
            aOrbiterE = RotL64((aOrbiterE * 8001346480955847013U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 16083784052002800300U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 1957284290736468379U;
            aOrbiterG = RotL64((aOrbiterG * 5046501301740813065U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 7349538179311335863U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 16395170077006105258U;
            aOrbiterI = RotL64((aOrbiterI * 4230485452156662763U), 19U);
            //
            aIngress = RotL64(aOrbiterK, 27U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 18U));
            aIngress = aIngress + RotL64(aOrbiterC, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 19U) + aOrbiterH) + RotL64(aOrbiterE, 38U)) + aPhaseAWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 13U) + RotL64(aOrbiterI, 5U)) + aOrbiterF) + RotL64(aNonceWordH, 56U)) + aPhaseAWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 41U) + aOrbiterG) + RotL64(aOrbiterF, 11U)) + RotL64(aCarry, 47U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterF, 21U)) + aOrbiterC);
            aWandererE = aWandererE + ((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterC, 51U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterK, 27U)) + aOrbiterE) + RotL64(aNonceWordE, 51U));
            aWandererA = aWandererA + (((RotL64(aIngress, 26U) + aOrbiterG) + RotL64(aOrbiterK, 57U)) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 10U));
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 27U);
            aCarry = aCarry + RotL64(aIngress, 50U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 46U) ^ RotL64(aNonceWordE, 35U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30701U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((aIndex + 32339U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 3U) ^ RotL64(aNonceWordA, 39U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29082U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27955U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 18U)) + (RotL64(aCross, 57U) + RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 3U)) + 6342299552323486695U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = (((aWandererF + RotL64(aIngress, 41U)) + RotL64(aCarry, 51U)) + 12692748514781367538U) + RotL64(aNonceWordC, 29U);
            aOrbiterI = (((aWandererB + RotL64(aScatter, 20U)) + RotL64(aCarry, 35U)) + 8202639945493229155U) + RotL64(aNonceWordA, 48U);
            aOrbiterA = (((aWandererD + RotL64(aCross, 13U)) + RotL64(aCarry, 21U)) + 4439975701793231639U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aPrevious, 35U)) + 16774235182859553759U;
            aOrbiterJ = (aWandererE + RotL64(aScatter, 29U)) + 8764155413335405667U;
            aOrbiterG = (aWandererJ + RotL64(aIngress, 47U)) + 7167848811974967685U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 16768278912125334220U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 9090838954826296201U;
            aOrbiterI = RotL64((aOrbiterI * 5459329624017272077U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 7644075729758006298U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 17326182797908071215U;
            aOrbiterD = RotL64((aOrbiterD * 2408330168749256075U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 16158809721888137555U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 8029938783858263694U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12628072435324195483U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 8716553521415553404U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 7012599977009208840U) ^ RotL64(aNonceWordB, 43U);
            aOrbiterG = RotL64((aOrbiterG * 8775355876188948851U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 13250558696578541499U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 13705957059101025396U;
            aOrbiterK = RotL64((aOrbiterK * 16889495686487056367U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 2796775206291902461U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 13741676263512390669U;
            aOrbiterA = RotL64((aOrbiterA * 10455782033465595947U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 1691908360612389252U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 4114939415206031540U) ^ RotL64(aNonceWordH, 37U);
            aOrbiterE = RotL64((aOrbiterE * 2797401802892718297U), 13U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 29U);
            aIngress = aIngress + (RotL64(aOrbiterD, 21U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterA, 58U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 12U) + aOrbiterJ) + RotL64(aOrbiterE, 40U)) + RotL64(aNonceWordG, 27U));
            aWandererI = aWandererI + (((RotL64(aCross, 41U) + aOrbiterJ) + RotL64(aOrbiterA, 29U)) + aPhaseAWandererUpdateSaltF[((aIndex + 22U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 27U) + aOrbiterI) + RotL64(aOrbiterK, 5U));
            aWandererB = aWandererB + (((RotL64(aScatter, 35U) + RotL64(aOrbiterG, 13U)) + aOrbiterI) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterD, 47U)) + aOrbiterA);
            aWandererD = aWandererD + (((((RotL64(aPrevious, 19U) + RotL64(aOrbiterI, 57U)) + aOrbiterJ) + RotL64(aCarry, 13U)) + RotL64(aNonceWordF, 53U)) + aPhaseAWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterE, 21U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 52U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 47U);
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

void TwistExpander_BaseBall_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xC277E7D0622C643DULL + 0xFDA29A85F8849D7AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xABA326A360051FD7ULL + 0xB479FFA2193DC9A3ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xC6E4234D5F591915ULL + 0xCB0C4717EF32B599ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB8D909476CB35B75ULL + 0x8F9F0882C21050F8ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xFE99E4587EAACB73ULL + 0xD91609D6758D615CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xF00E4E9F7B6FC65DULL + 0xF725743A0625B969ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xFCD6EDDBF22E52F1ULL + 0xF5B2C464FD4107FAULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xF2450BAC308E82FDULL + 0xDB1E4921A5E8DF17ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 57U) ^ RotL64(aNonceWordC, 41U)) ^ RotL64(aNonceWordB, 11U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 3645U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2582U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 27U) ^ RotL64(aNonceWordF, 37U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4811U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((aIndex + 513U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 36U) + RotL64(aCross, 5U)) ^ (RotL64(aCarry, 53U) ^ RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterE = (((aWandererC + RotL64(aScatter, 60U)) + RotL64(aCarry, 5U)) + 10726035965553989335U) + aPhaseBOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = ((aWandererI + RotL64(aCross, 41U)) + 967354339530195662U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 5U)) + RotL64(aCarry, 19U)) + 10834593005478605624U;
            aOrbiterF = (((aWandererD + RotL64(aPrevious, 27U)) + RotL64(aCarry, 47U)) + 1012888282838656933U) + RotL64(aNonceWordC, 22U);
            aOrbiterB = ((aWandererE + RotL64(aCross, 19U)) + 15283530351725183253U) + RotL64(aNonceWordA, 59U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 11724495956731703750U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 4288330117317505776U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2738997410474076757U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 10894778070022873473U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterF) ^ 15563886747621617467U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1]) ^ RotL64(aNonceWordF, 27U);
            aOrbiterE = RotL64((aOrbiterE * 17884709931569040065U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 11182488628562891937U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 10420140066310588580U) ^ RotL64(aNonceWordD, 11U);
            aOrbiterF = RotL64((aOrbiterF * 13898299782819948719U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 11775138062167543111U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 16545391898578161683U;
            aOrbiterC = RotL64((aOrbiterC * 14588306527161321535U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 1550144656312299266U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 14903504853138279883U;
            aOrbiterB = RotL64((aOrbiterB * 8003033561266164387U), 11U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterC, 50U);
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterC, 51U)) + RotL64(aCarry, 13U)) + aPhaseBWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 11U) + aOrbiterE) + RotL64(aOrbiterJ, 40U)) + aPhaseBWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 34U) + RotL64(aOrbiterB, 13U)) + aOrbiterE) + RotL64(aNonceWordG, 29U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterF, 5U)) + aOrbiterC);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 19U) + aOrbiterJ) + RotL64(aOrbiterB, 23U)) + RotL64(aCarry, 51U)) + RotL64(aNonceWordH, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + RotL64(aWandererE, 26U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 3U) ^ RotL64(aNonceWordA, 24U)) ^ RotL64(aNonceWordE, 47U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9399U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((aIndex + 5966U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 48U) ^ RotL64(aNonceWordH, 13U)) ^ RotL64(aNonceWordC, 37U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8702U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10071U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 21U) ^ RotL64(aIngress, 5U)) ^ (RotL64(aCross, 36U) + RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterK = ((((aWandererB + RotL64(aScatter, 43U)) + RotL64(aCarry, 35U)) + 13053031069776604052U) + aPhaseBOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1]) + RotL64(aNonceWordE, 27U);
            aOrbiterA = (aWandererJ + RotL64(aIngress, 3U)) + 1331396630251085122U;
            aOrbiterD = ((aWandererI + RotL64(aCross, 11U)) + RotL64(aCarry, 51U)) + 15879286043343942393U;
            aOrbiterG = ((((aWandererA + RotL64(aPrevious, 53U)) + RotL64(aCarry, 19U)) + 13590365633321406830U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1]) + RotL64(aNonceWordF, 9U);
            aOrbiterE = (aWandererE + RotL64(aIngress, 20U)) + 14569235423040242618U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 11397370636618371560U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 3455933494593971847U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13051161161405358793U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 1307153376443784593U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 10688618762584786871U) ^ RotL64(aNonceWordG, 14U);
            aOrbiterE = RotL64((aOrbiterE * 9503823896874842411U), 5U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterD) + 17746248451153600096U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]) + RotL64(aNonceWordC, 23U);
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 8512568600755410158U;
            aOrbiterK = RotL64((aOrbiterK * 16648320170768234063U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 8950230550112591092U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 17790968369472845496U;
            aOrbiterA = RotL64((aOrbiterA * 5104988920132008913U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 12583323865381967534U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 11243927099685293887U;
            aOrbiterG = RotL64((aOrbiterG * 12867003042486433971U), 51U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterK, 46U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + RotL64(aOrbiterE, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterK, 11U)) + aOrbiterA) + aPhaseBWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 21U) + aOrbiterG) + RotL64(aOrbiterK, 30U)) + RotL64(aCarry, 51U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 29U) + aOrbiterD) + RotL64(aOrbiterE, 19U)) + aPhaseBWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 58U) + RotL64(aOrbiterE, 57U)) + aOrbiterK) + RotL64(aCarry, 23U)) + RotL64(aNonceWordA, 15U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 13U) + aOrbiterK) + RotL64(aOrbiterD, 47U)) + RotL64(aNonceWordD, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererB, 11U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 58U) ^ RotL64(aNonceWordC, 27U)) ^ RotL64(aNonceWordD, 41U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 14021U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 12301U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 3U) ^ RotL64(aNonceWordB, 27U)) ^ RotL64(aNonceWordE, 57U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12892U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneC[((aIndex + 12694U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 34U) ^ RotL64(aIngress, 3U)) + (RotL64(aCross, 51U) ^ RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterG = ((((aWandererE + RotL64(aScatter, 28U)) + RotL64(aCarry, 39U)) + 14686411261024919129U) + aPhaseBOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1]) + RotL64(aNonceWordE, 44U);
            aOrbiterD = (((aWandererF + RotL64(aIngress, 19U)) + RotL64(aCarry, 51U)) + 7514582233957632005U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (((aWandererJ + RotL64(aCross, 51U)) + RotL64(aCarry, 5U)) + 6520710480103365552U) + RotL64(aNonceWordH, 49U);
            aOrbiterI = (aWandererC + RotL64(aPrevious, 3U)) + 1983621978676188036U;
            aOrbiterE = (aWandererA + RotL64(aIngress, 37U)) + 9003524602590749672U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 6428568234045228995U) + RotL64(aNonceWordF, 13U);
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 8656552687136446989U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16297456077021607301U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 16916248288415922490U) + RotL64(aNonceWordD, 35U);
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 9740237548002535784U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7970729853948983849U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 907561000814618339U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 4751108900841197631U;
            aOrbiterG = RotL64((aOrbiterG * 4545395964730641957U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 167774899400732287U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 11907484918310854962U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7213139491146402985U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 14910318613649863924U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 14882888155751455276U;
            aOrbiterE = RotL64((aOrbiterE * 11394136445442060201U), 51U);
            //
            aIngress = RotL64(aOrbiterI, 21U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterE, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aCross, 39U) + aOrbiterD) + RotL64(aOrbiterH, 51U)) + RotL64(aNonceWordB, 29U));
            aWandererA = aWandererA + (((RotL64(aIngress, 51U) + aOrbiterE) + RotL64(aOrbiterI, 29U)) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 37U)) + aOrbiterI) + RotL64(aNonceWordG, 11U)) + aPhaseBWandererUpdateSaltA[((aIndex + 26U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterG, 14U)) + RotL64(aCarry, 11U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 4U) + aOrbiterH) + RotL64(aOrbiterE, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 56U));
            aCarry = aCarry + RotL64(aWandererC, 21U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 54U) ^ RotL64(aNonceWordG, 41U)) ^ RotL64(aNonceWordE, 5U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 17062U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((aIndex + 18235U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 57U) ^ RotL64(aNonceWordA, 21U)) ^ RotL64(aNonceWordB, 43U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21634U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16686U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 27U)) ^ (RotL64(aCross, 56U) + RotL64(aIngress, 43U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterI = (((aWandererE + RotL64(aPrevious, 11U)) + RotL64(aCarry, 37U)) + 1708250618750199233U) + RotL64(aNonceWordG, 51U);
            aOrbiterB = ((aWandererB + RotL64(aCross, 52U)) + RotL64(aCarry, 23U)) + 12009147777553691142U;
            aOrbiterC = (((aWandererC + RotL64(aScatter, 19U)) + RotL64(aCarry, 11U)) + 8393982703399156592U) + aPhaseBOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aIngress, 35U)) + 3247327098356831221U) + RotL64(aNonceWordE, 9U);
            aOrbiterE = ((aWandererF + RotL64(aScatter, 27U)) + 3403590155376353737U) + aPhaseBOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 18197244558104735044U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 3096253642040701606U) ^ RotL64(aNonceWordD, 27U);
            aOrbiterC = RotL64((aOrbiterC * 6656168712438620783U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 8012692688785412179U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 17531946907545680745U;
            aOrbiterI = RotL64((aOrbiterI * 16510602981731506381U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 17687695944270225817U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 16147773866007628769U;
            aOrbiterF = RotL64((aOrbiterF * 16926442582711557877U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 18244641303026196497U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 8839160526348897457U;
            aOrbiterB = RotL64((aOrbiterB * 14268021129087663397U), 21U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterF) + 10599266240854068246U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]) + RotL64(aNonceWordA, 39U);
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 2056723540756216155U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13311591601230386375U), 13U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterC, 3U);
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 41U) + aOrbiterI) + RotL64(aOrbiterE, 18U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 26U) + RotL64(aOrbiterC, 5U)) + aOrbiterF) + RotL64(aCarry, 19U)) + RotL64(aNonceWordF, 13U));
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterE, 43U)) + aOrbiterF) + RotL64(aNonceWordB, 30U)) + aPhaseBWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 51U) + aOrbiterF) + RotL64(aOrbiterI, 27U)) + RotL64(aCarry, 51U)) + aPhaseBWandererUpdateSaltD[((aIndex + 4U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterB, 35U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererI, 30U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 11U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 56U) ^ RotL64(aNonceWordE, 43U)) ^ RotL64(aNonceWordF, 3U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 23677U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24808U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 56U) ^ RotL64(aNonceWordG, 3U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23757U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23356U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCross, 3U)) ^ (RotL64(aCarry, 54U) + RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterK = (((aWandererE + RotL64(aScatter, 13U)) + RotL64(aCarry, 51U)) + 12632404972795375757U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aCross, 57U)) + 5351879979055988456U;
            aOrbiterG = ((((aWandererF + RotL64(aPrevious, 38U)) + RotL64(aCarry, 23U)) + 3597737727467443413U) + aPhaseBOrbiterAssignSaltE[((aIndex + 10U)) & S_SALT1]) + RotL64(aNonceWordD, 23U);
            aOrbiterB = (aWandererD + RotL64(aIngress, 47U)) + 2830846754917852318U;
            aOrbiterE = (((aWandererA + RotL64(aCross, 29U)) + RotL64(aCarry, 11U)) + 17311925960294518018U) + RotL64(aNonceWordH, 9U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 2083584640523695383U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 15049343611387010158U;
            aOrbiterG = RotL64((aOrbiterG * 5567816356477420399U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 6443050378205811147U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 6021965178697344070U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6054064448935006741U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 5080289878758029976U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 576927745306972983U) ^ RotL64(aNonceWordE, 13U);
            aOrbiterK = RotL64((aOrbiterK * 16008958833683246115U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 4728489691382690859U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 6184355840165758855U) ^ RotL64(aNonceWordG, 41U);
            aOrbiterJ = RotL64((aOrbiterJ * 1515043910404156423U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 11220539885798595450U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 11091438724966718214U;
            aOrbiterB = RotL64((aOrbiterB * 8225347114759391961U), 11U);
            //
            aIngress = RotL64(aOrbiterE, 21U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + RotL64(aOrbiterJ, 46U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aIngress, 41U) + aOrbiterE) + RotL64(aOrbiterG, 13U)) + RotL64(aNonceWordA, 46U));
            aWandererE = aWandererE + ((((RotL64(aCross, 53U) + aOrbiterJ) + RotL64(aOrbiterE, 35U)) + RotL64(aCarry, 51U)) + RotL64(aNonceWordC, 29U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 18U) + RotL64(aOrbiterG, 3U)) + aOrbiterB) + aPhaseBWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aScatter, 29U) + aOrbiterK) + RotL64(aOrbiterE, 50U)) + RotL64(aCarry, 27U)) + aPhaseBWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterB, 21U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 56U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 19U) ^ RotL64(aNonceWordA, 38U)) ^ RotL64(aNonceWordH, 3U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 30239U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30575U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 52U) ^ RotL64(aNonceWordE, 13U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30391U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((aIndex + 27567U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aPrevious, 51U)) + (RotL64(aIngress, 38U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterK = ((aWandererH + RotL64(aScatter, 37U)) + 3650233661228036955U) + RotL64(aNonceWordH, 13U);
            aOrbiterC = ((((aWandererF + RotL64(aPrevious, 19U)) + RotL64(aCarry, 5U)) + 11607036400067735729U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1]) + RotL64(aNonceWordE, 3U);
            aOrbiterE = (((aWandererI + RotL64(aCross, 10U)) + RotL64(aCarry, 41U)) + 3899614406903883035U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aIngress, 47U)) + RotL64(aCarry, 29U)) + 8159156925629965143U;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 27U)) + 7148903913967261270U;
            //
            aOrbiterK = (((aOrbiterK + aOrbiterC) + 9161665622287517848U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1]) + RotL64(aNonceWordF, 10U);
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 2981535013474059469U;
            aOrbiterE = RotL64((aOrbiterE * 4434815231517266013U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 15812469008200319549U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 14687469489893270300U;
            aOrbiterC = RotL64((aOrbiterC * 14142363399696670451U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 6025209349511417063U) + RotL64(aNonceWordC, 39U);
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 12964750392311112676U;
            aOrbiterK = RotL64((aOrbiterK * 12955480283032701843U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 6572355895765394340U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 3542300121890027981U;
            aOrbiterG = RotL64((aOrbiterG * 11201491178181273935U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 6477175684045398359U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 1081388388827929314U;
            aOrbiterH = RotL64((aOrbiterH * 8752188637514143529U), 39U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 57U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 26U));
            aIngress = aIngress + RotL64(aOrbiterK, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aScatter, 3U) + aOrbiterK) + RotL64(aOrbiterE, 20U)) + RotL64(aCarry, 23U)) + RotL64(aNonceWordD, 5U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterH, 3U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 24U) + aOrbiterE) + RotL64(aOrbiterG, 39U)) + RotL64(aCarry, 57U)) + RotL64(aNonceWordA, 41U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 51U) + aOrbiterC) + RotL64(aOrbiterG, 29U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 13U) + aOrbiterC) + RotL64(aOrbiterE, 47U)) + aPhaseBWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 53U);
            aCarry = aCarry + RotL64(aIngress, 20U);
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

void TwistExpander_BaseBall_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xF18609429E32D28BULL + 0xFC5E7612B9369BD1ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x8481AF4588193FABULL + 0xEEB6E8DEB0C7C990ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x810D7F4A3475F489ULL + 0xB3D7FC384F974ECDULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xE49E545B0AA482BFULL + 0xFD3898C1891544E0ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xC15710311B84FDCDULL + 0xBF0E0F18CB4DF131ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xEC5C75146BDB89CBULL + 0xD1628936F301F511ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x89D4B2F348320289ULL + 0xBCCACC0FBB3F6727ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x9237D26BC65FB17FULL + 0xFF13A9E1525343DBULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 3U) ^ RotL64(aNonceWordG, 38U)) ^ RotL64(aNonceWordA, 11U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 2045U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 5308U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 4U) ^ RotL64(aNonceWordH, 23U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 3456U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneA[((aIndex + 4338U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCarry, 11U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCross, 24U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 21U)) + RotL64(aCarry, 21U)) + 1297415699043177788U;
            aOrbiterG = (aWandererK + RotL64(aCross, 29U)) + 17583786534509260153U;
            aOrbiterH = (((aWandererI + RotL64(aIngress, 3U)) + RotL64(aCarry, 57U)) + 643197858925708798U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = (((aWandererC + RotL64(aScatter, 56U)) + RotL64(aCarry, 5U)) + 5062653766915694874U) + RotL64(aNonceWordA, 27U);
            aOrbiterF = (aWandererG + RotL64(aPrevious, 13U)) + 7034273638367180511U;
            aOrbiterB = (aWandererF + RotL64(aCross, 35U)) + 2026909726972916996U;
            aOrbiterD = (aWandererB + RotL64(aScatter, 39U)) + 2785690475553211646U;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 51U)) + 2910341716302991892U) + aPhaseCOrbiterAssignSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aScatter, 60U)) + 2834181605200829791U) + RotL64(aNonceWordE, 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 13323052600571281928U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 10434901530315760460U) ^ RotL64(aNonceWordF, 21U);
            aOrbiterH = RotL64((aOrbiterH * 2042210188346767033U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 247903955625194782U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 5196515747387257163U;
            aOrbiterB = RotL64((aOrbiterB * 1799024689023272275U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 7196305682377987476U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 14777739876892587484U;
            aOrbiterA = RotL64((aOrbiterA * 95220583948241581U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 10609060796540136671U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 8386027207212484155U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4855610536246556893U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 729659744301903424U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterF) ^ 2350564261412606157U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]) ^ RotL64(aNonceWordD, 55U);
            aOrbiterJ = RotL64((aOrbiterJ * 16713856782349084977U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 16611987556673864177U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 1525195188708550503U;
            aOrbiterE = RotL64((aOrbiterE * 10045858602151004553U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 4654808490980989596U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 8189569777087686263U;
            aOrbiterD = RotL64((aOrbiterD * 17278657566389299577U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 10932857495004451792U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 1833880112534916813U;
            aOrbiterG = RotL64((aOrbiterG * 8004341577533825681U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 13100236350175516423U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 2773759534195186313U;
            aOrbiterF = RotL64((aOrbiterF * 3194954066097323161U), 35U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 29U);
            aIngress = aIngress + (RotL64(aOrbiterH, 6U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aCross, 34U) + aOrbiterI) + RotL64(aOrbiterH, 23U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 13U)) + aOrbiterD) + aPhaseCWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 11U) + aOrbiterB) + RotL64(aOrbiterJ, 46U)) + RotL64(aNonceWordB, 57U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 5U) + aOrbiterG) + RotL64(aOrbiterF, 35U));
            aWandererA = aWandererA + ((RotL64(aCross, 57U) + aOrbiterF) + RotL64(aOrbiterE, 5U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterF, 19U)) + aOrbiterI) + RotL64(aNonceWordC, 54U));
            aWandererE = aWandererE + (((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterE, 39U)) + RotL64(aCarry, 37U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterA, 51U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 20U) + RotL64(aOrbiterI, 58U)) + aOrbiterG) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 22U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 43U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 23U) ^ RotL64(aNonceWordA, 11U)) ^ RotL64(aNonceWordH, 60U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 13838U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneD[((aIndex + 15090U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 23U) ^ RotL64(aNonceWordG, 13U)) ^ RotL64(aNonceWordE, 4U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 15178U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 11884U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 42U) ^ RotL64(aIngress, 13U)) ^ (RotL64(aCross, 57U) + RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterE = (aWandererB + RotL64(aPrevious, 24U)) + 7893287783892523139U;
            aOrbiterI = (((aWandererC + RotL64(aCross, 5U)) + RotL64(aCarry, 19U)) + 10257331997383491153U) + aPhaseCOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = ((aWandererG + RotL64(aScatter, 57U)) + RotL64(aCarry, 3U)) + 14562226733652231753U;
            aOrbiterA = (aWandererF + RotL64(aIngress, 43U)) + 14320342577110737851U;
            aOrbiterG = ((((aWandererE + RotL64(aPrevious, 35U)) + RotL64(aCarry, 35U)) + 9816717579822880756U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 14U)) & S_SALT1]) + RotL64(aNonceWordC, 35U);
            aOrbiterB = (aWandererJ + RotL64(aCross, 10U)) + 9558926960095881953U;
            aOrbiterF = (aWandererK + RotL64(aIngress, 51U)) + 9230371862654338324U;
            aOrbiterJ = (aWandererA + RotL64(aScatter, 39U)) + 6414274291252913420U;
            aOrbiterD = ((aWandererI + RotL64(aCross, 29U)) + 13868546184398350849U) + RotL64(aNonceWordA, 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 16940736952569949038U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 2866957764814864371U;
            aOrbiterC = RotL64((aOrbiterC * 3554702178644797003U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 7916721976073979724U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 1602444214978842275U;
            aOrbiterG = RotL64((aOrbiterG * 11072503711308122385U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 9529061385251008037U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 8402775110887376588U) ^ RotL64(aNonceWordB, 23U);
            aOrbiterF = RotL64((aOrbiterF * 13980225144628227381U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 15003592180290390713U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 14195681406520825751U;
            aOrbiterJ = RotL64((aOrbiterJ * 11455000833788877217U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 3263577002367714202U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 12019422062655581928U;
            aOrbiterD = RotL64((aOrbiterD * 5002313835338447799U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 8508638054582582917U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 6536618106353552880U;
            aOrbiterE = RotL64((aOrbiterE * 6233964121117511885U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 9654542989321430868U) + RotL64(aNonceWordD, 5U);
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 7019594782797863244U;
            aOrbiterA = RotL64((aOrbiterA * 1234877854354279981U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 8256061220727519919U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 9232754129467036130U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17556001874302369781U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 5608829951337740378U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 12632120498473345701U;
            aOrbiterI = RotL64((aOrbiterI * 6994794653605831925U), 47U);
            //
            aIngress = RotL64(aOrbiterB, 53U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 18U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 23U));
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterJ, 35U)) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 3U)) + aOrbiterG);
            aWandererI = aWandererI + ((RotL64(aIngress, 60U) + aOrbiterG) + RotL64(aOrbiterJ, 47U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterD, 14U)) + aOrbiterF) + aPhaseCWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 35U) + RotL64(aOrbiterE, 39U)) + aOrbiterI) + RotL64(aNonceWordF, 13U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 11U) + aOrbiterA) + RotL64(aOrbiterD, 43U));
            aWandererE = aWandererE + (((RotL64(aScatter, 23U) + aOrbiterG) + RotL64(aOrbiterE, 51U)) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 39U) + aOrbiterE) + RotL64(aOrbiterF, 60U)) + RotL64(aNonceWordG, 4U));
            aWandererG = aWandererG + (((RotL64(aCross, 18U) + aOrbiterD) + RotL64(aOrbiterB, 19U)) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 46U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 51U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 50U) ^ RotL64(aNonceWordD, 27U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 22048U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 17771U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 39U) ^ RotL64(aNonceWordF, 28U)) ^ RotL64(aNonceWordC, 53U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 24084U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 21816U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 12U) + RotL64(aCross, 41U)) ^ (RotL64(aCarry, 27U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 3U)) + 8506388683755208267U;
            aOrbiterG = (aWandererB + RotL64(aScatter, 29U)) + 2179323259055019735U;
            aOrbiterD = (aWandererJ + RotL64(aIngress, 24U)) + 3345902531140983016U;
            aOrbiterB = (((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 37U)) + 17456139311481306584U) + RotL64(aNonceWordG, 31U);
            aOrbiterF = (aWandererH + RotL64(aScatter, 41U)) + 14587864088462311164U;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 13U)) + RotL64(aCarry, 13U)) + 13178947246650647057U;
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 37U)) + 12866578138946916962U) + RotL64(aNonceWordB, 27U);
            aOrbiterK = ((aWandererD + RotL64(aCross, 48U)) + 13098524333655118173U) + aPhaseCOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = (((aWandererF + RotL64(aPrevious, 53U)) + RotL64(aCarry, 21U)) + 15451329483787541982U) + aPhaseCOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 9494299579678389385U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 15581954810375490643U) ^ RotL64(aNonceWordH, 55U);
            aOrbiterD = RotL64((aOrbiterD * 13670002280188424825U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 4487042505730624892U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 2774455928791636186U;
            aOrbiterJ = RotL64((aOrbiterJ * 15847933919136777451U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 12435319582397755819U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 10077180055177766823U;
            aOrbiterB = RotL64((aOrbiterB * 3924363471701748703U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 10391963896910956455U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 6149237416725301794U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10115917698918612823U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 15673402771629639978U) + RotL64(aNonceWordE, 47U);
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 14729117178956592426U;
            aOrbiterF = RotL64((aOrbiterF * 9070464269215820531U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 14492001279368870240U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 6278248084483259952U;
            aOrbiterI = RotL64((aOrbiterI * 16731228350971263873U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 15727518866499740411U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 8652631010810965473U;
            aOrbiterA = RotL64((aOrbiterA * 9508484121620912715U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 13660890300188313775U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 14699253534935936300U;
            aOrbiterK = RotL64((aOrbiterK * 3978135617259934869U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 1621689916308271346U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 5651399428852950385U;
            aOrbiterE = RotL64((aOrbiterE * 12220143634120124133U), 47U);
            //
            aIngress = RotL64(aOrbiterA, 29U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 54U));
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterB, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aScatter, 34U) + RotL64(aOrbiterF, 43U)) + aOrbiterA) + aPhaseCWandererUpdateSaltE[((aIndex + 22U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 19U) + RotL64(aOrbiterB, 12U)) + aOrbiterE) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 43U) + aOrbiterD) + RotL64(aOrbiterA, 53U)) + aPhaseCWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterJ, 23U)) + aOrbiterB);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterD, 37U)) + aOrbiterB);
            aWandererF = aWandererF + (((RotL64(aIngress, 27U) + aOrbiterD) + RotL64(aOrbiterE, 57U)) + RotL64(aNonceWordF, 23U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 51U) + aOrbiterE) + RotL64(aOrbiterK, 29U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 4U) + aOrbiterK) + RotL64(aOrbiterI, 48U)) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterG, 19U)) + aOrbiterB) + RotL64(aNonceWordA, 24U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 36U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + RotL64(aWandererG, 51U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 5U) ^ RotL64(aNonceWordH, 19U)) ^ RotL64(aNonceWordF, 60U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 25768U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25825U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 41U) ^ RotL64(aNonceWordE, 29U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25618U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 30837U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 35U)) ^ (RotL64(aCross, 22U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterF = ((aWandererC + RotL64(aIngress, 57U)) + 12122689833405846292U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aCross, 53U)) + 9640400270962766788U) + RotL64(aNonceWordA, 61U);
            aOrbiterG = (((aWandererG + RotL64(aPrevious, 23U)) + RotL64(aCarry, 13U)) + 9141937998266739071U) + RotL64(aNonceWordG, 11U);
            aOrbiterJ = (aWandererK + RotL64(aScatter, 34U)) + 12899395770434090537U;
            aOrbiterE = (aWandererE + RotL64(aCross, 13U)) + 13457918115408031842U;
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 27U)) + 15134784483576000943U;
            aOrbiterH = (((aWandererD + RotL64(aScatter, 39U)) + RotL64(aCarry, 29U)) + 12540961268790055438U) + aPhaseCOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aIngress, 48U)) + RotL64(aCarry, 41U)) + 6306886773092764230U;
            aOrbiterD = (aWandererI + RotL64(aCross, 43U)) + 13573343491337243121U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 8545588657348974413U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterF) ^ 10891410570357275120U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1]) ^ RotL64(aNonceWordC, 44U);
            aOrbiterG = RotL64((aOrbiterG * 5399310978367842841U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 2877137119767060151U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 9178097682386595144U;
            aOrbiterE = RotL64((aOrbiterE * 3524486002084427513U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 15528007881855616978U) + RotL64(aNonceWordH, 37U);
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 11368419529245281435U;
            aOrbiterH = RotL64((aOrbiterH * 12433207037378339309U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 5932738914934356645U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 5551842263864055419U;
            aOrbiterF = RotL64((aOrbiterF * 16093776759971522681U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 3824433359595690603U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 17184628855571662441U;
            aOrbiterJ = RotL64((aOrbiterJ * 691208053136187317U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 8724462245014132623U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 7481349499528092352U;
            aOrbiterI = RotL64((aOrbiterI * 8212182934509617583U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 6908362960248294718U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 5354057969992655314U;
            aOrbiterB = RotL64((aOrbiterB * 16586084885820679343U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 11138301629323903147U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 14164180536320940750U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9099767681053390287U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 709942920176922902U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 17128241237359414945U;
            aOrbiterK = RotL64((aOrbiterK * 14063385518459963529U), 35U);
            //
            aIngress = RotL64(aOrbiterE, 34U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterD, 53U)) + aOrbiterB);
            aWandererD = aWandererD + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterK, 47U)) + aOrbiterH);
            aWandererB = aWandererB ^ (((RotL64(aCross, 26U) + RotL64(aOrbiterF, 18U)) + aOrbiterK) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 23U)) + aOrbiterD) + RotL64(aCarry, 47U)) + RotL64(aNonceWordB, 13U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 57U) + aOrbiterE) + RotL64(aOrbiterJ, 27U)) + aPhaseCWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterB, 11U)) + aOrbiterG) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 30U) + aOrbiterD) + RotL64(aOrbiterE, 60U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 41U) + aOrbiterI) + RotL64(aOrbiterJ, 35U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 11U) + aOrbiterG) + RotL64(aOrbiterK, 41U)) + RotL64(aNonceWordD, 39U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 24U));
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererE, 5U);
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

void TwistExpander_BaseBall_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xA9588950950D9B15ULL + 0xB2F6EF912AF749D4ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xDAEB27D7BAB3C1F5ULL + 0xFE8761FC38ECBC12ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xD67576A37AD1F9C3ULL + 0x8261D795E3024783ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xEF1B68643A16C2A3ULL + 0x8225E8122DB81022ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x908D21FEBB70AA47ULL + 0xFA279C19E0EFE1D3ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xF59CBED8ED8FD5CFULL + 0xEAE8BB6909A2D937ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xE7E8DBE7E716FAAFULL + 0xD24D4947139F3A04ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x957F2EC40D67198BULL + 0xAC814E4BA1C9198DULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 27U) ^ RotL64(aNonceWordE, 56U)) ^ RotL64(aNonceWordG, 19U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 3248U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 695U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 5U) ^ RotL64(aNonceWordD, 53U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4903U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneA[((aIndex + 4927U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCarry, 35U)) + (RotL64(aCross, 52U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 43U)) + RotL64(aCarry, 5U)) + 77518479758428414U;
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 20U)) + RotL64(aCarry, 11U)) + 4832061802166300011U;
            aOrbiterC = ((aWandererH + RotL64(aScatter, 23U)) + 11695291171006574112U) + aPhaseDOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aCross, 3U)) + 7467412817843260094U;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 27U)) + 17801484124471154757U;
            aOrbiterK = ((aWandererD + RotL64(aCross, 13U)) + RotL64(aCarry, 21U)) + 5555455638503958639U;
            aOrbiterF = ((aWandererI + RotL64(aScatter, 47U)) + 5669470540733721606U) + RotL64(aNonceWordC, 30U);
            aOrbiterI = ((aWandererC + RotL64(aIngress, 11U)) + 3042388456327784163U) + RotL64(aNonceWordE, 11U);
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 39U)) + 2236734925228156691U) + aPhaseDOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aIngress, 6U)) + 14459720401528685450U;
            aOrbiterD = (aWandererG + RotL64(aPrevious, 41U)) + 4814967631216658856U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 16950679344449075945U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 6262238639302011050U) ^ RotL64(aNonceWordG, 21U);
            aOrbiterC = RotL64((aOrbiterC * 9942659897425088183U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 3522256359074996724U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 12524717897707074242U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6787771338063891989U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 13891759914865623828U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 11910250571469028666U;
            aOrbiterA = RotL64((aOrbiterA * 12311343917878428995U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 2240189915640314069U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 5365912986308810837U;
            aOrbiterG = RotL64((aOrbiterG * 15133972552032469957U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 9323732721344489753U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 13087326560957916553U;
            aOrbiterF = RotL64((aOrbiterF * 14659491687401151733U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 16398238057564892809U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 11517870519285159224U) ^ RotL64(aNonceWordD, 37U);
            aOrbiterJ = RotL64((aOrbiterJ * 1501848878469712681U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 7758285512254776734U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 17475149091906684720U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6015816725428299273U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 2051631493975035243U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 11684740065349595315U;
            aOrbiterH = RotL64((aOrbiterH * 10918975496337269197U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 10575473798991451167U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 8267005776169272822U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13166868678285963961U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 6249698995716039231U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 13808085811784323978U;
            aOrbiterI = RotL64((aOrbiterI * 3897731011582061983U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 2739364646624876985U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 77518479758428414U;
            aOrbiterB = RotL64((aOrbiterB * 6977724811175035551U), 41U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterI, 41U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 26U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 5U));
            aIngress = aIngress + RotL64(aOrbiterC, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aCross, 48U) + RotL64(aOrbiterB, 35U)) + aOrbiterH) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 43U)) + aOrbiterC);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterB, 27U)) + aOrbiterC);
            aWandererE = aWandererE + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 60U)) + aOrbiterI) + RotL64(aNonceWordH, 55U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 29U)) + aOrbiterG);
            aWandererG = aWandererG + (((((RotL64(aPrevious, 39U) + RotL64(aOrbiterF, 51U)) + aOrbiterC) + RotL64(aCarry, 51U)) + RotL64(aNonceWordF, 59U)) + aPhaseDWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterD, 21U)) + aOrbiterF);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 53U) + aOrbiterG) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 35U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 46U) + RotL64(aOrbiterJ, 38U)) + aOrbiterH);
            aWandererB = aWandererB + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterG, 57U)) + aOrbiterB);
            aWandererK = aWandererK ^ ((RotL64(aCross, 41U) + aOrbiterE) + RotL64(aOrbiterD, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 28U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + RotL64(aWandererJ, 18U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 21U) ^ RotL64(aNonceWordE, 3U)) ^ RotL64(aNonceWordA, 51U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 9355U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9974U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 3U) ^ RotL64(aNonceWordF, 46U)) ^ RotL64(aNonceWordH, 27U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8526U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7161U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 21U) + RotL64(aCarry, 3U)) ^ (RotL64(aCross, 37U) + RotL64(aPrevious, 50U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterJ = ((aWandererG + RotL64(aCross, 39U)) + RotL64(aCarry, 23U)) + 9080426856729228705U;
            aOrbiterF = (((aWandererF + RotL64(aIngress, 41U)) + RotL64(aCarry, 3U)) + 7851218321653539276U) + RotL64(aNonceWordC, 53U);
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 48U)) + 7023344692919298036U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = (aWandererE + RotL64(aScatter, 21U)) + 9772846154227440734U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 53U)) + 12008298632429608431U) + RotL64(aNonceWordB, 10U);
            aOrbiterE = (aWandererI + RotL64(aPrevious, 3U)) + 12201090455849562875U;
            aOrbiterK = ((aWandererA + RotL64(aIngress, 43U)) + 9498721803411445471U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aScatter, 5U)) + 351203764023093632U;
            aOrbiterD = (aWandererD + RotL64(aIngress, 46U)) + 4966360430644539250U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 51U)) + RotL64(aCarry, 57U)) + 9194167899071345693U;
            aOrbiterB = (aWandererB + RotL64(aCross, 35U)) + 4922477697284269116U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 15742625291642356429U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 7528703106518431730U;
            aOrbiterC = RotL64((aOrbiterC * 11530049278751507567U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 15279053574704935317U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 2425839793660355555U;
            aOrbiterF = RotL64((aOrbiterF * 11486964816849830667U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 13209849392400008898U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 9041500097716231309U;
            aOrbiterA = RotL64((aOrbiterA * 340661035700748739U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 7885423750878814599U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 1992993999902904603U) ^ RotL64(aNonceWordE, 57U);
            aOrbiterK = RotL64((aOrbiterK * 1478629826632201617U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 6120758615019314102U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 8529621625846992066U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8485991471612862467U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 9125182130757385320U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 15691232622970220043U) ^ RotL64(aNonceWordD, 11U);
            aOrbiterJ = RotL64((aOrbiterJ * 16517916951054758147U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 11413090085435424697U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 11563151001080914939U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16828196274450408201U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 1778975369262558069U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 3232132443557192010U;
            aOrbiterE = RotL64((aOrbiterE * 17132823737792200981U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 277456309842614908U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 10470076566806421600U;
            aOrbiterH = RotL64((aOrbiterH * 7526503789282158285U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 12466953663713418197U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 15871548472936716844U;
            aOrbiterG = RotL64((aOrbiterG * 11788139245249205765U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 12322317028530419228U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 9080426856729228705U;
            aOrbiterB = RotL64((aOrbiterB * 4204042134412769955U), 51U);
            //
            aIngress = RotL64(aOrbiterD, 35U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 20U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + RotL64(aOrbiterG, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aScatter, 35U) + RotL64(aOrbiterD, 53U)) + aOrbiterG);
            aWandererE = aWandererE ^ (((RotL64(aCross, 43U) + aOrbiterA) + RotL64(aOrbiterE, 3U)) + RotL64(aNonceWordF, 59U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 54U) + aOrbiterB) + RotL64(aOrbiterI, 60U)) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 39U) + aOrbiterE) + RotL64(aOrbiterG, 41U)) + RotL64(aNonceWordH, 21U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 41U) + aOrbiterH) + RotL64(aOrbiterD, 35U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterJ, 43U)) + aOrbiterI);
            aWandererB = aWandererB + (((RotL64(aCross, 3U) + RotL64(aOrbiterF, 13U)) + aOrbiterJ) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterK, 5U)) + aOrbiterI);
            aWandererC = aWandererC + (((RotL64(aIngress, 11U) + RotL64(aOrbiterC, 27U)) + aOrbiterK) + aPhaseDWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 27U) + aOrbiterB) + RotL64(aOrbiterA, 58U)) + aPhaseDWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 18U) + aOrbiterF) + RotL64(aOrbiterG, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 50U));
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + RotL64(aWandererF, 27U);
            aCarry = aCarry + RotL64(aIngress, 46U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 11U) ^ RotL64(aNonceWordA, 34U)) ^ RotL64(aNonceWordF, 47U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 11428U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneA[((aIndex + 12846U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 3U) ^ RotL64(aNonceWordG, 19U)) ^ RotL64(aNonceWordH, 38U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11064U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((aIndex + 12202U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCarry, 43U)) ^ (RotL64(aCross, 6U) + RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterH = (aWandererJ + RotL64(aCross, 26U)) + 9630214189402543339U;
            aOrbiterF = (aWandererA + RotL64(aScatter, 29U)) + 4072576573737526819U;
            aOrbiterD = (aWandererC + RotL64(aIngress, 47U)) + 15994787452709618869U;
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 13U)) + 6403240137132259482U) + RotL64(aNonceWordB, 60U);
            aOrbiterI = ((aWandererE + RotL64(aScatter, 39U)) + 10229266900170507720U) + RotL64(aNonceWordD, 59U);
            aOrbiterE = (aWandererK + RotL64(aPrevious, 51U)) + 5025294577989748989U;
            aOrbiterG = ((aWandererD + RotL64(aCross, 5U)) + 16696461238217956883U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aIngress, 53U)) + 9878318855341719119U;
            aOrbiterJ = (((aWandererG + RotL64(aScatter, 21U)) + RotL64(aCarry, 51U)) + 16086635438116177346U) + aPhaseDOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 3U)) + RotL64(aCarry, 41U)) + 12295437783084203730U;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 56U)) + RotL64(aCarry, 23U)) + 7681150419912842402U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 2639104034287637448U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 12298170009332243573U;
            aOrbiterD = RotL64((aOrbiterD * 9397919591171238575U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 3485932317267669626U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 16569551670038752475U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8139802826402217631U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 4448490103784103954U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 14510534073046885941U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7777192047386438305U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 4286195398675733451U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 15790355933840266463U;
            aOrbiterI = RotL64((aOrbiterI * 13342257823027075501U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 6362891510370156055U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterK) ^ 15121822034579983174U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]) ^ RotL64(aNonceWordG, 19U);
            aOrbiterB = RotL64((aOrbiterB * 7268045994574844937U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 13817341015719915628U) + RotL64(aNonceWordH, 27U);
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 14113474087906143783U;
            aOrbiterC = RotL64((aOrbiterC * 12838910141533126059U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 9988301252236121106U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 11287477288382171758U;
            aOrbiterH = RotL64((aOrbiterH * 4979297247881426383U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 9491727010910328644U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 7961202721830514030U;
            aOrbiterA = RotL64((aOrbiterA * 16300364540313620767U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 10058066852293995222U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 541563830282750968U;
            aOrbiterG = RotL64((aOrbiterG * 1516823517052019845U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 7791201128863372861U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 8334318157449352359U;
            aOrbiterJ = RotL64((aOrbiterJ * 2924838607279239375U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 6861081455774799715U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 9630214189402543339U;
            aOrbiterK = RotL64((aOrbiterK * 10837610668580336781U), 19U);
            //
            aIngress = RotL64(aOrbiterF, 39U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 24U));
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterB, 11U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterE, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 43U)) + aOrbiterF);
            aWandererH = aWandererH + ((RotL64(aCross, 23U) + RotL64(aOrbiterA, 19U)) + aOrbiterD);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterB, 39U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 46U) + RotL64(aOrbiterC, 5U)) + aOrbiterJ);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 51U) + aOrbiterB) + RotL64(aOrbiterJ, 23U));
            aWandererI = aWandererI + (((RotL64(aCross, 21U) + RotL64(aOrbiterC, 54U)) + aOrbiterE) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 37U) + aOrbiterG) + RotL64(aOrbiterE, 3U)) + aPhaseDWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererD = aWandererD + (((((RotL64(aIngress, 13U) + RotL64(aOrbiterI, 21U)) + aOrbiterD) + RotL64(aCarry, 29U)) + RotL64(aNonceWordC, 9U)) + aPhaseDWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 6U) + aOrbiterK) + RotL64(aOrbiterG, 57U));
            aWandererF = aWandererF + ((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 48U)) + aOrbiterI);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 11U) + aOrbiterH) + RotL64(aOrbiterF, 13U)) + RotL64(aNonceWordE, 53U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 60U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 23U);
            aCarry = aCarry + RotL64(aIngress, 20U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 43U) ^ RotL64(aNonceWordF, 51U)) ^ RotL64(aNonceWordC, 60U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 19760U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 16696U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 43U) ^ RotL64(aNonceWordE, 51U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19031U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneD[((aIndex + 17865U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 52U)) + (RotL64(aIngress, 39U) ^ RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterE = ((aWandererK + RotL64(aIngress, 23U)) + 14249093584376402677U) + RotL64(aNonceWordE, 34U);
            aOrbiterD = ((aWandererG + RotL64(aCross, 56U)) + RotL64(aCarry, 23U)) + 8756965951816492264U;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 41U)) + 11221139480258176330U;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 47U)) + RotL64(aCarry, 37U)) + 17218894445564194851U;
            aOrbiterA = (aWandererC + RotL64(aIngress, 19U)) + 8064642692524949490U;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 13U)) + 5822093203710704646U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = (aWandererI + RotL64(aScatter, 11U)) + 3217799620158102238U;
            aOrbiterI = ((aWandererB + RotL64(aCross, 51U)) + 2613757677892120843U) + aPhaseDOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (aWandererH + RotL64(aIngress, 60U)) + 13647481499551657237U;
            aOrbiterF = (aWandererA + RotL64(aCross, 3U)) + 3545714196663685016U;
            aOrbiterH = (((aWandererF + RotL64(aPrevious, 5U)) + RotL64(aCarry, 53U)) + 9735422670576621521U) + RotL64(aNonceWordD, 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 3911046580637583767U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 9315984027042049203U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12568550776487242469U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 8926367674641729058U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 11035347490524961446U;
            aOrbiterA = RotL64((aOrbiterA * 10948288997163592463U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 10748158733051120339U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 2467801787989056455U;
            aOrbiterJ = RotL64((aOrbiterJ * 12621934274702358977U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 9244415080474351390U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 8517784887959492079U;
            aOrbiterK = RotL64((aOrbiterK * 17022899813765884147U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 8409307332803038455U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 11043806021873232950U;
            aOrbiterI = RotL64((aOrbiterI * 8294888329708842989U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 17512395828450251457U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 16849067939795823992U) ^ RotL64(aNonceWordA, 23U);
            aOrbiterG = RotL64((aOrbiterG * 9361991804481514337U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 17541946638063238056U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 11430501673960586718U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15074409630605450091U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 78307505705383302U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 4834528975263832983U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17245673681686752861U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 9647985402149698269U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 6610247710757518931U;
            aOrbiterE = RotL64((aOrbiterE * 8672486173272686859U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 2706696306041774372U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 9519896513600816252U;
            aOrbiterD = RotL64((aOrbiterD * 7468605169665549731U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 14647351223431646222U) + RotL64(aNonceWordC, 15U);
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 14249093584376402677U;
            aOrbiterC = RotL64((aOrbiterC * 8296105266618697281U), 13U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterE, 13U);
            aIngress = aIngress + (RotL64(aOrbiterK, 60U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 27U));
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 21U));
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 29U) + aOrbiterD) + RotL64(aOrbiterJ, 44U));
            aWandererG = aWandererG + (((RotL64(aScatter, 40U) + RotL64(aOrbiterH, 19U)) + aOrbiterA) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterJ, 11U)) + aOrbiterC) + aPhaseDWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 37U) + RotL64(aOrbiterB, 3U)) + aOrbiterA);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 39U)) + aOrbiterH) + RotL64(aNonceWordG, 27U));
            aWandererB = aWandererB + ((((RotL64(aCross, 5U) + RotL64(aOrbiterA, 57U)) + aOrbiterD) + RotL64(aCarry, 43U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterG, 29U));
            aWandererF = aWandererF + (((RotL64(aIngress, 22U) + aOrbiterK) + RotL64(aOrbiterE, 34U)) + RotL64(aNonceWordH, 19U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterK, 5U)) + aOrbiterF);
            aWandererE = aWandererE + ((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 53U)) + aOrbiterK);
            aWandererK = aWandererK ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterC, 51U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 46U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + RotL64(aWandererE, 13U);
            aCarry = aCarry + RotL64(aIngress, 28U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 18U) ^ RotL64(aNonceWordF, 39U)) ^ RotL64(aNonceWordH, 29U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 22091U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23811U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 11U) ^ RotL64(aNonceWordC, 3U)) ^ RotL64(aNonceWordE, 40U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26154U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneA[((aIndex + 23868U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 40U) + RotL64(aIngress, 57U)) + (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterD = (aWandererD + RotL64(aScatter, 60U)) + 11450949896247900941U;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 43U)) + RotL64(aCarry, 19U)) + 3905542253538116335U;
            aOrbiterE = ((aWandererA + RotL64(aCross, 51U)) + 9529740545977785305U) + aPhaseDOrbiterAssignSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 19U)) + 1856876631533143492U) + RotL64(aNonceWordD, 57U);
            aOrbiterK = ((aWandererG + RotL64(aScatter, 36U)) + RotL64(aCarry, 5U)) + 84253466320181686U;
            aOrbiterA = (aWandererJ + RotL64(aIngress, 41U)) + 12577480918745432444U;
            aOrbiterG = (aWandererH + RotL64(aCross, 3U)) + 5625703170397704029U;
            aOrbiterB = (((aWandererF + RotL64(aPrevious, 13U)) + RotL64(aCarry, 47U)) + 694608607323629282U) + RotL64(aNonceWordG, 39U);
            aOrbiterJ = (aWandererB + RotL64(aCross, 5U)) + 3993981243536262204U;
            aOrbiterF = (aWandererC + RotL64(aPrevious, 23U)) + 4119215953484892051U;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 53U)) + 8785040118556157146U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 16234403619456882890U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 10398727475672860610U;
            aOrbiterE = RotL64((aOrbiterE * 5086871400049644715U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 18327987141759096769U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 2645964788056875452U;
            aOrbiterA = RotL64((aOrbiterA * 8778681366114628045U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 2859452497983106129U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 7196557924940881076U;
            aOrbiterB = RotL64((aOrbiterB * 14415389907490256711U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 930127943984174668U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 15673596916054795749U;
            aOrbiterF = RotL64((aOrbiterF * 7505660488733199479U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 16673140529110941163U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 2258448294877833760U;
            aOrbiterD = RotL64((aOrbiterD * 1821550319748977445U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 6870209259643931219U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 12749790107942194104U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4871407285968611725U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 17131374134617173866U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterK) ^ 6426448390733751612U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1]) ^ RotL64(aNonceWordF, 61U);
            aOrbiterG = RotL64((aOrbiterG * 12490559588384058417U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 15592826434339731146U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 14182944418026376183U;
            aOrbiterJ = RotL64((aOrbiterJ * 7218860482893476233U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 17447476498234456596U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 972861017466618022U;
            aOrbiterH = RotL64((aOrbiterH * 9610670431280153921U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 13185309156950240549U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 14442284480744008537U;
            aOrbiterI = RotL64((aOrbiterI * 2907844852105175837U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 7816745313858811117U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 11450949896247900941U) ^ RotL64(aNonceWordB, 19U);
            aOrbiterK = RotL64((aOrbiterK * 18317765298694454463U), 43U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 23U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + (RotL64(aOrbiterC, 44U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 54U) + RotL64(aOrbiterJ, 19U)) + aOrbiterB) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterG, 23U));
            aWandererA = aWandererA + (((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 51U)) + aOrbiterK) + RotL64(aNonceWordC, 14U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 51U) + aOrbiterA) + RotL64(aOrbiterJ, 46U)) + aPhaseDWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 47U) + aOrbiterC) + RotL64(aOrbiterI, 11U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterE, 21U)) + aOrbiterH);
            aWandererI = aWandererI + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 43U)) + aOrbiterC);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterC, 27U)) + RotL64(aNonceWordE, 5U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 24U) + RotL64(aOrbiterA, 53U)) + aOrbiterD) + RotL64(aCarry, 57U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterE, 6U)) + aOrbiterF);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 13U) + aOrbiterJ) + RotL64(aOrbiterK, 37U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 34U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + RotL64(aWandererB, 51U);
            aCarry = aCarry + RotL64(aIngress, 36U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 43U) ^ RotL64(aNonceWordH, 13U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 30546U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneB[((aIndex + 31653U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 10U) ^ RotL64(aNonceWordA, 39U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27485U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((aIndex + 27672U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCross, 18U)) ^ (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterF = (aWandererH + RotL64(aPrevious, 37U)) + 7893287783892523139U;
            aOrbiterI = ((aWandererD + RotL64(aCross, 28U)) + RotL64(aCarry, 53U)) + 10257331997383491153U;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 39U)) + RotL64(aCarry, 37U)) + 14562226733652231753U;
            aOrbiterG = (aWandererG + RotL64(aIngress, 13U)) + 14320342577110737851U;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 43U)) + 9816717579822880756U) + RotL64(aNonceWordB, 19U);
            aOrbiterD = ((aWandererA + RotL64(aCross, 19U)) + 9558926960095881953U) + aPhaseDOrbiterAssignSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 21U)) + 9230371862654338324U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (aWandererK + RotL64(aScatter, 5U)) + 6414274291252913420U;
            aOrbiterB = (((aWandererC + RotL64(aPrevious, 41U)) + RotL64(aCarry, 3U)) + 13868546184398350849U) + RotL64(aNonceWordC, 49U);
            aOrbiterK = (aWandererE + RotL64(aScatter, 26U)) + 16940736952569949038U;
            aOrbiterA = (aWandererB + RotL64(aCross, 47U)) + 2866957764814864371U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 7916721976073979724U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 1602444214978842275U;
            aOrbiterE = RotL64((aOrbiterE * 11072503711308122385U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 9529061385251008037U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 8402775110887376588U;
            aOrbiterJ = RotL64((aOrbiterJ * 13980225144628227381U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 15003592180290390713U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 14195681406520825751U;
            aOrbiterD = RotL64((aOrbiterD * 11455000833788877217U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 3263577002367714202U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 12019422062655581928U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5002313835338447799U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 8508638054582582917U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 6536618106353552880U;
            aOrbiterC = RotL64((aOrbiterC * 6233964121117511885U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 9654542989321430868U) + RotL64(aNonceWordF, 59U);
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 7019594782797863244U;
            aOrbiterB = RotL64((aOrbiterB * 1234877854354279981U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 8256061220727519919U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 9232754129467036130U;
            aOrbiterK = RotL64((aOrbiterK * 17556001874302369781U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 5608829951337740378U) + RotL64(aNonceWordA, 53U);
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 12632120498473345701U;
            aOrbiterA = RotL64((aOrbiterA * 6994794653605831925U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 17313364434369677697U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 10147405701828074385U;
            aOrbiterF = RotL64((aOrbiterF * 11544579984323623009U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 16853703086012867980U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 3591438641820423822U;
            aOrbiterI = RotL64((aOrbiterI * 3570430739475340845U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 13974806289212867511U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 7893287783892523139U;
            aOrbiterG = RotL64((aOrbiterG * 6648351608953339723U), 41U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterG, 48U);
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aIngress, 51U) + aOrbiterH) + RotL64(aOrbiterK, 43U)) + RotL64(aNonceWordE, 3U));
            aWandererE = aWandererE + (((RotL64(aCross, 27U) + RotL64(aOrbiterC, 37U)) + aOrbiterE) + RotL64(aCarry, 19U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 53U) + aOrbiterG) + RotL64(aOrbiterI, 5U));
            aWandererB = aWandererB + (((RotL64(aScatter, 44U) + RotL64(aOrbiterE, 23U)) + aOrbiterB) + aPhaseDWandererUpdateSaltE[((aIndex + 16U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 5U) + aOrbiterD) + RotL64(aOrbiterG, 26U));
            aWandererH = aWandererH + (((RotL64(aScatter, 21U) + aOrbiterB) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterJ, 13U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterF, 51U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 60U) + aOrbiterD) + RotL64(aOrbiterK, 34U));
            aWandererA = aWandererA + (((RotL64(aCross, 23U) + aOrbiterD) + RotL64(aOrbiterH, 29U)) + RotL64(aNonceWordG, 56U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 39U) + aOrbiterC) + RotL64(aOrbiterA, 19U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 60U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 41U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 30U);
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

void TwistExpander_BaseBall_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xA9EEF7370A96AA4DULL + 0xCCC7B83B11D25553ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x9A02D26FF1677265ULL + 0xEC5BE08D91854E2AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xC18CF4C355EE09C5ULL + 0x9941478865758766ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xF2C60D17EB8EBD27ULL + 0xA90294D2A05AF68FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xC8D80661FFC80AD1ULL + 0xF339A4F9074C0871ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x822BE46BBE5D053DULL + 0x96980FC45AD3EDAAULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xD3DF6805E64519BBULL + 0xDA2450387081CE4BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xF136DEDD7BA519E3ULL + 0x9F345D5F82D8D90CULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 37U) ^ RotL64(aNonceWordC, 29U)) ^ RotL64(aNonceWordA, 21U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 2436U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneC[((aIndex + 4028U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 43U) ^ RotL64(aNonceWordB, 51U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 2847U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 2762U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 48U) + RotL64(aCarry, 21U)) ^ (RotL64(aCross, 5U) ^ RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterG = (aWandererI + RotL64(aScatter, 29U)) + 1888427424966603593U;
            aOrbiterK = (aWandererJ + RotL64(aCross, 14U)) + 5436761445660415091U;
            aOrbiterA = (((aWandererB + RotL64(aIngress, 11U)) + RotL64(aCarry, 35U)) + 17322876217962143270U) + RotL64(aNonceWordH, 49U);
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 53U)) + RotL64(aCarry, 13U)) + 9728299982740564979U;
            aOrbiterB = (aWandererA + RotL64(aIngress, 21U)) + 301720335271716921U;
            aOrbiterC = (aWandererK + RotL64(aPrevious, 3U)) + 8069685428854814396U;
            aOrbiterE = (((aWandererE + RotL64(aCross, 27U)) + 1973715500949100991U) + aPhaseEOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1]) + RotL64(aNonceWordE, 60U);
            aOrbiterD = (((aWandererF + RotL64(aScatter, 39U)) + RotL64(aCarry, 3U)) + 87666408799854155U) + aPhaseEOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aIngress, 48U)) + 12195436904339035245U;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 43U)) + 4578742069143400295U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 5U)) + 7828776048774876484U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 17203146364542781833U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 16913369550858890466U;
            aOrbiterA = RotL64((aOrbiterA * 13534417587921978507U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 9632761514552265402U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 9106637671877341286U;
            aOrbiterC = RotL64((aOrbiterC * 9073709119482640391U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 15423680889126750876U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 6087310684583331882U) ^ RotL64(aNonceWordC, 53U);
            aOrbiterG = RotL64((aOrbiterG * 8964465129744898619U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 5420955876411796789U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 14166807419730848032U;
            aOrbiterH = RotL64((aOrbiterH * 442659738632823751U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 8118312450347026824U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 4253043584558403086U;
            aOrbiterE = RotL64((aOrbiterE * 5651748455190536467U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 8810774678371762700U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 12218479555589447835U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11026364205248516355U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 11389930523582876358U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 16334420553471379915U) ^ RotL64(aNonceWordB, 51U);
            aOrbiterI = RotL64((aOrbiterI * 13830132212033904777U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 18201289372553710279U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 7196540389657785361U;
            aOrbiterK = RotL64((aOrbiterK * 13058135202554889791U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 2601046573550065116U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 2243003381737071984U;
            aOrbiterB = RotL64((aOrbiterB * 10518763530499878945U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 6058992247656841580U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 10083863011670540073U;
            aOrbiterD = RotL64((aOrbiterD * 17908394295613117155U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 8505005026063156940U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 1888427424966603593U;
            aOrbiterF = RotL64((aOrbiterF * 18298382581929885653U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 51U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterJ, 41U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterF, 54U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 27U)) + aOrbiterH) + RotL64(aCarry, 21U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterK, 29U)) + aOrbiterJ);
            aWandererH = aWandererH + ((RotL64(aCross, 5U) + RotL64(aOrbiterH, 47U)) + aOrbiterF);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 10U) + aOrbiterG) + RotL64(aOrbiterI, 37U)) + aPhaseEWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterJ, 23U)) + aOrbiterE) + aPhaseEWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterG, 6U)) + RotL64(aNonceWordD, 45U));
            aWandererF = aWandererF + (((RotL64(aCross, 39U) + aOrbiterH) + RotL64(aOrbiterB, 41U)) + RotL64(aCarry, 47U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 43U)) + aOrbiterA);
            aWandererB = aWandererB + ((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 21U)) + aOrbiterG);
            aWandererA = aWandererA ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterG, 10U)) + aOrbiterD);
            aWandererG = aWandererG + (((RotL64(aIngress, 22U) + RotL64(aOrbiterI, 57U)) + aOrbiterB) + RotL64(aNonceWordF, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 58U));
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 34U) ^ RotL64(aNonceWordA, 11U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 9519U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneD[((aIndex + 6368U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 53U) ^ RotL64(aNonceWordD, 21U)) ^ RotL64(aNonceWordC, 13U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 9851U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 7337U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 23U)) ^ (RotL64(aCarry, 35U) + RotL64(aIngress, 6U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterD = (aWandererD + RotL64(aPrevious, 29U)) + 8506388683755208267U;
            aOrbiterB = (aWandererF + RotL64(aCross, 37U)) + 2179323259055019735U;
            aOrbiterE = (aWandererH + RotL64(aIngress, 10U)) + 3345902531140983016U;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 3U)) + 17456139311481306584U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = (((aWandererA + RotL64(aIngress, 43U)) + RotL64(aCarry, 13U)) + 14587864088462311164U) + RotL64(aNonceWordG, 9U);
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 41U)) + 13178947246650647057U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aPrevious, 19U)) + 12866578138946916962U;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 14U)) + RotL64(aCarry, 5U)) + 13098524333655118173U;
            aOrbiterA = (aWandererK + RotL64(aIngress, 27U)) + 15451329483787541982U;
            aOrbiterK = (aWandererB + RotL64(aPrevious, 51U)) + 9494299579678389385U;
            aOrbiterC = (((aWandererE + RotL64(aCross, 23U)) + RotL64(aCarry, 47U)) + 15581954810375490643U) + RotL64(aNonceWordA, 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 4487042505730624892U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 2774455928791636186U;
            aOrbiterE = RotL64((aOrbiterE * 15847933919136777451U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 12435319582397755819U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 10077180055177766823U;
            aOrbiterB = RotL64((aOrbiterB * 3924363471701748703U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 10391963896910956455U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 6149237416725301794U;
            aOrbiterI = RotL64((aOrbiterI * 10115917698918612823U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 15673402771629639978U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 14729117178956592426U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9070464269215820531U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 14492001279368870240U) + RotL64(aNonceWordH, 48U);
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 6278248084483259952U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16731228350971263873U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 15727518866499740411U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 8652631010810965473U;
            aOrbiterD = RotL64((aOrbiterD * 9508484121620912715U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 13660890300188313775U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 14699253534935936300U;
            aOrbiterH = RotL64((aOrbiterH * 3978135617259934869U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 1621689916308271346U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 5651399428852950385U;
            aOrbiterJ = RotL64((aOrbiterJ * 12220143634120124133U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 9833573729127477238U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 11171647423058940388U) ^ RotL64(aNonceWordF, 45U);
            aOrbiterG = RotL64((aOrbiterG * 9692915620701425697U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 10346908196429120039U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 11972183669378621435U;
            aOrbiterK = RotL64((aOrbiterK * 12364429258926549335U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 11063215816236490488U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 8506388683755208267U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11514304191652750181U), 5U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterC, 10U);
            aIngress = aIngress + (RotL64(aOrbiterD, 37U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 53U));
            aIngress = aIngress + RotL64(aOrbiterK, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterI, 5U)) + aOrbiterK) + aPhaseEWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 21U) + aOrbiterI) + RotL64(aOrbiterE, 23U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterK, 43U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 42U) + RotL64(aOrbiterF, 20U)) + aOrbiterC) + RotL64(aNonceWordD, 43U)) + aPhaseEWandererUpdateSaltE[((aIndex + 16U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 29U) + aOrbiterI) + RotL64(aOrbiterG, 35U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 39U) + aOrbiterJ) + RotL64(aOrbiterK, 41U)) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 35U) + aOrbiterC) + RotL64(aOrbiterH, 47U));
            aWandererI = aWandererI + ((((RotL64(aCross, 27U) + RotL64(aOrbiterJ, 53U)) + aOrbiterA) + RotL64(aCarry, 43U)) + RotL64(aNonceWordE, 19U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterH, 60U));
            aWandererH = aWandererH + ((RotL64(aCross, 14U) + RotL64(aOrbiterD, 11U)) + aOrbiterB);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterE, 39U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 44U));
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 11U);
            aCarry = aCarry + RotL64(aIngress, 54U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 5U) ^ RotL64(aNonceWordA, 38U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 13583U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((aIndex + 15368U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 29U) ^ RotL64(aNonceWordF, 12U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 14723U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 14217U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 51U) ^ RotL64(aCross, 5U)) + (RotL64(aCarry, 39U) ^ RotL64(aIngress, 22U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterC = (aWandererD + RotL64(aIngress, 13U)) + 16424657151168221875U;
            aOrbiterJ = (aWandererI + RotL64(aCross, 3U)) + 17150123681886380361U;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 11U)) + 16041993588694572757U) + RotL64(aNonceWordE, 59U);
            aOrbiterE = (((aWandererA + RotL64(aScatter, 27U)) + RotL64(aCarry, 53U)) + 9871185846434828537U) + RotL64(aNonceWordD, 57U);
            aOrbiterH = (aWandererF + RotL64(aCross, 57U)) + 11227236398354430757U;
            aOrbiterK = (aWandererE + RotL64(aIngress, 20U)) + 5399325217402192631U;
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 37U)) + 9248828789282890454U) + aPhaseEOrbiterAssignSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 53U)) + RotL64(aCarry, 23U)) + 9041370494203701062U;
            aOrbiterG = (((aWandererH + RotL64(aCross, 51U)) + RotL64(aCarry, 47U)) + 14944424084524970764U) + aPhaseEOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aPrevious, 39U)) + 5481938174456671041U;
            aOrbiterF = (aWandererG + RotL64(aScatter, 18U)) + 14783648629543752715U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 12355573914530445723U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 9863991559011968318U;
            aOrbiterD = RotL64((aOrbiterD * 8495251211794343179U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 16149688605937250965U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 106041828692026825U;
            aOrbiterK = RotL64((aOrbiterK * 12199934305374582599U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 8076098639554567792U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 11155119311895580013U;
            aOrbiterJ = RotL64((aOrbiterJ * 1495180896564818647U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 6847612160595917702U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 16094377920388017367U) ^ RotL64(aNonceWordA, 53U);
            aOrbiterH = RotL64((aOrbiterH * 4875801863643206333U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 13584719866672696684U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 13446209321646234607U;
            aOrbiterI = RotL64((aOrbiterI * 9945349065094781529U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 15829806645369560988U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 12573767256739062550U;
            aOrbiterB = RotL64((aOrbiterB * 5649504278826069077U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 3850030870300393809U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 11857593987748189858U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15942863910931814193U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 5505918410521728373U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 12949653497121247860U;
            aOrbiterE = RotL64((aOrbiterE * 90944913639560027U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 2448323375614082955U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 4386059032042654583U;
            aOrbiterA = RotL64((aOrbiterA * 11730132905525317201U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 108129028178045299U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 18292666533864994149U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2599590507178673531U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 10771402979550786312U) + RotL64(aNonceWordG, 27U);
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 16424657151168221875U;
            aOrbiterF = RotL64((aOrbiterF * 6255743082177474607U), 37U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterJ, 3U);
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterC, 37U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 24U));
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 27U) + aOrbiterC) + RotL64(aOrbiterD, 39U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 19U) + aOrbiterD) + RotL64(aOrbiterK, 34U)) + RotL64(aNonceWordB, 21U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 50U) + RotL64(aOrbiterJ, 51U)) + aOrbiterB) + RotL64(aNonceWordH, 54U));
            aWandererK = aWandererK + (((RotL64(aCross, 5U) + RotL64(aOrbiterB, 41U)) + aOrbiterF) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 41U) + aOrbiterI) + RotL64(aOrbiterF, 37U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterH, 19U)) + aOrbiterD) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterG, 27U)) + aOrbiterA);
            aWandererD = aWandererD + ((RotL64(aScatter, 29U) + RotL64(aOrbiterE, 47U)) + aOrbiterH);
            aWandererF = aWandererF ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterI, 3U)) + aOrbiterD);
            aWandererC = aWandererC + ((((RotL64(aScatter, 21U) + RotL64(aOrbiterJ, 5U)) + aOrbiterG) + RotL64(aCarry, 19U)) + aPhaseEWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 52U) + aOrbiterI) + RotL64(aOrbiterG, 12U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 6U));
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + RotL64(aWandererE, 41U);
            aCarry = aCarry + RotL64(aIngress, 38U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 27U) ^ RotL64(aNonceWordG, 5U)) ^ RotL64(aNonceWordD, 13U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 17375U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 21692U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 24U) ^ RotL64(aNonceWordC, 43U)) ^ RotL64(aNonceWordB, 53U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 17307U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 20491U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 18U) ^ RotL64(aCarry, 39U)) + (RotL64(aCross, 3U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterB = ((aWandererJ + RotL64(aCross, 27U)) + RotL64(aCarry, 41U)) + 8767379393098711499U;
            aOrbiterG = (((aWandererE + RotL64(aPrevious, 58U)) + RotL64(aCarry, 23U)) + 7168159491580816433U) + aPhaseEOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aIngress, 19U)) + 9879279829061883406U;
            aOrbiterF = (aWandererH + RotL64(aScatter, 41U)) + 10537167136053399303U;
            aOrbiterD = (aWandererI + RotL64(aCross, 11U)) + 2839070018069188936U;
            aOrbiterC = (((aWandererK + RotL64(aPrevious, 3U)) + 13844278063968429732U) + aPhaseEOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1]) + RotL64(aNonceWordA, 3U);
            aOrbiterH = ((aWandererF + RotL64(aScatter, 51U)) + 11278946626186474646U) + RotL64(aNonceWordF, 6U);
            aOrbiterK = (aWandererD + RotL64(aIngress, 14U)) + 11798425216660557799U;
            aOrbiterA = (aWandererG + RotL64(aScatter, 39U)) + 7618446090703335192U;
            aOrbiterJ = (aWandererB + RotL64(aCross, 5U)) + 695423597006983660U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 47U)) + RotL64(aCarry, 29U)) + 14344728202803488813U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 11656100506575697086U) + RotL64(aNonceWordG, 23U);
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 10384358779985773937U;
            aOrbiterE = RotL64((aOrbiterE * 247494692039140973U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 17585001605131977341U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 9964478171465522911U;
            aOrbiterD = RotL64((aOrbiterD * 13484044854790175315U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 2710943171829692624U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 17809072853457153057U;
            aOrbiterC = RotL64((aOrbiterC * 16341884203303271365U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 12814092033910687774U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 1743186323268668740U;
            aOrbiterH = RotL64((aOrbiterH * 11150822630624332557U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 10750472346626754704U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 15925901217078035356U) ^ RotL64(aNonceWordH, 11U);
            aOrbiterK = RotL64((aOrbiterK * 9276504171291801637U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 2569102106359362359U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 8868261301410769739U;
            aOrbiterA = RotL64((aOrbiterA * 3662495603133918101U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 2143691008373582476U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 10606616796243205921U;
            aOrbiterJ = RotL64((aOrbiterJ * 15794414817813485643U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 16258070651850746855U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 11720192793689633315U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14475623219460678021U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 8230871037292355675U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 16898650748046368353U;
            aOrbiterB = RotL64((aOrbiterB * 7368697435476300255U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 9071122174426904737U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 4506737259011736474U;
            aOrbiterG = RotL64((aOrbiterG * 11903039808814842447U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 4545409671845718259U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 8767379393098711499U;
            aOrbiterF = RotL64((aOrbiterF * 1210632171306946669U), 51U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterJ, 29U);
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterG, 11U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + (RotL64(aOrbiterE, 26U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterD, 13U)) + RotL64(aCarry, 27U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 54U) + aOrbiterH) + RotL64(aOrbiterI, 53U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterE, 41U)) + aOrbiterH) + RotL64(aCarry, 11U)) + aPhaseEWandererUpdateSaltC[((aIndex + 28U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterA, 5U)) + aOrbiterG);
            aWandererG = aWandererG + (((RotL64(aPrevious, 19U) + aOrbiterD) + RotL64(aOrbiterC, 3U)) + RotL64(aNonceWordC, 49U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 51U)) + aOrbiterJ);
            aWandererB = aWandererB + ((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterF, 46U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 5U) + aOrbiterJ) + RotL64(aOrbiterA, 39U));
            aWandererC = aWandererC + ((RotL64(aCross, 11U) + RotL64(aOrbiterD, 27U)) + aOrbiterE);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 58U) + RotL64(aOrbiterF, 37U)) + aOrbiterK) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 48U)) + aOrbiterD) + RotL64(aNonceWordE, 61U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 50U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + RotL64(aWandererF, 27U);
            aCarry = aCarry + RotL64(aIngress, 52U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 29U) ^ RotL64(aNonceWordA, 51U)) ^ RotL64(aNonceWordB, 43U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 23281U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24574U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 19U) ^ RotL64(aNonceWordC, 29U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 23208U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneA[((aIndex + 22159U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aPrevious, 11U)) + (RotL64(aCarry, 60U) ^ RotL64(aIngress, 47U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterK = (aWandererH + RotL64(aIngress, 29U)) + 18191288703716505885U;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 21U)) + 9824014524910417136U) + RotL64(aNonceWordF, 19U);
            aOrbiterB = (aWandererA + RotL64(aScatter, 5U)) + 11953012029254917548U;
            aOrbiterI = ((aWandererD + RotL64(aCross, 47U)) + RotL64(aCarry, 35U)) + 6297568011027199089U;
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 26U)) + 2576999400457367975U;
            aOrbiterE = (aWandererK + RotL64(aCross, 23U)) + 13176139160575558254U;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 57U)) + RotL64(aCarry, 27U)) + 9978408174563621810U;
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 19U)) + RotL64(aCarry, 5U)) + 16765834875061607142U;
            aOrbiterG = (aWandererI + RotL64(aScatter, 3U)) + 16534507305459121344U;
            aOrbiterH = ((aWandererF + RotL64(aCross, 44U)) + 3114710944346151807U) + aPhaseEOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (((aWandererB + RotL64(aPrevious, 51U)) + 10240517868726718592U) + aPhaseEOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1]) + RotL64(aNonceWordG, 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 10721450637990777883U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 16689590768796583952U;
            aOrbiterB = RotL64((aOrbiterB * 3046344179729901637U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 2427422768928450209U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 13495584061816457831U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6670984773768885119U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 7058636403765106682U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 9897341853944713767U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14286816859999869231U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 17749559755733386064U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 12515645083926326659U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6582878478865838245U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 2625692458813609962U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 10596240255026143019U;
            aOrbiterK = RotL64((aOrbiterK * 11605800195771080135U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 12374290338067865540U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 1507386663796330249U;
            aOrbiterI = RotL64((aOrbiterI * 1210241080424446087U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 9288099549484146726U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 15159312464747000702U;
            aOrbiterA = RotL64((aOrbiterA * 500055502081347757U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 14998608679505446229U) + RotL64(aNonceWordE, 41U);
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 17625038109437732009U;
            aOrbiterG = RotL64((aOrbiterG * 14785862243019841689U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 10543192232885637211U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 10330547522729618042U;
            aOrbiterD = RotL64((aOrbiterD * 7635903835474874057U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 5753298214283941201U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 15943436872588208065U;
            aOrbiterC = RotL64((aOrbiterC * 17704547766822075741U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 5757218926946874970U) + RotL64(aNonceWordC, 47U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 18191288703716505885U;
            aOrbiterJ = RotL64((aOrbiterJ * 2644970408001409575U), 51U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterB, 60U);
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 39U));
            aIngress = aIngress + (RotL64(aOrbiterK, 53U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterG, 46U)) + aOrbiterJ);
            aWandererH = aWandererH + (((RotL64(aIngress, 27U) + aOrbiterH) + RotL64(aOrbiterG, 39U)) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 58U) + RotL64(aOrbiterG, 11U)) + aOrbiterE);
            aWandererG = aWandererG + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterC, 43U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltA[((aIndex + 26U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 13U)) + aOrbiterF) + RotL64(aNonceWordA, 49U));
            aWandererK = aWandererK + ((RotL64(aIngress, 39U) + RotL64(aOrbiterA, 51U)) + aOrbiterC);
            aWandererC = aWandererC ^ ((RotL64(aCross, 14U) + RotL64(aOrbiterH, 23U)) + aOrbiterD);
            aWandererI = aWandererI + (((RotL64(aPrevious, 35U) + aOrbiterE) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterE, 37U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 27U)) + aOrbiterI);
            aWandererE = aWandererE ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterE, 58U)) + aOrbiterB) + RotL64(aNonceWordD, 44U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + (RotL64(aWandererA, 60U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererC, 44U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 23U) ^ RotL64(aNonceWordD, 48U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 27627U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneB[((aIndex + 31891U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 57U) ^ RotL64(aNonceWordA, 19U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 27385U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((aIndex + 29031U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aPrevious, 3U)) ^ (RotL64(aIngress, 24U) + RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterB = (((aWandererI + RotL64(aIngress, 19U)) + RotL64(aCarry, 43U)) + 12669015908335980355U) + aPhaseEOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = (((aWandererF + RotL64(aScatter, 51U)) + RotL64(aCarry, 39U)) + 5438715179868613192U) + RotL64(aNonceWordA, 9U);
            aOrbiterA = (aWandererB + RotL64(aCross, 43U)) + 13172104448184536460U;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 34U)) + 13421421503244744803U) + RotL64(aNonceWordB, 4U);
            aOrbiterG = (aWandererE + RotL64(aScatter, 13U)) + 13327113302994856582U;
            aOrbiterK = (aWandererJ + RotL64(aCross, 21U)) + 4671768205922454413U;
            aOrbiterI = (aWandererG + RotL64(aIngress, 39U)) + 5355759962838579929U;
            aOrbiterC = (aWandererC + RotL64(aPrevious, 11U)) + 6691720614265406851U;
            aOrbiterH = (((aWandererD + RotL64(aCross, 37U)) + RotL64(aCarry, 3U)) + 7063906424700911378U) + aPhaseEOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 46U)) + 17328616394166672263U;
            aOrbiterF = (aWandererA + RotL64(aIngress, 23U)) + 1542940602574207068U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 7203866278803132454U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 993485696233139264U;
            aOrbiterA = RotL64((aOrbiterA * 11609009908810366447U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 15659679028507488331U) + RotL64(aNonceWordC, 11U);
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 18321361454094675842U;
            aOrbiterG = RotL64((aOrbiterG * 3966860765622641843U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 9633319822696783352U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 3496559332232402963U;
            aOrbiterK = RotL64((aOrbiterK * 7772060229838162977U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 1918349708324205526U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 7701088402761359134U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9649485438465644795U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 6006824348814439686U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 18088375375347012557U;
            aOrbiterC = RotL64((aOrbiterC * 12801082943086128385U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 12816533373478543584U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 17951880253818836433U;
            aOrbiterH = RotL64((aOrbiterH * 8935839101517220201U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 11311632024372748238U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 9891349164779752351U;
            aOrbiterJ = RotL64((aOrbiterJ * 11405973752233193209U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 711130292000437038U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 17818800917771709681U;
            aOrbiterF = RotL64((aOrbiterF * 10567029732245868263U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 10188714200240109442U) + RotL64(aNonceWordG, 47U);
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 9745615081760948652U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9321909462220134035U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 6508703788527163965U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 7536038073603467381U;
            aOrbiterE = RotL64((aOrbiterE * 12015514242701199813U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 2793951597846756844U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 12669015908335980355U;
            aOrbiterD = RotL64((aOrbiterD * 7355285540199760689U), 57U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 47U);
            aIngress = aIngress + (RotL64(aOrbiterD, 22U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aScatter, 36U) + aOrbiterE) + RotL64(aOrbiterI, 56U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 39U)) + aOrbiterI);
            aWandererC = aWandererC + (((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterC, 47U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 43U) + aOrbiterJ) + RotL64(aOrbiterG, 37U)) + RotL64(aCarry, 13U)) + aPhaseEWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 3U) + aOrbiterJ) + RotL64(aOrbiterF, 51U));
            aWandererA = aWandererA + ((((RotL64(aScatter, 47U) + aOrbiterK) + RotL64(aOrbiterJ, 21U)) + RotL64(aNonceWordE, 53U)) + aPhaseEWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterE, 43U));
            aWandererF = aWandererF + ((RotL64(aIngress, 27U) + aOrbiterC) + RotL64(aOrbiterB, 23U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterJ, 12U)) + aOrbiterE) + RotL64(aNonceWordH, 13U));
            aWandererB = aWandererB + ((RotL64(aScatter, 6U) + RotL64(aOrbiterI, 5U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + (RotL64(aWandererB, 56U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 50U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_BaseBall_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xE59F3B07F9DCC67FULL + 0xDD05EE00E99B1F75ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xB38338C10384ED5FULL + 0xB84271567854A226ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xD3A116F20A2E4369ULL + 0x8B3E64DB17E615E8ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xF2B44C10DC232103ULL + 0xF55240DFD28219E2ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x8CA70B5768379209ULL + 0xA1C90356C0B0F048ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x86DAE1C7124836D9ULL + 0xF7E81193E026072EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xC552DCE7A8CB7F3FULL + 0xA8E152B511A86CF0ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xFCD2286242344787ULL + 0xF30D980006E96F30ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 57U) ^ RotL64(aNonceWordH, 23U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 2340U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneC[((aIndex + 565U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 12U) ^ RotL64(aNonceWordE, 43U)) ^ RotL64(aNonceWordA, 51U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 1690U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 1031U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 4U) ^ RotL64(aCarry, 23U)) + (RotL64(aCross, 53U) + RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = (aWandererK + RotL64(aCross, 47U)) + 9914837590440975587U;
            aOrbiterJ = (aWandererA + RotL64(aScatter, 6U)) + 6706125076401958051U;
            aOrbiterG = (aWandererI + RotL64(aIngress, 41U)) + 16570817772679258409U;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 29U)) + 6843705658115186948U;
            aOrbiterA = (((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 21U)) + 16099930446791572351U) + RotL64(aNonceWordG, 57U);
            aOrbiterI = (aWandererF + RotL64(aPrevious, 35U)) + 5420550009556030459U;
            aOrbiterC = ((aWandererH + RotL64(aCross, 11U)) + 5729549069420177477U) + RotL64(aNonceWordA, 55U);
            aOrbiterF = (aWandererE + RotL64(aIngress, 56U)) + 15590601126188675834U;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 19U)) + 13044027390998620029U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = (((aWandererD + RotL64(aIngress, 23U)) + RotL64(aCarry, 57U)) + 11068338135659636772U) + aPhaseFOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = ((aWandererC + RotL64(aCross, 43U)) + RotL64(aCarry, 27U)) + 6584988841809544332U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 8516813219883915404U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 10647314042912492785U) ^ RotL64(aNonceWordF, 29U);
            aOrbiterG = RotL64((aOrbiterG * 15559481057047148785U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 201691689889605304U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 15512161798401184003U;
            aOrbiterI = RotL64((aOrbiterI * 11473219183982564709U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 3883760518944464145U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 13861805129175491145U;
            aOrbiterD = RotL64((aOrbiterD * 17194438894492581181U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 12019138626550801486U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 13030350224959652248U;
            aOrbiterK = RotL64((aOrbiterK * 11724200983306280107U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 2643807255422544248U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 4127143302485631794U) ^ RotL64(aNonceWordH, 38U);
            aOrbiterC = RotL64((aOrbiterC * 5441038881111578487U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 14602951930809633069U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 4555737199162278494U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12415825635220991865U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 6343143902997169834U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 10404783711336491985U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6235474458879439079U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 7406959231434835393U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 6684368109277850196U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8760360417572331159U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 4835889355927954728U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 7917682889852676712U;
            aOrbiterA = RotL64((aOrbiterA * 9045350756570117327U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 10268055422944417055U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 5563744562922937643U;
            aOrbiterF = RotL64((aOrbiterF * 12442484191329795173U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 17244672945880141679U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 9914837590440975587U;
            aOrbiterE = RotL64((aOrbiterE * 12269340309792850489U), 19U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 34U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 53U));
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 39U));
            aIngress = aIngress + RotL64(aOrbiterD, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 41U) + aOrbiterG) + RotL64(aOrbiterC, 47U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 60U)) + aOrbiterH);
            aWandererC = aWandererC ^ ((RotL64(aCross, 39U) + aOrbiterG) + RotL64(aOrbiterH, 5U));
            aWandererA = aWandererA + (((RotL64(aScatter, 56U) + RotL64(aOrbiterJ, 11U)) + aOrbiterC) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 51U) + aOrbiterI) + RotL64(aOrbiterA, 3U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterD, 24U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 43U)) + aOrbiterH);
            aWandererE = aWandererE + ((RotL64(aCross, 37U) + RotL64(aOrbiterK, 41U)) + aOrbiterG);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterD, 57U)) + aOrbiterB);
            aWandererD = aWandererD + ((((RotL64(aIngress, 6U) + aOrbiterA) + RotL64(aOrbiterJ, 27U)) + RotL64(aCarry, 51U)) + RotL64(aNonceWordB, 11U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterF, 37U)) + aOrbiterI) + RotL64(aNonceWordC, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 18U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + RotL64(aWandererJ, 44U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 41U) ^ RotL64(aNonceWordD, 27U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8539U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 7344U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 39U) ^ RotL64(aNonceWordA, 18U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 5997U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6176U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 56U)) + (RotL64(aIngress, 43U) + RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterB = (aWandererH + RotL64(aPrevious, 41U)) + 11450949896247900941U;
            aOrbiterF = (aWandererG + RotL64(aIngress, 50U)) + 3905542253538116335U;
            aOrbiterH = (((aWandererA + RotL64(aScatter, 37U)) + RotL64(aCarry, 35U)) + 9529740545977785305U) + RotL64(aNonceWordF, 49U);
            aOrbiterC = ((aWandererE + RotL64(aCross, 23U)) + 1856876631533143492U) + RotL64(aNonceWordE, 37U);
            aOrbiterK = (aWandererD + RotL64(aIngress, 47U)) + 84253466320181686U;
            aOrbiterI = (aWandererC + RotL64(aScatter, 60U)) + 12577480918745432444U;
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 29U)) + 5625703170397704029U;
            aOrbiterA = ((aWandererF + RotL64(aCross, 13U)) + 694608607323629282U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aScatter, 53U)) + 3993981243536262204U;
            aOrbiterG = ((aWandererB + RotL64(aCross, 19U)) + RotL64(aCarry, 43U)) + 4119215953484892051U;
            aOrbiterE = (((aWandererI + RotL64(aIngress, 21U)) + RotL64(aCarry, 21U)) + 8785040118556157146U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 16234403619456882890U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 10398727475672860610U;
            aOrbiterH = RotL64((aOrbiterH * 5086871400049644715U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 18327987141759096769U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 2645964788056875452U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8778681366114628045U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 2859452497983106129U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 7196557924940881076U;
            aOrbiterK = RotL64((aOrbiterK * 14415389907490256711U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 930127943984174668U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 15673596916054795749U;
            aOrbiterJ = RotL64((aOrbiterJ * 7505660488733199479U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 16673140529110941163U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 2258448294877833760U;
            aOrbiterD = RotL64((aOrbiterD * 1821550319748977445U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 6870209259643931219U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 12749790107942194104U;
            aOrbiterB = RotL64((aOrbiterB * 4871407285968611725U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 17131374134617173866U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 6426448390733751612U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12490559588384058417U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 15592826434339731146U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 14182944418026376183U;
            aOrbiterI = RotL64((aOrbiterI * 7218860482893476233U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 17447476498234456596U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 972861017466618022U;
            aOrbiterA = RotL64((aOrbiterA * 9610670431280153921U), 21U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterE) + 13185309156950240549U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1]) + RotL64(aNonceWordC, 57U);
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 14442284480744008537U;
            aOrbiterG = RotL64((aOrbiterG * 2907844852105175837U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 7816745313858811117U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 11450949896247900941U) ^ RotL64(aNonceWordB, 48U);
            aOrbiterE = RotL64((aOrbiterE * 18317765298694454463U), 51U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterC, 29U);
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 56U));
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterI, 47U)) + aOrbiterE);
            aWandererJ = aWandererJ + ((RotL64(aCross, 35U) + RotL64(aOrbiterC, 39U)) + aOrbiterE);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 27U)) + aOrbiterK);
            aWandererA = aWandererA + (((RotL64(aScatter, 53U) + RotL64(aOrbiterJ, 13U)) + aOrbiterK) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterI, 24U)) + aOrbiterF) + aPhaseFWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 60U) + RotL64(aOrbiterF, 35U)) + aOrbiterD) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterK, 3U)) + aOrbiterA);
            aWandererE = aWandererE + (((RotL64(aCross, 5U) + RotL64(aOrbiterB, 29U)) + aOrbiterA) + RotL64(aNonceWordD, 45U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 23U) + aOrbiterG) + RotL64(aOrbiterC, 41U)) + aPhaseFWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 11U) + aOrbiterH) + RotL64(aOrbiterF, 43U)) + RotL64(aNonceWordH, 19U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 50U) + RotL64(aOrbiterI, 50U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 30U));
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 54U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 54U) ^ RotL64(aNonceWordH, 3U)) ^ RotL64(aNonceWordG, 13U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13702U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12940U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 52U) ^ RotL64(aNonceWordE, 43U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 14551U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 10957U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCross, 21U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCarry, 38U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = (((aWandererA + RotL64(aIngress, 37U)) + RotL64(aCarry, 23U)) + 4622023259121087483U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aCross, 44U)) + RotL64(aCarry, 13U)) + 10253505250223501352U;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 53U)) + RotL64(aCarry, 5U)) + 17133877904420462669U;
            aOrbiterA = (aWandererE + RotL64(aScatter, 23U)) + 6162827793741796700U;
            aOrbiterF = (aWandererH + RotL64(aIngress, 21U)) + 9610986424765907615U;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 27U)) + 11210747154264753754U) + RotL64(aNonceWordA, 26U);
            aOrbiterC = (aWandererJ + RotL64(aCross, 41U)) + 16554205219580654546U;
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 12U)) + 10352576357413766388U) + aPhaseFOrbiterAssignSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aCross, 47U)) + 3651845783283479752U) + RotL64(aNonceWordB, 37U);
            aOrbiterH = (aWandererC + RotL64(aPrevious, 29U)) + 18145542190463500476U;
            aOrbiterI = (aWandererK + RotL64(aScatter, 19U)) + 5415609566767162857U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 2033734872464201570U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 3507213117125813345U;
            aOrbiterG = RotL64((aOrbiterG * 5453058336688881113U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 8716253393049851856U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 695984869565941856U;
            aOrbiterE = RotL64((aOrbiterE * 8377921610764044735U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 7661578828878284931U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 906654265099155956U;
            aOrbiterK = RotL64((aOrbiterK * 8117625377607536949U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 6050049984731254612U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 17882717590338190821U;
            aOrbiterF = RotL64((aOrbiterF * 10807367411402733215U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 4996521991532815957U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 4246460672800604436U;
            aOrbiterJ = RotL64((aOrbiterJ * 12047466401960824903U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 8700148116452518842U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 10039050281847466206U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11884791271239660157U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 4513844680425845372U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 3037563127442815153U) ^ RotL64(aNonceWordF, 29U);
            aOrbiterD = RotL64((aOrbiterD * 18363509277992292407U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 1005237931570968724U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 1373258132025712065U;
            aOrbiterA = RotL64((aOrbiterA * 10458020799382532395U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 12759144329395682277U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 5139371668116336931U;
            aOrbiterC = RotL64((aOrbiterC * 10761543179345026943U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 3211005174890625715U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 18045286961878287418U;
            aOrbiterB = RotL64((aOrbiterB * 4536094526540761611U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 4454078771279674978U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterH) ^ 4622023259121087483U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1]) ^ RotL64(aNonceWordG, 21U);
            aOrbiterI = RotL64((aOrbiterI * 8991756794989027019U), 5U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterD, 41U);
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 58U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 23U));
            aIngress = aIngress + RotL64(aOrbiterJ, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aCross, 22U) + RotL64(aOrbiterI, 47U)) + aOrbiterK) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterF, 39U)) + aOrbiterI) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 3U)) + aOrbiterG);
            aWandererF = aWandererF + ((RotL64(aIngress, 39U) + RotL64(aOrbiterG, 11U)) + aOrbiterJ);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterK, 60U)) + aOrbiterE);
            aWandererB = aWandererB + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterB, 5U)) + aOrbiterD) + RotL64(aCarry, 41U)) + RotL64(aNonceWordD, 41U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 30U) + RotL64(aOrbiterG, 23U)) + aOrbiterI);
            aWandererH = aWandererH + ((RotL64(aPrevious, 41U) + aOrbiterC) + RotL64(aOrbiterA, 19U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 57U)) + aOrbiterH);
            aWandererE = aWandererE + (((RotL64(aScatter, 47U) + aOrbiterK) + RotL64(aOrbiterA, 35U)) + RotL64(aNonceWordC, 57U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterH, 26U)) + aPhaseFWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 60U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererJ, 39U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 34U) ^ RotL64(aNonceWordF, 13U)) ^ RotL64(aNonceWordD, 5U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 17387U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16906U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 57U) ^ RotL64(aNonceWordB, 6U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18113U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneD[((aIndex + 19971U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 21U)) + (RotL64(aCarry, 35U) ^ RotL64(aIngress, 48U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = (aWandererB + RotL64(aIngress, 11U)) + 13204735390996728477U;
            aOrbiterH = (((aWandererK + RotL64(aPrevious, 44U)) + RotL64(aCarry, 47U)) + 851171359595647173U) + RotL64(aNonceWordH, 61U);
            aOrbiterD = (((aWandererG + RotL64(aScatter, 39U)) + RotL64(aCarry, 57U)) + 16745304202825290723U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aCross, 53U)) + 562392736584913979U;
            aOrbiterA = (aWandererD + RotL64(aPrevious, 47U)) + 3244267012529053918U;
            aOrbiterG = ((aWandererA + RotL64(aCross, 51U)) + RotL64(aCarry, 23U)) + 17282536111067869133U;
            aOrbiterC = ((aWandererE + RotL64(aScatter, 27U)) + 14851130066471729068U) + aPhaseFOrbiterAssignSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aIngress, 41U)) + 5256130407952363129U;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 21U)) + 2904742485828362001U) + RotL64(aNonceWordG, 43U);
            aOrbiterK = (aWandererH + RotL64(aScatter, 6U)) + 3723346325449225387U;
            aOrbiterF = (aWandererJ + RotL64(aIngress, 35U)) + 5344621093694027341U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 12919263300833603026U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 17989801264160996071U;
            aOrbiterD = RotL64((aOrbiterD * 15468293047311883751U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 5022175042377172157U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 16684822380107847758U;
            aOrbiterA = RotL64((aOrbiterA * 2834049270263837537U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 2740326510600876682U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 13981423865219318820U;
            aOrbiterG = RotL64((aOrbiterG * 14593082145080056441U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 231945878229848395U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 14139797734944312580U;
            aOrbiterC = RotL64((aOrbiterC * 6492256080432266407U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 16704102101387552373U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 8506734780526852552U;
            aOrbiterB = RotL64((aOrbiterB * 4684566118627414659U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 2774630043988894695U) + RotL64(aNonceWordC, 57U);
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 12490034334296488127U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16765455396278233145U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 545238171291436006U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 1023872898002379590U;
            aOrbiterK = RotL64((aOrbiterK * 8626333831510136515U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 5065187021047872560U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 10391809965648089863U;
            aOrbiterF = RotL64((aOrbiterF * 10912471108849550469U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 5576919045471579002U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 9761904001375034639U;
            aOrbiterE = RotL64((aOrbiterE * 8612901811320541361U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 2001472279505185946U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 11576457012366242134U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1070815118051466731U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 17713147845216099336U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterF) ^ 13204735390996728477U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1]) ^ RotL64(aNonceWordA, 13U);
            aOrbiterI = RotL64((aOrbiterI * 10889281795183444943U), 37U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 30U);
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + RotL64(aOrbiterI, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 22U) + RotL64(aOrbiterI, 30U)) + aOrbiterH) + aPhaseFWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterI, 5U));
            aWandererE = aWandererE + (((RotL64(aIngress, 37U) + RotL64(aOrbiterD, 47U)) + aOrbiterK) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterJ, 11U)) + aOrbiterA);
            aWandererI = aWandererI + (((RotL64(aScatter, 60U) + aOrbiterE) + RotL64(aOrbiterG, 18U)) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 39U)) + aOrbiterF) + RotL64(aNonceWordE, 21U));
            aWandererB = aWandererB + ((RotL64(aCross, 5U) + aOrbiterB) + RotL64(aOrbiterA, 27U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 43U)) + aOrbiterE);
            aWandererK = aWandererK + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterK, 41U)) + aOrbiterJ);
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 51U) + aOrbiterF) + RotL64(aOrbiterK, 53U)) + RotL64(aNonceWordB, 22U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterJ, 3U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 60U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + RotL64(aWandererI, 58U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 19U) ^ RotL64(aNonceWordH, 37U)) ^ RotL64(aNonceWordC, 57U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 21970U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24122U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 28U) ^ RotL64(aNonceWordA, 47U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25192U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((aIndex + 23997U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 29U) ^ RotL64(aPrevious, 56U)) ^ (RotL64(aCross, 43U) + RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = (aWandererE + RotL64(aPrevious, 11U)) + 16451272412693907816U;
            aOrbiterB = ((aWandererD + RotL64(aCross, 37U)) + 10099485419723255462U) + RotL64(aNonceWordE, 6U);
            aOrbiterI = ((aWandererF + RotL64(aIngress, 23U)) + RotL64(aCarry, 21U)) + 17668900099534923192U;
            aOrbiterH = (aWandererG + RotL64(aScatter, 51U)) + 5497093724143181753U;
            aOrbiterD = (aWandererB + RotL64(aIngress, 47U)) + 10354044773550071706U;
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 14U)) + RotL64(aCarry, 13U)) + 12728258851198019099U;
            aOrbiterJ = (((aWandererK + RotL64(aCross, 53U)) + 4144050505314242618U) + aPhaseFOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1]) + RotL64(aNonceWordG, 17U);
            aOrbiterC = (aWandererA + RotL64(aPrevious, 21U)) + 14133805325480076530U;
            aOrbiterK = ((aWandererC + RotL64(aCross, 5U)) + RotL64(aCarry, 27U)) + 308863673210602899U;
            aOrbiterG = (aWandererI + RotL64(aIngress, 27U)) + 11741180130160569753U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 44U)) + 12926863156769180448U) + aPhaseFOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 211920854786494259U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 13234608842479411078U) ^ RotL64(aNonceWordH, 47U);
            aOrbiterI = RotL64((aOrbiterI * 2556747209733759467U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 9164711974854618892U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 6667377062281954219U;
            aOrbiterA = RotL64((aOrbiterA * 2603737166987437649U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 4559040002406721850U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 1749875480850675109U;
            aOrbiterC = RotL64((aOrbiterC * 15822640067349481089U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 9555365165561936366U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 18289733999504213574U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14156217554673229429U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 8727162691639622461U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 291406782452963706U;
            aOrbiterE = RotL64((aOrbiterE * 8413500075082350243U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 8294911802626492257U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 15853578397277298548U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13256191781365357747U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 11535146194939658681U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 2177540476748375661U;
            aOrbiterJ = RotL64((aOrbiterJ * 15791341922007841029U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 2705306323728084136U) + RotL64(aNonceWordA, 43U);
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 17617871830709148043U;
            aOrbiterK = RotL64((aOrbiterK * 3449981219502809255U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 3699834746313613206U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 17952609181629473245U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6103160209028988839U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 8016694658897707674U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 6971251395823324489U;
            aOrbiterB = RotL64((aOrbiterB * 13483776115929040277U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 17467528888050817915U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 16451272412693907816U;
            aOrbiterD = RotL64((aOrbiterD * 13689734638238895071U), 39U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterA, 27U);
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterH, 58U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 24U) + aOrbiterA) + RotL64(aOrbiterH, 29U)) + aPhaseFWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 5U) + aOrbiterF) + RotL64(aOrbiterB, 39U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 39U) + aOrbiterC) + RotL64(aOrbiterF, 58U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterH, 35U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterG, 11U)) + aOrbiterC);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 35U) + aOrbiterA) + RotL64(aOrbiterK, 41U)) + RotL64(aNonceWordF, 9U));
            aWandererI = aWandererI + ((RotL64(aCross, 37U) + RotL64(aOrbiterC, 6U)) + aOrbiterD);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 51U) + aOrbiterJ) + RotL64(aOrbiterB, 13U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterI, 51U)) + aOrbiterE) + RotL64(aCarry, 35U)) + RotL64(aNonceWordB, 35U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterA, 21U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 28U) + RotL64(aOrbiterF, 47U)) + aOrbiterK) + RotL64(aCarry, 41U)) + aPhaseFWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 30U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererD, 11U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 20U) ^ RotL64(aNonceWordG, 37U)) ^ RotL64(aNonceWordH, 57U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29012U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((aIndex + 30166U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 29U) ^ RotL64(aNonceWordB, 53U)) ^ RotL64(aNonceWordA, 11U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31555U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneB[((aIndex + 31998U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aPrevious, 6U)) ^ (RotL64(aCarry, 19U) + RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 13U)) + 5088525177670191619U) + RotL64(aNonceWordF, 27U);
            aOrbiterH = (aWandererK + RotL64(aScatter, 21U)) + 9966456257813932112U;
            aOrbiterC = (aWandererE + RotL64(aCross, 43U)) + 7707646574027146307U;
            aOrbiterB = (((aWandererG + RotL64(aIngress, 10U)) + 75480203757681173U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1]) + RotL64(aNonceWordG, 37U);
            aOrbiterK = (((aWandererA + RotL64(aCross, 51U)) + RotL64(aCarry, 37U)) + 384659134071835163U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 41U)) + RotL64(aCarry, 57U)) + 3158769775373307778U;
            aOrbiterE = (aWandererF + RotL64(aScatter, 47U)) + 17360830943513941272U;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 19U)) + RotL64(aCarry, 11U)) + 5317278822721604586U;
            aOrbiterA = (aWandererD + RotL64(aIngress, 24U)) + 1371427105215954781U;
            aOrbiterD = (aWandererH + RotL64(aCross, 3U)) + 3162710551223553423U;
            aOrbiterF = (aWandererC + RotL64(aScatter, 57U)) + 5332921933853550756U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 10572462410297815854U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterG) ^ 10234389605554817892U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]) ^ RotL64(aNonceWordD, 45U);
            aOrbiterC = RotL64((aOrbiterC * 2130374833440291193U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 13421365517991380605U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 10186643614984034083U;
            aOrbiterK = RotL64((aOrbiterK * 8554471709467808453U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 4742438973260817120U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 6081590345899008846U;
            aOrbiterI = RotL64((aOrbiterI * 7069396301823124931U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 15360092808493795340U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 12186413069553132646U;
            aOrbiterE = RotL64((aOrbiterE * 3815981440611914267U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 16756221656224451552U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 12232880965861373143U) ^ RotL64(aNonceWordE, 61U);
            aOrbiterJ = RotL64((aOrbiterJ * 14196910735715726471U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 10090954323470840557U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 15615770271463853537U;
            aOrbiterA = RotL64((aOrbiterA * 13544181592829027283U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 556029032505658411U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 13311879111583579039U;
            aOrbiterD = RotL64((aOrbiterD * 3924744868168749003U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 8646360871497847336U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 2064833941982069154U;
            aOrbiterF = RotL64((aOrbiterF * 10016546852137913163U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 1701847261278886621U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 9654208200019718374U;
            aOrbiterG = RotL64((aOrbiterG * 4398089490129603677U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 14276143262844412074U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 10738184916176200661U;
            aOrbiterH = RotL64((aOrbiterH * 8940267914440361883U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 2966052720680305600U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 5088525177670191619U;
            aOrbiterB = RotL64((aOrbiterB * 11621585388684456139U), 41U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 4U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 19U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + (RotL64(aOrbiterD, 37U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aCross, 12U) + aOrbiterK) + RotL64(aOrbiterD, 29U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 23U) + RotL64(aOrbiterJ, 39U)) + aOrbiterF) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterG, 5U)) + aOrbiterC);
            aWandererD = aWandererD + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterJ, 35U)) + aOrbiterB);
            aWandererK = aWandererK ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterK, 24U)) + aOrbiterC);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 18U) + aOrbiterE) + RotL64(aOrbiterA, 47U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterF, 27U));
            aWandererH = aWandererH + (((RotL64(aScatter, 41U) + aOrbiterI) + RotL64(aOrbiterH, 53U)) + RotL64(aCarry, 19U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterF, 13U)) + aOrbiterC) + RotL64(aNonceWordC, 16U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 51U) + RotL64(aOrbiterI, 57U)) + aOrbiterB) + RotL64(aNonceWordA, 7U)) + aPhaseFWandererUpdateSaltF[((aIndex + 28U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 43U) + aOrbiterE) + RotL64(aOrbiterC, 10U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 30U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 18U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererJ, 5U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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

void TwistExpander_BaseBall_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x8E18F180884A6D25ULL + 0xBE55C84553DA4150ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xE51C7E817450EFA1ULL + 0xF5F1BF281419DFB2ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xFF44E4A39E52486DULL + 0x967C30AA214EE9E3ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x9C983B7EF72F6039ULL + 0xB8FC5D714E8E51B4ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x8C842C22FA1B457FULL + 0x81C5A224705EAD70ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xD93FE34B8C70424FULL + 0x9260D6761B7C3671ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xD696394DA806489BULL + 0xE90AFEBB9A568151ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF0890D5FA347141DULL + 0xC3E17CEF455B2B68ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 53U) ^ RotL64(aNonceWordE, 13U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 3639U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneC[((aIndex + 1086U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 29U) ^ RotL64(aNonceWordG, 5U)) ^ RotL64(aNonceWordF, 54U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 2835U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 5381U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 41U)) + (RotL64(aIngress, 57U) + RotL64(aCarry, 20U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterG = (aWandererE + RotL64(aPrevious, 57U)) + 11274974230580265396U;
            aOrbiterC = (aWandererC + RotL64(aScatter, 11U)) + 16658438747342741547U;
            aOrbiterB = (aWandererI + RotL64(aCross, 13U)) + 16612986966106053844U;
            aOrbiterE = (((aWandererA + RotL64(aIngress, 19U)) + RotL64(aCarry, 43U)) + 9329502236843231290U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 5U)) + 14088261356708344656U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = (aWandererJ + RotL64(aScatter, 41U)) + 13692608802007789581U;
            aOrbiterI = (aWandererD + RotL64(aIngress, 46U)) + 6824473946645682398U;
            aOrbiterF = (((aWandererG + RotL64(aCross, 21U)) + RotL64(aCarry, 19U)) + 2072915876348570040U) + RotL64(aNonceWordC, 15U);
            aOrbiterH = (aWandererB + RotL64(aIngress, 53U)) + 7420507753044460759U;
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 43U)) + 4677557318688502593U) + RotL64(aNonceWordE, 21U);
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 50U)) + RotL64(aCarry, 53U)) + 15081678577055628459U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 7026792817486507482U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 14871665922943969918U;
            aOrbiterB = RotL64((aOrbiterB * 694073180313083145U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 6807734532159292872U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 17882797335141303280U;
            aOrbiterD = RotL64((aOrbiterD * 15439872930381050291U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 9233542707022629190U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 1205501586581350876U;
            aOrbiterG = RotL64((aOrbiterG * 2596053290311090589U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 10878718669747466677U) + RotL64(aNonceWordB, 17U);
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 8066049063548639241U;
            aOrbiterE = RotL64((aOrbiterE * 3031382633089381605U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 861295180226875235U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 9134969787937288583U;
            aOrbiterI = RotL64((aOrbiterI * 7565008208670843555U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 6726642007159809594U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 8061661744643240470U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6703498926835391813U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 13541412083111962884U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 8617442758729315637U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15471862889276160953U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 16884403561131293362U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 9490680911678221233U;
            aOrbiterC = RotL64((aOrbiterC * 15988763830018001033U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 10486145044311386738U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 10200001044821063684U;
            aOrbiterA = RotL64((aOrbiterA * 16149790736141571017U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 6997073594007878034U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 13585783612009989767U) ^ RotL64(aNonceWordA, 23U);
            aOrbiterF = RotL64((aOrbiterF * 11425303157774550449U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 3847846040256340653U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 11274974230580265396U;
            aOrbiterJ = RotL64((aOrbiterJ * 13970270689108369205U), 13U);
            //
            aIngress = RotL64(aOrbiterE, 26U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aIngress, 6U) + RotL64(aOrbiterG, 51U)) + aOrbiterB) + RotL64(aCarry, 37U)) + RotL64(aNonceWordH, 20U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterK, 35U)) + aOrbiterB);
            aWandererG = aWandererG + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterE, 60U)) + aOrbiterB);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 19U) + aOrbiterD) + RotL64(aOrbiterA, 19U)) + aPhaseFWandererUpdateSaltF[((aIndex + 16U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 29U) + aOrbiterJ) + RotL64(aOrbiterG, 23U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterH, 37U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 43U) + aOrbiterI) + RotL64(aOrbiterB, 53U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 35U) + aOrbiterF) + RotL64(aOrbiterE, 57U)) + RotL64(aNonceWordG, 49U));
            aWandererD = aWandererD + (((RotL64(aIngress, 53U) + RotL64(aOrbiterI, 14U)) + aOrbiterE) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterD, 39U)) + aOrbiterE);
            aWandererJ = aWandererJ + (((RotL64(aCross, 14U) + aOrbiterJ) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 30U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 4U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 5U) ^ RotL64(aNonceWordH, 60U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 5644U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 7919U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 11U) ^ RotL64(aNonceWordC, 43U)) ^ RotL64(aNonceWordG, 27U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 8229U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 7111U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 10U) ^ RotL64(aCarry, 35U)) + (RotL64(aCross, 23U) ^ RotL64(aIngress, 47U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = (aWandererJ + RotL64(aCross, 37U)) + 8866844335448071821U;
            aOrbiterG = (aWandererG + RotL64(aPrevious, 27U)) + 15159698739856430085U;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 48U)) + RotL64(aCarry, 37U)) + 9582805772989594633U;
            aOrbiterF = ((aWandererB + RotL64(aScatter, 41U)) + 1438538239931588373U) + aPhaseFOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 19U)) + 10862044156620436139U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = (aWandererC + RotL64(aScatter, 3U)) + 13682173320058164615U;
            aOrbiterB = (aWandererE + RotL64(aCross, 13U)) + 8351013291045977592U;
            aOrbiterE = (aWandererH + RotL64(aIngress, 21U)) + 15777857431516633916U;
            aOrbiterJ = ((aWandererK + RotL64(aCross, 46U)) + 16178966745333885377U) + RotL64(aNonceWordF, 46U);
            aOrbiterD = (((aWandererI + RotL64(aScatter, 35U)) + RotL64(aCarry, 11U)) + 9031889187993001617U) + RotL64(aNonceWordG, 57U);
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 5U)) + RotL64(aCarry, 53U)) + 6308472367425865347U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 642109145903321046U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 9186268569255318035U;
            aOrbiterI = RotL64((aOrbiterI * 10714674348507516749U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 6091345356803675860U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 13218507921880873749U;
            aOrbiterG = RotL64((aOrbiterG * 15415157927185637717U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 4266652275234474616U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 4391422098164506195U;
            aOrbiterA = RotL64((aOrbiterA * 17634679403195085867U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 5160682323243635577U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 10351728852161347404U;
            aOrbiterB = RotL64((aOrbiterB * 11105410036471745951U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 3950932176454814023U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 9536466386833427441U;
            aOrbiterJ = RotL64((aOrbiterJ * 18064984243491293435U), 53U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterF) + 9927425919978776529U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]) + RotL64(aNonceWordD, 21U);
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 6819384090527481081U;
            aOrbiterK = RotL64((aOrbiterK * 18032965969184368561U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 1646274931424218507U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 16166524473976135097U) ^ RotL64(aNonceWordA, 15U);
            aOrbiterF = RotL64((aOrbiterF * 11672192658072663849U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 11252501968059485262U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 16847854447987609067U;
            aOrbiterH = RotL64((aOrbiterH * 6326299154627028295U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 16723218285355036446U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 13870211254243048975U;
            aOrbiterE = RotL64((aOrbiterE * 10203222183774624097U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 11401147367366049493U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 4266628469244269926U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2409934496621365221U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 11578385782347296942U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 8866844335448071821U;
            aOrbiterC = RotL64((aOrbiterC * 6456956795450036515U), 3U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterJ, 58U);
            aIngress = aIngress + (RotL64(aOrbiterF, 23U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + (RotL64(aOrbiterA, 41U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterD, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 11U) + RotL64(aOrbiterC, 23U)) + aOrbiterI) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterK, 57U)) + aOrbiterG) + RotL64(aNonceWordH, 55U));
            aWandererH = aWandererH + ((RotL64(aIngress, 3U) + RotL64(aOrbiterB, 54U)) + aOrbiterH);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterD, 21U)) + aOrbiterB) + RotL64(aNonceWordC, 17U));
            aWandererA = aWandererA + ((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterI, 3U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 18U) + RotL64(aOrbiterE, 5U)) + aOrbiterB);
            aWandererF = aWandererF + (((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 29U)) + aOrbiterA) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 19U)) + aOrbiterK);
            aWandererD = aWandererD + (((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterA, 35U)) + aPhaseFWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 48U) + RotL64(aOrbiterF, 11U)) + aOrbiterC) + aPhaseFWandererUpdateSaltA[((aIndex + 20U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 13U) + aOrbiterF) + RotL64(aOrbiterB, 44U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 56U));
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + RotL64(aWandererI, 50U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 37U) ^ RotL64(aNonceWordD, 52U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 11638U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((aIndex + 15468U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 29U) ^ RotL64(aNonceWordH, 41U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 13223U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneC[((aIndex + 13727U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 50U) + RotL64(aPrevious, 21U)) ^ (RotL64(aCross, 37U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = (aWandererI + RotL64(aIngress, 5U)) + 2225397913940961213U;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 35U)) + RotL64(aCarry, 53U)) + 8342544893601343643U;
            aOrbiterK = (aWandererC + RotL64(aScatter, 53U)) + 162922186381417187U;
            aOrbiterB = (((aWandererD + RotL64(aCross, 10U)) + RotL64(aCarry, 23U)) + 11660218373710972210U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = (aWandererA + RotL64(aScatter, 29U)) + 14909034764605802354U;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 23U)) + 16776955237009701511U) + aPhaseFOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = (aWandererB + RotL64(aCross, 21U)) + 5834487809188925253U;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 37U)) + 1498492772767040320U) + RotL64(aNonceWordF, 59U);
            aOrbiterJ = (((aWandererG + RotL64(aScatter, 57U)) + RotL64(aCarry, 3U)) + 4161765458781579617U) + RotL64(aNonceWordH, 41U);
            aOrbiterE = (aWandererJ + RotL64(aCross, 41U)) + 10511923076962447765U;
            aOrbiterF = (aWandererE + RotL64(aIngress, 50U)) + 8575954471692620021U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 6536325446331340573U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 1790628986900286346U;
            aOrbiterK = RotL64((aOrbiterK * 5262997114200816715U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 2623814807619278590U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 11676970995834706612U;
            aOrbiterA = RotL64((aOrbiterA * 10057461115132434901U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 13836786354224256591U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 6293096163612129260U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8977954126326217153U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 4271144764978661248U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 15938494256992560202U;
            aOrbiterH = RotL64((aOrbiterH * 10004841288382726739U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 11038155227307702976U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 12408749795071243930U;
            aOrbiterG = RotL64((aOrbiterG * 5527720475032868855U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 1673665849053496882U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 12866353361497103629U;
            aOrbiterE = RotL64((aOrbiterE * 6041125499398924871U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 10673935802381580966U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 8946776538955520352U) ^ RotL64(aNonceWordE, 11U);
            aOrbiterC = RotL64((aOrbiterC * 12293084177712710021U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 16294935203370452805U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 4697759331563852212U;
            aOrbiterB = RotL64((aOrbiterB * 14407806317275373043U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 17633118874112283386U) + RotL64(aNonceWordC, 47U);
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 89602424202721105U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1010654844008668685U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 4019154066191316616U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 15029609435149173243U;
            aOrbiterJ = RotL64((aOrbiterJ * 3522168783248806167U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 11765990698273078458U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 2225397913940961213U;
            aOrbiterF = RotL64((aOrbiterF * 8471538922288466221U), 5U);
            //
            aIngress = RotL64(aOrbiterA, 37U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + (RotL64(aOrbiterE, 50U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 53U));
            aIngress = aIngress + RotL64(aOrbiterG, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 53U) + aOrbiterF) + RotL64(aOrbiterH, 58U)) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterF, 21U)) + aOrbiterK);
            aWandererK = aWandererK + (((RotL64(aScatter, 44U) + RotL64(aOrbiterI, 41U)) + aOrbiterF) + RotL64(aNonceWordG, 22U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterH, 11U));
            aWandererH = aWandererH + ((RotL64(aScatter, 5U) + RotL64(aOrbiterB, 47U)) + aOrbiterD);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterC, 23U));
            aWandererC = aWandererC + (((RotL64(aCross, 37U) + RotL64(aOrbiterI, 51U)) + aOrbiterH) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterJ, 60U));
            aWandererF = aWandererF + (((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterI, 43U)) + aPhaseFWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 24U) + RotL64(aOrbiterF, 29U)) + aOrbiterE) + RotL64(aNonceWordB, 61U));
            aWandererD = aWandererD + (((RotL64(aScatter, 41U) + RotL64(aOrbiterI, 37U)) + aOrbiterA) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 60U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererK, 46U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 3U) ^ RotL64(aNonceWordH, 23U)) ^ RotL64(aNonceWordA, 58U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 18396U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 20205U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 11U) ^ RotL64(aNonceWordG, 23U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 16800U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneD[((aIndex + 16984U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aPrevious, 57U)) + (RotL64(aCarry, 11U) + RotL64(aIngress, 44U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 41U)) + RotL64(aCarry, 19U)) + 2558105147674438050U;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 27U)) + 15856662514774702561U) + RotL64(aNonceWordA, 35U);
            aOrbiterF = (((aWandererD + RotL64(aCross, 39U)) + RotL64(aCarry, 41U)) + 13346869226246584582U) + aPhaseFOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = (((aWandererF + RotL64(aScatter, 56U)) + 7632111846116243973U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 14U)) & S_SALT1]) + RotL64(aNonceWordE, 15U);
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 23U)) + 2102101361626976279U;
            aOrbiterA = (aWandererC + RotL64(aScatter, 13U)) + 5605968705067851563U;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 19U)) + 6842483186584326681U;
            aOrbiterH = (aWandererB + RotL64(aCross, 48U)) + 5559797213819425064U;
            aOrbiterG = ((aWandererE + RotL64(aIngress, 11U)) + RotL64(aCarry, 23U)) + 12422313931331576759U;
            aOrbiterD = (aWandererA + RotL64(aCross, 53U)) + 2751024420047872601U;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 35U)) + 11031320239359798610U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 14366375309473793217U) + RotL64(aNonceWordD, 20U);
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 11971479429768505316U;
            aOrbiterF = RotL64((aOrbiterF * 10063001532313098203U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 3947595951884469542U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 17882767922372770896U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3361906348965810211U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 513871456983509223U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 5951677013597794294U;
            aOrbiterA = RotL64((aOrbiterA * 8508629569649935293U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 437626309049021931U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 466674061172005705U;
            aOrbiterK = RotL64((aOrbiterK * 1310502572084891157U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 12362602809233133718U) + RotL64(aNonceWordF, 19U);
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 10525852878882195702U;
            aOrbiterH = RotL64((aOrbiterH * 17755022180514914325U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 17927000184308583095U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 566723721423470052U;
            aOrbiterG = RotL64((aOrbiterG * 17710534355278632573U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 9504585484034413577U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 4614306037721859929U;
            aOrbiterD = RotL64((aOrbiterD * 170807293799483539U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 1463218357720031588U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 4036696102163560633U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15389914226155130065U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 9907678911300898726U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 11804311892289601322U;
            aOrbiterC = RotL64((aOrbiterC * 13986106774841242253U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 6514645538508331396U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 17246364354815744899U;
            aOrbiterE = RotL64((aOrbiterE * 12800661037742526999U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 6725706155285333764U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 2558105147674438050U;
            aOrbiterB = RotL64((aOrbiterB * 6752457079901154727U), 5U);
            //
            aIngress = RotL64(aOrbiterA, 3U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 46U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterB, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 21U)) + aOrbiterI);
            aWandererE = aWandererE + ((((RotL64(aScatter, 48U) + RotL64(aOrbiterK, 27U)) + aOrbiterF) + RotL64(aCarry, 37U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 43U) + aOrbiterD) + RotL64(aOrbiterE, 13U));
            aWandererK = aWandererK + ((RotL64(aIngress, 29U) + RotL64(aOrbiterK, 5U)) + aOrbiterA);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterK, 30U)) + aOrbiterD) + RotL64(aNonceWordC, 37U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterB, 53U)) + aOrbiterK) + RotL64(aCarry, 43U)) + aPhaseFWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterD, 23U)) + RotL64(aNonceWordG, 39U));
            aWandererA = aWandererA + ((RotL64(aCross, 39U) + RotL64(aOrbiterF, 35U)) + aOrbiterH);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 5U) + aOrbiterC) + RotL64(aOrbiterK, 43U));
            aWandererC = aWandererC + ((RotL64(aScatter, 50U) + aOrbiterD) + RotL64(aOrbiterG, 37U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterI, 10U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + (RotL64(aWandererD, 20U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 57U) ^ RotL64(aNonceWordG, 13U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22325U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25519U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 51U) ^ RotL64(aNonceWordE, 5U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 23997U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneA[((aIndex + 24644U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 60U) ^ RotL64(aCross, 47U)) + (RotL64(aIngress, 29U) ^ RotL64(aCarry, 13U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterA = (aWandererC + RotL64(aIngress, 29U)) + 16124889768301047791U;
            aOrbiterC = (aWandererH + RotL64(aCross, 47U)) + 11912338587186717280U;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 27U)) + 8594012868813114354U;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 34U)) + 18281043566156682815U) + aPhaseFOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 19U)) + RotL64(aCarry, 39U)) + 16853106130200942302U;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 5U)) + RotL64(aCarry, 19U)) + 2611212958619673086U;
            aOrbiterK = (((aWandererG + RotL64(aCross, 39U)) + 18039472325066855180U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1]) + RotL64(aNonceWordF, 39U);
            aOrbiterG = ((aWandererI + RotL64(aScatter, 41U)) + RotL64(aCarry, 23U)) + 14495785571345122046U;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 44U)) + 4556063793412832418U) + RotL64(aNonceWordE, 42U);
            aOrbiterD = (aWandererK + RotL64(aIngress, 53U)) + 14896419970271244358U;
            aOrbiterB = (aWandererF + RotL64(aPrevious, 13U)) + 880028529183500036U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 2379557167489415783U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 11854373946064529806U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 150755294320438887U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 1487252775956449964U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 12777924204511625545U;
            aOrbiterI = RotL64((aOrbiterI * 1366019527386994789U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 15998631485222477969U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 8864212892296191613U) ^ RotL64(aNonceWordC, 57U);
            aOrbiterG = RotL64((aOrbiterG * 579242788050369815U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 17069347835763226743U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 7443008171694679791U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 748894368884566607U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 17334256152350782002U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 8986626119086556393U;
            aOrbiterA = RotL64((aOrbiterA * 2258172145924120235U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 8528180968228358674U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 12702290928064582589U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15673603224146737631U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 7742438100860023610U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 3729687240959702198U;
            aOrbiterK = RotL64((aOrbiterK * 3756794766163746783U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 426129097367382096U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 16782175452274911213U;
            aOrbiterJ = RotL64((aOrbiterJ * 1041477289638333659U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 5942016166948841079U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 5260815086125551703U;
            aOrbiterB = RotL64((aOrbiterB * 1603799103692438147U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 11732742583346900772U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 17182924380693084401U;
            aOrbiterC = RotL64((aOrbiterC * 14858685629471497071U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 8539335803784852017U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 16124889768301047791U) ^ RotL64(aNonceWordH, 31U);
            aOrbiterF = RotL64((aOrbiterF * 6607245691919237755U), 23U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterE, 21U);
            aIngress = aIngress + (RotL64(aOrbiterH, 44U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 51U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + RotL64(aOrbiterF, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterF, 10U)) + aOrbiterG);
            aWandererD = aWandererD + ((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 53U)) + aOrbiterJ);
            aWandererG = aWandererG ^ ((RotL64(aCross, 28U) + RotL64(aOrbiterF, 47U)) + aOrbiterA);
            aWandererK = aWandererK + ((RotL64(aScatter, 51U) + aOrbiterB) + RotL64(aOrbiterG, 23U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterC, 51U));
            aWandererB = aWandererB + (((((RotL64(aCross, 5U) + RotL64(aOrbiterF, 39U)) + aOrbiterH) + RotL64(aCarry, 29U)) + RotL64(aNonceWordG, 5U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterK, 57U)) + aOrbiterH);
            aWandererC = aWandererC + ((RotL64(aScatter, 37U) + RotL64(aOrbiterK, 27U)) + aOrbiterI);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterG, 36U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 21U)) + aOrbiterF) + RotL64(aCarry, 11U)) + RotL64(aNonceWordA, 21U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 30U) + aOrbiterD) + RotL64(aOrbiterH, 29U)) + aPhaseFWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + (RotL64(aWandererE, 60U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererG, 41U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 11U) ^ RotL64(aNonceWordC, 35U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29128U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32309U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 21U) ^ RotL64(aNonceWordG, 54U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31697U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29949U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 21U) ^ RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCross, 56U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = ((((aWandererI + RotL64(aPrevious, 51U)) + RotL64(aCarry, 41U)) + 7722279280863371124U) + aPhaseFOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1]) + RotL64(aNonceWordE, 27U);
            aOrbiterB = (aWandererF + RotL64(aCross, 43U)) + 11584220561732385598U;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 21U)) + 7834679350105534657U) + RotL64(aNonceWordG, 14U);
            aOrbiterG = (aWandererC + RotL64(aIngress, 13U)) + 11347994382444180879U;
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 18U)) + 9449903188047063431U) + aPhaseFOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = ((aWandererG + RotL64(aCross, 53U)) + RotL64(aCarry, 3U)) + 6516243976652795170U;
            aOrbiterJ = (aWandererD + RotL64(aScatter, 23U)) + 8420815253991184777U;
            aOrbiterF = (aWandererB + RotL64(aIngress, 37U)) + 9081386852515170937U;
            aOrbiterA = (aWandererK + RotL64(aPrevious, 35U)) + 14375955191735286867U;
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 3U)) + RotL64(aCarry, 19U)) + 880757589768436072U;
            aOrbiterK = (aWandererE + RotL64(aScatter, 6U)) + 3349856625725164229U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 7826309957607577207U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 8057435761214313635U;
            aOrbiterI = RotL64((aOrbiterI * 4718430712767038607U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 9565237500443303103U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 15893066735310588501U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8457633439171452397U), 5U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterI) + 3276844534476430842U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1]) + RotL64(aNonceWordF, 13U);
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 6828644383891274120U;
            aOrbiterC = RotL64((aOrbiterC * 979580351653410157U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 2815676923011504251U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 5030251870850928417U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7075653570570819253U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 13464083008377887034U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 8994560761846897590U;
            aOrbiterF = RotL64((aOrbiterF * 9892839554658865143U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 8398813387154468736U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 8136429428340910892U;
            aOrbiterA = RotL64((aOrbiterA * 3348811490733577295U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 418587250696862341U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 4111667833838312094U;
            aOrbiterD = RotL64((aOrbiterD * 860949442143849147U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 6075478294190926371U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 2208124955874142264U;
            aOrbiterK = RotL64((aOrbiterK * 15741988616251072075U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 4726538724576443010U) + RotL64(aNonceWordA, 19U);
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 6524078248882840425U;
            aOrbiterE = RotL64((aOrbiterE * 9784875566721689069U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 14521003220464811621U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 16916247868211621303U;
            aOrbiterB = RotL64((aOrbiterB * 1911638054294853877U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 18207293125461843123U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 7722279280863371124U;
            aOrbiterG = RotL64((aOrbiterG * 14303108475807941791U), 13U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 30U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 39U));
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aScatter, 39U) + RotL64(aOrbiterB, 18U)) + aOrbiterF);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 47U) + aOrbiterD) + RotL64(aOrbiterK, 41U));
            aWandererA = aWandererA + ((RotL64(aIngress, 19U) + RotL64(aOrbiterA, 43U)) + aOrbiterJ);
            aWandererH = aWandererH ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterC, 53U)) + aOrbiterH);
            aWandererC = aWandererC + ((RotL64(aPrevious, 44U) + aOrbiterB) + RotL64(aOrbiterC, 21U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterA, 37U)) + aOrbiterG);
            aWandererB = aWandererB + ((((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterG, 60U)) + RotL64(aCarry, 37U)) + RotL64(aNonceWordB, 39U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterJ, 11U)) + aOrbiterI) + RotL64(aNonceWordH, 17U));
            aWandererI = aWandererI + ((RotL64(aCross, 23U) + RotL64(aOrbiterJ, 3U)) + aOrbiterB);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 26U) + aOrbiterG) + RotL64(aOrbiterI, 51U)) + aPhaseFWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterC, 39U)) + RotL64(aCarry, 57U)) + aPhaseFWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 54U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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

void TwistExpander_BaseBall_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 4572U)) & S_BLOCK1], 58U) ^ RotL64(aKeyRowReadA[((aIndex + 3387U)) & W_KEY1], 29U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 7351U)) & W_KEY1], 12U) ^ RotL64(mSource[((aIndex + 609U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 56U) ^ RotL64(aIngress, 39U)) + (RotL64(aCross, 5U) + RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (aWandererF + RotL64(aScatter, 39U)) + 12311607308490066301U;
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 5U)) + RotL64(aCarry, 11U)) + 13100864684740679846U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 26U)) + 13697304189274329704U) + aPhaseCOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = (aWandererI + RotL64(aPrevious, 51U)) + 9047976902871216732U;
            aOrbiterB = (aWandererJ + RotL64(aScatter, 11U)) + 2147897579538537888U;
            aOrbiterG = (aWandererK + RotL64(aIngress, 21U)) + 2072444829390996142U;
            aOrbiterH = ((aWandererG + RotL64(aCross, 57U)) + RotL64(aCarry, 35U)) + 2129307836981020908U;
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 43U)) + RotL64(aCarry, 43U)) + 10663145333751112064U;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 30U)) + 15019844390503785459U) + aPhaseCOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 5460865577557928142U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 15806522559993224197U;
            aOrbiterA = RotL64((aOrbiterA * 8722932687972240099U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 6361113778657833389U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 8306013884615042570U;
            aOrbiterG = RotL64((aOrbiterG * 8234258702656728667U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 4038420580499706912U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 11908091484457158973U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3964111175645156719U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 11133912466611921250U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 2469227904206936928U;
            aOrbiterE = RotL64((aOrbiterE * 2704438771198001599U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 13234017916788297295U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 9061117693840451988U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3637440416741459419U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 12013423690843812324U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 14371779015144617412U;
            aOrbiterC = RotL64((aOrbiterC * 3359568073302062667U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 10044883414565441442U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 14334898081890462218U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4878939077928220019U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 13788962593988366125U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 8377887372059713516U;
            aOrbiterJ = RotL64((aOrbiterJ * 1925913354197206851U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 4584439257847749371U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 13335592911357756498U;
            aOrbiterB = RotL64((aOrbiterB * 6515028218115896375U), 43U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 29U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterF, 46U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 29U) + RotL64(aOrbiterE, 50U)) + aOrbiterC) + RotL64(aCarry, 43U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterF, 19U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 18U) + aOrbiterF) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 21U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterC, 11U)) + aOrbiterA);
            aWandererB = aWandererB + ((RotL64(aCross, 11U) + RotL64(aOrbiterE, 23U)) + aOrbiterJ);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterI, 43U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 51U) + aOrbiterF) + RotL64(aOrbiterH, 28U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 4U) + RotL64(aOrbiterB, 3U)) + aOrbiterF);
            aWandererK = aWandererK + ((RotL64(aCross, 35U) + RotL64(aOrbiterB, 39U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 26U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 44U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 13159U)) & S_BLOCK1], 57U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 8975U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 9573U)) & W_KEY1], 37U) ^ RotL64(aKeyRowReadB[((aIndex + 14599U)) & W_KEY1], 52U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aIngress, 6U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = ((aWandererB + RotL64(aCross, 60U)) + 15316464782468770057U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aScatter, 39U)) + 6642872057476351588U;
            aOrbiterE = (aWandererD + RotL64(aPrevious, 47U)) + 660732654689529192U;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 13U)) + 7235418086884000655U;
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 52U)) + RotL64(aCarry, 41U)) + 14784518476694580493U;
            aOrbiterD = ((aWandererH + RotL64(aScatter, 23U)) + RotL64(aCarry, 27U)) + 12222433977933449375U;
            aOrbiterG = ((aWandererG + RotL64(aIngress, 35U)) + 8573001207708329927U) + aPhaseCOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = ((aWandererC + RotL64(aCross, 29U)) + RotL64(aCarry, 3U)) + 16035256260815013172U;
            aOrbiterK = (aWandererI + RotL64(aPrevious, 19U)) + 15767726974121910203U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 17712217935322939971U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 13488963456923357159U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16785285630840310405U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 10222949131965611079U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 1495561412321657209U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9706305581868526265U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 16156530750584361434U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 7773792489045606309U;
            aOrbiterG = RotL64((aOrbiterG * 10730624207715601393U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 11544578291333360613U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 3665587867634242865U;
            aOrbiterA = RotL64((aOrbiterA * 4840528190844842595U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 15248434984650998090U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 15487979645426567581U;
            aOrbiterK = RotL64((aOrbiterK * 10868107809356766183U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 6972347795052712690U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 16074994810010431338U;
            aOrbiterC = RotL64((aOrbiterC * 1262655238856775853U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 16851139687900415292U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 14630026837021552812U;
            aOrbiterJ = RotL64((aOrbiterJ * 9577900853521254603U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 14236330619137368169U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 17778707026111136216U;
            aOrbiterD = RotL64((aOrbiterD * 16239561893843454747U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 9390961969105999083U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 1174881758316573228U;
            aOrbiterI = RotL64((aOrbiterI * 6602061268277529311U), 27U);
            //
            aIngress = RotL64(aOrbiterE, 3U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 48U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + RotL64(aOrbiterC, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 11U) + aOrbiterE) + RotL64(aOrbiterJ, 43U)) + RotL64(aCarry, 27U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterC, 20U)) + aOrbiterE) + aPhaseCWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 27U) + aOrbiterG) + RotL64(aOrbiterJ, 39U)) + aPhaseCWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 41U) + aOrbiterD) + RotL64(aOrbiterE, 57U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 22U) + aOrbiterI) + RotL64(aOrbiterG, 11U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 27U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aScatter, 47U) + aOrbiterH) + RotL64(aOrbiterJ, 51U)) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterC, 34U)) + aOrbiterA);
            aWandererI = aWandererI + ((RotL64(aPrevious, 58U) + aOrbiterG) + RotL64(aOrbiterK, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 38U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 20718U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 19864U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 21904U)) & W_KEY1], 41U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 23422U)) & W_KEY1], 50U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCross, 53U)) + (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 20U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = (aWandererJ + RotL64(aScatter, 11U)) + 11450949896247900941U;
            aOrbiterD = (aWandererB + RotL64(aIngress, 3U)) + 3905542253538116335U;
            aOrbiterA = (((aWandererA + RotL64(aPrevious, 36U)) + RotL64(aCarry, 41U)) + 9529740545977785305U) + aPhaseCOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aCross, 53U)) + 1856876631533143492U;
            aOrbiterB = ((aWandererK + RotL64(aIngress, 23U)) + RotL64(aCarry, 3U)) + 84253466320181686U;
            aOrbiterC = (aWandererF + RotL64(aCross, 19U)) + 12577480918745432444U;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 29U)) + RotL64(aCarry, 53U)) + 5625703170397704029U;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 48U)) + 694608607323629282U;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 57U)) + 3993981243536262204U) + aPhaseCOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 4119215953484892051U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 8785040118556157146U;
            aOrbiterA = RotL64((aOrbiterA * 17113521266125471625U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 16234403619456882890U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 10398727475672860610U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5086871400049644715U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 18327987141759096769U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 2645964788056875452U;
            aOrbiterG = RotL64((aOrbiterG * 8778681366114628045U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 2859452497983106129U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 7196557924940881076U;
            aOrbiterD = RotL64((aOrbiterD * 14415389907490256711U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 930127943984174668U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 15673596916054795749U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7505660488733199479U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 16673140529110941163U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 2258448294877833760U;
            aOrbiterC = RotL64((aOrbiterC * 1821550319748977445U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 6870209259643931219U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 12749790107942194104U;
            aOrbiterJ = RotL64((aOrbiterJ * 4871407285968611725U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 17131374134617173866U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 6426448390733751612U;
            aOrbiterH = RotL64((aOrbiterH * 12490559588384058417U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 15592826434339731146U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 14182944418026376183U;
            aOrbiterF = RotL64((aOrbiterF * 7218860482893476233U), 27U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterD, 22U);
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 43U));
            aIngress = aIngress + RotL64(aOrbiterH, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 35U)) + aOrbiterB) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 37U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterH, 58U)) + aPhaseCWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterH, 27U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 24U) + RotL64(aOrbiterJ, 41U)) + aOrbiterC);
            aWandererA = aWandererA + ((RotL64(aIngress, 51U) + RotL64(aOrbiterF, 23U)) + aOrbiterA);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterA, 14U));
            aWandererF = aWandererF + (((RotL64(aCross, 47U) + aOrbiterC) + RotL64(aOrbiterD, 53U)) + RotL64(aCarry, 51U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterH, 5U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 10U));
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + RotL64(aWandererJ, 29U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 24927U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26634U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32250U)) & S_BLOCK1], 46U) ^ RotL64(mSource[((aIndex + 28253U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCross, 58U)) ^ (RotL64(aCarry, 27U) ^ RotL64(aIngress, 13U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 43U)) + 4476099022490972343U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aIngress, 58U)) + 16836423700375760429U;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 13U)) + RotL64(aCarry, 21U)) + 8850577488928703557U;
            aOrbiterG = (aWandererB + RotL64(aScatter, 47U)) + 7091631824560042743U;
            aOrbiterA = (aWandererK + RotL64(aIngress, 51U)) + 12560498899956759494U;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 3U)) + RotL64(aCarry, 35U)) + 7797973377112012161U;
            aOrbiterK = ((aWandererE + RotL64(aScatter, 37U)) + RotL64(aCarry, 43U)) + 6173820673874805794U;
            aOrbiterH = (aWandererD + RotL64(aCross, 18U)) + 10805025132310245348U;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 29U)) + 7139216143268029968U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 8241544862261635722U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 4735527016563596150U;
            aOrbiterE = RotL64((aOrbiterE * 6621354217673598381U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 5166171126690294033U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 11117641762075368393U;
            aOrbiterA = RotL64((aOrbiterA * 4980156869201219393U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 6312932356458415421U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 1304139291184508668U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 90744653170922319U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 10085025354842771067U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 16745854428789531080U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1945983905747274355U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 2497187958708890337U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 16069701876646548995U;
            aOrbiterG = RotL64((aOrbiterG * 16606039730973709495U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 17242004368025978091U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 12334315722243232121U;
            aOrbiterB = RotL64((aOrbiterB * 16528598396696346719U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 8007042082518126895U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 5665686359038811484U;
            aOrbiterH = RotL64((aOrbiterH * 11289316305875751813U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 3913477186958600592U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 16918984318564170343U;
            aOrbiterJ = RotL64((aOrbiterJ * 5128293326494417281U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 10227611546502931418U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 7187623463085447228U;
            aOrbiterI = RotL64((aOrbiterI * 8479839369622163181U), 47U);
            //
            aIngress = RotL64(aOrbiterB, 43U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 6U));
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 37U));
            aIngress = aIngress + RotL64(aOrbiterJ, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterC, 29U)) + aOrbiterI);
            aWandererK = aWandererK + (((RotL64(aPrevious, 43U) + aOrbiterG) + RotL64(aOrbiterA, 4U)) + RotL64(aCarry, 13U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterI, 41U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 50U) + aOrbiterB) + RotL64(aOrbiterC, 37U)) + RotL64(aCarry, 23U)) + aPhaseCWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 47U)) + aOrbiterJ) + aPhaseCWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 5U) + RotL64(aOrbiterA, 57U)) + aOrbiterJ);
            aWandererF = aWandererF ^ ((RotL64(aCross, 23U) + aOrbiterA) + RotL64(aOrbiterK, 12U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 56U) + RotL64(aOrbiterB, 21U)) + aOrbiterH);
            aWandererH = aWandererH ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterA, 51U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererK, 12U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 19U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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

void TwistExpander_BaseBall_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterJ = 0;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 6017U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((aIndex + 7905U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 8179U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 3503U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 13U) + RotL64(aCarry, 27U)) + (RotL64(aIngress, 43U) ^ RotL64(aCross, 60U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = ((aWandererA + RotL64(aScatter, 29U)) + RotL64(aCarry, 3U)) + 7651355040951791298U;
            aOrbiterB = ((aWandererI + RotL64(aCross, 21U)) + 13988210277931659312U) + aPhaseDOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = (((aWandererD + RotL64(aIngress, 56U)) + RotL64(aCarry, 27U)) + 9846849412579537783U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 37U)) + RotL64(aCarry, 51U)) + 12746719939495876158U;
            aOrbiterH = (aWandererG + RotL64(aIngress, 5U)) + 11498066185182895284U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 11101058955193080232U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 15513734459555672046U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6974281215677538561U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 15711108675349394643U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 4771231759949468556U;
            aOrbiterK = RotL64((aOrbiterK * 9806191054594333615U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 11449258010811305256U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 17036938391509986723U;
            aOrbiterJ = RotL64((aOrbiterJ * 7411466953205347639U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 6999245666776654250U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 2106819066263369528U;
            aOrbiterB = RotL64((aOrbiterB * 13005885810757743129U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 12716183358903477216U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 16752724547046059889U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11475905692393034141U), 3U);
            //
            aIngress = RotL64(aOrbiterE, 29U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 39U) + aOrbiterE) + RotL64(aOrbiterH, 43U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 27U)) + aOrbiterJ) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 13U)) + aOrbiterK);
            aWandererG = aWandererG + (((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 5U)) + aOrbiterB) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 48U) + aOrbiterJ) + RotL64(aOrbiterK, 58U)) + aPhaseDWandererUpdateSaltD[((aIndex + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 56U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 8224U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneD[((aIndex + 14507U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12512U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((aIndex + 11504U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 51U) + RotL64(aCross, 10U)) + (RotL64(aCarry, 23U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 21U)) + RotL64(aCarry, 57U)) + 10812151398716051703U;
            aOrbiterB = (aWandererG + RotL64(aCross, 29U)) + 18202551453336003710U;
            aOrbiterG = (((aWandererB + RotL64(aScatter, 5U)) + RotL64(aCarry, 37U)) + 9434410809101973752U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 41U)) + RotL64(aCarry, 13U)) + 12955829998028534045U;
            aOrbiterK = ((aWandererF + RotL64(aCross, 54U)) + 12271740641929640181U) + aPhaseDOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 14009351527014534752U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 4316296955679133450U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11582128345511775161U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 16473324966997442872U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 15735123324965019802U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5624078184997601019U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 17656375090484080236U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 16066325053456055298U;
            aOrbiterJ = RotL64((aOrbiterJ * 17912970706985130327U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 12908968778503516903U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 12761433987676836197U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1023329467480907925U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 12737513138040664509U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 14535795767570998392U;
            aOrbiterH = RotL64((aOrbiterH * 15560519667062222269U), 35U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 13U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterJ, 43U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 3U) + aOrbiterH) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 39U)) + aPhaseDWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 14U) + aOrbiterG) + RotL64(aOrbiterK, 35U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterJ, 51U)) + aOrbiterK) + RotL64(aCarry, 19U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterH, 18U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 21U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 20270U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 16600U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19537U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 22142U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 6U) + RotL64(aIngress, 37U)) ^ (RotL64(aCross, 57U) + RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = ((aWandererD + RotL64(aCross, 21U)) + RotL64(aCarry, 23U)) + 12535417189990029950U;
            aOrbiterA = ((aWandererF + RotL64(aScatter, 43U)) + 6204401443676390273U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = ((aWandererC + RotL64(aIngress, 60U)) + RotL64(aCarry, 39U)) + 869613505613154672U;
            aOrbiterJ = (((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 5U)) + 15053590879563855802U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = (aWandererK + RotL64(aIngress, 35U)) + 13338989605204591428U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 18306470022403825392U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 1150696349434090218U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1099447646821052165U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 13549541786420596437U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 14302878430259588461U;
            aOrbiterA = RotL64((aOrbiterA * 16813606782134305513U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 4660437084477165225U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 1653628537860912069U;
            aOrbiterD = RotL64((aOrbiterD * 2624835201155303123U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 5594199757006711631U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 11008472193138708891U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13645764762027798301U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 3668516817279364310U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 128159531749679984U;
            aOrbiterH = RotL64((aOrbiterH * 4523246859249826987U), 41U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterA, 30U);
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 13U) + aOrbiterH) + RotL64(aOrbiterK, 13U));
            aWandererK = aWandererK + (((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterA, 58U)) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 46U) + aOrbiterJ) + RotL64(aOrbiterK, 41U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterD, 21U)) + aOrbiterA) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterH, 29U)) + aOrbiterA) + aPhaseDWandererUpdateSaltA[((aIndex + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 28U));
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererC, 57U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 25181U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((aIndex + 26750U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28399U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneD[((aIndex + 29309U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aPrevious, 53U)) ^ (RotL64(aCarry, 3U) + RotL64(aIngress, 18U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = (aWandererA + RotL64(aCross, 37U)) + 5721224134332887360U;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 48U)) + RotL64(aCarry, 21U)) + 6892749729775049095U;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 23U)) + RotL64(aCarry, 43U)) + 3884839462099556836U;
            aOrbiterD = (((aWandererD + RotL64(aScatter, 57U)) + RotL64(aCarry, 5U)) + 4365431706830216193U) + aPhaseDOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aCross, 3U)) + 15501528746571578773U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 4505911326320650606U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 1865129050927879580U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9198152644404068721U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 2011737665969640369U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 611672935827062688U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12873671551304596619U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 663547038310431047U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 5468932264754299556U;
            aOrbiterD = RotL64((aOrbiterD * 11968657455484578525U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 17920294117231191705U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 486058453837528110U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8851102552244026737U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 2789178451938129313U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 420772587981211184U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17402987842294006667U), 27U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 13U);
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 3U)) + aOrbiterD) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 56U) + aOrbiterC) + RotL64(aOrbiterD, 58U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 39U) + aOrbiterC) + RotL64(aOrbiterA, 19U)) + RotL64(aCarry, 13U)) + aPhaseDWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterD, 39U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 26U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererD, 11U);
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

void TwistExpander_BaseBall_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 4848U)) & S_BLOCK1], 24U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4397U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7743U)) & S_BLOCK1], 24U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 5134U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aIngress, 37U)) ^ (RotL64(aPrevious, 50U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = ((aWandererF + RotL64(aCross, 3U)) + 16016931609704150191U) + aPhaseEOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aIngress, 51U)) + RotL64(aCarry, 5U)) + 14511433515861302636U;
            aOrbiterB = (aWandererK + RotL64(aPrevious, 20U)) + 11691237442613269593U;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 57U)) + RotL64(aCarry, 19U)) + 16383220587320484649U;
            aOrbiterH = (((aWandererC + RotL64(aPrevious, 43U)) + RotL64(aCarry, 35U)) + 14293015313458219868U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (aWandererH + RotL64(aCross, 11U)) + 4407695248205526670U;
            aOrbiterF = (aWandererI + RotL64(aScatter, 27U)) + 1158323195324398372U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 6577683409653864555U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 171080079472863843U;
            aOrbiterB = RotL64((aOrbiterB * 3063978974927752653U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 5766333425872228205U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 16173508656917582960U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12187968015372936695U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 11781450063402219202U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 13033139686637576694U;
            aOrbiterD = RotL64((aOrbiterD * 4331137994135472025U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 4006310759400926020U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 13156817947481574467U;
            aOrbiterF = RotL64((aOrbiterF * 563189239835001483U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 12791290558893516411U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 989729955679243234U;
            aOrbiterK = RotL64((aOrbiterK * 8757228712495095017U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 838379839663022790U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 2830743864262313606U;
            aOrbiterG = RotL64((aOrbiterG * 10173947177104802797U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 2146646527331684652U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 4629168181742174906U;
            aOrbiterC = RotL64((aOrbiterC * 9046124907945045131U), 29U);
            //
            aIngress = RotL64(aOrbiterK, 53U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 60U));
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterH, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 53U) + aOrbiterG) + RotL64(aOrbiterB, 53U));
            aWandererF = aWandererF + (((RotL64(aIngress, 23U) + aOrbiterD) + RotL64(aOrbiterC, 23U)) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterH, 47U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterK, 30U)) + aOrbiterF) + RotL64(aCarry, 29U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 11U) + aOrbiterC) + RotL64(aOrbiterK, 3U));
            aWandererH = aWandererH + ((RotL64(aIngress, 60U) + RotL64(aOrbiterH, 41U)) + aOrbiterK);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterK, 11U)) + aOrbiterB) + aPhaseEWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 20U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9659U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 12024U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 13863U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10426U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCross, 53U)) + (RotL64(aCarry, 38U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = (((aWandererJ + RotL64(aPrevious, 53U)) + RotL64(aCarry, 51U)) + 14157904117287696136U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = (aWandererC + RotL64(aCross, 37U)) + 7369512677371640676U;
            aOrbiterK = (aWandererG + RotL64(aScatter, 43U)) + 8411250745902073798U;
            aOrbiterH = (aWandererE + RotL64(aIngress, 23U)) + 5002041814539710275U;
            aOrbiterB = ((aWandererB + RotL64(aCross, 29U)) + RotL64(aCarry, 35U)) + 9538041410816283124U;
            aOrbiterD = (aWandererK + RotL64(aIngress, 60U)) + 5210700103927513061U;
            aOrbiterF = (((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 7600709399101287982U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 2366369466696580499U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 5544575244203019109U;
            aOrbiterK = RotL64((aOrbiterK * 16231219246786333057U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 8710073749110329779U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 15998211310115361630U;
            aOrbiterI = RotL64((aOrbiterI * 15275657696897688955U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 15354357553877376422U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 10657523549259276169U;
            aOrbiterH = RotL64((aOrbiterH * 13695239532898311073U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 10405750198355464768U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 3465819693133515142U;
            aOrbiterG = RotL64((aOrbiterG * 14678343718277562799U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 16724189641701408630U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 3484340153620198872U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17247547677520703125U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 7420442404884871126U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 11138445997256757636U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11167543379937571127U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 1428191560884663125U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 16950093140800653985U;
            aOrbiterF = RotL64((aOrbiterF * 4423012306984814805U), 47U);
            //
            aIngress = RotL64(aOrbiterB, 19U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterG, 11U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterI, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 21U)) + aOrbiterB) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 34U) + RotL64(aOrbiterK, 27U)) + aOrbiterI) + aPhaseEWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 21U) + aOrbiterI) + RotL64(aOrbiterF, 35U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterG, 47U)) + aOrbiterI);
            aWandererE = aWandererE + ((RotL64(aCross, 13U) + aOrbiterK) + RotL64(aOrbiterH, 58U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 13U)) + aOrbiterF) + aPhaseEWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 5U)) + aOrbiterD) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 12U));
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererG, 41U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 16866U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((aIndex + 19011U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 23309U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 20690U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 20U) ^ RotL64(aCarry, 3U)) + (RotL64(aIngress, 37U) + RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = ((aWandererI + RotL64(aScatter, 4U)) + RotL64(aCarry, 37U)) + 13924571355038625040U;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 47U)) + RotL64(aCarry, 5U)) + 16328300979357156658U;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 41U)) + 3947771961206012461U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 35U)) + 15428284250569311285U;
            aOrbiterG = ((aWandererB + RotL64(aScatter, 27U)) + 5777369485254032486U) + aPhaseEOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aCross, 13U)) + 16813320300717644673U;
            aOrbiterH = ((aWandererK + RotL64(aIngress, 19U)) + RotL64(aCarry, 19U)) + 16689933050200758251U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 1856422419049390708U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 18214498743831925517U;
            aOrbiterC = RotL64((aOrbiterC * 10744120577560529379U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 18278550878494094923U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 797712062039591797U;
            aOrbiterE = RotL64((aOrbiterE * 7212998747080137625U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 15854849439012341347U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 996882939768167773U;
            aOrbiterB = RotL64((aOrbiterB * 14936703950807908575U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 3005829974130671692U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 8793495343509953906U;
            aOrbiterJ = RotL64((aOrbiterJ * 14065479348374612031U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 7710453029930631112U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 9511995836117707047U;
            aOrbiterG = RotL64((aOrbiterG * 7250766204781428201U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 670902975693341744U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 9045820304668279777U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 18373074917532639027U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 12417212387607119470U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 12816983560669985622U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8406003970221889847U), 5U);
            //
            aIngress = RotL64(aOrbiterG, 5U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 51U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 23U) + aOrbiterC) + RotL64(aOrbiterE, 19U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterH, 41U)) + aOrbiterC) + RotL64(aCarry, 5U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 29U) + aOrbiterJ) + RotL64(aOrbiterE, 47U));
            aWandererK = aWandererK + ((RotL64(aScatter, 35U) + RotL64(aOrbiterG, 53U)) + aOrbiterJ);
            aWandererB = aWandererB ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterE, 35U)) + aOrbiterB);
            aWandererG = aWandererG + (((RotL64(aScatter, 11U) + aOrbiterC) + RotL64(aOrbiterI, 26U)) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 4U) + RotL64(aOrbiterB, 5U)) + aOrbiterG) + aPhaseEWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 6U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 58U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 29188U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((aIndex + 28766U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28811U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 31121U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 53U)) + (RotL64(aIngress, 38U) + RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = ((aWandererF + RotL64(aCross, 47U)) + 9435962834163239322U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aIngress, 3U)) + 10524704356081318973U;
            aOrbiterF = (((aWandererD + RotL64(aScatter, 29U)) + RotL64(aCarry, 13U)) + 7403401305665208680U) + aPhaseEOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 57U)) + RotL64(aCarry, 51U)) + 7525414805023556493U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 11U)) + RotL64(aCarry, 35U)) + 1116686470029070951U;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 38U)) + 13257612299137802420U;
            aOrbiterD = (aWandererH + RotL64(aCross, 23U)) + 9181543003986598283U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 9739384852307501107U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 11308402900229016057U;
            aOrbiterF = RotL64((aOrbiterF * 12690186771773188967U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 14935167593705272337U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 7171824007631943535U;
            aOrbiterC = RotL64((aOrbiterC * 4839974427616194289U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 8068411284829563567U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 12350207458513447578U;
            aOrbiterA = RotL64((aOrbiterA * 813973258659041895U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 17039236343991574134U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 18291683592714999632U;
            aOrbiterK = RotL64((aOrbiterK * 7771718817924840713U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 6239616841884430968U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 10604527977569876774U;
            aOrbiterJ = RotL64((aOrbiterJ * 6972820410084939637U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 1707724300671717658U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 3802268808625297647U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11296811630387191563U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 9423064323799920219U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 242153923313096551U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12117679073775630197U), 13U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterA, 21U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 3U) + aOrbiterK) + RotL64(aOrbiterG, 4U));
            aWandererD = aWandererD + (((RotL64(aIngress, 27U) + aOrbiterA) + RotL64(aOrbiterJ, 51U)) + RotL64(aCarry, 11U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterC, 57U)) + aOrbiterG);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 47U) + aOrbiterD) + RotL64(aOrbiterC, 29U)) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 10U) + aOrbiterD) + RotL64(aOrbiterJ, 11U)) + aPhaseEWandererUpdateSaltF[((aIndex + 16U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 21U) + aOrbiterG) + RotL64(aOrbiterF, 35U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterF, 41U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererE, 22U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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

void TwistExpander_BaseBall_Arx::Twist_D(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 5904U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3584U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5613U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((aIndex + 2230U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 24U) ^ RotL64(aPrevious, 3U)) ^ (RotL64(aIngress, 37U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 57U)) + RotL64(aCarry, 13U)) + 7790166497945719700U;
            aOrbiterC = ((aWandererE + RotL64(aCross, 19U)) + RotL64(aCarry, 27U)) + 7136208896846119188U;
            aOrbiterF = ((aWandererH + RotL64(aIngress, 29U)) + 12123156943355100886U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = ((aWandererG + RotL64(aScatter, 39U)) + RotL64(aCarry, 39U)) + 5095546037880875199U;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 10U)) + 17642705393916765992U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 9918479837334416990U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 4890009823843176466U;
            aOrbiterF = RotL64((aOrbiterF * 16898633181256061239U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 17652590786213674124U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 870002527644696135U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 915408393979165539U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 12545429703552643682U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 5310272867406182581U;
            aOrbiterG = RotL64((aOrbiterG * 10420003334833925011U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 3264719049050179440U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 1967241238180278937U;
            aOrbiterC = RotL64((aOrbiterC * 13004319774269457957U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 773883832927040736U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 12766817190261232485U;
            aOrbiterJ = RotL64((aOrbiterJ * 7448864556802318431U), 53U);
            //
            aIngress = RotL64(aOrbiterI, 57U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + RotL64(aOrbiterF, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 10U) + aOrbiterG) + RotL64(aOrbiterC, 39U)) + aPhaseFWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterJ, 21U)) + aOrbiterC);
            aWandererF = aWandererF + (((RotL64(aScatter, 57U) + aOrbiterI) + RotL64(aOrbiterF, 29U)) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterJ, 3U)) + aOrbiterF);
            aWandererC = aWandererC + ((((RotL64(aCross, 47U) + RotL64(aOrbiterI, 54U)) + aOrbiterJ) + RotL64(aCarry, 11U)) + aPhaseFWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 23U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 16014U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 8479U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13962U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 13453U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 29U) ^ RotL64(aPrevious, 57U)) ^ (RotL64(aIngress, 42U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = (((aWandererA + RotL64(aPrevious, 57U)) + RotL64(aCarry, 19U)) + 4970414922752555648U) + aPhaseFOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aIngress, 13U)) + 9462756592787669327U;
            aOrbiterG = ((aWandererD + RotL64(aCross, 5U)) + RotL64(aCarry, 5U)) + 3948790686662213095U;
            aOrbiterD = (((aWandererC + RotL64(aScatter, 46U)) + RotL64(aCarry, 47U)) + 14542857212241578311U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = (aWandererG + RotL64(aPrevious, 35U)) + 3387479009827029547U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 1411421370057797877U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 16894451466895681236U;
            aOrbiterG = RotL64((aOrbiterG * 13825974818858676215U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 12727136462290223542U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 4625389198191960525U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5726474430977810191U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 3471881403786164913U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 6433115856048534831U;
            aOrbiterJ = RotL64((aOrbiterJ * 9363233870194144053U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 9825592965466157982U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 1553125767261293088U;
            aOrbiterB = RotL64((aOrbiterB * 411535191177308781U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 9951616357109647617U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 11231080382787286889U;
            aOrbiterD = RotL64((aOrbiterD * 14024961994986659187U), 47U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterA, 47U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterG, 14U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterA, 53U)) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 3U) + aOrbiterB) + RotL64(aOrbiterD, 27U));
            aWandererB = aWandererB + ((((RotL64(aCross, 21U) + aOrbiterJ) + RotL64(aOrbiterB, 37U)) + RotL64(aCarry, 5U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 12U) + RotL64(aOrbiterA, 19U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 35U) + RotL64(aOrbiterD, 10U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 23866U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((aIndex + 18180U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17277U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 23144U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 4U) + RotL64(aCarry, 51U)) ^ (RotL64(aCross, 35U) ^ RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = (((aWandererD + RotL64(aScatter, 26U)) + RotL64(aCarry, 5U)) + 5576732410244514238U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aCross, 11U)) + 2833808925935929629U) + aPhaseFOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aIngress, 3U)) + RotL64(aCarry, 29U)) + 3670188682914544792U;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 53U)) + RotL64(aCarry, 57U)) + 15759072378887814995U;
            aOrbiterH = (aWandererA + RotL64(aCross, 37U)) + 13934007231137439994U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 11022225696007690512U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 16989177104453635790U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14156758251105809453U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 9256930045263527091U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 17788596104417068290U;
            aOrbiterK = RotL64((aOrbiterK * 675554110563253305U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 17044369456673337625U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 1310908395523250343U;
            aOrbiterE = RotL64((aOrbiterE * 16305084373037705921U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 12067065689034065422U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 15130844248737512262U;
            aOrbiterG = RotL64((aOrbiterG * 9409499577465934107U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 14532689204495587494U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 8198147292120244178U;
            aOrbiterH = RotL64((aOrbiterH * 1418356389507740991U), 23U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 43U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + RotL64(aOrbiterK, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 48U) + RotL64(aOrbiterF, 51U)) + aOrbiterG);
            aWandererD = aWandererD + (((RotL64(aCross, 39U) + RotL64(aOrbiterF, 41U)) + aOrbiterK) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 13U)) + aOrbiterH) + aPhaseFWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 5U) + aOrbiterG) + RotL64(aOrbiterE, 28U)) + RotL64(aCarry, 27U)) + aPhaseFWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 3U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + RotL64(aWandererJ, 4U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 26332U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24603U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25041U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((aIndex + 31425U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCross, 57U)) + (RotL64(aPrevious, 24U) + RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = ((aWandererJ + RotL64(aCross, 13U)) + RotL64(aCarry, 39U)) + 4752759164691497960U;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 36U)) + RotL64(aCarry, 51U)) + 12088872623537639782U;
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 47U)) + 3734943577379734227U) + aPhaseFOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = (((aWandererG + RotL64(aIngress, 21U)) + RotL64(aCarry, 21U)) + 8854778183012444234U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = (aWandererF + RotL64(aCross, 5U)) + 16948373492893967275U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 7962415690046184385U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 1872682375669714454U;
            aOrbiterJ = RotL64((aOrbiterJ * 959061892772099785U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 7776801806943853566U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 16665439117257230732U;
            aOrbiterD = RotL64((aOrbiterD * 6866375628213114965U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 11088186766134265676U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 10850237991780969350U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7547414856143095121U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 6464817712131305812U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 244557182884209844U;
            aOrbiterG = RotL64((aOrbiterG * 2394270354887582889U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 13261563971157415841U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 2323811103717827362U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11483723582415081925U), 3U);
            //
            aIngress = RotL64(aOrbiterJ, 5U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 58U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 36U) + RotL64(aOrbiterJ, 27U)) + aOrbiterF);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 41U)) + aOrbiterI) + RotL64(aCarry, 51U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterG, 56U)) + aOrbiterD) + aPhaseFWandererUpdateSaltE[((aIndex + 22U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 47U) + RotL64(aOrbiterI, 19U)) + aOrbiterF) + RotL64(aCarry, 29U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 11U) + aOrbiterD) + RotL64(aOrbiterF, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 12U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + RotL64(aWandererC, 43U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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

void TwistExpander_BaseBall_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 2823U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 5716U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 1117U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 4075U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 56U) + RotL64(aPrevious, 5U)) + (RotL64(aCarry, 35U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = (((aWandererF + RotL64(aIngress, 3U)) + RotL64(aCarry, 57U)) + 12222235191147985484U) + aPhaseGOrbiterAssignSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 39U)) + RotL64(aCarry, 5U)) + 16367317014523328414U;
            aOrbiterF = (((aWandererD + RotL64(aCross, 11U)) + RotL64(aCarry, 27U)) + 3511378091284703789U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aScatter, 28U)) + 15247492830966725949U;
            aOrbiterC = (aWandererH + RotL64(aCross, 53U)) + 7745995913390407897U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 6463593307540108810U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 1101669311005268630U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10550146460887359369U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 12988052764067518580U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 17717179747434679772U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10820310705487638793U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 11662190906682400416U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 6563014073547628748U;
            aOrbiterH = RotL64((aOrbiterH * 16967910471722117761U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 13099094932059419219U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 16342730862261868847U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10988124108686164829U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 16855346813127524624U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 6570063128502306944U;
            aOrbiterC = RotL64((aOrbiterC * 4571570049463124831U), 23U);
            //
            aIngress = RotL64(aOrbiterA, 21U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterC, 3U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 27U) + aOrbiterH) + RotL64(aOrbiterE, 51U)) + RotL64(aCarry, 27U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 40U) + aOrbiterE) + RotL64(aOrbiterC, 11U)) + aPhaseGWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 53U) + RotL64(aOrbiterC, 29U)) + aOrbiterF) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterA, 20U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + RotL64(aWandererF, 21U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 8443U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneC[((aIndex + 15074U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 12734U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 10985U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCarry, 54U)) + (RotL64(aCross, 39U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = (aWandererG + RotL64(aPrevious, 13U)) + 4980738603982643969U;
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 58U)) + RotL64(aCarry, 5U)) + 17660278413018470020U;
            aOrbiterE = ((aWandererH + RotL64(aCross, 29U)) + RotL64(aCarry, 41U)) + 17598114429859543466U;
            aOrbiterC = (((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 21U)) + 10993929335279994739U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = ((aWandererD + RotL64(aCross, 47U)) + 17967203122976322481U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 1872290205549034384U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 16607778671782810797U;
            aOrbiterE = RotL64((aOrbiterE * 340054507611349681U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 4895226930754394376U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 14960359005982301383U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8546231310054433721U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 9921642352377700630U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 893281964367208693U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2345509157333444217U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 8232519988397858732U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 4433022122758913407U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 834240393225479419U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 12689609831247168353U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 404535388957472176U;
            aOrbiterC = RotL64((aOrbiterC * 14534020545479806593U), 3U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 13U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + RotL64(aOrbiterE, 52U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 29U) + aOrbiterD) + RotL64(aOrbiterC, 3U));
            aWandererH = aWandererH + ((((RotL64(aCross, 60U) + RotL64(aOrbiterJ, 24U)) + aOrbiterB) + RotL64(aCarry, 11U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 51U) + aOrbiterE) + RotL64(aOrbiterC, 51U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 11U) + aOrbiterB) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterB, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 34U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 19407U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneD[((aIndex + 19373U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23548U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneB[((aIndex + 18101U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 47U) ^ RotL64(aCarry, 22U)) ^ (RotL64(aIngress, 5U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 5U)) + RotL64(aCarry, 47U)) + 3105313968748067810U;
            aOrbiterH = (aWandererE + RotL64(aScatter, 36U)) + 9977249451119627064U;
            aOrbiterK = (((aWandererC + RotL64(aIngress, 51U)) + RotL64(aCarry, 11U)) + 17941392803495349366U) + aPhaseGOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = ((aWandererG + RotL64(aCross, 13U)) + 4279533326705471133U) + aPhaseGOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = ((aWandererB + RotL64(aScatter, 27U)) + RotL64(aCarry, 23U)) + 13983828966811580039U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 3983490984234810378U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 308786542215259956U;
            aOrbiterK = RotL64((aOrbiterK * 4366245356597769425U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 8443607695364427037U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 14939626441464340668U;
            aOrbiterH = RotL64((aOrbiterH * 16793255020331774983U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 9350693577306121110U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 1717071159396961752U;
            aOrbiterD = RotL64((aOrbiterD * 11062480662625054525U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 15911765265202100610U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 14898546272333182767U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2674900543810733067U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 3560903518513465868U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 5367062725726860234U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8521908836601319553U), 47U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterG, 41U);
            aIngress = aIngress + (RotL64(aOrbiterK, 53U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 11U)) + aOrbiterK);
            aWandererF = aWandererF ^ ((RotL64(aCross, 58U) + aOrbiterH) + RotL64(aOrbiterD, 60U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterI, 43U)) + aOrbiterH) + RotL64(aCarry, 43U)) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 47U) + aOrbiterK) + RotL64(aOrbiterG, 51U)) + aPhaseGWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 11U) + RotL64(aOrbiterD, 29U)) + aOrbiterI) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 26956U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30357U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24713U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 32338U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 39U)) ^ (RotL64(aCross, 57U) + RotL64(aIngress, 14U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 35U)) + 18255347001097480328U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = ((aWandererE + RotL64(aIngress, 5U)) + RotL64(aCarry, 19U)) + 13679246790311505735U;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 23U)) + 10565839529765027116U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = ((aWandererB + RotL64(aCross, 53U)) + RotL64(aCarry, 3U)) + 14327172566224769901U;
            aOrbiterF = ((aWandererI + RotL64(aScatter, 44U)) + RotL64(aCarry, 53U)) + 16239024612038195174U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 13800012174212131890U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 13900288860157577583U;
            aOrbiterD = RotL64((aOrbiterD * 13177682776510523095U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 4144386119777112740U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 3154558262670631372U;
            aOrbiterE = RotL64((aOrbiterE * 13236911910092437063U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 7456728543137614001U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 11709519851158935384U;
            aOrbiterH = RotL64((aOrbiterH * 7016689518570071587U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 15607438907832240304U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 9276575329661725624U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8879744070762412745U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 6459435969129449226U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 6442382118416542275U;
            aOrbiterF = RotL64((aOrbiterF * 2921027306686588233U), 27U);
            //
            aIngress = RotL64(aOrbiterE, 13U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterE, 47U)) + aOrbiterK) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterE, 13U));
            aWandererB = aWandererB + (((RotL64(aScatter, 11U) + aOrbiterH) + RotL64(aOrbiterD, 27U)) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 30U) + aOrbiterH) + RotL64(aOrbiterE, 58U)) + aPhaseGWandererUpdateSaltA[((aIndex + 10U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterH, 39U)) + aPhaseGWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererI, 22U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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

void TwistExpander_BaseBall_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 4849U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneB[((aIndex + 7687U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2823U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 2410U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aPrevious, 36U)) ^ (RotL64(aIngress, 51U) + RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = (((aWandererB + RotL64(aIngress, 13U)) + RotL64(aCarry, 27U)) + 3550722402315312207U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 5U)) + 16724184551669522754U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = (aWandererD + RotL64(aScatter, 58U)) + 981751330116773021U;
            aOrbiterK = ((aWandererI + RotL64(aCross, 41U)) + RotL64(aCarry, 43U)) + 7891159229704944868U;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 29U)) + RotL64(aCarry, 13U)) + 13618396711464799841U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 5969291018449003648U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 14595540413313640042U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8151104319012840963U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 3287990436916111762U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 12534369400200483704U;
            aOrbiterE = RotL64((aOrbiterE * 2345945228434740707U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 2277312067930392274U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 10026320559261334353U;
            aOrbiterK = RotL64((aOrbiterK * 11020464940995912637U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 11258082063135659551U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 1445958517675746990U;
            aOrbiterD = RotL64((aOrbiterD * 10062265337488757971U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 1011298251290970844U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 6487834862470043744U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15477913837027179675U), 5U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterD, 56U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterJ, 19U)) + aOrbiterE) + RotL64(aCarry, 5U)) + aPhaseHWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterD, 53U)) + aOrbiterA);
            aWandererD = aWandererD + (((RotL64(aPrevious, 37U) + aOrbiterK) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 46U) + aOrbiterJ) + RotL64(aOrbiterA, 38U));
            aWandererI = aWandererI + (((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 11U)) + aOrbiterK) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 13853U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneC[((aIndex + 12857U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12039U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15561U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 24U) ^ RotL64(aIngress, 51U)) + (RotL64(aPrevious, 37U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = (((aWandererD + RotL64(aScatter, 44U)) + RotL64(aCarry, 5U)) + 7893287783892523139U) + aPhaseHOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = ((aWandererA + RotL64(aCross, 3U)) + RotL64(aCarry, 53U)) + 10257331997383491153U;
            aOrbiterE = (aWandererE + RotL64(aPrevious, 57U)) + 14562226733652231753U;
            aOrbiterC = (((aWandererC + RotL64(aIngress, 21U)) + RotL64(aCarry, 39U)) + 14320342577110737851U) + aPhaseHOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aScatter, 29U)) + 9816717579822880756U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 9558926960095881953U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 9230371862654338324U;
            aOrbiterE = RotL64((aOrbiterE * 8842712825810461561U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 6414274291252913420U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 13868546184398350849U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1547986864837497409U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 16940736952569949038U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 2866957764814864371U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3554702178644797003U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 7916721976073979724U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 1602444214978842275U;
            aOrbiterH = RotL64((aOrbiterH * 11072503711308122385U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 9529061385251008037U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 8402775110887376588U;
            aOrbiterC = RotL64((aOrbiterC * 13980225144628227381U), 51U);
            //
            aIngress = RotL64(aOrbiterE, 47U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 24U));
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 43U)) + aOrbiterJ) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterC, 5U)) + aOrbiterH);
            aWandererD = aWandererD + ((((RotL64(aIngress, 39U) + aOrbiterE) + RotL64(aOrbiterA, 19U)) + RotL64(aCarry, 19U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterA, 54U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 18U) + RotL64(aOrbiterJ, 35U)) + aOrbiterH) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 14U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 35U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 24473U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18643U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18476U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((aIndex + 16744U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 52U)) ^ (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = (aWandererK + RotL64(aPrevious, 3U)) + 2168513956284366370U;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 12U)) + 10290361969974613111U) + aPhaseHOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aIngress, 35U)) + RotL64(aCarry, 3U)) + 15673836275828498050U;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 43U)) + RotL64(aCarry, 43U)) + 16600540024145812236U;
            aOrbiterD = (((aWandererF + RotL64(aScatter, 21U)) + RotL64(aCarry, 29U)) + 9428052101528111892U) + aPhaseHOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 12763657928312763377U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 10751286982008662485U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6169084301655877217U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 1708230173038057979U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 4011389705422783816U;
            aOrbiterH = RotL64((aOrbiterH * 11692237130784795961U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 11704428328093077714U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 2055336619674699284U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6374289210096410907U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 1870865272102705804U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 3574214263751923179U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13132083406834413563U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 984611970726966186U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 15207945449947643672U;
            aOrbiterD = RotL64((aOrbiterD * 9539470161576639981U), 13U);
            //
            aIngress = RotL64(aOrbiterA, 6U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 43U));
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterH, 51U)) + RotL64(aCarry, 21U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 3U)) + aOrbiterE) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 11U)) + aOrbiterA) + RotL64(aCarry, 53U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 12U) + aOrbiterD) + RotL64(aOrbiterA, 26U));
            aWandererC = aWandererC + ((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterE, 35U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 52U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 25055U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneA[((aIndex + 30907U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31255U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 29364U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aIngress, 53U)) + (RotL64(aPrevious, 41U) + RotL64(aCarry, 4U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = (((aWandererA + RotL64(aPrevious, 11U)) + RotL64(aCarry, 5U)) + 16424657151168221875U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = ((aWandererE + RotL64(aCross, 47U)) + RotL64(aCarry, 37U)) + 17150123681886380361U;
            aOrbiterE = (aWandererI + RotL64(aScatter, 27U)) + 16041993588694572757U;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 38U)) + RotL64(aCarry, 51U)) + 9871185846434828537U;
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 57U)) + 11227236398354430757U) + aPhaseHOrbiterAssignSaltB[((aIndex + 14U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 5399325217402192631U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 9248828789282890454U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6733832755349139621U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 9041370494203701062U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 14944424084524970764U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10283363059424655079U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 5481938174456671041U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 14783648629543752715U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7260164783191886395U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 12355573914530445723U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 9863991559011968318U;
            aOrbiterK = RotL64((aOrbiterK * 8495251211794343179U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 16149688605937250965U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 106041828692026825U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12199934305374582599U), 27U);
            //
            aIngress = RotL64(aOrbiterD, 29U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 4U) + RotL64(aOrbiterD, 10U)) + aOrbiterA);
            aWandererA = aWandererA + (((RotL64(aCross, 57U) + aOrbiterE) + RotL64(aOrbiterD, 39U)) + RotL64(aCarry, 11U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterD, 47U)) + aOrbiterG) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 41U)) + aPhaseHWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 27U) + aOrbiterG) + RotL64(aOrbiterA, 23U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 5U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
