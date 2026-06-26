#include "TwistExpander_Soccer_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Soccer_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x98D93D95D89AE4BDULL + 0xB703F4B3EA6BD2DFULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x937CB68F743830D9ULL + 0xFCFDCC14593175B1ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xD4B1DA4AE28DE2B7ULL + 0xDC46F0F062FE2F55ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xE7D622E0D3E23907ULL + 0xC767126960EEEFCEULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xF3421CDF98961EB3ULL + 0xD4A7961B3F130D9DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x8BFBD279AD5F09D1ULL + 0xD7BDCA908BA9F2A4ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xA5084841D1AE0C59ULL + 0xF0D9081ACB1E2960ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x8A8BBBC3B66509A5ULL + 0xC2513B458CEFD8E2ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xE1C9524D30EAF469ULL + 0xFC1307FBFA0043A7ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x8731D56705714C91ULL + 0xEE88DDB6F97F7844ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xC71AFD0E0C4F7795ULL + 0xDDF4B4344DBD1382ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x986E83BF1031B483ULL + 0xF6272A14269E25BAULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xD75C87A65E24D72BULL + 0xAD5B39D19461963BULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xF4B3C25D214192B3ULL + 0xE311237824359084ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x855C57366E3F43AFULL + 0xADC8E91A3BAB570DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xB91F5B311FFE99A9ULL + 0xAAAC72177AC5A051ULL);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 3535U)) & S_BLOCK1], 3U) ^ RotL64(pSnow[((aIndex + 2605U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 1760U)) & S_BLOCK1], 48U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 3774U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 18U) ^ RotL64(aIngress, 3U)) + (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 53U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 52U)) + RotL64(aCarry, 35U)) + 6069475454765660321U;
            aOrbiterH = (aWandererA + RotL64(aScatter, 39U)) + 11483704742497268068U;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 47U)) + RotL64(aCarry, 5U)) + 11055697447388986418U;
            aOrbiterK = (aWandererH + RotL64(aCross, 21U)) + 10897095046039997004U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 27U)) + 4731637118230457840U;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 57U)) + 13855839187084986751U) + aNonceWordB;
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 37U)) + 5328208115460188239U) + aNonceWordK;
            aOrbiterD = (((aWandererF + RotL64(aCross, 5U)) + RotL64(aCarry, 27U)) + 12479538544291412985U) + aOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aIngress, 50U)) + 10740165998792608231U;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 35U)) + 6492798157284955373U) + aOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aCross, 43U)) + 13056825957483891921U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 2068184064919194657U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 5656302738780746294U;
            aOrbiterE = RotL64((aOrbiterE * 16493021179127646345U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 11193756120230763294U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 17306750816837208999U;
            aOrbiterB = RotL64((aOrbiterB * 7949360041241439741U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 12952818800389361804U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 15380412293642628312U;
            aOrbiterC = RotL64((aOrbiterC * 2914662289178925547U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 7706090204767242996U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 14598802276412649570U;
            aOrbiterK = RotL64((aOrbiterK * 4821408736292041399U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 17819762117328075515U) + aOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 6481384240915075101U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4836701121865783029U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 754936290510338717U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 15510875946573720154U;
            aOrbiterF = RotL64((aOrbiterF * 2994718968852184303U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 9245381722813944586U) + aNonceWordA;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 2629847912019726214U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6718795794951106961U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 3909987749797113773U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 9277056074757335265U;
            aOrbiterH = RotL64((aOrbiterH * 11580847505996697115U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 12577180954515966707U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 9144513680789115458U;
            aOrbiterI = RotL64((aOrbiterI * 8880777678193004979U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 1544232962956974411U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 2658275904714859636U;
            aOrbiterD = RotL64((aOrbiterD * 1926083316365175327U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 5733515391293514025U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 6069475454765660321U;
            aOrbiterG = RotL64((aOrbiterG * 9627476106108146391U), 27U);
            //
            aIngress = RotL64(aOrbiterI, 41U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterK, 46U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterF, 23U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + RotL64(aOrbiterC, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aCross, 27U) + aOrbiterE) + RotL64(aOrbiterA, 60U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 39U) + aOrbiterB) + RotL64(aOrbiterK, 13U));
            aWandererG = aWandererG + (((RotL64(aIngress, 56U) + RotL64(aOrbiterA, 37U)) + aOrbiterD) + aWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 41U) + aOrbiterH) + RotL64(aOrbiterG, 11U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterG, 41U)) + aOrbiterC) + aNonceWordC);
            aWandererC = aWandererC ^ ((RotL64(aCross, 53U) + aOrbiterG) + RotL64(aOrbiterI, 3U));
            aWandererE = aWandererE + (((RotL64(aScatter, 51U) + RotL64(aOrbiterB, 46U)) + aOrbiterG) + aWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 44U) + aOrbiterF) + RotL64(aOrbiterC, 29U)) + aNonceWordE);
            aWandererI = aWandererI + (((RotL64(aCross, 13U) + aOrbiterD) + RotL64(aOrbiterC, 51U)) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterI, 35U)) + aOrbiterH) + aNonceWordG);
            aWandererF = aWandererF + (((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 60U));
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 26U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordC);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9404U)) & S_BLOCK1], 39U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 5514U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(pSnow[((S_BLOCK1 - aIndex + 5813U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 5786U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCarry, 58U)) + (RotL64(aCross, 23U) ^ RotL64(aPrevious, 39U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererB + RotL64(aIngress, 47U)) + RotL64(aCarry, 13U)) + 14686411261024919129U;
            aOrbiterA = (aWandererK + RotL64(aPrevious, 37U)) + 7514582233957632005U;
            aOrbiterD = (aWandererG + RotL64(aScatter, 41U)) + 6520710480103365552U;
            aOrbiterI = ((aWandererA + RotL64(aCross, 27U)) + 1983621978676188036U) + aOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aScatter, 50U)) + 9003524602590749672U;
            aOrbiterE = (aWandererC + RotL64(aIngress, 57U)) + 6428568234045228995U;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 5U)) + RotL64(aCarry, 3U)) + 8656552687136446989U;
            aOrbiterB = ((aWandererH + RotL64(aCross, 11U)) + 16916248288415922490U) + aOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aScatter, 13U)) + 9740237548002535784U;
            aOrbiterK = (((aWandererD + RotL64(aCross, 54U)) + RotL64(aCarry, 39U)) + 907561000814618339U) + aNonceWordD;
            aOrbiterC = (aWandererI + RotL64(aIngress, 21U)) + 4751108900841197631U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 167774899400732287U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 11907484918310854962U;
            aOrbiterD = RotL64((aOrbiterD * 7213139491146402985U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 14910318613649863924U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 14882888155751455276U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11394136445442060201U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 16175942562693781908U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 11022373758481651102U;
            aOrbiterG = RotL64((aOrbiterG * 6836331461393816027U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 12548405399045031548U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 10850926364556828443U) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 16231561687709867431U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 13391684887911141790U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 14648937281264822988U;
            aOrbiterJ = RotL64((aOrbiterJ * 6533299316940026059U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 8298658887198526821U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 13822977698661348891U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17769262972278410937U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 7505646847564645719U) + aNonceWordP;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 3238749538197209166U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15394286542600778567U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 15853506915123709257U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 8426329899401071248U;
            aOrbiterE = RotL64((aOrbiterE * 1330397096577715113U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 14848635392815613098U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 3549927798350175044U;
            aOrbiterB = RotL64((aOrbiterB * 1899044682313056949U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 1798973117197750802U) + aOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 13056711228618953977U;
            aOrbiterK = RotL64((aOrbiterK * 9102877396419306689U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 1395893547965799281U) + aNonceWordJ;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 14686411261024919129U;
            aOrbiterC = RotL64((aOrbiterC * 17075377081365066067U), 21U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 11U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 26U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + RotL64(aOrbiterC, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterG, 11U)) + aOrbiterI) + RotL64(aCarry, 47U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 23U) + aOrbiterB) + RotL64(aOrbiterJ, 30U));
            aWandererG = aWandererG + ((RotL64(aScatter, 60U) + aOrbiterD) + RotL64(aOrbiterB, 23U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterK, 5U));
            aWandererI = aWandererI + ((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 13U)) + aOrbiterG);
            aWandererE = aWandererE ^ (((RotL64(aCross, 53U) + aOrbiterA) + RotL64(aOrbiterH, 57U)) + aWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 37U)) + aOrbiterF) + RotL64(aCarry, 43U)) + aWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 11U) + aOrbiterI) + RotL64(aOrbiterA, 3U));
            aWandererD = aWandererD + ((RotL64(aIngress, 51U) + RotL64(aOrbiterE, 43U)) + aOrbiterF);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterD, 27U)) + aNonceWordF);
            aWandererK = aWandererK + ((RotL64(aCross, 56U) + RotL64(aOrbiterD, 52U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 52U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + RotL64(aWandererE, 41U);
            aCarry = aCarry + RotL64(aIngress, 50U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordJ);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13993U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11784U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 16230U)) & S_BLOCK1], 4U) ^ RotL64(pSnow[((aIndex + 12311U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 58U) ^ RotL64(aPrevious, 27U)) + (RotL64(aCross, 13U) ^ RotL64(aIngress, 43U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererA + RotL64(aCross, 37U)) + RotL64(aCarry, 47U)) + 3255291173184001106U;
            aOrbiterG = (aWandererD + RotL64(aPrevious, 19U)) + 15308468160116255528U;
            aOrbiterH = ((aWandererB + RotL64(aIngress, 58U)) + RotL64(aCarry, 53U)) + 18186972408589866656U;
            aOrbiterE = (aWandererH + RotL64(aScatter, 23U)) + 4439324265978331914U;
            aOrbiterB = (((aWandererJ + RotL64(aCross, 47U)) + 13099263173016322486U) + aOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1]) + aNonceWordH;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 41U)) + 7041561081767500660U) + aOrbiterAssignSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aIngress, 51U)) + 6196422612687812971U;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 39U)) + 7664260932541281413U) + aNonceWordM;
            aOrbiterI = (aWandererE + RotL64(aPrevious, 11U)) + 17802347823020441056U;
            aOrbiterD = (aWandererK + RotL64(aCross, 21U)) + 4253107484061190446U;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 6U)) + RotL64(aCarry, 19U)) + 13799496534030645312U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 14252892847595951926U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 5663527578664291422U;
            aOrbiterH = RotL64((aOrbiterH * 18314294235895182465U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 11148755959699137661U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 17036900929333594592U;
            aOrbiterF = RotL64((aOrbiterF * 16041243617369003291U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 2403828181385259549U) + aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 17813580350434928194U;
            aOrbiterG = RotL64((aOrbiterG * 13666780980793857831U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 5623611126885414523U) + aNonceWordD;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 7293224381174846969U;
            aOrbiterB = RotL64((aOrbiterB * 7032561584670788117U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 10602620906929686163U) + aNonceWordJ;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 18015916257203385982U;
            aOrbiterC = RotL64((aOrbiterC * 10684090189688871993U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 13592915735376305773U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 13995866908043417505U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3802175869395887331U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 8200465989447697618U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 9866671660800629464U;
            aOrbiterK = RotL64((aOrbiterK * 2138851839905326265U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 11557528777230608777U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 131060617338185060U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11068705423012265209U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 13404720733342982167U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 13128574378042136042U;
            aOrbiterJ = RotL64((aOrbiterJ * 5805270317312187011U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 15879295432652112238U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 9433361543323748909U;
            aOrbiterI = RotL64((aOrbiterI * 3592390041363796221U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 6262775775981534941U) + aNonceWordL;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 3255291173184001106U;
            aOrbiterA = RotL64((aOrbiterA * 2748492753337241005U), 19U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 24U);
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterD, 30U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aCross, 19U) + aOrbiterA) + RotL64(aOrbiterK, 27U)) + aWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 22U) + RotL64(aOrbiterA, 21U)) + aOrbiterG);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 57U) + aOrbiterI) + RotL64(aOrbiterB, 43U)) + aNonceWordO);
            aWandererC = aWandererC + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 47U)) + aOrbiterE);
            aWandererI = aWandererI ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterG, 5U)) + aOrbiterJ);
            aWandererF = aWandererF + ((((RotL64(aScatter, 11U) + aOrbiterA) + RotL64(aOrbiterH, 18U)) + RotL64(aCarry, 29U)) + aWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 60U) + aOrbiterE) + RotL64(aOrbiterB, 53U));
            aWandererG = aWandererG + ((RotL64(aIngress, 53U) + RotL64(aOrbiterC, 23U)) + aOrbiterB);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 5U) + aOrbiterC) + RotL64(aOrbiterJ, 57U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterD, 51U)) + aOrbiterI) + RotL64(aCarry, 39U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterK, 10U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 54U));
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererC, 51U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordN);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 16638U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17061U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20382U)) & S_BLOCK1], 57U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 18276U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 6U) + RotL64(aCarry, 37U)) + (RotL64(aIngress, 51U) ^ RotL64(aCross, 23U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererK + RotL64(aCross, 35U)) + 17936518874386450467U;
            aOrbiterC = (aWandererD + RotL64(aIngress, 43U)) + 13722737841589910344U;
            aOrbiterF = (((aWandererC + RotL64(aScatter, 37U)) + 11774969167948715796U) + aOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordC;
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 19U)) + 3640101505680493777U) + aOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aIngress, 60U)) + 1369495382725650822U;
            aOrbiterD = ((aWandererA + RotL64(aCross, 3U)) + RotL64(aCarry, 5U)) + 11827310354654653345U;
            aOrbiterI = (aWandererF + RotL64(aPrevious, 47U)) + 186037671377175394U;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 53U)) + RotL64(aCarry, 11U)) + 11428829344234627340U;
            aOrbiterB = (aWandererH + RotL64(aIngress, 27U)) + 2275016369870029068U;
            aOrbiterJ = (aWandererE + RotL64(aScatter, 22U)) + 15471646673734798328U;
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 39U)) + RotL64(aCarry, 39U)) + 12172082573115640145U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 6626736341348283154U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterK) ^ 12220614992483863623U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterF = RotL64((aOrbiterF * 8137086205714097487U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 13157102324253760215U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 4143587482368093601U;
            aOrbiterH = RotL64((aOrbiterH * 5060677690991506895U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 11007575246013796426U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 11721585930088637162U;
            aOrbiterD = RotL64((aOrbiterD * 15009627907125738519U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 5720789204450196217U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 3094696226821431648U;
            aOrbiterI = RotL64((aOrbiterI * 4412033981712165541U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 14675830108100986773U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 9444071495289719645U;
            aOrbiterA = RotL64((aOrbiterA * 10983136361953366557U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 5106753847015199956U) + aNonceWordH;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 7585421898593510010U;
            aOrbiterB = RotL64((aOrbiterB * 140996914192351011U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 11746948407655524690U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 16336323220286344483U;
            aOrbiterJ = RotL64((aOrbiterJ * 6590417628835864497U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 8030445186765781136U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 276034088015165891U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7626025612710225099U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 8116955322602209153U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 5704503350608834450U;
            aOrbiterK = RotL64((aOrbiterK * 7049558959583832449U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 8063875087087055875U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 1111816778196345760U;
            aOrbiterC = RotL64((aOrbiterC * 13820440198677609571U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 7702895879089714461U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 17936518874386450467U) ^ aNonceWordG;
            aOrbiterE = RotL64((aOrbiterE * 12767279443267850009U), 53U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 13U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 40U));
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + RotL64(aOrbiterD, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 53U) + aOrbiterK) + RotL64(aOrbiterH, 13U)) + aWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 50U) + aOrbiterE) + RotL64(aOrbiterF, 37U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterH, 58U)) + aOrbiterD) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 27U) + aOrbiterD) + RotL64(aOrbiterG, 51U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 21U) + RotL64(aOrbiterA, 11U)) + aOrbiterI) + RotL64(aCarry, 3U)) + aNonceWordN);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterB, 19U)) + aOrbiterD) + aWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 43U) + RotL64(aOrbiterD, 6U)) + aOrbiterI);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterJ, 29U)) + aOrbiterD);
            aWandererB = aWandererB + ((RotL64(aCross, 60U) + aOrbiterB) + RotL64(aOrbiterE, 3U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 39U)) + aOrbiterC);
            aWandererH = aWandererH + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 53U)) + aOrbiterA) + aNonceWordD);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 44U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 10U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 26839U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26666U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22361U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((aIndex + 24665U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 19U)) + (RotL64(aCross, 39U) + RotL64(aIngress, 56U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererH + RotL64(aScatter, 38U)) + RotL64(aCarry, 35U)) + 9133751643283278896U;
            aOrbiterC = (aWandererB + RotL64(aPrevious, 21U)) + 8971581804375380408U;
            aOrbiterB = (aWandererE + RotL64(aIngress, 23U)) + 12559650383714566592U;
            aOrbiterE = ((aWandererD + RotL64(aCross, 57U)) + 15753206088872859163U) + aOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 10U)) + 7640756270450762350U) + aNonceWordD;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 19U)) + 7340073357551376125U;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 5U)) + 5270256573644196046U;
            aOrbiterD = (aWandererK + RotL64(aCross, 27U)) + 3567367996479995928U;
            aOrbiterA = (((aWandererG + RotL64(aIngress, 53U)) + RotL64(aCarry, 5U)) + 11939634537492733738U) + aNonceWordJ;
            aOrbiterF = (((aWandererA + RotL64(aCross, 47U)) + RotL64(aCarry, 23U)) + 7051817732424527120U) + aOrbiterAssignSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aScatter, 13U)) + 1730487669951837941U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 18009252467909454817U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 2361024272031696442U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15215151562500226027U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 15902755877642960397U) + aNonceWordL;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 12243517544704116184U) ^ aOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2576071074148141447U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 16846181962302186187U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 636121425116506681U;
            aOrbiterD = RotL64((aOrbiterD * 17075030673338779993U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 6887385655828217318U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 3705834550934775862U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11275428284929594435U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 11165142437077969438U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 6426659930331618269U) ^ aNonceWordI;
            aOrbiterK = RotL64((aOrbiterK * 17170640810530893705U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 12629082390899315789U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 4277510580069574724U) ^ aNonceWordM;
            aOrbiterE = RotL64((aOrbiterE * 9829125163412708305U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 13814834144170469978U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 3698381854100295826U;
            aOrbiterJ = RotL64((aOrbiterJ * 5126359230872258015U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 11623170635983579937U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 7247413650388803796U) ^ aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3403219499465560059U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 3129755194359521145U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 4081016725582134919U;
            aOrbiterI = RotL64((aOrbiterI * 11564414998539605389U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 15878346077922215753U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 2974440187796944059U;
            aOrbiterC = RotL64((aOrbiterC * 783253926537018373U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 3922344163443096356U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 9133751643283278896U;
            aOrbiterH = RotL64((aOrbiterH * 16887991698415418429U), 47U);
            //
            aIngress = RotL64(aOrbiterC, 30U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 48U));
            aIngress = aIngress + RotL64(aOrbiterK, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aCross, 11U) + aOrbiterB) + RotL64(aOrbiterG, 5U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 40U) + aOrbiterI) + RotL64(aOrbiterA, 3U)) + aWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterG, 53U)) + RotL64(aCarry, 35U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterC, 39U)) + aNonceWordC);
            aWandererA = aWandererA + ((((RotL64(aCross, 57U) + RotL64(aOrbiterB, 13U)) + aOrbiterF) + RotL64(aCarry, 29U)) + aWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 19U) + aOrbiterD) + RotL64(aOrbiterJ, 43U));
            aWandererF = aWandererF + ((RotL64(aIngress, 37U) + aOrbiterD) + RotL64(aOrbiterG, 34U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 47U)) + aOrbiterI);
            aWandererD = aWandererD + ((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterA, 29U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterC, 23U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 60U) + RotL64(aOrbiterA, 56U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 22U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 10U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31758U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((aIndex + 28249U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32381U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29196U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 51U)) ^ (RotL64(aCross, 21U) + RotL64(aIngress, 36U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (((aWandererG + RotL64(aScatter, 57U)) + RotL64(aCarry, 27U)) + 5573188770530340913U) + aOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 19U)) + 1431772230889897111U) + aOrbiterAssignSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aCross, 27U)) + 4809192776429682319U;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 21U)) + RotL64(aCarry, 37U)) + 5576603692574369341U;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 10U)) + 2720143226007220386U) + aNonceWordN;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 13U)) + RotL64(aCarry, 11U)) + 17220328778565331629U;
            aOrbiterG = (aWandererB + RotL64(aIngress, 23U)) + 9629485808442089423U;
            aOrbiterH = (aWandererE + RotL64(aScatter, 53U)) + 1136998437010390983U;
            aOrbiterC = (aWandererA + RotL64(aPrevious, 3U)) + 11893390497814523841U;
            aOrbiterB = ((aWandererH + RotL64(aCross, 35U)) + 1764986431917532370U) + aNonceWordG;
            aOrbiterK = (aWandererD + RotL64(aScatter, 30U)) + 1741014798007010376U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 12221368453236547044U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 7694538641172350430U;
            aOrbiterJ = RotL64((aOrbiterJ * 8439120733670016501U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 17472344518811560603U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 3308740700728172984U;
            aOrbiterE = RotL64((aOrbiterE * 15290400462887712083U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 9535358833412446771U) + aNonceWordE;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 11192312491731312451U;
            aOrbiterA = RotL64((aOrbiterA * 17405609148475445743U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 14850451970047190039U) + aNonceWordM;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 11932493299452443256U;
            aOrbiterG = RotL64((aOrbiterG * 7964808728820467795U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 5972619895614731870U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 17174497535809891690U;
            aOrbiterH = RotL64((aOrbiterH * 15471084511364572533U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 17412894714378898351U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 14675615208706549810U;
            aOrbiterC = RotL64((aOrbiterC * 7864845089606499769U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 16116792108013658523U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 9702262005960966336U;
            aOrbiterB = RotL64((aOrbiterB * 970452849653781703U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 17337264966818542841U) + aNonceWordD;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 7004462033775827275U;
            aOrbiterK = RotL64((aOrbiterK * 11943575980344402681U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 17499850384482055438U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 1839357713256560566U;
            aOrbiterF = RotL64((aOrbiterF * 12943750650487416281U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 8144238113917577524U) + aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 888195876227325908U) ^ aOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7941506708630993709U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 5081763359501717653U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 5573188770530340913U;
            aOrbiterI = RotL64((aOrbiterI * 9699901099898698965U), 29U);
            //
            aIngress = RotL64(aOrbiterD, 13U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterE, 24U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterG, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aIngress, 42U) + RotL64(aOrbiterA, 5U)) + aOrbiterB);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 13U)) + aOrbiterG);
            aWandererF = aWandererF + (((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterK, 27U)) + aNonceWordO);
            aWandererG = aWandererG ^ (((RotL64(aCross, 37U) + aOrbiterG) + RotL64(aOrbiterC, 21U)) + aWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 39U) + RotL64(aOrbiterH, 57U)) + aOrbiterD);
            aWandererI = aWandererI ^ (((RotL64(aCross, 21U) + aOrbiterD) + RotL64(aOrbiterF, 36U)) + aNonceWordC);
            aWandererK = aWandererK + ((RotL64(aPrevious, 53U) + aOrbiterE) + RotL64(aOrbiterJ, 41U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 18U) + aOrbiterJ) + RotL64(aOrbiterI, 19U));
            aWandererD = aWandererD + ((((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterC, 47U)) + RotL64(aCarry, 53U)) + aWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterD, 51U)) + aOrbiterA);
            aWandererB = aWandererB + (((RotL64(aIngress, 51U) + aOrbiterH) + RotL64(aOrbiterF, 24U)) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 48U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 20U));
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ aNonceWordB;
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

void TwistExpander_Soccer_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xDB59FDA429285F4DULL + 0xF9CF750F193F1D5BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xF321CBA950FFF28BULL + 0xF11D4A9AA32BCE09ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xC0A20A989C962A2BULL + 0xCBCD713C139EA714ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xB261CE1F6137C53DULL + 0xC1A87D71F5958DDFULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xAF108CDB1EAE3CF3ULL + 0xE188CA5EAE49A95CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xB8B61B1E83644EBBULL + 0x84C5D1F8EF47FF47ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x9B34F667BEDCCB51ULL + 0xD298760580CD546BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE5F7734B94EDB835ULL + 0x8879E80B8C790550ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x91C93FA3374BD0F5ULL + 0x95A7EC3B50687FBAULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x9A163B0FEE901B13ULL + 0xF892A6FE763D8B7DULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x88CF6B5ACAB3EDE9ULL + 0x813D8948257C29EAULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xF62BB81BF824C7BBULL + 0x93FF500555D6BA5EULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xF4DAF5CF9A121CD1ULL + 0x8B10B3BEFE40D384ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xBF9A55E33382457FULL + 0xA2047F02C7BD2B8DULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xED800B3FD0B9F6B3ULL + 0xA1F827F435777C24ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xE30296050F88E439ULL + 0x84A06CE9EF9D6AD8ULL);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 6376U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneC[((aIndex + 3476U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1243U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 5328U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 10U) + RotL64(aPrevious, 23U)) + (RotL64(aCross, 37U) ^ RotL64(aIngress, 57U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererF + RotL64(aScatter, 3U)) + 9914837590440975587U;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 54U)) + 6706125076401958051U) + aOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 27U)) + RotL64(aCarry, 35U)) + 16570817772679258409U;
            aOrbiterF = (aWandererI + RotL64(aCross, 43U)) + 6843705658115186948U;
            aOrbiterD = (aWandererB + RotL64(aIngress, 35U)) + 16099930446791572351U;
            aOrbiterE = ((((aWandererC + RotL64(aScatter, 23U)) + RotL64(aCarry, 13U)) + 5420550009556030459U) + aOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1]) + aNonceWordH;
            aOrbiterA = (aWandererH + RotL64(aPrevious, 19U)) + 5729549069420177477U;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 47U)) + RotL64(aCarry, 47U)) + 15590601126188675834U;
            aOrbiterI = (aWandererG + RotL64(aIngress, 14U)) + 13044027390998620029U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 11068338135659636772U) + aOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 6584988841809544332U;
            aOrbiterC = RotL64((aOrbiterC * 1683336180438945439U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 8516813219883915404U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 10647314042912492785U;
            aOrbiterE = RotL64((aOrbiterE * 15559481057047148785U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 201691689889605304U) + aOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 15512161798401184003U;
            aOrbiterG = RotL64((aOrbiterG * 11473219183982564709U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 3883760518944464145U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 13861805129175491145U;
            aOrbiterI = RotL64((aOrbiterI * 17194438894492581181U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 12019138626550801486U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 13030350224959652248U;
            aOrbiterK = RotL64((aOrbiterK * 11724200983306280107U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 2643807255422544248U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 4127143302485631794U;
            aOrbiterF = RotL64((aOrbiterF * 5441038881111578487U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 14602951930809633069U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 4555737199162278494U) ^ aNonceWordK;
            aOrbiterA = RotL64((aOrbiterA * 12415825635220991865U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 6343143902997169834U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 10404783711336491985U;
            aOrbiterJ = RotL64((aOrbiterJ * 6235474458879439079U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 7406959231434835393U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterI) ^ 6684368109277850196U) ^ aOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterD = RotL64((aOrbiterD * 8760360417572331159U), 23U);
            //
            aIngress = RotL64(aOrbiterG, 39U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 54U));
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 12U) + RotL64(aOrbiterA, 34U)) + aOrbiterK);
            aWandererH = aWandererH + (((RotL64(aScatter, 43U) + aOrbiterC) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterC, 29U)) + aOrbiterE) + aWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aCross, 51U) + RotL64(aOrbiterJ, 23U)) + aOrbiterI) + RotL64(aCarry, 27U)) + aNonceWordD);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterF, 43U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 27U) + aOrbiterD) + RotL64(aOrbiterG, 39U));
            aWandererD = aWandererD ^ ((((RotL64(aCross, 22U) + RotL64(aOrbiterF, 53U)) + aOrbiterG) + aNonceWordN) + aWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 11U)) + aOrbiterI);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterK, 58U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 58U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 10128U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneD[((aIndex + 9196U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10986U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneB[((aIndex + 12028U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCross, 5U)) ^ (RotL64(aCarry, 18U) + RotL64(aPrevious, 37U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererF + RotL64(aCross, 58U)) + 16424657151168221875U;
            aOrbiterG = (aWandererB + RotL64(aPrevious, 23U)) + 17150123681886380361U;
            aOrbiterI = (((aWandererE + RotL64(aIngress, 11U)) + RotL64(aCarry, 53U)) + 16041993588694572757U) + aNonceWordJ;
            aOrbiterF = (((aWandererJ + RotL64(aScatter, 5U)) + 9871185846434828537U) + aOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1]) + aNonceWordP;
            aOrbiterD = (aWandererK + RotL64(aCross, 35U)) + 11227236398354430757U;
            aOrbiterA = (aWandererA + RotL64(aPrevious, 41U)) + 5399325217402192631U;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 47U)) + RotL64(aCarry, 27U)) + 9248828789282890454U;
            aOrbiterE = (aWandererC + RotL64(aIngress, 28U)) + 9041370494203701062U;
            aOrbiterC = ((((aWandererG + RotL64(aPrevious, 53U)) + RotL64(aCarry, 39U)) + 14944424084524970764U) + aOrbiterAssignSaltB[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordF;
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 5481938174456671041U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 14783648629543752715U;
            aOrbiterI = RotL64((aOrbiterI * 7260164783191886395U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 12355573914530445723U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 9863991559011968318U;
            aOrbiterD = RotL64((aOrbiterD * 8495251211794343179U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 16149688605937250965U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 106041828692026825U;
            aOrbiterB = RotL64((aOrbiterB * 12199934305374582599U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 8076098639554567792U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 11155119311895580013U) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 1495180896564818647U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 6847612160595917702U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 16094377920388017367U;
            aOrbiterC = RotL64((aOrbiterC * 4875801863643206333U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 13584719866672696684U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 13446209321646234607U;
            aOrbiterK = RotL64((aOrbiterK * 9945349065094781529U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 15829806645369560988U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 12573767256739062550U;
            aOrbiterF = RotL64((aOrbiterF * 5649504278826069077U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 3850030870300393809U) + aNonceWordK;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 11857593987748189858U) ^ aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15942863910931814193U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 5505918410521728373U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 12949653497121247860U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 90944913639560027U), 23U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterA, 39U);
            aIngress = aIngress + (RotL64(aOrbiterD, 27U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterG, 50U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterB, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterI, 13U)) + aNonceWordG) + aWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 57U) + aOrbiterB) + RotL64(aOrbiterE, 34U)) + aWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterC, 57U)) + aOrbiterD);
            aWandererC = aWandererC + ((RotL64(aScatter, 43U) + aOrbiterB) + RotL64(aOrbiterA, 47U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 52U) + RotL64(aOrbiterI, 51U)) + aOrbiterF);
            aWandererA = aWandererA + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterG, 27U)) + aOrbiterE) + RotL64(aCarry, 3U)) + aNonceWordC);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterI, 21U)) + aOrbiterK);
            aWandererD = aWandererD + (((RotL64(aCross, 23U) + aOrbiterK) + RotL64(aOrbiterG, 39U)) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 48U) + aOrbiterK) + RotL64(aOrbiterE, 4U)) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererG, 14U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 54U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 19069U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneA[((aIndex + 17923U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 22022U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 16520U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 43U) ^ RotL64(aCross, 57U)) ^ (RotL64(aPrevious, 14U) + RotL64(aCarry, 29U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererB + RotL64(aPrevious, 29U)) + 13499155707765393469U;
            aOrbiterD = (aWandererG + RotL64(aIngress, 58U)) + 3740324981823726185U;
            aOrbiterI = ((aWandererI + RotL64(aCross, 19U)) + RotL64(aCarry, 3U)) + 5470765363949735652U;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 39U)) + 3446436171274452326U;
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 3U)) + 1778929412631211933U) + aOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = (aWandererE + RotL64(aCross, 47U)) + 14666308799855220954U;
            aOrbiterK = (((aWandererA + RotL64(aIngress, 12U)) + RotL64(aCarry, 53U)) + 4548410236791175055U) + aNonceWordB;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 35U)) + 5829739767694190372U) + aOrbiterAssignSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = (((aWandererF + RotL64(aPrevious, 43U)) + RotL64(aCarry, 27U)) + 14319231414903675748U) + aNonceWordC;
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 1513851750246111405U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 1685620217748986019U;
            aOrbiterI = RotL64((aOrbiterI * 9286548037413609445U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 16284162182006054402U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 6271539598462003309U) ^ aOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13923286694131331137U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 12669312437565969473U) + aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 11894755313393001665U;
            aOrbiterJ = RotL64((aOrbiterJ * 12556759675372354075U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 6315983824634946566U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 17106616474222892782U;
            aOrbiterD = RotL64((aOrbiterD * 167205520766791073U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 13350266700180455548U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 4608846311203767162U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2504857468837437365U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 14195866746143604365U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 7917977448256795054U) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 5927771378657284557U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 10707336923305131629U) + aNonceWordN;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 17122696159336995392U;
            aOrbiterK = RotL64((aOrbiterK * 13953518568670659191U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 5182322763573586116U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 6503754948502556246U;
            aOrbiterG = RotL64((aOrbiterG * 14749002194140663519U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 14907832047832987341U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 6258064448676621346U;
            aOrbiterE = RotL64((aOrbiterE * 4407960312705621487U), 23U);
            //
            aIngress = RotL64(aOrbiterJ, 41U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 34U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + RotL64(aOrbiterH, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 35U) + RotL64(aOrbiterA, 35U)) + aOrbiterD) + RotL64(aCarry, 35U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 14U) + aOrbiterF) + RotL64(aOrbiterK, 19U)) + aWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 24U)) + aOrbiterH);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterG, 3U)) + aOrbiterJ);
            aWandererI = aWandererI + ((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterJ, 39U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 27U) + aOrbiterI) + RotL64(aOrbiterG, 13U)) + aNonceWordI);
            aWandererF = aWandererF + (((((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 57U)) + aOrbiterE) + RotL64(aCarry, 57U)) + aNonceWordF) + aWandererUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 10U) + aOrbiterE) + RotL64(aOrbiterF, 52U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 3U) + aOrbiterA) + RotL64(aOrbiterF, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 6U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 28474U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneB[((aIndex + 30867U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25542U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((aIndex + 32086U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 37U) ^ RotL64(aIngress, 11U)) + (RotL64(aCross, 23U) + RotL64(aPrevious, 60U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererF + RotL64(aScatter, 28U)) + RotL64(aCarry, 53U)) + 12775735908960052604U;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 41U)) + 11791373812080296887U) + aNonceWordM;
            aOrbiterD = (aWandererG + RotL64(aCross, 37U)) + 5537362877706057303U;
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 23U)) + 2023912048504189380U) + aOrbiterAssignSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = (aWandererA + RotL64(aScatter, 3U)) + 17668828109963766893U;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 57U)) + 558908629933941224U) + aOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = ((aWandererH + RotL64(aCross, 46U)) + RotL64(aCarry, 23U)) + 1479633119685446888U;
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 13U)) + RotL64(aCarry, 39U)) + 15460320397843364063U;
            aOrbiterB = (aWandererD + RotL64(aIngress, 19U)) + 10059749397555469054U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 9987633811929693924U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 10087337844580228269U;
            aOrbiterD = RotL64((aOrbiterD * 13817142288940843815U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 4446204415503364254U) + aOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 15106063243302192717U;
            aOrbiterC = RotL64((aOrbiterC * 13273756657334709803U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 9430197906134676162U) + aNonceWordE;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 1226048679997253363U) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 14247538885252664127U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 10611580584157624739U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 3137391249289641509U;
            aOrbiterA = RotL64((aOrbiterA * 5462682413239873181U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 9327201928815412810U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 7890659377013147073U;
            aOrbiterI = RotL64((aOrbiterI * 13827717178378062047U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 10675114832750356941U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 8804440385852327267U) ^ aOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8520671775587260601U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 12871947817782057116U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 11015991745792051390U;
            aOrbiterH = RotL64((aOrbiterH * 17152451500505815031U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 6320437975845673731U) + aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 702457937087191287U) ^ aNonceWordH;
            aOrbiterB = RotL64((aOrbiterB * 17491257114676739589U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 16629064896250312921U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 6054107387816339103U;
            aOrbiterJ = RotL64((aOrbiterJ * 6983767878966747219U), 3U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 35U);
            aIngress = aIngress + (RotL64(aOrbiterI, 4U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 21U));
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((((RotL64(aScatter, 26U) + aOrbiterC) + RotL64(aOrbiterD, 37U)) + RotL64(aCarry, 51U)) + aNonceWordN) + aWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 6U)) + aOrbiterE);
            aWandererG = aWandererG + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 29U)) + aOrbiterB) + aWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 43U)) + aOrbiterA);
            aWandererI = aWandererI + (((RotL64(aCross, 60U) + aOrbiterE) + RotL64(aOrbiterG, 51U)) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 43U) + aOrbiterE) + RotL64(aOrbiterH, 18U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 23U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterE, 11U)) + aOrbiterC) + aNonceWordJ);
            aWandererA = aWandererA + ((RotL64(aPrevious, 13U) + aOrbiterC) + RotL64(aOrbiterG, 47U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 20U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordG;
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

void TwistExpander_Soccer_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xEE92495053140D95ULL + 0xAD473936AD83D8ACULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xE10484B89FD1A095ULL + 0xA0131B2D4AB1AD5AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xBD65C8B128655DD7ULL + 0xD3A2A5420EA3ECFEULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xBE42E76CD4BD2ED3ULL + 0x9C2DF93DE2C434FBULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x828A41B7F36077AFULL + 0x8B62F578F0755B45ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xB1C346EBEBE1CE57ULL + 0xDCE221A4A6E5035CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x8970F40048495A55ULL + 0xEEFF790BEDC494CEULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xC158554CEF4C5099ULL + 0x864CD80EBD257F45ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xD845D827AE4B0909ULL + 0x8BEDD6982193070BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xF06D39E0FFA05E47ULL + 0xD5E2B36DF0161A7FULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xAD105F918DB92AC5ULL + 0x99E398C94074A212ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xEA13E434A5639E85ULL + 0xD680F3DAC26581A5ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x9118FAB2AAE326E9ULL + 0xDBDAB86E7BBA3778ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xC03437F1527B6E45ULL + 0x99856B70FD7CB54FULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xC8B8F3093A1244D1ULL + 0x8D84CB738118F675ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xEAFDE29381DF7E9DULL + 0xCC6804BDD9CF44E4ULL);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 6863U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 5093U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 1791U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneA[((aIndex + 5182U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 36U) + RotL64(aCross, 3U)) + (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 19U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 53U)) + RotL64(aCarry, 13U)) + 14179205183062705133U;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 39U)) + RotL64(aCarry, 29U)) + 210032324058740920U;
            aOrbiterE = ((((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 43U)) + 7387115089142500152U) + aOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordI;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 29U)) + 17583362781238061430U) + aNonceWordF;
            aOrbiterI = (((aWandererB + RotL64(aScatter, 14U)) + 4991442849150005943U) + aOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordN;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 2891376254689854555U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 10523274382407446239U;
            aOrbiterE = RotL64((aOrbiterE * 17443994099359920915U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 3861893764676218667U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 3366674459852093746U;
            aOrbiterJ = RotL64((aOrbiterJ * 14005994095369483813U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 5898492634386601145U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 7047353571244768721U) ^ aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2257518291062508467U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 14374108805453186316U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterI) ^ 8763667021501226510U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterF = RotL64((aOrbiterF * 7694695426430267863U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 18261523829316379575U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 650477532238860965U;
            aOrbiterI = RotL64((aOrbiterI * 8291758490821819851U), 51U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 24U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 37U));
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 30U) + RotL64(aOrbiterE, 21U)) + aOrbiterJ);
            aWandererB = aWandererB + (((((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterF, 37U)) + RotL64(aCarry, 57U)) + aNonceWordJ) + aWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterJ, 56U));
            aWandererC = aWandererC + (((((RotL64(aScatter, 53U) + aOrbiterE) + RotL64(aOrbiterI, 11U)) + RotL64(aCarry, 5U)) + aNonceWordB) + aWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterI, 47U)) + aOrbiterJ) + aNonceWordH);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 56U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 12023U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 10198U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 11648U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneB[((aIndex + 12931U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aIngress, 11U)) + (RotL64(aCross, 23U) ^ RotL64(aPrevious, 60U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererB + RotL64(aIngress, 57U)) + 13880995121909552664U) + aNonceWordL;
            aOrbiterB = (((aWandererJ + RotL64(aScatter, 11U)) + RotL64(aCarry, 27U)) + 14534942818069300546U) + aOrbiterAssignSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = (aWandererI + RotL64(aCross, 23U)) + 17745973100886007133U;
            aOrbiterE = (((aWandererG + RotL64(aPrevious, 35U)) + RotL64(aCarry, 51U)) + 2249805580771946872U) + aNonceWordM;
            aOrbiterH = ((((aWandererK + RotL64(aCross, 44U)) + RotL64(aCarry, 39U)) + 4460116116396439410U) + aOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordB;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 3378683994078106878U) + aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 3992996501048809123U) ^ aNonceWordI;
            aOrbiterK = RotL64((aOrbiterK * 13273544260537223797U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 12057768808864451929U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 4115362079047921130U;
            aOrbiterH = RotL64((aOrbiterH * 12263015903331031345U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 15297384955502206698U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 17623548383481905636U;
            aOrbiterI = RotL64((aOrbiterI * 7487278217901483685U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 3559213898000162417U) + aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 12311605719074507335U) ^ aOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3982199462062847697U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 14807313864347885885U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterH) ^ 11222085523291581822U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterE = RotL64((aOrbiterE * 12580941911587215653U), 11U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 13U);
            aIngress = aIngress + (RotL64(aOrbiterE, 54U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aScatter, 41U) + RotL64(aOrbiterE, 29U)) + aOrbiterI) + RotL64(aCarry, 5U)) + aWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterE, 40U)) + aOrbiterB);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 11U) + aOrbiterH) + RotL64(aOrbiterK, 11U)) + RotL64(aCarry, 29U)) + aWandererUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterB, 57U)) + aOrbiterI);
            aWandererI = aWandererI + (((RotL64(aPrevious, 30U) + RotL64(aOrbiterI, 21U)) + aOrbiterH) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordK;
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 16830U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 21214U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 21885U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 23522U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 13U) + RotL64(aIngress, 39U)) + (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 54U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererD + RotL64(aCross, 5U)) + RotL64(aCarry, 57U)) + 11410829607777684449U;
            aOrbiterK = (((aWandererG + RotL64(aIngress, 41U)) + RotL64(aCarry, 21U)) + 7502698839700975347U) + aNonceWordK;
            aOrbiterD = (aWandererK + RotL64(aPrevious, 58U)) + 13267685058252106173U;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 13U)) + 238242706996630625U) + aOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = (((aWandererB + RotL64(aPrevious, 21U)) + RotL64(aCarry, 37U)) + 8184695499511454281U) + aOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 12767823220461985403U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 12293198423143850330U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5073886956792823825U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 11149495229952495939U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 7556992689338382800U;
            aOrbiterK = RotL64((aOrbiterK * 18232398462716803063U), 3U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterH) + 3431338808774134649U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordA;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 16863099140844995099U;
            aOrbiterA = RotL64((aOrbiterA * 752376661101787919U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 17872458049880677604U) + aNonceWordE;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 16760153457252546974U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11225037229069712805U), 21U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterD) + 3115544493537438408U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordF;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 4359882942759752958U;
            aOrbiterF = RotL64((aOrbiterF * 561477566995575801U), 11U);
            //
            aIngress = RotL64(aOrbiterH, 57U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterF, 34U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterD, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aIngress, 13U) + RotL64(aOrbiterK, 29U)) + aOrbiterD) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 37U) + aOrbiterK) + RotL64(aOrbiterA, 21U)) + aNonceWordG) + aWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aCross, 5U) + RotL64(aOrbiterA, 51U)) + aOrbiterH) + RotL64(aCarry, 41U)) + aWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 22U) + RotL64(aOrbiterH, 5U)) + aOrbiterF) + aNonceWordH);
            aWandererK = aWandererK + ((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 40U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 27U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ aNonceWordB;
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 30662U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27495U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30976U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneD[((aIndex + 25771U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 13U) ^ RotL64(aIngress, 58U)) + (RotL64(aPrevious, 29U) + RotL64(aCarry, 41U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((((aWandererB + RotL64(aScatter, 39U)) + RotL64(aCarry, 51U)) + 16651241552253078315U) + aOrbiterAssignSaltB[((aIndex + 8U)) & S_SALT1]) + aNonceWordP;
            aOrbiterA = (aWandererI + RotL64(aCross, 19U)) + 4558144676982478003U;
            aOrbiterE = ((((aWandererH + RotL64(aPrevious, 56U)) + RotL64(aCarry, 13U)) + 8814884320080367550U) + aOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordB;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 11U)) + RotL64(aCarry, 37U)) + 16011579668555672117U;
            aOrbiterG = ((aWandererC + RotL64(aCross, 47U)) + 4738918668759862438U) + aNonceWordL;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 12526083125540985108U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 8048723561746000552U;
            aOrbiterE = RotL64((aOrbiterE * 11914807994597963481U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 1082218464034639039U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 8432043246965946816U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7801965585991025451U), 27U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterE) + 9982080524048636852U) + aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1]) + aNonceWordG;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 6720069955755215919U) ^ aOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1025046364205332059U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 1019035028070247757U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 7360619079463870467U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6623074813047915863U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 10893918488381348474U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 1390297670907738019U;
            aOrbiterG = RotL64((aOrbiterG * 11909657437658597735U), 5U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterA, 21U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterG, 13U)) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 42U) + RotL64(aOrbiterE, 4U)) + aOrbiterI) + aNonceWordM);
            aWandererB = aWandererB + (((RotL64(aPrevious, 11U) + aOrbiterA) + RotL64(aOrbiterE, 29U)) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 53U) + aOrbiterI) + RotL64(aOrbiterH, 41U)) + aWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aScatter, 19U) + aOrbiterH) + RotL64(aOrbiterA, 53U)) + aNonceWordI) + aWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 56U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordB;
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

void TwistExpander_Soccer_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xDF6446E80D0C8EA7ULL + 0xE6837A957BA3962CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xFAFA4F0858CA8E53ULL + 0x86691AFD061A3287ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xD7EE60CD57585609ULL + 0xB90DE54FF03F1F7AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xE684690D34F830A7ULL + 0x9A7203EF3282E42EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xB1E2CCEE80592691ULL + 0xEA248A1238E6BC0DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xAB69946945998389ULL + 0xECDD9F374C83BD1CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xDAD0051F23A0514DULL + 0xACF255CD8A7B7DD9ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE8C1637F03ADB7AFULL + 0x953EDA24D5ADF301ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xC218E117114F801DULL + 0xF9B93F8AFF32A4DEULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xB3E2E7C150B7A61BULL + 0xC441F3388126B9E0ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x9F3A3DB58D7420FBULL + 0xB6777E44D5534034ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xF37A49E7425DF2BFULL + 0xB97B4323EAF77E7AULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xD54A634A4F190B45ULL + 0xF07494931094333FULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xCCAD4ECDADD997D1ULL + 0xA40FE67C2EE98843ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xFD34D966D721950DULL + 0xA6269D32DC3248C4ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xA818E4316E0D7F49ULL + 0x9226B3BF07972146ULL);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 6819U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 342U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2531U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneA[((aIndex + 3326U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aIngress, 3U)) + (RotL64(aCross, 24U) + RotL64(aPrevious, 51U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererK + RotL64(aCross, 60U)) + RotL64(aCarry, 43U)) + 898812731947995389U;
            aOrbiterE = ((aWandererF + RotL64(aIngress, 43U)) + RotL64(aCarry, 23U)) + 8677347622525527167U;
            aOrbiterH = (((aWandererE + RotL64(aScatter, 53U)) + RotL64(aCarry, 5U)) + 770321564027567654U) + aOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 29U)) + 11020474858081526395U) + aOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = ((aWandererC + RotL64(aCross, 11U)) + 17289793580414993470U) + aNonceWordE;
            aOrbiterA = (aWandererD + RotL64(aPrevious, 35U)) + 10111912559295118444U;
            aOrbiterB = (aWandererJ + RotL64(aIngress, 23U)) + 8083622125544542011U;
            //
            aOrbiterD = (((aOrbiterD + aOrbiterE) + 7149858558922988240U) + aOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1]) + aNonceWordL;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 5919683821379905699U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16705119888884231567U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 6860902846079238714U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 15083517836867542075U;
            aOrbiterC = RotL64((aOrbiterC * 4686657139237578325U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 14852868368708376381U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 9860233289028878323U;
            aOrbiterA = RotL64((aOrbiterA * 13418143547952204667U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 772406119079116272U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 7971141501337627589U;
            aOrbiterB = RotL64((aOrbiterB * 10168120622976358617U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 8478568022896691911U) + aNonceWordO;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 4027604850785607101U;
            aOrbiterD = RotL64((aOrbiterD * 4826627523578901467U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 17199331557841535430U) + aNonceWordJ;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 7515957656979776361U;
            aOrbiterK = RotL64((aOrbiterK * 5468950152869656599U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 17138249294921502391U) + aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 16236812863923234668U;
            aOrbiterE = RotL64((aOrbiterE * 2925542836624164807U), 47U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 23U);
            aIngress = aIngress + (RotL64(aOrbiterE, 60U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + RotL64(aOrbiterB, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 3U) + aOrbiterD) + RotL64(aOrbiterE, 41U)) + aWandererUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 51U) + RotL64(aOrbiterB, 3U)) + aOrbiterD) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 43U) + aOrbiterE) + RotL64(aOrbiterC, 27U)) + aNonceWordH);
            aWandererE = aWandererE + (((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 13U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 21U)) + aOrbiterA);
            aWandererC = aWandererC + (((RotL64(aCross, 35U) + RotL64(aOrbiterD, 54U)) + aOrbiterC) + aWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 10U) + RotL64(aOrbiterD, 35U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 22U));
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 5U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordC);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 13399U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12886U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14632U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 12892U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 19U)) ^ (RotL64(aCarry, 51U) + RotL64(aPrevious, 34U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererE + RotL64(aScatter, 41U)) + RotL64(aCarry, 47U)) + 9023059520606551446U;
            aOrbiterC = (aWandererA + RotL64(aIngress, 58U)) + 662441755115638133U;
            aOrbiterI = (aWandererK + RotL64(aCross, 51U)) + 16957253361196144712U;
            aOrbiterK = ((((aWandererJ + RotL64(aPrevious, 11U)) + RotL64(aCarry, 21U)) + 7840955025765308605U) + aOrbiterAssignSaltD[((aIndex + 8U)) & S_SALT1]) + aNonceWordA;
            aOrbiterH = (((aWandererC + RotL64(aIngress, 35U)) + RotL64(aCarry, 5U)) + 346855809270395799U) + aNonceWordK;
            aOrbiterD = (((aWandererB + RotL64(aCross, 29U)) + 16099139781586668343U) + aOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1]) + aNonceWordH;
            aOrbiterA = (aWandererI + RotL64(aScatter, 3U)) + 3706457327118322098U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 12166825885547622870U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 7792658665720344200U) ^ aOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16305542632794270697U), 19U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterH) + 7128477606152986326U) + aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1]) + aNonceWordN;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 11116533962780290084U) ^ aOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11993485572912492297U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 10443889548568288532U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 4402387036946561017U;
            aOrbiterK = RotL64((aOrbiterK * 9032964741841833277U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 13002706161178447654U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 13929727277530310708U;
            aOrbiterC = RotL64((aOrbiterC * 7005639090871200285U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 10949073760696935106U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 15405923432006783533U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17989565878445202495U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 18096057968822208905U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 3032155040484574973U) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 448597307502544605U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 17462076466907467134U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 15471015427013701406U) ^ aNonceWordE;
            aOrbiterA = RotL64((aOrbiterA * 6113474000571976139U), 11U);
            //
            aIngress = RotL64(aOrbiterI, 21U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterH, 50U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterA, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterK, 27U)) + aOrbiterC);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 41U) + RotL64(aOrbiterI, 20U)) + aOrbiterA) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterH, 53U));
            aWandererE = aWandererE + ((((RotL64(aCross, 21U) + RotL64(aOrbiterI, 11U)) + aOrbiterE) + aNonceWordJ) + aWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 37U)) + aOrbiterH) + aWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 34U) + RotL64(aOrbiterE, 5U)) + aOrbiterD) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterD, 47U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + RotL64(aWandererI, 34U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordK);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 23714U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneA[((aIndex + 19409U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 23882U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 23984U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCarry, 23U)) ^ (RotL64(aIngress, 58U) ^ RotL64(aCross, 11U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererG + RotL64(aScatter, 11U)) + RotL64(aCarry, 23U)) + 2168513956284366370U;
            aOrbiterE = (aWandererH + RotL64(aCross, 47U)) + 10290361969974613111U;
            aOrbiterG = (((aWandererC + RotL64(aPrevious, 41U)) + RotL64(aCarry, 3U)) + 15673836275828498050U) + aOrbiterAssignSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aIngress, 21U)) + 16600540024145812236U;
            aOrbiterC = ((aWandererA + RotL64(aCross, 27U)) + 9428052101528111892U) + aNonceWordH;
            aOrbiterK = ((aWandererB + RotL64(aScatter, 3U)) + 12763657928312763377U) + aNonceWordJ;
            aOrbiterD = (((aWandererF + RotL64(aIngress, 58U)) + RotL64(aCarry, 53U)) + 10751286982008662485U) + aOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 1708230173038057979U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 4011389705422783816U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11692237130784795961U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 11704428328093077714U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 2055336619674699284U;
            aOrbiterE = RotL64((aOrbiterE * 6374289210096410907U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 1870865272102705804U) + aNonceWordG;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 3574214263751923179U) ^ aOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13132083406834413563U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 984611970726966186U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 15207945449947643672U) ^ aOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9539470161576639981U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 4181398506373973169U) + aNonceWordN;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 15222345431506025949U;
            aOrbiterC = RotL64((aOrbiterC * 6925143692628659467U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 15023513452326240962U) + aNonceWordC;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 14965669361708810699U;
            aOrbiterK = RotL64((aOrbiterK * 587008860996713147U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 7985755518735406360U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 225592097619240187U;
            aOrbiterD = RotL64((aOrbiterD * 2313509354133400439U), 39U);
            //
            aIngress = RotL64(aOrbiterG, 23U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + RotL64(aOrbiterD, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 37U) + aOrbiterD) + RotL64(aOrbiterG, 4U));
            aWandererH = aWandererH + ((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 13U)) + aOrbiterK);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterD, 39U)) + aWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 26U) + aOrbiterC) + RotL64(aOrbiterK, 51U)) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterB, 29U)) + aOrbiterE);
            aWandererG = aWandererG + ((((RotL64(aIngress, 13U) + aOrbiterG) + RotL64(aOrbiterK, 21U)) + RotL64(aCarry, 41U)) + aNonceWordL);
            aWandererB = aWandererB ^ (((RotL64(aCross, 47U) + aOrbiterG) + RotL64(aOrbiterJ, 57U)) + aWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 46U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + RotL64(aWandererK, 23U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordL);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 26683U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29902U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31836U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 26557U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCarry, 35U)) + (RotL64(aCross, 3U) + RotL64(aPrevious, 20U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererH + RotL64(aCross, 3U)) + 8767379393098711499U;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 21U)) + RotL64(aCarry, 35U)) + 7168159491580816433U;
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 13U)) + 9879279829061883406U) + aOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = ((aWandererK + RotL64(aScatter, 57U)) + 10537167136053399303U) + aNonceWordM;
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 29U)) + 2839070018069188936U) + aOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterI = (((aWandererE + RotL64(aCross, 37U)) + RotL64(aCarry, 51U)) + 13844278063968429732U) + aNonceWordG;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 46U)) + RotL64(aCarry, 23U)) + 11278946626186474646U;
            //
            aOrbiterD = (((aOrbiterD + aOrbiterJ) + 11798425216660557799U) + aOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1]) + aNonceWordL;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 7618446090703335192U) ^ aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7168757300685156779U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 695423597006983660U) + aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 14344728202803488813U) ^ aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5168825904902285909U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 11656100506575697086U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 10384358779985773937U) ^ aNonceWordH;
            aOrbiterJ = RotL64((aOrbiterJ * 247494692039140973U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 17585001605131977341U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 9964478171465522911U;
            aOrbiterB = RotL64((aOrbiterB * 13484044854790175315U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 2710943171829692624U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 17809072853457153057U;
            aOrbiterD = RotL64((aOrbiterD * 16341884203303271365U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 12814092033910687774U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 1743186323268668740U;
            aOrbiterK = RotL64((aOrbiterK * 11150822630624332557U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 10750472346626754704U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 15925901217078035356U;
            aOrbiterF = RotL64((aOrbiterF * 9276504171291801637U), 3U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 35U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 60U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 27U)) + aNonceWordA);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterH, 39U)) + aWandererUpdateSaltD[((aIndex + 26U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 4U) + RotL64(aOrbiterJ, 51U)) + aOrbiterD);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 35U) + aOrbiterD) + RotL64(aOrbiterI, 27U)) + aNonceWordB);
            aWandererH = aWandererH + ((RotL64(aCross, 57U) + RotL64(aOrbiterB, 19U)) + aOrbiterJ);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterK, 13U)) + aOrbiterB);
            aWandererE = aWandererE + (((((RotL64(aScatter, 23U) + aOrbiterK) + RotL64(aOrbiterI, 60U)) + RotL64(aCarry, 43U)) + aNonceWordE) + aWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + RotL64(aWandererD, 52U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordC;
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

void TwistExpander_Soccer_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xB54989338D677233ULL + 0xC8246C791613DD6BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xD9F6A3D1035927D1ULL + 0xE315A2047A2DBC1CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xA01CF489094B582BULL + 0xCDBC506C0CA30A4AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xF4E7119A9B17830DULL + 0x92C4E4043F795586ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA59CB4A73C7A3789ULL + 0xE4DB5AE7E8B15C4AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xA9F3FC346D0CEFAFULL + 0xF27DDA0EE6412778ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x94810E7DAF5DC961ULL + 0x8D0FF2601EDC82C0ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xA2539CDD027087EFULL + 0xE81819BCEA38BB8EULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xB355203F7F002689ULL + 0x946CA41E6C9D0632ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xA9BAE981C924C949ULL + 0xBE6CBE2D3C931271ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xCA5EE1AD315735F9ULL + 0xE92CE07B269015E7ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xE5EF73FF2C0DDB9FULL + 0xF61F29373714F2AAULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xF9978F5F33889189ULL + 0x883D1A8253EB8C40ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x849D94DC349793A1ULL + 0xE3B651C70CF0BDC6ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xA4DD13B81AD72C65ULL + 0xF96A17803B6AD3B5ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xC352D7B6638C55A9ULL + 0xEA03FE65CD234FBDULL);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 4725U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneC[((aIndex + 8049U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 478U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 3373U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 37U)) + (RotL64(aIngress, 52U) ^ RotL64(aCarry, 19U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (aWandererB + RotL64(aPrevious, 34U)) + 3917730204724097072U;
            aOrbiterK = (((aWandererJ + RotL64(aCross, 19U)) + RotL64(aCarry, 11U)) + 1874642340716212824U) + aNonceWordL;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 27U)) + RotL64(aCarry, 39U)) + 6900165757434854160U;
            aOrbiterH = (((aWandererH + RotL64(aScatter, 3U)) + 12750946097023807161U) + aOrbiterAssignSaltF[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordB;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 11U)) + RotL64(aCarry, 27U)) + 6563216048479513594U;
            aOrbiterI = ((aWandererA + RotL64(aCross, 51U)) + 14960240191349450795U) + aNonceWordM;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 43U)) + 16306180275951788289U) + aOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 6502066618271045547U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 6219852857850888738U;
            aOrbiterD = RotL64((aOrbiterD * 10892297250334325283U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 2272931312452845850U) + aOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 3028929882263199463U) ^ aNonceWordE;
            aOrbiterC = RotL64((aOrbiterC * 11005324285856805069U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 6067393030073568112U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 10094809900437037258U) ^ aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 18095564940730322769U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 5962414178157074575U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 15755563045799129417U;
            aOrbiterB = RotL64((aOrbiterB * 3692603590609922031U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 6321455513889880590U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 1197435601998121700U;
            aOrbiterA = RotL64((aOrbiterA * 17693996266260557625U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 12496949381666299968U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 6357070235648527030U) ^ aOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2931486644220862433U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 8423760160877540210U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 8090246492554850768U;
            aOrbiterK = RotL64((aOrbiterK * 2949407491181921633U), 41U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 3U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterD, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterI, 41U)) + aOrbiterK) + aWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 5U)) + aOrbiterH);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 58U) + RotL64(aOrbiterD, 11U)) + aOrbiterI);
            aWandererH = aWandererH + (((RotL64(aCross, 19U) + aOrbiterA) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 3U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterC, 21U)) + aOrbiterK);
            aWandererK = aWandererK + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterD, 58U)) + aOrbiterH) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ ((((RotL64(aCross, 11U) + RotL64(aOrbiterA, 29U)) + aOrbiterD) + aNonceWordI) + aWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 14U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + RotL64(aWandererG, 39U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordK);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 14558U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneD[((aIndex + 14671U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 15496U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 8913U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 54U) + RotL64(aPrevious, 5U)) + (RotL64(aCarry, 41U) ^ RotL64(aIngress, 19U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((((aWandererD + RotL64(aIngress, 41U)) + RotL64(aCarry, 35U)) + 10336802574069791273U) + aOrbiterAssignSaltD[((aIndex + 24U)) & S_SALT1]) + aNonceWordD;
            aOrbiterG = (aWandererC + RotL64(aPrevious, 19U)) + 169025388197058936U;
            aOrbiterC = (aWandererK + RotL64(aCross, 13U)) + 6541354188379168846U;
            aOrbiterI = (aWandererI + RotL64(aScatter, 5U)) + 16223920526599306104U;
            aOrbiterE = (((aWandererB + RotL64(aPrevious, 53U)) + RotL64(aCarry, 57U)) + 12756613707692514808U) + aOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = ((aWandererF + RotL64(aScatter, 35U)) + RotL64(aCarry, 21U)) + 5082475548176484035U;
            aOrbiterF = ((aWandererA + RotL64(aIngress, 26U)) + 4907435526952698526U) + aNonceWordB;
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 14236627073831834337U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 11502511046130497584U;
            aOrbiterC = RotL64((aOrbiterC * 3460330807286625917U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 3679044835550219497U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 11254838916686736746U;
            aOrbiterH = RotL64((aOrbiterH * 8631695922983532915U), 51U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterA) + 10582608424233200966U) + aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1]) + aNonceWordL;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 10449735026385340313U;
            aOrbiterI = RotL64((aOrbiterI * 7363770199734997411U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 4628253464169957835U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 17664454668473204465U;
            aOrbiterG = RotL64((aOrbiterG * 4234720298731378527U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 3798386391743884889U) + aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 1379331161819246587U;
            aOrbiterE = RotL64((aOrbiterE * 13086160171095077295U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 9816600392407327227U) + aNonceWordK;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 16781971616348376878U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12503867584828289879U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 4807797577690520554U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 2492057261148595922U;
            aOrbiterF = RotL64((aOrbiterF * 9453302540675483005U), 29U);
            //
            aIngress = RotL64(aOrbiterE, 5U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 39U));
            aIngress = aIngress + (RotL64(aOrbiterG, 46U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterC, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterG, 41U)) + aWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 43U) + aOrbiterF) + RotL64(aOrbiterC, 13U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterI, 57U)) + aOrbiterG) + RotL64(aCarry, 51U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 50U) + aOrbiterC) + RotL64(aOrbiterH, 19U));
            aWandererD = aWandererD + ((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 26U)) + aOrbiterH);
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 3U)) + aOrbiterE) + aNonceWordP) + aWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 23U) + aOrbiterA) + RotL64(aOrbiterC, 47U)) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 24U));
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + RotL64(aWandererB, 29U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 16769U)) & S_BLOCK1], 42U) ^ RotL64(aExpandLaneA[((aIndex + 22442U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 20523U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneC[((aIndex + 18589U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 11U)) + (RotL64(aCross, 23U) + RotL64(aIngress, 60U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererK + RotL64(aCross, 27U)) + 17470880031634374199U;
            aOrbiterE = (aWandererF + RotL64(aPrevious, 57U)) + 757565846006937746U;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 19U)) + RotL64(aCarry, 21U)) + 9419282475801345674U;
            aOrbiterG = (aWandererH + RotL64(aScatter, 13U)) + 2014248014107898196U;
            aOrbiterC = ((aWandererB + RotL64(aCross, 40U)) + RotL64(aCarry, 57U)) + 15113928519446490441U;
            aOrbiterK = (((aWandererD + RotL64(aPrevious, 47U)) + RotL64(aCarry, 43U)) + 7346126964886259935U) + aOrbiterAssignSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = (((aWandererG + RotL64(aScatter, 5U)) + 5594123113093162359U) + aOrbiterAssignSaltC[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordF;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 5659237263369402005U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 11565709683423969703U) ^ aOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16731289017588574671U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 16782863743534856287U) + aNonceWordD;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 13499100900072115907U;
            aOrbiterE = RotL64((aOrbiterE * 5567729598873214433U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 11414447651044205242U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 7545993795121430538U;
            aOrbiterF = RotL64((aOrbiterF * 10758488381206257261U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 11778229237616454988U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 2544793391976514665U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4021060413798523299U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 9972156716619459164U) + aOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 17651030383827445664U;
            aOrbiterC = RotL64((aOrbiterC * 6742914240706775487U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 17439147296849134543U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 10021926927948343656U;
            aOrbiterK = RotL64((aOrbiterK * 18139540407315440909U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 9309867875882669289U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 14951424455944346337U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10569523948169951309U), 29U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterK, 21U);
            aIngress = aIngress + (RotL64(aOrbiterH, 50U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + RotL64(aOrbiterG, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aScatter, 21U) + aOrbiterK) + RotL64(aOrbiterJ, 57U)) + aWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererF = aWandererF + (((((RotL64(aIngress, 3U) + aOrbiterF) + RotL64(aOrbiterH, 51U)) + RotL64(aCarry, 3U)) + aNonceWordI) + aWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 26U)) + aOrbiterG);
            aWandererB = aWandererB + ((((RotL64(aCross, 58U) + RotL64(aOrbiterG, 35U)) + aOrbiterE) + RotL64(aCarry, 37U)) + aNonceWordA);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 19U)) + aOrbiterE);
            aWandererK = aWandererK + ((RotL64(aIngress, 27U) + RotL64(aOrbiterJ, 5U)) + aOrbiterE);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 11U) + aOrbiterH) + RotL64(aOrbiterE, 11U)) + aNonceWordK);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 4U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + RotL64(aWandererG, 13U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordK;
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 26244U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((aIndex + 31261U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30363U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneD[((aIndex + 28401U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCarry, 52U)) ^ (RotL64(aCross, 37U) ^ RotL64(aIngress, 5U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 47U)) + RotL64(aCarry, 51U)) + 3621877681473089725U;
            aOrbiterJ = (aWandererE + RotL64(aCross, 41U)) + 4451752751536414717U;
            aOrbiterF = (((aWandererJ + RotL64(aIngress, 13U)) + RotL64(aCarry, 29U)) + 11371625415377772117U) + aOrbiterAssignSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = (((aWandererF + RotL64(aScatter, 57U)) + RotL64(aCarry, 11U)) + 6046792758881150619U) + aNonceWordJ;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 21U)) + 8213166120394461682U;
            aOrbiterD = (aWandererC + RotL64(aCross, 27U)) + 4343156661140422645U;
            aOrbiterG = (((aWandererK + RotL64(aScatter, 4U)) + 11105271483234947905U) + aOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordA;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 348904609985341372U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 12924652822526858767U;
            aOrbiterF = RotL64((aOrbiterF * 2801892489296408735U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 7461211697358520287U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 16551553555297890558U;
            aOrbiterD = RotL64((aOrbiterD * 16432952324635746293U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 11908056404140782995U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 9147367258259948715U;
            aOrbiterJ = RotL64((aOrbiterJ * 10777628928376261667U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 8876461054692728610U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 10546855952702525404U;
            aOrbiterH = RotL64((aOrbiterH * 10071104785895309677U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 4748636139110443794U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 783046909529525098U) ^ aOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8969157702460927215U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 16683965945838696665U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 12385412690177109575U;
            aOrbiterB = RotL64((aOrbiterB * 10795062772707143187U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 8210546822184469023U) + aOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 13146493623236979963U) ^ aNonceWordO;
            aOrbiterG = RotL64((aOrbiterG * 13199947810161148155U), 43U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 13U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 58U));
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterA, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aCross, 47U) + aOrbiterA) + RotL64(aOrbiterD, 53U)) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 20U) + RotL64(aOrbiterH, 29U)) + aOrbiterB) + aWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 13U) + aOrbiterB) + RotL64(aOrbiterF, 19U)) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterG, 42U)) + aOrbiterJ) + aWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 3U) + RotL64(aOrbiterG, 35U)) + aOrbiterH) + aNonceWordL);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 27U) + aOrbiterD) + RotL64(aOrbiterG, 3U)) + aNonceWordN);
            aWandererJ = aWandererJ + ((RotL64(aCross, 57U) + aOrbiterD) + RotL64(aOrbiterB, 11U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 58U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + RotL64(aWandererH, 37U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ aNonceWordH;
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

void TwistExpander_Soccer_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xBB9F3E7C50FD7973ULL + 0xFE92FC7B8B71668DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xB7BF473097CE5179ULL + 0xFF7E74BC5F6D361EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xDA64EE2C42079337ULL + 0xB42EAF98D7A68F7BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xF07DC9C55D5BBFB1ULL + 0x9A2CAF5639247F92ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x9FA547E2A99A3C8FULL + 0xAA5F903523B7ECBBULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xE4B36D0D9CB60527ULL + 0xC05717DBAF04DE83ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xA2AB098E9211E505ULL + 0xFB50C18A618B904BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xB2907014909F707DULL + 0xAA64CCC0C9BD79FAULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xE977526E8563E915ULL + 0xD9451899326F50DAULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xD5D36B53A05A5AE5ULL + 0xA90FEAD850DF281FULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xC1CD6E98FBC9109BULL + 0x8A686757EAFDD1B7ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xB1F79BE6702DF5C5ULL + 0xD0D1CAFAA90E0854ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xD886FF0C4A873C31ULL + 0xBEDBB34D41622F11ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xB5506E021ADBDB09ULL + 0xECC0DF81198B2B19ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xD66152A312B20F97ULL + 0xD01EAC42F9814C27ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xF364CCE83ECC4D17ULL + 0xB0BB3AADC349B5D0ULL);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 3632U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4341U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6660U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 7369U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aIngress, 58U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 41U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererA + RotL64(aIngress, 10U)) + 3917730204724097072U;
            aOrbiterB = ((aWandererK + RotL64(aCross, 35U)) + RotL64(aCarry, 3U)) + 1874642340716212824U;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 19U)) + 6900165757434854160U) + aOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 27U)) + 12750946097023807161U) + aNonceWordN;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 29U)) + RotL64(aCarry, 27U)) + 6563216048479513594U;
            aOrbiterH = (aWandererE + RotL64(aCross, 21U)) + 14960240191349450795U;
            aOrbiterE = ((aWandererD + RotL64(aIngress, 39U)) + RotL64(aCarry, 13U)) + 16306180275951788289U;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 53U)) + 6502066618271045547U) + aOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aIngress, 44U)) + 6219852857850888738U) + aNonceWordF;
            aOrbiterA = (aWandererB + RotL64(aScatter, 57U)) + 2272931312452845850U;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 51U)) + 3028929882263199463U) + aNonceWordO;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 6067393030073568112U) + aNonceWordE;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 10094809900437037258U;
            aOrbiterJ = RotL64((aOrbiterJ * 18095564940730322769U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 5962414178157074575U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 15755563045799129417U;
            aOrbiterH = RotL64((aOrbiterH * 3692603590609922031U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 6321455513889880590U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 1197435601998121700U;
            aOrbiterG = RotL64((aOrbiterG * 17693996266260557625U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 12496949381666299968U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 6357070235648527030U;
            aOrbiterK = RotL64((aOrbiterK * 2931486644220862433U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 8423760160877540210U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 8090246492554850768U;
            aOrbiterE = RotL64((aOrbiterE * 2949407491181921633U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 11436635942985063755U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 17086363141014359856U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10504127577318206801U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 10734017887545474935U) + aNonceWordB;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 375515325165740779U) ^ aOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9980486695448151709U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 5217148491945389821U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 14696058217023530058U;
            aOrbiterB = RotL64((aOrbiterB * 11026674782236654799U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 11869055287836412650U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 16951500118659983436U;
            aOrbiterI = RotL64((aOrbiterI * 4304372681583055077U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 7866300390953569803U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 18017335943787362993U;
            aOrbiterF = RotL64((aOrbiterF * 15683049583437004889U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 2477944286851267725U) + aNonceWordM;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 3917730204724097072U;
            aOrbiterA = RotL64((aOrbiterA * 6617615984203047419U), 57U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterA, 35U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 28U));
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + RotL64(aOrbiterF, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 5U)) + aOrbiterJ) + aNonceWordA);
            aWandererA = aWandererA + (((RotL64(aIngress, 43U) + RotL64(aOrbiterD, 37U)) + aOrbiterB) + aWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 18U) + RotL64(aOrbiterG, 34U)) + aOrbiterC);
            aWandererE = aWandererE + (((RotL64(aPrevious, 39U) + aOrbiterB) + RotL64(aOrbiterG, 23U)) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterI, 57U)) + aOrbiterD);
            aWandererF = aWandererF + (((RotL64(aCross, 29U) + RotL64(aOrbiterF, 53U)) + aOrbiterJ) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 46U) + aOrbiterA) + RotL64(aOrbiterK, 39U)) + aNonceWordH);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 21U)) + aOrbiterE) + aWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterJ, 29U)) + aOrbiterK);
            aWandererC = aWandererC + ((RotL64(aPrevious, 53U) + aOrbiterF) + RotL64(aOrbiterH, 10U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterG, 43U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 50U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 20U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 8352U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9581U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8402U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneB[((aIndex + 10961U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 47U) + RotL64(aCarry, 35U)) + (RotL64(aCross, 22U) ^ RotL64(aIngress, 3U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererC + RotL64(aPrevious, 21U)) + 6024062041314952357U;
            aOrbiterD = ((aWandererH + RotL64(aIngress, 3U)) + RotL64(aCarry, 39U)) + 18340757093658015585U;
            aOrbiterG = (aWandererJ + RotL64(aCross, 47U)) + 11911120493880346751U;
            aOrbiterC = (((aWandererA + RotL64(aScatter, 52U)) + 17428074353884654439U) + aOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1]) + aNonceWordG;
            aOrbiterH = ((aWandererB + RotL64(aCross, 23U)) + RotL64(aCarry, 5U)) + 12790849760814795936U;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 41U)) + RotL64(aCarry, 23U)) + 12633397052172117800U;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 39U)) + 11946150433665237945U;
            aOrbiterK = (aWandererF + RotL64(aIngress, 60U)) + 16842157900909419285U;
            aOrbiterE = (aWandererI + RotL64(aPrevious, 13U)) + 14186235783224155962U;
            aOrbiterA = (aWandererD + RotL64(aScatter, 57U)) + 13284904542579767591U;
            aOrbiterB = ((aWandererK + RotL64(aCross, 37U)) + 11609181965078844357U) + aOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 9628562297095374984U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 7850281529011259759U;
            aOrbiterG = RotL64((aOrbiterG * 17611485102925470357U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 257458718073794527U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 10693404545773519306U;
            aOrbiterD = RotL64((aOrbiterD * 14821443722828498323U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 3430519236533871460U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 6183054506953198055U) ^ aNonceWordP;
            aOrbiterH = RotL64((aOrbiterH * 6121082743789970911U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 2905610989884221654U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 4472163910775333862U;
            aOrbiterF = RotL64((aOrbiterF * 7770678426310856745U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 16870142883133769663U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 1403692060594816451U;
            aOrbiterE = RotL64((aOrbiterE * 9740854430251597879U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 16904169913507057108U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 4773518591580333357U;
            aOrbiterI = RotL64((aOrbiterI * 5306070307776061267U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 6528141733853494275U) + aNonceWordH;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 11254806909313951442U;
            aOrbiterC = RotL64((aOrbiterC * 6316669786405548827U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 6857506858448143407U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 2855763534355983644U;
            aOrbiterJ = RotL64((aOrbiterJ * 16881334940165182415U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 12328391751024624740U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 16475072086109949522U;
            aOrbiterK = RotL64((aOrbiterK * 15218626930666825883U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 15505670341076785424U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 6972128419331939330U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12206069109180246067U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 7151546362283646210U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterE) ^ 6024062041314952357U) ^ aOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 10243806128059850493U), 57U);
            //
            aIngress = RotL64(aOrbiterF, 37U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterA, 20U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterE, 23U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 53U));
            aIngress = aIngress + RotL64(aOrbiterD, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 19U) + aOrbiterE) + RotL64(aOrbiterG, 29U));
            aWandererK = aWandererK + ((((RotL64(aCross, 27U) + aOrbiterD) + RotL64(aOrbiterK, 57U)) + RotL64(aCarry, 21U)) + aWandererUpdateSaltD[((aIndex + 20U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterB, 54U)) + aOrbiterI) + aNonceWordD);
            aWandererH = aWandererH + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterG, 27U)) + aOrbiterF) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterF, 47U)) + aNonceWordF);
            aWandererF = aWandererF + (((RotL64(aPrevious, 58U) + RotL64(aOrbiterF, 35U)) + aOrbiterJ) + aNonceWordO);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterJ, 39U)) + aOrbiterH);
            aWandererD = aWandererD + ((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterI, 5U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 41U) + aOrbiterF) + RotL64(aOrbiterA, 21U));
            aWandererE = aWandererE + ((RotL64(aScatter, 39U) + aOrbiterC) + RotL64(aOrbiterK, 44U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 10U) + RotL64(aOrbiterE, 3U)) + aOrbiterB) + aWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 42U));
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 10U);
            aCarry = aCarry ^ aNonceWordB;
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 22158U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 21561U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18962U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 24266U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 52U) ^ RotL64(aCross, 39U)) ^ (RotL64(aPrevious, 27U) + RotL64(aCarry, 5U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererA + RotL64(aIngress, 53U)) + 4739486756133131180U;
            aOrbiterC = (((aWandererI + RotL64(aScatter, 58U)) + RotL64(aCarry, 53U)) + 16089707555501328184U) + aNonceWordO;
            aOrbiterF = (aWandererF + RotL64(aCross, 43U)) + 15310047330238536453U;
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 47U)) + RotL64(aCarry, 39U)) + 7901411596386834955U;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 29U)) + 4357555491060982163U) + aOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (aWandererD + RotL64(aScatter, 22U)) + 15667085602825720102U;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 35U)) + 8520635334382269253U) + aNonceWordL;
            aOrbiterJ = ((aWandererK + RotL64(aCross, 5U)) + 1772509779231068315U) + aOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 37U)) + 15336170957886025677U;
            aOrbiterG = ((aWandererG + RotL64(aCross, 19U)) + RotL64(aCarry, 5U)) + 8628770833489469980U;
            aOrbiterD = (aWandererB + RotL64(aIngress, 11U)) + 15469234024247246228U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 10796430900884288328U) + aOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 10660110397012853289U;
            aOrbiterF = RotL64((aOrbiterF * 9140007610912037461U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 11202284258711214794U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 17509491802893182994U) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 9329107599972703671U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 16212572740740103554U) + aNonceWordG;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 2190030203761579226U;
            aOrbiterC = RotL64((aOrbiterC * 3101886685668871045U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 12014337082293041909U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 3733531010807001506U;
            aOrbiterK = RotL64((aOrbiterK * 5797362244066062299U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 7100994963061975529U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 17837541162838600258U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8745987361678166553U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 3311518938023146951U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 7709505172646831553U;
            aOrbiterG = RotL64((aOrbiterG * 7121143171245765213U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 4979968094554018443U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 16822214821463034107U;
            aOrbiterH = RotL64((aOrbiterH * 8618262120451291765U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 8376124175020587079U) + aOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 11084586282092424876U;
            aOrbiterA = RotL64((aOrbiterA * 5835632742522563537U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 7816368455027681621U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 10893292019060642422U;
            aOrbiterI = RotL64((aOrbiterI * 3995821210667317677U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 13602875505184178486U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 5425735673005681983U;
            aOrbiterE = RotL64((aOrbiterE * 12667085597129312079U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 5995385043278810987U) + aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 4739486756133131180U) ^ aNonceWordF;
            aOrbiterD = RotL64((aOrbiterD * 15709273328685013399U), 23U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterE, 50U);
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterF, 53U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterK, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterC, 30U)) + aOrbiterA) + RotL64(aCarry, 51U)) + aWandererUpdateSaltA[((aIndex + 8U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 54U) + RotL64(aOrbiterK, 35U)) + aOrbiterA);
            aWandererG = aWandererG + (((RotL64(aIngress, 19U) + RotL64(aOrbiterG, 13U)) + aOrbiterJ) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 41U) + aOrbiterD) + RotL64(aOrbiterG, 51U));
            aWandererI = aWandererI + ((RotL64(aScatter, 21U) + aOrbiterI) + RotL64(aOrbiterE, 18U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterH, 39U)) + aOrbiterK);
            aWandererH = aWandererH + (((RotL64(aPrevious, 12U) + aOrbiterF) + RotL64(aOrbiterI, 5U)) + aNonceWordC);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterH, 3U)) + aOrbiterC) + aWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterG, 37U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterJ, 43U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 37U) + aOrbiterB) + RotL64(aOrbiterF, 23U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 41U));
            aCarry = aCarry + (RotL64(aWandererE, 58U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererC, 11U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordF);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 30807U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30604U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29198U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 24767U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 26U) ^ RotL64(aCarry, 41U)) ^ (RotL64(aCross, 5U) + RotL64(aIngress, 57U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererC + RotL64(aScatter, 51U)) + 15383045568644941552U;
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 46U)) + 17452811657750910067U) + aOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = (((aWandererF + RotL64(aCross, 5U)) + 15660117718455155603U) + aOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordA;
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 53U)) + RotL64(aCarry, 41U)) + 10396441207743665753U;
            aOrbiterB = ((aWandererE + RotL64(aScatter, 3U)) + RotL64(aCarry, 51U)) + 3708971058200841442U;
            aOrbiterG = (aWandererD + RotL64(aIngress, 43U)) + 7000673057768598750U;
            aOrbiterC = ((aWandererA + RotL64(aCross, 27U)) + 9886354469011131596U) + aNonceWordB;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 21U)) + RotL64(aCarry, 23U)) + 16018065329058043467U;
            aOrbiterA = (aWandererB + RotL64(aCross, 36U)) + 5024756166109352320U;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 11U)) + 6587818720728886652U;
            aOrbiterF = (aWandererI + RotL64(aIngress, 23U)) + 3652672354944162319U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 6307315649915348048U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 16405347331742979258U;
            aOrbiterE = RotL64((aOrbiterE * 7183142442906743699U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 5427299664054601957U) + aNonceWordI;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 4983381733483185898U;
            aOrbiterB = RotL64((aOrbiterB * 14646556236306407673U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 10182995521328377487U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 8694282877540593550U;
            aOrbiterG = RotL64((aOrbiterG * 14614602561910403893U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 4085927978153269932U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 6176195962815240877U) ^ aOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16792916528959579875U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 6966742100601433005U) + aOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 9920952446921247521U;
            aOrbiterD = RotL64((aOrbiterD * 1879821050131820933U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 11958734477518336014U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 2058335903640404380U;
            aOrbiterA = RotL64((aOrbiterA * 6986170159285417789U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 77366119537297816U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 12072894199692855000U;
            aOrbiterH = RotL64((aOrbiterH * 9083781120514635987U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 11874297832446385377U) + aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 13715562531763053196U;
            aOrbiterF = RotL64((aOrbiterF * 12822488258322963187U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 13664465415354326653U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 10365386643010882315U;
            aOrbiterK = RotL64((aOrbiterK * 3687934567254955761U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 2003863843075564853U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 8864134110143237364U) ^ aOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4586162015675320985U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 8055736412403126985U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 15383045568644941552U;
            aOrbiterJ = RotL64((aOrbiterJ * 5175405553995854715U), 53U);
            //
            aIngress = RotL64(aOrbiterG, 19U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 39U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 60U));
            aIngress = aIngress + RotL64(aOrbiterB, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterD, 13U)) + RotL64(aCarry, 39U)) + aNonceWordO) + aWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 51U) + aOrbiterJ) + RotL64(aOrbiterE, 35U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 6U) + aOrbiterI) + RotL64(aOrbiterD, 43U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 47U) + aOrbiterH) + RotL64(aOrbiterJ, 37U)) + aWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 43U) + aOrbiterF) + RotL64(aOrbiterE, 28U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterK, 5U)) + aOrbiterB);
            aWandererC = aWandererC + (((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 26U) + aOrbiterC) + RotL64(aOrbiterJ, 11U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterH, 51U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 37U) + aOrbiterC) + RotL64(aOrbiterG, 48U));
            aWandererK = aWandererK + ((RotL64(aCross, 21U) + aOrbiterF) + RotL64(aOrbiterJ, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 30U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + (RotL64(aWandererB, 21U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererG, 18U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordF;
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

void TwistExpander_Soccer_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xAA0D74E60FDB7C9DULL + 0x943950939AFAF40AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xA8BD469E0C648A75ULL + 0xA0A6375A4CE47699ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x894AB2CCE8A4F0FFULL + 0xA60DD8441DB6B93FULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xB95003F25CEBF91BULL + 0xEFDDC4903DE79D92ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xDD66482ADDA37CAFULL + 0xA7E88FEFA0DC4A3BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x917EF182F96941CDULL + 0xC42545F0557706E0ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xC70C02E606B2FD85ULL + 0xE5E207145021D4D4ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE7F47A429659014DULL + 0xB4FD581AA1337C2AULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xAF94AA75BE1ABDC9ULL + 0x8BC130844FB73D3AULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xE1960BC7234C8B39ULL + 0xC64B5E29966DB1A2ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xDE53577C4215E50FULL + 0xE280B1AFA670FBAEULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xF51BE6CDAA07D391ULL + 0x82718EB970B08BC9ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x87C5489515F53DE3ULL + 0xC1741392C246D407ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x9A9C4F6FB2BA1E5BULL + 0xA2F54970FE5EA20AULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x8D2326CA14A4471BULL + 0x918B178E31D82B56ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xC3CD884E43839969ULL + 0xCE651021F81CE4C7ULL);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 1797U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneC[((aIndex + 3276U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 3544U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneA[((aIndex + 1090U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 54U)) ^ (RotL64(aCross, 3U) + RotL64(aIngress, 21U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererG + RotL64(aCross, 57U)) + RotL64(aCarry, 41U)) + 15910560457440369082U;
            aOrbiterB = (aWandererJ + RotL64(aIngress, 43U)) + 17953072986407436888U;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 47U)) + 15446940721193538669U) + aNonceWordC;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 10U)) + RotL64(aCarry, 5U)) + 3020785262774422009U;
            aOrbiterJ = (aWandererK + RotL64(aCross, 19U)) + 7001288645424994404U;
            aOrbiterG = ((((aWandererF + RotL64(aScatter, 29U)) + RotL64(aCarry, 19U)) + 13385250665458462689U) + aOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordN;
            aOrbiterF = ((aWandererA + RotL64(aIngress, 3U)) + 4841895644623005949U) + aNonceWordI;
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 39U)) + 13053476783239482065U) + aOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = (aWandererE + RotL64(aIngress, 14U)) + 641996979335975244U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 16211238020928688299U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 12715448751323279480U;
            aOrbiterE = RotL64((aOrbiterE * 2116880429675303291U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 17784406727699995290U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 16626339815786580778U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13940754474750138041U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 9035070625716345139U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 6085848172494001945U;
            aOrbiterA = RotL64((aOrbiterA * 10405728912339646693U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 1177103851507561053U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 2281901691017816407U;
            aOrbiterK = RotL64((aOrbiterK * 3142197009403602497U), 47U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterA) + 9040984343694325070U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordH;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 13334258224023902365U;
            aOrbiterD = RotL64((aOrbiterD * 4782523727707164869U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 1079824790138592518U) + aNonceWordO;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 14024082692012948652U;
            aOrbiterH = RotL64((aOrbiterH * 3219489374333737903U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 2966776524421278970U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 5510281854029308547U) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 9275402927591867297U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 7126632329316720048U) + aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 1476827035602733472U;
            aOrbiterB = RotL64((aOrbiterB * 2217671289726794033U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 6470212302133184965U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 4172257438373147415U;
            aOrbiterJ = RotL64((aOrbiterJ * 4449314239630366533U), 13U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterA, 51U);
            aIngress = aIngress + (RotL64(aOrbiterD, 10U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterB, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 60U) + RotL64(aOrbiterJ, 6U)) + aOrbiterH) + aWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 27U) + aOrbiterB) + RotL64(aOrbiterK, 47U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterA, 29U)) + aOrbiterD);
            aWandererF = aWandererF + ((RotL64(aIngress, 51U) + RotL64(aOrbiterK, 19U)) + aOrbiterE);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 4U) + RotL64(aOrbiterG, 52U)) + aOrbiterB);
            aWandererK = aWandererK + (((RotL64(aCross, 13U) + RotL64(aOrbiterE, 37U)) + aOrbiterG) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterD, 41U)) + aOrbiterE);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterH, 23U)) + RotL64(aCarry, 43U)) + aNonceWordD);
            aWandererE = aWandererE ^ (((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterG, 11U)) + aWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 18U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 26U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordJ);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8760U)) & S_BLOCK1], 36U) ^ RotL64(aOperationLaneD[((aIndex + 6539U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 6388U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((aIndex + 7647U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 52U) + RotL64(aCarry, 19U)) ^ (RotL64(aIngress, 5U) ^ RotL64(aCross, 39U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererC + RotL64(aScatter, 19U)) + 2974056819475622600U;
            aOrbiterE = (aWandererI + RotL64(aPrevious, 54U)) + 7345051759236356098U;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 13U)) + 12738468816846628882U) + aNonceWordG;
            aOrbiterK = (aWandererG + RotL64(aCross, 43U)) + 7694520596043297922U;
            aOrbiterD = (((aWandererF + RotL64(aPrevious, 35U)) + RotL64(aCarry, 3U)) + 5530753590015084774U) + aOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aScatter, 23U)) + RotL64(aCarry, 53U)) + 3776309161718383105U;
            aOrbiterA = (((aWandererK + RotL64(aIngress, 27U)) + RotL64(aCarry, 13U)) + 784780304358106404U) + aNonceWordJ;
            aOrbiterH = ((aWandererE + RotL64(aCross, 39U)) + 8999942326995036509U) + aNonceWordB;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 48U)) + 5194986506064092779U) + aOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 7920040007459652762U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 11311997270710107937U) ^ aOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6227571709361790209U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 5365231114813547251U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 8630110234623825263U;
            aOrbiterD = RotL64((aOrbiterD * 2735881715888325759U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 2358235238039571072U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterB) ^ 18059414891616491807U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterA = RotL64((aOrbiterA * 17150786106857185467U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 14526050556461782864U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 6937282036603272474U;
            aOrbiterH = RotL64((aOrbiterH * 14954512365270028029U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 10105832250694931310U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 3884223553012098137U;
            aOrbiterG = RotL64((aOrbiterG * 16340956813003906195U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 10385284339549648087U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 1257633893341505930U;
            aOrbiterF = RotL64((aOrbiterF * 2669950791270500977U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 5528890519572824318U) + aNonceWordL;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 15664241747527713256U) ^ aOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16670884497088220497U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 14264122979415331887U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 17985061405540198036U;
            aOrbiterB = RotL64((aOrbiterB * 2729487440173395133U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 1663986734997903415U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 3706166884286400587U;
            aOrbiterE = RotL64((aOrbiterE * 10549736618301955745U), 19U);
            //
            aIngress = RotL64(aOrbiterH, 3U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 37U));
            aIngress = aIngress + (RotL64(aOrbiterE, 30U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterF, 23U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 34U)) + aOrbiterH) + aNonceWordI);
            aWandererB = aWandererB + (((RotL64(aCross, 54U) + aOrbiterC) + RotL64(aOrbiterF, 47U)) + aWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterC, 39U)) + aOrbiterH);
            aWandererG = aWandererG + ((RotL64(aIngress, 39U) + RotL64(aOrbiterD, 3U)) + aOrbiterK);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 27U)) + aOrbiterB);
            aWandererF = aWandererF + (((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 51U)) + aOrbiterH) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 12U)) + aOrbiterG) + aNonceWordN) + aWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 12U) + aOrbiterB) + RotL64(aOrbiterG, 19U)) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterF, 23U)) + aNonceWordA);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 6U));
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + RotL64(aWandererF, 51U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = aCarry ^ aNonceWordK;
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13714U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12884U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 11957U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 16157U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCross, 52U)) ^ (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 35U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((((aWandererC + RotL64(aScatter, 27U)) + RotL64(aCarry, 11U)) + 5568146815535263910U) + aOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1]) + aNonceWordL;
            aOrbiterA = (aWandererJ + RotL64(aCross, 11U)) + 7736084960873834666U;
            aOrbiterK = (aWandererH + RotL64(aIngress, 60U)) + 1336413621817562093U;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 19U)) + 5218462026934984692U;
            aOrbiterC = ((aWandererF + RotL64(aCross, 41U)) + 7048890985969555935U) + aOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = (((aWandererE + RotL64(aPrevious, 23U)) + RotL64(aCarry, 39U)) + 13415955213864702118U) + aNonceWordD;
            aOrbiterI = (aWandererB + RotL64(aScatter, 56U)) + 5657023257021528548U;
            aOrbiterE = (aWandererD + RotL64(aIngress, 5U)) + 14338310943137497116U;
            aOrbiterG = ((aWandererI + RotL64(aCross, 37U)) + RotL64(aCarry, 27U)) + 12305161641833950473U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 14514226578370459131U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 12692904083266024340U) ^ aNonceWordJ;
            aOrbiterK = RotL64((aOrbiterK * 14800805065279908839U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 11012959130001327964U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 7106471380403489078U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 515626559384817223U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 3718101961355280891U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 13364192077222322664U;
            aOrbiterJ = RotL64((aOrbiterJ * 1411328915372590283U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 6720867800318913440U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 14497243926965866546U;
            aOrbiterA = RotL64((aOrbiterA * 13595058589060114653U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 5789056168233262435U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 14438482587495779937U;
            aOrbiterC = RotL64((aOrbiterC * 10593535547917767263U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 313917798940179945U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 15241845511889502917U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16483477103771326107U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 3591957424821693032U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 1559050939014453558U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17933346117866604725U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 15340590914441451383U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 5538037287390050110U;
            aOrbiterE = RotL64((aOrbiterE * 4082576643144951473U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 4151270491894969214U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 263593701314144898U;
            aOrbiterG = RotL64((aOrbiterG * 10372046955804512457U), 29U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterI, 47U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 23U));
            aIngress = aIngress + (RotL64(aOrbiterF, 18U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 28U) + RotL64(aOrbiterF, 13U)) + aOrbiterG);
            aWandererD = aWandererD + (((RotL64(aScatter, 57U) + RotL64(aOrbiterA, 42U)) + aOrbiterI) + aWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterG, 29U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 53U)) + aOrbiterK) + RotL64(aCarry, 37U)) + aNonceWordO);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 51U) + aOrbiterK) + RotL64(aOrbiterI, 5U)) + aNonceWordG);
            aWandererE = aWandererE + (((RotL64(aIngress, 23U) + aOrbiterK) + RotL64(aOrbiterA, 60U)) + aNonceWordP);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 47U) + aOrbiterC) + RotL64(aOrbiterE, 23U));
            aWandererB = aWandererB + (((RotL64(aCross, 40U) + RotL64(aOrbiterI, 35U)) + aOrbiterE) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterB, 47U)) + aOrbiterE) + aWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 18U));
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererE, 43U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ aNonceWordJ;
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 21544U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((aIndex + 20502U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19439U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 19615U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aIngress, 37U)) ^ (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 54U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (aWandererF + RotL64(aCross, 27U)) + 8604208734152026945U;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 57U)) + 1374329953253889829U) + aNonceWordK;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 44U)) + RotL64(aCarry, 43U)) + 5779278910548228339U;
            aOrbiterH = (aWandererC + RotL64(aPrevious, 13U)) + 17670451230882805140U;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 5U)) + RotL64(aCarry, 27U)) + 8193848740764866860U;
            aOrbiterI = (((aWandererH + RotL64(aPrevious, 53U)) + RotL64(aCarry, 35U)) + 15801168428145650104U) + aOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 39U)) + 2584718176087499066U) + aNonceWordG;
            aOrbiterD = ((aWandererE + RotL64(aIngress, 18U)) + 14950366247822737997U) + aOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = (aWandererI + RotL64(aScatter, 35U)) + 9779293225265670135U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 8688968319288372383U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 13665723186950342601U;
            aOrbiterE = RotL64((aOrbiterE * 292035540396910837U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 9395428688359973510U) + aNonceWordM;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 2152719218018108418U;
            aOrbiterF = RotL64((aOrbiterF * 15271961483518392671U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 1350324137411377992U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 8729317951386057921U;
            aOrbiterJ = RotL64((aOrbiterJ * 6008790836417785083U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 6317310451893678411U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 10175620379041384281U) ^ aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14079679617394330781U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 1203082119358827708U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 523869107818193101U;
            aOrbiterH = RotL64((aOrbiterH * 4629501113595689157U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 4028324959540432983U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 15447631947468213912U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6037306615787729185U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 14225888694733041031U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 11925000696281947629U;
            aOrbiterD = RotL64((aOrbiterD * 4337022940520411253U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 15015531024930608745U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 16752579225076943550U) ^ aOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15551083683579981439U), 5U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterK) + 2432733494869267901U) + aOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1]) + aNonceWordF;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 10103430321388601485U;
            aOrbiterB = RotL64((aOrbiterB * 18372919379972432569U), 35U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterK, 38U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 41U) + aOrbiterB) + RotL64(aOrbiterE, 38U));
            aWandererE = aWandererE + (((RotL64(aIngress, 60U) + RotL64(aOrbiterI, 51U)) + aOrbiterA) + aNonceWordA);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterA, 19U)) + aOrbiterD);
            aWandererG = aWandererG + (((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterI, 43U)) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 11U) + aOrbiterI) + RotL64(aOrbiterE, 29U));
            aWandererI = aWandererI + (((RotL64(aIngress, 20U) + aOrbiterJ) + RotL64(aOrbiterA, 47U)) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterF, 13U)) + aWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 51U) + aOrbiterB) + RotL64(aOrbiterH, 24U)) + aWandererUpdateSaltB[((aIndex + 28U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterB, 57U)) + aNonceWordJ);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = aCarry ^ aNonceWordP;
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 25877U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 26659U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25835U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneA[((aIndex + 25139U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCarry, 51U)) + (RotL64(aPrevious, 4U) ^ RotL64(aCross, 23U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererF + RotL64(aCross, 39U)) + 17711946802293254150U) + aNonceWordA;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 13U)) + 16652362590489569378U) + aNonceWordN;
            aOrbiterD = (aWandererG + RotL64(aScatter, 57U)) + 6972810344198183097U;
            aOrbiterH = (((aWandererD + RotL64(aPrevious, 22U)) + RotL64(aCarry, 3U)) + 13117100889782940546U) + aOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 51U)) + 13199305696782626591U) + aOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = (aWandererC + RotL64(aPrevious, 47U)) + 992156184392760945U;
            aOrbiterK = (aWandererE + RotL64(aIngress, 35U)) + 13791265442074543880U;
            aOrbiterB = ((aWandererB + RotL64(aCross, 4U)) + RotL64(aCarry, 27U)) + 17057087245252294859U;
            aOrbiterI = ((aWandererH + RotL64(aIngress, 43U)) + RotL64(aCarry, 13U)) + 13444195995883541046U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 6723678233676059420U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 7913379431208430475U;
            aOrbiterD = RotL64((aOrbiterD * 2295062944289127123U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 4481887195529300665U) + aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 11892724101424384078U;
            aOrbiterC = RotL64((aOrbiterC * 3468639499716604111U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 7700902083270424194U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 1888001433557140271U;
            aOrbiterB = RotL64((aOrbiterB * 8975562955027025349U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 14996753906788986929U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 939004845422123765U) ^ aNonceWordL;
            aOrbiterI = RotL64((aOrbiterI * 2507090308972292313U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 11922230289291941807U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 15681187459741147199U;
            aOrbiterF = RotL64((aOrbiterF * 10124947739653819101U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 9119043713532718155U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 8327697433992362166U;
            aOrbiterH = RotL64((aOrbiterH * 11157657162184304567U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 13630755116592440359U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 771252613886022889U) ^ aOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2958918915223536519U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 8524239721467527770U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 17732617735422435572U;
            aOrbiterG = RotL64((aOrbiterG * 13992947983987668631U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 5265753270696005619U) + aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 14456128349522985053U;
            aOrbiterJ = RotL64((aOrbiterJ * 5406509991740849617U), 19U);
            //
            aIngress = RotL64(aOrbiterD, 51U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 43U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 60U));
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 38U) + RotL64(aOrbiterB, 47U)) + aOrbiterF) + aNonceWordD);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 27U)) + aOrbiterJ) + aNonceWordC);
            aWandererD = aWandererD + (((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterC, 10U)) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterK, 3U));
            aWandererG = aWandererG + (((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterC, 43U)) + RotL64(aCarry, 13U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterG, 19U)) + aWandererUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterG, 52U)) + aOrbiterJ) + aNonceWordH);
            aWandererH = aWandererH ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterK, 39U)) + aOrbiterI) + aWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 60U) + aOrbiterD) + RotL64(aOrbiterI, 57U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 14U));
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30906U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((aIndex + 28543U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29752U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27555U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCarry, 41U)) ^ (RotL64(aPrevious, 27U) + RotL64(aCross, 56U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (((aWandererH + RotL64(aIngress, 12U)) + RotL64(aCarry, 5U)) + 6069475454765660321U) + aNonceWordM;
            aOrbiterE = (aWandererG + RotL64(aCross, 47U)) + 11483704742497268068U;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 35U)) + 11055697447388986418U) + aOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aScatter, 29U)) + 10897095046039997004U;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 43U)) + 4731637118230457840U) + aNonceWordA;
            aOrbiterJ = (((aWandererE + RotL64(aCross, 51U)) + RotL64(aCarry, 47U)) + 13855839187084986751U) + aNonceWordO;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 21U)) + 5328208115460188239U;
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 56U)) + 12479538544291412985U) + aOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = (aWandererB + RotL64(aCross, 23U)) + 10740165998792608231U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 6492798157284955373U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 13056825957483891921U;
            aOrbiterH = RotL64((aOrbiterH * 14882112110627751751U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 2068184064919194657U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 5656302738780746294U;
            aOrbiterG = RotL64((aOrbiterG * 16493021179127646345U), 11U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterG) + 11193756120230763294U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordI;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 17306750816837208999U;
            aOrbiterF = RotL64((aOrbiterF * 7949360041241439741U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 12952818800389361804U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 15380412293642628312U;
            aOrbiterI = RotL64((aOrbiterI * 2914662289178925547U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 7706090204767242996U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 14598802276412649570U;
            aOrbiterC = RotL64((aOrbiterC * 4821408736292041399U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 17819762117328075515U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 6481384240915075101U;
            aOrbiterD = RotL64((aOrbiterD * 4836701121865783029U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 754936290510338717U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 15510875946573720154U) ^ aOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2994718968852184303U), 35U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterA) + 9245381722813944586U) + aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1]) + aNonceWordK;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 2629847912019726214U) ^ aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6718795794951106961U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 3909987749797113773U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 9277056074757335265U;
            aOrbiterE = RotL64((aOrbiterE * 11580847505996697115U), 47U);
            //
            aIngress = RotL64(aOrbiterC, 53U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterE, 60U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + RotL64(aOrbiterG, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 30U) + aOrbiterI) + RotL64(aOrbiterA, 18U)) + aNonceWordG);
            aWandererC = aWandererC ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterF, 51U)) + aOrbiterD) + aWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 39U) + aOrbiterH) + RotL64(aOrbiterE, 3U)) + aNonceWordB) + aWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 53U) + aOrbiterF) + RotL64(aOrbiterI, 11U));
            aWandererG = aWandererG + ((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 43U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 48U) + RotL64(aOrbiterD, 22U)) + aOrbiterH);
            aWandererF = aWandererF + (((RotL64(aScatter, 23U) + RotL64(aOrbiterE, 37U)) + aOrbiterI) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterD, 47U)) + aOrbiterG);
            aWandererE = aWandererE + (((RotL64(aIngress, 43U) + RotL64(aOrbiterG, 57U)) + aOrbiterJ) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + (RotL64(aWandererK, 48U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 11U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordB);
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

void TwistExpander_Soccer_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x95248A30D9FAE1E9ULL + 0xD2BC4A501D3F13ECULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xC2474ED3860FFD63ULL + 0xDA6FD6096FA7DDADULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x9DAE720AA545C0E7ULL + 0x92A29FF0955CFF2CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xEB6E28CA215D5461ULL + 0x906BC43A4881B443ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xE7FE70EFE74E67D5ULL + 0x90DB6A4B34EE714DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xFD921EABEFD4A1BDULL + 0xBCACDCF620629CD5ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x87BDF888BE06834BULL + 0xB996E74410E21DCAULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xEE984F69C81A017BULL + 0xD498CCA489CBDCC8ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xD9847BE1E28EA5DBULL + 0xFC478BB49DCEFDF0ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xE185055DD2FA0533ULL + 0xBC4E166D3307C93FULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xA8B8DE33E6755A99ULL + 0x8BB084CE690B61E3ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xF03F8ED7D3AA106FULL + 0xE8FFA35D0D1D92A9ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x911CAEAF76B895D5ULL + 0x8CCEBE5EC26A0A47ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xB7C0E01E70645727ULL + 0x8EBF97B7BBBB22DCULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xCBDD210DFFD1B2FDULL + 0xA4002471B307BB3FULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xAA70D032FF7AF975ULL + 0xE4A45747C096744AULL);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 1325U)) & S_BLOCK1], 40U) ^ RotL64(aKeyRowReadA[((aIndex + 5125U)) & W_KEY1], 53U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 2385U)) & W_KEY1], 57U) ^ RotL64(mSource[((aIndex + 1676U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 20U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCarry, 41U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterI = ((aWandererH + RotL64(aScatter, 5U)) + RotL64(aCarry, 53U)) + 2168513956284366370U;
            aOrbiterJ = (((aWandererF + RotL64(aIngress, 47U)) + RotL64(aCarry, 5U)) + 10290361969974613111U) + aNonceWordI;
            aOrbiterA = (((aWandererC + RotL64(aCross, 35U)) + 15673836275828498050U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordA;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 11U)) + RotL64(aCarry, 21U)) + 16600540024145812236U;
            aOrbiterK = (aWandererG + RotL64(aIngress, 60U)) + 9428052101528111892U;
            aOrbiterD = ((aWandererI + RotL64(aScatter, 53U)) + 12763657928312763377U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = (aWandererD + RotL64(aCross, 19U)) + 10751286982008662485U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 1708230173038057979U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterI) ^ 4011389705422783816U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterA = RotL64((aOrbiterA * 11692237130784795961U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 11704428328093077714U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 2055336619674699284U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6374289210096410907U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 1870865272102705804U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 3574214263751923179U;
            aOrbiterD = RotL64((aOrbiterD * 13132083406834413563U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 984611970726966186U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 15207945449947643672U;
            aOrbiterE = RotL64((aOrbiterE * 9539470161576639981U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 4181398506373973169U) + aNonceWordL;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 15222345431506025949U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6925143692628659467U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 15023513452326240962U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 14965669361708810699U;
            aOrbiterF = RotL64((aOrbiterF * 587008860996713147U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 7985755518735406360U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 225592097619240187U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2313509354133400439U), 5U);
            //
            aIngress = RotL64(aOrbiterF, 19U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterK, 54U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 21U)) + aOrbiterD);
            aWandererB = aWandererB + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterE, 13U)) + aOrbiterI) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterK, 47U)) + aOrbiterF) + aNonceWordF);
            aWandererF = aWandererF + ((((RotL64(aIngress, 60U) + RotL64(aOrbiterE, 41U)) + aOrbiterK) + RotL64(aCarry, 35U)) + aNonceWordG);
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterA, 56U)) + aOrbiterD) + aNonceWordC) + aPhaseAWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterF, 35U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterD, 5U)) + aOrbiterI) + aPhaseAWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 6U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 39U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ aNonceWordD;
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 6447U)) & S_BLOCK1], 3U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 8668U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 8754U)) & W_KEY1], 53U) ^ RotL64(aKeyRowReadB[((aIndex + 6708U)) & W_KEY1], 20U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 58U) + RotL64(aCross, 27U)) ^ (RotL64(aPrevious, 13U) ^ RotL64(aCarry, 39U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterC = (((aWandererE + RotL64(aIngress, 35U)) + 12535417189990029950U) + aPhaseAOrbiterAssignSaltD[((aIndex + 16U)) & S_SALT1]) + aNonceWordI;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 41U)) + 6204401443676390273U) + aNonceWordM;
            aOrbiterF = (((aWandererA + RotL64(aPrevious, 53U)) + RotL64(aCarry, 47U)) + 869613505613154672U) + aNonceWordB;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 47U)) + 15053590879563855802U) + aPhaseAOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aIngress, 6U)) + RotL64(aCarry, 23U)) + 13338989605204591428U;
            aOrbiterI = ((aWandererF + RotL64(aScatter, 29U)) + RotL64(aCarry, 5U)) + 18306470022403825392U;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 19U)) + 1150696349434090218U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 13549541786420596437U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 14302878430259588461U;
            aOrbiterF = RotL64((aOrbiterF * 16813606782134305513U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 4660437084477165225U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 1653628537860912069U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2624835201155303123U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 5594199757006711631U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 11008472193138708891U;
            aOrbiterH = RotL64((aOrbiterH * 13645764762027798301U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 3668516817279364310U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 128159531749679984U;
            aOrbiterG = RotL64((aOrbiterG * 4523246859249826987U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 6378674346113979108U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 11438762460659123362U;
            aOrbiterB = RotL64((aOrbiterB * 2733309638158283953U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 10624263004446482910U) + aNonceWordL;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 12546839706919241411U;
            aOrbiterI = RotL64((aOrbiterI * 11468326687628079347U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 8466639576503293921U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 5828694979857951504U;
            aOrbiterJ = RotL64((aOrbiterJ * 7835487310289634515U), 19U);
            //
            aIngress = RotL64(aOrbiterI, 57U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 37U));
            aIngress = aIngress + RotL64(aOrbiterH, 28U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 30U) + RotL64(aOrbiterJ, 35U)) + aOrbiterF);
            aWandererA = aWandererA + (((((RotL64(aIngress, 5U) + aOrbiterG) + RotL64(aOrbiterC, 44U)) + RotL64(aCarry, 19U)) + aNonceWordG) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 23U)) + aOrbiterF) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterB, 29U)) + aOrbiterH) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterJ, 3U)) + aOrbiterC);
            aWandererB = aWandererB + ((RotL64(aIngress, 43U) + aOrbiterB) + RotL64(aOrbiterI, 11U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterJ, 53U)) + aOrbiterI) + aNonceWordO);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (RotL64(aWandererK, 18U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + RotL64(aWandererA, 51U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordN;
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12288U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16319U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 14722U)) & W_KEY1], 38U) ^ RotL64(aKeyRowReadB[((aIndex + 14221U)) & W_KEY1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 41U)) ^ (RotL64(aPrevious, 11U) + RotL64(aCross, 26U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterF = (((aWandererB + RotL64(aCross, 50U)) + RotL64(aCarry, 47U)) + 14249093584376402677U) + aNonceWordD;
            aOrbiterD = (((aWandererK + RotL64(aScatter, 57U)) + RotL64(aCarry, 35U)) + 8756965951816492264U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 11U)) + RotL64(aCarry, 3U)) + 11221139480258176330U;
            aOrbiterE = (aWandererH + RotL64(aIngress, 3U)) + 17218894445564194851U;
            aOrbiterG = (aWandererJ + RotL64(aCross, 41U)) + 8064642692524949490U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 29U)) + 5822093203710704646U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = (aWandererE + RotL64(aPrevious, 21U)) + 3217799620158102238U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 2613757677892120843U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 13647481499551657237U;
            aOrbiterK = RotL64((aOrbiterK * 5517563514031899891U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 3545714196663685016U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 9735422670576621521U;
            aOrbiterD = RotL64((aOrbiterD * 7276207208162697249U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 3911046580637583767U) + aNonceWordP;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 9315984027042049203U;
            aOrbiterF = RotL64((aOrbiterF * 12568550776487242469U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 8926367674641729058U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 11035347490524961446U;
            aOrbiterE = RotL64((aOrbiterE * 10948288997163592463U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 10748158733051120339U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 2467801787989056455U;
            aOrbiterG = RotL64((aOrbiterG * 12621934274702358977U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 9244415080474351390U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 8517784887959492079U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17022899813765884147U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 8409307332803038455U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 11043806021873232950U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8294888329708842989U), 53U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterD, 6U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterE, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterE, 35U)) + aOrbiterH);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterD, 51U)) + aOrbiterK) + aNonceWordB);
            aWandererE = aWandererE + ((((RotL64(aScatter, 57U) + aOrbiterF) + RotL64(aOrbiterE, 5U)) + RotL64(aCarry, 37U)) + aNonceWordJ);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 34U) + RotL64(aOrbiterC, 29U)) + aOrbiterH) + aNonceWordG);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterE, 58U)) + RotL64(aCarry, 19U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 27U) + aOrbiterG) + RotL64(aOrbiterH, 23U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterE, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 42U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + RotL64(aWandererG, 23U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 17616U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16853U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19119U)) & S_BLOCK1], 4U) ^ RotL64(mSource[((aIndex + 19165U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aPrevious, 43U)) ^ (RotL64(aIngress, 29U) + RotL64(aCross, 56U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterC = ((aWandererC + RotL64(aScatter, 3U)) + 7893287783892523139U) + aNonceWordC;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 57U)) + RotL64(aCarry, 35U)) + 10257331997383491153U;
            aOrbiterG = (((aWandererE + RotL64(aIngress, 21U)) + 14562226733652231753U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordP;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 43U)) + 14320342577110737851U) + aPhaseAOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aScatter, 29U)) + 9816717579822880756U;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 37U)) + RotL64(aCarry, 19U)) + 9558926960095881953U;
            aOrbiterB = ((aWandererB + RotL64(aCross, 50U)) + RotL64(aCarry, 47U)) + 9230371862654338324U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 6414274291252913420U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 13868546184398350849U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1547986864837497409U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 16940736952569949038U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 2866957764814864371U;
            aOrbiterI = RotL64((aOrbiterI * 3554702178644797003U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 7916721976073979724U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 1602444214978842275U;
            aOrbiterK = RotL64((aOrbiterK * 11072503711308122385U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 9529061385251008037U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 8402775110887376588U;
            aOrbiterH = RotL64((aOrbiterH * 13980225144628227381U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 15003592180290390713U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 14195681406520825751U;
            aOrbiterC = RotL64((aOrbiterC * 11455000833788877217U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 3263577002367714202U) + aNonceWordK;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 12019422062655581928U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5002313835338447799U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 8508638054582582917U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 6536618106353552880U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6233964121117511885U), 5U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 29U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 39U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + RotL64(aOrbiterI, 4U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterK, 21U)) + aOrbiterC);
            aWandererE = aWandererE + (((RotL64(aIngress, 43U) + RotL64(aOrbiterK, 35U)) + aOrbiterB) + aPhaseAWandererUpdateSaltC[((aIndex + 4U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterB, 29U)) + aOrbiterI);
            aWandererB = aWandererB + (((RotL64(aScatter, 28U) + RotL64(aOrbiterA, 44U)) + aOrbiterH) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterG, 5U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterK, 11U)) + RotL64(aCarry, 23U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 57U)) + aOrbiterA) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererC, 6U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ aNonceWordE;
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 26995U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24393U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26297U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((aIndex + 24173U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCross, 18U)) + (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 51U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 47U)) + RotL64(aCarry, 39U)) + 11410829607777684449U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 21U)) + RotL64(aCarry, 5U)) + 7502698839700975347U;
            aOrbiterF = (((aWandererJ + RotL64(aCross, 27U)) + 13267685058252106173U) + aPhaseAOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1]) + aNonceWordC;
            aOrbiterB = ((aWandererF + RotL64(aIngress, 3U)) + RotL64(aCarry, 51U)) + 238242706996630625U;
            aOrbiterD = (aWandererK + RotL64(aScatter, 14U)) + 8184695499511454281U;
            aOrbiterA = (aWandererC + RotL64(aIngress, 35U)) + 12767823220461985403U;
            aOrbiterE = (((aWandererG + RotL64(aPrevious, 53U)) + 12293198423143850330U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordH;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 11149495229952495939U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 7556992689338382800U;
            aOrbiterF = RotL64((aOrbiterF * 18232398462716803063U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 3431338808774134649U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 16863099140844995099U) ^ aNonceWordA;
            aOrbiterH = RotL64((aOrbiterH * 752376661101787919U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 17872458049880677604U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 16760153457252546974U;
            aOrbiterB = RotL64((aOrbiterB * 11225037229069712805U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 3115544493537438408U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 4359882942759752958U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 561477566995575801U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 13387113067202396536U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 12955690074544490161U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12449941770827974511U), 35U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterH) + 15614054443728226807U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordI;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 1939441328066616114U;
            aOrbiterA = RotL64((aOrbiterA * 4484917074808974359U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 4599016263007782537U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 9962305629016158048U;
            aOrbiterE = RotL64((aOrbiterE * 1496184427500037279U), 43U);
            //
            aIngress = RotL64(aOrbiterK, 23U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 60U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterE, 43U)) + aOrbiterF);
            aWandererK = aWandererK + ((((RotL64(aScatter, 21U) + RotL64(aOrbiterB, 5U)) + aOrbiterD) + RotL64(aCarry, 37U)) + aNonceWordN);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 27U) + aOrbiterE) + RotL64(aOrbiterK, 11U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 23U)) + aOrbiterA) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 46U) + aOrbiterB) + RotL64(aOrbiterH, 37U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterK, 29U)) + aOrbiterD) + RotL64(aCarry, 5U)) + aPhaseAWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterH, 56U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 10U));
            aCarry = aCarry + RotL64(aWandererG, 35U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordL);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30943U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneB[((aIndex + 31172U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27496U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((aIndex + 32690U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCross, 22U)) ^ (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 3U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 51U)) + RotL64(aCarry, 51U)) + 17019646486641172469U;
            aOrbiterK = (((aWandererK + RotL64(aIngress, 11U)) + 12276141179299971572U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordH;
            aOrbiterA = (aWandererH + RotL64(aScatter, 20U)) + 3617241694029841555U;
            aOrbiterE = (((aWandererD + RotL64(aPrevious, 29U)) + RotL64(aCarry, 27U)) + 6967963401259371737U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = ((aWandererI + RotL64(aScatter, 39U)) + RotL64(aCarry, 11U)) + 6340709284279891017U;
            aOrbiterB = (aWandererC + RotL64(aIngress, 57U)) + 456065368903896482U;
            aOrbiterG = (aWandererG + RotL64(aPrevious, 3U)) + 17686765719908116203U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 1322045955429785736U) + aNonceWordB;
            aOrbiterA = (((aOrbiterA ^ aOrbiterJ) ^ 5163772703302372887U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterA = RotL64((aOrbiterA * 3193272189179082313U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 13268431135020363252U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 6538789950366849332U;
            aOrbiterC = RotL64((aOrbiterC * 5352960308459065837U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 10390344544314544893U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 5087084271300584267U) ^ aNonceWordP;
            aOrbiterB = RotL64((aOrbiterB * 15149302947570776165U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 13423071121590981727U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 18324443012024134729U;
            aOrbiterG = RotL64((aOrbiterG * 15814349432207734533U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 4129091815978464507U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 17024797553831962245U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3137753479364378175U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 6501545108779991661U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 11930037791867597447U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4904739567549702851U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 4667298703308315851U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 6315980380900062127U;
            aOrbiterK = RotL64((aOrbiterK * 12080555704907924637U), 41U);
            //
            aIngress = RotL64(aOrbiterA, 60U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterJ, 37U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterC, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aCross, 29U) + RotL64(aOrbiterB, 3U)) + aOrbiterE);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterJ, 47U)) + aOrbiterK);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 37U) + aOrbiterE) + RotL64(aOrbiterC, 38U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 21U) + aOrbiterK) + RotL64(aOrbiterG, 29U)) + aPhaseAWandererUpdateSaltA[((aIndex + 8U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 51U) + aOrbiterA) + RotL64(aOrbiterG, 57U)) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 44U) + RotL64(aOrbiterJ, 13U)) + aOrbiterA);
            aWandererC = aWandererC + (((((RotL64(aPrevious, 5U) + aOrbiterJ) + RotL64(aOrbiterB, 19U)) + RotL64(aCarry, 41U)) + aNonceWordN) + aPhaseAWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 30U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 37U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ aNonceWordM;
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

void TwistExpander_Soccer_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xE06DA48385E6CA43ULL + 0xE46DCC229E4AB523ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x86C81465ECAE9603ULL + 0xF7800BAFEF89E157ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xCC83BE89F3EB576BULL + 0xF5F9650426304095ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xE5CB689BAD90F9F3ULL + 0xF23F43D53885511EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xC46D7775EF4A8943ULL + 0x980D0D1EB3B24902ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xF5E3DB9B6D05D129ULL + 0xAC2EBEDCDA4EAF30ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xC83782B85ECD2C31ULL + 0x999080727C05B881ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xD7BD956589277DD7ULL + 0xB9A1FB724C0F1C69ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xBBC47BC7492F23CBULL + 0x83F9EF9FB105C9F3ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x9DA915432A1CFA11ULL + 0xC6D555078A17B4E8ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xB799A3AC07EAC587ULL + 0xE4F3BF13EC9278FAULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x9AEABFE79D77EDE7ULL + 0xD4521422F0FB9B28ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xC52A988EFF473C39ULL + 0x89A0D3D2E7840CA2ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xA3CFA05D2AFA4A4BULL + 0x97D89EBCA4BE9043ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xB6F599678C159A5DULL + 0xFA38947D97C9B771ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xE589709A86BACE6DULL + 0xB1D335EC3CDF0B59ULL);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 3860U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneC[((aIndex + 3382U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5029U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 4113U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 53U)) + (RotL64(aIngress, 18U) ^ RotL64(aCross, 39U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterD = ((aWandererC + RotL64(aScatter, 47U)) + 13714409587461539863U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = (((aWandererA + RotL64(aCross, 13U)) + 14101156723903265839U) + aPhaseBOrbiterAssignSaltD[((aIndex + 10U)) & S_SALT1]) + aNonceWordB;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 58U)) + RotL64(aCarry, 41U)) + 7063754562895369001U;
            aOrbiterJ = (((aWandererD + RotL64(aPrevious, 21U)) + RotL64(aCarry, 53U)) + 12320578575245519386U) + aNonceWordH;
            aOrbiterK = (((aWandererK + RotL64(aCross, 3U)) + RotL64(aCarry, 5U)) + 11744826789631008424U) + aNonceWordE;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 8744816505096675597U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 10405435520084528645U;
            aOrbiterB = RotL64((aOrbiterB * 13279521344071568023U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 1463157688070683543U) + aNonceWordG;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 12379603577919617703U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14858901470015109311U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 1343439118031348146U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 16118850268070235540U) ^ aNonceWordP;
            aOrbiterJ = RotL64((aOrbiterJ * 11184386483735388257U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 14116264435819277136U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterK) ^ 5251698273012432109U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 1495818611622063967U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 14806408656041403829U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 11569345414052398227U;
            aOrbiterK = RotL64((aOrbiterK * 9913158908301414861U), 53U);
            //
            aIngress = RotL64(aOrbiterB, 3U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + RotL64(aOrbiterJ, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aScatter, 34U) + aOrbiterK) + RotL64(aOrbiterD, 52U));
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 51U) + RotL64(aOrbiterF, 3U)) + aOrbiterK) + aNonceWordJ) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterF, 21U)) + RotL64(aCarry, 47U)) + aPhaseBWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 23U) + aOrbiterB) + RotL64(aOrbiterK, 37U));
            aWandererE = aWandererE + (((RotL64(aIngress, 5U) + RotL64(aOrbiterF, 29U)) + aOrbiterB) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + RotL64(aWandererA, 51U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordL);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 7988U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneD[((aIndex + 5650U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8983U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10648U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 28U) + RotL64(aPrevious, 41U)) ^ (RotL64(aCarry, 57U) + RotL64(aIngress, 5U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterC = (((aWandererC + RotL64(aScatter, 20U)) + RotL64(aCarry, 41U)) + 4739486756133131180U) + aNonceWordH;
            aOrbiterJ = (aWandererH + RotL64(aIngress, 41U)) + 16089707555501328184U;
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 57U)) + 15310047330238536453U) + aNonceWordJ;
            aOrbiterF = (((aWandererA + RotL64(aCross, 29U)) + RotL64(aCarry, 57U)) + 7901411596386834955U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = ((((aWandererD + RotL64(aPrevious, 3U)) + RotL64(aCarry, 13U)) + 4357555491060982163U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordI;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 15667085602825720102U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 8520635334382269253U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7348648918661047791U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 1772509779231068315U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 15336170957886025677U) ^ aNonceWordL;
            aOrbiterI = RotL64((aOrbiterI * 10996880551392077399U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 8628770833489469980U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 15469234024247246228U) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 8905266995119987947U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 10796430900884288328U) + aNonceWordG;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 10660110397012853289U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9140007610912037461U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 11202284258711214794U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 17509491802893182994U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9329107599972703671U), 39U);
            //
            aIngress = RotL64(aOrbiterH, 29U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterC, 14U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aScatter, 18U) + aOrbiterI) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 43U)) + aNonceWordN);
            aWandererA = aWandererA ^ (((RotL64(aCross, 27U) + aOrbiterC) + RotL64(aOrbiterF, 41U)) + aNonceWordO);
            aWandererH = aWandererH + ((((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 21U)) + aOrbiterF) + RotL64(aCarry, 27U)) + aPhaseBWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 29U)) + aOrbiterH);
            aWandererD = aWandererD + ((((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterC, 60U)) + aNonceWordF) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 37U);
            aCarry = aCarry + RotL64(aIngress, 48U);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12438U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 13592U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15402U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneC[((aIndex + 13882U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 40U) ^ RotL64(aCarry, 57U)) + (RotL64(aIngress, 5U) + RotL64(aCross, 21U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterI = (((aWandererK + RotL64(aCross, 51U)) + RotL64(aCarry, 43U)) + 14008824488073394623U) + aNonceWordJ;
            aOrbiterC = ((aWandererD + RotL64(aIngress, 60U)) + 13317978415866411468U) + aNonceWordP;
            aOrbiterG = (aWandererB + RotL64(aScatter, 21U)) + 13209180141897453900U;
            aOrbiterB = ((((aWandererE + RotL64(aPrevious, 11U)) + RotL64(aCarry, 13U)) + 11870521586865233578U) + aPhaseBOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1]) + aNonceWordO;
            aOrbiterK = (((aWandererA + RotL64(aScatter, 35U)) + RotL64(aCarry, 57U)) + 8052156380448047385U) + aPhaseBOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 12158131176743680605U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 14674467487607719347U;
            aOrbiterG = RotL64((aOrbiterG * 18372548574199176503U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 18055496790566231147U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 3838105585041578784U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1075709247574580091U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 2839568255183054418U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterK) ^ 11933612922864258179U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterI = RotL64((aOrbiterI * 7571964469321160347U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 6289849094151630580U) + aNonceWordI;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 2640344350528492271U;
            aOrbiterB = RotL64((aOrbiterB * 16197726750829369365U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 16306175266267657791U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 3339898380394883600U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7105436590182982373U), 3U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterC, 47U);
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterK, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterI, 57U)) + aOrbiterB) + aNonceWordG);
            aWandererA = aWandererA + (((((RotL64(aScatter, 42U) + aOrbiterG) + RotL64(aOrbiterB, 47U)) + RotL64(aCarry, 19U)) + aNonceWordH) + aPhaseBWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterC, 24U));
            aWandererD = aWandererD + ((((RotL64(aCross, 57U) + RotL64(aOrbiterG, 13U)) + aOrbiterK) + RotL64(aCarry, 3U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 39U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + RotL64(aWandererK, 34U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordM;
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 17429U)) & S_BLOCK1], 26U) ^ RotL64(aWorkLaneB[((aIndex + 19630U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21423U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneD[((aIndex + 21241U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 20U)) + (RotL64(aIngress, 41U) + RotL64(aCarry, 57U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterG = (((aWandererJ + RotL64(aCross, 13U)) + RotL64(aCarry, 39U)) + 12669015908335980355U) + aNonceWordA;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 21U)) + 5438715179868613192U) + aPhaseBOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aScatter, 51U)) + RotL64(aCarry, 19U)) + 13172104448184536460U;
            aOrbiterB = (aWandererK + RotL64(aPrevious, 4U)) + 13421421503244744803U;
            aOrbiterC = ((((aWandererH + RotL64(aIngress, 35U)) + RotL64(aCarry, 51U)) + 13327113302994856582U) + aPhaseBOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1]) + aNonceWordB;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 4671768205922454413U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 5355759962838579929U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15080379163499722187U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 6691720614265406851U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 7063906424700911378U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17091734375516280675U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 17328616394166672263U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 1542940602574207068U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8981679306319627975U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 7203866278803132454U) + aNonceWordH;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 993485696233139264U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11609009908810366447U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 15659679028507488331U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 18321361454094675842U;
            aOrbiterC = RotL64((aOrbiterC * 3966860765622641843U), 11U);
            //
            aIngress = RotL64(aOrbiterF, 26U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aCross, 39U) + aOrbiterE) + RotL64(aOrbiterG, 5U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterF, 39U)) + RotL64(aCarry, 13U)) + aNonceWordM);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 58U) + RotL64(aOrbiterB, 30U)) + aOrbiterC);
            aWandererG = aWandererG + (((((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 51U)) + aOrbiterF) + RotL64(aCarry, 29U)) + aNonceWordG) + aPhaseBWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 19U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererK, 56U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ aNonceWordH;
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 24649U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26355U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24898U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 24686U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 56U) + RotL64(aIngress, 23U)) ^ (RotL64(aCross, 11U) + RotL64(aPrevious, 41U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterH = ((aWandererG + RotL64(aIngress, 46U)) + RotL64(aCarry, 5U)) + 5573188770530340913U;
            aOrbiterA = (((aWandererA + RotL64(aPrevious, 57U)) + 1431772230889897111U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordM;
            aOrbiterD = (((aWandererF + RotL64(aCross, 19U)) + RotL64(aCarry, 23U)) + 4809192776429682319U) + aNonceWordI;
            aOrbiterI = ((((aWandererH + RotL64(aScatter, 3U)) + RotL64(aCarry, 35U)) + 5576603692574369341U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordD;
            aOrbiterF = (aWandererE + RotL64(aIngress, 11U)) + 2720143226007220386U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 17220328778565331629U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 9629485808442089423U;
            aOrbiterD = RotL64((aOrbiterD * 18349580416082045015U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 1136998437010390983U) + aNonceWordP;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 11893390497814523841U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5329621622743089531U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 1764986431917532370U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 1741014798007010376U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13414914086049500731U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 12221368453236547044U) + aNonceWordB;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 7694538641172350430U;
            aOrbiterA = RotL64((aOrbiterA * 8439120733670016501U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 17472344518811560603U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 3308740700728172984U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15290400462887712083U), 21U);
            //
            aIngress = RotL64(aOrbiterH, 19U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 30U) + RotL64(aOrbiterD, 24U)) + aOrbiterI);
            aWandererE = aWandererE + (((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 41U) + RotL64(aOrbiterH, 57U)) + aOrbiterA) + aNonceWordK) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aIngress, 21U) + aOrbiterF) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 13U)) + aPhaseBWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 13U) + aOrbiterI) + RotL64(aOrbiterA, 39U)) + aNonceWordJ);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 4U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + RotL64(aWandererE, 13U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordM;
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 32604U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((aIndex + 30037U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31133U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneB[((aIndex + 30867U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 29U) ^ RotL64(aCarry, 12U)) ^ (RotL64(aCross, 53U) + RotL64(aPrevious, 41U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterH = (((aWandererF + RotL64(aScatter, 47U)) + RotL64(aCarry, 37U)) + 11998579547770778580U) + aPhaseBOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (((aWandererJ + RotL64(aIngress, 19U)) + RotL64(aCarry, 21U)) + 8409465187298704610U) + aPhaseBOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aCross, 57U)) + RotL64(aCarry, 5U)) + 3470222286110333500U;
            aOrbiterD = (aWandererE + RotL64(aPrevious, 35U)) + 5704486785203069994U;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 4U)) + 10334944660253279633U) + aNonceWordI;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 7626852700722567477U) + aNonceWordC;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 14631310754943209743U;
            aOrbiterF = RotL64((aOrbiterF * 1958866541508493967U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 807160297237854120U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 5624154783624196107U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2404066593958052159U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 4971444394698940423U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 6340057638461027062U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12027586111086798629U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 9003019862787819481U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 13632057463595873033U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12575202147280216765U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 12766104026871797746U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 4062118445824915939U;
            aOrbiterB = RotL64((aOrbiterB * 13130770039048080701U), 27U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterG, 58U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + RotL64(aOrbiterB, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 37U) + aOrbiterH) + RotL64(aOrbiterB, 37U)) + aPhaseBWandererUpdateSaltC[((aIndex + 14U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterF, 53U)) + aNonceWordE);
            aWandererJ = aWandererJ + (((((RotL64(aIngress, 19U) + RotL64(aOrbiterG, 3U)) + aOrbiterH) + RotL64(aCarry, 51U)) + aNonceWordJ) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 58U) + aOrbiterF) + RotL64(aOrbiterH, 11U));
            aWandererB = aWandererB + (((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterD, 22U)) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + RotL64(aWandererF, 56U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordM);
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

void TwistExpander_Soccer_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xB8459C865F675B03ULL + 0xD18266F867B6164AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xFD1EF3F355613F9DULL + 0xCC8B47A64D5E34E9ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xB9416166B1C00DB5ULL + 0xDEA6EF1E64197E82ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xBA4842C98E810A4FULL + 0xAFB1AFCDA5EC5776ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xC1485FB0FFC3535BULL + 0x806B8CB07A9A6A9AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x80AC34C46A5FA55FULL + 0x8D1822ABCCC0F25EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xB7A4CF45642E1C0DULL + 0xB15C1495C3D4E2A0ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xBE33063FFDA3445FULL + 0x800EEEE514E6AB44ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x8C2060513044C06BULL + 0x801855AEFBB2B7E5ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xCCC7BA9D815AEE77ULL + 0x897FBE6DB82F9ADFULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x96F68568E72AE8BFULL + 0x81007DEE68FD2DD8ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x94A7AF74A8201BBBULL + 0xFCCF6731E65F7E16ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xE6A227C5DB364DE7ULL + 0xB5194C12D20AF0ECULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x903EF234D38E0CD5ULL + 0xA984EBA26FC78145ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xD5E2D6817D447C6DULL + 0xBCE3E9A7302956FBULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xAD46C23AAD82348BULL + 0xF1B675B94D5FBDB9ULL);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 7879U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3040U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 5334U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((aIndex + 1784U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 40U) ^ RotL64(aIngress, 19U)) + (RotL64(aPrevious, 53U) + RotL64(aCarry, 3U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 39U)) + RotL64(aCarry, 19U)) + 13924571355038625040U;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 29U)) + 16328300979357156658U) + aNonceWordC;
            aOrbiterH = ((aWandererC + RotL64(aIngress, 57U)) + RotL64(aCarry, 29U)) + 3947771961206012461U;
            aOrbiterJ = (aWandererA + RotL64(aCross, 6U)) + 15428284250569311285U;
            aOrbiterI = (aWandererI + RotL64(aPrevious, 47U)) + 5777369485254032486U;
            aOrbiterD = (aWandererH + RotL64(aIngress, 11U)) + 16813320300717644673U;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 35U)) + RotL64(aCarry, 43U)) + 16689933050200758251U;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 53U)) + 1856422419049390708U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 20U)) + 18214498743831925517U) + aPhaseCOrbiterAssignSaltD[((aIndex + 26U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 18278550878494094923U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 797712062039591797U;
            aOrbiterH = RotL64((aOrbiterH * 7212998747080137625U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 15854849439012341347U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 996882939768167773U;
            aOrbiterD = RotL64((aOrbiterD * 14936703950807908575U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 3005829974130671692U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 8793495343509953906U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14065479348374612031U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 7710453029930631112U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 9511995836117707047U;
            aOrbiterF = RotL64((aOrbiterF * 7250766204781428201U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 670902975693341744U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 9045820304668279777U;
            aOrbiterB = RotL64((aOrbiterB * 18373074917532639027U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 12417212387607119470U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 12816983560669985622U;
            aOrbiterJ = RotL64((aOrbiterJ * 8406003970221889847U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 17245432086377688540U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 6806521945548502014U;
            aOrbiterG = RotL64((aOrbiterG * 11335859481858640857U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 8947500746292365294U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 4468060468522895852U;
            aOrbiterA = RotL64((aOrbiterA * 7022481284816599797U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 9892975931958803992U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 3042599331526937836U) ^ aNonceWordH;
            aOrbiterI = RotL64((aOrbiterI * 3308512896171443645U), 51U);
            //
            aIngress = RotL64(aOrbiterI, 10U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterA, 47U)) + aOrbiterB) + aPhaseCWandererUpdateSaltD[((aIndex + 4U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterD, 20U));
            aWandererI = aWandererI + (((RotL64(aScatter, 10U) + aOrbiterG) + RotL64(aOrbiterE, 29U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterB, 37U)) + aNonceWordO);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 43U)) + aOrbiterI) + RotL64(aCarry, 41U)) + aNonceWordJ);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterH, 12U)) + aOrbiterB);
            aWandererD = aWandererD + (((RotL64(aIngress, 23U) + aOrbiterF) + RotL64(aOrbiterB, 53U)) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 57U)) + aOrbiterJ);
            aWandererC = aWandererC + ((RotL64(aIngress, 14U) + RotL64(aOrbiterB, 3U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + (RotL64(aWandererE, 14U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ aNonceWordN;
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 13500U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneD[((aIndex + 12886U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 14186U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneB[((aIndex + 12355U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCarry, 21U)) ^ (RotL64(aPrevious, 38U) ^ RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 29U)) + RotL64(aCarry, 5U)) + 6733949564325516029U;
            aOrbiterC = (((aWandererA + RotL64(aIngress, 47U)) + RotL64(aCarry, 13U)) + 7304098437143918796U) + aNonceWordD;
            aOrbiterA = (aWandererH + RotL64(aCross, 6U)) + 3923949518391777800U;
            aOrbiterH = (((aWandererB + RotL64(aScatter, 13U)) + 14243591003388927124U) + aPhaseCOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1]) + aNonceWordK;
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 39U)) + 18329498724605410406U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aCross, 43U)) + RotL64(aCarry, 47U)) + 13118172167747037249U;
            aOrbiterB = ((aWandererI + RotL64(aIngress, 57U)) + 5272025143849174212U) + aNonceWordP;
            aOrbiterI = (aWandererE + RotL64(aScatter, 24U)) + 16075917179214318424U;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 19U)) + 15263590648674658399U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 13730046728289525921U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 7703141464499623408U;
            aOrbiterA = RotL64((aOrbiterA * 5886009900621521987U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 1382279753822135359U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 2973369221699098292U) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 7440242040663550631U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 11578274119583013219U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 3419411247737896674U;
            aOrbiterB = RotL64((aOrbiterB * 17814942652262802991U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 2582783513078999303U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 3959762790273529677U) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 383974377372162751U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 465795011576934604U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 17880826624185821135U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4445949147592860913U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 10819659185349413173U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 17298208553586835030U;
            aOrbiterE = RotL64((aOrbiterE * 1965860510614222093U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 12585880006661489402U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 16650193903267408586U;
            aOrbiterH = RotL64((aOrbiterH * 5781132589396936615U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 885882046325991589U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 869560078374809974U;
            aOrbiterD = RotL64((aOrbiterD * 13440973563438747181U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 11871305571797951851U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 12137095015607196226U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7618152256560808581U), 27U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterF, 34U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 53U));
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 23U));
            aIngress = aIngress + RotL64(aOrbiterC, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 4U) + RotL64(aOrbiterH, 19U)) + aOrbiterF) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 23U) + aOrbiterF) + RotL64(aOrbiterK, 3U));
            aWandererE = aWandererE + ((RotL64(aCross, 57U) + RotL64(aOrbiterD, 54U)) + aOrbiterB);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterD, 43U)) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 11U) + aOrbiterI) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 37U)) + aNonceWordN);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 34U) + aOrbiterC) + RotL64(aOrbiterE, 47U)) + aNonceWordH);
            aWandererJ = aWandererJ + (((RotL64(aCross, 39U) + RotL64(aOrbiterB, 35U)) + aOrbiterA) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterF, 39U)) + aNonceWordF);
            aWandererB = aWandererB + ((RotL64(aPrevious, 53U) + aOrbiterK) + RotL64(aOrbiterB, 28U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 60U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 22317U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneA[((aIndex + 18285U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 17292U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 22468U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCross, 57U)) + (RotL64(aCarry, 5U) + RotL64(aPrevious, 38U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterC = (aWandererK + RotL64(aPrevious, 29U)) + 12632404972795375757U;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 56U)) + RotL64(aCarry, 5U)) + 5351879979055988456U;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 51U)) + RotL64(aCarry, 19U)) + 3597737727467443413U;
            aOrbiterI = ((aWandererB + RotL64(aCross, 23U)) + 2830846754917852318U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = (aWandererF + RotL64(aScatter, 3U)) + 17311925960294518018U;
            aOrbiterD = ((aWandererA + RotL64(aCross, 35U)) + 2083584640523695383U) + aPhaseCOrbiterAssignSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = (aWandererC + RotL64(aIngress, 19U)) + 15049343611387010158U;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 11U)) + RotL64(aCarry, 43U)) + 6443050378205811147U;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 40U)) + 6021965178697344070U) + aNonceWordK;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 5080289878758029976U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 576927745306972983U;
            aOrbiterG = RotL64((aOrbiterG * 16008958833683246115U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 4728489691382690859U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 6184355840165758855U;
            aOrbiterC = RotL64((aOrbiterC * 1515043910404156423U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 11220539885798595450U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterJ) ^ 11091438724966718214U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 8225347114759391961U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 17184210490020062419U) + aNonceWordD;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 2150997767099116408U;
            aOrbiterJ = RotL64((aOrbiterJ * 8058553821648892499U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 7021953562676903717U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 17159676348343312834U;
            aOrbiterE = RotL64((aOrbiterE * 13877284519668483549U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 10367891770525239784U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 11922478487264201233U;
            aOrbiterD = RotL64((aOrbiterD * 9195137452661956029U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 17815162358981720634U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 9582631251085100284U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11838992994130850483U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 872593750259572264U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 17832330100262167302U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1114416841510028467U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 16601139856969287418U) + aNonceWordN;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 14931287111691324985U;
            aOrbiterH = RotL64((aOrbiterH * 16757174577841001179U), 3U);
            //
            aIngress = RotL64(aOrbiterI, 11U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 14U));
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 37U) + aOrbiterB) + RotL64(aOrbiterH, 52U));
            aWandererC = aWandererC + (((RotL64(aScatter, 28U) + RotL64(aOrbiterA, 47U)) + aOrbiterI) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterG, 3U)) + aOrbiterA);
            aWandererD = aWandererD + (((RotL64(aCross, 41U) + RotL64(aOrbiterI, 57U)) + aOrbiterE) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 23U) + aOrbiterD) + RotL64(aOrbiterI, 43U));
            aWandererA = aWandererA + (((((RotL64(aIngress, 57U) + RotL64(aOrbiterG, 39U)) + aOrbiterC) + RotL64(aCarry, 47U)) + aNonceWordA) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 14U) + aOrbiterI) + RotL64(aOrbiterG, 10U)) + aNonceWordB);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 47U) + aOrbiterJ) + RotL64(aOrbiterB, 29U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterE, 35U)) + aOrbiterJ) + aNonceWordG);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 44U));
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordI;
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 27542U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneB[((aIndex + 27018U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28724U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 32370U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aIngress, 29U)) + (RotL64(aPrevious, 54U) ^ RotL64(aCarry, 41U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 4U)) + 1708250618750199233U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 35U)) + 12009147777553691142U) + aNonceWordF;
            aOrbiterG = (((aWandererJ + RotL64(aCross, 39U)) + RotL64(aCarry, 37U)) + 8393982703399156592U) + aNonceWordE;
            aOrbiterE = (((aWandererH + RotL64(aScatter, 23U)) + RotL64(aCarry, 47U)) + 3247327098356831221U) + aPhaseCOrbiterAssignSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aIngress, 43U)) + RotL64(aCarry, 19U)) + 3403590155376353737U;
            aOrbiterI = (aWandererG + RotL64(aCross, 51U)) + 18197244558104735044U;
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 11U)) + 3096253642040701606U) + aNonceWordC;
            aOrbiterH = (aWandererI + RotL64(aScatter, 29U)) + 8012692688785412179U;
            aOrbiterD = (aWandererD + RotL64(aPrevious, 60U)) + 17531946907545680745U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 17687695944270225817U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 16147773866007628769U;
            aOrbiterG = RotL64((aOrbiterG * 16926442582711557877U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 18244641303026196497U) + aNonceWordN;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 8839160526348897457U;
            aOrbiterA = RotL64((aOrbiterA * 14268021129087663397U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 10599266240854068246U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 2056723540756216155U;
            aOrbiterK = RotL64((aOrbiterK * 13311591601230386375U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 4629354220460621284U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 9505955649473204942U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17775391885312236187U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 17078153810088721310U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 9470436761716263000U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5431855497250357229U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 3305863413630104742U) + aNonceWordG;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 14377172434239576161U;
            aOrbiterI = RotL64((aOrbiterI * 6880176890091033423U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 415687827894226513U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 16975319836893760993U;
            aOrbiterH = RotL64((aOrbiterH * 6597144958013976445U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 12707054129431596074U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 8974182792497231239U) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 7874658957269462717U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 10826131924322955095U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 4168545139712703154U;
            aOrbiterJ = RotL64((aOrbiterJ * 10305904857550051705U), 23U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterA, 37U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 18U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 53U));
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterJ, 53U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 30U) + RotL64(aOrbiterF, 47U)) + aOrbiterI) + RotL64(aCarry, 13U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterK, 13U)) + aOrbiterA) + aNonceWordP);
            aWandererK = aWandererK + ((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 39U)) + aOrbiterG);
            aWandererA = aWandererA ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterA, 30U)) + aOrbiterH);
            aWandererC = aWandererC + (((RotL64(aIngress, 50U) + aOrbiterH) + RotL64(aOrbiterD, 23U)) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 5U) + aOrbiterI) + RotL64(aOrbiterG, 35U));
            aWandererG = aWandererG + ((RotL64(aScatter, 23U) + RotL64(aOrbiterF, 43U)) + aOrbiterE);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 60U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (RotL64(aWandererK, 40U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 51U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordN);
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

void TwistExpander_Soccer_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xAF326E7236661A8DULL + 0xFE2ADA65ED0A68DFULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xE3FA5ADB644E369BULL + 0x92A0C950C2958728ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x85EC7B54D4442B97ULL + 0xAE6C401CA1C9FC31ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xE8AFD53EAC7593FBULL + 0xB7B799903A40220CULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xF5453F626565FD9BULL + 0xFE757053099C3407ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xBEC87ED6A2F92DA3ULL + 0xA7F445F860EA862FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x90FAD42CCC22CA7FULL + 0xD0E4618088464FA9ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x8F81B3C6BDB7D91BULL + 0xEC58D7D9ADDFFFAAULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xBD80A5534B0CD8A1ULL + 0xF24770273D1F5047ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x8C8678AAD4E45265ULL + 0x8A6E6910DBB7A333ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xED3E37DD3D33F5C3ULL + 0xF500BE228E71EE9CULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xA36B68E7B594B399ULL + 0xB8D37A6FF5BF5B84ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xDE7E3A8A02C400FBULL + 0x80260E26D253A189ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xDBB712D6FC867177ULL + 0xC905D6CEB71AE1A4ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xDAFA23D1F2F83BADULL + 0xEF66AEE5A459E353ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xDDA93088C34925E1ULL + 0xC8E59F7B1DFC849FULL);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 4246U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneC[((aIndex + 1979U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4178U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((aIndex + 4775U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 22U) + RotL64(aPrevious, 51U)) ^ (RotL64(aCross, 5U) ^ RotL64(aIngress, 39U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterI = (aWandererF + RotL64(aIngress, 37U)) + 5295352595333316211U;
            aOrbiterF = (aWandererK + RotL64(aCross, 5U)) + 2341795367042042605U;
            aOrbiterA = (((aWandererB + RotL64(aScatter, 29U)) + RotL64(aCarry, 41U)) + 10122175780504033663U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aPrevious, 48U)) + 10084612804696198554U;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 39U)) + 16470424309851045971U) + aNonceWordA;
            aOrbiterG = (aWandererA + RotL64(aPrevious, 11U)) + 656016130975227994U;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 13U)) + 15313268829659834317U;
            aOrbiterK = ((((aWandererI + RotL64(aCross, 41U)) + RotL64(aCarry, 35U)) + 3795220914993923394U) + aPhaseDOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1]) + aNonceWordM;
            aOrbiterC = (aWandererE + RotL64(aScatter, 26U)) + 14044442220988813825U;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 19U)) + 3804224626734584802U;
            aOrbiterD = (((aWandererD + RotL64(aIngress, 53U)) + RotL64(aCarry, 21U)) + 7980006306010255693U) + aNonceWordL;
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 13746830564584711549U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 11852212099729274845U;
            aOrbiterA = RotL64((aOrbiterA * 2164880979318247855U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 9083223471018084847U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 13706723820703853346U;
            aOrbiterG = RotL64((aOrbiterG * 11361854103656219887U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 1713819986642275223U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 1382000168233902914U;
            aOrbiterI = RotL64((aOrbiterI * 3894160765130198157U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 4540474625764565485U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 1756168174375757220U;
            aOrbiterH = RotL64((aOrbiterH * 12739160208010092017U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 1409297070183609309U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 6082750101445444357U;
            aOrbiterJ = RotL64((aOrbiterJ * 17438740230251860935U), 39U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterG) + 1113239890859479202U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1]) + aNonceWordF;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 10932192439503964363U) ^ aNonceWordO;
            aOrbiterC = RotL64((aOrbiterC * 5915660289913324281U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 3732595033748508428U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 5117760372351117286U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2671510075176315761U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 7399968659654088641U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 14835608167871904147U;
            aOrbiterF = RotL64((aOrbiterF * 8312521710415756159U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 7851355416751467648U) + aNonceWordP;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 262169565276199916U;
            aOrbiterB = RotL64((aOrbiterB * 11801419425408657509U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 1771847554312299305U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 15588805765521695222U;
            aOrbiterK = RotL64((aOrbiterK * 8541206691371972017U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 6162696602553964144U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 5295352595333316211U;
            aOrbiterE = RotL64((aOrbiterE * 8368226841948931873U), 51U);
            //
            aIngress = RotL64(aOrbiterH, 14U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aScatter, 43U) + aOrbiterC) + RotL64(aOrbiterA, 5U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 21U) + aOrbiterK) + RotL64(aOrbiterI, 19U));
            aWandererH = aWandererH + (((RotL64(aIngress, 23U) + aOrbiterA) + RotL64(aOrbiterH, 21U)) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 41U) + aOrbiterD) + RotL64(aOrbiterG, 46U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 37U) + aOrbiterG) + RotL64(aOrbiterF, 57U)) + aNonceWordK);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 6U) + aOrbiterJ) + RotL64(aOrbiterC, 29U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterD, 3U)) + aNonceWordH) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterB, 41U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 51U)) + aOrbiterI);
            aWandererK = aWandererK ^ ((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterI, 44U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 54U) + RotL64(aOrbiterH, 53U)) + aOrbiterE) + RotL64(aCarry, 3U)) + aNonceWordE);
            //
            aCarry = aCarry + (RotL64(aWandererG, 18U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 24U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordA);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 9564U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((aIndex + 7942U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6729U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((aIndex + 10338U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 13U) + RotL64(aCross, 57U)) ^ (RotL64(aIngress, 44U) + RotL64(aCarry, 29U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterD = ((aWandererH + RotL64(aIngress, 18U)) + RotL64(aCarry, 35U)) + 7075016829833562104U;
            aOrbiterA = (((aWandererK + RotL64(aPrevious, 23U)) + 8783765886115517036U) + aPhaseDOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1]) + aNonceWordE;
            aOrbiterC = (aWandererJ + RotL64(aScatter, 21U)) + 2996723892384565829U;
            aOrbiterE = (aWandererE + RotL64(aCross, 53U)) + 9494134707342189476U;
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 47U)) + 5052642981395679904U) + aNonceWordO;
            aOrbiterB = (aWandererD + RotL64(aScatter, 13U)) + 8766787055127962238U;
            aOrbiterH = ((aWandererC + RotL64(aCross, 43U)) + 4467211954388738079U) + aNonceWordA;
            aOrbiterF = (aWandererI + RotL64(aIngress, 58U)) + 8030255604633658608U;
            aOrbiterI = (aWandererB + RotL64(aScatter, 29U)) + 16962408063455702251U;
            aOrbiterG = (((aWandererG + RotL64(aCross, 3U)) + RotL64(aCarry, 57U)) + 3768222186567699076U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 51U)) + RotL64(aCarry, 43U)) + 14930990410207899871U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 14179761938395502502U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 1879084742719898108U;
            aOrbiterC = RotL64((aOrbiterC * 16783034788172670121U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 5535012408925981515U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 12792553516710295939U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8577530993755159329U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 8979253163346099252U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 5559189896063990740U;
            aOrbiterK = RotL64((aOrbiterK * 8832485423727331621U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 13937564337299044079U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 2393376759689394948U;
            aOrbiterH = RotL64((aOrbiterH * 2352815657830413941U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 12647519563697356479U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 10946871249960389549U;
            aOrbiterI = RotL64((aOrbiterI * 6272580371881237173U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 13376798695582123147U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 10958115913599631271U;
            aOrbiterD = RotL64((aOrbiterD * 18233981473003345217U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 4283914227806672773U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 910842005516235816U) ^ aNonceWordG;
            aOrbiterE = RotL64((aOrbiterE * 6722229871617873429U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 1509644316619370324U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 165987596716078174U;
            aOrbiterB = RotL64((aOrbiterB * 13600064054240185123U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 12491315345199091186U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 5982431705686495125U) ^ aNonceWordD;
            aOrbiterF = RotL64((aOrbiterF * 2547243804779022665U), 5U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterJ) + 231183123382412440U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1]) + aNonceWordC;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 2872632389683254396U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1972278820468847241U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 15259314110008210315U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 7075016829833562104U;
            aOrbiterJ = RotL64((aOrbiterJ * 8350093877370898869U), 41U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 51U);
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 60U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterB, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aIngress, 11U) + aOrbiterC) + RotL64(aOrbiterA, 19U)) + RotL64(aCarry, 5U)) + aPhaseDWandererUpdateSaltE[((aIndex + 10U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 37U) + aOrbiterB) + RotL64(aOrbiterG, 51U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 18U) + RotL64(aOrbiterF, 38U)) + aOrbiterE) + RotL64(aCarry, 37U)) + aNonceWordM);
            aWandererA = aWandererA ^ ((RotL64(aCross, 21U) + aOrbiterH) + RotL64(aOrbiterE, 3U));
            aWandererH = aWandererH + ((RotL64(aIngress, 5U) + RotL64(aOrbiterI, 35U)) + aOrbiterG);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterA, 5U));
            aWandererK = aWandererK + ((RotL64(aScatter, 41U) + aOrbiterJ) + RotL64(aOrbiterK, 47U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterJ, 43U)) + aOrbiterE);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 39U) + aOrbiterC) + RotL64(aOrbiterD, 27U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 30U) + RotL64(aOrbiterK, 10U)) + aOrbiterC) + aNonceWordF);
            aWandererF = aWandererF + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 41U)) + aOrbiterD) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 34U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 24U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordK);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 15777U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 14199U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14743U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((aIndex + 11440U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 48U)) + (RotL64(aIngress, 21U) ^ RotL64(aCross, 35U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterC = (((aWandererG + RotL64(aCross, 57U)) + 6024062041314952357U) + aPhaseDOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1]) + aNonceWordF;
            aOrbiterF = (aWandererK + RotL64(aPrevious, 53U)) + 18340757093658015585U;
            aOrbiterG = ((aWandererF + RotL64(aScatter, 18U)) + RotL64(aCarry, 43U)) + 11911120493880346751U;
            aOrbiterI = (aWandererA + RotL64(aIngress, 39U)) + 17428074353884654439U;
            aOrbiterK = ((aWandererH + RotL64(aCross, 13U)) + RotL64(aCarry, 27U)) + 12790849760814795936U;
            aOrbiterH = (aWandererC + RotL64(aIngress, 21U)) + 12633397052172117800U;
            aOrbiterB = (aWandererJ + RotL64(aScatter, 37U)) + 11946150433665237945U;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 42U)) + 16842157900909419285U) + aPhaseDOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = (aWandererE + RotL64(aCross, 47U)) + 14186235783224155962U;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 51U)) + 13284904542579767591U;
            aOrbiterA = (((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 3U)) + 11609181965078844357U) + aNonceWordC;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 9628562297095374984U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 7850281529011259759U;
            aOrbiterG = RotL64((aOrbiterG * 17611485102925470357U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 257458718073794527U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 10693404545773519306U;
            aOrbiterH = RotL64((aOrbiterH * 14821443722828498323U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 3430519236533871460U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 6183054506953198055U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6121082743789970911U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 2905610989884221654U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 4472163910775333862U;
            aOrbiterK = RotL64((aOrbiterK * 7770678426310856745U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 16870142883133769663U) + aNonceWordN;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 1403692060594816451U;
            aOrbiterD = RotL64((aOrbiterD * 9740854430251597879U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 16904169913507057108U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 4773518591580333357U;
            aOrbiterE = RotL64((aOrbiterE * 5306070307776061267U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 6528141733853494275U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 11254806909313951442U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6316669786405548827U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 6857506858448143407U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 2855763534355983644U;
            aOrbiterI = RotL64((aOrbiterI * 16881334940165182415U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 12328391751024624740U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 16475072086109949522U;
            aOrbiterB = RotL64((aOrbiterB * 15218626930666825883U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 15505670341076785424U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 6972128419331939330U;
            aOrbiterJ = RotL64((aOrbiterJ * 12206069109180246067U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 7151546362283646210U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 6024062041314952357U;
            aOrbiterA = RotL64((aOrbiterA * 10243806128059850493U), 53U);
            //
            aIngress = RotL64(aOrbiterC, 4U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 11U));
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aScatter, 19U) + aOrbiterD) + RotL64(aOrbiterI, 21U)) + aPhaseDWandererUpdateSaltF[((aIndex + 8U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 51U) + aOrbiterF) + RotL64(aOrbiterJ, 3U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterI, 11U)) + aOrbiterB) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 23U) + aOrbiterG) + RotL64(aOrbiterE, 35U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 54U) + RotL64(aOrbiterB, 52U)) + aOrbiterG);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 37U)) + aOrbiterA);
            aWandererJ = aWandererJ + (((RotL64(aCross, 37U) + RotL64(aOrbiterI, 57U)) + aOrbiterK) + aNonceWordG);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterH, 27U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterC, 13U)) + aOrbiterK) + RotL64(aCarry, 43U)) + aNonceWordE);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 21U) + aOrbiterF) + RotL64(aOrbiterI, 18U));
            aWandererI = aWandererI + (((RotL64(aCross, 58U) + aOrbiterB) + RotL64(aOrbiterA, 23U)) + aNonceWordB);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 60U));
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 56U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordA);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 21150U)) & S_BLOCK1], 42U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 17639U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19417U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((aIndex + 16834U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 47U) ^ RotL64(aIngress, 35U)) + (RotL64(aPrevious, 4U) ^ RotL64(aCarry, 19U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 13U)) + 9435962834163239322U) + aNonceWordK;
            aOrbiterB = (((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 21U)) + 10524704356081318973U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 24U)) + RotL64(aCarry, 39U)) + 7403401305665208680U;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 57U)) + RotL64(aCarry, 27U)) + 7525414805023556493U;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 19U)) + 1116686470029070951U) + aNonceWordL;
            aOrbiterC = (aWandererA + RotL64(aScatter, 21U)) + 13257612299137802420U;
            aOrbiterK = ((aWandererG + RotL64(aCross, 51U)) + 9181543003986598283U) + aPhaseDOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aIngress, 38U)) + 9739384852307501107U;
            aOrbiterI = (aWandererC + RotL64(aCross, 27U)) + 11308402900229016057U;
            aOrbiterH = (aWandererI + RotL64(aScatter, 35U)) + 14935167593705272337U;
            aOrbiterE = (aWandererK + RotL64(aIngress, 53U)) + 7171824007631943535U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 8068411284829563567U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 12350207458513447578U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 813973258659041895U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 17039236343991574134U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 18291683592714999632U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7771718817924840713U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 6239616841884430968U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 10604527977569876774U;
            aOrbiterC = RotL64((aOrbiterC * 6972820410084939637U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 1707724300671717658U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 3802268808625297647U;
            aOrbiterK = RotL64((aOrbiterK * 11296811630387191563U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 9423064323799920219U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 242153923313096551U;
            aOrbiterF = RotL64((aOrbiterF * 12117679073775630197U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 945801070951928277U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 13094814302414492064U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14638176479878969775U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 7572219725951040117U) + aNonceWordI;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 16494986983782503428U;
            aOrbiterH = RotL64((aOrbiterH * 2739189408707408171U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 10949497978229234856U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 11219643352002119905U;
            aOrbiterE = RotL64((aOrbiterE * 16900635614259262873U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 14245670385849499678U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 13771155918235018585U;
            aOrbiterG = RotL64((aOrbiterG * 14121731385133220921U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 15722734439532828816U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 11032710342174118366U;
            aOrbiterB = RotL64((aOrbiterB * 16096465375397981585U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 2071496769185495150U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 9435962834163239322U;
            aOrbiterD = RotL64((aOrbiterD * 10640995428633266765U), 39U);
            //
            aIngress = RotL64(aOrbiterA, 27U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterD, 51U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 48U));
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aIngress, 35U) + RotL64(aOrbiterF, 18U)) + aOrbiterE);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterJ, 51U));
            aWandererA = aWandererA + ((((RotL64(aCross, 3U) + RotL64(aOrbiterK, 41U)) + aOrbiterF) + RotL64(aCarry, 19U)) + aNonceWordF);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 11U)) + aOrbiterH);
            aWandererI = aWandererI + (((RotL64(aIngress, 41U) + RotL64(aOrbiterD, 21U)) + aOrbiterE) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 30U) + RotL64(aOrbiterE, 43U)) + aOrbiterH) + aNonceWordO) + aPhaseDWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 39U) + aOrbiterD) + RotL64(aOrbiterC, 5U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterJ, 14U)) + aOrbiterA) + aNonceWordD);
            aWandererC = aWandererC + ((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 57U)) + aOrbiterA);
            aWandererB = aWandererB ^ (((RotL64(aCross, 60U) + RotL64(aOrbiterG, 29U)) + aOrbiterE) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 27U) + RotL64(aOrbiterB, 37U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererE, 28U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 50U));
            aCarry = aCarry + RotL64(aWandererA, 53U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 22971U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((aIndex + 25673U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 22508U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26699U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 47U) + RotL64(aCross, 19U)) ^ (RotL64(aCarry, 6U) + RotL64(aIngress, 35U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterA = (aWandererA + RotL64(aScatter, 14U)) + 12615321415808640429U;
            aOrbiterE = ((aWandererG + RotL64(aCross, 11U)) + 15712784676459931207U) + aNonceWordE;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 53U)) + 11013335427004930046U;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 47U)) + 8298733856304768806U;
            aOrbiterK = ((aWandererE + RotL64(aCross, 51U)) + RotL64(aCarry, 39U)) + 6207732959150824216U;
            aOrbiterF = (((aWandererI + RotL64(aIngress, 19U)) + RotL64(aCarry, 43U)) + 9769864876127544038U) + aPhaseDOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 43U)) + 10782181918651152563U) + aPhaseDOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = (aWandererD + RotL64(aPrevious, 21U)) + 5790454015845620939U;
            aOrbiterI = ((aWandererK + RotL64(aCross, 57U)) + 15606578025386733803U) + aNonceWordA;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 28U)) + RotL64(aCarry, 35U)) + 5522352539991175304U;
            aOrbiterD = ((aWandererH + RotL64(aScatter, 3U)) + 5993355818572869649U) + aNonceWordL;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 10864534396947622047U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 12090053126235913528U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7250801471645972261U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 14191181677234981396U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 2258570108233924592U;
            aOrbiterF = RotL64((aOrbiterF * 8307541155393855209U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 8448114811381534603U) + aNonceWordJ;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 2702389315763499817U;
            aOrbiterC = RotL64((aOrbiterC * 6710443836432274393U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 17202184076718780200U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 150549910056015002U;
            aOrbiterB = RotL64((aOrbiterB * 195034681254956335U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 4910512055808124967U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 4783477997418403079U;
            aOrbiterA = RotL64((aOrbiterA * 861977492146512865U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 13842899106208709771U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 7930112618036681468U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8609551859830858419U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 8790107242863198659U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 6882768826643279144U;
            aOrbiterJ = RotL64((aOrbiterJ * 13745521454063360763U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 12136498871759890015U) + aNonceWordC;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 8120456314755584336U;
            aOrbiterI = RotL64((aOrbiterI * 1830725195528043575U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 14425711740351183016U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 15907406009196323049U;
            aOrbiterD = RotL64((aOrbiterD * 8599371693260686839U), 37U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterI) + 4878521420367891861U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordO;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 1184672056055028939U;
            aOrbiterE = RotL64((aOrbiterE * 5963961755367831967U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 10126736568567000180U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 12615321415808640429U;
            aOrbiterK = RotL64((aOrbiterK * 11663715449073755137U), 47U);
            //
            aIngress = RotL64(aOrbiterJ, 51U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 34U));
            aIngress = aIngress + (RotL64(aOrbiterI, 39U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + RotL64(aOrbiterG, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterE, 51U)) + aOrbiterF) + aNonceWordH) + aPhaseDWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 53U) + aOrbiterD) + RotL64(aOrbiterA, 23U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterA, 3U));
            aWandererH = aWandererH + (((RotL64(aScatter, 48U) + RotL64(aOrbiterJ, 56U)) + aOrbiterH) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 51U) + aOrbiterD) + RotL64(aOrbiterI, 47U));
            aWandererK = aWandererK + ((RotL64(aScatter, 35U) + RotL64(aOrbiterG, 27U)) + aOrbiterE);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 41U)) + aOrbiterI);
            aWandererA = aWandererA + ((RotL64(aCross, 58U) + RotL64(aOrbiterH, 29U)) + aOrbiterD);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 27U) + aOrbiterD) + RotL64(aOrbiterE, 58U)) + aPhaseDWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 13U) + RotL64(aOrbiterH, 19U)) + aOrbiterK) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterI, 35U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 36U));
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 18U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordG);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 28648U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32166U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32492U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneB[((aIndex + 32165U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCross, 51U)) + (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 38U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterB = (aWandererK + RotL64(aIngress, 53U)) + 9654059367478508868U;
            aOrbiterJ = (((aWandererF + RotL64(aPrevious, 58U)) + RotL64(aCarry, 37U)) + 6473006635864677427U) + aPhaseDOrbiterAssignSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = (((aWandererG + RotL64(aCross, 37U)) + 6944184481315853243U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordD;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 29U)) + 4061496421939102306U) + aNonceWordI;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 19U)) + 15791809275719085463U) + aNonceWordM;
            aOrbiterG = ((aWandererD + RotL64(aCross, 5U)) + RotL64(aCarry, 13U)) + 14050798802646323055U;
            aOrbiterH = (aWandererA + RotL64(aScatter, 27U)) + 12072905924741758266U;
            aOrbiterC = (aWandererH + RotL64(aPrevious, 39U)) + 17639076509231343896U;
            aOrbiterK = (aWandererI + RotL64(aCross, 23U)) + 12195388285571234715U;
            aOrbiterF = (aWandererE + RotL64(aScatter, 48U)) + 4325404419499496529U;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 3U)) + RotL64(aCarry, 5U)) + 5910567888204238382U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 13092940059929942699U) + aNonceWordA;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 13381962590820308761U;
            aOrbiterA = RotL64((aOrbiterA * 6345904465930943295U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 15622862439323440527U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 14027151901132249793U;
            aOrbiterD = RotL64((aOrbiterD * 2273573821630510087U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 4584410023907605157U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 15763755180625487157U;
            aOrbiterG = RotL64((aOrbiterG * 6755736130607297639U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 17023059745666559199U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 5298529579288492971U;
            aOrbiterH = RotL64((aOrbiterH * 2483562793328357721U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 2870152867331654736U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 12017191100173748848U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9958191466506480519U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 15899529176182436062U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 16482713846343388735U;
            aOrbiterK = RotL64((aOrbiterK * 719465695044265601U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 12943393531812774449U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 9881108254540483225U) ^ aNonceWordJ;
            aOrbiterF = RotL64((aOrbiterF * 8011108108007885059U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 3532054586199716750U) + aNonceWordE;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 7142230313294797435U;
            aOrbiterI = RotL64((aOrbiterI * 14154176174768868421U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 733958394016131587U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 2060800099014517137U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12988885554457108631U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 2278498033811574812U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 15342071118593803929U;
            aOrbiterJ = RotL64((aOrbiterJ * 7842196613533603835U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 12987212219357101955U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 9654059367478508868U;
            aOrbiterE = RotL64((aOrbiterE * 11796100167917742307U), 57U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterJ, 60U);
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + RotL64(aOrbiterH, 24U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 41U) + aOrbiterF) + RotL64(aOrbiterJ, 14U)) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterA, 57U)) + aOrbiterB);
            aWandererG = aWandererG + ((RotL64(aScatter, 38U) + RotL64(aOrbiterJ, 11U)) + aOrbiterG);
            aWandererK = aWandererK ^ ((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterH, 19U));
            aWandererA = aWandererA + (((RotL64(aIngress, 27U) + aOrbiterC) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterE, 29U)) + aOrbiterJ);
            aWandererD = aWandererD + (((RotL64(aScatter, 4U) + RotL64(aOrbiterB, 3U)) + aOrbiterH) + aNonceWordK);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 47U) + aOrbiterI) + RotL64(aOrbiterH, 27U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 53U) + RotL64(aOrbiterD, 35U)) + aOrbiterJ) + aPhaseDWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 21U) + aOrbiterB) + RotL64(aOrbiterK, 46U));
            aWandererF = aWandererF + (((RotL64(aScatter, 11U) + aOrbiterC) + RotL64(aOrbiterB, 37U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 44U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 21U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordE);
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

void TwistExpander_Soccer_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xB9F8149C1C6E2367ULL + 0x9E128707D7D54DDAULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xA02B5A51A1FA6929ULL + 0xF11688158C00AB76ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xC4E2ECA5D535EB65ULL + 0xCA5E0A3E20CCFB87ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xDDD62B3CD48CDCAFULL + 0xAC87969C0A9DD5AEULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x91B4A293AC872D9DULL + 0xEE9E3F60C116BCB2ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xC0EF9A9EE068FF95ULL + 0xC0DE109A40B49FDCULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xE2CCD75434017E1BULL + 0xCC91ECBB2F4DAC2DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xDA3A86A856FD56C3ULL + 0xA36E8CF8A407D7C0ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xDC08EE734EFF73E7ULL + 0xDA575D330031DED2ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xEECB0334CC3D5F89ULL + 0x97913B22C3EA8E1CULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xF779F02FCC96448FULL + 0xE5129BA207A414F8ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xB6A147BB5ACB8EC1ULL + 0xC6A18AA5EA40F115ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xDD3A0013D9A6C7CDULL + 0xF8AA579C4C1ABCA1ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xAA88F24A1A5AABD1ULL + 0xC0E796646C302619ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x8328BC34C5FDA9B7ULL + 0xD3D18156D0E1A7C4ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x96E933500706424FULL + 0xA9A30CD856B49CFAULL);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 4770U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 2347U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 4189U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 2967U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aIngress, 39U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCarry, 52U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterH = (aWandererK + RotL64(aIngress, 41U)) + 7896237440058555694U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 23U)) + 11870529476037558635U;
            aOrbiterC = (aWandererE + RotL64(aCross, 44U)) + 9158983227801569448U;
            aOrbiterA = (aWandererF + RotL64(aPrevious, 13U)) + 4710172270996950329U;
            aOrbiterK = (((aWandererB + RotL64(aIngress, 19U)) + RotL64(aCarry, 21U)) + 14634482800356647630U) + aPhaseEOrbiterAssignSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aCross, 51U)) + 8822207952170610891U) + aNonceWordF;
            aOrbiterD = (((aWandererG + RotL64(aScatter, 21U)) + RotL64(aCarry, 43U)) + 13755891414028982553U) + aPhaseEOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aPrevious, 39U)) + 4555293067488040719U;
            aOrbiterB = (aWandererH + RotL64(aIngress, 53U)) + 2816805148093762081U;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 48U)) + RotL64(aCarry, 13U)) + 2122631477965135190U;
            aOrbiterG = (aWandererC + RotL64(aScatter, 35U)) + 4592922416380416071U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 7102471666524164715U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 17274623547879474204U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5443572270546181789U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 938587316977094680U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 18258015823797023523U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6068819567674605919U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 5809987756043471595U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 5083075160112581620U;
            aOrbiterH = RotL64((aOrbiterH * 3313957222154937503U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 5960021727750946496U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 5967477320950630150U;
            aOrbiterA = RotL64((aOrbiterA * 330964768256424655U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 6578428711689296132U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 5601728218197771276U;
            aOrbiterD = RotL64((aOrbiterD * 9552559022315971847U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 7923809409017855241U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 16479366540906497019U;
            aOrbiterB = RotL64((aOrbiterB * 7118578387798460919U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 17000467091738009736U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 6801634573655508028U;
            aOrbiterG = RotL64((aOrbiterG * 10584635770060137089U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 123668445682719574U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 14462802805503986316U;
            aOrbiterI = RotL64((aOrbiterI * 12398236364304875941U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 2433338393261685871U) + aNonceWordD;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 13869012262404991729U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12443261517483942937U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 4832421585086516998U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 11284414949564414958U;
            aOrbiterE = RotL64((aOrbiterE * 1586650935440790991U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 17872556812561387030U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 7896237440058555694U;
            aOrbiterJ = RotL64((aOrbiterJ * 16784165278693056013U), 27U);
            //
            aIngress = RotL64(aOrbiterH, 60U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterB, 37U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 46U) + RotL64(aOrbiterJ, 27U)) + aOrbiterH) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 51U) + aOrbiterJ) + RotL64(aOrbiterF, 47U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 43U) + aOrbiterB) + RotL64(aOrbiterK, 43U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterK, 56U)) + aOrbiterF);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 27U) + aOrbiterK) + RotL64(aOrbiterE, 51U));
            aWandererF = aWandererF + (((RotL64(aScatter, 30U) + aOrbiterC) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterK, 19U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 21U) + RotL64(aOrbiterB, 35U)) + aOrbiterA);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 39U) + aOrbiterG) + RotL64(aOrbiterE, 24U));
            aWandererG = aWandererG + (((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterI, 5U)) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterD, 37U)) + aOrbiterA) + aNonceWordC);
            //
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 24U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = aCarry ^ aNonceWordG;
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 8779U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneD[((aIndex + 7542U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 5716U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 6814U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCross, 18U)) ^ (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 39U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterF = (aWandererE + RotL64(aScatter, 29U)) + 3199575576585871314U;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 51U)) + 2533378188975571824U) + aNonceWordL;
            aOrbiterK = (aWandererC + RotL64(aCross, 39U)) + 6819782112558312658U;
            aOrbiterD = (aWandererK + RotL64(aPrevious, 47U)) + 12690060987724798497U;
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 21U)) + 7088375139715629606U) + aNonceWordP;
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 58U)) + RotL64(aCarry, 35U)) + 17785618677423695666U;
            aOrbiterJ = ((aWandererD + RotL64(aCross, 41U)) + RotL64(aCarry, 19U)) + 1714999280296491277U;
            aOrbiterH = (((aWandererG + RotL64(aScatter, 5U)) + RotL64(aCarry, 29U)) + 17611338506932491624U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aPrevious, 43U)) + 6475727359297421201U;
            aOrbiterB = (aWandererF + RotL64(aCross, 37U)) + 2347744591204119530U;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 54U)) + 2739317903351401068U) + aPhaseEOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 8663535261373274338U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 8205245127823536479U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13857005110466856439U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 8916510616749754516U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 3944805940148512932U;
            aOrbiterE = RotL64((aOrbiterE * 18082271583211389701U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 14094751253118853302U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 14094299829196076311U;
            aOrbiterI = RotL64((aOrbiterI * 6370012560657108493U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 3940673811518673802U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 3015106523254484839U;
            aOrbiterJ = RotL64((aOrbiterJ * 9655401190755573379U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 15404103131982599922U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 1828655763233900875U;
            aOrbiterA = RotL64((aOrbiterA * 13024358077740310049U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 1236981890899916502U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 18208975564570342697U;
            aOrbiterF = RotL64((aOrbiterF * 4577109989465876801U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 17882273895471449661U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 16196010765612713713U;
            aOrbiterD = RotL64((aOrbiterD * 15624856645134182005U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 14639250100311162559U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 9139027997336903273U) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 1853126389565574293U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 16848571995585465845U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 15901000078517800358U;
            aOrbiterH = RotL64((aOrbiterH * 11617866400577762383U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 9405166641274108606U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 6776079798531281127U;
            aOrbiterB = RotL64((aOrbiterB * 6914644957401512339U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 15056085197286596847U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 3199575576585871314U;
            aOrbiterG = RotL64((aOrbiterG * 15940936753708416817U), 27U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 13U);
            aIngress = aIngress + (RotL64(aOrbiterH, 43U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 58U));
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + RotL64(aOrbiterD, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterA, 20U)) + aOrbiterE) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 37U) + aOrbiterI) + RotL64(aOrbiterF, 43U)) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterK, 37U));
            aWandererE = aWandererE + ((RotL64(aCross, 11U) + aOrbiterG) + RotL64(aOrbiterA, 29U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 46U) + aOrbiterD) + RotL64(aOrbiterF, 23U)) + aPhaseEWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 35U) + RotL64(aOrbiterB, 5U)) + aOrbiterG);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 53U) + aOrbiterC) + RotL64(aOrbiterK, 41U)) + aNonceWordJ);
            aWandererG = aWandererG + (((RotL64(aPrevious, 39U) + aOrbiterC) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 58U) + RotL64(aOrbiterH, 3U)) + aOrbiterI);
            aWandererD = aWandererD + ((RotL64(aIngress, 23U) + aOrbiterD) + RotL64(aOrbiterJ, 26U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterF, 53U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererI, 38U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 4U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordE);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 12841U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneA[((aIndex + 14485U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 11004U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 13131U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 54U) + RotL64(aCross, 37U)) ^ (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 19U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterK = ((aWandererD + RotL64(aIngress, 29U)) + 1898718075389870739U) + aNonceWordJ;
            aOrbiterJ = (aWandererF + RotL64(aScatter, 13U)) + 5631794889237247403U;
            aOrbiterB = (aWandererE + RotL64(aPrevious, 18U)) + 18219714659484524607U;
            aOrbiterI = (aWandererA + RotL64(aCross, 35U)) + 15419581386225732921U;
            aOrbiterC = (aWandererK + RotL64(aScatter, 51U)) + 9125575431710198210U;
            aOrbiterH = ((aWandererH + RotL64(aIngress, 21U)) + RotL64(aCarry, 23U)) + 12205871520544965505U;
            aOrbiterG = (aWandererJ + RotL64(aCross, 39U)) + 7617534300497343422U;
            aOrbiterA = (aWandererB + RotL64(aPrevious, 41U)) + 18017579105368135814U;
            aOrbiterF = (((aWandererI + RotL64(aCross, 48U)) + RotL64(aCarry, 57U)) + 10693882161946020042U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = (((aWandererC + RotL64(aIngress, 3U)) + 11669615701700895306U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 43U)) + RotL64(aCarry, 41U)) + 11045110212889232165U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 18019107802806469913U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 12315940560472528716U;
            aOrbiterB = RotL64((aOrbiterB * 4505122470351404065U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 4899009736070044310U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 17412253404253730364U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10791901166391946485U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 4826286251927854181U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 4523455921321845084U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14534103906736598099U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 4132514462154182215U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 7164745605985109269U) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 14107325508977225261U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 6297434295807635654U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 8813887638672996646U;
            aOrbiterA = RotL64((aOrbiterA * 17495632530773158201U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 11086381278955626084U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 5660733992573928887U) ^ aNonceWordK;
            aOrbiterE = RotL64((aOrbiterE * 11248164458720777889U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 14851044686208609882U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 12707776386060264479U;
            aOrbiterK = RotL64((aOrbiterK * 4470919091467313071U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 11508023384209716657U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 11752973809740920034U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10212754472298834769U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 16746821150860017820U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 9659421716296641396U;
            aOrbiterG = RotL64((aOrbiterG * 7530071874978553673U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 3192309064305104593U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 11409078048681398061U;
            aOrbiterF = RotL64((aOrbiterF * 14991409124701807765U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 315359495275427324U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 1898718075389870739U;
            aOrbiterD = RotL64((aOrbiterD * 13126661894614781343U), 41U);
            //
            aIngress = RotL64(aOrbiterD, 35U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + RotL64(aOrbiterJ, 24U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterD, 53U)) + aOrbiterB);
            aWandererC = aWandererC + (((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterG, 48U)) + RotL64(aCarry, 21U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterA, 51U)) + aNonceWordM);
            aWandererI = aWandererI + (((RotL64(aPrevious, 6U) + RotL64(aOrbiterG, 39U)) + aOrbiterF) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterB, 43U)) + aOrbiterA);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 39U) + aOrbiterE) + RotL64(aOrbiterJ, 60U)) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterC, 57U)) + aOrbiterI);
            aWandererA = aWandererA + ((RotL64(aPrevious, 23U) + aOrbiterJ) + RotL64(aOrbiterI, 23U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 29U)) + aOrbiterK) + aNonceWordC);
            aWandererE = aWandererE + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterH, 21U)) + aOrbiterI) + aNonceWordI);
            aWandererG = aWandererG ^ (((RotL64(aCross, 36U) + aOrbiterJ) + RotL64(aOrbiterH, 11U)) + aPhaseEWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 50U));
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + RotL64(aWandererJ, 41U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordH);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 21567U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneB[((aIndex + 20798U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 19483U)) & S_BLOCK1], 40U) ^ RotL64(aWorkLaneD[((aIndex + 20403U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 22U) ^ RotL64(aCross, 3U)) + (RotL64(aIngress, 53U) ^ RotL64(aCarry, 37U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterB = (aWandererB + RotL64(aPrevious, 35U)) + 2177539223979303669U;
            aOrbiterH = (aWandererK + RotL64(aScatter, 56U)) + 3962004686551521471U;
            aOrbiterG = (((aWandererG + RotL64(aCross, 27U)) + 8457602312617147662U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordI;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 23U)) + 18011802451816510632U) + aPhaseEOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aPrevious, 3U)) + 9046101759168876832U;
            aOrbiterE = ((aWandererA + RotL64(aCross, 21U)) + RotL64(aCarry, 57U)) + 11135620637431969597U;
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 11U)) + 15913029940697999701U) + aNonceWordF;
            aOrbiterC = (((aWandererC + RotL64(aIngress, 5U)) + RotL64(aCarry, 47U)) + 16304193109948135982U) + aNonceWordO;
            aOrbiterD = (aWandererJ + RotL64(aCross, 13U)) + 13208892298820080981U;
            aOrbiterA = (aWandererF + RotL64(aPrevious, 50U)) + 4182377898949419225U;
            aOrbiterF = ((aWandererI + RotL64(aScatter, 19U)) + RotL64(aCarry, 41U)) + 13970137023071326151U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 8402396284835248583U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 8859190834060657829U) ^ aNonceWordN;
            aOrbiterG = RotL64((aOrbiterG * 13552418608113716117U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 9760005337757990392U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 14108277760135744897U;
            aOrbiterI = RotL64((aOrbiterI * 4474681104256093885U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 12226316121949012350U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 3456392186754113960U;
            aOrbiterE = RotL64((aOrbiterE * 8704729827929941215U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 5004087958637038973U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 7176881295123125567U;
            aOrbiterJ = RotL64((aOrbiterJ * 15272157962928021009U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 10889800478505074438U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 13728832441482547824U;
            aOrbiterC = RotL64((aOrbiterC * 17588477761978646139U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 17345665880706866772U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 301139993853297566U;
            aOrbiterD = RotL64((aOrbiterD * 5812445396758354505U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 2061389844760610160U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 13631862266139238355U;
            aOrbiterA = RotL64((aOrbiterA * 143613352104722701U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 10767186080827509622U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 4893486019456886013U;
            aOrbiterF = RotL64((aOrbiterF * 5194746459545610901U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 11264795916303477037U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 16013652139405432608U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14924257021089920495U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 5209743554932653849U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 13160179712987277456U;
            aOrbiterH = RotL64((aOrbiterH * 5003755912040281427U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 12440615920191945386U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 2177539223979303669U;
            aOrbiterK = RotL64((aOrbiterK * 3565122523239344029U), 51U);
            //
            aIngress = RotL64(aOrbiterK, 43U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 36U));
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterJ, 39U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterI, 35U)) + aOrbiterD);
            aWandererH = aWandererH + ((((RotL64(aCross, 22U) + RotL64(aOrbiterC, 11U)) + aOrbiterJ) + RotL64(aCarry, 53U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterD, 19U)) + aOrbiterK);
            aWandererA = aWandererA + (((RotL64(aScatter, 27U) + RotL64(aOrbiterB, 52U)) + aOrbiterE) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterG, 41U)) + aOrbiterI);
            aWandererC = aWandererC + (((RotL64(aScatter, 5U) + RotL64(aOrbiterH, 23U)) + aOrbiterF) + aPhaseEWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 35U) + aOrbiterH) + RotL64(aOrbiterJ, 3U)) + aNonceWordB);
            aWandererI = aWandererI + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterB, 27U)) + aOrbiterH);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 56U) + aOrbiterE) + RotL64(aOrbiterA, 57U));
            aWandererG = aWandererG + (((RotL64(aScatter, 53U) + RotL64(aOrbiterD, 37U)) + aOrbiterB) + aNonceWordP);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterC, 14U)) + aNonceWordA);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 40U));
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 60U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordE);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 25404U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((aIndex + 26055U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 23276U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24887U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aIngress, 39U)) + (RotL64(aCross, 13U) + RotL64(aPrevious, 54U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterF = (aWandererG + RotL64(aScatter, 27U)) + 6467297102954816305U;
            aOrbiterH = ((aWandererC + RotL64(aCross, 39U)) + 7921154109831114952U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aIngress, 19U)) + 5701131763215638919U) + aNonceWordK;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 24U)) + 10022999076719002684U;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 53U)) + RotL64(aCarry, 3U)) + 4367135243038982316U;
            aOrbiterB = (aWandererJ + RotL64(aCross, 3U)) + 14445846824810383592U;
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 35U)) + RotL64(aCarry, 21U)) + 7683697954545773253U;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 51U)) + RotL64(aCarry, 39U)) + 17517006750428030899U;
            aOrbiterD = (((aWandererI + RotL64(aIngress, 14U)) + 2052484792684025476U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordH;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 5U)) + 6279463052085808926U) + aNonceWordC;
            aOrbiterC = (aWandererE + RotL64(aCross, 37U)) + 679280153651813684U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 2939516520188460569U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 1960616434964712325U;
            aOrbiterG = RotL64((aOrbiterG * 15145998415466343039U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 12273819390719947361U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 5685033154709449397U;
            aOrbiterB = RotL64((aOrbiterB * 9845666295874714959U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 9314494172199500653U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 15757631834636427621U;
            aOrbiterK = RotL64((aOrbiterK * 15483543888965744529U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 10878078046389399574U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 3583495913766365232U;
            aOrbiterE = RotL64((aOrbiterE * 2913540984990155225U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 7385544065754622301U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 16839599460207922881U;
            aOrbiterF = RotL64((aOrbiterF * 240651605910592561U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 13038163804940349251U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 2587538594933924000U;
            aOrbiterI = RotL64((aOrbiterI * 3091149760401278671U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 13109518583364738004U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 2447689055742474261U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12100180201235703193U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 5752044906692668618U) + aNonceWordP;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 6637725371036522120U) ^ aNonceWordI;
            aOrbiterD = RotL64((aOrbiterD * 6021986525167161115U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 16549229877442298618U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 12825651879441561108U;
            aOrbiterC = RotL64((aOrbiterC * 9079931351967033993U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 16088338999978085987U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterK) ^ 12584648360998154782U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterH = RotL64((aOrbiterH * 2109996837220975261U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 7526256599938771686U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 6467297102954816305U;
            aOrbiterA = RotL64((aOrbiterA * 9289442676936248653U), 21U);
            //
            aIngress = RotL64(aOrbiterA, 41U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 26U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 12U)) + aOrbiterK);
            aWandererC = aWandererC + (((RotL64(aPrevious, 35U) + aOrbiterA) + RotL64(aOrbiterF, 23U)) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 53U) + aOrbiterA) + RotL64(aOrbiterH, 5U));
            aWandererI = aWandererI + ((RotL64(aScatter, 18U) + RotL64(aOrbiterC, 47U)) + aOrbiterB);
            aWandererE = aWandererE ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterK, 21U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltE[((aIndex + 10U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 57U) + aOrbiterF) + RotL64(aOrbiterH, 53U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 39U) + aOrbiterI) + RotL64(aOrbiterG, 51U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 41U) + aOrbiterI) + RotL64(aOrbiterB, 29U)) + RotL64(aCarry, 23U)) + aNonceWordA);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 44U) + RotL64(aOrbiterD, 34U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltF[((aIndex + 26U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 29U) + aOrbiterE) + RotL64(aOrbiterH, 19U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterF, 57U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 18U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + RotL64(aWandererA, 26U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordC);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 29563U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30526U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 32028U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneB[((aIndex + 28805U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aIngress, 40U)) ^ (RotL64(aCarry, 53U) + RotL64(aPrevious, 5U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterJ = (aWandererH + RotL64(aScatter, 43U)) + 4970414922752555648U;
            aOrbiterI = (aWandererG + RotL64(aPrevious, 47U)) + 9462756592787669327U;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 30U)) + 3948790686662213095U;
            aOrbiterE = (aWandererC + RotL64(aCross, 27U)) + 14542857212241578311U;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 21U)) + RotL64(aCarry, 29U)) + 3387479009827029547U;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 53U)) + 1411421370057797877U;
            aOrbiterH = (aWandererI + RotL64(aCross, 37U)) + 16894451466895681236U;
            aOrbiterF = (aWandererF + RotL64(aIngress, 39U)) + 12727136462290223542U;
            aOrbiterG = (((aWandererA + RotL64(aPrevious, 11U)) + RotL64(aCarry, 47U)) + 4625389198191960525U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = (aWandererK + RotL64(aIngress, 58U)) + 3471881403786164913U;
            aOrbiterK = ((((aWandererE + RotL64(aCross, 13U)) + RotL64(aCarry, 53U)) + 6433115856048534831U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordN;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 9825592965466157982U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 1553125767261293088U) ^ aNonceWordJ;
            aOrbiterC = RotL64((aOrbiterC * 411535191177308781U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 9951616357109647617U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 11231080382787286889U;
            aOrbiterD = RotL64((aOrbiterD * 14024961994986659187U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 13419663264017317947U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 4835055642466215566U;
            aOrbiterB = RotL64((aOrbiterB * 17898065852351759171U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 14558747666410946768U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 13120938960926874504U;
            aOrbiterH = RotL64((aOrbiterH * 5681766019285559739U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 11910501376797343986U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 15074100100781785300U;
            aOrbiterF = RotL64((aOrbiterF * 228976960937473851U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 12415377930578091821U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 14882039078390681802U;
            aOrbiterG = RotL64((aOrbiterG * 13855446647753150713U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 8094338361713756895U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 5478280604704108822U) ^ aNonceWordK;
            aOrbiterA = RotL64((aOrbiterA * 18062931724700600993U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 6977017654546871841U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 4131602217285988962U;
            aOrbiterK = RotL64((aOrbiterK * 11865422227883712419U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 9619228479582032318U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 13506679497441415586U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5789932662418992799U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 10180259475831448124U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 4721628773773094283U;
            aOrbiterI = RotL64((aOrbiterI * 10834196399754443771U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 7898137727558813688U) + aNonceWordL;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 4970414922752555648U;
            aOrbiterE = RotL64((aOrbiterE * 6651835668618579479U), 5U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterE, 47U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + (RotL64(aOrbiterK, 54U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aIngress, 24U) + RotL64(aOrbiterH, 19U)) + aOrbiterI) + aNonceWordA);
            aWandererE = aWandererE ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterE, 51U)) + aOrbiterC) + aNonceWordF);
            aWandererF = aWandererF + (((RotL64(aPrevious, 13U) + aOrbiterG) + RotL64(aOrbiterD, 39U)) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterH, 57U)) + aOrbiterC) + aPhaseEWandererUpdateSaltA[((aIndex + 12U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 47U)) + aOrbiterD);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterK, 60U));
            aWandererC = aWandererC + ((RotL64(aScatter, 50U) + aOrbiterB) + RotL64(aOrbiterA, 21U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 19U) + aOrbiterA) + RotL64(aOrbiterD, 35U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 41U)) + aOrbiterC);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterF, 14U)) + aOrbiterK);
            aWandererB = aWandererB + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterF, 29U)) + aOrbiterJ) + RotL64(aCarry, 47U)) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 46U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 21U));
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 48U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordD);
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

void TwistExpander_Soccer_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x8271C394C2A95D05ULL + 0xC98F7BCB1BD4D3D3ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xF22B739ECB94D8C9ULL + 0xB972C4BD61F4673FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xEF95F11453FD3373ULL + 0xD359BCA221155274ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x84E66F5F96C0B5C7ULL + 0xFF28F051ACF6B220ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xB1A97A3C1CEA16E7ULL + 0xFBAB106657ED6991ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xDB05F9E458C19933ULL + 0x9168CE3E90C7C90BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xF3D9E5A761033187ULL + 0xE2B2198A9F74A041ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xDEA6B606B78457CBULL + 0xEF4956B91CE6013BULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xFD9E9E0888938779ULL + 0x8C4C7A72BA52B301ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x9E56B5FAE555C6EBULL + 0x8AA4416CD008E537ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xDE526155FF765FFFULL + 0x8DDA3511CE0C839EULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xA31CEC523AAC87B5ULL + 0xD1C2DDA43E306A41ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xFA24BB2AEB20F459ULL + 0xE1628698FA666B7AULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x9B5DD3E9AEF3DFDBULL + 0xDA38510242AE90BBULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xE26BD3D00A0D8093ULL + 0x90F9396C2B9FEE70ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xF67E1E30E9E378E9ULL + 0xF6EB694E08C840C5ULL);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 4197U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3166U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 5106U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 2541U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 19U) + RotL64(aPrevious, 54U)) ^ (RotL64(aIngress, 37U) ^ RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = (aWandererH + RotL64(aIngress, 19U)) + 16451272412693907816U;
            aOrbiterG = ((aWandererK + RotL64(aCross, 53U)) + RotL64(aCarry, 53U)) + 10099485419723255462U;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 5U)) + RotL64(aCarry, 39U)) + 17668900099534923192U;
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 14U)) + 5497093724143181753U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aCross, 39U)) + 10354044773550071706U;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 41U)) + 12728258851198019099U;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 37U)) + RotL64(aCarry, 19U)) + 4144050505314242618U;
            aOrbiterC = ((aWandererB + RotL64(aScatter, 51U)) + 14133805325480076530U) + aNonceWordL;
            aOrbiterD = (aWandererE + RotL64(aCross, 21U)) + 308863673210602899U;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 43U)) + 11741180130160569753U) + aNonceWordB;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 58U)) + 12926863156769180448U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 211920854786494259U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 13234608842479411078U;
            aOrbiterA = RotL64((aOrbiterA * 2556747209733759467U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 9164711974854618892U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 6667377062281954219U;
            aOrbiterH = RotL64((aOrbiterH * 2603737166987437649U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 4559040002406721850U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 1749875480850675109U;
            aOrbiterK = RotL64((aOrbiterK * 15822640067349481089U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 9555365165561936366U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 18289733999504213574U;
            aOrbiterJ = RotL64((aOrbiterJ * 14156217554673229429U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 8727162691639622461U) + aNonceWordC;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 291406782452963706U;
            aOrbiterI = RotL64((aOrbiterI * 8413500075082350243U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 8294911802626492257U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 15853578397277298548U;
            aOrbiterD = RotL64((aOrbiterD * 13256191781365357747U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 11535146194939658681U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 2177540476748375661U;
            aOrbiterE = RotL64((aOrbiterE * 15791341922007841029U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 2705306323728084136U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 17617871830709148043U;
            aOrbiterG = RotL64((aOrbiterG * 3449981219502809255U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 3699834746313613206U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 17952609181629473245U) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 6103160209028988839U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 8016694658897707674U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 6971251395823324489U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13483776115929040277U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 17467528888050817915U) + aNonceWordI;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 16451272412693907816U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13689734638238895071U), 47U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterG, 3U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 54U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterD, 13U)) + aOrbiterA) + RotL64(aCarry, 57U)) + aNonceWordJ);
            aWandererI = aWandererI ^ ((RotL64(aCross, 22U) + aOrbiterA) + RotL64(aOrbiterC, 23U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 13U) + aOrbiterF) + RotL64(aOrbiterG, 47U)) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 39U) + aOrbiterC) + RotL64(aOrbiterH, 27U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 53U) + aOrbiterK) + RotL64(aOrbiterB, 51U));
            aWandererH = aWandererH ^ ((((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterJ, 30U)) + aNonceWordA) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 19U) + aOrbiterF) + RotL64(aOrbiterC, 21U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 28U) + RotL64(aOrbiterE, 37U)) + aOrbiterJ);
            aWandererD = aWandererD + (((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterE, 39U)) + aNonceWordP);
            aWandererK = aWandererK ^ (((RotL64(aCross, 11U) + aOrbiterC) + RotL64(aOrbiterK, 5U)) + aPhaseFWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 37U) + RotL64(aOrbiterA, 44U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 52U));
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (RotL64(aWandererC, 38U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordG;
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9792U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneD[((aIndex + 9585U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 9356U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneB[((aIndex + 9195U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 36U) ^ RotL64(aPrevious, 53U)) ^ (RotL64(aCarry, 3U) + RotL64(aIngress, 19U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = (((aWandererD + RotL64(aScatter, 21U)) + RotL64(aCarry, 53U)) + 10038936806177516123U) + aNonceWordG;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 19U)) + RotL64(aCarry, 3U)) + 1773168435195292638U;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 11U)) + 10655711161526628072U) + aPhaseFOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aCross, 13U)) + RotL64(aCarry, 41U)) + 14422295664639740437U;
            aOrbiterF = (aWandererI + RotL64(aIngress, 50U)) + 4125228715513159576U;
            aOrbiterE = (aWandererA + RotL64(aScatter, 35U)) + 3670449653158650845U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 43U)) + 17553727567180813057U;
            aOrbiterI = (aWandererG + RotL64(aPrevious, 57U)) + 5111401772713882743U;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 41U)) + 7688573124662314413U) + aPhaseFOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 30U)) + 9438375825507814395U;
            aOrbiterB = (aWandererE + RotL64(aScatter, 53U)) + 14177477039902118886U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 16329942595859623928U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 3990536794006836672U;
            aOrbiterC = RotL64((aOrbiterC * 579024714339065373U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 5072881436583180756U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 16789727877867289997U;
            aOrbiterG = RotL64((aOrbiterG * 8766246302636197905U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 17313956922306689438U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 11530878396329822041U;
            aOrbiterF = RotL64((aOrbiterF * 11356860047841383129U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 3612616532321160196U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 4172189825359187763U;
            aOrbiterJ = RotL64((aOrbiterJ * 12938945495299393177U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 8677279703778052804U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 1912172980909479362U;
            aOrbiterA = RotL64((aOrbiterA * 10053289257955474143U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 1460085850227494500U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 12116763868122868147U;
            aOrbiterD = RotL64((aOrbiterD * 6076945628020280957U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 17571840610366424432U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 15581362592611080868U;
            aOrbiterK = RotL64((aOrbiterK * 1129054058044872003U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 14434700039977611666U) + aNonceWordJ;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 4534294602623329152U;
            aOrbiterE = RotL64((aOrbiterE * 5860911553425182045U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 865998255725903702U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 16407778704555344108U) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 15571344643129797977U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 1948990288894429805U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 18218556219056835250U;
            aOrbiterH = RotL64((aOrbiterH * 16574160087642377293U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 1309229265173143398U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 10038936806177516123U;
            aOrbiterB = RotL64((aOrbiterB * 12954594462760207923U), 27U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterI, 5U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 48U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + (RotL64(aOrbiterF, 53U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 23U) + aOrbiterK) + RotL64(aOrbiterB, 23U));
            aWandererE = aWandererE + ((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterE, 51U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 21U) + aOrbiterI) + RotL64(aOrbiterC, 47U)) + aNonceWordF);
            aWandererA = aWandererA + (((RotL64(aIngress, 37U) + RotL64(aOrbiterG, 21U)) + aOrbiterH) + aPhaseFWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 34U) + RotL64(aOrbiterI, 11U)) + aOrbiterK);
            aWandererC = aWandererC + (((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterA, 53U)) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 41U) + aOrbiterI) + RotL64(aOrbiterA, 38U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 21U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 58U) + aOrbiterH) + RotL64(aOrbiterF, 43U));
            aWandererF = aWandererF + (((RotL64(aScatter, 39U) + RotL64(aOrbiterH, 41U)) + aOrbiterK) + aNonceWordD);
            aWandererG = aWandererG ^ ((RotL64(aCross, 13U) + aOrbiterA) + RotL64(aOrbiterD, 4U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 20U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + RotL64(aWandererB, 29U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordF);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12722U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11306U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 14823U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 12013U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 54U) ^ RotL64(aCross, 37U)) ^ (RotL64(aPrevious, 3U) + RotL64(aCarry, 19U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterA = (aWandererF + RotL64(aScatter, 23U)) + 13960289014350612206U;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 27U)) + RotL64(aCarry, 39U)) + 3483331015269589730U;
            aOrbiterJ = (((aWandererK + RotL64(aCross, 43U)) + RotL64(aCarry, 47U)) + 6873299241002444518U) + aPhaseFOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = (aWandererE + RotL64(aIngress, 18U)) + 3562094007125534229U;
            aOrbiterF = (aWandererC + RotL64(aPrevious, 3U)) + 11422367439932782705U;
            aOrbiterD = (aWandererG + RotL64(aIngress, 47U)) + 532453428514259816U;
            aOrbiterG = ((aWandererA + RotL64(aCross, 37U)) + 17810941465810193088U) + aNonceWordB;
            aOrbiterI = (((aWandererH + RotL64(aScatter, 5U)) + RotL64(aCarry, 19U)) + 11869759058631106331U) + aPhaseFOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 12U)) + 8837581071876177566U) + aNonceWordF;
            aOrbiterE = (aWandererI + RotL64(aScatter, 41U)) + 17185378327053837778U;
            aOrbiterB = (aWandererD + RotL64(aCross, 29U)) + 7578253375676981500U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 17112646434432814442U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 14949096407295697881U;
            aOrbiterJ = RotL64((aOrbiterJ * 14770977858283051753U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 4259590620758467836U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 6534899413644542303U;
            aOrbiterD = RotL64((aOrbiterD * 7987609419215568661U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 2637407498893694243U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 15819295597921425711U;
            aOrbiterH = RotL64((aOrbiterH * 5202015597375051399U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 6373559542002699718U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 11694562937392022505U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9311557972331218597U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 3308736483775453062U) + aNonceWordM;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 12749929710650475901U;
            aOrbiterI = RotL64((aOrbiterI * 248428400724560945U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 1569528215675579656U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 1044077933631689572U;
            aOrbiterE = RotL64((aOrbiterE * 6443796233912755143U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 8393422728124537471U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 2002732612516530754U;
            aOrbiterA = RotL64((aOrbiterA * 13702146823622364279U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 13469191942843147943U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 7633171368709520560U;
            aOrbiterK = RotL64((aOrbiterK * 9713514012478203047U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 4023206337737491091U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 15990323932023596968U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4816480271959713463U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 837005729394899591U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 9692088757104339973U;
            aOrbiterC = RotL64((aOrbiterC * 17971548293495807419U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 18039464962413134616U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 13960289014350612206U;
            aOrbiterB = RotL64((aOrbiterB * 931609478642506411U), 51U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 41U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 39U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 48U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterA, 41U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 50U) + aOrbiterG) + RotL64(aOrbiterK, 60U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 5U) + aOrbiterE) + RotL64(aOrbiterB, 23U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 29U)) + aOrbiterB);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterB, 43U)) + aOrbiterH) + aPhaseFWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterE, 18U)) + aOrbiterC) + RotL64(aCarry, 11U)) + aNonceWordL);
            aWandererF = aWandererF ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterG, 39U)) + aOrbiterB) + aNonceWordK);
            aWandererG = aWandererG + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterA, 53U)) + aOrbiterH) + aNonceWordA) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterD, 3U)) + aOrbiterG);
            aWandererC = aWandererC + (((RotL64(aScatter, 46U) + RotL64(aOrbiterI, 11U)) + aOrbiterB) + RotL64(aCarry, 3U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 21U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 46U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererF, 3U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 19926U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19113U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18614U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneD[((aIndex + 17763U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aIngress, 20U)) + (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 5U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = (aWandererA + RotL64(aPrevious, 27U)) + 17225673071833726819U;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 5U)) + 10301458382103627331U) + aNonceWordC;
            aOrbiterK = (aWandererB + RotL64(aIngress, 43U)) + 3960233050857362414U;
            aOrbiterA = ((aWandererK + RotL64(aCross, 29U)) + RotL64(aCarry, 19U)) + 17768665685046605837U;
            aOrbiterG = (((aWandererJ + RotL64(aScatter, 23U)) + RotL64(aCarry, 57U)) + 14471018461213959767U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = (aWandererH + RotL64(aPrevious, 36U)) + 10730597892721340453U;
            aOrbiterB = (aWandererE + RotL64(aCross, 11U)) + 14863394003122760542U;
            aOrbiterD = (aWandererG + RotL64(aIngress, 51U)) + 9948587274816688296U;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 41U)) + 3573569431435100993U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = (aWandererD + RotL64(aCross, 13U)) + 8153670675740450590U;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 34U)) + RotL64(aCarry, 11U)) + 16438856577722561424U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 15765587867581925041U) + aNonceWordK;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 1082039522061775213U;
            aOrbiterK = RotL64((aOrbiterK * 17023740047246402641U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 4202521649260798876U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 15877659681260461141U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11369910758551088173U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 2551560426129646123U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 3005102326163906320U;
            aOrbiterE = RotL64((aOrbiterE * 4241583192662435107U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 1675501058857208089U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 12774812270956702043U;
            aOrbiterB = RotL64((aOrbiterB * 5488437008504905105U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 1044886020922563597U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 4857445127457225171U) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 13223560654459705259U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 11548725551787560962U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 2434677823189765161U;
            aOrbiterH = RotL64((aOrbiterH * 4283026044563670969U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 9606875320524736294U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 13732615866277657704U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3905528919281629775U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 13921743663803299567U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 13350829301153929899U;
            aOrbiterJ = RotL64((aOrbiterJ * 11858642286713079795U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 9473349030551400156U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 7446792050826434742U;
            aOrbiterI = RotL64((aOrbiterI * 6619682184124713031U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 17970527747978977453U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 2326714817603921480U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14581676978186226887U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 7875511075130474136U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 17225673071833726819U;
            aOrbiterA = RotL64((aOrbiterA * 1196024136909896027U), 41U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterD, 23U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 56U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterA, 41U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterG, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 60U) + aOrbiterG) + RotL64(aOrbiterF, 37U)) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterA, 3U)) + aPhaseFWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterC, 50U)) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterC, 21U)) + aOrbiterK);
            aWandererE = aWandererE + ((RotL64(aScatter, 18U) + aOrbiterH) + RotL64(aOrbiterK, 47U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterE, 39U)) + aOrbiterH);
            aWandererH = aWandererH + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterH, 19U)) + aOrbiterA);
            aWandererB = aWandererB ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterI, 27U)) + aOrbiterB);
            aWandererK = aWandererK + (((RotL64(aScatter, 37U) + RotL64(aOrbiterB, 23U)) + aOrbiterC) + aNonceWordE);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterC, 11U)) + aPhaseFWandererUpdateSaltF[((aIndex + 8U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterG, 6U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (RotL64(aWandererG, 10U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererC, 34U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordD);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 26408U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((aIndex + 26787U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27093U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 22291U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCarry, 5U)) + (RotL64(aCross, 18U) ^ RotL64(aPrevious, 37U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterB = (((aWandererG + RotL64(aCross, 57U)) + RotL64(aCarry, 57U)) + 10915618884692072446U) + aPhaseFOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 38U)) + RotL64(aCarry, 37U)) + 12634922308499254909U;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 53U)) + 6533934734564499389U) + aNonceWordK;
            aOrbiterK = ((aWandererI + RotL64(aScatter, 11U)) + 6744203303756105181U) + aNonceWordB;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 5U)) + 13086782386652045658U) + aNonceWordC;
            aOrbiterD = (aWandererD + RotL64(aScatter, 60U)) + 5693840533331397822U;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 41U)) + 1803663542535024611U;
            aOrbiterI = (aWandererF + RotL64(aCross, 43U)) + 3597219300593287708U;
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 13U)) + RotL64(aCarry, 21U)) + 1429753448204448904U;
            aOrbiterH = (aWandererA + RotL64(aCross, 29U)) + 17229017825587322715U;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 19U)) + 1137574712801062932U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 2401991077004083378U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 1332473247826139292U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15029831858261506447U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 11730946340796899885U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 15319163439700390962U;
            aOrbiterD = RotL64((aOrbiterD * 1349242001887975499U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 4744141870145159917U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 6067132201862688684U;
            aOrbiterI = RotL64((aOrbiterI * 6046100687757836027U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 14991509179286371800U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 4342608825699398682U;
            aOrbiterH = RotL64((aOrbiterH * 10240526103933275875U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 3727521409410742075U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 3302027219498304367U;
            aOrbiterB = RotL64((aOrbiterB * 12153634588200479559U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 6039539483340398858U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 2902581519976937051U) ^ aNonceWordD;
            aOrbiterK = RotL64((aOrbiterK * 2057584328877854239U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 12332784713738947242U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 13761272577223712786U;
            aOrbiterC = RotL64((aOrbiterC * 14930145045480030821U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 2947946397617043735U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 11107014023853644521U;
            aOrbiterJ = RotL64((aOrbiterJ * 15030903626191481831U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 6212403196992771516U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 16107261731677426470U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13764822942405295129U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 8414111492161335472U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 3625937496991123221U;
            aOrbiterF = RotL64((aOrbiterF * 1736741235159600739U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 5466667339391480293U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 10915618884692072446U;
            aOrbiterG = RotL64((aOrbiterG * 14719282928172086707U), 37U);
            //
            aIngress = RotL64(aOrbiterC, 29U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterA, 54U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterH, 50U)) + aOrbiterA);
            aWandererD = aWandererD + (((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterI, 19U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 5U) + aOrbiterH) + RotL64(aOrbiterI, 29U)) + aPhaseFWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 13U)) + aOrbiterC) + aNonceWordF);
            aWandererF = aWandererF ^ ((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterA, 39U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 39U) + aOrbiterF) + RotL64(aOrbiterB, 54U)) + RotL64(aCarry, 29U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 60U) + aOrbiterE) + RotL64(aOrbiterC, 35U));
            aWandererK = aWandererK + ((RotL64(aIngress, 41U) + aOrbiterB) + RotL64(aOrbiterG, 3U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterE, 11U)) + aOrbiterJ) + aNonceWordP);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 11U) + RotL64(aOrbiterI, 43U)) + aOrbiterG) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 26U) + aOrbiterF) + RotL64(aOrbiterG, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 54U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + RotL64(aWandererB, 11U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordJ);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28175U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28239U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32557U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30659U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 42U) ^ RotL64(aCross, 23U)) + (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 5U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = (aWandererH + RotL64(aIngress, 29U)) + 2915859148137000694U;
            aOrbiterC = (aWandererB + RotL64(aScatter, 27U)) + 210680583721444425U;
            aOrbiterF = ((aWandererI + RotL64(aCross, 58U)) + 6668118118775650387U) + aNonceWordI;
            aOrbiterA = ((((aWandererC + RotL64(aPrevious, 23U)) + RotL64(aCarry, 23U)) + 15794200818099010989U) + aPhaseFOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1]) + aNonceWordO;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 3U)) + 6565076707062828369U) + aNonceWordA;
            aOrbiterG = ((aWandererF + RotL64(aCross, 51U)) + RotL64(aCarry, 35U)) + 16323164497808856719U;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 40U)) + RotL64(aCarry, 3U)) + 7965435318816716560U;
            aOrbiterI = (aWandererE + RotL64(aPrevious, 13U)) + 7390281030573369017U;
            aOrbiterJ = (aWandererG + RotL64(aScatter, 19U)) + 2269738866911824875U;
            aOrbiterH = ((aWandererJ + RotL64(aCross, 21U)) + 9664014216039993873U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = (aWandererK + RotL64(aIngress, 53U)) + 18284857398028357633U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 367667619795303009U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 7935945060956274197U;
            aOrbiterF = RotL64((aOrbiterF * 5481786693511955209U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 16683666162337789540U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 10655658270998102390U;
            aOrbiterB = RotL64((aOrbiterB * 15231596813382239841U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 8307037916581540297U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 3247742749860703524U;
            aOrbiterG = RotL64((aOrbiterG * 15052136713218656641U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 10446792483683818139U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 16374602929344972364U;
            aOrbiterD = RotL64((aOrbiterD * 12599903932725787599U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 2411334498322777183U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 1093701164116833765U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13129220206835381729U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 17018480952982840635U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 17348395690080029814U;
            aOrbiterJ = RotL64((aOrbiterJ * 6212591395713433257U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 16111252311283623152U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 12776492920397785951U;
            aOrbiterH = RotL64((aOrbiterH * 6136009241593081821U), 23U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterJ) + 12214538600808144816U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1]) + aNonceWordG;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 10043377462096783363U;
            aOrbiterE = RotL64((aOrbiterE * 14639467375095185877U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 5101561512438055661U) + aNonceWordF;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 3683207847147603335U;
            aOrbiterK = RotL64((aOrbiterK * 14355438383379198639U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 14446947359104987749U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 7596096688268335354U;
            aOrbiterC = RotL64((aOrbiterC * 13522935803383107145U), 19U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterK) + 14015424109468938015U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordD;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 2915859148137000694U;
            aOrbiterA = RotL64((aOrbiterA * 3653144205211106817U), 11U);
            //
            aIngress = RotL64(aOrbiterJ, 35U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 24U));
            aIngress = aIngress + RotL64(aOrbiterG, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 41U) + aOrbiterJ) + RotL64(aOrbiterF, 47U)) + aPhaseFWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 50U) + RotL64(aOrbiterK, 57U)) + aOrbiterC);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterG, 19U));
            aWandererG = aWandererG + ((RotL64(aCross, 5U) + aOrbiterF) + RotL64(aOrbiterH, 29U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 37U) + aOrbiterI) + RotL64(aOrbiterC, 50U));
            aWandererD = aWandererD + (((RotL64(aCross, 53U) + aOrbiterE) + RotL64(aOrbiterG, 53U)) + RotL64(aCarry, 21U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 39U)) + aOrbiterB) + aNonceWordH);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 5U)) + aOrbiterH) + RotL64(aCarry, 43U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterE, 11U));
            aWandererH = aWandererH + ((RotL64(aCross, 14U) + RotL64(aOrbiterC, 35U)) + aOrbiterH);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 26U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (RotL64(aWandererJ, 26U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 43U);
            aCarry = aCarry + RotL64(aIngress, 24U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordE);
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

void TwistExpander_Soccer_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xB73E78FC8A15F119ULL + 0x8F724D39DB05BC59ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xFB20361F9BBC9185ULL + 0xA6F6BD9E81651976ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x8A7939B0C2CED883ULL + 0xF997821141251728ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x9E8AD0FAECC92EC5ULL + 0xEE9D30027ADEF175ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xEE674C01541731ABULL + 0xA8D1716C1C032D29ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x8A9E41BA6B6FE48FULL + 0xB4EDC39D6BCCB6EEULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x8A767AC2C2403605ULL + 0xF4F9D9661EA3797DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xF51E3F7976C0044FULL + 0xDBE207C95B7F124DULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x972945360B6F280FULL + 0xB142FE20C248F85BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xBD345B7DEDC4D03FULL + 0xC31FBFC302E331BFULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xAA128B5756DE1455ULL + 0xE2C7E2CFD7336CBBULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x8CB56BB6D8BE8407ULL + 0xFE9BF0EF9324BF8CULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xC8ED7C68165C852DULL + 0xB3208E7AC610F5F5ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xBDD7B3C0C69AC013ULL + 0xB7F6EE2F88EAC473ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x9B5F6C541C6ECE7DULL + 0xF117250D0F517791ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x985175CCA86FFECFULL + 0xC294C0ABD8E61113ULL);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 3285U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 2327U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 1239U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 3560U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aIngress, 54U)) ^ (RotL64(aCarry, 3U) + RotL64(aPrevious, 21U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = (aWandererB + RotL64(aPrevious, 57U)) + 1142447269198373880U;
            aOrbiterD = ((aWandererH + RotL64(aIngress, 27U)) + RotL64(aCarry, 39U)) + 10581460640040336191U;
            aOrbiterI = ((aWandererG + RotL64(aScatter, 3U)) + 14703062773878202900U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aCross, 41U)) + 15737525756286914746U;
            aOrbiterJ = (aWandererD + RotL64(aScatter, 48U)) + 16178774478273186999U;
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 51U)) + RotL64(aCarry, 23U)) + 2514897053906809160U;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 37U)) + 13702496607592508464U) + aNonceWordA;
            aOrbiterG = ((aWandererA + RotL64(aCross, 23U)) + RotL64(aCarry, 43U)) + 18030885275418337965U;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 10U)) + 5241783876161655984U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 5U)) + 2807052676283587925U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = (aWandererC + RotL64(aCross, 53U)) + 8022804576763271327U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 15597099852232205860U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 1538435607932096400U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7900752511710516981U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 11147868774413615365U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 9325213746830411568U;
            aOrbiterB = RotL64((aOrbiterB * 561819005818948769U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 13792300423550555634U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 3134856508983945719U;
            aOrbiterE = RotL64((aOrbiterE * 4271845067763664863U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 8654966018053784882U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 8937113935476779267U;
            aOrbiterF = RotL64((aOrbiterF * 7386875687217705855U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 4135676350355234788U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 11407912615743682678U;
            aOrbiterK = RotL64((aOrbiterK * 2773506587480714695U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 10966950663872392059U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 6686634993700944582U) ^ aNonceWordJ;
            aOrbiterC = RotL64((aOrbiterC * 2509459942163678241U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 14154407529749257990U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 18054640398549782388U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7830759861389060149U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 14623473030642960240U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 1857945571104460086U) ^ aNonceWordH;
            aOrbiterD = RotL64((aOrbiterD * 18039903315045620079U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 17650774450811065797U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 9458168381246672881U;
            aOrbiterJ = RotL64((aOrbiterJ * 3452665113988737563U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 16604923466236483242U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 12447748535184711684U;
            aOrbiterG = RotL64((aOrbiterG * 5982708155382249061U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 9589720286549780720U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 1142447269198373880U;
            aOrbiterA = RotL64((aOrbiterA * 8176719948031280789U), 35U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 30U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 37U));
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterC, 53U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 26U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterK, 27U)) + aOrbiterE) + aNonceWordF);
            aWandererC = aWandererC + ((RotL64(aScatter, 53U) + RotL64(aOrbiterC, 13U)) + aOrbiterF);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 34U) + RotL64(aOrbiterC, 50U)) + aOrbiterE) + aPhaseFWandererUpdateSaltF[((aIndex + 22U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 5U) + RotL64(aOrbiterB, 29U)) + aOrbiterG) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterG, 23U));
            aWandererD = aWandererD + (((RotL64(aCross, 29U) + RotL64(aOrbiterB, 43U)) + aOrbiterH) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterJ, 11U)) + aOrbiterG);
            aWandererA = aWandererA + (((RotL64(aIngress, 37U) + aOrbiterJ) + RotL64(aOrbiterH, 41U)) + aNonceWordN);
            aWandererE = aWandererE ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterD, 57U)) + aOrbiterA);
            aWandererF = aWandererF + ((RotL64(aScatter, 11U) + aOrbiterC) + RotL64(aOrbiterD, 48U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 18U) + aOrbiterI) + RotL64(aOrbiterB, 53U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 58U));
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + (RotL64(aWandererB, 40U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordG);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 6736U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8421U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7129U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 10432U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aIngress, 51U)) ^ (RotL64(aPrevious, 27U) + RotL64(aCross, 6U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = (aWandererI + RotL64(aIngress, 50U)) + 15316464782468770057U;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 13U)) + 6642872057476351588U) + aNonceWordA;
            aOrbiterC = (aWandererE + RotL64(aScatter, 29U)) + 660732654689529192U;
            aOrbiterE = (aWandererA + RotL64(aCross, 19U)) + 7235418086884000655U;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 56U)) + 14784518476694580493U;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 23U)) + 12222433977933449375U) + aNonceWordJ;
            aOrbiterD = ((aWandererG + RotL64(aCross, 5U)) + 8573001207708329927U) + aNonceWordH;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 3U)) + RotL64(aCarry, 27U)) + 16035256260815013172U;
            aOrbiterB = (((aWandererC + RotL64(aPrevious, 35U)) + RotL64(aCarry, 53U)) + 15767726974121910203U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = ((aWandererD + RotL64(aCross, 27U)) + 17712217935322939971U) + aPhaseFOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aIngress, 21U)) + RotL64(aCarry, 3U)) + 13488963456923357159U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 10222949131965611079U) + aNonceWordD;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 1495561412321657209U;
            aOrbiterC = RotL64((aOrbiterC * 9706305581868526265U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 16156530750584361434U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 7773792489045606309U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10730624207715601393U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 11544578291333360613U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 3665587867634242865U;
            aOrbiterK = RotL64((aOrbiterK * 4840528190844842595U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 15248434984650998090U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 15487979645426567581U;
            aOrbiterD = RotL64((aOrbiterD * 10868107809356766183U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 6972347795052712690U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 16074994810010431338U) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 1262655238856775853U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 16851139687900415292U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 14630026837021552812U;
            aOrbiterI = RotL64((aOrbiterI * 9577900853521254603U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 14236330619137368169U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 17778707026111136216U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16239561893843454747U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 9390961969105999083U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 1174881758316573228U;
            aOrbiterG = RotL64((aOrbiterG * 6602061268277529311U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 3025148570039849574U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 2813499258480831171U;
            aOrbiterA = RotL64((aOrbiterA * 12272555492688861861U), 43U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterH) + 15397952138592662354U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1]) + aNonceWordL;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 10394648143430175275U;
            aOrbiterF = RotL64((aOrbiterF * 18195627209519212303U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 3043205345760158739U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 15316464782468770057U;
            aOrbiterH = RotL64((aOrbiterH * 8162506622688910545U), 27U);
            //
            aIngress = RotL64(aOrbiterI, 37U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 24U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + RotL64(aOrbiterE, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterI, 57U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 23U) + aOrbiterH) + RotL64(aOrbiterD, 14U)) + aPhaseFWandererUpdateSaltC[((aIndex + 22U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 37U) + aOrbiterK) + RotL64(aOrbiterE, 11U)) + aNonceWordG);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 56U) + RotL64(aOrbiterF, 5U)) + aOrbiterG) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterG, 19U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterC, 23U)) + aOrbiterJ);
            aWandererE = aWandererE + ((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 21U)) + aOrbiterE);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterD, 46U)) + aOrbiterE);
            aWandererG = aWandererG + (((RotL64(aIngress, 4U) + aOrbiterJ) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 41U) + aOrbiterB) + RotL64(aOrbiterC, 35U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterG, 37U)) + aOrbiterA) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 60U));
            aCarry = aCarry + (RotL64(aWandererB, 21U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 14U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordD);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 14316U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneA[((aIndex + 14461U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 16289U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 14872U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 11U)) + (RotL64(aCross, 40U) + RotL64(aIngress, 23U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterB = ((aWandererD + RotL64(aIngress, 53U)) + 1364174714924216027U) + aNonceWordG;
            aOrbiterF = (aWandererC + RotL64(aPrevious, 51U)) + 13561796874229506613U;
            aOrbiterC = (aWandererI + RotL64(aScatter, 47U)) + 11845572344206238305U;
            aOrbiterA = ((aWandererE + RotL64(aCross, 3U)) + RotL64(aCarry, 29U)) + 15762708240326773763U;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 5U)) + RotL64(aCarry, 19U)) + 1157119665207900473U;
            aOrbiterD = (((aWandererK + RotL64(aPrevious, 35U)) + RotL64(aCarry, 3U)) + 6823546624372055260U) + aPhaseFOrbiterAssignSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aScatter, 40U)) + 14465564210523945121U) + aPhaseFOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aCross, 43U)) + 10667464548080807531U;
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 23U)) + 13445737493224316575U;
            aOrbiterG = (aWandererH + RotL64(aCross, 19U)) + 3009837893785957665U;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 56U)) + 2886920524111083752U) + aNonceWordO;
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 10886177449328249656U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 15067759884678100433U;
            aOrbiterC = RotL64((aOrbiterC * 5724566815989860041U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 18307930462682331536U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 8791864377579255801U;
            aOrbiterD = RotL64((aOrbiterD * 9265158882471421767U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 805797468642992351U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterE) ^ 5743305867058244964U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 16263000753351131717U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 17102025528234481273U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 1841579177327486899U;
            aOrbiterI = RotL64((aOrbiterI * 3841603385577825265U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 2189493507896508972U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 18209567010094914374U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3737080408976852351U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 6697069234216868330U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 927471474577415372U;
            aOrbiterG = RotL64((aOrbiterG * 10680760991009199309U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 13155854301197725408U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 1014625081915435892U;
            aOrbiterB = RotL64((aOrbiterB * 11592754232949990435U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 12697209921410914931U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 11555096613655648647U;
            aOrbiterA = RotL64((aOrbiterA * 4598821388864997089U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 9335308231651271690U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 3160859883353473444U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4753600703924906409U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 15681189182414315768U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 3147692210581710663U;
            aOrbiterJ = RotL64((aOrbiterJ * 6271949093080510861U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 5373388632562432117U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 1364174714924216027U;
            aOrbiterH = RotL64((aOrbiterH * 4694926665965807945U), 21U);
            //
            aIngress = RotL64(aOrbiterF, 53U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 56U));
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + RotL64(aOrbiterB, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 50U) + aOrbiterK) + RotL64(aOrbiterJ, 6U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterB, 47U)) + aOrbiterF) + RotL64(aCarry, 13U)) + aPhaseFWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 11U) + aOrbiterC) + RotL64(aOrbiterH, 19U)) + aNonceWordN);
            aWandererC = aWandererC + ((RotL64(aCross, 23U) + aOrbiterF) + RotL64(aOrbiterD, 43U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterJ, 13U)) + aOrbiterD) + aNonceWordK);
            aWandererJ = aWandererJ + (((RotL64(aCross, 38U) + RotL64(aOrbiterC, 51U)) + aOrbiterK) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterJ, 28U)) + aOrbiterG);
            aWandererH = aWandererH + ((RotL64(aPrevious, 5U) + aOrbiterI) + RotL64(aOrbiterK, 53U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterE, 21U)) + aOrbiterH) + aNonceWordF);
            aWandererA = aWandererA + (((RotL64(aCross, 13U) + RotL64(aOrbiterB, 11U)) + aOrbiterG) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterA, 57U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + (RotL64(aWandererB, 18U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererE, 41U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 19711U)) & S_BLOCK1], 46U) ^ RotL64(aOperationLaneB[((aIndex + 21696U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 18860U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 17449U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 13U) ^ RotL64(aCarry, 56U)) + (RotL64(aCross, 29U) + RotL64(aIngress, 43U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 11U)) + 13687218104610230596U) + aNonceWordH;
            aOrbiterJ = (aWandererH + RotL64(aCross, 39U)) + 6841550124960692709U;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 30U)) + 17418968668458764131U) + aNonceWordL;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 27U)) + RotL64(aCarry, 53U)) + 8303537912696948204U;
            aOrbiterH = (aWandererK + RotL64(aCross, 19U)) + 12376614417285936537U;
            aOrbiterI = (aWandererF + RotL64(aPrevious, 37U)) + 14215749063579232654U;
            aOrbiterB = ((aWandererE + RotL64(aScatter, 53U)) + RotL64(aCarry, 19U)) + 4111736931433665347U;
            aOrbiterC = ((aWandererD + RotL64(aIngress, 41U)) + 11250375934571631522U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aCross, 24U)) + 5367367837773331275U) + aNonceWordK;
            aOrbiterA = (((aWandererC + RotL64(aPrevious, 57U)) + RotL64(aCarry, 43U)) + 15514089192382674434U) + aPhaseFOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = (aWandererA + RotL64(aScatter, 43U)) + 1475991716685034960U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 5531622777788629748U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 8363822215908303335U;
            aOrbiterE = RotL64((aOrbiterE * 17850203366840994883U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 3741256932685720414U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 11634667238062155772U) ^ aNonceWordI;
            aOrbiterH = RotL64((aOrbiterH * 15925089729784547403U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 18180546911210417155U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 5123234656838556335U;
            aOrbiterI = RotL64((aOrbiterI * 15362857462853398025U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 11215734271189250284U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 16863747802158398092U;
            aOrbiterB = RotL64((aOrbiterB * 1828035970246160023U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 9859050606636646323U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterH) ^ 9331300036643654675U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterC = RotL64((aOrbiterC * 2502263410556166281U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 15028845665427209759U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 8916444839488901676U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6646561894156038791U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 8024631140949068570U) + aNonceWordJ;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 1116378858490660031U;
            aOrbiterA = RotL64((aOrbiterA * 4247798531910227367U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 5066486214537899212U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 9346312092322423057U;
            aOrbiterD = RotL64((aOrbiterD * 13443190089768875191U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 11651011617027950122U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 11308862427412671711U;
            aOrbiterK = RotL64((aOrbiterK * 12167147966934334703U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 3850136281462840708U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 13461307727665667424U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10788040812090673421U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 17824744996404571928U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 13687218104610230596U;
            aOrbiterG = RotL64((aOrbiterG * 325803029547254631U), 29U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterA, 3U);
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 22U));
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aIngress, 51U) + aOrbiterF) + RotL64(aOrbiterJ, 3U)) + aNonceWordB);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 21U) + aOrbiterH) + RotL64(aOrbiterC, 40U)) + RotL64(aCarry, 19U)) + aNonceWordE);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 58U) + RotL64(aOrbiterB, 43U)) + aOrbiterC);
            aWandererE = aWandererE + ((RotL64(aScatter, 37U) + RotL64(aOrbiterJ, 13U)) + aOrbiterA);
            aWandererG = aWandererG ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterK, 51U)) + aOrbiterF);
            aWandererB = aWandererB + ((((RotL64(aIngress, 39U) + RotL64(aOrbiterB, 27U)) + aOrbiterE) + RotL64(aCarry, 11U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterG, 35U)) + aOrbiterJ);
            aWandererD = aWandererD + ((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterI, 19U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 3U) + aOrbiterD) + RotL64(aOrbiterE, 37U)) + aPhaseFWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterK, 24U)) + aOrbiterE) + aNonceWordM);
            aWandererC = aWandererC ^ ((RotL64(aCross, 14U) + aOrbiterJ) + RotL64(aOrbiterH, 29U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + (RotL64(aWandererK, 12U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 50U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23869U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneA[((aIndex + 25744U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 24090U)) & S_BLOCK1], 46U) ^ RotL64(aOperationLaneA[((aIndex + 25139U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aIngress, 24U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCross, 39U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = ((aWandererK + RotL64(aScatter, 47U)) + 13442819395490639310U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = (aWandererG + RotL64(aIngress, 58U)) + 8187292523194120936U;
            aOrbiterF = (aWandererH + RotL64(aPrevious, 41U)) + 11469697159823131388U;
            aOrbiterA = (aWandererA + RotL64(aCross, 35U)) + 13414083692375929653U;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 43U)) + 11404010733687907517U;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 54U)) + 6783212827186218247U) + aNonceWordC;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 51U)) + RotL64(aCarry, 11U)) + 8561131439340372614U;
            aOrbiterH = ((aWandererF + RotL64(aIngress, 13U)) + RotL64(aCarry, 51U)) + 6252609642004429113U;
            aOrbiterJ = ((aWandererE + RotL64(aCross, 37U)) + 12804867444200448952U) + aNonceWordD;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 27U)) + 2739648749603690781U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 39U)) + RotL64(aCarry, 23U)) + 14808861217017399752U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 17588866502571268888U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 5882260142735642980U;
            aOrbiterF = RotL64((aOrbiterF * 7688252946143263869U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 15493099088132862949U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 5175647411532429582U;
            aOrbiterI = RotL64((aOrbiterI * 15226544495598541883U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 14279707376173642767U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 6826363572161275158U;
            aOrbiterH = RotL64((aOrbiterH * 5263708315440161809U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 13267185753040999992U) + aNonceWordG;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 9980987858092888720U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13210290848800728635U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 3582972937645514549U) + aNonceWordL;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 10140409019562890804U;
            aOrbiterD = RotL64((aOrbiterD * 6944490201647678479U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 6160444117287330557U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 16344602960561293113U;
            aOrbiterA = RotL64((aOrbiterA * 2319964919335633293U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 3497141036108337171U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 91269118352540308U;
            aOrbiterK = RotL64((aOrbiterK * 5160060720189045505U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 12739932748793144857U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 12820180915064791197U;
            aOrbiterJ = RotL64((aOrbiterJ * 5843849637411948699U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 17572075652083359962U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 10684041099654982701U;
            aOrbiterG = RotL64((aOrbiterG * 7121293375756263771U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 10739534650885677354U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 9731206787727954809U;
            aOrbiterC = RotL64((aOrbiterC * 3730875775588585547U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 9655432616347117764U) + aNonceWordP;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 13442819395490639310U;
            aOrbiterE = RotL64((aOrbiterE * 3650859301708619119U), 13U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterB, 41U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + (RotL64(aOrbiterA, 10U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterH, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterK, 53U)) + aOrbiterI) + aNonceWordE);
            aWandererH = aWandererH + (((RotL64(aCross, 58U) + RotL64(aOrbiterI, 41U)) + aOrbiterA) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 21U) + aOrbiterB) + RotL64(aOrbiterF, 43U));
            aWandererF = aWandererF + ((RotL64(aScatter, 35U) + RotL64(aOrbiterJ, 50U)) + aOrbiterI);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterH, 35U)) + aOrbiterK);
            aWandererD = aWandererD + ((((RotL64(aCross, 47U) + aOrbiterI) + RotL64(aOrbiterD, 29U)) + aNonceWordN) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 41U) + aOrbiterG) + RotL64(aOrbiterC, 3U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 37U)) + aOrbiterC) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 37U) + aOrbiterK) + RotL64(aOrbiterE, 5U));
            aWandererK = aWandererK + (((RotL64(aCross, 51U) + RotL64(aOrbiterB, 60U)) + aOrbiterE) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 4U) + aOrbiterG) + RotL64(aOrbiterH, 57U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 26U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 60U));
            aCarry = aCarry + RotL64(aWandererA, 21U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ aNonceWordD;
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30522U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32204U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28345U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((aIndex + 27306U)) & S_BLOCK1], 40U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 34U) + RotL64(aCross, 3U)) ^ (RotL64(aPrevious, 21U) ^ RotL64(aCarry, 47U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = (aWandererD + RotL64(aScatter, 41U)) + 13204735390996728477U;
            aOrbiterK = ((aWandererI + RotL64(aCross, 47U)) + 851171359595647173U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 13U)) + RotL64(aCarry, 35U)) + 16745304202825290723U;
            aOrbiterB = (((aWandererG + RotL64(aIngress, 51U)) + RotL64(aCarry, 27U)) + 562392736584913979U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = (((aWandererA + RotL64(aCross, 37U)) + RotL64(aCarry, 43U)) + 3244267012529053918U) + aNonceWordB;
            aOrbiterF = (aWandererC + RotL64(aScatter, 27U)) + 17282536111067869133U;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 56U)) + 14851130066471729068U;
            aOrbiterE = (aWandererK + RotL64(aIngress, 23U)) + 5256130407952363129U;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 11U)) + 2904742485828362001U) + aNonceWordO;
            aOrbiterC = (aWandererB + RotL64(aIngress, 19U)) + 3723346325449225387U;
            aOrbiterD = (aWandererE + RotL64(aCross, 30U)) + 5344621093694027341U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 12919263300833603026U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 17989801264160996071U;
            aOrbiterJ = RotL64((aOrbiterJ * 15468293047311883751U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 5022175042377172157U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 16684822380107847758U;
            aOrbiterG = RotL64((aOrbiterG * 2834049270263837537U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 2740326510600876682U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 13981423865219318820U;
            aOrbiterF = RotL64((aOrbiterF * 14593082145080056441U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 231945878229848395U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 14139797734944312580U;
            aOrbiterH = RotL64((aOrbiterH * 6492256080432266407U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 16704102101387552373U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 8506734780526852552U;
            aOrbiterE = RotL64((aOrbiterE * 4684566118627414659U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 2774630043988894695U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 12490034334296488127U;
            aOrbiterA = RotL64((aOrbiterA * 16765455396278233145U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 545238171291436006U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 1023872898002379590U;
            aOrbiterC = RotL64((aOrbiterC * 8626333831510136515U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 5065187021047872560U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 10391809965648089863U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10912471108849550469U), 39U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterC) + 5576919045471579002U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 9761904001375034639U;
            aOrbiterI = RotL64((aOrbiterI * 8612901811320541361U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 2001472279505185946U) + aNonceWordK;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 11576457012366242134U;
            aOrbiterK = RotL64((aOrbiterK * 1070815118051466731U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 17713147845216099336U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 13204735390996728477U;
            aOrbiterB = RotL64((aOrbiterB * 10889281795183444943U), 43U);
            //
            aIngress = RotL64(aOrbiterA, 11U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 24U));
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + RotL64(aOrbiterD, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aIngress, 23U) + aOrbiterK) + RotL64(aOrbiterA, 39U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 11U)) + aOrbiterJ) + aNonceWordI);
            aWandererA = aWandererA + (((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterD, 5U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 21U) + aOrbiterH) + RotL64(aOrbiterJ, 37U));
            aWandererC = aWandererC + (((RotL64(aScatter, 39U) + aOrbiterK) + RotL64(aOrbiterG, 21U)) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 30U) + RotL64(aOrbiterC, 41U)) + aOrbiterG);
            aWandererE = aWandererE + ((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterE, 48U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterB, 3U));
            aWandererH = aWandererH + ((RotL64(aCross, 37U) + aOrbiterI) + RotL64(aOrbiterK, 43U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 28U) + aOrbiterF) + RotL64(aOrbiterB, 51U)) + aPhaseFWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 28U)) + aOrbiterJ) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 60U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + RotL64(aWandererC, 41U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ aNonceWordL;
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

void TwistExpander_Soccer_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 3337U)) & S_BLOCK1], 50U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 1803U)) & W_KEY1], 19U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 2979U)) & W_KEY1], 11U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 4084U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aIngress, 19U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCarry, 42U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = ((aWandererD + RotL64(aScatter, 23U)) + RotL64(aCarry, 51U)) + 7948891781097675369U;
            aOrbiterA = (aWandererC + RotL64(aIngress, 35U)) + 13928362874228230226U;
            aOrbiterI = (aWandererA + RotL64(aCross, 19U)) + 10776180542602258926U;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 47U)) + RotL64(aCarry, 3U)) + 5735115172149470447U;
            aOrbiterG = (aWandererK + RotL64(aCross, 54U)) + 5353591822981766987U;
            aOrbiterK = (aWandererB + RotL64(aScatter, 27U)) + 562301708107268570U;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 13U)) + 10467810247578364868U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aIngress, 3U)) + RotL64(aCarry, 43U)) + 14541630141152308564U;
            aOrbiterE = ((aWandererI + RotL64(aCross, 60U)) + 2350076897065139429U) + aPhaseCOrbiterAssignSaltA[((aIndex + 24U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 17519109078651162228U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 6061035173339902910U;
            aOrbiterI = RotL64((aOrbiterI * 10021905773432907835U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 15654836633731000065U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 13723521735153718904U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14459516479283070563U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 2849680038315532197U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 17336102435576647923U;
            aOrbiterB = RotL64((aOrbiterB * 10984689101753586739U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 7671010488872356142U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 11485114338165600777U;
            aOrbiterE = RotL64((aOrbiterE * 4162584865462407791U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 8759060657343458985U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 11009137869375286581U;
            aOrbiterC = RotL64((aOrbiterC * 8741417343929809115U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 15792999392743144135U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 6180808423175992479U;
            aOrbiterJ = RotL64((aOrbiterJ * 13681230339693676907U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 361487389591183005U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 15292753806514404853U;
            aOrbiterH = RotL64((aOrbiterH * 17478232597253311153U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 14929153438443362045U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 7904556383593914086U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2484130486635511403U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 3793180909904286848U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 10391957637467171320U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 505484041943467117U), 57U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterC, 26U);
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterC, 56U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 38U) + RotL64(aOrbiterE, 43U)) + aOrbiterJ) + aPhaseCWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterG, 19U)) + aOrbiterB) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 5U) + aOrbiterK) + RotL64(aOrbiterH, 27U));
            aWandererE = aWandererE + ((RotL64(aIngress, 51U) + aOrbiterK) + RotL64(aOrbiterA, 52U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 43U) + aOrbiterG) + RotL64(aOrbiterE, 3U));
            aWandererK = aWandererK + (((RotL64(aCross, 47U) + aOrbiterH) + RotL64(aOrbiterJ, 47U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 34U) + RotL64(aOrbiterH, 23U)) + aOrbiterI);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 35U)) + aOrbiterA) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 12U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 16370U)) & S_BLOCK1], 60U) ^ RotL64(mSource[((aIndex + 9274U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 14493U)) & W_KEY1], 46U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 13899U)) & W_KEY1], 13U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCarry, 57U)) ^ (RotL64(aPrevious, 11U) + RotL64(aCross, 28U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = ((aWandererH + RotL64(aCross, 24U)) + RotL64(aCarry, 53U)) + 8020711767807230555U;
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 3U)) + 15368693777246341570U) + aPhaseCOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = ((aWandererG + RotL64(aScatter, 19U)) + RotL64(aCarry, 13U)) + 5117523734225562401U;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 57U)) + 13155269151097507808U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (aWandererJ + RotL64(aScatter, 34U)) + 9879303753623578272U;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 51U)) + RotL64(aCarry, 21U)) + 1165799257173794826U;
            aOrbiterJ = (aWandererA + RotL64(aCross, 13U)) + 930641942062732091U;
            aOrbiterB = (aWandererB + RotL64(aIngress, 47U)) + 11330571332221123153U;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 43U)) + 2862963158282518899U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 6019186399361476659U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 1924419843785161958U;
            aOrbiterH = RotL64((aOrbiterH * 9485557122500346869U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 12618629043591380461U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 9334176504266512405U;
            aOrbiterG = RotL64((aOrbiterG * 18239109235362925739U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 16829692481030013551U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 5604784396927022709U;
            aOrbiterJ = RotL64((aOrbiterJ * 2833893610883508353U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 16124030106598549644U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 16571659812830230677U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4668250364992383549U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 15171089673591843703U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 2826755560293849328U;
            aOrbiterC = RotL64((aOrbiterC * 9397017963457655287U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 9976785768283589291U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 11845100564714691809U;
            aOrbiterE = RotL64((aOrbiterE * 4935139932585319251U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 7318560453127859950U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 3039196878830506712U;
            aOrbiterI = RotL64((aOrbiterI * 3140508261330698717U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 8850992055588337843U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 4219373528176869146U;
            aOrbiterD = RotL64((aOrbiterD * 1310964742529956743U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 1341474458715938799U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 15937557372891732898U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11437307017920192915U), 19U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterI, 37U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterE, 56U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 11U) + aOrbiterH) + RotL64(aOrbiterI, 51U)) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 48U) + aOrbiterC) + RotL64(aOrbiterK, 3U)) + aPhaseCWandererUpdateSaltB[((aIndex + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterG, 56U)) + RotL64(aCarry, 29U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterE, 11U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 27U) + aOrbiterI) + RotL64(aOrbiterG, 23U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterB, 35U)) + aOrbiterK);
            aWandererC = aWandererC + ((RotL64(aScatter, 35U) + aOrbiterJ) + RotL64(aOrbiterI, 27U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 54U) + aOrbiterD) + RotL64(aOrbiterH, 40U));
            aWandererB = aWandererB + ((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 19U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 30U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23667U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 17289U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 21395U)) & W_KEY1], 46U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 18965U)) & W_KEY1], 13U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 51U) ^ RotL64(aPrevious, 6U)) + (RotL64(aIngress, 23U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 38U)) + 4773124477323378268U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 29U)) + 16848723289435796005U;
            aOrbiterA = (aWandererF + RotL64(aPrevious, 29U)) + 13846642134917107058U;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 47U)) + RotL64(aCarry, 5U)) + 6472057872482789939U;
            aOrbiterF = (aWandererH + RotL64(aCross, 53U)) + 2747019500690707226U;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 19U)) + RotL64(aCarry, 39U)) + 9003965289739733880U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 23U)) + 3013390651936257377U) + aPhaseCOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = (aWandererD + RotL64(aScatter, 58U)) + 3331004709895625067U;
            aOrbiterB = (aWandererG + RotL64(aPrevious, 43U)) + 15355010435553517129U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 7709870658004280052U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 13568728443963926564U;
            aOrbiterA = RotL64((aOrbiterA * 6736090830113688981U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 12409548853419307131U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 969183352023661537U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5549220554838837145U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 15370309834426476775U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 3896803894396631184U;
            aOrbiterH = RotL64((aOrbiterH * 11018830202891911603U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 10848873633291935766U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 12885336509190543440U;
            aOrbiterG = RotL64((aOrbiterG * 1487357252619221365U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 8252290890093788010U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 9201553615601641350U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 420321130559162915U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 14014209645503188472U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 4015071464301844550U;
            aOrbiterD = RotL64((aOrbiterD * 17444195018239904971U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 16173085647514027347U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 16916627014974363360U;
            aOrbiterI = RotL64((aOrbiterI * 7699587344277490953U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 1591680303404522110U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 16499606051269327916U;
            aOrbiterJ = RotL64((aOrbiterJ * 814405848002794813U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 6932673635509444619U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 8745681160108707944U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14565255558668084787U), 47U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterB, 19U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 39U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 14U));
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 23U) + aOrbiterJ) + RotL64(aOrbiterA, 5U));
            aWandererH = aWandererH + ((((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterB, 11U)) + RotL64(aCarry, 53U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 28U) + aOrbiterD) + RotL64(aOrbiterF, 41U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterH, 28U)) + aOrbiterA);
            aWandererG = aWandererG ^ ((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterB, 19U));
            aWandererC = aWandererC + ((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterB, 35U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 43U) + aOrbiterF) + RotL64(aOrbiterC, 47U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 19U) + aOrbiterD) + RotL64(aOrbiterG, 60U)) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 48U) + aOrbiterI) + RotL64(aOrbiterJ, 53U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererC, 60U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 26021U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24732U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25457U)) & S_BLOCK1], 21U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 31253U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 43U) + RotL64(aCarry, 58U)) ^ (RotL64(aIngress, 11U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = ((aWandererC + RotL64(aScatter, 29U)) + RotL64(aCarry, 53U)) + 18180797995100240808U;
            aOrbiterE = (aWandererH + RotL64(aCross, 57U)) + 6585906608223552885U;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 53U)) + 14088708930575939855U;
            aOrbiterJ = (aWandererB + RotL64(aIngress, 36U)) + 468974153311516044U;
            aOrbiterC = (aWandererE + RotL64(aScatter, 23U)) + 12481951025619894110U;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 13U)) + 17227987923860711763U) + aPhaseCOrbiterAssignSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 47U)) + RotL64(aCarry, 21U)) + 4373962756657477139U;
            aOrbiterG = (aWandererD + RotL64(aCross, 40U)) + 2077576476565420951U;
            aOrbiterH = (((aWandererJ + RotL64(aIngress, 19U)) + RotL64(aCarry, 41U)) + 17435011300234663764U) + aPhaseCOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 4118039398293246896U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 13724716599855216683U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17556333902751079677U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 12391461204689596339U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 9900605191533799627U;
            aOrbiterC = RotL64((aOrbiterC * 13553565332531046301U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 972946858824366125U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 17247681919694541215U;
            aOrbiterD = RotL64((aOrbiterD * 2974639094630445643U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 15442851427306771601U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 7303586227288294037U;
            aOrbiterF = RotL64((aOrbiterF * 15406402525021428799U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 12650358753454105119U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 1483710933373510492U;
            aOrbiterJ = RotL64((aOrbiterJ * 6531763256577221891U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 18065810162229740788U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 11311677121338794007U;
            aOrbiterA = RotL64((aOrbiterA * 15116367961682119467U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 2355285311890287611U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 1287783821903407734U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8054011680932255985U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 9282654686791135654U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 15488608017745542551U;
            aOrbiterH = RotL64((aOrbiterH * 7858866274035085123U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 13296835576073421802U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 7127700236018338741U;
            aOrbiterE = RotL64((aOrbiterE * 11246173563106014149U), 29U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 13U);
            aIngress = aIngress + (RotL64(aOrbiterD, 30U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 23U) + aOrbiterG) + RotL64(aOrbiterD, 10U)) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 60U) + aOrbiterG) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 47U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterB, 39U)) + aOrbiterF);
            aWandererG = aWandererG + ((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 47U)) + aOrbiterC);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterF, 34U)) + aOrbiterJ);
            aWandererB = aWandererB + (((RotL64(aCross, 27U) + RotL64(aOrbiterE, 43U)) + aOrbiterJ) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterF, 19U)) + aOrbiterA);
            aWandererF = aWandererF + ((RotL64(aIngress, 18U) + RotL64(aOrbiterF, 53U)) + aOrbiterH);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterD, 27U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 38U));
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + RotL64(aWandererE, 35U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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

void TwistExpander_Soccer_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterJ = 0;

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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2570U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3997U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 358U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 6893U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 27U) + RotL64(aCarry, 4U)) ^ (RotL64(aCross, 39U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = ((aWandererB + RotL64(aCross, 11U)) + RotL64(aCarry, 3U)) + 9080426856729228705U;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 24U)) + RotL64(aCarry, 23U)) + 7851218321653539276U;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 35U)) + RotL64(aCarry, 37U)) + 7023344692919298036U;
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 47U)) + 9772846154227440734U) + aPhaseDOrbiterAssignSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aIngress, 3U)) + 12008298632429608431U) + aPhaseDOrbiterAssignSaltD[((aIndex + 24U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 12201090455849562875U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 9498721803411445471U;
            aOrbiterC = RotL64((aOrbiterC * 6511810500788451775U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 351203764023093632U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 4966360430644539250U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10138518378274592739U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 9194167899071345693U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 4922477697284269116U;
            aOrbiterI = RotL64((aOrbiterI * 8444814161720407881U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 15742625291642356429U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 7528703106518431730U;
            aOrbiterF = RotL64((aOrbiterF * 11530049278751507567U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 15279053574704935317U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 2425839793660355555U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11486964816849830667U), 5U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 3U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + RotL64(aOrbiterD, 52U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 51U) + aOrbiterI) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterD, 47U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterC, 11U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 6U) + RotL64(aOrbiterF, 56U)) + aOrbiterI);
            aWandererG = aWandererG + (((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterF, 29U)) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + RotL64(aWandererD, 21U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 8668U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13188U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14669U)) & S_BLOCK1], 42U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9078U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCross, 57U)) + (RotL64(aCarry, 41U) ^ RotL64(aIngress, 10U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = ((aWandererG + RotL64(aIngress, 57U)) + RotL64(aCarry, 29U)) + 11998579547770778580U;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 12U)) + 8409465187298704610U) + aPhaseDOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = (((aWandererJ + RotL64(aCross, 37U)) + RotL64(aCarry, 5U)) + 3470222286110333500U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aScatter, 27U)) + 5704486785203069994U;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 47U)) + RotL64(aCarry, 43U)) + 10334944660253279633U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 7626852700722567477U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 14631310754943209743U;
            aOrbiterE = RotL64((aOrbiterE * 1958866541508493967U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 807160297237854120U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 5624154783624196107U;
            aOrbiterG = RotL64((aOrbiterG * 2404066593958052159U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 4971444394698940423U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 6340057638461027062U;
            aOrbiterI = RotL64((aOrbiterI * 12027586111086798629U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 9003019862787819481U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 13632057463595873033U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12575202147280216765U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 12766104026871797746U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 4062118445824915939U;
            aOrbiterA = RotL64((aOrbiterA * 13130770039048080701U), 3U);
            //
            aIngress = RotL64(aOrbiterE, 37U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + RotL64(aOrbiterJ, 6U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aScatter, 56U) + RotL64(aOrbiterG, 43U)) + aOrbiterE) + RotL64(aCarry, 47U)) + aPhaseDWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 5U)) + aOrbiterG);
            aWandererJ = aWandererJ + (((RotL64(aCross, 19U) + RotL64(aOrbiterI, 56U)) + aOrbiterA) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 27U) + aOrbiterA) + RotL64(aOrbiterG, 29U));
            aWandererI = aWandererI + (((RotL64(aCross, 3U) + RotL64(aOrbiterI, 19U)) + aOrbiterJ) + aPhaseDWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + RotL64(aWandererH, 58U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 18368U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneA[((aIndex + 20018U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18291U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneC[((aIndex + 17028U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCross, 19U)) + (RotL64(aCarry, 35U) + RotL64(aIngress, 50U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = (((aWandererD + RotL64(aCross, 3U)) + RotL64(aCarry, 41U)) + 9630214189402543339U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = (((aWandererK + RotL64(aIngress, 30U)) + RotL64(aCarry, 11U)) + 4072576573737526819U) + aPhaseDOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 51U)) + RotL64(aCarry, 57U)) + 15994787452709618869U;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 41U)) + 6403240137132259482U;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 13U)) + 10229266900170507720U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 5025294577989748989U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 16696461238217956883U;
            aOrbiterC = RotL64((aOrbiterC * 15993828976234917577U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 9878318855341719119U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 16086635438116177346U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5585682357395705671U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 12295437783084203730U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 7681150419912842402U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7289497379725191451U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 2639104034287637448U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 12298170009332243573U;
            aOrbiterG = RotL64((aOrbiterG * 9397919591171238575U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 3485932317267669626U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 16569551670038752475U;
            aOrbiterJ = RotL64((aOrbiterJ * 8139802826402217631U), 21U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 57U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + RotL64(aOrbiterG, 22U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 20U)) + aOrbiterC);
            aWandererD = aWandererD + ((((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterG, 39U)) + RotL64(aCarry, 51U)) + aPhaseDWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterI, 29U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterC, 57U)) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 6U) + RotL64(aOrbiterJ, 11U)) + aOrbiterG) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 28U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 24822U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27963U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30318U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 24715U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCarry, 5U)) ^ (RotL64(aIngress, 43U) ^ RotL64(aCross, 22U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = (aWandererF + RotL64(aScatter, 43U)) + 8975885703279267062U;
            aOrbiterD = (((aWandererJ + RotL64(aCross, 51U)) + RotL64(aCarry, 21U)) + 8664844915562660637U) + aPhaseDOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aIngress, 3U)) + RotL64(aCarry, 37U)) + 12281774799736296726U;
            aOrbiterC = (((aWandererD + RotL64(aPrevious, 12U)) + RotL64(aCarry, 51U)) + 15347461352311329726U) + aPhaseDOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aIngress, 23U)) + 12967500561828907834U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 5002833859280402726U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 11908257536954668983U;
            aOrbiterG = RotL64((aOrbiterG * 4384790916151202785U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 17017174811949227162U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 16851323125613931180U;
            aOrbiterH = RotL64((aOrbiterH * 12446990992858763577U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 13469326957728686706U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 5228638551056105241U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13369947664646167255U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 11945166198089308564U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 16268645041872996022U;
            aOrbiterD = RotL64((aOrbiterD * 5391448793718370911U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 14781204627695095701U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 5365325354838101092U;
            aOrbiterI = RotL64((aOrbiterI * 8017284997946310807U), 13U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterH, 3U);
            aIngress = aIngress + (RotL64(aOrbiterD, 39U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterH, 56U)) + aOrbiterI) + RotL64(aCarry, 57U)) + aPhaseDWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 60U) + aOrbiterC) + RotL64(aOrbiterG, 27U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 35U)) + aOrbiterD) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 51U) + aOrbiterC) + RotL64(aOrbiterI, 3U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 5U) + aOrbiterC) + RotL64(aOrbiterH, 11U)) + aPhaseDWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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

void TwistExpander_Soccer_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 7619U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 1379U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 68U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneA[((aIndex + 7707U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCross, 41U)) + (RotL64(aCarry, 27U) + RotL64(aIngress, 6U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = ((aWandererC + RotL64(aIngress, 13U)) + 5697928251815176134U) + aPhaseEOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (aWandererK + RotL64(aPrevious, 57U)) + 337587740689259575U;
            aOrbiterB = (aWandererI + RotL64(aCross, 3U)) + 4927686903263973950U;
            aOrbiterG = ((aWandererE + RotL64(aScatter, 41U)) + RotL64(aCarry, 57U)) + 3742409032569801033U;
            aOrbiterH = (aWandererD + RotL64(aIngress, 22U)) + 1608092659172197650U;
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 35U)) + RotL64(aCarry, 21U)) + 15848744267145717509U;
            aOrbiterK = (((aWandererG + RotL64(aCross, 51U)) + RotL64(aCarry, 35U)) + 15300174177963339253U) + aPhaseEOrbiterAssignSaltE[((aIndex + 16U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 14162868453323648628U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 12020167069983729869U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2071080217680099017U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 16259538291658723956U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 8516686212464112245U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4731296903548893627U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 3722184575520553132U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 5663609293306386784U;
            aOrbiterJ = RotL64((aOrbiterJ * 14364218128780764749U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 15265344442454471986U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 3050323350098829515U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5890624677162388135U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 1093356813820599238U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 15167726103772238440U;
            aOrbiterD = RotL64((aOrbiterD * 5719466863561311069U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 15170797965325981472U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 17826286701992981628U;
            aOrbiterG = RotL64((aOrbiterG * 11186808881726573677U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 14710892030473425181U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 397194787697553904U;
            aOrbiterE = RotL64((aOrbiterE * 14368930300818752833U), 43U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterB, 58U);
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterG, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 47U) + aOrbiterK) + RotL64(aOrbiterH, 47U)) + aPhaseEWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 41U) + aOrbiterE) + RotL64(aOrbiterH, 29U));
            aWandererK = aWandererK + (((RotL64(aCross, 29U) + RotL64(aOrbiterG, 3U)) + aOrbiterK) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterD, 21U));
            aWandererH = aWandererH + ((RotL64(aCross, 53U) + RotL64(aOrbiterB, 60U)) + aOrbiterD);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterJ, 11U)) + aOrbiterE) + aPhaseEWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 60U) + aOrbiterJ) + RotL64(aOrbiterB, 39U)) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (RotL64(aWandererE, 46U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererC, 13U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 15560U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneD[((aIndex + 13499U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 10214U)) & S_BLOCK1], 36U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 13311U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCross, 57U)) + (RotL64(aPrevious, 43U) ^ RotL64(aCarry, 28U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = ((aWandererK + RotL64(aIngress, 41U)) + RotL64(aCarry, 37U)) + 1557680213571812384U;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 35U)) + RotL64(aCarry, 21U)) + 7387349725778021121U;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 19U)) + 15379264067601586976U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = (((aWandererA + RotL64(aScatter, 51U)) + RotL64(aCarry, 51U)) + 3730195724576043708U) + aPhaseEOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = (aWandererD + RotL64(aPrevious, 27U)) + 9637070085323827066U;
            aOrbiterK = (aWandererH + RotL64(aIngress, 60U)) + 1170865717363676184U;
            aOrbiterB = (aWandererG + RotL64(aCross, 11U)) + 2750833653175252030U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 15118992811225568305U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 4974092922102988451U;
            aOrbiterG = RotL64((aOrbiterG * 10575977398702460975U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 10625719096296719514U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 855167122475471865U;
            aOrbiterE = RotL64((aOrbiterE * 7441090331293158773U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 11322911068958340262U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 4334591909425429835U;
            aOrbiterD = RotL64((aOrbiterD * 10059025861172038183U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 14263701737208936392U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 678723206735649084U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10823239851733632227U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 15652053114252065230U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 1705225940224061401U;
            aOrbiterC = RotL64((aOrbiterC * 3626023093533713579U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 6826394665732900206U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 11902946775066981141U;
            aOrbiterK = RotL64((aOrbiterK * 18300629262162694137U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 9802212958998591310U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 14001358545610206524U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13172645840788327099U), 13U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterB, 35U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + RotL64(aOrbiterD, 60U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aScatter, 57U) + RotL64(aOrbiterC, 29U)) + aOrbiterD);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterD, 43U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 39U) + RotL64(aOrbiterK, 5U)) + aOrbiterI) + RotL64(aCarry, 21U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterB, 58U)) + aOrbiterC);
            aWandererH = aWandererH + (((RotL64(aScatter, 21U) + RotL64(aOrbiterK, 37U)) + aOrbiterG) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterE, 19U));
            aWandererK = aWandererK + (((RotL64(aCross, 14U) + RotL64(aOrbiterD, 13U)) + aOrbiterE) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 60U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 21490U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((aIndex + 19710U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 22931U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 23224U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 52U) + RotL64(aPrevious, 21U)) ^ (RotL64(aIngress, 35U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 29U)) + 9107326720193244489U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aScatter, 57U)) + 10868585484401664145U;
            aOrbiterD = (((aWandererA + RotL64(aIngress, 51U)) + RotL64(aCarry, 57U)) + 13637736741437846622U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = ((aWandererI + RotL64(aCross, 37U)) + RotL64(aCarry, 41U)) + 6130725216183918844U;
            aOrbiterJ = (aWandererK + RotL64(aIngress, 5U)) + 2063834478521338187U;
            aOrbiterG = (aWandererF + RotL64(aCross, 23U)) + 8564870627911949158U;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 14U)) + RotL64(aCarry, 19U)) + 6524015751064086390U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 9874937766875388236U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 14723718409522680894U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17379140128833323431U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 13767059954741528279U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 6387608251033722169U;
            aOrbiterI = RotL64((aOrbiterI * 6601902195707980693U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 5391425980008431000U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 11524218415655093779U;
            aOrbiterK = RotL64((aOrbiterK * 12508457981779189389U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 155510463350385905U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 10554591788433641311U;
            aOrbiterE = RotL64((aOrbiterE * 5412084824127934293U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 8662160162966241542U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 5092555636369853727U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 433807340167635499U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 7163345798448796101U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 695089002178413267U;
            aOrbiterG = RotL64((aOrbiterG * 17302689458565434475U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 5409173939213468972U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 15349690077393827541U;
            aOrbiterB = RotL64((aOrbiterB * 10984681254001609841U), 23U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 29U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + RotL64(aOrbiterD, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterJ, 41U)) + aPhaseEWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 12U) + aOrbiterE) + RotL64(aOrbiterI, 57U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 51U)) + aOrbiterE);
            aWandererA = aWandererA + (((RotL64(aIngress, 53U) + aOrbiterG) + RotL64(aOrbiterD, 13U)) + RotL64(aCarry, 11U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 27U) + aOrbiterD) + RotL64(aOrbiterK, 29U)) + aPhaseEWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterG, 4U)) + aOrbiterJ) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 21U) + aOrbiterB) + RotL64(aOrbiterD, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 60U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 56U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 31786U)) & S_BLOCK1], 40U) ^ RotL64(aWorkLaneB[((aIndex + 28612U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26206U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneD[((aIndex + 28605U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCross, 35U)) ^ (RotL64(aIngress, 20U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = (aWandererI + RotL64(aIngress, 29U)) + 1364174714924216027U;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 3U)) + 13561796874229506613U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aCross, 41U)) + RotL64(aCarry, 57U)) + 11845572344206238305U;
            aOrbiterD = (aWandererG + RotL64(aPrevious, 54U)) + 15762708240326773763U;
            aOrbiterE = (aWandererJ + RotL64(aIngress, 13U)) + 1157119665207900473U;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 35U)) + RotL64(aCarry, 23U)) + 6823546624372055260U;
            aOrbiterI = (((aWandererK + RotL64(aScatter, 21U)) + RotL64(aCarry, 41U)) + 14465564210523945121U) + aPhaseEOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 10667464548080807531U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 13445737493224316575U;
            aOrbiterJ = RotL64((aOrbiterJ * 12137295000900795711U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 3009837893785957665U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 2886920524111083752U;
            aOrbiterG = RotL64((aOrbiterG * 15308180928967762543U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 10886177449328249656U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 15067759884678100433U;
            aOrbiterH = RotL64((aOrbiterH * 5724566815989860041U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 18307930462682331536U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 8791864377579255801U;
            aOrbiterE = RotL64((aOrbiterE * 9265158882471421767U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 805797468642992351U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 5743305867058244964U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16263000753351131717U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 17102025528234481273U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 1841579177327486899U;
            aOrbiterD = RotL64((aOrbiterD * 3841603385577825265U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 2189493507896508972U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 18209567010094914374U;
            aOrbiterI = RotL64((aOrbiterI * 3737080408976852351U), 21U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterD, 57U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterK, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 29U)) + aOrbiterG) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 23U) + RotL64(aOrbiterK, 35U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 47U) + aOrbiterH) + RotL64(aOrbiterD, 43U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterK, 12U)) + aOrbiterG) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 14U) + aOrbiterH) + RotL64(aOrbiterE, 21U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 41U) + aOrbiterH) + RotL64(aOrbiterJ, 51U)) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 3U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 30U));
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererI, 35U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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

void TwistExpander_Soccer_Arx::Twist_D(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 696U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneC[((aIndex + 928U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6068U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((aIndex + 5884U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 6U) ^ RotL64(aCross, 53U)) + (RotL64(aCarry, 23U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = (aWandererK + RotL64(aCross, 19U)) + 3612110001869385068U;
            aOrbiterG = (((aWandererC + RotL64(aPrevious, 44U)) + RotL64(aCarry, 19U)) + 16340824141280225936U) + aPhaseFOrbiterAssignSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aIngress, 27U)) + RotL64(aCarry, 3U)) + 15222338965130765231U;
            aOrbiterE = ((aWandererH + RotL64(aScatter, 11U)) + RotL64(aCarry, 51U)) + 6649270508107155041U;
            aOrbiterF = ((aWandererA + RotL64(aCross, 3U)) + 768217258655426384U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 4481855259658861851U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 18318041934562434016U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14913761339765234979U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 4212457153804401807U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 16143621095636987628U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6576072860505961427U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 2095664232866642086U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 4339527736737366572U;
            aOrbiterE = RotL64((aOrbiterE * 17503569508822244125U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 13679353177869884790U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 11582168502846418236U;
            aOrbiterG = RotL64((aOrbiterG * 135539430034462861U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 10451330452898542191U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 12951448817640617841U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4141870904192742091U), 51U);
            //
            aIngress = RotL64(aOrbiterA, 18U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 41U));
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aIngress, 56U) + RotL64(aOrbiterE, 18U)) + aOrbiterJ);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterA, 29U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 21U) + aOrbiterE) + RotL64(aOrbiterG, 5U)) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterF, 43U)) + aOrbiterG) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 37U) + aOrbiterA) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 54U));
            aCarry = aCarry + RotL64(aWandererC, 41U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9567U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneD[((aIndex + 9782U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15833U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneB[((aIndex + 10301U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 43U) + RotL64(aCarry, 28U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCross, 13U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (((aWandererE + RotL64(aCross, 35U)) + RotL64(aCarry, 19U)) + 17668251151213543491U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 5U)) + RotL64(aCarry, 3U)) + 16101602509895104517U;
            aOrbiterA = (aWandererD + RotL64(aScatter, 43U)) + 9083915270773304935U;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 24U)) + 12810720730318214811U) + aPhaseFOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 57U)) + RotL64(aCarry, 39U)) + 18113428002071925621U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 1582208899354109878U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 4180688104819188154U;
            aOrbiterA = RotL64((aOrbiterA * 3391785441902730815U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 8954598189262820611U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 15360094153175355879U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8177798855402983685U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 8383954114668216260U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 15626783326234049197U;
            aOrbiterD = RotL64((aOrbiterD * 15058420415480073793U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 10609978564404958066U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 17656516608997517984U;
            aOrbiterC = RotL64((aOrbiterC * 4590620354119899777U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 760077259110786536U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 3597338735888033063U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6548831472863517621U), 57U);
            //
            aIngress = RotL64(aOrbiterC, 3U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterA, 29U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 14U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 21U) + aOrbiterG) + RotL64(aOrbiterA, 12U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 37U) + RotL64(aOrbiterD, 29U)) + aOrbiterH) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 54U) + RotL64(aOrbiterD, 3U)) + aOrbiterC);
            aWandererG = aWandererG + ((((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterC, 37U)) + RotL64(aCarry, 47U)) + aPhaseFWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterD, 51U)) + aOrbiterG) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererG, 37U);
            aCarry = aCarry + RotL64(aIngress, 28U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 22408U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22186U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21847U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneC[((aIndex + 23695U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aIngress, 53U)) + (RotL64(aPrevious, 20U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = ((aWandererA + RotL64(aIngress, 29U)) + RotL64(aCarry, 27U)) + 1297415699043177788U;
            aOrbiterE = (aWandererI + RotL64(aCross, 43U)) + 17583786534509260153U;
            aOrbiterB = (((aWandererF + RotL64(aScatter, 13U)) + RotL64(aCarry, 5U)) + 643197858925708798U) + aPhaseFOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = (((aWandererG + RotL64(aPrevious, 3U)) + RotL64(aCarry, 57U)) + 5062653766915694874U) + aPhaseFOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aCross, 54U)) + 7034273638367180511U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 2026909726972916996U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 2785690475553211646U;
            aOrbiterB = RotL64((aOrbiterB * 6612792037861160393U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 2910341716302991892U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 2834181605200829791U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1510617068750957651U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 13323052600571281928U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 10434901530315760460U;
            aOrbiterK = RotL64((aOrbiterK * 2042210188346767033U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 247903955625194782U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 5196515747387257163U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1799024689023272275U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 7196305682377987476U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 14777739876892587484U;
            aOrbiterC = RotL64((aOrbiterC * 95220583948241581U), 43U);
            //
            aIngress = RotL64(aOrbiterE, 37U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + RotL64(aOrbiterK, 24U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 20U) + aOrbiterB) + RotL64(aOrbiterC, 43U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 39U) + aOrbiterF) + RotL64(aOrbiterB, 11U)) + RotL64(aCarry, 53U)) + aPhaseFWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterK, 35U)) + aOrbiterF) + aPhaseFWandererUpdateSaltC[((aIndex + 26U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 29U) + RotL64(aOrbiterE, 27U)) + aOrbiterB) + RotL64(aCarry, 35U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterB, 58U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 44U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 35U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 28767U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((aIndex + 28569U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25065U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneD[((aIndex + 32055U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aPrevious, 53U)) + (RotL64(aIngress, 19U) ^ RotL64(aCarry, 6U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = ((aWandererB + RotL64(aCross, 3U)) + RotL64(aCarry, 53U)) + 5906639480605353429U;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 21U)) + RotL64(aCarry, 11U)) + 5293518570213287605U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 11U)) + 15383185501428521377U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aScatter, 40U)) + RotL64(aCarry, 27U)) + 15364072512743978902U;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 57U)) + 4525473357144014271U) + aPhaseFOrbiterAssignSaltB[((aIndex + 12U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 10400911938125603074U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 16417506293824627550U;
            aOrbiterE = RotL64((aOrbiterE * 8303380456072515611U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 2419329331753341815U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 14929222427923332069U;
            aOrbiterD = RotL64((aOrbiterD * 11596261802662514979U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 16771573504983922586U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 1863466450051787622U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2585626547126027053U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 12895350137096692415U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 3700979086526298327U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10279730254867618193U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 1977099106211282426U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 6144698304096915742U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5039822990560519609U), 41U);
            //
            aIngress = RotL64(aOrbiterB, 53U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 43U));
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aCross, 27U) + aOrbiterD) + RotL64(aOrbiterA, 51U)) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 54U) + aOrbiterB) + RotL64(aOrbiterD, 37U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 3U) + RotL64(aOrbiterD, 20U)) + aOrbiterC);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 37U) + aOrbiterC) + RotL64(aOrbiterE, 11U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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

void TwistExpander_Soccer_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 1163U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneB[((aIndex + 2889U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 2175U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneD[((aIndex + 2058U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCross, 20U)) ^ (RotL64(aCarry, 5U) + RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = (((aWandererA + RotL64(aCross, 35U)) + RotL64(aCarry, 51U)) + 7270044678408187242U) + aPhaseGOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = ((aWandererC + RotL64(aIngress, 57U)) + 10192278965379756766U) + aPhaseGOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = (aWandererF + RotL64(aPrevious, 26U)) + 17568666746676060748U;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 47U)) + RotL64(aCarry, 39U)) + 14312927531124963037U;
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 13U)) + RotL64(aCarry, 13U)) + 9825825726152087706U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 9696778570255265896U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 17657841352013417228U;
            aOrbiterI = RotL64((aOrbiterI * 17562220176018833833U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 16207815085909628439U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 1752979206374514227U;
            aOrbiterJ = RotL64((aOrbiterJ * 14182667540650694199U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 10456310689643905854U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 16127830548663742550U;
            aOrbiterF = RotL64((aOrbiterF * 4355938404839045417U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 2940917376003930842U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 7353596864777649953U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7499468723171042005U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 12725092740446150705U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 5791296650856037010U;
            aOrbiterE = RotL64((aOrbiterE * 760379251950502133U), 57U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterJ, 13U);
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterI, 29U)) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 41U) + aOrbiterJ) + RotL64(aOrbiterE, 58U)) + RotL64(aCarry, 57U)) + aPhaseGWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 5U) + aOrbiterF) + RotL64(aOrbiterA, 21U));
            aWandererC = aWandererC + (((RotL64(aScatter, 51U) + aOrbiterE) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 37U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 60U) + aOrbiterJ) + RotL64(aOrbiterF, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 42U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererC, 21U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12141U)) & S_BLOCK1], 40U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 13451U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8553U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneA[((aIndex + 11229U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 40U) + RotL64(aPrevious, 5U)) + (RotL64(aCross, 53U) ^ RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = (aWandererK + RotL64(aScatter, 30U)) + 13499155707765393469U;
            aOrbiterC = (aWandererJ + RotL64(aCross, 11U)) + 3740324981823726185U;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 21U)) + RotL64(aCarry, 57U)) + 5470765363949735652U;
            aOrbiterA = (((aWandererI + RotL64(aIngress, 39U)) + RotL64(aCarry, 41U)) + 3446436171274452326U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (((aWandererA + RotL64(aScatter, 51U)) + RotL64(aCarry, 5U)) + 1778929412631211933U) + aPhaseGOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 14666308799855220954U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 4548410236791175055U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6822908616815218501U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 5829739767694190372U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 14319231414903675748U;
            aOrbiterB = RotL64((aOrbiterB * 4966501102515775601U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 1513851750246111405U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 1685620217748986019U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9286548037413609445U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 16284162182006054402U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 6271539598462003309U;
            aOrbiterC = RotL64((aOrbiterC * 13923286694131331137U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 12669312437565969473U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 11894755313393001665U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12556759675372354075U), 57U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterC, 11U);
            aIngress = aIngress + (RotL64(aOrbiterG, 37U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 10U) + RotL64(aOrbiterB, 57U)) + aOrbiterG) + aPhaseGWandererUpdateSaltA[((aIndex + 24U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 39U) + aOrbiterC) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterA, 3U)) + aOrbiterK);
            aWandererI = aWandererI + (((RotL64(aCross, 47U) + RotL64(aOrbiterK, 20U)) + aOrbiterB) + RotL64(aCarry, 37U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 29U) + aOrbiterB) + RotL64(aOrbiterC, 37U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 60U));
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 51U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 22351U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 16946U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 17509U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneB[((aIndex + 24208U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 54U) + RotL64(aIngress, 21U)) ^ (RotL64(aPrevious, 3U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = (aWandererI + RotL64(aIngress, 23U)) + 3970829908171131502U;
            aOrbiterD = (((aWandererF + RotL64(aCross, 46U)) + RotL64(aCarry, 51U)) + 7040283759419531991U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = (((aWandererA + RotL64(aScatter, 13U)) + RotL64(aCarry, 11U)) + 11856292169397052901U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = (aWandererG + RotL64(aPrevious, 3U)) + 819598588791819022U;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 37U)) + RotL64(aCarry, 37U)) + 2176451710970866848U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 6454704928613390494U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 11792122387218053841U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17994898985794518565U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 9254780213489752211U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 16591812589999846482U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5425771603523423167U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 1471246223935074832U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 1424843083106386453U;
            aOrbiterB = RotL64((aOrbiterB * 15020536982657410783U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 1856469958050891629U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 6331743690452052712U;
            aOrbiterF = RotL64((aOrbiterF * 15327924647897459645U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 10351075711345476487U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 9518585245330480185U;
            aOrbiterJ = RotL64((aOrbiterJ * 3792179827396760391U), 57U);
            //
            aIngress = RotL64(aOrbiterA, 3U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + RotL64(aOrbiterB, 44U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aScatter, 21U) + aOrbiterD) + RotL64(aOrbiterB, 27U)) + RotL64(aCarry, 11U)) + aPhaseGWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 37U) + aOrbiterA) + RotL64(aOrbiterJ, 3U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterD, 35U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 48U) + RotL64(aOrbiterB, 18U)) + aOrbiterF);
            aWandererA = aWandererA + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 51U)) + aOrbiterA) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 58U));
            aCarry = aCarry + RotL64(aWandererA, 29U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 28328U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((aIndex + 24817U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31206U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 24582U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCross, 39U)) + (RotL64(aCarry, 10U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = (aWandererD + RotL64(aPrevious, 3U)) + 9133751643283278896U;
            aOrbiterB = (((aWandererE + RotL64(aScatter, 40U)) + RotL64(aCarry, 3U)) + 8971581804375380408U) + aPhaseGOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = (((aWandererH + RotL64(aIngress, 11U)) + RotL64(aCarry, 53U)) + 12559650383714566592U) + aPhaseGOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aCross, 27U)) + RotL64(aCarry, 23U)) + 15753206088872859163U;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 57U)) + 7640756270450762350U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 7340073357551376125U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 5270256573644196046U;
            aOrbiterH = RotL64((aOrbiterH * 13286406906662922841U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 3567367996479995928U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 11939634537492733738U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5640541900117183639U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 7051817732424527120U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 1730487669951837941U;
            aOrbiterF = RotL64((aOrbiterF * 15191634337956285841U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 18009252467909454817U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 2361024272031696442U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15215151562500226027U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 15902755877642960397U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 12243517544704116184U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2576071074148141447U), 53U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 43U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + RotL64(aOrbiterI, 26U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 21U) + aOrbiterH) + RotL64(aOrbiterB, 3U));
            aWandererH = aWandererH + ((((RotL64(aScatter, 30U) + RotL64(aOrbiterH, 19U)) + aOrbiterF) + RotL64(aCarry, 39U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterH, 58U)) + aOrbiterE);
            aWandererE = aWandererE + (((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterE, 47U)) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterE, 35U)) + aOrbiterF) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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

void TwistExpander_Soccer_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 381U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneB[((aIndex + 6304U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1504U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((aIndex + 8154U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 47U) ^ RotL64(aPrevious, 22U)) ^ (RotL64(aCarry, 5U) + RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = ((aWandererE + RotL64(aScatter, 6U)) + RotL64(aCarry, 35U)) + 11700815697312060726U;
            aOrbiterB = (((aWandererB + RotL64(aCross, 57U)) + RotL64(aCarry, 3U)) + 11808423452327465441U) + aPhaseHOrbiterAssignSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aIngress, 47U)) + RotL64(aCarry, 47U)) + 8670503858631730886U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 39U)) + 2400061067991988544U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 29U)) + 16163118178366229686U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 3280178595904941068U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 3298683600817047727U;
            aOrbiterG = RotL64((aOrbiterG * 9865649058799255343U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 16321624053445183574U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 6730229877611375225U;
            aOrbiterI = RotL64((aOrbiterI * 2022290495153519279U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 10162830636713641322U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 15646771327759599256U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15333053762177144775U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 14841751262270544102U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 9545541117228834895U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11529769874752969377U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 14676615635857599982U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 1231768638470558855U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2716808508509014677U), 57U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 11U);
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterF, 11U)) + aPhaseHWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 56U) + aOrbiterJ) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterG, 22U)) + aOrbiterI);
            aWandererB = aWandererB + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 57U)) + aOrbiterJ) + RotL64(aCarry, 23U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 11U) + aOrbiterB) + RotL64(aOrbiterF, 35U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + RotL64(aWandererE, 22U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 14159U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneC[((aIndex + 9515U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 8755U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10252U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCross, 11U)) ^ (RotL64(aCarry, 35U) + RotL64(aPrevious, 52U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 11U)) + RotL64(aCarry, 43U)) + 4634399531433127141U;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 19U)) + RotL64(aCarry, 19U)) + 16961792729406903200U;
            aOrbiterF = ((aWandererB + RotL64(aCross, 29U)) + 4105280732301137738U) + aPhaseHOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = (((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 57U)) + 15692013501147331191U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = (aWandererA + RotL64(aCross, 50U)) + 1252216715968780587U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 7958289043012473752U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 6611577301818896615U;
            aOrbiterF = RotL64((aOrbiterF * 2757493607265637973U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 8506226754305949140U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 3648813120449403353U;
            aOrbiterK = RotL64((aOrbiterK * 9521367946879238849U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 5195245426245535735U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 542948051600803051U;
            aOrbiterE = RotL64((aOrbiterE * 4631106308856448475U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 11974253551208964789U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 10596463592332655367U;
            aOrbiterG = RotL64((aOrbiterG * 10941161258815714641U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 12015129484061440159U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 8254944355710109060U;
            aOrbiterC = RotL64((aOrbiterC * 3233697992479357615U), 35U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 57U);
            aIngress = aIngress + (RotL64(aOrbiterC, 12U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 39U) + aOrbiterE) + RotL64(aOrbiterK, 35U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 57U) + aOrbiterF) + RotL64(aOrbiterK, 27U)) + RotL64(aCarry, 13U)) + aPhaseHWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 20U) + RotL64(aOrbiterC, 5U)) + aOrbiterF) + aPhaseHWandererUpdateSaltD[((aIndex + 26U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 11U) + aOrbiterG) + RotL64(aOrbiterC, 44U)) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterE, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 21U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 34U));
            aCarry = aCarry + RotL64(aWandererD, 47U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 22361U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneD[((aIndex + 24400U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24250U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneB[((aIndex + 19552U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 60U) + RotL64(aCross, 29U)) ^ (RotL64(aCarry, 47U) + RotL64(aIngress, 13U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = ((aWandererG + RotL64(aScatter, 4U)) + 6342299552323486695U) + aPhaseHOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 5U)) + 12692748514781367538U;
            aOrbiterG = (((aWandererI + RotL64(aIngress, 23U)) + RotL64(aCarry, 41U)) + 8202639945493229155U) + aPhaseHOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 43U)) + RotL64(aCarry, 23U)) + 4439975701793231639U;
            aOrbiterK = (aWandererB + RotL64(aCross, 35U)) + 16774235182859553759U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 8764155413335405667U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 7167848811974967685U;
            aOrbiterG = RotL64((aOrbiterG * 1052856924757654735U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 16768278912125334220U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 9090838954826296201U;
            aOrbiterC = RotL64((aOrbiterC * 5459329624017272077U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 7644075729758006298U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 17326182797908071215U;
            aOrbiterI = RotL64((aOrbiterI * 2408330168749256075U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 16158809721888137555U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 8029938783858263694U;
            aOrbiterA = RotL64((aOrbiterA * 12628072435324195483U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 8716553521415553404U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 7012599977009208840U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8775355876188948851U), 19U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterA, 27U);
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterK, 52U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 19U) + aOrbiterK) + RotL64(aOrbiterA, 56U));
            aWandererK = aWandererK + (((RotL64(aIngress, 51U) + aOrbiterI) + RotL64(aOrbiterC, 37U)) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 60U) + aOrbiterG) + RotL64(aOrbiterK, 19U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aScatter, 27U) + RotL64(aOrbiterC, 11U)) + aOrbiterG) + RotL64(aCarry, 5U)) + aPhaseHWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterI, 29U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererI, 44U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 21U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 26677U)) & S_BLOCK1], 26U) ^ RotL64(aWorkLaneA[((aIndex + 25987U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28580U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneC[((aIndex + 28162U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCross, 11U)) ^ (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 24U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = (aWandererG + RotL64(aCross, 13U)) + 3255291173184001106U;
            aOrbiterK = (((aWandererF + RotL64(aScatter, 36U)) + RotL64(aCarry, 51U)) + 15308468160116255528U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 5U)) + RotL64(aCarry, 13U)) + 18186972408589866656U;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 51U)) + RotL64(aCarry, 27U)) + 4439324265978331914U;
            aOrbiterF = ((aWandererB + RotL64(aCross, 27U)) + 13099263173016322486U) + aPhaseHOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 7041561081767500660U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 6196422612687812971U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13359900204297781063U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 7664260932541281413U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 17802347823020441056U;
            aOrbiterE = RotL64((aOrbiterE * 2220679459017369255U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 4253107484061190446U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 13799496534030645312U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9167675060053848207U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 14252892847595951926U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 5663527578664291422U;
            aOrbiterK = RotL64((aOrbiterK * 18314294235895182465U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 11148755959699137661U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 17036900929333594592U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16041243617369003291U), 5U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterA, 53U);
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 23U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 27U) + aOrbiterA) + RotL64(aOrbiterE, 3U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterE, 47U)) + aOrbiterK) + RotL64(aCarry, 11U)) + aPhaseHWandererUpdateSaltA[((aIndex + 20U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 56U) + aOrbiterA) + RotL64(aOrbiterF, 20U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 43U) + aOrbiterK) + RotL64(aOrbiterH, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 34U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
