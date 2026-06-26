#include "TwistExpander_Karate_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Karate_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x870A3914478CC9DFULL + 0xBA0880292ADFB5F9ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xF1CEE91D310B45E3ULL + 0x98D30E9112F4FEF9ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xC909DD23C19BC2BDULL + 0x9C2477B8EF862CD8ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x8273BB95E84BCF15ULL + 0xD529FF2D5F911537ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xD94662DB3D175CD1ULL + 0xE318DB60D79A5631ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x8AF3C9C231253C9BULL + 0x8F6466134BA004BBULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xA186850E27593D0FULL + 0xC664B184ADBE3223ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xFC882AA28F38F68DULL + 0xCFF6174021449EC0ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xFDD9D1B81FDFA5A7ULL + 0x8FC67E31A752E18BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xCE6A0D861BE74983ULL + 0xCD7CC66A16EE8D69ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xC781A7B43C280EE7ULL + 0x96735B1FE0B60255ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x9614B6CCE885BDF7ULL + 0xA1F40BAA03781A50ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xDA23F2C140DE669DULL + 0xBB6D26CB3B57B18CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xA1864FA802C1B2C3ULL + 0xC5228D39C3D9E9A3ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xC2408350D2AC1C23ULL + 0x9249A48A5D5AD5FFULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x97B46A18614AFA9DULL + 0xEC98CD67905D07D2ULL);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 975U)) & S_BLOCK1], 27U) ^ RotL64(pSnow[((aIndex + 3726U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 32U)) & S_BLOCK1], 48U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 1531U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 22U) + RotL64(aCarry, 39U)) + (RotL64(aCross, 3U) ^ RotL64(aIngress, 53U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererB + RotL64(aScatter, 41U)) + 10404808878585437255U;
            aOrbiterI = (aWandererI + RotL64(aPrevious, 43U)) + 10587858736301591439U;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 60U)) + 1430530909801644435U;
            aOrbiterD = (aWandererC + RotL64(aCross, 19U)) + 9090938022430118902U;
            aOrbiterK = (aWandererG + RotL64(aIngress, 37U)) + 12936604311751121235U;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 47U)) + RotL64(aCarry, 27U)) + 1000583006020232032U;
            aOrbiterE = (aWandererD + RotL64(aPrevious, 5U)) + 12352532088997042232U;
            aOrbiterB = ((((aWandererE + RotL64(aScatter, 51U)) + RotL64(aCarry, 47U)) + 16723410947058502564U) + aOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1]) + aNonceWordG;
            aOrbiterA = ((aWandererK + RotL64(aCross, 57U)) + 16614089235313154270U) + aNonceWordC;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 3U)) + 4245553025593349277U;
            aOrbiterG = ((((aWandererH + RotL64(aIngress, 22U)) + RotL64(aCarry, 57U)) + 3353146318549477494U) + aOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1]) + aNonceWordE;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 5935727336135635196U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 10312187090293319667U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1395964500396711899U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 12192843181244744484U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 2542570124502586365U) ^ aNonceWordH;
            aOrbiterJ = RotL64((aOrbiterJ * 17222847847573534963U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 3315472769469002444U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 17512858811783071174U;
            aOrbiterF = RotL64((aOrbiterF * 9070400454074283765U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 16633218007427888082U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 2502077714838858460U;
            aOrbiterD = RotL64((aOrbiterD * 970762420815997725U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 14792910273226469214U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 15739513291150783151U) ^ aNonceWordF;
            aOrbiterE = RotL64((aOrbiterE * 11896279674116906915U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 2192903544350345992U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 844428341223009295U;
            aOrbiterA = RotL64((aOrbiterA * 4768368713974002539U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 2998511458298901402U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 7790789639864783373U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9173097618440495497U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 4540735375055164995U) + aOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 13700342877362633034U;
            aOrbiterI = RotL64((aOrbiterI * 14730797752841670505U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 16966725424259324323U) + aNonceWordD;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 5945539295893015935U;
            aOrbiterK = RotL64((aOrbiterK * 12226268057062268981U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 12560355243513521281U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 2104086086480258265U;
            aOrbiterB = RotL64((aOrbiterB * 17989755118752755577U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 4476697099257280568U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 10404808878585437255U;
            aOrbiterH = RotL64((aOrbiterH * 6245415417832089357U), 35U);
            //
            aIngress = RotL64(aOrbiterF, 11U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + (RotL64(aOrbiterD, 20U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + (RotL64(aOrbiterG, 41U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterD, 19U)) + aOrbiterB);
            aWandererB = aWandererB + ((((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterF, 3U)) + aNonceWordK) + aWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 56U) + RotL64(aOrbiterG, 53U)) + aOrbiterC) + aWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 5U) + aOrbiterF) + RotL64(aOrbiterE, 27U)) + RotL64(aCarry, 37U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 21U) + aOrbiterB) + RotL64(aOrbiterK, 56U));
            aWandererC = aWandererC + ((RotL64(aCross, 13U) + RotL64(aOrbiterC, 29U)) + aOrbiterJ);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterC, 43U)) + aOrbiterA);
            aWandererE = aWandererE + ((RotL64(aIngress, 50U) + aOrbiterG) + RotL64(aOrbiterK, 35U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 47U) + aOrbiterH) + RotL64(aOrbiterK, 13U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterG, 60U)) + aOrbiterE) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterI, 11U)) + aOrbiterB) + aNonceWordO);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 60U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + RotL64(aWandererB, 34U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordJ);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8632U)) & S_BLOCK1], 24U) ^ RotL64(mSource[((aIndex + 10078U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(pSnow[((S_BLOCK1 - aIndex + 5983U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 6981U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aPrevious, 26U)) + (RotL64(aCarry, 57U) + RotL64(aIngress, 43U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererH + RotL64(aScatter, 51U)) + RotL64(aCarry, 37U)) + 1297415699043177788U;
            aOrbiterG = (aWandererI + RotL64(aCross, 60U)) + 17583786534509260153U;
            aOrbiterK = (aWandererK + RotL64(aPrevious, 3U)) + 643197858925708798U;
            aOrbiterF = (((aWandererF + RotL64(aIngress, 53U)) + RotL64(aCarry, 47U)) + 5062653766915694874U) + aOrbiterAssignSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aScatter, 27U)) + 7034273638367180511U) + aNonceWordL;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 5U)) + 2026909726972916996U;
            aOrbiterB = ((aWandererE + RotL64(aCross, 23U)) + 2785690475553211646U) + aNonceWordP;
            aOrbiterH = (aWandererD + RotL64(aIngress, 35U)) + 2910341716302991892U;
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 29U)) + 2834181605200829791U;
            aOrbiterE = (((aWandererC + RotL64(aIngress, 43U)) + 13323052600571281928U) + aOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordI;
            aOrbiterC = ((aWandererA + RotL64(aCross, 48U)) + RotL64(aCarry, 5U)) + 10434901530315760460U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 247903955625194782U) + aNonceWordM;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 5196515747387257163U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1799024689023272275U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 7196305682377987476U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 14777739876892587484U;
            aOrbiterG = RotL64((aOrbiterG * 95220583948241581U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 10609060796540136671U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 8386027207212484155U;
            aOrbiterD = RotL64((aOrbiterD * 4855610536246556893U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 729659744301903424U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 2350564261412606157U;
            aOrbiterB = RotL64((aOrbiterB * 16713856782349084977U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 16611987556673864177U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 1525195188708550503U;
            aOrbiterI = RotL64((aOrbiterI * 10045858602151004553U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 4654808490980989596U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 8189569777087686263U;
            aOrbiterA = RotL64((aOrbiterA * 17278657566389299577U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 10932857495004451792U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 1833880112534916813U;
            aOrbiterF = RotL64((aOrbiterF * 8004341577533825681U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 13100236350175516423U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 2773759534195186313U;
            aOrbiterJ = RotL64((aOrbiterJ * 3194954066097323161U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 13963126688973399221U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 1464529855671190406U;
            aOrbiterH = RotL64((aOrbiterH * 6129954747502059213U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 9489842625026216815U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 17806120432918490594U) ^ aOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 349307975773661379U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 13833297268854563081U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 1297415699043177788U;
            aOrbiterC = RotL64((aOrbiterC * 4818542043777342249U), 19U);
            //
            aIngress = RotL64(aOrbiterH, 35U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 54U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + (RotL64(aOrbiterE, 51U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 39U));
            aIngress = aIngress + RotL64(aOrbiterB, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 53U) + aOrbiterE) + RotL64(aOrbiterG, 44U)) + aNonceWordF);
            aWandererB = aWandererB + (((RotL64(aScatter, 23U) + RotL64(aOrbiterI, 39U)) + aOrbiterG) + aWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 34U) + RotL64(aOrbiterB, 57U)) + aOrbiterF);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 3U) + aOrbiterD) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 39U)) + aNonceWordN);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterK, 34U)) + aOrbiterH);
            aWandererI = aWandererI + ((RotL64(aCross, 43U) + RotL64(aOrbiterI, 29U)) + aOrbiterC);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 21U)) + aOrbiterJ);
            aWandererE = aWandererE + ((RotL64(aIngress, 27U) + RotL64(aOrbiterH, 47U)) + aOrbiterB);
            aWandererC = aWandererC ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterG, 53U)) + aOrbiterA);
            aWandererD = aWandererD + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterC, 41U)) + aOrbiterD) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 12U) + RotL64(aOrbiterH, 23U)) + aOrbiterJ) + aWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 6U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + RotL64(aWandererJ, 21U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordP);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15120U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 12187U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 14450U)) & S_BLOCK1], 3U) ^ RotL64(pSnow[((aIndex + 15889U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 10U) + RotL64(aPrevious, 51U)) ^ (RotL64(aIngress, 23U) + RotL64(aCross, 39U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (aWandererK + RotL64(aScatter, 51U)) + 7270044678408187242U;
            aOrbiterK = (((aWandererC + RotL64(aCross, 18U)) + 10192278965379756766U) + aOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1]) + aNonceWordM;
            aOrbiterB = (aWandererF + RotL64(aIngress, 53U)) + 17568666746676060748U;
            aOrbiterC = (aWandererB + RotL64(aPrevious, 43U)) + 14312927531124963037U;
            aOrbiterD = (aWandererD + RotL64(aCross, 13U)) + 9825825726152087706U;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 39U)) + RotL64(aCarry, 41U)) + 9696778570255265896U;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 56U)) + 17657841352013417228U;
            aOrbiterJ = (((aWandererE + RotL64(aIngress, 41U)) + RotL64(aCarry, 27U)) + 16207815085909628439U) + aOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = ((aWandererA + RotL64(aCross, 47U)) + RotL64(aCarry, 53U)) + 1752979206374514227U;
            aOrbiterI = (aWandererJ + RotL64(aScatter, 35U)) + 10456310689643905854U;
            aOrbiterE = (aWandererG + RotL64(aPrevious, 3U)) + 16127830548663742550U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 2940917376003930842U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 7353596864777649953U;
            aOrbiterB = RotL64((aOrbiterB * 7499468723171042005U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 12725092740446150705U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 5791296650856037010U;
            aOrbiterF = RotL64((aOrbiterF * 760379251950502133U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 1200130368046206150U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterG) ^ 16689604428598558547U) ^ aOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterK = RotL64((aOrbiterK * 13815324235939996623U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 14359561591103730856U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 3975025843599045263U) ^ aOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5025047888533298617U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 14017901732955607601U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 10431526786489555196U;
            aOrbiterJ = RotL64((aOrbiterJ * 10181915874476132407U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 7320527073559849223U) + aOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 15333411223710709907U;
            aOrbiterI = RotL64((aOrbiterI * 3488684905528068775U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 14302474063321663801U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 2104154521019935187U;
            aOrbiterA = RotL64((aOrbiterA * 12944382959742278055U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 5167600586916325228U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 4566823109447208716U;
            aOrbiterC = RotL64((aOrbiterC * 9997799807454267443U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 12475580453805083495U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 15461491763911887974U;
            aOrbiterG = RotL64((aOrbiterG * 13548865386159287481U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 11000532703581114393U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 7815822789941347770U;
            aOrbiterH = RotL64((aOrbiterH * 1476638214324946775U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 2166336159928211562U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 7270044678408187242U;
            aOrbiterE = RotL64((aOrbiterE * 10648564933168714815U), 35U);
            //
            aIngress = RotL64(aOrbiterF, 5U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + (RotL64(aOrbiterG, 60U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + RotL64(aOrbiterH, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterH, 14U)) + aOrbiterK);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 37U) + RotL64(aOrbiterI, 37U)) + aOrbiterA) + RotL64(aCarry, 19U)) + aWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 14U) + aOrbiterD) + RotL64(aOrbiterG, 11U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterD, 39U)) + aNonceWordO) + aWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 11U) + aOrbiterH) + RotL64(aOrbiterJ, 56U));
            aWandererE = aWandererE + ((RotL64(aIngress, 21U) + RotL64(aOrbiterC, 41U)) + aOrbiterF);
            aWandererG = aWandererG ^ ((RotL64(aCross, 3U) + aOrbiterE) + RotL64(aOrbiterC, 19U));
            aWandererA = aWandererA + (((RotL64(aScatter, 6U) + RotL64(aOrbiterG, 21U)) + aOrbiterB) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterI, 43U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterG, 35U)) + aOrbiterJ);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 51U) + aOrbiterA) + RotL64(aOrbiterK, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 54U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 50U));
            aCarry = aCarry + RotL64(aWandererJ, 21U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordK);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 19738U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 20200U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20915U)) & S_BLOCK1], 23U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 16474U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 54U)) + (RotL64(aIngress, 11U) ^ RotL64(aCross, 37U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (((aWandererJ + RotL64(aPrevious, 41U)) + 13278949403988203974U) + aOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1]) + aNonceWordC;
            aOrbiterD = (aWandererK + RotL64(aIngress, 13U)) + 9213599924054673756U;
            aOrbiterI = (aWandererE + RotL64(aCross, 28U)) + 1255746482932381798U;
            aOrbiterJ = (((aWandererD + RotL64(aScatter, 39U)) + RotL64(aCarry, 41U)) + 11575321997144516122U) + aNonceWordE;
            aOrbiterF = ((aWandererI + RotL64(aCross, 43U)) + 15881587525529432437U) + aOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = (aWandererC + RotL64(aPrevious, 35U)) + 9846195809864862707U;
            aOrbiterA = (aWandererG + RotL64(aIngress, 26U)) + 12319815691858217670U;
            aOrbiterC = ((aWandererH + RotL64(aScatter, 37U)) + 16322617427294439587U) + aNonceWordD;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 21U)) + RotL64(aCarry, 3U)) + 16332130810525887437U;
            aOrbiterB = (aWandererA + RotL64(aScatter, 19U)) + 4920951156015336794U;
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 51U)) + RotL64(aCarry, 35U)) + 16767126455124552329U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 12553595911087945223U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 1437522202135436142U;
            aOrbiterI = RotL64((aOrbiterI * 2001992794165550905U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 12313100454852227143U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 2761983020631055729U;
            aOrbiterF = RotL64((aOrbiterF * 3874839760378039509U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 17635303588421554367U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 788212489507463763U) ^ aOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17896475584538528059U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 5192552894670654434U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 6784748488807738811U;
            aOrbiterA = RotL64((aOrbiterA * 8077237651953896479U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 16113417046719114943U) + aNonceWordF;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 1096874945215225916U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17308604412622879833U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 7610274704570171595U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 10466070212284342550U;
            aOrbiterK = RotL64((aOrbiterK * 6449728258497920613U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 6777845928873855221U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 5251515022021984126U;
            aOrbiterB = RotL64((aOrbiterB * 9018277343404261611U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 13849343158824111498U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterC) ^ 7977711210181714021U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterE = RotL64((aOrbiterE * 4182053966171053577U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 6494539818728106982U) + aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 11314590450226080781U;
            aOrbiterH = RotL64((aOrbiterH * 12455979257225599157U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 552687702594328012U) + aNonceWordG;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 14961304171192292246U;
            aOrbiterD = RotL64((aOrbiterD * 846375892915484717U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 9771874402848476494U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 13278949403988203974U;
            aOrbiterJ = RotL64((aOrbiterJ * 2119203863777871233U), 3U);
            //
            aIngress = RotL64(aOrbiterI, 53U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterC, 24U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aCross, 10U) + RotL64(aOrbiterE, 4U)) + aOrbiterD);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterK, 51U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 23U) + aOrbiterJ) + RotL64(aOrbiterA, 41U)) + RotL64(aCarry, 35U)) + aNonceWordB);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterG, 57U)) + aNonceWordN);
            aWandererF = aWandererF + ((((RotL64(aCross, 3U) + RotL64(aOrbiterG, 29U)) + aOrbiterA) + RotL64(aCarry, 47U)) + aWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterF, 27U)) + aOrbiterC);
            aWandererE = aWandererE + (((RotL64(aScatter, 43U) + RotL64(aOrbiterK, 36U)) + aOrbiterJ) + aNonceWordA);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterB, 23U)) + aOrbiterI);
            aWandererC = aWandererC + ((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterI, 47U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterF, 43U)) + aOrbiterI);
            aWandererA = aWandererA + (((RotL64(aIngress, 50U) + aOrbiterK) + RotL64(aOrbiterF, 53U)) + aWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 56U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 4U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ aNonceWordB;
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 25800U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22770U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22126U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25868U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 22U) + RotL64(aCross, 53U)) ^ (RotL64(aCarry, 39U) + RotL64(aPrevious, 5U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererK + RotL64(aPrevious, 34U)) + 9435962834163239322U;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 41U)) + 10524704356081318973U) + aOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aScatter, 3U)) + 7403401305665208680U;
            aOrbiterH = ((aWandererH + RotL64(aCross, 21U)) + 7525414805023556493U) + aOrbiterAssignSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 47U)) + 1116686470029070951U) + aNonceWordH;
            aOrbiterF = (aWandererF + RotL64(aScatter, 12U)) + 13257612299137802420U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 29U)) + RotL64(aCarry, 53U)) + 9181543003986598283U;
            aOrbiterE = ((aWandererA + RotL64(aCross, 19U)) + RotL64(aCarry, 5U)) + 9739384852307501107U;
            aOrbiterB = (aWandererB + RotL64(aScatter, 27U)) + 11308402900229016057U;
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 51U)) + RotL64(aCarry, 39U)) + 14935167593705272337U;
            aOrbiterJ = (aWandererG + RotL64(aCross, 37U)) + 7171824007631943535U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 8068411284829563567U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 12350207458513447578U;
            aOrbiterG = RotL64((aOrbiterG * 813973258659041895U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 17039236343991574134U) + aOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 18291683592714999632U;
            aOrbiterF = RotL64((aOrbiterF * 7771718817924840713U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 6239616841884430968U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 10604527977569876774U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6972820410084939637U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 1707724300671717658U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 3802268808625297647U;
            aOrbiterA = RotL64((aOrbiterA * 11296811630387191563U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 9423064323799920219U) + aNonceWordB;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 242153923313096551U;
            aOrbiterD = RotL64((aOrbiterD * 12117679073775630197U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 945801070951928277U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 13094814302414492064U;
            aOrbiterH = RotL64((aOrbiterH * 14638176479878969775U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 7572219725951040117U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 16494986983782503428U;
            aOrbiterI = RotL64((aOrbiterI * 2739189408707408171U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 10949497978229234856U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 11219643352002119905U) ^ aNonceWordL;
            aOrbiterB = RotL64((aOrbiterB * 16900635614259262873U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 14245670385849499678U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 13771155918235018585U;
            aOrbiterJ = RotL64((aOrbiterJ * 14121731385133220921U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 15722734439532828816U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 11032710342174118366U;
            aOrbiterK = RotL64((aOrbiterK * 16096465375397981585U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 2071496769185495150U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 9435962834163239322U;
            aOrbiterC = RotL64((aOrbiterC * 10640995428633266765U), 47U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterK, 29U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + (RotL64(aOrbiterA, 23U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterJ, 41U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 34U));
            aIngress = aIngress + RotL64(aOrbiterH, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterB, 3U));
            aWandererG = aWandererG + ((RotL64(aScatter, 5U) + aOrbiterE) + RotL64(aOrbiterB, 39U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterH, 47U)) + aWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 40U) + aOrbiterB) + RotL64(aOrbiterD, 23U)) + RotL64(aCarry, 3U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterG, 44U));
            aWandererC = aWandererC + (((RotL64(aCross, 13U) + RotL64(aOrbiterG, 21U)) + aOrbiterF) + aNonceWordF);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 51U) + aOrbiterI) + RotL64(aOrbiterE, 41U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 53U) + aOrbiterH) + RotL64(aOrbiterE, 29U)) + RotL64(aCarry, 57U)) + aWandererUpdateSaltC[((aIndex + 22U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterK, 14U)) + aOrbiterF) + aNonceWordK);
            aWandererI = aWandererI + ((RotL64(aScatter, 38U) + RotL64(aOrbiterE, 35U)) + aOrbiterJ);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 27U) + aOrbiterD) + RotL64(aOrbiterF, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 22U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + RotL64(aWandererH, 41U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordI);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30632U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((aIndex + 31640U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31487U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27337U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aIngress, 23U)) + (RotL64(aPrevious, 56U) + RotL64(aCross, 39U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererI + RotL64(aScatter, 35U)) + 4179952823252098240U) + aOrbiterAssignSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = (aWandererG + RotL64(aIngress, 41U)) + 3745613452332101749U;
            aOrbiterF = (aWandererA + RotL64(aPrevious, 29U)) + 2955689793395307176U;
            aOrbiterB = (aWandererF + RotL64(aCross, 27U)) + 5639060180251322019U;
            aOrbiterK = ((aWandererB + RotL64(aScatter, 48U)) + 7901969163853586463U) + aOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aCross, 53U)) + 2242166787816318119U;
            aOrbiterC = (aWandererD + RotL64(aIngress, 39U)) + 5239936443960750064U;
            aOrbiterJ = (((aWandererE + RotL64(aPrevious, 3U)) + RotL64(aCarry, 51U)) + 13939136954732185558U) + aNonceWordN;
            aOrbiterA = ((aWandererC + RotL64(aCross, 21U)) + RotL64(aCarry, 19U)) + 17058884136712717463U;
            aOrbiterH = (aWandererK + RotL64(aScatter, 51U)) + 18148618660054585941U;
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 14U)) + RotL64(aCarry, 37U)) + 7022023484530327814U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 7722084537340095637U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 11764151879690934182U;
            aOrbiterF = RotL64((aOrbiterF * 12264384877711365655U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 16412785901758144708U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 9666718667728274824U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10865799822751771795U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 4307127540152109364U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 2457646804702647606U;
            aOrbiterI = RotL64((aOrbiterI * 6340030928007058595U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 3179394870088602208U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 504977947273774249U;
            aOrbiterC = RotL64((aOrbiterC * 16190282058883481551U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 16182729401018310837U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 7110817020445860609U;
            aOrbiterJ = RotL64((aOrbiterJ * 13371352088428584087U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 12960656706837391973U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 7103806893724395904U;
            aOrbiterA = RotL64((aOrbiterA * 14365984439655979791U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 1248300178080633527U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 7195473175424961337U;
            aOrbiterH = RotL64((aOrbiterH * 4633558992739305045U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 13007951568242991449U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 10296811247653636372U;
            aOrbiterG = RotL64((aOrbiterG * 16469682651380549395U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 13922797949001028335U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 16773545425463040155U) ^ aOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10639282630227832397U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 2888887140296117803U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 10279517418046269817U;
            aOrbiterE = RotL64((aOrbiterE * 8600355360339461535U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 17303373436784809093U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 4179952823252098240U) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 3675754609699406437U), 23U);
            //
            aIngress = RotL64(aOrbiterE, 35U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 12U));
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterF, 23U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterA, 14U)) + aOrbiterC) + aWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterI, 41U)) + aWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 41U) + RotL64(aOrbiterB, 11U)) + aOrbiterF);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 34U) + RotL64(aOrbiterH, 39U)) + aOrbiterC) + aNonceWordL);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterE, 53U)) + aOrbiterD) + RotL64(aCarry, 5U)) + aNonceWordC);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 29U)) + aOrbiterJ);
            aWandererA = aWandererA + ((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterD, 60U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterH, 57U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 19U)) + aOrbiterH);
            aWandererB = aWandererB ^ ((RotL64(aCross, 58U) + aOrbiterG) + RotL64(aOrbiterK, 23U));
            aWandererH = aWandererH + (((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterF, 35U)) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 20U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererE, 30U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordE);
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

void TwistExpander_Karate_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xFA1A7F75774768A7ULL + 0xD3668D896F912ECCULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x89BAC8CD05A24401ULL + 0xCDB014EC519871AEULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xDB4FA11A22208D2BULL + 0xBDA847697D6606AAULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xE74FCBE3BEFE8E01ULL + 0xE3012964C7818D0AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xC95AFD2279C699CFULL + 0xB31D3FBF1451F194ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xAFC6F52DA20D4AE9ULL + 0x8E27FA1E076C201CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xD1FFDFD29CC83227ULL + 0xC6AB69C57C309EAFULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x8B75B5DA1F80A6B9ULL + 0xCE3FCDF57EB2910AULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xECA2022872109029ULL + 0x89F65AB23CDBC6A3ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x9D935A193ED96757ULL + 0xBEA53065E7A46E8BULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xAF529EB1577580ADULL + 0x856F90B540030A07ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xD57804D328E5D893ULL + 0xDBCE1F26CD6124B2ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x864122ACE34486D3ULL + 0xBE8249A8D5A605B8ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xBE9E9858CC7BA63DULL + 0xAC28D949F26B8BE6ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xD7B4CA64A7DF8F81ULL + 0xDB5F64872780D33FULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xE1BCFA1BA6B4D00BULL + 0xEAAAC4BAFA083068ULL);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1108U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5109U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7042U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((aIndex + 2986U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 40U) + RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 19U) ^ RotL64(aCross, 53U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererG + RotL64(aCross, 35U)) + RotL64(aCarry, 19U)) + 4204560462077827182U;
            aOrbiterG = ((aWandererH + RotL64(aScatter, 54U)) + RotL64(aCarry, 11U)) + 6572370199668594039U;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 5U)) + 15958999876732622825U;
            aOrbiterH = (((aWandererF + RotL64(aPrevious, 47U)) + RotL64(aCarry, 3U)) + 9969349486879280377U) + aNonceWordF;
            aOrbiterF = (((aWandererE + RotL64(aIngress, 19U)) + 15450238998293956181U) + aOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordI;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 43U)) + 9128619863683138259U) + aOrbiterAssignSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aPrevious, 29U)) + 5691270563628979565U;
            aOrbiterD = ((aWandererC + RotL64(aCross, 23U)) + 5901029710568933106U) + aNonceWordB;
            aOrbiterI = (aWandererD + RotL64(aScatter, 58U)) + 10442738941988588834U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 3508116020325721993U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 13221917083569767259U;
            aOrbiterC = RotL64((aOrbiterC * 6845108555710135357U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 11627915460377128176U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 17858261365514253433U;
            aOrbiterA = RotL64((aOrbiterA * 7535577636975884641U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 4294837988806295989U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 11242915481585070249U) ^ aOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17540688242763829319U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 13030663829236027109U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 7451948220723185149U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5191778587712222029U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 5575508866505031037U) + aNonceWordD;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 5161096033789876794U;
            aOrbiterE = RotL64((aOrbiterE * 16843827915802461797U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 3980482740649505122U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 11188906150207270241U;
            aOrbiterH = RotL64((aOrbiterH * 408550837615188413U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 4435504916461645189U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 9970252853543702833U;
            aOrbiterB = RotL64((aOrbiterB * 5829143716916091997U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 3766347619186305854U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 11004616087340082895U) ^ aOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14469267845747063735U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 17600791542296175812U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 2556224430252009744U;
            aOrbiterF = RotL64((aOrbiterF * 14469426539907112137U), 29U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterI, 38U);
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + RotL64(aOrbiterA, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 4U)) + aOrbiterF);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 37U) + aOrbiterA) + RotL64(aOrbiterB, 39U));
            aWandererA = aWandererA + (((RotL64(aCross, 23U) + aOrbiterI) + RotL64(aOrbiterF, 35U)) + aWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterG, 29U));
            aWandererI = aWandererI + ((RotL64(aScatter, 46U) + aOrbiterB) + RotL64(aOrbiterE, 47U));
            aWandererF = aWandererF ^ ((((RotL64(aCross, 11U) + RotL64(aOrbiterC, 10U)) + aOrbiterH) + aNonceWordE) + aWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterF, 53U)) + RotL64(aCarry, 29U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 27U) + aOrbiterI) + RotL64(aOrbiterG, 23U));
            aWandererD = aWandererD + (((RotL64(aScatter, 52U) + aOrbiterE) + RotL64(aOrbiterA, 43U)) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 44U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ aNonceWordN;
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 13539U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13757U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12694U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 13527U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aIngress, 40U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCross, 13U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererK + RotL64(aIngress, 23U)) + 9654059367478508868U;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 14U)) + 6473006635864677427U) + aNonceWordH;
            aOrbiterB = (aWandererG + RotL64(aCross, 29U)) + 6944184481315853243U;
            aOrbiterD = (aWandererA + RotL64(aScatter, 53U)) + 4061496421939102306U;
            aOrbiterK = (((aWandererI + RotL64(aPrevious, 43U)) + RotL64(aCarry, 51U)) + 15791809275719085463U) + aOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = (aWandererB + RotL64(aIngress, 57U)) + 14050798802646323055U;
            aOrbiterJ = (((aWandererH + RotL64(aScatter, 37U)) + 12072905924741758266U) + aOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1]) + aNonceWordO;
            aOrbiterF = ((aWandererC + RotL64(aCross, 3U)) + RotL64(aCarry, 29U)) + 17639076509231343896U;
            aOrbiterA = (((aWandererJ + RotL64(aIngress, 48U)) + RotL64(aCarry, 37U)) + 12195388285571234715U) + aNonceWordJ;
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 4325404419499496529U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 5910567888204238382U;
            aOrbiterB = RotL64((aOrbiterB * 11503787177122206937U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 13092940059929942699U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 13381962590820308761U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6345904465930943295U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 15622862439323440527U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 14027151901132249793U;
            aOrbiterJ = RotL64((aOrbiterJ * 2273573821630510087U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 4584410023907605157U) + aNonceWordB;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 15763755180625487157U;
            aOrbiterF = RotL64((aOrbiterF * 6755736130607297639U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 17023059745666559199U) + aNonceWordP;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 5298529579288492971U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2483562793328357721U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 2870152867331654736U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 12017191100173748848U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9958191466506480519U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 15899529176182436062U) + aOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 16482713846343388735U;
            aOrbiterD = RotL64((aOrbiterD * 719465695044265601U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 12943393531812774449U) + aNonceWordG;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 9881108254540483225U;
            aOrbiterG = RotL64((aOrbiterG * 8011108108007885059U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 3532054586199716750U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 7142230313294797435U;
            aOrbiterC = RotL64((aOrbiterC * 14154176174768868421U), 13U);
            //
            aIngress = RotL64(aOrbiterJ, 47U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterF, 51U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterA, 10U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 13U) + aOrbiterG) + RotL64(aOrbiterI, 47U));
            aWandererB = aWandererB + ((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 60U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 43U)) + aOrbiterJ);
            aWandererG = aWandererG + (((RotL64(aCross, 18U) + aOrbiterI) + RotL64(aOrbiterF, 35U)) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterJ, 39U)) + aWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aIngress, 5U) + aOrbiterK) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 35U)) + aNonceWordK);
            aWandererI = aWandererI ^ ((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterI, 11U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 24U) + RotL64(aOrbiterC, 52U)) + aOrbiterA) + aWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterF, 3U)) + aOrbiterJ) + aNonceWordN);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 50U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererK, 19U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordK);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 16607U)) & S_BLOCK1], 34U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23211U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19794U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((aIndex + 19994U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 58U) ^ RotL64(aCarry, 13U)) + (RotL64(aPrevious, 27U) ^ RotL64(aCross, 41U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererE + RotL64(aScatter, 5U)) + 6243113109470883144U;
            aOrbiterD = (aWandererJ + RotL64(aIngress, 52U)) + 3891552123999605832U;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 37U)) + 8758797898587019128U) + aNonceWordD;
            aOrbiterA = (aWandererI + RotL64(aCross, 19U)) + 1005891374086408851U;
            aOrbiterE = (aWandererK + RotL64(aScatter, 29U)) + 3713426782180050764U;
            aOrbiterC = (((aWandererH + RotL64(aIngress, 10U)) + RotL64(aCarry, 35U)) + 18358143862391573534U) + aOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = (((aWandererA + RotL64(aPrevious, 47U)) + RotL64(aCarry, 51U)) + 17504394029693712404U) + aOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aCross, 43U)) + RotL64(aCarry, 43U)) + 5312729289027417014U;
            aOrbiterG = (aWandererD + RotL64(aIngress, 23U)) + 2560873623431186029U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 16309322822806704211U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 10195513918020652600U) ^ aOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14569219741824123715U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 2552116263258744287U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 7732784879810980089U;
            aOrbiterI = RotL64((aOrbiterI * 15041929399477790999U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 16499127570665381507U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 10890036715535519036U;
            aOrbiterA = RotL64((aOrbiterA * 9065115450010475187U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 16288944603478791554U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 14542766121469312846U) ^ aOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8435383464425875209U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 5973595239494084696U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 1820492719977197097U;
            aOrbiterE = RotL64((aOrbiterE * 16164917159141304405U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 10489529555776381736U) + aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 6392552206958240484U;
            aOrbiterC = RotL64((aOrbiterC * 11761477994533503307U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 10163241948999404556U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 16054678853554707148U;
            aOrbiterB = RotL64((aOrbiterB * 10570418210789350091U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 3606021702108590330U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 16920568417324295852U) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 5222656554577625385U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 13889995689147406315U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 7908387312354285092U;
            aOrbiterG = RotL64((aOrbiterG * 7995682580514280949U), 51U);
            //
            aIngress = RotL64(aOrbiterA, 54U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 27U));
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterI, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterG, 41U)) + RotL64(aCarry, 23U)) + aNonceWordH);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterC, 47U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 11U)) + aOrbiterA) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 34U) + RotL64(aOrbiterG, 51U)) + aOrbiterJ) + aWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 21U) + aOrbiterH) + RotL64(aOrbiterI, 6U)) + aNonceWordM);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterA, 57U)) + aOrbiterD);
            aWandererB = aWandererB + ((RotL64(aScatter, 43U) + aOrbiterI) + RotL64(aOrbiterD, 27U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 60U) + aOrbiterB) + RotL64(aOrbiterJ, 37U));
            aWandererE = aWandererE + (((RotL64(aIngress, 39U) + RotL64(aOrbiterJ, 18U)) + aOrbiterA) + aWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 54U));
            aCarry = aCarry + RotL64(aWandererH, 37U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 25262U)) & S_BLOCK1], 28U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30829U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26839U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 25671U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCross, 11U)) + (RotL64(aCarry, 60U) + RotL64(aIngress, 43U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (((aWandererF + RotL64(aPrevious, 14U)) + RotL64(aCarry, 3U)) + 10336802574069791273U) + aNonceWordP;
            aOrbiterI = ((aWandererC + RotL64(aCross, 35U)) + RotL64(aCarry, 53U)) + 169025388197058936U;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 57U)) + RotL64(aCarry, 37U)) + 6541354188379168846U;
            aOrbiterK = (aWandererE + RotL64(aScatter, 19U)) + 16223920526599306104U;
            aOrbiterH = (aWandererH + RotL64(aCross, 53U)) + 12756613707692514808U;
            aOrbiterB = (aWandererI + RotL64(aPrevious, 47U)) + 5082475548176484035U;
            aOrbiterF = (((aWandererJ + RotL64(aScatter, 10U)) + 4907435526952698526U) + aOrbiterAssignSaltE[((aIndex + 20U)) & S_SALT1]) + aNonceWordO;
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 27U)) + 14236627073831834337U) + aNonceWordD;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 43U)) + 11502511046130497584U) + aOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 3679044835550219497U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 11254838916686736746U;
            aOrbiterA = RotL64((aOrbiterA * 8631695922983532915U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 10582608424233200966U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 10449735026385340313U;
            aOrbiterH = RotL64((aOrbiterH * 7363770199734997411U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 4628253464169957835U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 17664454668473204465U) ^ aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4234720298731378527U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 3798386391743884889U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 1379331161819246587U;
            aOrbiterD = RotL64((aOrbiterD * 13086160171095077295U), 43U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterD) + 9816600392407327227U) + aOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1]) + aNonceWordL;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 16781971616348376878U;
            aOrbiterK = RotL64((aOrbiterK * 12503867584828289879U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 4807797577690520554U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 2492057261148595922U;
            aOrbiterB = RotL64((aOrbiterB * 9453302540675483005U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 7909676419643119585U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 256053568910383007U;
            aOrbiterJ = RotL64((aOrbiterJ * 11965085163352053161U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 16179914439220412472U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 3968867762761955845U;
            aOrbiterE = RotL64((aOrbiterE * 7473632378251893139U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 7474832923901283742U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 4736994731050735779U;
            aOrbiterI = RotL64((aOrbiterI * 9839654409121414047U), 39U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 56U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 43U));
            aIngress = aIngress + RotL64(aOrbiterE, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 22U) + aOrbiterA) + RotL64(aOrbiterK, 51U)) + aWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 3U) + RotL64(aOrbiterK, 4U)) + aOrbiterE) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 53U) + aOrbiterD) + RotL64(aOrbiterB, 35U));
            aWandererF = aWandererF + (((RotL64(aIngress, 41U) + aOrbiterF) + RotL64(aOrbiterI, 27U)) + RotL64(aCarry, 29U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 46U) + RotL64(aOrbiterA, 19U)) + aOrbiterJ) + aNonceWordJ);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterJ, 44U)) + aOrbiterF) + aNonceWordA);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 27U) + aOrbiterA) + RotL64(aOrbiterH, 57U));
            aWandererE = aWandererE + ((RotL64(aIngress, 11U) + RotL64(aOrbiterI, 39U)) + aOrbiterB);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 57U) + aOrbiterH) + RotL64(aOrbiterF, 11U)) + aWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (RotL64(aWandererG, 30U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 37U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordP);
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

void TwistExpander_Karate_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xBEC7DE5A8C87E159ULL + 0x920D531C22769EFBULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xFCC4E3A7C198F1A3ULL + 0xA875A2EAFDA19812ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xD1CEB4F5240F1C5FULL + 0xC983FECACE60727DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xB8EA55FD86490205ULL + 0x908ADE114328DCA7ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xACBD297472DFCFCDULL + 0x9F56170DD3D65EEFULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xF83260FBA287CB8FULL + 0xB5B54C9B930B1159ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xA1D60FF462471313ULL + 0xA77B5C38A157A541ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xCD1E724B222122F5ULL + 0xA37DB530D03F2117ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x9053ACF3CC58EDEBULL + 0x92199277328E428FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xA02153AFF2EABF8FULL + 0x8489DC94AE190E87ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xA0B8F7FDFB46B81FULL + 0xD46B8C1F6369D76DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xE7A49D49A7EF992FULL + 0xC83CCE6850F1A9B4ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x8B91E0B2F1C509A3ULL + 0xB185DEFC58B7E7AEULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xBCE3D1CBF4807191ULL + 0x826037EF2711B8E1ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xD14F334E2F0DFB8BULL + 0xD4C7A9F9344BBEF2ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xD04DD302882023CDULL + 0x9B0E442B06AFF410ULL);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 1609U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 206U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 3621U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((aIndex + 6249U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 42U) ^ RotL64(aCross, 57U)) + (RotL64(aIngress, 27U) ^ RotL64(aCarry, 13U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (((aWandererI + RotL64(aScatter, 21U)) + RotL64(aCarry, 27U)) + 10812151398716051703U) + aOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = ((aWandererG + RotL64(aCross, 13U)) + RotL64(aCarry, 3U)) + 18202551453336003710U;
            aOrbiterF = (aWandererC + RotL64(aPrevious, 30U)) + 9434410809101973752U;
            aOrbiterI = (((aWandererD + RotL64(aIngress, 47U)) + RotL64(aCarry, 51U)) + 12955829998028534045U) + aNonceWordE;
            aOrbiterJ = (((aWandererK + RotL64(aPrevious, 57U)) + 12271740641929640181U) + aOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordN;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 14009351527014534752U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 4316296955679133450U) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 11582128345511775161U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 16473324966997442872U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 15735123324965019802U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5624078184997601019U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 17656375090484080236U) + aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 16066325053456055298U;
            aOrbiterI = RotL64((aOrbiterI * 17912970706985130327U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 12908968778503516903U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 12761433987676836197U;
            aOrbiterG = RotL64((aOrbiterG * 1023329467480907925U), 57U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterI) + 12737513138040664509U) + aOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1]) + aNonceWordL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 14535795767570998392U;
            aOrbiterJ = RotL64((aOrbiterJ * 15560519667062222269U), 13U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterC, 14U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 37U));
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((((RotL64(aIngress, 21U) + aOrbiterJ) + RotL64(aOrbiterF, 43U)) + RotL64(aCarry, 35U)) + aNonceWordF) + aWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 40U) + RotL64(aOrbiterC, 21U)) + aOrbiterF) + aNonceWordI);
            aWandererK = aWandererK + (((RotL64(aScatter, 13U) + RotL64(aOrbiterI, 52U)) + aOrbiterC) + RotL64(aCarry, 23U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 53U) + aOrbiterG) + RotL64(aOrbiterJ, 3U)) + aWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 35U)) + aOrbiterG) + aNonceWordA);
            //
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 39U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordP);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 15626U)) & S_BLOCK1], 42U) ^ RotL64(aOperationLaneD[((aIndex + 8456U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 14776U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 14250U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 37U)) ^ (RotL64(aPrevious, 50U) + RotL64(aCross, 21U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((((aWandererH + RotL64(aIngress, 57U)) + RotL64(aCarry, 19U)) + 7896237440058555694U) + aOrbiterAssignSaltB[((aIndex + 14U)) & S_SALT1]) + aNonceWordG;
            aOrbiterG = ((((aWandererK + RotL64(aCross, 3U)) + RotL64(aCarry, 5U)) + 11870529476037558635U) + aOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordP;
            aOrbiterC = (aWandererD + RotL64(aScatter, 19U)) + 9158983227801569448U;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 29U)) + RotL64(aCarry, 53U)) + 4710172270996950329U;
            aOrbiterI = (aWandererJ + RotL64(aScatter, 44U)) + 14634482800356647630U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 8822207952170610891U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 13755891414028982553U;
            aOrbiterC = RotL64((aOrbiterC * 5173750624716006485U), 57U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterD) + 4555293067488040719U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordC;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 2816805148093762081U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16838149138341713943U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 2122631477965135190U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 4592922416380416071U;
            aOrbiterK = RotL64((aOrbiterK * 11644507904538573165U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 7102471666524164715U) + aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 17274623547879474204U;
            aOrbiterG = RotL64((aOrbiterG * 5443572270546181789U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 938587316977094680U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 18258015823797023523U;
            aOrbiterD = RotL64((aOrbiterD * 6068819567674605919U), 37U);
            //
            aIngress = RotL64(aOrbiterD, 47U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + RotL64(aOrbiterK, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aCross, 21U) + aOrbiterI) + RotL64(aOrbiterC, 57U)) + aNonceWordA);
            aWandererK = aWandererK + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterG, 37U)) + aOrbiterK) + RotL64(aCarry, 29U)) + aNonceWordJ);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 11U)) + aOrbiterK);
            aWandererD = aWandererD + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterI, 46U)) + aOrbiterK) + RotL64(aCarry, 5U)) + aWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 60U) + aOrbiterC) + RotL64(aOrbiterK, 3U)) + aWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererI);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + RotL64(aWandererJ, 11U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordC);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 24568U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((aIndex + 23054U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 16693U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneC[((aIndex + 19394U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aIngress, 41U)) + (RotL64(aCarry, 11U) + RotL64(aPrevious, 26U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererF + RotL64(aIngress, 29U)) + RotL64(aCarry, 47U)) + 9107326720193244489U;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 3U)) + 10868585484401664145U) + aOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = (aWandererD + RotL64(aCross, 14U)) + 13637736741437846622U;
            aOrbiterH = (((aWandererJ + RotL64(aScatter, 51U)) + RotL64(aCarry, 27U)) + 6130725216183918844U) + aOrbiterAssignSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = (((aWandererB + RotL64(aCross, 41U)) + RotL64(aCarry, 5U)) + 2063834478521338187U) + aNonceWordO;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 8564870627911949158U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 6524015751064086390U) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 12055267995727104463U), 13U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterA) + 9874937766875388236U) + aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1]) + aNonceWordD;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 14723718409522680894U;
            aOrbiterB = RotL64((aOrbiterB * 17379140128833323431U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 13767059954741528279U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 6387608251033722169U;
            aOrbiterA = RotL64((aOrbiterA * 6601902195707980693U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 5391425980008431000U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 11524218415655093779U;
            aOrbiterH = RotL64((aOrbiterH * 12508457981779189389U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 155510463350385905U) + aOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 10554591788433641311U;
            aOrbiterF = RotL64((aOrbiterF * 5412084824127934293U), 39U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterB, 5U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 19U));
            aIngress = aIngress + RotL64(aOrbiterA, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aIngress, 3U) + aOrbiterI) + RotL64(aOrbiterH, 5U)) + aWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 35U) + aOrbiterF) + RotL64(aOrbiterH, 43U)) + RotL64(aCarry, 51U)) + aNonceWordG);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterA, 27U)) + aOrbiterH);
            aWandererD = aWandererD + (((RotL64(aScatter, 44U) + RotL64(aOrbiterB, 60U)) + aOrbiterA) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ ((((RotL64(aCross, 53U) + aOrbiterH) + RotL64(aOrbiterB, 13U)) + aNonceWordJ) + aWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (RotL64(aWandererJ, 60U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 13U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 31555U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26035U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31344U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((aIndex + 28929U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCross, 41U)) + (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 26U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (((aWandererH + RotL64(aScatter, 21U)) + RotL64(aCarry, 27U)) + 12131317914288566437U) + aNonceWordM;
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 4U)) + RotL64(aCarry, 11U)) + 5672805657999385496U;
            aOrbiterG = ((aWandererE + RotL64(aCross, 13U)) + RotL64(aCarry, 41U)) + 3581710244233124197U;
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 39U)) + 15251296040538489436U) + aOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 29U)) + 11295008604679904153U) + aOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 2230897493419504490U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 7109600123297458999U;
            aOrbiterG = RotL64((aOrbiterG * 8267799351136506307U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 13119156643107683803U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 14755160867807355250U;
            aOrbiterB = RotL64((aOrbiterB * 10007087518844899239U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 16829363373287496832U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 16981122946707720883U) ^ aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5394974422201576627U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 8806000776958603317U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 16810923047720876014U) ^ aOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17872735050219539145U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 8129657889554436328U) + aNonceWordI;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 8653100378491974463U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11395283153912468661U), 19U);
            //
            aIngress = RotL64(aOrbiterF, 47U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 39U) + aOrbiterC) + RotL64(aOrbiterG, 21U)) + aNonceWordJ) + aWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 18U) + aOrbiterB) + RotL64(aOrbiterC, 53U)) + RotL64(aCarry, 29U));
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterJ, 38U)) + aNonceWordA) + aWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterF, 29U)) + RotL64(aCarry, 51U)) + aNonceWordK);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 27U) + aOrbiterB) + RotL64(aOrbiterJ, 3U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + RotL64(aWandererH, 27U);
            aCarry = aCarry + RotL64(aIngress, 4U);
            aCarry = aCarry ^ aNonceWordB;
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

void TwistExpander_Karate_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xF7BE889CCB790453ULL + 0xAE22B3A8F872EDDDULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x866481B2498D3FF9ULL + 0xC64CD73C259EBF40ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xC6A779F35777AE0FULL + 0xD5E1DEB04CFD2038ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x876848587D734D13ULL + 0xF2221B3FB9E27C4AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xCD494B10712555C3ULL + 0x9B2ACCCA757F169BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x86848EE66F963649ULL + 0x8AD5B4DE7C044BA2ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x9E1F0A1A8B2329E9ULL + 0xA3C68341289D15A8ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xEF7AFBE7440EB4ADULL + 0xF2C1D1C5786967D6ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xDC5889C42AED67D5ULL + 0xF439676C56DDEDE2ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xD68AF9079BA1FF73ULL + 0x9D0381FE7868130CULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xA705E5E34BA8A335ULL + 0xAE715F03A73188C7ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x87541B086A2F8DB7ULL + 0xD9707444B9B658DFULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xC7486532F1ADD157ULL + 0xBC77DB321163A550ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xBB57D1EDE45C7A43ULL + 0x9A04D16BF5894912ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xE1FD4A85C685202FULL + 0x80803ED1986AA11AULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xA9273D12210DE6A5ULL + 0xE643929A9EE70BCFULL);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 5270U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7057U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3044U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 1523U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aIngress, 29U)) + (RotL64(aPrevious, 12U) ^ RotL64(aCarry, 41U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 47U)) + 16651241552253078315U) + aOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aScatter, 57U)) + 4558144676982478003U;
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 35U)) + RotL64(aCarry, 3U)) + 8814884320080367550U;
            aOrbiterB = (((aWandererA + RotL64(aIngress, 44U)) + RotL64(aCarry, 29U)) + 16011579668555672117U) + aNonceWordN;
            aOrbiterK = (aWandererB + RotL64(aCross, 23U)) + 4738918668759862438U;
            aOrbiterF = (((aWandererF + RotL64(aScatter, 11U)) + 12526083125540985108U) + aOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordP;
            aOrbiterA = (aWandererE + RotL64(aIngress, 51U)) + 8048723561746000552U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 1082218464034639039U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 8432043246965946816U;
            aOrbiterI = RotL64((aOrbiterI * 7801965585991025451U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 9982080524048636852U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 6720069955755215919U) ^ aNonceWordJ;
            aOrbiterK = RotL64((aOrbiterK * 1025046364205332059U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 1019035028070247757U) + aOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 7360619079463870467U;
            aOrbiterF = RotL64((aOrbiterF * 6623074813047915863U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 10893918488381348474U) + aOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 1390297670907738019U;
            aOrbiterA = RotL64((aOrbiterA * 11909657437658597735U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 12512200589031203480U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 14741471280748399540U;
            aOrbiterH = RotL64((aOrbiterH * 3012135242889901095U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 8543897248359826770U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterF) ^ 8545972622733791272U) ^ aOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 11793879362775346821U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 7049384618581928664U) + aNonceWordC;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 14730773807906925408U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10711566871536755073U), 13U);
            //
            aIngress = RotL64(aOrbiterF, 27U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 56U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 23U) + aOrbiterH) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterF, 29U)) + aOrbiterI) + aNonceWordL);
            aWandererA = aWandererA + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterB, 37U)) + aOrbiterA) + RotL64(aCarry, 21U)) + aNonceWordM);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterK, 11U)) + aOrbiterG) + aWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 40U) + aOrbiterK) + RotL64(aOrbiterA, 56U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterB, 3U));
            aWandererI = aWandererI + ((((RotL64(aCross, 47U) + RotL64(aOrbiterI, 19U)) + aOrbiterA) + aNonceWordK) + aWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 10U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + RotL64(aWandererF, 27U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordE);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 11329U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15757U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15208U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9705U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCarry, 21U)) + (RotL64(aPrevious, 37U) ^ RotL64(aCross, 4U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererB + RotL64(aIngress, 42U)) + 1888427424966603593U) + aNonceWordB;
            aOrbiterK = (((aWandererH + RotL64(aScatter, 57U)) + RotL64(aCarry, 39U)) + 5436761445660415091U) + aOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aCross, 13U)) + 17322876217962143270U;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 35U)) + 9728299982740564979U;
            aOrbiterE = (((aWandererI + RotL64(aCross, 27U)) + 301720335271716921U) + aOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordN;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 21U)) + RotL64(aCarry, 5U)) + 8069685428854814396U;
            aOrbiterI = ((aWandererA + RotL64(aIngress, 3U)) + RotL64(aCarry, 19U)) + 1973715500949100991U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 87666408799854155U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 12195436904339035245U;
            aOrbiterJ = RotL64((aOrbiterJ * 15427739165893738105U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 4578742069143400295U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 7828776048774876484U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4047964518501081039U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 17203146364542781833U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 16913369550858890466U;
            aOrbiterC = RotL64((aOrbiterC * 13534417587921978507U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 9632761514552265402U) + aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 9106637671877341286U) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 9073709119482640391U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 15423680889126750876U) + aOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 6087310684583331882U) ^ aNonceWordG;
            aOrbiterE = RotL64((aOrbiterE * 8964465129744898619U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 5420955876411796789U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 14166807419730848032U) ^ aNonceWordE;
            aOrbiterF = RotL64((aOrbiterF * 442659738632823751U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 8118312450347026824U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 4253043584558403086U;
            aOrbiterI = RotL64((aOrbiterI * 5651748455190536467U), 21U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 21U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aIngress, 13U) + RotL64(aOrbiterK, 35U)) + aOrbiterG);
            aWandererA = aWandererA ^ ((RotL64(aCross, 21U) + aOrbiterI) + RotL64(aOrbiterJ, 21U));
            aWandererH = aWandererH + (((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 3U)) + aOrbiterC) + aNonceWordD);
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterI, 54U)) + aOrbiterG) + aNonceWordF) + aWandererUpdateSaltB[((aIndex + 28U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 28U) + aOrbiterE) + RotL64(aOrbiterI, 11U)) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 27U)) + aOrbiterG);
            aWandererC = aWandererC + ((((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 43U)) + aOrbiterF) + RotL64(aCarry, 47U)) + aWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 40U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 16852U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18486U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18575U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneC[((aIndex + 19272U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 54U) + RotL64(aCarry, 13U)) ^ (RotL64(aIngress, 27U) + RotL64(aCross, 39U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererG + RotL64(aCross, 3U)) + 14249093584376402677U;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 58U)) + RotL64(aCarry, 11U)) + 8756965951816492264U;
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 13U)) + 11221139480258176330U) + aOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = ((((aWandererB + RotL64(aScatter, 35U)) + RotL64(aCarry, 39U)) + 17218894445564194851U) + aOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterH = (aWandererK + RotL64(aCross, 23U)) + 8064642692524949490U;
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 43U)) + 5822093203710704646U) + aNonceWordH;
            aOrbiterA = ((aWandererA + RotL64(aIngress, 29U)) + RotL64(aCarry, 53U)) + 3217799620158102238U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 2613757677892120843U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 13647481499551657237U;
            aOrbiterC = RotL64((aOrbiterC * 5517563514031899891U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 3545714196663685016U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 9735422670576621521U;
            aOrbiterD = RotL64((aOrbiterD * 7276207208162697249U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 3911046580637583767U) + aNonceWordK;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 9315984027042049203U;
            aOrbiterB = RotL64((aOrbiterB * 12568550776487242469U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 8926367674641729058U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 11035347490524961446U) ^ aOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10948288997163592463U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 10748158733051120339U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 2467801787989056455U;
            aOrbiterH = RotL64((aOrbiterH * 12621934274702358977U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 9244415080474351390U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 8517784887959492079U;
            aOrbiterJ = RotL64((aOrbiterJ * 17022899813765884147U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 8409307332803038455U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 11043806021873232950U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8294888329708842989U), 3U);
            //
            aIngress = RotL64(aOrbiterA, 35U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 53U) + RotL64(aOrbiterC, 13U)) + aOrbiterI) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterH, 41U)) + aOrbiterB);
            aWandererK = aWandererK + (((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 19U)) + aOrbiterH) + aNonceWordL);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterC, 56U)) + aOrbiterD) + aNonceWordP);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 47U) + aOrbiterC) + RotL64(aOrbiterJ, 35U)) + aWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 27U) + aOrbiterD) + RotL64(aOrbiterA, 29U)) + aWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 36U) + RotL64(aOrbiterB, 3U)) + aOrbiterC) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 26U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ aNonceWordA;
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 26558U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((aIndex + 25849U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24679U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 25905U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCarry, 39U)) ^ (RotL64(aCross, 3U) ^ RotL64(aPrevious, 20U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((((aWandererA + RotL64(aIngress, 27U)) + RotL64(aCarry, 53U)) + 7893287783892523139U) + aOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordO;
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 11U)) + 10257331997383491153U;
            aOrbiterG = (aWandererC + RotL64(aCross, 37U)) + 14562226733652231753U;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 51U)) + RotL64(aCarry, 11U)) + 14320342577110737851U;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 20U)) + 9816717579822880756U) + aNonceWordI;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 57U)) + 9558926960095881953U) + aOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = (((aWandererH + RotL64(aCross, 3U)) + RotL64(aCarry, 37U)) + 9230371862654338324U) + aNonceWordC;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 6414274291252913420U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 13868546184398350849U) ^ aOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1547986864837497409U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 16940736952569949038U) + aNonceWordF;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 2866957764814864371U;
            aOrbiterF = RotL64((aOrbiterF * 3554702178644797003U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 7916721976073979724U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 1602444214978842275U;
            aOrbiterJ = RotL64((aOrbiterJ * 11072503711308122385U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 9529061385251008037U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 8402775110887376588U) ^ aOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13980225144628227381U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 15003592180290390713U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 14195681406520825751U;
            aOrbiterH = RotL64((aOrbiterH * 11455000833788877217U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 3263577002367714202U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 12019422062655581928U) ^ aNonceWordE;
            aOrbiterD = RotL64((aOrbiterD * 5002313835338447799U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 8508638054582582917U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 6536618106353552880U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6233964121117511885U), 53U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 29U);
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 60U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aScatter, 29U) + RotL64(aOrbiterG, 6U)) + aOrbiterC) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 23U) + aOrbiterC) + RotL64(aOrbiterD, 35U)) + aWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterJ, 47U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 50U) + aOrbiterE) + RotL64(aOrbiterJ, 23U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterH, 13U)) + aOrbiterF) + aNonceWordP) + aWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterE, 29U)) + aOrbiterF);
            aWandererH = aWandererH + (((RotL64(aIngress, 11U) + RotL64(aOrbiterH, 41U)) + aOrbiterG) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 30U));
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + RotL64(aWandererG, 47U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordB);
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

void TwistExpander_Karate_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xA1E0EFA1346C0E67ULL + 0xCE21B6E4457F5159ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xC532696F86AEDB1DULL + 0xA5C944424210367EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xED79CCF7D3CCB26DULL + 0xA9786F335CC29A3BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x8B0BB0491AF10E81ULL + 0xDCC211259DD215BBULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xD36E6C73F82AF485ULL + 0x814F1BF25C6B1265ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xDB3A85721BC3CE65ULL + 0xF66D8FB166D75033ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x92ED6BE8E27BEBC7ULL + 0xD62EAA649F168530ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xEF9AA290AC699A7BULL + 0xB352E63F1C65FD69ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x9F4B27A2BCA32083ULL + 0x838381EDAF2A4B3DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xD0CDE1BC41BD32C5ULL + 0xB88AE120C35ABEE6ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x8D39C4DF502A18D5ULL + 0x9A71E0A63472EEB1ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xD9D045CB0B33632FULL + 0xD6E0F2B01117A2D9ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xD8F9D6C228888E2FULL + 0xC63746548D8A23D3ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xC238C2FBCD0DB7AFULL + 0x954B32F2F2E047B4ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xF622FF1D1C16E007ULL + 0xDFAAA3B3B0A9A644ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x9569B8BA9A5920E7ULL + 0xF20AA1B0B2E195C6ULL);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 8184U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 1071U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 2857U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneA[((aIndex + 7425U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 58U) ^ RotL64(aCross, 41U)) + (RotL64(aCarry, 11U) + RotL64(aIngress, 29U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererH + RotL64(aIngress, 6U)) + 13481227414590594621U;
            aOrbiterI = (aWandererC + RotL64(aCross, 13U)) + 17425964381118918026U;
            aOrbiterC = (((aWandererJ + RotL64(aPrevious, 51U)) + RotL64(aCarry, 51U)) + 4792004356135956581U) + aNonceWordG;
            aOrbiterF = (aWandererF + RotL64(aScatter, 43U)) + 11926849936000639098U;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 23U)) + 990697329347742142U) + aOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = ((aWandererE + RotL64(aScatter, 57U)) + RotL64(aCarry, 19U)) + 9307721505373076588U;
            aOrbiterH = (((aWandererK + RotL64(aIngress, 29U)) + RotL64(aCarry, 39U)) + 17605732738841908719U) + aOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 13110764518634187439U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 17970109897810645911U;
            aOrbiterC = RotL64((aOrbiterC * 10395095143998920213U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 10273133817644703654U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 11239046688920468137U;
            aOrbiterE = RotL64((aOrbiterE * 5197802934333553327U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 8355821483275763145U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 15522151127786049345U) ^ aOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4844278537850520413U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 5381663179722418112U) + aNonceWordI;
            aOrbiterH = (((aOrbiterH ^ aOrbiterC) ^ 9551368011768104906U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 14202470972121732997U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 16264476585232221270U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 7721417776432288282U;
            aOrbiterG = RotL64((aOrbiterG * 10267770327791051869U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 339418090653475277U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 3247926250495935511U;
            aOrbiterF = RotL64((aOrbiterF * 16824669543765729097U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 3390560045236418590U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterH) ^ 3894024951542543635U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 10599637790900418767U), 29U);
            //
            aIngress = RotL64(aOrbiterD, 11U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 23U));
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterC, 51U)) + aOrbiterD);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterI, 19U)) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ ((((RotL64(aScatter, 60U) + aOrbiterG) + RotL64(aOrbiterE, 57U)) + aNonceWordE) + aWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 11U) + aOrbiterG) + RotL64(aOrbiterH, 29U)) + RotL64(aCarry, 35U)) + aWandererUpdateSaltF[((aIndex + 8U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 13U)) + aOrbiterH);
            aWandererK = aWandererK + ((RotL64(aScatter, 27U) + RotL64(aOrbiterH, 39U)) + aOrbiterE);
            aWandererD = aWandererD ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterD, 4U)) + aOrbiterF) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererC, 60U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordB);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 13129U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8332U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 10626U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 13126U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 29U) + RotL64(aCarry, 54U)) ^ (RotL64(aCross, 41U) ^ RotL64(aPrevious, 5U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererE + RotL64(aScatter, 50U)) + RotL64(aCarry, 29U)) + 16160838483846078448U;
            aOrbiterC = (((aWandererG + RotL64(aIngress, 11U)) + 15404960896190227946U) + aOrbiterAssignSaltA[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordO;
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 37U)) + RotL64(aCarry, 57U)) + 16904160594024977199U;
            aOrbiterE = (((aWandererJ + RotL64(aCross, 19U)) + 17790460246821031802U) + aOrbiterAssignSaltD[((aIndex + 24U)) & S_SALT1]) + aNonceWordI;
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 29U)) + 16395168254086971959U) + aNonceWordD;
            aOrbiterG = (aWandererH + RotL64(aIngress, 5U)) + 7484373204039901786U;
            aOrbiterB = ((aWandererF + RotL64(aCross, 57U)) + RotL64(aCarry, 13U)) + 18026814691322913510U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 15244817793136966450U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 5795491730356335666U;
            aOrbiterF = RotL64((aOrbiterF * 13253529465289332171U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 3163873518027801504U) + aNonceWordB;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 2690791759507349172U;
            aOrbiterH = RotL64((aOrbiterH * 16677948635136515083U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 17898067251167087906U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 8028010015006604239U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5601629670521300241U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 7304739457289910555U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 6476837815096530043U) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 16380545138701113267U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 14242499233467960602U) + aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 17305645693017634630U) ^ aNonceWordF;
            aOrbiterJ = RotL64((aOrbiterJ * 14442976693206929569U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 9772864059444171908U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 7897200728282156408U;
            aOrbiterG = RotL64((aOrbiterG * 816306719390807411U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 4890999319172950996U) + aOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 8165132649356094963U;
            aOrbiterB = RotL64((aOrbiterB * 17297706071263690189U), 5U);
            //
            aIngress = RotL64(aOrbiterH, 39U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterG, 22U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 53U) + aOrbiterH) + RotL64(aOrbiterB, 35U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterE, 41U)) + aOrbiterH);
            aWandererH = aWandererH ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterF, 27U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 13U) + aOrbiterC) + RotL64(aOrbiterH, 21U)) + RotL64(aCarry, 53U)) + aNonceWordC);
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 21U) + RotL64(aOrbiterG, 54U)) + aOrbiterB) + aNonceWordJ) + aWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 41U) + aOrbiterE) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 41U));
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 4U) + aOrbiterC) + RotL64(aOrbiterJ, 47U)) + aNonceWordN) + aWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + (RotL64(aWandererA, 6U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordP;
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22049U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((aIndex + 18083U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 23696U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 19977U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 3U)) + (RotL64(aIngress, 20U) + RotL64(aCross, 41U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (((aWandererG + RotL64(aIngress, 51U)) + RotL64(aCarry, 3U)) + 4634399531433127141U) + aNonceWordP;
            aOrbiterI = (((aWandererA + RotL64(aCross, 60U)) + RotL64(aCarry, 53U)) + 16961792729406903200U) + aNonceWordN;
            aOrbiterJ = (((aWandererH + RotL64(aPrevious, 3U)) + RotL64(aCarry, 21U)) + 4105280732301137738U) + aOrbiterAssignSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = (aWandererC + RotL64(aScatter, 35U)) + 15692013501147331191U;
            aOrbiterD = (((aWandererD + RotL64(aCross, 29U)) + 1252216715968780587U) + aOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterK = (aWandererB + RotL64(aScatter, 43U)) + 7958289043012473752U;
            aOrbiterC = (aWandererK + RotL64(aIngress, 19U)) + 6611577301818896615U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 8506226754305949140U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 3648813120449403353U) ^ aOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9521367946879238849U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 5195245426245535735U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 542948051600803051U;
            aOrbiterI = RotL64((aOrbiterI * 4631106308856448475U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 11974253551208964789U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 10596463592332655367U;
            aOrbiterF = RotL64((aOrbiterF * 10941161258815714641U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 12015129484061440159U) + aOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 8254944355710109060U;
            aOrbiterH = RotL64((aOrbiterH * 3233697992479357615U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 2754858806943915419U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 5007802002906662779U;
            aOrbiterD = RotL64((aOrbiterD * 15613733948331639723U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 6262190752136523216U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 10528977986487821428U) ^ aNonceWordE;
            aOrbiterK = RotL64((aOrbiterK * 1184258264034585525U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 8511097226098211854U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 12091864735686692582U) ^ aOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6128140528141411237U), 41U);
            //
            aIngress = RotL64(aOrbiterF, 53U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterJ, 42U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterJ, 27U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 60U) + RotL64(aOrbiterD, 57U)) + aOrbiterF) + aNonceWordB);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 39U)) + aNonceWordI);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 47U)) + aOrbiterI) + aWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 41U) + aOrbiterH) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterH, 41U));
            aWandererC = aWandererC + (((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 14U)) + aOrbiterI) + aWandererUpdateSaltA[((aIndex + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 52U));
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererK, 27U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29181U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25347U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27675U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneD[((aIndex + 26721U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 47U) + RotL64(aCross, 4U)) ^ (RotL64(aIngress, 23U) ^ RotL64(aCarry, 35U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (((aWandererE + RotL64(aIngress, 5U)) + RotL64(aCarry, 35U)) + 1708250618750199233U) + aNonceWordP;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 54U)) + RotL64(aCarry, 3U)) + 12009147777553691142U;
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 47U)) + 8393982703399156592U;
            aOrbiterG = (((aWandererJ + RotL64(aCross, 41U)) + RotL64(aCarry, 21U)) + 3247327098356831221U) + aOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = (aWandererF + RotL64(aPrevious, 27U)) + 3403590155376353737U;
            aOrbiterD = ((aWandererB + RotL64(aCross, 13U)) + 18197244558104735044U) + aOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aScatter, 21U)) + 3096253642040701606U) + aNonceWordC;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 8012692688785412179U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 17531946907545680745U;
            aOrbiterJ = RotL64((aOrbiterJ * 16510602981731506381U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 17687695944270225817U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 16147773866007628769U) ^ aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16926442582711557877U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 18244641303026196497U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 8839160526348897457U;
            aOrbiterA = RotL64((aOrbiterA * 14268021129087663397U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 10599266240854068246U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 2056723540756216155U;
            aOrbiterK = RotL64((aOrbiterK * 13311591601230386375U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 4629354220460621284U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 9505955649473204942U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17775391885312236187U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 17078153810088721310U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 9470436761716263000U;
            aOrbiterG = RotL64((aOrbiterG * 5431855497250357229U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 3305863413630104742U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterK) ^ 14377172434239576161U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterF = RotL64((aOrbiterF * 6880176890091033423U), 37U);
            //
            aIngress = RotL64(aOrbiterJ, 35U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 58U));
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterD, 27U)) + aOrbiterK);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 41U) + RotL64(aOrbiterA, 35U)) + aOrbiterF) + RotL64(aCarry, 27U)) + aWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 54U) + aOrbiterG) + RotL64(aOrbiterA, 13U)) + aNonceWordM);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterI, 3U)) + aOrbiterJ) + RotL64(aCarry, 13U)) + aNonceWordF);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 27U) + aOrbiterK) + RotL64(aOrbiterJ, 47U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterJ, 56U)) + aOrbiterG);
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 21U) + RotL64(aOrbiterA, 19U)) + aOrbiterK) + aNonceWordA) + aWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 60U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ aNonceWordB;
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

void TwistExpander_Karate_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xB6B639B23DE020EBULL + 0xEA1833316F9E3CC2ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xAA64C442E18D6477ULL + 0x8E760E45DC930DC7ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xB182987B482A76FDULL + 0x9C1C868EAF16D99CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xBEC6CEE16CFEA9FFULL + 0xE82274CDA80A5AD6ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xED1B7727530E93A7ULL + 0xC5159A5B06EC59C5ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xC075C48C5C6EAD6DULL + 0xF160522F4065EAD2ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xFDD47818A13E5523ULL + 0xF8D1406BBB3C60FBULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xCF728E4F537C7BFDULL + 0xB5686DB84EE70E1CULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x953ACA45B9484E2DULL + 0x84A4831941035F78ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x80EF70310A49A435ULL + 0xA6DC621435B0E44DULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xF99294BDFCE4CBE7ULL + 0xF9C244D91F967D29ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xB81E267EAB788971ULL + 0xEC2169295035C703ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x94908EE0E53A475FULL + 0xCB106C3716EF1DA2ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xB00C05737725B1E9ULL + 0xA850BD568A9F3237ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xDA4F77F275083F6FULL + 0xD026F79512CC849AULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xD4A76FD894825413ULL + 0xB98BDEB1AA63C41DULL);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 7739U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3188U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 165U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneA[((aIndex + 645U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCross, 34U)) ^ (RotL64(aCarry, 3U) + RotL64(aPrevious, 47U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererF + RotL64(aIngress, 43U)) + RotL64(aCarry, 39U)) + 5041131702736607991U;
            aOrbiterC = (aWandererD + RotL64(aScatter, 41U)) + 9295010428212681446U;
            aOrbiterI = ((aWandererH + RotL64(aCross, 19U)) + 6235875895358766017U) + aOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 11U)) + 2622227802531866918U) + aNonceWordA;
            aOrbiterH = (((aWandererI + RotL64(aCross, 23U)) + 3888894734834524972U) + aOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 6U)) + 241682012014701753U;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 21U)) + RotL64(aCarry, 3U)) + 15758000422451568079U;
            aOrbiterD = (aWandererC + RotL64(aIngress, 51U)) + 2061944548396976912U;
            aOrbiterE = (aWandererG + RotL64(aScatter, 57U)) + 8177144990755754531U;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 39U)) + RotL64(aCarry, 43U)) + 554978075608818497U;
            aOrbiterK = (aWandererK + RotL64(aIngress, 28U)) + 250408260560714933U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 8700027645880997552U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 10026130047465480902U;
            aOrbiterI = RotL64((aOrbiterI * 12417270861933696623U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 9785843014096326696U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 9998582683258411251U;
            aOrbiterG = RotL64((aOrbiterG * 7197956237569462269U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 13817734599383455151U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 6647207154174092691U;
            aOrbiterA = RotL64((aOrbiterA * 1578528131687283531U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 4957715980509035719U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 4994885315786213197U;
            aOrbiterB = RotL64((aOrbiterB * 5676683798126497011U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 5072908311783966503U) + aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 5535039946192891515U;
            aOrbiterF = RotL64((aOrbiterF * 2989412783482309753U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 6594577050344146271U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 8750154123258714856U;
            aOrbiterE = RotL64((aOrbiterE * 6942158167127532003U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 3514769314840874873U) + aNonceWordP;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 8626045200273524281U;
            aOrbiterK = RotL64((aOrbiterK * 4315441782689789689U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 8524870284841706517U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 1841819423572964209U;
            aOrbiterC = RotL64((aOrbiterC * 9802481758007234681U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 12668382464510772517U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 6330331402801670515U;
            aOrbiterH = RotL64((aOrbiterH * 9096920618612750935U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 10346986196055766087U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 10932918162471200996U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6863632877625141567U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 6264557195446069146U) + aNonceWordE;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 5041131702736607991U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4978591546106895045U), 29U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 42U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterG, 39U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterE, 13U)) + aOrbiterB) + aNonceWordH) + aWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 22U) + RotL64(aOrbiterI, 53U)) + aOrbiterG);
            aWandererK = aWandererK + ((RotL64(aScatter, 39U) + RotL64(aOrbiterA, 47U)) + aOrbiterJ);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 27U) + aOrbiterJ) + RotL64(aOrbiterI, 44U)) + aNonceWordC);
            aWandererD = aWandererD + (((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 11U)) + aOrbiterD) + aNonceWordB);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 35U) + aOrbiterA) + RotL64(aOrbiterK, 51U));
            aWandererC = aWandererC + (((RotL64(aCross, 10U) + aOrbiterJ) + RotL64(aOrbiterC, 21U)) + RotL64(aCarry, 29U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 53U) + aOrbiterA) + RotL64(aOrbiterH, 23U));
            aWandererA = aWandererA + ((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterA, 37U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterC, 19U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 6U)) + aOrbiterF) + RotL64(aCarry, 57U)) + aWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 34U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + RotL64(aWandererB, 43U);
            aCarry = aCarry + RotL64(aIngress, 12U);
            aCarry = aCarry ^ aNonceWordB;
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 14017U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10359U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13987U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneB[((aIndex + 15331U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 19U)) + (RotL64(aCross, 4U) ^ RotL64(aIngress, 53U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererB + RotL64(aIngress, 36U)) + RotL64(aCarry, 37U)) + 12690502671561165478U;
            aOrbiterD = (aWandererA + RotL64(aCross, 57U)) + 17519943923428102801U;
            aOrbiterA = (aWandererE + RotL64(aScatter, 53U)) + 10705515807975331385U;
            aOrbiterB = (((aWandererF + RotL64(aPrevious, 23U)) + RotL64(aCarry, 5U)) + 16586447272278538179U) + aOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (aWandererH + RotL64(aScatter, 51U)) + 8006560996840971798U;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 19U)) + 12928600185788857701U) + aOrbiterAssignSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aCross, 5U)) + 14240723153798267172U;
            aOrbiterH = (aWandererD + RotL64(aPrevious, 30U)) + 8636219177994872072U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 27U)) + 7586790235186467512U) + aNonceWordL;
            aOrbiterF = ((aWandererI + RotL64(aCross, 47U)) + RotL64(aCarry, 21U)) + 1103807034179512424U;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 3U)) + 7547526530239498693U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 8380239679344786397U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 5690809173787433519U;
            aOrbiterA = RotL64((aOrbiterA * 5354724308093372953U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 8390902801141804609U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 3507306189192059486U;
            aOrbiterD = RotL64((aOrbiterD * 18336280496510253103U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 6190745292098482871U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 8065418693975056902U) ^ aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6414621418430102589U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 12111755051718111803U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 7605877769709909297U;
            aOrbiterJ = RotL64((aOrbiterJ * 17525248694315944599U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 5969794501112646237U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 5127559299360591476U;
            aOrbiterE = RotL64((aOrbiterE * 4521563633438853069U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 10593847754747739786U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 4401750688524310121U;
            aOrbiterI = RotL64((aOrbiterI * 14265829318976633707U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 6927893132508779499U) + aOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 4874009978647014479U;
            aOrbiterB = RotL64((aOrbiterB * 13340466017023540755U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 13146693487138744677U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 3298472134223595298U;
            aOrbiterK = RotL64((aOrbiterK * 2145005258008477281U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 8729305340729268734U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 18347161842033439538U) ^ aNonceWordI;
            aOrbiterH = RotL64((aOrbiterH * 7952715248988302017U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 166831495912855225U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 4943633045563697271U;
            aOrbiterF = RotL64((aOrbiterF * 1809857625425000137U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 2460623715340753589U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 12690502671561165478U;
            aOrbiterC = RotL64((aOrbiterC * 16421139715633515623U), 27U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterE, 53U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 58U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 39U));
            aIngress = aIngress + (RotL64(aOrbiterH, 23U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterB, 60U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 24U)) + aOrbiterI) + aNonceWordC);
            aWandererD = aWandererD + (((RotL64(aCross, 21U) + aOrbiterF) + RotL64(aOrbiterB, 41U)) + RotL64(aCarry, 19U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 5U) + aOrbiterF) + RotL64(aOrbiterD, 37U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 13U)) + aOrbiterG) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 44U) + aOrbiterF) + RotL64(aOrbiterK, 11U)) + aWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 29U) + RotL64(aOrbiterI, 47U)) + aOrbiterH) + aWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 23U) + aOrbiterA) + RotL64(aOrbiterE, 39U));
            aWandererF = aWandererF + ((RotL64(aScatter, 41U) + RotL64(aOrbiterK, 21U)) + aOrbiterC);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 34U) + RotL64(aOrbiterF, 35U)) + aOrbiterG);
            aWandererE = aWandererE + ((RotL64(aScatter, 27U) + RotL64(aOrbiterA, 3U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterF, 30U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 12U));
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 51U);
            aCarry = aCarry + RotL64(aIngress, 42U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 17120U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((aIndex + 17429U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17502U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 16619U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 47U) ^ RotL64(aPrevious, 35U)) + (RotL64(aCross, 22U) ^ RotL64(aIngress, 3U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererG + RotL64(aPrevious, 41U)) + 12692813903177772178U;
            aOrbiterA = ((aWandererD + RotL64(aCross, 13U)) + 7112496446691277899U) + aOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = (aWandererE + RotL64(aIngress, 34U)) + 2112247138290568813U;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 21U)) + RotL64(aCarry, 37U)) + 3699421080882855947U;
            aOrbiterH = (aWandererA + RotL64(aIngress, 51U)) + 13761832028354380922U;
            aOrbiterK = (aWandererI + RotL64(aCross, 27U)) + 9243822514887600214U;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 47U)) + 6863833516853046129U;
            aOrbiterC = (aWandererF + RotL64(aScatter, 30U)) + 8863897995943098018U;
            aOrbiterF = (((aWandererC + RotL64(aPrevious, 37U)) + RotL64(aCarry, 19U)) + 13346785686701467520U) + aOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aCross, 5U)) + RotL64(aCarry, 27U)) + 15309543066305531619U;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 43U)) + 17515530938817919111U) + aNonceWordA;
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 760493237816424254U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 7282586354117620860U) ^ aNonceWordH;
            aOrbiterJ = RotL64((aOrbiterJ * 2327153408185290635U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 4129706068526969105U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 7020175432730888755U;
            aOrbiterK = RotL64((aOrbiterK * 10095158356907592239U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 9102258982216515596U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 10822031305361453690U;
            aOrbiterA = RotL64((aOrbiterA * 2036205056490578491U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 12571477440964330246U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 8436347026653095199U;
            aOrbiterH = RotL64((aOrbiterH * 17930734781213681573U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 14214789872073941940U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 12915911919403385001U;
            aOrbiterC = RotL64((aOrbiterC * 13161681603528031511U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 15443240166233851298U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 7311369180113240915U) ^ aOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13339195007946889423U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 12976516224995960015U) + aOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 7823308381434556721U) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 502385172763861451U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 4829417661664149137U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 16306394751966719700U) ^ aNonceWordD;
            aOrbiterD = RotL64((aOrbiterD * 5294376579588592157U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 16769868341852572677U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 7107433163189177642U;
            aOrbiterG = RotL64((aOrbiterG * 5279050651595743649U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 11896784111967113871U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 389626690429371003U;
            aOrbiterF = RotL64((aOrbiterF * 10665914532159182181U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 8226849597052979358U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 12692813903177772178U;
            aOrbiterB = RotL64((aOrbiterB * 17909062471564422847U), 27U);
            //
            aIngress = RotL64(aOrbiterJ, 21U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterK, 60U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterG, 37U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterB, 10U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aCross, 27U) + RotL64(aOrbiterA, 4U)) + aOrbiterH) + aWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 60U) + aOrbiterG) + RotL64(aOrbiterK, 23U));
            aWandererB = aWandererB + (((RotL64(aIngress, 5U) + RotL64(aOrbiterG, 21U)) + aOrbiterB) + aNonceWordP);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterE, 19U)) + aOrbiterD);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 11U) + aOrbiterA) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 43U)) + aWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 47U)) + aOrbiterJ);
            aWandererE = aWandererE + ((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterH, 50U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterJ, 37U)) + aOrbiterB) + aNonceWordB);
            aWandererD = aWandererD + (((RotL64(aIngress, 21U) + RotL64(aOrbiterK, 27U)) + aOrbiterF) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 30U) + aOrbiterF) + RotL64(aOrbiterG, 57U)) + aNonceWordK);
            aWandererA = aWandererA + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterK, 41U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 54U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 56U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ aNonceWordI;
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 28765U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28029U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 32597U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 25764U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 57U)) ^ (RotL64(aCross, 37U) + RotL64(aIngress, 6U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (((aWandererJ + RotL64(aCross, 37U)) + RotL64(aCarry, 3U)) + 3917730204724097072U) + aNonceWordN;
            aOrbiterB = (((aWandererH + RotL64(aPrevious, 27U)) + RotL64(aCarry, 29U)) + 1874642340716212824U) + aNonceWordO;
            aOrbiterG = (aWandererE + RotL64(aIngress, 13U)) + 6900165757434854160U;
            aOrbiterD = (aWandererF + RotL64(aScatter, 30U)) + 12750946097023807161U;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 11U)) + 6563216048479513594U) + aOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 43U)) + 14960240191349450795U) + aOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = ((aWandererD + RotL64(aScatter, 47U)) + RotL64(aCarry, 43U)) + 16306180275951788289U;
            aOrbiterK = (aWandererK + RotL64(aCross, 5U)) + 6502066618271045547U;
            aOrbiterC = (aWandererC + RotL64(aScatter, 41U)) + 6219852857850888738U;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 35U)) + 2272931312452845850U;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 60U)) + 3028929882263199463U) + aNonceWordJ;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 6067393030073568112U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 10094809900437037258U;
            aOrbiterG = RotL64((aOrbiterG * 18095564940730322769U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 5962414178157074575U) + aOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 15755563045799129417U;
            aOrbiterI = RotL64((aOrbiterI * 3692603590609922031U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 6321455513889880590U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 1197435601998121700U;
            aOrbiterH = RotL64((aOrbiterH * 17693996266260557625U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 12496949381666299968U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 6357070235648527030U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2931486644220862433U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 8423760160877540210U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 8090246492554850768U;
            aOrbiterK = RotL64((aOrbiterK * 2949407491181921633U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 11436635942985063755U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 17086363141014359856U;
            aOrbiterC = RotL64((aOrbiterC * 10504127577318206801U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 10734017887545474935U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 375515325165740779U;
            aOrbiterF = RotL64((aOrbiterF * 9980486695448151709U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 5217148491945389821U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 14696058217023530058U;
            aOrbiterJ = RotL64((aOrbiterJ * 11026674782236654799U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 11869055287836412650U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 16951500118659983436U;
            aOrbiterA = RotL64((aOrbiterA * 4304372681583055077U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 7866300390953569803U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 18017335943787362993U;
            aOrbiterB = RotL64((aOrbiterB * 15683049583437004889U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 2477944286851267725U) + aNonceWordE;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 3917730204724097072U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6617615984203047419U), 41U);
            //
            aIngress = RotL64(aOrbiterH, 27U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 6U));
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterC, 41U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 37U) + aOrbiterC) + RotL64(aOrbiterK, 46U)) + aNonceWordD);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterJ, 13U)) + aOrbiterB);
            aWandererE = aWandererE + ((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 29U)) + aOrbiterE);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 52U) + aOrbiterG) + RotL64(aOrbiterE, 53U)) + aWandererUpdateSaltC[((aIndex + 10U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 3U)) + aOrbiterF);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 27U) + aOrbiterC) + RotL64(aOrbiterB, 11U)) + aNonceWordP);
            aWandererJ = aWandererJ + (((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterH, 19U)) + aWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 58U) + RotL64(aOrbiterH, 43U)) + aOrbiterE);
            aWandererC = aWandererC + (((RotL64(aScatter, 43U) + aOrbiterH) + RotL64(aOrbiterI, 37U)) + RotL64(aCarry, 3U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterD, 60U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 47U) + aOrbiterI) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 11U)) + aNonceWordA);
            //
            aCarry = aCarry + (RotL64(aWandererB, 54U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + RotL64(aWandererK, 44U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordP);
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

void TwistExpander_Karate_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xC46E25FFDB3085D5ULL + 0x94CDDDEDB2858E5DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x9EDA84BEC65567B7ULL + 0xD16A1BA334DC5658ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xF9F6E582A301F5C1ULL + 0xA665BF51C7847B50ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xC27DB387B7E41D03ULL + 0xBB5776ECB354F9EEULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xC10B710930D2AA2FULL + 0xED2C7F35823B265FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xCAAC16333EFABE21ULL + 0xF929477E464BF20DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xAB6FE6E084CED2CFULL + 0x882D1E8AB7F3E6B8ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xD69CF6F31CABE8C5ULL + 0xBA16AE1DCF41145BULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xD9F1A9C2212C6C83ULL + 0x8D53B2C536541746ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x82E3796FFB51F041ULL + 0xC905D4E34993016AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xB4495D8C933C43D7ULL + 0x991E81A49742FB0BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xC67E72D61ADA7B6DULL + 0xF9065793BE6038D9ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xCAFFF29AC68EE4F9ULL + 0xF83083F9D34D39D7ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xAE8D29D21C98E531ULL + 0xD38992DF0FEA9F66ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xC22B7787211E058FULL + 0xAE3D9F048349BAFFULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x812CD10350A94E17ULL + 0xF7B354AD0FBF1E91ULL);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 1222U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneC[((aIndex + 101U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 2527U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 5013U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 50U)) ^ (RotL64(aIngress, 19U) ^ RotL64(aCarry, 37U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 53U)) + 17019646486641172469U) + aOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 18U)) + 12276141179299971572U) + aOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = (aWandererC + RotL64(aScatter, 43U)) + 3617241694029841555U;
            aOrbiterA = (aWandererK + RotL64(aIngress, 53U)) + 6967963401259371737U;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 35U)) + 6340709284279891017U;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 39U)) + RotL64(aCarry, 21U)) + 456065368903896482U;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 27U)) + RotL64(aCarry, 39U)) + 17686765719908116203U;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 12U)) + 1322045955429785736U) + aNonceWordD;
            aOrbiterB = (aWandererD + RotL64(aScatter, 57U)) + 5163772703302372887U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 13268431135020363252U) + aNonceWordG;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 6538789950366849332U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5352960308459065837U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 10390344544314544893U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 5087084271300584267U;
            aOrbiterF = RotL64((aOrbiterF * 15149302947570776165U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 13423071121590981727U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 18324443012024134729U;
            aOrbiterK = RotL64((aOrbiterK * 15814349432207734533U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 4129091815978464507U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 17024797553831962245U;
            aOrbiterB = RotL64((aOrbiterB * 3137753479364378175U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 6501545108779991661U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 11930037791867597447U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4904739567549702851U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 4667298703308315851U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 6315980380900062127U;
            aOrbiterA = RotL64((aOrbiterA * 12080555704907924637U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 12732382340390769888U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 7792095326183864547U;
            aOrbiterC = RotL64((aOrbiterC * 12645556660611824631U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 17428384983571405782U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 3193205313177048443U;
            aOrbiterD = RotL64((aOrbiterD * 14488006565106259731U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 2813743367131107264U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 2742138679703780981U) ^ aOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 18356569025783532225U), 53U);
            //
            aIngress = RotL64(aOrbiterK, 21U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 52U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 39U));
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 6U) + RotL64(aOrbiterA, 60U)) + aOrbiterK) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterE, 27U)) + aOrbiterK) + aNonceWordJ);
            aWandererC = aWandererC + ((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 19U)) + aOrbiterH);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 43U) + aOrbiterE) + RotL64(aOrbiterC, 51U)) + aWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 34U) + RotL64(aOrbiterC, 4U)) + aOrbiterK) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 39U)) + aOrbiterH) + aNonceWordB) + aWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 39U) + RotL64(aOrbiterF, 43U)) + aOrbiterE);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterG, 23U)) + aOrbiterA);
            aWandererD = aWandererD + ((RotL64(aCross, 27U) + RotL64(aOrbiterD, 11U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 30U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 23U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ aNonceWordG;
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9855U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 10913U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 9888U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6896U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 54U) ^ RotL64(aPrevious, 11U)) + (RotL64(aIngress, 29U) ^ RotL64(aCarry, 41U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererF + RotL64(aCross, 51U)) + RotL64(aCarry, 19U)) + 898812731947995389U;
            aOrbiterH = (aWandererG + RotL64(aScatter, 57U)) + 8677347622525527167U;
            aOrbiterC = ((aWandererD + RotL64(aIngress, 5U)) + RotL64(aCarry, 39U)) + 770321564027567654U;
            aOrbiterJ = (((aWandererE + RotL64(aPrevious, 30U)) + RotL64(aCarry, 57U)) + 11020474858081526395U) + aNonceWordO;
            aOrbiterG = (((aWandererC + RotL64(aScatter, 19U)) + 17289793580414993470U) + aOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordA;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 43U)) + 10111912559295118444U) + aOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aCross, 13U)) + 8083622125544542011U;
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 23U)) + 7149858558922988240U) + aNonceWordF;
            aOrbiterF = (aWandererB + RotL64(aScatter, 34U)) + 5919683821379905699U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 6860902846079238714U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 15083517836867542075U;
            aOrbiterC = RotL64((aOrbiterC * 4686657139237578325U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 14852868368708376381U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 9860233289028878323U;
            aOrbiterG = RotL64((aOrbiterG * 13418143547952204667U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 772406119079116272U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 7971141501337627589U;
            aOrbiterI = RotL64((aOrbiterI * 10168120622976358617U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 8478568022896691911U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 4027604850785607101U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4826627523578901467U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 17199331557841535430U) + aNonceWordP;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 7515957656979776361U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5468950152869656599U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 17138249294921502391U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 16236812863923234668U;
            aOrbiterB = RotL64((aOrbiterB * 2925542836624164807U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 16941524155859123682U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 11240343728857342866U;
            aOrbiterJ = RotL64((aOrbiterJ * 7281012444214294659U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 15163914964139858328U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 6673576554415729652U) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 1558880328574736975U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 5399050402101642989U) + aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 11806006719060024615U) ^ aNonceWordD;
            aOrbiterH = RotL64((aOrbiterH * 15782156615926092159U), 3U);
            //
            aIngress = RotL64(aOrbiterI, 53U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 40U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterC, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aScatter, 56U) + RotL64(aOrbiterJ, 3U)) + aOrbiterH) + aNonceWordH);
            aWandererD = aWandererD + (((RotL64(aCross, 23U) + RotL64(aOrbiterF, 43U)) + aOrbiterA) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 13U) + aOrbiterC) + RotL64(aOrbiterE, 28U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterG, 47U)) + aOrbiterA) + RotL64(aCarry, 35U)) + aWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterI, 39U));
            aWandererK = aWandererK + ((RotL64(aIngress, 28U) + aOrbiterE) + RotL64(aOrbiterG, 57U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterJ, 35U)) + aOrbiterC);
            aWandererJ = aWandererJ + ((RotL64(aCross, 51U) + RotL64(aOrbiterF, 51U)) + aOrbiterI);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterB, 22U)) + aOrbiterC) + aWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (RotL64(aWandererD, 14U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 53U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordG);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13023U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16348U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 12460U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 11698U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCross, 35U)) + (RotL64(aIngress, 57U) ^ RotL64(aCarry, 6U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererE + RotL64(aPrevious, 41U)) + 12131317914288566437U;
            aOrbiterA = (((aWandererA + RotL64(aScatter, 13U)) + 5672805657999385496U) + aOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordN;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 37U)) + RotL64(aCarry, 35U)) + 3581710244233124197U;
            aOrbiterJ = (((aWandererC + RotL64(aCross, 4U)) + RotL64(aCarry, 21U)) + 15251296040538489436U) + aNonceWordK;
            aOrbiterH = (((aWandererJ + RotL64(aScatter, 51U)) + RotL64(aCarry, 57U)) + 11295008604679904153U) + aOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aIngress, 47U)) + 2230897493419504490U) + aNonceWordF;
            aOrbiterB = (aWandererI + RotL64(aCross, 19U)) + 7109600123297458999U;
            aOrbiterI = (aWandererG + RotL64(aPrevious, 56U)) + 13119156643107683803U;
            aOrbiterG = (aWandererD + RotL64(aIngress, 27U)) + 14755160867807355250U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 16829363373287496832U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 16981122946707720883U) ^ aOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5394974422201576627U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 8806000776958603317U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 16810923047720876014U;
            aOrbiterF = RotL64((aOrbiterF * 17872735050219539145U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 8129657889554436328U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 8653100378491974463U) ^ aOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11395283153912468661U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 17048985838727432415U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 10892675550889823573U;
            aOrbiterA = RotL64((aOrbiterA * 976298937314081913U), 19U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterI) + 15960158965421254346U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordG;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 12290011578634850001U) ^ aOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9280475585104357745U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 16265047040311479093U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 10312956912303656248U;
            aOrbiterC = RotL64((aOrbiterC * 3012584393253845131U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 16706890352221352779U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 10630955894218491929U;
            aOrbiterB = RotL64((aOrbiterB * 12675937483456206355U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 4009352551041162434U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 3043810773683888556U;
            aOrbiterI = RotL64((aOrbiterI * 4328135390387997315U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 1398071019814944785U) + aNonceWordP;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 16689766557488135301U;
            aOrbiterG = RotL64((aOrbiterG * 8403881916549404871U), 35U);
            //
            aIngress = RotL64(aOrbiterG, 24U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterF, 27U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + RotL64(aOrbiterJ, 48U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 51U) + RotL64(aOrbiterJ, 23U)) + aOrbiterK) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 4U) + RotL64(aOrbiterH, 58U)) + aOrbiterF) + aWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterI, 27U)) + aNonceWordO);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 39U) + aOrbiterG) + RotL64(aOrbiterB, 5U)) + aNonceWordD);
            aWandererF = aWandererF + ((RotL64(aScatter, 11U) + RotL64(aOrbiterF, 41U)) + aOrbiterJ);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 27U) + aOrbiterI) + RotL64(aOrbiterG, 37U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 46U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 34U) + RotL64(aOrbiterK, 51U)) + aOrbiterG) + aWandererUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterG, 13U)) + aOrbiterC) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 50U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 41U));
            aCarry = aCarry + RotL64(aWandererA, 23U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordC);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 18545U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19008U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19983U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 16605U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 50U) ^ RotL64(aCross, 35U)) ^ (RotL64(aCarry, 19U) + RotL64(aPrevious, 3U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (((aWandererK + RotL64(aPrevious, 26U)) + RotL64(aCarry, 57U)) + 12690502671561165478U) + aOrbiterAssignSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = ((aWandererH + RotL64(aCross, 35U)) + 17519943923428102801U) + aNonceWordO;
            aOrbiterJ = (aWandererB + RotL64(aIngress, 3U)) + 10705515807975331385U;
            aOrbiterK = (aWandererC + RotL64(aScatter, 57U)) + 16586447272278538179U;
            aOrbiterD = (aWandererG + RotL64(aPrevious, 21U)) + 8006560996840971798U;
            aOrbiterH = (((aWandererA + RotL64(aIngress, 53U)) + RotL64(aCarry, 47U)) + 12928600185788857701U) + aNonceWordF;
            aOrbiterB = (aWandererJ + RotL64(aScatter, 13U)) + 14240723153798267172U;
            aOrbiterI = (((aWandererD + RotL64(aCross, 47U)) + RotL64(aCarry, 39U)) + 8636219177994872072U) + aOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = ((aWandererE + RotL64(aScatter, 40U)) + 7586790235186467512U) + aNonceWordB;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 1103807034179512424U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 7547526530239498693U;
            aOrbiterJ = RotL64((aOrbiterJ * 3360295583636013509U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 8380239679344786397U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 5690809173787433519U;
            aOrbiterD = RotL64((aOrbiterD * 5354724308093372953U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 8390902801141804609U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 3507306189192059486U;
            aOrbiterB = RotL64((aOrbiterB * 18336280496510253103U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 6190745292098482871U) + aNonceWordM;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 8065418693975056902U;
            aOrbiterE = RotL64((aOrbiterE * 6414621418430102589U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 12111755051718111803U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 7605877769709909297U;
            aOrbiterK = RotL64((aOrbiterK * 17525248694315944599U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 5969794501112646237U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 5127559299360591476U;
            aOrbiterH = RotL64((aOrbiterH * 4521563633438853069U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 10593847754747739786U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 4401750688524310121U;
            aOrbiterI = RotL64((aOrbiterI * 14265829318976633707U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 6927893132508779499U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 4874009978647014479U;
            aOrbiterF = RotL64((aOrbiterF * 13340466017023540755U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 13146693487138744677U) + aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 3298472134223595298U;
            aOrbiterC = RotL64((aOrbiterC * 2145005258008477281U), 13U);
            //
            aIngress = RotL64(aOrbiterD, 22U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 39U));
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + RotL64(aOrbiterC, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aCross, 57U) + RotL64(aOrbiterC, 19U)) + aOrbiterH);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 52U) + RotL64(aOrbiterB, 43U)) + aOrbiterI) + aWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 5U) + aOrbiterH) + RotL64(aOrbiterD, 35U)) + aNonceWordI);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 37U) + aOrbiterC) + RotL64(aOrbiterJ, 56U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterE, 5U)) + RotL64(aCarry, 37U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterH, 51U)) + aWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 30U) + RotL64(aOrbiterC, 47U)) + aOrbiterE) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 60U)) + aOrbiterF) + aNonceWordJ);
            aWandererE = aWandererE + ((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterH, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 36U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 50U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 24235U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((aIndex + 25186U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25887U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21885U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aIngress, 35U)) + (RotL64(aPrevious, 10U) ^ RotL64(aCross, 51U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 23U)) + 2783898056762489197U) + aOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aIngress, 60U)) + 7177192902873343053U;
            aOrbiterJ = (aWandererI + RotL64(aScatter, 47U)) + 12254703232691980774U;
            aOrbiterC = (aWandererD + RotL64(aCross, 35U)) + 15446547245691219559U;
            aOrbiterG = ((((aWandererJ + RotL64(aPrevious, 53U)) + RotL64(aCarry, 41U)) + 888475203006174856U) + aOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1]) + aNonceWordC;
            aOrbiterD = (((aWandererG + RotL64(aScatter, 19U)) + RotL64(aCarry, 27U)) + 3649183529366307877U) + aNonceWordO;
            aOrbiterB = (aWandererB + RotL64(aIngress, 29U)) + 4642631047518805167U;
            aOrbiterI = (((aWandererK + RotL64(aCross, 42U)) + RotL64(aCarry, 57U)) + 6108329730724782250U) + aNonceWordD;
            aOrbiterA = (aWandererC + RotL64(aIngress, 13U)) + 8334054653023816636U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 5891895375031474350U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 3176720746238477862U;
            aOrbiterJ = RotL64((aOrbiterJ * 1869961473768307911U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 6111038696865301675U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 11914998302228682704U;
            aOrbiterD = RotL64((aOrbiterD * 11738924766359642853U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 17005063057791320948U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 18333780598768130670U;
            aOrbiterI = RotL64((aOrbiterI * 5416759844884107303U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 2056115016443263153U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 10245512728872962677U;
            aOrbiterA = RotL64((aOrbiterA * 707106795383284903U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 4810366069422162351U) + aOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 3051442983125942469U;
            aOrbiterK = RotL64((aOrbiterK * 13558537578054436423U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 9285068547223654308U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 13067251130180968842U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7000687697769766605U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 3203670242792002165U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterD) ^ 1770881716916463461U) ^ aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 13870229847371882171U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 16286823712870537410U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 13067191141829694202U;
            aOrbiterH = RotL64((aOrbiterH * 15629974528467350445U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 3414576315085336932U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 8979691827341555245U;
            aOrbiterG = RotL64((aOrbiterG * 15971594804040295757U), 29U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterA, 24U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aScatter, 39U) + aOrbiterI) + RotL64(aOrbiterA, 28U)) + aWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aCross, 53U) + RotL64(aOrbiterB, 3U)) + aOrbiterI) + RotL64(aCarry, 41U)) + aNonceWordJ);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 14U) + aOrbiterB) + RotL64(aOrbiterH, 53U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 37U)) + aOrbiterJ) + aNonceWordG);
            aWandererI = aWandererI ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterD, 57U)) + aOrbiterC) + aWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 43U)) + aOrbiterH) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 19U) + aOrbiterJ) + RotL64(aOrbiterA, 13U)) + aNonceWordA);
            aWandererC = aWandererC + ((RotL64(aIngress, 24U) + RotL64(aOrbiterB, 47U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 5U) + aOrbiterJ) + RotL64(aOrbiterG, 20U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 44U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 13U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordO;
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28916U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29065U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29707U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 30929U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCarry, 53U)) ^ (RotL64(aPrevious, 36U) + RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererB + RotL64(aIngress, 23U)) + 8367680518550579791U) + aNonceWordF;
            aOrbiterF = (aWandererD + RotL64(aPrevious, 5U)) + 11491674725611181241U;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 60U)) + RotL64(aCarry, 57U)) + 16673861720782164214U;
            aOrbiterE = (((aWandererE + RotL64(aCross, 43U)) + RotL64(aCarry, 19U)) + 9786610124108350855U) + aOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 35U)) + 5745080601557577637U) + aNonceWordN;
            aOrbiterK = (aWandererH + RotL64(aIngress, 39U)) + 1959402215131684684U;
            aOrbiterA = (aWandererJ + RotL64(aScatter, 53U)) + 6121650036079196522U;
            aOrbiterD = ((aWandererG + RotL64(aCross, 19U)) + 12016309761037342392U) + aOrbiterAssignSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = (((aWandererI + RotL64(aPrevious, 10U)) + RotL64(aCarry, 11U)) + 5986936646177049603U) + aNonceWordO;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 1000367700904043468U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 17425288243569101032U;
            aOrbiterI = RotL64((aOrbiterI * 2174614006719048535U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 4856917474950325209U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 16312111093223166419U;
            aOrbiterH = RotL64((aOrbiterH * 11046477664487805241U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 456110002032422270U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 11393724374787795662U;
            aOrbiterA = RotL64((aOrbiterA * 1176984359123668389U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 8378176867715697176U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 8086186452345234815U;
            aOrbiterD = RotL64((aOrbiterD * 8450438271765985235U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 8470349167474173245U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 2528229938740192694U;
            aOrbiterG = RotL64((aOrbiterG * 8717790851266520943U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 13247168811545753141U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 8745293957516815264U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14270617180621072619U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 6165915500564961987U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterA) ^ 12015407798844173213U) ^ aOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterE = RotL64((aOrbiterE * 3913451986559154153U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 545006684939922156U) + aNonceWordD;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 16366753936267185001U;
            aOrbiterK = RotL64((aOrbiterK * 6495185976430013201U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 3097605623436091728U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 15950167830259022926U;
            aOrbiterF = RotL64((aOrbiterF * 4415538963984293323U), 29U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 57U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 27U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 36U));
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 24U) + RotL64(aOrbiterK, 35U)) + aOrbiterA) + aNonceWordL);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterG, 5U)) + aNonceWordB);
            aWandererB = aWandererB + ((((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterG, 43U)) + RotL64(aCarry, 5U)) + aNonceWordI);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 53U) + aOrbiterH) + RotL64(aOrbiterI, 52U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterA, 29U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 58U) + RotL64(aOrbiterI, 23U)) + aOrbiterD);
            aWandererI = aWandererI + (((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 19U)) + aOrbiterF) + aWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 5U) + aOrbiterF) + RotL64(aOrbiterI, 13U)) + aWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterC, 60U)) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 60U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordP);
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

void TwistExpander_Karate_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xBED8260B6CA59DB5ULL + 0xD798EFFA522DEDD8ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xB13CAF90CC07E421ULL + 0x98422D8A70253764ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x8A9EAEAA8430F1C1ULL + 0xBB8CB135E775AAC5ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x806019B3A8737039ULL + 0x80C40CDCBCC98D52ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xB08A8160658CD525ULL + 0xBD19DA1C20204894ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xB7B3A1EC378E116BULL + 0xE9EC6FC1093C1567ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xFF679C3478BC8CE9ULL + 0xF122D3E451E90E60ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x818B2F71B3527767ULL + 0xC6A19583BBEDA232ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xC6A106ADB9A63FE7ULL + 0x87E96328E1C5AB5EULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xA1FC972EFF1C5DB5ULL + 0xC9AFC2F132D9D460ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xA5164CA500BE962BULL + 0x84AB793C9BF90CD6ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xA2E11E510AB54A15ULL + 0xE90AD15E8551D7FDULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xFAE12FE2C72B35B5ULL + 0xDF8116B13A2F5A75ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xCA288555F5BED48FULL + 0x9434DB26A97B08E3ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x98E94E455F00964DULL + 0xEB887B1BFD2DE2CCULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x8E5D9529915C7953ULL + 0xF1C447697FEF3358ULL);
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 2022U)) & S_BLOCK1], 37U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 4675U)) & W_KEY1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 1699U)) & W_KEY1], 44U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 783U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 30U) ^ RotL64(aCross, 57U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCarry, 43U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterH = (aWandererH + RotL64(aPrevious, 3U)) + 12029393034357490020U;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 43U)) + 4526754731580694987U) + aNonceWordO;
            aOrbiterB = (((aWandererB + RotL64(aIngress, 35U)) + RotL64(aCarry, 41U)) + 17060419646421271853U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = (((aWandererJ + RotL64(aCross, 60U)) + RotL64(aCarry, 29U)) + 4128488893837059683U) + aPhaseAOrbiterAssignSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = (aWandererA + RotL64(aPrevious, 53U)) + 12706894827547160110U;
            aOrbiterD = (aWandererC + RotL64(aCross, 29U)) + 12506324593645825056U;
            aOrbiterC = ((aWandererE + RotL64(aScatter, 21U)) + RotL64(aCarry, 57U)) + 12581344490649250025U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 14357032418199130132U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 15341977701796331249U;
            aOrbiterB = RotL64((aOrbiterB * 6332369248718076031U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 7086602307544733241U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 12398300065276832486U;
            aOrbiterA = RotL64((aOrbiterA * 18157408831225635333U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 2499745046076601988U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 7249361592814001829U;
            aOrbiterD = RotL64((aOrbiterD * 14597139848072319685U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 3254456186337366437U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 3472973415969046680U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14583566953969168353U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 7905718972111691591U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 15941413652144021522U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3473779492962783565U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 10583964125960308762U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 13659925272340853715U) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 16708294803316630743U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 9487054537489454887U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 13287757570441887517U;
            aOrbiterF = RotL64((aOrbiterF * 17351439045329892107U), 35U);
            //
            aIngress = RotL64(aOrbiterJ, 35U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 51U));
            aIngress = aIngress + RotL64(aOrbiterA, 26U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterD, 13U)) + aOrbiterJ) + aPhaseAWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 27U) + RotL64(aOrbiterJ, 37U)) + aOrbiterB) + RotL64(aCarry, 3U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterC, 60U)) + aOrbiterF);
            aWandererA = aWandererA + ((RotL64(aPrevious, 43U) + aOrbiterC) + RotL64(aOrbiterH, 21U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 6U) + RotL64(aOrbiterH, 27U)) + aOrbiterF) + aPhaseAWandererUpdateSaltD[((aIndex + 26U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterD, 3U)) + aOrbiterB) + RotL64(aCarry, 35U)) + aNonceWordC);
            aWandererH = aWandererH ^ (((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterA, 53U)) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 10U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererE, 39U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordM;
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10709U)) & S_BLOCK1], 11U) ^ RotL64(mSource[((aIndex + 7643U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 6191U)) & W_KEY1], 47U) ^ RotL64(aKeyRowReadB[((aIndex + 8452U)) & W_KEY1], 12U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCarry, 23U)) ^ (RotL64(aCross, 58U) ^ RotL64(aIngress, 11U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterH = (aWandererD + RotL64(aCross, 46U)) + 15316464782468770057U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 11U)) + 6642872057476351588U) + aNonceWordK;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 5U)) + 660732654689529192U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aIngress, 29U)) + RotL64(aCarry, 19U)) + 7235418086884000655U;
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 23U)) + RotL64(aCarry, 3U)) + 14784518476694580493U;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 37U)) + RotL64(aCarry, 41U)) + 12222433977933449375U;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 57U)) + 8573001207708329927U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 16035256260815013172U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 15767726974121910203U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 719060452537759331U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 17712217935322939971U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 13488963456923357159U;
            aOrbiterH = RotL64((aOrbiterH * 16785285630840310405U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 10222949131965611079U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 1495561412321657209U;
            aOrbiterB = RotL64((aOrbiterB * 9706305581868526265U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 16156530750584361434U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 7773792489045606309U;
            aOrbiterF = RotL64((aOrbiterF * 10730624207715601393U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 11544578291333360613U) + aNonceWordG;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 3665587867634242865U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4840528190844842595U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 15248434984650998090U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 15487979645426567581U;
            aOrbiterA = RotL64((aOrbiterA * 10868107809356766183U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 6972347795052712690U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 16074994810010431338U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1262655238856775853U), 21U);
            //
            aIngress = RotL64(aOrbiterE, 35U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 4U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterF, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 41U) + aOrbiterI) + RotL64(aOrbiterH, 46U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 27U) + aOrbiterJ) + RotL64(aOrbiterE, 13U)) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 53U) + aOrbiterI) + RotL64(aOrbiterB, 37U)) + aNonceWordH);
            aWandererH = aWandererH + ((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 23U)) + aOrbiterF);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterF, 29U)) + aPhaseAWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererG = aWandererG + (((((RotL64(aCross, 60U) + aOrbiterA) + RotL64(aOrbiterJ, 53U)) + RotL64(aCarry, 5U)) + aNonceWordM) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterB, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (RotL64(aWandererD, 24U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 43U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordP);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12938U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15772U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 16192U)) & W_KEY1], 5U) ^ RotL64(aKeyRowReadB[((aIndex + 14523U)) & W_KEY1], 13U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 21U) + RotL64(aCarry, 35U)) ^ (RotL64(aPrevious, 51U) + RotL64(aCross, 4U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterJ = (aWandererH + RotL64(aIngress, 57U)) + 17454559218352016650U;
            aOrbiterK = ((aWandererG + RotL64(aCross, 35U)) + 8005709669325164803U) + aPhaseAOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 51U)) + 13393741948412816357U) + aNonceWordP;
            aOrbiterG = (((aWandererK + RotL64(aScatter, 29U)) + RotL64(aCarry, 27U)) + 3665865624348875553U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 3U)) + RotL64(aCarry, 41U)) + 8334142570031883436U;
            aOrbiterB = (((aWandererE + RotL64(aCross, 11U)) + RotL64(aCarry, 53U)) + 17226066128706139657U) + aNonceWordH;
            aOrbiterH = (aWandererF + RotL64(aIngress, 22U)) + 3319093033121522613U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 6657535603401588798U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 5469746182326331147U;
            aOrbiterA = RotL64((aOrbiterA * 11315450342347794329U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 17846791786050221418U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 15939541003714896288U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1400351482213119809U), 29U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterG) + 12076763190461077406U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordC;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 3594038213596405284U) ^ aNonceWordL;
            aOrbiterJ = RotL64((aOrbiterJ * 10244002692575821495U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 8301291631324464622U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 8460406137668390582U;
            aOrbiterG = RotL64((aOrbiterG * 9117147929757711595U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 7612394867020871200U) + aNonceWordI;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 8525076134853103975U;
            aOrbiterI = RotL64((aOrbiterI * 5790440201072204659U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 11929899088215090379U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 7119509166360685726U;
            aOrbiterB = RotL64((aOrbiterB * 1662341427992528823U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 5081078459225240607U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 17149991983909906705U;
            aOrbiterH = RotL64((aOrbiterH * 950223374568067343U), 35U);
            //
            aIngress = RotL64(aOrbiterG, 30U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 35U) + aOrbiterH) + RotL64(aOrbiterI, 21U)) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterB, 35U)) + aNonceWordF);
            aWandererE = aWandererE + (((RotL64(aPrevious, 12U) + RotL64(aOrbiterK, 5U)) + aOrbiterH) + RotL64(aCarry, 11U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterG, 51U)) + aNonceWordA);
            aWandererF = aWandererF + (((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 42U)) + aOrbiterH) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterI, 11U)) + aOrbiterG) + aPhaseAWandererUpdateSaltC[((aIndex + 6U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterJ, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 30U));
            aCarry = aCarry + RotL64(aWandererJ, 23U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordK);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 21341U)) & S_BLOCK1], 20U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17253U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20243U)) & S_BLOCK1], 13U) ^ RotL64(mSource[((aIndex + 18897U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 20U)) + (RotL64(aCross, 35U) ^ RotL64(aIngress, 51U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterH = (aWandererB + RotL64(aScatter, 13U)) + 9220392006207660113U;
            aOrbiterJ = (((aWandererA + RotL64(aIngress, 56U)) + RotL64(aCarry, 23U)) + 11305018553489132882U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aCross, 29U)) + RotL64(aCarry, 5U)) + 5860373868073513684U;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 19U)) + 12319586170883987589U) + aNonceWordB;
            aOrbiterD = (((aWandererH + RotL64(aCross, 47U)) + 14072333614354649021U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 37U)) + 9332158529453194608U) + aNonceWordM;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 39U)) + 3860569321145958686U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 8119005668901240093U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 13918259792880333239U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5441062406822088853U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 6938856216758228704U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 3960905839118710604U;
            aOrbiterC = RotL64((aOrbiterC * 16203746868670689793U), 13U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterH) + 6043879193734253929U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1]) + aNonceWordE;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 15691425268831319195U;
            aOrbiterJ = RotL64((aOrbiterJ * 7189195135654636271U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 14912209933584715274U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = (((aOrbiterD ^ aOrbiterE) ^ 16180183395910618923U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterD = RotL64((aOrbiterD * 3942858974766467849U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 4966642362507707776U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 6962226782462822861U;
            aOrbiterH = RotL64((aOrbiterH * 3647802407741095419U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 12409120845092026295U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 2302946450253872465U) ^ aNonceWordG;
            aOrbiterK = RotL64((aOrbiterK * 7099576330777297911U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 16118304388937163838U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 15968419034359049422U;
            aOrbiterG = RotL64((aOrbiterG * 11736207775827080165U), 29U);
            //
            aIngress = RotL64(aOrbiterH, 43U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + RotL64(aOrbiterK, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 18U) + aOrbiterJ) + RotL64(aOrbiterK, 5U));
            aWandererA = aWandererA + ((RotL64(aCross, 27U) + RotL64(aOrbiterJ, 37U)) + aOrbiterG);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterE, 54U)) + aNonceWordH);
            aWandererB = aWandererB + (((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterD, 13U)) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterH, 29U)) + aPhaseAWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aCross, 41U) + RotL64(aOrbiterH, 21U)) + aOrbiterC) + RotL64(aCarry, 21U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterK, 47U)) + aOrbiterD) + aNonceWordF);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 34U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordH;
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22555U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((aIndex + 23395U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24880U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((aIndex + 22693U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 27U) ^ RotL64(aPrevious, 43U)) ^ (RotL64(aCarry, 11U) + RotL64(aIngress, 58U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterK = ((aWandererF + RotL64(aScatter, 54U)) + RotL64(aCarry, 39U)) + 13915875634607599122U;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 41U)) + 1695770381382411673U) + aNonceWordD;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 3U)) + RotL64(aCarry, 13U)) + 3709105579778295511U;
            aOrbiterH = (((aWandererE + RotL64(aCross, 47U)) + RotL64(aCarry, 53U)) + 7673376335333251804U) + aNonceWordP;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 21U)) + 8814147709738503518U) + aPhaseAOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 13U)) + 13451412605350381172U) + aNonceWordB;
            aOrbiterA = ((aWandererI + RotL64(aCross, 27U)) + 6447870234069609538U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 13419487997946496825U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 5478309847615220345U;
            aOrbiterF = RotL64((aOrbiterF * 12953043149543448765U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 3635184969215610049U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 12527903812035294828U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12540800512035534967U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 1684685110885338814U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 12860354576326835090U) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 12743745087733307255U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 9081823570147481835U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 14369321778210049109U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17865953349448767035U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 11518132079084873250U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 11893535026126957389U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15751374986135615095U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 7084079180579206226U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 2999676609847603277U;
            aOrbiterB = RotL64((aOrbiterB * 14602698397511266403U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 17683445810614029153U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 11576460512964896969U;
            aOrbiterA = RotL64((aOrbiterA * 5243651036457051155U), 53U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 35U);
            aIngress = aIngress + (RotL64(aOrbiterA, 41U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 53U));
            aIngress = aIngress + RotL64(aOrbiterI, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterI, 13U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 37U) + aOrbiterB) + RotL64(aOrbiterI, 29U)) + aNonceWordG);
            aWandererD = aWandererD + (((RotL64(aScatter, 57U) + aOrbiterF) + RotL64(aOrbiterH, 35U)) + aNonceWordJ);
            aWandererC = aWandererC ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterD, 3U)) + aOrbiterB) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 48U) + aOrbiterD) + RotL64(aOrbiterH, 43U)) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterH, 21U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 21U) + RotL64(aOrbiterI, 56U)) + aOrbiterK) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 12U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ aNonceWordP;
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30709U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29646U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31843U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneB[((aIndex + 30465U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 29U) ^ RotL64(aIngress, 12U)) ^ (RotL64(aPrevious, 41U) + RotL64(aCross, 53U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 47U)) + 4179952823252098240U) + aNonceWordP;
            aOrbiterG = ((((aWandererG + RotL64(aIngress, 29U)) + RotL64(aCarry, 19U)) + 3745613452332101749U) + aPhaseAOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1]) + aNonceWordE;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 5U)) + RotL64(aCarry, 43U)) + 2955689793395307176U;
            aOrbiterF = (((aWandererI + RotL64(aCross, 57U)) + 5639060180251322019U) + aPhaseAOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1]) + aNonceWordD;
            aOrbiterK = (aWandererB + RotL64(aIngress, 23U)) + 7901969163853586463U;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 12U)) + RotL64(aCarry, 57U)) + 2242166787816318119U;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 35U)) + 5239936443960750064U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 13939136954732185558U) + aNonceWordI;
            aOrbiterI = (((aOrbiterI ^ aOrbiterD) ^ 17058884136712717463U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 7222348891215482977U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 18148618660054585941U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 7022023484530327814U;
            aOrbiterK = RotL64((aOrbiterK * 650100011311048589U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 7722084537340095637U) + aNonceWordK;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 11764151879690934182U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12264384877711365655U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 16412785901758144708U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 9666718667728274824U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10865799822751771795U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 4307127540152109364U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 2457646804702647606U;
            aOrbiterD = RotL64((aOrbiterD * 6340030928007058595U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 3179394870088602208U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 504977947273774249U;
            aOrbiterF = RotL64((aOrbiterF * 16190282058883481551U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 16182729401018310837U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 7110817020445860609U;
            aOrbiterG = RotL64((aOrbiterG * 13371352088428584087U), 51U);
            //
            aIngress = RotL64(aOrbiterI, 19U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 48U));
            aIngress = aIngress + (RotL64(aOrbiterG, 11U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterC, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterI, 19U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 5U) + aOrbiterF) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 53U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 35U) + aOrbiterG) + RotL64(aOrbiterC, 47U));
            aWandererB = aWandererB + ((((RotL64(aCross, 41U) + aOrbiterF) + RotL64(aOrbiterI, 13U)) + RotL64(aCarry, 19U)) + aPhaseAWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 27U)) + aOrbiterD) + aNonceWordF);
            aWandererI = aWandererI + ((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterC, 36U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterI, 57U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 18U));
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + RotL64(aWandererG, 51U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ aNonceWordI;
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

void TwistExpander_Karate_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xDFABEDEA6183C695ULL + 0xCFDA22ED688F8513ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xD64FDCA12E17AABDULL + 0x9105D3E5754BFFCDULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xEC005CE8519F1B91ULL + 0xD23F6755D05D74A0ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x9AF6C5C34A5C099DULL + 0x9AD4F9F3C4586F59ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xC9BBE5142EDD9763ULL + 0xD8B0B0FA56405751ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xDFE2972BCE73B961ULL + 0xE6F1F62C1D5A9729ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x986510A729201D55ULL + 0xF365D8593766CDD6ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xB7FC21DC34BE1F2BULL + 0xD5B02CF679185964ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xCCE47F842B674FC5ULL + 0xB7F4E25F77623442ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xC1CC2C82A5643E09ULL + 0x95B45158A8FC7CF4ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xC6169EB1C9A2E89DULL + 0xB20F12B2B1111687ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xBECAC92F7854463BULL + 0xE5E05C4985D6AC92ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xDC5A419CCC434BD5ULL + 0xB67FA20F87738783ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xE8F3B071818DA913ULL + 0xE0080D16F05A24AAULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xA17064F9B3FDD5B1ULL + 0xE435931DDCA5D76BULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x9E5D3365CA491E9BULL + 0xA9FE55C8FCBE39F8ULL);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 3457U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 94U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4972U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 2245U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 24U)) + (RotL64(aCross, 41U) ^ RotL64(aIngress, 57U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterA = (aWandererF + RotL64(aScatter, 3U)) + 2177539223979303669U;
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 37U)) + 3962004686551521471U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = (((aWandererC + RotL64(aCross, 23U)) + RotL64(aCarry, 51U)) + 8457602312617147662U) + aNonceWordA;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 51U)) + RotL64(aCarry, 11U)) + 18011802451816510632U;
            aOrbiterC = ((((aWandererI + RotL64(aScatter, 12U)) + RotL64(aCarry, 35U)) + 9046101759168876832U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordE;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 11135620637431969597U) + aNonceWordK;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 15913029940697999701U;
            aOrbiterB = RotL64((aOrbiterB * 646524659942693491U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 16304193109948135982U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 13208892298820080981U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15093751072618884859U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 4182377898949419225U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 13970137023071326151U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9075061559681739865U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 8402396284835248583U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 8859190834060657829U;
            aOrbiterJ = RotL64((aOrbiterJ * 13552418608113716117U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 9760005337757990392U) + aNonceWordF;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 14108277760135744897U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4474681104256093885U), 35U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterC, 13U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((((RotL64(aPrevious, 13U) + aOrbiterI) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 47U)) + aNonceWordC) + aPhaseBWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterC, 5U)) + aOrbiterA) + aNonceWordD);
            aWandererC = aWandererC + (((RotL64(aScatter, 34U) + aOrbiterA) + RotL64(aOrbiterB, 13U)) + aNonceWordJ);
            aWandererH = aWandererH ^ (((RotL64(aCross, 23U) + aOrbiterC) + RotL64(aOrbiterB, 23U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 5U) + RotL64(aOrbiterA, 44U)) + aOrbiterI) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordE;
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10800U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 5814U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10852U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9344U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 52U) ^ RotL64(aCross, 19U)) + (RotL64(aCarry, 3U) ^ RotL64(aIngress, 39U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterC = ((aWandererI + RotL64(aScatter, 26U)) + RotL64(aCarry, 51U)) + 16124889768301047791U;
            aOrbiterF = (aWandererG + RotL64(aCross, 13U)) + 11912338587186717280U;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 51U)) + 8594012868813114354U) + aNonceWordA;
            aOrbiterG = ((((aWandererK + RotL64(aPrevious, 5U)) + RotL64(aCarry, 3U)) + 18281043566156682815U) + aPhaseBOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1]) + aNonceWordD;
            aOrbiterA = ((((aWandererE + RotL64(aCross, 35U)) + RotL64(aCarry, 23U)) + 16853106130200942302U) + aPhaseBOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1]) + aNonceWordE;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 2611212958619673086U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 18039472325066855180U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10213999643376367785U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 14495785571345122046U) + aNonceWordP;
            aOrbiterA = (((aOrbiterA ^ aOrbiterF) ^ 4556063793412832418U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 13166927543135467627U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 14896419970271244358U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 880028529183500036U;
            aOrbiterC = RotL64((aOrbiterC * 14228281807461251361U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 2379557167489415783U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 11854373946064529806U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 150755294320438887U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 1487252775956449964U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 12777924204511625545U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1366019527386994789U), 57U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterC, 57U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 28U));
            aIngress = aIngress + RotL64(aOrbiterA, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aIngress, 48U) + RotL64(aOrbiterC, 27U)) + aOrbiterA) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 29U) + aOrbiterK) + RotL64(aOrbiterA, 43U)) + aNonceWordN) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererI = aWandererI + (((((RotL64(aCross, 5U) + RotL64(aOrbiterG, 35U)) + aOrbiterF) + RotL64(aCarry, 11U)) + aNonceWordM) + aPhaseBWandererUpdateSaltF[((aIndex + 8U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 21U) + aOrbiterF) + RotL64(aOrbiterC, 19U));
            aWandererE = aWandererE + ((RotL64(aCross, 39U) + RotL64(aOrbiterG, 60U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 44U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordM;
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12982U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 16054U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13806U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneC[((aIndex + 13534U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 52U) + RotL64(aCross, 19U)) + (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 35U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterE = (aWandererC + RotL64(aScatter, 5U)) + 6381335981879993247U;
            aOrbiterI = (((aWandererJ + RotL64(aCross, 30U)) + RotL64(aCarry, 23U)) + 15595429101600023172U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = (aWandererE + RotL64(aIngress, 21U)) + 5449234297249826461U;
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 57U)) + RotL64(aCarry, 51U)) + 11213734849329731168U;
            aOrbiterG = ((((aWandererI + RotL64(aScatter, 43U)) + RotL64(aCarry, 5U)) + 16438473952464514248U) + aPhaseBOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1]) + aNonceWordC;
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 7357872882115186976U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 394402075160738643U;
            aOrbiterF = RotL64((aOrbiterF * 11961225338735982661U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 11112941985410283532U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 14955125011182736212U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10711684773326395603U), 39U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterJ) + 14770727009821304070U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1]) + aNonceWordA;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 11286366598129204910U;
            aOrbiterE = RotL64((aOrbiterE * 15884310771003021989U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 7358400908565425780U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 15635109923749114761U;
            aOrbiterJ = RotL64((aOrbiterJ * 12415152149408700329U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 13826842523738623579U) + aNonceWordI;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 1072811298828325231U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9662800288646215083U), 3U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterJ, 47U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterJ, 47U)) + aOrbiterG) + RotL64(aCarry, 3U)) + aNonceWordE);
            aWandererI = aWandererI ^ (((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterJ, 35U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 12U) + RotL64(aOrbiterF, 27U)) + aOrbiterJ) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 53U) + aOrbiterJ) + RotL64(aOrbiterI, 57U));
            aWandererG = aWandererG + (((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 4U)) + aOrbiterF) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + RotL64(aWandererE, 3U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordL);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 20276U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21165U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19095U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((aIndex + 16423U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aPrevious, 41U)) + (RotL64(aCarry, 27U) + RotL64(aIngress, 6U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterA = (((aWandererB + RotL64(aScatter, 51U)) + RotL64(aCarry, 21U)) + 13854738573712660276U) + aNonceWordO;
            aOrbiterH = ((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 5U)) + 16835460633412286294U;
            aOrbiterD = (((aWandererK + RotL64(aPrevious, 29U)) + RotL64(aCarry, 53U)) + 6785859293758091931U) + aPhaseBOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = ((aWandererA + RotL64(aIngress, 42U)) + 126317283127992659U) + aPhaseBOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aScatter, 13U)) + 7568963536291415413U) + aNonceWordE;
            //
            aOrbiterA = (((aOrbiterA + aOrbiterH) + 12294016745653004819U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordM;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 18269588932920281147U;
            aOrbiterD = RotL64((aOrbiterD * 9031152619272892317U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 5872406424994751026U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 7764434758831474129U;
            aOrbiterA = RotL64((aOrbiterA * 3772146788188420071U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 4804168969415573371U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 959601763507651280U;
            aOrbiterG = RotL64((aOrbiterG * 4647396592804833217U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 9257644462479293048U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 14332699366894494579U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8829304078930625541U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 10487012596470786004U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 612729229562321440U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11380387280507726003U), 57U);
            //
            aIngress = RotL64(aOrbiterF, 3U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 47U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterG, 5U)) + aOrbiterD);
            aWandererE = aWandererE + ((RotL64(aCross, 27U) + RotL64(aOrbiterA, 28U)) + aOrbiterF);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterG, 19U)) + aOrbiterF) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aCross, 58U) + aOrbiterG) + RotL64(aOrbiterA, 43U)) + RotL64(aCarry, 3U)) + aNonceWordI);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + RotL64(aWandererA, 56U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordH;
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 24980U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23311U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23572U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25837U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCross, 51U)) ^ (RotL64(aCarry, 4U) + RotL64(aIngress, 35U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterC = (((aWandererJ + RotL64(aIngress, 23U)) + RotL64(aCarry, 51U)) + 12206125048349568300U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = ((aWandererG + RotL64(aScatter, 35U)) + 5843520589343188818U) + aNonceWordO;
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 43U)) + RotL64(aCarry, 19U)) + 12195046124287121687U;
            aOrbiterK = ((aWandererH + RotL64(aCross, 13U)) + RotL64(aCarry, 37U)) + 16769779119214020640U;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 56U)) + 5257603646260695833U) + aPhaseBOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 8523523946234886745U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 7316024684200084096U;
            aOrbiterF = RotL64((aOrbiterF * 11620083021691341337U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 11996978575084115207U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 15491711479085513628U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15136690392026011819U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 6036648530996821484U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 926323222234121863U;
            aOrbiterC = RotL64((aOrbiterC * 6639661141258803779U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 2700323841295743492U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 5852273765810284935U) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 16665696735016345215U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 11697397483133538067U) + aNonceWordM;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 17777142964957007194U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6338967222543284999U), 29U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 53U);
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aIngress, 12U) + aOrbiterH) + RotL64(aOrbiterF, 11U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterC, 19U)) + aOrbiterG);
            aWandererG = aWandererG + (((((RotL64(aCross, 47U) + RotL64(aOrbiterH, 3U)) + aOrbiterC) + RotL64(aCarry, 13U)) + aNonceWordD) + aPhaseBWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterF, 34U)) + aOrbiterK) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 39U) + aOrbiterH) + RotL64(aOrbiterG, 57U)) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 30U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 41U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 11U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordK);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 32602U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32517U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31817U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((aIndex + 28956U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aIngress, 11U)) + (RotL64(aCross, 54U) ^ RotL64(aPrevious, 41U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterG = ((aWandererK + RotL64(aScatter, 27U)) + RotL64(aCarry, 11U)) + 15036852811491820366U;
            aOrbiterC = (((aWandererE + RotL64(aCross, 37U)) + RotL64(aCarry, 29U)) + 305637140752898475U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aPrevious, 5U)) + 11948631574496129610U;
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 18U)) + 5321623592482991426U) + aNonceWordJ;
            aOrbiterH = ((((aWandererF + RotL64(aPrevious, 47U)) + RotL64(aCarry, 57U)) + 4075270159062690728U) + aPhaseBOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1]) + aNonceWordA;
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 15111580500356908928U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 7244150695504160363U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2445733898697939969U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 5131563519577488862U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = (((aOrbiterC ^ aOrbiterE) ^ 5881954992088651371U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterC = RotL64((aOrbiterC * 2424421828597294607U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 12780935808751507998U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 12599159643925470226U;
            aOrbiterG = RotL64((aOrbiterG * 17690046932587062701U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 9466589929741834066U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 6093158735705189789U;
            aOrbiterE = RotL64((aOrbiterE * 7453778295800853653U), 43U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterI) + 17461243886150519249U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1]) + aNonceWordK;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 15456408913739900718U;
            aOrbiterH = RotL64((aOrbiterH * 16093292401746174671U), 27U);
            //
            aIngress = RotL64(aOrbiterC, 3U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aScatter, 48U) + RotL64(aOrbiterG, 58U)) + aOrbiterC) + RotL64(aCarry, 21U)) + aNonceWordM);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 19U) + aOrbiterC) + RotL64(aOrbiterE, 3U)) + aPhaseBWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 3U)) + aNonceWordE);
            aWandererK = aWandererK ^ (((RotL64(aCross, 5U) + aOrbiterH) + RotL64(aOrbiterG, 39U)) + aNonceWordC);
            aWandererG = aWandererG + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterC, 13U)) + aOrbiterH) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererE, 27U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordL);
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

void TwistExpander_Karate_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x9B8C8FCFCB65574BULL + 0x85B04CDCF795E335ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x9451EB35C153A113ULL + 0xDB6623A18CAA444FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x978996A5B97A0867ULL + 0xF72DDE8253703D44ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xE3CA99D28563D0C1ULL + 0x921F62AB4B1B0253ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xECCF4F2151F6DCBFULL + 0xEF87C4ED73AEE1AAULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xA7008B849C3D91F5ULL + 0x9F1809CBBF51C5D3ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xA7CB6C431720E0E5ULL + 0xFB4FB71C4B0C9647ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x9CD8BD59A7FFD363ULL + 0xDEA4AC800F3A3DE8ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xFB5673C3B1C387F1ULL + 0xD8CA5335B2EDFCE5ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xED2F529228196549ULL + 0xB0C2BD6244A6FAB7ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x9C3F3C52AD72D07DULL + 0xAD951E650174D561ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x929E4E456E2878CDULL + 0xFD06B2351703C047ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xB79607588FBCCCCBULL + 0xF722C12AEC27831FULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x890F0DB82EACD8B3ULL + 0xC9A77B633DC3DA60ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xBBD07B9E96C2D00FULL + 0xBA87CA5573A5E13EULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xF8EFC465D6FB5733ULL + 0xD1BF180DA120AE68ULL);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 8013U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneC[((aIndex + 3016U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 3681U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 5661U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 18U)) + (RotL64(aCross, 37U) ^ RotL64(aPrevious, 53U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 47U)) + 7790166497945719700U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = ((aWandererI + RotL64(aScatter, 35U)) + 7136208896846119188U) + aNonceWordN;
            aOrbiterH = ((aWandererD + RotL64(aCross, 12U)) + RotL64(aCarry, 47U)) + 12123156943355100886U;
            aOrbiterF = (aWandererG + RotL64(aIngress, 41U)) + 5095546037880875199U;
            aOrbiterG = ((((aWandererK + RotL64(aPrevious, 19U)) + RotL64(aCarry, 35U)) + 17642705393916765992U) + aPhaseCOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1]) + aNonceWordG;
            aOrbiterB = (aWandererC + RotL64(aIngress, 53U)) + 9918479837334416990U;
            aOrbiterI = ((aWandererF + RotL64(aScatter, 58U)) + RotL64(aCarry, 3U)) + 4890009823843176466U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 27U)) + 17652590786213674124U;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 3U)) + 870002527644696135U) + aNonceWordK;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 12545429703552643682U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 5310272867406182581U;
            aOrbiterH = RotL64((aOrbiterH * 10420003334833925011U), 47U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterG) + 3264719049050179440U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1]) + aNonceWordE;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 1967241238180278937U;
            aOrbiterB = RotL64((aOrbiterB * 13004319774269457957U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 773883832927040736U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 12766817190261232485U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7448864556802318431U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 260069382395598265U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 15462103891287350123U;
            aOrbiterC = RotL64((aOrbiterC * 5029268763635635753U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 4072032867513289827U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 17153061419083897076U;
            aOrbiterD = RotL64((aOrbiterD * 11934532169271718913U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 6207264270332656966U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 18048064697837314947U) ^ aNonceWordF;
            aOrbiterF = RotL64((aOrbiterF * 13632594619404208489U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 14484617445340272026U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 16160443600497652026U;
            aOrbiterI = RotL64((aOrbiterI * 1988599349457831597U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 5873314228291583482U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 16418290052752166515U;
            aOrbiterE = RotL64((aOrbiterE * 18270363452003213317U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 9158414409987627714U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 8205937960146492168U;
            aOrbiterG = RotL64((aOrbiterG * 14008398661393344261U), 35U);
            //
            aIngress = RotL64(aOrbiterC, 29U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 26U));
            aIngress = aIngress + (RotL64(aOrbiterH, 37U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterI, 41U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 6U)) + aOrbiterI) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 20U) + RotL64(aOrbiterD, 29U)) + aOrbiterB);
            aWandererC = aWandererC + (((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 47U)) + aOrbiterD) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterG, 23U)) + aOrbiterE);
            aWandererK = aWandererK + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterG, 39U)) + aOrbiterH) + RotL64(aCarry, 13U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 56U) + aOrbiterD) + RotL64(aOrbiterG, 54U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterC, 11U)) + aNonceWordL);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 51U) + aOrbiterI) + RotL64(aOrbiterC, 35U));
            aWandererI = aWandererI + ((RotL64(aCross, 39U) + RotL64(aOrbiterH, 19U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 26U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererI, 39U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 14366U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneD[((aIndex + 14497U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 15947U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8356U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 3U)) + (RotL64(aIngress, 47U) ^ RotL64(aCross, 20U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterE = ((aWandererA + RotL64(aIngress, 27U)) + 18180797995100240808U) + aNonceWordF;
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 41U)) + RotL64(aCarry, 3U)) + 6585906608223552885U;
            aOrbiterJ = (((aWandererK + RotL64(aCross, 5U)) + RotL64(aCarry, 43U)) + 14088708930575939855U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = (((aWandererI + RotL64(aScatter, 21U)) + RotL64(aCarry, 35U)) + 468974153311516044U) + aNonceWordK;
            aOrbiterB = (aWandererG + RotL64(aCross, 60U)) + 12481951025619894110U;
            aOrbiterC = (aWandererF + RotL64(aIngress, 37U)) + 17227987923860711763U;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 11U)) + 4373962756657477139U) + aNonceWordL;
            aOrbiterI = (aWandererH + RotL64(aScatter, 53U)) + 2077576476565420951U;
            aOrbiterA = ((aWandererD + RotL64(aCross, 46U)) + 17435011300234663764U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 4118039398293246896U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 13724716599855216683U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17556333902751079677U), 13U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterJ) + 12391461204689596339U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordO;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 9900605191533799627U;
            aOrbiterB = RotL64((aOrbiterB * 13553565332531046301U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 972946858824366125U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 17247681919694541215U;
            aOrbiterD = RotL64((aOrbiterD * 2974639094630445643U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 15442851427306771601U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 7303586227288294037U;
            aOrbiterI = RotL64((aOrbiterI * 15406402525021428799U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 12650358753454105119U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 1483710933373510492U;
            aOrbiterA = RotL64((aOrbiterA * 6531763256577221891U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 18065810162229740788U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 11311677121338794007U;
            aOrbiterE = RotL64((aOrbiterE * 15116367961682119467U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 2355285311890287611U) + aNonceWordE;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 1287783821903407734U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8054011680932255985U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 9282654686791135654U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 15488608017745542551U;
            aOrbiterC = RotL64((aOrbiterC * 7858866274035085123U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 13296835576073421802U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 7127700236018338741U;
            aOrbiterH = RotL64((aOrbiterH * 11246173563106014149U), 57U);
            //
            aIngress = RotL64(aOrbiterH, 53U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterJ, 44U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 52U) + aOrbiterD) + RotL64(aOrbiterF, 28U)) + RotL64(aCarry, 47U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterC, 35U)) + aOrbiterD);
            aWandererF = aWandererF + ((RotL64(aIngress, 5U) + RotL64(aOrbiterI, 57U)) + aOrbiterH);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterC, 41U)) + aOrbiterB) + aPhaseCWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 34U) + RotL64(aOrbiterF, 53U)) + aOrbiterI) + aPhaseCWandererUpdateSaltE[((aIndex + 10U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterA, 10U)) + aOrbiterJ);
            aWandererH = aWandererH + ((((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterC, 21U)) + RotL64(aCarry, 23U)) + aNonceWordJ);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 29U) + aOrbiterE) + RotL64(aOrbiterI, 5U)) + aNonceWordP);
            aWandererK = aWandererK + ((RotL64(aIngress, 39U) + aOrbiterE) + RotL64(aOrbiterD, 47U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 50U));
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + RotL64(aWandererF, 5U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordJ);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 22559U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneA[((aIndex + 24099U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 23945U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneC[((aIndex + 21044U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 4U) ^ RotL64(aIngress, 21U)) + (RotL64(aPrevious, 37U) ^ RotL64(aCarry, 51U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterB = ((aWandererK + RotL64(aIngress, 41U)) + 8793908991006073956U) + aPhaseCOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aScatter, 54U)) + RotL64(aCarry, 27U)) + 2932916283348441943U;
            aOrbiterE = ((aWandererB + RotL64(aCross, 3U)) + RotL64(aCarry, 3U)) + 11069042087940968262U;
            aOrbiterI = (aWandererG + RotL64(aPrevious, 11U)) + 14369628676782894441U;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 47U)) + RotL64(aCarry, 47U)) + 8602903272780978282U;
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 58U)) + 3827036107178568820U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = (aWandererF + RotL64(aScatter, 35U)) + 8905245209036772489U;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 19U)) + 13331387530760017893U) + aNonceWordK;
            aOrbiterK = (aWandererC + RotL64(aPrevious, 27U)) + 9880107580289737823U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 10199619040626900278U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 2466307560891374281U;
            aOrbiterE = RotL64((aOrbiterE * 6295342978834217571U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 13973403407981259448U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 2851460278409385243U;
            aOrbiterB = RotL64((aOrbiterB * 11226902976321781743U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 10365453393815690776U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 2382382358987358791U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 481563628980705781U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 5058198848163792422U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 10500434740387593487U;
            aOrbiterD = RotL64((aOrbiterD * 5946747708776079787U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 11289798395177667084U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 14327152153231286666U;
            aOrbiterJ = RotL64((aOrbiterJ * 18155778059595245561U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 8065137263811956313U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 3865153574847924816U;
            aOrbiterF = RotL64((aOrbiterF * 9495741102667755161U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 18102279969722473375U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 6306428427188742325U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17826782872351406167U), 27U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterB) + 16953348204663693724U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1]) + aNonceWordM;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 11950791817032898613U;
            aOrbiterC = RotL64((aOrbiterC * 1498946055469611133U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 11980823193543752994U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 17845490308799454871U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16385153013485463791U), 51U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 19U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 40U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterC, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterK, 47U));
            aWandererA = aWandererA + (((RotL64(aIngress, 10U) + RotL64(aOrbiterG, 36U)) + aOrbiterF) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 57U)) + aOrbiterI) + aNonceWordJ);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 57U) + RotL64(aOrbiterG, 27U)) + aOrbiterJ) + RotL64(aCarry, 11U)) + aPhaseCWandererUpdateSaltB[((aIndex + 28U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 27U) + aOrbiterB) + RotL64(aOrbiterD, 43U));
            aWandererI = aWandererI + (((RotL64(aScatter, 53U) + RotL64(aOrbiterG, 4U)) + aOrbiterD) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 46U) + RotL64(aOrbiterI, 11U)) + aOrbiterK);
            aWandererK = aWandererK + ((RotL64(aCross, 23U) + RotL64(aOrbiterK, 19U)) + aOrbiterE);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterE, 51U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + (RotL64(aWandererI, 14U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererA, 19U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 31707U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneB[((aIndex + 27287U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32453U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneD[((aIndex + 31689U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 51U) ^ RotL64(aCross, 39U)) ^ (RotL64(aIngress, 10U) + RotL64(aCarry, 23U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterA = ((aWandererB + RotL64(aIngress, 35U)) + RotL64(aCarry, 13U)) + 3238389262925516513U;
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 51U)) + RotL64(aCarry, 27U)) + 12381787182611386995U;
            aOrbiterI = (((aWandererA + RotL64(aScatter, 47U)) + 7883885539305181549U) + aPhaseCOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1]) + aNonceWordG;
            aOrbiterE = (((aWandererG + RotL64(aCross, 56U)) + RotL64(aCarry, 51U)) + 1185413044597727092U) + aNonceWordA;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 39U)) + 15219353497204773135U;
            aOrbiterH = (aWandererI + RotL64(aPrevious, 27U)) + 7533774715626734082U;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 13U)) + 2599930450937763464U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = (aWandererD + RotL64(aCross, 5U)) + 16074720663961214284U;
            aOrbiterK = (aWandererC + RotL64(aPrevious, 60U)) + 15483613196360051221U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 9396557867081376268U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 9668459976852660245U) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 11748505665890567063U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 9037269914643207212U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 16936742640861088240U;
            aOrbiterJ = RotL64((aOrbiterJ * 1040172193161012227U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 16481274825758546398U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 481851372837611166U;
            aOrbiterG = RotL64((aOrbiterG * 2225030139210599207U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 13608921517203544108U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 16930740723286214636U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2605108503821980865U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 902242902582149908U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 1510861213079342977U) ^ aNonceWordH;
            aOrbiterE = RotL64((aOrbiterE * 3309753895727400707U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 7116243600304980310U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 6631412278359709602U;
            aOrbiterH = RotL64((aOrbiterH * 11452627691392637463U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 9246698682265275165U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 8594373032014031450U;
            aOrbiterD = RotL64((aOrbiterD * 2550138341089957033U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 15912837963877821048U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 11404583513022627609U;
            aOrbiterK = RotL64((aOrbiterK * 17715204726760125357U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 17295214920690244319U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 18315664494984189344U) ^ aNonceWordO;
            aOrbiterC = RotL64((aOrbiterC * 17398893532076312945U), 23U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 34U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 21U));
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 39U));
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 47U)) + aOrbiterG) + RotL64(aCarry, 51U)) + aPhaseCWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterD, 30U)) + aNonceWordD);
            aWandererD = aWandererD + (((RotL64(aIngress, 4U) + aOrbiterC) + RotL64(aOrbiterG, 57U)) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterE, 5U)) + aOrbiterJ);
            aWandererI = aWandererI + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterE, 53U)) + aOrbiterI);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 51U) + aOrbiterG) + RotL64(aOrbiterK, 26U)) + aNonceWordF);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 23U) + aOrbiterJ) + RotL64(aOrbiterK, 41U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 30U) + RotL64(aOrbiterI, 19U)) + aOrbiterJ);
            aWandererC = aWandererC + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterD, 11U)) + aOrbiterH) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 26U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererC, 39U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ aNonceWordL;
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

void TwistExpander_Karate_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xE1DAC28E5D8E85BDULL + 0x91FC882AB0B64940ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xDF90A46BB2F8DF5FULL + 0xE2B5F0799ACE6E3CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xD0C8C056801B7D89ULL + 0xD6CDD7DE1234D86BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xA596152C28DF8ACFULL + 0x8522B465D98AF5A8ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x9B02B4CFFF19B2BFULL + 0xC8C9113B911423D4ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xDB28480F7F3CE827ULL + 0xA4D07B101DDBC5C3ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xD21FDA606E9B4929ULL + 0xE8C3DC7345122D21ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xBD67B578B88A5D1DULL + 0xD267ABD9ABA60C62ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x984E76715999E7DDULL + 0xE37213AF293183A1ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xEC6C186AE4855009ULL + 0xB5CA0FAC0CCEC767ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xE36BB42776B99E4BULL + 0x90987FAE990DC3BDULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xCD42D50146973C27ULL + 0x9E35CDEE01D246CDULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xFFC128C6BCC49EA5ULL + 0x9290AD12AC86D320ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x914B82739D651A1DULL + 0x895965C48723A63BULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x80D14CD74BFB2295ULL + 0xEEC071FAE3972D0FULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x9A288FB40AE68D19ULL + 0xB21F62F13E619616ULL);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 183U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2891U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1330U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 5454U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 10U) ^ RotL64(aCarry, 27U)) + (RotL64(aIngress, 57U) ^ RotL64(aCross, 41U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterB = (aWandererI + RotL64(aScatter, 47U)) + 16160838483846078448U;
            aOrbiterH = ((aWandererH + RotL64(aIngress, 30U)) + 15404960896190227946U) + aPhaseDOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = (aWandererB + RotL64(aPrevious, 27U)) + 16904160594024977199U;
            aOrbiterE = ((aWandererA + RotL64(aCross, 51U)) + RotL64(aCarry, 19U)) + 17790460246821031802U;
            aOrbiterG = (aWandererK + RotL64(aScatter, 23U)) + 16395168254086971959U;
            aOrbiterD = (aWandererC + RotL64(aIngress, 21U)) + 7484373204039901786U;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 19U)) + 18026814691322913510U) + aPhaseDOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 37U)) + 15244817793136966450U) + aNonceWordJ;
            aOrbiterK = (((aWandererD + RotL64(aScatter, 41U)) + RotL64(aCarry, 11U)) + 5795491730356335666U) + aNonceWordD;
            aOrbiterF = (((aWandererF + RotL64(aIngress, 35U)) + RotL64(aCarry, 37U)) + 3163873518027801504U) + aNonceWordA;
            aOrbiterA = (aWandererE + RotL64(aPrevious, 60U)) + 2690791759507349172U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 17898067251167087906U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 8028010015006604239U;
            aOrbiterI = RotL64((aOrbiterI * 5601629670521300241U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 7304739457289910555U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 6476837815096530043U) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 16380545138701113267U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 14242499233467960602U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 17305645693017634630U;
            aOrbiterB = RotL64((aOrbiterB * 14442976693206929569U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 9772864059444171908U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 7897200728282156408U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 816306719390807411U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 4890999319172950996U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 8165132649356094963U;
            aOrbiterJ = RotL64((aOrbiterJ * 17297706071263690189U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 9342923520083533265U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 7213639583505088067U;
            aOrbiterK = RotL64((aOrbiterK * 1349251979649428909U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 4079475132684197272U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 3350998022472827283U;
            aOrbiterA = RotL64((aOrbiterA * 948841791460066265U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 2479140576609216238U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 7703147534931674972U;
            aOrbiterH = RotL64((aOrbiterH * 11419116495223970801U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 9050277787914448469U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 13295888852307317371U;
            aOrbiterG = RotL64((aOrbiterG * 3027097172772140975U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 15380254190549884741U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 17653690414528791774U;
            aOrbiterC = RotL64((aOrbiterC * 15923958179714368315U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 6825072759468337036U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 16160838483846078448U;
            aOrbiterF = RotL64((aOrbiterF * 11690325563580492415U), 21U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterH, 36U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 41U));
            aIngress = aIngress + RotL64(aOrbiterK, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterJ, 5U));
            aWandererE = aWandererE + ((RotL64(aIngress, 39U) + RotL64(aOrbiterK, 35U)) + aOrbiterB);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterA, 48U));
            aWandererF = aWandererF + ((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterC, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 54U) + RotL64(aOrbiterD, 23U)) + aOrbiterA);
            aWandererD = aWandererD + (((((RotL64(aScatter, 41U) + aOrbiterG) + RotL64(aOrbiterH, 19U)) + RotL64(aCarry, 13U)) + aNonceWordH) + aPhaseDWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((((RotL64(aCross, 23U) + aOrbiterI) + RotL64(aOrbiterA, 41U)) + aNonceWordL) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterK, 27U)) + aOrbiterE);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 6U) + aOrbiterH) + RotL64(aOrbiterD, 54U));
            aWandererI = aWandererI + (((RotL64(aCross, 3U) + RotL64(aOrbiterF, 29U)) + aOrbiterD) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 43U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 48U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + RotL64(aWandererF, 23U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 10720U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneD[((aIndex + 9702U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9090U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6562U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCarry, 41U)) + (RotL64(aCross, 5U) ^ RotL64(aIngress, 28U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterH = (aWandererK + RotL64(aPrevious, 29U)) + 439898681482066326U;
            aOrbiterC = ((aWandererE + RotL64(aScatter, 23U)) + 17362083676671776094U) + aPhaseDOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aCross, 57U)) + 6418499837265155024U;
            aOrbiterI = (aWandererB + RotL64(aIngress, 44U)) + 17262244253027454972U;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 51U)) + RotL64(aCarry, 5U)) + 2382066162993139503U;
            aOrbiterJ = (((aWandererF + RotL64(aCross, 19U)) + 14345808395587174135U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordM;
            aOrbiterA = (aWandererI + RotL64(aPrevious, 39U)) + 7534743166385552851U;
            aOrbiterF = (aWandererH + RotL64(aIngress, 35U)) + 16994453324688523966U;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 3U)) + RotL64(aCarry, 13U)) + 7079553728544045092U;
            aOrbiterG = (aWandererA + RotL64(aCross, 47U)) + 3562822704508440641U;
            aOrbiterE = (((aWandererG + RotL64(aIngress, 54U)) + RotL64(aCarry, 37U)) + 13990892681975857821U) + aNonceWordP;
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 1796728922368577238U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 6605161260520067178U;
            aOrbiterB = RotL64((aOrbiterB * 8147537646591674091U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 13994083795942328918U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 6144523182899107711U;
            aOrbiterC = RotL64((aOrbiterC * 4153879991344611283U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 12247462325297436642U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 1065809332002012789U;
            aOrbiterD = RotL64((aOrbiterD * 5496601177032953251U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 10147919864511540753U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 17138553441127273354U;
            aOrbiterA = RotL64((aOrbiterA * 5773875596275267871U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 2653924016109573974U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 6254416952351699582U;
            aOrbiterK = RotL64((aOrbiterK * 12756861659704947257U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 813046408080197079U) + aNonceWordF;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 9624466135414123483U;
            aOrbiterH = RotL64((aOrbiterH * 6960320253124395015U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 972586705850825744U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 155283774901960223U;
            aOrbiterI = RotL64((aOrbiterI * 9928051687724257041U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 18200100644751360406U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 1168426822045686004U;
            aOrbiterJ = RotL64((aOrbiterJ * 5867027156069481313U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 2271564377169233643U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 1896317305868283986U;
            aOrbiterF = RotL64((aOrbiterF * 8080751157990019287U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 10209708407397294552U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 947585551223387294U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15339472308062247067U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 12313594490465462211U) + aNonceWordO;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 439898681482066326U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12336632799055203705U), 39U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 54U);
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + RotL64(aOrbiterI, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aIngress, 51U) + RotL64(aOrbiterB, 27U)) + aOrbiterJ) + RotL64(aCarry, 53U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 29U) + aOrbiterK) + RotL64(aOrbiterC, 14U)) + aNonceWordL);
            aWandererD = aWandererD + (((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 47U)) + aOrbiterG) + RotL64(aCarry, 47U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 58U) + RotL64(aOrbiterI, 21U)) + aOrbiterF);
            aWandererG = aWandererG + ((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterI, 51U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterD, 40U)) + aPhaseDWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterA, 37U)) + aOrbiterF);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 23U) + aOrbiterK) + RotL64(aOrbiterB, 11U));
            aWandererK = aWandererK + (((RotL64(aScatter, 43U) + RotL64(aOrbiterF, 29U)) + aOrbiterB) + aNonceWordC);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 13U) + aOrbiterD) + RotL64(aOrbiterE, 3U)) + aNonceWordI);
            aWandererC = aWandererC + ((RotL64(aCross, 56U) + aOrbiterK) + RotL64(aOrbiterH, 43U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 60U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + RotL64(aWandererI, 53U);
            aCarry = aCarry + RotL64(aIngress, 12U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 14187U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((aIndex + 15822U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11124U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11176U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 38U)) + (RotL64(aCarry, 53U) ^ RotL64(aIngress, 19U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterK = (aWandererE + RotL64(aScatter, 41U)) + 6973892330986118220U;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 53U)) + 9886813896272094864U;
            aOrbiterE = (((aWandererD + RotL64(aCross, 11U)) + RotL64(aCarry, 29U)) + 10996306582517553173U) + aPhaseDOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = ((aWandererG + RotL64(aIngress, 38U)) + RotL64(aCarry, 53U)) + 8490648283899856223U;
            aOrbiterI = (aWandererB + RotL64(aCross, 19U)) + 105141713530704655U;
            aOrbiterH = ((aWandererK + RotL64(aIngress, 35U)) + 3114337422810562588U) + aNonceWordB;
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 3U)) + 980857684690886131U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = (((aWandererF + RotL64(aScatter, 51U)) + RotL64(aCarry, 19U)) + 6562042345807072665U) + aNonceWordH;
            aOrbiterF = (aWandererJ + RotL64(aIngress, 46U)) + 15665371138706353619U;
            aOrbiterA = (aWandererH + RotL64(aScatter, 21U)) + 18113013571374375028U;
            aOrbiterC = (aWandererI + RotL64(aCross, 27U)) + 17405346422601997299U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 5130876096426182506U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 1813821672299154629U;
            aOrbiterE = RotL64((aOrbiterE * 15478100342425611875U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 15793814882743306728U) + aNonceWordM;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 13925299440495476399U) ^ aNonceWordA;
            aOrbiterH = RotL64((aOrbiterH * 12049601510660117401U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9924458846049579438U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 7810034662781768090U;
            aOrbiterD = RotL64((aOrbiterD * 10310594595026622513U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 12812586478656872854U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 5709576448057435237U;
            aOrbiterI = RotL64((aOrbiterI * 9101555233909853025U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 7839807649914541516U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 4717944526755429647U;
            aOrbiterJ = RotL64((aOrbiterJ * 8515229146471335721U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 3933911971504256022U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 4814079680865379831U;
            aOrbiterA = RotL64((aOrbiterA * 15100740696230557391U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 18352577312212175569U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 9670612998448920742U;
            aOrbiterK = RotL64((aOrbiterK * 5743579439303300553U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 72737302703035726U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 10032869372369626210U;
            aOrbiterG = RotL64((aOrbiterG * 7449905669249993731U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 2669999453643982386U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 2016129534922291383U;
            aOrbiterB = RotL64((aOrbiterB * 11730911201750754301U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 5108689262300895422U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 3753457479225942895U;
            aOrbiterF = RotL64((aOrbiterF * 11503304711866175497U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 859776381005289485U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 6973892330986118220U;
            aOrbiterC = RotL64((aOrbiterC * 12337041087475258221U), 19U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 52U);
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterK, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 24U) + RotL64(aOrbiterH, 57U)) + aOrbiterG);
            aWandererG = aWandererG + (((RotL64(aCross, 19U) + RotL64(aOrbiterC, 13U)) + aOrbiterI) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 11U) + aOrbiterB) + RotL64(aOrbiterA, 47U)) + aNonceWordO);
            aWandererI = aWandererI + ((RotL64(aScatter, 41U) + aOrbiterK) + RotL64(aOrbiterG, 43U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterC, 10U)) + aOrbiterF);
            aWandererB = aWandererB + (((RotL64(aPrevious, 27U) + aOrbiterJ) + RotL64(aOrbiterA, 37U)) + RotL64(aCarry, 27U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 14U) + aOrbiterB) + RotL64(aOrbiterJ, 21U)) + aNonceWordE);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 35U) + RotL64(aOrbiterE, 5U)) + aOrbiterA) + RotL64(aCarry, 19U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterC, 27U));
            aWandererK = aWandererK + ((RotL64(aCross, 43U) + aOrbiterA) + RotL64(aOrbiterK, 41U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterD, 34U)) + aOrbiterG) + aNonceWordC);
            //
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 44U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordM);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 17723U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneB[((aIndex + 21261U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 18997U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((aIndex + 18650U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 51U) + RotL64(aCarry, 22U)) ^ (RotL64(aIngress, 35U) ^ RotL64(aCross, 3U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterI = (aWandererI + RotL64(aPrevious, 29U)) + 14499676118633326000U;
            aOrbiterE = (aWandererJ + RotL64(aIngress, 3U)) + 17191273593018552288U;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 34U)) + 4085176294948097737U) + aNonceWordO;
            aOrbiterA = (((aWandererA + RotL64(aCross, 43U)) + RotL64(aCarry, 51U)) + 11112671474158908186U) + aPhaseDOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = (aWandererB + RotL64(aPrevious, 53U)) + 8745787969012266485U;
            aOrbiterG = (aWandererC + RotL64(aIngress, 47U)) + 18074049663777707948U;
            aOrbiterF = (aWandererE + RotL64(aCross, 19U)) + 2543758649719164688U;
            aOrbiterK = (((aWandererG + RotL64(aScatter, 39U)) + 4659584749412700523U) + aPhaseDOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1]) + aNonceWordP;
            aOrbiterH = ((aWandererK + RotL64(aIngress, 23U)) + RotL64(aCarry, 35U)) + 974639159259871273U;
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 51U)) + 9211220687971081987U;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 12U)) + RotL64(aCarry, 41U)) + 8567024626862182714U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 5803002132294840900U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 11968489432878148467U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4501441062617123165U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 9470807228394903442U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 1692347973120388469U;
            aOrbiterC = RotL64((aOrbiterC * 17433393164156231575U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 16510815732690193145U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 755159406833096510U;
            aOrbiterG = RotL64((aOrbiterG * 14091736464659561165U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 1518824876475937620U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 701225390867330446U;
            aOrbiterF = RotL64((aOrbiterF * 12264618860580199927U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 8425976693733003889U) + aNonceWordB;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 7182176375442410367U;
            aOrbiterK = RotL64((aOrbiterK * 8860605703761731859U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 4546566785167467924U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 2593340999038753749U;
            aOrbiterH = RotL64((aOrbiterH * 10152461487764567563U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 9756331608356622299U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 5511625814747641978U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4806076157539829529U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 8694400787420160733U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 12648969491371382682U;
            aOrbiterD = RotL64((aOrbiterD * 5346585704222643759U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 15261238546696118531U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 14236129054778329471U;
            aOrbiterI = RotL64((aOrbiterI * 11789581469516267749U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 16251500056378064213U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 790320176607605195U;
            aOrbiterE = RotL64((aOrbiterE * 15706130623435648555U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 17114773669444878655U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 14499676118633326000U;
            aOrbiterA = RotL64((aOrbiterA * 8095707555083587081U), 53U);
            //
            aIngress = RotL64(aOrbiterG, 3U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 60U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + RotL64(aOrbiterC, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterA, 46U)) + aOrbiterJ) + aNonceWordF) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 40U) + RotL64(aOrbiterI, 51U)) + aOrbiterD);
            aWandererG = aWandererG + ((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterH, 13U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterA, 39U)) + aOrbiterF);
            aWandererD = aWandererD + (((RotL64(aScatter, 27U) + aOrbiterE) + RotL64(aOrbiterJ, 53U)) + aNonceWordL);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 30U) + RotL64(aOrbiterK, 43U)) + aOrbiterB);
            aWandererF = aWandererF + ((RotL64(aCross, 21U) + RotL64(aOrbiterF, 10U)) + aOrbiterE);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterI, 3U)) + aOrbiterK) + aPhaseDWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 19U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 57U) + aOrbiterK) + RotL64(aOrbiterC, 5U));
            aWandererK = aWandererK + (((RotL64(aScatter, 23U) + RotL64(aOrbiterF, 27U)) + aOrbiterD) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 24U));
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererJ, 37U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordA);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 22822U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneA[((aIndex + 25007U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 23915U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24898U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 10U) ^ RotL64(aCarry, 27U)) + (RotL64(aCross, 43U) + RotL64(aPrevious, 57U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 58U)) + RotL64(aCarry, 53U)) + 1708250618750199233U;
            aOrbiterC = (((aWandererI + RotL64(aScatter, 21U)) + RotL64(aCarry, 23U)) + 12009147777553691142U) + aNonceWordC;
            aOrbiterH = (aWandererK + RotL64(aCross, 39U)) + 8393982703399156592U;
            aOrbiterA = (((aWandererC + RotL64(aPrevious, 23U)) + RotL64(aCarry, 35U)) + 3247327098356831221U) + aNonceWordH;
            aOrbiterJ = (aWandererA + RotL64(aCross, 11U)) + 3403590155376353737U;
            aOrbiterF = (aWandererF + RotL64(aIngress, 29U)) + 18197244558104735044U;
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 18U)) + 3096253642040701606U) + aNonceWordA;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 43U)) + 8012692688785412179U) + aPhaseDOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = (aWandererD + RotL64(aIngress, 47U)) + 17531946907545680745U;
            aOrbiterE = (aWandererE + RotL64(aPrevious, 27U)) + 17687695944270225817U;
            aOrbiterK = ((aWandererH + RotL64(aCross, 5U)) + 16147773866007628769U) + aPhaseDOrbiterAssignSaltD[((aIndex + 10U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 18244641303026196497U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 8839160526348897457U;
            aOrbiterH = RotL64((aOrbiterH * 14268021129087663397U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 10599266240854068246U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 2056723540756216155U;
            aOrbiterF = RotL64((aOrbiterF * 13311591601230386375U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 4629354220460621284U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 9505955649473204942U;
            aOrbiterB = RotL64((aOrbiterB * 17775391885312236187U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 17078153810088721310U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 9470436761716263000U;
            aOrbiterE = RotL64((aOrbiterE * 5431855497250357229U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 3305863413630104742U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 14377172434239576161U;
            aOrbiterG = RotL64((aOrbiterG * 6880176890091033423U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 415687827894226513U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 16975319836893760993U;
            aOrbiterA = RotL64((aOrbiterA * 6597144958013976445U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 12707054129431596074U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 8974182792497231239U;
            aOrbiterI = RotL64((aOrbiterI * 7874658957269462717U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 10826131924322955095U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 4168545139712703154U;
            aOrbiterD = RotL64((aOrbiterD * 10305904857550051705U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 4539070253658625193U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterF) ^ 3737870219498561326U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterK = RotL64((aOrbiterK * 13130847633918921393U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 11563084648810555040U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 7410695535361901473U;
            aOrbiterC = RotL64((aOrbiterC * 7540855656023807389U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 6687453696858775037U) + aNonceWordL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 1708250618750199233U;
            aOrbiterJ = RotL64((aOrbiterJ * 13104250803527718135U), 41U);
            //
            aIngress = RotL64(aOrbiterE, 29U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + (RotL64(aOrbiterH, 40U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 23U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + RotL64(aOrbiterC, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((((RotL64(aScatter, 27U) + RotL64(aOrbiterC, 21U)) + aOrbiterK) + RotL64(aCarry, 47U)) + aNonceWordJ) + aPhaseDWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 48U) + RotL64(aOrbiterG, 47U)) + aOrbiterF) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 39U) + aOrbiterC) + RotL64(aOrbiterD, 56U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterK, 13U)) + aOrbiterA);
            aWandererD = aWandererD + (((RotL64(aPrevious, 21U) + aOrbiterA) + RotL64(aOrbiterI, 29U)) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 35U)) + aOrbiterE);
            aWandererH = aWandererH + ((RotL64(aIngress, 50U) + RotL64(aOrbiterB, 51U)) + aOrbiterD);
            aWandererB = aWandererB ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterB, 4U)) + aOrbiterA);
            aWandererF = aWandererF + ((RotL64(aIngress, 35U) + RotL64(aOrbiterG, 37U)) + aOrbiterC);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterD, 27U)) + aOrbiterJ);
            aWandererI = aWandererI + ((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterK, 43U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 18U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 6U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 32688U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29365U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29998U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneB[((aIndex + 30139U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 27U) ^ RotL64(aPrevious, 12U)) + (RotL64(aIngress, 39U) ^ RotL64(aCarry, 51U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterE = (aWandererG + RotL64(aIngress, 46U)) + 4970414922752555648U;
            aOrbiterH = (aWandererA + RotL64(aCross, 51U)) + 9462756592787669327U;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 53U)) + 3948790686662213095U) + aPhaseDOrbiterAssignSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aScatter, 23U)) + 14542857212241578311U;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 19U)) + 3387479009827029547U;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 43U)) + RotL64(aCarry, 41U)) + 1411421370057797877U;
            aOrbiterC = (((aWandererB + RotL64(aScatter, 27U)) + RotL64(aCarry, 53U)) + 16894451466895681236U) + aNonceWordC;
            aOrbiterF = (((aWandererF + RotL64(aCross, 60U)) + RotL64(aCarry, 47U)) + 12727136462290223542U) + aPhaseDOrbiterAssignSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 39U)) + 4625389198191960525U;
            aOrbiterJ = (aWandererE + RotL64(aCross, 3U)) + 3471881403786164913U;
            aOrbiterB = (aWandererH + RotL64(aIngress, 5U)) + 6433115856048534831U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 9825592965466157982U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 1553125767261293088U) ^ aNonceWordK;
            aOrbiterK = RotL64((aOrbiterK * 411535191177308781U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 9951616357109647617U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 11231080382787286889U;
            aOrbiterD = RotL64((aOrbiterD * 14024961994986659187U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 13419663264017317947U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 4835055642466215566U;
            aOrbiterA = RotL64((aOrbiterA * 17898065852351759171U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 14558747666410946768U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 13120938960926874504U;
            aOrbiterC = RotL64((aOrbiterC * 5681766019285559739U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 11910501376797343986U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 15074100100781785300U;
            aOrbiterF = RotL64((aOrbiterF * 228976960937473851U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 12415377930578091821U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 14882039078390681802U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13855446647753150713U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 8094338361713756895U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 5478280604704108822U;
            aOrbiterJ = RotL64((aOrbiterJ * 18062931724700600993U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 6977017654546871841U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 4131602217285988962U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11865422227883712419U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 9619228479582032318U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 13506679497441415586U) ^ aNonceWordM;
            aOrbiterE = RotL64((aOrbiterE * 5789932662418992799U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 10180259475831448124U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 4721628773773094283U;
            aOrbiterH = RotL64((aOrbiterH * 10834196399754443771U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 7898137727558813688U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 4970414922752555648U;
            aOrbiterG = RotL64((aOrbiterG * 6651835668618579479U), 29U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 47U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 30U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + RotL64(aOrbiterE, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 30U) + RotL64(aOrbiterD, 27U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterK, 23U)) + aOrbiterC) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 51U) + aOrbiterI) + RotL64(aOrbiterA, 3U));
            aWandererE = aWandererE + (((RotL64(aScatter, 27U) + aOrbiterG) + RotL64(aOrbiterC, 39U)) + RotL64(aCarry, 13U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterJ, 6U)) + aNonceWordL);
            aWandererF = aWandererF + ((((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterH, 13U)) + aNonceWordH) + aPhaseDWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 5U) + aOrbiterG) + RotL64(aOrbiterF, 11U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 47U) + aOrbiterF) + RotL64(aOrbiterK, 47U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterF, 18U)) + aOrbiterE) + aNonceWordD);
            aWandererH = aWandererH + ((RotL64(aScatter, 41U) + aOrbiterB) + RotL64(aOrbiterJ, 29U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 14U) + RotL64(aOrbiterD, 41U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 36U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 52U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordJ);
            aCarry = TwistMix64::DiffuseB(aCarry);
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

void TwistExpander_Karate_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xF51695901D837199ULL + 0xD73652D93D8B1F40ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xDD343549669A5FE1ULL + 0x92736ED9FD0DE430ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xD1E1F55C6E1B8631ULL + 0xFBC2B990449B99DCULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xDCFF9A696F77702BULL + 0xD09DF5A60C31ABF0ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xEED56378C2F8B31BULL + 0xD958D8CBF206CF57ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xF8FDC2760B4E43ABULL + 0xC3445273B89D869CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xA48CAD86C7978DC3ULL + 0xB86CC118865B2FDBULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xE75BD7E4F9EF79D3ULL + 0xFE6AA1CC39F1351FULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xB56FEAF9FC8626E3ULL + 0xC33F4D5DFCAB1DEEULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xF64344DC521B0EDBULL + 0xB6988F4C277AA6F0ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xBD269C9CC04661BFULL + 0x9A4674E122593531ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x956868101226EF0FULL + 0xB58E368A8AC69715ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xAA937F34C6FDFD93ULL + 0xA98175FB26405DF0ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x9AF7F73E4038494BULL + 0xED6741960C6B9591ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xE6E5DDE5F11E4DB5ULL + 0x850FA3CEA53978D4ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xF4FBF6DF44634B13ULL + 0x96EF2C8378E77475ULL);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 1549U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneC[((aIndex + 3612U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 2000U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 1312U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 12U) + RotL64(aIngress, 27U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCross, 41U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterF = (aWandererI + RotL64(aScatter, 11U)) + 4179952823252098240U;
            aOrbiterI = (aWandererB + RotL64(aIngress, 47U)) + 3745613452332101749U;
            aOrbiterC = (((aWandererD + RotL64(aCross, 19U)) + RotL64(aCarry, 47U)) + 2955689793395307176U) + aNonceWordD;
            aOrbiterD = (aWandererF + RotL64(aPrevious, 29U)) + 5639060180251322019U;
            aOrbiterE = (aWandererC + RotL64(aIngress, 58U)) + 7901969163853586463U;
            aOrbiterB = (aWandererK + RotL64(aPrevious, 53U)) + 2242166787816318119U;
            aOrbiterK = (((aWandererH + RotL64(aScatter, 41U)) + 5239936443960750064U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordL;
            aOrbiterH = ((aWandererJ + RotL64(aCross, 37U)) + 13939136954732185558U) + aPhaseEOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 4U)) + 17058884136712717463U;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 51U)) + RotL64(aCarry, 35U)) + 18148618660054585941U;
            aOrbiterG = (((aWandererE + RotL64(aIngress, 43U)) + RotL64(aCarry, 29U)) + 7022023484530327814U) + aNonceWordO;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 7722084537340095637U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 11764151879690934182U;
            aOrbiterC = RotL64((aOrbiterC * 12264384877711365655U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 16412785901758144708U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 9666718667728274824U;
            aOrbiterB = RotL64((aOrbiterB * 10865799822751771795U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 4307127540152109364U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 2457646804702647606U;
            aOrbiterF = RotL64((aOrbiterF * 6340030928007058595U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 3179394870088602208U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 504977947273774249U) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 16190282058883481551U), 3U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterC) + 16182729401018310837U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1]) + aNonceWordB;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 7110817020445860609U;
            aOrbiterK = RotL64((aOrbiterK * 13371352088428584087U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 12960656706837391973U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 7103806893724395904U;
            aOrbiterJ = RotL64((aOrbiterJ * 14365984439655979791U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 1248300178080633527U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 7195473175424961337U;
            aOrbiterG = RotL64((aOrbiterG * 4633558992739305045U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 13007951568242991449U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 10296811247653636372U;
            aOrbiterI = RotL64((aOrbiterI * 16469682651380549395U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 13922797949001028335U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 16773545425463040155U;
            aOrbiterE = RotL64((aOrbiterE * 10639282630227832397U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 2888887140296117803U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 10279517418046269817U;
            aOrbiterH = RotL64((aOrbiterH * 8600355360339461535U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 17303373436784809093U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 4179952823252098240U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3675754609699406437U), 13U);
            //
            aIngress = RotL64(aOrbiterE, 48U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 54U));
            aIngress = aIngress + RotL64(aOrbiterJ, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aIngress, 51U) + aOrbiterF) + RotL64(aOrbiterI, 50U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterD, 3U)) + aOrbiterC);
            aWandererK = aWandererK + ((RotL64(aPrevious, 19U) + aOrbiterE) + RotL64(aOrbiterG, 27U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 57U) + aOrbiterB) + RotL64(aOrbiterF, 35U));
            aWandererD = aWandererD + (((RotL64(aIngress, 53U) + RotL64(aOrbiterK, 19U)) + aOrbiterC) + aPhaseEWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 46U) + RotL64(aOrbiterC, 5U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 29U) + RotL64(aOrbiterI, 41U)) + aOrbiterA) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 43U) + aOrbiterH) + RotL64(aOrbiterG, 11U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 47U)) + aOrbiterH) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterI, 29U)) + aOrbiterB);
            aWandererC = aWandererC + (((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterG, 56U)) + aNonceWordH);
            //
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 28U));
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 30U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordD);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 10058U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8531U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 5562U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 10916U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 21U)) + (RotL64(aCarry, 34U) + RotL64(aIngress, 53U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterJ = (aWandererH + RotL64(aIngress, 5U)) + 12206125048349568300U;
            aOrbiterC = ((aWandererE + RotL64(aScatter, 43U)) + 5843520589343188818U) + aNonceWordI;
            aOrbiterB = ((aWandererJ + RotL64(aCross, 41U)) + 12195046124287121687U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = (((aWandererG + RotL64(aPrevious, 37U)) + 16769779119214020640U) + aPhaseEOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1]) + aNonceWordG;
            aOrbiterH = (aWandererF + RotL64(aCross, 11U)) + 5257603646260695833U;
            aOrbiterG = ((aWandererB + RotL64(aScatter, 20U)) + RotL64(aCarry, 53U)) + 8523523946234886745U;
            aOrbiterK = (aWandererI + RotL64(aIngress, 35U)) + 7316024684200084096U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 53U)) + RotL64(aCarry, 21U)) + 11996978575084115207U;
            aOrbiterD = ((aWandererC + RotL64(aCross, 23U)) + RotL64(aCarry, 35U)) + 15491711479085513628U;
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 46U)) + 6036648530996821484U) + aNonceWordC;
            aOrbiterA = (aWandererA + RotL64(aIngress, 39U)) + 926323222234121863U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 2700323841295743492U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 5852273765810284935U;
            aOrbiterB = RotL64((aOrbiterB * 16665696735016345215U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 11697397483133538067U) + aNonceWordE;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 17777142964957007194U) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 6338967222543284999U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 10892176201151170298U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 11759700374509499684U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14247697264744736081U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 11343756773329590643U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 15785048929757652350U;
            aOrbiterK = RotL64((aOrbiterK * 17208103574389502597U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 7508839228498497238U) + aNonceWordB;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 13088508510402094665U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15730279447009669103U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 16259236641717377699U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 11228995722951003980U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4870092259515181323U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 13775851561528617086U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 3023564646900497080U;
            aOrbiterE = RotL64((aOrbiterE * 9936548213275464131U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 154952467284609583U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 14239675888632174461U;
            aOrbiterG = RotL64((aOrbiterG * 1370550680736926425U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 168749514558708557U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 5070416708211422927U;
            aOrbiterI = RotL64((aOrbiterI * 13631900152346927703U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 1961290602001581341U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 12235345489656113478U;
            aOrbiterF = RotL64((aOrbiterF * 14403534235273302211U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 2295581049708176078U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 12206125048349568300U;
            aOrbiterA = RotL64((aOrbiterA * 6008868846674396181U), 13U);
            //
            aIngress = RotL64(aOrbiterE, 43U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + (RotL64(aOrbiterF, 41U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 50U));
            aIngress = aIngress + (RotL64(aOrbiterC, 37U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 38U)) + aOrbiterC);
            aWandererH = aWandererH ^ ((((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 13U)) + aOrbiterB) + aNonceWordO) + aPhaseEWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 5U) + aOrbiterJ) + RotL64(aOrbiterD, 3U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 60U) + RotL64(aOrbiterE, 19U)) + aOrbiterK) + aNonceWordD);
            aWandererA = aWandererA + (((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterA, 24U)) + aNonceWordH);
            aWandererG = aWandererG ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterK, 57U)) + aOrbiterF);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterC, 41U)) + aOrbiterI);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 36U) + RotL64(aOrbiterK, 43U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 21U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterE, 51U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 39U) + aOrbiterG) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 56U));
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 46U);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 16071U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneA[((aIndex + 12660U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15049U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 15114U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 43U) + RotL64(aCross, 26U)) ^ (RotL64(aCarry, 5U) ^ RotL64(aIngress, 57U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterF = ((((aWandererJ + RotL64(aCross, 41U)) + RotL64(aCarry, 23U)) + 4476099022490972343U) + aPhaseEOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1]) + aNonceWordF;
            aOrbiterI = (aWandererI + RotL64(aIngress, 60U)) + 16836423700375760429U;
            aOrbiterK = (aWandererK + RotL64(aPrevious, 13U)) + 8850577488928703557U;
            aOrbiterJ = (aWandererD + RotL64(aScatter, 51U)) + 7091631824560042743U;
            aOrbiterC = (aWandererA + RotL64(aPrevious, 43U)) + 12560498899956759494U;
            aOrbiterB = ((aWandererG + RotL64(aIngress, 21U)) + RotL64(aCarry, 3U)) + 7797973377112012161U;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 27U)) + RotL64(aCarry, 53U)) + 6173820673874805794U;
            aOrbiterD = (aWandererF + RotL64(aCross, 37U)) + 10805025132310245348U;
            aOrbiterA = (((aWandererB + RotL64(aScatter, 19U)) + 7139216143268029968U) + aPhaseEOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1]) + aNonceWordC;
            aOrbiterH = (aWandererH + RotL64(aCross, 23U)) + 8241544862261635722U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 4U)) + 4735527016563596150U) + aNonceWordM;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 5166171126690294033U) + aNonceWordG;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 11117641762075368393U;
            aOrbiterK = RotL64((aOrbiterK * 4980156869201219393U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 6312932356458415421U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 1304139291184508668U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 90744653170922319U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 10085025354842771067U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 16745854428789531080U;
            aOrbiterI = RotL64((aOrbiterI * 1945983905747274355U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 2497187958708890337U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 16069701876646548995U;
            aOrbiterC = RotL64((aOrbiterC * 16606039730973709495U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 17242004368025978091U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 12334315722243232121U) ^ aNonceWordI;
            aOrbiterD = RotL64((aOrbiterD * 16528598396696346719U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 8007042082518126895U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 5665686359038811484U;
            aOrbiterH = RotL64((aOrbiterH * 11289316305875751813U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 3913477186958600592U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 16918984318564170343U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5128293326494417281U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 10227611546502931418U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 7187623463085447228U;
            aOrbiterJ = RotL64((aOrbiterJ * 8479839369622163181U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 16655159122037336519U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 9844145011519243346U;
            aOrbiterE = RotL64((aOrbiterE * 16512883184116277583U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 8660130685326542506U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 16192687259641294851U;
            aOrbiterA = RotL64((aOrbiterA * 2882649237163668499U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 15208432734447317310U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = (((aOrbiterG ^ aOrbiterH) ^ 4476099022490972343U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterG = RotL64((aOrbiterG * 7447168142776253041U), 47U);
            //
            aIngress = RotL64(aOrbiterD, 30U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 37U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + RotL64(aOrbiterJ, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aPrevious, 18U) + aOrbiterJ) + RotL64(aOrbiterB, 27U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterC, 39U)) + aOrbiterJ);
            aWandererK = aWandererK + (((RotL64(aScatter, 39U) + aOrbiterC) + RotL64(aOrbiterG, 23U)) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterF, 35U)) + aOrbiterG) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 23U) + RotL64(aOrbiterG, 3U)) + aOrbiterJ);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterK, 48U)) + aNonceWordH);
            aWandererI = aWandererI + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterI, 51U)) + aOrbiterC);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 20U) + aOrbiterJ) + RotL64(aOrbiterD, 13U)) + aNonceWordN);
            aWandererH = aWandererH + (((RotL64(aCross, 35U) + RotL64(aOrbiterE, 37U)) + aOrbiterJ) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 37U) + aOrbiterA) + RotL64(aOrbiterH, 42U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 53U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererC, 34U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 51U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordN;
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 16749U)) & S_BLOCK1], 42U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 20341U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21679U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneD[((aIndex + 17219U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCarry, 51U)) ^ (RotL64(aCross, 21U) + RotL64(aPrevious, 38U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 47U)) + RotL64(aCarry, 29U)) + 12046647397183218524U;
            aOrbiterF = (aWandererJ + RotL64(aCross, 39U)) + 2760779375026461991U;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 41U)) + 13735454443176855650U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aScatter, 35U)) + 4370377000586647724U;
            aOrbiterA = (aWandererE + RotL64(aPrevious, 19U)) + 14566322384189969094U;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 53U)) + RotL64(aCarry, 57U)) + 5056565959818422786U;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 28U)) + 8795403810686579209U) + aNonceWordO;
            aOrbiterB = ((aWandererK + RotL64(aCross, 51U)) + 9625947666256011567U) + aPhaseEOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aPrevious, 13U)) + 1703669290934254701U;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 5U)) + RotL64(aCarry, 11U)) + 6664070663184147951U;
            aOrbiterD = ((aWandererH + RotL64(aIngress, 10U)) + 2104148316797553431U) + aNonceWordM;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 1197910004222596145U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 9922977170060903197U;
            aOrbiterC = RotL64((aOrbiterC * 13047828062605568603U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 2048376210852567829U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 12568990647075931409U) ^ aNonceWordH;
            aOrbiterA = RotL64((aOrbiterA * 9860242601194210927U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 15026894775772902751U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 3439447160137900629U) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 1813754963043785165U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 6532671388552829796U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 17261098369835997661U;
            aOrbiterE = RotL64((aOrbiterE * 568292591215203521U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 3171300991007459947U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 5935563269327662024U;
            aOrbiterB = RotL64((aOrbiterB * 11271790283157765003U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 14290941734320455612U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 12371794745736518824U;
            aOrbiterK = RotL64((aOrbiterK * 12208762336145168647U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 8782840145467637373U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 4067525421190366741U;
            aOrbiterI = RotL64((aOrbiterI * 6671002797916227485U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 11854812920571789853U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 17564890418553131451U;
            aOrbiterD = RotL64((aOrbiterD * 16657184504366731805U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 6250004085193517531U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 2362659992682660827U) ^ aNonceWordI;
            aOrbiterH = RotL64((aOrbiterH * 4365619310373869859U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 4597159873252831182U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 13197238269207675773U;
            aOrbiterF = RotL64((aOrbiterF * 379653377172816575U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 8552479493772820372U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 12046647397183218524U;
            aOrbiterG = RotL64((aOrbiterG * 17918033655125400323U), 39U);
            //
            aIngress = RotL64(aOrbiterK, 39U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 24U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterG, 37U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterB, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterD, 53U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 39U) + aOrbiterF) + RotL64(aOrbiterK, 21U)) + RotL64(aCarry, 29U)) + aNonceWordL);
            aWandererB = aWandererB ^ ((RotL64(aCross, 14U) + RotL64(aOrbiterK, 47U)) + aOrbiterC);
            aWandererD = aWandererD + ((RotL64(aScatter, 3U) + RotL64(aOrbiterF, 41U)) + aOrbiterE);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 23U) + aOrbiterI) + RotL64(aOrbiterG, 39U)) + aNonceWordC);
            aWandererI = aWandererI + ((RotL64(aPrevious, 47U) + aOrbiterA) + RotL64(aOrbiterH, 3U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterJ, 14U)) + aOrbiterG);
            aWandererA = aWandererA + (((RotL64(aScatter, 50U) + RotL64(aOrbiterJ, 11U)) + aOrbiterH) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 41U) + aOrbiterK) + RotL64(aOrbiterJ, 51U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 53U) + aOrbiterB) + RotL64(aOrbiterE, 37U));
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 58U)) + aOrbiterA) + aNonceWordJ) + aPhaseEWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + (RotL64(aWandererH, 20U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + RotL64(aWandererC, 13U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ aNonceWordG;
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 22601U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((aIndex + 22457U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26796U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23000U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 23U)) + (RotL64(aCross, 4U) + RotL64(aIngress, 53U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 14U)) + RotL64(aCarry, 21U)) + 13481227414590594621U;
            aOrbiterE = (((aWandererF + RotL64(aIngress, 19U)) + RotL64(aCarry, 5U)) + 17425964381118918026U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aScatter, 21U)) + 4792004356135956581U;
            aOrbiterG = ((aWandererD + RotL64(aCross, 3U)) + 11926849936000639098U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = (aWandererI + RotL64(aPrevious, 43U)) + 990697329347742142U;
            aOrbiterB = (aWandererC + RotL64(aCross, 23U)) + 9307721505373076588U;
            aOrbiterA = (aWandererH + RotL64(aIngress, 27U)) + 17605732738841908719U;
            aOrbiterH = (aWandererJ + RotL64(aScatter, 11U)) + 13110764518634187439U;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 29U)) + 17970109897810645911U) + aNonceWordE;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 46U)) + RotL64(aCarry, 29U)) + 10273133817644703654U;
            aOrbiterF = (aWandererB + RotL64(aPrevious, 5U)) + 11239046688920468137U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 8355821483275763145U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 15522151127786049345U;
            aOrbiterI = RotL64((aOrbiterI * 4844278537850520413U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 5381663179722418112U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 9551368011768104906U;
            aOrbiterB = RotL64((aOrbiterB * 14202470972121732997U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 16264476585232221270U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 7721417776432288282U;
            aOrbiterH = RotL64((aOrbiterH * 10267770327791051869U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 339418090653475277U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 3247926250495935511U;
            aOrbiterD = RotL64((aOrbiterD * 16824669543765729097U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 3390560045236418590U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 3894024951542543635U) ^ aNonceWordD;
            aOrbiterK = RotL64((aOrbiterK * 10599637790900418767U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 3878539166189668154U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 5617705593218220843U;
            aOrbiterG = RotL64((aOrbiterG * 82771190372750823U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 12320861089148474544U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 14943790251625519550U;
            aOrbiterA = RotL64((aOrbiterA * 13758322022902008313U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 18119213517612562775U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 1413193144229486646U;
            aOrbiterJ = RotL64((aOrbiterJ * 14562375280658115687U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 14810150213456844196U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 8468712395797520201U;
            aOrbiterF = RotL64((aOrbiterF * 8167911669632436949U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 13501570100536254566U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 15409772061478100850U;
            aOrbiterE = RotL64((aOrbiterE * 955182899606655851U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 8621805947309982779U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 13481227414590594621U;
            aOrbiterC = RotL64((aOrbiterC * 9591362493722704105U), 23U);
            //
            aIngress = RotL64(aOrbiterE, 41U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterC, 60U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 37U) + aOrbiterJ) + RotL64(aOrbiterK, 43U));
            aWandererE = aWandererE + ((((RotL64(aPrevious, 27U) + aOrbiterK) + RotL64(aOrbiterG, 51U)) + aNonceWordG) + aPhaseEWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 48U) + aOrbiterE) + RotL64(aOrbiterF, 11U));
            aWandererA = aWandererA + ((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 23U)) + aOrbiterK);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterC, 60U)) + aNonceWordH);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 39U) + aOrbiterI) + RotL64(aOrbiterA, 41U)) + RotL64(aCarry, 39U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterD, 39U)) + aOrbiterI);
            aWandererK = aWandererK + ((RotL64(aCross, 50U) + RotL64(aOrbiterD, 37U)) + aOrbiterH);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 3U)) + aOrbiterB);
            aWandererF = aWandererF + ((((RotL64(aCross, 19U) + aOrbiterK) + RotL64(aOrbiterC, 14U)) + RotL64(aCarry, 23U)) + aPhaseEWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterH, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (RotL64(aWandererI, 18U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + RotL64(aWandererE, 39U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = aCarry ^ aNonceWordB;
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 28532U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((aIndex + 27458U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 27612U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((aIndex + 32367U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 19U) ^ RotL64(aIngress, 57U)) ^ (RotL64(aCross, 5U) + RotL64(aPrevious, 40U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterJ = ((aWandererK + RotL64(aCross, 37U)) + 12775735908960052604U) + aNonceWordL;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 29U)) + 11791373812080296887U) + aNonceWordK;
            aOrbiterD = (aWandererD + RotL64(aIngress, 54U)) + 5537362877706057303U;
            aOrbiterH = (aWandererI + RotL64(aPrevious, 41U)) + 2023912048504189380U;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 51U)) + 17668828109963766893U) + aNonceWordI;
            aOrbiterI = (((aWandererF + RotL64(aIngress, 39U)) + RotL64(aCarry, 23U)) + 558908629933941224U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aCross, 3U)) + 1479633119685446888U;
            aOrbiterB = (((aWandererB + RotL64(aPrevious, 35U)) + RotL64(aCarry, 57U)) + 15460320397843364063U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 27U)) + RotL64(aCarry, 43U)) + 10059749397555469054U;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 47U)) + 9987633811929693924U;
            aOrbiterG = (aWandererA + RotL64(aIngress, 12U)) + 10087337844580228269U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 4446204415503364254U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterJ) ^ 15106063243302192717U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterD = RotL64((aOrbiterD * 13273756657334709803U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 9430197906134676162U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 1226048679997253363U;
            aOrbiterF = RotL64((aOrbiterF * 14247538885252664127U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 10611580584157624739U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 3137391249289641509U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5462682413239873181U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 9327201928815412810U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 7890659377013147073U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13827717178378062047U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 10675114832750356941U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 8804440385852327267U;
            aOrbiterB = RotL64((aOrbiterB * 8520671775587260601U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 12871947817782057116U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 11015991745792051390U;
            aOrbiterE = RotL64((aOrbiterE * 17152451500505815031U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 6320437975845673731U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 702457937087191287U;
            aOrbiterC = RotL64((aOrbiterC * 17491257114676739589U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 16629064896250312921U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 6054107387816339103U;
            aOrbiterG = RotL64((aOrbiterG * 6983767878966747219U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 13274874838094190290U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 12211422735294360321U;
            aOrbiterJ = RotL64((aOrbiterJ * 5113738196151089817U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 15338616110718583619U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 1475787183754511373U;
            aOrbiterA = RotL64((aOrbiterA * 10904607643785840003U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 15486810401396777742U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 12775735908960052604U;
            aOrbiterH = RotL64((aOrbiterH * 7478156942468930207U), 35U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterA, 26U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 50U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterI, 21U)) + aOrbiterC);
            aWandererB = aWandererB + (((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterA, 47U)) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterK, 60U)) + aOrbiterJ);
            aWandererF = aWandererF + (((RotL64(aScatter, 35U) + aOrbiterA) + RotL64(aOrbiterE, 11U)) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 24U) + aOrbiterG) + RotL64(aOrbiterK, 19U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 29U) + aOrbiterD) + RotL64(aOrbiterH, 5U)) + aPhaseEWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterF, 53U)) + aOrbiterC) + aNonceWordF);
            aWandererC = aWandererC + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterB, 41U)) + aOrbiterK);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterH, 24U)) + aOrbiterG);
            aWandererD = aWandererD + ((RotL64(aPrevious, 46U) + aOrbiterC) + RotL64(aOrbiterD, 3U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterH, 35U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 50U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + (RotL64(aWandererC, 46U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 19U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordN);
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

void TwistExpander_Karate_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xC40E2509DEB0F64FULL + 0x846B3C6054BA95EBULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x873319A65164F075ULL + 0xD7957F29AC45DAC0ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xCDA39ACC38B69F97ULL + 0xA427DF1BF31E0C57ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xAAA039A4809E4455ULL + 0xFD42005C34CED90AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xBCEAA23A9F374075ULL + 0x92D93D5BF8659143ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xA86E1441183E62DDULL + 0xC95E76AF393874C0ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xF7BDE33742C06577ULL + 0xCF182C847BD66034ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xA0E891B0E2E680B7ULL + 0xCE999C2036A9BF8CULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xCA45E115A23CC11DULL + 0xAF26823D4945C472ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xD3050B0C58041387ULL + 0x9A9BA9D4C2875D10ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xA5910FA82A8E9223ULL + 0xE0713AFF978409A7ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xAA6BF8545866F673ULL + 0x9419B38806B25B20ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xF42A32B201709BA9ULL + 0xE25F0F0D090292DBULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xA955EE8AA1730943ULL + 0xFF147EE6BAF922DBULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xBB621C40675E7C59ULL + 0xE988BB66293920C6ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x9C785E2C623A638DULL + 0xB903E2218CEA35B8ULL);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 1848U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneC[((aIndex + 2862U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 5183U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((aIndex + 5288U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCarry, 39U)) ^ (RotL64(aIngress, 3U) + RotL64(aCross, 52U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = ((aWandererF + RotL64(aIngress, 51U)) + RotL64(aCarry, 27U)) + 18319689184146942855U;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 11U)) + RotL64(aCarry, 47U)) + 8041304130090501019U;
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 23U)) + 11347064191990897738U;
            aOrbiterA = (aWandererE + RotL64(aCross, 29U)) + 15242243470024447468U;
            aOrbiterF = (aWandererJ + RotL64(aIngress, 3U)) + 10619749107163611105U;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 57U)) + 14795614276221947128U) + aPhaseFOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aScatter, 36U)) + 1578095288886372393U;
            aOrbiterB = (aWandererI + RotL64(aCross, 53U)) + 13593906305770501684U;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 27U)) + RotL64(aCarry, 35U)) + 8919815528334599172U;
            aOrbiterI = ((aWandererK + RotL64(aCross, 21U)) + 17425548324720065145U) + aNonceWordD;
            aOrbiterE = (((aWandererC + RotL64(aScatter, 14U)) + 11125018338392347335U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordI;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 3779189180734244399U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 10958224663276134041U;
            aOrbiterJ = RotL64((aOrbiterJ * 6206963519509783781U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 4317305352561612995U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 4891139433808505355U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11507024985663120317U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 5166074784835930965U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 10080890270621589202U;
            aOrbiterK = RotL64((aOrbiterK * 13170894418184288695U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 4501071771615514619U) + aNonceWordE;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 6486573807774431753U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 324029625116648669U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 15714881857668975753U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 3506619392820235900U;
            aOrbiterH = RotL64((aOrbiterH * 5707033870161224499U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 5295711072762443783U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 11192836530396570648U;
            aOrbiterD = RotL64((aOrbiterD * 4361810118382207039U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 7993389678399774574U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 12551394763541226695U;
            aOrbiterE = RotL64((aOrbiterE * 11903486656172026403U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 11553674370322129668U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 4459881583199320245U;
            aOrbiterC = RotL64((aOrbiterC * 2805857426321555685U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 3053507713574219459U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 15458441755058850309U;
            aOrbiterF = RotL64((aOrbiterF * 7296609957819165877U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 17429750026356459756U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 17114614857181230304U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10541235280918902739U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 8958993884028672039U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 18319689184146942855U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5430881344386342703U), 23U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterJ, 35U);
            aIngress = aIngress + (RotL64(aOrbiterC, 46U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + (RotL64(aOrbiterA, 39U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterG, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 57U) + aOrbiterI) + RotL64(aOrbiterJ, 60U)) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterI, 27U)) + aOrbiterD) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 46U) + aOrbiterG) + RotL64(aOrbiterE, 41U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterE, 23U)) + aOrbiterD) + aPhaseFWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 37U) + aOrbiterH) + RotL64(aOrbiterA, 53U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterK, 43U)) + aOrbiterF) + aNonceWordC);
            aWandererK = aWandererK + (((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 21U)) + aOrbiterI) + aNonceWordB);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 5U)) + aOrbiterG);
            aWandererH = aWandererH + ((RotL64(aIngress, 21U) + RotL64(aOrbiterA, 14U)) + aOrbiterF);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 6U) + aOrbiterK) + RotL64(aOrbiterB, 47U));
            aWandererA = aWandererA + ((((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterK, 3U)) + RotL64(aCarry, 23U)) + aNonceWordJ);
            //
            aCarry = aCarry + (RotL64(aWandererD, 24U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 13U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = aCarry ^ aNonceWordM;
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8008U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 6285U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 9996U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((aIndex + 8604U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aPrevious, 51U)) ^ (RotL64(aIngress, 3U) + RotL64(aCarry, 34U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = ((aWandererA + RotL64(aCross, 27U)) + RotL64(aCarry, 3U)) + 15188686795415908074U;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 39U)) + RotL64(aCarry, 29U)) + 17310049041983079779U;
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 29U)) + 8246925977992441471U;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 19U)) + RotL64(aCarry, 57U)) + 8644260919918112781U;
            aOrbiterI = ((aWandererG + RotL64(aCross, 3U)) + 13401663736874819483U) + aNonceWordE;
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 44U)) + 7940358935238314973U;
            aOrbiterF = (aWandererC + RotL64(aScatter, 57U)) + 13278990328548007839U;
            aOrbiterD = (aWandererH + RotL64(aIngress, 21U)) + 11346868298353840706U;
            aOrbiterA = (aWandererK + RotL64(aCross, 35U)) + 2374077904806833579U;
            aOrbiterC = ((aWandererE + RotL64(aScatter, 60U)) + 6978903378645019166U) + aPhaseFOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 51U)) + 11951633297870965212U) + aPhaseFOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 17398460995357409673U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 1215437945597836770U;
            aOrbiterJ = RotL64((aOrbiterJ * 9322970054123481621U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 1878751468043972239U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 5343002808239712390U;
            aOrbiterB = RotL64((aOrbiterB * 11878640995447558811U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 9884918450053276861U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 15894599082080422550U;
            aOrbiterI = RotL64((aOrbiterI * 8359936745539546131U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 13917339232771145459U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 18101134009493720683U;
            aOrbiterF = RotL64((aOrbiterF * 15835859435306756387U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 3830086372356903769U) + aNonceWordB;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 15894394599564584010U;
            aOrbiterA = RotL64((aOrbiterA * 9513921913446609263U), 51U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterG) + 5127590955274245812U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordO;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 9410946933309720054U;
            aOrbiterE = RotL64((aOrbiterE * 14507476989423060561U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 15544384157294987085U) + aNonceWordD;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 998801294460434123U;
            aOrbiterG = RotL64((aOrbiterG * 5946968142746472745U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 16442095194965452163U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 14294936349037516932U;
            aOrbiterH = RotL64((aOrbiterH * 14655345374740882581U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 16680659892463349201U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 10921918150041635666U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2908474941036821745U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 15350264522133299871U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 16413848767507968239U;
            aOrbiterC = RotL64((aOrbiterC * 10226942289998651355U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 11963105565077056299U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 15188686795415908074U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13002484121826831091U), 39U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 3U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 42U));
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 47U) + aOrbiterK) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 53U) + aOrbiterF) + RotL64(aOrbiterA, 21U)) + aNonceWordM);
            aWandererB = aWandererB + (((RotL64(aCross, 34U) + RotL64(aOrbiterB, 53U)) + aOrbiterJ) + aNonceWordP);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 11U)) + aOrbiterI) + aPhaseFWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 5U) + aOrbiterI) + RotL64(aOrbiterG, 24U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 21U) + aOrbiterG) + RotL64(aOrbiterF, 19U)) + aNonceWordI);
            aWandererA = aWandererA + ((RotL64(aCross, 19U) + RotL64(aOrbiterE, 57U)) + aOrbiterD);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 58U) + RotL64(aOrbiterC, 37U)) + aOrbiterB);
            aWandererD = aWandererD + (((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterG, 47U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 23U) + aOrbiterI) + RotL64(aOrbiterF, 6U));
            aWandererE = aWandererE + (((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 27U)) + aOrbiterH) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 28U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = aCarry ^ aNonceWordG;
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12057U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15284U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 15236U)) & S_BLOCK1], 24U) ^ RotL64(aOperationLaneC[((aIndex + 15677U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 42U)) ^ (RotL64(aCarry, 57U) + RotL64(aIngress, 19U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterB = (aWandererB + RotL64(aCross, 13U)) + 898812731947995389U;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 60U)) + 8677347622525527167U) + aPhaseFOrbiterAssignSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aScatter, 47U)) + RotL64(aCarry, 11U)) + 770321564027567654U;
            aOrbiterG = (aWandererD + RotL64(aPrevious, 3U)) + 11020474858081526395U;
            aOrbiterC = (aWandererK + RotL64(aIngress, 23U)) + 17289793580414993470U;
            aOrbiterH = (aWandererH + RotL64(aScatter, 53U)) + 10111912559295118444U;
            aOrbiterE = (((aWandererC + RotL64(aCross, 29U)) + RotL64(aCarry, 29U)) + 8083622125544542011U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aPrevious, 26U)) + 7149858558922988240U;
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 39U)) + 5919683821379905699U;
            aOrbiterK = ((aWandererG + RotL64(aCross, 41U)) + 6860902846079238714U) + aNonceWordJ;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 35U)) + RotL64(aCarry, 3U)) + 15083517836867542075U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 14852868368708376381U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 9860233289028878323U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13418143547952204667U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 772406119079116272U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 7971141501337627589U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10168120622976358617U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 8478568022896691911U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 4027604850785607101U;
            aOrbiterI = RotL64((aOrbiterI * 4826627523578901467U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 17199331557841535430U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 7515957656979776361U;
            aOrbiterC = RotL64((aOrbiterC * 5468950152869656599U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 17138249294921502391U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 16236812863923234668U;
            aOrbiterD = RotL64((aOrbiterD * 2925542836624164807U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 16941524155859123682U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 11240343728857342866U;
            aOrbiterK = RotL64((aOrbiterK * 7281012444214294659U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 15163914964139858328U) + aNonceWordH;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 6673576554415729652U;
            aOrbiterB = RotL64((aOrbiterB * 1558880328574736975U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 5399050402101642989U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 11806006719060024615U;
            aOrbiterG = RotL64((aOrbiterG * 15782156615926092159U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 9812148913932011655U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 4737919734590584193U) ^ aNonceWordE;
            aOrbiterE = RotL64((aOrbiterE * 2739737604370936959U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 3415477403346468057U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 5922725868927615919U;
            aOrbiterJ = RotL64((aOrbiterJ * 12390148483052777871U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 17435294951520465659U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 898812731947995389U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 17248379279729365007U), 21U);
            //
            aIngress = RotL64(aOrbiterF, 30U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + RotL64(aOrbiterH, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 35U) + aOrbiterA) + RotL64(aOrbiterK, 35U)) + aNonceWordN);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 37U) + aOrbiterC) + RotL64(aOrbiterB, 39U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterC, 19U)) + aNonceWordI);
            aWandererH = aWandererH + (((RotL64(aCross, 47U) + aOrbiterA) + RotL64(aOrbiterC, 58U)) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 41U) + aOrbiterF) + RotL64(aOrbiterK, 41U));
            aWandererE = aWandererE + ((RotL64(aScatter, 39U) + RotL64(aOrbiterH, 23U)) + aOrbiterE);
            aWandererD = aWandererD ^ ((RotL64(aCross, 20U) + aOrbiterJ) + RotL64(aOrbiterK, 29U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterB, 37U)) + aOrbiterA) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 29U) + aOrbiterG) + RotL64(aOrbiterE, 43U));
            aWandererA = aWandererA + (((RotL64(aCross, 57U) + RotL64(aOrbiterI, 21U)) + aOrbiterE) + aPhaseFWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 18U) + aOrbiterE) + RotL64(aOrbiterD, 6U)) + aNonceWordA) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererA);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (RotL64(aWandererG, 44U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ aNonceWordL;
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 19721U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((aIndex + 17962U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19903U)) & S_BLOCK1], 34U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 21750U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 41U) + RotL64(aPrevious, 24U)) ^ (RotL64(aCross, 53U) ^ RotL64(aIngress, 3U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = (aWandererG + RotL64(aCross, 39U)) + 8101351470141807662U;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 43U)) + 6965474099521076705U) + aPhaseFOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aPrevious, 23U)) + 6803828268885684784U;
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 4U)) + RotL64(aCarry, 11U)) + 13454235922950972488U;
            aOrbiterI = (aWandererE + RotL64(aPrevious, 21U)) + 11678091885751244777U;
            aOrbiterD = (aWandererK + RotL64(aCross, 11U)) + 5307134544628507141U;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 53U)) + 4873703518950429353U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aScatter, 41U)) + 8542156221858586039U;
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 60U)) + RotL64(aCarry, 27U)) + 3993726182905296513U;
            aOrbiterH = (((aWandererC + RotL64(aCross, 13U)) + RotL64(aCarry, 41U)) + 12113047622035464386U) + aNonceWordL;
            aOrbiterG = (aWandererF + RotL64(aScatter, 35U)) + 1944244448665721151U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 12914188029425467576U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 2486762763475327024U) ^ aNonceWordE;
            aOrbiterB = RotL64((aOrbiterB * 12319769994433811617U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 14580191602982245481U) + aNonceWordD;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 12093414832400135066U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12720286833215690663U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 13623906997320021065U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 9977356009806428696U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2005536391712733499U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 3694954095397810851U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 11453812627797091638U;
            aOrbiterF = RotL64((aOrbiterF * 13730420725113907161U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 542311345544726351U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 3024285045990499484U;
            aOrbiterJ = RotL64((aOrbiterJ * 5153745952148205645U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 15397664082460849530U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 10716856680110815056U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13947203772929252823U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 833342121331428547U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 1111339940097269219U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17991642769781175473U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 9312963978841402871U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 8225496710723213204U;
            aOrbiterG = RotL64((aOrbiterG * 894499195498817065U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 7947419530949269753U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 5028446114139808517U;
            aOrbiterK = RotL64((aOrbiterK * 5593084899736787263U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 9818957208200746975U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 17549192719666647522U;
            aOrbiterE = RotL64((aOrbiterE * 4705007748877441833U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 16389708540378477737U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 8101351470141807662U;
            aOrbiterC = RotL64((aOrbiterC * 9858235486537441981U), 53U);
            //
            aIngress = RotL64(aOrbiterD, 37U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 50U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 41U));
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aIngress, 39U) + RotL64(aOrbiterF, 47U)) + aOrbiterE);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 43U) + aOrbiterB) + RotL64(aOrbiterG, 39U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterF, 58U)) + aOrbiterG);
            aWandererA = aWandererA ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterG, 35U)) + aOrbiterH) + aPhaseFWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 6U) + RotL64(aOrbiterF, 41U)) + aOrbiterJ) + aNonceWordP);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 23U) + aOrbiterA) + RotL64(aOrbiterK, 37U));
            aWandererE = aWandererE + ((RotL64(aIngress, 19U) + RotL64(aOrbiterA, 11U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterB, 13U)) + aOrbiterK) + aPhaseFWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 13U) + aOrbiterG) + RotL64(aOrbiterD, 27U)) + RotL64(aCarry, 39U)) + aNonceWordK);
            aWandererB = aWandererB ^ (((RotL64(aCross, 27U) + aOrbiterC) + RotL64(aOrbiterD, 24U)) + aNonceWordF);
            aWandererD = aWandererD + (((RotL64(aScatter, 48U) + aOrbiterI) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 48U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 41U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererA, 18U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordA);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 21966U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneA[((aIndex + 26248U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24910U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 23078U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCross, 21U)) + (RotL64(aPrevious, 36U) ^ RotL64(aCarry, 57U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterJ = (((aWandererI + RotL64(aPrevious, 43U)) + 9888431329297626900U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordM;
            aOrbiterB = (aWandererK + RotL64(aCross, 41U)) + 2937735167534624403U;
            aOrbiterK = ((aWandererA + RotL64(aIngress, 46U)) + RotL64(aCarry, 27U)) + 17626022970343789617U;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 23U)) + RotL64(aCarry, 13U)) + 5665660859333693743U;
            aOrbiterD = (aWandererH + RotL64(aIngress, 57U)) + 1060537034632076669U;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 51U)) + 743777763907175800U) + aPhaseFOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aCross, 38U)) + 5744905970181808845U;
            aOrbiterC = (aWandererG + RotL64(aScatter, 21U)) + 3545351394494002180U;
            aOrbiterF = (aWandererB + RotL64(aPrevious, 35U)) + 4877547088414106007U;
            aOrbiterG = (aWandererC + RotL64(aIngress, 3U)) + 11669378338379598445U;
            aOrbiterI = ((aWandererE + RotL64(aCross, 27U)) + RotL64(aCarry, 47U)) + 2961072441706158212U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 13984945589234919765U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 1433097875470903205U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 451996840039906781U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 716415411025451152U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 8542286150858297810U;
            aOrbiterA = RotL64((aOrbiterA * 9139015340823332449U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 12932391786479661299U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterH) ^ 14005503313299177013U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 802663466907819743U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 9382792812676318046U) + aNonceWordP;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 5138554251079724724U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6386016499265056247U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 8522380066269546172U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 11825536408101906458U;
            aOrbiterJ = RotL64((aOrbiterJ * 17042837108792016849U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 15504062350899452495U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 1219010998820336744U;
            aOrbiterE = RotL64((aOrbiterE * 10650635772711590803U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 6442717843380349632U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 1047843426279085117U;
            aOrbiterH = RotL64((aOrbiterH * 4074561571072878005U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 10611039527108679173U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 5092816736177358221U;
            aOrbiterF = RotL64((aOrbiterF * 14342779343820140833U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 12327496881352988530U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 6405703847824845457U;
            aOrbiterI = RotL64((aOrbiterI * 12094143526751620113U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 8906613392335197542U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 5962698890029858689U;
            aOrbiterB = RotL64((aOrbiterB * 9136193803330500489U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 2610083915800734277U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 9888431329297626900U;
            aOrbiterD = RotL64((aOrbiterD * 3794133356691218671U), 5U);
            //
            aIngress = RotL64(aOrbiterK, 47U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterB, 30U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterA, 41U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterD, 21U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 27U));
            aIngress = aIngress + RotL64(aOrbiterI, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 28U) + aOrbiterH) + RotL64(aOrbiterG, 19U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 13U) + aOrbiterE) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 43U)) + aNonceWordH);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 11U) + aOrbiterF) + RotL64(aOrbiterA, 35U));
            aWandererF = aWandererF + (((RotL64(aScatter, 37U) + aOrbiterK) + RotL64(aOrbiterE, 3U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterF, 23U)) + aOrbiterD) + aNonceWordC);
            aWandererA = aWandererA + ((RotL64(aCross, 47U) + RotL64(aOrbiterD, 60U)) + aOrbiterB);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 39U)) + aOrbiterD) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 27U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 23U) + aOrbiterJ) + RotL64(aOrbiterD, 5U));
            aWandererK = aWandererK + ((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterH, 54U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 18U) + RotL64(aOrbiterK, 43U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 58U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererA, 39U);
            aCarry = aCarry + RotL64(aIngress, 24U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordF);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 27374U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30293U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28712U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneB[((aIndex + 32221U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 26U) ^ RotL64(aIngress, 13U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 41U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = (((aWandererH + RotL64(aPrevious, 54U)) + RotL64(aCarry, 47U)) + 1297415699043177788U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aCross, 47U)) + 17583786534509260153U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 3U)) + 643197858925708798U) + aNonceWordK;
            aOrbiterB = (aWandererA + RotL64(aScatter, 27U)) + 5062653766915694874U;
            aOrbiterD = (aWandererG + RotL64(aPrevious, 43U)) + 7034273638367180511U;
            aOrbiterJ = ((aWandererD + RotL64(aCross, 19U)) + 2026909726972916996U) + aNonceWordO;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 35U)) + RotL64(aCarry, 19U)) + 2785690475553211646U;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 50U)) + RotL64(aCarry, 3U)) + 2910341716302991892U;
            aOrbiterE = ((aWandererC + RotL64(aCross, 23U)) + 2834181605200829791U) + aPhaseFOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = (aWandererE + RotL64(aIngress, 5U)) + 13323052600571281928U;
            aOrbiterI = (aWandererB + RotL64(aPrevious, 11U)) + 10434901530315760460U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 247903955625194782U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 5196515747387257163U;
            aOrbiterF = RotL64((aOrbiterF * 1799024689023272275U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 7196305682377987476U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 14777739876892587484U;
            aOrbiterD = RotL64((aOrbiterD * 95220583948241581U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 10609060796540136671U) + aNonceWordC;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 8386027207212484155U;
            aOrbiterJ = RotL64((aOrbiterJ * 4855610536246556893U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 729659744301903424U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 2350564261412606157U;
            aOrbiterK = RotL64((aOrbiterK * 16713856782349084977U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 16611987556673864177U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 1525195188708550503U;
            aOrbiterC = RotL64((aOrbiterC * 10045858602151004553U), 47U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterK) + 4654808490980989596U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 8189569777087686263U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17278657566389299577U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 10932857495004451792U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 1833880112534916813U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8004341577533825681U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 13100236350175516423U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 2773759534195186313U) ^ aNonceWordF;
            aOrbiterI = RotL64((aOrbiterI * 3194954066097323161U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 13963126688973399221U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 1464529855671190406U;
            aOrbiterH = RotL64((aOrbiterH * 6129954747502059213U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 9489842625026216815U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 17806120432918490594U;
            aOrbiterG = RotL64((aOrbiterG * 349307975773661379U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 13833297268854563081U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 1297415699043177788U;
            aOrbiterB = RotL64((aOrbiterB * 4818542043777342249U), 11U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterK, 41U);
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterF, 51U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterB, 58U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterJ, 41U)) + aOrbiterD) + RotL64(aCarry, 23U)) + aNonceWordD);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterE, 3U)) + aOrbiterJ);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 46U)) + aOrbiterK) + RotL64(aCarry, 19U)) + aPhaseFWandererUpdateSaltB[((aIndex + 20U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 26U) + aOrbiterJ) + RotL64(aOrbiterK, 51U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterB, 37U)) + aOrbiterI);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterG, 27U)) + aOrbiterJ) + aNonceWordA);
            aWandererG = aWandererG + ((RotL64(aScatter, 5U) + RotL64(aOrbiterC, 57U)) + aOrbiterB);
            aWandererH = aWandererH ^ ((RotL64(aCross, 37U) + aOrbiterE) + RotL64(aOrbiterH, 35U));
            aWandererB = aWandererB + ((RotL64(aScatter, 28U) + aOrbiterB) + RotL64(aOrbiterJ, 6U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 39U) + aOrbiterA) + RotL64(aOrbiterB, 29U)) + aNonceWordI);
            aWandererD = aWandererD + (((RotL64(aIngress, 41U) + aOrbiterF) + RotL64(aOrbiterC, 21U)) + aPhaseFWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 42U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererD, 10U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordI);
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

void TwistExpander_Karate_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xF9A8AD9CF04816DBULL + 0xF1AD6025531F4AEFULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xC11D6EFF978D868BULL + 0xA7CFBD955120B70AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xA07EB0A6AFEFAF31ULL + 0xD09F46C1B04BDE2EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x88404F7DBD506427ULL + 0xF24CA92BEEF25600ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x9D5C198DFCC4588BULL + 0xAF25F3040130C4A1ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xBCEFA1CD4CC73BEBULL + 0xAB30A6FE460981E2ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x8A838D8032BD236BULL + 0xCA966000DB8CB756ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xC6725FE3682056AFULL + 0x9CC3D90592694C55ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x87B7B5DF89F6D7F1ULL + 0xB94EE9F8EFDA67F4ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xBD3B8353B0737893ULL + 0xC5277E3C2F3D1D92ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xE929E06C4AF1F581ULL + 0x81EF4F7AB0EC19C7ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xBD9E789204BF169BULL + 0xFE6CB55F83DB990DULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xB20D1DD637656F51ULL + 0xB845BAF52E947529ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xB425F63B58452FAFULL + 0x9B3F94C4A2EE5A71ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xF07CC1615140BF8FULL + 0xE898061105B1EC84ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xCF65B2C03B63A585ULL + 0xB3652E918EA5E26BULL);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 2285U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneC[((aIndex + 5083U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 5107U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneA[((aIndex + 1580U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 13U) + RotL64(aCarry, 39U)) ^ (RotL64(aCross, 27U) ^ RotL64(aIngress, 56U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 34U)) + 5160910997561396461U) + aPhaseFOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = ((aWandererD + RotL64(aCross, 27U)) + RotL64(aCarry, 57U)) + 14920764751058512062U;
            aOrbiterE = (aWandererH + RotL64(aIngress, 13U)) + 6080952401749660022U;
            aOrbiterC = (aWandererC + RotL64(aScatter, 43U)) + 17667234330526298627U;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 29U)) + 760630072638686756U;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 11U)) + RotL64(aCarry, 51U)) + 3504157162816997476U;
            aOrbiterD = (aWandererB + RotL64(aCross, 23U)) + 9489022223422585882U;
            aOrbiterF = (((aWandererJ + RotL64(aScatter, 3U)) + 1149898536879968964U) + aPhaseFOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1]) + aNonceWordH;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 57U)) + RotL64(aCarry, 13U)) + 10492284328940025310U;
            aOrbiterG = (aWandererG + RotL64(aIngress, 6U)) + 13213275606286399312U;
            aOrbiterH = (aWandererK + RotL64(aCross, 37U)) + 10557118912847180413U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 15618980209023994776U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 5268600749854045564U;
            aOrbiterE = RotL64((aOrbiterE * 3849660559223919613U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 8011552687609649990U) + aNonceWordO;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 3148133096349525066U;
            aOrbiterA = RotL64((aOrbiterA * 5245156554959620007U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 12032847944237867285U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 14999005703490824673U;
            aOrbiterK = RotL64((aOrbiterK * 6631584955208646049U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 5426735969392906710U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 3593177531650386729U;
            aOrbiterC = RotL64((aOrbiterC * 12997284886192717043U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 1701444719333347373U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 15928731228196894960U;
            aOrbiterD = RotL64((aOrbiterD * 1919318226904213433U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 5960179456039157036U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 5716434224061596483U;
            aOrbiterJ = RotL64((aOrbiterJ * 3731976564761202801U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 2136841536293340279U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 12969550408652728526U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7612191387451455137U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 3641997570461447114U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 4677572491523684525U;
            aOrbiterI = RotL64((aOrbiterI * 2730358077882211651U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 2741372094325164504U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 4998631511811832690U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10619395395977372695U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 6260464862798783617U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 16489087874167346533U;
            aOrbiterF = RotL64((aOrbiterF * 11278053967185244867U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 7043760915859224327U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 5160910997561396461U;
            aOrbiterG = RotL64((aOrbiterG * 15260149870590431675U), 37U);
            //
            aIngress = RotL64(aOrbiterA, 27U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 39U));
            aIngress = aIngress + (RotL64(aOrbiterK, 22U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 58U)) + aOrbiterG) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 37U) + aOrbiterK) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterC, 39U)) + aOrbiterJ);
            aWandererI = aWandererI + ((RotL64(aIngress, 41U) + aOrbiterE) + RotL64(aOrbiterK, 37U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterI, 3U)) + aOrbiterF) + aNonceWordJ);
            aWandererH = aWandererH + ((RotL64(aIngress, 35U) + RotL64(aOrbiterD, 19U)) + aOrbiterG);
            aWandererE = aWandererE ^ (((RotL64(aCross, 27U) + aOrbiterD) + RotL64(aOrbiterC, 5U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 48U) + aOrbiterF) + RotL64(aOrbiterD, 27U)) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterE, 41U));
            aWandererG = aWandererG + ((RotL64(aCross, 23U) + aOrbiterG) + RotL64(aOrbiterK, 11U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterE, 24U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 12U));
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererC, 3U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ aNonceWordO;
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 7424U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneD[((aIndex + 8399U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7998U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 8143U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 54U) ^ RotL64(aCarry, 11U)) ^ (RotL64(aCross, 27U) + RotL64(aPrevious, 39U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterA = ((aWandererA + RotL64(aCross, 19U)) + RotL64(aCarry, 3U)) + 1297415699043177788U;
            aOrbiterK = (aWandererD + RotL64(aIngress, 44U)) + 17583786534509260153U;
            aOrbiterH = (aWandererI + RotL64(aScatter, 3U)) + 643197858925708798U;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 13U)) + 5062653766915694874U) + aNonceWordH;
            aOrbiterB = (aWandererH + RotL64(aCross, 37U)) + 7034273638367180511U;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 23U)) + RotL64(aCarry, 23U)) + 2026909726972916996U;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 5U)) + 2785690475553211646U) + aPhaseFOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = (((aWandererC + RotL64(aScatter, 35U)) + RotL64(aCarry, 37U)) + 2910341716302991892U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aIngress, 28U)) + 2834181605200829791U;
            aOrbiterC = (aWandererK + RotL64(aPrevious, 41U)) + 13323052600571281928U;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 53U)) + 10434901530315760460U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 247903955625194782U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 5196515747387257163U;
            aOrbiterH = RotL64((aOrbiterH * 1799024689023272275U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 7196305682377987476U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 14777739876892587484U;
            aOrbiterK = RotL64((aOrbiterK * 95220583948241581U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 10609060796540136671U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (((aOrbiterB ^ aOrbiterI) ^ 8386027207212484155U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 4855610536246556893U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 729659744301903424U) + aNonceWordM;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 2350564261412606157U;
            aOrbiterJ = RotL64((aOrbiterJ * 16713856782349084977U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 16611987556673864177U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 1525195188708550503U;
            aOrbiterF = RotL64((aOrbiterF * 10045858602151004553U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 4654808490980989596U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 8189569777087686263U;
            aOrbiterA = RotL64((aOrbiterA * 17278657566389299577U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 10932857495004451792U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 1833880112534916813U;
            aOrbiterD = RotL64((aOrbiterD * 8004341577533825681U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 13100236350175516423U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 2773759534195186313U;
            aOrbiterI = RotL64((aOrbiterI * 3194954066097323161U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 13963126688973399221U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 1464529855671190406U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6129954747502059213U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 9489842625026216815U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 17806120432918490594U;
            aOrbiterC = RotL64((aOrbiterC * 349307975773661379U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 13833297268854563081U) + aNonceWordE;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 1297415699043177788U;
            aOrbiterG = RotL64((aOrbiterG * 4818542043777342249U), 37U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterG, 11U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 60U));
            aIngress = aIngress + RotL64(aOrbiterE, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterE, 37U)) + aOrbiterK) + aPhaseFWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 21U)) + aOrbiterB) + aNonceWordG);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 13U)) + aOrbiterB) + aPhaseFWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 11U) + aOrbiterF) + RotL64(aOrbiterE, 43U)) + RotL64(aCarry, 41U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterH, 4U)) + aOrbiterG);
            aWandererC = aWandererC + ((RotL64(aPrevious, 24U) + aOrbiterI) + RotL64(aOrbiterJ, 23U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 19U)) + aOrbiterD) + aNonceWordI);
            aWandererK = aWandererK + ((RotL64(aCross, 3U) + RotL64(aOrbiterK, 51U)) + aOrbiterA);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 27U) + aOrbiterJ) + RotL64(aOrbiterE, 27U));
            aWandererF = aWandererF + (((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterC, 58U)) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 22U) + aOrbiterE) + RotL64(aOrbiterH, 41U)) + aNonceWordJ);
            //
            aCarry = aCarry + (RotL64(aWandererB, 21U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 14U));
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + RotL64(aWandererG, 44U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordP;
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 12197U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((aIndex + 11836U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 11380U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneC[((aIndex + 11102U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 27U) + RotL64(aIngress, 47U)) + (RotL64(aPrevious, 60U) ^ RotL64(aCross, 11U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = (aWandererB + RotL64(aIngress, 23U)) + 964165145848253292U;
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 13U)) + RotL64(aCarry, 13U)) + 10645976767204934746U;
            aOrbiterI = (aWandererH + RotL64(aCross, 57U)) + 8241612229349212650U;
            aOrbiterD = (aWandererG + RotL64(aPrevious, 50U)) + 4159196033256913347U;
            aOrbiterA = ((aWandererF + RotL64(aCross, 21U)) + RotL64(aCarry, 21U)) + 7194795864620233507U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 41U)) + 7638928444536778384U) + aNonceWordC;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 11U)) + RotL64(aCarry, 5U)) + 11819105916503968109U;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 43U)) + 18052213302858186237U) + aPhaseFOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = (aWandererI + RotL64(aScatter, 3U)) + 8663575313970041570U;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 60U)) + 16644136720439299786U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = (aWandererJ + RotL64(aIngress, 47U)) + 16930316530442679864U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 16251107616988250593U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 7171986193609401665U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3543709971414550087U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 17885046834432626644U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 7757069274715713557U;
            aOrbiterB = RotL64((aOrbiterB * 15766885299397923879U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 2212805322061155615U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 6368539134638838822U;
            aOrbiterJ = RotL64((aOrbiterJ * 13383744883433594259U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 5264326094252925613U) + aNonceWordE;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 6126345334815012938U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17180934809764905307U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 13826731214018407061U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 6621261811613643620U;
            aOrbiterK = RotL64((aOrbiterK * 2823596473596114171U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 5964406317285863781U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 2167324450276308078U;
            aOrbiterH = RotL64((aOrbiterH * 1098346374733634905U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 16740710162977859724U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 8236083581048717923U) ^ aNonceWordK;
            aOrbiterE = RotL64((aOrbiterE * 4364887787000704039U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 13967473987446124012U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 5136051802217149813U;
            aOrbiterD = RotL64((aOrbiterD * 13997246005108872883U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 5842999397215390366U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 8621394946580065499U;
            aOrbiterF = RotL64((aOrbiterF * 11658023035736362355U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 18086875424872976900U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 7429246355923896047U;
            aOrbiterC = RotL64((aOrbiterC * 5077079237334961761U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 18123753993386959014U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 964165145848253292U;
            aOrbiterG = RotL64((aOrbiterG * 3178072569980307307U), 35U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 23U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 52U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 39U) + aOrbiterF) + RotL64(aOrbiterC, 53U)) + RotL64(aCarry, 27U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 18U) + RotL64(aOrbiterJ, 24U)) + aOrbiterA);
            aWandererF = aWandererF + (((RotL64(aIngress, 53U) + RotL64(aOrbiterB, 57U)) + aOrbiterE) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterH, 51U)) + aPhaseFWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 23U) + RotL64(aOrbiterF, 3U)) + aOrbiterD);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterF, 41U)) + aOrbiterJ);
            aWandererH = aWandererH + (((RotL64(aPrevious, 41U) + aOrbiterG) + RotL64(aOrbiterF, 39U)) + aNonceWordM);
            aWandererI = aWandererI ^ ((RotL64(aCross, 21U) + aOrbiterI) + RotL64(aOrbiterG, 11U));
            aWandererD = aWandererD + (((RotL64(aIngress, 3U) + RotL64(aOrbiterB, 19U)) + aOrbiterI) + aPhaseFWandererUpdateSaltF[((aIndex + 26U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 22U)) + aOrbiterJ);
            aWandererG = aWandererG + ((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterK, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 44U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 58U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 21U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordJ);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 17266U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 17534U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 18393U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneD[((aIndex + 17418U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aPrevious, 3U)) + (RotL64(aCarry, 21U) ^ RotL64(aIngress, 52U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = ((aWandererA + RotL64(aCross, 57U)) + RotL64(aCarry, 57U)) + 4179952823252098240U;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 51U)) + 3745613452332101749U;
            aOrbiterB = ((((aWandererG + RotL64(aScatter, 34U)) + RotL64(aCarry, 41U)) + 2955689793395307176U) + aPhaseFOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 41U)) + RotL64(aCarry, 47U)) + 5639060180251322019U;
            aOrbiterD = ((aWandererI + RotL64(aCross, 13U)) + 7901969163853586463U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = (aWandererD + RotL64(aPrevious, 3U)) + 2242166787816318119U;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 26U)) + 5239936443960750064U;
            aOrbiterG = (aWandererC + RotL64(aIngress, 23U)) + 13939136954732185558U;
            aOrbiterH = (aWandererB + RotL64(aPrevious, 5U)) + 17058884136712717463U;
            aOrbiterF = (aWandererF + RotL64(aScatter, 29U)) + 18148618660054585941U;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 11U)) + 7022023484530327814U) + aNonceWordK;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 7722084537340095637U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 11764151879690934182U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12264384877711365655U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 16412785901758144708U) + aNonceWordP;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 9666718667728274824U;
            aOrbiterD = RotL64((aOrbiterD * 10865799822751771795U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 4307127540152109364U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 2457646804702647606U;
            aOrbiterE = RotL64((aOrbiterE * 6340030928007058595U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 3179394870088602208U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 504977947273774249U;
            aOrbiterJ = RotL64((aOrbiterJ * 16190282058883481551U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 16182729401018310837U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 7110817020445860609U;
            aOrbiterG = RotL64((aOrbiterG * 13371352088428584087U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 12960656706837391973U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 7103806893724395904U;
            aOrbiterH = RotL64((aOrbiterH * 14365984439655979791U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 1248300178080633527U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 7195473175424961337U;
            aOrbiterF = RotL64((aOrbiterF * 4633558992739305045U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 13007951568242991449U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 10296811247653636372U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16469682651380549395U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 13922797949001028335U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 16773545425463040155U) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 10639282630227832397U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 2888887140296117803U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 10279517418046269817U;
            aOrbiterC = RotL64((aOrbiterC * 8600355360339461535U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 17303373436784809093U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 4179952823252098240U;
            aOrbiterA = RotL64((aOrbiterA * 3675754609699406437U), 29U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterG, 14U);
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterE, 39U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 26U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aIngress, 19U) + aOrbiterG) + RotL64(aOrbiterC, 57U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterI, 39U)) + aOrbiterJ) + aNonceWordD);
            aWandererC = aWandererC + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterI, 42U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 34U) + RotL64(aOrbiterI, 23U)) + aOrbiterG) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterK, 51U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterH, 19U)) + aOrbiterF);
            aWandererK = aWandererK + (((RotL64(aCross, 21U) + RotL64(aOrbiterA, 26U)) + aOrbiterG) + RotL64(aCarry, 53U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 39U) + aOrbiterC) + RotL64(aOrbiterE, 29U)) + aNonceWordG);
            aWandererA = aWandererA + ((((RotL64(aIngress, 54U) + aOrbiterD) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 43U)) + aPhaseFWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterB, 37U)) + aOrbiterK);
            aWandererD = aWandererD + (((RotL64(aScatter, 11U) + RotL64(aOrbiterK, 11U)) + aOrbiterE) + aNonceWordI);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 24U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 12U));
            aCarry = aCarry + RotL64(aWandererC, 27U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 24179U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24831U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 25753U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25752U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aIngress, 21U)) ^ (RotL64(aPrevious, 51U) + RotL64(aCarry, 6U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = (aWandererJ + RotL64(aScatter, 29U)) + 11521331427196538632U;
            aOrbiterH = ((aWandererG + RotL64(aCross, 21U)) + RotL64(aCarry, 39U)) + 16653824187682957632U;
            aOrbiterB = (aWandererH + RotL64(aPrevious, 57U)) + 11654676587350088289U;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 47U)) + 8010313317412193584U) + aNonceWordJ;
            aOrbiterD = ((aWandererB + RotL64(aCross, 60U)) + 1108775560502907471U) + aNonceWordH;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 23U)) + RotL64(aCarry, 47U)) + 243952321439823521U;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 43U)) + 2324945800401240403U) + aPhaseFOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = (aWandererD + RotL64(aIngress, 11U)) + 9257554497543369657U;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 41U)) + 16701314607244592540U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aIngress, 53U)) + RotL64(aCarry, 11U)) + 3900445848034341782U;
            aOrbiterG = (aWandererA + RotL64(aCross, 26U)) + 7652316487347103658U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 14980368605272070578U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 2001165460948764796U) ^ aNonceWordL;
            aOrbiterB = RotL64((aOrbiterB * 8110980921827107649U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 1911044015666991050U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 11366207111147818339U;
            aOrbiterK = RotL64((aOrbiterK * 17234439040652553865U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 16469329744002456607U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 8062793687044950815U;
            aOrbiterE = RotL64((aOrbiterE * 5856142259851144369U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 15364721421972807872U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 8979915611483540231U;
            aOrbiterF = RotL64((aOrbiterF * 10899377466171153383U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 7654234623563110457U) + aNonceWordF;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 1526832460342135008U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12766083052650723051U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 1596625448797520938U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 15723912914858523080U;
            aOrbiterA = RotL64((aOrbiterA * 6003857787643420337U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 7664226719746532168U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 13767298788411473401U;
            aOrbiterJ = RotL64((aOrbiterJ * 15663266144965532019U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 8371251860069346385U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 10143279934304029980U;
            aOrbiterC = RotL64((aOrbiterC * 12764966547132248131U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 10034920090729616747U) + aNonceWordO;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 14450253491131954914U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15877567779079226909U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 9450697155749555210U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 14051719612902917300U;
            aOrbiterH = RotL64((aOrbiterH * 7659810299163085295U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 659383614060726993U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 11521331427196538632U;
            aOrbiterD = RotL64((aOrbiterD * 1068009283450923005U), 23U);
            //
            aIngress = RotL64(aOrbiterH, 10U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterA, 37U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterI, 39U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 41U)) + aOrbiterF);
            aWandererI = aWandererI + ((((RotL64(aCross, 21U) + aOrbiterA) + RotL64(aOrbiterH, 34U)) + RotL64(aCarry, 23U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 34U) + aOrbiterD) + RotL64(aOrbiterC, 19U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterI, 37U)) + aOrbiterH) + aPhaseFWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 27U)) + aOrbiterD);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 41U) + aOrbiterA) + RotL64(aOrbiterJ, 5U));
            aWandererB = aWandererB + ((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 53U)) + aOrbiterK);
            aWandererH = aWandererH ^ ((RotL64(aCross, 53U) + aOrbiterA) + RotL64(aOrbiterG, 51U));
            aWandererE = aWandererE + (((RotL64(aIngress, 5U) + RotL64(aOrbiterJ, 30U)) + aOrbiterB) + aNonceWordE);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 10U) + RotL64(aOrbiterA, 39U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererK, 34U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + RotL64(aWandererC, 6U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordB;
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28816U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((aIndex + 30209U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28225U)) & S_BLOCK1], 34U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29791U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 11U)) + (RotL64(aIngress, 41U) + RotL64(aCross, 56U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = (((aWandererK + RotL64(aPrevious, 19U)) + RotL64(aCarry, 43U)) + 3236820517816085022U) + aNonceWordG;
            aOrbiterE = ((aWandererI + RotL64(aCross, 41U)) + 741288875914097926U) + aNonceWordA;
            aOrbiterG = (aWandererC + RotL64(aScatter, 3U)) + 8417246926007729580U;
            aOrbiterI = (aWandererH + RotL64(aIngress, 13U)) + 9715717805774537170U;
            aOrbiterK = (aWandererF + RotL64(aCross, 51U)) + 14360243844821619482U;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 43U)) + 10760908100206775334U) + aPhaseFOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (((aWandererG + RotL64(aScatter, 34U)) + RotL64(aCarry, 53U)) + 3434641779946167811U) + aNonceWordD;
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 21U)) + 7885568822756234567U) + aPhaseFOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aScatter, 29U)) + 3041563437672051294U;
            aOrbiterA = ((aWandererA + RotL64(aIngress, 57U)) + RotL64(aCarry, 57U)) + 15761355327564963516U;
            aOrbiterJ = (aWandererD + RotL64(aCross, 54U)) + 1158633562785937421U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 9338581575871970653U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 9172038894262857354U;
            aOrbiterG = RotL64((aOrbiterG * 3110871165285625807U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 14653924713599790081U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 3854497592598563309U;
            aOrbiterK = RotL64((aOrbiterK * 11737111068815795303U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 16286980180327600557U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 5092583772591249756U;
            aOrbiterB = RotL64((aOrbiterB * 13955105624639442903U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 4288397994175567333U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 15584236478994873104U;
            aOrbiterD = RotL64((aOrbiterD * 1860480595862755379U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 5557463939827483792U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 2659814275753280856U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17702430405693184643U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 6941807963525063449U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 2040598555191211307U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14750544987531722765U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 347572666231116258U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 779304821185302523U;
            aOrbiterA = RotL64((aOrbiterA * 14180254150318109855U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 10632524582873079742U) + aNonceWordO;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 9761308771280517212U;
            aOrbiterJ = RotL64((aOrbiterJ * 13926235411726048921U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 2097439707055737964U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 2813977930321463948U;
            aOrbiterH = RotL64((aOrbiterH * 14983538728730662603U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 6080592019313796689U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 5396623654821376409U;
            aOrbiterE = RotL64((aOrbiterE * 15478858835919398677U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 8460497459575045342U) + aNonceWordB;
            aOrbiterI = (((aOrbiterI ^ aOrbiterJ) ^ 3236820517816085022U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 5530411244458067093U), 13U);
            //
            aIngress = RotL64(aOrbiterA, 27U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterK, 14U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aIngress, 19U) + RotL64(aOrbiterJ, 21U)) + aOrbiterI);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 53U) + aOrbiterD) + RotL64(aOrbiterA, 10U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 34U) + RotL64(aOrbiterE, 51U)) + aOrbiterF);
            aWandererG = aWandererG ^ ((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterA, 19U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 43U) + aOrbiterA) + RotL64(aOrbiterE, 43U)) + aNonceWordM) + aPhaseFWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterG, 13U)) + aOrbiterK);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterF, 3U)) + aOrbiterH) + RotL64(aCarry, 37U)) + aNonceWordF);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 47U) + aOrbiterB) + RotL64(aOrbiterJ, 24U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 26U) + RotL64(aOrbiterC, 41U)) + aOrbiterE);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 51U) + aOrbiterH) + RotL64(aOrbiterK, 35U));
            aWandererH = aWandererH + (((RotL64(aScatter, 11U) + aOrbiterI) + RotL64(aOrbiterE, 37U)) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 54U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 28U));
            aCarry = aCarry + RotL64(aWandererJ, 5U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordD);
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

void TwistExpander_Karate_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 7596U)) & S_BLOCK1], 54U) ^ RotL64(aKeyRowReadA[((aIndex + 4119U)) & W_KEY1], 37U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 206U)) & W_KEY1], 57U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6710U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 27U) + RotL64(aCross, 56U)) ^ (RotL64(aCarry, 11U) ^ RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = ((aWandererK + RotL64(aIngress, 19U)) + RotL64(aCarry, 39U)) + 12122689833405846292U;
            aOrbiterF = ((aWandererD + RotL64(aCross, 13U)) + 9640400270962766788U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (((aWandererF + RotL64(aScatter, 5U)) + RotL64(aCarry, 21U)) + 9141937998266739071U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 52U)) + 12899395770434090537U;
            aOrbiterE = (aWandererH + RotL64(aCross, 35U)) + 13457918115408031842U;
            aOrbiterC = (aWandererJ + RotL64(aScatter, 57U)) + 15134784483576000943U;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 27U)) + RotL64(aCarry, 13U)) + 12540961268790055438U;
            aOrbiterH = (aWandererC + RotL64(aIngress, 46U)) + 6306886773092764230U;
            aOrbiterD = (aWandererI + RotL64(aPrevious, 39U)) + 13573343491337243121U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 8545588657348974413U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 10891410570357275120U;
            aOrbiterI = RotL64((aOrbiterI * 5399310978367842841U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 2877137119767060151U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 9178097682386595144U;
            aOrbiterC = RotL64((aOrbiterC * 3524486002084427513U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 15528007881855616978U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 11368419529245281435U;
            aOrbiterH = RotL64((aOrbiterH * 12433207037378339309U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 5932738914934356645U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 5551842263864055419U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16093776759971522681U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 3824433359595690603U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 17184628855571662441U;
            aOrbiterB = RotL64((aOrbiterB * 691208053136187317U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 8724462245014132623U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 7481349499528092352U;
            aOrbiterJ = RotL64((aOrbiterJ * 8212182934509617583U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 6908362960248294718U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 5354057969992655314U;
            aOrbiterA = RotL64((aOrbiterA * 16586084885820679343U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 11138301629323903147U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 14164180536320940750U;
            aOrbiterF = RotL64((aOrbiterF * 9099767681053390287U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 709942920176922902U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 17128241237359414945U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14063385518459963529U), 19U);
            //
            aIngress = RotL64(aOrbiterH, 57U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 6U));
            aIngress = aIngress + RotL64(aOrbiterB, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aCross, 3U) + RotL64(aOrbiterD, 29U)) + aOrbiterF);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 10U) + aOrbiterE) + RotL64(aOrbiterF, 57U));
            aWandererK = aWandererK + (((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterA, 47U)) + aPhaseCWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 35U) + aOrbiterF) + RotL64(aOrbiterH, 23U));
            aWandererG = aWandererG + (((RotL64(aIngress, 39U) + RotL64(aOrbiterC, 4U)) + aOrbiterB) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterH, 19U)) + aOrbiterE);
            aWandererF = aWandererF + (((RotL64(aPrevious, 30U) + aOrbiterJ) + RotL64(aOrbiterI, 43U)) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 37U)) + aOrbiterC) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterI, 12U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 21U));
            aCarry = aCarry + (RotL64(aWandererG, 14U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererF, 35U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 14706U)) & S_BLOCK1], 21U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 16028U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 12026U)) & W_KEY1], 12U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 8800U)) & W_KEY1], 43U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aPrevious, 11U)) ^ (RotL64(aCarry, 23U) + RotL64(aIngress, 56U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 19U)) + 2915859148137000694U) + aPhaseCOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 53U)) + RotL64(aCarry, 37U)) + 210680583721444425U;
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 29U)) + RotL64(aCarry, 23U)) + 6668118118775650387U;
            aOrbiterC = (((aWandererK + RotL64(aCross, 44U)) + RotL64(aCarry, 47U)) + 15794200818099010989U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = (aWandererH + RotL64(aPrevious, 57U)) + 6565076707062828369U;
            aOrbiterK = (aWandererG + RotL64(aScatter, 39U)) + 16323164497808856719U;
            aOrbiterF = (aWandererE + RotL64(aCross, 35U)) + 7965435318816716560U;
            aOrbiterB = (aWandererA + RotL64(aIngress, 5U)) + 7390281030573369017U;
            aOrbiterI = (aWandererF + RotL64(aScatter, 24U)) + 2269738866911824875U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 9664014216039993873U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 18284857398028357633U;
            aOrbiterG = RotL64((aOrbiterG * 8402008251343393737U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 367667619795303009U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 7935945060956274197U;
            aOrbiterD = RotL64((aOrbiterD * 5481786693511955209U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 16683666162337789540U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 10655658270998102390U;
            aOrbiterF = RotL64((aOrbiterF * 15231596813382239841U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 8307037916581540297U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 3247742749860703524U;
            aOrbiterB = RotL64((aOrbiterB * 15052136713218656641U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 10446792483683818139U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 16374602929344972364U;
            aOrbiterI = RotL64((aOrbiterI * 12599903932725787599U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 2411334498322777183U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 1093701164116833765U;
            aOrbiterJ = RotL64((aOrbiterJ * 13129220206835381729U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 17018480952982840635U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 17348395690080029814U;
            aOrbiterC = RotL64((aOrbiterC * 6212591395713433257U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 16111252311283623152U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 12776492920397785951U;
            aOrbiterK = RotL64((aOrbiterK * 6136009241593081821U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 12214538600808144816U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 10043377462096783363U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14639467375095185877U), 39U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterE, 29U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterB, 6U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterF, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aScatter, 39U) + aOrbiterI) + RotL64(aOrbiterC, 11U)) + aPhaseCWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterD, 27U)) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 54U) + RotL64(aOrbiterJ, 58U)) + aOrbiterF);
            aWandererA = aWandererA + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 43U)) + aOrbiterK) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterE, 3U)) + aOrbiterB);
            aWandererF = aWandererF + ((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterJ, 47U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterC, 19U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 24U) + RotL64(aOrbiterB, 34U)) + aOrbiterK) + RotL64(aCarry, 35U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterK, 51U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 38U));
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + RotL64(aWandererB, 56U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23361U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneA[((aIndex + 18316U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 23996U)) & W_KEY1], 54U) ^ RotL64(aKeyRowReadB[((aIndex + 22453U)) & W_KEY1], 3U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 28U) + RotL64(aCross, 5U)) + (RotL64(aCarry, 57U) ^ RotL64(aIngress, 43U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = (aWandererH + RotL64(aIngress, 47U)) + 7825479804710770560U;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 53U)) + RotL64(aCarry, 13U)) + 5298124167101358123U;
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 10U)) + RotL64(aCarry, 53U)) + 17774541024369233726U;
            aOrbiterH = ((aWandererD + RotL64(aCross, 27U)) + 7679371833537454082U) + aPhaseCOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = (aWandererI + RotL64(aScatter, 37U)) + 5385914900748772224U;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 57U)) + 3879781930908486531U;
            aOrbiterD = (aWandererC + RotL64(aCross, 23U)) + 659110346638873236U;
            aOrbiterA = (((aWandererJ + RotL64(aIngress, 42U)) + RotL64(aCarry, 23U)) + 10749021728538539749U) + aPhaseCOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (aWandererG + RotL64(aPrevious, 5U)) + 3631252455767429457U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 2271978810960685021U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 5963558780692551176U;
            aOrbiterC = RotL64((aOrbiterC * 4772055335210781149U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 974909966119198104U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 9296998242911152296U;
            aOrbiterB = RotL64((aOrbiterB * 2613629915877957661U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 2245318466901521959U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 13391076374843288568U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 18094558036982107419U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 6184487746594236737U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 1563385912137291418U;
            aOrbiterI = RotL64((aOrbiterI * 4805455299959232321U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 1744840092006498629U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 2100927276837188416U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3541788262067077997U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 9998911862807246338U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 12239948725635220096U;
            aOrbiterJ = RotL64((aOrbiterJ * 7098620484129489129U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 3307447094994950246U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 12746613971448298932U;
            aOrbiterD = RotL64((aOrbiterD * 9463975886346934681U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 11577488293733790649U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 191108997585598809U;
            aOrbiterA = RotL64((aOrbiterA * 9574978681405356871U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 18096145693841273722U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 10026281133603934071U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17261343107314203471U), 53U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 27U);
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 40U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterH, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aIngress, 34U) + RotL64(aOrbiterA, 37U)) + aOrbiterK) + aPhaseCWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterC, 57U)) + aOrbiterB);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 42U)) + aOrbiterC);
            aWandererH = aWandererH + (((RotL64(aCross, 53U) + RotL64(aOrbiterH, 23U)) + aOrbiterA) + RotL64(aCarry, 57U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 27U) + aOrbiterD) + RotL64(aOrbiterA, 47U));
            aWandererB = aWandererB + ((RotL64(aCross, 60U) + RotL64(aOrbiterK, 5U)) + aOrbiterI);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 19U) + aOrbiterC) + RotL64(aOrbiterA, 19U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterG, 52U)) + aOrbiterB) + RotL64(aCarry, 47U)) + aPhaseCWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterJ, 29U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 60U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 43U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 27659U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((aIndex + 27744U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29051U)) & S_BLOCK1], 48U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 28350U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 29U) + RotL64(aPrevious, 42U)) ^ (RotL64(aCarry, 57U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = (aWandererE + RotL64(aScatter, 43U)) + 18319689184146942855U;
            aOrbiterE = (aWandererB + RotL64(aCross, 39U)) + 8041304130090501019U;
            aOrbiterD = (aWandererG + RotL64(aIngress, 4U)) + 11347064191990897738U;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 11U)) + 15242243470024447468U;
            aOrbiterC = (((aWandererH + RotL64(aIngress, 29U)) + RotL64(aCarry, 37U)) + 10619749107163611105U) + aPhaseCOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = ((aWandererC + RotL64(aCross, 51U)) + 14795614276221947128U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 60U)) + RotL64(aCarry, 51U)) + 1578095288886372393U;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 21U)) + RotL64(aCarry, 11U)) + 13593906305770501684U;
            aOrbiterI = (aWandererI + RotL64(aCross, 35U)) + 8919815528334599172U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 17425548324720065145U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 11125018338392347335U;
            aOrbiterD = RotL64((aOrbiterD * 4377887040461528587U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 3779189180734244399U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 10958224663276134041U;
            aOrbiterC = RotL64((aOrbiterC * 6206963519509783781U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 4317305352561612995U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 4891139433808505355U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11507024985663120317U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 5166074784835930965U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 10080890270621589202U;
            aOrbiterJ = RotL64((aOrbiterJ * 13170894418184288695U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 4501071771615514619U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 6486573807774431753U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 324029625116648669U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 15714881857668975753U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 3506619392820235900U;
            aOrbiterB = RotL64((aOrbiterB * 5707033870161224499U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 5295711072762443783U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 11192836530396570648U;
            aOrbiterA = RotL64((aOrbiterA * 4361810118382207039U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 7993389678399774574U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 12551394763541226695U;
            aOrbiterI = RotL64((aOrbiterI * 11903486656172026403U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 11553674370322129668U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 4459881583199320245U;
            aOrbiterE = RotL64((aOrbiterE * 2805857426321555685U), 47U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterE, 54U);
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 36U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aCross, 60U) + RotL64(aOrbiterB, 43U)) + aOrbiterE);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 19U) + aOrbiterA) + RotL64(aOrbiterJ, 30U)) + aPhaseCWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 53U) + RotL64(aOrbiterB, 53U)) + aOrbiterJ) + RotL64(aCarry, 29U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterC, 5U)) + aOrbiterA);
            aWandererI = aWandererI + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterD, 57U)) + aOrbiterE) + aPhaseCWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 46U) + aOrbiterI) + RotL64(aOrbiterF, 39U));
            aWandererK = aWandererK + ((RotL64(aCross, 5U) + aOrbiterK) + RotL64(aOrbiterB, 47U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 19U)) + aOrbiterA);
            aWandererC = aWandererC + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterA, 10U)) + aOrbiterI) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + RotL64(aWandererB, 50U);
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

void TwistExpander_Karate_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 5431U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7723U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 388U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 7260U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 19U) ^ RotL64(aPrevious, 35U)) ^ (RotL64(aCarry, 47U) + RotL64(aIngress, 60U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = (aWandererI + RotL64(aIngress, 57U)) + 1457104756581596530U;
            aOrbiterG = (((aWandererK + RotL64(aScatter, 23U)) + RotL64(aCarry, 3U)) + 6127240317844622874U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = (((aWandererD + RotL64(aPrevious, 3U)) + RotL64(aCarry, 29U)) + 16492290056044189421U) + aPhaseDOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aCross, 37U)) + RotL64(aCarry, 47U)) + 10963676850938416468U;
            aOrbiterE = (aWandererG + RotL64(aPrevious, 12U)) + 4872917367399752405U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 15218882377875616148U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 5934166612122118251U;
            aOrbiterI = RotL64((aOrbiterI * 10365045124180379919U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 14215280930872003003U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 11428034799044600979U;
            aOrbiterH = RotL64((aOrbiterH * 12162528943733976177U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 5453003654321728726U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 14273775120265649389U;
            aOrbiterA = RotL64((aOrbiterA * 5139018128323795309U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 328723770018440271U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 13032190719588211088U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13363368478932798315U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 2386881543033598494U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 1649501123340887116U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11148976582360499033U), 47U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 57U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + RotL64(aOrbiterH, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 3U) + RotL64(aOrbiterE, 50U)) + aOrbiterI) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 11U) + aOrbiterA) + RotL64(aOrbiterG, 13U)) + aPhaseDWandererUpdateSaltD[((aIndex + 26U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 19U) + RotL64(aOrbiterH, 5U)) + aOrbiterE) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterA, 29U)) + aPhaseDWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 56U) + aOrbiterG) + RotL64(aOrbiterE, 41U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 3U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 12718U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneD[((aIndex + 8857U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10232U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneB[((aIndex + 10120U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 37U) + RotL64(aIngress, 54U)) + (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 53U)) + 17470880031634374199U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aCross, 3U)) + RotL64(aCarry, 3U)) + 757565846006937746U;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 41U)) + RotL64(aCarry, 53U)) + 9419282475801345674U;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 11U)) + 2014248014107898196U) + aPhaseDOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 26U)) + RotL64(aCarry, 23U)) + 15113928519446490441U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 7346126964886259935U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 5594123113093162359U;
            aOrbiterE = RotL64((aOrbiterE * 18043634828891483403U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 5659237263369402005U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 11565709683423969703U;
            aOrbiterC = RotL64((aOrbiterC * 16731289017588574671U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 16782863743534856287U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 13499100900072115907U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5567729598873214433U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 11414447651044205242U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 7545993795121430538U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10758488381206257261U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 11778229237616454988U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 2544793391976514665U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4021060413798523299U), 13U);
            //
            aIngress = RotL64(aOrbiterG, 37U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + RotL64(aOrbiterE, 58U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 23U) + aOrbiterD) + RotL64(aOrbiterG, 39U)) + aPhaseDWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterF, 5U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 58U) + aOrbiterD) + RotL64(aOrbiterE, 48U)) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterC, 19U)) + aOrbiterE);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 29U)) + aOrbiterC) + RotL64(aCarry, 43U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 56U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 19092U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 17467U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17935U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 24117U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 54U) + RotL64(aIngress, 5U)) + (RotL64(aCross, 23U) ^ RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = ((aWandererD + RotL64(aScatter, 29U)) + 13350544654542863236U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 47U)) + RotL64(aCarry, 27U)) + 12364346790125404372U;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 5U)) + RotL64(aCarry, 43U)) + 9738750172849512764U;
            aOrbiterI = (((aWandererH + RotL64(aCross, 39U)) + RotL64(aCarry, 3U)) + 3781373837635491421U) + aPhaseDOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aScatter, 20U)) + 16635020317512702337U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 5383653921676231276U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 10181959815492056493U;
            aOrbiterD = RotL64((aOrbiterD * 14784636206508715141U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 10005510924273927017U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 9524687662265740565U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13687380438646756931U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 4259138552009771014U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 8973051213213726023U;
            aOrbiterB = RotL64((aOrbiterB * 12625091476068190979U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 17602611840127337490U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 8218984546932905269U;
            aOrbiterI = RotL64((aOrbiterI * 17504305273683304231U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 18102186122213487888U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 2629927500298092976U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6983280164448292723U), 29U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterD, 5U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + RotL64(aOrbiterI, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 38U) + RotL64(aOrbiterA, 19U)) + aOrbiterI) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 53U) + aOrbiterD) + RotL64(aOrbiterA, 29U)) + aPhaseDWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterE, 39U)) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterE, 51U)) + aOrbiterD) + aPhaseDWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 13U) + aOrbiterB) + RotL64(aOrbiterI, 60U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + RotL64(aWandererB, 5U);
            aCarry = aCarry + RotL64(aIngress, 48U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 28475U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((aIndex + 31299U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 32760U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((aIndex + 24755U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 19U) + RotL64(aIngress, 5U)) + (RotL64(aPrevious, 39U) ^ RotL64(aCross, 56U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 3U)) + 10726035965553989335U;
            aOrbiterK = (((aWandererA + RotL64(aScatter, 19U)) + RotL64(aCarry, 37U)) + 967354339530195662U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = (aWandererD + RotL64(aIngress, 41U)) + 10834593005478605624U;
            aOrbiterA = (((aWandererE + RotL64(aCross, 29U)) + RotL64(aCarry, 13U)) + 1012888282838656933U) + aPhaseDOrbiterAssignSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 58U)) + RotL64(aCarry, 57U)) + 15283530351725183253U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 11724495956731703750U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 4288330117317505776U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2738997410474076757U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 10894778070022873473U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 15563886747621617467U;
            aOrbiterJ = RotL64((aOrbiterJ * 17884709931569040065U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 11182488628562891937U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 10420140066310588580U;
            aOrbiterA = RotL64((aOrbiterA * 13898299782819948719U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 11775138062167543111U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 16545391898578161683U;
            aOrbiterK = RotL64((aOrbiterK * 14588306527161321535U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 1550144656312299266U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 14903504853138279883U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8003033561266164387U), 51U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterB, 47U);
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterK, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 3U) + aOrbiterK) + RotL64(aOrbiterB, 19U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterK, 27U)) + aOrbiterJ) + RotL64(aCarry, 5U)) + aPhaseDWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 34U) + aOrbiterB) + RotL64(aOrbiterA, 43U));
            aWandererD = aWandererD + ((RotL64(aIngress, 23U) + aOrbiterG) + RotL64(aOrbiterA, 6U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererD, 56U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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

void TwistExpander_Karate_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterI = 0;
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 1016U)) & S_BLOCK1], 24U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 229U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6961U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneA[((aIndex + 5735U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCarry, 54U)) + (RotL64(aIngress, 41U) ^ RotL64(aCross, 29U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = (aWandererD + RotL64(aCross, 35U)) + 17454559218352016650U;
            aOrbiterF = (aWandererB + RotL64(aPrevious, 58U)) + 8005709669325164803U;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 43U)) + 13393741948412816357U) + aPhaseEOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = ((aWandererG + RotL64(aIngress, 27U)) + 3665865624348875553U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = ((aWandererI + RotL64(aCross, 5U)) + RotL64(aCarry, 51U)) + 8334142570031883436U;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 19U)) + RotL64(aCarry, 23U)) + 17226066128706139657U;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 5U)) + 3319093033121522613U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 6657535603401588798U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 5469746182326331147U;
            aOrbiterD = RotL64((aOrbiterD * 11315450342347794329U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 17846791786050221418U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 15939541003714896288U;
            aOrbiterE = RotL64((aOrbiterE * 1400351482213119809U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 12076763190461077406U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 3594038213596405284U;
            aOrbiterA = RotL64((aOrbiterA * 10244002692575821495U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 8301291631324464622U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 8460406137668390582U;
            aOrbiterJ = RotL64((aOrbiterJ * 9117147929757711595U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 7612394867020871200U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 8525076134853103975U;
            aOrbiterK = RotL64((aOrbiterK * 5790440201072204659U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 11929899088215090379U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 7119509166360685726U;
            aOrbiterC = RotL64((aOrbiterC * 1662341427992528823U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 5081078459225240607U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 17149991983909906705U;
            aOrbiterF = RotL64((aOrbiterF * 950223374568067343U), 51U);
            //
            aIngress = RotL64(aOrbiterC, 56U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 21U));
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterC, 51U)) + aOrbiterJ);
            aWandererE = aWandererE + (((RotL64(aScatter, 35U) + aOrbiterK) + RotL64(aOrbiterF, 19U)) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterD, 43U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 56U) + RotL64(aOrbiterC, 58U)) + aOrbiterD) + RotL64(aCarry, 27U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 41U) + aOrbiterF) + RotL64(aOrbiterE, 27U)) + aPhaseEWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 19U) + aOrbiterK) + RotL64(aOrbiterA, 37U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 3U) + aOrbiterK) + RotL64(aOrbiterE, 13U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (RotL64(aWandererC, 22U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + RotL64(aWandererD, 35U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8622U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 9344U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 15028U)) & S_BLOCK1], 24U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 15379U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 29U) + RotL64(aPrevious, 41U)) ^ (RotL64(aCross, 13U) ^ RotL64(aIngress, 60U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = ((aWandererB + RotL64(aScatter, 11U)) + 16424657151168221875U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 57U)) + RotL64(aCarry, 19U)) + 17150123681886380361U;
            aOrbiterG = (aWandererA + RotL64(aIngress, 37U)) + 16041993588694572757U;
            aOrbiterJ = ((aWandererH + RotL64(aCross, 29U)) + RotL64(aCarry, 47U)) + 9871185846434828537U;
            aOrbiterK = (((aWandererK + RotL64(aScatter, 4U)) + RotL64(aCarry, 35U)) + 11227236398354430757U) + aPhaseEOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = (aWandererG + RotL64(aIngress, 23U)) + 5399325217402192631U;
            aOrbiterD = (aWandererD + RotL64(aPrevious, 51U)) + 9248828789282890454U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 9041370494203701062U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 14944424084524970764U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10283363059424655079U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 5481938174456671041U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 14783648629543752715U;
            aOrbiterE = RotL64((aOrbiterE * 7260164783191886395U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 12355573914530445723U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 9863991559011968318U;
            aOrbiterJ = RotL64((aOrbiterJ * 8495251211794343179U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 16149688605937250965U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 106041828692026825U;
            aOrbiterC = RotL64((aOrbiterC * 12199934305374582599U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 8076098639554567792U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 11155119311895580013U;
            aOrbiterK = RotL64((aOrbiterK * 1495180896564818647U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 6847612160595917702U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 16094377920388017367U;
            aOrbiterA = RotL64((aOrbiterA * 4875801863643206333U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 13584719866672696684U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 13446209321646234607U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9945349065094781529U), 29U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterA, 27U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 50U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + RotL64(aOrbiterD, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 41U) + aOrbiterA) + RotL64(aOrbiterK, 57U));
            aWandererK = aWandererK + ((((RotL64(aCross, 27U) + RotL64(aOrbiterA, 37U)) + aOrbiterG) + RotL64(aCarry, 35U)) + aPhaseEWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterD, 12U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 53U) + RotL64(aOrbiterJ, 21U)) + aOrbiterG) + RotL64(aCarry, 53U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 4U) + aOrbiterJ) + RotL64(aOrbiterC, 5U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 35U) + aOrbiterA) + RotL64(aOrbiterE, 51U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 13U) + aOrbiterK) + RotL64(aOrbiterC, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 52U));
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 17744U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17171U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 16921U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 18897U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 27U) + RotL64(aCross, 10U)) ^ (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = (aWandererI + RotL64(aCross, 35U)) + 13687218104610230596U;
            aOrbiterD = (aWandererD + RotL64(aScatter, 19U)) + 6841550124960692709U;
            aOrbiterG = (aWandererC + RotL64(aIngress, 13U)) + 17418968668458764131U;
            aOrbiterB = (((aWandererA + RotL64(aPrevious, 56U)) + RotL64(aCarry, 43U)) + 8303537912696948204U) + aPhaseEOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 41U)) + RotL64(aCarry, 19U)) + 12376614417285936537U;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 29U)) + 14215749063579232654U;
            aOrbiterK = (((aWandererH + RotL64(aScatter, 5U)) + RotL64(aCarry, 3U)) + 4111736931433665347U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 11250375934571631522U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 5367367837773331275U;
            aOrbiterG = RotL64((aOrbiterG * 7262723007545807179U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 15514089192382674434U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 1475991716685034960U;
            aOrbiterD = RotL64((aOrbiterD * 17720681295551650891U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 5531622777788629748U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 8363822215908303335U;
            aOrbiterI = RotL64((aOrbiterI * 17850203366840994883U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 3741256932685720414U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 11634667238062155772U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15925089729784547403U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 18180546911210417155U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 5123234656838556335U;
            aOrbiterC = RotL64((aOrbiterC * 15362857462853398025U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 11215734271189250284U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 16863747802158398092U;
            aOrbiterJ = RotL64((aOrbiterJ * 1828035970246160023U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 9859050606636646323U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 9331300036643654675U;
            aOrbiterK = RotL64((aOrbiterK * 2502263410556166281U), 51U);
            //
            aIngress = RotL64(aOrbiterB, 41U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterK, 21U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterI, 48U)) + aOrbiterG) + RotL64(aCarry, 37U)) + aPhaseEWandererUpdateSaltA[((aIndex + 8U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterG, 13U)) + aOrbiterJ);
            aWandererB = aWandererB + (((RotL64(aScatter, 41U) + RotL64(aOrbiterJ, 39U)) + aOrbiterK) + RotL64(aCarry, 21U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 54U) + RotL64(aOrbiterD, 21U)) + aOrbiterG);
            aWandererA = aWandererA + ((RotL64(aIngress, 35U) + aOrbiterB) + RotL64(aOrbiterC, 57U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 29U)) + aOrbiterK);
            aWandererD = aWandererD + (((RotL64(aCross, 11U) + RotL64(aOrbiterK, 3U)) + aOrbiterD) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 24U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 28340U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32367U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28391U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((aIndex + 29293U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 56U) + RotL64(aCarry, 39U)) ^ (RotL64(aIngress, 27U) ^ RotL64(aCross, 13U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = (aWandererG + RotL64(aIngress, 5U)) + 15036852811491820366U;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 11U)) + 305637140752898475U) + aPhaseEOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aCross, 35U)) + RotL64(aCarry, 23U)) + 11948631574496129610U;
            aOrbiterC = (((aWandererC + RotL64(aPrevious, 41U)) + RotL64(aCarry, 43U)) + 5321623592482991426U) + aPhaseEOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 24U)) + RotL64(aCarry, 5U)) + 4075270159062690728U;
            aOrbiterI = (aWandererD + RotL64(aCross, 51U)) + 15111580500356908928U;
            aOrbiterA = (aWandererI + RotL64(aPrevious, 57U)) + 7244150695504160363U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 5131563519577488862U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 5881954992088651371U;
            aOrbiterF = RotL64((aOrbiterF * 2424421828597294607U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 12780935808751507998U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 12599159643925470226U;
            aOrbiterI = RotL64((aOrbiterI * 17690046932587062701U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 9466589929741834066U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 6093158735705189789U;
            aOrbiterD = RotL64((aOrbiterD * 7453778295800853653U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 17461243886150519249U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 15456408913739900718U;
            aOrbiterG = RotL64((aOrbiterG * 16093292401746174671U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 11260643903290392780U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 7870342756041882616U;
            aOrbiterJ = RotL64((aOrbiterJ * 2431528656086173419U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 134484990005888936U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 10626896209992890407U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12034131076645285597U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 14031164129515132292U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 1771835705730244212U;
            aOrbiterA = RotL64((aOrbiterA * 186981668443596623U), 57U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterC, 35U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 54U));
            aIngress = aIngress + RotL64(aOrbiterG, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 51U)) + aOrbiterI);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterD, 30U)) + aPhaseEWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 42U) + RotL64(aOrbiterD, 43U)) + aOrbiterC) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterG, 11U)) + aOrbiterC);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 57U)) + aOrbiterA) + RotL64(aCarry, 47U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterJ, 23U));
            aWandererI = aWandererI + ((RotL64(aCross, 19U) + RotL64(aOrbiterD, 5U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 20U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + RotL64(aWandererA, 3U);
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

void TwistExpander_Karate_Arx::Twist_D(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2413U)) & S_BLOCK1], 42U) ^ RotL64(aExpandLaneC[((aIndex + 3973U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7933U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 7601U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 13U) + RotL64(aIngress, 44U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = ((aWandererA + RotL64(aCross, 11U)) + RotL64(aCarry, 11U)) + 898812731947995389U;
            aOrbiterB = (aWandererH + RotL64(aPrevious, 19U)) + 8677347622525527167U;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 42U)) + RotL64(aCarry, 23U)) + 770321564027567654U;
            aOrbiterI = (((aWandererE + RotL64(aScatter, 57U)) + RotL64(aCarry, 39U)) + 11020474858081526395U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 3U)) + 17289793580414993470U) + aPhaseFOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 10111912559295118444U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 8083622125544542011U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3610772128071340341U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 7149858558922988240U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 5919683821379905699U;
            aOrbiterH = RotL64((aOrbiterH * 16705119888884231567U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 6860902846079238714U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 15083517836867542075U;
            aOrbiterI = RotL64((aOrbiterI * 4686657139237578325U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 14852868368708376381U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 9860233289028878323U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13418143547952204667U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 772406119079116272U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 7971141501337627589U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10168120622976358617U), 3U);
            //
            aIngress = RotL64(aOrbiterB, 13U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterH, 52U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aCross, 27U) + aOrbiterI) + RotL64(aOrbiterH, 3U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 53U) + aOrbiterH) + RotL64(aOrbiterD, 11U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 3U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 12U) + RotL64(aOrbiterH, 58U)) + aOrbiterK);
            aWandererF = aWandererF + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterB, 27U)) + aOrbiterI) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 34U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 15043U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneD[((aIndex + 10052U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8881U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9401U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCarry, 13U)) + (RotL64(aCross, 26U) ^ RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = (((aWandererA + RotL64(aCross, 5U)) + RotL64(aCarry, 11U)) + 8793908991006073956U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = (((aWandererK + RotL64(aPrevious, 13U)) + RotL64(aCarry, 41U)) + 2932916283348441943U) + aPhaseFOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = ((aWandererB + RotL64(aIngress, 41U)) + RotL64(aCarry, 27U)) + 11069042087940968262U;
            aOrbiterE = (aWandererH + RotL64(aScatter, 56U)) + 14369628676782894441U;
            aOrbiterF = (aWandererF + RotL64(aCross, 29U)) + 8602903272780978282U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 3827036107178568820U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 8905245209036772489U;
            aOrbiterH = RotL64((aOrbiterH * 5744017326197157667U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 13331387530760017893U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 9880107580289737823U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10302652857542703753U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 10199619040626900278U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 2466307560891374281U;
            aOrbiterA = RotL64((aOrbiterA * 6295342978834217571U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 13973403407981259448U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 2851460278409385243U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11226902976321781743U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 10365453393815690776U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 2382382358987358791U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 481563628980705781U), 27U);
            //
            aIngress = RotL64(aOrbiterF, 57U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + RotL64(aOrbiterA, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 42U) + aOrbiterF) + RotL64(aOrbiterH, 3U)) + aPhaseFWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 57U) + RotL64(aOrbiterA, 39U)) + aOrbiterG) + RotL64(aCarry, 19U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 58U)) + aOrbiterH);
            aWandererK = aWandererK + (((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 13U)) + aOrbiterA) + RotL64(aCarry, 47U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterG, 21U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 30U));
            aCarry = aCarry + RotL64(aWandererB, 53U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 17181U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17566U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19834U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneC[((aIndex + 17477U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 52U) ^ RotL64(aIngress, 37U)) + (RotL64(aPrevious, 11U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = ((aWandererD + RotL64(aIngress, 5U)) + RotL64(aCarry, 5U)) + 1457104756581596530U;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 57U)) + RotL64(aCarry, 57U)) + 6127240317844622874U;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 39U)) + 16492290056044189421U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aCross, 13U)) + 10963676850938416468U;
            aOrbiterH = (((aWandererK + RotL64(aPrevious, 30U)) + RotL64(aCarry, 19U)) + 4872917367399752405U) + aPhaseFOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 15218882377875616148U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 5934166612122118251U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10365045124180379919U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 14215280930872003003U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 11428034799044600979U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12162528943733976177U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 5453003654321728726U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 14273775120265649389U;
            aOrbiterC = RotL64((aOrbiterC * 5139018128323795309U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 328723770018440271U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 13032190719588211088U;
            aOrbiterK = RotL64((aOrbiterK * 13363368478932798315U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 2386881543033598494U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 1649501123340887116U;
            aOrbiterH = RotL64((aOrbiterH * 11148976582360499033U), 13U);
            //
            aIngress = RotL64(aOrbiterD, 57U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 44U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 29U)) + aOrbiterK) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterH, 13U)) + aOrbiterD) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 13U) + aOrbiterC) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 53U)) + aPhaseFWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterJ, 56U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 24U) + RotL64(aOrbiterK, 41U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + RotL64(aWandererJ, 46U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 25711U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24913U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29707U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 28198U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCross, 13U)) ^ (RotL64(aIngress, 28U) + RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = (aWandererK + RotL64(aPrevious, 5U)) + 12206125048349568300U;
            aOrbiterA = (((aWandererJ + RotL64(aCross, 13U)) + RotL64(aCarry, 13U)) + 5843520589343188818U) + aPhaseFOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = (((aWandererI + RotL64(aScatter, 44U)) + RotL64(aCarry, 27U)) + 12195046124287121687U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = ((aWandererB + RotL64(aIngress, 53U)) + RotL64(aCarry, 47U)) + 16769779119214020640U;
            aOrbiterH = (aWandererE + RotL64(aPrevious, 27U)) + 5257603646260695833U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 8523523946234886745U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 7316024684200084096U;
            aOrbiterE = RotL64((aOrbiterE * 11620083021691341337U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 11996978575084115207U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 15491711479085513628U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15136690392026011819U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 6036648530996821484U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 926323222234121863U;
            aOrbiterG = RotL64((aOrbiterG * 6639661141258803779U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 2700323841295743492U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 5852273765810284935U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16665696735016345215U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 11697397483133538067U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 17777142964957007194U;
            aOrbiterH = RotL64((aOrbiterH * 6338967222543284999U), 19U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 35U);
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterI, 37U)) + aOrbiterA) + RotL64(aCarry, 37U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterE, 3U)) + aOrbiterG);
            aWandererK = aWandererK + ((RotL64(aCross, 21U) + aOrbiterH) + RotL64(aOrbiterI, 54U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 10U) + aOrbiterG) + RotL64(aOrbiterH, 21U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 11U)) + aOrbiterE) + RotL64(aCarry, 57U)) + aPhaseFWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + RotL64(aWandererI, 35U);
            aCarry = aCarry + RotL64(aIngress, 58U);
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

void TwistExpander_Karate_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 5580U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 7166U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6927U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 5569U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 13U) + RotL64(aIngress, 56U)) ^ (RotL64(aPrevious, 27U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = (((aWandererI + RotL64(aIngress, 42U)) + RotL64(aCarry, 19U)) + 7075016829833562104U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aScatter, 51U)) + RotL64(aCarry, 35U)) + 8783765886115517036U;
            aOrbiterD = (aWandererC + RotL64(aCross, 11U)) + 2996723892384565829U;
            aOrbiterB = (((aWandererD + RotL64(aPrevious, 27U)) + RotL64(aCarry, 57U)) + 9494134707342189476U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aCross, 3U)) + 5052642981395679904U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 8766787055127962238U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 4467211954388738079U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8599295330343804047U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 8030255604633658608U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 16962408063455702251U;
            aOrbiterJ = RotL64((aOrbiterJ * 11171737929747471631U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 3768222186567699076U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 14930990410207899871U;
            aOrbiterB = RotL64((aOrbiterB * 10930005786146268241U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 14179761938395502502U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 1879084742719898108U;
            aOrbiterH = RotL64((aOrbiterH * 16783034788172670121U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 5535012408925981515U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 12792553516710295939U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8577530993755159329U), 5U);
            //
            aIngress = RotL64(aOrbiterD, 30U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 11U) + aOrbiterB) + RotL64(aOrbiterH, 39U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 28U)) + aOrbiterJ) + RotL64(aCarry, 21U)) + aPhaseGWandererUpdateSaltC[((aIndex + 4U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 58U) + RotL64(aOrbiterJ, 13U)) + aOrbiterK);
            aWandererI = aWandererI + (((RotL64(aCross, 39U) + RotL64(aOrbiterD, 5U)) + aOrbiterJ) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 47U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 19U);
            aCarry = aCarry + RotL64(aIngress, 52U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 11732U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 14430U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8508U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9114U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCross, 39U)) + (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 18U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = (((aWandererC + RotL64(aCross, 3U)) + RotL64(aCarry, 27U)) + 15920462086654025436U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = ((aWandererK + RotL64(aIngress, 43U)) + 487844076858004017U) + aPhaseGOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (aWandererG + RotL64(aScatter, 35U)) + 14502883786442630566U;
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 12U)) + RotL64(aCarry, 43U)) + 3787107318658233674U;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 57U)) + RotL64(aCarry, 13U)) + 12548777544693755491U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 4907309444075181683U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 18342396700266492072U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14842961036061482089U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 13503051997624242670U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 17845742460521374571U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1366356786138085155U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 8640887211877858169U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 5273913123709097537U;
            aOrbiterH = RotL64((aOrbiterH * 1661149444148461791U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 17756844173695563883U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 6713055830729302951U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2832836748513174311U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 5106468334224035972U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 10228769728713526172U;
            aOrbiterE = RotL64((aOrbiterE * 9760310686414358435U), 57U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterK, 47U);
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 37U) + aOrbiterK) + RotL64(aOrbiterE, 10U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterG, 57U)) + aOrbiterE) + RotL64(aCarry, 53U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterK, 21U));
            aWandererB = aWandererB + ((((RotL64(aCross, 53U) + aOrbiterA) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 11U)) + aPhaseGWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 14U) + aOrbiterA) + RotL64(aOrbiterH, 41U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 60U));
            aCarry = aCarry + RotL64(aWandererK, 27U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 22611U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 23207U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 17125U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 22285U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 35U)) ^ (RotL64(aIngress, 56U) + RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = (aWandererE + RotL64(aPrevious, 35U)) + 3199575576585871314U;
            aOrbiterC = (((aWandererJ + RotL64(aCross, 51U)) + RotL64(aCarry, 21U)) + 2533378188975571824U) + aPhaseGOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = (aWandererD + RotL64(aScatter, 13U)) + 6819782112558312658U;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 43U)) + RotL64(aCarry, 35U)) + 12690060987724798497U;
            aOrbiterK = (((aWandererC + RotL64(aScatter, 60U)) + RotL64(aCarry, 51U)) + 7088375139715629606U) + aPhaseGOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 17785618677423695666U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 1714999280296491277U;
            aOrbiterI = RotL64((aOrbiterI * 7675674437417383741U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 17611338506932491624U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 6475727359297421201U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15133348244242438069U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 2347744591204119530U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 2739317903351401068U;
            aOrbiterF = RotL64((aOrbiterF * 15435029315209475631U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 8663535261373274338U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 8205245127823536479U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13857005110466856439U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 8916510616749754516U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 3944805940148512932U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 18082271583211389701U), 57U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 26U);
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterF, 47U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 11U) + aOrbiterK) + RotL64(aOrbiterG, 30U)) + RotL64(aCarry, 19U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterC, 3U)) + aOrbiterI);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 27U) + aOrbiterI) + RotL64(aOrbiterK, 39U)) + RotL64(aCarry, 57U)) + aPhaseGWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 44U) + aOrbiterI) + RotL64(aOrbiterG, 13U)) + aPhaseGWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 21U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 30265U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25202U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24715U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 25957U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCross, 28U)) + (RotL64(aIngress, 41U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = (aWandererA + RotL64(aPrevious, 13U)) + 7651355040951791298U;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 27U)) + RotL64(aCarry, 37U)) + 13988210277931659312U;
            aOrbiterH = (((aWandererI + RotL64(aScatter, 35U)) + RotL64(aCarry, 21U)) + 9846849412579537783U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = (((aWandererC + RotL64(aIngress, 3U)) + RotL64(aCarry, 53U)) + 12746719939495876158U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = (aWandererG + RotL64(aPrevious, 54U)) + 11498066185182895284U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 11101058955193080232U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 15513734459555672046U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6974281215677538561U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 15711108675349394643U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 4771231759949468556U;
            aOrbiterG = RotL64((aOrbiterG * 9806191054594333615U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 11449258010811305256U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 17036938391509986723U;
            aOrbiterF = RotL64((aOrbiterF * 7411466953205347639U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 6999245666776654250U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 2106819066263369528U;
            aOrbiterJ = RotL64((aOrbiterJ * 13005885810757743129U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 12716183358903477216U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 16752724547046059889U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11475905692393034141U), 39U);
            //
            aIngress = RotL64(aOrbiterH, 39U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + RotL64(aOrbiterF, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterA, 3U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterH, 35U)) + aOrbiterJ) + RotL64(aCarry, 43U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 48U) + RotL64(aOrbiterH, 21U)) + aOrbiterF);
            aWandererC = aWandererC + ((((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 11U)) + aPhaseGWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterH, 50U)) + aOrbiterA) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 60U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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

void TwistExpander_Karate_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 2475U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneB[((aIndex + 1262U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5522U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneD[((aIndex + 3918U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 23U)) + (RotL64(aCross, 57U) ^ RotL64(aPrevious, 44U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = ((aWandererK + RotL64(aScatter, 35U)) + RotL64(aCarry, 53U)) + 1557680213571812384U;
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 27U)) + 7387349725778021121U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 47U)) + RotL64(aCarry, 37U)) + 15379264067601586976U;
            aOrbiterH = ((aWandererG + RotL64(aCross, 58U)) + RotL64(aCarry, 21U)) + 3730195724576043708U;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 5U)) + 9637070085323827066U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 1170865717363676184U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 2750833653175252030U;
            aOrbiterJ = RotL64((aOrbiterJ * 1937822982381882775U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 15118992811225568305U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 4974092922102988451U;
            aOrbiterG = RotL64((aOrbiterG * 10575977398702460975U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 10625719096296719514U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 855167122475471865U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7441090331293158773U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 11322911068958340262U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 4334591909425429835U;
            aOrbiterF = RotL64((aOrbiterF * 10059025861172038183U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 14263701737208936392U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 678723206735649084U;
            aOrbiterE = RotL64((aOrbiterE * 10823239851733632227U), 19U);
            //
            aIngress = RotL64(aOrbiterE, 23U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 56U) + aOrbiterG) + RotL64(aOrbiterH, 27U)) + RotL64(aCarry, 43U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterG, 3U)) + aOrbiterE);
            aWandererF = aWandererF + ((((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterE, 43U)) + RotL64(aCarry, 29U)) + aPhaseHWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterE, 35U)) + aOrbiterJ) + aPhaseHWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 12U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 13U);
            aCarry = aCarry + RotL64(aIngress, 58U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 15227U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14699U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11404U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8708U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aIngress, 11U)) + (RotL64(aPrevious, 37U) ^ RotL64(aCarry, 50U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = (((aWandererJ + RotL64(aScatter, 26U)) + RotL64(aCarry, 57U)) + 8506388683755208267U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aCross, 41U)) + RotL64(aCarry, 5U)) + 2179323259055019735U;
            aOrbiterF = (aWandererK + RotL64(aIngress, 3U)) + 3345902531140983016U;
            aOrbiterC = (((aWandererH + RotL64(aPrevious, 53U)) + RotL64(aCarry, 41U)) + 17456139311481306584U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = (aWandererI + RotL64(aCross, 13U)) + 14587864088462311164U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 13178947246650647057U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 12866578138946916962U;
            aOrbiterF = RotL64((aOrbiterF * 121991325166969319U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 13098524333655118173U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 15451329483787541982U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13580376920467431451U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 9494299579678389385U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 15581954810375490643U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13670002280188424825U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 4487042505730624892U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 2774455928791636186U;
            aOrbiterB = RotL64((aOrbiterB * 15847933919136777451U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 12435319582397755819U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 10077180055177766823U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3924363471701748703U), 3U);
            //
            aIngress = RotL64(aOrbiterC, 13U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 39U));
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterC, 24U)) + aOrbiterI);
            aWandererE = aWandererE + ((((RotL64(aIngress, 54U) + RotL64(aOrbiterI, 39U)) + aOrbiterK) + RotL64(aCarry, 3U)) + aPhaseHWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 53U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterK, 13U)) + RotL64(aCarry, 43U)) + aPhaseHWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterB, 3U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererI, 30U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 21472U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneD[((aIndex + 23391U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22776U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17393U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 24U) ^ RotL64(aCross, 41U)) + (RotL64(aPrevious, 53U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 14008824488073394623U;
            aOrbiterH = (aWandererA + RotL64(aCross, 43U)) + 13317978415866411468U;
            aOrbiterD = (((aWandererG + RotL64(aPrevious, 14U)) + RotL64(aCarry, 53U)) + 13209180141897453900U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = (aWandererB + RotL64(aIngress, 29U)) + 11870521586865233578U;
            aOrbiterI = (((aWandererF + RotL64(aCross, 53U)) + RotL64(aCarry, 21U)) + 8052156380448047385U) + aPhaseHOrbiterAssignSaltD[((aIndex + 22U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 12158131176743680605U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 14674467487607719347U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 18372548574199176503U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 18055496790566231147U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 3838105585041578784U;
            aOrbiterH = RotL64((aOrbiterH * 1075709247574580091U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 2839568255183054418U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 11933612922864258179U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7571964469321160347U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 6289849094151630580U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 2640344350528492271U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16197726750829369365U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 16306175266267657791U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 3339898380394883600U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7105436590182982373U), 47U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterJ, 47U);
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterJ, 13U)) + aOrbiterG);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterD, 27U)) + aOrbiterH) + RotL64(aCarry, 5U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterH, 38U));
            aWandererF = aWandererF + (((RotL64(aIngress, 24U) + RotL64(aOrbiterD, 51U)) + aOrbiterG) + RotL64(aCarry, 41U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterI, 3U)) + aOrbiterD) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + RotL64(aWandererB, 3U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 29650U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31145U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30346U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneC[((aIndex + 31373U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 4U) ^ RotL64(aCross, 23U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 57U)) + 701291026547470433U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = ((aWandererH + RotL64(aIngress, 19U)) + 17283292650462111643U) + aPhaseHOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aCross, 3U)) + RotL64(aCarry, 37U)) + 9969124091931303406U;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 29U)) + RotL64(aCarry, 21U)) + 889176772718046988U;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 40U)) + RotL64(aCarry, 57U)) + 6054541844643748084U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 14703226235143028132U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 7977975878522921062U;
            aOrbiterC = RotL64((aOrbiterC * 9030855800028448469U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 16894322614172266274U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 12160451749345900570U;
            aOrbiterI = RotL64((aOrbiterI * 18055355572903901749U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 10870847008043897470U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 8159920947172520247U;
            aOrbiterD = RotL64((aOrbiterD * 4833194641611011805U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 2440099120969517932U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 2428396147731468007U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9363073341539598441U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 2213226274394673479U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 7079731443427765333U;
            aOrbiterA = RotL64((aOrbiterA * 16918930776877030559U), 29U);
            //
            aIngress = RotL64(aOrbiterA, 23U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 56U));
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterD, 13U)) + aOrbiterA) + RotL64(aCarry, 21U)) + aPhaseHWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterD, 26U)) + aOrbiterI);
            aWandererB = aWandererB + (((RotL64(aScatter, 56U) + aOrbiterG) + RotL64(aOrbiterC, 37U)) + aPhaseHWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 3U)) + aOrbiterA);
            aWandererK = aWandererK + (((RotL64(aCross, 11U) + RotL64(aOrbiterI, 51U)) + aOrbiterG) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 21U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
