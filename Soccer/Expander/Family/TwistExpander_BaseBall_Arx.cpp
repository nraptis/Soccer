#include "TwistExpander_BaseBall_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_BaseBall_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xAF7CE1ED04C89AA9ULL + 0x80EF8B3AB37C63D1ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x80D8C742BF474AF7ULL + 0xD12A3E950C6443D5ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x9D8B9150CE4912BDULL + 0x9E36C8E5CDA46084ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xF4FE7601107465B3ULL + 0xCA5AE5635A7CDB88ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x93304928F8E65C37ULL + 0x9723A0F5CF2666C6ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xC504F69BD1F18C75ULL + 0x9F3488AE5DD6AF7EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xDC32A4F565A9A047ULL + 0xA9BA66492F81E0B6ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xA0FDA8C1B1125B4FULL + 0xF1466B89388226C3ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xD8CEFDD1A1E545F1ULL + 0xF4A0676611F75338ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xF1615859363E1D39ULL + 0xB693AA14D90ABBF8ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x8F9EF8AAA4902889ULL + 0xA0328C48DD6843BDULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xD4CA0BB66568142BULL + 0xFECD69290984AE2EULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x9C04250615C102FDULL + 0x880F709EDEF33D4EULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x86F33ED1AE2C013BULL + 0xCC1A70E04DFAE38FULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xD503DCB7026259EBULL + 0x84F0BCD0F9FBE465ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x9D7FA361F4F9B863ULL + 0xBABA9DF4D031438AULL);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 5083U)) & S_BLOCK1], 51U) ^ RotL64(pSnow[((aIndex + 3841U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 3931U)) & S_BLOCK1], 58U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 1438U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 19U) ^ RotL64(aPrevious, 5U)) + (RotL64(aCarry, 38U) + RotL64(aIngress, 57U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 39U)) + RotL64(aCarry, 23U)) + 15920462086654025436U;
            aOrbiterD = (aWandererB + RotL64(aIngress, 35U)) + 487844076858004017U;
            aOrbiterF = (aWandererJ + RotL64(aCross, 50U)) + 14502883786442630566U;
            aOrbiterK = ((aWandererK + RotL64(aScatter, 41U)) + 3787107318658233674U) + aOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = (aWandererH + RotL64(aIngress, 11U)) + 12548777544693755491U;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 37U)) + 4907309444075181683U) + aNonceWordN;
            aOrbiterA = (((aWandererA + RotL64(aScatter, 4U)) + RotL64(aCarry, 3U)) + 18342396700266492072U) + aNonceWordP;
            aOrbiterC = (aWandererC + RotL64(aCross, 23U)) + 13503051997624242670U;
            aOrbiterJ = (aWandererE + RotL64(aScatter, 43U)) + 17845742460521374571U;
            aOrbiterB = ((aWandererG + RotL64(aCross, 47U)) + RotL64(aCarry, 47U)) + 8640887211877858169U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 21U)) + 5273913123709097537U) + aOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 17756844173695563883U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterI) ^ 6713055830729302951U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterF = RotL64((aOrbiterF * 2832836748513174311U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 5106468334224035972U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 10228769728713526172U) ^ aOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9760310686414358435U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 7687649520668883142U) + aNonceWordH;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 7757480627354711605U;
            aOrbiterI = RotL64((aOrbiterI * 7222553727737349209U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 10876291698508634557U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 8149278085586014186U;
            aOrbiterK = RotL64((aOrbiterK * 8577133863470695381U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 15592893988925610485U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 8639028256640537165U) ^ aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1880655276432963955U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 475660347892196219U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 1903736092401853832U;
            aOrbiterJ = RotL64((aOrbiterJ * 8486318978769094799U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 12463250192809450953U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 7253918448601703982U) ^ aNonceWordD;
            aOrbiterH = RotL64((aOrbiterH * 3821034106528009129U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 5171661020093804486U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 11627344933828324146U;
            aOrbiterD = RotL64((aOrbiterD * 5388047063152043277U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 6206801139131132815U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 9221302203943031377U;
            aOrbiterE = RotL64((aOrbiterE * 12912049016813367241U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 1798857939965423979U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 5476854168685641232U;
            aOrbiterC = RotL64((aOrbiterC * 3884216989250294213U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 2816659151953455230U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 15920462086654025436U;
            aOrbiterB = RotL64((aOrbiterB * 17843161654734820613U), 11U);
            //
            aIngress = RotL64(aOrbiterG, 3U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 12U));
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 29U) + aOrbiterB) + RotL64(aOrbiterE, 47U)) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 48U) + aOrbiterF) + RotL64(aOrbiterH, 24U)) + aWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 39U) + RotL64(aOrbiterE, 37U)) + aOrbiterJ);
            aWandererI = aWandererI ^ ((RotL64(aCross, 5U) + aOrbiterJ) + RotL64(aOrbiterF, 27U));
            aWandererF = aWandererF + ((RotL64(aIngress, 43U) + aOrbiterA) + RotL64(aOrbiterD, 3U));
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 41U) + aOrbiterG) + RotL64(aOrbiterB, 41U)) + aNonceWordM) + aWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 23U) + RotL64(aOrbiterG, 51U)) + aOrbiterC) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 37U) + aOrbiterI) + RotL64(aOrbiterA, 5U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 53U) + aOrbiterK) + RotL64(aOrbiterB, 53U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 34U) + aOrbiterC) + RotL64(aOrbiterI, 21U)) + aNonceWordF);
            aWandererK = aWandererK + ((RotL64(aScatter, 19U) + aOrbiterD) + RotL64(aOrbiterG, 10U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 10U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 27U);
            aCarry = aCarry + RotL64(aIngress, 12U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordE);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9009U)) & S_BLOCK1], 57U) ^ RotL64(mSource[((aIndex + 6843U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(pSnow[((S_BLOCK1 - aIndex + 8061U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((aIndex + 6659U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 21U) + RotL64(aCarry, 5U)) ^ (RotL64(aCross, 57U) + RotL64(aPrevious, 36U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererH + RotL64(aPrevious, 10U)) + 3973833383430652211U;
            aOrbiterH = (aWandererF + RotL64(aIngress, 3U)) + 5760227042747169187U;
            aOrbiterB = (aWandererE + RotL64(aScatter, 41U)) + 4923009065139227286U;
            aOrbiterA = ((aWandererC + RotL64(aCross, 57U)) + RotL64(aCarry, 53U)) + 1477807307009107590U;
            aOrbiterD = (aWandererG + RotL64(aIngress, 5U)) + 5707194514329007301U;
            aOrbiterJ = (((aWandererD + RotL64(aPrevious, 24U)) + 5340439728375269724U) + aOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordH;
            aOrbiterK = (aWandererJ + RotL64(aCross, 29U)) + 17080457898946572387U;
            aOrbiterE = (((aWandererI + RotL64(aScatter, 13U)) + RotL64(aCarry, 19U)) + 281559150259472813U) + aOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (aWandererB + RotL64(aCross, 47U)) + 16160633048230910560U;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 39U)) + RotL64(aCarry, 13U)) + 9003989610509592121U;
            aOrbiterF = (aWandererA + RotL64(aIngress, 51U)) + 10579322462808454333U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 15059383289528723069U) + aNonceWordB;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 10417647757852880956U;
            aOrbiterB = RotL64((aOrbiterB * 1457919230286043137U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 14484665027393813330U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 12344463053485837974U;
            aOrbiterH = RotL64((aOrbiterH * 5762654194001525041U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 5826453246659297805U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = (((aOrbiterD ^ aOrbiterJ) ^ 12547902286376986223U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterD = RotL64((aOrbiterD * 2982850000322672789U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 9637855144278126174U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 2132744427444501938U;
            aOrbiterK = RotL64((aOrbiterK * 5911587798564836199U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 9248933938130311231U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 13274297928717090383U) ^ aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2901398809555237563U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 3690262236918560930U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 3626005326410800344U;
            aOrbiterI = RotL64((aOrbiterI * 13030443356669355355U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 10801089744186148218U) + aNonceWordL;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 5446653082176311031U;
            aOrbiterA = RotL64((aOrbiterA * 4594267575901248321U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 3205541585889107366U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 4532327942368884436U) ^ aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16287094987689326229U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 9755333481079721632U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 722154154363571049U;
            aOrbiterE = RotL64((aOrbiterE * 11002432494248958957U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 8071668483354405205U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 8770466248803121315U;
            aOrbiterC = RotL64((aOrbiterC * 12780438190628717807U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 1999251593502332271U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 3973833383430652211U;
            aOrbiterF = RotL64((aOrbiterF * 5325244982474631559U), 41U);
            //
            aIngress = RotL64(aOrbiterG, 23U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 18U));
            aIngress = aIngress + RotL64(aOrbiterE, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 51U)) + aOrbiterB) + aWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 30U) + aOrbiterJ) + RotL64(aOrbiterF, 19U));
            aWandererH = aWandererH + (((RotL64(aCross, 13U) + RotL64(aOrbiterC, 11U)) + aOrbiterG) + RotL64(aCarry, 35U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterD, 5U));
            aWandererA = aWandererA + ((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 26U)) + aOrbiterK);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 37U) + aOrbiterH) + RotL64(aOrbiterD, 23U)) + aNonceWordG);
            aWandererD = aWandererD + ((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterA, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 40U) + aOrbiterF) + RotL64(aOrbiterI, 13U));
            aWandererI = aWandererI + (((RotL64(aCross, 23U) + RotL64(aOrbiterE, 58U)) + aOrbiterD) + aNonceWordK);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterA, 37U)) + aOrbiterI) + aWandererUpdateSaltD[((aIndex + 20U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 57U) + RotL64(aOrbiterB, 21U)) + aOrbiterA) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 58U));
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 41U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 24U));
            aCarry = aCarry + RotL64(aWandererH, 51U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ aNonceWordL;
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15857U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneA[((aIndex + 14271U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 14605U)) & S_BLOCK1], 11U) ^ RotL64(pSnow[((aIndex + 14824U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 21U)) ^ (RotL64(aCross, 57U) ^ RotL64(aIngress, 40U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererD + RotL64(aScatter, 37U)) + 7790166497945719700U;
            aOrbiterD = (aWandererI + RotL64(aPrevious, 13U)) + 7136208896846119188U;
            aOrbiterI = (((aWandererA + RotL64(aIngress, 54U)) + RotL64(aCarry, 51U)) + 12123156943355100886U) + aOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aCross, 5U)) + 5095546037880875199U;
            aOrbiterB = (aWandererC + RotL64(aIngress, 43U)) + 17642705393916765992U;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 21U)) + 9918479837334416990U) + aNonceWordA;
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 3U)) + 4890009823843176466U) + aNonceWordB;
            aOrbiterE = ((aWandererH + RotL64(aScatter, 19U)) + RotL64(aCarry, 29U)) + 17652590786213674124U;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 47U)) + RotL64(aCarry, 21U)) + 870002527644696135U;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 56U)) + 12545429703552643682U) + aOrbiterAssignSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aIngress, 51U)) + 5310272867406182581U) + aNonceWordE;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 3264719049050179440U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 1967241238180278937U;
            aOrbiterI = RotL64((aOrbiterI * 13004319774269457957U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 773883832927040736U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 12766817190261232485U;
            aOrbiterA = RotL64((aOrbiterA * 7448864556802318431U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 260069382395598265U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 15462103891287350123U;
            aOrbiterD = RotL64((aOrbiterD * 5029268763635635753U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 4072032867513289827U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 17153061419083897076U;
            aOrbiterB = RotL64((aOrbiterB * 11934532169271718913U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 6207264270332656966U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 18048064697837314947U;
            aOrbiterE = RotL64((aOrbiterE * 13632594619404208489U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 14484617445340272026U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 16160443600497652026U) ^ aOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1988599349457831597U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 5873314228291583482U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 16418290052752166515U) ^ aOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 18270363452003213317U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 9158414409987627714U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 8205937960146492168U;
            aOrbiterG = RotL64((aOrbiterG * 14008398661393344261U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 16386126219854809263U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 12418021156683187869U) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 13897930566207284517U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 5427232681451476584U) + aOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 18237670074497382745U) ^ aNonceWordO;
            aOrbiterK = RotL64((aOrbiterK * 15528665160297906195U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 8330262458028468513U) + aNonceWordK;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 7790166497945719700U;
            aOrbiterF = RotL64((aOrbiterF * 6001280767763971107U), 3U);
            //
            aIngress = RotL64(aOrbiterE, 11U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterD, 54U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + RotL64(aOrbiterA, 46U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aIngress, 37U) + RotL64(aOrbiterK, 29U)) + aOrbiterA);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 10U) + RotL64(aOrbiterC, 13U)) + aOrbiterK) + aNonceWordF);
            aWandererG = aWandererG + ((RotL64(aPrevious, 21U) + aOrbiterE) + RotL64(aOrbiterF, 54U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 5U) + aOrbiterJ) + RotL64(aOrbiterB, 43U)) + aWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 43U) + aOrbiterI) + RotL64(aOrbiterE, 5U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterA, 35U)) + aOrbiterG);
            aWandererE = aWandererE + (((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterJ, 10U)) + RotL64(aCarry, 35U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterB, 21U)) + aOrbiterF);
            aWandererK = aWandererK + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterH, 39U)) + aOrbiterI) + RotL64(aCarry, 29U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 47U) + aOrbiterG) + RotL64(aOrbiterC, 23U)) + aWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 24U) + RotL64(aOrbiterD, 19U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 20U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererB, 22U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordK;
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 19352U)) & S_BLOCK1], 20U) ^ RotL64(aWorkLaneB[((aIndex + 18935U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18198U)) & S_BLOCK1], 30U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 20147U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 41U) + RotL64(aIngress, 5U)) ^ (RotL64(aCross, 18U) ^ RotL64(aPrevious, 53U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererK + RotL64(aScatter, 39U)) + 8866844335448071821U;
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 29U)) + RotL64(aCarry, 21U)) + 15159698739856430085U;
            aOrbiterJ = (aWandererC + RotL64(aCross, 11U)) + 9582805772989594633U;
            aOrbiterG = (aWandererE + RotL64(aIngress, 21U)) + 1438538239931588373U;
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 27U)) + 10862044156620436139U) + aOrbiterAssignSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = (((aWandererG + RotL64(aScatter, 18U)) + RotL64(aCarry, 41U)) + 13682173320058164615U) + aOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = (aWandererI + RotL64(aIngress, 35U)) + 8351013291045977592U;
            aOrbiterA = ((aWandererD + RotL64(aCross, 37U)) + 15777857431516633916U) + aNonceWordH;
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 13U)) + 16178966745333885377U) + aNonceWordD;
            aOrbiterH = ((aWandererH + RotL64(aCross, 41U)) + RotL64(aCarry, 11U)) + 9031889187993001617U;
            aOrbiterF = (aWandererB + RotL64(aIngress, 24U)) + 6308472367425865347U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 642109145903321046U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 9186268569255318035U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10714674348507516749U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 6091345356803675860U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 13218507921880873749U;
            aOrbiterB = RotL64((aOrbiterB * 15415157927185637717U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 4266652275234474616U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 4391422098164506195U) ^ aNonceWordO;
            aOrbiterE = RotL64((aOrbiterE * 17634679403195085867U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 5160682323243635577U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 10351728852161347404U;
            aOrbiterD = RotL64((aOrbiterD * 11105410036471745951U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 3950932176454814023U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 9536466386833427441U;
            aOrbiterA = RotL64((aOrbiterA * 18064984243491293435U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 9927425919978776529U) + aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 6819384090527481081U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 18032965969184368561U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 1646274931424218507U) + aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 16166524473976135097U;
            aOrbiterH = RotL64((aOrbiterH * 11672192658072663849U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 11252501968059485262U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 16847854447987609067U;
            aOrbiterF = RotL64((aOrbiterF * 6326299154627028295U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 16723218285355036446U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 13870211254243048975U;
            aOrbiterC = RotL64((aOrbiterC * 10203222183774624097U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 11401147367366049493U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 4266628469244269926U;
            aOrbiterI = RotL64((aOrbiterI * 2409934496621365221U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 11578385782347296942U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 8866844335448071821U) ^ aNonceWordE;
            aOrbiterG = RotL64((aOrbiterG * 6456956795450036515U), 21U);
            //
            aIngress = RotL64(aOrbiterI, 27U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + (RotL64(aOrbiterC, 42U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 39U));
            aIngress = aIngress + RotL64(aOrbiterJ, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 39U) + aOrbiterA) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 10U) + aOrbiterE) + RotL64(aOrbiterI, 41U)) + aWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 29U) + RotL64(aOrbiterK, 11U)) + aOrbiterH) + RotL64(aCarry, 37U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 37U) + aOrbiterI) + RotL64(aOrbiterH, 60U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 41U) + RotL64(aOrbiterK, 21U)) + aOrbiterB);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterF, 47U)) + aOrbiterE) + aWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 5U) + RotL64(aOrbiterJ, 19U)) + aOrbiterH);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 43U) + aOrbiterK) + RotL64(aOrbiterG, 38U));
            aWandererK = aWandererK + (((RotL64(aCross, 13U) + aOrbiterK) + RotL64(aOrbiterE, 23U)) + aNonceWordC);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 18U) + aOrbiterI) + RotL64(aOrbiterD, 27U));
            aWandererB = aWandererB + ((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 13U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 10U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererJ, 4U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22593U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 26614U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26288U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((aIndex + 25070U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCross, 5U)) ^ (RotL64(aCarry, 53U) ^ RotL64(aIngress, 36U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 41U)) + 1898718075389870739U) + aOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aCross, 56U)) + 5631794889237247403U;
            aOrbiterH = (aWandererK + RotL64(aScatter, 13U)) + 18219714659484524607U;
            aOrbiterC = ((aWandererD + RotL64(aIngress, 3U)) + RotL64(aCarry, 43U)) + 15419581386225732921U;
            aOrbiterK = ((aWandererH + RotL64(aCross, 35U)) + RotL64(aCarry, 21U)) + 9125575431710198210U;
            aOrbiterA = (aWandererI + RotL64(aScatter, 43U)) + 12205871520544965505U;
            aOrbiterE = (aWandererE + RotL64(aPrevious, 27U)) + 7617534300497343422U;
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 11U)) + 18017579105368135814U) + aOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aScatter, 21U)) + RotL64(aCarry, 57U)) + 10693882161946020042U;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 23U)) + 11669615701700895306U;
            aOrbiterG = ((aWandererA + RotL64(aCross, 30U)) + 11045110212889232165U) + aNonceWordE;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 18019107802806469913U) + aNonceWordL;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 12315940560472528716U;
            aOrbiterH = RotL64((aOrbiterH * 4505122470351404065U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 4899009736070044310U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 17412253404253730364U;
            aOrbiterA = RotL64((aOrbiterA * 10791901166391946485U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 4826286251927854181U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 4523455921321845084U;
            aOrbiterD = RotL64((aOrbiterD * 14534103906736598099U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 4132514462154182215U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 7164745605985109269U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14107325508977225261U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 6297434295807635654U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 8813887638672996646U;
            aOrbiterI = RotL64((aOrbiterI * 17495632530773158201U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 11086381278955626084U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 5660733992573928887U;
            aOrbiterC = RotL64((aOrbiterC * 11248164458720777889U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 14851044686208609882U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 12707776386060264479U;
            aOrbiterE = RotL64((aOrbiterE * 4470919091467313071U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 11508023384209716657U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 11752973809740920034U;
            aOrbiterF = RotL64((aOrbiterF * 10212754472298834769U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 16746821150860017820U) + aNonceWordC;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 9659421716296641396U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7530071874978553673U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 3192309064305104593U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 11409078048681398061U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14991409124701807765U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 315359495275427324U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 1898718075389870739U) ^ aNonceWordB;
            aOrbiterK = RotL64((aOrbiterK * 13126661894614781343U), 21U);
            //
            aIngress = RotL64(aOrbiterG, 51U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterH, 48U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + RotL64(aOrbiterI, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterG, 23U)) + aNonceWordA) + aWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 51U) + aOrbiterB) + RotL64(aOrbiterF, 51U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 34U) + aOrbiterF) + RotL64(aOrbiterJ, 39U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 53U) + aOrbiterI) + RotL64(aOrbiterC, 46U)) + aWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterD, 37U)) + RotL64(aCarry, 57U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 19U)) + aOrbiterA);
            aWandererE = aWandererE + ((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterF, 11U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 44U) + RotL64(aOrbiterF, 41U)) + aOrbiterI);
            aWandererB = aWandererB + ((((RotL64(aCross, 21U) + RotL64(aOrbiterK, 14U)) + aOrbiterC) + RotL64(aCarry, 11U)) + aNonceWordI);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 27U) + aOrbiterA) + RotL64(aOrbiterH, 29U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 13U) + aOrbiterC) + RotL64(aOrbiterD, 35U)) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 58U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + RotL64(aWandererF, 56U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordE);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29799U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneB[((aIndex + 29655U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31803U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30598U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 21U) + RotL64(aCarry, 34U)) ^ (RotL64(aPrevious, 51U) ^ RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererD + RotL64(aIngress, 3U)) + 77518479758428414U;
            aOrbiterI = ((aWandererI + RotL64(aCross, 5U)) + 4832061802166300011U) + aNonceWordL;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 51U)) + 11695291171006574112U) + aOrbiterAssignSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 54U)) + 7467412817843260094U;
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 41U)) + 17801484124471154757U) + aOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 23U)) + RotL64(aCarry, 3U)) + 5555455638503958639U;
            aOrbiterE = ((aWandererK + RotL64(aCross, 37U)) + RotL64(aCarry, 27U)) + 5669470540733721606U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 19U)) + RotL64(aCarry, 19U)) + 3042388456327784163U;
            aOrbiterF = (aWandererB + RotL64(aPrevious, 56U)) + 2236734925228156691U;
            aOrbiterG = (aWandererG + RotL64(aCross, 13U)) + 14459720401528685450U;
            aOrbiterB = (aWandererA + RotL64(aScatter, 27U)) + 4814967631216658856U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 16950679344449075945U) + aNonceWordD;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 6262238639302011050U;
            aOrbiterK = RotL64((aOrbiterK * 9942659897425088183U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 3522256359074996724U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 12524717897707074242U) ^ aNonceWordI;
            aOrbiterJ = RotL64((aOrbiterJ * 6787771338063891989U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 13891759914865623828U) + aOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 11910250571469028666U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12311343917878428995U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 2240189915640314069U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 5365912986308810837U;
            aOrbiterE = RotL64((aOrbiterE * 15133972552032469957U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 9323732721344489753U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 13087326560957916553U;
            aOrbiterA = RotL64((aOrbiterA * 14659491687401151733U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 16398238057564892809U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 11517870519285159224U;
            aOrbiterF = RotL64((aOrbiterF * 1501848878469712681U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 7758285512254776734U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 17475149091906684720U;
            aOrbiterG = RotL64((aOrbiterG * 6015816725428299273U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 2051631493975035243U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 11684740065349595315U) ^ aOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10918975496337269197U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 10575473798991451167U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 8267005776169272822U) ^ aNonceWordH;
            aOrbiterH = RotL64((aOrbiterH * 13166868678285963961U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 6249698995716039231U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 13808085811784323978U;
            aOrbiterI = RotL64((aOrbiterI * 3897731011582061983U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 2739364646624876985U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 77518479758428414U;
            aOrbiterD = RotL64((aOrbiterD * 6977724811175035551U), 29U);
            //
            aIngress = RotL64(aOrbiterF, 5U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 26U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + RotL64(aOrbiterG, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterF, 23U)) + aOrbiterD);
            aWandererG = aWandererG + (((RotL64(aPrevious, 46U) + RotL64(aOrbiterH, 51U)) + aOrbiterI) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterA, 41U)) + aOrbiterE) + aWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 53U) + aOrbiterH) + RotL64(aOrbiterA, 35U)) + aNonceWordK);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 39U) + aOrbiterB) + RotL64(aOrbiterA, 60U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 37U) + aOrbiterJ) + RotL64(aOrbiterK, 39U)) + aWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 12U) + RotL64(aOrbiterK, 43U)) + aOrbiterG);
            aWandererI = aWandererI + (((RotL64(aCross, 57U) + RotL64(aOrbiterD, 13U)) + aOrbiterK) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 41U) + aOrbiterC) + RotL64(aOrbiterB, 3U));
            aWandererD = aWandererD + ((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 11U)) + aOrbiterD);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterD, 26U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 56U));
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 5U);
            aCarry = aCarry + RotL64(aIngress, 36U);
            aCarry = aCarry ^ aNonceWordH;
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

void TwistExpander_BaseBall_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xC57884DF333886AFULL + 0xA44A5F363AA8FC32ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xF69F2893E296B0D5ULL + 0xC0BAF049BB276D8DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x90B3797381C9F43DULL + 0xEFC6F59C48F5C5A3ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xF0B6B0786A1B241BULL + 0xAD670E8E3F45E962ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xCD4F1C9509C264FBULL + 0xBB873E02B9E9AE60ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xCB297BEC7434733FULL + 0xAA52B6AE44C7CA14ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xB2F4028893EAF39FULL + 0xCBB8B8150F93D86EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xBB032C77B11AC16FULL + 0xCAC8CFF85184A658ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x9E5BF26EA62FEC1FULL + 0x99EC21C6AE3FBABEULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xEF51274413AD6589ULL + 0xF57FC010B1761385ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xB12CB1C482200E57ULL + 0xD2FD06E38B315019ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xDF84E68C52128A1BULL + 0x9B714EA5A74102B0ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x9A65B8E545F2A625ULL + 0xC8D7362ED1973AEDULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x83BEB2F212704391ULL + 0xDB66C902CE303A14ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xA94B8CB1B381B99FULL + 0x924D69A8DE367747ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xA154A1B09CFB710BULL + 0xFC07A1EB20981BD6ULL);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 3746U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((aIndex + 1955U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4253U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((aIndex + 4428U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 19U) ^ RotL64(aPrevious, 5U)) + (RotL64(aCross, 34U) ^ RotL64(aIngress, 57U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererI + RotL64(aScatter, 18U)) + 2168513956284366370U) + aNonceWordO;
            aOrbiterB = ((aWandererE + RotL64(aCross, 41U)) + RotL64(aCarry, 53U)) + 10290361969974613111U;
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 5U)) + RotL64(aCarry, 5U)) + 15673836275828498050U;
            aOrbiterJ = (((aWandererC + RotL64(aIngress, 23U)) + RotL64(aCarry, 19U)) + 16600540024145812236U) + aNonceWordC;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 11U)) + 9428052101528111892U) + aNonceWordH;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 57U)) + 12763657928312763377U) + aOrbiterAssignSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = ((aWandererB + RotL64(aCross, 37U)) + 10751286982008662485U) + aOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aScatter, 46U)) + 1708230173038057979U;
            aOrbiterK = (aWandererG + RotL64(aCross, 27U)) + 4011389705422783816U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 11704428328093077714U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 2055336619674699284U) ^ aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6374289210096410907U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 1870865272102705804U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 3574214263751923179U;
            aOrbiterG = RotL64((aOrbiterG * 13132083406834413563U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 984611970726966186U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 15207945449947643672U;
            aOrbiterA = RotL64((aOrbiterA * 9539470161576639981U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 4181398506373973169U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 15222345431506025949U) ^ aNonceWordK;
            aOrbiterK = RotL64((aOrbiterK * 6925143692628659467U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 15023513452326240962U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterI) ^ 14965669361708810699U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 587008860996713147U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 7985755518735406360U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 225592097619240187U) ^ aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2313509354133400439U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 3659537916566939383U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 17043668033610689611U) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 10797634709118100773U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 10217321522161675848U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 8013663869536146842U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2293233079384777175U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 13762445330867496042U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 2692400019659269106U;
            aOrbiterI = RotL64((aOrbiterI * 167704184292219399U), 47U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterB, 3U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterD, 18U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 18U) + RotL64(aOrbiterB, 56U)) + aOrbiterG) + aWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 13U) + aOrbiterG) + RotL64(aOrbiterJ, 27U)) + aWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 3U) + RotL64(aOrbiterB, 39U)) + aOrbiterA) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 41U) + aOrbiterF) + RotL64(aOrbiterB, 5U)) + aNonceWordD);
            aWandererG = aWandererG + ((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterK, 12U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterB, 43U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 47U) + aOrbiterI) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 52U) + RotL64(aOrbiterF, 19U)) + aOrbiterG) + aNonceWordL);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 23U) + RotL64(aOrbiterC, 23U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 60U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordK;
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 8732U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneD[((aIndex + 10357U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8604U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 11320U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCarry, 57U)) ^ (RotL64(aCross, 44U) ^ RotL64(aIngress, 23U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererA + RotL64(aIngress, 43U)) + 9041099828460168106U) + aNonceWordN;
            aOrbiterE = ((aWandererC + RotL64(aCross, 60U)) + RotL64(aCarry, 13U)) + 12883711604096848454U;
            aOrbiterF = ((aWandererF + RotL64(aScatter, 19U)) + RotL64(aCarry, 21U)) + 17420968786226443079U;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 29U)) + 3448213891716125104U) + aNonceWordI;
            aOrbiterH = (aWandererG + RotL64(aCross, 35U)) + 11866455977445336560U;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 13U)) + RotL64(aCarry, 37U)) + 4119356835384495905U;
            aOrbiterA = (aWandererB + RotL64(aScatter, 52U)) + 2186212599698637068U;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 47U)) + 6506144898969301620U) + aOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = ((aWandererD + RotL64(aCross, 3U)) + 12556800923644051626U) + aOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 4075551535185182945U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 17877694808492008749U;
            aOrbiterF = RotL64((aOrbiterF * 901315308379887473U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 5553428900598223316U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 14362304852277160675U;
            aOrbiterH = RotL64((aOrbiterH * 11415103199856419303U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 9174200302876075831U) + aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 16110739511917638547U;
            aOrbiterA = RotL64((aOrbiterA * 7004356839428657949U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 10189881974519849402U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 2128076632642616677U;
            aOrbiterD = RotL64((aOrbiterD * 8860453653433114929U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 18133523799074400083U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 9916472958834153766U) ^ aOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3454601168808001733U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 10274457562795569227U) + aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 14134814273275356425U;
            aOrbiterB = RotL64((aOrbiterB * 15912501063665343159U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 6394306369514735480U) + aNonceWordD;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 4825761192736485643U) ^ aNonceWordC;
            aOrbiterC = RotL64((aOrbiterC * 12534544147331805643U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 5672807934779206275U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 3881953574159390421U;
            aOrbiterJ = RotL64((aOrbiterJ * 7448770570912161095U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 12012232712634303203U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 14176392925893052596U;
            aOrbiterE = RotL64((aOrbiterE * 11288668529893084583U), 19U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterA, 44U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 5U)) + aOrbiterD);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 51U) + aOrbiterD) + RotL64(aOrbiterF, 60U));
            aWandererB = aWandererB + ((RotL64(aCross, 34U) + RotL64(aOrbiterJ, 29U)) + aOrbiterA);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 39U) + aOrbiterE) + RotL64(aOrbiterK, 43U)) + aNonceWordB);
            aWandererH = aWandererH + (((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 11U)) + aOrbiterB) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 27U) + aOrbiterC) + RotL64(aOrbiterD, 39U)) + aWandererUpdateSaltB[((aIndex + 16U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 23U) + aOrbiterC) + RotL64(aOrbiterH, 34U)) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 58U) + RotL64(aOrbiterH, 21U)) + aOrbiterJ);
            aWandererF = aWandererF + (((RotL64(aPrevious, 43U) + aOrbiterC) + RotL64(aOrbiterE, 51U)) + aWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (RotL64(aWandererG, 10U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 27U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 24487U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 16872U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 24528U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 18732U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 19U)) + (RotL64(aCross, 6U) ^ RotL64(aIngress, 57U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererA + RotL64(aCross, 41U)) + 12980104182836602177U) + aOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 5U)) + RotL64(aCarry, 11U)) + 3172622203188863995U;
            aOrbiterI = (((aWandererF + RotL64(aScatter, 57U)) + RotL64(aCarry, 3U)) + 1170974132219980203U) + aNonceWordG;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 18U)) + RotL64(aCarry, 23U)) + 6035201940965047490U;
            aOrbiterC = (aWandererJ + RotL64(aCross, 13U)) + 18033907118424996722U;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 51U)) + 14604813424800580304U;
            aOrbiterD = (aWandererK + RotL64(aIngress, 27U)) + 13720232492851066035U;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 34U)) + 3902659710585257448U) + aNonceWordL;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 47U)) + 8331560652661619868U) + aOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 4485014147538689794U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 168202636924512424U) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 13711020666131492091U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 16227825670092707848U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 4792781933944671365U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15859849676231455283U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 12636865372722601282U) + aOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 18198291399585556632U;
            aOrbiterK = RotL64((aOrbiterK * 18155803890313399795U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 3650053185419807206U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 5897288963905408776U) ^ aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3706949366974086151U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 9922308113622901726U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 13352279749091561510U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4025213180483632557U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 14969461950939646117U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 10231661776135056651U;
            aOrbiterB = RotL64((aOrbiterB * 11284575051455238501U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 10621934544068320859U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 6029116920305246887U;
            aOrbiterD = RotL64((aOrbiterD * 6087523725059376905U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 12887482425168671195U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 8351351557123783853U;
            aOrbiterH = RotL64((aOrbiterH * 3839381627914762245U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 5405938210926464973U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 385145802287899406U;
            aOrbiterG = RotL64((aOrbiterG * 8330751480464271445U), 29U);
            //
            aIngress = RotL64(aOrbiterI, 27U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterB, 20U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aCross, 27U) + aOrbiterK) + RotL64(aOrbiterB, 39U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 35U)) + aOrbiterJ);
            aWandererH = aWandererH + (((RotL64(aPrevious, 35U) + aOrbiterB) + RotL64(aOrbiterG, 27U)) + aNonceWordO);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 52U) + RotL64(aOrbiterH, 52U)) + aOrbiterC);
            aWandererD = aWandererD + ((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterB, 23U));
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 47U) + aOrbiterF) + RotL64(aOrbiterB, 57U)) + aNonceWordN) + aWandererUpdateSaltF[((aIndex + 16U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 3U) + aOrbiterF) + RotL64(aOrbiterI, 19U)) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 18U) + aOrbiterH) + RotL64(aOrbiterI, 43U));
            aWandererE = aWandererE + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 12U)) + aOrbiterD) + RotL64(aCarry, 27U)) + aWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererG, 10U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ aNonceWordE;
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 25740U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneB[((aIndex + 30117U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31613U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 28013U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 4U) ^ RotL64(aPrevious, 35U)) ^ (RotL64(aIngress, 47U) + RotL64(aCross, 21U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (((aWandererB + RotL64(aIngress, 27U)) + RotL64(aCarry, 3U)) + 6381335981879993247U) + aNonceWordF;
            aOrbiterJ = ((aWandererE + RotL64(aCross, 58U)) + 15595429101600023172U) + aOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 11U)) + RotL64(aCarry, 11U)) + 5449234297249826461U;
            aOrbiterC = (aWandererA + RotL64(aScatter, 43U)) + 11213734849329731168U;
            aOrbiterG = (aWandererF + RotL64(aIngress, 5U)) + 16438473952464514248U;
            aOrbiterH = (aWandererC + RotL64(aScatter, 23U)) + 7357872882115186976U;
            aOrbiterB = (aWandererI + RotL64(aPrevious, 19U)) + 394402075160738643U;
            aOrbiterD = (((aWandererK + RotL64(aCross, 48U)) + RotL64(aCarry, 35U)) + 11112941985410283532U) + aOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aScatter, 39U)) + 14955125011182736212U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 14770727009821304070U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 11286366598129204910U;
            aOrbiterI = RotL64((aOrbiterI * 15884310771003021989U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 7358400908565425780U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 15635109923749114761U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12415152149408700329U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 13826842523738623579U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 1072811298828325231U;
            aOrbiterB = RotL64((aOrbiterB * 9662800288646215083U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 4017334196009350776U) + aNonceWordJ;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 8812213572751410831U) ^ aNonceWordL;
            aOrbiterF = RotL64((aOrbiterF * 12744171921566782795U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 6723457786170634403U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 9785583533999417673U;
            aOrbiterC = RotL64((aOrbiterC * 7776915427605471097U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 10265132640322153964U) + aOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 8435670887514808087U;
            aOrbiterH = RotL64((aOrbiterH * 2706263045620662131U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 4303823386961718326U) + aOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 4214384238167491037U;
            aOrbiterD = RotL64((aOrbiterD * 8490707334221154005U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 8740835037840799136U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 5988815405391206280U;
            aOrbiterA = RotL64((aOrbiterA * 17838555472135715929U), 29U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterA) + 15539461383052981747U) + aOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1]) + aNonceWordM;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 3743772525784217714U;
            aOrbiterJ = RotL64((aOrbiterJ * 6352086797545969187U), 43U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterH, 29U);
            aIngress = aIngress + (RotL64(aOrbiterI, 44U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 23U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aIngress, 60U) + aOrbiterI) + RotL64(aOrbiterG, 30U)) + aNonceWordO) + aWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterD, 39U)) + aOrbiterF);
            aWandererC = aWandererC + (((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterD, 43U)) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 37U) + aOrbiterG) + RotL64(aOrbiterC, 57U));
            aWandererB = aWandererB + (((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 47U)) + aOrbiterA) + aNonceWordH);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterJ, 11U)) + aOrbiterF);
            aWandererA = aWandererA + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterC, 52U)) + aOrbiterA) + RotL64(aCarry, 35U)) + aWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterC, 3U)) + aNonceWordA);
            aWandererK = aWandererK + ((RotL64(aPrevious, 14U) + aOrbiterG) + RotL64(aOrbiterB, 21U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 26U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ aNonceWordH;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xAE0F21FE845C147BULL + 0xA6CE64601E94FEC4ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x86A566063093B6CFULL + 0xFB54E12DC21F9FA9ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xB2C6067CD1097CDBULL + 0xE8B912430F91DA7AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xDD67EEF55D2C0493ULL + 0x95489735E91314DFULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x9D85C15D2F60213FULL + 0xB3013E50DE1A9AA9ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xF4C5D3C7FE306043ULL + 0x9E184D724138BBE1ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xFFE4D83D72D2CE0FULL + 0xA334E056EE33EF2CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE29AA8735B3447F5ULL + 0xD732C7FFD4C3CF00ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x813699571A6BA5C9ULL + 0xB13B51310DE8494CULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xDD377AC70C1B86F7ULL + 0xC7E9D6C19CEF1A19ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xD947095CEF531EE9ULL + 0xC75A5B0F29DC060EULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xB3F102120AFFBD41ULL + 0xD5354572E731242BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xC4C38EC9F0BBF1CBULL + 0xD07062FE59E715B6ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x8C25FC0492226195ULL + 0xB46629E39B708867ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xF1910E8B297F0743ULL + 0xEB43093008FB58D6ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xE964EBD804760FBDULL + 0xC15913944056C615ULL);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 4783U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneC[((aIndex + 2469U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 996U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 1248U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 27U) ^ RotL64(aPrevious, 12U)) ^ (RotL64(aIngress, 41U) + RotL64(aCarry, 57U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 43U)) + RotL64(aCarry, 29U)) + 9914837590440975587U;
            aOrbiterE = (((aWandererF + RotL64(aIngress, 57U)) + RotL64(aCarry, 57U)) + 6706125076401958051U) + aNonceWordB;
            aOrbiterF = ((aWandererA + RotL64(aCross, 12U)) + 16570817772679258409U) + aOrbiterAssignSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = (((aWandererJ + RotL64(aPrevious, 27U)) + RotL64(aCarry, 13U)) + 6843705658115186948U) + aNonceWordH;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 35U)) + 16099930446791572351U) + aOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 5420550009556030459U) + aNonceWordN;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 5729549069420177477U;
            aOrbiterF = RotL64((aOrbiterF * 7842192631021712569U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 15590601126188675834U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 13044027390998620029U;
            aOrbiterJ = RotL64((aOrbiterJ * 16845199115313444123U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 11068338135659636772U) + aOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 6584988841809544332U) ^ aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1683336180438945439U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 8516813219883915404U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 10647314042912492785U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15559481057047148785U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 201691689889605304U) + aOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 15512161798401184003U;
            aOrbiterA = RotL64((aOrbiterA * 11473219183982564709U), 47U);
            //
            aIngress = RotL64(aOrbiterA, 37U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aScatter, 39U) + aOrbiterF) + RotL64(aOrbiterJ, 6U)) + aNonceWordK) + aWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterB, 53U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 27U) + aOrbiterF) + RotL64(aOrbiterA, 35U)) + RotL64(aCarry, 35U)) + aWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 4U) + RotL64(aOrbiterB, 43U)) + aOrbiterE);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 13U) + aOrbiterB) + RotL64(aOrbiterA, 27U)) + RotL64(aCarry, 23U)) + aNonceWordF);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 13072U)) & S_BLOCK1], 36U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 8235U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 15536U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10731U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 19U)) ^ (RotL64(aPrevious, 56U) + RotL64(aCross, 41U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (aWandererB + RotL64(aScatter, 11U)) + 1898718075389870739U;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 21U)) + 5631794889237247403U) + aNonceWordL;
            aOrbiterB = (((aWandererC + RotL64(aIngress, 38U)) + RotL64(aCarry, 29U)) + 18219714659484524607U) + aNonceWordB;
            aOrbiterC = (((aWandererG + RotL64(aCross, 47U)) + RotL64(aCarry, 53U)) + 15419581386225732921U) + aOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = (((aWandererJ + RotL64(aScatter, 57U)) + RotL64(aCarry, 11U)) + 9125575431710198210U) + aOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 12205871520544965505U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 7617534300497343422U;
            aOrbiterB = RotL64((aOrbiterB * 10052675719887595625U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 18017579105368135814U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 10693882161946020042U) ^ aOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2326507900303932855U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 11669615701700895306U) + aOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 11045110212889232165U) ^ aNonceWordK;
            aOrbiterA = RotL64((aOrbiterA * 5965171269273719849U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 18019107802806469913U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 12315940560472528716U;
            aOrbiterI = RotL64((aOrbiterI * 4505122470351404065U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 4899009736070044310U) + aOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 17412253404253730364U;
            aOrbiterC = RotL64((aOrbiterC * 10791901166391946485U), 11U);
            //
            aIngress = RotL64(aOrbiterA, 58U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 43U));
            aIngress = aIngress + RotL64(aOrbiterD, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((((RotL64(aCross, 41U) + aOrbiterB) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 3U)) + aNonceWordE) + aWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 54U) + RotL64(aOrbiterI, 29U)) + aOrbiterC) + aNonceWordG);
            aWandererF = aWandererF + (((RotL64(aPrevious, 3U) + aOrbiterA) + RotL64(aOrbiterD, 56U)) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 23U) + aOrbiterA) + RotL64(aOrbiterC, 43U)) + aWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 11U) + aOrbiterI) + RotL64(aOrbiterA, 19U)) + aNonceWordM);
            //
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + RotL64(aWandererJ, 35U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 18480U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17443U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 24556U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 22139U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aPrevious, 26U)) + (RotL64(aCarry, 5U) ^ RotL64(aIngress, 39U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((((aWandererF + RotL64(aScatter, 29U)) + RotL64(aCarry, 29U)) + 12690502671561165478U) + aOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordH;
            aOrbiterK = (((aWandererK + RotL64(aCross, 52U)) + RotL64(aCarry, 13U)) + 17519943923428102801U) + aNonceWordL;
            aOrbiterF = (((aWandererH + RotL64(aIngress, 11U)) + 10705515807975331385U) + aOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1]) + aNonceWordB;
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 19U)) + RotL64(aCarry, 43U)) + 16586447272278538179U;
            aOrbiterJ = (aWandererG + RotL64(aIngress, 3U)) + 8006560996840971798U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 12928600185788857701U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 14240723153798267172U) ^ aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7446040187505339853U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 8636219177994872072U) + aNonceWordG;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 7586790235186467512U;
            aOrbiterK = RotL64((aOrbiterK * 15052686382507614169U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 1103807034179512424U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 7547526530239498693U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3360295583636013509U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 8380239679344786397U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 5690809173787433519U;
            aOrbiterD = RotL64((aOrbiterD * 5354724308093372953U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 8390902801141804609U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterK) ^ 3507306189192059486U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterJ = RotL64((aOrbiterJ * 18336280496510253103U), 13U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterG, 3U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterG, 13U)) + aOrbiterD);
            aWandererK = aWandererK + ((((RotL64(aIngress, 60U) + aOrbiterG) + RotL64(aOrbiterK, 39U)) + RotL64(aCarry, 53U)) + aWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 23U) + aOrbiterF) + RotL64(aOrbiterJ, 4U)) + aNonceWordN) + aWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterJ, 51U)) + RotL64(aCarry, 41U)) + aNonceWordA);
            aWandererG = aWandererG ^ ((RotL64(aCross, 51U) + aOrbiterF) + RotL64(aOrbiterK, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 31964U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25308U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26278U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 32744U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 37U) + RotL64(aCross, 21U)) ^ (RotL64(aPrevious, 52U) ^ RotL64(aCarry, 3U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererK + RotL64(aCross, 41U)) + 3236820517816085022U) + aOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = ((((aWandererD + RotL64(aScatter, 30U)) + RotL64(aCarry, 51U)) + 741288875914097926U) + aOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1]) + aNonceWordL;
            aOrbiterB = (aWandererE + RotL64(aIngress, 11U)) + 8417246926007729580U;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 57U)) + RotL64(aCarry, 23U)) + 9715717805774537170U;
            aOrbiterG = ((aWandererI + RotL64(aCross, 21U)) + RotL64(aCarry, 39U)) + 14360243844821619482U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 10760908100206775334U) + aNonceWordA;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 3434641779946167811U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3305698324169010803U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 7885568822756234567U) + aOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 3041563437672051294U;
            aOrbiterF = RotL64((aOrbiterF * 11440300917533482297U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 15761355327564963516U) + aNonceWordD;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 1158633562785937421U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15511324886867188235U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 9338581575871970653U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 9172038894262857354U;
            aOrbiterJ = RotL64((aOrbiterJ * 3110871165285625807U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 14653924713599790081U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 3854497592598563309U) ^ aNonceWordB;
            aOrbiterG = RotL64((aOrbiterG * 11737111068815795303U), 5U);
            //
            aIngress = RotL64(aOrbiterF, 3U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterH, 43U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 54U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterF, 35U)) + aOrbiterG) + RotL64(aCarry, 53U)) + aNonceWordI);
            aWandererD = aWandererD ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterH, 13U)) + aOrbiterG);
            aWandererE = aWandererE + (((((RotL64(aScatter, 19U) + aOrbiterH) + RotL64(aOrbiterF, 43U)) + RotL64(aCarry, 21U)) + aNonceWordE) + aWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterB, 3U)) + aOrbiterH);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 56U)) + aOrbiterJ) + aNonceWordG) + aWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + RotL64(aWandererA, 21U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordE);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xA4F432F4875577A5ULL + 0xB90D4892978578AAULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x98F9BF9AD3159F17ULL + 0xCE3FD92A06C5D9D1ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xF0D5764820756EC9ULL + 0x8405D0281E75856AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xC9B513AE70CC2753ULL + 0x92DD159D1D748800ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xF1631A98EB9579C3ULL + 0xBE0399992B79B7DCULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xB7B2807D02009AFFULL + 0xC2803F3EDAF1F681ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xEA406DCC90D832DFULL + 0xBBD89A8FA7269E68ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xD687C66480C50EA1ULL + 0xA64A7FFCAE467F82ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xD978A4D763F11925ULL + 0xA19299CAACC743E4ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xC501094D2461F65FULL + 0xFE2B64A1291E7FD5ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xFAC8D7D9A56285DBULL + 0xE4DD67A41BCF7232ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xB5D90FCD8B73F07DULL + 0xC0AAD74E742E8D16ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x9AED8517B472BF5FULL + 0xD818DEB385F05558ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xA2BC6F375D2AC979ULL + 0x8657E9A3DAE38761ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xA44CDD207B7FE01FULL + 0xFCB278E0520830B5ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x8C933E2E2453051DULL + 0xD08070078BDB04ABULL);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 968U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 609U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5040U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((aIndex + 3120U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCarry, 18U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCross, 57U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (((aWandererJ + RotL64(aScatter, 11U)) + RotL64(aCarry, 11U)) + 16802219662864902427U) + aNonceWordK;
            aOrbiterG = (aWandererC + RotL64(aPrevious, 21U)) + 14332033461409490629U;
            aOrbiterK = (((aWandererH + RotL64(aIngress, 37U)) + RotL64(aCarry, 47U)) + 8781794298640286845U) + aOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (((aWandererA + RotL64(aCross, 48U)) + 8459933908074937264U) + aOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1]) + aNonceWordD;
            aOrbiterF = (aWandererE + RotL64(aScatter, 3U)) + 1883580287986004426U;
            aOrbiterA = ((aWandererF + RotL64(aCross, 57U)) + 17500258188004626118U) + aNonceWordO;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 27U)) + RotL64(aCarry, 29U)) + 7934811305150872870U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 6380363892361098905U) + aNonceWordE;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 12623079132626676910U;
            aOrbiterK = RotL64((aOrbiterK * 12406671746344127399U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 10455208121949202703U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 8805532707916767629U) ^ aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 666082374369701881U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 9161544391400377699U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 3501434325829663268U) ^ aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7933545151293799637U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 651783304096081996U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterK) ^ 441505031509930622U) ^ aOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 8045355432310956143U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 1771159983581326424U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 15227946417377695989U;
            aOrbiterI = RotL64((aOrbiterI * 1563141188972797601U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 4153717524193279095U) + aNonceWordI;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 4404521756523902829U;
            aOrbiterB = RotL64((aOrbiterB * 1410342912973206203U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 6231945075461813285U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 3864780227164426690U;
            aOrbiterG = RotL64((aOrbiterG * 18031353247480673617U), 19U);
            //
            aIngress = RotL64(aOrbiterG, 21U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 58U) + aOrbiterK) + RotL64(aOrbiterA, 5U)) + aWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 11U) + aOrbiterJ) + RotL64(aOrbiterG, 29U)) + aNonceWordN);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 21U) + RotL64(aOrbiterI, 43U)) + aOrbiterF);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterF, 50U));
            aWandererE = aWandererE + ((((RotL64(aCross, 41U) + aOrbiterJ) + RotL64(aOrbiterK, 11U)) + RotL64(aCarry, 21U)) + aWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterA, 23U)) + aOrbiterB);
            aWandererK = aWandererK + (((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 37U)) + aOrbiterG) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 58U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordN;
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 16083U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11693U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15352U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10052U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 19U) ^ RotL64(aIngress, 37U)) + (RotL64(aCarry, 50U) + RotL64(aPrevious, 5U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 29U)) + RotL64(aCarry, 53U)) + 9446153639709651566U;
            aOrbiterF = (((aWandererD + RotL64(aIngress, 42U)) + RotL64(aCarry, 19U)) + 10550762260670758167U) + aOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = (aWandererG + RotL64(aScatter, 13U)) + 7062634922142578383U;
            aOrbiterH = ((aWandererH + RotL64(aCross, 51U)) + RotL64(aCarry, 5U)) + 9178499097812764515U;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 19U)) + 6887103379773525538U) + aNonceWordG;
            aOrbiterC = (((aWandererJ + RotL64(aCross, 5U)) + 6239750312052010257U) + aOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordN;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 57U)) + 17645022614523287959U) + aNonceWordO;
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 3639618183259408272U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 3131737117548745095U;
            aOrbiterG = RotL64((aOrbiterG * 6585057380704940395U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 7253994382396406554U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 15217993711938379561U) ^ aOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17853313384747259923U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 12594152227603630033U) + aOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 11250170200489647869U) ^ aOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 546800378327864723U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 12936942656624279424U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 10990736056052106149U) ^ aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7123916809953459187U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 12787293075893090465U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 17154990205620778151U;
            aOrbiterE = RotL64((aOrbiterE * 10031369940028159521U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 1270827262969060301U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 17337623431665013136U;
            aOrbiterC = RotL64((aOrbiterC * 1517262088236356107U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 830330490987911853U) + aNonceWordA;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 6828309232554560547U;
            aOrbiterA = RotL64((aOrbiterA * 9742464176986145819U), 53U);
            //
            aIngress = RotL64(aOrbiterB, 35U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterA, 48U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterG, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterB, 4U)) + aOrbiterH);
            aWandererA = aWandererA + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 37U)) + aOrbiterE) + RotL64(aCarry, 5U)) + aNonceWordL);
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 29U)) + aOrbiterG) + aNonceWordH) + aWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 43U) + aOrbiterF) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 22U) + RotL64(aOrbiterG, 57U)) + aOrbiterB);
            aWandererG = aWandererG + ((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 23U)) + aOrbiterG);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterC, 51U)) + aOrbiterE) + aWandererUpdateSaltD[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 20U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + RotL64(aWandererG, 43U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ aNonceWordH;
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 18631U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((aIndex + 21593U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20992U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((aIndex + 23428U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aIngress, 43U)) + (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 56U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererB + RotL64(aIngress, 35U)) + 16462052553719977502U) + aNonceWordJ;
            aOrbiterE = (((aWandererD + RotL64(aScatter, 11U)) + RotL64(aCarry, 19U)) + 12337064059566619581U) + aNonceWordK;
            aOrbiterC = ((aWandererC + RotL64(aCross, 50U)) + 15801005007094515447U) + aOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 21U)) + RotL64(aCarry, 3U)) + 8228706742665081656U;
            aOrbiterI = ((aWandererH + RotL64(aCross, 29U)) + 11006723027845190869U) + aNonceWordE;
            aOrbiterG = (((aWandererI + RotL64(aIngress, 3U)) + RotL64(aCarry, 47U)) + 18173765337829177450U) + aOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 43U)) + 530215083653542558U;
            //
            aOrbiterB = (((aOrbiterB + aOrbiterE) + 6608611827035564511U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordI;
            aOrbiterC = (((aOrbiterC ^ aOrbiterB) ^ 2246051826221626809U) ^ aOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 6333352641495253539U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 5228575308895381421U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 10999213210689606857U) ^ aNonceWordB;
            aOrbiterE = RotL64((aOrbiterE * 5467601259546342925U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 3773371037240485696U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 8887985779436152504U;
            aOrbiterB = RotL64((aOrbiterB * 698713082830739677U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 11150566414723818350U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 8336366151003049546U) ^ aOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9033771197242493699U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 13233968794237090787U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 8172558473508478819U;
            aOrbiterI = RotL64((aOrbiterI * 17837070423649268435U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 133564480283347997U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 15104810248883567064U;
            aOrbiterG = RotL64((aOrbiterG * 706802420642303533U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 9138629520201127075U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 13993086066341664080U;
            aOrbiterK = RotL64((aOrbiterK * 4875046427147105077U), 35U);
            //
            aIngress = RotL64(aOrbiterI, 43U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterC, 60U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aCross, 11U) + aOrbiterB) + RotL64(aOrbiterF, 60U)) + aWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 21U) + aOrbiterK) + RotL64(aOrbiterE, 47U)) + RotL64(aCarry, 35U)) + aNonceWordA);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 5U)) + aOrbiterF) + aWandererUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 5U) + aOrbiterG) + RotL64(aOrbiterC, 21U)) + RotL64(aCarry, 11U)) + aNonceWordO);
            aWandererH = aWandererH ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterK, 37U)) + aOrbiterG);
            aWandererI = aWandererI + (((RotL64(aScatter, 38U) + aOrbiterC) + RotL64(aOrbiterE, 27U)) + aNonceWordH);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterB, 11U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererH, 6U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererJ, 11U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordN;
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 30644U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((aIndex + 32141U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31502U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneD[((aIndex + 27803U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCross, 60U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCarry, 11U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererD + RotL64(aCross, 5U)) + RotL64(aCarry, 37U)) + 14624277139785904404U;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 53U)) + 6966977309498165611U;
            aOrbiterI = (((aWandererH + RotL64(aIngress, 21U)) + RotL64(aCarry, 21U)) + 205536824352530761U) + aNonceWordD;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 27U)) + 16629575265808255692U) + aOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aWandererJ + RotL64(aIngress, 37U)) + 596881340147972746U;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 14U)) + RotL64(aCarry, 3U)) + 11944412799107412650U;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 43U)) + 4615021315668210206U) + aOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 8497630055977606216U) + aNonceWordA;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 11131601107309336885U;
            aOrbiterI = RotL64((aOrbiterI * 18028349768453554935U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 5935883479805510099U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 15629346719765798174U;
            aOrbiterH = RotL64((aOrbiterH * 8535523790685945275U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 5279128339113651273U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 16778365912440331821U;
            aOrbiterK = RotL64((aOrbiterK * 705421028266789241U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 16003052937645491524U) + aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 6723226158737614764U;
            aOrbiterD = RotL64((aOrbiterD * 16690657664909260573U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 9785784358981219543U) + aNonceWordJ;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 10055457337292292710U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17919129940751761111U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 11779163108592974175U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 1177999477942202687U;
            aOrbiterB = RotL64((aOrbiterB * 13475069421684114643U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 9190694445141492214U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 15605342360346353457U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14547769706392595647U), 57U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 11U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 30U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + RotL64(aOrbiterF, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 41U) + aOrbiterK) + RotL64(aOrbiterE, 51U)) + aNonceWordO);
            aWandererG = aWandererG + ((((RotL64(aScatter, 26U) + aOrbiterE) + RotL64(aOrbiterF, 44U)) + RotL64(aCarry, 43U)) + aWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 11U) + aOrbiterH) + RotL64(aOrbiterD, 11U)) + aNonceWordP);
            aWandererI = aWandererI + ((((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterI, 21U)) + RotL64(aCarry, 19U)) + aWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 5U)) + aOrbiterE) + aNonceWordF);
            aWandererK = aWandererK + ((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 27U)) + aOrbiterI);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterI, 57U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (RotL64(aWandererK, 48U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ aNonceWordO;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x904DB925F079139BULL + 0xD6F5C31685A643BEULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xDF0D0BE17EF9A95DULL + 0xE954FC9F409D3537ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x9FF82773615F484BULL + 0x8321641902985B6DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xC49B38C3DB211F3DULL + 0xF9F255700B7C28DAULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x8904DFCAC9DD03FBULL + 0xB11F0E150D4326F4ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xBC1E45380784A221ULL + 0xB2503898DD4ACCEAULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xAE5EB5FA6E5F238FULL + 0xCADC30039CCD9C36ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x9E8237F0BCBCAE8FULL + 0x96D056D3D45BF2DAULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x91303D0E31179689ULL + 0xA38D35D90CDF4945ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xAD425253B12354B1ULL + 0x891C7522C591C07CULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xFC1B041515C7212FULL + 0xD010AA24C397FAD1ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xF927AEAB42386E7DULL + 0xBACD002BDCD888EEULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xE4E71CD9D70E89BBULL + 0xF04BC0E48524B5D3ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x8A1618B09EDF223DULL + 0x869A6FEED0A389EAULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xE3238687A8FA5E71ULL + 0xF1F78711BDB047F2ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xDED8A9EEC99FE47BULL + 0xEFCC5C13A218C198ULL);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 959U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneC[((aIndex + 6702U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 6023U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneA[((aIndex + 8022U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCross, 35U)) ^ (RotL64(aCarry, 51U) + RotL64(aPrevious, 20U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (((aWandererH + RotL64(aPrevious, 4U)) + RotL64(aCarry, 57U)) + 17454559218352016650U) + aOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = ((aWandererD + RotL64(aScatter, 13U)) + RotL64(aCarry, 13U)) + 8005709669325164803U;
            aOrbiterJ = (aWandererE + RotL64(aIngress, 35U)) + 13393741948412816357U;
            aOrbiterI = ((aWandererF + RotL64(aCross, 27U)) + 3665865624348875553U) + aNonceWordE;
            aOrbiterE = (aWandererK + RotL64(aScatter, 19U)) + 8334142570031883436U;
            aOrbiterB = ((aWandererA + RotL64(aCross, 53U)) + RotL64(aCarry, 27U)) + 17226066128706139657U;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 43U)) + 3319093033121522613U) + aOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 6657535603401588798U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 5469746182326331147U) ^ aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11315450342347794329U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 17846791786050221418U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 15939541003714896288U) ^ aNonceWordB;
            aOrbiterE = RotL64((aOrbiterE * 1400351482213119809U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 12076763190461077406U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 3594038213596405284U;
            aOrbiterB = RotL64((aOrbiterB * 10244002692575821495U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 8301291631324464622U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 8460406137668390582U;
            aOrbiterG = RotL64((aOrbiterG * 9117147929757711595U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 7612394867020871200U) + aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 8525076134853103975U;
            aOrbiterF = RotL64((aOrbiterF * 5790440201072204659U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 11929899088215090379U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 7119509166360685726U;
            aOrbiterI = RotL64((aOrbiterI * 1662341427992528823U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 5081078459225240607U) + aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 17149991983909906705U;
            aOrbiterA = RotL64((aOrbiterA * 950223374568067343U), 3U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 27U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 42U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aScatter, 57U) + aOrbiterF) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 23U)) + aWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 41U)) + aOrbiterE);
            aWandererK = aWandererK + ((((RotL64(aCross, 35U) + RotL64(aOrbiterB, 27U)) + aOrbiterI) + RotL64(aCarry, 41U)) + aWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 23U) + aOrbiterI) + RotL64(aOrbiterG, 5U)) + aNonceWordA);
            aWandererF = aWandererF + ((RotL64(aIngress, 6U) + RotL64(aOrbiterB, 18U)) + aOrbiterA);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 35U)) + aOrbiterG) + aNonceWordO);
            aWandererH = aWandererH + (((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterE, 11U)) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 20U));
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + RotL64(aWandererD, 13U);
            aCarry = aCarry + RotL64(aIngress, 42U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordF);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 9934U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 13780U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 9238U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 8935U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 51U) ^ RotL64(aCross, 5U)) + (RotL64(aCarry, 36U) + RotL64(aIngress, 23U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (((aWandererC + RotL64(aCross, 41U)) + 6318740973868639425U) + aOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 29U)) + RotL64(aCarry, 41U)) + 5487840061430920881U;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 57U)) + 10258706763248072672U;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 57U)) + 18356875269730338208U;
            aOrbiterJ = (aWandererH + RotL64(aIngress, 20U)) + 12883160282903147010U;
            aOrbiterC = ((aWandererB + RotL64(aCross, 51U)) + 1010140474942697730U) + aOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 35U)) + RotL64(aCarry, 21U)) + 17733939421700898293U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 13693055887924981201U) + aOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 14574732452793385269U;
            aOrbiterE = RotL64((aOrbiterE * 9373765929885750185U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 10832873941223609012U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 8212600587135328040U;
            aOrbiterA = RotL64((aOrbiterA * 5334613996794796145U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 5312744319781971178U) + aNonceWordC;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 6173741211706546923U;
            aOrbiterD = RotL64((aOrbiterD * 12854414066390848249U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 3693249147883790810U) + aNonceWordN;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 18365859989736602556U;
            aOrbiterH = RotL64((aOrbiterH * 3348463719324104997U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 10645056678337549771U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 1175668356822251045U;
            aOrbiterJ = RotL64((aOrbiterJ * 6579675292775345579U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 13556844570541823717U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 4790355739411849736U;
            aOrbiterC = RotL64((aOrbiterC * 4083544011788850307U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 14905575502272644116U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 17047244574558476634U) ^ aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2356386971503880047U), 13U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 5U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + (RotL64(aOrbiterH, 56U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterC, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterC, 13U)) + aOrbiterA);
            aWandererB = aWandererB + (((((RotL64(aCross, 3U) + RotL64(aOrbiterH, 20U)) + aOrbiterC) + RotL64(aCarry, 27U)) + aNonceWordI) + aWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 60U) + aOrbiterF) + RotL64(aOrbiterA, 53U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 53U) + aOrbiterJ) + RotL64(aOrbiterD, 3U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterF, 41U)) + aWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 11U) + aOrbiterE) + RotL64(aOrbiterA, 35U)) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterE, 29U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererG, 30U) ^ aWandererA);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + RotL64(aWandererB, 43U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordJ);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22749U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22161U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 24025U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 17791U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCarry, 41U)) + (RotL64(aPrevious, 57U) + RotL64(aCross, 6U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererF + RotL64(aScatter, 13U)) + 380024772508948442U;
            aOrbiterC = ((aWandererE + RotL64(aCross, 21U)) + RotL64(aCarry, 19U)) + 7649029098162567210U;
            aOrbiterJ = (aWandererG + RotL64(aIngress, 39U)) + 5329304598870421851U;
            aOrbiterK = ((((aWandererI + RotL64(aPrevious, 3U)) + RotL64(aCarry, 35U)) + 12306118665045151326U) + aOrbiterAssignSaltD[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordA;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 46U)) + 960751560457324256U) + aNonceWordD;
            aOrbiterH = (((aWandererC + RotL64(aScatter, 57U)) + RotL64(aCarry, 57U)) + 3244070254386191876U) + aOrbiterAssignSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 27U)) + 15733408571609521746U) + aNonceWordM;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 17623448932647018544U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterE) ^ 8787759896149035829U) ^ aOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterJ = RotL64((aOrbiterJ * 7092515868845497573U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 14741681792348288162U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterK) ^ 8801731213568307302U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterC = RotL64((aOrbiterC * 12127126999570616489U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 9872248187499779222U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 15407371518644528235U;
            aOrbiterE = RotL64((aOrbiterE * 1245102406469471673U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 4242060317152943062U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 9942784962409917541U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 888649755587764533U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 7296348796484458631U) + aNonceWordB;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 15061417216070157797U;
            aOrbiterD = RotL64((aOrbiterD * 10349554676953256231U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 3233185810644297433U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 9241229457641024287U;
            aOrbiterH = RotL64((aOrbiterH * 2728237515724597517U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 8464051359381554575U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 3307872165699029375U) ^ aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4859663401033023433U), 27U);
            //
            aIngress = RotL64(aOrbiterD, 22U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 37U));
            aIngress = aIngress + RotL64(aOrbiterE, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterD, 60U)) + aOrbiterG) + RotL64(aCarry, 19U)) + aNonceWordI);
            aWandererC = aWandererC ^ ((((RotL64(aScatter, 30U) + aOrbiterK) + RotL64(aOrbiterH, 5U)) + aNonceWordE) + aWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterG, 53U)) + RotL64(aCarry, 53U)) + aWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 43U) + aOrbiterK) + RotL64(aOrbiterD, 13U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterG, 23U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterG, 41U)) + aOrbiterH) + aNonceWordJ);
            aWandererG = aWandererG + ((RotL64(aCross, 13U) + RotL64(aOrbiterK, 29U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererD, 28U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + RotL64(aWandererG, 23U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = aCarry ^ aNonceWordM;
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 26430U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28743U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27359U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 25889U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 20U) ^ RotL64(aCarry, 39U)) ^ (RotL64(aPrevious, 51U) + RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererK + RotL64(aIngress, 43U)) + 7722279280863371124U) + aNonceWordM;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 13U)) + RotL64(aCarry, 41U)) + 11584220561732385598U;
            aOrbiterC = (((aWandererD + RotL64(aPrevious, 4U)) + 7834679350105534657U) + aOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordF;
            aOrbiterG = (aWandererI + RotL64(aScatter, 57U)) + 11347994382444180879U;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 51U)) + RotL64(aCarry, 5U)) + 9449903188047063431U;
            aOrbiterI = (((aWandererA + RotL64(aScatter, 19U)) + RotL64(aCarry, 29U)) + 6516243976652795170U) + aOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = (aWandererC + RotL64(aPrevious, 37U)) + 8420815253991184777U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 9081386852515170937U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 14375955191735286867U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2772840314542262283U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 880757589768436072U) + aOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 3349856625725164229U;
            aOrbiterI = RotL64((aOrbiterI * 681514212582331781U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 7826309957607577207U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 8057435761214313635U) ^ aNonceWordL;
            aOrbiterJ = RotL64((aOrbiterJ * 4718430712767038607U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 9565237500443303103U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 15893066735310588501U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8457633439171452397U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 3276844534476430842U) + aNonceWordI;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 6828644383891274120U;
            aOrbiterA = RotL64((aOrbiterA * 979580351653410157U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 2815676923011504251U) + aOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 5030251870850928417U) ^ aNonceWordP;
            aOrbiterG = RotL64((aOrbiterG * 7075653570570819253U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 13464083008377887034U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 8994560761846897590U;
            aOrbiterD = RotL64((aOrbiterD * 9892839554658865143U), 23U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterA, 57U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterG, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 60U) + aOrbiterJ) + RotL64(aOrbiterF, 5U));
            aWandererI = aWandererI + ((RotL64(aCross, 51U) + aOrbiterJ) + RotL64(aOrbiterC, 13U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterG, 29U)) + aOrbiterI) + aWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererG = aWandererG + (((((RotL64(aIngress, 23U) + RotL64(aOrbiterD, 56U)) + aOrbiterJ) + RotL64(aCarry, 5U)) + aNonceWordE) + aWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 37U) + aOrbiterI) + RotL64(aOrbiterA, 43U));
            aWandererD = aWandererD + ((((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterA, 35U)) + RotL64(aCarry, 57U)) + aNonceWordK);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterI, 19U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 58U));
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordJ);
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

void TwistExpander_BaseBall_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x950E37B358D898D5ULL + 0xF96FA4C674979A32ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xF3A153D94D6CAB89ULL + 0xD6A6F128F5910AE1ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xA664D0A7F5507F5DULL + 0x93146CDDB499DE99ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x82DE6034DE521FCDULL + 0xD08611638DC2FCE5ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xB73EF3AF51B24A13ULL + 0xE13EFDA637E158B4ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xD4D9B48BF68E51B1ULL + 0xFA1894F62C7FCF77ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x917039063330458BULL + 0xE8677EE36A2F5878ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x9400BA9F927BAEF5ULL + 0x81C2074EC289DA6DULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x975514F8D631F871ULL + 0xC50288D59E9E7FC2ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xEEBEFFFF618C069BULL + 0xA78963975F558AAEULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xAD2B06E9C56DEB55ULL + 0x917E937A89E314FDULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x8DE7675D6CABEF1DULL + 0xFEADB064EF634C11ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x9ECEDECB9BFAE1D5ULL + 0xD74008C6FA840F4EULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x823E5C7B80EBED71ULL + 0xB748B18733EBBC74ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xBC1EBD438B80EF7FULL + 0x99B6E1103EC25515ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xF20AD94BC57E410BULL + 0xFE12E3741DF7A9BFULL);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 5415U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((aIndex + 1207U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2766U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 2411U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCross, 37U)) + (RotL64(aCarry, 50U) + RotL64(aIngress, 3U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererA + RotL64(aCross, 41U)) + 3199575576585871314U;
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 21U)) + 2533378188975571824U) + aOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aPrevious, 47U)) + 6819782112558312658U;
            aOrbiterG = (aWandererD + RotL64(aScatter, 43U)) + 12690060987724798497U;
            aOrbiterE = (aWandererG + RotL64(aIngress, 6U)) + 7088375139715629606U;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 37U)) + 17785618677423695666U) + aNonceWordB;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 53U)) + RotL64(aCarry, 37U)) + 1714999280296491277U;
            aOrbiterD = (((aWandererK + RotL64(aCross, 51U)) + RotL64(aCarry, 21U)) + 17611338506932491624U) + aOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (aWandererB + RotL64(aIngress, 3U)) + 6475727359297421201U;
            aOrbiterK = (aWandererC + RotL64(aPrevious, 19U)) + 2347744591204119530U;
            aOrbiterC = ((aWandererH + RotL64(aScatter, 14U)) + RotL64(aCarry, 43U)) + 2739317903351401068U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 8663535261373274338U) + aNonceWordP;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 8205245127823536479U;
            aOrbiterA = RotL64((aOrbiterA * 13857005110466856439U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 8916510616749754516U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 3944805940148512932U;
            aOrbiterF = RotL64((aOrbiterF * 18082271583211389701U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 14094751253118853302U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 14094299829196076311U;
            aOrbiterJ = RotL64((aOrbiterJ * 6370012560657108493U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 3940673811518673802U) + aNonceWordA;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 3015106523254484839U;
            aOrbiterG = RotL64((aOrbiterG * 9655401190755573379U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 15404103131982599922U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 1828655763233900875U;
            aOrbiterH = RotL64((aOrbiterH * 13024358077740310049U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 1236981890899916502U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 18208975564570342697U;
            aOrbiterI = RotL64((aOrbiterI * 4577109989465876801U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 17882273895471449661U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 16196010765612713713U;
            aOrbiterC = RotL64((aOrbiterC * 15624856645134182005U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 14639250100311162559U) + aNonceWordO;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 9139027997336903273U;
            aOrbiterB = RotL64((aOrbiterB * 1853126389565574293U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 16848571995585465845U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 15901000078517800358U;
            aOrbiterE = RotL64((aOrbiterE * 11617866400577762383U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 9405166641274108606U) + aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 6776079798531281127U;
            aOrbiterD = RotL64((aOrbiterD * 6914644957401512339U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 15056085197286596847U) + aOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 3199575576585871314U;
            aOrbiterK = RotL64((aOrbiterK * 15940936753708416817U), 35U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterJ, 35U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 39U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + (RotL64(aOrbiterG, 54U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterA, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterG, 53U)) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 6U) + aOrbiterC) + RotL64(aOrbiterE, 47U));
            aWandererI = aWandererI + (((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 18U)) + aOrbiterJ) + aWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterB, 41U)) + aOrbiterD);
            aWandererB = aWandererB + (((RotL64(aScatter, 11U) + aOrbiterB) + RotL64(aOrbiterC, 13U)) + aNonceWordI);
            aWandererF = aWandererF ^ ((RotL64(aCross, 41U) + aOrbiterK) + RotL64(aOrbiterI, 23U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 37U) + aOrbiterF) + RotL64(aOrbiterJ, 5U)) + aWandererUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 26U) + aOrbiterB) + RotL64(aOrbiterK, 39U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterH, 35U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterB, 29U)) + aNonceWordH);
            aWandererA = aWandererA + (((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterA, 10U)) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 24U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + RotL64(aWandererI, 21U);
            aCarry = aCarry + RotL64(aIngress, 46U);
            aCarry = aCarry ^ aNonceWordA;
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 14898U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11248U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9419U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 11578U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCross, 5U)) + (RotL64(aCarry, 43U) ^ RotL64(aPrevious, 22U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererD + RotL64(aScatter, 24U)) + RotL64(aCarry, 3U)) + 5573188770530340913U;
            aOrbiterE = (((aWandererK + RotL64(aIngress, 35U)) + RotL64(aCarry, 37U)) + 1431772230889897111U) + aNonceWordJ;
            aOrbiterG = (aWandererB + RotL64(aPrevious, 29U)) + 4809192776429682319U;
            aOrbiterD = (aWandererJ + RotL64(aCross, 27U)) + 5576603692574369341U;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 5U)) + RotL64(aCarry, 27U)) + 2720143226007220386U;
            aOrbiterF = (aWandererG + RotL64(aScatter, 39U)) + 17220328778565331629U;
            aOrbiterH = (((aWandererC + RotL64(aIngress, 42U)) + 9629485808442089423U) + aOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordN;
            aOrbiterA = (((aWandererE + RotL64(aCross, 37U)) + 1136998437010390983U) + aOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordD;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 21U)) + 11893390497814523841U;
            aOrbiterI = (aWandererA + RotL64(aScatter, 47U)) + 1764986431917532370U;
            aOrbiterC = (aWandererH + RotL64(aCross, 3U)) + 1741014798007010376U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 12221368453236547044U) + aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = (((aOrbiterG ^ aOrbiterB) ^ 7694538641172350430U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterG = RotL64((aOrbiterG * 8439120733670016501U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 17472344518811560603U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 3308740700728172984U;
            aOrbiterE = RotL64((aOrbiterE * 15290400462887712083U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 9535358833412446771U) + aNonceWordO;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 11192312491731312451U;
            aOrbiterK = RotL64((aOrbiterK * 17405609148475445743U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 14850451970047190039U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 11932493299452443256U;
            aOrbiterH = RotL64((aOrbiterH * 7964808728820467795U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 5972619895614731870U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 17174497535809891690U;
            aOrbiterJ = RotL64((aOrbiterJ * 15471084511364572533U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 17412894714378898351U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 14675615208706549810U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7864845089606499769U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 16116792108013658523U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 9702262005960966336U;
            aOrbiterD = RotL64((aOrbiterD * 970452849653781703U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 17337264966818542841U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 7004462033775827275U;
            aOrbiterF = RotL64((aOrbiterF * 11943575980344402681U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 17499850384482055438U) + aNonceWordB;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 1839357713256560566U;
            aOrbiterA = RotL64((aOrbiterA * 12943750650487416281U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 8144238113917577524U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 888195876227325908U;
            aOrbiterI = RotL64((aOrbiterI * 7941506708630993709U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 5081763359501717653U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 5573188770530340913U;
            aOrbiterC = RotL64((aOrbiterC * 9699901099898698965U), 3U);
            //
            aIngress = RotL64(aOrbiterA, 11U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 48U));
            aIngress = aIngress + RotL64(aOrbiterB, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterD, 35U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 26U) + aOrbiterH) + RotL64(aOrbiterK, 27U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterA, 5U)) + aOrbiterF);
            aWandererE = aWandererE + ((((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterK, 48U)) + RotL64(aCarry, 11U)) + aNonceWordP);
            aWandererG = aWandererG ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterD, 21U)) + aOrbiterK) + aWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 11U) + aOrbiterJ) + RotL64(aOrbiterC, 41U)) + aWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterK, 37U)) + aOrbiterI);
            aWandererD = aWandererD + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterC, 19U)) + aOrbiterG);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 4U) + aOrbiterA) + RotL64(aOrbiterK, 39U)) + aNonceWordG);
            aWandererH = aWandererH + (((RotL64(aCross, 53U) + RotL64(aOrbiterG, 46U)) + aOrbiterB) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 41U) + aOrbiterG) + RotL64(aOrbiterK, 57U)) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererF, 12U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = aCarry ^ aNonceWordI;
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 20551U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 21257U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21402U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((aIndex + 19150U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 24U)) ^ (RotL64(aIngress, 37U) ^ RotL64(aCross, 57U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererD + RotL64(aIngress, 27U)) + 5697928251815176134U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 13U)) + RotL64(aCarry, 47U)) + 337587740689259575U;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 36U)) + 4927686903263973950U;
            aOrbiterD = (((aWandererF + RotL64(aCross, 41U)) + 3742409032569801033U) + aOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1]) + aNonceWordN;
            aOrbiterF = ((aWandererC + RotL64(aIngress, 29U)) + 1608092659172197650U) + aOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aCross, 3U)) + 15848744267145717509U) + aNonceWordO;
            aOrbiterA = (aWandererE + RotL64(aPrevious, 43U)) + 15300174177963339253U;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 39U)) + 14162868453323648628U) + aNonceWordC;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 57U)) + RotL64(aCarry, 3U)) + 12020167069983729869U;
            aOrbiterJ = ((aWandererH + RotL64(aCross, 50U)) + RotL64(aCarry, 19U)) + 16259538291658723956U;
            aOrbiterB = (aWandererB + RotL64(aScatter, 47U)) + 8516686212464112245U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 3722184575520553132U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 5663609293306386784U;
            aOrbiterK = RotL64((aOrbiterK * 14364218128780764749U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 15265344442454471986U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 3050323350098829515U;
            aOrbiterI = RotL64((aOrbiterI * 5890624677162388135U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 1093356813820599238U) + aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 15167726103772238440U;
            aOrbiterH = RotL64((aOrbiterH * 5719466863561311069U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 15170797965325981472U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 17826286701992981628U) ^ aNonceWordH;
            aOrbiterF = RotL64((aOrbiterF * 11186808881726573677U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 14710892030473425181U) + aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 397194787697553904U;
            aOrbiterE = RotL64((aOrbiterE * 14368930300818752833U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 1273724124862533034U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 13018397560392545616U;
            aOrbiterJ = RotL64((aOrbiterJ * 4644812473262395329U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 9638716186445643730U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 7255587739807843785U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6055682981584011189U), 51U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterG) + 9272350563697399628U) + aOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1]) + aNonceWordP;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 1040729335295009339U;
            aOrbiterD = RotL64((aOrbiterD * 17825687660830291443U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 12128124729613601747U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 2285238815562202219U;
            aOrbiterA = RotL64((aOrbiterA * 15398840993074390573U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 6339113298619163493U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 5911895708485037040U;
            aOrbiterG = RotL64((aOrbiterG * 3271006139923200439U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 7601399508218901328U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 5697928251815176134U;
            aOrbiterB = RotL64((aOrbiterB * 8184257916861355735U), 47U);
            //
            aIngress = RotL64(aOrbiterI, 43U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + (RotL64(aOrbiterE, 50U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 51U) + aOrbiterF) + RotL64(aOrbiterK, 48U));
            aWandererE = aWandererE + (((RotL64(aScatter, 37U) + RotL64(aOrbiterI, 23U)) + aOrbiterG) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 21U)) + aOrbiterK);
            aWandererC = aWandererC + (((RotL64(aCross, 48U) + RotL64(aOrbiterA, 11U)) + aOrbiterI) + aWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 57U) + aOrbiterF) + RotL64(aOrbiterD, 27U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 35U) + aOrbiterD) + RotL64(aOrbiterH, 39U)) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterH, 57U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 34U)) + aOrbiterE) + aWandererUpdateSaltB[((aIndex + 20U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 14U) + RotL64(aOrbiterJ, 43U)) + aOrbiterA);
            aWandererI = aWandererI + (((RotL64(aPrevious, 53U) + aOrbiterD) + RotL64(aOrbiterC, 41U)) + aNonceWordD);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 21U) + aOrbiterG) + RotL64(aOrbiterE, 37U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 46U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + RotL64(aWandererA, 12U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 28264U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 25997U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 32016U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneD[((aIndex + 26001U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 11U)) + (RotL64(aIngress, 58U) ^ RotL64(aCross, 37U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererB + RotL64(aScatter, 3U)) + 16424657151168221875U) + aOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aCross, 12U)) + 17150123681886380361U;
            aOrbiterC = (aWandererH + RotL64(aPrevious, 51U)) + 16041993588694572757U;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 29U)) + 9871185846434828537U) + aOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aScatter, 47U)) + 11227236398354430757U;
            aOrbiterB = (((aWandererE + RotL64(aCross, 37U)) + RotL64(aCarry, 19U)) + 5399325217402192631U) + aNonceWordI;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 14U)) + RotL64(aCarry, 43U)) + 9248828789282890454U;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 35U)) + RotL64(aCarry, 29U)) + 9041370494203701062U;
            aOrbiterD = (aWandererA + RotL64(aScatter, 41U)) + 14944424084524970764U;
            aOrbiterA = (aWandererK + RotL64(aIngress, 5U)) + 5481938174456671041U;
            aOrbiterI = (aWandererC + RotL64(aCross, 27U)) + 14783648629543752715U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 12355573914530445723U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 9863991559011968318U;
            aOrbiterC = RotL64((aOrbiterC * 8495251211794343179U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 16149688605937250965U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 106041828692026825U;
            aOrbiterG = RotL64((aOrbiterG * 12199934305374582599U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 8076098639554567792U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 11155119311895580013U) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 1495180896564818647U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 6847612160595917702U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 16094377920388017367U;
            aOrbiterE = RotL64((aOrbiterE * 4875801863643206333U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 13584719866672696684U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 13446209321646234607U) ^ aOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9945349065094781529U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 15829806645369560988U) + aOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 12573767256739062550U;
            aOrbiterD = RotL64((aOrbiterD * 5649504278826069077U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 3850030870300393809U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 11857593987748189858U;
            aOrbiterA = RotL64((aOrbiterA * 15942863910931814193U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 5505918410521728373U) + aNonceWordN;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 12949653497121247860U) ^ aOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 90944913639560027U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 2448323375614082955U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 4386059032042654583U;
            aOrbiterH = RotL64((aOrbiterH * 11730132905525317201U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 108129028178045299U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 18292666533864994149U;
            aOrbiterF = RotL64((aOrbiterF * 2599590507178673531U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 10771402979550786312U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 16424657151168221875U;
            aOrbiterK = RotL64((aOrbiterK * 6255743082177474607U), 23U);
            //
            aIngress = RotL64(aOrbiterF, 44U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + (RotL64(aOrbiterD, 51U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 21U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterH, 29U)) + aOrbiterF) + aNonceWordG);
            aWandererC = aWandererC + (((RotL64(aPrevious, 47U) + aOrbiterH) + RotL64(aOrbiterJ, 43U)) + aWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 12U) + RotL64(aOrbiterA, 52U)) + aOrbiterK);
            aWandererH = aWandererH + (((RotL64(aIngress, 27U) + aOrbiterK) + RotL64(aOrbiterJ, 19U)) + RotL64(aCarry, 43U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 5U)) + aOrbiterG);
            aWandererK = aWandererK + ((RotL64(aScatter, 23U) + RotL64(aOrbiterC, 41U)) + aOrbiterH);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterJ, 27U)) + aOrbiterE) + aWandererUpdateSaltF[((aIndex + 12U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 50U) + RotL64(aOrbiterI, 3U)) + aOrbiterF);
            aWandererD = aWandererD ^ ((RotL64(aCross, 5U) + aOrbiterB) + RotL64(aOrbiterK, 23U));
            aWandererG = aWandererG + (((RotL64(aScatter, 29U) + aOrbiterJ) + RotL64(aOrbiterD, 47U)) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 58U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 30U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + RotL64(aWandererE, 37U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordN);
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

void TwistExpander_BaseBall_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xEA957B8D54876E5FULL + 0x90CFAE6B90040BC2ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x95E7C8FA014CD973ULL + 0xD52426DB8273BF59ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xAF1E592B00C39AC5ULL + 0xBF89797473C8F303ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xBEA35FF0B75A647FULL + 0xCF68B719ACB4BF38ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x9C1562CAA128EFCDULL + 0xBD396CDFBDF39971ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x8C102FC5AA9FE9EFULL + 0xBB4DB3956F343C7DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xADCB3F05076066E3ULL + 0xD5703F96FAAA2FF8ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x92E2AB78303DA595ULL + 0x9D5FB3ACCF468013ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xB658FF7A795A5AD5ULL + 0xF406E863FEA201F9ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x8829B55EA1ECE9C1ULL + 0xE931F66851D7C75CULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x9A4EC9020412676DULL + 0xB48860EAA0892803ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x83063E2D43B7A573ULL + 0xB9D0391DAC3DB0C7ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xC8E0DF599548FC73ULL + 0x9FD30FB075742386ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x8AF9A9C01E666E57ULL + 0x848908C9AAD29161ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x992A856FC22134FFULL + 0x8B9995D2E5202D2BULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x8AEA5851A4E1F7EBULL + 0xFE3AA96099A455D5ULL);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 1290U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneC[((aIndex + 737U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 3255U)) & S_BLOCK1], 20U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 3826U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aIngress, 54U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCross, 41U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererE + RotL64(aPrevious, 40U)) + 14823268998003220191U;
            aOrbiterF = (((aWandererK + RotL64(aScatter, 53U)) + RotL64(aCarry, 35U)) + 15295237288788213847U) + aOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterI = ((aWandererG + RotL64(aCross, 47U)) + 16434853402001133899U) + aOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aIngress, 57U)) + 7555911304407871631U;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 11U)) + 14977248264994834620U) + aNonceWordJ;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 29U)) + RotL64(aCarry, 27U)) + 9707764144919392380U;
            aOrbiterD = (aWandererA + RotL64(aCross, 24U)) + 1277304385464681529U;
            aOrbiterA = (((aWandererJ + RotL64(aIngress, 5U)) + RotL64(aCarry, 43U)) + 3089786220465849395U) + aNonceWordM;
            aOrbiterH = ((aWandererH + RotL64(aCross, 35U)) + 3700503853358695085U) + aNonceWordG;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 3240054112993517371U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 16897532076915366859U;
            aOrbiterI = RotL64((aOrbiterI * 4120874717534309035U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 18167359289798364307U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 8870819278575769863U;
            aOrbiterC = RotL64((aOrbiterC * 9334066154398059075U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 15363069206212330251U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 14858164441499725158U) ^ aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14931933411393847915U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 5357144808788707522U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 2910681277417754860U) ^ aNonceWordE;
            aOrbiterH = RotL64((aOrbiterH * 13170868582159347059U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 9824408699018165151U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 368370224788793300U;
            aOrbiterK = RotL64((aOrbiterK * 14358982366258729959U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 7095398304588825115U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 11418879758164313554U;
            aOrbiterB = RotL64((aOrbiterB * 5983520332639771791U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 2171599720681913272U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 17593730219647495033U;
            aOrbiterD = RotL64((aOrbiterD * 12926053208918563087U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 17755947635188715523U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 14565740605227022106U;
            aOrbiterF = RotL64((aOrbiterF * 15866418354612945335U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 14538017880915584414U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 6174566474851449123U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 179569008593475683U), 19U);
            //
            aIngress = RotL64(aOrbiterA, 54U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 39U));
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aPrevious, 3U) + aOrbiterE) + RotL64(aOrbiterI, 23U)) + RotL64(aCarry, 5U)) + aWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 28U)) + aOrbiterI);
            aWandererE = aWandererE + (((RotL64(aIngress, 43U) + RotL64(aOrbiterD, 43U)) + aOrbiterA) + aNonceWordO);
            aWandererG = aWandererG ^ (((RotL64(aCross, 60U) + RotL64(aOrbiterC, 19U)) + aOrbiterK) + aWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 11U) + aOrbiterB) + RotL64(aOrbiterI, 53U)) + aNonceWordA);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 21U) + aOrbiterF) + RotL64(aOrbiterK, 39U));
            aWandererC = aWandererC + (((RotL64(aScatter, 53U) + aOrbiterB) + RotL64(aOrbiterC, 47U)) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterH, 3U)) + aOrbiterD) + aNonceWordC);
            aWandererI = aWandererI + ((RotL64(aPrevious, 36U) + aOrbiterF) + RotL64(aOrbiterA, 60U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + (RotL64(aWandererJ, 44U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + RotL64(aWandererD, 51U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 7792U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 10296U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 8766U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6373U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCarry, 27U)) ^ (RotL64(aCross, 57U) + RotL64(aIngress, 10U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererH + RotL64(aIngress, 57U)) + 15910560457440369082U;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 48U)) + 17953072986407436888U) + aNonceWordN;
            aOrbiterH = (aWandererI + RotL64(aPrevious, 13U)) + 15446940721193538669U;
            aOrbiterE = ((aWandererD + RotL64(aCross, 29U)) + 3020785262774422009U) + aNonceWordJ;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 5U)) + 7001288645424994404U) + aOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aCross, 35U)) + RotL64(aCarry, 35U)) + 13385250665458462689U;
            aOrbiterK = (aWandererA + RotL64(aPrevious, 24U)) + 4841895644623005949U;
            aOrbiterA = ((aWandererF + RotL64(aScatter, 19U)) + RotL64(aCarry, 27U)) + 13053476783239482065U;
            aOrbiterI = ((((aWandererJ + RotL64(aIngress, 53U)) + RotL64(aCarry, 53U)) + 641996979335975244U) + aOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1]) + aNonceWordL;
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 16211238020928688299U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 12715448751323279480U;
            aOrbiterH = RotL64((aOrbiterH * 2116880429675303291U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 17784406727699995290U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 16626339815786580778U;
            aOrbiterD = RotL64((aOrbiterD * 13940754474750138041U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 9035070625716345139U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 6085848172494001945U;
            aOrbiterK = RotL64((aOrbiterK * 10405728912339646693U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 1177103851507561053U) + aNonceWordI;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 2281901691017816407U) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 3142197009403602497U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 9040984343694325070U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 13334258224023902365U;
            aOrbiterI = RotL64((aOrbiterI * 4782523727707164869U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 1079824790138592518U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 14024082692012948652U;
            aOrbiterG = RotL64((aOrbiterG * 3219489374333737903U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 2966776524421278970U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 5510281854029308547U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9275402927591867297U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 7126632329316720048U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 1476827035602733472U;
            aOrbiterB = RotL64((aOrbiterB * 2217671289726794033U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 6470212302133184965U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 4172257438373147415U;
            aOrbiterF = RotL64((aOrbiterF * 4449314239630366533U), 57U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 13U);
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterB, 24U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterA, 29U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aCross, 24U) + RotL64(aOrbiterG, 11U)) + aOrbiterA);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 11U) + aOrbiterF) + RotL64(aOrbiterG, 37U)) + aNonceWordB);
            aWandererD = aWandererD + (((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 19U)) + aOrbiterD) + RotL64(aCarry, 41U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterK, 51U)) + aOrbiterG) + aNonceWordK);
            aWandererI = aWandererI + (((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterI, 58U)) + aWandererUpdateSaltB[((aIndex + 16U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterI, 43U)) + aOrbiterH) + aWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 47U)) + aOrbiterI) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterE, 5U)) + aOrbiterD);
            aWandererB = aWandererB + ((RotL64(aCross, 28U) + RotL64(aOrbiterA, 24U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 24U));
            aCarry = aCarry + RotL64(aWandererC, 53U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13975U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15743U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 14375U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 12536U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 37U) + RotL64(aCarry, 52U)) ^ (RotL64(aCross, 5U) + RotL64(aPrevious, 19U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererG + RotL64(aCross, 11U)) + 16183871922837164759U;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 43U)) + 7002058258090219055U) + aOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = ((aWandererA + RotL64(aIngress, 29U)) + 5650868611888303705U) + aNonceWordG;
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 23U)) + RotL64(aCarry, 41U)) + 11899839660943876690U;
            aOrbiterD = ((aWandererD + RotL64(aCross, 50U)) + RotL64(aCarry, 23U)) + 15349649504488111111U;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 5U)) + 14060149569086744970U) + aNonceWordA;
            aOrbiterK = (((aWandererB + RotL64(aPrevious, 35U)) + RotL64(aCarry, 11U)) + 12920917574225030112U) + aOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aScatter, 39U)) + 2831994965175330135U;
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 54U)) + 18312543585028439192U) + aNonceWordJ;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 11657562205118394239U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 10850792819281246052U;
            aOrbiterG = RotL64((aOrbiterG * 10663100544207879337U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 17810371216216125323U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 7963413941144223128U;
            aOrbiterB = RotL64((aOrbiterB * 534217972450595401U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 5498715358793875584U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 9256727548911651373U) ^ aOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10498848323914000989U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 17246360111302191699U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 18309978718113983369U;
            aOrbiterC = RotL64((aOrbiterC * 18267472694666221077U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 3100998994319502921U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 8129301860291235970U;
            aOrbiterD = RotL64((aOrbiterD * 17847033539279176187U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 1889641029473279114U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 16538494307002917945U;
            aOrbiterJ = RotL64((aOrbiterJ * 8081488217920885783U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 5432230549146849322U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 2634437941396090817U) ^ aNonceWordD;
            aOrbiterK = RotL64((aOrbiterK * 7612999214758935211U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 16940172599174185058U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterH) ^ 13151669140593952203U) ^ aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterE = RotL64((aOrbiterE * 16225319638131723487U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 3995064294869931681U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 913081077665768816U;
            aOrbiterH = RotL64((aOrbiterH * 9299514648768060453U), 43U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 3U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 28U));
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 51U) + aOrbiterG) + RotL64(aOrbiterC, 23U)) + aNonceWordO) + aWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 37U) + aOrbiterB) + RotL64(aOrbiterA, 58U)) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterG, 11U)) + aOrbiterA) + aNonceWordL);
            aWandererD = aWandererD + ((RotL64(aPrevious, 30U) + aOrbiterH) + RotL64(aOrbiterK, 53U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterE, 27U)) + aOrbiterH);
            aWandererC = aWandererC + (((((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 18U)) + aOrbiterJ) + RotL64(aCarry, 51U)) + aNonceWordB) + aWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 5U) + aOrbiterD) + RotL64(aOrbiterB, 3U));
            aWandererG = aWandererG + ((RotL64(aScatter, 18U) + RotL64(aOrbiterG, 47U)) + aOrbiterE);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterH, 41U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererB, 34U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordM);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 21334U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21403U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16719U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneD[((aIndex + 19160U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 24U) ^ RotL64(aPrevious, 5U)) + (RotL64(aIngress, 37U) ^ RotL64(aCarry, 51U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererG + RotL64(aScatter, 28U)) + 3650233661228036955U;
            aOrbiterD = ((aWandererE + RotL64(aIngress, 53U)) + 11607036400067735729U) + aNonceWordE;
            aOrbiterC = (((aWandererI + RotL64(aCross, 43U)) + RotL64(aCarry, 23U)) + 3899614406903883035U) + aOrbiterAssignSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 57U)) + RotL64(aCarry, 5U)) + 8159156925629965143U;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 47U)) + 7148903913967261270U;
            aOrbiterG = (aWandererH + RotL64(aCross, 21U)) + 9161665622287517848U;
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 39U)) + 2981535013474059469U) + aOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = ((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 13U)) + 15812469008200319549U;
            aOrbiterA = (aWandererA + RotL64(aIngress, 10U)) + 14687469489893270300U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 6025209349511417063U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 12964750392311112676U;
            aOrbiterC = RotL64((aOrbiterC * 12955480283032701843U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 6572355895765394340U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 3542300121890027981U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11201491178181273935U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 6477175684045398359U) + aNonceWordO;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 1081388388827929314U;
            aOrbiterB = RotL64((aOrbiterB * 8752188637514143529U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 13754328481584620771U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 3684673342659575917U;
            aOrbiterE = RotL64((aOrbiterE * 6139923312873039143U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 6542045150319909445U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 5352102692424060388U;
            aOrbiterF = RotL64((aOrbiterF * 7385758355501860261U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 9110100774657340354U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 2813273684436269057U;
            aOrbiterG = RotL64((aOrbiterG * 10468759062594022273U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 5860425751137403755U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 1598622981888978548U) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 651816500461718345U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 14710305692377606725U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 16280545617802383463U;
            aOrbiterA = RotL64((aOrbiterA * 12541767206978802063U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 6849565243667718750U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterB) ^ 12152381961996750050U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterD = RotL64((aOrbiterD * 11185935780063403807U), 23U);
            //
            aIngress = RotL64(aOrbiterH, 35U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterK, 48U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterD, 27U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterD, 47U)) + aOrbiterF);
            aWandererD = aWandererD + ((RotL64(aScatter, 50U) + RotL64(aOrbiterE, 23U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 58U)) + aOrbiterE);
            aWandererC = aWandererC + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 5U)) + aOrbiterF) + aNonceWordD);
            aWandererE = aWandererE ^ ((((RotL64(aCross, 57U) + RotL64(aOrbiterK, 11U)) + aOrbiterA) + aNonceWordP) + aWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 35U) + aOrbiterC) + RotL64(aOrbiterK, 41U)) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 23U) + aOrbiterH) + RotL64(aOrbiterG, 19U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterH, 36U)) + RotL64(aCarry, 51U)) + aWandererUpdateSaltF[((aIndex + 26U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 18U) + RotL64(aOrbiterH, 27U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (RotL64(aWandererJ, 44U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordL);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22324U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((aIndex + 27000U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26331U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((aIndex + 25897U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aIngress, 10U)) ^ (RotL64(aCross, 37U) + RotL64(aPrevious, 51U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererK + RotL64(aIngress, 43U)) + 9630214189402543339U;
            aOrbiterI = ((aWandererG + RotL64(aCross, 39U)) + 4072576573737526819U) + aNonceWordO;
            aOrbiterD = (aWandererJ + RotL64(aScatter, 23U)) + 15994787452709618869U;
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 34U)) + 6403240137132259482U;
            aOrbiterK = ((((aWandererI + RotL64(aIngress, 19U)) + RotL64(aCarry, 43U)) + 10229266900170507720U) + aOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordI;
            aOrbiterC = ((aWandererH + RotL64(aCross, 3U)) + 5025294577989748989U) + aNonceWordL;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 53U)) + 16696461238217956883U;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 11U)) + RotL64(aCarry, 21U)) + 9878318855341719119U;
            aOrbiterE = ((aWandererF + RotL64(aCross, 52U)) + 16086635438116177346U) + aOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 12295437783084203730U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 7681150419912842402U;
            aOrbiterD = RotL64((aOrbiterD * 7289497379725191451U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 2639104034287637448U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 12298170009332243573U) ^ aOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9397919591171238575U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 3485932317267669626U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 16569551670038752475U;
            aOrbiterF = RotL64((aOrbiterF * 8139802826402217631U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 4448490103784103954U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 14510534073046885941U;
            aOrbiterE = RotL64((aOrbiterE * 7777192047386438305U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 4286195398675733451U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 15790355933840266463U;
            aOrbiterH = RotL64((aOrbiterH * 13342257823027075501U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 6362891510370156055U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 15121822034579983174U;
            aOrbiterJ = RotL64((aOrbiterJ * 7268045994574844937U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 13817341015719915628U) + aNonceWordM;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 14113474087906143783U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12838910141533126059U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 9988301252236121106U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 11287477288382171758U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4979297247881426383U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 9491727010910328644U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 7961202721830514030U;
            aOrbiterK = RotL64((aOrbiterK * 16300364540313620767U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 29U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + RotL64(aOrbiterF, 14U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aIngress, 19U) + aOrbiterH) + RotL64(aOrbiterD, 24U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 39U)) + aOrbiterE);
            aWandererG = aWandererG + ((RotL64(aScatter, 10U) + RotL64(aOrbiterK, 3U)) + aOrbiterD);
            aWandererE = aWandererE ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterH, 43U)) + aOrbiterC);
            aWandererI = aWandererI + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 29U)) + aOrbiterC) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 39U) + aOrbiterK) + RotL64(aOrbiterE, 52U)) + aNonceWordN) + aWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 52U) + RotL64(aOrbiterD, 35U)) + aOrbiterJ) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 3U) + aOrbiterF) + RotL64(aOrbiterK, 47U));
            aWandererA = aWandererA + (((RotL64(aScatter, 35U) + aOrbiterC) + RotL64(aOrbiterI, 11U)) + aWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 24U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordG;
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 32099U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32566U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31186U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((aIndex + 32047U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 4U) + RotL64(aCarry, 41U)) ^ (RotL64(aIngress, 53U) + RotL64(aCross, 21U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererF + RotL64(aCross, 13U)) + 14499676118633326000U;
            aOrbiterC = ((aWandererI + RotL64(aScatter, 27U)) + 17191273593018552288U) + aOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aIngress, 57U)) + RotL64(aCarry, 23U)) + 4085176294948097737U;
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 52U)) + 11112671474158908186U;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 5U)) + RotL64(aCarry, 11U)) + 8745787969012266485U;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 43U)) + 18074049663777707948U) + aNonceWordP;
            aOrbiterK = ((aWandererD + RotL64(aScatter, 19U)) + 2543758649719164688U) + aOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 38U)) + RotL64(aCarry, 41U)) + 4659584749412700523U;
            aOrbiterH = (aWandererB + RotL64(aIngress, 47U)) + 974639159259871273U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 9211220687971081987U) + aOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = (((aOrbiterI ^ aOrbiterF) ^ 8567024626862182714U) ^ aOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterI = RotL64((aOrbiterI * 7755874089832496393U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 5803002132294840900U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 11968489432878148467U;
            aOrbiterG = RotL64((aOrbiterG * 4501441062617123165U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 9470807228394903442U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 1692347973120388469U;
            aOrbiterK = RotL64((aOrbiterK * 17433393164156231575U), 23U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterK) + 16510815732690193145U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordB;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 755159406833096510U;
            aOrbiterD = RotL64((aOrbiterD * 14091736464659561165U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 1518824876475937620U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 701225390867330446U;
            aOrbiterH = RotL64((aOrbiterH * 12264618860580199927U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 8425976693733003889U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 7182176375442410367U;
            aOrbiterF = RotL64((aOrbiterF * 8860605703761731859U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 4546566785167467924U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 2593340999038753749U;
            aOrbiterJ = RotL64((aOrbiterJ * 10152461487764567563U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 9756331608356622299U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 5511625814747641978U;
            aOrbiterE = RotL64((aOrbiterE * 4806076157539829529U), 13U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterE) + 8694400787420160733U) + aOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1]) + aNonceWordM;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 12648969491371382682U;
            aOrbiterC = RotL64((aOrbiterC * 5346585704222643759U), 19U);
            //
            aIngress = RotL64(aOrbiterF, 29U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 18U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterH, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aCross, 5U) + aOrbiterH) + RotL64(aOrbiterE, 56U)) + aWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 57U) + aOrbiterJ) + RotL64(aOrbiterI, 5U));
            aWandererC = aWandererC + (((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 11U)) + aOrbiterI) + aNonceWordO);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterH, 51U)) + aOrbiterG);
            aWandererF = aWandererF + (((RotL64(aScatter, 30U) + aOrbiterD) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 51U) + aOrbiterJ) + RotL64(aOrbiterE, 21U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterF, 39U)) + aOrbiterK) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterD, 27U)) + aOrbiterC);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 42U) + RotL64(aOrbiterK, 60U)) + aOrbiterJ) + aNonceWordI) + aWandererUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 10U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererA, 13U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordN);
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

void TwistExpander_BaseBall_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xF17A5A01857095B5ULL + 0x9D582D231BDE25ACULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xFCDCBFF6735B2B11ULL + 0xE5F6C5AD04A6832DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xC4907C518438AC15ULL + 0xF26F4B331DEABD8DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xCAED9024C9B2A3C1ULL + 0xACCF34C2C03FA84CULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA0EBAB3213F66A7FULL + 0xB60CDC6DA0D5F696ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x8D22B5AA39D40783ULL + 0x8FB16879CB9A1652ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xC5F4BE371BB7A795ULL + 0xDE037B9257C83469ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x9AF3E3EE32640AE1ULL + 0xFEDC99C780D56CB2ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x90EA24FE3F62D86DULL + 0xFF8D32B5D7D21500ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xAF718DB0ABE405E9ULL + 0xB1260A68A068823AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xCD0B484C4D7546C1ULL + 0x8F340B5865562EDCULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xBFC1EB5F2F70435DULL + 0x85AB383EFF6D809AULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xA31C86F133A0D2AFULL + 0xBC25B41629040FECULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xB90A77A23D0AB661ULL + 0x9F610FF68EA8FAC6ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xD14AADD9BB8FA87FULL + 0xDA963CFA343E989DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xF331AED8FFA0BB53ULL + 0xACA86DB3FD27500EULL);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 986U)) & S_BLOCK1], 51U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 635U)) & W_KEY1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 4896U)) & W_KEY1], 37U) ^ RotL64(mSource[((aIndex + 4339U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 36U) ^ RotL64(aPrevious, 53U)) + (RotL64(aCarry, 23U) + RotL64(aIngress, 11U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterA = ((aWandererD + RotL64(aIngress, 5U)) + RotL64(aCarry, 23U)) + 3917730204724097072U;
            aOrbiterI = (aWandererH + RotL64(aCross, 13U)) + 1874642340716212824U;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 60U)) + RotL64(aCarry, 3U)) + 6900165757434854160U;
            aOrbiterJ = (aWandererA + RotL64(aScatter, 51U)) + 12750946097023807161U;
            aOrbiterG = (((aWandererB + RotL64(aPrevious, 43U)) + 6563216048479513594U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordO;
            aOrbiterH = (((aWandererK + RotL64(aScatter, 27U)) + 14960240191349450795U) + aPhaseAOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1]) + aNonceWordM;
            aOrbiterD = (((aWandererE + RotL64(aCross, 35U)) + RotL64(aCarry, 43U)) + 16306180275951788289U) + aNonceWordE;
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 6502066618271045547U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 6219852857850888738U) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 10892297250334325283U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 2272931312452845850U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 3028929882263199463U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11005324285856805069U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 6067393030073568112U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 10094809900437037258U;
            aOrbiterH = RotL64((aOrbiterH * 18095564940730322769U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 5962414178157074575U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 15755563045799129417U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3692603590609922031U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 6321455513889880590U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 1197435601998121700U;
            aOrbiterA = RotL64((aOrbiterA * 17693996266260557625U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 12496949381666299968U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 6357070235648527030U;
            aOrbiterJ = RotL64((aOrbiterJ * 2931486644220862433U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 8423760160877540210U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 8090246492554850768U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2949407491181921633U), 39U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 53U);
            aIngress = aIngress + (RotL64(aOrbiterD, 37U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 11U));
            aIngress = aIngress + RotL64(aOrbiterB, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterB, 5U)) + aOrbiterA) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 42U) + aOrbiterJ) + RotL64(aOrbiterH, 13U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 27U) + aOrbiterA) + RotL64(aOrbiterG, 21U));
            aWandererH = aWandererH + (((RotL64(aIngress, 11U) + RotL64(aOrbiterJ, 47U)) + aOrbiterD) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterA, 60U)) + aNonceWordN);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterA, 53U)) + aOrbiterD) + RotL64(aCarry, 5U)) + aNonceWordL);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 29U)) + aOrbiterG) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 6U));
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererE, 43U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordL);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8846U)) & S_BLOCK1], 23U) ^ RotL64(mSource[((aIndex + 7262U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 7904U)) & W_KEY1], 56U) ^ RotL64(aKeyRowReadB[((aIndex + 7779U)) & W_KEY1], 13U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 6U) + RotL64(aIngress, 21U)) ^ (RotL64(aPrevious, 35U) ^ RotL64(aCross, 47U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterJ = (((aWandererI + RotL64(aScatter, 19U)) + RotL64(aCarry, 41U)) + 14624277139785904404U) + aPhaseAOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = ((aWandererC + RotL64(aCross, 11U)) + 6966977309498165611U) + aNonceWordC;
            aOrbiterI = (((aWandererJ + RotL64(aPrevious, 5U)) + RotL64(aCarry, 11U)) + 205536824352530761U) + aPhaseAOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (aWandererD + RotL64(aIngress, 43U)) + 16629575265808255692U;
            aOrbiterA = ((aWandererA + RotL64(aCross, 60U)) + RotL64(aCarry, 57U)) + 596881340147972746U;
            aOrbiterG = ((aWandererH + RotL64(aScatter, 51U)) + 11944412799107412650U) + aNonceWordI;
            aOrbiterB = (aWandererE + RotL64(aPrevious, 37U)) + 4615021315668210206U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 8497630055977606216U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 11131601107309336885U;
            aOrbiterI = RotL64((aOrbiterI * 18028349768453554935U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 5935883479805510099U) + aNonceWordM;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 15629346719765798174U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8535523790685945275U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 5279128339113651273U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 16778365912440331821U;
            aOrbiterE = RotL64((aOrbiterE * 705421028266789241U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 16003052937645491524U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 6723226158737614764U;
            aOrbiterD = RotL64((aOrbiterD * 16690657664909260573U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 9785784358981219543U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 10055457337292292710U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17919129940751761111U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 11779163108592974175U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 1177999477942202687U;
            aOrbiterG = RotL64((aOrbiterG * 13475069421684114643U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 9190694445141492214U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 15605342360346353457U;
            aOrbiterB = RotL64((aOrbiterB * 14547769706392595647U), 53U);
            //
            aIngress = RotL64(aOrbiterD, 11U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 37U));
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aCross, 21U) + RotL64(aOrbiterJ, 5U)) + aOrbiterI);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 21U)) + aOrbiterD);
            aWandererA = aWandererA + (((RotL64(aPrevious, 27U) + aOrbiterD) + RotL64(aOrbiterA, 37U)) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterJ, 29U));
            aWandererH = aWandererH + ((((RotL64(aCross, 58U) + RotL64(aOrbiterJ, 43U)) + aOrbiterB) + RotL64(aCarry, 35U)) + aPhaseAWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterA, 13U)) + aOrbiterB);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterG, 54U)) + aOrbiterD) + aNonceWordJ) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (RotL64(aWandererC, 30U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ aNonceWordE;
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 14835U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 13483U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 14522U)) & W_KEY1], 14U) ^ RotL64(aKeyRowReadB[((aIndex + 15215U)) & W_KEY1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCarry, 35U)) ^ (RotL64(aIngress, 47U) + RotL64(aCross, 4U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 23U)) + RotL64(aCarry, 21U)) + 15045917390223766480U;
            aOrbiterB = (((aWandererF + RotL64(aCross, 39U)) + RotL64(aCarry, 57U)) + 10763054007033668758U) + aNonceWordP;
            aOrbiterG = (aWandererK + RotL64(aScatter, 53U)) + 13190170142593666607U;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 46U)) + 9657025731441167065U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aScatter, 5U)) + 11433367178975954211U) + aNonceWordF;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 35U)) + 17904920143996810366U;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 29U)) + 3244383020512113283U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 6538815775171139091U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 7195368312757976343U;
            aOrbiterG = RotL64((aOrbiterG * 10515679176134176565U), 19U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterJ) + 18134430713910279374U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 6571776588427107976U;
            aOrbiterB = RotL64((aOrbiterB * 11916502085252589161U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 11830778129647517758U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 9793702760907767365U;
            aOrbiterJ = RotL64((aOrbiterJ * 4096246227968677179U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 2287235876793192036U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 8951959188326141794U;
            aOrbiterC = RotL64((aOrbiterC * 9968356718110753845U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 7583061790273240157U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 3571364625022806085U;
            aOrbiterH = RotL64((aOrbiterH * 6238360922735480669U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 13869345563551689212U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 277480328952975002U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1057564597096163085U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 4983735092494677578U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 9490022869381030928U;
            aOrbiterF = RotL64((aOrbiterF * 12926352917961703123U), 5U);
            //
            aIngress = RotL64(aOrbiterG, 60U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 21U)) + aOrbiterA);
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 39U)) + aOrbiterB) + aNonceWordD) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 53U) + aOrbiterF) + RotL64(aOrbiterH, 53U)) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterC, 13U)) + aOrbiterA);
            aWandererD = aWandererD + (((((RotL64(aScatter, 60U) + RotL64(aOrbiterC, 4U)) + aOrbiterG) + RotL64(aCarry, 5U)) + aNonceWordH) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 47U)) + aOrbiterJ);
            aWandererK = aWandererK + (((RotL64(aIngress, 21U) + RotL64(aOrbiterJ, 29U)) + aOrbiterG) + aNonceWordB);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (RotL64(aWandererK, 52U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordC);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 20015U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16485U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16675U)) & S_BLOCK1], 46U) ^ RotL64(mSource[((aIndex + 18602U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 41U)) + (RotL64(aIngress, 26U) ^ RotL64(aCross, 11U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterI = (((aWandererA + RotL64(aScatter, 54U)) + RotL64(aCarry, 13U)) + 1557680213571812384U) + aPhaseAOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = (aWandererH + RotL64(aIngress, 43U)) + 7387349725778021121U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 19U)) + RotL64(aCarry, 39U)) + 15379264067601586976U;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 37U)) + 3730195724576043708U) + aNonceWordJ;
            aOrbiterD = ((((aWandererG + RotL64(aIngress, 27U)) + RotL64(aCarry, 53U)) + 9637070085323827066U) + aPhaseAOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1]) + aNonceWordI;
            aOrbiterG = (aWandererE + RotL64(aCross, 5U)) + 1170865717363676184U;
            aOrbiterF = (aWandererB + RotL64(aPrevious, 13U)) + 2750833653175252030U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 15118992811225568305U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 4974092922102988451U) ^ aNonceWordN;
            aOrbiterC = RotL64((aOrbiterC * 10575977398702460975U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 10625719096296719514U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 855167122475471865U;
            aOrbiterG = RotL64((aOrbiterG * 7441090331293158773U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 11322911068958340262U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 4334591909425429835U;
            aOrbiterJ = RotL64((aOrbiterJ * 10059025861172038183U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 14263701737208936392U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 678723206735649084U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10823239851733632227U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 15652053114252065230U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 1705225940224061401U;
            aOrbiterI = RotL64((aOrbiterI * 3626023093533713579U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 6826394665732900206U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 11902946775066981141U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 18300629262162694137U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 9802212958998591310U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 14001358545610206524U;
            aOrbiterF = RotL64((aOrbiterF * 13172645840788327099U), 19U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterF, 41U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 21U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 30U));
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 5U) + RotL64(aOrbiterD, 13U)) + aOrbiterC) + aPhaseAWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterG, 29U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 27U) + aOrbiterJ) + RotL64(aOrbiterI, 5U)) + aNonceWordA);
            aWandererE = aWandererE ^ ((RotL64(aCross, 54U) + RotL64(aOrbiterJ, 20U)) + aOrbiterF);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 35U) + aOrbiterE) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 37U)) + aNonceWordE);
            aWandererA = aWandererA ^ (((RotL64(aCross, 47U) + aOrbiterC) + RotL64(aOrbiterE, 51U)) + aNonceWordL);
            aWandererB = aWandererB + (((RotL64(aScatter, 41U) + RotL64(aOrbiterD, 57U)) + aOrbiterF) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 18U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + RotL64(aWandererA, 5U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ aNonceWordP;
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23640U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((aIndex + 21872U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22510U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25021U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aIngress, 35U)) + (RotL64(aCross, 52U) ^ RotL64(aPrevious, 23U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterE = (((aWandererE + RotL64(aIngress, 35U)) + RotL64(aCarry, 57U)) + 8685374557928800912U) + aPhaseAOrbiterAssignSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = (((aWandererG + RotL64(aPrevious, 21U)) + RotL64(aCarry, 39U)) + 3482312691892161229U) + aPhaseAOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aWandererD + RotL64(aCross, 58U)) + 6948130297389161165U;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 11U)) + RotL64(aCarry, 13U)) + 5506385663788942690U;
            aOrbiterD = ((aWandererJ + RotL64(aCross, 29U)) + 17859982009307397161U) + aNonceWordI;
            aOrbiterK = (aWandererB + RotL64(aIngress, 41U)) + 9178488809207094043U;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 51U)) + 1835479501226057169U) + aNonceWordG;
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 5368101733632614939U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 9050459666576835422U;
            aOrbiterI = RotL64((aOrbiterI * 10351719549990259551U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 9042186993119635078U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterA) ^ 17528342580198295025U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterE = RotL64((aOrbiterE * 14316671546614386775U), 37U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterK) + 6495418332558436882U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordH;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 8834495762667327342U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10783141541937645995U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 4364314196965690905U) + aNonceWordC;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 6357485231062120459U;
            aOrbiterH = RotL64((aOrbiterH * 289429584586504995U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 3321488322626415347U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 10817330671781848737U;
            aOrbiterD = RotL64((aOrbiterD * 15875919466358823335U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 17974092279281611763U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 2871472057292789157U;
            aOrbiterK = RotL64((aOrbiterK * 16104199340711015181U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 15187929795092006849U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 13482063681546475923U;
            aOrbiterG = RotL64((aOrbiterG * 14466266308157364963U), 57U);
            //
            aIngress = RotL64(aOrbiterK, 23U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 52U) + RotL64(aOrbiterK, 29U)) + aOrbiterH);
            aWandererI = aWandererI + (((((RotL64(aIngress, 11U) + aOrbiterI) + RotL64(aOrbiterE, 43U)) + RotL64(aCarry, 39U)) + aNonceWordN) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterG, 35U)) + aOrbiterD) + aPhaseAWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterA, 50U)) + RotL64(aCarry, 23U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterD, 5U)) + aOrbiterK);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 5U) + aOrbiterI) + RotL64(aOrbiterG, 23U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterG, 11U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + RotL64(aWandererA, 28U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordK;
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30479U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((aIndex + 29742U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31934U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28761U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 13U) + RotL64(aCarry, 58U)) + (RotL64(aCross, 43U) ^ RotL64(aIngress, 29U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterE = (aWandererB + RotL64(aPrevious, 41U)) + 3612110001869385068U;
            aOrbiterC = (aWandererF + RotL64(aIngress, 47U)) + 16340824141280225936U;
            aOrbiterG = (aWandererA + RotL64(aScatter, 5U)) + 15222338965130765231U;
            aOrbiterK = (aWandererG + RotL64(aCross, 53U)) + 6649270508107155041U;
            aOrbiterD = ((((aWandererD + RotL64(aPrevious, 11U)) + RotL64(aCarry, 53U)) + 768217258655426384U) + aPhaseAOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1]) + aNonceWordK;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 60U)) + RotL64(aCarry, 37U)) + 4481855259658861851U;
            aOrbiterH = (((aWandererH + RotL64(aScatter, 27U)) + RotL64(aCarry, 21U)) + 18318041934562434016U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 4212457153804401807U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 16143621095636987628U) ^ aNonceWordO;
            aOrbiterG = RotL64((aOrbiterG * 6576072860505961427U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 2095664232866642086U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 4339527736737366572U;
            aOrbiterD = RotL64((aOrbiterD * 17503569508822244125U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 13679353177869884790U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 11582168502846418236U;
            aOrbiterA = RotL64((aOrbiterA * 135539430034462861U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 10451330452898542191U) + aNonceWordD;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 12951448817640617841U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4141870904192742091U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 15389161934419370747U) + aNonceWordB;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 4754886272708253014U;
            aOrbiterE = RotL64((aOrbiterE * 16638243718191281597U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 11746389873929280688U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 12042680172517298768U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3814780289755857543U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 2648103752465009244U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 451594673632597973U;
            aOrbiterC = RotL64((aOrbiterC * 8496763663271072425U), 37U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterH, 11U);
            aIngress = aIngress + (RotL64(aOrbiterK, 41U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + RotL64(aOrbiterE, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aScatter, 5U) + RotL64(aOrbiterG, 13U)) + aOrbiterH);
            aWandererG = aWandererG ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterD, 35U)) + aOrbiterK);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 43U) + aOrbiterD) + RotL64(aOrbiterE, 29U)) + aPhaseAWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 58U) + aOrbiterK) + RotL64(aOrbiterA, 21U)) + aPhaseAWandererUpdateSaltE[((aIndex + 22U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 21U) + RotL64(aOrbiterH, 50U)) + aOrbiterK) + RotL64(aCarry, 21U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 37U) + aOrbiterG) + RotL64(aOrbiterA, 3U)) + aNonceWordE);
            aWandererH = aWandererH + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 43U)) + aOrbiterC) + RotL64(aCarry, 5U)) + aNonceWordN);
            //
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 41U));
            aCarry = aCarry + (RotL64(aWandererD, 50U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 21U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordD;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x8500A64CDF78C4B1ULL + 0xA84E930827BED9A7ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xFA31BD2FF43837B1ULL + 0x90872E5B6B74AECEULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x9D6DDD29FEE773A1ULL + 0xDCC3991F5991CAC9ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xF0DD811E9DB10649ULL + 0xEB6BF50C8DCCB3B6ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xD467F91C8E903BF1ULL + 0xC8DC36CA512BC69FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xCC871E17342EC287ULL + 0xB334ED0B9C76755DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xE247B2094F6856CBULL + 0xC813FCA18B89B209ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xA36BF9DFE60D2811ULL + 0xE298F50D17F4692FULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xB6D2AE4D69827A6BULL + 0xB92B107F7414826DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xFA2E88FA8AC0A413ULL + 0xDD23B3975F88A1B1ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xF412A1DE6F79C403ULL + 0xB92ABEB22278C6C3ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xC2D7FD73252A4F11ULL + 0xDE3B9F26FBA212D8ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x9A285CE8567551C1ULL + 0xCAE50D3A01DFA40BULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x81921AF972364331ULL + 0xA676D2B3C5C61B49ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xB8D6E8F8714B7F4BULL + 0xFE45836F79EAF649ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xA5D979D94455B67BULL + 0xBC5DB8885EC341FBULL);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1354U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((aIndex + 1018U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3101U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 1930U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCross, 34U)) ^ (RotL64(aCarry, 53U) + RotL64(aPrevious, 5U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterI = ((aWandererK + RotL64(aCross, 57U)) + 6024062041314952357U) + aNonceWordG;
            aOrbiterF = (((aWandererJ + RotL64(aScatter, 47U)) + RotL64(aCarry, 37U)) + 18340757093658015585U) + aPhaseBOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = (((aWandererD + RotL64(aIngress, 13U)) + RotL64(aCarry, 13U)) + 11911120493880346751U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = (((aWandererE + RotL64(aPrevious, 3U)) + RotL64(aCarry, 57U)) + 17428074353884654439U) + aNonceWordI;
            aOrbiterE = (aWandererH + RotL64(aCross, 30U)) + 12790849760814795936U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 12633397052172117800U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 11946150433665237945U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10324089534873171291U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 16842157900909419285U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 14186235783224155962U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10521157787073684417U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 13284904542579767591U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 11609181965078844357U;
            aOrbiterH = RotL64((aOrbiterH * 5455780554452453513U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 9628562297095374984U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 7850281529011259759U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17611485102925470357U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 257458718073794527U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 10693404545773519306U) ^ aNonceWordH;
            aOrbiterE = RotL64((aOrbiterE * 14821443722828498323U), 5U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 57U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aCross, 30U) + aOrbiterE) + RotL64(aOrbiterA, 57U)) + aNonceWordB);
            aWandererK = aWandererK + ((((RotL64(aScatter, 41U) + RotL64(aOrbiterE, 29U)) + aOrbiterI) + RotL64(aCarry, 39U)) + aNonceWordN);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 11U)) + aOrbiterE);
            aWandererD = aWandererD + ((((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterH, 37U)) + RotL64(aCarry, 19U)) + aPhaseBWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 51U) + RotL64(aOrbiterI, 20U)) + aOrbiterH) + aNonceWordF) + aPhaseBWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + RotL64(aWandererD, 37U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordJ);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8596U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((aIndex + 9499U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9903U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneB[((aIndex + 8508U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aPrevious, 40U)) ^ (RotL64(aIngress, 19U) + RotL64(aCarry, 5U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterF = ((aWandererG + RotL64(aCross, 3U)) + 8975885703279267062U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = ((((aWandererI + RotL64(aScatter, 51U)) + RotL64(aCarry, 47U)) + 8664844915562660637U) + aPhaseBOrbiterAssignSaltA[((aIndex + 26U)) & S_SALT1]) + aNonceWordN;
            aOrbiterE = (((aWandererH + RotL64(aPrevious, 11U)) + RotL64(aCarry, 19U)) + 12281774799736296726U) + aNonceWordG;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 41U)) + RotL64(aCarry, 35U)) + 15347461352311329726U;
            aOrbiterI = ((aWandererA + RotL64(aCross, 26U)) + 12967500561828907834U) + aNonceWordF;
            //
            aOrbiterF = (((aOrbiterF + aOrbiterH) + 5002833859280402726U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordD;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 11908257536954668983U;
            aOrbiterE = RotL64((aOrbiterE * 4384790916151202785U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 17017174811949227162U) + aNonceWordB;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 16851323125613931180U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12446990992858763577U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 13469326957728686706U) + aNonceWordM;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 5228638551056105241U;
            aOrbiterF = RotL64((aOrbiterF * 13369947664646167255U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 11945166198089308564U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 16268645041872996022U;
            aOrbiterH = RotL64((aOrbiterH * 5391448793718370911U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 14781204627695095701U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 5365325354838101092U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8017284997946310807U), 3U);
            //
            aIngress = RotL64(aOrbiterI, 40U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aCross, 19U) + aOrbiterI) + RotL64(aOrbiterF, 19U)) + RotL64(aCarry, 5U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 11U)) + aOrbiterA);
            aWandererG = aWandererG + ((((RotL64(aScatter, 5U) + aOrbiterF) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 43U)) + aNonceWordK);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 48U) + RotL64(aOrbiterA, 41U)) + aOrbiterH);
            aWandererC = aWandererC + (((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterA, 56U)) + aPhaseBWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 60U));
            aCarry = aCarry + RotL64(aWandererC, 27U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordA);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 11695U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 12054U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13182U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((aIndex + 13365U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 52U) ^ RotL64(aPrevious, 23U)) + (RotL64(aCarry, 11U) ^ RotL64(aIngress, 39U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterA = ((aWandererA + RotL64(aIngress, 21U)) + 3684295017013759987U) + aNonceWordH;
            aOrbiterK = (((aWandererD + RotL64(aScatter, 5U)) + RotL64(aCarry, 27U)) + 6740408842457292881U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aCross, 29U)) + 4563975890702399441U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 41U)) + RotL64(aCarry, 39U)) + 797804144825287940U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 56U)) + RotL64(aCarry, 57U)) + 2763779540450101303U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 13211846164102089685U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 15214578447281401982U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12107189619131483661U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 13745208628754232427U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 17358621225969190747U;
            aOrbiterK = RotL64((aOrbiterK * 5325024317338823061U), 29U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterE) + 779739369960480023U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 4370963533701407813U;
            aOrbiterA = RotL64((aOrbiterA * 3123135216876641039U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 6061333005507739975U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 3589705340762734456U;
            aOrbiterE = RotL64((aOrbiterE * 16499293983611196967U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 10607697666369230567U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 9356757995305239271U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10945513661439954731U), 43U);
            //
            aIngress = RotL64(aOrbiterK, 5U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + RotL64(aOrbiterH, 20U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterA, 19U)) + RotL64(aCarry, 35U)) + aNonceWordK);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterH, 27U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 51U) + aOrbiterF) + RotL64(aOrbiterH, 50U)) + aNonceWordL);
            aWandererC = aWandererC ^ ((((RotL64(aCross, 23U) + aOrbiterK) + RotL64(aOrbiterA, 41U)) + aNonceWordC) + aPhaseBWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 34U) + aOrbiterF) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 23U)) + aPhaseBWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordE);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 20146U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16661U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21327U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneD[((aIndex + 17886U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 37U) ^ RotL64(aCarry, 3U)) + (RotL64(aCross, 52U) + RotL64(aPrevious, 21U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterA = (aWandererC + RotL64(aPrevious, 43U)) + 1142447269198373880U;
            aOrbiterB = ((aWandererG + RotL64(aIngress, 21U)) + RotL64(aCarry, 11U)) + 10581460640040336191U;
            aOrbiterH = (((aWandererA + RotL64(aScatter, 35U)) + RotL64(aCarry, 37U)) + 14703062773878202900U) + aNonceWordF;
            aOrbiterC = ((((aWandererJ + RotL64(aCross, 58U)) + RotL64(aCarry, 23U)) + 15737525756286914746U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordA;
            aOrbiterF = (((aWandererH + RotL64(aPrevious, 11U)) + 16178774478273186999U) + aPhaseBOrbiterAssignSaltE[((aIndex + 18U)) & S_SALT1]) + aNonceWordB;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 2514897053906809160U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 13702496607592508464U;
            aOrbiterH = RotL64((aOrbiterH * 16540143680974064057U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 18030885275418337965U) + aNonceWordN;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 5241783876161655984U;
            aOrbiterA = RotL64((aOrbiterA * 10970981186787227937U), 39U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterH) + 2807052676283587925U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1]) + aNonceWordK;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 8022804576763271327U;
            aOrbiterC = RotL64((aOrbiterC * 11727096043219370577U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 15597099852232205860U) + aNonceWordI;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 1538435607932096400U;
            aOrbiterB = RotL64((aOrbiterB * 7900752511710516981U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 11147868774413615365U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 9325213746830411568U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 561819005818948769U), 29U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterC, 43U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterC, 23U)) + aOrbiterA) + aPhaseBWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererG = aWandererG + (((((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 43U)) + aOrbiterC) + RotL64(aCarry, 27U)) + aNonceWordC) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterC, 3U)) + aOrbiterH) + aNonceWordM);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 60U) + aOrbiterB) + RotL64(aOrbiterC, 54U)) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterB, 13U)) + aOrbiterA) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ aNonceWordE;
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 25812U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneA[((aIndex + 24872U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26211U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneA[((aIndex + 27187U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 34U) + RotL64(aIngress, 53U)) ^ (RotL64(aCross, 3U) + RotL64(aPrevious, 21U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterD = ((((aWandererE + RotL64(aIngress, 21U)) + RotL64(aCarry, 29U)) + 7825479804710770560U) + aPhaseBOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1]) + aNonceWordO;
            aOrbiterJ = (((aWandererA + RotL64(aPrevious, 11U)) + RotL64(aCarry, 5U)) + 5298124167101358123U) + aNonceWordD;
            aOrbiterF = ((aWandererK + RotL64(aCross, 42U)) + 17774541024369233726U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aScatter, 3U)) + 7679371833537454082U;
            aOrbiterG = (((aWandererF + RotL64(aCross, 57U)) + RotL64(aCarry, 43U)) + 5385914900748772224U) + aNonceWordF;
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 3879781930908486531U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 659110346638873236U;
            aOrbiterF = RotL64((aOrbiterF * 17439162088869824407U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 10749021728538539749U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 3631252455767429457U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8552825360915119613U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 2271978810960685021U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 5963558780692551176U;
            aOrbiterD = RotL64((aOrbiterD * 4772055335210781149U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 974909966119198104U) + aNonceWordN;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 9296998242911152296U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2613629915877957661U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 2245318466901521959U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 13391076374843288568U;
            aOrbiterI = RotL64((aOrbiterI * 18094558036982107419U), 41U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 47U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 18U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aCross, 57U) + aOrbiterD) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 5U)) + aNonceWordH);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 12U) + aOrbiterG) + RotL64(aOrbiterJ, 53U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 41U) + aOrbiterJ) + RotL64(aOrbiterI, 40U)) + RotL64(aCarry, 39U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterF, 11U)) + aOrbiterG);
            aWandererK = aWandererK + ((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterG, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 52U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordK);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 29408U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32408U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31360U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31376U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aPrevious, 5U)) ^ (RotL64(aCarry, 54U) ^ RotL64(aIngress, 39U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterH = (((aWandererH + RotL64(aCross, 21U)) + RotL64(aCarry, 53U)) + 12980104182836602177U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 37U)) + RotL64(aCarry, 13U)) + 3172622203188863995U;
            aOrbiterE = (((aWandererK + RotL64(aScatter, 52U)) + 1170974132219980203U) + aPhaseBOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1]) + aNonceWordA;
            aOrbiterC = (aWandererB + RotL64(aPrevious, 5U)) + 6035201940965047490U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 13U)) + RotL64(aCarry, 35U)) + 18033907118424996722U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 14604813424800580304U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 13720232492851066035U) ^ aNonceWordJ;
            aOrbiterE = RotL64((aOrbiterE * 8927246214721284759U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 3902659710585257448U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterC) ^ 8331560652661619868U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterJ = RotL64((aOrbiterJ * 11418103770615560205U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 4485014147538689794U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 168202636924512424U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13711020666131492091U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 16227825670092707848U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 4792781933944671365U;
            aOrbiterC = RotL64((aOrbiterC * 15859849676231455283U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 12636865372722601282U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 18198291399585556632U) ^ aNonceWordI;
            aOrbiterB = RotL64((aOrbiterB * 18155803890313399795U), 23U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 39U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterB, 37U)) + RotL64(aCarry, 13U)) + aNonceWordH) + aPhaseBWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterC, 57U)) + aOrbiterE);
            aWandererB = aWandererB + (((RotL64(aCross, 35U) + RotL64(aOrbiterE, 12U)) + aOrbiterH) + aPhaseBWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterH, 3U));
            aWandererG = aWandererG + (((RotL64(aCross, 54U) + aOrbiterB) + RotL64(aOrbiterH, 29U)) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 34U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ aNonceWordF;
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

void TwistExpander_BaseBall_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xBD3A300B51F2805DULL + 0xA523E19F77F33D07ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xDDAF17B9B1573691ULL + 0x82D0046A4D097662ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xC09672D9E2E00461ULL + 0x81A00842E09715AFULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x8D1BC38CD5B62829ULL + 0xAE180B1F4DBDB5F0ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xC08E6247F79FA793ULL + 0xA2DD90DEFDD0B57DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xA362E50E920F7DABULL + 0xD55DD17C1878E9EEULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xE061DC20B44F2361ULL + 0xDF3B5BCD86F90039ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xA628AA657ED2000DULL + 0xDD02D7B618FD74E7ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xFCE870BE829E4873ULL + 0x9F5E427D4C4D193AULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xE8A8655B3C0BADF3ULL + 0x912A84782637EC07ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xF2B14EF7CEA056C5ULL + 0xDF18F455D075DDA5ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x93429F44F7725B31ULL + 0xFE36C8CE98C05CE0ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x93DD7B0917E5BC39ULL + 0xE3E7E200B6980B8DULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xE353D2A36F50BB83ULL + 0x9305742AF5083DA7ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xF09E6355BB149AD1ULL + 0xB83E572275733DCEULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xDA3E9C64A83D4E07ULL + 0xAC56F548FFC17E55ULL);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 5358U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 5222U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7780U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 1089U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 21U)) ^ (RotL64(aCross, 39U) + RotL64(aIngress, 56U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterI = (aWandererF + RotL64(aCross, 13U)) + 4848316479321533394U;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 46U)) + 6919360256662636195U) + aNonceWordE;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 53U)) + RotL64(aCarry, 35U)) + 9897013582181108544U;
            aOrbiterF = ((aWandererC + RotL64(aIngress, 19U)) + 7319353809896158678U) + aPhaseCOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 41U)) + 2848175435514849859U) + aPhaseCOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 23U)) + RotL64(aCarry, 51U)) + 6967780718720437934U;
            aOrbiterE = ((aWandererG + RotL64(aCross, 60U)) + RotL64(aCarry, 13U)) + 10143884766603388136U;
            aOrbiterA = (aWandererD + RotL64(aScatter, 5U)) + 8675965006150972051U;
            aOrbiterK = (aWandererB + RotL64(aIngress, 29U)) + 16350117755560994281U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 17976597517118423760U) + aNonceWordF;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 1399631141355370237U;
            aOrbiterG = RotL64((aOrbiterG * 16537788276543236833U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 3590613762034716792U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 5134624314245932157U;
            aOrbiterJ = RotL64((aOrbiterJ * 13077589037975283371U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 10082236952942943654U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 4015535035905433450U;
            aOrbiterA = RotL64((aOrbiterA * 4961808568701908559U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 611474103801573800U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 5786708483794098001U;
            aOrbiterK = RotL64((aOrbiterK * 7694007039340089267U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 5201943497363274455U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 9282160506938328489U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5368182164239021367U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 4932320527498940158U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 11576526341731392916U;
            aOrbiterF = RotL64((aOrbiterF * 1712051774729439363U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 10790691517638887125U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 16280649213607464422U;
            aOrbiterE = RotL64((aOrbiterE * 10756733801499471873U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 9553716940667712810U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 11827518270964003341U;
            aOrbiterD = RotL64((aOrbiterD * 1322489827908132831U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 16777463701235809321U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 3375489084588454149U;
            aOrbiterB = RotL64((aOrbiterB * 3335010977457647307U), 13U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterB, 19U);
            aIngress = aIngress + (RotL64(aOrbiterK, 48U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 53U));
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterD, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 54U) + aOrbiterB) + RotL64(aOrbiterI, 10U)) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterA, 51U));
            aWandererB = aWandererB + (((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterJ, 23U)) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 3U)) + aOrbiterD);
            aWandererF = aWandererF + (((RotL64(aCross, 58U) + aOrbiterJ) + RotL64(aOrbiterG, 36U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterD, 19U)) + aOrbiterK) + aPhaseCWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 39U) + RotL64(aOrbiterB, 41U)) + aOrbiterK);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterF, 29U)) + aNonceWordL);
            aWandererJ = aWandererJ + ((RotL64(aCross, 35U) + RotL64(aOrbiterG, 47U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 28U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + RotL64(aWandererJ, 23U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordM);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 12501U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 8676U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 14217U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneB[((aIndex + 14495U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 24U) ^ RotL64(aPrevious, 5U)) ^ (RotL64(aCross, 39U) + RotL64(aIngress, 57U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterE = ((aWandererK + RotL64(aScatter, 41U)) + 16651241552253078315U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aIngress, 23U)) + 4558144676982478003U;
            aOrbiterK = (aWandererJ + RotL64(aCross, 57U)) + 8814884320080367550U;
            aOrbiterB = (aWandererI + RotL64(aPrevious, 18U)) + 16011579668555672117U;
            aOrbiterD = (aWandererH + RotL64(aIngress, 47U)) + 4738918668759862438U;
            aOrbiterI = ((aWandererD + RotL64(aCross, 11U)) + RotL64(aCarry, 11U)) + 12526083125540985108U;
            aOrbiterC = (((aWandererG + RotL64(aScatter, 51U)) + RotL64(aCarry, 57U)) + 8048723561746000552U) + aNonceWordG;
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 6U)) + 1082218464034639039U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 29U)) + RotL64(aCarry, 35U)) + 8432043246965946816U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 9982080524048636852U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 6720069955755215919U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1025046364205332059U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 1019035028070247757U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 7360619079463870467U;
            aOrbiterD = RotL64((aOrbiterD * 6623074813047915863U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 10893918488381348474U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 1390297670907738019U;
            aOrbiterC = RotL64((aOrbiterC * 11909657437658597735U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 12512200589031203480U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 14741471280748399540U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3012135242889901095U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 8543897248359826770U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 8545972622733791272U;
            aOrbiterJ = RotL64((aOrbiterJ * 11793879362775346821U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 7049384618581928664U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 14730773807906925408U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10711566871536755073U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 11480717275652449986U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 1135397594974536859U;
            aOrbiterB = RotL64((aOrbiterB * 6347492892938856497U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 6897207625849516702U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 10920630712550287148U) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 4140705091806993359U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 1094056478999931332U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 6784487144549717207U) ^ aNonceWordB;
            aOrbiterG = RotL64((aOrbiterG * 6295177724167067891U), 27U);
            //
            aIngress = RotL64(aOrbiterE, 24U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + RotL64(aOrbiterG, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 30U) + aOrbiterB) + RotL64(aOrbiterC, 4U)) + RotL64(aCarry, 43U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterC, 57U)) + aOrbiterJ);
            aWandererG = aWandererG + ((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 19U)) + aOrbiterH);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterG, 11U)) + aOrbiterJ);
            aWandererE = aWandererE + (((RotL64(aIngress, 53U) + aOrbiterJ) + RotL64(aOrbiterD, 43U)) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterJ, 47U)) + aOrbiterB) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 5U) + RotL64(aOrbiterB, 28U)) + aOrbiterH) + aNonceWordC);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterK, 53U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 18U) + RotL64(aOrbiterC, 35U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererE, 28U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 53U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 22846U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19584U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 17911U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneC[((aIndex + 17596U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 20U) ^ RotL64(aPrevious, 35U)) ^ (RotL64(aCarry, 51U) + RotL64(aIngress, 3U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterJ = (aWandererI + RotL64(aScatter, 53U)) + 4259993311776766595U;
            aOrbiterH = (aWandererF + RotL64(aIngress, 13U)) + 2857813330021126753U;
            aOrbiterG = (((aWandererD + RotL64(aCross, 5U)) + RotL64(aCarry, 3U)) + 1345396841329442896U) + aNonceWordN;
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 19U)) + 320992148982301024U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = (aWandererG + RotL64(aCross, 26U)) + 5619109532065293074U;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 43U)) + RotL64(aCarry, 35U)) + 10380157329426706345U;
            aOrbiterE = (aWandererJ + RotL64(aIngress, 57U)) + 12449831150625409695U;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 35U)) + RotL64(aCarry, 27U)) + 7847096607042268396U;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 48U)) + 11707184096803214678U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 9893643746186827088U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 333687403830908774U;
            aOrbiterG = RotL64((aOrbiterG * 17911256836121454271U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 13837360705077441580U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 4367119682175710689U;
            aOrbiterJ = RotL64((aOrbiterJ * 10295744669174603401U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 1193493435041306784U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 15062951612027370606U) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 2509383510565136549U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 16000173839235429105U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 15294482444605409961U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1031800997944302665U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 5720749055549773527U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 17248674962996093668U;
            aOrbiterC = RotL64((aOrbiterC * 15730637462755795591U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 16956840483882091059U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 9637715107943515594U;
            aOrbiterI = RotL64((aOrbiterI * 8878362378343603463U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 7147495779349862274U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 7508890985889484275U;
            aOrbiterE = RotL64((aOrbiterE * 17728368447504622035U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 4407738164617959366U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 17027017782352660454U;
            aOrbiterD = RotL64((aOrbiterD * 417183060881259295U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 3174658601748235285U) + aNonceWordI;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 9779053567370714831U;
            aOrbiterK = RotL64((aOrbiterK * 6383245776181968033U), 47U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterB, 6U);
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterK, 39U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 43U));
            aIngress = aIngress + RotL64(aOrbiterI, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aIngress, 11U) + aOrbiterE) + RotL64(aOrbiterC, 27U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 41U) + RotL64(aOrbiterK, 56U)) + aOrbiterB);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 52U) + aOrbiterH) + RotL64(aOrbiterE, 23U)) + aNonceWordG);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 35U) + aOrbiterB) + RotL64(aOrbiterC, 51U)) + aNonceWordF);
            aWandererE = aWandererE ^ ((RotL64(aCross, 29U) + aOrbiterE) + RotL64(aOrbiterG, 3U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterJ, 13U)) + aOrbiterB) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 19U) + aOrbiterD) + RotL64(aOrbiterJ, 18U)) + aPhaseCWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 48U) + aOrbiterG) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterI, 39U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 60U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + RotL64(aWandererG, 43U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordF;
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 31477U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((aIndex + 27310U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30115U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneD[((aIndex + 31104U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCross, 3U)) + (RotL64(aIngress, 54U) ^ RotL64(aCarry, 19U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterG = ((aWandererH + RotL64(aIngress, 43U)) + 3684295017013759987U) + aNonceWordO;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 29U)) + 6740408842457292881U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = (aWandererG + RotL64(aScatter, 18U)) + 4563975890702399441U;
            aOrbiterK = ((aWandererE + RotL64(aCross, 39U)) + RotL64(aCarry, 47U)) + 797804144825287940U;
            aOrbiterI = (((aWandererF + RotL64(aPrevious, 47U)) + RotL64(aCarry, 5U)) + 2763779540450101303U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aIngress, 13U)) + 13211846164102089685U;
            aOrbiterA = (aWandererA + RotL64(aCross, 3U)) + 15214578447281401982U;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 53U)) + RotL64(aCarry, 29U)) + 13745208628754232427U;
            aOrbiterJ = (aWandererB + RotL64(aCross, 34U)) + 17358621225969190747U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 779739369960480023U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 4370963533701407813U;
            aOrbiterE = RotL64((aOrbiterE * 3123135216876641039U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 6061333005507739975U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 3589705340762734456U;
            aOrbiterI = RotL64((aOrbiterI * 16499293983611196967U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 10607697666369230567U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 9356757995305239271U;
            aOrbiterA = RotL64((aOrbiterA * 10945513661439954731U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 10093033335903048138U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 11037328061699834100U;
            aOrbiterG = RotL64((aOrbiterG * 11189760551792389605U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 558431161176115540U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 17795680919453449358U;
            aOrbiterK = RotL64((aOrbiterK * 3910117359996283803U), 39U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterK) + 6096779391116214109U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1]) + aNonceWordK;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 17594243286880690775U) ^ aNonceWordE;
            aOrbiterB = RotL64((aOrbiterB * 12655610181937429915U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 15414704802398002423U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 18040588240488602196U;
            aOrbiterH = RotL64((aOrbiterH * 16344249573086571225U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 14636298592697156931U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 9677305688594936561U;
            aOrbiterJ = RotL64((aOrbiterJ * 8354776999961642997U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 16408025751875050713U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 10018342878801454965U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10349132962708124117U), 57U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 35U);
            aIngress = aIngress + (RotL64(aOrbiterE, 40U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 53U));
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterK, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aIngress, 57U) + aOrbiterI) + RotL64(aOrbiterJ, 11U)) + RotL64(aCarry, 37U)) + aNonceWordJ);
            aWandererH = aWandererH ^ (((RotL64(aCross, 22U) + RotL64(aOrbiterA, 56U)) + aOrbiterJ) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 43U) + aOrbiterK) + RotL64(aOrbiterC, 27U)) + RotL64(aCarry, 3U)) + aNonceWordL);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 21U)) + aOrbiterE);
            aWandererE = aWandererE + (((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterJ, 41U)) + aNonceWordG);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterB, 3U)) + aOrbiterC) + aPhaseCWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterH, 47U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 18U) + RotL64(aOrbiterG, 51U)) + aOrbiterA);
            aWandererB = aWandererB + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterK, 60U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 26U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + RotL64(aWandererI, 23U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordD;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x918041D34423613BULL + 0x8B4FF9FD51D2393AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xCE84CA36AE95A61DULL + 0xA2CE6682B4C3B339ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x8601F6C660B09AE3ULL + 0xD25A32F2466D7405ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xBD3697D12EE964EFULL + 0xE2D425BD5102C0AAULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xFE2F472160E92861ULL + 0x8D4C6971D2333DEFULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xA19929A3E2567243ULL + 0xE0012479F3E4EE44ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xBA28601CAA84E3C7ULL + 0x974C15A8261FA97FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x820D78A2B6A0916FULL + 0xBF038503FD7134BAULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x99B010A32D4E192FULL + 0xBC3CF9DF7053D64DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xBAD38D7A0515B4D5ULL + 0xCFC11C818F5F4DA1ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xF57C69ED26EB5CCDULL + 0xD55557798DC977A1ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xEA86088AEBA9DA85ULL + 0xF6BFC030C145F835ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xF01E07EDF2DF6AE1ULL + 0xDB606B1F6975906AULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x8541B7739E9F15EDULL + 0xAEF569313DA8F3BCULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xAF5F1B060DD176AFULL + 0xA1C9E0E011589B64ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xE4182E9A33A0D2B3ULL + 0xE5CE9F0C749D7A02ULL);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1039U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((aIndex + 3729U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4690U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 2854U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCross, 47U)) ^ (RotL64(aIngress, 60U) + RotL64(aCarry, 29U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 60U)) + 2915859148137000694U) + aNonceWordH;
            aOrbiterG = ((((aWandererD + RotL64(aIngress, 51U)) + RotL64(aCarry, 23U)) + 210680583721444425U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordP;
            aOrbiterF = (((aWandererC + RotL64(aScatter, 39U)) + RotL64(aCarry, 19U)) + 6668118118775650387U) + aNonceWordA;
            aOrbiterI = (aWandererB + RotL64(aCross, 3U)) + 15794200818099010989U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 41U)) + RotL64(aCarry, 43U)) + 6565076707062828369U;
            aOrbiterA = (aWandererE + RotL64(aIngress, 43U)) + 16323164497808856719U;
            aOrbiterE = (aWandererG + RotL64(aCross, 37U)) + 7965435318816716560U;
            aOrbiterB = (aWandererI + RotL64(aScatter, 35U)) + 7390281030573369017U;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 58U)) + 2269738866911824875U;
            aOrbiterD = ((aWandererA + RotL64(aCross, 23U)) + 9664014216039993873U) + aPhaseDOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = (aWandererK + RotL64(aScatter, 29U)) + 18284857398028357633U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 367667619795303009U) + aNonceWordB;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 7935945060956274197U;
            aOrbiterF = RotL64((aOrbiterF * 5481786693511955209U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 16683666162337789540U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 10655658270998102390U;
            aOrbiterA = RotL64((aOrbiterA * 15231596813382239841U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 8307037916581540297U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 3247742749860703524U;
            aOrbiterJ = RotL64((aOrbiterJ * 15052136713218656641U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 10446792483683818139U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 16374602929344972364U;
            aOrbiterI = RotL64((aOrbiterI * 12599903932725787599U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 2411334498322777183U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 1093701164116833765U;
            aOrbiterE = RotL64((aOrbiterE * 13129220206835381729U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 17018480952982840635U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 17348395690080029814U) ^ aNonceWordD;
            aOrbiterC = RotL64((aOrbiterC * 6212591395713433257U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 16111252311283623152U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 12776492920397785951U;
            aOrbiterH = RotL64((aOrbiterH * 6136009241593081821U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 12214538600808144816U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 10043377462096783363U) ^ aNonceWordJ;
            aOrbiterG = RotL64((aOrbiterG * 14639467375095185877U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 5101561512438055661U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 3683207847147603335U;
            aOrbiterK = RotL64((aOrbiterK * 14355438383379198639U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 14446947359104987749U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 7596096688268335354U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13522935803383107145U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 14015424109468938015U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 2915859148137000694U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3653144205211106817U), 23U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 29U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 6U));
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterB, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 37U) + aOrbiterE) + RotL64(aOrbiterG, 39U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 26U) + RotL64(aOrbiterK, 41U)) + aOrbiterJ);
            aWandererA = aWandererA + (((((RotL64(aScatter, 43U) + aOrbiterA) + RotL64(aOrbiterD, 23U)) + RotL64(aCarry, 35U)) + aNonceWordO) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 6U)) + aOrbiterC);
            aWandererB = aWandererB + (((RotL64(aPrevious, 11U) + aOrbiterK) + RotL64(aOrbiterD, 51U)) + RotL64(aCarry, 19U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 28U) + aOrbiterH) + RotL64(aOrbiterF, 57U)) + aNonceWordM);
            aWandererK = aWandererK + ((RotL64(aScatter, 39U) + RotL64(aOrbiterD, 19U)) + aOrbiterG);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterI, 35U)) + aOrbiterF) + aNonceWordL);
            aWandererE = aWandererE + ((RotL64(aIngress, 21U) + RotL64(aOrbiterI, 43U)) + aOrbiterH);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 19U) + aOrbiterD) + RotL64(aOrbiterC, 21U));
            aWandererC = aWandererC + ((RotL64(aCross, 57U) + aOrbiterE) + RotL64(aOrbiterB, 4U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 42U));
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + RotL64(aWandererE, 27U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ aNonceWordM;
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 10001U)) & S_BLOCK1], 42U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9787U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8976U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10270U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCross, 19U)) ^ (RotL64(aPrevious, 37U) + RotL64(aCarry, 6U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterI = ((aWandererG + RotL64(aScatter, 3U)) + 5041131702736607991U) + aPhaseDOrbiterAssignSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aIngress, 37U)) + 9295010428212681446U;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 11U)) + RotL64(aCarry, 21U)) + 6235875895358766017U;
            aOrbiterJ = (aWandererA + RotL64(aCross, 60U)) + 2622227802531866918U;
            aOrbiterD = (aWandererC + RotL64(aScatter, 35U)) + 3888894734834524972U;
            aOrbiterG = ((aWandererE + RotL64(aCross, 5U)) + 241682012014701753U) + aPhaseDOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (aWandererD + RotL64(aPrevious, 41U)) + 15758000422451568079U;
            aOrbiterF = (((aWandererI + RotL64(aIngress, 13U)) + RotL64(aCarry, 3U)) + 2061944548396976912U) + aNonceWordP;
            aOrbiterC = ((aWandererH + RotL64(aCross, 53U)) + RotL64(aCarry, 29U)) + 8177144990755754531U;
            aOrbiterH = (aWandererK + RotL64(aIngress, 48U)) + 554978075608818497U;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 39U)) + 250408260560714933U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 8700027645880997552U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 10026130047465480902U;
            aOrbiterA = RotL64((aOrbiterA * 12417270861933696623U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 9785843014096326696U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 9998582683258411251U;
            aOrbiterK = RotL64((aOrbiterK * 7197956237569462269U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 13817734599383455151U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 6647207154174092691U;
            aOrbiterD = RotL64((aOrbiterD * 1578528131687283531U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 4957715980509035719U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 4994885315786213197U) ^ aNonceWordO;
            aOrbiterB = RotL64((aOrbiterB * 5676683798126497011U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 5072908311783966503U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 5535039946192891515U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2989412783482309753U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 6594577050344146271U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 8750154123258714856U;
            aOrbiterI = RotL64((aOrbiterI * 6942158167127532003U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 3514769314840874873U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 8626045200273524281U;
            aOrbiterJ = RotL64((aOrbiterJ * 4315441782689789689U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 8524870284841706517U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 1841819423572964209U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9802481758007234681U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 12668382464510772517U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 6330331402801670515U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9096920618612750935U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 10346986196055766087U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 10932918162471200996U;
            aOrbiterH = RotL64((aOrbiterH * 6863632877625141567U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 6264557195446069146U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 5041131702736607991U;
            aOrbiterE = RotL64((aOrbiterE * 4978591546106895045U), 51U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterD, 35U);
            aIngress = aIngress + (RotL64(aOrbiterH, 39U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterE, 51U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterB, 30U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + RotL64(aOrbiterG, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterK, 57U)) + aPhaseDWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 51U) + aOrbiterJ) + RotL64(aOrbiterF, 41U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterI, 21U)) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 34U) + aOrbiterB) + RotL64(aOrbiterE, 19U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterI, 10U)) + aNonceWordM);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterD, 37U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((RotL64(aCross, 43U) + RotL64(aOrbiterG, 5U)) + aOrbiterA);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterI, 51U));
            aWandererA = aWandererA + ((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterJ, 23U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 36U) + aOrbiterC) + RotL64(aOrbiterG, 30U));
            aWandererG = aWandererG + (((RotL64(aScatter, 27U) + aOrbiterK) + RotL64(aOrbiterH, 53U)) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 18U) ^ aWandererI);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + RotL64(aWandererJ, 46U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 12685U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneA[((aIndex + 14992U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14943U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneC[((aIndex + 15701U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCarry, 51U)) ^ (RotL64(aCross, 26U) + RotL64(aIngress, 5U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterK = (aWandererD + RotL64(aCross, 3U)) + 4980738603982643969U;
            aOrbiterG = (aWandererE + RotL64(aPrevious, 11U)) + 17660278413018470020U;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 5U)) + 17598114429859543466U) + aNonceWordO;
            aOrbiterF = (aWandererC + RotL64(aIngress, 48U)) + 10993929335279994739U;
            aOrbiterJ = ((((aWandererF + RotL64(aPrevious, 23U)) + RotL64(aCarry, 29U)) + 17967203122976322481U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordL;
            aOrbiterB = (aWandererH + RotL64(aIngress, 21U)) + 1872290205549034384U;
            aOrbiterE = (aWandererA + RotL64(aScatter, 51U)) + 16607778671782810797U;
            aOrbiterA = (aWandererK + RotL64(aCross, 60U)) + 4895226930754394376U;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 27U)) + RotL64(aCarry, 53U)) + 14960359005982301383U;
            aOrbiterD = ((aWandererJ + RotL64(aCross, 37U)) + 9921642352377700630U) + aNonceWordN;
            aOrbiterI = (((aWandererI + RotL64(aScatter, 29U)) + RotL64(aCarry, 23U)) + 893281964367208693U) + aPhaseDOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 8232519988397858732U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterK) ^ 4433022122758913407U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterH = RotL64((aOrbiterH * 834240393225479419U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 12689609831247168353U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 404535388957472176U;
            aOrbiterB = RotL64((aOrbiterB * 14534020545479806593U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 3349108201964013155U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 4386449511297371730U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9596273264321140229U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 14314587717949070586U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterC) ^ 10923886625271054985U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterJ = RotL64((aOrbiterJ * 7838969002623486809U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 17634909585329833520U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 2021301459918350372U;
            aOrbiterA = RotL64((aOrbiterA * 1388242915918642741U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 5219599112498224367U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 10641339455385046206U;
            aOrbiterD = RotL64((aOrbiterD * 1022283727595400719U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 5003342156562330058U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 10951027475628404336U;
            aOrbiterK = RotL64((aOrbiterK * 17836928292555158461U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 13040991872592235460U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 11149099984302782267U;
            aOrbiterF = RotL64((aOrbiterF * 4248667283139686251U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 2202253777854402763U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 16679038924474862612U;
            aOrbiterE = RotL64((aOrbiterE * 2624443661523083597U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 1959650241410955571U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 8415989510614674816U;
            aOrbiterC = RotL64((aOrbiterC * 16340289102832732519U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 2344501711730399821U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 4980738603982643969U;
            aOrbiterI = RotL64((aOrbiterI * 6419275275477478723U), 37U);
            //
            aIngress = RotL64(aOrbiterF, 57U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 6U));
            aIngress = aIngress + RotL64(aOrbiterI, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 37U)) + aOrbiterG);
            aWandererK = aWandererK + ((RotL64(aScatter, 56U) + aOrbiterD) + RotL64(aOrbiterK, 39U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 37U) + aOrbiterF) + RotL64(aOrbiterI, 11U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterA, 58U)) + aOrbiterE) + RotL64(aCarry, 37U)) + aPhaseDWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 29U) + aOrbiterE) + RotL64(aOrbiterB, 41U));
            aWandererH = aWandererH + ((((RotL64(aCross, 5U) + RotL64(aOrbiterJ, 3U)) + aOrbiterK) + RotL64(aCarry, 43U)) + aNonceWordI);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 23U)) + aOrbiterI) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterH, 19U)) + aOrbiterE);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterJ, 46U)) + aOrbiterI);
            aWandererF = aWandererF + ((RotL64(aIngress, 58U) + aOrbiterG) + RotL64(aOrbiterB, 21U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterK, 5U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 34U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 52U));
            aCarry = aCarry + RotL64(aWandererH, 43U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 19778U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 19416U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 18279U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17620U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 21U)) + (RotL64(aPrevious, 36U) ^ RotL64(aCross, 51U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterH = ((aWandererF + RotL64(aCross, 18U)) + 12632404972795375757U) + aPhaseDOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aPrevious, 27U)) + 5351879979055988456U;
            aOrbiterF = ((aWandererC + RotL64(aIngress, 3U)) + RotL64(aCarry, 11U)) + 3597737727467443413U;
            aOrbiterI = ((aWandererD + RotL64(aScatter, 57U)) + 2830846754917852318U) + aPhaseDOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 41U)) + RotL64(aCarry, 47U)) + 17311925960294518018U;
            aOrbiterC = (aWandererB + RotL64(aScatter, 51U)) + 2083584640523695383U;
            aOrbiterB = ((aWandererG + RotL64(aCross, 39U)) + RotL64(aCarry, 35U)) + 15049343611387010158U;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 21U)) + 6443050378205811147U) + aNonceWordH;
            aOrbiterE = (aWandererH + RotL64(aPrevious, 34U)) + 6021965178697344070U;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 11U)) + 5080289878758029976U) + aNonceWordC;
            aOrbiterK = (aWandererK + RotL64(aScatter, 13U)) + 576927745306972983U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 4728489691382690859U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 6184355840165758855U;
            aOrbiterF = RotL64((aOrbiterF * 1515043910404156423U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 11220539885798595450U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 11091438724966718214U;
            aOrbiterJ = RotL64((aOrbiterJ * 8225347114759391961U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 17184210490020062419U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 2150997767099116408U;
            aOrbiterC = RotL64((aOrbiterC * 8058553821648892499U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 7021953562676903717U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 17159676348343312834U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13877284519668483549U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 10367891770525239784U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 11922478487264201233U;
            aOrbiterD = RotL64((aOrbiterD * 9195137452661956029U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 17815162358981720634U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 9582631251085100284U;
            aOrbiterE = RotL64((aOrbiterE * 11838992994130850483U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 872593750259572264U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 17832330100262167302U;
            aOrbiterA = RotL64((aOrbiterA * 1114416841510028467U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 16601139856969287418U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 14931287111691324985U;
            aOrbiterK = RotL64((aOrbiterK * 16757174577841001179U), 23U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterA) + 11413072442039115924U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1]) + aNonceWordD;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 15253605470589905889U;
            aOrbiterH = RotL64((aOrbiterH * 10832817442285245673U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 3653487723581514107U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 14891378240114471865U;
            aOrbiterG = RotL64((aOrbiterG * 1386594204573386051U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 15659724464711852035U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 12632404972795375757U;
            aOrbiterI = RotL64((aOrbiterI * 2407347385127296647U), 39U);
            //
            aIngress = RotL64(aOrbiterJ, 19U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterK, 48U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 23U));
            aIngress = aIngress + RotL64(aOrbiterE, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 24U) + RotL64(aOrbiterI, 27U)) + aOrbiterE);
            aWandererB = aWandererB + ((RotL64(aCross, 53U) + RotL64(aOrbiterJ, 51U)) + aOrbiterC);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 43U) + aOrbiterI) + RotL64(aOrbiterA, 23U));
            aWandererG = aWandererG + (((RotL64(aIngress, 13U) + aOrbiterD) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterK, 5U)) + aOrbiterD);
            aWandererE = aWandererE + ((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 56U)) + aOrbiterJ);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 50U) + RotL64(aOrbiterJ, 39U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 21U) + aOrbiterG) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 11U)) + aPhaseDWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 5U) + aOrbiterH) + RotL64(aOrbiterG, 41U)) + aNonceWordN) + aPhaseDWandererUpdateSaltB[((aIndex + 8U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 37U) + aOrbiterF) + RotL64(aOrbiterB, 44U)) + aNonceWordG);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 27U) + aOrbiterI) + RotL64(aOrbiterD, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 54U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererH, 34U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 23231U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24272U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 23937U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((aIndex + 23993U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 39U)) + (RotL64(aIngress, 19U) ^ RotL64(aCarry, 52U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 21U)) + 18302975933754610273U) + aNonceWordK;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 19U)) + RotL64(aCarry, 3U)) + 16736972646771456082U;
            aOrbiterD = (aWandererE + RotL64(aCross, 3U)) + 17389406266488137442U;
            aOrbiterJ = (((aWandererG + RotL64(aScatter, 40U)) + RotL64(aCarry, 37U)) + 5252511566486165539U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = (aWandererA + RotL64(aPrevious, 37U)) + 5730715427422747640U;
            aOrbiterH = (aWandererF + RotL64(aScatter, 29U)) + 6412695646456045825U;
            aOrbiterI = (aWandererD + RotL64(aCross, 11U)) + 9539701605708994494U;
            aOrbiterE = (((aWandererI + RotL64(aIngress, 44U)) + RotL64(aCarry, 11U)) + 18355107116412945722U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aCross, 47U)) + 11735742491750132942U;
            aOrbiterB = (aWandererB + RotL64(aScatter, 51U)) + 12363819388562658842U;
            aOrbiterG = (aWandererC + RotL64(aIngress, 53U)) + 5861430292304371543U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 15027487084595017708U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 7012850020745791926U) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 15952928839355613939U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 11904871669287886120U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 11199760114477343208U;
            aOrbiterH = RotL64((aOrbiterH * 7156374911847525867U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 3856004502263742700U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 3705931243173921893U;
            aOrbiterE = RotL64((aOrbiterE * 10334871178498711485U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 12305785390539209389U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 18057980996551978823U;
            aOrbiterB = RotL64((aOrbiterB * 4850564181113470859U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 3229431819292153014U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 2994716629242460094U;
            aOrbiterC = RotL64((aOrbiterC * 1029427328395257917U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 9796307843453735512U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 2957260393651252432U;
            aOrbiterJ = RotL64((aOrbiterJ * 7261055869794739609U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 4060469664218866340U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 17462081697889685330U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7712009170974461225U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 13638660073917821172U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 15202349592659062565U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4514326257446024301U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 12071949111168967041U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 11930843273199806728U;
            aOrbiterG = RotL64((aOrbiterG * 16229663295689525137U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 11294220104731500296U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 440743185210586759U;
            aOrbiterF = RotL64((aOrbiterF * 14810195235168807229U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 8514240764798061804U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 18302975933754610273U;
            aOrbiterK = RotL64((aOrbiterK * 1972439346780950873U), 5U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterH, 27U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterF, 6U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 60U) + RotL64(aOrbiterC, 53U)) + aOrbiterB) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterJ, 60U)) + aOrbiterG) + aNonceWordL);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 11U)) + aOrbiterD);
            aWandererI = aWandererI ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterI, 41U)) + aOrbiterJ) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterG, 23U)) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterA, 39U)) + aOrbiterD);
            aWandererG = aWandererG + (((RotL64(aCross, 34U) + RotL64(aOrbiterK, 57U)) + aOrbiterD) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterE, 47U));
            aWandererK = aWandererK + ((RotL64(aCross, 39U) + RotL64(aOrbiterA, 3U)) + aOrbiterH);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 53U) + aOrbiterK) + RotL64(aOrbiterJ, 18U)) + aNonceWordI);
            aWandererH = aWandererH + ((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterF, 29U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (RotL64(aWandererJ, 6U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 41U);
            aCarry = aCarry + RotL64(aIngress, 4U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordE);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 32551U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneB[((aIndex + 30370U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27814U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((aIndex + 28714U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 53U)) + (RotL64(aCarry, 37U) ^ RotL64(aPrevious, 20U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterD = ((aWandererE + RotL64(aCross, 21U)) + RotL64(aCarry, 57U)) + 11177787645248006236U;
            aOrbiterE = (aWandererG + RotL64(aIngress, 35U)) + 3808340254579817169U;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 41U)) + 828030667598518279U) + aNonceWordK;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 43U)) + 16177835921238398371U) + aPhaseDOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 28U)) + 5518747735458708741U) + aNonceWordI;
            aOrbiterK = (aWandererA + RotL64(aIngress, 51U)) + 17346319082399995165U;
            aOrbiterA = ((aWandererK + RotL64(aCross, 39U)) + 6397156921893030937U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 53U)) + RotL64(aCarry, 47U)) + 15559381654710713582U;
            aOrbiterF = ((aWandererH + RotL64(aIngress, 3U)) + RotL64(aCarry, 37U)) + 940404446491415088U;
            aOrbiterH = ((aWandererD + RotL64(aCross, 12U)) + 8047166032048732645U) + aNonceWordN;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 23U)) + 4688468645859470491U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 3710878044770337260U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 116343189456629220U;
            aOrbiterI = RotL64((aOrbiterI * 5637725064169289339U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 883908030159391659U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 18058691521694880482U;
            aOrbiterB = RotL64((aOrbiterB * 3132200449123497619U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 17521015077103586117U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 3668332225435714918U;
            aOrbiterK = RotL64((aOrbiterK * 12658899101297839881U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 12229480388278883300U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 16206524049491531816U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11122340196620859805U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 5743265849441077466U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 2812293020719282236U;
            aOrbiterJ = RotL64((aOrbiterJ * 8903956475200417109U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 13718364781538837074U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 861529717259766236U;
            aOrbiterF = RotL64((aOrbiterF * 17019744777211266685U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 4862687502126693872U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 7722024283321020761U;
            aOrbiterH = RotL64((aOrbiterH * 18086944039541060829U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 8205803118233399853U) + aNonceWordP;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 15130160926615050422U;
            aOrbiterC = RotL64((aOrbiterC * 1454552751453996765U), 21U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterH) + 667469191899263617U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordB;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 18048970185163843471U;
            aOrbiterD = RotL64((aOrbiterD * 1800698970568737425U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 508102841337488721U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 3803840516662727630U;
            aOrbiterE = RotL64((aOrbiterE * 8477778555284121637U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 17055028117762299436U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 11177787645248006236U) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 12457019014051206805U), 47U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterD, 47U);
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 20U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 37U) + aOrbiterD) + RotL64(aOrbiterC, 53U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 51U) + RotL64(aOrbiterA, 19U)) + aOrbiterE) + RotL64(aCarry, 37U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 27U) + aOrbiterC) + RotL64(aOrbiterG, 14U)) + aNonceWordJ);
            aWandererC = aWandererC + ((RotL64(aPrevious, 30U) + RotL64(aOrbiterK, 21U)) + aOrbiterB);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterH, 43U)) + aOrbiterA);
            aWandererK = aWandererK + ((RotL64(aCross, 21U) + aOrbiterA) + RotL64(aOrbiterF, 57U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 23U) + aOrbiterC) + RotL64(aOrbiterI, 39U)) + aNonceWordG);
            aWandererE = aWandererE + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterH, 60U)) + aOrbiterC) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 57U) + aOrbiterF) + RotL64(aOrbiterJ, 27U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 14U) + aOrbiterK) + RotL64(aOrbiterE, 23U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 3U)) + aOrbiterK) + aPhaseDWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 52U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 43U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = aCarry ^ aNonceWordD;
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

void TwistExpander_BaseBall_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xAE6D5C0EBEE36B01ULL + 0xF2DC9B008BA14AA6ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xE4807751F6420603ULL + 0xA66EC90A037C3DB7ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xA3C77937AEB755EBULL + 0xD4E86B1012DCBCEDULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xE439709F8E867381ULL + 0xC17720FA115281ABULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xB73DF720578A55C3ULL + 0xD6865A143EE79D6BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x891C029142E56C19ULL + 0xA90E0FD585B39C27ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xE8560D019FCDA201ULL + 0xC25882BD595E4514ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x9F64209873452B95ULL + 0xE85E4A8B4096F976ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xECEAB19EE7959A8FULL + 0xF5F051C4C2F542FAULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x909E0D529525246BULL + 0xD368120B95772CB4ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xC5A6A0BB6AA829BBULL + 0xBE600080D2AA1CBEULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x94965574E86F8841ULL + 0x8661F0EE7A1BAE30ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xB27639EB371E0347ULL + 0x8D2DEEF14CEE483FULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xA368C1B1237EBF27ULL + 0xCD354EDD99C6E3C9ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xC6355D24B50036F1ULL + 0xBFAE97E28A9F1F6DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xB6CFA255426D6DD3ULL + 0x8711E6929C1DD10DULL);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 704U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 4633U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 310U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneA[((aIndex + 4646U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 36U) ^ RotL64(aIngress, 51U)) ^ (RotL64(aCross, 3U) + RotL64(aPrevious, 23U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterF = (aWandererD + RotL64(aScatter, 39U)) + 3612110001869385068U;
            aOrbiterC = (((aWandererB + RotL64(aIngress, 34U)) + RotL64(aCarry, 3U)) + 16340824141280225936U) + aNonceWordK;
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 41U)) + 15222338965130765231U;
            aOrbiterA = (aWandererK + RotL64(aCross, 51U)) + 6649270508107155041U;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 43U)) + RotL64(aCarry, 29U)) + 768217258655426384U;
            aOrbiterK = (((aWandererG + RotL64(aScatter, 37U)) + RotL64(aCarry, 53U)) + 4481855259658861851U) + aNonceWordN;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 19U)) + 18318041934562434016U;
            aOrbiterG = (((aWandererE + RotL64(aCross, 23U)) + 4212457153804401807U) + aPhaseEOrbiterAssignSaltB[((aIndex + 20U)) & S_SALT1]) + aNonceWordM;
            aOrbiterB = (aWandererC + RotL64(aIngress, 5U)) + 16143621095636987628U;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 13U)) + 2095664232866642086U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = (aWandererA + RotL64(aCross, 46U)) + 4339527736737366572U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 13679353177869884790U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 11582168502846418236U;
            aOrbiterE = RotL64((aOrbiterE * 135539430034462861U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 10451330452898542191U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 12951448817640617841U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4141870904192742091U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 15389161934419370747U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 4754886272708253014U;
            aOrbiterF = RotL64((aOrbiterF * 16638243718191281597U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 11746389873929280688U) + aNonceWordC;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 12042680172517298768U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3814780289755857543U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 2648103752465009244U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 451594673632597973U;
            aOrbiterJ = RotL64((aOrbiterJ * 8496763663271072425U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 5696534794094099710U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 14609435045257077395U;
            aOrbiterB = RotL64((aOrbiterB * 14658408563237468407U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 11599395126850950133U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 12699598504604446664U;
            aOrbiterH = RotL64((aOrbiterH * 14313494063098111823U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 9398465148537154745U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 12139736860648011256U;
            aOrbiterC = RotL64((aOrbiterC * 15257503229375247987U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 5390816291244486383U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 2797988892316486895U;
            aOrbiterD = RotL64((aOrbiterD * 14668138881285892065U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 18356290434261054712U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 16582824574485822826U) ^ aNonceWordB;
            aOrbiterG = RotL64((aOrbiterG * 7207935384746719969U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 9858803484150150915U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 3612110001869385068U;
            aOrbiterI = RotL64((aOrbiterI * 2862887443435821143U), 35U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 29U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 41U));
            aIngress = aIngress + (RotL64(aOrbiterF, 27U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + RotL64(aOrbiterI, 4U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterB, 19U));
            aWandererA = aWandererA + (((RotL64(aScatter, 12U) + aOrbiterG) + RotL64(aOrbiterJ, 3U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterC, 5U));
            aWandererK = aWandererK + ((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterF, 24U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 47U) + aOrbiterH) + RotL64(aOrbiterE, 21U));
            aWandererD = aWandererD + (((RotL64(aCross, 43U) + aOrbiterA) + RotL64(aOrbiterH, 41U)) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 53U)) + aOrbiterC) + aNonceWordD);
            aWandererG = aWandererG + (((RotL64(aIngress, 10U) + RotL64(aOrbiterK, 29U)) + aOrbiterG) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterI, 27U)) + aOrbiterK);
            aWandererH = aWandererH + ((RotL64(aIngress, 35U) + RotL64(aOrbiterD, 35U)) + aOrbiterC);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 37U) + aOrbiterI) + RotL64(aOrbiterJ, 50U)) + aPhaseEWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 60U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 10584U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneD[((aIndex + 6099U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 5693U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 6590U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aIngress, 27U)) ^ (RotL64(aPrevious, 6U) + RotL64(aCarry, 57U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterI = (aWandererH + RotL64(aIngress, 13U)) + 12311607308490066301U;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 5U)) + 13100864684740679846U) + aNonceWordN;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 21U)) + RotL64(aCarry, 27U)) + 13697304189274329704U;
            aOrbiterB = (aWandererI + RotL64(aCross, 35U)) + 9047976902871216732U;
            aOrbiterG = (aWandererA + RotL64(aIngress, 30U)) + 2147897579538537888U;
            aOrbiterF = ((aWandererF + RotL64(aCross, 41U)) + 2072444829390996142U) + aPhaseEOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aPrevious, 39U)) + 2129307836981020908U;
            aOrbiterK = ((aWandererK + RotL64(aScatter, 53U)) + RotL64(aCarry, 41U)) + 10663145333751112064U;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 27U)) + RotL64(aCarry, 23U)) + 15019844390503785459U;
            aOrbiterJ = (((aWandererE + RotL64(aPrevious, 57U)) + 5460865577557928142U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordL;
            aOrbiterC = (aWandererG + RotL64(aScatter, 60U)) + 15806522559993224197U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 6361113778657833389U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 8306013884615042570U;
            aOrbiterH = RotL64((aOrbiterH * 8234258702656728667U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 4038420580499706912U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 11908091484457158973U;
            aOrbiterE = RotL64((aOrbiterE * 3964111175645156719U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 11133912466611921250U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 2469227904206936928U;
            aOrbiterG = RotL64((aOrbiterG * 2704438771198001599U), 37U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterA) + 13234017916788297295U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1]) + aNonceWordM;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 9061117693840451988U;
            aOrbiterD = RotL64((aOrbiterD * 3637440416741459419U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 12013423690843812324U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 14371779015144617412U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3359568073302062667U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 10044883414565441442U) + aNonceWordD;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 14334898081890462218U;
            aOrbiterI = RotL64((aOrbiterI * 4878939077928220019U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 13788962593988366125U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 8377887372059713516U;
            aOrbiterB = RotL64((aOrbiterB * 1925913354197206851U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 4584439257847749371U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 13335592911357756498U;
            aOrbiterF = RotL64((aOrbiterF * 6515028218115896375U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 11166747459333977215U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 2368465601636093120U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1929974840976648333U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 4538402006569031063U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 3397601475441212067U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12043369327112500565U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 4804403185062062524U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 12311607308490066301U;
            aOrbiterC = RotL64((aOrbiterC * 10281231071618984185U), 27U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 51U);
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 34U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 53U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterC, 44U)) + RotL64(aCarry, 21U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 38U) + RotL64(aOrbiterE, 27U)) + aOrbiterB) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 5U) + RotL64(aOrbiterD, 19U)) + aOrbiterK);
            aWandererI = aWandererI ^ (((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterE, 13U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterA, 35U)) + RotL64(aCarry, 39U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterE, 60U)) + aOrbiterI);
            aWandererF = aWandererF + ((RotL64(aCross, 13U) + aOrbiterE) + RotL64(aOrbiterA, 37U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterG, 11U)) + aOrbiterK);
            aWandererE = aWandererE + (((RotL64(aScatter, 23U) + aOrbiterI) + RotL64(aOrbiterK, 29U)) + aNonceWordG);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 21U) + aOrbiterG) + RotL64(aOrbiterH, 47U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 48U) + aOrbiterC) + RotL64(aOrbiterB, 57U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 10U));
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 28U));
            aCarry = aCarry + RotL64(aWandererB, 53U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 11871U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 14222U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 13852U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 16036U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 44U) ^ RotL64(aCarry, 57U)) + (RotL64(aCross, 21U) ^ RotL64(aPrevious, 5U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterG = ((aWandererK + RotL64(aIngress, 43U)) + RotL64(aCarry, 41U)) + 15036852811491820366U;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 46U)) + 305637140752898475U) + aPhaseEOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aCross, 35U)) + 11948631574496129610U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 51U)) + 5321623592482991426U) + aNonceWordE;
            aOrbiterI = ((aWandererD + RotL64(aCross, 53U)) + RotL64(aCarry, 11U)) + 4075270159062690728U;
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 37U)) + 15111580500356908928U;
            aOrbiterB = (aWandererI + RotL64(aScatter, 60U)) + 7244150695504160363U;
            aOrbiterE = (aWandererF + RotL64(aIngress, 13U)) + 5131563519577488862U;
            aOrbiterK = (aWandererB + RotL64(aPrevious, 19U)) + 5881954992088651371U;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 27U)) + RotL64(aCarry, 51U)) + 12780935808751507998U;
            aOrbiterC = ((aWandererC + RotL64(aIngress, 57U)) + 12599159643925470226U) + aNonceWordI;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 9466589929741834066U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 6093158735705189789U;
            aOrbiterA = RotL64((aOrbiterA * 7453778295800853653U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 17461243886150519249U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 15456408913739900718U;
            aOrbiterH = RotL64((aOrbiterH * 16093292401746174671U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 11260643903290392780U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 7870342756041882616U;
            aOrbiterF = RotL64((aOrbiterF * 2431528656086173419U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 134484990005888936U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 10626896209992890407U) ^ aNonceWordC;
            aOrbiterI = RotL64((aOrbiterI * 12034131076645285597U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 14031164129515132292U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 1771835705730244212U;
            aOrbiterE = RotL64((aOrbiterE * 186981668443596623U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 16395472745067254664U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 1455944290845294254U;
            aOrbiterJ = RotL64((aOrbiterJ * 6757824754363319079U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 17866422769075350837U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 10226884082632410805U;
            aOrbiterG = RotL64((aOrbiterG * 206035536985843815U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 14474587247775371703U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 8501763445324525303U;
            aOrbiterD = RotL64((aOrbiterD * 5298694643596784007U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 222650368553738561U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 3901452368735982094U;
            aOrbiterB = RotL64((aOrbiterB * 18347115513126660483U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 3063093906728331146U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 9026710562384443411U;
            aOrbiterK = RotL64((aOrbiterK * 8411243802199203035U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 11282041925238364080U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 15036852811491820366U;
            aOrbiterC = RotL64((aOrbiterC * 18185121326941087841U), 23U);
            //
            aIngress = RotL64(aOrbiterD, 11U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterF, 58U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 23U));
            aIngress = aIngress + RotL64(aOrbiterB, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aIngress, 29U) + RotL64(aOrbiterK, 41U)) + aOrbiterH) + RotL64(aCarry, 11U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 60U) + aOrbiterE) + RotL64(aOrbiterH, 23U));
            aWandererE = aWandererE + (((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterF, 19U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterE, 21U)) + aOrbiterA) + aNonceWordF) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 43U) + aOrbiterB) + RotL64(aOrbiterE, 37U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 39U) + aOrbiterJ) + RotL64(aOrbiterB, 26U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 53U) + aOrbiterJ) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 29U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 14U) + RotL64(aOrbiterD, 53U)) + aOrbiterI);
            aWandererD = aWandererD + ((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterG, 51U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 23U) + aOrbiterA) + RotL64(aOrbiterJ, 56U));
            aWandererK = aWandererK + ((RotL64(aCross, 11U) + RotL64(aOrbiterD, 43U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 18U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 41U);
            aCarry = aCarry + RotL64(aIngress, 46U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 17378U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 18427U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20325U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 16657U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aPrevious, 6U)) ^ (RotL64(aIngress, 53U) + RotL64(aCarry, 41U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterB = (((aWandererG + RotL64(aScatter, 27U)) + RotL64(aCarry, 57U)) + 13442819395490639310U) + aNonceWordE;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 41U)) + 8187292523194120936U) + aNonceWordK;
            aOrbiterE = (aWandererE + RotL64(aPrevious, 46U)) + 11469697159823131388U;
            aOrbiterA = ((aWandererF + RotL64(aCross, 29U)) + 13414083692375929653U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 5U)) + 11404010733687907517U) + aNonceWordC;
            aOrbiterH = ((aWandererD + RotL64(aCross, 21U)) + 6783212827186218247U) + aPhaseEOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aScatter, 3U)) + 8561131439340372614U;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 23U)) + RotL64(aCarry, 5U)) + 6252609642004429113U;
            aOrbiterJ = (aWandererA + RotL64(aScatter, 13U)) + 12804867444200448952U;
            aOrbiterF = (aWandererC + RotL64(aCross, 50U)) + 2739648749603690781U;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 53U)) + RotL64(aCarry, 13U)) + 14808861217017399752U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 17588866502571268888U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 5882260142735642980U;
            aOrbiterE = RotL64((aOrbiterE * 7688252946143263869U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 15493099088132862949U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 5175647411532429582U;
            aOrbiterG = RotL64((aOrbiterG * 15226544495598541883U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 14279707376173642767U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 6826363572161275158U;
            aOrbiterH = RotL64((aOrbiterH * 5263708315440161809U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 13267185753040999992U) + aNonceWordJ;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 9980987858092888720U;
            aOrbiterK = RotL64((aOrbiterK * 13210290848800728635U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 3582972937645514549U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 10140409019562890804U) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 6944490201647678479U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 6160444117287330557U) + aNonceWordB;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 16344602960561293113U;
            aOrbiterJ = RotL64((aOrbiterJ * 2319964919335633293U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 3497141036108337171U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 91269118352540308U;
            aOrbiterF = RotL64((aOrbiterF * 5160060720189045505U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 12739932748793144857U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 12820180915064791197U;
            aOrbiterC = RotL64((aOrbiterC * 5843849637411948699U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 17572075652083359962U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 10684041099654982701U;
            aOrbiterB = RotL64((aOrbiterB * 7121293375756263771U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 10739534650885677354U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 9731206787727954809U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3730875775588585547U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 9655432616347117764U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 13442819395490639310U;
            aOrbiterA = RotL64((aOrbiterA * 3650859301708619119U), 29U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterB, 12U);
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterC, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aIngress, 34U) + aOrbiterI) + RotL64(aOrbiterH, 35U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterD, 37U)) + aOrbiterG) + aNonceWordF);
            aWandererE = aWandererE + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterE, 43U)) + aOrbiterF);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 26U)) + aOrbiterK);
            aWandererA = aWandererA + ((((RotL64(aIngress, 18U) + aOrbiterB) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 41U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 21U)) + aOrbiterA);
            aWandererD = aWandererD + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 13U)) + aOrbiterF) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 21U) + aOrbiterK) + RotL64(aOrbiterA, 3U));
            aWandererB = aWandererB + ((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 5U)) + aOrbiterI);
            aWandererG = aWandererG ^ (((RotL64(aCross, 11U) + aOrbiterB) + RotL64(aOrbiterG, 23U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterE, 28U)) + aOrbiterB) + aNonceWordA);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 48U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + RotL64(aWandererI, 26U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ aNonceWordN;
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 23254U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25698U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24088U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneA[((aIndex + 25382U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aPrevious, 35U)) + (RotL64(aCarry, 52U) ^ RotL64(aIngress, 21U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterE = ((aWandererG + RotL64(aIngress, 34U)) + 15726877954695761686U) + aPhaseEOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 39U)) + RotL64(aCarry, 53U)) + 14187652171881943587U;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 51U)) + RotL64(aCarry, 57U)) + 8420423151313882782U;
            aOrbiterG = (aWandererE + RotL64(aCross, 57U)) + 14942322692433259283U;
            aOrbiterA = (aWandererK + RotL64(aScatter, 28U)) + 7272331475919796255U;
            aOrbiterD = (aWandererC + RotL64(aIngress, 21U)) + 154504365041805840U;
            aOrbiterK = ((aWandererH + RotL64(aCross, 5U)) + 17475491222554948786U) + aNonceWordF;
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 47U)) + 5759181483165339605U;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 53U)) + 5993060214499322845U;
            aOrbiterF = (((aWandererF + RotL64(aIngress, 37U)) + RotL64(aCarry, 23U)) + 10901786237875941844U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = (aWandererA + RotL64(aPrevious, 13U)) + 17135786595614068473U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 5208202073886811165U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 6821452921018900631U;
            aOrbiterH = RotL64((aOrbiterH * 13119330055184115669U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 13348064837402206969U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 8967943922403445136U;
            aOrbiterD = RotL64((aOrbiterD * 300168481725373093U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 8130283784171430891U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 6351113882502502876U;
            aOrbiterC = RotL64((aOrbiterC * 15960622823993072903U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 6894708729226455769U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 12065058511247133944U;
            aOrbiterF = RotL64((aOrbiterF * 5432601727436935831U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 17138279326229372741U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 12987698199066890628U;
            aOrbiterE = RotL64((aOrbiterE * 12665716655177320977U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 13688833537574196675U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 4211971980434000618U;
            aOrbiterG = RotL64((aOrbiterG * 1374411763361518851U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 10376917117582537592U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 4807742522197923516U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15257251453302090961U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 18038296468177121243U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 6879666349379745258U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15819475269715810555U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 5193656664432659624U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 680899397323387963U) ^ aNonceWordH;
            aOrbiterB = RotL64((aOrbiterB * 9857476056194621321U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 1851929589073547860U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 13093101559415170218U;
            aOrbiterI = RotL64((aOrbiterI * 13950928576652143737U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 13695333301427028607U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 15726877954695761686U;
            aOrbiterA = RotL64((aOrbiterA * 960063676226172027U), 39U);
            //
            aIngress = RotL64(aOrbiterF, 57U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + (RotL64(aOrbiterH, 60U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aCross, 21U) + aOrbiterK) + RotL64(aOrbiterF, 35U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterD, 29U)) + aOrbiterI) + aPhaseEWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 58U)) + aOrbiterJ);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 60U) + aOrbiterG) + RotL64(aOrbiterC, 11U));
            aWandererE = aWandererE + ((((RotL64(aCross, 43U) + RotL64(aOrbiterC, 39U)) + aOrbiterD) + RotL64(aCarry, 5U)) + aNonceWordB);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 41U) + aOrbiterG) + RotL64(aOrbiterB, 3U)) + aNonceWordE);
            aWandererI = aWandererI + (((RotL64(aIngress, 27U) + RotL64(aOrbiterH, 37U)) + aOrbiterE) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterH, 41U)) + aOrbiterD);
            aWandererG = aWandererG + ((RotL64(aIngress, 54U) + RotL64(aOrbiterE, 60U)) + aOrbiterD);
            aWandererB = aWandererB ^ ((RotL64(aCross, 51U) + aOrbiterK) + RotL64(aOrbiterC, 53U));
            aWandererA = aWandererA + (((RotL64(aScatter, 57U) + RotL64(aOrbiterA, 27U)) + aOrbiterK) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 58U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 41U));
            aCarry = aCarry + RotL64(aWandererG, 37U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 30793U)) & S_BLOCK1], 42U) ^ RotL64(aOperationLaneB[((aIndex + 29785U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31158U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneB[((aIndex + 32344U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aIngress, 38U)) ^ (RotL64(aCross, 11U) + RotL64(aPrevious, 23U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterA = (aWandererH + RotL64(aPrevious, 27U)) + 9888431329297626900U;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 34U)) + RotL64(aCarry, 3U)) + 2937735167534624403U;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 39U)) + 17626022970343789617U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aCross, 43U)) + RotL64(aCarry, 41U)) + 5665660859333693743U;
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 41U)) + 1060537034632076669U) + aPhaseEOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = (aWandererA + RotL64(aIngress, 29U)) + 743777763907175800U;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 47U)) + RotL64(aCarry, 47U)) + 5744905970181808845U;
            aOrbiterB = (aWandererB + RotL64(aCross, 11U)) + 3545351394494002180U;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 18U)) + 4877547088414106007U;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 37U)) + 11669378338379598445U) + aNonceWordE;
            aOrbiterH = ((aWandererG + RotL64(aCross, 21U)) + 2961072441706158212U) + aNonceWordC;
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 13984945589234919765U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 1433097875470903205U;
            aOrbiterK = RotL64((aOrbiterK * 451996840039906781U), 21U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterD) + 716415411025451152U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1]) + aNonceWordH;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterI) ^ 8542286150858297810U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 9139015340823332449U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 12932391786479661299U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 14005503313299177013U;
            aOrbiterC = RotL64((aOrbiterC * 802663466907819743U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 9382792812676318046U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 5138554251079724724U;
            aOrbiterF = RotL64((aOrbiterF * 6386016499265056247U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 8522380066269546172U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 11825536408101906458U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17042837108792016849U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 15504062350899452495U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 1219010998820336744U;
            aOrbiterG = RotL64((aOrbiterG * 10650635772711590803U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 6442717843380349632U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 1047843426279085117U;
            aOrbiterE = RotL64((aOrbiterE * 4074561571072878005U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 10611039527108679173U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 5092816736177358221U;
            aOrbiterH = RotL64((aOrbiterH * 14342779343820140833U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 12327496881352988530U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 6405703847824845457U;
            aOrbiterA = RotL64((aOrbiterA * 12094143526751620113U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 8906613392335197542U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 5962698890029858689U;
            aOrbiterI = RotL64((aOrbiterI * 9136193803330500489U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 2610083915800734277U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 9888431329297626900U;
            aOrbiterD = RotL64((aOrbiterD * 3794133356691218671U), 43U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterG, 53U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterD, 30U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterF, 5U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aScatter, 19U) + aOrbiterE) + RotL64(aOrbiterJ, 53U)) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 30U) + aOrbiterD) + RotL64(aOrbiterK, 44U));
            aWandererC = aWandererC + ((RotL64(aCross, 13U) + aOrbiterD) + RotL64(aOrbiterI, 3U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterC, 29U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 3U) + aOrbiterB) + RotL64(aOrbiterH, 47U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterI, 39U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 10U) + aOrbiterH) + RotL64(aOrbiterA, 10U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 41U) + aOrbiterE) + RotL64(aOrbiterK, 57U)) + aNonceWordN);
            aWandererB = aWandererB + ((((RotL64(aIngress, 51U) + aOrbiterK) + RotL64(aOrbiterH, 27U)) + RotL64(aCarry, 57U)) + aPhaseEWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterD, 37U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + (RotL64(aWandererF, 50U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ aNonceWordB;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x806F57E840E43AFDULL + 0xAC73B7939FB49C79ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xA1447D16E646347DULL + 0xD85048D4A19F9002ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xEF0B7E4C067B1DCFULL + 0xA39A53DD6BB71D81ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xE156B0D266E2D785ULL + 0xE616D9EA3C60BF98ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xA36E10FAFCD8DF2FULL + 0xD4E55AE8AB07B285ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x809951EA1B109067ULL + 0xC316EB85909AC338ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xDEA46E333A5CE615ULL + 0x8894365FE293E9D3ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xBB96289D6B7F019BULL + 0xE8B4F2C7F4102C2BULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xC25ACFE316DD8F1BULL + 0xF9307557E24CF618ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xA32FC12B4E5B9D7FULL + 0x855CEED4AC8DB573ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xE7095B6A155E43A9ULL + 0xDDE96B6FDE0F7597ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xC28793D4B693F5A1ULL + 0x8295051E40EA7442ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xF72DFA8C72FCCCCDULL + 0x83064E84A277569DULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xD11065E5A95E565DULL + 0x8D1DF7244D385A65ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xF73B301AE94CAAD7ULL + 0x9722A992675AB5ADULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xD402ABC0F1FCE6D3ULL + 0x95626B7A28710821ULL);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 1645U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((aIndex + 2154U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 2611U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 1054U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCross, 20U)) + (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 47U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 23U)) + RotL64(aCarry, 5U)) + 4179952823252098240U;
            aOrbiterG = (aWandererJ + RotL64(aIngress, 35U)) + 3745613452332101749U;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 6U)) + RotL64(aCarry, 35U)) + 2955689793395307176U;
            aOrbiterA = (aWandererG + RotL64(aCross, 13U)) + 5639060180251322019U;
            aOrbiterB = (aWandererH + RotL64(aScatter, 29U)) + 7901969163853586463U;
            aOrbiterK = (aWandererB + RotL64(aIngress, 47U)) + 2242166787816318119U;
            aOrbiterJ = (((aWandererK + RotL64(aPrevious, 21U)) + 5239936443960750064U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordP;
            aOrbiterF = ((aWandererA + RotL64(aCross, 56U)) + RotL64(aCarry, 41U)) + 13939136954732185558U;
            aOrbiterI = (aWandererE + RotL64(aScatter, 19U)) + 17058884136712717463U;
            aOrbiterE = ((aWandererI + RotL64(aCross, 53U)) + 18148618660054585941U) + aPhaseFOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = (aWandererD + RotL64(aIngress, 11U)) + 7022023484530327814U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 7722084537340095637U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 11764151879690934182U) ^ aNonceWordJ;
            aOrbiterH = RotL64((aOrbiterH * 12264384877711365655U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 16412785901758144708U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 9666718667728274824U;
            aOrbiterK = RotL64((aOrbiterK * 10865799822751771795U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 4307127540152109364U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 2457646804702647606U;
            aOrbiterD = RotL64((aOrbiterD * 6340030928007058595U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 3179394870088602208U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 504977947273774249U;
            aOrbiterA = RotL64((aOrbiterA * 16190282058883481551U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 16182729401018310837U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 7110817020445860609U;
            aOrbiterJ = RotL64((aOrbiterJ * 13371352088428584087U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 12960656706837391973U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 7103806893724395904U;
            aOrbiterI = RotL64((aOrbiterI * 14365984439655979791U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 1248300178080633527U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 7195473175424961337U;
            aOrbiterC = RotL64((aOrbiterC * 4633558992739305045U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 13007951568242991449U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 10296811247653636372U;
            aOrbiterG = RotL64((aOrbiterG * 16469682651380549395U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 13922797949001028335U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 16773545425463040155U;
            aOrbiterB = RotL64((aOrbiterB * 10639282630227832397U), 13U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterI) + 2888887140296117803U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordL;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 10279517418046269817U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8600355360339461535U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 17303373436784809093U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 4179952823252098240U;
            aOrbiterE = RotL64((aOrbiterE * 3675754609699406437U), 37U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterF, 40U);
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + RotL64(aOrbiterB, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterD, 51U)) + RotL64(aCarry, 35U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 28U) + aOrbiterH) + RotL64(aOrbiterJ, 26U)) + aNonceWordI);
            aWandererK = aWandererK + (((RotL64(aCross, 21U) + aOrbiterI) + RotL64(aOrbiterH, 47U)) + aNonceWordC);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterF, 41U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aScatter, 23U) + aOrbiterI) + RotL64(aOrbiterE, 35U)) + aPhaseFWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterD, 11U)) + aOrbiterC);
            aWandererH = aWandererH + (((RotL64(aCross, 12U) + RotL64(aOrbiterH, 19U)) + aOrbiterC) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 53U) + aOrbiterB) + RotL64(aOrbiterI, 43U));
            aWandererI = aWandererI + (((RotL64(aIngress, 51U) + aOrbiterA) + RotL64(aOrbiterE, 30U)) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterH, 37U)) + aNonceWordM);
            aWandererD = aWandererD + ((RotL64(aScatter, 57U) + RotL64(aOrbiterA, 3U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 48U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + RotL64(aWandererH, 57U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordB;
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 7374U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneD[((aIndex + 10758U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 8035U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10039U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCarry, 4U)) + (RotL64(aPrevious, 51U) ^ RotL64(aCross, 39U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = ((aWandererH + RotL64(aScatter, 23U)) + 1457104756581596530U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aIngress, 29U)) + RotL64(aCarry, 35U)) + 6127240317844622874U;
            aOrbiterC = (aWandererC + RotL64(aCross, 37U)) + 16492290056044189421U;
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 60U)) + RotL64(aCarry, 47U)) + 10963676850938416468U;
            aOrbiterH = ((((aWandererA + RotL64(aScatter, 53U)) + RotL64(aCarry, 21U)) + 4872917367399752405U) + aPhaseFOrbiterAssignSaltA[((aIndex + 6U)) & S_SALT1]) + aNonceWordF;
            aOrbiterA = (aWandererD + RotL64(aCross, 41U)) + 15218882377875616148U;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 35U)) + 5934166612122118251U) + aNonceWordD;
            aOrbiterJ = (aWandererB + RotL64(aIngress, 13U)) + 14215280930872003003U;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 18U)) + 11428034799044600979U) + aNonceWordI;
            aOrbiterI = (aWandererK + RotL64(aCross, 57U)) + 5453003654321728726U;
            aOrbiterD = (aWandererE + RotL64(aIngress, 47U)) + 14273775120265649389U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 328723770018440271U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 13032190719588211088U;
            aOrbiterC = RotL64((aOrbiterC * 13363368478932798315U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 2386881543033598494U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 1649501123340887116U;
            aOrbiterF = RotL64((aOrbiterF * 11148976582360499033U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 16462401546754210583U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 1510579201823042227U;
            aOrbiterH = RotL64((aOrbiterH * 16287912400104043275U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 6889066000014251983U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 11324594596597724357U;
            aOrbiterE = RotL64((aOrbiterE * 15344987814648586023U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 12237796033168436537U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 17306069670330000343U;
            aOrbiterB = RotL64((aOrbiterB * 3167451351403385259U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 14197284538008811658U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterD) ^ 4754134852883071927U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterK = RotL64((aOrbiterK * 3484427259538998699U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 17201907781639753736U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 8318419319239859855U;
            aOrbiterG = RotL64((aOrbiterG * 10320390501983802091U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 16012488623961565780U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 15583721012865354925U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10656414363201743961U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 14680351201973315018U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 14483973292275372321U;
            aOrbiterJ = RotL64((aOrbiterJ * 9279222721410811027U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 16324317860030681248U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 7038506963317910910U) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 2960451734542956767U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 12767672960346001218U) + aNonceWordM;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 1457104756581596530U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1560375242310194691U), 53U);
            //
            aIngress = RotL64(aOrbiterI, 58U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterH, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterG, 47U)) + aOrbiterI);
            aWandererH = aWandererH + (((RotL64(aPrevious, 22U) + aOrbiterA) + RotL64(aOrbiterE, 51U)) + aPhaseFWandererUpdateSaltB[((aIndex + 4U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterK, 21U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 42U)) + aOrbiterE) + RotL64(aCarry, 47U)) + aPhaseFWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 57U) + aOrbiterJ) + RotL64(aOrbiterK, 19U)) + aNonceWordE);
            aWandererG = aWandererG + (((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterH, 39U)) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 27U) + aOrbiterH) + RotL64(aOrbiterI, 11U));
            aWandererE = aWandererE + ((RotL64(aCross, 37U) + RotL64(aOrbiterD, 3U)) + aOrbiterH);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 48U) + aOrbiterK) + RotL64(aOrbiterC, 5U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterK, 35U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 53U) + aOrbiterH) + RotL64(aOrbiterG, 54U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (RotL64(aWandererB, 46U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererK, 60U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordG);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13814U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13226U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 14920U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 11822U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 54U)) + (RotL64(aIngress, 3U) + RotL64(aCross, 29U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = ((aWandererC + RotL64(aCross, 11U)) + RotL64(aCarry, 47U)) + 16189787374324972735U;
            aOrbiterA = (aWandererH + RotL64(aIngress, 27U)) + 17563763730956242224U;
            aOrbiterF = (((aWandererF + RotL64(aScatter, 23U)) + 10572803498593789385U) + aPhaseFOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1]) + aNonceWordO;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 39U)) + RotL64(aCarry, 27U)) + 7713105232072974166U;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 14U)) + 10760839534772718139U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aCross, 41U)) + 13397069448391230253U;
            aOrbiterK = (aWandererK + RotL64(aPrevious, 5U)) + 4569255679998375682U;
            aOrbiterD = (aWandererB + RotL64(aScatter, 37U)) + 9888769350817876949U;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 34U)) + 11351796060878856300U) + aNonceWordP;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 29U)) + 18153775071965707204U) + aNonceWordB;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 19U)) + RotL64(aCarry, 19U)) + 1282846411145853435U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 16457743979262460660U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 173493260775251032U;
            aOrbiterF = RotL64((aOrbiterF * 4935807229040883505U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 3927345926316409630U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 5158769729850853623U;
            aOrbiterG = RotL64((aOrbiterG * 2446452358663812945U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 12331351600010165154U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 3940794200348684050U;
            aOrbiterA = RotL64((aOrbiterA * 13248997263062075043U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 11248514843822945425U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 1391497323278226522U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8376841806072565005U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 13265623528678787307U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 2802033745265647317U;
            aOrbiterD = RotL64((aOrbiterD * 3437626962562016147U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 6938444301018051844U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 1086544666755559028U;
            aOrbiterI = RotL64((aOrbiterI * 16039728388882079889U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 16156443117365816536U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 3619942859562697142U;
            aOrbiterH = RotL64((aOrbiterH * 7589346043159112151U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 17681848914912743292U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 8848238631758130416U) ^ aNonceWordL;
            aOrbiterB = RotL64((aOrbiterB * 810402256099500607U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 6019192027793541890U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 16917288363166352778U;
            aOrbiterK = RotL64((aOrbiterK * 17673667086593738207U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 5598218150530046752U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 17285995539011279010U;
            aOrbiterE = RotL64((aOrbiterE * 15621233176885995065U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 12380627610747299268U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 16189787374324972735U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2144714828503219209U), 5U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 26U);
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 13U)) + aOrbiterB) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 46U) + aOrbiterG) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 11U)) + aOrbiterD);
            aWandererF = aWandererF + (((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 47U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 11U) + aOrbiterF) + RotL64(aOrbiterD, 57U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 53U) + aOrbiterI) + RotL64(aOrbiterA, 4U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterK, 37U)) + aOrbiterD) + aNonceWordK);
            aWandererK = aWandererK + ((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterG, 27U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterH, 53U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 24U) + aOrbiterB) + RotL64(aOrbiterH, 43U)) + aNonceWordJ);
            aWandererG = aWandererG ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterB, 50U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 48U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 46U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererE, 39U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordH);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 19694U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19105U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21141U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneD[((aIndex + 18222U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aPrevious, 6U)) ^ (RotL64(aCarry, 27U) + RotL64(aIngress, 57U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterB = ((aWandererA + RotL64(aScatter, 20U)) + RotL64(aCarry, 13U)) + 6068543441070417854U;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 39U)) + 2995980468193441856U;
            aOrbiterG = (aWandererG + RotL64(aCross, 41U)) + 18020277482171594003U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 35U)) + RotL64(aCarry, 39U)) + 4293807434721230702U;
            aOrbiterE = ((((aWandererD + RotL64(aCross, 57U)) + RotL64(aCarry, 43U)) + 7980599111583893156U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordD;
            aOrbiterJ = (aWandererE + RotL64(aScatter, 27U)) + 8593141111851052016U;
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 51U)) + 5903487523900084325U) + aNonceWordL;
            aOrbiterK = (aWandererF + RotL64(aIngress, 53U)) + 15112035513447930209U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 4U)) + 9854037263057006439U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aScatter, 11U)) + 16759760289688823193U;
            aOrbiterH = (aWandererK + RotL64(aIngress, 13U)) + 12622628933030601390U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 1264668857268123425U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 16302812053619101593U;
            aOrbiterG = RotL64((aOrbiterG * 18291400055836111547U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 16087995784896123610U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 7970269262800468363U;
            aOrbiterE = RotL64((aOrbiterE * 14924752223305807461U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 5331477046030959632U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 16534913204255550893U;
            aOrbiterJ = RotL64((aOrbiterJ * 1013433634373673565U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 11042821902537871209U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 8069677512345031660U;
            aOrbiterC = RotL64((aOrbiterC * 13622218526054132397U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 5737130058129936372U) + aNonceWordJ;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 1076627182956662997U;
            aOrbiterK = RotL64((aOrbiterK * 14342191224014199929U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 13911061091801078190U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 15397603151098990373U;
            aOrbiterA = RotL64((aOrbiterA * 1802890451633592245U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 15137326716738637972U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 11248737008959896786U;
            aOrbiterD = RotL64((aOrbiterD * 90789374131547005U), 11U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterA) + 1847847987633923657U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordE;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 10560748778679145431U;
            aOrbiterH = RotL64((aOrbiterH * 2919333327817231099U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 2703726238610290251U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 12950671360471467310U;
            aOrbiterB = RotL64((aOrbiterB * 7490327691501537047U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 10331504168520449467U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 1541527607705280906U;
            aOrbiterI = RotL64((aOrbiterI * 14197400812600186171U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 9135056476214341809U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 6068543441070417854U) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 14102524444094948875U), 21U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 43U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 34U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + RotL64(aOrbiterC, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 22U) + RotL64(aOrbiterK, 37U)) + aOrbiterE);
            aWandererG = aWandererG + ((RotL64(aCross, 27U) + aOrbiterA) + RotL64(aOrbiterK, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 11U) + aOrbiterH) + RotL64(aOrbiterC, 34U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterH, 19U)) + aOrbiterE) + RotL64(aCarry, 21U)) + aNonceWordM);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 34U) + RotL64(aOrbiterG, 51U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aScatter, 37U) + RotL64(aOrbiterB, 53U)) + aOrbiterC) + aPhaseFWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterA, 26U)) + aOrbiterD) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 39U) + RotL64(aOrbiterB, 13U)) + aOrbiterJ) + aNonceWordK);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 29U)) + aOrbiterB) + aNonceWordB);
            aWandererA = aWandererA + (((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 53U) + aOrbiterI) + RotL64(aOrbiterE, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 18U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 5U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ aNonceWordJ;
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 25578U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24436U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24692U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 24761U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 35U)) + (RotL64(aCarry, 50U) ^ RotL64(aIngress, 21U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = (aWandererE + RotL64(aIngress, 26U)) + 12380376990224645149U;
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 21U)) + 18296928500297384014U) + aNonceWordK;
            aOrbiterC = (aWandererC + RotL64(aPrevious, 23U)) + 3550626816361145100U;
            aOrbiterK = (aWandererF + RotL64(aCross, 5U)) + 2667792936946706027U;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 51U)) + 12020969779370926953U;
            aOrbiterH = (aWandererH + RotL64(aCross, 56U)) + 737340727886903447U;
            aOrbiterI = (aWandererB + RotL64(aScatter, 13U)) + 1681797651799760502U;
            aOrbiterE = ((aWandererD + RotL64(aIngress, 53U)) + RotL64(aCarry, 5U)) + 2956186342689489064U;
            aOrbiterF = (aWandererJ + RotL64(aScatter, 47U)) + 1876852870402977177U;
            aOrbiterA = (((aWandererG + RotL64(aPrevious, 37U)) + RotL64(aCarry, 27U)) + 6433205819353555071U) + aPhaseFOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = (((aWandererI + RotL64(aCross, 35U)) + RotL64(aCarry, 23U)) + 9065076854974222998U) + aPhaseFOrbiterAssignSaltE[((aIndex + 20U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 3254410578766789992U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 2005081975473815576U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9947701153722014085U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 15992999234834560419U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 3458344156815120948U) ^ aNonceWordF;
            aOrbiterH = RotL64((aOrbiterH * 1668460113964608051U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 17069783053664877727U) + aNonceWordI;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 1260234710193913099U;
            aOrbiterE = RotL64((aOrbiterE * 4561226779897414381U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 3825186451876061335U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 2905344294992827535U;
            aOrbiterA = RotL64((aOrbiterA * 2469896090698580795U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 18141402347899180617U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 8760129857609925066U;
            aOrbiterD = RotL64((aOrbiterD * 2507999156108123047U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 594052473780678210U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 13216719212966128379U;
            aOrbiterK = RotL64((aOrbiterK * 10691355329696722303U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 10029948739466316169U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 11912428807431992996U;
            aOrbiterI = RotL64((aOrbiterI * 85016510811938307U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 8735634019801417287U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 12785916159063273545U;
            aOrbiterF = RotL64((aOrbiterF * 1161917531260663357U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 367752057919802452U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 3961036242431041564U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16352646009782597315U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 3858415336170090719U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 14325258358254321551U;
            aOrbiterJ = RotL64((aOrbiterJ * 12080431158781060059U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 16872184337970977180U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 12380376990224645149U;
            aOrbiterB = RotL64((aOrbiterB * 16559121155413059221U), 35U);
            //
            aIngress = RotL64(aOrbiterJ, 57U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterG, 26U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 43U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 11U));
            aIngress = aIngress + RotL64(aOrbiterK, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aIngress, 13U) + aOrbiterG) + RotL64(aOrbiterK, 14U)) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 54U) + RotL64(aOrbiterF, 23U)) + aOrbiterB);
            aWandererE = aWandererE + (((RotL64(aScatter, 27U) + RotL64(aOrbiterC, 29U)) + aOrbiterI) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterD, 53U)) + aOrbiterF);
            aWandererK = aWandererK + (((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterE, 39U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterJ, 21U)) + aOrbiterA);
            aWandererH = aWandererH + (((RotL64(aIngress, 24U) + aOrbiterI) + RotL64(aOrbiterK, 27U)) + aPhaseFWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterJ, 5U)) + aOrbiterH) + aNonceWordE);
            aWandererG = aWandererG + ((RotL64(aIngress, 37U) + RotL64(aOrbiterD, 3U)) + aOrbiterH);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 51U) + aOrbiterH) + RotL64(aOrbiterF, 34U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterC, 37U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererB, 34U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + (RotL64(aWandererJ, 18U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ aNonceWordJ;
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28636U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneB[((aIndex + 29118U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31270U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((aIndex + 29902U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCross, 5U)) + (RotL64(aIngress, 24U) ^ RotL64(aCarry, 41U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = (aWandererE + RotL64(aIngress, 51U)) + 13296600294247799698U;
            aOrbiterI = ((aWandererB + RotL64(aScatter, 37U)) + RotL64(aCarry, 27U)) + 5818503518080877515U;
            aOrbiterF = ((aWandererI + RotL64(aCross, 56U)) + 6735784238734173597U) + aNonceWordK;
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 13U)) + 7368398209488856201U) + aPhaseFOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aIngress, 11U)) + 961734029066455638U;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 41U)) + RotL64(aCarry, 3U)) + 797011946660892011U;
            aOrbiterK = ((aWandererD + RotL64(aCross, 18U)) + RotL64(aCarry, 53U)) + 12841876018396622350U;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 47U)) + 16213253970483895623U) + aPhaseFOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aIngress, 39U)) + 15186950557113470375U;
            aOrbiterJ = (aWandererF + RotL64(aScatter, 3U)) + 5117930310827477341U;
            aOrbiterH = (aWandererA + RotL64(aCross, 27U)) + 12265429373166094162U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 13920531346698601568U) + aNonceWordF;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 14695405206998211456U;
            aOrbiterF = RotL64((aOrbiterF * 13950964363414164279U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 7851960904825938443U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 9501511171732550190U;
            aOrbiterA = RotL64((aOrbiterA * 5614164120361489613U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 5663365182245722077U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 9607860124321315555U) ^ aNonceWordH;
            aOrbiterD = RotL64((aOrbiterD * 3461820361914280601U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 18171052650586819280U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 3442698321538580861U) ^ aNonceWordI;
            aOrbiterK = RotL64((aOrbiterK * 6317525514963824829U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 1491052813469258970U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 3956599824067616133U;
            aOrbiterC = RotL64((aOrbiterC * 2928600779267623085U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 10963841237346073453U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 2303020125591252534U;
            aOrbiterG = RotL64((aOrbiterG * 9969099842343321981U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 14503856057958162356U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 11147548150090597694U;
            aOrbiterJ = RotL64((aOrbiterJ * 11856382308792700441U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 9191681438318311481U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 13556072770381999852U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 18316231099054203683U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 10103207278550444685U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 10415809965217261104U;
            aOrbiterE = RotL64((aOrbiterE * 16562732599511350217U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 17435033201864058457U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 5540494424887364682U;
            aOrbiterI = RotL64((aOrbiterI * 18230910315317249045U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 18020151683897013854U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 13296600294247799698U;
            aOrbiterB = RotL64((aOrbiterB * 10000194329456668845U), 35U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 10U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 27U));
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 53U));
            aIngress = aIngress + RotL64(aOrbiterK, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterG, 5U)) + aOrbiterA);
            aWandererE = aWandererE + ((RotL64(aIngress, 29U) + RotL64(aOrbiterH, 53U)) + aOrbiterA);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 21U) + aOrbiterI) + RotL64(aOrbiterE, 48U)) + aPhaseFWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterC, 35U)) + aPhaseFWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 48U) + RotL64(aOrbiterK, 43U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 23U) + aOrbiterB) + RotL64(aOrbiterD, 3U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterH, 14U));
            aWandererA = aWandererA + ((((RotL64(aCross, 51U) + aOrbiterJ) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 41U)) + aNonceWordP);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterJ, 51U)) + aOrbiterD);
            aWandererD = aWandererD + ((((RotL64(aScatter, 18U) + aOrbiterD) + RotL64(aOrbiterG, 27U)) + RotL64(aCarry, 11U)) + aNonceWordC);
            aWandererG = aWandererG ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterA, 23U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (RotL64(aWandererE, 60U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + RotL64(aWandererH, 10U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ aNonceWordE;
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

void TwistExpander_BaseBall_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xB5A7B96338A1377BULL + 0xDC6AF68D55CB3FABULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xC688132E4A14FD3FULL + 0xD84B6B04C97BC6B1ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x9D2BE2039FB353DDULL + 0xCE07EF9867950677ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x9BD89E41ACE0CFDDULL + 0xA8058BCB15D1D807ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xDC740874631D6F6DULL + 0xAA4028B0E97CF548ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xCF0EBE1347E55A0DULL + 0xE05D0CD57C2E22E6ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x80202A4A12D61C17ULL + 0xAEEAB19ADF80A6EDULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x8ED20502D85647FDULL + 0xD320ADF36BA5B2D5ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x95C90B244CB30AA3ULL + 0xD5D88EB571A0BF34ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xC0090FE5474CCDCBULL + 0xA6530651AB3684A2ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x8A8C37D08AF15BD1ULL + 0x8E787F2FCA29073BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xD988DEAAE5FEA0A3ULL + 0xFB0983FFB22C4C73ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xE954582F657AB1AFULL + 0xE951D537F0F85AD7ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xDB6C674AFAF7FAF5ULL + 0x92B77C4A7E98E377ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xD1B4025A4FD37B3DULL + 0x9B0082C5A9D633B1ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xB0A5743261EACAC9ULL + 0xFF7C0D807058E86FULL);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 35U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneC[((aIndex + 5130U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 1181U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((aIndex + 945U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 10U) ^ RotL64(aIngress, 35U)) + (RotL64(aCross, 23U) + RotL64(aPrevious, 53U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = (aWandererD + RotL64(aCross, 43U)) + 14823268998003220191U;
            aOrbiterA = (aWandererK + RotL64(aIngress, 10U)) + 15295237288788213847U;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 53U)) + RotL64(aCarry, 27U)) + 16434853402001133899U;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 23U)) + RotL64(aCarry, 51U)) + 7555911304407871631U;
            aOrbiterK = ((aWandererC + RotL64(aScatter, 19U)) + 14977248264994834620U) + aPhaseFOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = (((aWandererA + RotL64(aIngress, 37U)) + RotL64(aCarry, 35U)) + 9707764144919392380U) + aPhaseFOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 29U)) + 1277304385464681529U) + aNonceWordJ;
            aOrbiterH = (aWandererE + RotL64(aCross, 46U)) + 3089786220465849395U;
            aOrbiterE = (aWandererI + RotL64(aPrevious, 57U)) + 3700503853358695085U;
            aOrbiterJ = ((aWandererH + RotL64(aCross, 5U)) + 3240054112993517371U) + aNonceWordI;
            aOrbiterF = (aWandererF + RotL64(aScatter, 51U)) + 16897532076915366859U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 18167359289798364307U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 8870819278575769863U;
            aOrbiterB = RotL64((aOrbiterB * 9334066154398059075U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 15363069206212330251U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 14858164441499725158U;
            aOrbiterC = RotL64((aOrbiterC * 14931933411393847915U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 5357144808788707522U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 2910681277417754860U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13170868582159347059U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 9824408699018165151U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 368370224788793300U;
            aOrbiterG = RotL64((aOrbiterG * 14358982366258729959U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 7095398304588825115U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 11418879758164313554U;
            aOrbiterD = RotL64((aOrbiterD * 5983520332639771791U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 2171599720681913272U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 17593730219647495033U;
            aOrbiterE = RotL64((aOrbiterE * 12926053208918563087U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 17755947635188715523U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 14565740605227022106U;
            aOrbiterF = RotL64((aOrbiterF * 15866418354612945335U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 14538017880915584414U) + aNonceWordL;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 6174566474851449123U;
            aOrbiterA = RotL64((aOrbiterA * 179569008593475683U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 3806438394748643441U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 13737114463856719285U;
            aOrbiterK = RotL64((aOrbiterK * 13439346068497710151U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 3698379331577470045U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 1097081284062708554U;
            aOrbiterH = RotL64((aOrbiterH * 3498627643013255777U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 215117138867597766U) + aNonceWordH;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 14823268998003220191U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12131828437975771377U), 5U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterG, 46U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 51U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + RotL64(aOrbiterC, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterK, 21U)) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 19U) + aOrbiterC) + RotL64(aOrbiterF, 27U));
            aWandererK = aWandererK + ((RotL64(aIngress, 23U) + RotL64(aOrbiterF, 13U)) + aOrbiterI);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 50U)) + aOrbiterB);
            aWandererA = aWandererA + ((((RotL64(aCross, 21U) + RotL64(aOrbiterE, 39U)) + aOrbiterD) + aNonceWordN) + aPhaseFWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterB, 43U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 40U) + aOrbiterK) + RotL64(aOrbiterJ, 37U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 27U) + aOrbiterF) + RotL64(aOrbiterE, 5U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 23U)) + aOrbiterI) + RotL64(aCarry, 51U)) + aPhaseFWandererUpdateSaltF[((aIndex + 26U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterC, 19U)) + aOrbiterK);
            aWandererH = aWandererH + ((RotL64(aScatter, 44U) + aOrbiterF) + RotL64(aOrbiterG, 58U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 18U));
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + RotL64(aWandererH, 60U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 9268U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8003U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 10367U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneB[((aIndex + 6327U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 42U) + RotL64(aCarry, 57U)) ^ (RotL64(aPrevious, 29U) + RotL64(aCross, 13U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterJ = (aWandererA + RotL64(aScatter, 3U)) + 16124889768301047791U;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 5U)) + RotL64(aCarry, 23U)) + 11912338587186717280U;
            aOrbiterI = ((aWandererB + RotL64(aCross, 22U)) + 8594012868813114354U) + aNonceWordO;
            aOrbiterA = (aWandererE + RotL64(aPrevious, 11U)) + 18281043566156682815U;
            aOrbiterD = ((aWandererD + RotL64(aCross, 51U)) + 16853106130200942302U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aIngress, 29U)) + 2611212958619673086U;
            aOrbiterC = (aWandererC + RotL64(aPrevious, 27U)) + 18039472325066855180U;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 43U)) + 14495785571345122046U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = (aWandererG + RotL64(aIngress, 19U)) + 4556063793412832418U;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 39U)) + RotL64(aCarry, 43U)) + 14896419970271244358U;
            aOrbiterH = ((aWandererI + RotL64(aCross, 54U)) + RotL64(aCarry, 53U)) + 880028529183500036U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 2379557167489415783U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 11854373946064529806U) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 150755294320438887U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 1487252775956449964U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 12777924204511625545U;
            aOrbiterB = RotL64((aOrbiterB * 1366019527386994789U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 15998631485222477969U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 8864212892296191613U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 579242788050369815U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 17069347835763226743U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 7443008171694679791U;
            aOrbiterC = RotL64((aOrbiterC * 748894368884566607U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 17334256152350782002U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 8986626119086556393U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2258172145924120235U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 8528180968228358674U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 12702290928064582589U) ^ aNonceWordF;
            aOrbiterJ = RotL64((aOrbiterJ * 15673603224146737631U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 7742438100860023610U) + aNonceWordB;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 3729687240959702198U;
            aOrbiterA = RotL64((aOrbiterA * 3756794766163746783U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 426129097367382096U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 16782175452274911213U;
            aOrbiterF = RotL64((aOrbiterF * 1041477289638333659U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 5942016166948841079U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 5260815086125551703U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1603799103692438147U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 11732742583346900772U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 17182924380693084401U;
            aOrbiterG = RotL64((aOrbiterG * 14858685629471497071U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 8539335803784852017U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 16124889768301047791U;
            aOrbiterH = RotL64((aOrbiterH * 6607245691919237755U), 23U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 27U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 22U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + (RotL64(aOrbiterA, 29U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 10U) + RotL64(aOrbiterA, 43U)) + aOrbiterB) + aNonceWordG) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 29U) + RotL64(aOrbiterA, 37U)) + aOrbiterK);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterG, 13U)) + aOrbiterH);
            aWandererG = aWandererG + (((RotL64(aCross, 13U) + aOrbiterC) + RotL64(aOrbiterI, 21U)) + aPhaseFWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 34U) + RotL64(aOrbiterF, 53U)) + aOrbiterH);
            aWandererH = aWandererH + ((RotL64(aPrevious, 21U) + aOrbiterF) + RotL64(aOrbiterK, 23U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 51U) + aOrbiterC) + RotL64(aOrbiterD, 60U));
            aWandererI = aWandererI + (((RotL64(aCross, 39U) + aOrbiterI) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterE, 5U)) + aOrbiterI);
            aWandererA = aWandererA + (((RotL64(aIngress, 27U) + aOrbiterJ) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterK, 18U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 44U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererJ, 14U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 11065U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 15666U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 12004U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneC[((aIndex + 11499U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aIngress, 11U)) ^ (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 24U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = (((aWandererK + RotL64(aScatter, 27U)) + RotL64(aCarry, 29U)) + 4848316479321533394U) + aNonceWordM;
            aOrbiterA = (aWandererE + RotL64(aIngress, 39U)) + 6919360256662636195U;
            aOrbiterK = (aWandererD + RotL64(aCross, 23U)) + 9897013582181108544U;
            aOrbiterG = (aWandererB + RotL64(aPrevious, 12U)) + 7319353809896158678U;
            aOrbiterF = ((aWandererH + RotL64(aIngress, 57U)) + RotL64(aCarry, 23U)) + 2848175435514849859U;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 53U)) + 6967780718720437934U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = (aWandererA + RotL64(aPrevious, 41U)) + 10143884766603388136U;
            aOrbiterI = ((aWandererF + RotL64(aCross, 19U)) + 8675965006150972051U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 4U)) + RotL64(aCarry, 41U)) + 16350117755560994281U;
            aOrbiterC = (aWandererJ + RotL64(aScatter, 51U)) + 17976597517118423760U;
            aOrbiterH = (aWandererC + RotL64(aCross, 29U)) + 1399631141355370237U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 3590613762034716792U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 5134624314245932157U;
            aOrbiterK = RotL64((aOrbiterK * 13077589037975283371U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 10082236952942943654U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 4015535035905433450U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4961808568701908559U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 611474103801573800U) + aNonceWordE;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 5786708483794098001U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7694007039340089267U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 5201943497363274455U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 9282160506938328489U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5368182164239021367U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 4932320527498940158U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 11576526341731392916U;
            aOrbiterI = RotL64((aOrbiterI * 1712051774729439363U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 10790691517638887125U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterK) ^ 16280649213607464422U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterC = RotL64((aOrbiterC * 10756733801499471873U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 9553716940667712810U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 11827518270964003341U;
            aOrbiterD = RotL64((aOrbiterD * 1322489827908132831U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 16777463701235809321U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 3375489084588454149U) ^ aNonceWordA;
            aOrbiterG = RotL64((aOrbiterG * 3335010977457647307U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 8129898095524287632U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 14496406641486541929U;
            aOrbiterB = RotL64((aOrbiterB * 10077246205532940301U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 17968163292907132345U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 2431407778543471402U;
            aOrbiterE = RotL64((aOrbiterE * 407105842057624537U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 18330313613898211889U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 4848316479321533394U;
            aOrbiterH = RotL64((aOrbiterH * 3462735144109152811U), 19U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 39U);
            aIngress = aIngress + (RotL64(aOrbiterD, 10U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aPrevious, 39U) + aOrbiterA) + RotL64(aOrbiterD, 23U));
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 42U) + aOrbiterE) + RotL64(aOrbiterC, 13U)) + aNonceWordF) + aPhaseFWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterJ, 48U)) + aNonceWordB);
            aWandererA = aWandererA ^ ((RotL64(aCross, 11U) + aOrbiterG) + RotL64(aOrbiterA, 43U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 53U) + aOrbiterH) + RotL64(aOrbiterF, 29U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 27U) + aOrbiterK) + RotL64(aOrbiterG, 35U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 57U)) + aOrbiterI) + RotL64(aCarry, 27U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterH, 21U)) + aOrbiterK);
            aWandererD = aWandererD + ((((RotL64(aScatter, 6U) + RotL64(aOrbiterJ, 50U)) + aOrbiterE) + RotL64(aCarry, 23U)) + aNonceWordD);
            aWandererI = aWandererI ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterF, 41U)) + aOrbiterG);
            aWandererF = aWandererF + (((RotL64(aIngress, 19U) + aOrbiterB) + RotL64(aOrbiterH, 37U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (RotL64(aWandererJ, 24U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + RotL64(aWandererE, 38U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordK);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 17503U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneB[((aIndex + 18430U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 17528U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneD[((aIndex + 21179U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aPrevious, 14U)) + (RotL64(aCarry, 27U) + RotL64(aIngress, 57U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 47U)) + 2617613537256538553U) + aPhaseFOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = (aWandererI + RotL64(aCross, 3U)) + 16642868916835132715U;
            aOrbiterJ = (aWandererH + RotL64(aIngress, 5U)) + 10860291124337073254U;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 11U)) + 6432511273906902472U) + aNonceWordM;
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 30U)) + RotL64(aCarry, 11U)) + 7505375005848241910U;
            aOrbiterG = (aWandererC + RotL64(aPrevious, 41U)) + 11086616004678821329U;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 37U)) + RotL64(aCarry, 27U)) + 3298830587569881951U;
            aOrbiterK = ((aWandererD + RotL64(aCross, 39U)) + RotL64(aCarry, 23U)) + 9775143140064220979U;
            aOrbiterB = (aWandererA + RotL64(aScatter, 53U)) + 4147601326580823120U;
            aOrbiterF = (aWandererF + RotL64(aPrevious, 20U)) + 12245920269898100415U;
            aOrbiterI = (((aWandererB + RotL64(aCross, 13U)) + 8391940489176734499U) + aPhaseFOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1]) + aNonceWordG;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 17876893379544668477U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 18301882058180370541U;
            aOrbiterJ = RotL64((aOrbiterJ * 16680384667098921309U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 6869225862715140102U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 15404118372589259800U;
            aOrbiterE = RotL64((aOrbiterE * 5766851935950389915U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 17757381020518233814U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 17677969146092374455U;
            aOrbiterG = RotL64((aOrbiterG * 3469432916562405063U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 15783378556632870114U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 5792858258663697864U;
            aOrbiterD = RotL64((aOrbiterD * 12008981883482080427U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 11737803388202260296U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 16001927091970715330U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3062030309852922061U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 1749586939123286632U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 6169421068855905938U;
            aOrbiterB = RotL64((aOrbiterB * 12374789910763348695U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 10073586820719728062U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 17744171227198661555U;
            aOrbiterF = RotL64((aOrbiterF * 10658375268803957647U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 1149819647337612792U) + aNonceWordI;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 7725598665625892006U;
            aOrbiterI = RotL64((aOrbiterI * 15097586655234391559U), 3U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterF) + 13930096050550704122U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1]) + aNonceWordE;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 3632241034947389647U;
            aOrbiterA = RotL64((aOrbiterA * 8442222389196610427U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 17933893495867517142U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 7888594392078082482U;
            aOrbiterH = RotL64((aOrbiterH * 9809847720610861237U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 10805303827043372168U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 2617613537256538553U) ^ aNonceWordJ;
            aOrbiterC = RotL64((aOrbiterC * 3940471942234248791U), 51U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 21U);
            aIngress = aIngress + (RotL64(aOrbiterG, 42U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + (RotL64(aOrbiterA, 53U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 46U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 60U) + aOrbiterK) + RotL64(aOrbiterA, 53U)) + aNonceWordA) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterC, 11U)) + aOrbiterJ) + aNonceWordB);
            aWandererE = aWandererE + (((RotL64(aCross, 3U) + RotL64(aOrbiterG, 43U)) + aOrbiterD) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 11U) + aOrbiterB) + RotL64(aOrbiterJ, 35U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 42U) + RotL64(aOrbiterI, 51U)) + aOrbiterG) + RotL64(aCarry, 5U)) + aPhaseFWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 51U) + aOrbiterB) + RotL64(aOrbiterF, 57U)) + aNonceWordN);
            aWandererC = aWandererC + ((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 29U)) + aOrbiterI);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 27U) + aOrbiterE) + RotL64(aOrbiterB, 60U));
            aWandererD = aWandererD + ((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterE, 5U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterC, 23U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (RotL64(aWandererD, 52U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + RotL64(aWandererH, 50U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ aNonceWordA;
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 26596U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23621U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 24831U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23592U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 35U)) ^ (RotL64(aCross, 51U) ^ RotL64(aIngress, 22U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterB = (((aWandererI + RotL64(aScatter, 5U)) + RotL64(aCarry, 5U)) + 14179205183062705133U) + aNonceWordE;
            aOrbiterC = (aWandererB + RotL64(aPrevious, 21U)) + 210032324058740920U;
            aOrbiterE = (aWandererD + RotL64(aCross, 29U)) + 7387115089142500152U;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 53U)) + 17583362781238061430U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = ((aWandererE + RotL64(aCross, 47U)) + RotL64(aCarry, 27U)) + 4991442849150005943U;
            aOrbiterF = (aWandererF + RotL64(aIngress, 34U)) + 2891376254689854555U;
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 41U)) + RotL64(aCarry, 21U)) + 10523274382407446239U;
            aOrbiterK = ((aWandererG + RotL64(aScatter, 39U)) + 3861893764676218667U) + aPhaseFOrbiterAssignSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aPrevious, 13U)) + 3366674459852093746U;
            aOrbiterG = (aWandererA + RotL64(aIngress, 10U)) + 5898492634386601145U;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 37U)) + 7047353571244768721U) + aNonceWordI;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 14374108805453186316U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 8763667021501226510U) ^ aNonceWordD;
            aOrbiterE = RotL64((aOrbiterE * 7694695426430267863U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 18261523829316379575U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 650477532238860965U;
            aOrbiterF = RotL64((aOrbiterF * 8291758490821819851U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 2162326554604894042U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 5776546692501825278U;
            aOrbiterK = RotL64((aOrbiterK * 14911545784585246537U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 3501863793638415049U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 14853789267425352958U;
            aOrbiterG = RotL64((aOrbiterG * 10590325397179928739U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 15399673014671329743U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 12253428583438990426U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12052855472196447849U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 13202953937621953839U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 7547616636832698398U;
            aOrbiterH = RotL64((aOrbiterH * 9533399972562428073U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 15709801946594868318U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 12458677982746610971U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6662570874316418993U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 6957370791367530127U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 10511379961344950861U;
            aOrbiterI = RotL64((aOrbiterI * 15551333099264031337U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 16489828646914719181U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 6827290294344770680U;
            aOrbiterA = RotL64((aOrbiterA * 6408864925398536651U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 3308531598034561099U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 10336568208337990458U;
            aOrbiterC = RotL64((aOrbiterC * 5606941634846696657U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 14116471880098183908U) + aNonceWordN;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 14179205183062705133U;
            aOrbiterD = RotL64((aOrbiterD * 8824119255416045191U), 41U);
            //
            aIngress = RotL64(aOrbiterF, 19U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 51U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 22U));
            aIngress = aIngress + RotL64(aOrbiterC, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 13U) + RotL64(aOrbiterG, 22U)) + aOrbiterI) + aNonceWordG);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 51U)) + aOrbiterJ);
            aWandererJ = aWandererJ + (((RotL64(aCross, 29U) + RotL64(aOrbiterD, 53U)) + aOrbiterB) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterG, 57U)) + aOrbiterA);
            aWandererG = aWandererG + ((RotL64(aPrevious, 39U) + aOrbiterF) + RotL64(aOrbiterE, 41U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 10U) + aOrbiterB) + RotL64(aOrbiterC, 37U)) + aNonceWordM);
            aWandererE = aWandererE + ((RotL64(aCross, 21U) + RotL64(aOrbiterE, 29U)) + aOrbiterD);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterC, 13U)) + aOrbiterJ);
            aWandererB = aWandererB + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterH, 43U)) + aOrbiterE) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterG, 46U)) + aOrbiterJ);
            aWandererH = aWandererH + ((((RotL64(aScatter, 58U) + RotL64(aOrbiterK, 27U)) + aOrbiterH) + RotL64(aCarry, 21U)) + aPhaseFWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 14U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 58U));
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31728U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29480U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32618U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneB[((aIndex + 27741U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 19U)) + (RotL64(aCarry, 34U) ^ RotL64(aPrevious, 47U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterJ = (aWandererF + RotL64(aCross, 37U)) + 12849591986267890852U;
            aOrbiterA = (aWandererK + RotL64(aScatter, 6U)) + 8232614804696815750U;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 29U)) + 12141567259210877281U;
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 3U)) + 2928641981037885644U) + aPhaseFOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aScatter, 43U)) + 980733350554783938U;
            aOrbiterF = (aWandererE + RotL64(aCross, 27U)) + 2683985177993350746U;
            aOrbiterH = (aWandererG + RotL64(aPrevious, 23U)) + 14532148403815527355U;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 47U)) + 7736296629433884203U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (((aWandererC + RotL64(aScatter, 41U)) + RotL64(aCarry, 51U)) + 10428437770166310549U) + aNonceWordD;
            aOrbiterI = ((aWandererI + RotL64(aCross, 35U)) + RotL64(aCarry, 47U)) + 18327174144859461029U;
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 12U)) + RotL64(aCarry, 57U)) + 6810436935194432002U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 12606153309690753435U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 17123256945895150555U;
            aOrbiterD = RotL64((aOrbiterD * 13469111258504672565U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 9057777759026189541U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 16478485918911194442U;
            aOrbiterK = RotL64((aOrbiterK * 11054247078884894131U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 18064460487552100483U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 11477276762421684083U;
            aOrbiterF = RotL64((aOrbiterF * 3886501230380184395U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 18318375441973295081U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 13849305985380030986U;
            aOrbiterH = RotL64((aOrbiterH * 12962140243967824959U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 10240409420338313641U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 18360586077779529086U;
            aOrbiterG = RotL64((aOrbiterG * 18196875422391501927U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 16801797158622424257U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 4950305991208513887U;
            aOrbiterC = RotL64((aOrbiterC * 4437082499761416951U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 15790878572843321918U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 9808781805065559728U;
            aOrbiterI = RotL64((aOrbiterI * 9394280083159162953U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 11974996650410830731U) + aNonceWordM;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 4955004489435232515U;
            aOrbiterB = RotL64((aOrbiterB * 13301966529515483085U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 1187569634223338864U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 5351017164244226367U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14735674576470803699U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 9587142385246940125U) + aNonceWordE;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 16253850371962732943U;
            aOrbiterA = RotL64((aOrbiterA * 3408021872390904463U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 14990060157351237661U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 12849591986267890852U;
            aOrbiterE = RotL64((aOrbiterE * 2158106726261981983U), 23U);
            //
            aIngress = RotL64(aOrbiterC, 46U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 27U));
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + RotL64(aOrbiterD, 22U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 37U) + aOrbiterC) + RotL64(aOrbiterF, 13U));
            aWandererA = aWandererA + (((((RotL64(aPrevious, 27U) + aOrbiterJ) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 23U)) + aNonceWordI) + aPhaseFWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterK, 11U)) + aNonceWordN);
            aWandererK = aWandererK + ((RotL64(aIngress, 5U) + aOrbiterD) + RotL64(aOrbiterI, 43U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterI, 27U)) + aOrbiterH);
            aWandererC = aWandererC + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 60U)) + aOrbiterG);
            aWandererE = aWandererE ^ ((RotL64(aCross, 24U) + aOrbiterG) + RotL64(aOrbiterA, 35U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterI, 37U)) + RotL64(aCarry, 37U)) + aNonceWordB);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterG, 23U)) + aOrbiterE);
            aWandererB = aWandererB + (((RotL64(aIngress, 39U) + RotL64(aOrbiterG, 18U)) + aOrbiterK) + aPhaseFWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 18U) + RotL64(aOrbiterB, 51U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 60U));
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererD, 54U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordE);
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 2082U)) & S_BLOCK1], 47U) ^ RotL64(aKeyRowReadA[((aIndex + 4631U)) & W_KEY1], 4U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 7272U)) & W_KEY1], 3U) ^ RotL64(mSource[((aIndex + 4240U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCross, 47U)) + (RotL64(aCarry, 6U) ^ RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = (aWandererD + RotL64(aCross, 5U)) + 3684295017013759987U;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 35U)) + 6740408842457292881U;
            aOrbiterG = (aWandererK + RotL64(aPrevious, 27U)) + 4563975890702399441U;
            aOrbiterE = (aWandererI + RotL64(aIngress, 18U)) + 797804144825287940U;
            aOrbiterD = ((aWandererB + RotL64(aCross, 53U)) + RotL64(aCarry, 13U)) + 2763779540450101303U;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 23U)) + 13211846164102089685U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = ((aWandererF + RotL64(aScatter, 57U)) + RotL64(aCarry, 57U)) + 15214578447281401982U;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 11U)) + RotL64(aCarry, 37U)) + 13745208628754232427U;
            aOrbiterB = ((aWandererE + RotL64(aScatter, 40U)) + 17358621225969190747U) + aPhaseCOrbiterAssignSaltD[((aIndex + 16U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 779739369960480023U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 4370963533701407813U;
            aOrbiterG = RotL64((aOrbiterG * 3123135216876641039U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 6061333005507739975U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 3589705340762734456U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16499293983611196967U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 10607697666369230567U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 9356757995305239271U;
            aOrbiterH = RotL64((aOrbiterH * 10945513661439954731U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 10093033335903048138U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 11037328061699834100U;
            aOrbiterB = RotL64((aOrbiterB * 11189760551792389605U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 558431161176115540U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 17795680919453449358U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3910117359996283803U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 6096779391116214109U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 17594243286880690775U;
            aOrbiterE = RotL64((aOrbiterE * 12655610181937429915U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 15414704802398002423U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 18040588240488602196U;
            aOrbiterI = RotL64((aOrbiterI * 16344249573086571225U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 14636298592697156931U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 9677305688594936561U;
            aOrbiterJ = RotL64((aOrbiterJ * 8354776999961642997U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 16408025751875050713U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 10018342878801454965U;
            aOrbiterD = RotL64((aOrbiterD * 10349132962708124117U), 53U);
            //
            aIngress = RotL64(aOrbiterG, 53U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 43U));
            aIngress = aIngress + RotL64(aOrbiterD, 24U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 41U) + aOrbiterJ) + RotL64(aOrbiterB, 21U)) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterG, 43U)) + aOrbiterD);
            aWandererD = aWandererD + (((RotL64(aCross, 18U) + RotL64(aOrbiterJ, 14U)) + aOrbiterC) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 51U) + aOrbiterE) + RotL64(aOrbiterF, 29U)) + aPhaseCWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 23U) + RotL64(aOrbiterJ, 51U)) + aOrbiterD) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 5U) + aOrbiterJ) + RotL64(aOrbiterI, 39U));
            aWandererK = aWandererK + ((RotL64(aIngress, 57U) + aOrbiterE) + RotL64(aOrbiterI, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterH, 58U));
            aWandererC = aWandererC + ((RotL64(aIngress, 46U) + aOrbiterI) + RotL64(aOrbiterB, 35U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 30U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + RotL64(aWandererB, 37U);
            aCarry = aCarry + RotL64(aIngress, 54U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 13862U)) & S_BLOCK1], 27U) ^ RotL64(mSource[((aIndex + 10489U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 14147U)) & W_KEY1], 6U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 12520U)) & W_KEY1], 57U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 23U)) + (RotL64(aIngress, 10U) + RotL64(aCross, 43U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = (aWandererI + RotL64(aCross, 26U)) + 7948891781097675369U;
            aOrbiterC = ((aWandererE + RotL64(aScatter, 3U)) + 13928362874228230226U) + aPhaseCOrbiterAssignSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 37U)) + RotL64(aCarry, 23U)) + 10776180542602258926U;
            aOrbiterG = (aWandererC + RotL64(aIngress, 43U)) + 5735115172149470447U;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 47U)) + RotL64(aCarry, 35U)) + 5353591822981766987U;
            aOrbiterK = ((aWandererA + RotL64(aIngress, 13U)) + 562301708107268570U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aCross, 58U)) + RotL64(aCarry, 11U)) + 10467810247578364868U;
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 51U)) + 14541630141152308564U;
            aOrbiterE = (aWandererJ + RotL64(aCross, 19U)) + 2350076897065139429U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 17519109078651162228U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 6061035173339902910U;
            aOrbiterB = RotL64((aOrbiterB * 10021905773432907835U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 15654836633731000065U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 13723521735153718904U;
            aOrbiterH = RotL64((aOrbiterH * 14459516479283070563U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 2849680038315532197U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 17336102435576647923U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10984689101753586739U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 7671010488872356142U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 11485114338165600777U;
            aOrbiterJ = RotL64((aOrbiterJ * 4162584865462407791U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 8759060657343458985U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 11009137869375286581U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8741417343929809115U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 15792999392743144135U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 6180808423175992479U;
            aOrbiterI = RotL64((aOrbiterI * 13681230339693676907U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 361487389591183005U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 15292753806514404853U;
            aOrbiterG = RotL64((aOrbiterG * 17478232597253311153U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 14929153438443362045U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 7904556383593914086U;
            aOrbiterK = RotL64((aOrbiterK * 2484130486635511403U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 3793180909904286848U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 10391957637467171320U;
            aOrbiterC = RotL64((aOrbiterC * 505484041943467117U), 27U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterH, 44U);
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 14U) + aOrbiterH) + RotL64(aOrbiterC, 14U));
            aWandererI = aWandererI + ((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterF, 29U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterC, 19U)) + aOrbiterE);
            aWandererB = aWandererB + (((RotL64(aIngress, 51U) + aOrbiterI) + RotL64(aOrbiterF, 23U)) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterG, 53U)) + aOrbiterH);
            aWandererE = aWandererE + ((((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 37U)) + aPhaseCWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 28U) + RotL64(aOrbiterK, 37U)) + aOrbiterJ);
            aWandererC = aWandererC + ((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 6U)) + aOrbiterJ);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterG, 41U)) + aOrbiterE) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 60U));
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 18073U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20703U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 20000U)) & W_KEY1], 46U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 19606U)) & W_KEY1], 19U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 29U)) ^ (RotL64(aIngress, 44U) + RotL64(aCross, 13U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = ((aWandererB + RotL64(aScatter, 57U)) + RotL64(aCarry, 53U)) + 4259993311776766595U;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 5U)) + 2857813330021126753U;
            aOrbiterC = (aWandererK + RotL64(aCross, 29U)) + 1345396841329442896U;
            aOrbiterD = (((aWandererF + RotL64(aIngress, 10U)) + RotL64(aCarry, 27U)) + 320992148982301024U) + aPhaseCOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = (aWandererC + RotL64(aScatter, 23U)) + 5619109532065293074U;
            aOrbiterA = (aWandererD + RotL64(aPrevious, 19U)) + 10380157329426706345U;
            aOrbiterE = (aWandererE + RotL64(aCross, 53U)) + 12449831150625409695U;
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 48U)) + 7847096607042268396U) + aPhaseCOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aCross, 35U)) + RotL64(aCarry, 39U)) + 11707184096803214678U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 9893643746186827088U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 333687403830908774U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17911256836121454271U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 13837360705077441580U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 4367119682175710689U;
            aOrbiterF = RotL64((aOrbiterF * 10295744669174603401U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 1193493435041306784U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 15062951612027370606U;
            aOrbiterD = RotL64((aOrbiterD * 2509383510565136549U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 16000173839235429105U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 15294482444605409961U;
            aOrbiterK = RotL64((aOrbiterK * 1031800997944302665U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 5720749055549773527U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 17248674962996093668U;
            aOrbiterG = RotL64((aOrbiterG * 15730637462755795591U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 16956840483882091059U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 9637715107943515594U;
            aOrbiterA = RotL64((aOrbiterA * 8878362378343603463U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 7147495779349862274U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 7508890985889484275U;
            aOrbiterE = RotL64((aOrbiterE * 17728368447504622035U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 4407738164617959366U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 17027017782352660454U;
            aOrbiterJ = RotL64((aOrbiterJ * 417183060881259295U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 3174658601748235285U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 9779053567370714831U;
            aOrbiterB = RotL64((aOrbiterB * 6383245776181968033U), 47U);
            //
            aIngress = RotL64(aOrbiterJ, 43U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterC, 38U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 35U));
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aPrevious, 34U) + aOrbiterC) + RotL64(aOrbiterK, 34U)) + RotL64(aCarry, 3U)) + aPhaseCWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterK, 27U));
            aWandererC = aWandererC + ((RotL64(aIngress, 13U) + aOrbiterJ) + RotL64(aOrbiterC, 39U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterF, 53U)) + aOrbiterD);
            aWandererA = aWandererA + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 13U)) + aOrbiterF) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterB, 43U)) + aOrbiterD);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 51U) + RotL64(aOrbiterG, 19U)) + aOrbiterJ) + RotL64(aCarry, 37U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 23U) + aOrbiterJ) + RotL64(aOrbiterE, 48U));
            aWandererG = aWandererG + ((RotL64(aIngress, 38U) + aOrbiterA) + RotL64(aOrbiterG, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 60U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 35U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 24956U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneB[((aIndex + 32358U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27941U)) & S_BLOCK1], 51U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 31060U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 6U) ^ RotL64(aCarry, 37U)) + (RotL64(aCross, 21U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = (aWandererI + RotL64(aPrevious, 3U)) + 16424657151168221875U;
            aOrbiterB = ((aWandererE + RotL64(aScatter, 13U)) + RotL64(aCarry, 35U)) + 17150123681886380361U;
            aOrbiterI = (aWandererB + RotL64(aCross, 60U)) + 16041993588694572757U;
            aOrbiterC = ((aWandererC + RotL64(aIngress, 19U)) + 9871185846434828537U) + aPhaseCOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aCross, 53U)) + RotL64(aCarry, 47U)) + 11227236398354430757U;
            aOrbiterG = (aWandererF + RotL64(aScatter, 41U)) + 5399325217402192631U;
            aOrbiterF = (aWandererK + RotL64(aPrevious, 46U)) + 9248828789282890454U;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 23U)) + RotL64(aCarry, 19U)) + 9041370494203701062U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 27U)) + 14944424084524970764U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 5481938174456671041U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 14783648629543752715U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7260164783191886395U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 12355573914530445723U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 9863991559011968318U;
            aOrbiterK = RotL64((aOrbiterK * 8495251211794343179U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 16149688605937250965U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 106041828692026825U;
            aOrbiterF = RotL64((aOrbiterF * 12199934305374582599U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 8076098639554567792U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 11155119311895580013U;
            aOrbiterA = RotL64((aOrbiterA * 1495180896564818647U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 6847612160595917702U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 16094377920388017367U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4875801863643206333U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 13584719866672696684U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 13446209321646234607U;
            aOrbiterG = RotL64((aOrbiterG * 9945349065094781529U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 15829806645369560988U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 12573767256739062550U;
            aOrbiterD = RotL64((aOrbiterD * 5649504278826069077U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 3850030870300393809U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 11857593987748189858U;
            aOrbiterH = RotL64((aOrbiterH * 15942863910931814193U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 5505918410521728373U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 12949653497121247860U;
            aOrbiterB = RotL64((aOrbiterB * 90944913639560027U), 35U);
            //
            aIngress = RotL64(aOrbiterH, 40U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 14U) + RotL64(aOrbiterB, 18U)) + aOrbiterI) + aPhaseCWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterD, 23U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterK, 5U)) + aOrbiterC);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 27U) + aOrbiterC) + RotL64(aOrbiterA, 37U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterK, 41U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 6U) + RotL64(aOrbiterI, 29U)) + aOrbiterC);
            aWandererI = aWandererI + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 13U)) + aOrbiterF) + RotL64(aCarry, 51U)) + aPhaseCWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterH, 57U)) + aOrbiterC);
            aWandererA = aWandererA + (((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterB, 48U)) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 42U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + RotL64(aWandererF, 5U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 4293U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((aIndex + 4705U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3019U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 4242U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 43U) + RotL64(aPrevious, 27U)) + (RotL64(aIngress, 11U) ^ RotL64(aCross, 60U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = ((aWandererH + RotL64(aIngress, 13U)) + RotL64(aCarry, 3U)) + 1708250618750199233U;
            aOrbiterD = ((aWandererC + RotL64(aCross, 27U)) + RotL64(aCarry, 43U)) + 12009147777553691142U;
            aOrbiterB = (aWandererF + RotL64(aPrevious, 38U)) + 8393982703399156592U;
            aOrbiterC = (((aWandererE + RotL64(aScatter, 5U)) + RotL64(aCarry, 19U)) + 3247327098356831221U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 47U)) + 3403590155376353737U) + aPhaseDOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 18197244558104735044U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 3096253642040701606U;
            aOrbiterB = RotL64((aOrbiterB * 6656168712438620783U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 8012692688785412179U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 17531946907545680745U;
            aOrbiterK = RotL64((aOrbiterK * 16510602981731506381U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 17687695944270225817U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 16147773866007628769U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16926442582711557877U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 18244641303026196497U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 8839160526348897457U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14268021129087663397U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 10599266240854068246U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 2056723540756216155U;
            aOrbiterG = RotL64((aOrbiterG * 13311591601230386375U), 3U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 57U);
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 54U) + RotL64(aOrbiterB, 5U)) + aOrbiterG) + aPhaseDWandererUpdateSaltF[((aIndex + 16U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 21U) + aOrbiterK) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterD, 27U)) + aOrbiterC) + aPhaseDWandererUpdateSaltA[((aIndex + 14U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 13U) + aOrbiterK) + RotL64(aOrbiterC, 37U)) + RotL64(aCarry, 41U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 39U) + aOrbiterG) + RotL64(aOrbiterK, 60U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (RotL64(aWandererF, 20U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererB, 3U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 9634U)) & S_BLOCK1], 42U) ^ RotL64(aExpandLaneD[((aIndex + 13620U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11040U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 11388U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 13U) ^ RotL64(aIngress, 26U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = ((aWandererC + RotL64(aCross, 35U)) + RotL64(aCarry, 29U)) + 9041099828460168106U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 57U)) + 12883711604096848454U;
            aOrbiterK = ((aWandererA + RotL64(aIngress, 21U)) + RotL64(aCarry, 5U)) + 17420968786226443079U;
            aOrbiterG = (((aWandererF + RotL64(aPrevious, 43U)) + RotL64(aCarry, 51U)) + 3448213891716125104U) + aPhaseDOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = ((aWandererI + RotL64(aScatter, 10U)) + 11866455977445336560U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 4119356835384495905U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 2186212599698637068U;
            aOrbiterK = RotL64((aOrbiterK * 6756888950976735707U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 6506144898969301620U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 12556800923644051626U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15961043406612913121U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 4075551535185182945U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 17877694808492008749U;
            aOrbiterE = RotL64((aOrbiterE * 901315308379887473U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 5553428900598223316U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 14362304852277160675U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11415103199856419303U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 9174200302876075831U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 16110739511917638547U;
            aOrbiterG = RotL64((aOrbiterG * 7004356839428657949U), 29U);
            //
            aIngress = RotL64(aOrbiterH, 47U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + RotL64(aOrbiterG, 20U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 19U) + aOrbiterK) + RotL64(aOrbiterG, 29U));
            aWandererC = aWandererC + (((RotL64(aIngress, 27U) + aOrbiterH) + RotL64(aOrbiterE, 60U)) + RotL64(aCarry, 21U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 53U) + aOrbiterE) + RotL64(aOrbiterG, 5U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 21U)) + aOrbiterI) + RotL64(aCarry, 35U)) + aPhaseDWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 42U) + RotL64(aOrbiterI, 13U)) + aOrbiterG) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (RotL64(aWandererF, 52U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererD, 27U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 24510U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneA[((aIndex + 17718U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 23077U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 22499U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 6U) + RotL64(aIngress, 53U)) + (RotL64(aPrevious, 37U) ^ RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = (((aWandererD + RotL64(aCross, 11U)) + RotL64(aCarry, 51U)) + 6469584119078165548U) + aPhaseDOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = (aWandererE + RotL64(aIngress, 51U)) + 14329756366517987910U;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 27U)) + RotL64(aCarry, 5U)) + 12890831797059772123U;
            aOrbiterF = (((aWandererJ + RotL64(aPrevious, 60U)) + RotL64(aCarry, 19U)) + 3164503807500018990U) + aPhaseDOrbiterAssignSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = (aWandererF + RotL64(aScatter, 41U)) + 177531431387646836U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 3167421392893561015U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 2813174781844753460U;
            aOrbiterE = RotL64((aOrbiterE * 9760688894575305115U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 10953270419153249857U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 16911518309710356951U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13162785997686570445U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 6616750447844893150U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 10276741398025985982U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6824712685896987133U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 6206043608461213208U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 12021552904553405793U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10023362889960174909U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 15283586234744144846U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 5923238786775948571U;
            aOrbiterK = RotL64((aOrbiterK * 8200882393521882651U), 21U);
            //
            aIngress = RotL64(aOrbiterC, 47U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 29U) + RotL64(aOrbiterJ, 21U)) + aOrbiterC) + RotL64(aCarry, 27U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterC, 11U)) + aOrbiterE) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 6U) + aOrbiterF) + RotL64(aOrbiterC, 51U)) + RotL64(aCarry, 3U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterK, 41U));
            aWandererE = aWandererE + ((RotL64(aScatter, 21U) + RotL64(aOrbiterE, 30U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 12U));
            aCarry = aCarry + RotL64(aWandererD, 21U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 25383U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((aIndex + 24976U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 27600U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 25081U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCross, 24U)) ^ (RotL64(aIngress, 37U) ^ RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererG + RotL64(aScatter, 13U)) + RotL64(aCarry, 39U)) + 7651355040951791298U;
            aOrbiterK = (aWandererE + RotL64(aCross, 54U)) + 13988210277931659312U;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 5U)) + RotL64(aCarry, 27U)) + 9846849412579537783U;
            aOrbiterC = (((aWandererK + RotL64(aIngress, 21U)) + RotL64(aCarry, 13U)) + 12746719939495876158U) + aPhaseDOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 39U)) + 11498066185182895284U) + aPhaseDOrbiterAssignSaltD[((aIndex + 24U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 11101058955193080232U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 15513734459555672046U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6974281215677538561U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 15711108675349394643U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 4771231759949468556U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9806191054594333615U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 11449258010811305256U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 17036938391509986723U;
            aOrbiterC = RotL64((aOrbiterC * 7411466953205347639U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 6999245666776654250U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 2106819066263369528U;
            aOrbiterK = RotL64((aOrbiterK * 13005885810757743129U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 12716183358903477216U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 16752724547046059889U;
            aOrbiterF = RotL64((aOrbiterF * 11475905692393034141U), 57U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterC, 23U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 54U));
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 19U) + aOrbiterH) + RotL64(aOrbiterF, 46U));
            aWandererF = aWandererF + (((RotL64(aScatter, 43U) + RotL64(aOrbiterB, 3U)) + aOrbiterC) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 51U) + aOrbiterF) + RotL64(aOrbiterC, 57U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 10U) + aOrbiterH) + RotL64(aOrbiterK, 27U)) + RotL64(aCarry, 57U)) + aPhaseDWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterH, 37U)) + aOrbiterC) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 48U));
            aCarry = aCarry + RotL64(aWandererE, 19U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 8087U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 8098U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 1897U)) & S_BLOCK1], 20U) ^ RotL64(aOperationLaneA[((aIndex + 4589U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 22U)) ^ (RotL64(aIngress, 43U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = (aWandererC + RotL64(aIngress, 20U)) + 6381335981879993247U;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 43U)) + RotL64(aCarry, 3U)) + 15595429101600023172U;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 37U)) + 5449234297249826461U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = (((aWandererF + RotL64(aCross, 51U)) + RotL64(aCarry, 19U)) + 11213734849329731168U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aScatter, 27U)) + 16438473952464514248U;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 13U)) + RotL64(aCarry, 43U)) + 7357872882115186976U;
            aOrbiterB = (aWandererG + RotL64(aIngress, 3U)) + 394402075160738643U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 11112941985410283532U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 14955125011182736212U;
            aOrbiterD = RotL64((aOrbiterD * 10711684773326395603U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 14770727009821304070U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 11286366598129204910U;
            aOrbiterH = RotL64((aOrbiterH * 15884310771003021989U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 7358400908565425780U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 15635109923749114761U;
            aOrbiterJ = RotL64((aOrbiterJ * 12415152149408700329U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 13826842523738623579U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 1072811298828325231U;
            aOrbiterB = RotL64((aOrbiterB * 9662800288646215083U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 4017334196009350776U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 8812213572751410831U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12744171921566782795U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 6723457786170634403U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 9785583533999417673U;
            aOrbiterI = RotL64((aOrbiterI * 7776915427605471097U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 10265132640322153964U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 8435670887514808087U;
            aOrbiterF = RotL64((aOrbiterF * 2706263045620662131U), 5U);
            //
            aIngress = RotL64(aOrbiterJ, 60U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 3U) + aOrbiterF) + RotL64(aOrbiterH, 27U));
            aWandererD = aWandererD + (((RotL64(aCross, 53U) + aOrbiterI) + RotL64(aOrbiterH, 5U)) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 19U)) + aOrbiterJ);
            aWandererK = aWandererK + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterJ, 12U)) + aOrbiterI) + RotL64(aCarry, 27U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterJ, 35U)) + aOrbiterE) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 60U) + aOrbiterE) + RotL64(aOrbiterH, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterI, 43U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 40U));
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 53U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10465U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 9933U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 15041U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 11394U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aIngress, 35U)) + (RotL64(aCarry, 5U) + RotL64(aPrevious, 22U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = (aWandererG + RotL64(aScatter, 10U)) + 13687218104610230596U;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 29U)) + RotL64(aCarry, 11U)) + 6841550124960692709U;
            aOrbiterH = (((aWandererK + RotL64(aCross, 51U)) + RotL64(aCarry, 27U)) + 17418968668458764131U) + aPhaseEOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aIngress, 3U)) + 8303537912696948204U;
            aOrbiterE = (aWandererF + RotL64(aPrevious, 23U)) + 12376614417285936537U;
            aOrbiterJ = (aWandererD + RotL64(aCross, 57U)) + 14215749063579232654U;
            aOrbiterA = (((aWandererI + RotL64(aIngress, 35U)) + RotL64(aCarry, 57U)) + 4111736931433665347U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 11250375934571631522U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 5367367837773331275U;
            aOrbiterH = RotL64((aOrbiterH * 7262723007545807179U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 15514089192382674434U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 1475991716685034960U;
            aOrbiterG = RotL64((aOrbiterG * 17720681295551650891U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 5531622777788629748U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 8363822215908303335U;
            aOrbiterD = RotL64((aOrbiterD * 17850203366840994883U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 3741256932685720414U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 11634667238062155772U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15925089729784547403U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 18180546911210417155U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 5123234656838556335U;
            aOrbiterE = RotL64((aOrbiterE * 15362857462853398025U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 11215734271189250284U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 16863747802158398092U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1828035970246160023U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 9859050606636646323U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 9331300036643654675U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2502263410556166281U), 51U);
            //
            aIngress = RotL64(aOrbiterJ, 18U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aIngress, 57U) + RotL64(aOrbiterG, 11U)) + aOrbiterD);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterJ, 19U)) + aOrbiterE) + aPhaseEWandererUpdateSaltD[((aIndex + 4U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aCross, 50U) + aOrbiterG) + RotL64(aOrbiterH, 58U)) + RotL64(aCarry, 13U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterJ, 39U)) + aOrbiterA);
            aWandererH = aWandererH + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterJ, 29U)) + aOrbiterI) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterA, 3U));
            aWandererK = aWandererK + ((RotL64(aIngress, 35U) + RotL64(aOrbiterJ, 51U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + RotL64(aWandererK, 10U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 23671U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneA[((aIndex + 18853U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 18881U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 18609U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 27U) ^ RotL64(aPrevious, 58U)) ^ (RotL64(aCarry, 11U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 19U)) + RotL64(aCarry, 5U)) + 4970414922752555648U;
            aOrbiterC = (aWandererB + RotL64(aIngress, 13U)) + 9462756592787669327U;
            aOrbiterI = ((aWandererD + RotL64(aScatter, 37U)) + RotL64(aCarry, 27U)) + 3948790686662213095U;
            aOrbiterG = (((aWandererG + RotL64(aPrevious, 5U)) + RotL64(aCarry, 47U)) + 14542857212241578311U) + aPhaseEOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aIngress, 53U)) + 3387479009827029547U;
            aOrbiterE = ((aWandererK + RotL64(aCross, 60U)) + 1411421370057797877U) + aPhaseEOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aPrevious, 27U)) + 16894451466895681236U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 12727136462290223542U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 4625389198191960525U;
            aOrbiterI = RotL64((aOrbiterI * 5726474430977810191U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 3471881403786164913U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 6433115856048534831U;
            aOrbiterC = RotL64((aOrbiterC * 9363233870194144053U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 9825592965466157982U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 1553125767261293088U;
            aOrbiterJ = RotL64((aOrbiterJ * 411535191177308781U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 9951616357109647617U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 11231080382787286889U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14024961994986659187U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 13419663264017317947U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 4835055642466215566U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17898065852351759171U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 14558747666410946768U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 13120938960926874504U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5681766019285559739U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 11910501376797343986U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 15074100100781785300U;
            aOrbiterF = RotL64((aOrbiterF * 228976960937473851U), 5U);
            //
            aIngress = RotL64(aOrbiterC, 29U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + (RotL64(aOrbiterE, 10U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 57U)) + aOrbiterI) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterB, 11U)) + RotL64(aCarry, 47U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 19U) + aOrbiterB) + RotL64(aOrbiterE, 41U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterI, 21U)) + RotL64(aCarry, 29U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 27U)) + aOrbiterG);
            aWandererC = aWandererC + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterC, 5U)) + aOrbiterG);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 6U) + aOrbiterF) + RotL64(aOrbiterI, 48U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 18U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + RotL64(aWandererK, 41U);
            aCarry = aCarry + RotL64(aIngress, 46U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 25447U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27105U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32429U)) & S_BLOCK1], 28U) ^ RotL64(aOperationLaneD[((aIndex + 25064U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 37U) + RotL64(aCross, 21U)) ^ (RotL64(aPrevious, 6U) + RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 21U)) + RotL64(aCarry, 41U)) + 12206125048349568300U;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 53U)) + RotL64(aCarry, 19U)) + 5843520589343188818U;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 3U)) + 12195046124287121687U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = (((aWandererB + RotL64(aIngress, 29U)) + RotL64(aCarry, 53U)) + 16769779119214020640U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = (aWandererK + RotL64(aScatter, 41U)) + 5257603646260695833U;
            aOrbiterG = (aWandererC + RotL64(aPrevious, 60U)) + 8523523946234886745U;
            aOrbiterK = (aWandererI + RotL64(aCross, 11U)) + 7316024684200084096U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 11996978575084115207U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 15491711479085513628U;
            aOrbiterJ = RotL64((aOrbiterJ * 15136690392026011819U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 6036648530996821484U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 926323222234121863U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6639661141258803779U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 2700323841295743492U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 5852273765810284935U;
            aOrbiterC = RotL64((aOrbiterC * 16665696735016345215U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 11697397483133538067U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 17777142964957007194U;
            aOrbiterA = RotL64((aOrbiterA * 6338967222543284999U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 10892176201151170298U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 11759700374509499684U;
            aOrbiterI = RotL64((aOrbiterI * 14247697264744736081U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 11343756773329590643U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 15785048929757652350U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17208103574389502597U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 7508839228498497238U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 13088508510402094665U;
            aOrbiterK = RotL64((aOrbiterK * 15730279447009669103U), 11U);
            //
            aIngress = RotL64(aOrbiterK, 3U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 41U)) + aOrbiterK);
            aWandererA = aWandererA + (((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 57U)) + aOrbiterC) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterI, 11U)) + aPhaseEWandererUpdateSaltB[((aIndex + 24U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 21U) + RotL64(aOrbiterG, 5U)) + aOrbiterD) + RotL64(aCarry, 35U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 34U) + RotL64(aOrbiterI, 19U)) + aOrbiterK);
            aWandererK = aWandererK + ((RotL64(aScatter, 41U) + RotL64(aOrbiterC, 26U)) + aOrbiterI);
            aWandererC = aWandererC ^ (((RotL64(aCross, 27U) + aOrbiterC) + RotL64(aOrbiterA, 51U)) + aPhaseEWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererA);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 7611U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneC[((aIndex + 3846U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5964U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 7450U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 13U) + RotL64(aPrevious, 43U)) ^ (RotL64(aIngress, 27U) ^ RotL64(aCross, 58U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = ((aWandererG + RotL64(aScatter, 47U)) + RotL64(aCarry, 19U)) + 16183871922837164759U;
            aOrbiterB = (aWandererF + RotL64(aPrevious, 39U)) + 7002058258090219055U;
            aOrbiterE = (((aWandererH + RotL64(aIngress, 11U)) + RotL64(aCarry, 3U)) + 5650868611888303705U) + aPhaseFOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = (((aWandererB + RotL64(aCross, 30U)) + RotL64(aCarry, 35U)) + 11899839660943876690U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 57U)) + 15349649504488111111U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 14060149569086744970U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 12920917574225030112U;
            aOrbiterE = RotL64((aOrbiterE * 6552626684290469367U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 2831994965175330135U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 18312543585028439192U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11618182708195744321U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 11657562205118394239U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 10850792819281246052U;
            aOrbiterC = RotL64((aOrbiterC * 10663100544207879337U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 17810371216216125323U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 7963413941144223128U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 534217972450595401U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 5498715358793875584U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 9256727548911651373U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10498848323914000989U), 29U);
            //
            aIngress = RotL64(aOrbiterE, 6U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterA, 23U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 46U) + aOrbiterB) + RotL64(aOrbiterC, 54U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterB, 29U)) + aOrbiterH);
            aWandererG = aWandererG + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterH, 5U)) + aOrbiterA) + RotL64(aCarry, 23U)) + aPhaseFWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterA, 13U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterE, 43U)) + aOrbiterH) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 48U));
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 3U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8441U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11394U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10864U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 8216U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aIngress, 34U)) + (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = ((aWandererI + RotL64(aCross, 47U)) + 6467297102954816305U) + aPhaseFOrbiterAssignSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 11U)) + RotL64(aCarry, 39U)) + 7921154109831114952U;
            aOrbiterB = (aWandererK + RotL64(aIngress, 34U)) + 5701131763215638919U;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 57U)) + RotL64(aCarry, 19U)) + 10022999076719002684U;
            aOrbiterC = (((aWandererJ + RotL64(aIngress, 3U)) + RotL64(aCarry, 3U)) + 4367135243038982316U) + aPhaseFOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 14445846824810383592U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 7683697954545773253U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4832124801510084629U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 17517006750428030899U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 2052484792684025476U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12463117571122469643U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 6279463052085808926U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 679280153651813684U;
            aOrbiterK = RotL64((aOrbiterK * 3047031560593583881U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 2939516520188460569U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 1960616434964712325U;
            aOrbiterI = RotL64((aOrbiterI * 15145998415466343039U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 12273819390719947361U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 5685033154709449397U;
            aOrbiterH = RotL64((aOrbiterH * 9845666295874714959U), 21U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 47U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 60U));
            aIngress = aIngress + RotL64(aOrbiterB, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterK, 13U));
            aWandererF = aWandererF + (((RotL64(aCross, 27U) + aOrbiterK) + RotL64(aOrbiterI, 21U)) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 58U) + aOrbiterK) + RotL64(aOrbiterH, 29U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 39U) + aOrbiterH) + RotL64(aOrbiterB, 40U)) + RotL64(aCarry, 29U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterH, 57U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 38U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 17623U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneA[((aIndex + 20956U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20372U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneC[((aIndex + 23084U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 39U)) ^ (RotL64(aCross, 51U) ^ RotL64(aIngress, 24U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = ((aWandererF + RotL64(aCross, 38U)) + RotL64(aCarry, 35U)) + 4476099022490972343U;
            aOrbiterD = (aWandererG + RotL64(aPrevious, 21U)) + 16836423700375760429U;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 11U)) + RotL64(aCarry, 57U)) + 8850577488928703557U;
            aOrbiterG = (((aWandererK + RotL64(aIngress, 53U)) + RotL64(aCarry, 19U)) + 7091631824560042743U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 3U)) + 12560498899956759494U) + aPhaseFOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 7797973377112012161U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 6173820673874805794U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15741300047917486527U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 10805025132310245348U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 7139216143268029968U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8349754682635765573U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 8241544862261635722U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 4735527016563596150U;
            aOrbiterE = RotL64((aOrbiterE * 6621354217673598381U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 5166171126690294033U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 11117641762075368393U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4980156869201219393U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 6312932356458415421U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 1304139291184508668U;
            aOrbiterB = RotL64((aOrbiterB * 90744653170922319U), 13U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 3U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 14U));
            aIngress = aIngress + RotL64(aOrbiterE, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterG, 47U)) + aOrbiterB) + RotL64(aCarry, 47U)) + aPhaseFWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 23U)) + aOrbiterF);
            aWandererH = aWandererH + ((RotL64(aCross, 21U) + RotL64(aOrbiterF, 14U)) + aOrbiterD);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterD, 3U)) + aOrbiterE);
            aWandererG = aWandererG + ((((RotL64(aCross, 60U) + RotL64(aOrbiterE, 35U)) + aOrbiterG) + RotL64(aCarry, 13U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererF, 41U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 26813U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30014U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28079U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 27586U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 54U) + RotL64(aCarry, 21U)) ^ (RotL64(aIngress, 3U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 5U)) + RotL64(aCarry, 43U)) + 3970829908171131502U;
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 23U)) + 7040283759419531991U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = (((aWandererG + RotL64(aCross, 51U)) + RotL64(aCarry, 23U)) + 11856292169397052901U) + aPhaseFOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aPrevious, 34U)) + 819598588791819022U;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 13U)) + RotL64(aCarry, 3U)) + 2176451710970866848U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 6454704928613390494U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 11792122387218053841U;
            aOrbiterB = RotL64((aOrbiterB * 17994898985794518565U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 9254780213489752211U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 16591812589999846482U;
            aOrbiterH = RotL64((aOrbiterH * 5425771603523423167U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 1471246223935074832U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 1424843083106386453U;
            aOrbiterD = RotL64((aOrbiterD * 15020536982657410783U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 1856469958050891629U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 6331743690452052712U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15327924647897459645U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 10351075711345476487U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 9518585245330480185U;
            aOrbiterG = RotL64((aOrbiterG * 3792179827396760391U), 11U);
            //
            aIngress = RotL64(aOrbiterB, 57U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterG, 37U)) + aOrbiterH);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterB, 5U)) + aOrbiterD) + RotL64(aCarry, 57U)) + aPhaseFWandererUpdateSaltE[((aIndex + 26U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 58U) + aOrbiterD) + RotL64(aOrbiterG, 13U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 13U) + aOrbiterH) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 29U) + aOrbiterJ) + RotL64(aOrbiterH, 54U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 58U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 1177U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 1801U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 5564U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneD[((aIndex + 4576U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 20U)) ^ (RotL64(aCross, 5U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = ((aWandererJ + RotL64(aCross, 22U)) + RotL64(aCarry, 5U)) + 1142447269198373880U;
            aOrbiterD = (((aWandererA + RotL64(aScatter, 47U)) + RotL64(aCarry, 47U)) + 10581460640040336191U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aIngress, 57U)) + 14703062773878202900U;
            aOrbiterJ = (((aWandererK + RotL64(aPrevious, 3U)) + RotL64(aCarry, 29U)) + 15737525756286914746U) + aPhaseGOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = (aWandererB + RotL64(aScatter, 39U)) + 16178774478273186999U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 2514897053906809160U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 13702496607592508464U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16540143680974064057U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 18030885275418337965U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 5241783876161655984U;
            aOrbiterK = RotL64((aOrbiterK * 10970981186787227937U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 2807052676283587925U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 8022804576763271327U;
            aOrbiterJ = RotL64((aOrbiterJ * 11727096043219370577U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 15597099852232205860U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 1538435607932096400U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7900752511710516981U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 11147868774413615365U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 9325213746830411568U;
            aOrbiterE = RotL64((aOrbiterE * 561819005818948769U), 13U);
            //
            aIngress = RotL64(aOrbiterJ, 35U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 46U));
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aScatter, 58U) + RotL64(aOrbiterK, 20U)) + aOrbiterJ) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 37U) + aOrbiterD) + RotL64(aOrbiterE, 37U)) + aPhaseGWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 11U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterB, 3U)) + aOrbiterE);
            aWandererA = aWandererA + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterK, 47U)) + aOrbiterE) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + RotL64(aWandererB, 27U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 9674U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneC[((aIndex + 14943U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 13371U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 14414U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 19U)) ^ (RotL64(aIngress, 57U) ^ RotL64(aCross, 44U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = ((aWandererD + RotL64(aIngress, 57U)) + RotL64(aCarry, 51U)) + 6916817163240024692U;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 19U)) + 14554930751292077817U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = ((aWandererH + RotL64(aCross, 34U)) + RotL64(aCarry, 37U)) + 1098305064484336101U;
            aOrbiterJ = (((aWandererJ + RotL64(aPrevious, 47U)) + RotL64(aCarry, 3U)) + 12192821172420471527U) + aPhaseGOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (aWandererF + RotL64(aScatter, 3U)) + 2435134991707318845U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 1896745368738512624U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 1114996424222923873U;
            aOrbiterC = RotL64((aOrbiterC * 6248754732325773087U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 9839135798371512656U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 8037967239603177043U;
            aOrbiterE = RotL64((aOrbiterE * 7848951103759663025U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 15185468738487237432U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 4912098316394854543U;
            aOrbiterG = RotL64((aOrbiterG * 3072785550384399929U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 13142688607850380888U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 4507379759608945839U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2989332387754215967U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 7299006009652289342U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 5390655277207053627U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10973744708856143715U), 37U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 13U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + RotL64(aOrbiterC, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aCross, 27U) + RotL64(aOrbiterJ, 43U)) + aOrbiterD) + RotL64(aCarry, 3U)) + aPhaseGWandererUpdateSaltF[((aIndex + 26U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 3U)) + aOrbiterC);
            aWandererK = aWandererK + (((RotL64(aScatter, 52U) + aOrbiterJ) + RotL64(aOrbiterG, 11U)) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterE, 22U)) + aOrbiterC);
            aWandererD = aWandererD + (((RotL64(aCross, 3U) + aOrbiterE) + RotL64(aOrbiterG, 35U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + RotL64(aWandererH, 56U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 17459U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneD[((aIndex + 17626U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18510U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((aIndex + 20408U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCross, 6U)) ^ (RotL64(aIngress, 47U) + RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = (aWandererE + RotL64(aScatter, 43U)) + 15920462086654025436U;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 4U)) + 487844076858004017U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = (((aWandererI + RotL64(aIngress, 51U)) + RotL64(aCarry, 57U)) + 14502883786442630566U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = ((aWandererH + RotL64(aCross, 13U)) + RotL64(aCarry, 13U)) + 3787107318658233674U;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 23U)) + RotL64(aCarry, 27U)) + 12548777544693755491U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 4907309444075181683U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 18342396700266492072U;
            aOrbiterG = RotL64((aOrbiterG * 14842961036061482089U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 13503051997624242670U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 17845742460521374571U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1366356786138085155U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 8640887211877858169U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 5273913123709097537U;
            aOrbiterA = RotL64((aOrbiterA * 1661149444148461791U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 17756844173695563883U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 6713055830729302951U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2832836748513174311U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 5106468334224035972U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 10228769728713526172U;
            aOrbiterF = RotL64((aOrbiterF * 9760310686414358435U), 47U);
            //
            aIngress = RotL64(aOrbiterA, 23U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + RotL64(aOrbiterF, 46U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterG, 39U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 41U) + aOrbiterA) + RotL64(aOrbiterC, 56U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 26U) + RotL64(aOrbiterA, 5U)) + aOrbiterD) + RotL64(aCarry, 53U)) + aPhaseGWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterG, 29U));
            aWandererK = aWandererK + (((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterC, 47U)) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 50U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 35U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 27507U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneA[((aIndex + 28903U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24635U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((aIndex + 26083U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aIngress, 6U)) ^ (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = (aWandererC + RotL64(aPrevious, 5U)) + 3650233661228036955U;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 13U)) + RotL64(aCarry, 11U)) + 11607036400067735729U;
            aOrbiterF = (((aWandererJ + RotL64(aScatter, 56U)) + RotL64(aCarry, 57U)) + 3899614406903883035U) + aPhaseGOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = (((aWandererE + RotL64(aCross, 23U)) + RotL64(aCarry, 29U)) + 8159156925629965143U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aPrevious, 37U)) + 7148903913967261270U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 9161665622287517848U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 2981535013474059469U;
            aOrbiterF = RotL64((aOrbiterF * 4434815231517266013U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 15812469008200319549U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 14687469489893270300U;
            aOrbiterH = RotL64((aOrbiterH * 14142363399696670451U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 6025209349511417063U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 12964750392311112676U;
            aOrbiterC = RotL64((aOrbiterC * 12955480283032701843U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 6572355895765394340U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 3542300121890027981U;
            aOrbiterB = RotL64((aOrbiterB * 11201491178181273935U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 6477175684045398359U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 1081388388827929314U;
            aOrbiterK = RotL64((aOrbiterK * 8752188637514143529U), 27U);
            //
            aIngress = RotL64(aOrbiterF, 51U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 39U));
            aIngress = aIngress + RotL64(aOrbiterK, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterC, 3U)) + aOrbiterF);
            aWandererG = aWandererG + (((RotL64(aPrevious, 58U) + RotL64(aOrbiterB, 11U)) + aOrbiterH) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 35U) + aOrbiterC) + RotL64(aOrbiterK, 43U));
            aWandererE = aWandererE + ((((RotL64(aCross, 23U) + aOrbiterH) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 39U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 43U) + aOrbiterC) + RotL64(aOrbiterB, 56U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererC, 4U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 4955U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((aIndex + 3996U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4832U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((aIndex + 195U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 40U) ^ RotL64(aPrevious, 11U)) + (RotL64(aIngress, 23U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 34U)) + RotL64(aCarry, 23U)) + 5088525177670191619U;
            aOrbiterK = ((aWandererI + RotL64(aIngress, 3U)) + 9966456257813932112U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (aWandererE + RotL64(aScatter, 21U)) + 7707646574027146307U;
            aOrbiterE = ((aWandererF + RotL64(aCross, 47U)) + RotL64(aCarry, 47U)) + 75480203757681173U;
            aOrbiterJ = (((aWandererJ + RotL64(aIngress, 13U)) + RotL64(aCarry, 35U)) + 384659134071835163U) + aPhaseHOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 3158769775373307778U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 17360830943513941272U;
            aOrbiterC = RotL64((aOrbiterC * 9986023786908098621U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 5317278822721604586U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 1371427105215954781U;
            aOrbiterD = RotL64((aOrbiterD * 10956603063464438611U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 3162710551223553423U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 5332921933853550756U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11709546145149357887U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 10572462410297815854U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 10234389605554817892U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2130374833440291193U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 13421365517991380605U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 10186643614984034083U;
            aOrbiterJ = RotL64((aOrbiterJ * 8554471709467808453U), 53U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 5U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 44U) + aOrbiterJ) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 21U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 11U) + aOrbiterK) + RotL64(aOrbiterE, 21U)) + aPhaseHWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 35U) + RotL64(aOrbiterK, 11U)) + aOrbiterJ) + RotL64(aCarry, 51U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterC, 56U)) + aPhaseHWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterK, 43U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 21U));
            aCarry = aCarry + RotL64(aWandererI, 43U);
            aCarry = aCarry + RotL64(aIngress, 58U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 11572U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((aIndex + 13749U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11668U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12682U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 43U) + RotL64(aCross, 27U)) + (RotL64(aIngress, 58U) ^ RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = (((aWandererK + RotL64(aIngress, 3U)) + RotL64(aCarry, 51U)) + 6163290588946759209U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 35U)) + RotL64(aCarry, 23U)) + 7342672468560105447U;
            aOrbiterK = (((aWandererD + RotL64(aCross, 21U)) + RotL64(aCarry, 37U)) + 11574563167017282321U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aPrevious, 43U)) + 2254820206194758964U;
            aOrbiterA = (aWandererJ + RotL64(aScatter, 12U)) + 1469783447473099498U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 14174828900676165088U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 16277954291890598132U;
            aOrbiterK = RotL64((aOrbiterK * 4608888834164373691U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 14845750668693136766U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 150099699692047766U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7644895634421086357U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 1200784917165131703U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 9469982764806754302U;
            aOrbiterB = RotL64((aOrbiterB * 17851969334511301943U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 10956702761701710182U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 7915506894975487807U;
            aOrbiterJ = RotL64((aOrbiterJ * 8874108311712727983U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 17335794183733623213U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 557028996286989506U;
            aOrbiterF = RotL64((aOrbiterF * 3993359298602424281U), 11U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterA, 37U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 52U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterB, 51U)) + aOrbiterA) + aPhaseHWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 54U) + RotL64(aOrbiterB, 29U)) + aOrbiterJ) + RotL64(aCarry, 35U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterK, 43U)) + aPhaseHWandererUpdateSaltC[((aIndex + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 39U) + RotL64(aOrbiterB, 20U)) + aOrbiterF) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 13U) + aOrbiterF) + RotL64(aOrbiterJ, 11U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 24541U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneD[((aIndex + 24141U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24555U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24430U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 29U) ^ RotL64(aPrevious, 41U)) ^ (RotL64(aIngress, 13U) + RotL64(aCross, 56U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = ((aWandererC + RotL64(aIngress, 5U)) + RotL64(aCarry, 51U)) + 3973833383430652211U;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 13U)) + RotL64(aCarry, 37U)) + 5760227042747169187U;
            aOrbiterI = ((aWandererB + RotL64(aScatter, 56U)) + RotL64(aCarry, 19U)) + 4923009065139227286U;
            aOrbiterD = ((aWandererI + RotL64(aCross, 37U)) + 1477807307009107590U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 21U)) + 5707194514329007301U) + aPhaseHOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 5340439728375269724U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 17080457898946572387U;
            aOrbiterI = RotL64((aOrbiterI * 17719588880215414933U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 281559150259472813U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 16160633048230910560U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16883442583309073785U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 9003989610509592121U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 10579322462808454333U;
            aOrbiterC = RotL64((aOrbiterC * 100832431598087235U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 15059383289528723069U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 10417647757852880956U;
            aOrbiterD = RotL64((aOrbiterD * 1457919230286043137U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 14484665027393813330U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 12344463053485837974U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5762654194001525041U), 47U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterD, 24U);
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aIngress, 5U) + RotL64(aOrbiterD, 3U)) + aOrbiterI) + RotL64(aCarry, 37U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterI, 52U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 14U) + aOrbiterC) + RotL64(aOrbiterD, 43U)) + RotL64(aCarry, 57U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterD, 35U)) + aOrbiterA);
            aWandererC = aWandererC + ((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterB, 13U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + RotL64(aWandererB, 21U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 28172U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27863U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27623U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 26139U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 26U) + RotL64(aCarry, 43U)) + (RotL64(aPrevious, 11U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = ((aWandererB + RotL64(aCross, 21U)) + RotL64(aCarry, 43U)) + 12669015908335980355U;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 57U)) + RotL64(aCarry, 21U)) + 5438715179868613192U;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 10U)) + 13172104448184536460U) + aPhaseHOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 47U)) + RotL64(aCarry, 5U)) + 13421421503244744803U;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 37U)) + 13327113302994856582U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 4671768205922454413U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 5355759962838579929U;
            aOrbiterI = RotL64((aOrbiterI * 15080379163499722187U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 6691720614265406851U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 7063906424700911378U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17091734375516280675U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 17328616394166672263U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 1542940602574207068U;
            aOrbiterK = RotL64((aOrbiterK * 8981679306319627975U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 7203866278803132454U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 993485696233139264U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11609009908810366447U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 15659679028507488331U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 18321361454094675842U;
            aOrbiterB = RotL64((aOrbiterB * 3966860765622641843U), 23U);
            //
            aIngress = RotL64(aOrbiterA, 5U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterK, 58U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterK, 23U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 13U)) + aOrbiterB) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 27U) + RotL64(aOrbiterK, 57U)) + aOrbiterI) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 56U) + aOrbiterF) + RotL64(aOrbiterI, 48U));
            aWandererG = aWandererG + ((((RotL64(aCross, 11U) + RotL64(aOrbiterA, 39U)) + aOrbiterB) + RotL64(aCarry, 47U)) + aPhaseHWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererH, 54U);
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
