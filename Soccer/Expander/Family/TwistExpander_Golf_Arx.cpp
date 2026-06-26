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
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xFCF5631FB2C95E5FULL + 0xDA6CF1FDEAE91EC9ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xFCA21971F5BB8B9DULL + 0xD309B04851D38643ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x9B373A16F579C29BULL + 0x97A1B4EE16B2CC9BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x96643932C41714C5ULL + 0xB87B43F6B556309AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xD53DBE7C37B31DA1ULL + 0x869C1D4D9376C958ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xAC74AD1246478B6FULL + 0xADE412F27434BCDAULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xE916F6469C159E85ULL + 0xE627105BE149AD3BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xAA7C7822E5CFFE57ULL + 0xB2C95035341E38E0ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xC271F7D129A51041ULL + 0xA3BDF54483738A49ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xB07D7FAB3F29C83FULL + 0xA2CD6F1E6632525EULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xB2A27B5845A5E6A5ULL + 0x8196B5DB5B727B0FULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xA4F419DA7977AF39ULL + 0xB6C9F23E9694ADF0ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xF4C4CBC2F26EEB15ULL + 0xECE5ECB6F9402A84ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xFF9F53834F4FC7FDULL + 0xFC36D6CD2B4B208FULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xFE39AD794499B2A7ULL + 0xA695270C3122FA7CULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xB8825721833C4B99ULL + 0xB9D3165143C4D0AFULL);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 2899U)) & S_BLOCK1], 37U) ^ RotL64(pSnow[((aIndex + 3345U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 1408U)) & S_BLOCK1], 27U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 4735U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCross, 4U)) ^ (RotL64(aCarry, 51U) + RotL64(aIngress, 21U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererG + RotL64(aPrevious, 57U)) + 2330952702412094686U;
            aOrbiterE = (aWandererD + RotL64(aCross, 13U)) + 7820188225935060799U;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 21U)) + 9347644591709839145U) + aOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aScatter, 28U)) + 2288624878446846870U) + aNonceWordA;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 19U)) + RotL64(aCarry, 47U)) + 9358977729492824128U;
            aOrbiterI = (((aWandererJ + RotL64(aIngress, 37U)) + RotL64(aCarry, 3U)) + 1858511275052455039U) + aNonceWordK;
            aOrbiterF = (aWandererE + RotL64(aScatter, 43U)) + 13715478509322292552U;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 51U)) + 16413396625604260455U;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 39U)) + RotL64(aCarry, 37U)) + 17714322215518432705U;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 35U)) + 16188315436202861122U) + aOrbiterAssignSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = (aWandererH + RotL64(aCross, 10U)) + 5564445841368207813U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 13717068949900594673U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 14143659432287313765U;
            aOrbiterA = RotL64((aOrbiterA * 17281441046722262917U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 5729546141908425670U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 4297827922736712074U;
            aOrbiterI = RotL64((aOrbiterI * 13631630436759768885U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 829520109395163673U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 11547160328525174295U) ^ aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4759690159673049775U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 2907177944512117206U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 11100346409065275671U;
            aOrbiterH = RotL64((aOrbiterH * 17927994356809011637U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 1344592529249949068U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 6470438516791143572U;
            aOrbiterF = RotL64((aOrbiterF * 13339390828725370475U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 5217751823741520847U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 5371275223586938039U;
            aOrbiterK = RotL64((aOrbiterK * 12318403075523724125U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 14218103150268532919U) + aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 1367628876596800571U;
            aOrbiterD = RotL64((aOrbiterD * 13777531272321533137U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 2372041991018455610U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 9870744274890595581U;
            aOrbiterE = RotL64((aOrbiterE * 12093443117747395585U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 15531376915156611594U) + aNonceWordG;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 11166549148968363252U;
            aOrbiterJ = RotL64((aOrbiterJ * 10024372567841218915U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 8555942275137258839U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 3304132937209624841U;
            aOrbiterG = RotL64((aOrbiterG * 7965093976633155809U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 14825330575158830172U) + aOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 2330952702412094686U;
            aOrbiterC = RotL64((aOrbiterC * 9146641978165131495U), 29U);
            //
            aIngress = RotL64(aOrbiterH, 29U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + (RotL64(aOrbiterK, 53U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 14U));
            aIngress = aIngress + RotL64(aOrbiterJ, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 53U) + aOrbiterG) + RotL64(aOrbiterI, 60U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 51U) + aOrbiterF) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 27U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 56U) + aOrbiterB) + RotL64(aOrbiterI, 37U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 37U) + aOrbiterC) + RotL64(aOrbiterI, 53U)) + aWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 39U) + aOrbiterH) + RotL64(aOrbiterK, 43U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 35U) + aOrbiterB) + RotL64(aOrbiterD, 23U)) + aNonceWordI) + aWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterA, 40U)) + aOrbiterB) + aNonceWordC);
            aWandererE = aWandererE + ((RotL64(aCross, 10U) + RotL64(aOrbiterK, 5U)) + aOrbiterB);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterE, 29U));
            aWandererD = aWandererD + (((RotL64(aCross, 21U) + RotL64(aOrbiterH, 51U)) + aOrbiterJ) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterG, 27U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + (RotL64(aWandererK, 18U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + RotL64(aWandererB, 50U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordL);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8363U)) & S_BLOCK1], 42U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 10695U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(pSnow[((S_BLOCK1 - aIndex + 10749U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneA[((aIndex + 6091U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCarry, 20U)) ^ (RotL64(aCross, 5U) ^ RotL64(aIngress, 43U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererG + RotL64(aIngress, 6U)) + 12775735908960052604U;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 23U)) + RotL64(aCarry, 23U)) + 11791373812080296887U;
            aOrbiterD = ((aWandererE + RotL64(aScatter, 27U)) + RotL64(aCarry, 47U)) + 5537362877706057303U;
            aOrbiterI = ((aWandererH + RotL64(aCross, 3U)) + 2023912048504189380U) + aNonceWordO;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 57U)) + 17668828109963766893U;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 51U)) + 558908629933941224U) + aNonceWordC;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 47U)) + 1479633119685446888U) + aOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aCross, 13U)) + 15460320397843364063U;
            aOrbiterH = (aWandererI + RotL64(aPrevious, 43U)) + 10059749397555469054U;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 11U)) + RotL64(aCarry, 13U)) + 9987633811929693924U;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 60U)) + 10087337844580228269U) + aOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 4446204415503364254U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 15106063243302192717U;
            aOrbiterD = RotL64((aOrbiterD * 13273756657334709803U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 9430197906134676162U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 1226048679997253363U;
            aOrbiterJ = RotL64((aOrbiterJ * 14247538885252664127U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 10611580584157624739U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 3137391249289641509U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5462682413239873181U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 9327201928815412810U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 7890659377013147073U;
            aOrbiterF = RotL64((aOrbiterF * 13827717178378062047U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 10675114832750356941U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 8804440385852327267U) ^ aOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8520671775587260601U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 12871947817782057116U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 11015991745792051390U;
            aOrbiterK = RotL64((aOrbiterK * 17152451500505815031U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 6320437975845673731U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 702457937087191287U) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 17491257114676739589U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 16629064896250312921U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 6054107387816339103U) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 6983767878966747219U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 13274874838094190290U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 12211422735294360321U;
            aOrbiterB = RotL64((aOrbiterB * 5113738196151089817U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 15338616110718583619U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 1475787183754511373U;
            aOrbiterG = RotL64((aOrbiterG * 10904607643785840003U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 15486810401396777742U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 12775735908960052604U;
            aOrbiterA = RotL64((aOrbiterA * 7478156942468930207U), 5U);
            //
            aIngress = RotL64(aOrbiterE, 13U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 30U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + RotL64(aOrbiterI, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterE, 42U)) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterD, 3U)) + aOrbiterB) + aNonceWordD);
            aWandererJ = aWandererJ + (((RotL64(aCross, 37U) + aOrbiterA) + RotL64(aOrbiterI, 35U)) + aNonceWordP);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterG, 5U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterA, 39U)) + aOrbiterE) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterC, 47U)) + aOrbiterB) + aWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 44U) + RotL64(aOrbiterI, 19U)) + aOrbiterK);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterB, 44U)) + aOrbiterF);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 53U)) + aOrbiterF) + aNonceWordB) + aWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterH, 23U));
            aWandererA = aWandererA + ((RotL64(aScatter, 52U) + RotL64(aOrbiterJ, 57U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 34U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + RotL64(aWandererJ, 27U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordI);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13272U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14437U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 14778U)) & S_BLOCK1], 13U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 11603U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 40U) + RotL64(aIngress, 3U)) ^ (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 53U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (((aWandererG + RotL64(aScatter, 11U)) + RotL64(aCarry, 19U)) + 4970414922752555648U) + aOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aIngress, 42U)) + RotL64(aCarry, 53U)) + 9462756592787669327U;
            aOrbiterH = (aWandererI + RotL64(aPrevious, 47U)) + 3948790686662213095U;
            aOrbiterK = (((aWandererF + RotL64(aCross, 21U)) + 14542857212241578311U) + aOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordO;
            aOrbiterG = (aWandererA + RotL64(aIngress, 35U)) + 3387479009827029547U;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 29U)) + 1411421370057797877U) + aNonceWordA;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 40U)) + 16894451466895681236U;
            aOrbiterB = ((aWandererD + RotL64(aCross, 37U)) + RotL64(aCarry, 11U)) + 12727136462290223542U;
            aOrbiterA = (aWandererK + RotL64(aScatter, 13U)) + 4625389198191960525U;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 23U)) + 3471881403786164913U;
            aOrbiterF = (aWandererH + RotL64(aPrevious, 27U)) + 6433115856048534831U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 9825592965466157982U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 1553125767261293088U;
            aOrbiterH = RotL64((aOrbiterH * 411535191177308781U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 9951616357109647617U) + aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 11231080382787286889U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14024961994986659187U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 13419663264017317947U) + aNonceWordH;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 4835055642466215566U) ^ aOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17898065852351759171U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 14558747666410946768U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 13120938960926874504U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5681766019285559739U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 11910501376797343986U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 15074100100781785300U;
            aOrbiterB = RotL64((aOrbiterB * 228976960937473851U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 12415377930578091821U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 14882039078390681802U;
            aOrbiterC = RotL64((aOrbiterC * 13855446647753150713U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 8094338361713756895U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 5478280604704108822U;
            aOrbiterD = RotL64((aOrbiterD * 18062931724700600993U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 6977017654546871841U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 4131602217285988962U;
            aOrbiterK = RotL64((aOrbiterK * 11865422227883712419U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 9619228479582032318U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 13506679497441415586U;
            aOrbiterI = RotL64((aOrbiterI * 5789932662418992799U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 10180259475831448124U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 4721628773773094283U;
            aOrbiterA = RotL64((aOrbiterA * 10834196399754443771U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 7898137727558813688U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 4970414922752555648U;
            aOrbiterF = RotL64((aOrbiterF * 6651835668618579479U), 41U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 18U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 41U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aIngress, 39U) + aOrbiterJ) + RotL64(aOrbiterC, 53U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterE, 28U)) + aOrbiterI) + aNonceWordI);
            aWandererH = aWandererH + (((RotL64(aScatter, 56U) + RotL64(aOrbiterD, 19U)) + aOrbiterK) + aWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterE, 43U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterK, 3U)) + aNonceWordJ);
            aWandererA = aWandererA ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterD, 60U)) + aOrbiterA);
            aWandererC = aWandererC + ((((RotL64(aIngress, 28U) + aOrbiterJ) + RotL64(aOrbiterH, 57U)) + aNonceWordE) + aWandererUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 37U) + aOrbiterD) + RotL64(aOrbiterC, 21U));
            aWandererE = aWandererE + (((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterG, 23U)) + aOrbiterH);
            aWandererD = aWandererD + (((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 35U)) + aOrbiterG) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 34U));
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 46U);
            aCarry = aCarry ^ aNonceWordH;
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 17210U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((aIndex + 21471U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19948U)) & S_BLOCK1], 43U) ^ RotL64(mSource[((aIndex + 20122U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aPrevious, 23U)) + (RotL64(aIngress, 56U) + RotL64(aCross, 43U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererB + RotL64(aIngress, 41U)) + 13924571355038625040U;
            aOrbiterE = (aWandererE + RotL64(aCross, 20U)) + 16328300979357156658U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 53U)) + RotL64(aCarry, 47U)) + 3947771961206012461U;
            aOrbiterD = (((aWandererH + RotL64(aScatter, 47U)) + RotL64(aCarry, 11U)) + 15428284250569311285U) + aNonceWordI;
            aOrbiterJ = (aWandererG + RotL64(aCross, 43U)) + 5777369485254032486U;
            aOrbiterF = (aWandererA + RotL64(aScatter, 3U)) + 16813320300717644673U;
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 60U)) + 16689933050200758251U) + aOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = ((aWandererF + RotL64(aIngress, 23U)) + 1856422419049390708U) + aOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = (aWandererC + RotL64(aCross, 57U)) + 18214498743831925517U;
            aOrbiterC = (aWandererJ + RotL64(aScatter, 39U)) + 18278550878494094923U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 11U)) + RotL64(aCarry, 57U)) + 797712062039591797U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 15854849439012341347U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 996882939768167773U;
            aOrbiterH = RotL64((aOrbiterH * 14936703950807908575U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 3005829974130671692U) + aNonceWordB;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 8793495343509953906U;
            aOrbiterJ = RotL64((aOrbiterJ * 14065479348374612031U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 7710453029930631112U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 9511995836117707047U) ^ aOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7250766204781428201U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 670902975693341744U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 9045820304668279777U;
            aOrbiterG = RotL64((aOrbiterG * 18373074917532639027U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 12417212387607119470U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 12816983560669985622U;
            aOrbiterA = RotL64((aOrbiterA * 8406003970221889847U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 17245432086377688540U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 6806521945548502014U;
            aOrbiterB = RotL64((aOrbiterB * 11335859481858640857U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 8947500746292365294U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 4468060468522895852U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7022481284816599797U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 9892975931958803992U) + aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 3042599331526937836U;
            aOrbiterK = RotL64((aOrbiterK * 3308512896171443645U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 12991568221485810891U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 8551331172836260315U;
            aOrbiterI = RotL64((aOrbiterI * 4509997595920847057U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 183547209633334407U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 17275712817092769452U;
            aOrbiterE = RotL64((aOrbiterE * 15677355290000929085U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 12743863879392372723U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 13924571355038625040U;
            aOrbiterD = RotL64((aOrbiterD * 11966689345179279407U), 39U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 38U);
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 37U) + aOrbiterD) + RotL64(aOrbiterH, 24U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 27U)) + aOrbiterA) + RotL64(aCarry, 21U)) + aNonceWordC);
            aWandererF = aWandererF ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterI, 39U)) + aOrbiterG) + aWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 11U) + RotL64(aOrbiterK, 5U)) + aOrbiterH);
            aWandererK = aWandererK ^ ((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterH, 20U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 48U) + aOrbiterE) + RotL64(aOrbiterC, 53U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterI, 47U)) + aOrbiterB) + aNonceWordH);
            aWandererA = aWandererA + (((RotL64(aIngress, 51U) + aOrbiterD) + RotL64(aOrbiterA, 57U)) + aNonceWordG);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 13U) + aOrbiterG) + RotL64(aOrbiterE, 41U));
            aWandererE = aWandererE + ((((RotL64(aPrevious, 40U) + aOrbiterG) + RotL64(aOrbiterF, 35U)) + RotL64(aCarry, 43U)) + aWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterE, 13U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererG, 48U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 34U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 5U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordE);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 25326U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24915U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23567U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneA[((aIndex + 25765U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCarry, 52U)) + (RotL64(aIngress, 19U) ^ RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (((aWandererG + RotL64(aIngress, 13U)) + RotL64(aCarry, 47U)) + 10915618884692072446U) + aOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = ((((aWandererI + RotL64(aCross, 51U)) + RotL64(aCarry, 39U)) + 12634922308499254909U) + aOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1]) + aNonceWordE;
            aOrbiterC = (aWandererE + RotL64(aScatter, 35U)) + 6533934734564499389U;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 10U)) + RotL64(aCarry, 13U)) + 6744203303756105181U;
            aOrbiterK = (aWandererA + RotL64(aCross, 21U)) + 13086782386652045658U;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 53U)) + 5693840533331397822U) + aNonceWordD;
            aOrbiterA = (aWandererJ + RotL64(aScatter, 5U)) + 1803663542535024611U;
            aOrbiterH = (aWandererD + RotL64(aPrevious, 37U)) + 3597219300593287708U;
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 19U)) + 1429753448204448904U) + aNonceWordN;
            aOrbiterE = (aWandererB + RotL64(aCross, 28U)) + 17229017825587322715U;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 39U)) + 1137574712801062932U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 2401991077004083378U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 1332473247826139292U;
            aOrbiterC = RotL64((aOrbiterC * 15029831858261506447U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 11730946340796899885U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 15319163439700390962U;
            aOrbiterG = RotL64((aOrbiterG * 1349242001887975499U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 4744141870145159917U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 6067132201862688684U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6046100687757836027U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 14991509179286371800U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 4342608825699398682U;
            aOrbiterE = RotL64((aOrbiterE * 10240526103933275875U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 3727521409410742075U) + aNonceWordL;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 3302027219498304367U;
            aOrbiterI = RotL64((aOrbiterI * 12153634588200479559U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 6039539483340398858U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 2902581519976937051U) ^ aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2057584328877854239U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 12332784713738947242U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 13761272577223712786U) ^ aOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14930145045480030821U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 2947946397617043735U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 11107014023853644521U) ^ aOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15030903626191481831U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 6212403196992771516U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 16107261731677426470U) ^ aNonceWordK;
            aOrbiterD = RotL64((aOrbiterD * 13764822942405295129U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 8414111492161335472U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 3625937496991123221U;
            aOrbiterB = RotL64((aOrbiterB * 1736741235159600739U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 5466667339391480293U) + aNonceWordC;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 10915618884692072446U;
            aOrbiterK = RotL64((aOrbiterK * 14719282928172086707U), 51U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 13U);
            aIngress = aIngress + (RotL64(aOrbiterD, 46U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + RotL64(aOrbiterF, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 50U) + aOrbiterK) + RotL64(aOrbiterF, 48U));
            aWandererF = aWandererF + ((RotL64(aScatter, 23U) + RotL64(aOrbiterE, 21U)) + aOrbiterK);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterJ, 29U));
            aWandererB = aWandererB + ((((RotL64(aCross, 13U) + aOrbiterB) + RotL64(aOrbiterD, 13U)) + RotL64(aCarry, 11U)) + aNonceWordI);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterB, 51U)) + aWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 41U) + aOrbiterC) + RotL64(aOrbiterF, 41U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 5U) + aOrbiterK) + RotL64(aOrbiterA, 43U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 39U) + aOrbiterE) + RotL64(aOrbiterC, 57U)) + aWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterG, 35U));
            aWandererA = aWandererA + (((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 24U)) + aOrbiterD) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 34U) + aOrbiterG) + RotL64(aOrbiterI, 3U)) + aNonceWordB);
            //
            aCarry = aCarry + (RotL64(aWandererD, 14U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 41U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 26U));
            aCarry = aCarry + RotL64(aWandererA, 11U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ aNonceWordK;
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28595U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneB[((aIndex + 31730U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32552U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneB[((aIndex + 28317U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 4U) ^ RotL64(aIngress, 41U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCross, 19U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (aWandererH + RotL64(aScatter, 51U)) + 16519040829220310189U;
            aOrbiterB = (((aWandererG + RotL64(aIngress, 30U)) + 6888002778416941825U) + aOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1]) + aNonceWordM;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 39U)) + 1310832187746534025U;
            aOrbiterK = (aWandererA + RotL64(aCross, 43U)) + 5890888009051281674U;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 57U)) + RotL64(aCarry, 11U)) + 5143864838362464857U;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 5U)) + 15591534069452660003U) + aNonceWordH;
            aOrbiterC = (aWandererC + RotL64(aPrevious, 11U)) + 1466867671765325096U;
            aOrbiterE = (((aWandererB + RotL64(aCross, 26U)) + RotL64(aCarry, 39U)) + 13931443680107902488U) + aOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 37U)) + 15400747367673245552U;
            aOrbiterF = (aWandererE + RotL64(aScatter, 41U)) + 2836975369734495759U;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 35U)) + RotL64(aCarry, 23U)) + 2370720358274970117U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 3470677184188006133U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 7175584278499266723U) ^ aNonceWordF;
            aOrbiterG = RotL64((aOrbiterG * 10067096593682482345U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 6095078817776863055U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 2176637999243513070U;
            aOrbiterD = RotL64((aOrbiterD * 12215701810843975501U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 5580391239754903129U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 15196125567953871184U;
            aOrbiterH = RotL64((aOrbiterH * 12686361960729564519U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 12787014151503209931U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 1523153207064063495U;
            aOrbiterC = RotL64((aOrbiterC * 3113907543551927561U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 12973289026485937829U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 9087439766232078173U;
            aOrbiterE = RotL64((aOrbiterE * 5817029335999350327U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 16318022893068674015U) + aNonceWordD;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 11089160685103562409U;
            aOrbiterJ = RotL64((aOrbiterJ * 17087834321385147603U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 8680037953925067235U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 3112588943274158119U;
            aOrbiterF = RotL64((aOrbiterF * 9214011370307670371U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 16749015684369649821U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 9419550535891334966U;
            aOrbiterI = RotL64((aOrbiterI * 5421312787569114811U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 12309598080688360615U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 12244971765096881835U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17260277357109449509U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 10088685417774847648U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 3241987595838650154U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14096986158958931367U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 17916401586500786536U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 16519040829220310189U;
            aOrbiterK = RotL64((aOrbiterK * 6742024268853509861U), 5U);
            //
            aIngress = RotL64(aOrbiterG, 35U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 50U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterD, 39U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 30U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 21U) + aOrbiterG) + RotL64(aOrbiterE, 37U));
            aWandererA = aWandererA + (((RotL64(aScatter, 23U) + aOrbiterB) + RotL64(aOrbiterK, 53U)) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 53U) + aOrbiterC) + RotL64(aOrbiterK, 3U)) + aNonceWordL);
            aWandererK = aWandererK + ((RotL64(aPrevious, 5U) + aOrbiterH) + RotL64(aOrbiterB, 21U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 34U) + aOrbiterG) + RotL64(aOrbiterJ, 58U)) + aWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 41U)) + aOrbiterD);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterA, 39U)) + aOrbiterI);
            aWandererE = aWandererE + ((((RotL64(aCross, 19U) + RotL64(aOrbiterC, 51U)) + aOrbiterF) + RotL64(aCarry, 11U)) + aWandererUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 41U) + aOrbiterK) + RotL64(aOrbiterH, 13U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 11U) + aOrbiterE) + RotL64(aOrbiterK, 29U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 56U) + RotL64(aOrbiterJ, 10U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererH, 46U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 60U));
            aCarry = aCarry + RotL64(aWandererI, 39U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ aNonceWordG;
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
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xE2BE692022796EB1ULL + 0x85071090B8FBC78CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xC15F849423A3C801ULL + 0xB87ACF6A96663BC9ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x9710011083A07FD7ULL + 0xCB8E97164C474ACAULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xEB8F3743394721B7ULL + 0x9B6C5E804BF763CEULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xCA2BD6D47B633165ULL + 0xEA584B08021FB493ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x919189EBEFA004D3ULL + 0xA37D1EAAB758F899ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x80DE96D1869F77A9ULL + 0x946126123E9B8884ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x8B2A185F4C9E1C1BULL + 0xBDDEC0D886604DC9ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x9430EBB1983D664DULL + 0xD56DC81038AD6484ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xE77DA0440B007C73ULL + 0x9A7C826C6843369EULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xC62D80918D939FA7ULL + 0x8E47A8EF32C0CF60ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x9A16081A0DEACB49ULL + 0x85DCFADD9AE14CB4ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x961197E0BDCAC807ULL + 0x87A2627FE1A3C6D7ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xC2E4688D33B38D15ULL + 0xDD5B3F76B96A8CEEULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x925213799CDD4C1FULL + 0xF4B4C8A7B0F70A73ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xEDEF1DE08B159F0FULL + 0x9F6600E3801428C7ULL);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1867U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 469U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 113U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 2919U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 56U) + RotL64(aCross, 23U)) + (RotL64(aCarry, 11U) ^ RotL64(aPrevious, 39U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererA + RotL64(aIngress, 46U)) + 10726035965553989335U) + aNonceWordA;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 13U)) + 967354339530195662U;
            aOrbiterB = (aWandererD + RotL64(aScatter, 23U)) + 10834593005478605624U;
            aOrbiterJ = (aWandererC + RotL64(aCross, 5U)) + 1012888282838656933U;
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 60U)) + 15283530351725183253U) + aOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = (((aWandererH + RotL64(aScatter, 29U)) + RotL64(aCarry, 23U)) + 11724495956731703750U) + aOrbiterAssignSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 51U)) + RotL64(aCarry, 41U)) + 4288330117317505776U;
            aOrbiterE = ((aWandererB + RotL64(aCross, 41U)) + RotL64(aCarry, 11U)) + 10894778070022873473U;
            aOrbiterH = (aWandererE + RotL64(aPrevious, 35U)) + 15563886747621617467U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 11182488628562891937U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 10420140066310588580U;
            aOrbiterB = RotL64((aOrbiterB * 13898299782819948719U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 11775138062167543111U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 16545391898578161683U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14588306527161321535U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 1550144656312299266U) + aOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 14903504853138279883U;
            aOrbiterE = RotL64((aOrbiterE * 8003033561266164387U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 309935535526750396U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 13991265868040011411U) ^ aNonceWordD;
            aOrbiterH = RotL64((aOrbiterH * 2887531132228588441U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 1755976294857114222U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 2259275858478396846U;
            aOrbiterG = RotL64((aOrbiterG * 7416165760067878161U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 4838175912944552936U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 12307900457200936013U) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 14719363144850838805U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 18025411832912225805U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 981375022769564523U;
            aOrbiterA = RotL64((aOrbiterA * 15869361544011831483U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 3174014054982742562U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 8119692378748963609U;
            aOrbiterK = RotL64((aOrbiterK * 3072354179707448489U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 14502863160788675807U) + aOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 1207582534593709516U) ^ aNonceWordF;
            aOrbiterD = RotL64((aOrbiterD * 3045412087535529357U), 13U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterA, 44U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 21U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 27U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterE, 23U));
            aWandererE = aWandererE + (((RotL64(aScatter, 13U) + aOrbiterJ) + RotL64(aOrbiterH, 60U)) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 24U) + RotL64(aOrbiterE, 13U)) + aOrbiterG) + aNonceWordH) + aWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 53U) + aOrbiterJ) + RotL64(aOrbiterI, 43U));
            aWandererC = aWandererC ^ ((((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterB, 51U)) + aNonceWordL) + aWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 35U) + RotL64(aOrbiterH, 18U)) + aOrbiterK);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 47U) + aOrbiterD) + RotL64(aOrbiterB, 29U));
            aWandererH = aWandererH + (((RotL64(aIngress, 28U) + RotL64(aOrbiterH, 39U)) + aOrbiterB) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterG, 3U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 60U));
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordK;
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 9422U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((aIndex + 16099U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13888U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((aIndex + 10736U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aPrevious, 51U)) ^ (RotL64(aCross, 35U) + RotL64(aIngress, 6U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererB + RotL64(aIngress, 6U)) + RotL64(aCarry, 3U)) + 5131645209694953015U;
            aOrbiterA = (((aWandererD + RotL64(aScatter, 11U)) + 12070391048835379854U) + aOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordC;
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 23U)) + 2604295836242338724U;
            aOrbiterC = ((aWandererE + RotL64(aCross, 35U)) + 14042039029284001596U) + aNonceWordG;
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 19U)) + 8914654543854559327U;
            aOrbiterB = (aWandererI + RotL64(aIngress, 48U)) + 2185619407969359869U;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 57U)) + RotL64(aCarry, 19U)) + 5187406295103352574U;
            aOrbiterG = ((aWandererG + RotL64(aCross, 53U)) + RotL64(aCarry, 27U)) + 8022832481290871217U;
            aOrbiterE = (((aWandererF + RotL64(aPrevious, 29U)) + 8783061916740573472U) + aOrbiterAssignSaltB[((aIndex + 12U)) & S_SALT1]) + aNonceWordE;
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 10711028365596196301U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 13387065038269133571U;
            aOrbiterJ = RotL64((aOrbiterJ * 12444578026365205255U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 11187001318931801582U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 14191473173276034019U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2491253922434756431U), 23U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterF) + 16207761776716426435U) + aOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1]) + aNonceWordO;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 9677408414452078760U;
            aOrbiterI = RotL64((aOrbiterI * 5487303383095129949U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 17812460332794370649U) + aNonceWordJ;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 7736423148554132028U;
            aOrbiterG = RotL64((aOrbiterG * 15588733747232852555U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 17293203944059014763U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 13487243633338010243U;
            aOrbiterE = RotL64((aOrbiterE * 9468688858740539095U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 15979293016815060755U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 17645215484691359547U) ^ aOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1449450767288733995U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 11635961468586927692U) + aNonceWordB;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 10530136578329059784U;
            aOrbiterC = RotL64((aOrbiterC * 8785021493374398437U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 4900370530116992731U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 15952900504821599445U;
            aOrbiterB = RotL64((aOrbiterB * 5413316082800365261U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 9938000151832814778U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 14170277411106520726U;
            aOrbiterA = RotL64((aOrbiterA * 5058343552974910737U), 35U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterE, 42U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 53U));
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aIngress, 60U) + aOrbiterJ) + RotL64(aOrbiterC, 34U)) + RotL64(aCarry, 21U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterE, 53U)) + aOrbiterB);
            aWandererD = aWandererD + (((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 39U)) + aOrbiterG) + RotL64(aCarry, 35U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 27U) + aOrbiterK) + RotL64(aOrbiterF, 11U)) + aWandererUpdateSaltC[((aIndex + 26U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 44U)) + aOrbiterE);
            aWandererC = aWandererC ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterF, 19U)) + aOrbiterB);
            aWandererF = aWandererF + ((RotL64(aIngress, 52U) + RotL64(aOrbiterK, 27U)) + aOrbiterA);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 23U) + aOrbiterG) + RotL64(aOrbiterB, 5U)) + aNonceWordP);
            aWandererB = aWandererB + (((RotL64(aScatter, 5U) + aOrbiterJ) + RotL64(aOrbiterI, 57U)) + aWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 40U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 22890U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((aIndex + 21461U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 23194U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 22059U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCross, 11U)) + (RotL64(aPrevious, 60U) ^ RotL64(aCarry, 27U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererK + RotL64(aCross, 46U)) + 13174219512651137892U) + aOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aScatter, 51U)) + RotL64(aCarry, 39U)) + 2715455762789269341U;
            aOrbiterA = ((aWandererA + RotL64(aIngress, 41U)) + 1338018183235594313U) + aOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 5U)) + RotL64(aCarry, 57U)) + 16566866551729552930U;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 27U)) + 6901845297307236726U) + aNonceWordG;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 13U)) + 2476078302049201718U) + aNonceWordL;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 19U)) + 15531109473927052260U) + aNonceWordD;
            aOrbiterF = ((aWandererE + RotL64(aCross, 60U)) + RotL64(aCarry, 19U)) + 4087849380858572351U;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 23U)) + 5167830630098599644U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 7275995452428627217U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 14794340370010024117U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 8779497557416568379U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 8509217403041662849U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 2321522025240806996U;
            aOrbiterI = RotL64((aOrbiterI * 113568101672878697U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 5676672952755594051U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 2304681269233504384U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15731441084605554497U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 8383399721062437300U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 13181984036942227666U;
            aOrbiterH = RotL64((aOrbiterH * 1648761328771932069U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 13602604532551684210U) + aNonceWordJ;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 12725687663616352843U;
            aOrbiterD = RotL64((aOrbiterD * 4684699861686199753U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 5831790822416009806U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 4535048543735457407U;
            aOrbiterJ = RotL64((aOrbiterJ * 12076777878870257053U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 10617608605149381858U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 5244225377862618630U) ^ aOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15307177251167023999U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 18229989093139888456U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 9728120630096192811U;
            aOrbiterF = RotL64((aOrbiterF * 16052574428163231023U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 1312233443099767304U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 8043115602160128619U;
            aOrbiterE = RotL64((aOrbiterE * 9365756845731616963U), 35U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterI, 19U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 52U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + (RotL64(aOrbiterF, 39U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 5U) + aOrbiterF) + RotL64(aOrbiterJ, 51U)) + aWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 41U) + RotL64(aOrbiterF, 35U)) + aOrbiterI);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterH, 5U)) + aOrbiterD);
            aWandererH = aWandererH + ((RotL64(aScatter, 10U) + aOrbiterI) + RotL64(aOrbiterD, 47U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 18U)) + aOrbiterE);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterA, 27U)) + aOrbiterI) + RotL64(aCarry, 53U)) + aWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterI, 41U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 14U) + RotL64(aOrbiterF, 57U)) + aOrbiterC) + RotL64(aCarry, 3U)) + aNonceWordK);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterG, 12U)) + aOrbiterH) + aNonceWordH);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 4U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererC, 21U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 25705U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31514U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28750U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((aIndex + 31548U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 34U) ^ RotL64(aPrevious, 21U)) ^ (RotL64(aCross, 47U) + RotL64(aIngress, 5U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererK + RotL64(aPrevious, 29U)) + 4739486756133131180U;
            aOrbiterK = (aWandererJ + RotL64(aScatter, 3U)) + 16089707555501328184U;
            aOrbiterD = (aWandererC + RotL64(aIngress, 14U)) + 15310047330238536453U;
            aOrbiterH = ((aWandererH + RotL64(aCross, 57U)) + 7901411596386834955U) + aOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aScatter, 23U)) + RotL64(aCarry, 29U)) + 4357555491060982163U;
            aOrbiterJ = ((aWandererI + RotL64(aCross, 19U)) + RotL64(aCarry, 13U)) + 15667085602825720102U;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 37U)) + RotL64(aCarry, 21U)) + 8520635334382269253U;
            aOrbiterE = (((aWandererG + RotL64(aPrevious, 47U)) + 1772509779231068315U) + aOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordE;
            aOrbiterC = (aWandererB + RotL64(aScatter, 10U)) + 15336170957886025677U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 8628770833489469980U) + aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 15469234024247246228U;
            aOrbiterD = RotL64((aOrbiterD * 8905266995119987947U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 10796430900884288328U) + aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 10660110397012853289U) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 9140007610912037461U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 11202284258711214794U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 17509491802893182994U;
            aOrbiterI = RotL64((aOrbiterI * 9329107599972703671U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 16212572740740103554U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 2190030203761579226U) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 3101886685668871045U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 12014337082293041909U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 3733531010807001506U;
            aOrbiterH = RotL64((aOrbiterH * 5797362244066062299U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 7100994963061975529U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 17837541162838600258U;
            aOrbiterJ = RotL64((aOrbiterJ * 8745987361678166553U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 3311518938023146951U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 7709505172646831553U;
            aOrbiterE = RotL64((aOrbiterE * 7121143171245765213U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 4979968094554018443U) + aNonceWordK;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 16822214821463034107U;
            aOrbiterC = RotL64((aOrbiterC * 8618262120451291765U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 8376124175020587079U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 11084586282092424876U) ^ aOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5835632742522563537U), 3U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterC, 27U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 37U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 34U));
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aScatter, 24U) + aOrbiterC) + RotL64(aOrbiterH, 4U)) + aNonceWordP);
            aWandererH = aWandererH + ((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterD, 39U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 43U) + aOrbiterE) + RotL64(aOrbiterC, 23U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterJ, 35U)) + aOrbiterE);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterE, 58U)) + aOrbiterI) + aNonceWordF);
            aWandererA = aWandererA + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterK, 29U)) + aOrbiterC) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 11U)) + aOrbiterF) + aWandererUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererK = aWandererK + (((((RotL64(aCross, 35U) + aOrbiterH) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 21U)) + aNonceWordI) + aWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 28U) + aOrbiterD) + RotL64(aOrbiterA, 43U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 60U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 21U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordP);
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
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
    [[maybe_unused]] std::uint8_t *aWorkLaneC = pWorkSpace->mWorkLaneC;
    [[maybe_unused]] std::uint8_t *aWorkLaneD = pWorkSpace->mWorkLaneD;
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterJ = 0;
    std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xCD245DB64D3C050FULL + 0x82FAE8285B0149E6ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xA5AEF452922E5019ULL + 0xFE8C040EA67A2E38ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xBA6A4A312272697FULL + 0x8033427C035F5FECULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xEFB9AE78FABBE4ABULL + 0xD6AD0776BB2A439BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x8A49400B5052C391ULL + 0xC981E09B07893485ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x8A4582248CBB7D73ULL + 0xDB2E41F1E8CD04E7ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xEDC4C7F87529974DULL + 0xFE033511F004771AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF24A7CFA330D805FULL + 0xE01CDF1DA0840C3AULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xCF6179F60C0B50B1ULL + 0x940D9097176F0FB9ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xC2D570E7A0293425ULL + 0xEB7196D5462E2BCCULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xD9ACAB99DFF7E4CFULL + 0xCD503D2B02AA1F8BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xF174DB5B3B143831ULL + 0xD1B196854378AC6FULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x9FCB63293B9366D5ULL + 0x8D632EF5B72105C3ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xDD28D84B31F7A295ULL + 0xB345ED2BEA5D0E93ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xF3108032F65A2E73ULL + 0xE30595812EB7C128ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xCCC24BDFC42E1E79ULL + 0x8DBCA882E3ABD820ULL);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 5074U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneC[((aIndex + 4581U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 2051U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 1458U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 21U) ^ RotL64(aIngress, 34U)) ^ (RotL64(aCross, 5U) + RotL64(aPrevious, 57U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererA + RotL64(aScatter, 19U)) + RotL64(aCarry, 3U)) + 18319689184146942855U;
            aOrbiterD = (((aWandererF + RotL64(aPrevious, 39U)) + RotL64(aCarry, 21U)) + 8041304130090501019U) + aNonceWordF;
            aOrbiterE = (((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 51U)) + 11347064191990897738U) + aOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = (((aWandererI + RotL64(aIngress, 47U)) + 15242243470024447468U) + aOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordH;
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 28U)) + 10619749107163611105U) + aNonceWordA;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 14795614276221947128U) + aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 1578095288886372393U;
            aOrbiterE = RotL64((aOrbiterE * 9953192041564147241U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 13593906305770501684U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 8919815528334599172U) ^ aNonceWordP;
            aOrbiterH = RotL64((aOrbiterH * 2033810402808238127U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 17425548324720065145U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 11125018338392347335U;
            aOrbiterJ = RotL64((aOrbiterJ * 4377887040461528587U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 3779189180734244399U) + aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 10958224663276134041U) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 6206963519509783781U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 4317305352561612995U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 4891139433808505355U;
            aOrbiterB = RotL64((aOrbiterB * 11507024985663120317U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 57U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 6U));
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterH, 19U)) + aOrbiterJ) + aWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 29U) + RotL64(aOrbiterE, 39U)) + aOrbiterB) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterJ, 58U)) + aNonceWordN);
            aWandererI = aWandererI + (((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 14U) + RotL64(aOrbiterD, 29U)) + aOrbiterB) + aWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 15657U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 9103U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 11877U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8309U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 20U) ^ RotL64(aIngress, 51U)) ^ (RotL64(aPrevious, 3U) + RotL64(aCarry, 37U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererF + RotL64(aScatter, 3U)) + 12131317914288566437U;
            aOrbiterK = (((aWandererB + RotL64(aCross, 23U)) + RotL64(aCarry, 43U)) + 5672805657999385496U) + aNonceWordA;
            aOrbiterH = ((aWandererC + RotL64(aIngress, 41U)) + RotL64(aCarry, 57U)) + 3581710244233124197U;
            aOrbiterF = (((aWandererD + RotL64(aPrevious, 58U)) + 15251296040538489436U) + aOrbiterAssignSaltE[((aIndex + 20U)) & S_SALT1]) + aNonceWordF;
            aOrbiterA = ((((aWandererI + RotL64(aScatter, 11U)) + RotL64(aCarry, 19U)) + 11295008604679904153U) + aOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordE;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 2230897493419504490U) + aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 7109600123297458999U;
            aOrbiterH = RotL64((aOrbiterH * 8267799351136506307U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 13119156643107683803U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 14755160867807355250U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10007087518844899239U), 35U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterH) + 16829363373287496832U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordM;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 16981122946707720883U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5394974422201576627U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 8806000776958603317U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 16810923047720876014U;
            aOrbiterK = RotL64((aOrbiterK * 17872735050219539145U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 8129657889554436328U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 8653100378491974463U) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 11395283153912468661U), 51U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterA, 40U);
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterJ, 43U)) + aOrbiterF);
            aWandererI = aWandererI + ((((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterK, 27U)) + RotL64(aCarry, 51U)) + aNonceWordJ);
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 53U)) + aOrbiterF) + aNonceWordB) + aWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererF = aWandererF + (((((RotL64(aPrevious, 36U) + aOrbiterA) + RotL64(aOrbiterJ, 6U)) + RotL64(aCarry, 21U)) + aNonceWordO) + aWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterH, 19U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 17279U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneA[((aIndex + 23665U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 24237U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 19147U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 10U) + RotL64(aCarry, 53U)) + (RotL64(aCross, 29U) ^ RotL64(aIngress, 41U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (((aWandererH + RotL64(aIngress, 51U)) + RotL64(aCarry, 23U)) + 7651355040951791298U) + aOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = (((aWandererG + RotL64(aPrevious, 27U)) + RotL64(aCarry, 3U)) + 13988210277931659312U) + aOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = ((aWandererE + RotL64(aCross, 3U)) + 9846849412579537783U) + aNonceWordE;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 42U)) + 12746719939495876158U) + aNonceWordK;
            aOrbiterD = ((aWandererD + RotL64(aCross, 11U)) + RotL64(aCarry, 51U)) + 11498066185182895284U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 11101058955193080232U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 15513734459555672046U) ^ aOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6974281215677538561U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 15711108675349394643U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 4771231759949468556U;
            aOrbiterH = RotL64((aOrbiterH * 9806191054594333615U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 11449258010811305256U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 17036938391509986723U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7411466953205347639U), 3U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterD) + 6999245666776654250U) + aOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1]) + aNonceWordI;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 2106819066263369528U) ^ aNonceWordO;
            aOrbiterG = RotL64((aOrbiterG * 13005885810757743129U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 12716183358903477216U) + aOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 16752724547046059889U) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 11475905692393034141U), 43U);
            //
            aIngress = RotL64(aOrbiterJ, 3U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 53U));
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterJ, 35U)) + aOrbiterH) + RotL64(aCarry, 23U)) + aWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 29U) + aOrbiterG) + RotL64(aOrbiterJ, 5U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 13U)) + aOrbiterD) + aWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 10U) + RotL64(aOrbiterF, 58U)) + aOrbiterD) + aNonceWordH);
            aWandererG = aWandererG + (((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterG, 27U)) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererJ, 21U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = aCarry ^ aNonceWordJ;
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 27722U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27511U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28955U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 26001U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 56U) + RotL64(aPrevious, 27U)) + (RotL64(aCarry, 11U) ^ RotL64(aIngress, 41U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (((aWandererG + RotL64(aCross, 57U)) + RotL64(aCarry, 5U)) + 7632760812370906911U) + aNonceWordJ;
            aOrbiterH = ((((aWandererD + RotL64(aScatter, 27U)) + RotL64(aCarry, 23U)) + 6007174525479723089U) + aOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1]) + aNonceWordM;
            aOrbiterD = (aWandererA + RotL64(aIngress, 37U)) + 3362829642521821048U;
            aOrbiterK = (((aWandererI + RotL64(aPrevious, 48U)) + RotL64(aCarry, 57U)) + 18009548556107978286U) + aOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 5U)) + 17880909432272697327U) + aNonceWordB;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 15961567935420752568U) + aNonceWordO;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 10136559064656837921U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14473810261421912849U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 17622019364405410277U) + aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 6927494824421416306U;
            aOrbiterG = RotL64((aOrbiterG * 2686290883767829973U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 7125170407794874847U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 12342273503071032250U;
            aOrbiterK = RotL64((aOrbiterK * 867417849555857179U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 14997696377476124836U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 14874498694181230698U) ^ aNonceWordE;
            aOrbiterH = RotL64((aOrbiterH * 4026127545746010937U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 2549397729130885686U) + aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 4217995818662767955U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5525525344485251063U), 13U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 6U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 37U));
            aIngress = aIngress + RotL64(aOrbiterG, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 11U) + aOrbiterD) + RotL64(aOrbiterH, 50U)) + aNonceWordA);
            aWandererG = aWandererG + (((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterH, 5U)) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterK, 37U)) + aOrbiterG);
            aWandererI = aWandererI + ((((RotL64(aIngress, 39U) + aOrbiterD) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 13U)) + aWandererUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 58U) + aOrbiterG) + RotL64(aOrbiterJ, 19U)) + aWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererC, 3U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordF);
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
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xF36AB3AC39B7810DULL + 0xE3C9693748DD82E8ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xB5CCE49457F468B3ULL + 0xC500B9E5E80FC941ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xD2C9C6C23262BB9BULL + 0xC583658E76C48E39ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x8DD30F8F11AE21C5ULL + 0xD405D9835230E703ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xF0E1FC2D55C8F0EFULL + 0xA2722B0E8FCA6CB5ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xCE039DC45D807AE3ULL + 0xC3E9F717F8FD0E8CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xE3EDC2553F83E0CBULL + 0xD8DE5D5F0E62953BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xA7A0EDF5919FD515ULL + 0xEC94C29A9BE5B958ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xD89F97267415BFE3ULL + 0xCC35094ABF4ADD34ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xCFC55FDB3D59541BULL + 0xF1F91296A38626BBULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xDC88CC864DE95431ULL + 0x92D5DA7EFBE36E2FULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xC1BC13AD912F4CEFULL + 0x92A8A3FFDBE9831BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x8161598195DFFB07ULL + 0xA2119284B0360395ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xF59D742A16830209ULL + 0x883BAF68B61FA4AEULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x8444CA08D57A834DULL + 0xE269121B6DCBBB60ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xEA6B751EEC3B77CDULL + 0xE24D6D0180BE419EULL);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2773U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 787U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5310U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 3398U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 4U) + RotL64(aPrevious, 27U)) ^ (RotL64(aIngress, 41U) ^ RotL64(aCarry, 53U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (((aWandererF + RotL64(aScatter, 29U)) + RotL64(aCarry, 13U)) + 1087148170018530502U) + aOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aIngress, 58U)) + RotL64(aCarry, 27U)) + 15530846874509311414U;
            aOrbiterC = (aWandererD + RotL64(aCross, 19U)) + 16987358651515511212U;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 3U)) + 12504143181007924259U) + aOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aCross, 43U)) + 393322117322732418U) + aNonceWordK;
            aOrbiterH = (aWandererI + RotL64(aIngress, 37U)) + 14325937299241887166U;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 51U)) + RotL64(aCarry, 41U)) + 9395262907017475742U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 13658510441418344769U) + aOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 6410754322737005336U;
            aOrbiterC = RotL64((aOrbiterC * 6932217611373076391U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 9257290738538818434U) + aNonceWordA;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 7489828960857692286U;
            aOrbiterE = RotL64((aOrbiterE * 16519674788777989043U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 4118778591214588387U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 16619215231168796563U;
            aOrbiterH = RotL64((aOrbiterH * 14876884956536265157U), 19U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterH) + 11326283811003573430U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 1865401866017614604U;
            aOrbiterJ = RotL64((aOrbiterJ * 8378326058282460073U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 670150121105733604U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 1499331510641068749U) ^ aOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16623742535540383107U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 1116410848560838532U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 2696841341036281779U;
            aOrbiterG = RotL64((aOrbiterG * 9598953298074904869U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 5487352391229549881U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 12008243050943342979U;
            aOrbiterD = RotL64((aOrbiterD * 9087261224804582459U), 11U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterJ, 5U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 39U));
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aCross, 21U) + RotL64(aOrbiterG, 3U)) + aOrbiterC) + RotL64(aCarry, 21U)) + aNonceWordH);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterD, 43U)) + aOrbiterE) + aWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aIngress, 60U) + aOrbiterC) + RotL64(aOrbiterH, 50U)) + RotL64(aCarry, 53U)) + aNonceWordF);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterH, 57U)) + aWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 13U)) + aOrbiterE);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 11U) + aOrbiterC) + RotL64(aOrbiterK, 35U)) + aNonceWordC);
            aWandererF = aWandererF + ((RotL64(aIngress, 27U) + aOrbiterD) + RotL64(aOrbiterJ, 29U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 60U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + RotL64(aWandererK, 35U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordJ);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 12141U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneD[((aIndex + 9442U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9506U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10131U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 19U)) + (RotL64(aIngress, 36U) ^ RotL64(aCross, 3U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 57U)) + RotL64(aCarry, 21U)) + 12535417189990029950U;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 21U)) + RotL64(aCarry, 51U)) + 6204401443676390273U;
            aOrbiterF = ((aWandererC + RotL64(aIngress, 29U)) + RotL64(aCarry, 37U)) + 869613505613154672U;
            aOrbiterK = (((aWandererJ + RotL64(aCross, 51U)) + 15053590879563855802U) + aOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1]) + aNonceWordE;
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 3U)) + 13338989605204591428U) + aNonceWordP;
            aOrbiterE = (aWandererA + RotL64(aScatter, 14U)) + 18306470022403825392U;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 41U)) + 1150696349434090218U) + aOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 13549541786420596437U) + aNonceWordC;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 14302878430259588461U;
            aOrbiterF = RotL64((aOrbiterF * 16813606782134305513U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 4660437084477165225U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 1653628537860912069U;
            aOrbiterD = RotL64((aOrbiterD * 2624835201155303123U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 5594199757006711631U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 11008472193138708891U;
            aOrbiterK = RotL64((aOrbiterK * 13645764762027798301U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 3668516817279364310U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 128159531749679984U;
            aOrbiterI = RotL64((aOrbiterI * 4523246859249826987U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 6378674346113979108U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 11438762460659123362U;
            aOrbiterA = RotL64((aOrbiterA * 2733309638158283953U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 10624263004446482910U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 12546839706919241411U) ^ aOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11468326687628079347U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 8466639576503293921U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 5828694979857951504U) ^ aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7835487310289634515U), 41U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterG, 27U);
            aIngress = aIngress + (RotL64(aOrbiterD, 50U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterK, 11U)) + aWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 29U) + aOrbiterK) + RotL64(aOrbiterF, 58U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 41U)) + aOrbiterI) + aWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 23U) + aOrbiterD) + RotL64(aOrbiterI, 5U)) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 37U) + aOrbiterF) + RotL64(aOrbiterE, 29U)) + aNonceWordH);
            aWandererA = aWandererA + ((((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 57U)) + aNonceWordG);
            aWandererG = aWandererG ^ (((RotL64(aCross, 58U) + aOrbiterE) + RotL64(aOrbiterG, 21U)) + aNonceWordF);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 12U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordL);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 20588U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22336U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21124U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((aIndex + 20663U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCross, 57U)) ^ (RotL64(aPrevious, 44U) + RotL64(aCarry, 23U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererH + RotL64(aIngress, 19U)) + 4751694786009671052U;
            aOrbiterI = (((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 43U)) + 16362725160370844224U) + aOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (((aWandererF + RotL64(aPrevious, 43U)) + RotL64(aCarry, 3U)) + 6360885380915941057U) + aNonceWordJ;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 29U)) + RotL64(aCarry, 21U)) + 5154536007972297036U;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 53U)) + 9362540581874808253U) + aOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aScatter, 37U)) + 13902493871525612934U;
            aOrbiterC = ((aWandererD + RotL64(aIngress, 60U)) + 10208452885367546542U) + aNonceWordO;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 3117030377279160998U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 17286247690414027870U) ^ aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4896931759653832095U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 3930314320040949141U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 7289525252391668404U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15452162299105112187U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 3434167955466809185U) + aNonceWordG;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 17852573095128575663U;
            aOrbiterH = RotL64((aOrbiterH * 1485660158767033425U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 6137259687928853253U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 13992510605237574698U) ^ aOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15346263295995333395U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 6470556523400123474U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 4333255670390099293U;
            aOrbiterK = RotL64((aOrbiterK * 11089933812030082647U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 7700424876430257995U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 16920736951239453071U;
            aOrbiterD = RotL64((aOrbiterD * 8920407493132380497U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 1635071690430295730U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 9966700845966398620U) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 17210048121896546867U), 51U);
            //
            aIngress = RotL64(aOrbiterK, 19U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterD, 51U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 30U));
            aIngress = aIngress + RotL64(aOrbiterI, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aScatter, 21U) + aOrbiterI) + RotL64(aOrbiterC, 3U)) + aNonceWordP);
            aWandererE = aWandererE + (((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterD, 37U)) + aWandererUpdateSaltB[((aIndex + 16U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterD, 23U)) + aOrbiterK) + RotL64(aCarry, 41U)) + aNonceWordB);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 60U)) + aOrbiterK);
            aWandererD = aWandererD + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterJ, 53U)) + aOrbiterI) + aWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 58U) + aOrbiterD) + RotL64(aOrbiterC, 47U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 58U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordM);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 32539U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((aIndex + 31953U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29619U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((aIndex + 32432U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCarry, 52U)) ^ (RotL64(aIngress, 23U) ^ RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererK + RotL64(aIngress, 34U)) + 3970829908171131502U;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 47U)) + 7040283759419531991U) + aNonceWordL;
            aOrbiterE = (((aWandererI + RotL64(aCross, 11U)) + RotL64(aCarry, 13U)) + 11856292169397052901U) + aOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = (((aWandererG + RotL64(aPrevious, 5U)) + RotL64(aCarry, 53U)) + 819598588791819022U) + aOrbiterAssignSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = (((aWandererH + RotL64(aIngress, 57U)) + RotL64(aCarry, 39U)) + 2176451710970866848U) + aNonceWordO;
            aOrbiterJ = (aWandererE + RotL64(aScatter, 27U)) + 6454704928613390494U;
            aOrbiterH = (aWandererA + RotL64(aCross, 41U)) + 11792122387218053841U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 9254780213489752211U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 16591812589999846482U;
            aOrbiterE = RotL64((aOrbiterE * 5425771603523423167U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 1471246223935074832U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 1424843083106386453U;
            aOrbiterJ = RotL64((aOrbiterJ * 15020536982657410783U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 1856469958050891629U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 6331743690452052712U) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 15327924647897459645U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 10351075711345476487U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 9518585245330480185U;
            aOrbiterB = RotL64((aOrbiterB * 3792179827396760391U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 17787514620244712033U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 14182328067398162557U) ^ aOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 18107337388659070197U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 12798088948801072444U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 9563215159275202323U) ^ aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7058145016617349141U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9904919772580498232U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 16579777394992143043U;
            aOrbiterH = RotL64((aOrbiterH * 10516761340320196661U), 39U);
            //
            aIngress = RotL64(aOrbiterH, 43U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 60U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 37U));
            aIngress = aIngress + RotL64(aOrbiterA, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 21U)) + aOrbiterC) + aWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 23U) + aOrbiterA) + RotL64(aOrbiterC, 30U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterJ, 37U)) + aOrbiterB) + aNonceWordI);
            aWandererE = aWandererE + ((((RotL64(aCross, 54U) + aOrbiterB) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 11U)) + aWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterH, 53U)) + aOrbiterK);
            aWandererG = aWandererG + ((((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterC, 43U)) + RotL64(aCarry, 57U)) + aNonceWordK);
            aWandererA = aWandererA ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterC, 13U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + (RotL64(aWandererG, 60U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + RotL64(aWandererA, 27U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ aNonceWordL;
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
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xF04633CD67E4F905ULL + 0xDE90BB27657487ACULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xE4544C08BC4AAC7DULL + 0xE0FC871D8F189BEDULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xFBA86058F7C30713ULL + 0xF385C4842B6C38AFULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xC94B197C7818BDA1ULL + 0xD77A6B2A51A03155ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA2F1AD2B56F1594BULL + 0xAED0698E8D979C1CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xC15B90F1909A23E9ULL + 0xC62F6CDABEDDC187ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xAEEDD6955EAA2E87ULL + 0xE7B7E4879F2755FBULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xD16B2AE0F853FAEBULL + 0xAC67F473C27989F3ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xE507EBB893D7DCF9ULL + 0x9C9F3934D2B1B37BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xC5768DD6043BB0B1ULL + 0xFB23759349350E8BULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x93679066D69D8CAFULL + 0xE23DB11F3FBE1D19ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xE1B69B71D41A6CE3ULL + 0xFB38FBE1BDF04C3EULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xDA869E54BFA82437ULL + 0xF1C76982E46124A7ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xE9E48E140C1D384BULL + 0x97933C3399367CDFULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xD5B4CB131DB869D9ULL + 0xCF50C982927482DFULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xED18E8C58E64CE41ULL + 0xEA76998E0284599CULL);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 2328U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 1636U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 7018U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 1176U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 42U) ^ RotL64(aCross, 57U)) + (RotL64(aCarry, 11U) + RotL64(aIngress, 27U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 58U)) + 2617613537256538553U) + aOrbiterAssignSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aIngress, 27U)) + 16642868916835132715U;
            aOrbiterD = ((aWandererK + RotL64(aCross, 3U)) + 10860291124337073254U) + aNonceWordB;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 19U)) + 6432511273906902472U;
            aOrbiterA = (((aWandererF + RotL64(aCross, 37U)) + RotL64(aCarry, 47U)) + 7505375005848241910U) + aNonceWordK;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 13U)) + RotL64(aCarry, 35U)) + 11086616004678821329U;
            aOrbiterK = (((aWandererG + RotL64(aPrevious, 43U)) + RotL64(aCarry, 13U)) + 3298830587569881951U) + aOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 9775143140064220979U) + aNonceWordC;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 4147601326580823120U;
            aOrbiterD = RotL64((aOrbiterD * 13462244678782260871U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 12245920269898100415U) + aNonceWordD;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 8391940489176734499U;
            aOrbiterA = RotL64((aOrbiterA * 9119606167674098007U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 17876893379544668477U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 18301882058180370541U) ^ aOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16680384667098921309U), 19U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterH) + 6869225862715140102U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordA;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 15404118372589259800U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5766851935950389915U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 17757381020518233814U) + aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 17677969146092374455U;
            aOrbiterE = RotL64((aOrbiterE * 3469432916562405063U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 15783378556632870114U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 5792858258663697864U;
            aOrbiterJ = RotL64((aOrbiterJ * 12008981883482080427U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 11737803388202260296U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 16001927091970715330U;
            aOrbiterF = RotL64((aOrbiterF * 3062030309852922061U), 41U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterE, 57U);
            aIngress = aIngress + (RotL64(aOrbiterD, 21U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 37U));
            aIngress = aIngress + RotL64(aOrbiterJ, 14U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 19U) + aOrbiterE) + RotL64(aOrbiterD, 57U));
            aWandererA = aWandererA + ((((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterK, 46U)) + RotL64(aCarry, 19U)) + aWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 5U) + aOrbiterF) + RotL64(aOrbiterK, 3U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 51U) + aOrbiterH) + RotL64(aOrbiterF, 11U)) + RotL64(aCarry, 53U)) + aWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterJ, 29U)) + aOrbiterA) + aNonceWordF);
            aWandererG = aWandererG + ((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 37U)) + aOrbiterE);
            aWandererD = aWandererD ^ ((RotL64(aCross, 36U) + RotL64(aOrbiterF, 23U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 54U));
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 13U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 14145U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 10004U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 14799U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 10900U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aIngress, 6U)) + (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 41U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 13U)) + 15383045568644941552U) + aOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = (aWandererG + RotL64(aScatter, 43U)) + 17452811657750910067U;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 29U)) + RotL64(aCarry, 11U)) + 15660117718455155603U;
            aOrbiterE = ((aWandererA + RotL64(aCross, 51U)) + 10396441207743665753U) + aNonceWordC;
            aOrbiterC = (((aWandererI + RotL64(aIngress, 19U)) + RotL64(aCarry, 41U)) + 3708971058200841442U) + aOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aCross, 35U)) + 7000673057768598750U;
            aOrbiterK = (((aWandererJ + RotL64(aScatter, 60U)) + RotL64(aCarry, 57U)) + 9886354469011131596U) + aNonceWordD;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 16018065329058043467U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 5024756166109352320U) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 11660932185479046483U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 6587818720728886652U) + aOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 3652672354944162319U) ^ aNonceWordH;
            aOrbiterJ = RotL64((aOrbiterJ * 10807121230791716109U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 6307315649915348048U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 16405347331742979258U;
            aOrbiterE = RotL64((aOrbiterE * 7183142442906743699U), 47U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterK) + 5427299664054601957U) + aOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1]) + aNonceWordK;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 4983381733483185898U;
            aOrbiterG = RotL64((aOrbiterG * 14646556236306407673U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 10182995521328377487U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 8694282877540593550U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14614602561910403893U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 4085927978153269932U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 6176195962815240877U;
            aOrbiterI = RotL64((aOrbiterI * 16792916528959579875U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 6966742100601433005U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 9920952446921247521U;
            aOrbiterK = RotL64((aOrbiterK * 1879821050131820933U), 27U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterI, 35U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aIngress, 21U) + RotL64(aOrbiterC, 57U)) + aOrbiterG) + aNonceWordA);
            aWandererK = aWandererK ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 41U)) + aOrbiterK) + aWandererUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterI, 13U)) + aNonceWordG) + aWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 57U) + aOrbiterG) + RotL64(aOrbiterJ, 4U)) + aNonceWordE);
            aWandererH = aWandererH + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterJ, 51U)) + aOrbiterH) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterK, 23U));
            aWandererG = aWandererG + (((RotL64(aScatter, 48U) + RotL64(aOrbiterJ, 29U)) + aOrbiterE) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 58U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererB, 39U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ aNonceWordB;
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 18822U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((aIndex + 23278U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 17503U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 18872U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCross, 38U)) ^ (RotL64(aIngress, 53U) + RotL64(aCarry, 21U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererD + RotL64(aScatter, 19U)) + 17936518874386450467U) + aOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = (aWandererB + RotL64(aPrevious, 44U)) + 13722737841589910344U;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 57U)) + 11774969167948715796U) + aNonceWordN;
            aOrbiterD = ((aWandererH + RotL64(aCross, 29U)) + RotL64(aCarry, 53U)) + 3640101505680493777U;
            aOrbiterK = ((aWandererI + RotL64(aIngress, 3U)) + RotL64(aCarry, 39U)) + 1369495382725650822U;
            aOrbiterG = (((aWandererF + RotL64(aPrevious, 11U)) + RotL64(aCarry, 3U)) + 11827310354654653345U) + aNonceWordK;
            aOrbiterH = (((aWandererA + RotL64(aScatter, 37U)) + 186037671377175394U) + aOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordC;
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 11428829344234627340U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 2275016369870029068U) ^ aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14936799202145280833U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 15471646673734798328U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 12172082573115640145U) ^ aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9629417882787847753U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 6626736341348283154U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterK) ^ 12220614992483863623U) ^ aOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterF = RotL64((aOrbiterF * 8137086205714097487U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 13157102324253760215U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 4143587482368093601U) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 5060677690991506895U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 11007575246013796426U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 11721585930088637162U;
            aOrbiterK = RotL64((aOrbiterK * 15009627907125738519U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 5720789204450196217U) + aOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 3094696226821431648U;
            aOrbiterG = RotL64((aOrbiterG * 4412033981712165541U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 14675830108100986773U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 9444071495289719645U;
            aOrbiterH = RotL64((aOrbiterH * 10983136361953366557U), 29U);
            //
            aIngress = RotL64(aOrbiterG, 27U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterF, 46U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 5U) + aOrbiterH) + RotL64(aOrbiterG, 22U));
            aWandererE = aWandererE + (((RotL64(aScatter, 21U) + RotL64(aOrbiterD, 13U)) + aOrbiterA) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterD, 47U));
            aWandererA = aWandererA + ((((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 37U)) + aWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterA, 41U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterF, 3U));
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 50U) + RotL64(aOrbiterA, 57U)) + aOrbiterF) + aNonceWordF) + aWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 18U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + RotL64(aWandererB, 43U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordA);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28525U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32659U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26671U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 27853U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aIngress, 41U)) ^ (RotL64(aPrevious, 54U) + RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 35U)) + 2558105147674438050U) + aNonceWordO;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 51U)) + 15856662514774702561U) + aOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aScatter, 27U)) + RotL64(aCarry, 3U)) + 13346869226246584582U;
            aOrbiterB = (((aWandererG + RotL64(aIngress, 19U)) + RotL64(aCarry, 43U)) + 7632111846116243973U) + aOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (((aWandererF + RotL64(aCross, 58U)) + RotL64(aCarry, 27U)) + 2102101361626976279U) + aNonceWordI;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 5U)) + 5605968705067851563U) + aNonceWordC;
            aOrbiterC = (aWandererI + RotL64(aIngress, 41U)) + 6842483186584326681U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 5559797213819425064U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterF) ^ 12422313931331576759U) ^ aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 7399849122565913401U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 2751024420047872601U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 11031320239359798610U;
            aOrbiterG = RotL64((aOrbiterG * 8607639453141148025U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 14366375309473793217U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 11971479429768505316U;
            aOrbiterE = RotL64((aOrbiterE * 10063001532313098203U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 3947595951884469542U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 17882767922372770896U;
            aOrbiterK = RotL64((aOrbiterK * 3361906348965810211U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 513871456983509223U) + aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 5951677013597794294U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8508629569649935293U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 437626309049021931U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 466674061172005705U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1310502572084891157U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 12362602809233133718U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 10525852878882195702U;
            aOrbiterC = RotL64((aOrbiterC * 17755022180514914325U), 19U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 57U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 43U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + RotL64(aOrbiterF, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterG, 37U)) + RotL64(aCarry, 27U)) + aWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 57U)) + aOrbiterK) + aWandererUpdateSaltA[((aIndex + 10U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 44U) + RotL64(aOrbiterB, 13U)) + aOrbiterG);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterF, 24U));
            aWandererF = aWandererF + ((RotL64(aCross, 53U) + aOrbiterE) + RotL64(aOrbiterI, 3U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterE, 43U)) + aOrbiterK) + aNonceWordD);
            aWandererC = aWandererC + (((RotL64(aScatter, 3U) + RotL64(aOrbiterI, 51U)) + aOrbiterK) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 36U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ aNonceWordA;
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
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xCD10B6624AAB4577ULL + 0xC36612D0C1C88E24ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xAAE279671D99B845ULL + 0xE0083C34647182E1ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xC88982D1BE15D8DFULL + 0xDF9EA9DCCBE14084ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xF749795B7E685E9FULL + 0x989668B091F1E661ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xB5C5C1BA1F90E1E5ULL + 0xDE21EF38B7489038ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xD5A3AAA0D57F98A5ULL + 0xBD00B82DE05B48ABULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xB5D59073AD242973ULL + 0xCE9075FE51E8E7B0ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xA257CFA0D0CD0493ULL + 0xF541864AC4CA4006ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x830371300AA9A58DULL + 0xDB9F58C1517FF677ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xBED297D1C72F9D4DULL + 0xB5A644143E6EA581ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xC1D776660414CA83ULL + 0xFF6A3EE8CD51D427ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xDC74B6C8E8DEBE9FULL + 0x9896FE437993F59BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xBE8B7AE6337FB1CDULL + 0x8F61063E2C047E61ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x99B5390078692C09ULL + 0xF99C183B19B4F029ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xCFEC68794B6672C5ULL + 0xB2E80D84A2DE9590ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xB1E44EBAC39080EDULL + 0xCBDD384DD015D725ULL);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 7175U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((aIndex + 1592U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 567U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 2397U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCross, 43U)) + (RotL64(aPrevious, 13U) ^ RotL64(aCarry, 26U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererE + RotL64(aScatter, 19U)) + 9914837590440975587U) + aOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = (aWandererG + RotL64(aPrevious, 3U)) + 6706125076401958051U;
            aOrbiterF = (aWandererJ + RotL64(aIngress, 21U)) + 16570817772679258409U;
            aOrbiterB = (((aWandererI + RotL64(aCross, 58U)) + RotL64(aCarry, 3U)) + 6843705658115186948U) + aNonceWordG;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 5U)) + RotL64(aCarry, 11U)) + 16099930446791572351U;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 39U)) + 5420550009556030459U;
            aOrbiterC = (aWandererA + RotL64(aIngress, 47U)) + 5729549069420177477U;
            aOrbiterG = (aWandererK + RotL64(aCross, 13U)) + 15590601126188675834U;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 24U)) + 13044027390998620029U;
            aOrbiterK = (((aWandererF + RotL64(aIngress, 11U)) + RotL64(aCarry, 19U)) + 11068338135659636772U) + aOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = (aWandererD + RotL64(aPrevious, 51U)) + 6584988841809544332U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 8516813219883915404U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 10647314042912492785U;
            aOrbiterF = RotL64((aOrbiterF * 15559481057047148785U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 201691689889605304U) + aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 15512161798401184003U;
            aOrbiterI = RotL64((aOrbiterI * 11473219183982564709U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 3883760518944464145U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 13861805129175491145U;
            aOrbiterH = RotL64((aOrbiterH * 17194438894492581181U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 12019138626550801486U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 13030350224959652248U;
            aOrbiterB = RotL64((aOrbiterB * 11724200983306280107U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 2643807255422544248U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterA) ^ 4127143302485631794U) ^ aOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 5441038881111578487U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 14602951930809633069U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 4555737199162278494U;
            aOrbiterJ = RotL64((aOrbiterJ * 12415825635220991865U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 6343143902997169834U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 10404783711336491985U) ^ aNonceWordJ;
            aOrbiterA = RotL64((aOrbiterA * 6235474458879439079U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 7406959231434835393U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 6684368109277850196U;
            aOrbiterE = RotL64((aOrbiterE * 8760360417572331159U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 4835889355927954728U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 7917682889852676712U;
            aOrbiterD = RotL64((aOrbiterD * 9045350756570117327U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 10268055422944417055U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 5563744562922937643U) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 12442484191329795173U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 17244672945880141679U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 9914837590440975587U;
            aOrbiterK = RotL64((aOrbiterK * 12269340309792850489U), 11U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 11U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 41U));
            aIngress = aIngress + (RotL64(aOrbiterK, 21U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterD, 51U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 18U));
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterD, 24U));
            aWandererD = aWandererD + ((RotL64(aCross, 60U) + aOrbiterK) + RotL64(aOrbiterB, 47U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterD, 35U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterI, 13U)) + RotL64(aCarry, 35U)) + aWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 21U) + aOrbiterJ) + RotL64(aOrbiterD, 21U));
            aWandererA = aWandererA + ((RotL64(aIngress, 39U) + aOrbiterF) + RotL64(aOrbiterH, 57U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterE, 43U)) + aOrbiterJ);
            aWandererE = aWandererE + (((RotL64(aCross, 27U) + RotL64(aOrbiterC, 5U)) + aOrbiterH) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 14U) + RotL64(aOrbiterI, 19U)) + aOrbiterE) + aNonceWordK);
            aWandererC = aWandererC + ((RotL64(aCross, 41U) + RotL64(aOrbiterC, 39U)) + aOrbiterF);
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 53U) + RotL64(aOrbiterF, 10U)) + aOrbiterA) + aNonceWordD) + aWandererUpdateSaltF[((aIndex + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 58U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 12U));
            aCarry = aCarry + RotL64(aWandererK, 21U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordP;
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 8215U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneD[((aIndex + 13712U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10957U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 13993U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 47U) + RotL64(aIngress, 34U)) ^ (RotL64(aCarry, 21U) ^ RotL64(aPrevious, 3U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererH + RotL64(aCross, 3U)) + 439898681482066326U;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 13U)) + 17362083676671776094U) + aOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = ((aWandererG + RotL64(aIngress, 43U)) + RotL64(aCarry, 3U)) + 6418499837265155024U;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 11U)) + RotL64(aCarry, 23U)) + 17262244253027454972U;
            aOrbiterF = (aWandererB + RotL64(aCross, 24U)) + 2382066162993139503U;
            aOrbiterD = (aWandererC + RotL64(aScatter, 51U)) + 14345808395587174135U;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 35U)) + 7534743166385552851U;
            aOrbiterG = (aWandererK + RotL64(aIngress, 37U)) + 16994453324688523966U;
            aOrbiterI = ((aWandererF + RotL64(aCross, 5U)) + 7079553728544045092U) + aNonceWordG;
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 41U)) + 3562822704508440641U) + aOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 54U)) + RotL64(aCarry, 53U)) + 13990892681975857821U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 1796728922368577238U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 6605161260520067178U;
            aOrbiterB = RotL64((aOrbiterB * 8147537646591674091U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 13994083795942328918U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 6144523182899107711U;
            aOrbiterH = RotL64((aOrbiterH * 4153879991344611283U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 12247462325297436642U) + aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 1065809332002012789U;
            aOrbiterF = RotL64((aOrbiterF * 5496601177032953251U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 10147919864511540753U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 17138553441127273354U;
            aOrbiterC = RotL64((aOrbiterC * 5773875596275267871U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 2653924016109573974U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 6254416952351699582U) ^ aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12756861659704947257U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 813046408080197079U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 9624466135414123483U) ^ aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6960320253124395015U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 972586705850825744U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 155283774901960223U;
            aOrbiterA = RotL64((aOrbiterA * 9928051687724257041U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 18200100644751360406U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 1168426822045686004U;
            aOrbiterD = RotL64((aOrbiterD * 5867027156069481313U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 2271564377169233643U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 1896317305868283986U) ^ aNonceWordB;
            aOrbiterG = RotL64((aOrbiterG * 8080751157990019287U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 10209708407397294552U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 947585551223387294U;
            aOrbiterJ = RotL64((aOrbiterJ * 15339472308062247067U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 12313594490465462211U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 439898681482066326U;
            aOrbiterK = RotL64((aOrbiterK * 12336632799055203705U), 11U);
            //
            aIngress = RotL64(aOrbiterJ, 19U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 24U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + RotL64(aOrbiterF, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aScatter, 51U) + aOrbiterF) + RotL64(aOrbiterE, 34U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterK, 53U)) + aWandererUpdateSaltD[((aIndex + 6U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 30U) + RotL64(aOrbiterJ, 3U)) + aOrbiterC) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 57U) + aOrbiterD) + RotL64(aOrbiterI, 29U)) + aWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 53U) + RotL64(aOrbiterJ, 43U)) + aOrbiterE);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterF, 41U)) + aOrbiterH);
            aWandererK = aWandererK + ((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterB, 21U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 13U) + aOrbiterC) + RotL64(aOrbiterG, 14U)) + aNonceWordE);
            aWandererF = aWandererF + ((RotL64(aIngress, 36U) + aOrbiterD) + RotL64(aOrbiterH, 5U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 47U)) + aOrbiterE);
            aWandererC = aWandererC + (((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 21U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 24U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 27U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 17066U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22428U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19670U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((aIndex + 20100U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aIngress, 27U)) ^ (RotL64(aPrevious, 56U) + RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererB + RotL64(aCross, 43U)) + RotL64(aCarry, 53U)) + 15383045568644941552U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 24U)) + RotL64(aCarry, 57U)) + 17452811657750910067U;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 19U)) + 15660117718455155603U) + aNonceWordM;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 35U)) + 10396441207743665753U) + aOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aIngress, 29U)) + 3708971058200841442U;
            aOrbiterF = (aWandererA + RotL64(aPrevious, 21U)) + 7000673057768598750U;
            aOrbiterG = ((aWandererF + RotL64(aScatter, 39U)) + RotL64(aCarry, 43U)) + 9886354469011131596U;
            aOrbiterH = (aWandererI + RotL64(aCross, 11U)) + 16018065329058043467U;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 54U)) + 5024756166109352320U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 37U)) + 6587818720728886652U;
            aOrbiterA = (((aWandererJ + RotL64(aScatter, 3U)) + 3652672354944162319U) + aOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordB;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 6307315649915348048U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 16405347331742979258U;
            aOrbiterB = RotL64((aOrbiterB * 7183142442906743699U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 5427299664054601957U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 4983381733483185898U;
            aOrbiterF = RotL64((aOrbiterF * 14646556236306407673U), 41U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterH) + 10182995521328377487U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordG;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 8694282877540593550U;
            aOrbiterK = RotL64((aOrbiterK * 14614602561910403893U), 39U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterJ) + 4085927978153269932U) + aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1]) + aNonceWordD;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 6176195962815240877U;
            aOrbiterI = RotL64((aOrbiterI * 16792916528959579875U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 6966742100601433005U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 9920952446921247521U;
            aOrbiterH = RotL64((aOrbiterH * 1879821050131820933U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 11958734477518336014U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 2058335903640404380U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6986170159285417789U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 77366119537297816U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 12072894199692855000U;
            aOrbiterE = RotL64((aOrbiterE * 9083781120514635987U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 11874297832446385377U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 13715562531763053196U;
            aOrbiterC = RotL64((aOrbiterC * 12822488258322963187U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 13664465415354326653U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 10365386643010882315U;
            aOrbiterG = RotL64((aOrbiterG * 3687934567254955761U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 2003863843075564853U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 8864134110143237364U;
            aOrbiterD = RotL64((aOrbiterD * 4586162015675320985U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 8055736412403126985U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 15383045568644941552U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5175405553995854715U), 5U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterH, 35U);
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterJ, 58U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterC, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 12U) + RotL64(aOrbiterD, 13U)) + aOrbiterF) + aWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterA, 36U)) + aOrbiterB);
            aWandererC = aWandererC + ((RotL64(aScatter, 35U) + RotL64(aOrbiterA, 21U)) + aOrbiterK);
            aWandererF = aWandererF ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterG, 11U)) + aOrbiterF);
            aWandererI = aWandererI + ((RotL64(aScatter, 5U) + aOrbiterK) + RotL64(aOrbiterI, 3U));
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 23U) + aOrbiterJ) + RotL64(aOrbiterG, 24U)) + aNonceWordN) + aWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 10U) + RotL64(aOrbiterD, 57U)) + aOrbiterI) + RotL64(aCarry, 3U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 41U) + aOrbiterK) + RotL64(aOrbiterC, 39U));
            aWandererG = aWandererG + (((RotL64(aCross, 51U) + RotL64(aOrbiterE, 27U)) + aOrbiterK) + RotL64(aCarry, 13U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 21U) + aOrbiterH) + RotL64(aOrbiterF, 47U)) + aNonceWordI);
            aWandererE = aWandererE + ((RotL64(aScatter, 27U) + RotL64(aOrbiterH, 29U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 46U));
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = aCarry ^ aNonceWordP;
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 25380U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30616U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24836U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((aIndex + 28693U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 41U)) + (RotL64(aIngress, 53U) ^ RotL64(aCross, 24U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererB + RotL64(aCross, 39U)) + 12222235191147985484U) + aNonceWordE;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 21U)) + 16367317014523328414U;
            aOrbiterI = (aWandererI + RotL64(aScatter, 13U)) + 3511378091284703789U;
            aOrbiterC = (aWandererC + RotL64(aPrevious, 47U)) + 15247492830966725949U;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 3U)) + RotL64(aCarry, 21U)) + 7745995913390407897U;
            aOrbiterD = (((aWandererK + RotL64(aCross, 35U)) + RotL64(aCarry, 57U)) + 6463593307540108810U) + aOrbiterAssignSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aScatter, 50U)) + 1101669311005268630U) + aOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = (aWandererF + RotL64(aPrevious, 57U)) + 12988052764067518580U;
            aOrbiterE = (aWandererH + RotL64(aIngress, 37U)) + 17717179747434679772U;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 41U)) + RotL64(aCarry, 47U)) + 11662190906682400416U;
            aOrbiterG = (aWandererG + RotL64(aScatter, 30U)) + 6563014073547628748U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 13099094932059419219U) + aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 16342730862261868847U;
            aOrbiterI = RotL64((aOrbiterI * 10988124108686164829U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 16855346813127524624U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 6570063128502306944U;
            aOrbiterB = RotL64((aOrbiterB * 4571570049463124831U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 11328352033809240501U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 11640986648833160901U;
            aOrbiterD = RotL64((aOrbiterD * 2895830492089678919U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 2675226158571501666U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 17700531248266458165U;
            aOrbiterA = RotL64((aOrbiterA * 2231403813970188657U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 7729597396731910874U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 15172374484412053756U;
            aOrbiterF = RotL64((aOrbiterF * 149009041406406517U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 9178769489257842683U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 9020154972097834926U;
            aOrbiterE = RotL64((aOrbiterE * 8910504667566521429U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 1317403761217790562U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 17151528554929201571U;
            aOrbiterK = RotL64((aOrbiterK * 3735945655450625203U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 11621882033959669977U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 10289504450815075623U;
            aOrbiterG = RotL64((aOrbiterG * 13365982786836243195U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 16178772981106335703U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 16896130772325866910U) ^ aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6993524735412868965U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 9573223644675562575U) + aNonceWordB;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 17552463713786507189U;
            aOrbiterJ = RotL64((aOrbiterJ * 16103431656424881779U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 4801852246698369631U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 12222235191147985484U) ^ aOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2835204872125428065U), 27U);
            //
            aIngress = RotL64(aOrbiterK, 41U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + (RotL64(aOrbiterH, 21U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 30U));
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterJ, 3U)) + aOrbiterE) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 23U)) + aOrbiterJ);
            aWandererB = aWandererB + (((RotL64(aCross, 51U) + aOrbiterK) + RotL64(aOrbiterE, 39U)) + RotL64(aCarry, 11U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 20U) + aOrbiterG) + RotL64(aOrbiterB, 35U));
            aWandererA = aWandererA + ((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterI, 44U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterG, 5U)) + aOrbiterH);
            aWandererJ = aWandererJ + (((RotL64(aCross, 5U) + RotL64(aOrbiterI, 27U)) + aOrbiterA) + aWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 29U)) + aOrbiterC) + aNonceWordC);
            aWandererK = aWandererK + (((RotL64(aIngress, 44U) + aOrbiterD) + RotL64(aOrbiterB, 11U)) + aWandererUpdateSaltB[((aIndex + 8U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterJ, 53U)) + aOrbiterA);
            aWandererG = aWandererG + ((RotL64(aScatter, 27U) + aOrbiterE) + RotL64(aOrbiterD, 42U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 26U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + RotL64(aWandererJ, 35U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = aCarry ^ aNonceWordG;
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
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xD2A99DF8501CCC7BULL + 0xFFD3F059F3C4FA25ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x87B776688314DEFDULL + 0x8E84C9210C58650FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xF98102C2A71E7E15ULL + 0xC0A87CAE2F905339ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xD5965B036557CC4BULL + 0xF294C0B657AD1BCCULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xFC288BEC457ED70DULL + 0xCBB6C21B1901E674ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xDAA67B0051B7AA6FULL + 0xE5290556CF0EDC44ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x89057A5F175B82DBULL + 0xA8D70F2215722B70ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xCBD88F841E4EFA95ULL + 0xCA70DCA01BA41EA7ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xE6A6802034599867ULL + 0x9D8BAFE8CF475331ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x83E487240C2F7C83ULL + 0x965B969ECA516AA8ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x9DB32E0F5725F41FULL + 0x986F33105542763AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xDEE7382C0D32689DULL + 0xCC536D827324EC08ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xEDF9F7F0AEA83491ULL + 0x8A12BF7E615DBB08ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xDC1FB8DE23DDCA95ULL + 0xE9C7D2C9A7FD1F3FULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xF1ECC3C204A49A89ULL + 0xDBE6BDA9C22D5B1BULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x859E683659775925ULL + 0xA24CF33A75E28BB3ULL);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 4467U)) & S_BLOCK1], 42U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4702U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 4774U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 3616U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aPrevious, 19U)) ^ (RotL64(aCross, 5U) ^ RotL64(aIngress, 38U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererI + RotL64(aIngress, 19U)) + 4980738603982643969U) + aOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = ((aWandererG + RotL64(aCross, 4U)) + 17660278413018470020U) + aNonceWordN;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 43U)) + 17598114429859543466U) + aNonceWordB;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 51U)) + RotL64(aCarry, 5U)) + 10993929335279994739U;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 47U)) + 17967203122976322481U) + aOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = ((aWandererB + RotL64(aCross, 57U)) + RotL64(aCarry, 41U)) + 1872290205549034384U;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 23U)) + 16607778671782810797U) + aNonceWordM;
            aOrbiterA = (aWandererJ + RotL64(aIngress, 28U)) + 4895226930754394376U;
            aOrbiterI = ((aWandererD + RotL64(aScatter, 35U)) + RotL64(aCarry, 23U)) + 14960359005982301383U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 9921642352377700630U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 893281964367208693U;
            aOrbiterB = RotL64((aOrbiterB * 2345509157333444217U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 8232519988397858732U) + aOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 4433022122758913407U;
            aOrbiterH = RotL64((aOrbiterH * 834240393225479419U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 12689609831247168353U) + aOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 404535388957472176U;
            aOrbiterA = RotL64((aOrbiterA * 14534020545479806593U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 3349108201964013155U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 4386449511297371730U;
            aOrbiterI = RotL64((aOrbiterI * 9596273264321140229U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 14314587717949070586U) + aOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 10923886625271054985U;
            aOrbiterD = RotL64((aOrbiterD * 7838969002623486809U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 17634909585329833520U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 2021301459918350372U;
            aOrbiterG = RotL64((aOrbiterG * 1388242915918642741U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 5219599112498224367U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 10641339455385046206U;
            aOrbiterJ = RotL64((aOrbiterJ * 1022283727595400719U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 5003342156562330058U) + aOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 10951027475628404336U;
            aOrbiterE = RotL64((aOrbiterE * 17836928292555158461U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 13040991872592235460U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 11149099984302782267U) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 4248667283139686251U), 23U);
            //
            aIngress = RotL64(aOrbiterI, 34U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aIngress, 34U) + aOrbiterB) + RotL64(aOrbiterF, 57U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 51U) + aOrbiterJ) + RotL64(aOrbiterD, 23U));
            aWandererI = aWandererI + ((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 28U)) + aOrbiterE);
            aWandererF = aWandererF ^ (((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterJ, 39U)) + aNonceWordF);
            aWandererD = aWandererD + ((((RotL64(aScatter, 12U) + aOrbiterG) + RotL64(aOrbiterB, 43U)) + RotL64(aCarry, 51U)) + aNonceWordH);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterD, 5U)) + aOrbiterI);
            aWandererA = aWandererA + ((((RotL64(aIngress, 39U) + RotL64(aOrbiterF, 53U)) + aOrbiterE) + RotL64(aCarry, 21U)) + aWandererUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterH, 35U)) + aWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterD, 18U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 4U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordI;
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 6678U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 7357U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 6781U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((aIndex + 9041U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 43U) ^ RotL64(aCarry, 29U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCross, 14U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererG + RotL64(aIngress, 5U)) + 4476099022490972343U;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 47U)) + RotL64(aCarry, 13U)) + 16836423700375760429U;
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 39U)) + RotL64(aCarry, 41U)) + 8850577488928703557U;
            aOrbiterD = ((aWandererJ + RotL64(aCross, 30U)) + 7091631824560042743U) + aOrbiterAssignSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aPrevious, 51U)) + 12560498899956759494U;
            aOrbiterB = ((aWandererD + RotL64(aCross, 35U)) + 7797973377112012161U) + aOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aIngress, 43U)) + 6173820673874805794U;
            aOrbiterG = ((aWandererB + RotL64(aScatter, 13U)) + 10805025132310245348U) + aNonceWordC;
            aOrbiterI = ((aWandererC + RotL64(aCross, 24U)) + RotL64(aCarry, 3U)) + 7139216143268029968U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 8241544862261635722U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterF) ^ 4735527016563596150U) ^ aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 6621354217673598381U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 5166171126690294033U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 11117641762075368393U;
            aOrbiterE = RotL64((aOrbiterE * 4980156869201219393U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 6312932356458415421U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 1304139291184508668U;
            aOrbiterH = RotL64((aOrbiterH * 90744653170922319U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 10085025354842771067U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 16745854428789531080U;
            aOrbiterG = RotL64((aOrbiterG * 1945983905747274355U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 2497187958708890337U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 16069701876646548995U;
            aOrbiterI = RotL64((aOrbiterI * 16606039730973709495U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 17242004368025978091U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 12334315722243232121U) ^ aOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16528598396696346719U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 8007042082518126895U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 5665686359038811484U;
            aOrbiterD = RotL64((aOrbiterD * 11289316305875751813U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 3913477186958600592U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 16918984318564170343U;
            aOrbiterB = RotL64((aOrbiterB * 5128293326494417281U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 10227611546502931418U) + aNonceWordP;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 7187623463085447228U;
            aOrbiterK = RotL64((aOrbiterK * 8479839369622163181U), 19U);
            //
            aIngress = RotL64(aOrbiterK, 3U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 28U));
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterB, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterJ, 57U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterK, 6U)) + aOrbiterE);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterJ, 39U));
            aWandererF = aWandererF + ((RotL64(aIngress, 56U) + RotL64(aOrbiterE, 47U)) + aOrbiterF);
            aWandererB = aWandererB ^ ((((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterB, 23U)) + aNonceWordB) + aWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 47U) + RotL64(aOrbiterG, 43U)) + aOrbiterD) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterH, 11U)) + aOrbiterK) + aWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 38U) + aOrbiterE) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterB, 34U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 50U));
            aCarry = aCarry + RotL64(aWandererC, 37U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ aNonceWordA;
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 14406U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12962U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 15016U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 14090U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 26U) + RotL64(aIngress, 57U)) ^ (RotL64(aCross, 11U) + RotL64(aPrevious, 39U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 47U)) + 5906639480605353429U) + aOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = (((aWandererK + RotL64(aIngress, 14U)) + 5293518570213287605U) + aOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1]) + aNonceWordM;
            aOrbiterI = (((aWandererB + RotL64(aCross, 23U)) + RotL64(aCarry, 37U)) + 15383185501428521377U) + aNonceWordO;
            aOrbiterA = (aWandererA + RotL64(aScatter, 41U)) + 15364072512743978902U;
            aOrbiterE = ((aWandererF + RotL64(aIngress, 53U)) + RotL64(aCarry, 13U)) + 4525473357144014271U;
            aOrbiterB = (aWandererE + RotL64(aScatter, 37U)) + 10400911938125603074U;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 19U)) + 16417506293824627550U;
            aOrbiterF = ((aWandererD + RotL64(aCross, 27U)) + 2419329331753341815U) + aNonceWordL;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 10U)) + RotL64(aCarry, 53U)) + 14929222427923332069U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 16771573504983922586U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 1863466450051787622U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2585626547126027053U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 12895350137096692415U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 3700979086526298327U;
            aOrbiterD = RotL64((aOrbiterD * 10279730254867618193U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 1977099106211282426U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 6144698304096915742U;
            aOrbiterA = RotL64((aOrbiterA * 5039822990560519609U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 3858895556659724975U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 1283646340363435327U;
            aOrbiterJ = RotL64((aOrbiterJ * 11622421841377018069U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 6240532051889108891U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 757364889381634634U) ^ aNonceWordJ;
            aOrbiterE = RotL64((aOrbiterE * 943852137901972945U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 5272945693977418174U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 6850528198786172283U;
            aOrbiterB = RotL64((aOrbiterB * 1966383079897679953U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 14431587733859573714U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 16124590257870999553U;
            aOrbiterH = RotL64((aOrbiterH * 7755796211433191143U), 29U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterD) + 14912695018110241411U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordN;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 11098623474413346520U) ^ aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15167688959990872051U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 3484847683376368686U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 2295388097292719800U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1240808318176106909U), 57U);
            //
            aIngress = RotL64(aOrbiterJ, 46U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 39U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + RotL64(aOrbiterE, 34U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 29U)) + aOrbiterI);
            aWandererE = aWandererE + ((RotL64(aCross, 11U) + aOrbiterA) + RotL64(aOrbiterJ, 60U));
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 18U) + RotL64(aOrbiterF, 3U)) + aOrbiterE) + aNonceWordB) + aWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 23U) + aOrbiterD) + RotL64(aOrbiterF, 39U)) + aWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 27U) + aOrbiterH) + RotL64(aOrbiterI, 43U));
            aWandererB = aWandererB + (((RotL64(aCross, 43U) + aOrbiterB) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 51U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 37U) + aOrbiterB) + RotL64(aOrbiterE, 24U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterE, 35U)) + aOrbiterH) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 48U) + RotL64(aOrbiterJ, 19U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 38U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ aNonceWordL;
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 16817U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18658U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20304U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 21158U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCross, 6U)) ^ (RotL64(aCarry, 39U) + RotL64(aPrevious, 51U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 39U)) + 11039986441331892533U) + aOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1]) + aNonceWordL;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 19U)) + 6256024955965426119U;
            aOrbiterF = (aWandererI + RotL64(aScatter, 11U)) + 9857443189988995666U;
            aOrbiterK = (((aWandererD + RotL64(aIngress, 26U)) + 11900944813380998208U) + aOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordO;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 57U)) + RotL64(aCarry, 13U)) + 8422577734978875541U;
            aOrbiterD = (aWandererB + RotL64(aCross, 53U)) + 3100835100713928724U;
            aOrbiterC = (aWandererF + RotL64(aIngress, 47U)) + 11871553509810206993U;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 38U)) + RotL64(aCarry, 21U)) + 17614749493763417027U;
            aOrbiterG = (aWandererG + RotL64(aPrevious, 43U)) + 3638372131856199916U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 6582275259281025770U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 17016882418498941958U;
            aOrbiterF = RotL64((aOrbiterF * 4269869255230867823U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 1747214688658984715U) + aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 9356088987044015278U;
            aOrbiterA = RotL64((aOrbiterA * 16221733545319753695U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 4056238112133473456U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 16013150119949532998U;
            aOrbiterC = RotL64((aOrbiterC * 12913648646318115315U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 16076621211111834889U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 9940824359571581765U;
            aOrbiterB = RotL64((aOrbiterB * 11624767861336495331U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 15624084004784515753U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 7630989544834680335U;
            aOrbiterK = RotL64((aOrbiterK * 12261063237156822067U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 18003586430673313786U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 1654118743290334161U;
            aOrbiterD = RotL64((aOrbiterD * 1153250137357176071U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 3254189676528343910U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 15629083361573065165U) ^ aOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17024833368570949107U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 10056859810555674806U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 15976683222786846254U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2801754232182942635U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 11872378594829637933U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterC) ^ 7633773773528713489U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterE = RotL64((aOrbiterE * 8218288492011593353U), 5U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 51U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 23U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + RotL64(aOrbiterC, 26U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 60U) + aOrbiterE) + RotL64(aOrbiterD, 39U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 43U) + aOrbiterG) + RotL64(aOrbiterE, 43U)) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterC, 35U)) + aOrbiterG);
            aWandererB = aWandererB + ((RotL64(aCross, 39U) + aOrbiterA) + RotL64(aOrbiterI, 13U));
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 60U)) + aOrbiterA) + aNonceWordJ) + aWandererUpdateSaltC[((aIndex + 14U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 5U) + aOrbiterF) + RotL64(aOrbiterK, 21U)) + aNonceWordB);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 34U) + RotL64(aOrbiterK, 3U)) + aOrbiterG) + aWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 21U) + aOrbiterF) + RotL64(aOrbiterB, 47U)) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 54U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (RotL64(aWandererA, 54U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordD);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 25097U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((aIndex + 25301U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24348U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23573U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCarry, 41U)) + (RotL64(aCross, 26U) ^ RotL64(aIngress, 53U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 19U)) + RotL64(aCarry, 47U)) + 13204735390996728477U;
            aOrbiterI = (aWandererA + RotL64(aPrevious, 24U)) + 851171359595647173U;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 47U)) + RotL64(aCarry, 19U)) + 16745304202825290723U;
            aOrbiterE = ((aWandererI + RotL64(aCross, 39U)) + 562392736584913979U) + aNonceWordB;
            aOrbiterD = ((((aWandererG + RotL64(aPrevious, 53U)) + RotL64(aCarry, 27U)) + 3244267012529053918U) + aOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordG;
            aOrbiterB = ((aWandererB + RotL64(aCross, 29U)) + 17282536111067869133U) + aOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aIngress, 5U)) + 14851130066471729068U;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 35U)) + 5256130407952363129U) + aNonceWordI;
            aOrbiterA = (aWandererK + RotL64(aIngress, 10U)) + 2904742485828362001U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 3723346325449225387U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 5344621093694027341U) ^ aOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9044881458629673499U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 12919263300833603026U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 17989801264160996071U;
            aOrbiterB = RotL64((aOrbiterB * 15468293047311883751U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 5022175042377172157U) + aNonceWordN;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 16684822380107847758U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2834049270263837537U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 2740326510600876682U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 13981423865219318820U;
            aOrbiterA = RotL64((aOrbiterA * 14593082145080056441U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 231945878229848395U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 14139797734944312580U;
            aOrbiterJ = RotL64((aOrbiterJ * 6492256080432266407U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 16704102101387552373U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 8506734780526852552U;
            aOrbiterE = RotL64((aOrbiterE * 4684566118627414659U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 2774630043988894695U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 12490034334296488127U;
            aOrbiterK = RotL64((aOrbiterK * 16765455396278233145U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 545238171291436006U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 1023872898002379590U;
            aOrbiterI = RotL64((aOrbiterI * 8626333831510136515U), 29U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterK) + 5065187021047872560U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordK;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 10391809965648089863U) ^ aOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10912471108849550469U), 19U);
            //
            aIngress = RotL64(aOrbiterE, 41U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 54U));
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aScatter, 58U) + RotL64(aOrbiterK, 43U)) + aOrbiterA) + aNonceWordH);
            aWandererB = aWandererB + ((((RotL64(aCross, 19U) + aOrbiterH) + RotL64(aOrbiterI, 30U)) + aNonceWordL) + aWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterD, 21U)) + aOrbiterH);
            aWandererK = aWandererK + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterB, 51U)) + aOrbiterI);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 54U) + RotL64(aOrbiterK, 11U)) + aOrbiterI) + aNonceWordP);
            aWandererI = aWandererI + (((RotL64(aScatter, 13U) + aOrbiterI) + RotL64(aOrbiterJ, 47U)) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 37U) + aOrbiterE) + RotL64(aOrbiterK, 56U));
            aWandererA = aWandererA + (((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterE, 5U)) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterH, 37U)) + aOrbiterE) + aWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 54U));
            aCarry = aCarry + RotL64(aWandererI, 39U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordP);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 27606U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((aIndex + 29994U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32309U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneB[((aIndex + 28509U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 37U) ^ RotL64(aIngress, 23U)) + (RotL64(aCross, 10U) ^ RotL64(aPrevious, 53U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererB + RotL64(aIngress, 48U)) + 15904465836916519864U;
            aOrbiterG = (((aWandererH + RotL64(aCross, 13U)) + RotL64(aCarry, 21U)) + 17725629806317789307U) + aOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = ((aWandererE + RotL64(aScatter, 19U)) + RotL64(aCarry, 11U)) + 13794170125914914828U;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 27U)) + 2149055907476874332U) + aNonceWordD;
            aOrbiterE = (((aWandererA + RotL64(aIngress, 37U)) + 5342047776745074649U) + aOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordE;
            aOrbiterB = (aWandererG + RotL64(aScatter, 3U)) + 8268148484060546838U;
            aOrbiterH = (aWandererJ + RotL64(aCross, 23U)) + 10821151364028563719U;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 43U)) + RotL64(aCarry, 47U)) + 4294213820894407378U;
            aOrbiterI = (aWandererC + RotL64(aIngress, 58U)) + 10884726101307943090U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 16432210042202444824U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 15196602644336228055U) ^ aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12680438355124070237U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 14117787670220328165U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 219833877949480215U;
            aOrbiterE = RotL64((aOrbiterE * 10736293047771972173U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 3326396981881473962U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 14918513066311426279U) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 14269763278564574663U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 11795234681370163206U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 3068267285352664813U;
            aOrbiterF = RotL64((aOrbiterF * 15746255933920904619U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 245233356957999496U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 709926406353796673U;
            aOrbiterI = RotL64((aOrbiterI * 13627039596842073595U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 5378105439430271038U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 10114555061122044430U;
            aOrbiterD = RotL64((aOrbiterD * 5351295043424885549U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 13233010815716769713U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 8231291294833548389U;
            aOrbiterC = RotL64((aOrbiterC * 10840516135212753869U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 7160760224172419829U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 14767926435411546785U) ^ aNonceWordP;
            aOrbiterB = RotL64((aOrbiterB * 1643485739468851073U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 4464245330038080103U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 15778166658285494712U) ^ aOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13980891936095282989U), 37U);
            //
            aIngress = RotL64(aOrbiterH, 60U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 39U));
            aIngress = aIngress + RotL64(aOrbiterE, 14U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aPrevious, 46U) + RotL64(aOrbiterF, 48U)) + aOrbiterE) + RotL64(aCarry, 37U)) + aWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterD, 13U)) + aOrbiterG) + aNonceWordF);
            aWandererA = aWandererA + (((RotL64(aCross, 29U) + RotL64(aOrbiterD, 37U)) + aOrbiterC) + aNonceWordB);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 41U) + aOrbiterI) + RotL64(aOrbiterC, 29U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 5U) + aOrbiterI) + RotL64(aOrbiterB, 41U)) + aNonceWordM) + aWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterG, 5U)) + aOrbiterB);
            aWandererD = aWandererD + (((RotL64(aCross, 35U) + RotL64(aOrbiterH, 53U)) + aOrbiterG) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 56U) + aOrbiterC) + RotL64(aOrbiterF, 19U));
            aWandererB = aWandererB + ((RotL64(aIngress, 51U) + RotL64(aOrbiterK, 60U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 54U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordA;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xF297F7B405D9D02DULL + 0xA05701B86C0A5E70ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xD93C7BEA5A68BF13ULL + 0xC73AA47DEC8597F6ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xCF8D5252FE7203F3ULL + 0xD5DC9284F78117F7ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x8B023ED424743ABDULL + 0x82973E592781E4D9ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x9E5B028404FCB681ULL + 0x872E14D6389934FFULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xD3A68383220C40F5ULL + 0x895DFB505FBEC075ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xE979EA9E49521131ULL + 0xC045EF647DF01AF4ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xDD4E465E581ED3DBULL + 0xC74FCD0BDAC0884CULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xEE78D35AE17CC887ULL + 0x9FC5856A31A36056ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x817640BE4CF7229DULL + 0x82CF98A033C800BBULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x9C8B7C64F6E8A9DFULL + 0x8C066E506AD23680ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xE323E772A1FF3EE9ULL + 0xB4C79CD2A0E00D3FULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xB0E6DD5856ADBAAFULL + 0x90B776D62BFC33FDULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x925BD55D8DC10DE9ULL + 0xEF32B8DC5EDACD55ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xFC47AE0FC0761C1DULL + 0xCC3FE084AB4CF8C3ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xD2711147FE74C391ULL + 0xEC614A30EB4D9F60ULL);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 4739U)) & S_BLOCK1], 10U) ^ RotL64(aKeyRowReadA[((aIndex + 4164U)) & W_KEY1], 27U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 780U)) & W_KEY1], 47U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 1705U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCross, 37U)) ^ (RotL64(aCarry, 3U) + RotL64(aIngress, 50U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterB = (aWandererC + RotL64(aCross, 3U)) + 7948891781097675369U;
            aOrbiterC = (((aWandererJ + RotL64(aPrevious, 27U)) + RotL64(aCarry, 43U)) + 13928362874228230226U) + aNonceWordC;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 51U)) + 10776180542602258926U) + aPhaseAOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = ((aWandererD + RotL64(aIngress, 43U)) + RotL64(aCarry, 19U)) + 5735115172149470447U;
            aOrbiterI = (aWandererH + RotL64(aPrevious, 18U)) + 5353591822981766987U;
            aOrbiterK = (aWandererE + RotL64(aIngress, 37U)) + 562301708107268570U;
            aOrbiterD = (((aWandererA + RotL64(aCross, 11U)) + RotL64(aCarry, 3U)) + 10467810247578364868U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 14541630141152308564U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 2350076897065139429U;
            aOrbiterA = RotL64((aOrbiterA * 12222554362482034393U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 17519109078651162228U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 6061035173339902910U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10021905773432907835U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 15654836633731000065U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 13723521735153718904U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14459516479283070563U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 2849680038315532197U) + aNonceWordM;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 17336102435576647923U;
            aOrbiterD = RotL64((aOrbiterD * 10984689101753586739U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 7671010488872356142U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 11485114338165600777U;
            aOrbiterB = RotL64((aOrbiterB * 4162584865462407791U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 8759060657343458985U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 11009137869375286581U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8741417343929809115U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 15792999392743144135U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterD) ^ 6180808423175992479U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterC = RotL64((aOrbiterC * 13681230339693676907U), 27U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 43U);
            aIngress = aIngress + (RotL64(aOrbiterK, 4U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + RotL64(aOrbiterH, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterB, 21U)) + RotL64(aCarry, 43U)) + aNonceWordO);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 51U) + aOrbiterH) + RotL64(aOrbiterA, 27U));
            aWandererE = aWandererE + (((RotL64(aIngress, 20U) + RotL64(aOrbiterA, 13U)) + aOrbiterB) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 41U) + aOrbiterI) + RotL64(aOrbiterC, 53U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 5U) + aOrbiterH) + RotL64(aOrbiterK, 44U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 27U) + aOrbiterC) + RotL64(aOrbiterD, 35U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 11U) + aOrbiterI) + RotL64(aOrbiterH, 5U)) + aNonceWordG);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 22U));
            aCarry = aCarry + RotL64(aWandererE, 35U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordL;
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 5524U)) & S_BLOCK1], 35U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 9166U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 6376U)) & W_KEY1], 19U) ^ RotL64(aKeyRowReadB[((aIndex + 8798U)) & W_KEY1], 6U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aIngress, 60U)) ^ (RotL64(aPrevious, 11U) + RotL64(aCross, 47U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterC = ((aWandererC + RotL64(aScatter, 5U)) + 15813325389431304548U) + aNonceWordB;
            aOrbiterE = (aWandererF + RotL64(aIngress, 11U)) + 2223874171125403602U;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 37U)) + 5510483568496824130U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aCross, 20U)) + RotL64(aCarry, 51U)) + 15474152493495661876U;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 27U)) + RotL64(aCarry, 11U)) + 16846339705130829195U;
            aOrbiterB = (aWandererB + RotL64(aCross, 43U)) + 1289670576865739669U;
            aOrbiterG = (((aWandererD + RotL64(aScatter, 57U)) + RotL64(aCarry, 23U)) + 18017354919647006944U) + aPhaseAOrbiterAssignSaltA[((aIndex + 18U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 8539685539928984921U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 3333721400836704048U;
            aOrbiterJ = RotL64((aOrbiterJ * 3745286323481400085U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 2261560416623815491U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 4377786131746816567U;
            aOrbiterC = RotL64((aOrbiterC * 9164777834392621157U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 18047393176583722719U) + aNonceWordP;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 8184724021940434631U;
            aOrbiterK = RotL64((aOrbiterK * 9800116157750921119U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 10469895939183324807U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 14543391765109879223U;
            aOrbiterE = RotL64((aOrbiterE * 4817987697437667225U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 5757225781746158178U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 3539000495894022869U;
            aOrbiterH = RotL64((aOrbiterH * 1032298408884695925U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 11288971092707065923U) + aNonceWordA;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 2761384065186568294U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3323838837427471051U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 7120580145300417101U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 6977246291769372866U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15170353875184253779U), 5U);
            //
            aIngress = RotL64(aOrbiterK, 27U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 4U));
            aIngress = aIngress + RotL64(aOrbiterB, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterK, 51U)) + aOrbiterH) + aNonceWordC);
            aWandererD = aWandererD + ((RotL64(aScatter, 57U) + aOrbiterG) + RotL64(aOrbiterH, 57U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterC, 29U)) + aNonceWordM);
            aWandererA = aWandererA + (((RotL64(aCross, 29U) + aOrbiterJ) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 18U) + aOrbiterG) + RotL64(aOrbiterC, 13U));
            aWandererJ = aWandererJ + (((((RotL64(aIngress, 51U) + aOrbiterB) + RotL64(aOrbiterG, 22U)) + RotL64(aCarry, 5U)) + aNonceWordK) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 11U) + aOrbiterB) + RotL64(aOrbiterE, 41U)) + aPhaseAWandererUpdateSaltC[((aIndex + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 60U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordD;
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15726U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((aIndex + 14714U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 11428U)) & W_KEY1], 28U) ^ RotL64(aKeyRowReadB[((aIndex + 13712U)) & W_KEY1], 43U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 60U) ^ RotL64(aPrevious, 39U)) + (RotL64(aIngress, 13U) + RotL64(aCross, 27U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterI = (((aWandererG + RotL64(aPrevious, 29U)) + RotL64(aCarry, 39U)) + 3199575576585871314U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (((aWandererE + RotL64(aIngress, 13U)) + 2533378188975571824U) + aPhaseAOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1]) + aNonceWordP;
            aOrbiterG = (aWandererK + RotL64(aScatter, 22U)) + 6819782112558312658U;
            aOrbiterE = (aWandererI + RotL64(aCross, 47U)) + 12690060987724798497U;
            aOrbiterH = (((aWandererC + RotL64(aIngress, 53U)) + RotL64(aCarry, 57U)) + 7088375139715629606U) + aNonceWordE;
            aOrbiterD = (((aWandererF + RotL64(aCross, 5U)) + RotL64(aCarry, 11U)) + 17785618677423695666U) + aNonceWordM;
            aOrbiterK = (aWandererH + RotL64(aScatter, 39U)) + 1714999280296491277U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 17611338506932491624U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 6475727359297421201U;
            aOrbiterG = RotL64((aOrbiterG * 15133348244242438069U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 2347744591204119530U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 2739317903351401068U;
            aOrbiterA = RotL64((aOrbiterA * 15435029315209475631U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 8663535261373274338U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterH) ^ 8205245127823536479U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterI = RotL64((aOrbiterI * 13857005110466856439U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 8916510616749754516U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 3944805940148512932U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 18082271583211389701U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 14094751253118853302U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 14094299829196076311U;
            aOrbiterH = RotL64((aOrbiterH * 6370012560657108493U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 3940673811518673802U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 3015106523254484839U;
            aOrbiterD = RotL64((aOrbiterD * 9655401190755573379U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 15404103131982599922U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 1828655763233900875U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13024358077740310049U), 13U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 27U);
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterH, 42U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aScatter, 29U) + aOrbiterE) + RotL64(aOrbiterI, 57U)) + aNonceWordC);
            aWandererI = aWandererI + ((((RotL64(aCross, 19U) + aOrbiterI) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 47U)) + aNonceWordA);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterK, 34U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 41U) + RotL64(aOrbiterG, 19U)) + aOrbiterD) + RotL64(aCarry, 13U)) + aPhaseAWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterE, 27U)) + aNonceWordH);
            aWandererF = aWandererF + (((RotL64(aPrevious, 10U) + RotL64(aOrbiterD, 13U)) + aOrbiterE) + aPhaseAWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterA, 47U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 34U));
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + RotL64(aWandererG, 47U);
            aCarry = aCarry + RotL64(aIngress, 30U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordA);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 17820U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((aIndex + 18815U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18107U)) & S_BLOCK1], 23U) ^ RotL64(mSource[((aIndex + 18335U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCarry, 53U)) + (RotL64(aCross, 4U) + RotL64(aPrevious, 41U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterF = (aWandererI + RotL64(aIngress, 44U)) + 826930775230515406U;
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 27U)) + 5137814617363250861U) + aNonceWordF;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 19U)) + 14761561947426681616U) + aPhaseAOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = (((aWandererE + RotL64(aCross, 11U)) + RotL64(aCarry, 5U)) + 12773023438753662590U) + aNonceWordP;
            aOrbiterI = (((aWandererK + RotL64(aScatter, 53U)) + RotL64(aCarry, 41U)) + 7331345852207096322U) + aPhaseAOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 5U)) + 3899381212671247460U) + aNonceWordN;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 37U)) + RotL64(aCarry, 21U)) + 10072004147620068599U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 3424585039401897560U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 8246760141625966321U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11478879365443736383U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 3655992860610853290U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 11154618022505863898U;
            aOrbiterK = RotL64((aOrbiterK * 4791494171286145231U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 15629361991059709973U) + aNonceWordH;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 10842068502278489664U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17223002513104960799U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 5571312349016336686U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 589313823745748879U;
            aOrbiterI = RotL64((aOrbiterI * 1356685926549786027U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 13633457935771935260U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 12684602052812183096U;
            aOrbiterF = RotL64((aOrbiterF * 4689206269919806711U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 5711307583717354204U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 7181854170553728211U;
            aOrbiterA = RotL64((aOrbiterA * 9835601115561325911U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 1884620014396115821U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 1471516373272364262U;
            aOrbiterC = RotL64((aOrbiterC * 5126319375714848029U), 3U);
            //
            aIngress = RotL64(aOrbiterK, 27U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterA, 44U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterI, 20U)) + aOrbiterA) + aPhaseAWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 13U)) + aOrbiterD) + RotL64(aCarry, 29U)) + aNonceWordJ);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 3U) + aOrbiterF) + RotL64(aOrbiterD, 5U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterK, 47U)) + aOrbiterC) + RotL64(aCarry, 13U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 21U) + aOrbiterC) + RotL64(aOrbiterF, 53U));
            aWandererE = aWandererE + ((RotL64(aScatter, 12U) + RotL64(aOrbiterJ, 27U)) + aOrbiterF);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 53U) + aOrbiterI) + RotL64(aOrbiterK, 35U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + RotL64(aWandererJ, 50U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordD);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 25232U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25561U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22909U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25153U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aIngress, 44U)) + (RotL64(aCross, 27U) + RotL64(aPrevious, 11U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterJ = (((aWandererG + RotL64(aPrevious, 35U)) + RotL64(aCarry, 27U)) + 18255347001097480328U) + aNonceWordO;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 27U)) + 13679246790311505735U) + aPhaseAOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = ((aWandererH + RotL64(aCross, 41U)) + RotL64(aCarry, 57U)) + 10565839529765027116U;
            aOrbiterC = (((aWandererA + RotL64(aScatter, 52U)) + RotL64(aCarry, 43U)) + 14327172566224769901U) + aNonceWordN;
            aOrbiterB = ((aWandererC + RotL64(aCross, 21U)) + 16239024612038195174U) + aNonceWordB;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 13U)) + 13800012174212131890U) + aPhaseAOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aIngress, 5U)) + 13900288860157577583U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 4144386119777112740U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 3154558262670631372U;
            aOrbiterD = RotL64((aOrbiterD * 13236911910092437063U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 7456728543137614001U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 11709519851158935384U;
            aOrbiterJ = RotL64((aOrbiterJ * 7016689518570071587U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 15607438907832240304U) + aNonceWordH;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 9276575329661725624U) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 8879744070762412745U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 6459435969129449226U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 6442382118416542275U;
            aOrbiterE = RotL64((aOrbiterE * 2921027306686588233U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 12117432107282150865U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 6831279293184793243U;
            aOrbiterB = RotL64((aOrbiterB * 2435360641135249073U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 9520022957804572889U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 8322178689474588679U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1627707191467537115U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 4162401591586869316U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 8994015844714895961U;
            aOrbiterF = RotL64((aOrbiterF * 15421910378057951895U), 57U);
            //
            aIngress = RotL64(aOrbiterB, 39U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 37U) + aOrbiterJ) + RotL64(aOrbiterC, 35U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 41U)) + aOrbiterB) + RotL64(aCarry, 27U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterD, 21U)) + aOrbiterC);
            aWandererH = aWandererH + ((((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 3U)) + aNonceWordE);
            aWandererC = aWandererC ^ ((RotL64(aCross, 23U) + aOrbiterF) + RotL64(aOrbiterB, 56U));
            aWandererA = aWandererA + ((RotL64(aScatter, 5U) + RotL64(aOrbiterC, 3U)) + aOrbiterE);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 58U) + aOrbiterK) + RotL64(aOrbiterF, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 52U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 43U);
            aCarry = aCarry + RotL64(aIngress, 28U);
            aCarry = aCarry ^ aNonceWordJ;
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 32440U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneB[((aIndex + 31553U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29144U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29145U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 47U) ^ RotL64(aCross, 35U)) + (RotL64(aPrevious, 18U) + RotL64(aCarry, 5U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterC = ((((aWandererG + RotL64(aCross, 13U)) + RotL64(aCarry, 13U)) + 3255291173184001106U) + aPhaseAOrbiterAssignSaltB[((aIndex + 22U)) & S_SALT1]) + aNonceWordH;
            aOrbiterE = (((aWandererJ + RotL64(aScatter, 43U)) + 15308468160116255528U) + aPhaseAOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1]) + aNonceWordC;
            aOrbiterD = (((aWandererH + RotL64(aIngress, 29U)) + RotL64(aCarry, 47U)) + 18186972408589866656U) + aNonceWordE;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 37U)) + RotL64(aCarry, 35U)) + 4439324265978331914U;
            aOrbiterF = (aWandererA + RotL64(aCross, 51U)) + 13099263173016322486U;
            aOrbiterA = (aWandererC + RotL64(aScatter, 60U)) + 7041561081767500660U;
            aOrbiterG = (aWandererF + RotL64(aIngress, 5U)) + 6196422612687812971U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 7664260932541281413U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 17802347823020441056U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2220679459017369255U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 4253107484061190446U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 13799496534030645312U;
            aOrbiterF = RotL64((aOrbiterF * 9167675060053848207U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 14252892847595951926U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterE) ^ 5663527578664291422U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 18314294235895182465U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 11148755959699137661U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 17036900929333594592U;
            aOrbiterG = RotL64((aOrbiterG * 16041243617369003291U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 2403828181385259549U) + aNonceWordJ;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 17813580350434928194U) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 13666780980793857831U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 5623611126885414523U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 7293224381174846969U;
            aOrbiterJ = RotL64((aOrbiterJ * 7032561584670788117U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 10602620906929686163U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 18015916257203385982U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10684090189688871993U), 53U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterG, 30U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 41U));
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterD, 5U)) + aOrbiterA) + aNonceWordO);
            aWandererC = aWandererC + ((((RotL64(aIngress, 11U) + RotL64(aOrbiterD, 13U)) + aOrbiterC) + RotL64(aCarry, 3U)) + aNonceWordM);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterC, 41U)) + aOrbiterE) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 39U) + aOrbiterJ) + RotL64(aOrbiterF, 21U)) + RotL64(aCarry, 19U)) + aNonceWordK);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterG, 47U)) + aOrbiterE) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 50U) + aOrbiterJ) + RotL64(aOrbiterD, 27U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterG, 34U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererA, 60U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + RotL64(aWandererC, 11U);
            aCarry = aCarry + RotL64(aIngress, 24U);
            aCarry = aCarry ^ aNonceWordF;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x888411EECAF27039ULL + 0xEDBECDDDB7DAB2AAULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xA943A093F93C9C91ULL + 0x80A7848E0EA7256CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xD1763A28FC8A8EF7ULL + 0xDE5096FD415C58EEULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xD0873EC53CCB1637ULL + 0x8A44D02D8DDA3369ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xD8423F85D6510903ULL + 0xA3AC16BC21C7073FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x8AEEBBAEA708C729ULL + 0xBB0A85C7FB2BE419ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xA8FD25470F86FCBFULL + 0xED2E77C621C54955ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xEFFCD014E01B6E07ULL + 0xBF5F465268664D27ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xC08E704131434EB7ULL + 0xDFB5D41F0F56CF74ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xC72D713F8A676E47ULL + 0x9F4C1009CE76D617ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xA525D297E0338EF9ULL + 0xC79F860402C7D6CEULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xF481C343FEFF98D7ULL + 0xE4EDB28BB2096E15ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x8B44D41F3CF67FEDULL + 0xBA3B94EC01412EFFULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x9245F3A07E46FEA9ULL + 0xA40E942F53C057DBULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xA9ABA2AE63CF794FULL + 0xF0783A0B4EA39977ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xC258D34BC2AB429DULL + 0xD5AB394F17722905ULL);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1796U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1495U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 162U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 200U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 54U) + RotL64(aCross, 5U)) + (RotL64(aIngress, 21U) ^ RotL64(aCarry, 41U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterD = ((((aWandererJ + RotL64(aCross, 18U)) + RotL64(aCarry, 23U)) + 12122689833405846292U) + aPhaseBOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1]) + aNonceWordA;
            aOrbiterG = ((aWandererB + RotL64(aScatter, 5U)) + 9640400270962766788U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 51U)) + 9141937998266739071U) + aNonceWordJ;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 35U)) + RotL64(aCarry, 43U)) + 12899395770434090537U;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 43U)) + RotL64(aCarry, 11U)) + 13457918115408031842U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 15134784483576000943U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 12540961268790055438U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3295706140418040089U), 39U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterA) + 6306886773092764230U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1]) + aNonceWordO;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 13573343491337243121U;
            aOrbiterD = RotL64((aOrbiterD * 15893457012357368707U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 8545588657348974413U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 10891410570357275120U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5399310978367842841U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 2877137119767060151U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 9178097682386595144U) ^ aNonceWordK;
            aOrbiterG = RotL64((aOrbiterG * 3524486002084427513U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 15528007881855616978U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 11368419529245281435U;
            aOrbiterA = RotL64((aOrbiterA * 12433207037378339309U), 51U);
            //
            aIngress = RotL64(aOrbiterF, 34U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aCross, 53U) + RotL64(aOrbiterD, 47U)) + aOrbiterA) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 29U) + aOrbiterB) + RotL64(aOrbiterG, 27U)) + aNonceWordP) + aPhaseBWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 58U)) + aOrbiterD) + aNonceWordB);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 3U) + aOrbiterD) + RotL64(aOrbiterF, 19U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aIngress, 40U) + RotL64(aOrbiterD, 11U)) + aOrbiterG) + RotL64(aCarry, 57U)) + aNonceWordI);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererC, 21U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordP);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 7495U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 6968U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10633U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5792U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 23U)) + (RotL64(aCross, 53U) ^ RotL64(aPrevious, 38U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterI = ((aWandererC + RotL64(aIngress, 47U)) + RotL64(aCarry, 5U)) + 6467297102954816305U;
            aOrbiterG = ((aWandererA + RotL64(aCross, 56U)) + RotL64(aCarry, 41U)) + 7921154109831114952U;
            aOrbiterB = (((aWandererE + RotL64(aScatter, 27U)) + 5701131763215638919U) + aPhaseBOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterD = (((aWandererI + RotL64(aPrevious, 35U)) + RotL64(aCarry, 19U)) + 10022999076719002684U) + aPhaseBOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aScatter, 19U)) + 4367135243038982316U) + aNonceWordC;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 14445846824810383592U) + aNonceWordO;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 7683697954545773253U;
            aOrbiterB = RotL64((aOrbiterB * 4832124801510084629U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 17517006750428030899U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 2052484792684025476U;
            aOrbiterK = RotL64((aOrbiterK * 12463117571122469643U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 6279463052085808926U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 679280153651813684U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3047031560593583881U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 2939516520188460569U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterB) ^ 1960616434964712325U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 15145998415466343039U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 12273819390719947361U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 5685033154709449397U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9845666295874714959U), 3U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterG, 39U);
            aIngress = aIngress + (RotL64(aOrbiterB, 14U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aPrevious, 14U) + RotL64(aOrbiterI, 27U)) + aOrbiterG) + RotL64(aCarry, 35U)) + aNonceWordF);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterI, 57U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterD, 38U)) + aOrbiterB) + aNonceWordK) + aPhaseBWandererUpdateSaltB[((aIndex + 20U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterG, 11U)) + aNonceWordB) + aPhaseBWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 35U) + RotL64(aOrbiterK, 3U)) + aOrbiterB) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 13U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15946U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((aIndex + 13214U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14973U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14782U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 5U)) + (RotL64(aCross, 39U) ^ RotL64(aIngress, 52U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterB = ((aWandererD + RotL64(aIngress, 3U)) + 18144572925667544139U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 14U)) + RotL64(aCarry, 23U)) + 5659758077574059728U;
            aOrbiterJ = ((((aWandererG + RotL64(aCross, 53U)) + RotL64(aCarry, 3U)) + 6343330616999166392U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordE;
            aOrbiterC = (aWandererK + RotL64(aScatter, 35U)) + 17754639838410839447U;
            aOrbiterA = (((aWandererH + RotL64(aIngress, 43U)) + RotL64(aCarry, 35U)) + 9451843819849581729U) + aNonceWordB;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 7957854457197462212U) + aNonceWordK;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 1461994799722205010U;
            aOrbiterJ = RotL64((aOrbiterJ * 13431080873536691809U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 18002214276252170177U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterC) ^ 14689869073147027164U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterD = RotL64((aOrbiterD * 12242482963989582191U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 3978104368003440293U) + aNonceWordP;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 8512135845221335386U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10506667163729414667U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 1477533446382953439U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 2166717790929947990U;
            aOrbiterC = RotL64((aOrbiterC * 6538884492418324461U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 8082437060686606995U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 4363687722464700362U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7199165810993478887U), 29U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterD, 57U);
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 53U) + RotL64(aOrbiterA, 57U)) + aOrbiterC) + aNonceWordM);
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 5U) + RotL64(aOrbiterJ, 21U)) + aOrbiterD) + aNonceWordF) + aPhaseBWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterD, 37U)) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterJ, 12U)) + aOrbiterC) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 38U) + aOrbiterA) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 24U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordJ);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 18659U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 16703U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18086U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20918U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aIngress, 22U)) + (RotL64(aPrevious, 43U) ^ RotL64(aCarry, 5U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterA = (((aWandererK + RotL64(aCross, 47U)) + RotL64(aCarry, 53U)) + 4751694786009671052U) + aNonceWordK;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 38U)) + RotL64(aCarry, 35U)) + 16362725160370844224U;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 19U)) + 6360885380915941057U) + aPhaseBOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = ((((aWandererI + RotL64(aScatter, 29U)) + RotL64(aCarry, 13U)) + 5154536007972297036U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterB = ((aWandererH + RotL64(aCross, 11U)) + 9362540581874808253U) + aNonceWordC;
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 13902493871525612934U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 10208452885367546542U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12067703239567933105U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 3117030377279160998U) + aNonceWordL;
            aOrbiterA = (((aOrbiterA ^ aOrbiterC) ^ 17286247690414027870U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterA = RotL64((aOrbiterA * 4896931759653832095U), 41U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterF) + 3930314320040949141U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordH;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 7289525252391668404U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15452162299105112187U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 3434167955466809185U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 17852573095128575663U;
            aOrbiterI = RotL64((aOrbiterI * 1485660158767033425U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 6137259687928853253U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 13992510605237574698U;
            aOrbiterB = RotL64((aOrbiterB * 15346263295995333395U), 5U);
            //
            aIngress = RotL64(aOrbiterB, 23U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + RotL64(aOrbiterA, 52U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 29U) + aOrbiterA) + RotL64(aOrbiterB, 21U)) + RotL64(aCarry, 19U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 13U) + aOrbiterC) + RotL64(aOrbiterA, 3U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 5U) + aOrbiterF) + RotL64(aOrbiterC, 12U)) + RotL64(aCarry, 47U)) + aNonceWordF);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterF, 29U)) + aOrbiterI) + aNonceWordM);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 50U) + aOrbiterI) + RotL64(aOrbiterA, 41U)) + aNonceWordN) + aPhaseBWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererI, 44U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 23640U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26617U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26109U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((aIndex + 22382U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 37U) + RotL64(aPrevious, 18U)) ^ (RotL64(aCarry, 51U) ^ RotL64(aIngress, 3U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterC = ((aWandererE + RotL64(aCross, 5U)) + 15316464782468770057U) + aNonceWordA;
            aOrbiterE = (aWandererK + RotL64(aPrevious, 57U)) + 6642872057476351588U;
            aOrbiterD = (((aWandererH + RotL64(aIngress, 18U)) + RotL64(aCarry, 53U)) + 660732654689529192U) + aPhaseBOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = (((aWandererC + RotL64(aScatter, 47U)) + RotL64(aCarry, 19U)) + 7235418086884000655U) + aPhaseBOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aCross, 37U)) + RotL64(aCarry, 35U)) + 14784518476694580493U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 12222433977933449375U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 8573001207708329927U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17771120145431297541U), 43U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterH) + 16035256260815013172U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordB;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 15767726974121910203U;
            aOrbiterA = RotL64((aOrbiterA * 719060452537759331U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 17712217935322939971U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterH) ^ 13488963456923357159U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 16785285630840310405U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 10222949131965611079U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 1495561412321657209U;
            aOrbiterE = RotL64((aOrbiterE * 9706305581868526265U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 16156530750584361434U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 7773792489045606309U) ^ aNonceWordO;
            aOrbiterH = RotL64((aOrbiterH * 10730624207715601393U), 29U);
            //
            aIngress = RotL64(aOrbiterD, 19U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + RotL64(aOrbiterC, 58U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aScatter, 28U) + aOrbiterA) + RotL64(aOrbiterD, 51U)) + aNonceWordE);
            aWandererI = aWandererI + (((RotL64(aCross, 43U) + aOrbiterH) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterE, 23U)) + aNonceWordJ) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererK = aWandererK + (((((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterE, 60U)) + RotL64(aCarry, 5U)) + aNonceWordK) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 51U) + aOrbiterH) + RotL64(aOrbiterC, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + RotL64(aWandererK, 48U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 30034U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneB[((aIndex + 27454U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30551U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((aIndex + 30200U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 29U) + RotL64(aCarry, 47U)) ^ (RotL64(aIngress, 60U) ^ RotL64(aCross, 11U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterD = ((((aWandererB + RotL64(aScatter, 19U)) + RotL64(aCarry, 43U)) + 7075016829833562104U) + aPhaseBOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1]) + aNonceWordM;
            aOrbiterE = ((aWandererG + RotL64(aCross, 42U)) + RotL64(aCarry, 29U)) + 8783765886115517036U;
            aOrbiterK = (aWandererD + RotL64(aIngress, 53U)) + 2996723892384565829U;
            aOrbiterC = (((aWandererK + RotL64(aPrevious, 11U)) + RotL64(aCarry, 13U)) + 9494134707342189476U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = (aWandererH + RotL64(aScatter, 29U)) + 5052642981395679904U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 8766787055127962238U) + aNonceWordH;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 4467211954388738079U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8599295330343804047U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 8030255604633658608U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 16962408063455702251U) ^ aNonceWordJ;
            aOrbiterE = RotL64((aOrbiterE * 11171737929747471631U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 3768222186567699076U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 14930990410207899871U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10930005786146268241U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 14179761938395502502U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 1879084742719898108U;
            aOrbiterC = RotL64((aOrbiterC * 16783034788172670121U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 5535012408925981515U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 12792553516710295939U;
            aOrbiterG = RotL64((aOrbiterG * 8577530993755159329U), 53U);
            //
            aIngress = RotL64(aOrbiterG, 13U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aIngress, 39U) + RotL64(aOrbiterC, 13U)) + aOrbiterE) + aNonceWordN) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 57U) + aOrbiterK) + RotL64(aOrbiterD, 37U)) + aNonceWordF);
            aWandererH = aWandererH + (((RotL64(aScatter, 24U) + aOrbiterG) + RotL64(aOrbiterE, 27U)) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 3U) + aOrbiterE) + RotL64(aOrbiterD, 52U));
            aWandererD = aWandererD + (((((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 3U)) + aOrbiterD) + RotL64(aCarry, 23U)) + aNonceWordP) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + (RotL64(aWandererK, 40U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererG, 11U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ aNonceWordN;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xE98DE1322F9F005DULL + 0xAF4F3C2ACB8B11E3ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xFC84806ED9400271ULL + 0xDA783978660471DCULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xD96D2F51F8715389ULL + 0xEB60604666D98FFBULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x86F9D1F2822B589BULL + 0xF3934FC81BB7BCB0ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x9471CB2D7120AC93ULL + 0x89CEE82E3731D9E5ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xA7539D8985ED0359ULL + 0xCB24D50FAE7DADF0ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xFB0C798ABBA0375DULL + 0xCCAAECEAD7C5E77BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xD3769B460AA1F381ULL + 0xE089AC78FCD305F0ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xE731C18EB4901E35ULL + 0xC7AC95A6DA6CC41FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x9FD18081166C8C0BULL + 0xB54A90E6EB285D37ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xD82E44C98D5EC179ULL + 0x94D00951C03A7425ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xFD8F2294F4986287ULL + 0xCC332D7556F67BAFULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xEE9741F3D809155BULL + 0xBABBC59CD937BAC8ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xA84182F69F0C7569ULL + 0xE89AF7AE49459AA5ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xAAEE940741A23A7BULL + 0xD021CA54F94360FFULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xB0BF868A078EC525ULL + 0x8A515BECF1E0AA2CULL);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 6780U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 1473U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 3150U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((aIndex + 4540U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 20U) ^ RotL64(aCarry, 53U)) + (RotL64(aCross, 37U) ^ RotL64(aIngress, 3U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 53U)) + 18191288703716505885U;
            aOrbiterI = (aWandererG + RotL64(aCross, 57U)) + 9824014524910417136U;
            aOrbiterG = ((aWandererB + RotL64(aScatter, 23U)) + 11953012029254917548U) + aNonceWordF;
            aOrbiterH = ((aWandererK + RotL64(aIngress, 48U)) + RotL64(aCarry, 29U)) + 6297568011027199089U;
            aOrbiterE = (((aWandererC + RotL64(aPrevious, 3U)) + RotL64(aCarry, 51U)) + 2576999400457367975U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = (aWandererA + RotL64(aIngress, 41U)) + 13176139160575558254U;
            aOrbiterF = (aWandererF + RotL64(aScatter, 29U)) + 9978408174563621810U;
            aOrbiterD = (((aWandererE + RotL64(aCross, 19U)) + RotL64(aCarry, 39U)) + 16765834875061607142U) + aPhaseCOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aIngress, 10U)) + 16534507305459121344U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 3114710944346151807U) + aNonceWordG;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 10240517868726718592U;
            aOrbiterG = RotL64((aOrbiterG * 4645691562915606463U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 10721450637990777883U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 16689590768796583952U;
            aOrbiterB = RotL64((aOrbiterB * 3046344179729901637U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 2427422768928450209U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 13495584061816457831U;
            aOrbiterD = RotL64((aOrbiterD * 6670984773768885119U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 7058636403765106682U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 9897341853944713767U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14286816859999869231U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 17749559755733386064U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 12515645083926326659U;
            aOrbiterJ = RotL64((aOrbiterJ * 6582878478865838245U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 2625692458813609962U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 10596240255026143019U;
            aOrbiterH = RotL64((aOrbiterH * 11605800195771080135U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 12374290338067865540U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 1507386663796330249U;
            aOrbiterF = RotL64((aOrbiterF * 1210241080424446087U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 9288099549484146726U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 15159312464747000702U;
            aOrbiterI = RotL64((aOrbiterI * 500055502081347757U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 14998608679505446229U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 17625038109437732009U;
            aOrbiterE = RotL64((aOrbiterE * 14785862243019841689U), 47U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterI, 37U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterB, 26U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterD, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aPrevious, 52U) + aOrbiterJ) + RotL64(aOrbiterB, 6U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterG, 35U)) + aOrbiterE) + aPhaseCWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 5U) + aOrbiterE) + RotL64(aOrbiterK, 43U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterK, 53U)) + aOrbiterJ);
            aWandererD = aWandererD + (((RotL64(aPrevious, 37U) + aOrbiterJ) + RotL64(aOrbiterF, 29U)) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterI, 39U)) + aNonceWordP) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterJ, 11U)) + RotL64(aCarry, 35U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 46U) + aOrbiterJ) + RotL64(aOrbiterD, 57U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterH, 48U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererH, 44U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererB, 21U);
            aCarry = aCarry + RotL64(aIngress, 26U);
            aCarry = aCarry ^ aNonceWordD;
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10377U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 8975U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 8883U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 15890U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 47U) + RotL64(aCarry, 35U)) ^ (RotL64(aIngress, 60U) + RotL64(aCross, 21U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterG = ((aWandererI + RotL64(aIngress, 11U)) + 9080426856729228705U) + aNonceWordO;
            aOrbiterB = (aWandererK + RotL64(aPrevious, 4U)) + 7851218321653539276U;
            aOrbiterK = ((aWandererG + RotL64(aCross, 57U)) + RotL64(aCarry, 21U)) + 7023344692919298036U;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 29U)) + 9772846154227440734U;
            aOrbiterD = (aWandererD + RotL64(aIngress, 43U)) + 12008298632429608431U;
            aOrbiterH = (((aWandererJ + RotL64(aCross, 23U)) + 12201090455849562875U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordF;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 37U)) + RotL64(aCarry, 41U)) + 9498721803411445471U;
            aOrbiterC = (((aWandererA + RotL64(aPrevious, 19U)) + RotL64(aCarry, 13U)) + 351203764023093632U) + aPhaseCOrbiterAssignSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aCross, 52U)) + 4966360430644539250U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 9194167899071345693U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 4922477697284269116U;
            aOrbiterK = RotL64((aOrbiterK * 8444814161720407881U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 15742625291642356429U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 7528703106518431730U) ^ aNonceWordI;
            aOrbiterD = RotL64((aOrbiterD * 11530049278751507567U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 15279053574704935317U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 2425839793660355555U;
            aOrbiterE = RotL64((aOrbiterE * 11486964816849830667U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 13209849392400008898U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 9041500097716231309U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 340661035700748739U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 7885423750878814599U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 1992993999902904603U;
            aOrbiterF = RotL64((aOrbiterF * 1478629826632201617U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 6120758615019314102U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 8529621625846992066U;
            aOrbiterG = RotL64((aOrbiterG * 8485991471612862467U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 9125182130757385320U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 15691232622970220043U;
            aOrbiterJ = RotL64((aOrbiterJ * 16517916951054758147U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 11413090085435424697U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 11563151001080914939U;
            aOrbiterH = RotL64((aOrbiterH * 16828196274450408201U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 1778975369262558069U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 3232132443557192010U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17132823737792200981U), 53U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterD, 51U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterK, 41U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterG, 60U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 23U) + RotL64(aOrbiterH, 4U)) + aOrbiterK) + aNonceWordG) + aPhaseCWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aCross, 18U) + RotL64(aOrbiterJ, 57U)) + aOrbiterD) + RotL64(aCarry, 57U)) + aPhaseCWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterB, 35U)) + aOrbiterD) + aNonceWordD);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterC, 27U)) + aOrbiterG);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 47U)) + aOrbiterD);
            aWandererI = aWandererI + (((RotL64(aScatter, 47U) + aOrbiterF) + RotL64(aOrbiterH, 39U)) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 58U) + aOrbiterB) + RotL64(aOrbiterF, 53U)) + aNonceWordH);
            aWandererB = aWandererB + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 12U)) + aOrbiterE);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterJ, 23U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 60U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordL);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 20407U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20388U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20158U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 23876U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 43U) + RotL64(aIngress, 57U)) ^ (RotL64(aCarry, 10U) + RotL64(aPrevious, 29U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterF = (((aWandererB + RotL64(aScatter, 19U)) + RotL64(aCarry, 29U)) + 1042610313571524121U) + aNonceWordM;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 37U)) + 3505725321008825582U) + aNonceWordC;
            aOrbiterB = (aWandererJ + RotL64(aIngress, 48U)) + 12584654563843782991U;
            aOrbiterD = (aWandererA + RotL64(aCross, 27U)) + 6645399144515770935U;
            aOrbiterG = ((aWandererE + RotL64(aIngress, 11U)) + 3608978423753715584U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = (aWandererK + RotL64(aScatter, 41U)) + 8089198857670370983U;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 53U)) + RotL64(aCarry, 37U)) + 15207251813516399879U;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 57U)) + RotL64(aCarry, 5U)) + 9579268660105824516U;
            aOrbiterH = ((aWandererC + RotL64(aIngress, 4U)) + 16055044469473802812U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 583811872609805949U) + aNonceWordB;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 7027491967970873942U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12686754713465826139U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 18256061823189677508U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 12708429127816136937U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12593886633108075321U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 12169216645156306078U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 12694325407567795065U;
            aOrbiterD = RotL64((aOrbiterD * 3711789483877261899U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 16109994660203297503U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 4234704064165718913U;
            aOrbiterE = RotL64((aOrbiterE * 730085881474787681U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 14119541943554602878U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 8777769004811352951U;
            aOrbiterG = RotL64((aOrbiterG * 2556957257736134223U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 15642663488392549609U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 11594468530833278624U;
            aOrbiterK = RotL64((aOrbiterK * 6639306656361601143U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 7365350535791499871U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 5965170981970155956U;
            aOrbiterJ = RotL64((aOrbiterJ * 1898702752753066851U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 9115232101451815522U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 9433983580038990072U;
            aOrbiterI = RotL64((aOrbiterI * 1951249217843992179U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 8810565477444156140U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterB) ^ 12081286530401844859U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterH = RotL64((aOrbiterH * 1991383259486140229U), 3U);
            //
            aIngress = RotL64(aOrbiterH, 57U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterE, 51U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 60U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 35U) + aOrbiterJ) + RotL64(aOrbiterI, 52U));
            aWandererF = aWandererF + ((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 29U)) + aOrbiterE);
            aWandererC = aWandererC ^ (((RotL64(aCross, 39U) + aOrbiterB) + RotL64(aOrbiterF, 43U)) + aNonceWordD);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 14U) + aOrbiterE) + RotL64(aOrbiterK, 11U)) + RotL64(aCarry, 39U)) + aPhaseCWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterG, 19U)) + aOrbiterI) + aPhaseCWandererUpdateSaltD[((aIndex + 4U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 4U)) + aOrbiterK) + RotL64(aCarry, 21U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterE, 47U));
            aWandererG = aWandererG + ((RotL64(aCross, 24U) + aOrbiterJ) + RotL64(aOrbiterH, 57U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterD, 39U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 46U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererE, 43U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordM;
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 26743U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((aIndex + 26882U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31716U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 25427U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aIngress, 41U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCross, 58U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterH = (aWandererF + RotL64(aCross, 58U)) + 10812151398716051703U;
            aOrbiterF = (((aWandererB + RotL64(aScatter, 35U)) + RotL64(aCarry, 53U)) + 18202551453336003710U) + aPhaseCOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 43U)) + 9434410809101973752U) + aNonceWordE;
            aOrbiterB = (((aWandererD + RotL64(aIngress, 19U)) + RotL64(aCarry, 19U)) + 12955829998028534045U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 47U)) + 12271740641929640181U) + aNonceWordD;
            aOrbiterG = (aWandererK + RotL64(aCross, 39U)) + 14009351527014534752U;
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 14U)) + RotL64(aCarry, 27U)) + 4316296955679133450U;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 53U)) + 16473324966997442872U) + aNonceWordK;
            aOrbiterI = (aWandererC + RotL64(aCross, 29U)) + 15735123324965019802U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 17656375090484080236U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 16066325053456055298U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17912970706985130327U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 12908968778503516903U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 12761433987676836197U;
            aOrbiterJ = RotL64((aOrbiterJ * 1023329467480907925U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 12737513138040664509U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 14535795767570998392U;
            aOrbiterK = RotL64((aOrbiterK * 15560519667062222269U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 14370908061811284364U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 7001358781208669795U;
            aOrbiterH = RotL64((aOrbiterH * 11641248025734015835U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 7298578161120090849U) + aNonceWordJ;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 10498302152357484629U;
            aOrbiterB = RotL64((aOrbiterB * 13144110412179037175U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 11447343228638006767U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 18284143620422655675U;
            aOrbiterG = RotL64((aOrbiterG * 572862190073605651U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 5918253208127360199U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 3910541329178205943U;
            aOrbiterA = RotL64((aOrbiterA * 4550654545328228103U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 10357053096941367910U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 5610891501128498748U;
            aOrbiterI = RotL64((aOrbiterI * 8676370811772047449U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 9049881176058575811U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 6307599924966452216U;
            aOrbiterF = RotL64((aOrbiterF * 5551444450572055895U), 47U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterJ, 35U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 6U));
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 21U) + aOrbiterE) + RotL64(aOrbiterH, 48U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterE, 27U)) + RotL64(aCarry, 51U)) + aNonceWordH);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterK, 5U)) + aOrbiterI);
            aWandererH = aWandererH + (((RotL64(aCross, 41U) + aOrbiterE) + RotL64(aOrbiterA, 53U)) + aPhaseCWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 10U) + aOrbiterF) + RotL64(aOrbiterI, 57U)) + aNonceWordA);
            aWandererG = aWandererG + ((RotL64(aIngress, 35U) + aOrbiterJ) + RotL64(aOrbiterE, 13U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 51U) + aOrbiterB) + RotL64(aOrbiterG, 35U));
            aWandererD = aWandererD + ((((RotL64(aCross, 47U) + RotL64(aOrbiterH, 23U)) + aOrbiterK) + RotL64(aCarry, 37U)) + aNonceWordG);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 14U) + aOrbiterG) + RotL64(aOrbiterH, 42U)) + aPhaseCWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 46U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererC, 57U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ aNonceWordI;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xB8F4D10BE535EB4DULL + 0xA7D8E1016D18B7AEULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x839A15D2DB57BC1BULL + 0xDA91742CBBACE651ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC45C5335563882A5ULL + 0x8C662E08205F49DDULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x8085F33BF6B8FC1BULL + 0xE7CC260ACDD2C76CULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xD5330B32911B8F25ULL + 0xB18D5D24363B1B56ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xD39965F76CB5F485ULL + 0x8AD0CD608AB5BC76ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x881CE7B8D2C81FFBULL + 0xEC5E42A1324F0C66ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x87265B0BBFB348A7ULL + 0xDC97E7ACA69066B7ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xCA03614AB4BB5693ULL + 0x82A57310851572A8ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xFE344938402136B9ULL + 0x82A126F6897B9967ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xECBB1AC274557A6DULL + 0xE8DEC64DB79C3B0DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xD18F64A816FC98D5ULL + 0xD629BA9EE5E86B95ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xECC6C620C2B6D781ULL + 0x9975C43824D93670ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xF8B675E4CE58171DULL + 0x93F986E4DF425DF5ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xA4FA7A848D2D74FFULL + 0x9A7229ABADB3F99BULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x9CC44C2DB530F3E1ULL + 0xFA812273EB10B21DULL);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1505U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneC[((aIndex + 380U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3788U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneA[((aIndex + 2642U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 21U)) ^ (RotL64(aCross, 57U) + RotL64(aIngress, 34U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterH = (aWandererA + RotL64(aCross, 41U)) + 5131645209694953015U;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 11U)) + RotL64(aCarry, 13U)) + 12070391048835379854U;
            aOrbiterB = (aWandererJ + RotL64(aIngress, 35U)) + 2604295836242338724U;
            aOrbiterE = (aWandererH + RotL64(aPrevious, 30U)) + 14042039029284001596U;
            aOrbiterI = (aWandererF + RotL64(aCross, 21U)) + 8914654543854559327U;
            aOrbiterJ = ((((aWandererB + RotL64(aIngress, 37U)) + RotL64(aCarry, 35U)) + 2185619407969359869U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordA;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 5U)) + 5187406295103352574U) + aPhaseDOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = (aWandererC + RotL64(aPrevious, 39U)) + 8022832481290871217U;
            aOrbiterD = (aWandererE + RotL64(aIngress, 47U)) + 8783061916740573472U;
            aOrbiterF = (aWandererI + RotL64(aPrevious, 44U)) + 10711028365596196301U;
            aOrbiterK = ((aWandererG + RotL64(aCross, 57U)) + RotL64(aCarry, 23U)) + 13387065038269133571U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 11187001318931801582U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 14191473173276034019U;
            aOrbiterB = RotL64((aOrbiterB * 2491253922434756431U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 16207761776716426435U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 9677408414452078760U;
            aOrbiterJ = RotL64((aOrbiterJ * 5487303383095129949U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 17812460332794370649U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 7736423148554132028U;
            aOrbiterH = RotL64((aOrbiterH * 15588733747232852555U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 17293203944059014763U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 13487243633338010243U) ^ aNonceWordD;
            aOrbiterE = RotL64((aOrbiterE * 9468688858740539095U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 15979293016815060755U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 17645215484691359547U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1449450767288733995U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 11635961468586927692U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 10530136578329059784U;
            aOrbiterD = RotL64((aOrbiterD * 8785021493374398437U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 4900370530116992731U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 15952900504821599445U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5413316082800365261U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 9938000151832814778U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 14170277411106520726U;
            aOrbiterA = RotL64((aOrbiterA * 5058343552974910737U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 14091010427448547620U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 13658560822164111421U;
            aOrbiterI = RotL64((aOrbiterI * 9523184040517290629U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 13954269172267844623U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 3921811946419945868U;
            aOrbiterG = RotL64((aOrbiterG * 6839440867046147039U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 14296483810577739898U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 5131645209694953015U;
            aOrbiterF = RotL64((aOrbiterF * 10190969526209064367U), 39U);
            //
            aIngress = RotL64(aOrbiterE, 5U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterA, 39U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 46U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterE, 51U)) + aOrbiterC) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 60U) + aOrbiterE) + RotL64(aOrbiterI, 39U));
            aWandererK = aWandererK + ((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 13U)) + aOrbiterD);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 51U) + aOrbiterJ) + RotL64(aOrbiterK, 23U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterI, 43U)) + aOrbiterH);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterH, 48U));
            aWandererH = aWandererH + ((((RotL64(aCross, 53U) + RotL64(aOrbiterC, 5U)) + aOrbiterA) + RotL64(aCarry, 53U)) + aPhaseDWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 18U) + RotL64(aOrbiterF, 35U)) + aOrbiterC);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterK, 57U)) + aNonceWordJ);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterB, 10U)) + aOrbiterJ) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 23U) + aOrbiterF) + RotL64(aOrbiterI, 19U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 60U));
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererE, 41U);
            aCarry = aCarry + RotL64(aIngress, 22U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 10593U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9025U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10863U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((aIndex + 7516U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 43U) + RotL64(aCross, 11U)) ^ (RotL64(aCarry, 23U) + RotL64(aIngress, 56U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 29U)) + RotL64(aCarry, 27U)) + 2571116506511057880U;
            aOrbiterK = ((aWandererH + RotL64(aCross, 44U)) + RotL64(aCarry, 43U)) + 13112435411509707292U;
            aOrbiterG = (aWandererJ + RotL64(aIngress, 37U)) + 10403251762787357256U;
            aOrbiterF = (aWandererB + RotL64(aScatter, 41U)) + 8461951095541400405U;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 47U)) + 9890793478557463815U) + aNonceWordG;
            aOrbiterC = (aWandererC + RotL64(aCross, 27U)) + 3030229465991783707U;
            aOrbiterH = (aWandererE + RotL64(aScatter, 60U)) + 7273848154043719247U;
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 57U)) + 10681774862516028276U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aScatter, 13U)) + RotL64(aCarry, 5U)) + 7105082755586853104U;
            aOrbiterI = (aWandererI + RotL64(aCross, 3U)) + 6588579345319551129U;
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 53U)) + 14616333550242386092U) + aPhaseDOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 15439666290229654921U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 3360304356760164799U;
            aOrbiterG = RotL64((aOrbiterG * 5164191920584106237U), 23U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterD) + 14438730801970761889U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordI;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 14515616787452085729U;
            aOrbiterK = RotL64((aOrbiterK * 2041601927968559821U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 4167853822635132419U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 8950982233003320239U;
            aOrbiterD = RotL64((aOrbiterD * 887144270884244907U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 12391327853728029953U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 7100871010552394421U) ^ aNonceWordC;
            aOrbiterH = RotL64((aOrbiterH * 16552349374101955967U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 15381697462381887944U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 6801677551341079401U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13325954438427340703U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 947011315719204867U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 6356920162398333481U;
            aOrbiterA = RotL64((aOrbiterA * 5566721941682667419U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 8910262020598577378U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 8778455415977526457U;
            aOrbiterF = RotL64((aOrbiterF * 4092470497616637283U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 5585696961453127223U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 9670655481681494412U;
            aOrbiterC = RotL64((aOrbiterC * 7863197168965036383U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 10713004007087085729U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 4036355047492922339U;
            aOrbiterB = RotL64((aOrbiterB * 6923922258047667173U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 14580156873863533497U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 7049502932205025182U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8665428649262370727U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 12707521269341941677U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 2571116506511057880U;
            aOrbiterJ = RotL64((aOrbiterJ * 2388236789245943699U), 43U);
            //
            aIngress = RotL64(aOrbiterC, 21U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 34U));
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 39U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + RotL64(aOrbiterE, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aIngress, 41U) + RotL64(aOrbiterG, 37U)) + aOrbiterE) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterE, 13U)) + aOrbiterH) + aPhaseDWandererUpdateSaltA[((aIndex + 10U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 34U)) + aOrbiterB);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterK, 27U)) + aOrbiterI) + aNonceWordJ);
            aWandererF = aWandererF + ((RotL64(aIngress, 20U) + RotL64(aOrbiterB, 29U)) + aOrbiterF);
            aWandererG = aWandererG ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterD, 47U)) + aOrbiterC) + aPhaseDWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 11U) + aOrbiterG) + RotL64(aOrbiterJ, 19U)) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterH, 6U)) + aOrbiterI);
            aWandererH = aWandererH + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterA, 43U)) + aOrbiterJ);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 47U) + aOrbiterH) + RotL64(aOrbiterB, 11U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 18U) + aOrbiterK) + RotL64(aOrbiterC, 3U)) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 38U));
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererI, 29U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordJ);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 11978U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((aIndex + 14164U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13806U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 16375U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 56U) ^ RotL64(aIngress, 23U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCarry, 11U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 41U)) + RotL64(aCarry, 35U)) + 7948891781097675369U;
            aOrbiterI = (aWandererE + RotL64(aCross, 37U)) + 13928362874228230226U;
            aOrbiterH = ((aWandererF + RotL64(aIngress, 44U)) + 10776180542602258926U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aScatter, 27U)) + 5735115172149470447U;
            aOrbiterD = ((aWandererC + RotL64(aCross, 51U)) + 5353591822981766987U) + aNonceWordJ;
            aOrbiterB = (((aWandererA + RotL64(aIngress, 13U)) + 562301708107268570U) + aPhaseDOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1]) + aNonceWordC;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 11U)) + RotL64(aCarry, 43U)) + 10467810247578364868U;
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 18U)) + 14541630141152308564U;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 3U)) + 2350076897065139429U;
            aOrbiterE = ((aWandererG + RotL64(aCross, 35U)) + RotL64(aCarry, 11U)) + 17519109078651162228U;
            aOrbiterK = (aWandererH + RotL64(aPrevious, 47U)) + 6061035173339902910U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 15654836633731000065U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 13723521735153718904U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14459516479283070563U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 2849680038315532197U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 17336102435576647923U;
            aOrbiterB = RotL64((aOrbiterB * 10984689101753586739U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 7671010488872356142U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 11485114338165600777U;
            aOrbiterI = RotL64((aOrbiterI * 4162584865462407791U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 8759060657343458985U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 11009137869375286581U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8741417343929809115U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 15792999392743144135U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 6180808423175992479U;
            aOrbiterJ = RotL64((aOrbiterJ * 13681230339693676907U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 361487389591183005U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 15292753806514404853U;
            aOrbiterE = RotL64((aOrbiterE * 17478232597253311153U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 14929153438443362045U) + aNonceWordK;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 7904556383593914086U;
            aOrbiterA = RotL64((aOrbiterA * 2484130486635511403U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 3793180909904286848U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 10391957637467171320U;
            aOrbiterF = RotL64((aOrbiterF * 505484041943467117U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 11648765065563798353U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 17601185776537566611U;
            aOrbiterC = RotL64((aOrbiterC * 4753179291885740011U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 2907499704986356444U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 17048858067202291241U;
            aOrbiterG = RotL64((aOrbiterG * 2607549567999666889U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 4340465159886930775U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 7948891781097675369U;
            aOrbiterK = RotL64((aOrbiterK * 12913104720552907335U), 3U);
            //
            aIngress = RotL64(aOrbiterE, 34U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aPrevious, 51U) + aOrbiterK) + RotL64(aOrbiterG, 3U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 21U) + aOrbiterE) + RotL64(aOrbiterA, 5U));
            aWandererG = aWandererG + ((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 53U)) + aOrbiterE);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 11U) + aOrbiterE) + RotL64(aOrbiterC, 47U)) + aPhaseDWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 24U) + aOrbiterG) + RotL64(aOrbiterI, 30U)) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterF, 37U)) + aOrbiterH) + aNonceWordB);
            aWandererH = aWandererH + ((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 41U)) + aOrbiterJ);
            aWandererF = aWandererF ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterE, 43U)) + aOrbiterG);
            aWandererB = aWandererB + ((RotL64(aPrevious, 40U) + aOrbiterI) + RotL64(aOrbiterB, 28U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 19U) + aOrbiterD) + RotL64(aOrbiterG, 39U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 37U) + RotL64(aOrbiterD, 57U)) + aOrbiterH) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 56U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 48U));
            aCarry = aCarry + RotL64(aWandererK, 21U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordJ);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 16593U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 17994U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 20456U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20991U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 26U)) + (RotL64(aCross, 3U) ^ RotL64(aIngress, 53U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterG = ((aWandererC + RotL64(aIngress, 53U)) + 4773124477323378268U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = ((aWandererD + RotL64(aCross, 12U)) + 16848723289435796005U) + aPhaseDOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = (((aWandererJ + RotL64(aPrevious, 29U)) + RotL64(aCarry, 47U)) + 13846642134917107058U) + aNonceWordE;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 5U)) + RotL64(aCarry, 11U)) + 6472057872482789939U;
            aOrbiterH = (aWandererK + RotL64(aIngress, 47U)) + 2747019500690707226U;
            aOrbiterC = (aWandererB + RotL64(aCross, 37U)) + 9003965289739733880U;
            aOrbiterD = (aWandererF + RotL64(aPrevious, 57U)) + 3013390651936257377U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 35U)) + 3331004709895625067U) + aNonceWordL;
            aOrbiterK = ((aWandererH + RotL64(aCross, 51U)) + 15355010435553517129U) + aNonceWordH;
            aOrbiterB = (aWandererA + RotL64(aScatter, 44U)) + 7709870658004280052U;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 3U)) + RotL64(aCarry, 29U)) + 13568728443963926564U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 12409548853419307131U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 969183352023661537U;
            aOrbiterI = RotL64((aOrbiterI * 5549220554838837145U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 15370309834426476775U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 3896803894396631184U;
            aOrbiterH = RotL64((aOrbiterH * 11018830202891911603U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 10848873633291935766U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 12885336509190543440U;
            aOrbiterC = RotL64((aOrbiterC * 1487357252619221365U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 8252290890093788010U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 9201553615601641350U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 420321130559162915U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 14014209645503188472U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 4015071464301844550U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17444195018239904971U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 16173085647514027347U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 16916627014974363360U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7699587344277490953U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 1591680303404522110U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 16499606051269327916U;
            aOrbiterB = RotL64((aOrbiterB * 814405848002794813U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 6932673635509444619U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 8745681160108707944U;
            aOrbiterJ = RotL64((aOrbiterJ * 14565255558668084787U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 10387263947888920455U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 2553335462317280031U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7253573275397985211U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 17449861295444216249U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 15716408844914738774U) ^ aNonceWordA;
            aOrbiterE = RotL64((aOrbiterE * 10132631423215542589U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 16974370193820578179U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 4773124477323378268U;
            aOrbiterF = RotL64((aOrbiterF * 8982190762960590543U), 43U);
            //
            aIngress = RotL64(aOrbiterI, 5U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + (RotL64(aOrbiterE, 51U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 54U));
            aIngress = aIngress + RotL64(aOrbiterA, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aIngress, 11U) + aOrbiterF) + RotL64(aOrbiterI, 19U)) + aPhaseDWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 35U)) + aOrbiterG);
            aWandererA = aWandererA ^ (((RotL64(aCross, 5U) + aOrbiterH) + RotL64(aOrbiterB, 23U)) + aPhaseDWandererUpdateSaltE[((aIndex + 10U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterF, 29U)) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 21U)) + aOrbiterG) + aNonceWordF);
            aWandererD = aWandererD + (((RotL64(aScatter, 44U) + RotL64(aOrbiterK, 58U)) + aOrbiterH) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterD, 39U)) + aOrbiterF);
            aWandererH = aWandererH + ((RotL64(aCross, 37U) + aOrbiterK) + RotL64(aOrbiterI, 11U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterD, 13U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 21U) + aOrbiterD) + RotL64(aOrbiterE, 44U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterE, 41U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererE, 44U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 26U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordL);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 22554U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((aIndex + 24441U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 24985U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23711U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 41U) + RotL64(aPrevious, 54U)) ^ (RotL64(aIngress, 3U) ^ RotL64(aCross, 23U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterC = (aWandererF + RotL64(aIngress, 21U)) + 8020711767807230555U;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 43U)) + 15368693777246341570U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aCross, 57U)) + 5117523734225562401U;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 11U)) + 13155269151097507808U) + aPhaseDOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aCross, 51U)) + 9879303753623578272U) + aNonceWordK;
            aOrbiterI = (aWandererB + RotL64(aScatter, 27U)) + 1165799257173794826U;
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 14U)) + RotL64(aCarry, 19U)) + 930641942062732091U;
            aOrbiterK = ((aWandererI + RotL64(aIngress, 41U)) + RotL64(aCarry, 5U)) + 11330571332221123153U;
            aOrbiterE = (aWandererG + RotL64(aScatter, 5U)) + 2862963158282518899U;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 23U)) + 6019186399361476659U) + aNonceWordD;
            aOrbiterF = (((aWandererA + RotL64(aCross, 60U)) + RotL64(aCarry, 13U)) + 1924419843785161958U) + aNonceWordI;
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 12618629043591380461U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 9334176504266512405U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 18239109235362925739U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 16829692481030013551U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 5604784396927022709U;
            aOrbiterI = RotL64((aOrbiterI * 2833893610883508353U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 16124030106598549644U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 16571659812830230677U;
            aOrbiterK = RotL64((aOrbiterK * 4668250364992383549U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 15171089673591843703U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 2826755560293849328U;
            aOrbiterB = RotL64((aOrbiterB * 9397017963457655287U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 9976785768283589291U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 11845100564714691809U;
            aOrbiterC = RotL64((aOrbiterC * 4935139932585319251U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 7318560453127859950U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 3039196878830506712U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3140508261330698717U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 8850992055588337843U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 4219373528176869146U;
            aOrbiterJ = RotL64((aOrbiterJ * 1310964742529956743U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 1341474458715938799U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 15937557372891732898U;
            aOrbiterE = RotL64((aOrbiterE * 11437307017920192915U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 7512741986101399499U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 4304636545688233645U) ^ aNonceWordJ;
            aOrbiterF = RotL64((aOrbiterF * 1948671766238131953U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 11460886069492094055U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 2019818350627642126U;
            aOrbiterH = RotL64((aOrbiterH * 9802784763505584769U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 3190374588085859096U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 8020711767807230555U;
            aOrbiterD = RotL64((aOrbiterD * 12055760672321414929U), 27U);
            //
            aIngress = RotL64(aOrbiterK, 48U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aCross, 27U) + aOrbiterK) + RotL64(aOrbiterH, 29U)) + aPhaseDWandererUpdateSaltA[((aIndex + 20U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 51U) + RotL64(aOrbiterH, 19U)) + aOrbiterI) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterD, 39U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 48U) + aOrbiterE) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 13U) + aOrbiterE) + RotL64(aOrbiterI, 5U)) + aNonceWordH);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterC, 12U)) + aOrbiterB);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterK, 53U));
            aWandererE = aWandererE + ((RotL64(aScatter, 11U) + aOrbiterB) + RotL64(aOrbiterE, 27U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 6U) + RotL64(aOrbiterD, 41U)) + aOrbiterA);
            aWandererH = aWandererH + ((RotL64(aScatter, 3U) + RotL64(aOrbiterF, 57U)) + aOrbiterG);
            aWandererA = aWandererA ^ ((RotL64(aCross, 53U) + aOrbiterG) + RotL64(aOrbiterE, 14U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 48U));
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + RotL64(aWandererJ, 23U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordE);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 31612U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((aIndex + 32591U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31912U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28283U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 40U) ^ RotL64(aPrevious, 57U)) + (RotL64(aCross, 23U) + RotL64(aIngress, 11U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterH = (aWandererG + RotL64(aScatter, 24U)) + 16802219662864902427U;
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 35U)) + 14332033461409490629U;
            aOrbiterK = (aWandererB + RotL64(aCross, 13U)) + 8781794298640286845U;
            aOrbiterC = (aWandererI + RotL64(aIngress, 27U)) + 8459933908074937264U;
            aOrbiterB = ((aWandererE + RotL64(aCross, 37U)) + 1883580287986004426U) + aNonceWordC;
            aOrbiterI = (aWandererA + RotL64(aPrevious, 19U)) + 17500258188004626118U;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 43U)) + RotL64(aCarry, 39U)) + 7934811305150872870U;
            aOrbiterD = ((aWandererF + RotL64(aIngress, 39U)) + RotL64(aCarry, 27U)) + 6380363892361098905U;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 11U)) + 12623079132626676910U) + aPhaseDOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = ((aWandererH + RotL64(aCross, 51U)) + RotL64(aCarry, 5U)) + 10455208121949202703U;
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 54U)) + 8805532707916767629U) + aPhaseDOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 9161544391400377699U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 3501434325829663268U;
            aOrbiterK = RotL64((aOrbiterK * 7933545151293799637U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 651783304096081996U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 441505031509930622U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8045355432310956143U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 1771159983581326424U) + aNonceWordM;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 15227946417377695989U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1563141188972797601U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 4153717524193279095U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 4404521756523902829U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1410342912973206203U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 6231945075461813285U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 3864780227164426690U;
            aOrbiterD = RotL64((aOrbiterD * 18031353247480673617U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 1509699687948576558U) + aNonceWordG;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 17316114302489411191U;
            aOrbiterG = RotL64((aOrbiterG * 15490661284980281585U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 2250572827340157410U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 6403966113144372915U;
            aOrbiterF = RotL64((aOrbiterF * 726441947009132383U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 2329903609147403156U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 2486330017319455238U;
            aOrbiterE = RotL64((aOrbiterE * 17427461345935191757U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 9333421733051210144U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 14779925626161889533U;
            aOrbiterH = RotL64((aOrbiterH * 9120486933147706541U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 4343688173541745311U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 12686722305368397686U;
            aOrbiterJ = RotL64((aOrbiterJ * 17484250022537912537U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 3745163111502795473U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 16802219662864902427U;
            aOrbiterC = RotL64((aOrbiterC * 4343730534036919417U), 21U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 3U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 14U));
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 57U)) + aOrbiterK);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterD, 13U)) + aOrbiterG);
            aWandererG = aWandererG + ((((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterG, 19U)) + RotL64(aCarry, 13U)) + aNonceWordE);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterE, 44U)) + aOrbiterA) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 23U) + aOrbiterK) + RotL64(aOrbiterD, 41U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 30U) + aOrbiterC) + RotL64(aOrbiterF, 29U)) + aNonceWordH);
            aWandererA = aWandererA + (((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterJ, 35U)) + aPhaseDWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 37U) + aOrbiterH) + RotL64(aOrbiterB, 10U));
            aWandererD = aWandererD + ((RotL64(aCross, 43U) + aOrbiterB) + RotL64(aOrbiterJ, 27U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 41U) + aOrbiterH) + RotL64(aOrbiterA, 37U));
            aWandererB = aWandererB + (((RotL64(aScatter, 50U) + aOrbiterG) + RotL64(aOrbiterK, 5U)) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 44U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 38U));
            aCarry = aCarry + RotL64(aWandererJ, 27U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ aNonceWordN;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xE4B4CBDA338B9DC9ULL + 0xDAF5D5F859C366CBULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xC13C34E487DBC96FULL + 0x93009DFDA6027499ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x8C913FC7B2D8FC4DULL + 0x986760CCDAA2867EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xCB3B6876E4067921ULL + 0xBDBE644DADF74FA5ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xF452AA62BE4859D1ULL + 0xE6DFF8744C2ED4B2ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x96C22861FF136DC7ULL + 0xD2452BD6F3518136ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x9F8A37D919939863ULL + 0xFA0EBE69755ACB5AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xD6197D4C134ECBC1ULL + 0xE218E2FA20528845ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xF128BB071AF22453ULL + 0xFB1A5C20499696C0ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xB9A65EDC4E04E281ULL + 0xF8786E714ED59B97ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xF35A1AC32BFF9AF5ULL + 0xE08ABBAD42BEF7AEULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x8E360E40C088F13FULL + 0x82C54047BB2198C8ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x814A781D452AFF6BULL + 0xDEE360194263EFE9ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xBA318DB999C44BEBULL + 0xD45F3A27481249C7ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xE522A31831FA36E3ULL + 0xBA94BF988292B5F4ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xC29A4B8DFB5FA0B7ULL + 0x8D1F235D6B91B7AEULL);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 59U)) & S_BLOCK1], 26U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 4666U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 583U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 4462U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aPrevious, 41U)) + (RotL64(aCarry, 5U) ^ RotL64(aIngress, 54U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterK = (aWandererD + RotL64(aIngress, 26U)) + 12222235191147985484U;
            aOrbiterE = ((aWandererH + RotL64(aCross, 29U)) + 16367317014523328414U) + aNonceWordF;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 21U)) + 3511378091284703789U;
            aOrbiterI = (((aWandererE + RotL64(aScatter, 53U)) + RotL64(aCarry, 57U)) + 15247492830966725949U) + aPhaseEOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aCross, 39U)) + 7745995913390407897U;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 35U)) + 6463593307540108810U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = (aWandererC + RotL64(aPrevious, 3U)) + 1101669311005268630U;
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 41U)) + RotL64(aCarry, 13U)) + 12988052764067518580U;
            aOrbiterD = (aWandererI + RotL64(aPrevious, 5U)) + 17717179747434679772U;
            aOrbiterB = ((aWandererF + RotL64(aCross, 57U)) + RotL64(aCarry, 43U)) + 11662190906682400416U;
            aOrbiterF = (aWandererB + RotL64(aIngress, 10U)) + 6563014073547628748U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 13099094932059419219U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 16342730862261868847U;
            aOrbiterH = RotL64((aOrbiterH * 10988124108686164829U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 16855346813127524624U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 6570063128502306944U;
            aOrbiterA = RotL64((aOrbiterA * 4571570049463124831U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 11328352033809240501U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 11640986648833160901U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2895830492089678919U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 2675226158571501666U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 17700531248266458165U;
            aOrbiterI = RotL64((aOrbiterI * 2231403813970188657U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 7729597396731910874U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 15172374484412053756U;
            aOrbiterC = RotL64((aOrbiterC * 149009041406406517U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 9178769489257842683U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 9020154972097834926U;
            aOrbiterD = RotL64((aOrbiterD * 8910504667566521429U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 1317403761217790562U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 17151528554929201571U;
            aOrbiterF = RotL64((aOrbiterF * 3735945655450625203U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 11621882033959669977U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 10289504450815075623U;
            aOrbiterE = RotL64((aOrbiterE * 13365982786836243195U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 16178772981106335703U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 16896130772325866910U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6993524735412868965U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 9573223644675562575U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 17552463713786507189U;
            aOrbiterG = RotL64((aOrbiterG * 16103431656424881779U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 4801852246698369631U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 12222235191147985484U) ^ aNonceWordO;
            aOrbiterB = RotL64((aOrbiterB * 2835204872125428065U), 53U);
            //
            aIngress = RotL64(aOrbiterH, 51U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 23U));
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterD, 21U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterC, 6U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 37U) + aOrbiterK) + RotL64(aOrbiterC, 60U));
            aWandererF = aWandererF + ((RotL64(aCross, 58U) + RotL64(aOrbiterA, 23U)) + aOrbiterF);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 43U) + aOrbiterJ) + RotL64(aOrbiterG, 39U)) + aPhaseEWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 35U)) + aNonceWordI);
            aWandererH = aWandererH ^ ((RotL64(aCross, 21U) + aOrbiterD) + RotL64(aOrbiterI, 43U));
            aWandererD = aWandererD + ((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterI, 57U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterC, 29U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aPrevious, 39U) + aOrbiterJ) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 23U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterF, 36U)) + aOrbiterE) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 50U) + RotL64(aOrbiterI, 19U)) + aOrbiterB);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterH, 51U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 28U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 44U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordN;
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 9801U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 9032U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 9853U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((aIndex + 8007U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCarry, 4U)) ^ (RotL64(aIngress, 53U) + RotL64(aCross, 23U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterH = (aWandererG + RotL64(aCross, 43U)) + 12775735908960052604U;
            aOrbiterI = ((aWandererD + RotL64(aScatter, 28U)) + RotL64(aCarry, 41U)) + 11791373812080296887U;
            aOrbiterE = (aWandererF + RotL64(aIngress, 47U)) + 5537362877706057303U;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 19U)) + 2023912048504189380U;
            aOrbiterB = (aWandererE + RotL64(aScatter, 37U)) + 17668828109963766893U;
            aOrbiterG = (((aWandererA + RotL64(aIngress, 12U)) + RotL64(aCarry, 23U)) + 558908629933941224U) + aNonceWordG;
            aOrbiterK = (((aWandererB + RotL64(aPrevious, 5U)) + RotL64(aCarry, 5U)) + 1479633119685446888U) + aPhaseEOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aCross, 41U)) + 15460320397843364063U) + aPhaseEOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = (aWandererC + RotL64(aPrevious, 35U)) + 10059749397555469054U;
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 53U)) + 9987633811929693924U) + aNonceWordM;
            aOrbiterD = (aWandererH + RotL64(aCross, 57U)) + 10087337844580228269U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 4446204415503364254U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 15106063243302192717U) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 13273756657334709803U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 9430197906134676162U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 1226048679997253363U) ^ aNonceWordL;
            aOrbiterI = RotL64((aOrbiterI * 14247538885252664127U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 10611580584157624739U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 3137391249289641509U;
            aOrbiterB = RotL64((aOrbiterB * 5462682413239873181U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 9327201928815412810U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 7890659377013147073U;
            aOrbiterK = RotL64((aOrbiterK * 13827717178378062047U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 10675114832750356941U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 8804440385852327267U;
            aOrbiterC = RotL64((aOrbiterC * 8520671775587260601U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 12871947817782057116U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 11015991745792051390U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17152451500505815031U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 6320437975845673731U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 702457937087191287U;
            aOrbiterJ = RotL64((aOrbiterJ * 17491257114676739589U), 23U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterF) + 16629064896250312921U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordK;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 6054107387816339103U;
            aOrbiterG = RotL64((aOrbiterG * 6983767878966747219U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 13274874838094190290U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 12211422735294360321U;
            aOrbiterF = RotL64((aOrbiterF * 5113738196151089817U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 15338616110718583619U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 1475787183754511373U;
            aOrbiterA = RotL64((aOrbiterA * 10904607643785840003U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 15486810401396777742U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 12775735908960052604U;
            aOrbiterD = RotL64((aOrbiterD * 7478156942468930207U), 43U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterC, 40U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 21U));
            aIngress = aIngress + RotL64(aOrbiterE, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 41U) + aOrbiterC) + RotL64(aOrbiterK, 51U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterC, 3U)) + aOrbiterD) + RotL64(aCarry, 37U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterI, 11U)) + aOrbiterB);
            aWandererA = aWandererA + (((RotL64(aCross, 46U) + RotL64(aOrbiterA, 60U)) + aOrbiterG) + RotL64(aCarry, 13U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 53U)) + aOrbiterF);
            aWandererD = aWandererD + ((RotL64(aScatter, 51U) + aOrbiterK) + RotL64(aOrbiterE, 35U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterI, 5U)) + aOrbiterJ);
            aWandererE = aWandererE + ((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterI, 37U));
            aWandererH = aWandererH ^ ((((RotL64(aCross, 53U) + RotL64(aOrbiterK, 19U)) + aOrbiterF) + aNonceWordD) + aPhaseEWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 37U) + RotL64(aOrbiterC, 14U)) + aOrbiterG);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 30U) + aOrbiterE) + RotL64(aOrbiterF, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 14U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 42U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 12570U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((aIndex + 15663U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 14830U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneC[((aIndex + 14729U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 57U)) ^ (RotL64(aPrevious, 21U) ^ RotL64(aCross, 44U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterI = ((aWandererE + RotL64(aScatter, 35U)) + RotL64(aCarry, 27U)) + 16183871922837164759U;
            aOrbiterA = (aWandererK + RotL64(aIngress, 27U)) + 7002058258090219055U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 48U)) + 5650868611888303705U;
            aOrbiterC = (aWandererD + RotL64(aPrevious, 53U)) + 11899839660943876690U;
            aOrbiterH = (((aWandererG + RotL64(aCross, 39U)) + 15349649504488111111U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordE;
            aOrbiterG = (aWandererB + RotL64(aIngress, 3U)) + 14060149569086744970U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 29U)) + 12920917574225030112U) + aPhaseEOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = (aWandererA + RotL64(aScatter, 58U)) + 2831994965175330135U;
            aOrbiterD = ((aWandererC + RotL64(aCross, 41U)) + RotL64(aCarry, 11U)) + 18312543585028439192U;
            aOrbiterF = (aWandererF + RotL64(aPrevious, 37U)) + 11657562205118394239U;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 23U)) + RotL64(aCarry, 43U)) + 10850792819281246052U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 17810371216216125323U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 7963413941144223128U;
            aOrbiterJ = RotL64((aOrbiterJ * 534217972450595401U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 5498715358793875584U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 9256727548911651373U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10498848323914000989U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 17246360111302191699U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 18309978718113983369U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 18267472694666221077U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 3100998994319502921U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 8129301860291235970U;
            aOrbiterH = RotL64((aOrbiterH * 17847033539279176187U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 1889641029473279114U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 16538494307002917945U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8081488217920885783U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 5432230549146849322U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 2634437941396090817U;
            aOrbiterF = RotL64((aOrbiterF * 7612999214758935211U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 16940172599174185058U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 13151669140593952203U;
            aOrbiterI = RotL64((aOrbiterI * 16225319638131723487U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 3995064294869931681U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 913081077665768816U) ^ aNonceWordN;
            aOrbiterC = RotL64((aOrbiterC * 9299514648768060453U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 2469001696075411481U) + aNonceWordC;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 2167390955194185443U;
            aOrbiterK = RotL64((aOrbiterK * 11805065572289005223U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 1574066406534010796U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 8736976961589874013U;
            aOrbiterD = RotL64((aOrbiterD * 5980070607180321955U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 4233621443153132083U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 16183871922837164759U;
            aOrbiterE = RotL64((aOrbiterE * 4030569514959370895U), 43U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterC, 23U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 34U));
            aIngress = aIngress + (RotL64(aOrbiterE, 51U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + RotL64(aOrbiterK, 42U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterF, 21U)) + aOrbiterJ);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterE, 43U)) + aOrbiterK) + RotL64(aCarry, 23U)) + aNonceWordP);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 6U) + RotL64(aOrbiterC, 27U)) + aOrbiterJ);
            aWandererC = aWandererC + (((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterD, 47U)) + RotL64(aCarry, 51U));
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 47U) + RotL64(aOrbiterA, 38U)) + aOrbiterC) + aNonceWordK) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 19U)) + aOrbiterB) + aPhaseEWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 20U) + RotL64(aOrbiterG, 3U)) + aOrbiterC);
            aWandererB = aWandererB + ((RotL64(aIngress, 27U) + aOrbiterE) + RotL64(aOrbiterI, 41U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 57U) + aOrbiterD) + RotL64(aOrbiterG, 53U));
            aWandererI = aWandererI + (((RotL64(aIngress, 37U) + RotL64(aOrbiterJ, 50U)) + aOrbiterH) + aNonceWordA);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterD, 5U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererI, 30U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererG, 42U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordL;
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 18100U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((aIndex + 17225U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20807U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneD[((aIndex + 21696U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 13U) + RotL64(aPrevious, 51U)) ^ (RotL64(aIngress, 26U) ^ RotL64(aCross, 39U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterI = (aWandererK + RotL64(aCross, 46U)) + 8767379393098711499U;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 57U)) + 7168159491580816433U) + aNonceWordH;
            aOrbiterJ = (aWandererC + RotL64(aScatter, 13U)) + 9879279829061883406U;
            aOrbiterA = (((aWandererH + RotL64(aPrevious, 19U)) + RotL64(aCarry, 21U)) + 10537167136053399303U) + aNonceWordO;
            aOrbiterK = ((aWandererD + RotL64(aCross, 3U)) + RotL64(aCarry, 47U)) + 2839070018069188936U;
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 53U)) + 13844278063968429732U;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 35U)) + 11278946626186474646U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = ((aWandererG + RotL64(aScatter, 43U)) + RotL64(aCarry, 3U)) + 11798425216660557799U;
            aOrbiterG = (aWandererI + RotL64(aCross, 29U)) + 7618446090703335192U;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 41U)) + 695423597006983660U;
            aOrbiterC = (((aWandererF + RotL64(aIngress, 22U)) + 14344728202803488813U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordP;
            //
            aOrbiterI = (((aOrbiterI + aOrbiterE) + 11656100506575697086U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1]) + aNonceWordA;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 10384358779985773937U;
            aOrbiterJ = RotL64((aOrbiterJ * 247494692039140973U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 17585001605131977341U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 9964478171465522911U;
            aOrbiterK = RotL64((aOrbiterK * 13484044854790175315U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 2710943171829692624U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 17809072853457153057U) ^ aNonceWordF;
            aOrbiterF = RotL64((aOrbiterF * 16341884203303271365U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 12814092033910687774U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 1743186323268668740U;
            aOrbiterB = RotL64((aOrbiterB * 11150822630624332557U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 10750472346626754704U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 15925901217078035356U;
            aOrbiterH = RotL64((aOrbiterH * 9276504171291801637U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 2569102106359362359U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 8868261301410769739U;
            aOrbiterG = RotL64((aOrbiterG * 3662495603133918101U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 2143691008373582476U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 10606616796243205921U;
            aOrbiterD = RotL64((aOrbiterD * 15794414817813485643U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 16258070651850746855U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 11720192793689633315U;
            aOrbiterC = RotL64((aOrbiterC * 14475623219460678021U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 8230871037292355675U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 16898650748046368353U;
            aOrbiterI = RotL64((aOrbiterI * 7368697435476300255U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 9071122174426904737U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 4506737259011736474U) ^ aNonceWordD;
            aOrbiterE = RotL64((aOrbiterE * 11903039808814842447U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 4545409671845718259U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 8767379393098711499U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1210632171306946669U), 23U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 19U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + (RotL64(aOrbiterI, 22U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + RotL64(aOrbiterC, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aPrevious, 37U) + aOrbiterE) + RotL64(aOrbiterC, 53U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterG, 21U)) + aOrbiterA) + aNonceWordJ);
            aWandererF = aWandererF + ((RotL64(aCross, 44U) + aOrbiterI) + RotL64(aOrbiterC, 37U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterK, 39U));
            aWandererK = aWandererK + ((RotL64(aScatter, 3U) + aOrbiterH) + RotL64(aOrbiterB, 3U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterA, 58U)) + aOrbiterJ) + aNonceWordN);
            aWandererJ = aWandererJ + (((RotL64(aCross, 35U) + RotL64(aOrbiterD, 35U)) + aOrbiterA) + RotL64(aCarry, 27U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 6U) + RotL64(aOrbiterJ, 11U)) + aOrbiterC) + aPhaseEWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 47U) + RotL64(aOrbiterG, 27U)) + aOrbiterI);
            aWandererC = aWandererC ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterF, 13U)) + aOrbiterI) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 53U) + RotL64(aOrbiterB, 56U)) + aOrbiterA) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 48U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + (RotL64(aWandererE, 10U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 13U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordJ;
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 26728U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneA[((aIndex + 23541U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 22040U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23980U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCross, 23U)) + (RotL64(aCarry, 51U) ^ RotL64(aIngress, 10U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterC = ((aWandererE + RotL64(aCross, 3U)) + 16451272412693907816U) + aNonceWordI;
            aOrbiterI = (aWandererG + RotL64(aIngress, 34U)) + 10099485419723255462U;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 23U)) + RotL64(aCarry, 23U)) + 17668900099534923192U;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 37U)) + RotL64(aCarry, 43U)) + 5497093724143181753U;
            aOrbiterH = (aWandererA + RotL64(aCross, 13U)) + 10354044773550071706U;
            aOrbiterD = (aWandererB + RotL64(aScatter, 27U)) + 12728258851198019099U;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 56U)) + 4144050505314242618U) + aNonceWordC;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 39U)) + 14133805325480076530U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aCross, 29U)) + 308863673210602899U;
            aOrbiterF = (((aWandererC + RotL64(aIngress, 41U)) + RotL64(aCarry, 39U)) + 11741180130160569753U) + aPhaseEOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aScatter, 19U)) + 12926863156769180448U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 211920854786494259U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 13234608842479411078U;
            aOrbiterA = RotL64((aOrbiterA * 2556747209733759467U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 9164711974854618892U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 6667377062281954219U;
            aOrbiterD = RotL64((aOrbiterD * 2603737166987437649U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 4559040002406721850U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 1749875480850675109U;
            aOrbiterK = RotL64((aOrbiterK * 15822640067349481089U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 9555365165561936366U) + aNonceWordJ;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 18289733999504213574U;
            aOrbiterF = RotL64((aOrbiterF * 14156217554673229429U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 8727162691639622461U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 291406782452963706U;
            aOrbiterC = RotL64((aOrbiterC * 8413500075082350243U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 8294911802626492257U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 15853578397277298548U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13256191781365357747U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 11535146194939658681U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 2177540476748375661U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15791341922007841029U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 2705306323728084136U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 17617871830709148043U;
            aOrbiterG = RotL64((aOrbiterG * 3449981219502809255U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 3699834746313613206U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 17952609181629473245U;
            aOrbiterJ = RotL64((aOrbiterJ * 6103160209028988839U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 8016694658897707674U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 6971251395823324489U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13483776115929040277U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 17467528888050817915U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 16451272412693907816U;
            aOrbiterH = RotL64((aOrbiterH * 13689734638238895071U), 11U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 39U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 60U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterD, 39U)) + aOrbiterG) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 50U) + aOrbiterC) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 43U)) + aOrbiterA);
            aWandererE = aWandererE + (((RotL64(aCross, 41U) + aOrbiterC) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 43U) + aOrbiterH) + RotL64(aOrbiterI, 36U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 47U) + aOrbiterH) + RotL64(aOrbiterA, 11U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 19U) + aOrbiterK) + RotL64(aOrbiterG, 21U)) + aPhaseEWandererUpdateSaltD[((aIndex + 4U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 52U) + aOrbiterG) + RotL64(aOrbiterF, 47U)) + aNonceWordL);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterK, 27U)) + aOrbiterB);
            aWandererK = aWandererK + ((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 51U)) + aOrbiterH);
            aWandererC = aWandererC ^ (((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterB, 18U)) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 34U));
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererI, 6U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordJ);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 27686U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27871U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31520U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31142U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 43U) + RotL64(aCross, 57U)) ^ (RotL64(aIngress, 27U) + RotL64(aCarry, 6U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterK = ((aWandererD + RotL64(aScatter, 3U)) + 17225673071833726819U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 43U)) + RotL64(aCarry, 53U)) + 10301458382103627331U;
            aOrbiterE = ((aWandererF + RotL64(aCross, 11U)) + 3960233050857362414U) + aPhaseEOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 34U)) + 17768665685046605837U) + aNonceWordA;
            aOrbiterC = (aWandererJ + RotL64(aCross, 39U)) + 14471018461213959767U;
            aOrbiterH = (aWandererK + RotL64(aIngress, 29U)) + 10730597892721340453U;
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 27U)) + RotL64(aCarry, 29U)) + 14863394003122760542U;
            aOrbiterI = (aWandererE + RotL64(aScatter, 5U)) + 9948587274816688296U;
            aOrbiterG = (aWandererC + RotL64(aIngress, 21U)) + 3573569431435100993U;
            aOrbiterD = ((aWandererI + RotL64(aCross, 57U)) + RotL64(aCarry, 23U)) + 8153670675740450590U;
            aOrbiterA = (aWandererG + RotL64(aScatter, 46U)) + 16438856577722561424U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 15765587867581925041U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 1082039522061775213U;
            aOrbiterE = RotL64((aOrbiterE * 17023740047246402641U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 4202521649260798876U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 15877659681260461141U;
            aOrbiterC = RotL64((aOrbiterC * 11369910758551088173U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 2551560426129646123U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 3005102326163906320U;
            aOrbiterH = RotL64((aOrbiterH * 4241583192662435107U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 1675501058857208089U) + aNonceWordO;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 12774812270956702043U;
            aOrbiterF = RotL64((aOrbiterF * 5488437008504905105U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 1044886020922563597U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 4857445127457225171U;
            aOrbiterI = RotL64((aOrbiterI * 13223560654459705259U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 11548725551787560962U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 2434677823189765161U;
            aOrbiterG = RotL64((aOrbiterG * 4283026044563670969U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 9606875320524736294U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 13732615866277657704U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3905528919281629775U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 13921743663803299567U) + aNonceWordI;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 13350829301153929899U;
            aOrbiterA = RotL64((aOrbiterA * 11858642286713079795U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 9473349030551400156U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterG) ^ 7446792050826434742U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterK = RotL64((aOrbiterK * 6619682184124713031U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 17970527747978977453U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 2326714817603921480U;
            aOrbiterJ = RotL64((aOrbiterJ * 14581676978186226887U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 7875511075130474136U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 17225673071833726819U;
            aOrbiterB = RotL64((aOrbiterB * 1196024136909896027U), 27U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 57U);
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + RotL64(aOrbiterH, 60U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aIngress, 46U) + aOrbiterF) + RotL64(aOrbiterA, 39U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterH, 41U)) + aOrbiterD);
            aWandererF = aWandererF + ((RotL64(aPrevious, 23U) + aOrbiterG) + RotL64(aOrbiterB, 57U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterK, 44U)) + aOrbiterG);
            aWandererA = aWandererA + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 35U)) + aOrbiterF) + aNonceWordC);
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 5U) + RotL64(aOrbiterC, 23U)) + aOrbiterD) + aNonceWordL) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 60U) + RotL64(aOrbiterB, 37U)) + aOrbiterH) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterG, 19U)) + aOrbiterI);
            aWandererD = aWandererD + (((RotL64(aCross, 35U) + RotL64(aOrbiterG, 51U)) + aOrbiterH) + aNonceWordP);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterE, 46U)) + aOrbiterD);
            aWandererB = aWandererB + ((((RotL64(aIngress, 39U) + aOrbiterJ) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 51U)) + aPhaseEWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 40U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererJ, 60U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordB);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xD913221D6A1A8593ULL + 0xFB3237CC3F33CE55ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xDA8D5C14567C99F5ULL + 0x9B93A15C967C080DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xA784A29B5BAC11DBULL + 0x9D17BD5E59D2A315ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xD888A06F0AB4FA4FULL + 0x8920A6DA84A60669ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xF9E5CC71252F9FD1ULL + 0xC85BA4878886B81DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xC0CBAF4F31CE1A99ULL + 0xB51970F28AF09DA2ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xEB620D27066A8407ULL + 0xDC67C092C8546114ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xBEB2EE09D33F0B6DULL + 0xB4B05123B553A644ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xC82C578056D96819ULL + 0xFC04AC4E4EC63692ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xB19A33DA8B460415ULL + 0xCB6584CDD5BD0177ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xE64D9D378495F58DULL + 0xFE7B2D4FA3FCA650ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x8B2B8B984479570DULL + 0xCBDFE599E219BF32ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xE08E9DDB81ECF1CDULL + 0xADE8A852018A0B50ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xC06C9D6FC0F41151ULL + 0x92630363EC52E2B1ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xC00A2A9EA473881BULL + 0x964A79365107711CULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xBAF326FF192D8A1FULL + 0xE6278C68367A2C47ULL);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 1068U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 894U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 365U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 4916U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCross, 3U)) ^ (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 18U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = (aWandererB + RotL64(aCross, 53U)) + 15726877954695761686U;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 57U)) + 14187652171881943587U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = (aWandererI + RotL64(aIngress, 43U)) + 8420423151313882782U;
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 28U)) + 14942322692433259283U;
            aOrbiterB = ((aWandererK + RotL64(aCross, 13U)) + RotL64(aCarry, 11U)) + 7272331475919796255U;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 47U)) + RotL64(aCarry, 39U)) + 154504365041805840U;
            aOrbiterD = (aWandererD + RotL64(aScatter, 51U)) + 17475491222554948786U;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 11U)) + 5759181483165339605U) + aNonceWordH;
            aOrbiterK = (aWandererJ + RotL64(aIngress, 21U)) + 5993060214499322845U;
            aOrbiterH = ((((aWandererA + RotL64(aPrevious, 3U)) + RotL64(aCarry, 29U)) + 10901786237875941844U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordD;
            aOrbiterG = (aWandererH + RotL64(aCross, 34U)) + 17135786595614068473U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 5208202073886811165U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 6821452921018900631U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13119330055184115669U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 13348064837402206969U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 8967943922403445136U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 300168481725373093U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 8130283784171430891U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 6351113882502502876U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15960622823993072903U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 6894708729226455769U) + aNonceWordO;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 12065058511247133944U;
            aOrbiterJ = RotL64((aOrbiterJ * 5432601727436935831U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 17138279326229372741U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 12987698199066890628U;
            aOrbiterD = RotL64((aOrbiterD * 12665716655177320977U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 13688833537574196675U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 4211971980434000618U;
            aOrbiterK = RotL64((aOrbiterK * 1374411763361518851U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 10376917117582537592U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 4807742522197923516U;
            aOrbiterG = RotL64((aOrbiterG * 15257251453302090961U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 18038296468177121243U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 6879666349379745258U;
            aOrbiterA = RotL64((aOrbiterA * 15819475269715810555U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 5193656664432659624U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 680899397323387963U;
            aOrbiterB = RotL64((aOrbiterB * 9857476056194621321U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 1851929589073547860U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 13093101559415170218U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13950928576652143737U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 13695333301427028607U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 15726877954695761686U;
            aOrbiterH = RotL64((aOrbiterH * 960063676226172027U), 5U);
            //
            aIngress = RotL64(aOrbiterJ, 53U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterG, 37U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 23U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + RotL64(aOrbiterF, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aIngress, 37U) + RotL64(aOrbiterG, 35U)) + aOrbiterA) + aNonceWordL) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 40U) + RotL64(aOrbiterC, 52U)) + aOrbiterF);
            aWandererK = aWandererK + ((RotL64(aPrevious, 43U) + aOrbiterB) + RotL64(aOrbiterK, 37U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterF, 13U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 19U) + aOrbiterJ) + RotL64(aOrbiterG, 47U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterE, 54U)) + aNonceWordP);
            aWandererC = aWandererC + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 27U)) + aOrbiterG) + RotL64(aCarry, 41U)) + aPhaseFWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterH, 29U)) + aOrbiterI) + aNonceWordK);
            aWandererH = aWandererH + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 39U)) + aOrbiterA) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 11U) + aOrbiterH) + RotL64(aOrbiterK, 3U));
            aWandererA = aWandererA + ((RotL64(aScatter, 26U) + aOrbiterB) + RotL64(aOrbiterA, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 18U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + RotL64(aWandererJ, 27U);
            aCarry = aCarry + RotL64(aIngress, 10U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8555U)) & S_BLOCK1], 34U) ^ RotL64(aOperationLaneD[((aIndex + 9923U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 9053U)) & S_BLOCK1], 28U) ^ RotL64(aOperationLaneB[((aIndex + 6153U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 27U) ^ RotL64(aCross, 43U)) + (RotL64(aPrevious, 58U) ^ RotL64(aCarry, 13U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = (aWandererH + RotL64(aCross, 47U)) + 15188686795415908074U;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 20U)) + RotL64(aCarry, 27U)) + 17310049041983079779U;
            aOrbiterA = (aWandererA + RotL64(aScatter, 41U)) + 8246925977992441471U;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 35U)) + 8644260919918112781U) + aNonceWordE;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 51U)) + 13401663736874819483U;
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 24U)) + RotL64(aCarry, 47U)) + 7940358935238314973U;
            aOrbiterE = (((aWandererF + RotL64(aScatter, 29U)) + RotL64(aCarry, 37U)) + 13278990328548007839U) + aPhaseFOrbiterAssignSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = (aWandererE + RotL64(aCross, 53U)) + 11346868298353840706U;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 5U)) + 2374077904806833579U;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 43U)) + 6978903378645019166U) + aNonceWordJ;
            aOrbiterB = ((aWandererK + RotL64(aCross, 37U)) + 11951633297870965212U) + aPhaseFOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 17398460995357409673U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 1215437945597836770U;
            aOrbiterA = RotL64((aOrbiterA * 9322970054123481621U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 1878751468043972239U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 5343002808239712390U;
            aOrbiterI = RotL64((aOrbiterI * 11878640995447558811U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 9884918450053276861U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 15894599082080422550U) ^ aNonceWordB;
            aOrbiterJ = RotL64((aOrbiterJ * 8359936745539546131U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 13917339232771145459U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 18101134009493720683U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15835859435306756387U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 3830086372356903769U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 15894394599564584010U;
            aOrbiterK = RotL64((aOrbiterK * 9513921913446609263U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 5127590955274245812U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 9410946933309720054U;
            aOrbiterD = RotL64((aOrbiterD * 14507476989423060561U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 15544384157294987085U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 998801294460434123U;
            aOrbiterH = RotL64((aOrbiterH * 5946968142746472745U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 16442095194965452163U) + aNonceWordL;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 14294936349037516932U;
            aOrbiterC = RotL64((aOrbiterC * 14655345374740882581U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 16680659892463349201U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 10921918150041635666U;
            aOrbiterF = RotL64((aOrbiterF * 2908474941036821745U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 15350264522133299871U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 16413848767507968239U;
            aOrbiterG = RotL64((aOrbiterG * 10226942289998651355U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 11963105565077056299U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 15188686795415908074U;
            aOrbiterB = RotL64((aOrbiterB * 13002484121826831091U), 39U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterC, 19U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 22U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 35U));
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 44U)) + aOrbiterC) + aNonceWordD);
            aWandererI = aWandererI + (((RotL64(aIngress, 47U) + aOrbiterH) + RotL64(aOrbiterJ, 53U)) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterK, 11U)) + aOrbiterG);
            aWandererE = aWandererE + (((RotL64(aCross, 58U) + aOrbiterA) + RotL64(aOrbiterI, 39U)) + aNonceWordO);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterK, 27U)) + aOrbiterI);
            aWandererF = aWandererF + (((RotL64(aCross, 23U) + aOrbiterB) + RotL64(aOrbiterA, 41U)) + RotL64(aCarry, 37U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 41U) + aOrbiterF) + RotL64(aOrbiterE, 29U));
            aWandererB = aWandererB + ((RotL64(aScatter, 26U) + RotL64(aOrbiterG, 47U)) + aOrbiterD);
            aWandererA = aWandererA ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterI, 51U)) + aOrbiterH) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 53U) + aOrbiterJ) + RotL64(aOrbiterD, 20U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 23U)) + aOrbiterK) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 52U));
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + RotL64(aWandererJ, 35U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordG);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15469U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13679U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 14845U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneC[((aIndex + 14687U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 11U)) + (RotL64(aCross, 41U) + RotL64(aIngress, 24U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = (aWandererF + RotL64(aCross, 56U)) + 5576732410244514238U;
            aOrbiterH = (aWandererI + RotL64(aScatter, 53U)) + 2833808925935929629U;
            aOrbiterI = (((aWandererA + RotL64(aIngress, 51U)) + RotL64(aCarry, 43U)) + 3670188682914544792U) + aPhaseFOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = (aWandererG + RotL64(aPrevious, 23U)) + 15759072378887814995U;
            aOrbiterD = (aWandererC + RotL64(aCross, 41U)) + 13934007231137439994U;
            aOrbiterK = ((aWandererB + RotL64(aScatter, 60U)) + RotL64(aCarry, 5U)) + 11022225696007690512U;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 5U)) + 16989177104453635790U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 29U)) + RotL64(aCarry, 13U)) + 9256930045263527091U;
            aOrbiterE = (aWandererE + RotL64(aCross, 3U)) + 17788596104417068290U;
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 11U)) + 17044369456673337625U) + aNonceWordF;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 13U)) + 1310908395523250343U) + aNonceWordE;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 12067065689034065422U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 15130844248737512262U;
            aOrbiterI = RotL64((aOrbiterI * 9409499577465934107U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 14532689204495587494U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 8198147292120244178U) ^ aNonceWordG;
            aOrbiterK = RotL64((aOrbiterK * 1418356389507740991U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 5485494458627163347U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 10830008207150307611U;
            aOrbiterH = RotL64((aOrbiterH * 6526039534042499457U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 17770065502486618029U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 6397859353395335459U;
            aOrbiterD = RotL64((aOrbiterD * 14286997752368893825U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 5128700697381508319U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 7103394110057060499U;
            aOrbiterA = RotL64((aOrbiterA * 5053680689949149633U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 16024401282261796979U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 12818445221897253410U;
            aOrbiterJ = RotL64((aOrbiterJ * 11450004517784155405U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 13386978409145916350U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 16740821954556699503U) ^ aNonceWordJ;
            aOrbiterF = RotL64((aOrbiterF * 5376430209628515105U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 313978038530994953U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 1355733685461795345U;
            aOrbiterG = RotL64((aOrbiterG * 15955927322082619735U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 12590581077253956064U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 2298195367575496005U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17512801361187006363U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 11847450675712272468U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 5914296379577670282U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14574813500616811367U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 16901317262621287065U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 5576732410244514238U;
            aOrbiterB = RotL64((aOrbiterB * 4514943876091531567U), 5U);
            //
            aIngress = RotL64(aOrbiterE, 29U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 27U));
            aIngress = aIngress + (RotL64(aOrbiterA, 60U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterG, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterK, 42U)) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterG, 3U)) + aOrbiterC) + aNonceWordO);
            aWandererE = aWandererE + ((((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterC, 57U)) + RotL64(aCarry, 39U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 37U) + aOrbiterF) + RotL64(aOrbiterD, 47U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 20U) + aOrbiterG) + RotL64(aOrbiterI, 51U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 5U) + aOrbiterK) + RotL64(aOrbiterG, 27U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterA, 29U)) + aOrbiterB) + aPhaseFWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterI, 5U)) + aOrbiterD);
            aWandererI = aWandererI + ((RotL64(aCross, 27U) + aOrbiterA) + RotL64(aOrbiterE, 23U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 44U)) + aOrbiterG);
            aWandererF = aWandererF + ((RotL64(aPrevious, 52U) + RotL64(aOrbiterJ, 53U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 14U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + RotL64(aWandererK, 53U);
            aCarry = aCarry + RotL64(aIngress, 42U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordG);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 20597U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18109U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17373U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 17889U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aPrevious, 57U)) ^ (RotL64(aCarry, 6U) + RotL64(aIngress, 35U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = (((aWandererJ + RotL64(aIngress, 21U)) + RotL64(aCarry, 39U)) + 13296600294247799698U) + aPhaseFOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = (aWandererF + RotL64(aPrevious, 37U)) + 5818503518080877515U;
            aOrbiterA = ((aWandererB + RotL64(aCross, 12U)) + RotL64(aCarry, 13U)) + 6735784238734173597U;
            aOrbiterG = ((aWandererE + RotL64(aScatter, 3U)) + 7368398209488856201U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aIngress, 53U)) + 961734029066455638U;
            aOrbiterH = (aWandererD + RotL64(aCross, 41U)) + 797011946660892011U;
            aOrbiterC = (aWandererK + RotL64(aPrevious, 35U)) + 12841876018396622350U;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 39U)) + 16213253970483895623U) + aNonceWordN;
            aOrbiterK = (aWandererG + RotL64(aCross, 51U)) + 15186950557113470375U;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 10U)) + RotL64(aCarry, 5U)) + 5117930310827477341U;
            aOrbiterF = (aWandererH + RotL64(aPrevious, 43U)) + 12265429373166094162U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 13920531346698601568U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 14695405206998211456U;
            aOrbiterA = RotL64((aOrbiterA * 13950964363414164279U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 7851960904825938443U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 9501511171732550190U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5614164120361489613U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 5663365182245722077U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 9607860124321315555U;
            aOrbiterH = RotL64((aOrbiterH * 3461820361914280601U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 18171052650586819280U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 3442698321538580861U;
            aOrbiterC = RotL64((aOrbiterC * 6317525514963824829U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 1491052813469258970U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 3956599824067616133U;
            aOrbiterB = RotL64((aOrbiterB * 2928600779267623085U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 10963841237346073453U) + aNonceWordO;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 2303020125591252534U;
            aOrbiterK = RotL64((aOrbiterK * 9969099842343321981U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 14503856057958162356U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 11147548150090597694U;
            aOrbiterE = RotL64((aOrbiterE * 11856382308792700441U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 9191681438318311481U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 13556072770381999852U;
            aOrbiterF = RotL64((aOrbiterF * 18316231099054203683U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 10103207278550444685U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 10415809965217261104U;
            aOrbiterD = RotL64((aOrbiterD * 16562732599511350217U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 17435033201864058457U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 5540494424887364682U;
            aOrbiterI = RotL64((aOrbiterI * 18230910315317249045U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 18020151683897013854U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 13296600294247799698U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10000194329456668845U), 11U);
            //
            aIngress = RotL64(aOrbiterJ, 3U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + (RotL64(aOrbiterF, 36U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterK, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterC, 35U)) + aOrbiterF) + aPhaseFWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 19U) + RotL64(aOrbiterH, 58U)) + aOrbiterF) + aNonceWordD);
            aWandererA = aWandererA ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterF, 11U)) + aOrbiterB);
            aWandererH = aWandererH + (((RotL64(aScatter, 43U) + aOrbiterH) + RotL64(aOrbiterJ, 43U)) + RotL64(aCarry, 39U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 10U) + aOrbiterG) + RotL64(aOrbiterE, 3U)) + aNonceWordK);
            aWandererC = aWandererC + ((RotL64(aScatter, 3U) + RotL64(aOrbiterF, 6U)) + aOrbiterI);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterD, 21U)) + aOrbiterF);
            aWandererE = aWandererE + (((RotL64(aIngress, 23U) + aOrbiterK) + RotL64(aOrbiterA, 41U)) + aNonceWordB);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 36U) + aOrbiterH) + RotL64(aOrbiterC, 13U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 21U) + aOrbiterG) + RotL64(aOrbiterB, 27U)) + RotL64(aCarry, 5U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 53U) + aOrbiterA) + RotL64(aOrbiterC, 19U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 60U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + RotL64(aWandererH, 41U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordM;
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 26622U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneA[((aIndex + 25792U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24214U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((aIndex + 24785U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 54U) + RotL64(aCarry, 35U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterB = (aWandererB + RotL64(aCross, 21U)) + 5171470532667965920U;
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 11U)) + 750549462358682403U;
            aOrbiterE = (aWandererD + RotL64(aPrevious, 48U)) + 3325689257577120525U;
            aOrbiterH = ((aWandererF + RotL64(aIngress, 13U)) + 18031575461559790826U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 39U)) + RotL64(aCarry, 11U)) + 13874739537012288677U;
            aOrbiterD = (((aWandererG + RotL64(aIngress, 57U)) + RotL64(aCarry, 3U)) + 4250029868785016865U) + aPhaseFOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = ((aWandererC + RotL64(aScatter, 37U)) + RotL64(aCarry, 27U)) + 8211158803112611161U;
            aOrbiterK = ((aWandererI + RotL64(aCross, 23U)) + 1083939790236786027U) + aNonceWordL;
            aOrbiterA = (aWandererA + RotL64(aScatter, 46U)) + 3446525462376962464U;
            aOrbiterF = (aWandererE + RotL64(aPrevious, 29U)) + 6973817815000417325U;
            aOrbiterI = ((aWandererK + RotL64(aCross, 27U)) + 15230876489676945543U) + aNonceWordD;
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9359727659738755880U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 8775170107816327654U;
            aOrbiterE = RotL64((aOrbiterE * 6910680458261008653U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 11958941755525038545U) + aNonceWordK;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 16966819714283167348U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16363457661846050749U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 14556087985619763243U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 17915047508377045221U;
            aOrbiterK = RotL64((aOrbiterK * 6727635453185130109U), 29U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterD) + 8578745677485367222U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1]) + aNonceWordO;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 7002181668717618866U;
            aOrbiterF = RotL64((aOrbiterF * 12329703532414955235U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 3569939503066735457U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 2956247934282522184U;
            aOrbiterB = RotL64((aOrbiterB * 9946650822131152531U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 4285180013402474041U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 5976239869535619811U;
            aOrbiterH = RotL64((aOrbiterH * 3458095419039067465U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 2424524955161695463U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 6849595426583763537U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12727902040238318101U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 11414890686374886716U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 5668287266836153445U;
            aOrbiterA = RotL64((aOrbiterA * 8011885266143066285U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 9976985606260445887U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 9223940029500676834U;
            aOrbiterI = RotL64((aOrbiterI * 8508023992488499955U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 4480967907876921958U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterK) ^ 5132766654502526597U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 321625389942019245U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 12921555132452983464U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 5171470532667965920U;
            aOrbiterC = RotL64((aOrbiterC * 9710487797420618879U), 47U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterJ, 20U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + (RotL64(aOrbiterK, 53U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aScatter, 29U) + aOrbiterF) + RotL64(aOrbiterA, 51U)) + RotL64(aCarry, 23U)) + aNonceWordC);
            aWandererI = aWandererI ^ ((RotL64(aCross, 48U) + RotL64(aOrbiterC, 42U)) + aOrbiterK);
            aWandererD = aWandererD + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 19U)) + aOrbiterJ);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterE, 13U)) + aOrbiterH);
            aWandererK = aWandererK + ((RotL64(aScatter, 11U) + RotL64(aOrbiterD, 37U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 5U) + aOrbiterG) + RotL64(aOrbiterE, 11U)) + aNonceWordP) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterG, 53U)) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterK, 29U)) + aOrbiterJ);
            aWandererA = aWandererA + (((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterK, 21U)) + aPhaseFWandererUpdateSaltB[((aIndex + 4U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 39U) + aOrbiterF) + RotL64(aOrbiterB, 26U));
            aWandererE = aWandererE + ((RotL64(aIngress, 20U) + aOrbiterD) + RotL64(aOrbiterJ, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 30U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererE, 56U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordD);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 32640U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((aIndex + 31473U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28190U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31901U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aPrevious, 47U)) ^ (RotL64(aIngress, 19U) + RotL64(aCarry, 4U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = (aWandererD + RotL64(aScatter, 39U)) + 16424657151168221875U;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 26U)) + 17150123681886380361U) + aPhaseFOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = (((aWandererK + RotL64(aCross, 21U)) + RotL64(aCarry, 5U)) + 16041993588694572757U) + aNonceWordB;
            aOrbiterF = (aWandererA + RotL64(aPrevious, 57U)) + 9871185846434828537U;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 43U)) + RotL64(aCarry, 27U)) + 11227236398354430757U;
            aOrbiterB = (aWandererH + RotL64(aPrevious, 5U)) + 5399325217402192631U;
            aOrbiterD = (aWandererB + RotL64(aCross, 48U)) + 9248828789282890454U;
            aOrbiterG = (((aWandererE + RotL64(aIngress, 11U)) + RotL64(aCarry, 23U)) + 9041370494203701062U) + aNonceWordD;
            aOrbiterC = (aWandererC + RotL64(aCross, 29U)) + 14944424084524970764U;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 53U)) + 5481938174456671041U) + aNonceWordP;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 3U)) + 14783648629543752715U) + aPhaseFOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 12355573914530445723U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 9863991559011968318U;
            aOrbiterJ = RotL64((aOrbiterJ * 8495251211794343179U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 16149688605937250965U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 106041828692026825U;
            aOrbiterE = RotL64((aOrbiterE * 12199934305374582599U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 8076098639554567792U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 11155119311895580013U;
            aOrbiterB = RotL64((aOrbiterB * 1495180896564818647U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 6847612160595917702U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 16094377920388017367U;
            aOrbiterD = RotL64((aOrbiterD * 4875801863643206333U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 13584719866672696684U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 13446209321646234607U;
            aOrbiterG = RotL64((aOrbiterG * 9945349065094781529U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 15829806645369560988U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 12573767256739062550U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5649504278826069077U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 3850030870300393809U) + aNonceWordM;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 11857593987748189858U) ^ aNonceWordO;
            aOrbiterH = RotL64((aOrbiterH * 15942863910931814193U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 5505918410521728373U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 12949653497121247860U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 90944913639560027U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 2448323375614082955U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 4386059032042654583U;
            aOrbiterK = RotL64((aOrbiterK * 11730132905525317201U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 108129028178045299U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 18292666533864994149U;
            aOrbiterA = RotL64((aOrbiterA * 2599590507178673531U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 10771402979550786312U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 16424657151168221875U) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 6255743082177474607U), 53U);
            //
            aIngress = RotL64(aOrbiterG, 21U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 6U));
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterD, 37U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + RotL64(aOrbiterA, 50U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 22U) + RotL64(aOrbiterC, 3U)) + aOrbiterB) + aNonceWordI);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterJ, 26U)) + aOrbiterE);
            aWandererJ = aWandererJ + ((RotL64(aCross, 53U) + RotL64(aOrbiterF, 23U)) + aOrbiterG);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 39U) + aOrbiterA) + RotL64(aOrbiterK, 39U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 41U) + aOrbiterG) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 12U)) + aOrbiterE);
            aWandererE = aWandererE + ((((RotL64(aCross, 51U) + RotL64(aOrbiterE, 37U)) + aOrbiterH) + RotL64(aCarry, 39U)) + aNonceWordA);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterD, 57U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterJ, 41U)) + aPhaseFWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 26U) + aOrbiterF) + RotL64(aOrbiterD, 19U));
            aWandererF = aWandererF + ((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 53U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (RotL64(aWandererE, 60U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererF, 51U);
            aCarry = aCarry + RotL64(aIngress, 4U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordB);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x8D71490C4A2459DFULL + 0x83B3C2E1AD778D50ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xA85040BE855AAF33ULL + 0x9777F29FA7A9DC04ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xD3906E743DB2F251ULL + 0xA0B7569C94D3E894ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xFE86203A75EAB67BULL + 0xB299736C87719881ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x9C1015EF1F59AEB7ULL + 0xD053A8A075A6EBB3ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xE6D9E8605591612BULL + 0xF121E3A1F2537DC5ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xD2040B6048AB8D59ULL + 0xFC7BDDE7D72B7DFBULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xE49A688327C86B7DULL + 0x94B4C0EC83FFF500ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xF41945A0085530C1ULL + 0xACB4A60390BB033AULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xFB573F9BDA2D687DULL + 0xEE3A8DDFC7C7FA13ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x918D5FCD20E0CA31ULL + 0xD0278A8892AC0703ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xBEA5C8DF8CC23F61ULL + 0xFEF523B9BDB887ECULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xBC07EDB0782AB1B1ULL + 0xD316DA692FEF40DDULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x83CA60715C3965F3ULL + 0xD4965F44A01A884EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xA1FF41B75AD4A7D9ULL + 0x9CF261AEF40C2487ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xAB3D9E8AE8A34E3FULL + 0xA64C01D6F0F16B58ULL);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 3091U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 5256U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 3687U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneA[((aIndex + 5211U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aPrevious, 53U)) + (RotL64(aCarry, 4U) ^ RotL64(aIngress, 23U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = (aWandererD + RotL64(aCross, 30U)) + 3650233661228036955U;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 35U)) + RotL64(aCarry, 13U)) + 11607036400067735729U;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 19U)) + 3899614406903883035U) + aNonceWordP;
            aOrbiterG = ((aWandererB + RotL64(aScatter, 39U)) + RotL64(aCarry, 53U)) + 8159156925629965143U;
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 3U)) + 7148903913967261270U;
            aOrbiterC = (aWandererC + RotL64(aCross, 53U)) + 9161665622287517848U;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 43U)) + 2981535013474059469U) + aNonceWordN;
            aOrbiterA = (aWandererE + RotL64(aIngress, 57U)) + 15812469008200319549U;
            aOrbiterB = (aWandererJ + RotL64(aScatter, 46U)) + 14687469489893270300U;
            aOrbiterK = ((aWandererI + RotL64(aIngress, 23U)) + 6025209349511417063U) + aPhaseFOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = (((aWandererH + RotL64(aCross, 37U)) + RotL64(aCarry, 39U)) + 12964750392311112676U) + aPhaseFOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 6572355895765394340U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 3542300121890027981U;
            aOrbiterH = RotL64((aOrbiterH * 11201491178181273935U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 6477175684045398359U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 1081388388827929314U;
            aOrbiterC = RotL64((aOrbiterC * 8752188637514143529U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 13754328481584620771U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 3684673342659575917U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6139923312873039143U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 6542045150319909445U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 5352102692424060388U;
            aOrbiterG = RotL64((aOrbiterG * 7385758355501860261U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 9110100774657340354U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 2813273684436269057U;
            aOrbiterF = RotL64((aOrbiterF * 10468759062594022273U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 5860425751137403755U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 1598622981888978548U;
            aOrbiterB = RotL64((aOrbiterB * 651816500461718345U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 14710305692377606725U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 16280545617802383463U;
            aOrbiterD = RotL64((aOrbiterD * 12541767206978802063U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 6849565243667718750U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 12152381961996750050U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11185935780063403807U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 1318947876257794796U) + aNonceWordC;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 5447559252769140391U;
            aOrbiterJ = RotL64((aOrbiterJ * 13683733413554766327U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 2766869582494246454U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 15757729967222729304U;
            aOrbiterA = RotL64((aOrbiterA * 1858683399257513171U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 13063432816787882618U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 3650233661228036955U;
            aOrbiterK = RotL64((aOrbiterK * 16230564672533821641U), 37U);
            //
            aIngress = RotL64(aOrbiterF, 47U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterJ, 51U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 12U));
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterC, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 18U)) + aOrbiterF) + aNonceWordD) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 23U) + aOrbiterB) + RotL64(aOrbiterK, 41U)) + RotL64(aCarry, 23U)) + aNonceWordA);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 54U) + RotL64(aOrbiterH, 27U)) + aOrbiterD) + aNonceWordE);
            aWandererG = aWandererG + ((RotL64(aCross, 41U) + RotL64(aOrbiterI, 21U)) + aOrbiterH);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 5U)) + aOrbiterF);
            aWandererK = aWandererK + ((RotL64(aScatter, 39U) + RotL64(aOrbiterG, 29U)) + aOrbiterJ);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterH, 34U)) + aOrbiterG);
            aWandererI = aWandererI + ((RotL64(aCross, 3U) + RotL64(aOrbiterA, 11U)) + aOrbiterH);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 19U) + aOrbiterB) + RotL64(aOrbiterE, 23U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 37U) + aOrbiterC) + RotL64(aOrbiterA, 37U)) + RotL64(aCarry, 47U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterF, 39U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererA, 48U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 14U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ aNonceWordN;
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 8124U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneD[((aIndex + 6995U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6753U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((aIndex + 9177U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aIngress, 51U)) ^ (RotL64(aCross, 24U) ^ RotL64(aPrevious, 37U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = ((aWandererI + RotL64(aIngress, 57U)) + 3199575576585871314U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = (((aWandererG + RotL64(aPrevious, 54U)) + RotL64(aCarry, 57U)) + 2533378188975571824U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aScatter, 13U)) + 6819782112558312658U;
            aOrbiterH = ((aWandererC + RotL64(aCross, 37U)) + RotL64(aCarry, 47U)) + 12690060987724798497U;
            aOrbiterC = (aWandererD + RotL64(aIngress, 23U)) + 7088375139715629606U;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 52U)) + 17785618677423695666U;
            aOrbiterG = (aWandererA + RotL64(aCross, 39U)) + 1714999280296491277U;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 3U)) + 17611338506932491624U) + aNonceWordD;
            aOrbiterB = (aWandererE + RotL64(aPrevious, 27U)) + 6475727359297421201U;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 47U)) + 2347744591204119530U) + aNonceWordE;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 29U)) + RotL64(aCarry, 43U)) + 2739317903351401068U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 8663535261373274338U) + aNonceWordI;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 8205245127823536479U;
            aOrbiterD = RotL64((aOrbiterD * 13857005110466856439U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 8916510616749754516U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 3944805940148512932U;
            aOrbiterI = RotL64((aOrbiterI * 18082271583211389701U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 14094751253118853302U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 14094299829196076311U;
            aOrbiterC = RotL64((aOrbiterC * 6370012560657108493U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 3940673811518673802U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 3015106523254484839U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9655401190755573379U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 15404103131982599922U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 1828655763233900875U;
            aOrbiterB = RotL64((aOrbiterB * 13024358077740310049U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 1236981890899916502U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 18208975564570342697U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4577109989465876801U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 17882273895471449661U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 16196010765612713713U;
            aOrbiterH = RotL64((aOrbiterH * 15624856645134182005U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 14639250100311162559U) + aNonceWordG;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 9139027997336903273U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1853126389565574293U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 16848571995585465845U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 15901000078517800358U;
            aOrbiterJ = RotL64((aOrbiterJ * 11617866400577762383U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 9405166641274108606U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 6776079798531281127U;
            aOrbiterF = RotL64((aOrbiterF * 6914644957401512339U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 15056085197286596847U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 3199575576585871314U) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 15940936753708416817U), 13U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 47U);
            aIngress = aIngress + (RotL64(aOrbiterA, 58U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 37U));
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterB, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aScatter, 23U) + RotL64(aOrbiterD, 51U)) + aOrbiterE);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterG, 58U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 51U) + aOrbiterC) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 41U) + aOrbiterA) + RotL64(aOrbiterG, 41U));
            aWandererG = aWandererG + ((RotL64(aScatter, 44U) + RotL64(aOrbiterA, 5U)) + aOrbiterH);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 46U)) + aOrbiterA);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterG, 43U)) + aOrbiterF) + aNonceWordP) + aPhaseFWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterI, 23U)) + aOrbiterF) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 60U) + RotL64(aOrbiterJ, 19U)) + aOrbiterE) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterA, 35U)) + aOrbiterD);
            aWandererA = aWandererA + ((RotL64(aPrevious, 21U) + aOrbiterK) + RotL64(aOrbiterF, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 58U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 21U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 44U));
            aCarry = aCarry + RotL64(aWandererG, 11U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordB;
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 11254U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneA[((aIndex + 15570U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 12133U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneC[((aIndex + 12062U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 39U)) ^ (RotL64(aCross, 10U) + RotL64(aIngress, 27U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterB = (aWandererK + RotL64(aScatter, 54U)) + 9855743441035905047U;
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 39U)) + RotL64(aCarry, 19U)) + 8426286937143990276U;
            aOrbiterH = ((aWandererF + RotL64(aCross, 41U)) + 7146752367170267002U) + aPhaseFOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 5U)) + RotL64(aCarry, 43U)) + 12947210066678101726U;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 10U)) + 15902163559925328965U) + aPhaseFOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = (aWandererE + RotL64(aCross, 21U)) + 8506649889346449469U;
            aOrbiterF = (aWandererH + RotL64(aIngress, 51U)) + 8226286036430263052U;
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 43U)) + 2703047093452420216U;
            aOrbiterI = ((aWandererA + RotL64(aCross, 19U)) + 6769351326360139560U) + aNonceWordF;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 37U)) + RotL64(aCarry, 53U)) + 9857025533281333281U;
            aOrbiterK = (aWandererI + RotL64(aPrevious, 13U)) + 238297452132277585U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 7203572312072908931U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 12497027346166575632U;
            aOrbiterH = RotL64((aOrbiterH * 1703586436725662307U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 473851890609048879U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 1664484956453886047U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8566500756326590209U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 4635095143004754116U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 17695676150967345793U;
            aOrbiterJ = RotL64((aOrbiterJ * 5780416541584439301U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 15628965269863402796U) + aNonceWordJ;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 9190117464399730235U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5586437438425999715U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 17835918238346011086U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 4398005402429282682U;
            aOrbiterC = RotL64((aOrbiterC * 14828737209913317463U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 10902589938246551273U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 15124274429081385923U;
            aOrbiterG = RotL64((aOrbiterG * 13524180348258805367U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 8747233520702236018U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 5445611443463112371U;
            aOrbiterB = RotL64((aOrbiterB * 10294109295823410447U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 16296005217836151910U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 6468336224317602364U;
            aOrbiterE = RotL64((aOrbiterE * 7369779919748367133U), 37U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterK) + 3827976387089403774U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordM;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 7773383658122100111U;
            aOrbiterF = RotL64((aOrbiterF * 9784711300597525161U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 18273794621528918389U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 8401424792700263455U;
            aOrbiterI = RotL64((aOrbiterI * 13003420427441089595U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 11402828934846813949U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 9855743441035905047U;
            aOrbiterK = RotL64((aOrbiterK * 7339549576423555273U), 27U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterE, 41U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + RotL64(aOrbiterD, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterE, 13U)) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterH, 57U)) + aOrbiterE);
            aWandererH = aWandererH + (((RotL64(aScatter, 37U) + RotL64(aOrbiterK, 35U)) + aOrbiterE) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterB, 60U)) + aOrbiterG);
            aWandererC = aWandererC + ((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterJ, 37U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterC, 19U)) + aOrbiterK) + aNonceWordC);
            aWandererA = aWandererA + ((RotL64(aPrevious, 60U) + aOrbiterI) + RotL64(aOrbiterF, 11U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterF, 29U)) + aOrbiterH) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 51U) + aOrbiterI) + RotL64(aOrbiterA, 23U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterA, 52U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 56U) + RotL64(aOrbiterK, 47U)) + aOrbiterJ) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererE, 6U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 26U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 19965U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((aIndex + 21470U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 18505U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 20435U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 18U) ^ RotL64(aIngress, 57U)) + (RotL64(aCarry, 43U) + RotL64(aPrevious, 5U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = (aWandererE + RotL64(aPrevious, 20U)) + 380024772508948442U;
            aOrbiterK = (aWandererK + RotL64(aIngress, 27U)) + 7649029098162567210U;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 11U)) + RotL64(aCarry, 39U)) + 5329304598870421851U;
            aOrbiterD = ((aWandererH + RotL64(aScatter, 43U)) + 12306118665045151326U) + aNonceWordN;
            aOrbiterG = (aWandererG + RotL64(aIngress, 53U)) + 960751560457324256U;
            aOrbiterC = ((aWandererB + RotL64(aScatter, 29U)) + 3244070254386191876U) + aNonceWordF;
            aOrbiterB = (aWandererI + RotL64(aCross, 51U)) + 15733408571609521746U;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 37U)) + RotL64(aCarry, 21U)) + 17623448932647018544U;
            aOrbiterI = (((aWandererA + RotL64(aIngress, 57U)) + RotL64(aCarry, 27U)) + 8787759896149035829U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = (aWandererC + RotL64(aPrevious, 39U)) + 14741681792348288162U;
            aOrbiterF = ((aWandererD + RotL64(aCross, 4U)) + 8801731213568307302U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 9872248187499779222U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 15407371518644528235U;
            aOrbiterJ = RotL64((aOrbiterJ * 1245102406469471673U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 4242060317152943062U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 9942784962409917541U;
            aOrbiterG = RotL64((aOrbiterG * 888649755587764533U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 7296348796484458631U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 15061417216070157797U;
            aOrbiterC = RotL64((aOrbiterC * 10349554676953256231U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 3233185810644297433U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 9241229457641024287U;
            aOrbiterB = RotL64((aOrbiterB * 2728237515724597517U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 8464051359381554575U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 3307872165699029375U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4859663401033023433U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 5482617843966711997U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 4442149210462943872U) ^ aNonceWordB;
            aOrbiterI = RotL64((aOrbiterI * 8979352218576515647U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 10591636597580147381U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 14925122230279312217U;
            aOrbiterH = RotL64((aOrbiterH * 15038171961638724013U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 9772367878232735350U) + aNonceWordI;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 15800661165607190092U;
            aOrbiterF = RotL64((aOrbiterF * 10493976952980533589U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 1571665862499272194U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 3162847040693387901U;
            aOrbiterE = RotL64((aOrbiterE * 2747235335326991399U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 4868791925868749848U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 13134549226315884613U;
            aOrbiterK = RotL64((aOrbiterK * 3551955270718495869U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 7830447320021657240U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 380024772508948442U;
            aOrbiterD = RotL64((aOrbiterD * 5143324968958616357U), 43U);
            //
            aIngress = RotL64(aOrbiterH, 12U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 19U));
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterG, 39U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterC, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterG, 47U)) + aOrbiterF);
            aWandererJ = aWandererJ + (((RotL64(aCross, 21U) + aOrbiterE) + RotL64(aOrbiterG, 18U)) + RotL64(aCarry, 29U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 23U) + aOrbiterI) + RotL64(aOrbiterK, 27U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 14U) + aOrbiterA) + RotL64(aOrbiterD, 21U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 27U) + aOrbiterD) + RotL64(aOrbiterH, 5U));
            aWandererI = aWandererI + ((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterK, 57U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 37U) + aOrbiterJ) + RotL64(aOrbiterD, 37U)) + aPhaseFWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterC, 11U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterG, 54U)) + aOrbiterA);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 10U) + RotL64(aOrbiterA, 51U)) + aOrbiterB) + RotL64(aCarry, 19U)) + aNonceWordD);
            aWandererK = aWandererK ^ (((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterA, 39U)) + aPhaseFWandererUpdateSaltF[((aIndex + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 48U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererC, 54U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 24509U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((aIndex + 25676U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 25961U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25408U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aIngress, 44U)) + (RotL64(aCross, 23U) ^ RotL64(aPrevious, 11U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = (aWandererH + RotL64(aPrevious, 18U)) + 12849591986267890852U;
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 53U)) + RotL64(aCarry, 3U)) + 8232614804696815750U;
            aOrbiterG = ((aWandererK + RotL64(aCross, 35U)) + 12141567259210877281U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (aWandererF + RotL64(aIngress, 23U)) + 2928641981037885644U;
            aOrbiterB = (aWandererD + RotL64(aScatter, 37U)) + 980733350554783938U;
            aOrbiterD = (aWandererE + RotL64(aPrevious, 27U)) + 2683985177993350746U;
            aOrbiterK = (aWandererB + RotL64(aIngress, 51U)) + 14532148403815527355U;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 29U)) + 7736296629433884203U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = (aWandererI + RotL64(aIngress, 39U)) + 10428437770166310549U;
            aOrbiterA = (((aWandererA + RotL64(aPrevious, 3U)) + RotL64(aCarry, 13U)) + 18327174144859461029U) + aNonceWordP;
            aOrbiterE = (((aWandererG + RotL64(aCross, 12U)) + RotL64(aCarry, 53U)) + 6810436935194432002U) + aNonceWordN;
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 12606153309690753435U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 17123256945895150555U;
            aOrbiterG = RotL64((aOrbiterG * 13469111258504672565U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 9057777759026189541U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 16478485918911194442U;
            aOrbiterD = RotL64((aOrbiterD * 11054247078884894131U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 18064460487552100483U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 11477276762421684083U;
            aOrbiterJ = RotL64((aOrbiterJ * 3886501230380184395U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 18318375441973295081U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 13849305985380030986U;
            aOrbiterA = RotL64((aOrbiterA * 12962140243967824959U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 10240409420338313641U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 18360586077779529086U;
            aOrbiterC = RotL64((aOrbiterC * 18196875422391501927U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 16801797158622424257U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 4950305991208513887U;
            aOrbiterF = RotL64((aOrbiterF * 4437082499761416951U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 15790878572843321918U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 9808781805065559728U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9394280083159162953U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 11974996650410830731U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 4955004489435232515U;
            aOrbiterI = RotL64((aOrbiterI * 13301966529515483085U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 1187569634223338864U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 5351017164244226367U) ^ aNonceWordH;
            aOrbiterE = RotL64((aOrbiterE * 14735674576470803699U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 9587142385246940125U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 16253850371962732943U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3408021872390904463U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 14990060157351237661U) + aNonceWordE;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 12849591986267890852U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2158106726261981983U), 5U);
            //
            aIngress = RotL64(aOrbiterF, 35U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterC, 54U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 34U) + RotL64(aOrbiterJ, 39U)) + aOrbiterI);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 57U) + aOrbiterF) + RotL64(aOrbiterK, 37U)) + aNonceWordJ);
            aWandererH = aWandererH ^ (((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterC, 29U)) + aNonceWordK);
            aWandererI = aWandererI + ((((RotL64(aIngress, 41U) + aOrbiterB) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 13U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterE, 43U)) + aOrbiterI);
            aWandererE = aWandererE + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterG, 5U)) + aOrbiterF);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterJ, 60U)) + aNonceWordF);
            aWandererA = aWandererA + ((RotL64(aScatter, 60U) + aOrbiterD) + RotL64(aOrbiterI, 13U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterA, 21U)) + aOrbiterB) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 5U) + RotL64(aOrbiterH, 23U)) + aOrbiterB) + RotL64(aCarry, 35U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterA, 50U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererE, 20U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 46U));
            aCarry = aCarry + RotL64(aWandererH, 43U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordL;
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30424U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29467U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29516U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30864U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aIngress, 54U)) + (RotL64(aPrevious, 29U) ^ RotL64(aCarry, 3U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 39U)) + 1364174714924216027U) + aNonceWordN;
            aOrbiterC = ((aWandererE + RotL64(aCross, 27U)) + 13561796874229506613U) + aNonceWordH;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 35U)) + RotL64(aCarry, 23U)) + 11845572344206238305U;
            aOrbiterB = (aWandererA + RotL64(aIngress, 18U)) + 15762708240326773763U;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 47U)) + 1157119665207900473U;
            aOrbiterF = (aWandererK + RotL64(aScatter, 13U)) + 6823546624372055260U;
            aOrbiterD = (((aWandererJ + RotL64(aIngress, 29U)) + 14465564210523945121U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordM;
            aOrbiterJ = (aWandererG + RotL64(aCross, 5U)) + 10667464548080807531U;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 37U)) + 13445737493224316575U;
            aOrbiterH = (((aWandererD + RotL64(aIngress, 43U)) + RotL64(aCarry, 11U)) + 3009837893785957665U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = ((aWandererH + RotL64(aCross, 24U)) + RotL64(aCarry, 5U)) + 2886920524111083752U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 10886177449328249656U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 15067759884678100433U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 5724566815989860041U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 18307930462682331536U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 8791864377579255801U;
            aOrbiterE = RotL64((aOrbiterE * 9265158882471421767U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 805797468642992351U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 5743305867058244964U;
            aOrbiterF = RotL64((aOrbiterF * 16263000753351131717U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 17102025528234481273U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 1841579177327486899U;
            aOrbiterD = RotL64((aOrbiterD * 3841603385577825265U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 2189493507896508972U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 18209567010094914374U;
            aOrbiterJ = RotL64((aOrbiterJ * 3737080408976852351U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 6697069234216868330U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 927471474577415372U) ^ aNonceWordK;
            aOrbiterK = RotL64((aOrbiterK * 10680760991009199309U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 13155854301197725408U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 1014625081915435892U;
            aOrbiterH = RotL64((aOrbiterH * 11592754232949990435U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 12697209921410914931U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 11555096613655648647U;
            aOrbiterG = RotL64((aOrbiterG * 4598821388864997089U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 9335308231651271690U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 3160859883353473444U;
            aOrbiterI = RotL64((aOrbiterI * 4753600703924906409U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 15681189182414315768U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterH) ^ 3147692210581710663U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterC = RotL64((aOrbiterC * 6271949093080510861U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 5373388632562432117U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 1364174714924216027U;
            aOrbiterB = RotL64((aOrbiterB * 4694926665965807945U), 41U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterI, 47U);
            aIngress = aIngress + (RotL64(aOrbiterD, 36U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterF, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 51U) + aOrbiterA) + RotL64(aOrbiterK, 3U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 37U) + aOrbiterD) + RotL64(aOrbiterH, 41U)) + aNonceWordJ);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterJ, 35U)) + aOrbiterC);
            aWandererK = aWandererK + (((RotL64(aIngress, 20U) + aOrbiterI) + RotL64(aOrbiterJ, 43U)) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 41U) + aOrbiterF) + RotL64(aOrbiterK, 11U)) + aPhaseFWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterK, 29U)) + aOrbiterE) + aPhaseFWandererUpdateSaltD[((aIndex + 6U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 39U) + aOrbiterG) + RotL64(aOrbiterJ, 58U));
            aWandererF = aWandererF + ((RotL64(aScatter, 43U) + aOrbiterA) + RotL64(aOrbiterG, 19U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 5U) + aOrbiterC) + RotL64(aOrbiterD, 23U)) + aNonceWordG);
            aWandererI = aWandererI + (((RotL64(aScatter, 24U) + aOrbiterB) + RotL64(aOrbiterK, 13U)) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterA, 6U)) + aOrbiterE) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 24U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordH);
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 5885U)) & S_BLOCK1], 51U) ^ RotL64(aKeyRowReadA[((aIndex + 3181U)) & W_KEY1], 14U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 68U)) & W_KEY1], 52U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 3388U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCross, 40U)) ^ (RotL64(aPrevious, 3U) + RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = (aWandererI + RotL64(aScatter, 47U)) + 13960289014350612206U;
            aOrbiterB = (aWandererJ + RotL64(aCross, 51U)) + 3483331015269589730U;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 23U)) + 6873299241002444518U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 18U)) + RotL64(aCarry, 3U)) + 3562094007125534229U;
            aOrbiterF = (aWandererF + RotL64(aCross, 27U)) + 11422367439932782705U;
            aOrbiterE = (((aWandererE + RotL64(aScatter, 11U)) + RotL64(aCarry, 29U)) + 532453428514259816U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = (aWandererB + RotL64(aIngress, 39U)) + 17810941465810193088U;
            aOrbiterH = (((aWandererH + RotL64(aPrevious, 35U)) + RotL64(aCarry, 47U)) + 11869759058631106331U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (aWandererA + RotL64(aScatter, 58U)) + 8837581071876177566U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 17185378327053837778U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 7578253375676981500U;
            aOrbiterC = RotL64((aOrbiterC * 13371647568758721729U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 17112646434432814442U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 14949096407295697881U;
            aOrbiterE = RotL64((aOrbiterE * 14770977858283051753U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 4259590620758467836U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 6534899413644542303U;
            aOrbiterH = RotL64((aOrbiterH * 7987609419215568661U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 2637407498893694243U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 15819295597921425711U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5202015597375051399U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 6373559542002699718U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 11694562937392022505U;
            aOrbiterD = RotL64((aOrbiterD * 9311557972331218597U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 3308736483775453062U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 12749929710650475901U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 248428400724560945U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 1569528215675579656U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 1044077933631689572U;
            aOrbiterG = RotL64((aOrbiterG * 6443796233912755143U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 8393422728124537471U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 2002732612516530754U;
            aOrbiterB = RotL64((aOrbiterB * 13702146823622364279U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 13469191942843147943U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 7633171368709520560U;
            aOrbiterF = RotL64((aOrbiterF * 9713514012478203047U), 11U);
            //
            aIngress = RotL64(aOrbiterI, 47U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 14U));
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterE, 37U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 39U) + aOrbiterI) + RotL64(aOrbiterE, 23U)) + aPhaseCWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 60U) + aOrbiterB) + RotL64(aOrbiterD, 50U));
            aWandererH = aWandererH + ((RotL64(aIngress, 51U) + RotL64(aOrbiterH, 29U)) + aOrbiterE);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 43U) + aOrbiterD) + RotL64(aOrbiterC, 39U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterG, 35U)) + aOrbiterC) + RotL64(aCarry, 35U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterB, 5U)) + aOrbiterF);
            aWandererG = aWandererG + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterH, 19U)) + aOrbiterD) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 6U) + aOrbiterB) + RotL64(aOrbiterK, 43U));
            aWandererA = aWandererA + ((RotL64(aCross, 29U) + RotL64(aOrbiterH, 58U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererI, 60U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 39U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 16140U)) & S_BLOCK1], 22U) ^ RotL64(mSource[((aIndex + 8412U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 14295U)) & W_KEY1], 58U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 15452U)) & W_KEY1], 13U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 10U) ^ RotL64(aIngress, 47U)) + (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = (aWandererE + RotL64(aIngress, 23U)) + 7075016829833562104U;
            aOrbiterB = (aWandererJ + RotL64(aScatter, 19U)) + 8783765886115517036U;
            aOrbiterK = (aWandererC + RotL64(aCross, 12U)) + 2996723892384565829U;
            aOrbiterA = (((aWandererH + RotL64(aPrevious, 27U)) + RotL64(aCarry, 39U)) + 9494134707342189476U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = ((aWandererA + RotL64(aScatter, 37U)) + 5052642981395679904U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (aWandererF + RotL64(aPrevious, 41U)) + 8766787055127962238U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 48U)) + RotL64(aCarry, 3U)) + 4467211954388738079U;
            aOrbiterE = ((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 13U)) + 8030255604633658608U;
            aOrbiterG = (aWandererD + RotL64(aIngress, 5U)) + 16962408063455702251U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 3768222186567699076U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 14930990410207899871U;
            aOrbiterK = RotL64((aOrbiterK * 10930005786146268241U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 14179761938395502502U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 1879084742719898108U;
            aOrbiterH = RotL64((aOrbiterH * 16783034788172670121U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 5535012408925981515U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 12792553516710295939U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8577530993755159329U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 8979253163346099252U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 5559189896063990740U;
            aOrbiterE = RotL64((aOrbiterE * 8832485423727331621U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 13937564337299044079U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 2393376759689394948U;
            aOrbiterG = RotL64((aOrbiterG * 2352815657830413941U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 12647519563697356479U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 10946871249960389549U;
            aOrbiterI = RotL64((aOrbiterI * 6272580371881237173U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 13376798695582123147U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 10958115913599631271U;
            aOrbiterA = RotL64((aOrbiterA * 18233981473003345217U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 4283914227806672773U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 910842005516235816U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6722229871617873429U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 1509644316619370324U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 165987596716078174U;
            aOrbiterB = RotL64((aOrbiterB * 13600064054240185123U), 29U);
            //
            aIngress = RotL64(aOrbiterC, 29U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterG, 60U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterE, 51U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterF, 14U)) + aOrbiterI);
            aWandererK = aWandererK + ((RotL64(aScatter, 23U) + aOrbiterH) + RotL64(aOrbiterC, 27U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterG, 19U));
            aWandererD = aWandererD + ((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterG, 39U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 48U) + RotL64(aOrbiterK, 3U)) + aOrbiterG) + aPhaseCWandererUpdateSaltA[((aIndex + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 41U) + RotL64(aOrbiterB, 35U)) + aOrbiterH) + RotL64(aCarry, 3U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 43U)) + aOrbiterF);
            aWandererC = aWandererC + (((RotL64(aCross, 29U) + aOrbiterE) + RotL64(aOrbiterB, 10U)) + RotL64(aCarry, 27U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 12U) + RotL64(aOrbiterC, 47U)) + aOrbiterG) + aPhaseCWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 60U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 21U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 24216U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneA[((aIndex + 19759U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 17803U)) & W_KEY1], 39U) ^ RotL64(aKeyRowReadB[((aIndex + 19066U)) & W_KEY1], 24U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 44U) ^ RotL64(aIngress, 11U)) + (RotL64(aPrevious, 27U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (((aWandererE + RotL64(aIngress, 3U)) + RotL64(aCarry, 41U)) + 17019646486641172469U) + aPhaseCOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 18U)) + 12276141179299971572U;
            aOrbiterK = (aWandererK + RotL64(aScatter, 13U)) + 3617241694029841555U;
            aOrbiterE = (((aWandererA + RotL64(aCross, 37U)) + RotL64(aCarry, 53U)) + 6967963401259371737U) + aPhaseCOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aIngress, 41U)) + 6340709284279891017U;
            aOrbiterJ = (aWandererF + RotL64(aCross, 47U)) + 456065368903896482U;
            aOrbiterB = (aWandererI + RotL64(aPrevious, 57U)) + 17686765719908116203U;
            aOrbiterC = ((aWandererH + RotL64(aScatter, 52U)) + RotL64(aCarry, 23U)) + 1322045955429785736U;
            aOrbiterH = (aWandererD + RotL64(aPrevious, 29U)) + 5163772703302372887U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 13268431135020363252U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 6538789950366849332U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5352960308459065837U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 10390344544314544893U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 5087084271300584267U;
            aOrbiterD = RotL64((aOrbiterD * 15149302947570776165U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 13423071121590981727U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 18324443012024134729U;
            aOrbiterE = RotL64((aOrbiterE * 15814349432207734533U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 4129091815978464507U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 17024797553831962245U;
            aOrbiterI = RotL64((aOrbiterI * 3137753479364378175U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 6501545108779991661U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 11930037791867597447U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4904739567549702851U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 4667298703308315851U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 6315980380900062127U;
            aOrbiterJ = RotL64((aOrbiterJ * 12080555704907924637U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 12732382340390769888U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 7792095326183864547U;
            aOrbiterB = RotL64((aOrbiterB * 12645556660611824631U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 17428384983571405782U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 3193205313177048443U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14488006565106259731U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 2813743367131107264U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 2742138679703780981U;
            aOrbiterH = RotL64((aOrbiterH * 18356569025783532225U), 23U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterB, 13U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 26U));
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterJ, 11U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterC, 36U)) + aOrbiterA) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 47U) + RotL64(aOrbiterD, 43U)) + aOrbiterA) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 54U) + aOrbiterD) + RotL64(aOrbiterH, 53U));
            aWandererA = aWandererA + ((RotL64(aCross, 37U) + aOrbiterD) + RotL64(aOrbiterE, 29U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterH, 58U)) + aOrbiterB);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 13U) + aOrbiterI) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 5U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 30U) + RotL64(aOrbiterK, 47U)) + aOrbiterB);
            aWandererE = aWandererE + ((RotL64(aPrevious, 23U) + aOrbiterE) + RotL64(aOrbiterI, 19U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 42U));
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + RotL64(aWandererD, 23U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 25141U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((aIndex + 30411U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30137U)) & S_BLOCK1], 40U) ^ RotL64(mSource[((aIndex + 28813U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aPrevious, 23U)) + (RotL64(aCarry, 60U) + RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = (aWandererJ + RotL64(aScatter, 43U)) + 9446153639709651566U;
            aOrbiterE = ((aWandererE + RotL64(aCross, 35U)) + RotL64(aCarry, 53U)) + 10550762260670758167U;
            aOrbiterB = (aWandererF + RotL64(aIngress, 10U)) + 7062634922142578383U;
            aOrbiterI = (aWandererH + RotL64(aPrevious, 3U)) + 9178499097812764515U;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 19U)) + RotL64(aCarry, 11U)) + 6887103379773525538U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 51U)) + RotL64(aCarry, 29U)) + 6239750312052010257U;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 58U)) + 17645022614523287959U;
            aOrbiterA = ((aWandererG + RotL64(aCross, 29U)) + 3639618183259408272U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = ((aWandererB + RotL64(aIngress, 39U)) + 3131737117548745095U) + aPhaseCOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 7253994382396406554U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 15217993711938379561U;
            aOrbiterB = RotL64((aOrbiterB * 17853313384747259923U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 12594152227603630033U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 11250170200489647869U;
            aOrbiterC = RotL64((aOrbiterC * 546800378327864723U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 12936942656624279424U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 10990736056052106149U;
            aOrbiterJ = RotL64((aOrbiterJ * 7123916809953459187U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 12787293075893090465U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 17154990205620778151U;
            aOrbiterK = RotL64((aOrbiterK * 10031369940028159521U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 1270827262969060301U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 17337623431665013136U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1517262088236356107U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 830330490987911853U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 6828309232554560547U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9742464176986145819U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 11470087853413986203U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 10470148870747884420U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6766079738799967443U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 18315536891901859637U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 12264670822285914271U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5841574505408674119U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 10931842095884524879U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 11134871340959676257U;
            aOrbiterE = RotL64((aOrbiterE * 11714837622285605745U), 29U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 10U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 37U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterI, 58U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 47U)) + aOrbiterE) + RotL64(aCarry, 27U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 13U)) + aOrbiterK) + aPhaseCWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 6U) + RotL64(aOrbiterI, 27U)) + aOrbiterH) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterG, 37U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterE, 19U)) + aOrbiterI) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 43U) + aOrbiterK) + RotL64(aOrbiterG, 3U));
            aWandererH = aWandererH + ((RotL64(aScatter, 54U) + aOrbiterE) + RotL64(aOrbiterK, 42U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 19U) + aOrbiterE) + RotL64(aOrbiterJ, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 6U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + RotL64(aWandererB, 23U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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

    std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 4585U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7489U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 350U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 7982U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 6U) + RotL64(aCross, 35U)) ^ (RotL64(aCarry, 53U) + RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (((aWandererH + RotL64(aCross, 3U)) + RotL64(aCarry, 19U)) + 4622023259121087483U) + aPhaseDOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aIngress, 37U)) + 10253505250223501352U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 47U)) + RotL64(aCarry, 51U)) + 17133877904420462669U;
            aOrbiterH = (((aWandererC + RotL64(aScatter, 57U)) + RotL64(aCarry, 3U)) + 6162827793741796700U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aIngress, 26U)) + 9610986424765907615U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 11210747154264753754U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 16554205219580654546U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12754735039924859911U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 10352576357413766388U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 3651845783283479752U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1011289824180799641U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 18145542190463500476U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 5415609566767162857U;
            aOrbiterH = RotL64((aOrbiterH * 6474184559323816389U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 2033734872464201570U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 3507213117125813345U;
            aOrbiterE = RotL64((aOrbiterE * 5453058336688881113U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 8716253393049851856U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 695984869565941856U;
            aOrbiterK = RotL64((aOrbiterK * 8377921610764044735U), 35U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 13U);
            aIngress = aIngress + (RotL64(aOrbiterI, 54U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aCross, 27U) + aOrbiterE) + RotL64(aOrbiterH, 23U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 39U) + aOrbiterH) + RotL64(aOrbiterF, 5U));
            aWandererC = aWandererC + (((RotL64(aIngress, 48U) + aOrbiterI) + RotL64(aOrbiterK, 44U)) + RotL64(aCarry, 3U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 11U) + aOrbiterF) + RotL64(aOrbiterK, 57U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 35U)) + aOrbiterE) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 27U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 15673U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11851U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9090U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneB[((aIndex + 14341U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 50U)) ^ (RotL64(aCarry, 35U) + RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = (((aWandererE + RotL64(aScatter, 5U)) + RotL64(aCarry, 35U)) + 5173905450211892891U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = (aWandererD + RotL64(aCross, 22U)) + 3555542451908039957U;
            aOrbiterD = ((aWandererH + RotL64(aIngress, 37U)) + RotL64(aCarry, 3U)) + 11559884700283861559U;
            aOrbiterF = (((aWandererA + RotL64(aPrevious, 13U)) + RotL64(aCarry, 53U)) + 1352524329968738673U) + aPhaseDOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = (aWandererG + RotL64(aScatter, 51U)) + 8914206450420616349U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 2251523378498463946U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 9541575923299247038U;
            aOrbiterD = RotL64((aOrbiterD * 1066487482799638689U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 1239854507907214595U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 17698101462598498934U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2304948713665996433U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 12305566971683256060U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 13804545036303215569U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10359543704152744971U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 10239749097704329264U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 4212214906286320308U;
            aOrbiterH = RotL64((aOrbiterH * 3661436621615751071U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 12192418916967430783U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 4475514289326450361U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17497164630368757887U), 51U);
            //
            aIngress = RotL64(aOrbiterD, 3U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterF, 29U)) + aOrbiterD) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 56U) + aOrbiterH) + RotL64(aOrbiterF, 51U)) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterC, 41U));
            aWandererG = aWandererG + (((RotL64(aIngress, 35U) + RotL64(aOrbiterC, 18U)) + aOrbiterH) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 3U)) + aOrbiterD) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererG, 23U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 24253U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19088U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21049U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((aIndex + 17639U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 37U) + RotL64(aCross, 51U)) ^ (RotL64(aCarry, 5U) + RotL64(aPrevious, 22U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = (aWandererC + RotL64(aPrevious, 3U)) + 1866656689936219099U;
            aOrbiterH = (((aWandererJ + RotL64(aScatter, 46U)) + RotL64(aCarry, 29U)) + 2312314528139448289U) + aPhaseDOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = ((aWandererD + RotL64(aCross, 27U)) + RotL64(aCarry, 43U)) + 3554037526469185237U;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 13U)) + RotL64(aCarry, 13U)) + 405707755060974111U;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 37U)) + 1862976326004007697U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 12992483065443288263U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 3793854946371595197U;
            aOrbiterE = RotL64((aOrbiterE * 1819119223110966487U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 4244007978867369382U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 10280867500312580308U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13729899124177931289U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 472563452959164242U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 12041770406895816553U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17811798500132002631U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 6118634015704900486U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 13637107920449233307U;
            aOrbiterD = RotL64((aOrbiterD * 17712028184714868053U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 16673735670669318830U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 8602681273646630496U;
            aOrbiterB = RotL64((aOrbiterB * 6995213887710749241U), 29U);
            //
            aIngress = RotL64(aOrbiterB, 5U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + RotL64(aOrbiterH, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 26U) + RotL64(aOrbiterB, 19U)) + aOrbiterE) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterF, 43U)) + aOrbiterD);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterD, 51U)) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterH, 27U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterH, 4U)) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + RotL64(aWandererJ, 39U);
            aCarry = aCarry + RotL64(aIngress, 58U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 31637U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 25229U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30843U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneD[((aIndex + 30553U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aPrevious, 5U)) + (RotL64(aCarry, 50U) ^ RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = ((aWandererG + RotL64(aCross, 28U)) + RotL64(aCarry, 21U)) + 2571116506511057880U;
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 41U)) + 13112435411509707292U) + aPhaseDOrbiterAssignSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 13U)) + RotL64(aCarry, 39U)) + 10403251762787357256U;
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 57U)) + 8461951095541400405U) + aPhaseDOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 3U)) + RotL64(aCarry, 5U)) + 9890793478557463815U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 3030229465991783707U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 7273848154043719247U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17562254601517935669U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 10681774862516028276U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 7105082755586853104U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12217705329504230357U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 6588579345319551129U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 14616333550242386092U;
            aOrbiterJ = RotL64((aOrbiterJ * 2934574715879306337U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 15439666290229654921U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 3360304356760164799U;
            aOrbiterK = RotL64((aOrbiterK * 5164191920584106237U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 14438730801970761889U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 14515616787452085729U;
            aOrbiterG = RotL64((aOrbiterG * 2041601927968559821U), 35U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 19U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterB, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aCross, 29U) + RotL64(aOrbiterH, 52U)) + aOrbiterJ) + RotL64(aCarry, 19U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 18U) + RotL64(aOrbiterG, 29U)) + aOrbiterB);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 37U) + aOrbiterG) + RotL64(aOrbiterJ, 21U)) + RotL64(aCarry, 43U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterB, 13U)) + aOrbiterJ);
            aWandererE = aWandererE + ((RotL64(aScatter, 53U) + aOrbiterB) + RotL64(aOrbiterK, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererG, 13U);
            aCarry = aCarry + RotL64(aIngress, 44U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 2888U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneC[((aIndex + 7475U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 1476U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 6163U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 54U) ^ RotL64(aPrevious, 3U)) + (RotL64(aIngress, 19U) ^ RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = (aWandererA + RotL64(aCross, 35U)) + 9888431329297626900U;
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 5U)) + RotL64(aCarry, 23U)) + 2937735167534624403U;
            aOrbiterG = (aWandererE + RotL64(aPrevious, 19U)) + 17626022970343789617U;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 58U)) + 5665660859333693743U) + aPhaseEOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = (aWandererJ + RotL64(aScatter, 47U)) + 1060537034632076669U;
            aOrbiterI = (((aWandererK + RotL64(aPrevious, 29U)) + RotL64(aCarry, 43U)) + 743777763907175800U) + aPhaseEOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = ((aWandererD + RotL64(aCross, 41U)) + RotL64(aCarry, 3U)) + 5744905970181808845U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 3545351394494002180U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 4877547088414106007U;
            aOrbiterG = RotL64((aOrbiterG * 5416792889338547109U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 11669378338379598445U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 2961072441706158212U;
            aOrbiterC = RotL64((aOrbiterC * 2677988507090705371U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 13984945589234919765U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 1433097875470903205U;
            aOrbiterI = RotL64((aOrbiterI * 451996840039906781U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 716415411025451152U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 8542286150858297810U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9139015340823332449U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 12932391786479661299U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 14005503313299177013U;
            aOrbiterF = RotL64((aOrbiterF * 802663466907819743U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 9382792812676318046U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 5138554251079724724U;
            aOrbiterA = RotL64((aOrbiterA * 6386016499265056247U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 8522380066269546172U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 11825536408101906458U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17042837108792016849U), 43U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterF, 5U);
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterG, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 56U) + RotL64(aOrbiterI, 53U)) + aOrbiterF);
            aWandererK = aWandererK + ((((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterJ, 41U)) + RotL64(aCarry, 23U)) + aPhaseEWandererUpdateSaltC[((aIndex + 28U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterG, 19U)) + aOrbiterA);
            aWandererB = aWandererB + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterA, 47U)) + aOrbiterC) + RotL64(aCarry, 47U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 41U) + aOrbiterC) + RotL64(aOrbiterK, 11U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 11U) + RotL64(aOrbiterJ, 5U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 3U) + aOrbiterF) + RotL64(aOrbiterC, 34U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 48U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 15756U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 14403U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 10584U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((aIndex + 12706U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aIngress, 5U)) + (RotL64(aCarry, 20U) ^ RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 5U)) + 18144572925667544139U) + aPhaseEOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = (aWandererK + RotL64(aScatter, 47U)) + 5659758077574059728U;
            aOrbiterG = ((aWandererA + RotL64(aCross, 35U)) + RotL64(aCarry, 21U)) + 6343330616999166392U;
            aOrbiterD = (((aWandererF + RotL64(aPrevious, 27U)) + RotL64(aCarry, 51U)) + 17754639838410839447U) + aPhaseEOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = (aWandererE + RotL64(aIngress, 13U)) + 9451843819849581729U;
            aOrbiterK = ((aWandererG + RotL64(aScatter, 57U)) + RotL64(aCarry, 5U)) + 7957854457197462212U;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 20U)) + 1461994799722205010U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 18002214276252170177U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 14689869073147027164U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12242482963989582191U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 3978104368003440293U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 8512135845221335386U;
            aOrbiterA = RotL64((aOrbiterA * 10506667163729414667U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 1477533446382953439U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 2166717790929947990U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6538884492418324461U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 8082437060686606995U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 4363687722464700362U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7199165810993478887U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 15782763348014924206U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 8572509150015960728U;
            aOrbiterJ = RotL64((aOrbiterJ * 3340528604891897779U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 12248271773316742521U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 9602078627638561949U;
            aOrbiterK = RotL64((aOrbiterK * 1860631869877427405U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 17244849374768558859U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 1030743048280579012U;
            aOrbiterI = RotL64((aOrbiterI * 10858949914285817051U), 11U);
            //
            aIngress = RotL64(aOrbiterA, 22U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 5U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + RotL64(aOrbiterD, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 43U) + RotL64(aOrbiterJ, 60U)) + aOrbiterD) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterI, 19U));
            aWandererK = aWandererK + (((RotL64(aIngress, 60U) + RotL64(aOrbiterG, 51U)) + aOrbiterK) + aPhaseEWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 37U) + aOrbiterA) + RotL64(aOrbiterD, 35U));
            aWandererE = aWandererE + (((RotL64(aScatter, 23U) + aOrbiterG) + RotL64(aOrbiterD, 5U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 11U)) + aOrbiterC);
            aWandererD = aWandererD + (((RotL64(aIngress, 29U) + aOrbiterD) + RotL64(aOrbiterC, 41U)) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 41U));
            aCarry = aCarry + (RotL64(aWandererG, 18U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 23491U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19956U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 19638U)) & S_BLOCK1], 28U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 20720U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 52U) + RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = (aWandererC + RotL64(aCross, 47U)) + 12775735908960052604U;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 27U)) + 11791373812080296887U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = ((aWandererE + RotL64(aIngress, 56U)) + RotL64(aCarry, 53U)) + 5537362877706057303U;
            aOrbiterG = (aWandererK + RotL64(aScatter, 5U)) + 2023912048504189380U;
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 41U)) + RotL64(aCarry, 37U)) + 17668828109963766893U;
            aOrbiterE = (((aWandererJ + RotL64(aCross, 35U)) + RotL64(aCarry, 13U)) + 558908629933941224U) + aPhaseEOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aScatter, 11U)) + 1479633119685446888U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 15460320397843364063U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 10059749397555469054U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8671817118586065469U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 9987633811929693924U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 10087337844580228269U;
            aOrbiterI = RotL64((aOrbiterI * 13817142288940843815U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 4446204415503364254U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 15106063243302192717U;
            aOrbiterA = RotL64((aOrbiterA * 13273756657334709803U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 9430197906134676162U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 1226048679997253363U;
            aOrbiterG = RotL64((aOrbiterG * 14247538885252664127U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 10611580584157624739U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 3137391249289641509U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5462682413239873181U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 9327201928815412810U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 7890659377013147073U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13827717178378062047U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 10675114832750356941U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 8804440385852327267U;
            aOrbiterB = RotL64((aOrbiterB * 8520671775587260601U), 51U);
            //
            aIngress = RotL64(aOrbiterE, 11U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + (RotL64(aOrbiterK, 42U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 11U) + aOrbiterK) + RotL64(aOrbiterB, 60U));
            aWandererC = aWandererC + ((RotL64(aCross, 40U) + RotL64(aOrbiterA, 53U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterA, 41U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 19U) + aOrbiterE) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 29U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterB, 13U)) + aOrbiterI) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 47U) + aOrbiterI) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 13U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 19U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (RotL64(aWandererJ, 18U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 51U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 26338U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27919U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28616U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneD[((aIndex + 28563U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aIngress, 57U)) + (RotL64(aPrevious, 41U) + RotL64(aCarry, 28U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = ((aWandererD + RotL64(aIngress, 21U)) + RotL64(aCarry, 41U)) + 7075016829833562104U;
            aOrbiterI = (aWandererA + RotL64(aPrevious, 35U)) + 8783765886115517036U;
            aOrbiterC = (((aWandererI + RotL64(aCross, 11U)) + RotL64(aCarry, 29U)) + 2996723892384565829U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = (aWandererF + RotL64(aScatter, 41U)) + 9494134707342189476U;
            aOrbiterH = (aWandererE + RotL64(aCross, 47U)) + 5052642981395679904U;
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 4U)) + RotL64(aCarry, 57U)) + 8766787055127962238U;
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 27U)) + 4467211954388738079U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 8030255604633658608U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 16962408063455702251U;
            aOrbiterC = RotL64((aOrbiterC * 11171737929747471631U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 3768222186567699076U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 14930990410207899871U;
            aOrbiterF = RotL64((aOrbiterF * 10930005786146268241U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 14179761938395502502U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 1879084742719898108U;
            aOrbiterI = RotL64((aOrbiterI * 16783034788172670121U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 5535012408925981515U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 12792553516710295939U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8577530993755159329U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 8979253163346099252U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 5559189896063990740U;
            aOrbiterE = RotL64((aOrbiterE * 8832485423727331621U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 13937564337299044079U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 2393376759689394948U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2352815657830413941U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 12647519563697356479U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 10946871249960389549U;
            aOrbiterA = RotL64((aOrbiterA * 6272580371881237173U), 19U);
            //
            aIngress = RotL64(aOrbiterA, 58U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 56U) + aOrbiterI) + RotL64(aOrbiterC, 29U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterG, 43U)) + aOrbiterF) + aPhaseEWandererUpdateSaltB[((aIndex + 20U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 37U) + RotL64(aOrbiterI, 5U)) + aOrbiterH);
            aWandererF = aWandererF ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterA, 14U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterC, 53U)) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterH, 35U)) + aOrbiterG);
            aWandererD = aWandererD + ((((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterE, 21U)) + RotL64(aCarry, 5U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 12U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + RotL64(aWandererE, 43U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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

void TwistExpander_Golf_Arx::Twist_D(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterE = 0;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 8171U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4388U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1722U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneA[((aIndex + 503U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 4U) ^ RotL64(aCarry, 41U)) + (RotL64(aIngress, 29U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = (((aWandererC + RotL64(aPrevious, 11U)) + RotL64(aCarry, 21U)) + 3238389262925516513U) + aPhaseFOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 51U)) + RotL64(aCarry, 51U)) + 12381787182611386995U;
            aOrbiterE = (((aWandererG + RotL64(aIngress, 24U)) + RotL64(aCarry, 39U)) + 7883885539305181549U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = (aWandererF + RotL64(aCross, 43U)) + 1185413044597727092U;
            aOrbiterA = (aWandererH + RotL64(aPrevious, 35U)) + 15219353497204773135U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 7533774715626734082U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 2599930450937763464U;
            aOrbiterE = RotL64((aOrbiterE * 13207380361960949159U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 16074720663961214284U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 15483613196360051221U;
            aOrbiterJ = RotL64((aOrbiterJ * 11717479088020532861U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 9396557867081376268U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 9668459976852660245U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11748505665890567063U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 9037269914643207212U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 16936742640861088240U;
            aOrbiterH = RotL64((aOrbiterH * 1040172193161012227U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 16481274825758546398U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 481851372837611166U;
            aOrbiterA = RotL64((aOrbiterA * 2225030139210599207U), 27U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterE, 29U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 19U));
            aIngress = aIngress + RotL64(aOrbiterJ, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 24U) + RotL64(aOrbiterK, 5U)) + aOrbiterH);
            aWandererH = aWandererH + (((RotL64(aCross, 13U) + RotL64(aOrbiterK, 43U)) + aOrbiterJ) + RotL64(aCarry, 35U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterK, 27U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 41U) + RotL64(aOrbiterA, 13U)) + aOrbiterE) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 57U) + aOrbiterE) + RotL64(aOrbiterJ, 56U)) + aPhaseFWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 46U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 35U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 12225U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((aIndex + 8251U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14365U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 12928U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCross, 57U)) + (RotL64(aCarry, 26U) ^ RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 57U)) + RotL64(aCarry, 27U)) + 6243113109470883144U;
            aOrbiterC = ((aWandererF + RotL64(aCross, 29U)) + RotL64(aCarry, 57U)) + 3891552123999605832U;
            aOrbiterB = (((aWandererB + RotL64(aPrevious, 6U)) + RotL64(aCarry, 39U)) + 8758797898587019128U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = (aWandererI + RotL64(aIngress, 39U)) + 1005891374086408851U;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 47U)) + 3713426782180050764U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 18358143862391573534U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 17504394029693712404U;
            aOrbiterB = RotL64((aOrbiterB * 3391716204095092531U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 5312729289027417014U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 2560873623431186029U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16843728573219210173U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 16309322822806704211U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 10195513918020652600U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14569219741824123715U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 2552116263258744287U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 7732784879810980089U;
            aOrbiterC = RotL64((aOrbiterC * 15041929399477790999U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 16499127570665381507U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 10890036715535519036U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9065115450010475187U), 13U);
            //
            aIngress = RotL64(aOrbiterB, 47U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterB, 3U)) + aOrbiterA) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 35U) + RotL64(aOrbiterJ, 42U)) + aOrbiterC) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 6U) + RotL64(aOrbiterC, 19U)) + aOrbiterG);
            aWandererB = aWandererB + (((RotL64(aPrevious, 27U) + aOrbiterB) + RotL64(aOrbiterG, 11U)) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 27U)) + aOrbiterB) + aPhaseFWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererJ, 39U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 17324U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((aIndex + 18372U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 24075U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneC[((aIndex + 21385U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCross, 39U)) ^ (RotL64(aIngress, 5U) + RotL64(aCarry, 26U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = ((aWandererF + RotL64(aCross, 11U)) + RotL64(aCarry, 37U)) + 17019646486641172469U;
            aOrbiterK = (((aWandererI + RotL64(aPrevious, 3U)) + RotL64(aCarry, 13U)) + 12276141179299971572U) + aPhaseFOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = (aWandererD + RotL64(aScatter, 43U)) + 3617241694029841555U;
            aOrbiterA = (((aWandererC + RotL64(aIngress, 52U)) + RotL64(aCarry, 51U)) + 6967963401259371737U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aPrevious, 19U)) + 6340709284279891017U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 456065368903896482U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 17686765719908116203U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4451942512173336609U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 1322045955429785736U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 5163772703302372887U;
            aOrbiterK = RotL64((aOrbiterK * 3193272189179082313U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 13268431135020363252U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 6538789950366849332U;
            aOrbiterC = RotL64((aOrbiterC * 5352960308459065837U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 10390344544314544893U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 5087084271300584267U;
            aOrbiterA = RotL64((aOrbiterA * 15149302947570776165U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 13423071121590981727U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 18324443012024134729U;
            aOrbiterH = RotL64((aOrbiterH * 15814349432207734533U), 19U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterF, 37U);
            aIngress = aIngress + (RotL64(aOrbiterK, 52U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 57U) + aOrbiterF) + RotL64(aOrbiterH, 37U)) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterK, 29U)) + aOrbiterC) + aPhaseFWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 29U) + aOrbiterK) + RotL64(aOrbiterF, 11U)) + RotL64(aCarry, 41U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 4U) + aOrbiterA) + RotL64(aOrbiterF, 60U)) + aPhaseFWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 47U) + RotL64(aOrbiterC, 47U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + RotL64(aWandererI, 60U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 32322U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30915U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32346U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 27433U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aPrevious, 19U)) ^ (RotL64(aIngress, 39U) + RotL64(aCross, 52U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 43U)) + RotL64(aCarry, 47U)) + 4970414922752555648U;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 23U)) + RotL64(aCarry, 35U)) + 9462756592787669327U;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 57U)) + 3948790686662213095U) + aPhaseFOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = (((aWandererI + RotL64(aCross, 12U)) + RotL64(aCarry, 5U)) + 14542857212241578311U) + aPhaseFOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 3U)) + 3387479009827029547U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 1411421370057797877U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 16894451466895681236U;
            aOrbiterF = RotL64((aOrbiterF * 13825974818858676215U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 12727136462290223542U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 4625389198191960525U;
            aOrbiterG = RotL64((aOrbiterG * 5726474430977810191U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 3471881403786164913U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 6433115856048534831U;
            aOrbiterB = RotL64((aOrbiterB * 9363233870194144053U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 9825592965466157982U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 1553125767261293088U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 411535191177308781U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 9951616357109647617U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 11231080382787286889U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14024961994986659187U), 37U);
            //
            aIngress = RotL64(aOrbiterC, 14U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aPrevious, 23U) + aOrbiterC) + RotL64(aOrbiterG, 5U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterC, 13U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterG, 30U)) + RotL64(aCarry, 19U)) + aPhaseFWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 37U) + aOrbiterH) + RotL64(aOrbiterF, 57U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 46U) + aOrbiterF) + RotL64(aOrbiterB, 43U)) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + RotL64(aWandererI, 27U);
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterJ = 0;
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 121U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 668U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6231U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 3305U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aIngress, 10U)) + (RotL64(aPrevious, 23U) + RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 57U)) + RotL64(aCarry, 21U)) + 11998579547770778580U;
            aOrbiterH = (((aWandererA + RotL64(aScatter, 41U)) + RotL64(aCarry, 39U)) + 8409465187298704610U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = (aWandererE + RotL64(aCross, 21U)) + 3470222286110333500U;
            aOrbiterA = (aWandererB + RotL64(aIngress, 4U)) + 5704486785203069994U;
            aOrbiterD = (((aWandererD + RotL64(aCross, 13U)) + RotL64(aCarry, 51U)) + 10334944660253279633U) + aPhaseGOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 7626852700722567477U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 14631310754943209743U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1958866541508493967U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 807160297237854120U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 5624154783624196107U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2404066593958052159U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 4971444394698940423U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 6340057638461027062U;
            aOrbiterA = RotL64((aOrbiterA * 12027586111086798629U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 9003019862787819481U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 13632057463595873033U;
            aOrbiterH = RotL64((aOrbiterH * 12575202147280216765U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 12766104026871797746U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 4062118445824915939U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13130770039048080701U), 57U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 5U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 19U) + aOrbiterD) + RotL64(aOrbiterH, 5U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterE, 35U)) + RotL64(aCarry, 27U)) + aPhaseGWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 56U) + aOrbiterA) + RotL64(aOrbiterH, 43U));
            aWandererB = aWandererB + (((RotL64(aIngress, 39U) + RotL64(aOrbiterE, 57U)) + aOrbiterA) + RotL64(aCarry, 47U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 3U) + aOrbiterE) + RotL64(aOrbiterD, 24U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 48U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 8574U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneC[((aIndex + 10356U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 13023U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((aIndex + 10701U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aIngress, 5U)) + (RotL64(aPrevious, 38U) ^ RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = (((aWandererI + RotL64(aCross, 5U)) + RotL64(aCarry, 57U)) + 6024062041314952357U) + aPhaseGOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = ((aWandererC + RotL64(aIngress, 39U)) + RotL64(aCarry, 19U)) + 18340757093658015585U;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 19U)) + RotL64(aCarry, 43U)) + 11911120493880346751U;
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 30U)) + 17428074353884654439U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 53U)) + 12790849760814795936U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 12633397052172117800U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 11946150433665237945U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10324089534873171291U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 16842157900909419285U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 14186235783224155962U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10521157787073684417U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 13284904542579767591U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 11609181965078844357U;
            aOrbiterB = RotL64((aOrbiterB * 5455780554452453513U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 9628562297095374984U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 7850281529011259759U;
            aOrbiterA = RotL64((aOrbiterA * 17611485102925470357U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 257458718073794527U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 10693404545773519306U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14821443722828498323U), 29U);
            //
            aIngress = RotL64(aOrbiterJ, 41U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterB, 37U)) + RotL64(aCarry, 19U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 38U) + aOrbiterA) + RotL64(aOrbiterB, 21U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 23U) + aOrbiterJ) + RotL64(aOrbiterA, 4U)) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterJ, 29U)) + aOrbiterB);
            aWandererI = aWandererI + ((RotL64(aScatter, 13U) + RotL64(aOrbiterG, 51U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 58U));
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 20339U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneD[((aIndex + 19774U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18055U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneB[((aIndex + 20453U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCross, 35U)) ^ (RotL64(aCarry, 51U) + RotL64(aPrevious, 10U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = ((aWandererD + RotL64(aCross, 27U)) + RotL64(aCarry, 19U)) + 2786079456995203065U;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 35U)) + 7237256119153857253U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 11U)) + RotL64(aCarry, 5U)) + 9310834010563647604U;
            aOrbiterG = ((aWandererC + RotL64(aIngress, 47U)) + RotL64(aCarry, 47U)) + 17361734905706517877U;
            aOrbiterK = ((aWandererI + RotL64(aCross, 60U)) + 15837111231884647451U) + aPhaseGOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 18065431964418026445U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 3029123922999952652U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16309219658285890145U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 5166926595573507837U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 1918425684273807598U;
            aOrbiterJ = RotL64((aOrbiterJ * 16616641579714896719U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 4724551751012661440U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 1818014487579644390U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14904092108647864911U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 6670090372241084216U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 8485757110007268693U;
            aOrbiterG = RotL64((aOrbiterG * 11876760095108618363U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 4928130251509514742U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 2528788422725346792U;
            aOrbiterK = RotL64((aOrbiterK * 1855982047967756661U), 13U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterE, 52U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 41U));
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterK, 12U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterE, 21U)) + aOrbiterG) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 48U) + RotL64(aOrbiterK, 3U)) + aOrbiterE) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 41U)) + aOrbiterJ) + RotL64(aCarry, 19U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterF, 51U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 56U));
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererI, 39U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 29044U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneA[((aIndex + 26585U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27220U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 30355U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 54U) + RotL64(aPrevious, 41U)) + (RotL64(aIngress, 13U) ^ RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = ((aWandererE + RotL64(aScatter, 3U)) + RotL64(aCarry, 3U)) + 7632760812370906911U;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 26U)) + RotL64(aCarry, 41U)) + 6007174525479723089U;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 37U)) + 3362829642521821048U) + aPhaseGOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aCross, 13U)) + 18009548556107978286U) + aPhaseGOrbiterAssignSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aIngress, 53U)) + RotL64(aCarry, 29U)) + 17880909432272697327U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 15961567935420752568U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 10136559064656837921U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14473810261421912849U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 17622019364405410277U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 6927494824421416306U;
            aOrbiterG = RotL64((aOrbiterG * 2686290883767829973U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 7125170407794874847U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 12342273503071032250U;
            aOrbiterK = RotL64((aOrbiterK * 867417849555857179U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 14997696377476124836U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 14874498694181230698U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4026127545746010937U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 2549397729130885686U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 4217995818662767955U;
            aOrbiterE = RotL64((aOrbiterE * 5525525344485251063U), 13U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 3U);
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterH, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aScatter, 5U) + aOrbiterK) + RotL64(aOrbiterH, 13U)) + aPhaseGWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 26U)) + aOrbiterE) + RotL64(aCarry, 11U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 21U) + aOrbiterH) + RotL64(aOrbiterA, 5U));
            aWandererG = aWandererG + (((RotL64(aCross, 54U) + aOrbiterK) + RotL64(aOrbiterG, 53U)) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterK, 43U)) + aOrbiterE) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 35U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 5883U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneB[((aIndex + 5135U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7843U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((aIndex + 6933U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aIngress, 39U)) + (RotL64(aCross, 57U) + RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = (((aWandererH + RotL64(aPrevious, 57U)) + RotL64(aCarry, 51U)) + 6771552164800695068U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aScatter, 13U)) + 12131763371571322040U;
            aOrbiterK = ((aWandererI + RotL64(aIngress, 34U)) + 3326182381395522013U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aCross, 43U)) + RotL64(aCarry, 21U)) + 12288775097697156383U;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 5195948373449796741U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 14404044002250137144U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 11142382920035825426U;
            aOrbiterK = RotL64((aOrbiterK * 8134413822789107595U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 2967149520256475485U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 1470907369577818097U;
            aOrbiterB = RotL64((aOrbiterB * 9398653295177725883U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 9231668148004163910U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 13078929163913892386U;
            aOrbiterC = RotL64((aOrbiterC * 7509829068700523627U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 9485274692075657877U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 12216951187543631673U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6571066246507310805U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 6933334652581744234U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 17260276102423580920U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7796879893790990605U), 35U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 3U);
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterD, 28U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 13U)) + aOrbiterC) + RotL64(aCarry, 21U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterB, 57U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterB, 22U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 37U) + aOrbiterK) + RotL64(aOrbiterA, 47U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 18U) + RotL64(aOrbiterA, 39U)) + aOrbiterB) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (RotL64(aWandererH, 60U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 14205U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11557U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12333U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15203U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 18U) + RotL64(aPrevious, 5U)) + (RotL64(aCross, 37U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = (((aWandererI + RotL64(aCross, 13U)) + RotL64(aCarry, 53U)) + 1297415699043177788U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 47U)) + 17583786534509260153U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = ((aWandererK + RotL64(aIngress, 35U)) + RotL64(aCarry, 39U)) + 643197858925708798U;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 5U)) + RotL64(aCarry, 13U)) + 5062653766915694874U;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 26U)) + 7034273638367180511U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 2026909726972916996U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 2785690475553211646U;
            aOrbiterK = RotL64((aOrbiterK * 6612792037861160393U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 2910341716302991892U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 2834181605200829791U;
            aOrbiterJ = RotL64((aOrbiterJ * 1510617068750957651U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 13323052600571281928U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 10434901530315760460U;
            aOrbiterG = RotL64((aOrbiterG * 2042210188346767033U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 247903955625194782U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 5196515747387257163U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1799024689023272275U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 7196305682377987476U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 14777739876892587484U;
            aOrbiterF = RotL64((aOrbiterF * 95220583948241581U), 57U);
            //
            aIngress = RotL64(aOrbiterC, 51U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterF, 23U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aIngress, 39U) + RotL64(aOrbiterF, 24U)) + aOrbiterK) + RotL64(aCarry, 11U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 57U) + aOrbiterG) + RotL64(aOrbiterF, 3U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterK, 43U)) + RotL64(aCarry, 39U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 28U) + aOrbiterF) + RotL64(aOrbiterC, 53U)) + aPhaseHWandererUpdateSaltD[((aIndex + 20U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 11U) + RotL64(aOrbiterC, 13U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 19U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 23677U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneD[((aIndex + 16857U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19802U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19643U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 51U)) ^ (RotL64(aCross, 4U) + RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = (aWandererA + RotL64(aIngress, 4U)) + 8402620908307642697U;
            aOrbiterK = (((aWandererI + RotL64(aPrevious, 51U)) + RotL64(aCarry, 21U)) + 11347672014525086047U) + aPhaseHOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = ((aWandererC + RotL64(aCross, 29U)) + RotL64(aCarry, 3U)) + 2816462912503401876U;
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 21U)) + RotL64(aCarry, 51U)) + 6940159795470696093U;
            aOrbiterE = ((aWandererH + RotL64(aCross, 39U)) + 9134692490095883851U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 4999455497008026526U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 5992451460350651332U;
            aOrbiterC = RotL64((aOrbiterC * 12796550245322491401U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 3417087346651371924U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 3612773820086198270U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5519856345435871169U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 463398077083428570U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 11249391303705089012U;
            aOrbiterB = RotL64((aOrbiterB * 7106735772303292983U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 17027535139825739501U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 568131384979596481U;
            aOrbiterI = RotL64((aOrbiterI * 5683451044852895957U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 4793712537158004047U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 10415170179135963622U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13729564030210361415U), 41U);
            //
            aIngress = RotL64(aOrbiterK, 27U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterC, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aCross, 41U) + RotL64(aOrbiterE, 3U)) + aOrbiterI) + RotL64(aCarry, 13U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 27U)) + aOrbiterK);
            aWandererA = aWandererA + ((RotL64(aPrevious, 12U) + aOrbiterC) + RotL64(aOrbiterI, 37U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 13U)) + aOrbiterB) + aPhaseHWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 21U) + aOrbiterC) + RotL64(aOrbiterE, 52U)) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + RotL64(aWandererA, 27U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 28547U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((aIndex + 28564U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31257U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 29740U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCarry, 41U)) + (RotL64(aPrevious, 60U) + RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = (((aWandererE + RotL64(aCross, 12U)) + RotL64(aCarry, 29U)) + 9080426856729228705U) + aPhaseHOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = ((aWandererF + RotL64(aIngress, 43U)) + RotL64(aCarry, 57U)) + 7851218321653539276U;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 3U)) + 7023344692919298036U) + aPhaseHOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aScatter, 53U)) + RotL64(aCarry, 41U)) + 9772846154227440734U;
            aOrbiterA = (aWandererI + RotL64(aIngress, 29U)) + 12008298632429608431U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 12201090455849562875U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 9498721803411445471U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6511810500788451775U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 351203764023093632U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 4966360430644539250U;
            aOrbiterC = RotL64((aOrbiterC * 10138518378274592739U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 9194167899071345693U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 4922477697284269116U;
            aOrbiterI = RotL64((aOrbiterI * 8444814161720407881U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 15742625291642356429U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 7528703106518431730U;
            aOrbiterK = RotL64((aOrbiterK * 11530049278751507567U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 15279053574704935317U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 2425839793660355555U;
            aOrbiterA = RotL64((aOrbiterA * 11486964816849830667U), 11U);
            //
            aIngress = RotL64(aOrbiterF, 37U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterC, 58U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterI, 51U)) + aOrbiterF) + aPhaseHWandererUpdateSaltC[((aIndex + 28U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 51U) + aOrbiterA) + RotL64(aOrbiterI, 19U)) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 20U) + RotL64(aOrbiterI, 60U)) + aOrbiterC) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 41U)) + aOrbiterA) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 29U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 42U);
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
