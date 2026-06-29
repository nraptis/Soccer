#include "TwistExpander_Boxing_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Boxing_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xDD0ED4BEA53740EBULL + 0xF106EA609B69EA95ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xD2BFA4E726BD6E39ULL + 0xC43B08621A6F6F7CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xDC2E3AD7E48763D5ULL + 0xECA85B2FEEF46BFCULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xD4B101BB082FCFA9ULL + 0xAC19CA9E8BA98E09ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x9689AAED6933BBABULL + 0x8723EED227000EA5ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xF8174C7C4521E131ULL + 0xC19D41480F1B67F3ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xCA9C276C418A0325ULL + 0x8ABED6BB35A8764EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xD9D9F2D7CEB52B23ULL + 0xFCDA9114E372BA22ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xAB03EEAE494FB1F7ULL + 0xDBB628ECB1F15471ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x8E3A650FF5A35579ULL + 0xD12C7A40CA37EBEDULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xECB1E522A3293D09ULL + 0xE51482B6E5C82E26ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xF9A3F1B3CEF5D527ULL + 0xCC0F7149404F5C55ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xF1CFE876D331BA0FULL + 0xC81230621B430A67ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xB45119E1AA49F98DULL + 0x9CC4753368F30420ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xE030E8517FFEA849ULL + 0xB9B111524D8D0195ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xD8F481A4E9D45D9DULL + 0xB6A846ABBB4CC6F3ULL);
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
            aIngress = RotL64(mSource[((aIndex + 655U)) & S_BLOCK1], 29U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 895U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 4448U)) & S_BLOCK1], 19U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 4084U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 54U) ^ RotL64(aPrevious, 41U)) + (RotL64(aIngress, 29U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterC = ((aWandererF + RotL64(aCross, 11U)) + 3105313968748067810U) + aNonceWordC;
            aOrbiterA = (aWandererH + RotL64(aScatter, 13U)) + 9977249451119627064U;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 40U)) + RotL64(aCarry, 5U)) + 17941392803495349366U;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 3U)) + 4279533326705471133U) + aOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 53U)) + 13983828966811580039U) + aOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = ((aWandererC + RotL64(aCross, 57U)) + RotL64(aCarry, 41U)) + 3983490984234810378U;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 30U)) + RotL64(aCarry, 21U)) + 308786542215259956U;
            aOrbiterE = (aWandererD + RotL64(aIngress, 21U)) + 8443607695364427037U;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 47U)) + 14939626441464340668U) + aNonceWordH;
            aOrbiterF = ((aWandererG + RotL64(aCross, 43U)) + 9350693577306121110U) + aNonceWordD;
            aOrbiterG = (aWandererI + RotL64(aScatter, 37U)) + 1717071159396961752U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 15911765265202100610U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 14898546272333182767U;
            aOrbiterI = RotL64((aOrbiterI * 2674900543810733067U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 3560903518513465868U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 5367062725726860234U;
            aOrbiterJ = RotL64((aOrbiterJ * 8521908836601319553U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 15233321480618877327U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 9288449812290126074U) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 6815298520404038519U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 5504840529511585676U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 6825598386801620046U;
            aOrbiterK = RotL64((aOrbiterK * 11666542445846250077U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 6433024450721339470U) + aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 97934156644929458U;
            aOrbiterD = RotL64((aOrbiterD * 8630530773006923215U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 3260053604798744515U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 16539416623243059076U) ^ aOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12199577351166064503U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 9814290051339038920U) + aNonceWordE;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 13280156404507444041U) ^ aOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15269010043398910061U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 11853942590993546833U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 13207869904312989977U;
            aOrbiterF = RotL64((aOrbiterF * 15503461937625795969U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 14536032167989376750U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 3693282775047432356U;
            aOrbiterE = RotL64((aOrbiterE * 5290349323647887877U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 5803176485246280271U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 16702526675475954730U;
            aOrbiterG = RotL64((aOrbiterG * 13695676754973145769U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 16454171963808313625U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 3105313968748067810U;
            aOrbiterA = RotL64((aOrbiterA * 16572687178789102843U), 3U);
            //
            aIngress = RotL64(aOrbiterE, 14U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterG, 41U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 23U));
            aIngress = aIngress + (RotL64(aOrbiterD, 37U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aIngress, 42U) + aOrbiterA) + RotL64(aOrbiterG, 44U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 3U)) + aOrbiterA) + aNonceWordI);
            aWandererK = aWandererK + (((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterI, 51U)) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ ((((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterA, 37U)) + aNonceWordK) + aWandererUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 53U) + RotL64(aOrbiterJ, 19U)) + aOrbiterI);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 13U) + aOrbiterK) + RotL64(aOrbiterJ, 57U)) + aNonceWordO);
            aWandererH = aWandererH + (((RotL64(aCross, 37U) + RotL64(aOrbiterE, 30U)) + aOrbiterK) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterK, 11U)) + aOrbiterA) + aNonceWordJ) + aWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 35U) + RotL64(aOrbiterH, 23U)) + aOrbiterF);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterC, 47U)) + aOrbiterI);
            aWandererB = aWandererB + ((RotL64(aIngress, 48U) + aOrbiterI) + RotL64(aOrbiterD, 53U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 50U));
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererI);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 42U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 5670U)) & S_BLOCK1], 12U) ^ RotL64(pSnow[((aIndex + 9789U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 7638U)) & S_BLOCK1], 13U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 7698U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aIngress, 5U)) + (RotL64(aCross, 20U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterD = (aWandererI + RotL64(aIngress, 47U)) + 9220392006207660113U;
            aOrbiterI = (((aWandererB + RotL64(aScatter, 35U)) + 11305018553489132882U) + aOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1]) + aNonceWordB;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 5U)) + RotL64(aCarry, 3U)) + 5860373868073513684U;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 37U)) + 12319586170883987589U;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 23U)) + 14072333614354649021U) + aOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = (aWandererC + RotL64(aCross, 27U)) + 9332158529453194608U;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 10U)) + 3860569321145958686U) + aNonceWordG;
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 51U)) + RotL64(aCarry, 43U)) + 8119005668901240093U;
            aOrbiterE = ((aWandererD + RotL64(aCross, 39U)) + 13918259792880333239U) + aNonceWordC;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 41U)) + 6938856216758228704U) + aNonceWordO;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 30U)) + RotL64(aCarry, 11U)) + 3960905839118710604U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 6043879193734253929U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 15691425268831319195U;
            aOrbiterF = RotL64((aOrbiterF * 7189195135654636271U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 14912209933584715274U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 16180183395910618923U;
            aOrbiterD = RotL64((aOrbiterD * 3942858974766467849U), 53U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterB) + 4966642362507707776U) + aOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1]) + aNonceWordD;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 6962226782462822861U;
            aOrbiterK = RotL64((aOrbiterK * 3647802407741095419U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 12409120845092026295U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 2302946450253872465U) ^ aNonceWordM;
            aOrbiterE = RotL64((aOrbiterE * 7099576330777297911U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 16118304388937163838U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 15968419034359049422U;
            aOrbiterB = RotL64((aOrbiterB * 11736207775827080165U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 17098982091525008231U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 10298979200690822062U;
            aOrbiterC = RotL64((aOrbiterC * 12620028874653521945U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 552826643694256437U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 11786560990790695378U;
            aOrbiterI = RotL64((aOrbiterI * 11190309640069208311U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 13730399230389329793U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 17614226859252305432U) ^ aOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2640019643570222977U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 1062738267846296283U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 13959480457644980835U) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 1194145909157002977U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 4635071137794189167U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 13374502212707796180U;
            aOrbiterH = RotL64((aOrbiterH * 129680788767298945U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 11479902881487238033U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 9220392006207660113U) ^ aNonceWordF;
            aOrbiterG = RotL64((aOrbiterG * 1437457810224888809U), 37U);
            //
            aIngress = RotL64(aOrbiterF, 23U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterC, 18U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 60U) + RotL64(aOrbiterE, 43U)) + aOrbiterD) + aNonceWordK);
            aWandererF = aWandererF + ((RotL64(aPrevious, 51U) + aOrbiterH) + RotL64(aOrbiterK, 11U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterG, 4U));
            aWandererI = aWandererI + ((RotL64(aIngress, 39U) + RotL64(aOrbiterA, 27U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterC, 57U)) + aOrbiterD);
            aWandererD = aWandererD + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterJ, 29U)) + aOrbiterA) + RotL64(aCarry, 39U)) + aWandererUpdateSaltA[((aIndex + 10U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 37U)) + aOrbiterB) + aWandererUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 41U) + RotL64(aOrbiterB, 6U)) + aOrbiterI) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterE, 53U)) + aNonceWordP);
            aWandererA = aWandererA + (((RotL64(aPrevious, 24U) + aOrbiterB) + RotL64(aOrbiterG, 23U)) + aNonceWordN);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 47U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (RotL64(aWandererA, 14U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 18U);
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
            aIngress = RotL64(aFireLaneB[((aIndex + 13484U)) & S_BLOCK1], 40U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 14639U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 11921U)) & S_BLOCK1], 3U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 12698U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 34U) + RotL64(aPrevious, 3U)) ^ (RotL64(aIngress, 19U) + RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterE = (aWandererD + RotL64(aPrevious, 11U)) + 2786079456995203065U;
            aOrbiterI = (aWandererF + RotL64(aIngress, 37U)) + 7237256119153857253U;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 48U)) + 9310834010563647604U) + aNonceWordD;
            aOrbiterB = ((aWandererJ + RotL64(aCross, 23U)) + 17361734905706517877U) + aNonceWordA;
            aOrbiterJ = (((aWandererG + RotL64(aScatter, 5U)) + 15837111231884647451U) + aOrbiterAssignSaltF[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordC;
            aOrbiterC = (aWandererA + RotL64(aPrevious, 41U)) + 18065431964418026445U;
            aOrbiterD = (aWandererI + RotL64(aCross, 21U)) + 3029123922999952652U;
            aOrbiterA = (((aWandererC + RotL64(aIngress, 56U)) + RotL64(aCarry, 39U)) + 5166926595573507837U) + aOrbiterAssignSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = ((aWandererE + RotL64(aCross, 19U)) + RotL64(aCarry, 21U)) + 1918425684273807598U;
            aOrbiterG = (aWandererK + RotL64(aPrevious, 51U)) + 4724551751012661440U;
            aOrbiterF = (((aWandererH + RotL64(aScatter, 13U)) + RotL64(aCarry, 11U)) + 1818014487579644390U) + aNonceWordM;
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 6670090372241084216U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 8485757110007268693U;
            aOrbiterH = RotL64((aOrbiterH * 11876760095108618363U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 4928130251509514742U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 2528788422725346792U;
            aOrbiterC = RotL64((aOrbiterC * 1855982047967756661U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 2860387120895147503U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterJ) ^ 12927802338151379368U) ^ aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterA = RotL64((aOrbiterA * 8876144125458603029U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 18029699867733207083U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 13361836994951253312U;
            aOrbiterI = RotL64((aOrbiterI * 5349767426256597073U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 11957294454794128079U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 3755417922063414648U;
            aOrbiterD = RotL64((aOrbiterD * 13896364063651241401U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 18001157153447913032U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterD) ^ 16214145724690286854U) ^ aOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterK = RotL64((aOrbiterK * 5874139687703360515U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 3860958772090975562U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 12395621524459640173U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 722817135977510161U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 3402035664910754484U) + aNonceWordP;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 2139099117325745602U;
            aOrbiterE = RotL64((aOrbiterE * 14008983756425796029U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 7769274487425053026U) + aNonceWordJ;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 6492669707749367728U;
            aOrbiterG = RotL64((aOrbiterG * 5149771861620757839U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 14963366447884375043U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 11398874662567519691U) ^ aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8221521452475029835U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 7168445485232814860U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 2786079456995203065U;
            aOrbiterB = RotL64((aOrbiterB * 14258367164534307955U), 51U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterG, 46U);
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 21U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + (RotL64(aOrbiterK, 4U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 12U) + aOrbiterC) + RotL64(aOrbiterE, 41U)) + aWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 3U) + aOrbiterE) + RotL64(aOrbiterD, 35U)) + aNonceWordL);
            aWandererC = aWandererC + ((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 22U)) + aOrbiterF);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterC, 29U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 37U) + RotL64(aOrbiterG, 47U)) + aOrbiterA) + RotL64(aCarry, 35U)) + aWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterJ, 19U)) + aOrbiterI);
            aWandererD = aWandererD + ((RotL64(aCross, 39U) + RotL64(aOrbiterH, 13U)) + aOrbiterA);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 27U) + aOrbiterH) + RotL64(aOrbiterJ, 3U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterC, 43U)) + aOrbiterB) + aNonceWordO);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 22U) + aOrbiterG) + RotL64(aOrbiterE, 26U));
            aWandererB = aWandererB + (((RotL64(aCross, 57U) + aOrbiterF) + RotL64(aOrbiterD, 37U)) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 10U));
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 56U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 19238U)) & S_BLOCK1], 3U) ^ RotL64(pSnow[((aIndex + 16555U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 21454U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(mSource[((S_BLOCK1 - aIndex + 21317U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 19336U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCarry, 60U)) + (RotL64(aCross, 43U) ^ RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterC = (aWandererH + RotL64(aPrevious, 41U)) + 7948891781097675369U;
            aOrbiterJ = (((aWandererB + RotL64(aIngress, 6U)) + 13928362874228230226U) + aOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordG;
            aOrbiterI = (aWandererJ + RotL64(aCross, 37U)) + 10776180542602258926U;
            aOrbiterB = (aWandererA + RotL64(aScatter, 19U)) + 5735115172149470447U;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 51U)) + 5353591822981766987U) + aOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aScatter, 57U)) + 562301708107268570U) + aNonceWordA;
            aOrbiterA = ((aWandererC + RotL64(aCross, 47U)) + RotL64(aCarry, 53U)) + 10467810247578364868U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 23U)) + RotL64(aCarry, 19U)) + 14541630141152308564U;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 11U)) + 2350076897065139429U) + aNonceWordB;
            aOrbiterK = ((aWandererD + RotL64(aScatter, 13U)) + RotL64(aCarry, 47U)) + 17519109078651162228U;
            aOrbiterD = ((aWandererK + RotL64(aCross, 54U)) + 6061035173339902910U) + aNonceWordK;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 15654836633731000065U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterC) ^ 13723521735153718904U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 14459516479283070563U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 2849680038315532197U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 17336102435576647923U;
            aOrbiterC = RotL64((aOrbiterC * 10984689101753586739U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 7671010488872356142U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 11485114338165600777U;
            aOrbiterJ = RotL64((aOrbiterJ * 4162584865462407791U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 8759060657343458985U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 11009137869375286581U;
            aOrbiterG = RotL64((aOrbiterG * 8741417343929809115U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 15792999392743144135U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 6180808423175992479U;
            aOrbiterB = RotL64((aOrbiterB * 13681230339693676907U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 361487389591183005U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 15292753806514404853U) ^ aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17478232597253311153U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 14929153438443362045U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 7904556383593914086U) ^ aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2484130486635511403U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 3793180909904286848U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 10391957637467171320U) ^ aNonceWordE;
            aOrbiterF = RotL64((aOrbiterF * 505484041943467117U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 11648765065563798353U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 17601185776537566611U;
            aOrbiterK = RotL64((aOrbiterK * 4753179291885740011U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 2907499704986356444U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 17048858067202291241U;
            aOrbiterD = RotL64((aOrbiterD * 2607549567999666889U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 4340465159886930775U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 7948891781097675369U;
            aOrbiterE = RotL64((aOrbiterE * 12913104720552907335U), 23U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterA, 5U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 60U));
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 37U));
            aIngress = aIngress + RotL64(aOrbiterK, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aIngress, 29U) + aOrbiterJ) + RotL64(aOrbiterA, 11U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 21U) + aOrbiterE) + RotL64(aOrbiterB, 51U));
            aWandererF = aWandererF + ((RotL64(aScatter, 51U) + aOrbiterK) + RotL64(aOrbiterI, 22U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 18U) + RotL64(aOrbiterD, 35U)) + aOrbiterG) + aWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 23U) + aOrbiterA) + RotL64(aOrbiterC, 41U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterH, 57U)) + aOrbiterI) + aNonceWordH);
            aWandererK = aWandererK + ((((RotL64(aCross, 41U) + aOrbiterD) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 39U)) + aWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 56U) + RotL64(aOrbiterK, 19U)) + aOrbiterF) + aNonceWordF);
            aWandererI = aWandererI + (((RotL64(aIngress, 37U) + RotL64(aOrbiterK, 53U)) + aOrbiterD) + RotL64(aCarry, 35U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterB, 29U)) + aOrbiterA);
            aWandererH = aWandererH + ((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 38U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 46U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + RotL64(aWandererK, 23U);
            aCarry = aCarry + RotL64(aIngress, 28U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 22079U)) & S_BLOCK1], 43U) ^ RotL64(mSource[((aIndex + 24266U)) & S_BLOCK1], 51U));
            aIngress ^= (RotL64(pSnow[((aIndex + 26028U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneA[((aIndex + 24803U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25807U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneB[((aIndex + 25176U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCarry, 51U)) + (RotL64(aCross, 11U) ^ RotL64(aPrevious, 24U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterG = ((aWandererD + RotL64(aIngress, 29U)) + 6467297102954816305U) + aOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 40U)) + RotL64(aCarry, 27U)) + 7921154109831114952U;
            aOrbiterB = (((aWandererK + RotL64(aCross, 5U)) + RotL64(aCarry, 47U)) + 5701131763215638919U) + aNonceWordA;
            aOrbiterC = (aWandererH + RotL64(aScatter, 11U)) + 10022999076719002684U;
            aOrbiterK = (aWandererA + RotL64(aPrevious, 23U)) + 4367135243038982316U;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 47U)) + 14445846824810383592U) + aNonceWordC;
            aOrbiterA = ((aWandererC + RotL64(aCross, 57U)) + 7683697954545773253U) + aOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = ((aWandererF + RotL64(aScatter, 27U)) + RotL64(aCarry, 37U)) + 17517006750428030899U;
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 21U)) + 2052484792684025476U) + aNonceWordM;
            aOrbiterJ = (aWandererI + RotL64(aScatter, 19U)) + 6279463052085808926U;
            aOrbiterF = (aWandererE + RotL64(aIngress, 52U)) + 679280153651813684U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 2939516520188460569U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 1960616434964712325U;
            aOrbiterB = RotL64((aOrbiterB * 15145998415466343039U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 12273819390719947361U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 5685033154709449397U;
            aOrbiterK = RotL64((aOrbiterK * 9845666295874714959U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 9314494172199500653U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 15757631834636427621U;
            aOrbiterA = RotL64((aOrbiterA * 15483543888965744529U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 10878078046389399574U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 3583495913766365232U;
            aOrbiterI = RotL64((aOrbiterI * 2913540984990155225U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 7385544065754622301U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 16839599460207922881U;
            aOrbiterE = RotL64((aOrbiterE * 240651605910592561U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 13038163804940349251U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 2587538594933924000U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3091149760401278671U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 13109518583364738004U) + aNonceWordN;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 2447689055742474261U;
            aOrbiterH = RotL64((aOrbiterH * 12100180201235703193U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 5752044906692668618U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 6637725371036522120U;
            aOrbiterF = RotL64((aOrbiterF * 6021986525167161115U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 16549229877442298618U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 12825651879441561108U;
            aOrbiterG = RotL64((aOrbiterG * 9079931351967033993U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 16088338999978085987U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 12584648360998154782U) ^ aOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2109996837220975261U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 7526256599938771686U) + aOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 6467297102954816305U) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 9289442676936248653U), 53U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterK, 23U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 14U));
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterF, 39U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterA, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 34U) + aOrbiterF) + RotL64(aOrbiterI, 5U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 19U) + RotL64(aOrbiterA, 37U)) + aOrbiterI);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 39U) + aOrbiterJ) + RotL64(aOrbiterB, 3U)) + aWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 23U) + aOrbiterA) + RotL64(aOrbiterE, 53U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 13U) + aOrbiterE) + RotL64(aOrbiterC, 27U));
            aWandererF = aWandererF + ((RotL64(aIngress, 37U) + aOrbiterJ) + RotL64(aOrbiterH, 50U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 41U) + aOrbiterH) + RotL64(aOrbiterE, 41U)) + aNonceWordF);
            aWandererA = aWandererA + (((((RotL64(aScatter, 21U) + aOrbiterC) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 37U)) + aNonceWordO) + aWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterK, 35U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aIngress, 60U) + RotL64(aOrbiterG, 22U)) + aOrbiterD) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 19U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 60U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 18U));
            aCarry = aCarry + RotL64(aWandererJ, 39U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 31370U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneA[((aIndex + 29251U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 28066U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29348U)) & S_BLOCK1], 60U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 28987U)) & S_BLOCK1], 43U));
            aCross ^= (RotL64(pSnow[((S_BLOCK1 - aIndex + 28071U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneB[((aIndex + 28595U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 54U) + RotL64(aPrevious, 41U)) + (RotL64(aIngress, 11U) ^ RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterD = (aWandererJ + RotL64(aIngress, 14U)) + 9023059520606551446U;
            aOrbiterI = (aWandererK + RotL64(aCross, 39U)) + 662441755115638133U;
            aOrbiterB = (aWandererG + RotL64(aScatter, 27U)) + 16957253361196144712U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 47U)) + RotL64(aCarry, 19U)) + 7840955025765308605U;
            aOrbiterA = (((aWandererC + RotL64(aScatter, 29U)) + RotL64(aCarry, 41U)) + 346855809270395799U) + aNonceWordJ;
            aOrbiterK = (aWandererA + RotL64(aCross, 57U)) + 16099139781586668343U;
            aOrbiterJ = (((aWandererE + RotL64(aIngress, 24U)) + 3706457327118322098U) + aOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1]) + aNonceWordE;
            aOrbiterF = (((aWandererB + RotL64(aPrevious, 11U)) + 12166825885547622870U) + aOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordH;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 53U)) + 7792658665720344200U) + aNonceWordF;
            aOrbiterG = ((aWandererI + RotL64(aCross, 21U)) + RotL64(aCarry, 23U)) + 7128477606152986326U;
            aOrbiterE = (aWandererF + RotL64(aPrevious, 5U)) + 11116533962780290084U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 10443889548568288532U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 4402387036946561017U;
            aOrbiterB = RotL64((aOrbiterB * 9032964741841833277U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 13002706161178447654U) + aNonceWordB;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 13929727277530310708U;
            aOrbiterK = RotL64((aOrbiterK * 7005639090871200285U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 10949073760696935106U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 15405923432006783533U;
            aOrbiterA = RotL64((aOrbiterA * 17989565878445202495U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 18096057968822208905U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 3032155040484574973U;
            aOrbiterJ = RotL64((aOrbiterJ * 448597307502544605U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 17462076466907467134U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 15471015427013701406U;
            aOrbiterG = RotL64((aOrbiterG * 6113474000571976139U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 3549031751266594344U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 14243218483842508113U;
            aOrbiterC = RotL64((aOrbiterC * 9041601306479302047U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 5803147589312920032U) + aNonceWordN;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 5549470512227427855U;
            aOrbiterI = RotL64((aOrbiterI * 12592362489263862879U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 10076661824293832189U) + aNonceWordL;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 3196799148974716550U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8183276968961467775U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 5245559903456662243U) + aNonceWordM;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 5907555542861339984U) ^ aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10224549416454347583U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 12670710096595941569U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 655047039452620836U;
            aOrbiterH = RotL64((aOrbiterH * 9717552134857988153U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 2654837870443908572U) + aOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 9023059520606551446U;
            aOrbiterE = RotL64((aOrbiterE * 170905364378771841U), 53U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 43U);
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + (RotL64(aOrbiterB, 12U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterG, 23U));
            aWandererA = aWandererA ^ ((((RotL64(aCross, 3U) + aOrbiterE) + RotL64(aOrbiterA, 53U)) + aNonceWordG) + aWandererUpdateSaltE[((aIndex + 16U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 27U) + RotL64(aOrbiterK, 39U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 60U) + RotL64(aOrbiterG, 42U)) + aOrbiterA) + aNonceWordP);
            aWandererE = aWandererE + ((RotL64(aIngress, 53U) + aOrbiterI) + RotL64(aOrbiterJ, 57U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 51U) + aOrbiterE) + RotL64(aOrbiterC, 37U)) + aNonceWordD);
            aWandererF = aWandererF + ((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterD, 29U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 39U) + aOrbiterF) + RotL64(aOrbiterH, 18U)) + aWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 11U) + aOrbiterC) + RotL64(aOrbiterG, 27U)) + RotL64(aCarry, 11U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 14U) + RotL64(aOrbiterA, 35U)) + aOrbiterF);
            aWandererD = aWandererD + ((((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 3U)) + aNonceWordC);
            //
            aCarry = aCarry + (RotL64(aWandererD, 60U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererI, 48U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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

void TwistExpander_Boxing_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x9BEE8D5A72612DC3ULL + 0xC20AC8C1584B31F1ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xB6B67FA4A1A02E4BULL + 0xF47ABD968425507DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xBAB3EACC2A9DFEB1ULL + 0xCA5833F8F31E9664ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xBD830C9BB15A4A75ULL + 0xF8F11413DFFDC37AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xAB768432E480F91FULL + 0xB5A7CEC26EE1B73AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xD64F11AA4701656BULL + 0xD28B656868E57E36ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xB9418F4F4935AE05ULL + 0x903FBE3CBF67CC59ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xA01E7DD5FB5AEA19ULL + 0xF8D9E2D266359F4EULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xE8764C9D10F8EB17ULL + 0x94F172ACB2D7EB6FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x8EB8625A6374C39FULL + 0xE5DDEC7AE080275AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x8479C5F01BFAFFDDULL + 0xC543848050C1ED22ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xA9AF2DBBC8096417ULL + 0x98771A57AEA234B4ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xA67775609CB02F23ULL + 0xD4176DDBD1279571ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xCD3A08C58F50362BULL + 0xCEB7879308CE20F2ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x9E6E06381E67E0EFULL + 0x8912BD1B2E2C1978ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x9EB2340FDDC0474FULL + 0xB9E9C64FE6DDC9F8ULL);
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
            aIngress = RotL64(aExpandLaneA[((aIndex + 104U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1304U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4955U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((aIndex + 4820U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 52U) ^ RotL64(aCarry, 3U)) + (RotL64(aIngress, 19U) ^ RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterH = ((aWandererG + RotL64(aIngress, 30U)) + 11274974230580265396U) + aOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aCross, 47U)) + 16658438747342741547U;
            aOrbiterK = (aWandererC + RotL64(aScatter, 23U)) + 16612986966106053844U;
            aOrbiterG = (((aWandererK + RotL64(aPrevious, 57U)) + RotL64(aCarry, 13U)) + 9329502236843231290U) + aNonceWordF;
            aOrbiterA = (((aWandererA + RotL64(aCross, 19U)) + RotL64(aCarry, 21U)) + 14088261356708344656U) + aNonceWordI;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 51U)) + 13692608802007789581U) + aNonceWordP;
            aOrbiterC = (aWandererD + RotL64(aIngress, 4U)) + 6824473946645682398U;
            aOrbiterI = (((aWandererE + RotL64(aPrevious, 37U)) + 2072915876348570040U) + aOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1]) + aNonceWordB;
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 43U)) + RotL64(aCarry, 51U)) + 7420507753044460759U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 4677557318688502593U) + aNonceWordG;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 15081678577055628459U;
            aOrbiterK = RotL64((aOrbiterK * 16659305295251177155U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 7026792817486507482U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 14871665922943969918U;
            aOrbiterD = RotL64((aOrbiterD * 694073180313083145U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 6807734532159292872U) + aNonceWordK;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 17882797335141303280U;
            aOrbiterA = RotL64((aOrbiterA * 15439872930381050291U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 9233542707022629190U) + aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 1205501586581350876U) ^ aOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2596053290311090589U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 10878718669747466677U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 8066049063548639241U;
            aOrbiterI = RotL64((aOrbiterI * 3031382633089381605U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 861295180226875235U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 9134969787937288583U;
            aOrbiterC = RotL64((aOrbiterC * 7565008208670843555U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 6726642007159809594U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 8061661744643240470U;
            aOrbiterH = RotL64((aOrbiterH * 6703498926835391813U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 13541412083111962884U) + aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 8617442758729315637U;
            aOrbiterB = RotL64((aOrbiterB * 15471862889276160953U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 16884403561131293362U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 9490680911678221233U;
            aOrbiterF = RotL64((aOrbiterF * 15988763830018001033U), 21U);
            //
            aIngress = RotL64(aOrbiterK, 37U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 46U));
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterI, 39U)) + aNonceWordE);
            aWandererD = aWandererD + ((RotL64(aIngress, 35U) + RotL64(aOrbiterK, 51U)) + aOrbiterA);
            aWandererC = aWandererC ^ (((RotL64(aCross, 20U) + RotL64(aOrbiterD, 21U)) + aOrbiterB) + aWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterH, 60U)) + aNonceWordA);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 51U) + aOrbiterK) + RotL64(aOrbiterG, 13U));
            aWandererA = aWandererA + ((((RotL64(aScatter, 39U) + aOrbiterB) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 47U)) + aWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterA, 27U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 14U) + aOrbiterH) + RotL64(aOrbiterC, 34U)) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterH, 3U)) + aOrbiterD) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (RotL64(aWandererC, 6U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + RotL64(aWandererD, 41U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 6704U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((aIndex + 6164U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 10566U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 6744U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneD[((aIndex + 7735U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCross, 5U)) ^ (RotL64(aCarry, 57U) + RotL64(aIngress, 44U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 29U)) + RotL64(aCarry, 41U)) + 785861751704720606U;
            aOrbiterK = (aWandererE + RotL64(aIngress, 46U)) + 15968088718435606299U;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 53U)) + RotL64(aCarry, 13U)) + 1393976526590347151U;
            aOrbiterD = (aWandererI + RotL64(aCross, 37U)) + 17240750947292745884U;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 19U)) + 4921576136163183137U) + aNonceWordE;
            aOrbiterG = ((aWandererF + RotL64(aCross, 41U)) + 3334047873553153032U) + aNonceWordL;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 23U)) + RotL64(aCarry, 51U)) + 15086509978458408698U;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 14U)) + 892391205397581998U) + aOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterI = ((aWandererC + RotL64(aCross, 5U)) + 2965686403183767521U) + aOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 14632215393655706170U) + aNonceWordN;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 15740589515342377322U) ^ aOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15677716942904794913U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 11131164813943086445U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 6988080581278900960U;
            aOrbiterG = RotL64((aOrbiterG * 6412189142344044255U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 16021254613117657178U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 6183615599897921154U) ^ aNonceWordI;
            aOrbiterD = RotL64((aOrbiterD * 9976411093264211033U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 12533992547026652747U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 3104325358982904219U;
            aOrbiterA = RotL64((aOrbiterA * 14977348108778147265U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 3878525937957474644U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 2120435259884368445U;
            aOrbiterK = RotL64((aOrbiterK * 15964718652193073177U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 14928658302694194856U) + aOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = (((aOrbiterB ^ aOrbiterH) ^ 9121310461310309348U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 17304439784647477491U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 3715693239100476493U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 7336577492932262490U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11074754160002665253U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 2312452827448455675U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 4322756069651934618U;
            aOrbiterH = RotL64((aOrbiterH * 6908893297397073539U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 4962079617577705818U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 5072727464750706525U;
            aOrbiterJ = RotL64((aOrbiterJ * 4947670001221089155U), 51U);
            //
            aIngress = RotL64(aOrbiterK, 11U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterC, 51U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + RotL64(aOrbiterA, 14U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 58U) + RotL64(aOrbiterD, 19U)) + aOrbiterC) + aNonceWordG);
            aWandererF = aWandererF ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterD, 36U)) + aOrbiterK);
            aWandererE = aWandererE + ((RotL64(aScatter, 43U) + RotL64(aOrbiterA, 53U)) + aOrbiterJ);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterB, 11U)) + aOrbiterK) + aNonceWordA);
            aWandererH = aWandererH + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterK, 23U)) + aOrbiterJ) + RotL64(aCarry, 11U)) + aNonceWordB);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 29U) + aOrbiterC) + RotL64(aOrbiterI, 60U)) + aWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 4U) + RotL64(aOrbiterH, 3U)) + aOrbiterG);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterH, 43U)) + aOrbiterB);
            aWandererJ = aWandererJ + (((((RotL64(aCross, 21U) + RotL64(aOrbiterJ, 29U)) + aOrbiterH) + RotL64(aCarry, 35U)) + aNonceWordP) + aWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 10U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 14683U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((aIndex + 11149U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 16142U)) & S_BLOCK1], 26U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 11541U)) & S_BLOCK1], 48U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 13768U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCarry, 38U)) + (RotL64(aPrevious, 51U) ^ RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterK = ((aWandererH + RotL64(aScatter, 10U)) + 5041131702736607991U) + aOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = (aWandererE + RotL64(aIngress, 27U)) + 9295010428212681446U;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 41U)) + 6235875895358766017U) + aNonceWordM;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 47U)) + 2622227802531866918U) + aOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aPrevious, 21U)) + 3888894734834524972U;
            aOrbiterF = (((aWandererB + RotL64(aScatter, 57U)) + RotL64(aCarry, 11U)) + 241682012014701753U) + aNonceWordO;
            aOrbiterC = ((aWandererD + RotL64(aCross, 4U)) + RotL64(aCarry, 21U)) + 15758000422451568079U;
            aOrbiterH = ((aWandererC + RotL64(aIngress, 53U)) + RotL64(aCarry, 53U)) + 2061944548396976912U;
            aOrbiterD = (aWandererG + RotL64(aScatter, 35U)) + 8177144990755754531U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 554978075608818497U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 250408260560714933U) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 1295379390497107727U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 8700027645880997552U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 10026130047465480902U;
            aOrbiterG = RotL64((aOrbiterG * 12417270861933696623U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 9785843014096326696U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 9998582683258411251U) ^ aOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7197956237569462269U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 13817734599383455151U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 6647207154174092691U;
            aOrbiterH = RotL64((aOrbiterH * 1578528131687283531U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 4957715980509035719U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 4994885315786213197U) ^ aOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5676683798126497011U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 5072908311783966503U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 5535039946192891515U;
            aOrbiterD = RotL64((aOrbiterD * 2989412783482309753U), 47U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterC) + 6594577050344146271U) + aOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1]) + aNonceWordK;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 8750154123258714856U;
            aOrbiterA = RotL64((aOrbiterA * 6942158167127532003U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 3514769314840874873U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 8626045200273524281U;
            aOrbiterK = RotL64((aOrbiterK * 4315441782689789689U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 8524870284841706517U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 1841819423572964209U;
            aOrbiterF = RotL64((aOrbiterF * 9802481758007234681U), 43U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterE, 19U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + (RotL64(aOrbiterG, 34U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + RotL64(aOrbiterH, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aScatter, 21U) + RotL64(aOrbiterF, 51U)) + aOrbiterJ);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterA, 23U)) + aOrbiterC) + aWandererUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 10U) + aOrbiterG) + RotL64(aOrbiterD, 39U)) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 44U)) + aOrbiterE);
            aWandererH = aWandererH + ((RotL64(aIngress, 41U) + aOrbiterD) + RotL64(aOrbiterF, 57U));
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 29U)) + aOrbiterA) + aNonceWordF) + aWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 35U) + aOrbiterK) + RotL64(aOrbiterD, 13U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterD, 5U)) + aOrbiterA);
            aWandererK = aWandererK + ((((RotL64(aIngress, 14U) + aOrbiterH) + RotL64(aOrbiterG, 18U)) + RotL64(aCarry, 23U)) + aNonceWordB);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 56U));
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 40U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 18681U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneC[((aIndex + 21760U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 18146U)) & S_BLOCK1], 6U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17119U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneD[((aIndex + 16817U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCross, 39U)) ^ (RotL64(aCarry, 54U) + RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterK = ((aWandererH + RotL64(aCross, 19U)) + RotL64(aCarry, 11U)) + 14157904117287696136U;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 60U)) + 7369512677371640676U) + aNonceWordO;
            aOrbiterE = (aWandererE + RotL64(aIngress, 53U)) + 8411250745902073798U;
            aOrbiterI = (aWandererF + RotL64(aScatter, 23U)) + 5002041814539710275U;
            aOrbiterD = (aWandererB + RotL64(aCross, 27U)) + 9538041410816283124U;
            aOrbiterH = ((((aWandererD + RotL64(aScatter, 14U)) + RotL64(aCarry, 37U)) + 5210700103927513061U) + aOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1]) + aNonceWordL;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 41U)) + 7600709399101287982U;
            aOrbiterG = (((aWandererC + RotL64(aIngress, 47U)) + RotL64(aCarry, 51U)) + 2366369466696580499U) + aNonceWordI;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 5U)) + 5544575244203019109U) + aOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 8710073749110329779U) + aNonceWordG;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 15998211310115361630U;
            aOrbiterE = RotL64((aOrbiterE * 15275657696897688955U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 15354357553877376422U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 10657523549259276169U;
            aOrbiterH = RotL64((aOrbiterH * 13695239532898311073U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 10405750198355464768U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 3465819693133515142U) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 14678343718277562799U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 16724189641701408630U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 3484340153620198872U;
            aOrbiterJ = RotL64((aOrbiterJ * 17247547677520703125U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 7420442404884871126U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 11138445997256757636U;
            aOrbiterC = RotL64((aOrbiterC * 11167543379937571127U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 1428191560884663125U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 16950093140800653985U) ^ aOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4423012306984814805U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 17288299075036481960U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 13793597915359681028U;
            aOrbiterG = RotL64((aOrbiterG * 9639204979982125757U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 5017972942710079726U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 12409957957614320964U) ^ aNonceWordJ;
            aOrbiterK = RotL64((aOrbiterK * 10273295741911545745U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 12487994181992095174U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterJ) ^ 1573393166996612118U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 13364311829104520751U), 35U);
            //
            aIngress = RotL64(aOrbiterI, 5U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 44U));
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aIngress, 23U) + aOrbiterC) + RotL64(aOrbiterI, 12U)) + aNonceWordD);
            aWandererB = aWandererB + ((RotL64(aCross, 58U) + RotL64(aOrbiterK, 27U)) + aOrbiterE);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterG, 35U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 51U) + aOrbiterB) + RotL64(aOrbiterD, 43U)) + RotL64(aCarry, 19U)) + aWandererUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 37U) + aOrbiterI) + RotL64(aOrbiterG, 3U));
            aWandererD = aWandererD + (((RotL64(aScatter, 42U) + RotL64(aOrbiterD, 47U)) + aOrbiterE) + aNonceWordN);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterJ, 23U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterH, 51U)) + aOrbiterJ) + RotL64(aCarry, 11U)) + aWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterJ, 18U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 50U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = RotL64(aOperationLaneB[((aIndex + 26356U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneD[((aIndex + 26420U)) & S_BLOCK1], 22U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24553U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((aIndex + 26083U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 34U) ^ RotL64(aCross, 47U)) + (RotL64(aIngress, 21U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterJ = (aWandererF + RotL64(aScatter, 43U)) + 9630214189402543339U;
            aOrbiterF = ((aWandererK + RotL64(aCross, 12U)) + RotL64(aCarry, 51U)) + 4072576573737526819U;
            aOrbiterE = (((aWandererE + RotL64(aPrevious, 27U)) + RotL64(aCarry, 23U)) + 15994787452709618869U) + aOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aIngress, 21U)) + 6403240137132259482U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 35U)) + 10229266900170507720U) + aNonceWordE;
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 51U)) + 5025294577989748989U) + aNonceWordG;
            aOrbiterD = (aWandererJ + RotL64(aIngress, 39U)) + 16696461238217956883U;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 56U)) + RotL64(aCarry, 39U)) + 9878318855341719119U;
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 5U)) + 16086635438116177346U) + aOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 12295437783084203730U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 7681150419912842402U;
            aOrbiterE = RotL64((aOrbiterE * 7289497379725191451U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 2639104034287637448U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 12298170009332243573U;
            aOrbiterF = RotL64((aOrbiterF * 9397919591171238575U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 3485932317267669626U) + aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 16569551670038752475U;
            aOrbiterD = RotL64((aOrbiterD * 8139802826402217631U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 4448490103784103954U) + aNonceWordL;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 14510534073046885941U;
            aOrbiterH = RotL64((aOrbiterH * 7777192047386438305U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 4286195398675733451U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 15790355933840266463U) ^ aNonceWordO;
            aOrbiterC = RotL64((aOrbiterC * 13342257823027075501U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 6362891510370156055U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 15121822034579983174U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7268045994574844937U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 13817341015719915628U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 14113474087906143783U) ^ aNonceWordP;
            aOrbiterA = RotL64((aOrbiterA * 12838910141533126059U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 9988301252236121106U) + aNonceWordF;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 11287477288382171758U;
            aOrbiterJ = RotL64((aOrbiterJ * 4979297247881426383U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 9491727010910328644U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 7961202721830514030U) ^ aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16300364540313620767U), 29U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 53U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterF, 27U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterK, 34U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 18U)) + aOrbiterH) + aNonceWordN) + aWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 42U) + RotL64(aOrbiterJ, 43U)) + aOrbiterD);
            aWandererD = aWandererD + (((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterD, 23U)) + aNonceWordI);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterK, 5U)) + aOrbiterG);
            aWandererI = aWandererI + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 29U)) + aOrbiterE);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 56U) + RotL64(aOrbiterF, 39U)) + aOrbiterD);
            aWandererF = aWandererF + (((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterG, 10U)) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 23U) + aOrbiterC) + RotL64(aOrbiterA, 53U));
            aWandererC = aWandererC + ((((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 23U)) + aWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 10U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aOperationLaneC[((aIndex + 30894U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((aIndex + 27523U)) & S_BLOCK1], 40U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31823U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((aIndex + 31167U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 44U)) + (RotL64(aCross, 57U) + RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterB = ((aWandererA + RotL64(aCross, 47U)) + RotL64(aCarry, 57U)) + 1210605127156905516U;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 23U)) + RotL64(aCarry, 35U)) + 11964595428173569519U;
            aOrbiterG = ((((aWandererC + RotL64(aIngress, 6U)) + RotL64(aCarry, 19U)) + 16277319029916258482U) + aOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordA;
            aOrbiterE = ((aWandererH + RotL64(aScatter, 13U)) + 12369497463101824572U) + aNonceWordO;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 51U)) + 6201248574067068202U) + aNonceWordE;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 29U)) + 1727477025667206661U) + aOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (aWandererJ + RotL64(aCross, 39U)) + 1404510627789806851U;
            aOrbiterA = (aWandererD + RotL64(aIngress, 19U)) + 6948213591282018925U;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 56U)) + 6688865181284421478U) + aNonceWordD;
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 3351130769402360855U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 12681032488906270823U) ^ aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3680893896579741263U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 3591412591193726763U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 16153817571210878589U;
            aOrbiterF = RotL64((aOrbiterF * 4165137036092246349U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 3808228354421006630U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 1427373776207504205U;
            aOrbiterD = RotL64((aOrbiterD * 4534374093769595531U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 1831554180932501132U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 1114853085120949215U;
            aOrbiterK = RotL64((aOrbiterK * 4264176108298812905U), 43U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterB) + 2080935638828366835U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordI;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 16104777999646489828U;
            aOrbiterE = RotL64((aOrbiterE * 15205199362011777473U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 9782806013673440791U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 3721620299829386454U;
            aOrbiterA = RotL64((aOrbiterA * 6286765834910272409U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 4013706412064296527U) + aNonceWordB;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 5751022780695158579U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13766736471646116397U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 17684546333240329338U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 1106947111128020920U;
            aOrbiterJ = RotL64((aOrbiterJ * 3158839453318658951U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 11564229705849500598U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 1585817314460274286U;
            aOrbiterB = RotL64((aOrbiterB * 12687162159791577431U), 57U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 35U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 60U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + RotL64(aOrbiterC, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 12U) + aOrbiterC) + RotL64(aOrbiterB, 29U));
            aWandererD = aWandererD + ((RotL64(aScatter, 53U) + RotL64(aOrbiterC, 13U)) + aOrbiterJ);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterG, 58U)) + aOrbiterA);
            aWandererK = aWandererK + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterC, 19U)) + aOrbiterE) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 23U) + aOrbiterA) + RotL64(aOrbiterD, 39U)) + aNonceWordJ);
            aWandererA = aWandererA + ((((RotL64(aScatter, 28U) + aOrbiterF) + RotL64(aOrbiterD, 43U)) + RotL64(aCarry, 11U)) + aNonceWordM);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterK, 47U)) + aWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterJ, 23U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterJ, 54U)) + aWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + RotL64(aWandererA, 30U);
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

void TwistExpander_Boxing_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xDF1CD2CC3A54D3E3ULL + 0xDCAE260F4B7A2212ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x9B5774BAF8898697ULL + 0xAB0B935669576ECFULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xA9662FAC34E675D7ULL + 0x98EBC6BC9AB40948ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x85D615E3D7283C2BULL + 0xF9E9025F1120BA34ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xEDD65CB36ADA2419ULL + 0xFE5B1CC3E003B451ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xFD23CE04F6947919ULL + 0xB5A53B29B094CFA2ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xE438279DD1568FABULL + 0xA967C0B4CA14A27CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xF5D6893613276C71ULL + 0x8A4D38BFCF9C3C32ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x861EEA4578AAC0ADULL + 0xAC1AD31116802597ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x96C04187F458EFD1ULL + 0xE253377315DD3721ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xE0086343D48254FBULL + 0xBBDD9122D64D5C3AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x9202CF7540B9C951ULL + 0xD49459FD197F5577ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x9C9EE201427A4653ULL + 0xB0BF8454ECBBFAECULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xFEEC10C2ECAB2809ULL + 0xED4B1A3007F8C454ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xD0139A8F6E4FDF0BULL + 0x8DD941E4CAC0CE29ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xF25C01E31E12C497ULL + 0xDFE4EF589CB3D7CBULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 3070U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((aIndex + 1890U)) & S_BLOCK1], 40U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 3227U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4512U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 5272U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 4799U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 19U) + RotL64(aCross, 35U)) + (RotL64(aCarry, 5U) ^ RotL64(aIngress, 48U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterG = (((aWandererJ + RotL64(aIngress, 47U)) + RotL64(aCarry, 23U)) + 13278949403988203974U) + aOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = (((aWandererK + RotL64(aScatter, 13U)) + RotL64(aCarry, 37U)) + 9213599924054673756U) + aNonceWordE;
            aOrbiterH = ((((aWandererC + RotL64(aCross, 30U)) + RotL64(aCarry, 57U)) + 1255746482932381798U) + aOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1]) + aNonceWordI;
            aOrbiterC = (aWandererD + RotL64(aPrevious, 3U)) + 11575321997144516122U;
            aOrbiterI = (aWandererH + RotL64(aIngress, 21U)) + 15881587525529432437U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 9846195809864862707U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 12319815691858217670U) ^ aOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14271546305640811091U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 16322617427294439587U) + aNonceWordG;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 16332130810525887437U;
            aOrbiterI = RotL64((aOrbiterI * 7588076439690559343U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 4920951156015336794U) + aNonceWordM;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 16767126455124552329U;
            aOrbiterG = RotL64((aOrbiterG * 4440352337076842603U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 12553595911087945223U) + aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 1437522202135436142U;
            aOrbiterA = RotL64((aOrbiterA * 2001992794165550905U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 12313100454852227143U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 2761983020631055729U) ^ aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3874839760378039509U), 5U);
            //
            aIngress = RotL64(aOrbiterC, 3U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterH, 39U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 29U)) + aOrbiterI) + RotL64(aCarry, 43U)) + aWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterC, 11U)) + aOrbiterG) + aNonceWordP);
            aWandererJ = aWandererJ + (((RotL64(aCross, 47U) + aOrbiterC) + RotL64(aOrbiterA, 51U)) + aNonceWordD);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 21U) + aOrbiterA) + RotL64(aOrbiterH, 60U));
            aWandererC = aWandererC + (((((RotL64(aCross, 30U) + aOrbiterH) + RotL64(aOrbiterG, 19U)) + RotL64(aCarry, 21U)) + aNonceWordK) + aWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 13U);
            aCarry = aCarry + RotL64(aIngress, 34U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 12577U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((aIndex + 9003U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 12066U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 8364U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 8861U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 11279U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 13718U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aPrevious, 54U)) ^ (RotL64(aCross, 23U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterD = (((aWandererF + RotL64(aPrevious, 39U)) + RotL64(aCarry, 5U)) + 14499676118633326000U) + aNonceWordJ;
            aOrbiterF = (aWandererI + RotL64(aIngress, 3U)) + 17191273593018552288U;
            aOrbiterK = (((aWandererJ + RotL64(aScatter, 47U)) + RotL64(aCarry, 57U)) + 4085176294948097737U) + aNonceWordN;
            aOrbiterG = ((((aWandererC + RotL64(aCross, 24U)) + RotL64(aCarry, 23U)) + 11112671474158908186U) + aOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1]) + aNonceWordH;
            aOrbiterI = (((aWandererG + RotL64(aIngress, 57U)) + 8745787969012266485U) + aOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1]) + aNonceWordK;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 18074049663777707948U) + aNonceWordO;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 2543758649719164688U;
            aOrbiterK = RotL64((aOrbiterK * 7153845562786344373U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 4659584749412700523U) + aOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 974639159259871273U;
            aOrbiterI = RotL64((aOrbiterI * 17918719351847605523U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 9211220687971081987U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 8567024626862182714U) ^ aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7755874089832496393U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 5803002132294840900U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 11968489432878148467U) ^ aNonceWordP;
            aOrbiterG = RotL64((aOrbiterG * 4501441062617123165U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 9470807228394903442U) + aNonceWordL;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 1692347973120388469U) ^ aNonceWordI;
            aOrbiterD = RotL64((aOrbiterD * 17433393164156231575U), 23U);
            //
            aIngress = RotL64(aOrbiterK, 24U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 38U)) + aOrbiterK) + RotL64(aCarry, 13U)) + aNonceWordE) + aWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 5U) + aOrbiterD) + RotL64(aOrbiterG, 53U)) + aWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterF, 11U)) + RotL64(aCarry, 53U)) + aNonceWordA);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 56U) + aOrbiterI) + RotL64(aOrbiterF, 21U)) + aNonceWordD);
            aWandererC = aWandererC + (((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 29U)) + aOrbiterK) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 5U);
            aCarry = aCarry + RotL64(aIngress, 30U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 23860U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((aIndex + 18237U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 17952U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 19563U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22841U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 21773U)) & S_BLOCK1], 20U));
            aCross ^= RotL64(aExpandLaneB[((aIndex + 22898U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aPrevious, 58U)) + (RotL64(aCarry, 23U) ^ RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 47U)) + 3199575576585871314U) + aNonceWordJ;
            aOrbiterG = (((aWandererI + RotL64(aScatter, 5U)) + 2533378188975571824U) + aOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordI;
            aOrbiterC = (((aWandererK + RotL64(aCross, 22U)) + RotL64(aCarry, 51U)) + 6819782112558312658U) + aOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = (((aWandererD + RotL64(aIngress, 37U)) + RotL64(aCarry, 19U)) + 12690060987724798497U) + aNonceWordA;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 13U)) + RotL64(aCarry, 37U)) + 7088375139715629606U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 17785618677423695666U) + aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 1714999280296491277U;
            aOrbiterC = RotL64((aOrbiterC * 7675674437417383741U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 17611338506932491624U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 6475727359297421201U) ^ aOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15133348244242438069U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 2347744591204119530U) + aNonceWordG;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 2739317903351401068U;
            aOrbiterF = RotL64((aOrbiterF * 15435029315209475631U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 8663535261373274338U) + aNonceWordK;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 8205245127823536479U;
            aOrbiterB = RotL64((aOrbiterB * 13857005110466856439U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 8916510616749754516U) + aNonceWordM;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 3944805940148512932U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 18082271583211389701U), 27U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 19U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + RotL64(aOrbiterB, 56U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 19U)) + aOrbiterB);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 41U) + aOrbiterC) + RotL64(aOrbiterF, 48U)) + aNonceWordH);
            aWandererD = aWandererD + ((((RotL64(aScatter, 14U) + aOrbiterG) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 57U)) + aNonceWordO);
            aWandererF = aWandererF ^ ((((RotL64(aCross, 23U) + aOrbiterC) + RotL64(aOrbiterG, 35U)) + aNonceWordB) + aWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererI = aWandererI + (((((RotL64(aIngress, 53U) + RotL64(aOrbiterA, 57U)) + aOrbiterB) + RotL64(aCarry, 23U)) + aNonceWordE) + aWandererUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 30U));
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 28410U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((aIndex + 30841U)) & S_BLOCK1], 18U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 27171U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((aIndex + 27550U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32598U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29769U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 30206U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 56U)) + (RotL64(aIngress, 5U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterI = (((aWandererI + RotL64(aCross, 57U)) + RotL64(aCarry, 21U)) + 2558105147674438050U) + aOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = ((aWandererG + RotL64(aIngress, 13U)) + 15856662514774702561U) + aNonceWordG;
            aOrbiterF = (((aWandererH + RotL64(aPrevious, 34U)) + RotL64(aCarry, 35U)) + 13346869226246584582U) + aNonceWordF;
            aOrbiterB = ((((aWandererA + RotL64(aScatter, 23U)) + RotL64(aCarry, 53U)) + 7632111846116243973U) + aOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1]) + aNonceWordA;
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 3U)) + 2102101361626976279U) + aNonceWordB;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 5605968705067851563U) + aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 6842483186584326681U) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 11344798544990575365U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 5559797213819425064U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 12422313931331576759U;
            aOrbiterG = RotL64((aOrbiterG * 7399849122565913401U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 2751024420047872601U) + aOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 11031320239359798610U;
            aOrbiterI = RotL64((aOrbiterI * 8607639453141148025U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 14366375309473793217U) + aNonceWordI;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 11971479429768505316U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10063001532313098203U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 3947595951884469542U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 17882767922372770896U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3361906348965810211U), 21U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterH, 51U);
            aIngress = aIngress + (RotL64(aOrbiterB, 34U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterF, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 13U) + RotL64(aOrbiterI, 29U)) + aOrbiterB) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 28U) + RotL64(aOrbiterG, 51U)) + aOrbiterF);
            aWandererG = aWandererG + (((((RotL64(aPrevious, 53U) + RotL64(aOrbiterG, 3U)) + aOrbiterH) + RotL64(aCarry, 29U)) + aNonceWordJ) + aWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterH, 43U)) + aNonceWordH) + aWandererUpdateSaltD[((aIndex + 6U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 37U) + aOrbiterI) + RotL64(aOrbiterG, 14U)) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererI, 46U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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

void TwistExpander_Boxing_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x87C0E8CB248872A1ULL + 0xDFF48F44660EDE76ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xCFDF3D32EED0840BULL + 0xE250A2E0739A6CADULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xEC4C8338C863AC53ULL + 0xBC63CA7B5C04F78FULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xB897EC977135ACBBULL + 0xD679E97F0E96C7D8ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x8C35BF41F5CAD2C5ULL + 0x9DEE09A6E9242491ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xB14D1357939C45BDULL + 0x870443AB67A00CCAULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xF6D9C982FEE506D1ULL + 0x84861112A8EABEDBULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xC5F81AE36A7939C3ULL + 0xB7F70BA6A3FE7FABULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xA5AB4B54C9A0771BULL + 0x90F8129F6660780AULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xFDF148C3FD37EC4BULL + 0xA44A0B3E9AA77CA3ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xA1F0CAA551983987ULL + 0xDE05F6CF503EB7A8ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xD9421A4BF74C4471ULL + 0xF71CA65B4DCA065BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xF55A980E7EBA7069ULL + 0x8887C4F11656F78EULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xFF355AAC282BFB11ULL + 0xE6C3D1EF3FE190B3ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xBB25EA6B90A918E1ULL + 0x8FDFD819ADFE5312ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xD6E4042517926D97ULL + 0x8C5AB6B4422A1FE5ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 4609U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((aIndex + 4665U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 4163U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2680U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3338U)) & S_BLOCK1], 20U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 610U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aIngress, 21U)) ^ (RotL64(aCarry, 52U) ^ RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterC = (aWandererI + RotL64(aPrevious, 27U)) + 13296600294247799698U;
            aOrbiterF = (((aWandererK + RotL64(aCross, 60U)) + RotL64(aCarry, 21U)) + 5818503518080877515U) + aNonceWordG;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 19U)) + RotL64(aCarry, 47U)) + 6735784238734173597U;
            aOrbiterJ = (aWandererE + RotL64(aIngress, 39U)) + 7368398209488856201U;
            aOrbiterH = (((aWandererF + RotL64(aScatter, 51U)) + 961734029066455638U) + aOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordH;
            aOrbiterB = (((aWandererA + RotL64(aIngress, 13U)) + RotL64(aCarry, 35U)) + 797011946660892011U) + aOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = (aWandererG + RotL64(aCross, 5U)) + 12841876018396622350U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 16213253970483895623U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 15186950557113470375U) ^ aOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4647470430467908107U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 5117930310827477341U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 12265429373166094162U;
            aOrbiterH = RotL64((aOrbiterH * 1522823535151532249U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 13920531346698601568U) + aOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 14695405206998211456U;
            aOrbiterB = RotL64((aOrbiterB * 13950964363414164279U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 7851960904825938443U) + aOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 9501511171732550190U;
            aOrbiterF = RotL64((aOrbiterF * 5614164120361489613U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 5663365182245722077U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 9607860124321315555U;
            aOrbiterC = RotL64((aOrbiterC * 3461820361914280601U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 18171052650586819280U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 3442698321538580861U) ^ aNonceWordF;
            aOrbiterJ = RotL64((aOrbiterJ * 6317525514963824829U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 1491052813469258970U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterA) ^ 3956599824067616133U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 2928600779267623085U), 35U);
            //
            aIngress = RotL64(aOrbiterJ, 14U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 43U) + aOrbiterJ) + RotL64(aOrbiterA, 23U));
            aWandererF = aWandererF + (((RotL64(aIngress, 53U) + RotL64(aOrbiterH, 43U)) + aOrbiterB) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 35U) + aOrbiterF) + RotL64(aOrbiterB, 58U)) + aNonceWordM);
            aWandererA = aWandererA + ((((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterF, 29U)) + RotL64(aCarry, 37U)) + aWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterA, 3U)) + aOrbiterB) + aNonceWordN);
            aWandererK = aWandererK + ((((RotL64(aScatter, 12U) + aOrbiterJ) + RotL64(aOrbiterC, 37U)) + aNonceWordB) + aWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterG, 13U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + RotL64(aWandererB, 28U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 11661U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((aIndex + 11965U)) & S_BLOCK1], 43U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 15437U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 9036U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 13402U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 13603U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 12835U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCross, 53U)) ^ (RotL64(aIngress, 41U) + RotL64(aCarry, 20U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterJ = (((aWandererF + RotL64(aScatter, 41U)) + RotL64(aCarry, 5U)) + 16183871922837164759U) + aNonceWordN;
            aOrbiterH = (((aWandererI + RotL64(aPrevious, 47U)) + RotL64(aCarry, 57U)) + 7002058258090219055U) + aOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = (((aWandererG + RotL64(aCross, 27U)) + RotL64(aCarry, 27U)) + 5650868611888303705U) + aOrbiterAssignSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = ((aWandererH + RotL64(aIngress, 3U)) + 11899839660943876690U) + aNonceWordJ;
            aOrbiterE = (aWandererC + RotL64(aScatter, 21U)) + 15349649504488111111U;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 53U)) + 14060149569086744970U) + aNonceWordP;
            aOrbiterG = (aWandererA + RotL64(aCross, 60U)) + 12920917574225030112U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 2831994965175330135U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 18312543585028439192U) ^ aOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11618182708195744321U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 11657562205118394239U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 10850792819281246052U;
            aOrbiterJ = RotL64((aOrbiterJ * 10663100544207879337U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 17810371216216125323U) + aNonceWordD;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 7963413941144223128U) ^ aOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 534217972450595401U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 5498715358793875584U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterB) ^ 9256727548911651373U) ^ aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterD = RotL64((aOrbiterD * 10498848323914000989U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 17246360111302191699U) + aNonceWordE;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 18309978718113983369U;
            aOrbiterH = RotL64((aOrbiterH * 18267472694666221077U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 3100998994319502921U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 8129301860291235970U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17847033539279176187U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 1889641029473279114U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 16538494307002917945U;
            aOrbiterE = RotL64((aOrbiterE * 8081488217920885783U), 13U);
            //
            aIngress = RotL64(aOrbiterJ, 58U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + (RotL64(aOrbiterE, 51U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 5U) + aOrbiterG) + RotL64(aOrbiterH, 3U)) + aNonceWordK);
            aWandererI = aWandererI + ((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 34U)) + aOrbiterE);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 48U) + RotL64(aOrbiterB, 13U)) + aOrbiterG) + aNonceWordO);
            aWandererG = aWandererG + (((RotL64(aCross, 41U) + aOrbiterD) + RotL64(aOrbiterE, 47U)) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 53U)) + aOrbiterJ);
            aWandererA = aWandererA + (((((RotL64(aScatter, 29U) + RotL64(aOrbiterE, 41U)) + aOrbiterH) + RotL64(aCarry, 13U)) + aNonceWordL) + aWandererUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterE, 23U)) + aOrbiterB) + aWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 60U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 39U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 17817U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneA[((aIndex + 21840U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aExpandLaneB[((aIndex + 17925U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneA[((aIndex + 16776U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21929U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 20722U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 23566U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aIngress, 30U)) + (RotL64(aPrevious, 57U) + RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 13U)) + RotL64(aCarry, 39U)) + 5131645209694953015U;
            aOrbiterE = (((aWandererA + RotL64(aIngress, 3U)) + 12070391048835379854U) + aOrbiterAssignSaltE[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordL;
            aOrbiterF = ((aWandererH + RotL64(aCross, 21U)) + 2604295836242338724U) + aNonceWordD;
            aOrbiterA = (aWandererB + RotL64(aScatter, 37U)) + 14042039029284001596U;
            aOrbiterD = (((aWandererK + RotL64(aIngress, 53U)) + RotL64(aCarry, 23U)) + 8914654543854559327U) + aOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 43U)) + 2185619407969359869U;
            aOrbiterI = (((aWandererG + RotL64(aScatter, 30U)) + RotL64(aCarry, 57U)) + 5187406295103352574U) + aNonceWordE;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 8022832481290871217U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 8783061916740573472U) ^ aNonceWordH;
            aOrbiterF = RotL64((aOrbiterF * 3309891377744201773U), 43U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterA) + 10711028365596196301U) + aOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1]) + aNonceWordA;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 13387065038269133571U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12444578026365205255U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 11187001318931801582U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 14191473173276034019U;
            aOrbiterA = RotL64((aOrbiterA * 2491253922434756431U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 16207761776716426435U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 9677408414452078760U;
            aOrbiterJ = RotL64((aOrbiterJ * 5487303383095129949U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 17812460332794370649U) + aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 7736423148554132028U;
            aOrbiterI = RotL64((aOrbiterI * 15588733747232852555U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 17293203944059014763U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 13487243633338010243U) ^ aOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9468688858740539095U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 15979293016815060755U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 17645215484691359547U) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 1449450767288733995U), 11U);
            //
            aIngress = RotL64(aOrbiterI, 53U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterJ, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aIngress, 23U) + aOrbiterD) + RotL64(aOrbiterJ, 13U)) + aNonceWordO);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 30U) + RotL64(aOrbiterF, 35U)) + aOrbiterJ) + RotL64(aCarry, 57U)) + aNonceWordM);
            aWandererA = aWandererA ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterA, 5U)) + aOrbiterD);
            aWandererG = aWandererG + ((RotL64(aScatter, 41U) + RotL64(aOrbiterG, 58U)) + aOrbiterF);
            aWandererB = aWandererB ^ ((RotL64(aCross, 47U) + aOrbiterG) + RotL64(aOrbiterI, 51U));
            aWandererE = aWandererE + (((((RotL64(aScatter, 3U) + RotL64(aOrbiterJ, 19U)) + aOrbiterA) + RotL64(aCarry, 43U)) + aNonceWordF) + aWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterG, 41U)) + aNonceWordB) + aWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 18U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 23U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 28886U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((aIndex + 26927U)) & S_BLOCK1], 10U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 25041U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneC[((aIndex + 28333U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31252U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24577U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 25216U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 50U) + RotL64(aPrevious, 5U)) ^ (RotL64(aCross, 23U) + RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterA = (aWandererE + RotL64(aScatter, 37U)) + 6733949564325516029U;
            aOrbiterK = ((aWandererK + RotL64(aCross, 53U)) + 7304098437143918796U) + aOrbiterAssignSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = (((aWandererG + RotL64(aIngress, 3U)) + RotL64(aCarry, 39U)) + 3923949518391777800U) + aNonceWordH;
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 19U)) + 14243591003388927124U) + aNonceWordO;
            aOrbiterJ = (aWandererB + RotL64(aCross, 27U)) + 18329498724605410406U;
            aOrbiterI = (((aWandererC + RotL64(aScatter, 44U)) + RotL64(aCarry, 57U)) + 13118172167747037249U) + aNonceWordI;
            aOrbiterG = ((((aWandererH + RotL64(aPrevious, 13U)) + RotL64(aCarry, 19U)) + 5272025143849174212U) + aOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordB;
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 16075917179214318424U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 15263590648674658399U;
            aOrbiterB = RotL64((aOrbiterB * 9918239923411740337U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 13730046728289525921U) + aNonceWordE;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 7703141464499623408U;
            aOrbiterK = RotL64((aOrbiterK * 5886009900621521987U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 1382279753822135359U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 2973369221699098292U;
            aOrbiterF = RotL64((aOrbiterF * 7440242040663550631U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 11578274119583013219U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 3419411247737896674U;
            aOrbiterA = RotL64((aOrbiterA * 17814942652262802991U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 2582783513078999303U) + aOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 3959762790273529677U;
            aOrbiterJ = RotL64((aOrbiterJ * 383974377372162751U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 465795011576934604U) + aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 17880826624185821135U) ^ aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4445949147592860913U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 10819659185349413173U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterG) ^ 17298208553586835030U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterI = RotL64((aOrbiterI * 1965860510614222093U), 53U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterA, 60U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + RotL64(aOrbiterK, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterB, 4U)) + aOrbiterJ);
            aWandererC = aWandererC + ((((RotL64(aCross, 11U) + aOrbiterI) + RotL64(aOrbiterK, 13U)) + aNonceWordN) + aWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 26U) + RotL64(aOrbiterB, 57U)) + aOrbiterK) + aWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterF, 41U)) + aOrbiterA) + RotL64(aCarry, 13U)) + aNonceWordJ);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterI, 19U)) + aOrbiterA);
            aWandererE = aWandererE + (((RotL64(aCross, 57U) + RotL64(aOrbiterF, 29U)) + aOrbiterJ) + RotL64(aCarry, 37U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 51U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererC, 58U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + RotL64(aWandererE, 37U);
            aCarry = aCarry + RotL64(aIngress, 46U);
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

void TwistExpander_Boxing_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xA2FBAF4973C77B63ULL + 0xFB795407976DA0DFULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xD1801391188E3EB9ULL + 0x9B798A8FDFB48A7CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xE6E41DDC60C6D679ULL + 0x93BFB56328B572CDULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB6408CD79F4DFA73ULL + 0x827394AE05810E8EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA1A1C833A70202C7ULL + 0xE0C699855136940CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xE874A51DFFF83C07ULL + 0xD2248FE06C493BB5ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xF693A1F9DE59DF9DULL + 0x83A173FA55CEDBC1ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xA5022429E4A130EBULL + 0xF299A0ACFC9FAB63ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x9111DF0FCFDB7279ULL + 0xDC03DD3AB3FC38C7ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x9F77A6D53369FDCFULL + 0xBD0B48B945F53043ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xE33B924B4B8F35B9ULL + 0xC48551ADE4E48FFBULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xA0C2B2DCBC11782FULL + 0x87B67BD3D6E2CF8BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xD51B4650801740BFULL + 0xAF722166D5320C02ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x85C39DD6EDDAABF9ULL + 0xEEC713CDC052F9EEULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xD81093E22EAF8191ULL + 0xF50160789632D004ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xB93544F20BAD3745ULL + 0xA0AE0A7E466E9DE1ULL);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 3460U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((aIndex + 2302U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 585U)) & S_BLOCK1], 18U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 4387U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneD[((aIndex + 4005U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 54U) ^ RotL64(aCarry, 21U)) + (RotL64(aCross, 41U) ^ RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterB = (((aWandererA + RotL64(aScatter, 35U)) + RotL64(aCarry, 5U)) + 9888431329297626900U) + aOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 43U)) + 2937735167534624403U) + aNonceWordI;
            aOrbiterC = ((aWandererD + RotL64(aCross, 57U)) + RotL64(aCarry, 27U)) + 17626022970343789617U;
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 19U)) + RotL64(aCarry, 57U)) + 5665660859333693743U;
            aOrbiterD = (((aWandererH + RotL64(aScatter, 27U)) + 1060537034632076669U) + aOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1]) + aNonceWordE;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 6U)) + 743777763907175800U) + aNonceWordO;
            aOrbiterF = (aWandererC + RotL64(aCross, 51U)) + 5744905970181808845U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 3545351394494002180U) + aNonceWordN;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 4877547088414106007U;
            aOrbiterC = RotL64((aOrbiterC * 5416792889338547109U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 11669378338379598445U) + aOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 2961072441706158212U;
            aOrbiterD = RotL64((aOrbiterD * 2677988507090705371U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 13984945589234919765U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 1433097875470903205U;
            aOrbiterI = RotL64((aOrbiterI * 451996840039906781U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 716415411025451152U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 8542286150858297810U) ^ aNonceWordK;
            aOrbiterK = RotL64((aOrbiterK * 9139015340823332449U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 12932391786479661299U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 14005503313299177013U;
            aOrbiterB = RotL64((aOrbiterB * 802663466907819743U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 9382792812676318046U) + aOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 5138554251079724724U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6386016499265056247U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 8522380066269546172U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 11825536408101906458U;
            aOrbiterF = RotL64((aOrbiterF * 17042837108792016849U), 19U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterC, 39U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 60U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aCross, 51U) + aOrbiterI) + RotL64(aOrbiterJ, 19U)) + aNonceWordH);
            aWandererA = aWandererA + ((((RotL64(aIngress, 37U) + aOrbiterI) + RotL64(aOrbiterF, 35U)) + RotL64(aCarry, 51U)) + aNonceWordP);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterJ, 47U));
            aWandererD = aWandererD + (((RotL64(aScatter, 21U) + RotL64(aOrbiterC, 57U)) + aOrbiterB) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 28U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aIngress, 44U) + aOrbiterD) + RotL64(aOrbiterK, 5U)) + aWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 11U)) + aOrbiterK) + aNonceWordJ) + aWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (RotL64(aWandererC, 46U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aFireLaneA[((aIndex + 8467U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneC[((aIndex + 10488U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 7633U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9541U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 5989U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 7608U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 53U)) ^ (RotL64(aPrevious, 22U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 27U)) + 10038936806177516123U) + aOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = (((aWandererJ + RotL64(aScatter, 36U)) + RotL64(aCarry, 5U)) + 1773168435195292638U) + aOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aCross, 11U)) + 10655711161526628072U) + aNonceWordA;
            aOrbiterK = (((aWandererA + RotL64(aIngress, 43U)) + RotL64(aCarry, 29U)) + 14422295664639740437U) + aNonceWordB;
            aOrbiterI = (((aWandererH + RotL64(aCross, 3U)) + RotL64(aCarry, 53U)) + 4125228715513159576U) + aNonceWordD;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 21U)) + 3670449653158650845U) + aNonceWordJ;
            aOrbiterE = (aWandererG + RotL64(aScatter, 51U)) + 17553727567180813057U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 5111401772713882743U) + aNonceWordM;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 7688573124662314413U) ^ aOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10846442063022821393U), 27U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterI) + 9438375825507814395U) + aOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1]) + aNonceWordP;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 14177477039902118886U) ^ aOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6467406626985022537U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 16329942595859623928U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 3990536794006836672U;
            aOrbiterD = RotL64((aOrbiterD * 579024714339065373U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 5072881436583180756U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 16789727877867289997U;
            aOrbiterK = RotL64((aOrbiterK * 8766246302636197905U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 17313956922306689438U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 11530878396329822041U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11356860047841383129U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 3612616532321160196U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 4172189825359187763U) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 12938945495299393177U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 8677279703778052804U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 1912172980909479362U;
            aOrbiterI = RotL64((aOrbiterI * 10053289257955474143U), 11U);
            //
            aIngress = RotL64(aOrbiterI, 3U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 28U));
            aIngress = aIngress + RotL64(aOrbiterD, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterA, 41U)) + aOrbiterF);
            aWandererB = aWandererB + (((RotL64(aCross, 51U) + RotL64(aOrbiterH, 29U)) + aOrbiterD) + aNonceWordE);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterA, 11U)) + aWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 37U) + aOrbiterH) + RotL64(aOrbiterI, 48U)) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 12U) + RotL64(aOrbiterK, 35U)) + aOrbiterI) + aNonceWordK) + aWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 3U)) + aOrbiterE) + RotL64(aCarry, 27U)) + aNonceWordF);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterD, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 46U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 14216U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneD[((aIndex + 13318U)) & S_BLOCK1], 14U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 16008U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 14318U)) & S_BLOCK1], 14U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 15599U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCross, 58U)) ^ (RotL64(aCarry, 11U) ^ RotL64(aIngress, 29U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 47U)) + 7075016829833562104U;
            aOrbiterI = ((((aWandererG + RotL64(aIngress, 57U)) + RotL64(aCarry, 13U)) + 8783765886115517036U) + aOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1]) + aNonceWordN;
            aOrbiterH = (aWandererD + RotL64(aCross, 4U)) + 2996723892384565829U;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 41U)) + RotL64(aCarry, 35U)) + 9494134707342189476U;
            aOrbiterB = ((((aWandererA + RotL64(aPrevious, 35U)) + RotL64(aCarry, 53U)) + 5052642981395679904U) + aOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordD;
            aOrbiterG = ((aWandererI + RotL64(aCross, 19U)) + 8766787055127962238U) + aNonceWordM;
            aOrbiterK = (aWandererE + RotL64(aIngress, 13U)) + 4467211954388738079U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 8030255604633658608U) + aNonceWordE;
            aOrbiterH = (((aOrbiterH ^ aOrbiterJ) ^ 16962408063455702251U) ^ aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 11171737929747471631U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 3768222186567699076U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 14930990410207899871U;
            aOrbiterB = RotL64((aOrbiterB * 10930005786146268241U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 14179761938395502502U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 1879084742719898108U) ^ aOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16783034788172670121U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 5535012408925981515U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 12792553516710295939U) ^ aNonceWordH;
            aOrbiterI = RotL64((aOrbiterI * 8577530993755159329U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 8979253163346099252U) + aNonceWordP;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 5559189896063990740U) ^ aOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8832485423727331621U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 13937564337299044079U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 2393376759689394948U) ^ aOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2352815657830413941U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 12647519563697356479U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 10946871249960389549U;
            aOrbiterG = RotL64((aOrbiterG * 6272580371881237173U), 21U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 57U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + (RotL64(aOrbiterH, 23U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterB, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterG, 5U)) + aOrbiterH);
            aWandererG = aWandererG + ((((RotL64(aIngress, 50U) + RotL64(aOrbiterJ, 37U)) + aOrbiterG) + RotL64(aCarry, 23U)) + aNonceWordK);
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterI, 23U)) + aOrbiterC) + aNonceWordF) + aWandererUpdateSaltB[((aIndex + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterC, 29U)) + aOrbiterH);
            aWandererD = aWandererD + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterG, 46U)) + aOrbiterK);
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 57U)) + aOrbiterB) + aNonceWordI) + aWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 34U));
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 29U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 16877U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneC[((aIndex + 17198U)) & S_BLOCK1], 12U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 17993U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 16977U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneD[((aIndex + 20856U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 50U) ^ RotL64(aCross, 37U)) ^ (RotL64(aCarry, 21U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterE = ((aWandererG + RotL64(aScatter, 53U)) + 5697928251815176134U) + aNonceWordF;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 35U)) + 337587740689259575U) + aNonceWordL;
            aOrbiterH = ((((aWandererB + RotL64(aCross, 29U)) + RotL64(aCarry, 29U)) + 4927686903263973950U) + aOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1]) + aNonceWordC;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 20U)) + RotL64(aCarry, 13U)) + 3742409032569801033U;
            aOrbiterD = (((aWandererI + RotL64(aScatter, 5U)) + RotL64(aCarry, 41U)) + 1608092659172197650U) + aNonceWordP;
            aOrbiterA = (aWandererC + RotL64(aCross, 41U)) + 15848744267145717509U;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 13U)) + 15300174177963339253U) + aOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 14162868453323648628U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 12020167069983729869U) ^ aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2071080217680099017U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 16259538291658723956U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 8516686212464112245U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4731296903548893627U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 3722184575520553132U) + aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 5663609293306386784U;
            aOrbiterE = RotL64((aOrbiterE * 14364218128780764749U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 15265344442454471986U) + aNonceWordD;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 3050323350098829515U) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 5890624677162388135U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 1093356813820599238U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 15167726103772238440U) ^ aNonceWordK;
            aOrbiterC = RotL64((aOrbiterC * 5719466863561311069U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 15170797965325981472U) + aNonceWordM;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 17826286701992981628U;
            aOrbiterB = RotL64((aOrbiterB * 11186808881726573677U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 14710892030473425181U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 397194787697553904U;
            aOrbiterA = RotL64((aOrbiterA * 14368930300818752833U), 51U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 21U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 30U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 50U) + aOrbiterE) + RotL64(aOrbiterB, 35U)) + aNonceWordJ);
            aWandererA = aWandererA + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 47U)) + aOrbiterD) + RotL64(aCarry, 11U)) + aNonceWordG);
            aWandererB = aWandererB ^ (((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterC, 56U)) + aNonceWordA);
            aWandererI = aWandererI + ((((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 53U)) + aWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterD, 3U)) + aNonceWordO) + aWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterB, 21U)) + aOrbiterC);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterI, 29U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 21U));
            aCarry = aCarry + RotL64(aWandererC, 58U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aExpandLaneB[((aIndex + 22226U)) & S_BLOCK1], 41U) ^ RotL64(aFireLaneB[((aIndex + 26107U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25463U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneA[((aIndex + 26737U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 52U) ^ RotL64(aCross, 5U)) ^ (RotL64(aCarry, 19U) + RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterJ = ((((aWandererF + RotL64(aIngress, 35U)) + RotL64(aCarry, 41U)) + 2558105147674438050U) + aOrbiterAssignSaltE[((aIndex + 18U)) & S_SALT1]) + aNonceWordG;
            aOrbiterC = (aWandererI + RotL64(aCross, 27U)) + 15856662514774702561U;
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 43U)) + RotL64(aCarry, 11U)) + 13346869226246584582U;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 53U)) + RotL64(aCarry, 57U)) + 7632111846116243973U;
            aOrbiterF = (((aWandererB + RotL64(aIngress, 14U)) + 2102101361626976279U) + aOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1]) + aNonceWordE;
            aOrbiterE = (aWandererC + RotL64(aScatter, 5U)) + 5605968705067851563U;
            aOrbiterA = ((aWandererD + RotL64(aCross, 21U)) + 6842483186584326681U) + aNonceWordK;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 5559797213819425064U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterJ) ^ 12422313931331576759U) ^ aOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterH = RotL64((aOrbiterH * 7399849122565913401U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 2751024420047872601U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 11031320239359798610U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8607639453141148025U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 14366375309473793217U) + aNonceWordL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 11971479429768505316U;
            aOrbiterJ = RotL64((aOrbiterJ * 10063001532313098203U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 3947595951884469542U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 17882767922372770896U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3361906348965810211U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 513871456983509223U) + aNonceWordH;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 5951677013597794294U;
            aOrbiterC = RotL64((aOrbiterC * 8508629569649935293U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 437626309049021931U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 466674061172005705U;
            aOrbiterA = RotL64((aOrbiterA * 1310502572084891157U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 12362602809233133718U) + aNonceWordA;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 10525852878882195702U;
            aOrbiterE = RotL64((aOrbiterE * 17755022180514914325U), 37U);
            //
            aIngress = RotL64(aOrbiterC, 53U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + RotL64(aOrbiterF, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterC, 47U)) + aOrbiterD) + aNonceWordD);
            aWandererB = aWandererB + (((((RotL64(aScatter, 39U) + RotL64(aOrbiterH, 27U)) + aOrbiterC) + RotL64(aCarry, 57U)) + aNonceWordI) + aWandererUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterH, 11U)) + aOrbiterJ);
            aWandererF = aWandererF + (((RotL64(aPrevious, 60U) + RotL64(aOrbiterH, 53U)) + aOrbiterE) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterC, 38U)) + aOrbiterF);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 29U) + aOrbiterC) + RotL64(aOrbiterJ, 21U)) + aNonceWordN) + aWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterD, 5U)) + aOrbiterA) + aNonceWordB);
            //
            aCarry = aCarry + (RotL64(aWandererF, 48U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 53U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 27857U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneA[((aIndex + 32002U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29658U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((aIndex + 28028U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 5U)) + (RotL64(aCross, 24U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 47U)) + 8866844335448071821U) + aOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterF = (((aWandererK + RotL64(aCross, 13U)) + RotL64(aCarry, 19U)) + 15159698739856430085U) + aNonceWordD;
            aOrbiterA = (((aWandererC + RotL64(aScatter, 27U)) + RotL64(aCarry, 41U)) + 9582805772989594633U) + aNonceWordF;
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 3U)) + 1438538239931588373U) + aNonceWordO;
            aOrbiterH = ((aWandererE + RotL64(aCross, 21U)) + 10862044156620436139U) + aOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aIngress, 41U)) + RotL64(aCarry, 3U)) + 13682173320058164615U;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 34U)) + 8351013291045977592U) + aNonceWordK;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 15777857431516633916U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 16178966745333885377U) ^ aOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7545129923202147703U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 9031889187993001617U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 6308472367425865347U;
            aOrbiterH = RotL64((aOrbiterH * 17118710301967158153U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 642109145903321046U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 9186268569255318035U;
            aOrbiterD = RotL64((aOrbiterD * 10714674348507516749U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 6091345356803675860U) + aNonceWordL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 13218507921880873749U;
            aOrbiterJ = RotL64((aOrbiterJ * 15415157927185637717U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 4266652275234474616U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 4391422098164506195U) ^ aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17634679403195085867U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 5160682323243635577U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 10351728852161347404U) ^ aOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11105410036471745951U), 11U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterJ) + 3950932176454814023U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordC;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 9536466386833427441U) ^ aNonceWordB;
            aOrbiterK = RotL64((aOrbiterK * 18064984243491293435U), 51U);
            //
            aIngress = RotL64(aOrbiterD, 5U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterF, 21U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterG, 14U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aScatter, 58U) + aOrbiterD) + RotL64(aOrbiterH, 41U)) + aWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 47U)) + aOrbiterA) + RotL64(aCarry, 13U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterH, 21U)) + aOrbiterF) + aNonceWordE);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 53U)) + aOrbiterG) + RotL64(aCarry, 27U)) + aWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 21U) + aOrbiterH) + RotL64(aOrbiterA, 5U)) + aNonceWordI);
            aWandererA = aWandererA + (((RotL64(aIngress, 41U) + aOrbiterK) + RotL64(aOrbiterA, 11U)) + aNonceWordH);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterK, 30U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (RotL64(aWandererB, 30U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 43U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_Boxing_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xD3E4C8808CE584A5ULL + 0xCA61946BE7E9D688ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x9FE2CE6C18A87055ULL + 0xAD81A650ED2ED11EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xE434A7C71970CD87ULL + 0xB5765E4BAB9C738CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xBD9D46FBA635AE37ULL + 0xA1C01DA433C38DF4ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xEB573EA2E5DE17EDULL + 0x80A4A82C3F871404ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xE658BF80DCF9E6C9ULL + 0x9A98C7E1DE122C3FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x92531BC555245D47ULL + 0x8E2AFD99D249691CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x862841A61EA3E09DULL + 0xB349E50DA607148EULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xBEF35AADC64CED0FULL + 0x882503A0E0CB25E6ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xF256357719F5047DULL + 0xAB6B9DCA1C66EA80ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xD8468A6B2E30AD89ULL + 0x9F6C39743D9F1174ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xBC500B017E8B34B1ULL + 0xA1B0814B6A9E36B0ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x9A05CDE5DA42938FULL + 0x9B35B0755EDE0DDCULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xC076FD4D31CC2ED5ULL + 0xC6A9D079A1EEA56BULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xDEC5D5B285E14DB5ULL + 0xE4C4B468EF4B5976ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xFA1824DFD3954ABFULL + 0xF4036AC05DAE64FFULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 6078U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((aIndex + 7538U)) & S_BLOCK1], 54U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 4071U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2860U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 6739U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 3073U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCarry, 58U)) + (RotL64(aCross, 11U) + RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterA = (aWandererJ + RotL64(aCross, 57U)) + 10915618884692072446U;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 20U)) + 12634922308499254909U) + aOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = (((aWandererA + RotL64(aScatter, 43U)) + 6533934734564499389U) + aOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordM;
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 29U)) + 6744203303756105181U;
            aOrbiterC = (aWandererC + RotL64(aScatter, 53U)) + 13086782386652045658U;
            aOrbiterK = ((aWandererI + RotL64(aCross, 6U)) + RotL64(aCarry, 5U)) + 5693840533331397822U;
            aOrbiterI = (((aWandererG + RotL64(aIngress, 51U)) + RotL64(aCarry, 37U)) + 1803663542535024611U) + aNonceWordN;
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 47U)) + RotL64(aCarry, 23U)) + 3597219300593287708U;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 3U)) + 1429753448204448904U) + aNonceWordH;
            aOrbiterF = (aWandererE + RotL64(aScatter, 13U)) + 17229017825587322715U;
            aOrbiterG = (aWandererF + RotL64(aCross, 23U)) + 1137574712801062932U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 2401991077004083378U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 1332473247826139292U;
            aOrbiterH = RotL64((aOrbiterH * 15029831858261506447U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 11730946340796899885U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 15319163439700390962U;
            aOrbiterC = RotL64((aOrbiterC * 1349242001887975499U), 11U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterK) + 4744141870145159917U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordI;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 6067132201862688684U;
            aOrbiterE = RotL64((aOrbiterE * 6046100687757836027U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 14991509179286371800U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 4342608825699398682U;
            aOrbiterJ = RotL64((aOrbiterJ * 10240526103933275875U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 3727521409410742075U) + aNonceWordB;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 3302027219498304367U) ^ aNonceWordE;
            aOrbiterD = RotL64((aOrbiterD * 12153634588200479559U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 6039539483340398858U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 2902581519976937051U;
            aOrbiterI = RotL64((aOrbiterI * 2057584328877854239U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 12332784713738947242U) + aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 13761272577223712786U;
            aOrbiterA = RotL64((aOrbiterA * 14930145045480030821U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 2947946397617043735U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 11107014023853644521U;
            aOrbiterB = RotL64((aOrbiterB * 15030903626191481831U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 6212403196992771516U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 16107261731677426470U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13764822942405295129U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 8414111492161335472U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 3625937496991123221U;
            aOrbiterF = RotL64((aOrbiterF * 1736741235159600739U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 5466667339391480293U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 10915618884692072446U) ^ aNonceWordO;
            aOrbiterG = RotL64((aOrbiterG * 14719282928172086707U), 29U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterB, 39U);
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 19U));
            aIngress = aIngress + (RotL64(aOrbiterG, 10U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterD, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 11U) + aOrbiterG) + RotL64(aOrbiterH, 51U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 19U) + aOrbiterE) + RotL64(aOrbiterI, 23U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterC, 30U)) + aNonceWordF);
            aWandererF = aWandererF + ((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 13U)) + aOrbiterF);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 30U) + aOrbiterB) + RotL64(aOrbiterD, 47U)) + aWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 53U) + aOrbiterK) + RotL64(aOrbiterC, 43U)) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterD, 41U)) + aOrbiterC);
            aWandererE = aWandererE + ((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterG, 5U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 28U) + RotL64(aOrbiterE, 3U)) + aOrbiterC) + aWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 21U)) + aOrbiterJ) + RotL64(aCarry, 27U)) + aNonceWordG);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 26U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererG, 14U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 56U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 23U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 15681U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneC[((aIndex + 10867U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 11870U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneC[((aIndex + 12588U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9878U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 16069U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 16356U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 6U) + RotL64(aIngress, 27U)) ^ (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterH = (aWandererH + RotL64(aCross, 11U)) + 15920462086654025436U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 14U)) + 487844076858004017U) + aOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 19U)) + RotL64(aCarry, 3U)) + 14502883786442630566U;
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 43U)) + 3787107318658233674U) + aNonceWordJ;
            aOrbiterA = (aWandererC + RotL64(aCross, 57U)) + 12548777544693755491U;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 27U)) + RotL64(aCarry, 43U)) + 4907309444075181683U;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 29U)) + 18342396700266492072U;
            aOrbiterC = (((aWandererI + RotL64(aIngress, 41U)) + RotL64(aCarry, 53U)) + 13503051997624242670U) + aOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aCross, 39U)) + 17845742460521374571U) + aNonceWordB;
            aOrbiterB = (aWandererF + RotL64(aIngress, 34U)) + 8640887211877858169U;
            aOrbiterE = (aWandererE + RotL64(aPrevious, 53U)) + 5273913123709097537U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 17756844173695563883U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 6713055830729302951U;
            aOrbiterD = RotL64((aOrbiterD * 2832836748513174311U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 5106468334224035972U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 10228769728713526172U;
            aOrbiterG = RotL64((aOrbiterG * 9760310686414358435U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 7687649520668883142U) + aOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 7757480627354711605U;
            aOrbiterH = RotL64((aOrbiterH * 7222553727737349209U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 10876291698508634557U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 8149278085586014186U;
            aOrbiterA = RotL64((aOrbiterA * 8577133863470695381U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 15592893988925610485U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 8639028256640537165U) ^ aOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1880655276432963955U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 475660347892196219U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 1903736092401853832U;
            aOrbiterE = RotL64((aOrbiterE * 8486318978769094799U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 12463250192809450953U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 7253918448601703982U;
            aOrbiterK = RotL64((aOrbiterK * 3821034106528009129U), 3U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterH) + 5171661020093804486U) + aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1]) + aNonceWordM;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 11627344933828324146U;
            aOrbiterB = RotL64((aOrbiterB * 5388047063152043277U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 6206801139131132815U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 9221302203943031377U;
            aOrbiterI = RotL64((aOrbiterI * 12912049016813367241U), 19U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterE) + 1798857939965423979U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordP;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 5476854168685641232U) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 3884216989250294213U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 2816659151953455230U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 15920462086654025436U;
            aOrbiterJ = RotL64((aOrbiterJ * 17843161654734820613U), 21U);
            //
            aIngress = RotL64(aOrbiterC, 29U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 37U));
            aIngress = aIngress + (RotL64(aOrbiterG, 21U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 44U));
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aIngress, 19U) + aOrbiterH) + RotL64(aOrbiterK, 21U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 26U) + aOrbiterI) + RotL64(aOrbiterK, 13U));
            aWandererC = aWandererC + ((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterG, 48U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterG, 57U)) + aOrbiterJ) + aNonceWordI);
            aWandererD = aWandererD + (((RotL64(aScatter, 5U) + RotL64(aOrbiterC, 23U)) + aOrbiterA) + aWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 21U) + aOrbiterB) + RotL64(aOrbiterF, 53U));
            aWandererB = aWandererB + (((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterG, 28U)) + aNonceWordN);
            aWandererI = aWandererI ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterF, 43U)) + aOrbiterA);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 40U) + RotL64(aOrbiterD, 41U)) + aOrbiterH) + RotL64(aCarry, 27U)) + aWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 23U) + aOrbiterH) + RotL64(aOrbiterJ, 51U));
            aWandererE = aWandererE + (((RotL64(aCross, 29U) + RotL64(aOrbiterC, 19U)) + aOrbiterF) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 18U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererJ, 39U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 22077U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((aIndex + 20371U)) & S_BLOCK1], 27U));
            aIngress ^= (RotL64(aExpandLaneB[((aIndex + 17686U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20883U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 17961U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 23758U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 20129U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCross, 5U)) + (RotL64(aCarry, 21U) ^ RotL64(aIngress, 42U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 19U)) + 6361545377408870615U;
            aOrbiterC = (aWandererH + RotL64(aCross, 12U)) + 2967245486744774933U;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 5U)) + RotL64(aCarry, 47U)) + 3836634268482850139U;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 51U)) + 7691642115360086297U) + aNonceWordO;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 57U)) + 16479280384178279281U) + aOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aScatter, 29U)) + 2901468732552539249U) + aNonceWordD;
            aOrbiterB = (((aWandererK + RotL64(aCross, 39U)) + RotL64(aCarry, 23U)) + 2600353867755647475U) + aOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = ((aWandererD + RotL64(aIngress, 21U)) + RotL64(aCarry, 19U)) + 5666596904781510956U;
            aOrbiterI = (aWandererB + RotL64(aScatter, 35U)) + 16108791609267427553U;
            aOrbiterA = (aWandererE + RotL64(aCross, 27U)) + 8389926875737312112U;
            aOrbiterK = ((aWandererC + RotL64(aIngress, 46U)) + 1689501721163024426U) + aNonceWordA;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 11721701506949917719U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 3963842745030140473U) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 6692473494944919373U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 8510538243472109368U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 18281865214102080387U;
            aOrbiterE = RotL64((aOrbiterE * 1351546966368884609U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 2259725140963665123U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 11652011949557979650U) ^ aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11260100762113295037U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 1116085424226174473U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 4725260319270802912U) ^ aOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4697109059565450269U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 7348945429843437036U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 1249234309180653260U;
            aOrbiterF = RotL64((aOrbiterF * 3136745255820405881U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 12463505532573389603U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 2304125977906510386U;
            aOrbiterC = RotL64((aOrbiterC * 9960816714791454421U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 2178037443783425551U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 11712110130079307683U;
            aOrbiterI = RotL64((aOrbiterI * 9797864956200779505U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 10703510612147312252U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 18155460326242413483U;
            aOrbiterK = RotL64((aOrbiterK * 6903953708987478723U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 5753486645345036069U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 2314216774606770444U;
            aOrbiterA = RotL64((aOrbiterA * 14002639533287566667U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 9662599462788305323U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 3805101172359199209U) ^ aNonceWordJ;
            aOrbiterB = RotL64((aOrbiterB * 10669315962181581543U), 23U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterK) + 1073926575064224947U) + aOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1]) + aNonceWordI;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 6361545377408870615U;
            aOrbiterJ = RotL64((aOrbiterJ * 10685650563722188837U), 43U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 57U);
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 53U));
            aIngress = aIngress + (RotL64(aOrbiterA, 24U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 39U));
            aIngress = aIngress + RotL64(aOrbiterD, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 51U) + aOrbiterI) + RotL64(aOrbiterE, 56U));
            aWandererA = aWandererA + ((((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 3U)) + aOrbiterF) + RotL64(aCarry, 53U)) + aWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 3U) + aOrbiterB) + RotL64(aOrbiterC, 47U)) + aNonceWordK);
            aWandererB = aWandererB + ((RotL64(aIngress, 58U) + RotL64(aOrbiterC, 5U)) + aOrbiterJ);
            aWandererH = aWandererH ^ ((RotL64(aCross, 23U) + aOrbiterG) + RotL64(aOrbiterF, 37U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterH, 53U)) + aOrbiterJ) + aNonceWordL);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterG, 21U)) + aOrbiterC);
            aWandererF = aWandererF + ((((RotL64(aIngress, 44U) + aOrbiterD) + RotL64(aOrbiterI, 51U)) + RotL64(aCarry, 57U)) + aWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 41U) + aOrbiterI) + RotL64(aOrbiterK, 27U));
            aWandererC = aWandererC + ((RotL64(aCross, 27U) + RotL64(aOrbiterK, 18U)) + aOrbiterD);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterA, 39U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + (RotL64(aWandererF, 10U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 20U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 28799U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((aIndex + 27345U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 32202U)) & S_BLOCK1], 20U) ^ RotL64(aWorkLaneC[((aIndex + 25953U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26151U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31785U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 28719U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCross, 35U)) ^ (RotL64(aCarry, 10U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterC = (aWandererJ + RotL64(aScatter, 12U)) + 11177787645248006236U;
            aOrbiterI = (aWandererK + RotL64(aIngress, 35U)) + 3808340254579817169U;
            aOrbiterB = (aWandererD + RotL64(aCross, 57U)) + 828030667598518279U;
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 29U)) + 16177835921238398371U) + aOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aIngress, 23U)) + 5518747735458708741U;
            aOrbiterH = (((aWandererH + RotL64(aCross, 19U)) + RotL64(aCarry, 29U)) + 17346319082399995165U) + aNonceWordJ;
            aOrbiterA = (((aWandererA + RotL64(aScatter, 41U)) + 6397156921893030937U) + aOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1]) + aNonceWordK;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 39U)) + RotL64(aCarry, 11U)) + 15559381654710713582U;
            aOrbiterF = (((aWandererB + RotL64(aIngress, 43U)) + RotL64(aCarry, 23U)) + 940404446491415088U) + aNonceWordH;
            aOrbiterG = (aWandererC + RotL64(aScatter, 27U)) + 8047166032048732645U;
            aOrbiterJ = (aWandererI + RotL64(aCross, 10U)) + 4688468645859470491U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 3710878044770337260U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 116343189456629220U;
            aOrbiterB = RotL64((aOrbiterB * 5637725064169289339U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 883908030159391659U) + aNonceWordF;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 18058691521694880482U;
            aOrbiterD = RotL64((aOrbiterD * 3132200449123497619U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 17521015077103586117U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 3668332225435714918U;
            aOrbiterH = RotL64((aOrbiterH * 12658899101297839881U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 12229480388278883300U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 16206524049491531816U;
            aOrbiterF = RotL64((aOrbiterF * 11122340196620859805U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 5743265849441077466U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 2812293020719282236U) ^ aOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8903956475200417109U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 13718364781538837074U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 861529717259766236U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17019744777211266685U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 4862687502126693872U) + aNonceWordP;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 7722024283321020761U) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 18086944039541060829U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 8205803118233399853U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 15130160926615050422U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1454552751453996765U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 667469191899263617U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 18048970185163843471U;
            aOrbiterJ = RotL64((aOrbiterJ * 1800698970568737425U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 508102841337488721U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 3803840516662727630U;
            aOrbiterE = RotL64((aOrbiterE * 8477778555284121637U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 17055028117762299436U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 11177787645248006236U;
            aOrbiterC = RotL64((aOrbiterC * 12457019014051206805U), 47U);
            //
            aIngress = RotL64(aOrbiterG, 18U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterH, 30U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterH, 3U)) + aOrbiterA);
            aWandererB = aWandererB + (((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 23U)) + aOrbiterK) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterH, 43U)) + aOrbiterC);
            aWandererG = aWandererG + ((((RotL64(aScatter, 24U) + aOrbiterA) + RotL64(aOrbiterE, 39U)) + aNonceWordL) + aWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterC, 58U)) + aOrbiterD);
            aWandererA = aWandererA + (((RotL64(aIngress, 39U) + aOrbiterJ) + RotL64(aOrbiterE, 51U)) + aNonceWordA);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterA, 13U)) + aWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 35U) + aOrbiterE) + RotL64(aOrbiterI, 27U)) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 53U) + aOrbiterB) + RotL64(aOrbiterF, 47U)) + aNonceWordO);
            aWandererE = aWandererE + ((RotL64(aScatter, 47U) + aOrbiterB) + RotL64(aOrbiterG, 60U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 12U) + RotL64(aOrbiterF, 41U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 56U));
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + RotL64(aWandererD, 37U);
            aCarry = aCarry + RotL64(aIngress, 40U);
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

void TwistExpander_Boxing_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xCC1CFDF214AEB811ULL + 0xFCCE55F06892719BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x8DD831A47DAAEADBULL + 0xA268F84CFBD6E3B1ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xA853CFD71A14E48BULL + 0xD45BF168DB65F3D4ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xD82C07198F108F07ULL + 0x87B51A87C0306717ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xE904D4F4AA9BF721ULL + 0xCC4BAF9381553D26ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xAFF98A595DA1B335ULL + 0x917238838BC486FBULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xCAB9DD911A18D0C9ULL + 0x84208342A86DDEAEULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xC3909D27C35F65A7ULL + 0xA9AC914C862DD5A3ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x94590CFEBFF2A4FDULL + 0xFC50DB3C2B03741DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xAE6D1341959A17C7ULL + 0xD82F2F19AF6608E5ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xC2944615A63F4EFFULL + 0xEDDF3E48911DC2A1ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x88A54DE7962C2005ULL + 0xD788305988D6F331ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xE5AC6A75569B802DULL + 0x85BE80FB3592B31CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xB7E2F67628E939EFULL + 0xC231547393A64994ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x8654CA10628FB7A9ULL + 0xC1B71D1CB2D9C632ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xA01A1540C8AA4BEDULL + 0xFC25C2C56A19DF3DULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 5987U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneB[((aIndex + 3814U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 4628U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 694U)) & S_BLOCK1], 36U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 7970U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 7310U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCross, 44U)) ^ (RotL64(aPrevious, 11U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterD = ((aWandererK + RotL64(aScatter, 41U)) + RotL64(aCarry, 41U)) + 1708250618750199233U;
            aOrbiterE = (aWandererF + RotL64(aPrevious, 19U)) + 12009147777553691142U;
            aOrbiterK = ((aWandererE + RotL64(aCross, 58U)) + 8393982703399156592U) + aOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = (((aWandererI + RotL64(aIngress, 53U)) + RotL64(aCarry, 29U)) + 3247327098356831221U) + aOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aCross, 29U)) + 3403590155376353737U) + aNonceWordD;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 35U)) + 18197244558104735044U) + aNonceWordE;
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 46U)) + 3096253642040701606U) + aNonceWordN;
            aOrbiterC = (aWandererD + RotL64(aIngress, 13U)) + 8012692688785412179U;
            aOrbiterJ = (((aWandererG + RotL64(aPrevious, 3U)) + RotL64(aCarry, 53U)) + 17531946907545680745U) + aNonceWordG;
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 17687695944270225817U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 16147773866007628769U;
            aOrbiterK = RotL64((aOrbiterK * 16926442582711557877U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 18244641303026196497U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 8839160526348897457U;
            aOrbiterA = RotL64((aOrbiterA * 14268021129087663397U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 10599266240854068246U) + aNonceWordC;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 2056723540756216155U;
            aOrbiterF = RotL64((aOrbiterF * 13311591601230386375U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 4629354220460621284U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 9505955649473204942U;
            aOrbiterI = RotL64((aOrbiterI * 17775391885312236187U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 17078153810088721310U) + aNonceWordO;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 9470436761716263000U;
            aOrbiterE = RotL64((aOrbiterE * 5431855497250357229U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 3305863413630104742U) + aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 14377172434239576161U;
            aOrbiterH = RotL64((aOrbiterH * 6880176890091033423U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 415687827894226513U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 16975319836893760993U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6597144958013976445U), 5U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterK) + 12707054129431596074U) + aOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1]) + aNonceWordI;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 8974182792497231239U) ^ aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7874658957269462717U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 10826131924322955095U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 4168545139712703154U;
            aOrbiterD = RotL64((aOrbiterD * 10305904857550051705U), 43U);
            //
            aIngress = RotL64(aOrbiterJ, 60U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 19U));
            aIngress = aIngress + RotL64(aOrbiterE, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 43U) + RotL64(aOrbiterK, 47U)) + aOrbiterF) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 56U) + aOrbiterD) + RotL64(aOrbiterF, 37U));
            aWandererG = aWandererG + ((RotL64(aIngress, 37U) + RotL64(aOrbiterA, 58U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterI, 11U)) + aOrbiterD) + aNonceWordM) + aWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 51U) + RotL64(aOrbiterE, 23U)) + aOrbiterI);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 27U) + aOrbiterD) + RotL64(aOrbiterH, 5U));
            aWandererD = aWandererD + (((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 29U)) + aOrbiterC) + aNonceWordP);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 20U) + RotL64(aOrbiterH, 41U)) + aOrbiterI);
            aWandererC = aWandererC + ((((RotL64(aCross, 47U) + RotL64(aOrbiterF, 52U)) + aOrbiterJ) + RotL64(aCarry, 3U)) + aWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 30U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + RotL64(aWandererE, 11U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 13507U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneC[((aIndex + 13649U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 8312U)) & S_BLOCK1], 30U) ^ RotL64(aFireLaneC[((aIndex + 11812U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 10485U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 15688U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 15469U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aIngress, 5U)) ^ (RotL64(aCarry, 20U) + RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterD = ((aWandererC + RotL64(aIngress, 3U)) + 4622023259121087483U) + aNonceWordO;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 58U)) + 10253505250223501352U) + aOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = (((aWandererF + RotL64(aPrevious, 23U)) + RotL64(aCarry, 11U)) + 17133877904420462669U) + aNonceWordE;
            aOrbiterB = ((aWandererJ + RotL64(aCross, 39U)) + 6162827793741796700U) + aNonceWordB;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 19U)) + RotL64(aCarry, 19U)) + 9610986424765907615U;
            aOrbiterC = (aWandererB + RotL64(aCross, 47U)) + 11210747154264753754U;
            aOrbiterF = (((aWandererG + RotL64(aIngress, 11U)) + RotL64(aCarry, 39U)) + 16554205219580654546U) + aNonceWordN;
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 30U)) + 10352576357413766388U) + aOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aIngress, 43U)) + 3651845783283479752U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 18145542190463500476U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 5415609566767162857U;
            aOrbiterH = RotL64((aOrbiterH * 6474184559323816389U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 2033734872464201570U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 3507213117125813345U;
            aOrbiterJ = RotL64((aOrbiterJ * 5453058336688881113U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 8716253393049851856U) + aNonceWordJ;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 695984869565941856U;
            aOrbiterF = RotL64((aOrbiterF * 8377921610764044735U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 7661578828878284931U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 906654265099155956U) ^ aOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8117625377607536949U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 6050049984731254612U) + aNonceWordH;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 17882717590338190821U) ^ aOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10807367411402733215U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 4996521991532815957U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 4246460672800604436U;
            aOrbiterD = RotL64((aOrbiterD * 12047466401960824903U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 8700148116452518842U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 10039050281847466206U) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 11884791271239660157U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 4513844680425845372U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 3037563127442815153U;
            aOrbiterE = RotL64((aOrbiterE * 18363509277992292407U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 1005237931570968724U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 1373258132025712065U;
            aOrbiterI = RotL64((aOrbiterI * 10458020799382532395U), 47U);
            //
            aIngress = RotL64(aOrbiterA, 5U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 54U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + RotL64(aOrbiterH, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 23U) + aOrbiterB) + RotL64(aOrbiterJ, 4U));
            aWandererI = aWandererI + (((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 23U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterF, 39U)) + aNonceWordK);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 56U) + aOrbiterC) + RotL64(aOrbiterJ, 43U)) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 23U)) + aOrbiterE);
            aWandererE = aWandererE + ((((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterC, 35U)) + aNonceWordF) + aWandererUpdateSaltE[((aIndex + 8U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 27U) + aOrbiterC) + RotL64(aOrbiterI, 29U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 14U) + RotL64(aOrbiterA, 19U)) + aOrbiterD) + aWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 41U) + aOrbiterF) + RotL64(aOrbiterJ, 50U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (RotL64(aWandererI, 12U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + RotL64(aWandererF, 39U);
            aCarry = aCarry + RotL64(aIngress, 30U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 17178U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneA[((aIndex + 20759U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 20248U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20811U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 17795U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 24300U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 20966U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 37U) ^ RotL64(aCarry, 21U)) + (RotL64(aCross, 3U) ^ RotL64(aPrevious, 54U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterD = (aWandererI + RotL64(aCross, 27U)) + 2672739400294801233U;
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 3U)) + 8475624545015101850U;
            aOrbiterC = (aWandererF + RotL64(aIngress, 39U)) + 1252755112289831257U;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 50U)) + RotL64(aCarry, 47U)) + 7938039507649183387U;
            aOrbiterI = ((aWandererG + RotL64(aCross, 13U)) + RotL64(aCarry, 29U)) + 8167413146948861022U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 19U)) + RotL64(aCarry, 11U)) + 17712313989694374353U;
            aOrbiterB = ((aWandererK + RotL64(aIngress, 23U)) + 7637042279892596975U) + aOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aScatter, 35U)) + 15770412950033467341U) + aNonceWordL;
            aOrbiterG = (((aWandererH + RotL64(aPrevious, 60U)) + 3951812021898608685U) + aOrbiterAssignSaltD[((aIndex + 6U)) & S_SALT1]) + aNonceWordI;
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 8656983621098246507U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterD) ^ 17943342344730687317U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterC = RotL64((aOrbiterC * 16495519451034883813U), 35U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterE) + 3087677463651608668U) + aOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1]) + aNonceWordF;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 16493240011924342788U;
            aOrbiterI = RotL64((aOrbiterI * 16898479041530771871U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 7750923317452683057U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 2185924841611106546U;
            aOrbiterB = RotL64((aOrbiterB * 708072658250726381U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 14676868738946722416U) + aNonceWordG;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 6849098251696302393U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2599806275837778069U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 17817755047153606419U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 9900465270314068757U;
            aOrbiterK = RotL64((aOrbiterK * 9267925873983176685U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 11380000891112113701U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 15930503831156546113U;
            aOrbiterH = RotL64((aOrbiterH * 14450535035065393845U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 5439183530402949780U) + aNonceWordM;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 3731802052051181843U;
            aOrbiterG = RotL64((aOrbiterG * 7739775058947333169U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 14432344583247783600U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 16192098795467501636U;
            aOrbiterD = RotL64((aOrbiterD * 6285466374319549047U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 1523272672673940290U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 7462092373525113574U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15067751170235540679U), 3U);
            //
            aIngress = RotL64(aOrbiterH, 40U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 21U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aIngress, 44U) + RotL64(aOrbiterG, 24U)) + aOrbiterE) + aNonceWordA);
            aWandererF = aWandererF + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterC, 29U)) + aOrbiterK);
            aWandererE = aWandererE ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterE, 37U)) + aOrbiterK);
            aWandererG = aWandererG + (((((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 51U)) + aOrbiterC) + RotL64(aCarry, 21U)) + aNonceWordH) + aWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 48U) + aOrbiterI) + RotL64(aOrbiterD, 57U)) + aNonceWordE) + aWandererUpdateSaltA[((aIndex + 8U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 29U) + aOrbiterD) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 35U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterJ, 13U)) + aNonceWordD);
            aWandererH = aWandererH + ((RotL64(aCross, 39U) + RotL64(aOrbiterG, 47U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 42U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 6U));
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + RotL64(aWandererD, 51U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 25966U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneA[((aIndex + 26534U)) & S_BLOCK1], 27U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 32377U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneC[((aIndex + 26560U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32705U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30726U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 25061U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 51U) ^ RotL64(aCarry, 6U)) ^ (RotL64(aCross, 39U) + RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterF = (aWandererD + RotL64(aCross, 53U)) + 6654158889644956636U;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 4U)) + 9045779659363991870U;
            aOrbiterG = (((aWandererF + RotL64(aScatter, 47U)) + RotL64(aCarry, 11U)) + 3888897662136993491U) + aNonceWordH;
            aOrbiterK = ((aWandererA + RotL64(aIngress, 21U)) + RotL64(aCarry, 3U)) + 6882016842864459345U;
            aOrbiterC = (aWandererJ + RotL64(aScatter, 13U)) + 15601891715956172291U;
            aOrbiterE = (((aWandererI + RotL64(aCross, 35U)) + RotL64(aCarry, 51U)) + 5176811598629335350U) + aNonceWordF;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 39U)) + 12519945150889074325U) + aNonceWordL;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 28U)) + 4552583214397603278U) + aOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aScatter, 57U)) + 14225482701804864688U) + aOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 5485298070606280363U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 11237713257388094289U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11032429223099413011U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 14340345895626142788U) + aNonceWordG;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 16275167270553643347U) ^ aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7308578867128951199U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 14041860597556520250U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 1436068974197066343U;
            aOrbiterB = RotL64((aOrbiterB * 3938460345031496843U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 11483155566419547004U) + aNonceWordA;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 4608508534724289325U;
            aOrbiterI = RotL64((aOrbiterI * 13461385011638899485U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 2389196334288832895U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 4062682330273866602U;
            aOrbiterD = RotL64((aOrbiterD * 8787682133271101901U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 5655656046585592034U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 7977947821249746880U;
            aOrbiterK = RotL64((aOrbiterK * 10082104644185964787U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 11653718118543974168U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 5456429682072377614U) ^ aOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12504180638665296649U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 12457179652004203574U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 445821754230182952U;
            aOrbiterF = RotL64((aOrbiterF * 16043092621697786393U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 12429505513284703263U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 12480745784412363537U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 643617210585287593U), 13U);
            //
            aIngress = RotL64(aOrbiterC, 14U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 27U) + aOrbiterG) + RotL64(aOrbiterI, 57U)) + aNonceWordM);
            aWandererC = aWandererC + (((RotL64(aCross, 39U) + RotL64(aOrbiterD, 30U)) + aOrbiterE) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 22U) + aOrbiterF) + RotL64(aOrbiterB, 5U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 51U) + aOrbiterK) + RotL64(aOrbiterD, 43U)) + RotL64(aCarry, 39U)) + aWandererUpdateSaltF[((aIndex + 28U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterD, 19U)) + aOrbiterG);
            aWandererK = aWandererK + (((RotL64(aIngress, 43U) + RotL64(aOrbiterI, 37U)) + aOrbiterF) + aNonceWordK);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterB, 23U)) + aOrbiterI) + aWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 47U) + RotL64(aOrbiterG, 47U)) + aOrbiterC);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 10U) + RotL64(aOrbiterA, 52U)) + aOrbiterD) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 6U));
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererC, 37U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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

void TwistExpander_Boxing_Arx::KDF_B_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xD98FFAB99FBA2D67ULL + 0xDBA648D35CD519FCULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xC2ACB06965CAB5E7ULL + 0x902F020BC2B7CBD4ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xEE333F4D71325B87ULL + 0xEBFE1E40DED0F37CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xA3626F964590AE5BULL + 0xA4E44EA905E24FF3ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xCADFDAB66C74C10DULL + 0xC1A86DB56C5704EDULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xB90B34B1E1100EC3ULL + 0xCCA56259F8D535AFULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xDE53CFCE2CCA40BDULL + 0x89E8A6AC15061192ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x9056D4FA1DE4016FULL + 0xFF6AE948EBBA78F9ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xFCF75A2C0D465709ULL + 0xF3440A5DEBC6FC08ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xF3B6574FABB9E3EFULL + 0x896E53F800F43E67ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xD96E4EAD3211C6A1ULL + 0xDF9BFAB9066ADB4EULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xD8B648B120F84D57ULL + 0xDF237BB4803B4940ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xFFD90868B58A564DULL + 0x854ECC543C8A2A5AULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xF0D233AA517D30D1ULL + 0x930C8BA9293B1E67ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xAD45F2C866F1A155ULL + 0x984E90EF4CB79227ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xEC1CD80644854D8BULL + 0xEF36B2B320EDD462ULL);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 688U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((aIndex + 1932U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 1620U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 2403U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 2420U)) & S_BLOCK1], 48U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 7145U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCarry, 57U)) + (RotL64(aCross, 23U) + RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterI = (aWandererK + RotL64(aPrevious, 11U)) + 8375305456876489425U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 19U)) + RotL64(aCarry, 57U)) + 16193562952772453047U;
            aOrbiterF = ((aWandererC + RotL64(aCross, 35U)) + RotL64(aCarry, 13U)) + 18088652458594816223U;
            aOrbiterK = (((aWandererB + RotL64(aIngress, 57U)) + RotL64(aCarry, 27U)) + 767344788620249944U) + aNonceWordL;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 44U)) + 7705194930396368752U) + aNonceWordB;
            aOrbiterG = (((aWandererI + RotL64(aCross, 3U)) + 3829736891311272834U) + aOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordK;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 27U)) + 9881681671347640061U) + aOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 1721196560190164264U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 3002652618388454213U;
            aOrbiterF = RotL64((aOrbiterF * 15289749311593032657U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 9811621464004005202U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterA) ^ 5652598941069986530U) ^ aOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterH = RotL64((aOrbiterH * 4797973356708091621U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 6250499348327316328U) + aOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 16025054277615264530U;
            aOrbiterG = RotL64((aOrbiterG * 16446892258704281903U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 13800298546867243172U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 12256104592865905782U) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 16983140179497142713U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 17817225416918329229U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 17738671327352776217U;
            aOrbiterA = RotL64((aOrbiterA * 393488251327705063U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 6816031224188400541U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 16989563985059237014U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8677884225771717797U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 16891524847268207549U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 1833508573940405571U) ^ aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9709196587703979539U), 57U);
            //
            aIngress = RotL64(aOrbiterA, 29U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 21U));
            aIngress = aIngress + RotL64(aOrbiterG, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterK, 26U)) + RotL64(aCarry, 37U)) + aNonceWordM) + aWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterG, 3U)) + aOrbiterC) + aNonceWordC);
            aWandererE = aWandererE + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterH, 57U)) + aOrbiterF) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 19U)) + aOrbiterI) + aNonceWordF);
            aWandererI = aWandererI + ((RotL64(aScatter, 6U) + aOrbiterK) + RotL64(aOrbiterC, 41U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 27U) + aOrbiterF) + RotL64(aOrbiterC, 47U)) + aNonceWordH);
            aWandererK = aWandererK + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterH, 35U)) + aOrbiterC) + aWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 14U));
            aCarry = aCarry + RotL64(aWandererG, 39U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 9386U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneC[((aIndex + 8379U)) & S_BLOCK1], 39U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 10901U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 13228U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8703U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 12881U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 13481U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCross, 57U)) ^ (RotL64(aPrevious, 19U) + RotL64(aCarry, 42U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterG = ((((aWandererF + RotL64(aPrevious, 35U)) + RotL64(aCarry, 53U)) + 3105313968748067810U) + aOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1]) + aNonceWordD;
            aOrbiterI = (((aWandererG + RotL64(aScatter, 13U)) + RotL64(aCarry, 13U)) + 9977249451119627064U) + aNonceWordK;
            aOrbiterE = ((aWandererA + RotL64(aCross, 5U)) + 17941392803495349366U) + aOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = (aWandererI + RotL64(aIngress, 57U)) + 4279533326705471133U;
            aOrbiterA = (aWandererD + RotL64(aCross, 27U)) + 13983828966811580039U;
            aOrbiterK = (aWandererE + RotL64(aPrevious, 51U)) + 3983490984234810378U;
            aOrbiterB = (((aWandererB + RotL64(aIngress, 42U)) + RotL64(aCarry, 41U)) + 308786542215259956U) + aNonceWordJ;
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 8443607695364427037U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 14939626441464340668U) ^ aNonceWordE;
            aOrbiterE = RotL64((aOrbiterE * 16793255020331774983U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 9350693577306121110U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 1717071159396961752U;
            aOrbiterI = RotL64((aOrbiterI * 11062480662625054525U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 15911765265202100610U) + aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 14898546272333182767U;
            aOrbiterG = RotL64((aOrbiterG * 2674900543810733067U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 3560903518513465868U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 5367062725726860234U;
            aOrbiterK = RotL64((aOrbiterK * 8521908836601319553U), 21U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterE) + 15233321480618877327U) + aOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 9288449812290126074U) ^ aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6815298520404038519U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 5504840529511585676U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 6825598386801620046U;
            aOrbiterB = RotL64((aOrbiterB * 11666542445846250077U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 6433024450721339470U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 97934156644929458U;
            aOrbiterA = RotL64((aOrbiterA * 8630530773006923215U), 5U);
            //
            aIngress = RotL64(aOrbiterE, 13U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterK, 28U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aScatter, 29U) + aOrbiterE) + RotL64(aOrbiterB, 47U)) + RotL64(aCarry, 39U)) + aWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterB, 41U)) + aNonceWordI);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 23U) + aOrbiterE) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 13U)) + aNonceWordG);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterA, 53U)) + aOrbiterG);
            aWandererD = aWandererD + (((RotL64(aCross, 12U) + aOrbiterA) + RotL64(aOrbiterD, 13U)) + aNonceWordB);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterG, 21U)) + aOrbiterK);
            aWandererB = aWandererB + ((((RotL64(aScatter, 41U) + RotL64(aOrbiterK, 60U)) + aOrbiterI) + aNonceWordH) + aWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 28U));
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + RotL64(aWandererF, 35U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 20300U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((aIndex + 18605U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aWorkLaneB[((aIndex + 21332U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((aIndex + 20826U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24020U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 16595U)) & S_BLOCK1], 20U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 22659U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 38U) ^ RotL64(aCarry, 57U)) + (RotL64(aCross, 23U) ^ RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterK = (aWandererD + RotL64(aScatter, 21U)) + 13924571355038625040U;
            aOrbiterA = ((((aWandererH + RotL64(aPrevious, 37U)) + RotL64(aCarry, 41U)) + 16328300979357156658U) + aOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordC;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 11U)) + 3947771961206012461U) + aNonceWordI;
            aOrbiterE = (aWandererI + RotL64(aIngress, 29U)) + 15428284250569311285U;
            aOrbiterC = (((aWandererE + RotL64(aPrevious, 3U)) + 5777369485254032486U) + aOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordF;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 43U)) + RotL64(aCarry, 21U)) + 16813320300717644673U;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 58U)) + RotL64(aCarry, 3U)) + 16689933050200758251U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 1856422419049390708U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 18214498743831925517U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10744120577560529379U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 18278550878494094923U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 797712062039591797U) ^ aNonceWordM;
            aOrbiterJ = RotL64((aOrbiterJ * 7212998747080137625U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 15854849439012341347U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 996882939768167773U;
            aOrbiterC = RotL64((aOrbiterC * 14936703950807908575U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 3005829974130671692U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 8793495343509953906U) ^ aOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14065479348374612031U), 19U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterG) + 7710453029930631112U) + aOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1]) + aNonceWordP;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 9511995836117707047U;
            aOrbiterF = RotL64((aOrbiterF * 7250766204781428201U), 3U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterJ) + 670902975693341744U) + aOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1]) + aNonceWordG;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 9045820304668279777U;
            aOrbiterK = RotL64((aOrbiterK * 18373074917532639027U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 12417212387607119470U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 12816983560669985622U;
            aOrbiterE = RotL64((aOrbiterE * 8406003970221889847U), 11U);
            //
            aIngress = RotL64(aOrbiterA, 37U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 60U));
            aIngress = aIngress + RotL64(aOrbiterE, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aPrevious, 57U) + aOrbiterE) + RotL64(aOrbiterC, 5U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 41U) + aOrbiterC) + RotL64(aOrbiterJ, 13U)) + aWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 30U) + RotL64(aOrbiterE, 51U)) + aOrbiterF) + aNonceWordE);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 37U)) + aOrbiterK);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 21U)) + aOrbiterG) + RotL64(aCarry, 29U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 21U) + aOrbiterA) + RotL64(aOrbiterF, 27U));
            aWandererD = aWandererD + (((((RotL64(aScatter, 5U) + RotL64(aOrbiterG, 58U)) + aOrbiterF) + RotL64(aCarry, 5U)) + aNonceWordO) + aWandererUpdateSaltF[((aIndex + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 28U));
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + RotL64(aWandererC, 3U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 26922U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((aIndex + 31307U)) & S_BLOCK1], 60U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 26393U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 31427U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30169U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30484U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 25395U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 21U) ^ RotL64(aIngress, 35U)) + (RotL64(aPrevious, 51U) + RotL64(aCross, 4U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterI = (((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 35U)) + 15920462086654025436U) + aNonceWordH;
            aOrbiterC = (((aWandererB + RotL64(aPrevious, 60U)) + RotL64(aCarry, 23U)) + 487844076858004017U) + aNonceWordM;
            aOrbiterG = (((aWandererI + RotL64(aCross, 37U)) + RotL64(aCarry, 51U)) + 14502883786442630566U) + aNonceWordE;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 23U)) + 3787107318658233674U) + aOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = ((aWandererK + RotL64(aScatter, 13U)) + 12548777544693755491U) + aOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = (aWandererC + RotL64(aIngress, 53U)) + 4907309444075181683U;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 47U)) + 18342396700266492072U) + aNonceWordJ;
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 13503051997624242670U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 17845742460521374571U) ^ aNonceWordF;
            aOrbiterG = RotL64((aOrbiterG * 1366356786138085155U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 8640887211877858169U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 5273913123709097537U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1661149444148461791U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 17756844173695563883U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 6713055830729302951U) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 2832836748513174311U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 5106468334224035972U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 10228769728713526172U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9760310686414358435U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 7687649520668883142U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 7757480627354711605U;
            aOrbiterI = RotL64((aOrbiterI * 7222553727737349209U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 10876291698508634557U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 8149278085586014186U;
            aOrbiterB = RotL64((aOrbiterB * 8577133863470695381U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 15592893988925610485U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 8639028256640537165U;
            aOrbiterH = RotL64((aOrbiterH * 1880655276432963955U), 3U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 29U);
            aIngress = aIngress + (RotL64(aOrbiterB, 48U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterB, 29U)) + aOrbiterJ) + aNonceWordI);
            aWandererK = aWandererK + ((((RotL64(aIngress, 12U) + RotL64(aOrbiterJ, 47U)) + aOrbiterI) + RotL64(aCarry, 43U)) + aNonceWordD);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterH, 19U));
            aWandererA = aWandererA + (((((RotL64(aCross, 19U) + aOrbiterB) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 19U)) + aNonceWordC) + aWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterC, 36U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterH, 57U)) + aNonceWordP) + aWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterB, 11U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + RotL64(aWandererC, 50U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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

void TwistExpander_Boxing_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC;
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
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltB;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xDD1603D82E484695ULL + 0xED845A38613B7E9FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x9D8F0AF37AE58429ULL + 0x92D900AFACAEADF9ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xBFF41375E3F7902DULL + 0xDE4A1FA340A86C8EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x93377D89E67784F7ULL + 0xF7C8903C3FEABD16ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xE0FC8BAE8AA59387ULL + 0x97575D2733B4D7F3ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x962A38CAA75F53B1ULL + 0xFD9100C0B8CB2C2EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xCA2C62C66CA1B02BULL + 0xC6DB0C95387BCD52ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xDC35D5AF58CF84F5ULL + 0xEE99D4EAF338ADBAULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xD7BAECBFBDF5E521ULL + 0xCDB6E1AD79CA1026ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xD8C4A1A7F93FCF5FULL + 0xBD9B4AF0879B8E9BULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xBBF19341D75EDEEDULL + 0x8827A4F4A8FC5FE5ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xE680A7557DCB0879ULL + 0x99F38E756DD808EFULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xED893A98B6C2E08FULL + 0xBB78482B5B4EFEA3ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xEF1E4ADAAC20353DULL + 0x96DCCC919E84BA90ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xD3493230F7293979ULL + 0x85C3FB281E98D068ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x80945809C80FE3B7ULL + 0xDDA23A33AF8448DFULL);
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 1976U)) & W_KEY1], 58U) ^ RotL64(aKeyRowReadB[((aIndex + 174U)) & W_KEY1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 110U)) & W_KEY1], 52U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 1027U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 29U) ^ RotL64(aPrevious, 57U)) + (RotL64(aIngress, 6U) ^ RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 21U)) + RotL64(aCarry, 51U)) + 14823268998003220191U;
            aOrbiterJ = (((aWandererI + RotL64(aIngress, 3U)) + 15295237288788213847U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordA;
            aOrbiterG = ((aWandererK + RotL64(aCross, 58U)) + 16434853402001133899U) + aNonceWordG;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 51U)) + RotL64(aCarry, 3U)) + 7555911304407871631U;
            aOrbiterI = ((((aWandererH + RotL64(aCross, 41U)) + RotL64(aCarry, 35U)) + 14977248264994834620U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordE;
            aOrbiterB = (aWandererG + RotL64(aPrevious, 13U)) + 9707764144919392380U;
            aOrbiterA = (aWandererJ + RotL64(aIngress, 29U)) + 1277304385464681529U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 3089786220465849395U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 3700503853358695085U) ^ aNonceWordM;
            aOrbiterG = RotL64((aOrbiterG * 2079089949442685421U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 3240054112993517371U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 16897532076915366859U) ^ aNonceWordB;
            aOrbiterI = RotL64((aOrbiterI * 4120874717534309035U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 18167359289798364307U) + aNonceWordD;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 8870819278575769863U;
            aOrbiterB = RotL64((aOrbiterB * 9334066154398059075U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 15363069206212330251U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 14858164441499725158U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14931933411393847915U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 5357144808788707522U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 2910681277417754860U;
            aOrbiterE = RotL64((aOrbiterE * 13170868582159347059U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 9824408699018165151U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 368370224788793300U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14358982366258729959U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 7095398304588825115U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterI) ^ 11418879758164313554U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 5983520332639771791U), 43U);
            //
            aIngress = RotL64(aOrbiterI, 14U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + RotL64(aOrbiterA, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 60U) + RotL64(aOrbiterE, 39U)) + aOrbiterB) + aNonceWordF);
            aWandererG = aWandererG ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterA, 47U)) + aOrbiterJ);
            aWandererD = aWandererD + (((RotL64(aIngress, 53U) + RotL64(aOrbiterE, 11U)) + aOrbiterG) + aNonceWordK);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterJ, 23U)) + aPhaseEWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aCross, 39U) + aOrbiterJ) + RotL64(aOrbiterE, 3U)) + RotL64(aCarry, 47U)) + aNonceWordH);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterD, 53U)) + aOrbiterE) + aPhaseEWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 30U)) + aOrbiterI) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 38U));
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + RotL64(aWandererI, 13U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 3753U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 4902U)) & W_KEY1], 35U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 5374U)) & W_KEY1], 11U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 3949U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 27U) + RotL64(aPrevious, 12U)) ^ (RotL64(aIngress, 57U) ^ RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterI = (((aWandererI + RotL64(aIngress, 51U)) + RotL64(aCarry, 41U)) + 1888427424966603593U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aScatter, 11U)) + 5436761445660415091U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (((aWandererE + RotL64(aPrevious, 20U)) + RotL64(aCarry, 5U)) + 17322876217962143270U) + aNonceWordF;
            aOrbiterF = (((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 57U)) + 9728299982740564979U) + aNonceWordN;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 35U)) + 301720335271716921U;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 5U)) + 8069685428854814396U) + aNonceWordD;
            aOrbiterA = ((aWandererA + RotL64(aCross, 43U)) + 1973715500949100991U) + aNonceWordI;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 87666408799854155U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 12195436904339035245U;
            aOrbiterC = RotL64((aOrbiterC * 15427739165893738105U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 4578742069143400295U) + aNonceWordK;
            aOrbiterH = (((aOrbiterH ^ aOrbiterF) ^ 7828776048774876484U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterH = RotL64((aOrbiterH * 4047964518501081039U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 17203146364542781833U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 16913369550858890466U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13534417587921978507U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 9632761514552265402U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 9106637671877341286U;
            aOrbiterI = RotL64((aOrbiterI * 9073709119482640391U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 15423680889126750876U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 6087310684583331882U;
            aOrbiterD = RotL64((aOrbiterD * 8964465129744898619U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 5420955876411796789U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 14166807419730848032U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 442659738632823751U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 8118312450347026824U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 4253043584558403086U;
            aOrbiterB = RotL64((aOrbiterB * 5651748455190536467U), 29U);
            //
            aIngress = RotL64(aOrbiterC, 60U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 5U) + aOrbiterF) + RotL64(aOrbiterH, 29U)) + aNonceWordM);
            aWandererD = aWandererD + ((((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 5U)) + aNonceWordA);
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterC, 39U)) + aNonceWordL) + aPhaseEWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 13U) + RotL64(aOrbiterI, 47U)) + aOrbiterA) + aNonceWordO);
            aWandererK = aWandererK ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterH, 4U)) + aOrbiterA) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterH, 23U)) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 36U) + aOrbiterA) + RotL64(aOrbiterC, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + (RotL64(aWandererI, 6U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aFireLaneB[((aIndex + 7274U)) & S_BLOCK1], 46U) ^ RotL64(aKeyRowReadB[((aIndex + 6342U)) & W_KEY1], 23U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 7194U)) & W_KEY1], 57U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 8121U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 6432U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCarry, 5U)) ^ (RotL64(aPrevious, 20U) + RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterE = (((aWandererD + RotL64(aScatter, 23U)) + RotL64(aCarry, 47U)) + 16922357079016918108U) + aNonceWordL;
            aOrbiterD = (((aWandererB + RotL64(aPrevious, 48U)) + RotL64(aCarry, 29U)) + 11771749797137599131U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = (((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 13U)) + 4635668433708036077U) + aNonceWordP;
            aOrbiterA = (((aWandererC + RotL64(aIngress, 57U)) + 15827952719230577008U) + aPhaseEOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1]) + aNonceWordN;
            aOrbiterI = ((aWandererA + RotL64(aCross, 41U)) + 1495675306110023086U) + aNonceWordK;
            aOrbiterC = (aWandererF + RotL64(aScatter, 29U)) + 7294835466949728365U;
            aOrbiterG = (aWandererG + RotL64(aIngress, 35U)) + 179122461212041978U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 545981421632236251U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterE) ^ 15338259639814630535U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterB = RotL64((aOrbiterB * 14895421566334357871U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 12924313840290895215U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 17846785921286020610U;
            aOrbiterE = RotL64((aOrbiterE * 18309347016029917133U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 5721472794107057875U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 16359630793856870319U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14186771515526698907U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 10614102110239037308U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 16421992251278236531U) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 2561232904676068089U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 8668149834861244963U) + aNonceWordE;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 12699331834360948734U;
            aOrbiterI = RotL64((aOrbiterI * 2249360824172616357U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 4470693178142950471U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 526000656022724741U;
            aOrbiterC = RotL64((aOrbiterC * 16688501462334673493U), 57U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterC) + 6880246132270094141U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordO;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 7126466778855297013U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5692237926830293205U), 3U);
            //
            aIngress = RotL64(aOrbiterE, 3U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 60U));
            aIngress = aIngress + RotL64(aOrbiterG, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((((RotL64(aIngress, 20U) + RotL64(aOrbiterA, 27U)) + aOrbiterC) + RotL64(aCarry, 3U)) + aNonceWordJ) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterI, 35U)) + aOrbiterA) + aNonceWordM);
            aWandererC = aWandererC + ((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterA, 6U));
            aWandererA = aWandererA ^ ((((RotL64(aCross, 13U) + RotL64(aOrbiterA, 13U)) + aOrbiterE) + aNonceWordI) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 41U) + aOrbiterC) + RotL64(aOrbiterG, 53U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterD, 19U)) + aOrbiterE);
            aWandererF = aWandererF + (((RotL64(aCross, 3U) + RotL64(aOrbiterB, 43U)) + aOrbiterD) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 14U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + RotL64(aWandererG, 47U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 10831U)) & S_BLOCK1], 27U) ^ RotL64(aKeyRowReadB[((aIndex + 9994U)) & W_KEY1], 11U));
            aIngress ^= (RotL64(mSource[((aIndex + 8631U)) & S_BLOCK1], 37U) ^ RotL64(aFireLaneA[((aIndex + 10771U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 9124U)) & W_KEY1], 27U) ^ RotL64(aFireLaneB[((aIndex + 9690U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCross, 13U)) ^ (RotL64(aPrevious, 40U) + RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterB = (aWandererK + RotL64(aPrevious, 5U)) + 9107326720193244489U;
            aOrbiterI = (aWandererE + RotL64(aScatter, 11U)) + 10868585484401664145U;
            aOrbiterJ = (((aWandererG + RotL64(aCross, 47U)) + RotL64(aCarry, 3U)) + 13637736741437846622U) + aNonceWordM;
            aOrbiterH = (((aWandererF + RotL64(aIngress, 57U)) + 6130725216183918844U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordL;
            aOrbiterD = (((aWandererC + RotL64(aScatter, 26U)) + RotL64(aCarry, 29U)) + 2063834478521338187U) + aPhaseFOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 19U)) + RotL64(aCarry, 41U)) + 8564870627911949158U;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 37U)) + 6524015751064086390U) + aNonceWordC;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 9874937766875388236U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 14723718409522680894U) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 17379140128833323431U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 13767059954741528279U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 6387608251033722169U;
            aOrbiterH = RotL64((aOrbiterH * 6601902195707980693U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 5391425980008431000U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 11524218415655093779U) ^ aNonceWordP;
            aOrbiterK = RotL64((aOrbiterK * 12508457981779189389U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 155510463350385905U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 10554591788433641311U;
            aOrbiterC = RotL64((aOrbiterC * 5412084824127934293U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 8662160162966241542U) + aNonceWordA;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 5092555636369853727U;
            aOrbiterI = RotL64((aOrbiterI * 433807340167635499U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 7163345798448796101U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 695089002178413267U) ^ aNonceWordF;
            aOrbiterD = RotL64((aOrbiterD * 17302689458565434475U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 5409173939213468972U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 15349690077393827541U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10984681254001609841U), 19U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterD, 43U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 37U));
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterC, 23U)) + aOrbiterB) + aNonceWordH) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 53U) + RotL64(aOrbiterH, 35U)) + aOrbiterK) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterK, 57U));
            aWandererF = aWandererF + (((RotL64(aCross, 35U) + RotL64(aOrbiterC, 3U)) + aOrbiterK) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 60U) + aOrbiterI) + RotL64(aOrbiterB, 43U)) + aNonceWordO);
            aWandererG = aWandererG + (((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 50U)) + aOrbiterJ) + RotL64(aCarry, 11U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterB, 29U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 41U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 60U));
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 13120U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadA[((aIndex + 11074U)) & W_KEY1], 52U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 12829U)) & W_KEY1], 23U) ^ RotL64(mSource[((aIndex + 11060U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 12142U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 12820U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneC[((aIndex + 11527U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aPrevious, 3U)) + (RotL64(aIngress, 21U) ^ RotL64(aCarry, 54U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterE = (aWandererF + RotL64(aPrevious, 35U)) + 15904465836916519864U;
            aOrbiterC = (aWandererE + RotL64(aCross, 19U)) + 17725629806317789307U;
            aOrbiterG = (((aWandererJ + RotL64(aIngress, 13U)) + 13794170125914914828U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordB;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 41U)) + 2149055907476874332U) + aNonceWordE;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 3U)) + RotL64(aCarry, 23U)) + 5342047776745074649U;
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 60U)) + RotL64(aCarry, 47U)) + 8268148484060546838U;
            aOrbiterF = ((((aWandererB + RotL64(aCross, 51U)) + RotL64(aCarry, 11U)) + 10821151364028563719U) + aPhaseFOrbiterAssignSaltE[((aIndex + 18U)) & S_SALT1]) + aNonceWordG;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 4294213820894407378U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 10884726101307943090U;
            aOrbiterG = RotL64((aOrbiterG * 1116128870387229159U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 16432210042202444824U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 15196602644336228055U) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 12680438355124070237U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 14117787670220328165U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 219833877949480215U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10736293047771972173U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 3326396981881473962U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 14918513066311426279U;
            aOrbiterJ = RotL64((aOrbiterJ * 14269763278564574663U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 11795234681370163206U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 3068267285352664813U;
            aOrbiterH = RotL64((aOrbiterH * 15746255933920904619U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 245233356957999496U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 709926406353796673U) ^ aNonceWordF;
            aOrbiterF = RotL64((aOrbiterF * 13627039596842073595U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 5378105439430271038U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 10114555061122044430U;
            aOrbiterE = RotL64((aOrbiterE * 5351295043424885549U), 51U);
            //
            aIngress = RotL64(aOrbiterG, 57U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + RotL64(aOrbiterF, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterC, 21U)) + aOrbiterH) + RotL64(aCarry, 39U)) + aNonceWordK);
            aWandererD = aWandererD ^ (((RotL64(aCross, 43U) + aOrbiterC) + RotL64(aOrbiterG, 37U)) + aNonceWordM);
            aWandererI = aWandererI + ((RotL64(aScatter, 28U) + aOrbiterA) + RotL64(aOrbiterJ, 27U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 13U)) + aOrbiterH);
            aWandererK = aWandererK + ((((RotL64(aScatter, 37U) + aOrbiterC) + RotL64(aOrbiterA, 53U)) + RotL64(aCarry, 5U)) + aNonceWordA);
            aWandererB = aWandererB ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterC, 3U)) + aOrbiterE) + aPhaseFWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 51U) + aOrbiterE) + RotL64(aOrbiterJ, 60U)) + aPhaseFWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 4U));
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 15118U)) & S_BLOCK1], 60U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 15762U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15265U)) & W_KEY1], 47U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 14855U)) & W_KEY1], 20U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 16154U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 14883U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 13873U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCarry, 60U)) + (RotL64(aCross, 11U) ^ RotL64(aPrevious, 29U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterE = (aWandererB + RotL64(aScatter, 29U)) + 3105313968748067810U;
            aOrbiterC = (((aWandererA + RotL64(aPrevious, 23U)) + RotL64(aCarry, 13U)) + 9977249451119627064U) + aNonceWordE;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 3U)) + RotL64(aCarry, 51U)) + 17941392803495349366U;
            aOrbiterK = (aWandererE + RotL64(aIngress, 53U)) + 4279533326705471133U;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 44U)) + 13983828966811580039U) + aNonceWordG;
            aOrbiterI = (((aWandererC + RotL64(aPrevious, 13U)) + 3983490984234810378U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordO;
            aOrbiterJ = ((((aWandererF + RotL64(aIngress, 35U)) + RotL64(aCarry, 29U)) + 308786542215259956U) + aPhaseFOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1]) + aNonceWordB;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 8443607695364427037U) + aNonceWordP;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 14939626441464340668U;
            aOrbiterA = RotL64((aOrbiterA * 16793255020331774983U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 9350693577306121110U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 1717071159396961752U;
            aOrbiterF = RotL64((aOrbiterF * 11062480662625054525U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 15911765265202100610U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterI) ^ 14898546272333182767U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterE = RotL64((aOrbiterE * 2674900543810733067U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 3560903518513465868U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 5367062725726860234U) ^ aNonceWordI;
            aOrbiterC = RotL64((aOrbiterC * 8521908836601319553U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 15233321480618877327U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 9288449812290126074U;
            aOrbiterJ = RotL64((aOrbiterJ * 6815298520404038519U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 5504840529511585676U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 6825598386801620046U;
            aOrbiterK = RotL64((aOrbiterK * 11666542445846250077U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 6433024450721339470U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterJ) ^ 97934156644929458U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 8630530773006923215U), 11U);
            //
            aIngress = RotL64(aOrbiterE, 51U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterC, 58U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 11U) + aOrbiterF) + RotL64(aOrbiterA, 19U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 54U) + aOrbiterE) + RotL64(aOrbiterC, 47U)) + RotL64(aCarry, 47U)) + aPhaseFWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterE, 60U)) + aOrbiterI);
            aWandererF = aWandererF + ((((RotL64(aScatter, 21U) + aOrbiterI) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 29U)) + aNonceWordC);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 27U)) + aOrbiterA) + aPhaseFWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 13U)) + aOrbiterC) + aNonceWordJ);
            aWandererE = aWandererE ^ ((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterI, 3U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 26U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + RotL64(aWandererG, 39U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 16385U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadA[((aIndex + 17542U)) & W_KEY1], 3U));
            aIngress ^= (RotL64(mSource[((aIndex + 17100U)) & S_BLOCK1], 38U) ^ RotL64(aFireLaneA[((aIndex + 16650U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 18919U)) & W_KEY1], 50U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 17607U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16583U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 21U)) + (RotL64(aCross, 5U) ^ RotL64(aIngress, 44U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterE = (((aWandererJ + RotL64(aIngress, 57U)) + RotL64(aCarry, 39U)) + 18087125778766689269U) + aNonceWordP;
            aOrbiterG = (aWandererK + RotL64(aScatter, 27U)) + 13710545066503235196U;
            aOrbiterB = ((aWandererI + RotL64(aCross, 51U)) + RotL64(aCarry, 3U)) + 1701939704736254645U;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 39U)) + RotL64(aCarry, 51U)) + 8064093611384019909U;
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 11U)) + 16623332751533885431U) + aNonceWordF;
            aOrbiterC = (((aWandererE + RotL64(aIngress, 4U)) + 15590129153794910109U) + aPhaseGOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1]) + aNonceWordI;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 19U)) + 7413312683079107383U) + aPhaseGOrbiterAssignSaltE[((aIndex + 24U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 4186064478651458810U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 5501191643940735954U) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 14254804649177125269U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 11064645242200570835U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 13825922087298055833U;
            aOrbiterJ = RotL64((aOrbiterJ * 7529317892716108867U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 5944980709887369970U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 8181136916070569646U;
            aOrbiterG = RotL64((aOrbiterG * 395183021205661827U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 15442336949157292482U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 11580554435240641337U;
            aOrbiterF = RotL64((aOrbiterF * 6654637892858767739U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 11240018128174598322U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 2027565596050777471U;
            aOrbiterK = RotL64((aOrbiterK * 18048186560314431815U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 16425887196883725233U) + aNonceWordB;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 16828683527588834095U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17746289103235902485U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 9923829146479008804U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 6669171007279929454U;
            aOrbiterE = RotL64((aOrbiterE * 681823450939955099U), 21U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterC, 19U);
            aIngress = aIngress + (RotL64(aOrbiterG, 34U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 39U) + aOrbiterG) + RotL64(aOrbiterK, 13U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 21U) + RotL64(aOrbiterE, 35U)) + aOrbiterK) + RotL64(aCarry, 35U)) + aNonceWordL);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 5U) + aOrbiterG) + RotL64(aOrbiterF, 29U)) + aNonceWordC);
            aWandererF = aWandererF + (((RotL64(aIngress, 60U) + RotL64(aOrbiterC, 21U)) + aOrbiterB) + aNonceWordO);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterG, 57U)) + aOrbiterJ) + aPhaseGWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aCross, 11U) + aOrbiterK) + RotL64(aOrbiterC, 4U)) + RotL64(aCarry, 53U)) + aNonceWordM);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterE, 43U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 34U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 19902U)) & S_BLOCK1], 53U) ^ RotL64(mSource[((aIndex + 19349U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aWorkLaneA[((aIndex + 20078U)) & S_BLOCK1], 37U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 19339U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 19534U)) & W_KEY1], 27U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 21219U)) & W_KEY1], 39U));
            aCross ^= (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19418U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneB[((aIndex + 20328U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 54U) ^ RotL64(aIngress, 21U)) ^ (RotL64(aCarry, 5U) + RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 41U)) + RotL64(aCarry, 41U)) + 6381335981879993247U;
            aOrbiterH = ((aWandererA + RotL64(aCross, 35U)) + RotL64(aCarry, 5U)) + 15595429101600023172U;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 5U)) + 5449234297249826461U) + aNonceWordG;
            aOrbiterD = ((((aWandererB + RotL64(aScatter, 21U)) + RotL64(aCarry, 53U)) + 11213734849329731168U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordF;
            aOrbiterJ = (aWandererC + RotL64(aCross, 54U)) + 16438473952464514248U;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 29U)) + 7357872882115186976U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = (aWandererE + RotL64(aIngress, 47U)) + 394402075160738643U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 11112941985410283532U) + aNonceWordB;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 14955125011182736212U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10711684773326395603U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 14770727009821304070U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 11286366598129204910U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15884310771003021989U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 7358400908565425780U) + aNonceWordA;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 15635109923749114761U) ^ aNonceWordI;
            aOrbiterJ = RotL64((aOrbiterJ * 12415152149408700329U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 13826842523738623579U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 1072811298828325231U;
            aOrbiterH = RotL64((aOrbiterH * 9662800288646215083U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 4017334196009350776U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 8812213572751410831U;
            aOrbiterE = RotL64((aOrbiterE * 12744171921566782795U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 6723457786170634403U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 9785583533999417673U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7776915427605471097U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 10265132640322153964U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 8435670887514808087U;
            aOrbiterB = RotL64((aOrbiterB * 2706263045620662131U), 21U);
            //
            aIngress = RotL64(aOrbiterC, 47U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterB, 58U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + RotL64(aOrbiterH, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 44U) + RotL64(aOrbiterB, 47U)) + aOrbiterE);
            aWandererA = aWandererA + (((RotL64(aCross, 5U) + RotL64(aOrbiterB, 28U)) + aOrbiterJ) + RotL64(aCarry, 51U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 51U) + aOrbiterB) + RotL64(aOrbiterC, 19U)) + aNonceWordP);
            aWandererK = aWandererK + (((RotL64(aPrevious, 27U) + aOrbiterB) + RotL64(aOrbiterA, 57U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterA, 5U)) + aOrbiterC) + aNonceWordJ);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 35U) + aOrbiterD) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 27U)) + aPhaseGWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterH, 37U)) + aOrbiterA) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 41U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + RotL64(aWandererJ, 46U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 22992U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadA[((aIndex + 23214U)) & W_KEY1], 30U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 23666U)) & W_KEY1], 19U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 23337U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 24489U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23000U)) & S_BLOCK1], 4U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 23952U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneD[((aIndex + 22202U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCarry, 23U)) + (RotL64(aIngress, 37U) ^ RotL64(aCross, 58U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterE = (((aWandererC + RotL64(aScatter, 13U)) + RotL64(aCarry, 3U)) + 17019646486641172469U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (((aWandererA + RotL64(aPrevious, 57U)) + RotL64(aCarry, 51U)) + 12276141179299971572U) + aNonceWordP;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 29U)) + 3617241694029841555U) + aNonceWordE;
            aOrbiterF = ((aWandererH + RotL64(aCross, 21U)) + RotL64(aCarry, 21U)) + 6967963401259371737U;
            aOrbiterI = (aWandererG + RotL64(aIngress, 51U)) + 6340709284279891017U;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 5U)) + 456065368903896482U) + aNonceWordB;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 36U)) + 17686765719908116203U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 1322045955429785736U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 5163772703302372887U;
            aOrbiterC = RotL64((aOrbiterC * 3193272189179082313U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 13268431135020363252U) + aNonceWordM;
            aOrbiterK = (((aOrbiterK ^ aOrbiterF) ^ 6538789950366849332U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 5352960308459065837U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 10390344544314544893U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 5087084271300584267U;
            aOrbiterA = RotL64((aOrbiterA * 15149302947570776165U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 13423071121590981727U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 18324443012024134729U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15814349432207734533U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 4129091815978464507U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 17024797553831962245U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3137753479364378175U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 6501545108779991661U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 11930037791867597447U;
            aOrbiterF = RotL64((aOrbiterF * 4904739567549702851U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 4667298703308315851U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 6315980380900062127U;
            aOrbiterI = RotL64((aOrbiterI * 12080555704907924637U), 27U);
            //
            aIngress = RotL64(aOrbiterD, 11U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 34U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterI, 11U)) + aOrbiterD);
            aWandererB = aWandererB ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterC, 19U)) + aOrbiterE) + aNonceWordN);
            aWandererC = aWandererC + (((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 51U)) + aOrbiterI) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 27U)) + aOrbiterI);
            aWandererK = aWandererK + (((RotL64(aPrevious, 4U) + aOrbiterF) + RotL64(aOrbiterA, 43U)) + aPhaseGWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 53U) + RotL64(aOrbiterC, 3U)) + aOrbiterF) + aNonceWordL) + aPhaseGWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterK, 60U)) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (RotL64(aWandererG, 60U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + RotL64(aWandererA, 11U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 24679U)) & S_BLOCK1], 35U) ^ RotL64(aKeyRowReadA[((aIndex + 25096U)) & W_KEY1], 27U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 24754U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25701U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 27101U)) & W_KEY1], 52U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26685U)) & S_BLOCK1], 39U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 25348U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 25009U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 6U) ^ RotL64(aPrevious, 27U)) ^ (RotL64(aIngress, 51U) + RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterH = (((aWandererG + RotL64(aPrevious, 51U)) + RotL64(aCarry, 23U)) + 16200278595895089008U) + aNonceWordM;
            aOrbiterE = (((aWandererJ + RotL64(aCross, 58U)) + RotL64(aCarry, 43U)) + 1029614154810465897U) + aNonceWordB;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 7129562468705441295U;
            aOrbiterJ = (aWandererB + RotL64(aIngress, 35U)) + 14388903902433951274U;
            aOrbiterA = (aWandererI + RotL64(aCross, 29U)) + 1013568949315967455U;
            aOrbiterG = (((aWandererF + RotL64(aPrevious, 23U)) + 3128823373497815651U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordF;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 43U)) + 14525694606889470589U) + aPhaseHOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 14443983602196782887U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 12244220415328641190U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15052949098014803181U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 10477159225338766614U) + aNonceWordC;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 2842870123078131566U;
            aOrbiterH = RotL64((aOrbiterH * 11522265477555954071U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 8621138818955849917U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterC) ^ 5038396344400303181U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 14636756322207385447U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 2768613802894372496U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 2027754864051410015U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2461322540050569287U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 2848088309172056399U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 15017458513904884651U;
            aOrbiterJ = RotL64((aOrbiterJ * 9926904679902843055U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 9079797279596336139U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 15424866642305110811U) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 12912331089970158845U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 13751764050290602740U) + aNonceWordD;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 7694557131324740282U;
            aOrbiterA = RotL64((aOrbiterA * 14980807690491467023U), 37U);
            //
            aIngress = RotL64(aOrbiterC, 43U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + RotL64(aOrbiterH, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((((RotL64(aIngress, 47U) + RotL64(aOrbiterJ, 27U)) + aOrbiterA) + RotL64(aCarry, 13U)) + aNonceWordJ) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 18U) + RotL64(aOrbiterJ, 19U)) + aOrbiterI);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterG, 39U)) + aOrbiterJ) + RotL64(aCarry, 53U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterH, 57U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 53U) + aOrbiterA) + RotL64(aOrbiterE, 3U)) + aNonceWordG);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 27U) + aOrbiterH) + RotL64(aOrbiterE, 51U)) + aNonceWordK);
            aWandererJ = aWandererJ + ((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterH, 12U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 30U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 43U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 29539U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneD[((aIndex + 28297U)) & S_BLOCK1], 43U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 29933U)) & W_KEY1], 3U) ^ RotL64(aWorkLaneC[((aIndex + 27399U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 29945U)) & W_KEY1], 19U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 28131U)) & S_BLOCK1], 29U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28643U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneB[((aIndex + 29069U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 50U)) ^ (RotL64(aIngress, 37U) + RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterB = ((aWandererF + RotL64(aIngress, 11U)) + 3248574644570178787U) + aNonceWordH;
            aOrbiterG = (((aWandererA + RotL64(aScatter, 4U)) + 4506961512959200024U) + aPhaseHOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1]) + aNonceWordP;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 37U)) + RotL64(aCarry, 35U)) + 8423739774540738590U;
            aOrbiterE = (aWandererE + RotL64(aCross, 51U)) + 6593975869641735337U;
            aOrbiterK = (((aWandererB + RotL64(aIngress, 43U)) + RotL64(aCarry, 51U)) + 16441716090557369103U) + aNonceWordI;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 19U)) + 7936601450453207914U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = ((aWandererD + RotL64(aCross, 57U)) + RotL64(aCarry, 23U)) + 13333752583560167065U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 8013703284795432973U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 2349852779887439236U;
            aOrbiterD = RotL64((aOrbiterD * 2422888500648100783U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 5318539364763284138U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 11450957608502944376U;
            aOrbiterG = RotL64((aOrbiterG * 1957880366707810635U), 43U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterB) + 9058992558327552687U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordL;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 632095686920230926U;
            aOrbiterA = RotL64((aOrbiterA * 12460364388358520799U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 14734218428913777098U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 16344357661370784442U;
            aOrbiterB = RotL64((aOrbiterB * 15049472842002138369U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 2981145363531184308U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 14176472085175714494U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2584623327412130939U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 11198457590069700889U) + aNonceWordF;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 952584436750426828U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1165713888651280355U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 4311591763498985972U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 16194341833989936369U;
            aOrbiterE = RotL64((aOrbiterE * 9997934560195932575U), 37U);
            //
            aIngress = RotL64(aOrbiterB, 35U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 23U));
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterE, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aIngress, 13U) + aOrbiterD) + RotL64(aOrbiterK, 39U)) + aNonceWordK);
            aWandererF = aWandererF + ((((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 3U)) + aPhaseHWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 44U) + aOrbiterK) + RotL64(aOrbiterA, 22U)) + aNonceWordM);
            aWandererB = aWandererB + (((RotL64(aPrevious, 29U) + aOrbiterD) + RotL64(aOrbiterB, 47U)) + aPhaseHWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 57U) + aOrbiterG) + RotL64(aOrbiterB, 13U)) + aNonceWordE);
            aWandererA = aWandererA + (((RotL64(aCross, 35U) + RotL64(aOrbiterG, 5U)) + aOrbiterA) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 21U) + aOrbiterE) + RotL64(aOrbiterK, 29U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 58U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 11U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 31221U)) & S_BLOCK1], 26U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 31331U)) & W_KEY1], 35U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 32511U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32464U)) & S_BLOCK1], 47U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31475U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 31754U)) & W_KEY1], 57U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 60U) + RotL64(aCarry, 23U)) + (RotL64(aPrevious, 11U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterI = (aWandererH + RotL64(aIngress, 27U)) + 12809562813316740345U;
            aOrbiterC = (aWandererB + RotL64(aScatter, 19U)) + 17084212535326321199U;
            aOrbiterD = (((aWandererI + RotL64(aCross, 47U)) + 16074921689983846769U) + aPhaseHOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1]) + aNonceWordA;
            aOrbiterF = ((((aWandererF + RotL64(aPrevious, 11U)) + RotL64(aCarry, 29U)) + 14027986153007120145U) + aPhaseHOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1]) + aNonceWordF;
            aOrbiterK = ((aWandererD + RotL64(aCross, 40U)) + 7633455951809250227U) + aNonceWordJ;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 3U)) + RotL64(aCarry, 11U)) + 340989348513370174U;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 57U)) + RotL64(aCarry, 57U)) + 5307820377645020116U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 5605285015771527274U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterI) ^ 5293500434746182790U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterD = RotL64((aOrbiterD * 17674669610895537063U), 11U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterI) + 7263156475892261811U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordO;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 10672879570907433005U;
            aOrbiterK = RotL64((aOrbiterK * 2506338667179450741U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 16659226780900986107U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 9774892622769850665U) ^ aNonceWordP;
            aOrbiterB = RotL64((aOrbiterB * 7487477727543183211U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 10728057184108279042U) + aNonceWordD;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 5032485856947407217U;
            aOrbiterA = RotL64((aOrbiterA * 16651577903809154285U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 14642241075374862345U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 8386481273395203518U;
            aOrbiterI = RotL64((aOrbiterI * 11649977733867003445U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 2874153265304098104U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 11519900149177261000U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2010158758971864505U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 8885690878540115768U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 4482143389870987714U;
            aOrbiterF = RotL64((aOrbiterF * 7105332459437434281U), 57U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterF, 3U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 11U));
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 21U)) + aOrbiterI);
            aWandererF = aWandererF + ((((RotL64(aScatter, 41U) + aOrbiterD) + RotL64(aOrbiterI, 13U)) + aNonceWordB) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 60U) + aOrbiterC) + RotL64(aOrbiterB, 53U)) + aNonceWordN);
            aWandererG = aWandererG + (((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 36U)) + aOrbiterD) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 5U)) + aOrbiterF) + aNonceWordG);
            aWandererH = aWandererH + ((((RotL64(aCross, 27U) + RotL64(aOrbiterD, 27U)) + aOrbiterK) + RotL64(aCarry, 23U)) + aNonceWordI);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterA, 43U)) + aOrbiterC) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + RotL64(aWandererG, 18U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_Boxing_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xEA98C7275D7F02BDULL + 0xCA937359B2A80A64ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xA5FB758E19FC4B5DULL + 0xF16879181EF6AF6AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC9B012095D1DE4EDULL + 0xA5B5C454D2132B93ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xFC1104E91AD28EAFULL + 0x831B0DC466A036C4ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x98EA5AF3B949764FULL + 0x83BCCAEBC1379B45ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xF26F01A1BCDC05DDULL + 0xBA3FA68458C5E9E9ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xF66DBD6EE29747E1ULL + 0xF9A474B5AC0BA0F1ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xA00C5FE7A9188817ULL + 0x82C2C0872711570CULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xADB379E36F2E096DULL + 0xECA010B946F3C5C7ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x9B08E159935DBE39ULL + 0xF7E5E4E7F9ECB780ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x886D6845BD6E016FULL + 0xCE24CCF047C34A11ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xF2955278B6D50F17ULL + 0x9EFC53CBC64B4EF2ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x948A2D4440B39ECDULL + 0xD16FA3519CBACB0BULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xBF023316707DEDEFULL + 0x8B69C72317E0D02FULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xF0ABB1DA2B80C0F9ULL + 0x94D1725261037598ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xD7B0CB4ECFEE767BULL + 0xF6F78D436F1D3C0AULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3546U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((aIndex + 910U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 4114U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3846U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 372U)) & S_BLOCK1], 44U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 1072U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 39U)) + (RotL64(aPrevious, 52U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterB = (aWandererG + RotL64(aPrevious, 5U)) + 9133751643283278896U;
            aOrbiterJ = ((((aWandererF + RotL64(aCross, 29U)) + RotL64(aCarry, 19U)) + 8971581804375380408U) + aPhaseAOrbiterAssignSaltD[((aIndex + 22U)) & S_SALT1]) + aNonceWordO;
            aOrbiterF = ((((aWandererD + RotL64(aIngress, 47U)) + RotL64(aCarry, 53U)) + 12559650383714566592U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordB;
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 19U)) + 15753206088872859163U) + aNonceWordC;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 60U)) + RotL64(aCarry, 3U)) + 7640756270450762350U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 7340073357551376125U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 5270256573644196046U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13286406906662922841U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 3567367996479995928U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 11939634537492733738U) ^ aNonceWordM;
            aOrbiterJ = RotL64((aOrbiterJ * 5640541900117183639U), 5U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterF) + 7051817732424527120U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1]) + aNonceWordL;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 1730487669951837941U;
            aOrbiterC = RotL64((aOrbiterC * 15191634337956285841U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 18009252467909454817U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 2361024272031696442U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15215151562500226027U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 15902755877642960397U) + aNonceWordK;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 12243517544704116184U) ^ aNonceWordH;
            aOrbiterH = RotL64((aOrbiterH * 2576071074148141447U), 57U);
            //
            aIngress = RotL64(aOrbiterJ, 29U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 43U));
            aIngress = aIngress + RotL64(aOrbiterC, 54U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 27U) + RotL64(aOrbiterC, 3U)) + aOrbiterF) + aNonceWordD) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 47U)) + aOrbiterC) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 46U) + RotL64(aOrbiterJ, 39U)) + aOrbiterC) + aPhaseAWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterJ, 20U)) + RotL64(aCarry, 13U)) + aNonceWordE);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 5U) + aOrbiterJ) + RotL64(aOrbiterB, 57U)) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + RotL64(aWandererJ, 53U);
            aCarry = aCarry + RotL64(aIngress, 40U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 6378U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((aIndex + 6373U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 7765U)) & S_BLOCK1], 37U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 9012U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 10257U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 8263U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 5880U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCarry, 53U)) + (RotL64(aCross, 41U) ^ RotL64(aPrevious, 20U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterG = (((aWandererJ + RotL64(aScatter, 56U)) + 826930775230515406U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordB;
            aOrbiterE = (aWandererD + RotL64(aIngress, 43U)) + 5137814617363250861U;
            aOrbiterD = ((((aWandererA + RotL64(aCross, 29U)) + RotL64(aCarry, 13U)) + 14761561947426681616U) + aPhaseAOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1]) + aNonceWordA;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 21U)) + RotL64(aCarry, 27U)) + 12773023438753662590U;
            aOrbiterH = (((aWandererF + RotL64(aIngress, 11U)) + RotL64(aCarry, 47U)) + 7331345852207096322U) + aNonceWordI;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 3899381212671247460U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterG) ^ 10072004147620068599U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterD = RotL64((aOrbiterD * 5663583566047763435U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 3424585039401897560U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 8246760141625966321U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11478879365443736383U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 3655992860610853290U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterD) ^ 11154618022505863898U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterE = RotL64((aOrbiterE * 4791494171286145231U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 15629361991059709973U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 10842068502278489664U;
            aOrbiterH = RotL64((aOrbiterH * 17223002513104960799U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 5571312349016336686U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 589313823745748879U) ^ aNonceWordJ;
            aOrbiterA = RotL64((aOrbiterA * 1356685926549786027U), 29U);
            //
            aIngress = RotL64(aOrbiterD, 35U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterG, 11U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 22U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aCross, 37U) + RotL64(aOrbiterE, 48U)) + aOrbiterG) + RotL64(aCarry, 53U)) + aPhaseAWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterD, 19U)) + aOrbiterH) + aNonceWordP);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 27U)) + aOrbiterD) + RotL64(aCarry, 37U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterH, 35U)) + aOrbiterE) + aNonceWordN);
            aWandererJ = aWandererJ + ((RotL64(aCross, 46U) + RotL64(aOrbiterD, 11U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 24U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 10962U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 13904U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12425U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 12304U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((aIndex + 15025U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCarry, 43U)) ^ (RotL64(aCross, 11U) + RotL64(aPrevious, 30U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterD = (((aWandererA + RotL64(aPrevious, 3U)) + RotL64(aCarry, 5U)) + 15549114274303128055U) + aNonceWordE;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 23U)) + 16466750056388063241U) + aNonceWordM;
            aOrbiterK = ((((aWandererK + RotL64(aScatter, 11U)) + RotL64(aCarry, 35U)) + 12209449840836787142U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordF;
            aOrbiterC = ((aWandererE + RotL64(aCross, 43U)) + RotL64(aCarry, 53U)) + 14551496099734294336U;
            aOrbiterF = (((aWandererC + RotL64(aIngress, 58U)) + 6266576428679808622U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordH;
            //
            aOrbiterD = (((aOrbiterD + aOrbiterH) + 16892841575635668152U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1]) + aNonceWordD;
            aOrbiterK = (((aOrbiterK ^ aOrbiterD) ^ 7375966221423362125U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterK = RotL64((aOrbiterK * 15338878556107177587U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 11926105302821753530U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 16219253791550461124U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2117550758226173419U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 7299056065319248160U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 15234001484933728439U;
            aOrbiterC = RotL64((aOrbiterC * 8182244796017018911U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 6615802589932632120U) + aNonceWordG;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 5481176858895819247U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3604590158551984877U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 17220507586542139380U) + aNonceWordP;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 14137921473739415340U;
            aOrbiterF = RotL64((aOrbiterF * 10634645686035907603U), 27U);
            //
            aIngress = RotL64(aOrbiterK, 23U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 19U)) + aOrbiterF) + aNonceWordC) + aPhaseAWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 5U) + RotL64(aOrbiterF, 6U)) + aOrbiterK) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 50U) + RotL64(aOrbiterH, 39U)) + aOrbiterD) + aNonceWordO);
            aWandererG = aWandererG + ((((RotL64(aIngress, 23U) + aOrbiterC) + RotL64(aOrbiterF, 29U)) + RotL64(aCarry, 29U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterD, 51U)) + aOrbiterC) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 19381U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneA[((aIndex + 20709U)) & S_BLOCK1], 48U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19892U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 17555U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneD[((aIndex + 20249U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aIngress, 22U)) ^ (RotL64(aPrevious, 35U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 14U)) + 6243113109470883144U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = (((aWandererB + RotL64(aCross, 23U)) + RotL64(aCarry, 39U)) + 3891552123999605832U) + aNonceWordE;
            aOrbiterG = (((aWandererK + RotL64(aPrevious, 5U)) + RotL64(aCarry, 51U)) + 8758797898587019128U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = (((aWandererF + RotL64(aScatter, 57U)) + RotL64(aCarry, 13U)) + 1005891374086408851U) + aNonceWordM;
            aOrbiterK = (aWandererD + RotL64(aIngress, 43U)) + 3713426782180050764U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 18358143862391573534U) + aNonceWordH;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 17504394029693712404U;
            aOrbiterG = RotL64((aOrbiterG * 3391716204095092531U), 3U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterB) + 5312729289027417014U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1]) + aNonceWordP;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 2560873623431186029U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16843728573219210173U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 16309322822806704211U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 10195513918020652600U) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 14569219741824123715U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 2552116263258744287U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 7732784879810980089U;
            aOrbiterC = RotL64((aOrbiterC * 15041929399477790999U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 16499127570665381507U) + aNonceWordF;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 10890036715535519036U;
            aOrbiterD = RotL64((aOrbiterD * 9065115450010475187U), 11U);
            //
            aIngress = RotL64(aOrbiterD, 53U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 14U));
            aIngress = aIngress + RotL64(aOrbiterK, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterG, 60U)) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 30U) + aOrbiterG) + RotL64(aOrbiterD, 41U)) + aNonceWordJ);
            aWandererB = aWandererB + (((((RotL64(aScatter, 39U) + aOrbiterC) + RotL64(aOrbiterK, 51U)) + RotL64(aCarry, 21U)) + aNonceWordO) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 3U) + aOrbiterB) + RotL64(aOrbiterK, 29U)) + aNonceWordA) + aPhaseAWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterG, 13U)) + aNonceWordG);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 48U));
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 23142U)) & S_BLOCK1], 24U) ^ RotL64(aInvestLaneB[((aIndex + 25141U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 26852U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24625U)) & S_BLOCK1], 47U) ^ RotL64(aInvestLaneA[((aIndex + 24021U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCross, 43U) ^ RotL64(aIngress, 24U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterH = (aWandererK + RotL64(aIngress, 21U)) + 4634399531433127141U;
            aOrbiterC = ((((aWandererJ + RotL64(aScatter, 47U)) + RotL64(aCarry, 47U)) + 16961792729406903200U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordH;
            aOrbiterB = (((aWandererD + RotL64(aPrevious, 57U)) + RotL64(aCarry, 23U)) + 4105280732301137738U) + aNonceWordO;
            aOrbiterA = ((((aWandererH + RotL64(aCross, 3U)) + RotL64(aCarry, 11U)) + 15692013501147331191U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordE;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 38U)) + 1252216715968780587U) + aNonceWordA;
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 7958289043012473752U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 6611577301818896615U) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 2757493607265637973U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 8506226754305949140U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 3648813120449403353U;
            aOrbiterH = RotL64((aOrbiterH * 9521367946879238849U), 37U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterI) + 5195245426245535735U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordL;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 542948051600803051U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4631106308856448475U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 11974253551208964789U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 10596463592332655367U;
            aOrbiterA = RotL64((aOrbiterA * 10941161258815714641U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 12015129484061440159U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 8254944355710109060U;
            aOrbiterI = RotL64((aOrbiterI * 3233697992479357615U), 51U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterI, 57U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + RotL64(aOrbiterA, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 48U) + RotL64(aOrbiterB, 3U)) + aOrbiterA) + aNonceWordF) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterH, 23U)) + aOrbiterI) + RotL64(aCarry, 23U)) + aNonceWordC);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 13U) + aOrbiterB) + RotL64(aOrbiterI, 37U)) + aPhaseAWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 56U)) + aOrbiterH) + RotL64(aCarry, 11U)) + aNonceWordD);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterA, 13U)) + aOrbiterC) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 48U));
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 30679U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneA[((aIndex + 28445U)) & S_BLOCK1], 26U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 31809U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32507U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27902U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aIngress, 36U)) ^ (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterE = (((aWandererA + RotL64(aPrevious, 13U)) + 12262991801139086177U) + aPhaseAOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1]) + aNonceWordO;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 41U)) + RotL64(aCarry, 11U)) + 7963038771924890197U;
            aOrbiterI = (((aWandererF + RotL64(aIngress, 21U)) + RotL64(aCarry, 29U)) + 15540520327933568896U) + aNonceWordE;
            aOrbiterK = ((aWandererE + RotL64(aCross, 29U)) + RotL64(aCarry, 53U)) + 8745565892055020722U;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 60U)) + 16619329199683755286U) + aPhaseAOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 10865705026433867260U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 2743368697984518059U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2989232417816919375U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 5556006271515473135U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 5355833281353498588U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4190140212757841511U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 8313616108963479829U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 16657121016801866434U;
            aOrbiterE = RotL64((aOrbiterE * 331533349428472477U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 16532226425013000833U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterG) ^ 5800465874932467232U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterH = RotL64((aOrbiterH * 5966395771690704577U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 17882948163883121328U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 15029375310296563175U) ^ aNonceWordL;
            aOrbiterK = RotL64((aOrbiterK * 17021415832288477713U), 13U);
            //
            aIngress = RotL64(aOrbiterK, 37U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 54U));
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterI, 11U)) + aNonceWordA) + aPhaseAWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 43U) + RotL64(aOrbiterK, 54U)) + aOrbiterG) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ ((((RotL64(aCross, 11U) + aOrbiterH) + RotL64(aOrbiterE, 41U)) + aNonceWordF) + aPhaseAWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aScatter, 52U) + RotL64(aOrbiterG, 27U)) + aOrbiterH) + RotL64(aCarry, 29U)) + aNonceWordC);
            aWandererF = aWandererF ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterI, 19U)) + aOrbiterK) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 5U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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

void TwistExpander_Boxing_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xE34FAD7DC00BAA63ULL + 0x85A6C4522488A433ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xC83BE577B8756D9FULL + 0xA8EFBE7C8A2CFB86ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xA408AB4C32F14E53ULL + 0xC07869F1570B19FCULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xDE139E01664B7399ULL + 0xB3CB3BB235DF2A85ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xED1F69B21504C933ULL + 0xFC2C7EBB32881052ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xED5105D74525ADDFULL + 0xC02D39ECDF47AA99ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xFFF33EBB34933D93ULL + 0xABE691FC661623F7ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x8FAC89CBBD278815ULL + 0xCF9415A99166717BULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x95BD4C5D5568118DULL + 0xA5E745CFD5A0729FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xB35C20DEABBA16FBULL + 0xFB944698D09368C9ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xF9FD2B920AE51F59ULL + 0xDE947FD72D49C74DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x9BFD9FE41723A7DFULL + 0xED6CC89A76E048CDULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x986D3ADC10B3BC3DULL + 0xC11CE7624E77D613ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xB810DA8EE9BF1673ULL + 0x90F3E796F0613D7CULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xAA9C4D8AB834AB97ULL + 0xB10357768303F7BDULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xEEAA2830E952D4A1ULL + 0xB137F0275EBED96DULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 696U)) & S_BLOCK1], 42U) ^ RotL64(aOperationLaneB[((aIndex + 5960U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 455U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 1522U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 982U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 4375U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aIngress, 52U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterE = ((aWandererE + RotL64(aCross, 6U)) + RotL64(aCarry, 57U)) + 2168513956284366370U;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 41U)) + 10290361969974613111U) + aNonceWordG;
            aOrbiterA = (aWandererC + RotL64(aPrevious, 11U)) + 15673836275828498050U;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 19U)) + 16600540024145812236U) + aPhaseBOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = ((aWandererF + RotL64(aCross, 23U)) + 9428052101528111892U) + aNonceWordL;
            aOrbiterG = (((aWandererB + RotL64(aIngress, 57U)) + RotL64(aCarry, 23U)) + 12763657928312763377U) + aPhaseBOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (((aWandererG + RotL64(aPrevious, 27U)) + RotL64(aCarry, 35U)) + 10751286982008662485U) + aNonceWordP;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 51U)) + 1708230173038057979U) + aNonceWordE;
            aOrbiterF = (aWandererI + RotL64(aCross, 46U)) + 4011389705422783816U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 11704428328093077714U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 2055336619674699284U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6374289210096410907U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 1870865272102705804U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 3574214263751923179U;
            aOrbiterK = RotL64((aOrbiterK * 13132083406834413563U), 29U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterD) + 984611970726966186U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordK;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 15207945449947643672U) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 9539470161576639981U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 4181398506373973169U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 15222345431506025949U;
            aOrbiterD = RotL64((aOrbiterD * 6925143692628659467U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 15023513452326240962U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 14965669361708810699U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 587008860996713147U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 7985755518735406360U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 225592097619240187U;
            aOrbiterJ = RotL64((aOrbiterJ * 2313509354133400439U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 3659537916566939383U) + aNonceWordI;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 17043668033610689611U;
            aOrbiterF = RotL64((aOrbiterF * 10797634709118100773U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 10217321522161675848U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 8013663869536146842U;
            aOrbiterG = RotL64((aOrbiterG * 2293233079384777175U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 13762445330867496042U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 2692400019659269106U;
            aOrbiterC = RotL64((aOrbiterC * 167704184292219399U), 19U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterC, 60U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 19U) + RotL64(aOrbiterE, 14U)) + aOrbiterG) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterC, 37U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 35U) + aOrbiterG) + RotL64(aOrbiterD, 53U)) + aNonceWordJ);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 58U) + RotL64(aOrbiterB, 57U)) + aOrbiterF) + aPhaseBWandererUpdateSaltC[((aIndex + 10U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 41U) + RotL64(aOrbiterK, 27U)) + aOrbiterA) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 27U) + aOrbiterK) + RotL64(aOrbiterJ, 19U)) + aNonceWordB);
            aWandererH = aWandererH + ((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterE, 5U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 54U) + RotL64(aOrbiterE, 48U)) + aOrbiterA) + aNonceWordA);
            aWandererE = aWandererE + ((RotL64(aIngress, 23U) + RotL64(aOrbiterK, 41U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 44U));
            aCarry = aCarry + RotL64(aWandererD, 37U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 15729U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneC[((aIndex + 10094U)) & S_BLOCK1], 27U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 11772U)) & S_BLOCK1], 38U) ^ RotL64(aFireLaneC[((aIndex + 13856U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 8507U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 14567U)) & S_BLOCK1], 18U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 10005U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCarry, 21U)) + (RotL64(aPrevious, 37U) ^ RotL64(aCross, 52U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterK = (((aWandererB + RotL64(aIngress, 30U)) + RotL64(aCarry, 39U)) + 3561491146322798260U) + aNonceWordG;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 3U)) + 7075025056181885339U) + aNonceWordO;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 23U)) + 9230910887904171613U;
            aOrbiterA = ((aWandererK + RotL64(aCross, 51U)) + RotL64(aCarry, 3U)) + 4119781172609908917U;
            aOrbiterF = (((aWandererF + RotL64(aPrevious, 19U)) + RotL64(aCarry, 57U)) + 17155609083870983149U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = (aWandererI + RotL64(aIngress, 41U)) + 2423018561430181695U;
            aOrbiterG = (aWandererA + RotL64(aScatter, 47U)) + 12957280305617615744U;
            aOrbiterJ = (aWandererC + RotL64(aCross, 12U)) + 2461704174772065813U;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 37U)) + 7907123257849391997U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 7257868138318960007U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 16425903703085702285U;
            aOrbiterI = RotL64((aOrbiterI * 7996935869077231999U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 2990822664594079467U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 5654819006718953817U;
            aOrbiterD = RotL64((aOrbiterD * 4465096036756887801U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 12183676471235678779U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 15026286960542123922U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17199049329995315279U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 12169080607071830522U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 2906296852254787499U) ^ aNonceWordB;
            aOrbiterJ = RotL64((aOrbiterJ * 6754514406846040163U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 3029858695410344584U) + aNonceWordI;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 14406410317495954566U;
            aOrbiterK = RotL64((aOrbiterK * 9663780721657983421U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 11048818178401163861U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 13622063920319445043U) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 2516025554421589857U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 2642646089141233277U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 12761571777929273548U;
            aOrbiterG = RotL64((aOrbiterG * 5518252696078700127U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 7753802695131502382U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 8510425459525030222U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12412361423636026483U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 13522645164493316722U) + aNonceWordL;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 1437430302489702713U;
            aOrbiterA = RotL64((aOrbiterA * 14019316635365783545U), 47U);
            //
            aIngress = RotL64(aOrbiterJ, 14U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterJ, 19U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterI, 23U)) + aOrbiterC) + aPhaseBWandererUpdateSaltF[((aIndex + 22U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 41U) + aOrbiterD) + RotL64(aOrbiterI, 29U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 52U) + RotL64(aOrbiterF, 6U)) + aOrbiterG);
            aWandererG = aWandererG + (((RotL64(aScatter, 29U) + aOrbiterJ) + RotL64(aOrbiterE, 37U)) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ ((((RotL64(aCross, 47U) + RotL64(aOrbiterJ, 47U)) + aOrbiterA) + aNonceWordK) + aPhaseBWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 11U) + aOrbiterK) + RotL64(aOrbiterI, 53U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 58U) + RotL64(aOrbiterF, 41U)) + aOrbiterI) + aNonceWordE);
            aWandererI = aWandererI + (((RotL64(aIngress, 23U) + RotL64(aOrbiterI, 12U)) + aOrbiterA) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 20U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + RotL64(aWandererI, 51U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 17914U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneA[((aIndex + 17481U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 24074U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneA[((aIndex + 20551U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22238U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 24165U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24416U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 13U) + RotL64(aCross, 27U)) ^ (RotL64(aCarry, 56U) ^ RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterG = (aWandererC + RotL64(aPrevious, 5U)) + 13333509828310369865U;
            aOrbiterA = ((aWandererD + RotL64(aCross, 11U)) + 7645352517103840797U) + aNonceWordO;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 47U)) + RotL64(aCarry, 53U)) + 5310766306660062655U;
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 60U)) + RotL64(aCarry, 19U)) + 5165635069832352932U;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 51U)) + 15684141764734281849U) + aNonceWordP;
            aOrbiterC = (((aWandererI + RotL64(aScatter, 35U)) + 3327963374225061738U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordK;
            aOrbiterK = ((aWandererB + RotL64(aCross, 41U)) + 8625811794878848871U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aIngress, 23U)) + 7598657468430485291U;
            aOrbiterI = (((aWandererG + RotL64(aCross, 18U)) + RotL64(aCarry, 27U)) + 2881171216276746485U) + aNonceWordF;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 10237691227222918101U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 6419254255884834497U;
            aOrbiterH = RotL64((aOrbiterH * 3816625473642865305U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 4238455444646479956U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 14936613353493061492U;
            aOrbiterC = RotL64((aOrbiterC * 3544216916806292273U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 15324699725208372627U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 9506640480601832011U;
            aOrbiterG = RotL64((aOrbiterG * 12819564111348390227U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 3709149613660215641U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 1724290199312754307U;
            aOrbiterI = RotL64((aOrbiterI * 12597580418257897965U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 13191172833570139194U) + aNonceWordA;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 3686087945377837886U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10883609557429936283U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 10418330386245397022U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 5383531313632347245U;
            aOrbiterK = RotL64((aOrbiterK * 2987755379396160073U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 7414716553072652212U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 11301761123966206201U) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 1546727321088592187U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 8570229732236388847U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 8773754460060264773U;
            aOrbiterF = RotL64((aOrbiterF * 3251360788932563495U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 13636929800504199371U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 5486599841558573720U;
            aOrbiterB = RotL64((aOrbiterB * 2867914211589815153U), 57U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 51U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 26U));
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 4U) + aOrbiterI) + RotL64(aOrbiterB, 43U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterH, 11U));
            aWandererC = aWandererC ^ ((((RotL64(aScatter, 29U) + aOrbiterC) + RotL64(aOrbiterI, 60U)) + aNonceWordC) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterJ, 23U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 56U) + aOrbiterI) + RotL64(aOrbiterF, 19U)) + aPhaseBWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterK, 56U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 11U) + RotL64(aOrbiterA, 51U)) + aOrbiterG) + RotL64(aCarry, 29U)) + aNonceWordD);
            aWandererF = aWandererF ^ ((RotL64(aCross, 21U) + aOrbiterF) + RotL64(aOrbiterJ, 47U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 30U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 27819U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneA[((aIndex + 26359U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 27363U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 27628U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28864U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28968U)) & S_BLOCK1], 42U));
            aCross ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 30882U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCross, 5U)) ^ (RotL64(aCarry, 50U) + RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 47U)) + 14157904117287696136U) + aNonceWordL;
            aOrbiterI = ((aWandererH + RotL64(aCross, 10U)) + 7369512677371640676U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = ((((aWandererA + RotL64(aScatter, 3U)) + RotL64(aCarry, 51U)) + 8411250745902073798U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordG;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 37U)) + 5002041814539710275U) + aNonceWordN;
            aOrbiterJ = (aWandererD + RotL64(aScatter, 57U)) + 9538041410816283124U;
            aOrbiterD = (((aWandererB + RotL64(aPrevious, 19U)) + RotL64(aCarry, 3U)) + 5210700103927513061U) + aNonceWordB;
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 30U)) + RotL64(aCarry, 23U)) + 7600709399101287982U;
            aOrbiterG = (aWandererG + RotL64(aCross, 43U)) + 2366369466696580499U;
            aOrbiterB = (aWandererI + RotL64(aScatter, 53U)) + 5544575244203019109U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 8710073749110329779U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 15998211310115361630U) ^ aNonceWordF;
            aOrbiterH = RotL64((aOrbiterH * 15275657696897688955U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 15354357553877376422U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 10657523549259276169U) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 13695239532898311073U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 10405750198355464768U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 3465819693133515142U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14678343718277562799U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 16724189641701408630U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 3484340153620198872U;
            aOrbiterC = RotL64((aOrbiterC * 17247547677520703125U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 7420442404884871126U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 11138445997256757636U;
            aOrbiterB = RotL64((aOrbiterB * 11167543379937571127U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 1428191560884663125U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 16950093140800653985U;
            aOrbiterJ = RotL64((aOrbiterJ * 4423012306984814805U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 17288299075036481960U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 13793597915359681028U;
            aOrbiterG = RotL64((aOrbiterG * 9639204979982125757U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 5017972942710079726U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 12409957957614320964U;
            aOrbiterK = RotL64((aOrbiterK * 10273295741911545745U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 12487994181992095174U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 1573393166996612118U;
            aOrbiterD = RotL64((aOrbiterD * 13364311829104520751U), 57U);
            //
            aIngress = RotL64(aOrbiterI, 41U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 52U));
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aCross, 3U) + aOrbiterK) + RotL64(aOrbiterH, 43U)) + aNonceWordM);
            aWandererI = aWandererI + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterI, 57U)) + aOrbiterC) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 24U) + aOrbiterH) + RotL64(aOrbiterB, 24U));
            aWandererG = aWandererG + (((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterG, 5U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 43U) + aOrbiterG) + RotL64(aOrbiterC, 29U));
            aWandererA = aWandererA + (((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterH, 39U)) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 52U) + aOrbiterD) + RotL64(aOrbiterG, 11U)) + aNonceWordH);
            aWandererC = aWandererC + (((RotL64(aCross, 13U) + RotL64(aOrbiterF, 18U)) + aOrbiterJ) + aPhaseBWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 51U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 40U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + RotL64(aWandererA, 11U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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

void TwistExpander_Boxing_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x80D1B00AA41BD12BULL + 0x91C1DD9A9CC336A7ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xD4417684EEE46BBFULL + 0xBA18DC70D21F3961ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xD463CE3B3BE1A03BULL + 0x84B4E6D5447D04C3ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xD7DCEC6BB6F66523ULL + 0x9453BFF3801F2879ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x8FA60F1B1A9F3407ULL + 0xD1997F1262B51573ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xA690179A9503B763ULL + 0xEE60F11DB338B75CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x9CE2CC72053898E3ULL + 0xFEBA8A21AD4A8033ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xE27DB3189598F3B5ULL + 0xC506C5757A516437ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xB156EE2887654F65ULL + 0xDC38A941597D8B7FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x91E8CDB3A002BB05ULL + 0x97FDA35A0210ED64ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x8A967122BDD9AA11ULL + 0x8EA6426F5DF24A92ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xFE47E3BCF7D86969ULL + 0xE20EB7E12B818FD1ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x9E825010845383B3ULL + 0xEB8E71CFF2AC03E4ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x8856CED0F9518995ULL + 0xFB46A4C09C1531B5ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x9A680C9FA44850D5ULL + 0x8F3F074FFB83E5E4ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xEF1F93C4A9A89711ULL + 0xD5A0670392FCBD3EULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 5155U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((aIndex + 1667U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 5411U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1696U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 1240U)) & S_BLOCK1], 26U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 4794U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aIngress, 5U)) ^ (RotL64(aCross, 51U) + RotL64(aPrevious, 36U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterB = ((aWandererA + RotL64(aCross, 60U)) + 5573188770530340913U) + aNonceWordL;
            aOrbiterH = (((aWandererB + RotL64(aPrevious, 3U)) + RotL64(aCarry, 5U)) + 1431772230889897111U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (((aWandererG + RotL64(aIngress, 37U)) + RotL64(aCarry, 19U)) + 4809192776429682319U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aScatter, 27U)) + RotL64(aCarry, 53U)) + 5576603692574369341U;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 43U)) + 2720143226007220386U;
            aOrbiterI = ((aWandererE + RotL64(aCross, 21U)) + 17220328778565331629U) + aNonceWordN;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 13U)) + 9629485808442089423U) + aNonceWordI;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 1136998437010390983U) + aNonceWordJ;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 11893390497814523841U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5329621622743089531U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 1764986431917532370U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 1741014798007010376U;
            aOrbiterC = RotL64((aOrbiterC * 13414914086049500731U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 12221368453236547044U) + aNonceWordM;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 7694538641172350430U;
            aOrbiterB = RotL64((aOrbiterB * 8439120733670016501U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 17472344518811560603U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 3308740700728172984U;
            aOrbiterI = RotL64((aOrbiterI * 15290400462887712083U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 9535358833412446771U) + aNonceWordB;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 11192312491731312451U;
            aOrbiterH = RotL64((aOrbiterH * 17405609148475445743U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 14850451970047190039U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 11932493299452443256U;
            aOrbiterF = RotL64((aOrbiterF * 7964808728820467795U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 5972619895614731870U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterF) ^ 17174497535809891690U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterD = RotL64((aOrbiterD * 15471084511364572533U), 57U);
            //
            aIngress = RotL64(aOrbiterD, 19U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 53U) + aOrbiterD) + RotL64(aOrbiterB, 13U));
            aWandererI = aWandererI + (((RotL64(aIngress, 27U) + RotL64(aOrbiterF, 5U)) + aOrbiterG) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 37U) + aOrbiterD) + RotL64(aOrbiterF, 21U));
            aWandererG = aWandererG + ((RotL64(aScatter, 11U) + RotL64(aOrbiterG, 35U)) + aOrbiterI);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterC, 29U));
            aWandererF = aWandererF + (((((RotL64(aScatter, 60U) + RotL64(aOrbiterH, 42U)) + aOrbiterD) + RotL64(aCarry, 23U)) + aNonceWordF) + aPhaseDWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((((RotL64(aCross, 19U) + RotL64(aOrbiterB, 51U)) + aOrbiterG) + aNonceWordE) + aPhaseDWandererUpdateSaltA[((aIndex + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (RotL64(aWandererI, 28U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 6540U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((aIndex + 8413U)) & S_BLOCK1], 27U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 9022U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneC[((aIndex + 9531U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 5625U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5824U)) & S_BLOCK1], 14U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 10460U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aIngress, 5U)) ^ (RotL64(aCarry, 19U) + RotL64(aPrevious, 34U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterD = (((aWandererC + RotL64(aPrevious, 35U)) + 18255347001097480328U) + aPhaseDOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1]) + aNonceWordN;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 41U)) + RotL64(aCarry, 39U)) + 13679246790311505735U;
            aOrbiterE = ((((aWandererJ + RotL64(aCross, 47U)) + RotL64(aCarry, 53U)) + 10565839529765027116U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordO;
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 29U)) + 14327172566224769901U) + aNonceWordA;
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 54U)) + RotL64(aCarry, 19U)) + 16239024612038195174U;
            aOrbiterI = ((aWandererH + RotL64(aCross, 23U)) + 13800012174212131890U) + aNonceWordG;
            aOrbiterK = (aWandererK + RotL64(aScatter, 5U)) + 13900288860157577583U;
            //
            aOrbiterD = (((aOrbiterD + aOrbiterH) + 4144386119777112740U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 3154558262670631372U;
            aOrbiterE = RotL64((aOrbiterE * 13236911910092437063U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 7456728543137614001U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 11709519851158935384U;
            aOrbiterD = RotL64((aOrbiterD * 7016689518570071587U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 15607438907832240304U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 9276575329661725624U;
            aOrbiterH = RotL64((aOrbiterH * 8879744070762412745U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 6459435969129449226U) + aNonceWordP;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 6442382118416542275U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2921027306686588233U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 12117432107282150865U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 6831279293184793243U;
            aOrbiterJ = RotL64((aOrbiterJ * 2435360641135249073U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 9520022957804572889U) + aNonceWordM;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 8322178689474588679U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1627707191467537115U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 4162401591586869316U) + aNonceWordI;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 8994015844714895961U;
            aOrbiterK = RotL64((aOrbiterK * 15421910378057951895U), 35U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterH, 44U);
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterA, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterD, 21U)) + aOrbiterH);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterJ, 51U)) + aOrbiterH) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 11U) + RotL64(aOrbiterK, 57U)) + aOrbiterI) + aNonceWordL) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aIngress, 4U) + aOrbiterA) + RotL64(aOrbiterK, 5U)) + aNonceWordE) + aPhaseDWandererUpdateSaltB[((aIndex + 20U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 23U) + aOrbiterI) + RotL64(aOrbiterE, 44U)) + aNonceWordD);
            aWandererH = aWandererH + (((RotL64(aIngress, 57U) + aOrbiterE) + RotL64(aOrbiterJ, 37U)) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterD, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + RotL64(aWandererI, 24U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 13667U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneA[((aIndex + 14130U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 13695U)) & S_BLOCK1], 52U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16367U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((aIndex + 12305U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 26U)) ^ (RotL64(aCross, 57U) ^ RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterC = (((aWandererA + RotL64(aPrevious, 54U)) + RotL64(aCarry, 29U)) + 785861751704720606U) + aNonceWordP;
            aOrbiterJ = (((aWandererE + RotL64(aScatter, 5U)) + RotL64(aCarry, 41U)) + 15968088718435606299U) + aNonceWordB;
            aOrbiterK = (aWandererG + RotL64(aIngress, 21U)) + 1393976526590347151U;
            aOrbiterH = (aWandererK + RotL64(aCross, 11U)) + 17240750947292745884U;
            aOrbiterI = (aWandererI + RotL64(aIngress, 35U)) + 4921576136163183137U;
            aOrbiterG = ((aWandererF + RotL64(aScatter, 47U)) + 3334047873553153032U) + aPhaseDOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = ((((aWandererC + RotL64(aCross, 41U)) + RotL64(aCarry, 13U)) + 15086509978458408698U) + aPhaseDOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1]) + aNonceWordH;
            //
            aOrbiterC = (((aOrbiterC + aOrbiterJ) + 892391205397581998U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1]) + aNonceWordM;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 2965686403183767521U;
            aOrbiterK = RotL64((aOrbiterK * 709160942482770225U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 14632215393655706170U) + aNonceWordN;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 15740589515342377322U;
            aOrbiterG = RotL64((aOrbiterG * 15677716942904794913U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 11131164813943086445U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 6988080581278900960U;
            aOrbiterJ = RotL64((aOrbiterJ * 6412189142344044255U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 16021254613117657178U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 6183615599897921154U;
            aOrbiterI = RotL64((aOrbiterI * 9976411093264211033U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 12533992547026652747U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 3104325358982904219U;
            aOrbiterD = RotL64((aOrbiterD * 14977348108778147265U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 3878525937957474644U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 2120435259884368445U;
            aOrbiterC = RotL64((aOrbiterC * 15964718652193073177U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 14928658302694194856U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 9121310461310309348U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17304439784647477491U), 11U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterG, 13U);
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterH, 35U)) + aOrbiterK);
            aWandererA = aWandererA + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 29U)) + aOrbiterC) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 53U) + aOrbiterH) + RotL64(aOrbiterJ, 51U));
            aWandererF = aWandererF + (((RotL64(aCross, 18U) + RotL64(aOrbiterD, 43U)) + aOrbiterG) + aNonceWordL);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterG, 12U)) + aOrbiterH) + aPhaseDWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 27U) + RotL64(aOrbiterD, 19U)) + aOrbiterJ) + RotL64(aCarry, 35U));
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 41U) + RotL64(aOrbiterH, 57U)) + aOrbiterI) + aNonceWordJ) + aPhaseDWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 58U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 19011U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((aIndex + 20817U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 19839U)) & S_BLOCK1], 54U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20915U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((aIndex + 20967U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aIngress, 10U)) ^ (RotL64(aCarry, 23U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 19U)) + 11480359716598965890U;
            aOrbiterI = (((aWandererK + RotL64(aIngress, 5U)) + RotL64(aCarry, 19U)) + 15431182525482873419U) + aNonceWordB;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 51U)) + 11360504974812776707U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = (((aWandererG + RotL64(aCross, 43U)) + 9292576416573382769U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordC;
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 37U)) + RotL64(aCarry, 41U)) + 1549257414531028975U;
            aOrbiterC = ((aWandererH + RotL64(aCross, 60U)) + RotL64(aCarry, 3U)) + 5347769463033129317U;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 27U)) + 17019199177478377234U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 16558106007323125094U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 3976182233825939422U;
            aOrbiterD = RotL64((aOrbiterD * 4392162052317572289U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 2889047161195954395U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 2241831345026962605U;
            aOrbiterI = RotL64((aOrbiterI * 5757458560979927857U), 13U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterB) + 12850802412140579294U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordE;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 13541744735436450160U;
            aOrbiterC = RotL64((aOrbiterC * 906089290000537439U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 2085863085516538212U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 2969034221711544086U) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 7768528124408400403U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 6482666944512391472U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 16969153556875844613U;
            aOrbiterA = RotL64((aOrbiterA * 9483462388353216219U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 5161314086757363678U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 7150282484670673211U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8522427002337918663U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 5465304381272305847U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 2344610773390354017U;
            aOrbiterJ = RotL64((aOrbiterJ * 17010258514288089191U), 37U);
            //
            aIngress = RotL64(aOrbiterC, 3U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 40U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aCross, 13U) + aOrbiterD) + RotL64(aOrbiterA, 37U)) + aNonceWordM);
            aWandererH = aWandererH + ((((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterI, 22U)) + RotL64(aCarry, 57U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterD, 51U)) + aOrbiterI) + aNonceWordF);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 40U) + RotL64(aOrbiterD, 43U)) + aOrbiterJ) + RotL64(aCarry, 5U)) + aPhaseDWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 27U) + aOrbiterA) + RotL64(aOrbiterI, 11U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 29U)) + aOrbiterD);
            aWandererK = aWandererK ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterC, 5U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 22U));
            aCarry = aCarry + RotL64(aWandererA, 27U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 24931U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneB[((aIndex + 24935U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 23214U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 22428U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((aIndex + 25493U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 37U) + RotL64(aCarry, 51U)) + (RotL64(aIngress, 18U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 29U)) + RotL64(aCarry, 51U)) + 12849591986267890852U;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 53U)) + 8232614804696815750U) + aNonceWordJ;
            aOrbiterF = (((aWandererD + RotL64(aScatter, 5U)) + RotL64(aCarry, 27U)) + 12141567259210877281U) + aNonceWordM;
            aOrbiterH = ((((aWandererE + RotL64(aCross, 37U)) + RotL64(aCarry, 5U)) + 2928641981037885644U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordL;
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 13U)) + 980733350554783938U) + aNonceWordC;
            aOrbiterD = (aWandererG + RotL64(aIngress, 46U)) + 2683985177993350746U;
            aOrbiterG = ((aWandererH + RotL64(aScatter, 19U)) + 14532148403815527355U) + aPhaseDOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 7736296629433884203U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 10428437770166310549U;
            aOrbiterF = RotL64((aOrbiterF * 326634742742373401U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 18327174144859461029U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 6810436935194432002U;
            aOrbiterA = RotL64((aOrbiterA * 2715987179577753597U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 12606153309690753435U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 17123256945895150555U) ^ aNonceWordO;
            aOrbiterC = RotL64((aOrbiterC * 13469111258504672565U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 9057777759026189541U) + aNonceWordN;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 16478485918911194442U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11054247078884894131U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 18064460487552100483U) + aNonceWordE;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 11477276762421684083U;
            aOrbiterG = RotL64((aOrbiterG * 3886501230380184395U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 18318375441973295081U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 13849305985380030986U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12962140243967824959U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 10240409420338313641U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 18360586077779529086U;
            aOrbiterH = RotL64((aOrbiterH * 18196875422391501927U), 29U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 57U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 58U)) + aOrbiterF) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterE, 43U)) + aNonceWordI);
            aWandererC = aWandererC + ((RotL64(aIngress, 11U) + aOrbiterC) + RotL64(aOrbiterF, 13U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 18U) + aOrbiterH) + RotL64(aOrbiterG, 3U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 51U) + RotL64(aOrbiterD, 51U)) + aOrbiterE) + RotL64(aCarry, 57U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterG, 21U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 5U) + RotL64(aOrbiterA, 35U)) + aOrbiterG) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 10U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 3U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 28410U)) & S_BLOCK1], 57U) ^ RotL64(aInvestLaneA[((aIndex + 32308U)) & S_BLOCK1], 14U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 31228U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 27502U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31931U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aPrevious, 43U) + RotL64(aCarry, 27U)) + (RotL64(aIngress, 14U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterC = (aWandererC + RotL64(aCross, 5U)) + 13053031069776604052U;
            aOrbiterJ = (((aWandererA + RotL64(aIngress, 47U)) + RotL64(aCarry, 39U)) + 1331396630251085122U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = (((aWandererF + RotL64(aPrevious, 37U)) + RotL64(aCarry, 11U)) + 15879286043343942393U) + aNonceWordH;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 13U)) + 13590365633321406830U;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 21U)) + 14569235423040242618U) + aNonceWordM;
            aOrbiterB = ((((aWandererK + RotL64(aCross, 27U)) + RotL64(aCarry, 53U)) + 11397370636618371560U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordA;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 56U)) + 3455933494593971847U) + aNonceWordJ;
            //
            aOrbiterC = (((aOrbiterC + aOrbiterJ) + 1307153376443784593U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordO;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 10688618762584786871U;
            aOrbiterE = RotL64((aOrbiterE * 9503823896874842411U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 17746248451153600096U) + aNonceWordI;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 8512568600755410158U;
            aOrbiterA = RotL64((aOrbiterA * 16648320170768234063U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 8950230550112591092U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 17790968369472845496U) ^ aNonceWordD;
            aOrbiterC = RotL64((aOrbiterC * 5104988920132008913U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 12583323865381967534U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 11243927099685293887U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12867003042486433971U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 9690268715525781389U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 7466066217365074653U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17565696765505320889U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 3673528673209875118U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 14079103852360952255U;
            aOrbiterG = RotL64((aOrbiterG * 17449228863409999629U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 6747836856132250630U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 5027692924422297153U) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 2492421273167124437U), 53U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterG, 50U);
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterE, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 13U) + aOrbiterA) + RotL64(aOrbiterB, 21U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 36U)) + aOrbiterE) + RotL64(aCarry, 47U)) + aNonceWordC);
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterH, 43U)) + aNonceWordG) + aPhaseDWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterB, 27U)) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 41U) + aOrbiterA) + RotL64(aOrbiterG, 5U));
            aWandererI = aWandererI + (((RotL64(aCross, 27U) + RotL64(aOrbiterE, 57U)) + aOrbiterB) + aPhaseDWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 60U) + aOrbiterB) + RotL64(aOrbiterG, 13U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 14U);
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

void TwistExpander_Boxing_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xF1C728CF8D14919FULL + 0x8ED1E5B855880C96ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xDC7809EBD2D19527ULL + 0xF69CBA818E9F400EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xD34156169F11E34DULL + 0xE17CA596457F3ECFULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xCF257AEFB7767025ULL + 0xE858D943FE77BA8FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xD275C4B91E834F1BULL + 0x808CF51F6EA7D603ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xED92283F0B11F7E9ULL + 0x8C549D50FA764D5CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x98C225E749D7A083ULL + 0xB6C7A8D2F7C7301FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xF7B2713536EB0933ULL + 0xE1E2181E0974B7A9ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x98F0D6BBC5E74383ULL + 0xA9F17957C09636F5ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xBF6A6850E0E1B627ULL + 0xF278C5D0F5C382DDULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xDA7CD0A327D75DEBULL + 0x846A0328D2D09BB1ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x8460A431FEDE2891ULL + 0xDEA7E70974EFD349ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x8C0A98AC41575713ULL + 0xF3CCE858FBF6682EULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xD68F00B53237DE6FULL + 0xECFB054196CC47CBULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xC29CFE243D311C81ULL + 0xECB666D6CD95137DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xA05F4D12E088C0FFULL + 0x90563B90EF58E1B7ULL);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 2698U)) & S_BLOCK1], 51U) ^ RotL64(aInvestLaneB[((aIndex + 5045U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 4607U)) & S_BLOCK1], 42U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 4607U)) & S_BLOCK1], 52U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 985U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 2070U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCarry, 5U)) + (RotL64(aCross, 36U) ^ RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterA = (aWandererG + RotL64(aScatter, 43U)) + 8402620908307642697U;
            aOrbiterE = (aWandererD + RotL64(aCross, 14U)) + 11347672014525086047U;
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 39U)) + 2816462912503401876U) + aNonceWordD;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 57U)) + RotL64(aCarry, 3U)) + 6940159795470696093U;
            aOrbiterI = (aWandererH + RotL64(aIngress, 41U)) + 9134692490095883851U;
            aOrbiterF = ((aWandererE + RotL64(aCross, 5U)) + 4999455497008026526U) + aNonceWordF;
            aOrbiterG = (aWandererA + RotL64(aScatter, 51U)) + 5992451460350651332U;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 53U)) + 3417087346651371924U) + aPhaseEOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 3U)) + RotL64(aCarry, 51U)) + 3612773820086198270U;
            aOrbiterK = ((aWandererB + RotL64(aScatter, 36U)) + RotL64(aCarry, 47U)) + 463398077083428570U;
            aOrbiterH = (((aWandererF + RotL64(aCross, 11U)) + 11249391303705089012U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordJ;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 17027535139825739501U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 568131384979596481U;
            aOrbiterB = RotL64((aOrbiterB * 5683451044852895957U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 4793712537158004047U) + aNonceWordC;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 10415170179135963622U;
            aOrbiterE = RotL64((aOrbiterE * 13729564030210361415U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 2391473979460065630U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 4240058362680064261U) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 12375884373396400889U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 9963957011090031698U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 3325305624067445525U;
            aOrbiterJ = RotL64((aOrbiterJ * 3128542681461806309U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 2094945647665114693U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 10703615640774042674U;
            aOrbiterA = RotL64((aOrbiterA * 12641986098450423751U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 3768738815518590289U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 15021301790376706827U;
            aOrbiterK = RotL64((aOrbiterK * 14445850924223550339U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 10571246886181608316U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterJ) ^ 5130325144599151793U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterH = RotL64((aOrbiterH * 3185251943547657467U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 8617523421720966373U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 16574597770835250074U;
            aOrbiterF = RotL64((aOrbiterF * 1759209403428937799U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 17474733286551120355U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 17914672092861237776U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13657291990878792267U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 12856557371623447773U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 1636296609747335898U;
            aOrbiterD = RotL64((aOrbiterD * 9286345529656087313U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 12588848560509679821U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 8402620908307642697U;
            aOrbiterC = RotL64((aOrbiterC * 2269772223506258147U), 13U);
            //
            aIngress = RotL64(aOrbiterA, 3U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterC, 24U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + RotL64(aOrbiterG, 48U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterA, 39U));
            aWandererH = aWandererH + (((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterG, 47U)) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 30U) + aOrbiterI) + RotL64(aOrbiterB, 3U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterJ, 54U)) + aOrbiterH);
            aWandererK = aWandererK ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterD, 27U)) + aOrbiterC) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 13U)) + aOrbiterB);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 37U)) + aOrbiterD) + aNonceWordE);
            aWandererA = aWandererA + (((((RotL64(aScatter, 41U) + aOrbiterJ) + RotL64(aOrbiterA, 35U)) + RotL64(aCarry, 29U)) + aNonceWordM) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 41U)) + aOrbiterE) + aNonceWordI);
            aWandererE = aWandererE + ((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterH, 5U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 50U) + RotL64(aOrbiterK, 20U)) + aOrbiterJ) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 50U));
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 53U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 6903U)) & S_BLOCK1], 41U) ^ RotL64(aInvestLaneC[((aIndex + 8193U)) & S_BLOCK1], 53U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 8979U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneC[((aIndex + 9751U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 5874U)) & S_BLOCK1], 11U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 7756U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 8038U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCross, 39U)) ^ (RotL64(aCarry, 5U) + RotL64(aPrevious, 18U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterE = (aWandererD + RotL64(aScatter, 37U)) + 252059974543142812U;
            aOrbiterG = (((aWandererG + RotL64(aIngress, 19U)) + RotL64(aCarry, 51U)) + 11690823093681457368U) + aNonceWordJ;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 44U)) + 13282189752890971123U) + aNonceWordK;
            aOrbiterB = (aWandererF + RotL64(aPrevious, 13U)) + 9507416294305708435U;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 23U)) + RotL64(aCarry, 37U)) + 14053038174390776539U;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 57U)) + 14605253312318725009U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = (aWandererE + RotL64(aPrevious, 41U)) + 18138286582677863671U;
            aOrbiterC = ((aWandererC + RotL64(aCross, 26U)) + RotL64(aCarry, 19U)) + 8530091235978489988U;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 3U)) + 14381731677571170073U) + aPhaseEOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 53U)) + 13316413456378978456U) + aNonceWordL;
            aOrbiterF = ((aWandererI + RotL64(aScatter, 35U)) + 3910529530149320706U) + aNonceWordD;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 6302070286831566901U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 12324134652758551396U;
            aOrbiterJ = RotL64((aOrbiterJ * 17136438281540250165U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 4773478557638475048U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 4031153435446078944U;
            aOrbiterH = RotL64((aOrbiterH * 3876928995240982769U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 3114794895962903899U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 3552936509969106796U;
            aOrbiterC = RotL64((aOrbiterC * 16823186892738820299U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 5828754613946145627U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 17985241114076114558U;
            aOrbiterK = RotL64((aOrbiterK * 1986669631395606833U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 11319331046368072261U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 6104267020171882160U;
            aOrbiterB = RotL64((aOrbiterB * 12525117969211576177U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 7662668379725735125U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 6583034411403600735U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 262095656452193889U), 37U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterB) + 5569865728026310280U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordC;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 4176065898330374039U;
            aOrbiterI = RotL64((aOrbiterI * 11305749530796963967U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 13677146592276526676U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 2734371113158117596U) ^ aNonceWordM;
            aOrbiterE = RotL64((aOrbiterE * 13146444882662731975U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 14890607377967461739U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 3110674898918355049U;
            aOrbiterA = RotL64((aOrbiterA * 9637837600671200315U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 15329760212453783067U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 18214263442264013242U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9139354822936682953U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 6727267537859989206U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 252059974543142812U;
            aOrbiterF = RotL64((aOrbiterF * 9559128226993261041U), 11U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterD, 60U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + (RotL64(aOrbiterC, 40U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterF, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 34U) + aOrbiterH) + RotL64(aOrbiterJ, 13U));
            aWandererC = aWandererC + (((((RotL64(aPrevious, 57U) + RotL64(aOrbiterG, 29U)) + aOrbiterB) + RotL64(aCarry, 5U)) + aNonceWordO) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterK, 42U)) + aOrbiterD);
            aWandererD = aWandererD + ((RotL64(aIngress, 37U) + RotL64(aOrbiterF, 27U)) + aOrbiterI);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterD, 11U)) + aOrbiterJ);
            aWandererF = aWandererF + (((RotL64(aCross, 10U) + aOrbiterC) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 35U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 5U)) + aOrbiterB);
            aWandererK = aWandererK + ((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 19U)) + aOrbiterE);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterG, 39U)) + aOrbiterI);
            aWandererA = aWandererA + ((((RotL64(aCross, 41U) + RotL64(aOrbiterB, 48U)) + aOrbiterA) + aNonceWordB) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 57U)) + aOrbiterD) + aNonceWordN);
            //
            aCarry = aCarry + (RotL64(aWandererF, 6U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 18U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererK, 21U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 14544U)) & S_BLOCK1], 35U) ^ RotL64(aInvestLaneA[((aIndex + 14647U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13486U)) & S_BLOCK1], 12U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 15717U)) & S_BLOCK1], 4U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 15709U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 6U) ^ RotL64(aPrevious, 57U)) ^ (RotL64(aCross, 19U) + RotL64(aIngress, 43U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterJ = (aWandererC + RotL64(aScatter, 19U)) + 1087148170018530502U;
            aOrbiterA = (aWandererG + RotL64(aIngress, 41U)) + 15530846874509311414U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 23U)) + 16987358651515511212U) + aPhaseEOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = (aWandererJ + RotL64(aCross, 12U)) + 12504143181007924259U;
            aOrbiterG = (aWandererH + RotL64(aPrevious, 43U)) + 393322117322732418U;
            aOrbiterE = (aWandererI + RotL64(aScatter, 37U)) + 14325937299241887166U;
            aOrbiterC = ((((aWandererA + RotL64(aCross, 27U)) + RotL64(aCarry, 19U)) + 9395262907017475742U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordO;
            aOrbiterK = (aWandererF + RotL64(aIngress, 5U)) + 13658510441418344769U;
            aOrbiterF = (((aWandererE + RotL64(aScatter, 3U)) + RotL64(aCarry, 41U)) + 6410754322737005336U) + aNonceWordK;
            aOrbiterB = (aWandererB + RotL64(aIngress, 58U)) + 9257290738538818434U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 53U)) + RotL64(aCarry, 13U)) + 7489828960857692286U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 4118778591214588387U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 16619215231168796563U;
            aOrbiterI = RotL64((aOrbiterI * 14876884956536265157U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 11326283811003573430U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 1865401866017614604U;
            aOrbiterJ = RotL64((aOrbiterJ * 8378326058282460073U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 670150121105733604U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 1499331510641068749U;
            aOrbiterC = RotL64((aOrbiterC * 16623742535540383107U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 1116410848560838532U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 2696841341036281779U;
            aOrbiterE = RotL64((aOrbiterE * 9598953298074904869U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 5487352391229549881U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 12008243050943342979U) ^ aNonceWordP;
            aOrbiterG = RotL64((aOrbiterG * 9087261224804582459U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 552859665927882960U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 8426942688524814473U) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 10916963622695549105U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 1613287981244830815U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterB) ^ 15592897923468694288U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterD = RotL64((aOrbiterD * 6600750586743893303U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 7629853970631002676U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 13778028957247561272U;
            aOrbiterH = RotL64((aOrbiterH * 4063798788229605659U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 2932956928094332652U) + aNonceWordI;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 14855524972646900872U;
            aOrbiterB = RotL64((aOrbiterB * 9546042275547649745U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 11071597794692793784U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 6327727700942234552U;
            aOrbiterK = RotL64((aOrbiterK * 15301120263944789797U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 5147576281502110428U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 1087148170018530502U;
            aOrbiterF = RotL64((aOrbiterF * 18045084130531645749U), 5U);
            //
            aIngress = RotL64(aOrbiterE, 41U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterF, 36U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterD, 27U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterJ, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 30U) + aOrbiterD) + RotL64(aOrbiterI, 35U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 51U) + aOrbiterJ) + RotL64(aOrbiterH, 42U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 27U) + aOrbiterH) + RotL64(aOrbiterK, 5U)) + aNonceWordJ);
            aWandererK = aWandererK ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterJ, 51U)) + aOrbiterA);
            aWandererE = aWandererE + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 19U)) + aOrbiterI) + RotL64(aCarry, 39U)) + aNonceWordL);
            aWandererG = aWandererG ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterJ, 56U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterG, 53U)) + aOrbiterD) + RotL64(aCarry, 19U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterK, 37U)) + aOrbiterI) + aPhaseEWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 4U) + aOrbiterH) + RotL64(aOrbiterG, 21U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 39U) + aOrbiterC) + RotL64(aOrbiterB, 39U));
            aWandererH = aWandererH + ((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 3U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererH, 18U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 54U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 16516U)) & S_BLOCK1], 27U) ^ RotL64(aSnowLaneA[((aIndex + 20448U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 18338U)) & S_BLOCK1], 12U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 16525U)) & S_BLOCK1], 53U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 18813U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aIngress, 3U)) ^ (RotL64(aCarry, 41U) + RotL64(aPrevious, 24U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterE = ((aWandererE + RotL64(aIngress, 57U)) + 18191288703716505885U) + aNonceWordA;
            aOrbiterC = ((((aWandererF + RotL64(aCross, 42U)) + RotL64(aCarry, 35U)) + 9824014524910417136U) + aPhaseEOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1]) + aNonceWordH;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 29U)) + RotL64(aCarry, 11U)) + 11953012029254917548U;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 13U)) + 6297568011027199089U;
            aOrbiterI = (aWandererK + RotL64(aCross, 51U)) + 2576999400457367975U;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 23U)) + 13176139160575558254U) + aNonceWordB;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 37U)) + RotL64(aCarry, 5U)) + 9978408174563621810U;
            aOrbiterK = ((aWandererA + RotL64(aIngress, 47U)) + 16765834875061607142U) + aNonceWordJ;
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 18U)) + 16534507305459121344U;
            aOrbiterB = ((aWandererC + RotL64(aCross, 53U)) + 3114710944346151807U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = (aWandererI + RotL64(aIngress, 27U)) + 10240517868726718592U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 10721450637990777883U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 16689590768796583952U;
            aOrbiterH = RotL64((aOrbiterH * 3046344179729901637U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 2427422768928450209U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 13495584061816457831U;
            aOrbiterA = RotL64((aOrbiterA * 6670984773768885119U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 7058636403765106682U) + aNonceWordE;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 9897341853944713767U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14286816859999869231U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 17749559755733386064U) + aNonceWordL;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 12515645083926326659U;
            aOrbiterF = RotL64((aOrbiterF * 6582878478865838245U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 2625692458813609962U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 10596240255026143019U;
            aOrbiterC = RotL64((aOrbiterC * 11605800195771080135U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 12374290338067865540U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 1507386663796330249U;
            aOrbiterJ = RotL64((aOrbiterJ * 1210241080424446087U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 9288099549484146726U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 15159312464747000702U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 500055502081347757U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 14998608679505446229U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 17625038109437732009U;
            aOrbiterG = RotL64((aOrbiterG * 14785862243019841689U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 10543192232885637211U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 10330547522729618042U;
            aOrbiterB = RotL64((aOrbiterB * 7635903835474874057U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 5753298214283941201U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 15943436872588208065U;
            aOrbiterD = RotL64((aOrbiterD * 17704547766822075741U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 5757218926946874970U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 18191288703716505885U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2644970408001409575U), 5U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterG, 47U);
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 23U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 4U));
            aIngress = aIngress + RotL64(aOrbiterH, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aCross, 3U) + RotL64(aOrbiterE, 35U)) + aOrbiterF) + RotL64(aCarry, 41U)) + aPhaseEWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterD, 41U)) + aOrbiterI);
            aWandererE = aWandererE + ((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 18U)) + aOrbiterA);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 48U) + RotL64(aOrbiterA, 23U)) + aOrbiterF) + aNonceWordD);
            aWandererG = aWandererG + ((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterG, 5U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterA, 47U));
            aWandererA = aWandererA + (((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 37U)) + aOrbiterB) + aNonceWordK);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterH, 29U)) + aOrbiterB);
            aWandererF = aWandererF + ((RotL64(aCross, 21U) + RotL64(aOrbiterK, 58U)) + aOrbiterB);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 24U) + RotL64(aOrbiterH, 39U)) + aOrbiterD) + aNonceWordN);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 37U) + aOrbiterE) + RotL64(aOrbiterC, 43U)) + RotL64(aCarry, 57U)) + aPhaseEWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 58U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (RotL64(aWandererI, 48U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 35U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 26595U)) & S_BLOCK1], 40U) ^ RotL64(aSnowLaneB[((aIndex + 22853U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 26663U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25535U)) & S_BLOCK1], 37U) ^ RotL64(aSnowLaneA[((aIndex + 23113U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 19U) ^ RotL64(aPrevious, 51U)) + (RotL64(aCarry, 37U) + RotL64(aIngress, 4U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterK = (aWandererC + RotL64(aIngress, 21U)) + 2571116506511057880U;
            aOrbiterE = ((aWandererG + RotL64(aCross, 11U)) + 13112435411509707292U) + aNonceWordP;
            aOrbiterI = (aWandererD + RotL64(aScatter, 44U)) + 10403251762787357256U;
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 13U)) + RotL64(aCarry, 51U)) + 8461951095541400405U;
            aOrbiterH = (aWandererE + RotL64(aIngress, 51U)) + 9890793478557463815U;
            aOrbiterA = (((aWandererJ + RotL64(aScatter, 39U)) + RotL64(aCarry, 23U)) + 3030229465991783707U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = (((aWandererB + RotL64(aCross, 19U)) + RotL64(aCarry, 29U)) + 7273848154043719247U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = (aWandererI + RotL64(aPrevious, 35U)) + 10681774862516028276U;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 3U)) + 7105082755586853104U) + aNonceWordM;
            aOrbiterB = (aWandererF + RotL64(aCross, 53U)) + 6588579345319551129U;
            aOrbiterG = (aWandererK + RotL64(aIngress, 56U)) + 14616333550242386092U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 15439666290229654921U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 3360304356760164799U;
            aOrbiterI = RotL64((aOrbiterI * 5164191920584106237U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 14438730801970761889U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 14515616787452085729U;
            aOrbiterA = RotL64((aOrbiterA * 2041601927968559821U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 4167853822635132419U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 8950982233003320239U;
            aOrbiterJ = RotL64((aOrbiterJ * 887144270884244907U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 12391327853728029953U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 7100871010552394421U) ^ aNonceWordE;
            aOrbiterK = RotL64((aOrbiterK * 16552349374101955967U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 15381697462381887944U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterA) ^ 6801677551341079401U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 13325954438427340703U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 947011315719204867U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 6356920162398333481U) ^ aNonceWordC;
            aOrbiterE = RotL64((aOrbiterE * 5566721941682667419U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 8910262020598577378U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 8778455415977526457U;
            aOrbiterB = RotL64((aOrbiterB * 4092470497616637283U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 5585696961453127223U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 9670655481681494412U;
            aOrbiterC = RotL64((aOrbiterC * 7863197168965036383U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 10713004007087085729U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 4036355047492922339U) ^ aNonceWordF;
            aOrbiterG = RotL64((aOrbiterG * 6923922258047667173U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 14580156873863533497U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 7049502932205025182U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8665428649262370727U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 12707521269341941677U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 2571116506511057880U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2388236789245943699U), 35U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 5U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + RotL64(aOrbiterC, 36U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aScatter, 27U) + aOrbiterH) + RotL64(aOrbiterA, 29U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 18U) + RotL64(aOrbiterH, 58U)) + aOrbiterJ);
            aWandererI = aWandererI + ((((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterB, 23U)) + RotL64(aCarry, 37U)) + aNonceWordK);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterK, 51U)) + aOrbiterD);
            aWandererF = aWandererF + (((RotL64(aScatter, 53U) + RotL64(aOrbiterE, 39U)) + aOrbiterC) + aNonceWordD);
            aWandererD = aWandererD ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterC, 44U)) + aOrbiterG);
            aWandererE = aWandererE + (((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 13U)) + aOrbiterF) + aNonceWordI);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 20U) + RotL64(aOrbiterB, 35U)) + aOrbiterI) + aNonceWordH);
            aWandererC = aWandererC + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterD, 11U)) + aOrbiterG) + RotL64(aCarry, 13U)) + aPhaseEWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 23U) + aOrbiterI) + RotL64(aOrbiterA, 27U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 37U) + aOrbiterK) + RotL64(aOrbiterH, 19U)) + aPhaseEWandererUpdateSaltB[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 34U));
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 21U);
            aCarry = aCarry + RotL64(aIngress, 50U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 28748U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneA[((aIndex + 28525U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 30851U)) & S_BLOCK1], 30U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27516U)) & S_BLOCK1], 4U) ^ RotL64(aInvestLaneB[((aIndex + 27731U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 54U) ^ RotL64(aPrevious, 41U)) + (RotL64(aCarry, 23U) ^ RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterF = ((aWandererG + RotL64(aCross, 11U)) + 3238389262925516513U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 51U)) + 12381787182611386995U) + aNonceWordI;
            aOrbiterE = (aWandererF + RotL64(aScatter, 53U)) + 7883885539305181549U;
            aOrbiterH = (aWandererI + RotL64(aIngress, 57U)) + 1185413044597727092U;
            aOrbiterG = (aWandererD + RotL64(aCross, 37U)) + 15219353497204773135U;
            aOrbiterI = (((aWandererC + RotL64(aPrevious, 13U)) + RotL64(aCarry, 43U)) + 7533774715626734082U) + aNonceWordG;
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 6U)) + RotL64(aCarry, 29U)) + 2599930450937763464U;
            aOrbiterA = (aWandererB + RotL64(aScatter, 39U)) + 16074720663961214284U;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 41U)) + 15483613196360051221U) + aPhaseEOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = (((aWandererK + RotL64(aCross, 43U)) + RotL64(aCarry, 5U)) + 9396557867081376268U) + aNonceWordK;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 4U)) + 9668459976852660245U) + aNonceWordE;
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 9037269914643207212U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 16936742640861088240U;
            aOrbiterE = RotL64((aOrbiterE * 1040172193161012227U), 47U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterF) + 16481274825758546398U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1]) + aNonceWordF;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 481851372837611166U;
            aOrbiterG = RotL64((aOrbiterG * 2225030139210599207U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 13608921517203544108U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 16930740723286214636U;
            aOrbiterH = RotL64((aOrbiterH * 2605108503821980865U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 902242902582149908U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 1510861213079342977U;
            aOrbiterK = RotL64((aOrbiterK * 3309753895727400707U), 5U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterC) + 7116243600304980310U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordC;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 6631412278359709602U;
            aOrbiterA = RotL64((aOrbiterA * 11452627691392637463U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 9246698682265275165U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 8594373032014031450U;
            aOrbiterB = RotL64((aOrbiterB * 2550138341089957033U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 15912837963877821048U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 11404583513022627609U) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 17715204726760125357U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 17295214920690244319U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 18315664494984189344U;
            aOrbiterF = RotL64((aOrbiterF * 17398893532076312945U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 2474825506593695564U) + aNonceWordA;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 4400473621592150441U;
            aOrbiterI = RotL64((aOrbiterI * 7098832854166953839U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 15270166373215060119U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 4331232225067306139U;
            aOrbiterJ = RotL64((aOrbiterJ * 2299883590703870703U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 2176207815544347316U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 3238389262925516513U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13104597690682251231U), 29U);
            //
            aIngress = RotL64(aOrbiterC, 13U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterF, 4U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aCross, 53U) + RotL64(aOrbiterB, 57U)) + aOrbiterF);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterI, 18U));
            aWandererA = aWandererA + ((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterG, 39U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 46U) + RotL64(aOrbiterB, 35U)) + aOrbiterC) + aNonceWordM);
            aWandererK = aWandererK + ((RotL64(aScatter, 27U) + RotL64(aOrbiterH, 13U)) + aOrbiterK);
            aWandererC = aWandererC ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterF, 23U)) + aOrbiterJ);
            aWandererF = aWandererF + (((RotL64(aIngress, 41U) + RotL64(aOrbiterE, 41U)) + aOrbiterF) + aPhaseEWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 34U) + aOrbiterH) + RotL64(aOrbiterA, 37U));
            aWandererD = aWandererD + ((((RotL64(aCross, 13U) + RotL64(aOrbiterB, 3U)) + aOrbiterH) + RotL64(aCarry, 27U)) + aNonceWordH);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 21U) + aOrbiterE) + RotL64(aOrbiterK, 11U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 29U) + RotL64(aOrbiterD, 46U)) + aOrbiterJ) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 60U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 21U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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

void TwistExpander_Boxing_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xE93FBF1B99B88939ULL + 0x9449F8831A03CD41ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xCF02901B5231A87FULL + 0x845B7B8B1ACE9F0DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xF631A2397FE50D2DULL + 0x998B57E7C16E6BA6ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x92549F23BA768B75ULL + 0xC83DA8A7BA9085BAULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xEC7AFA9302E9E2A3ULL + 0xCCAC898BDA7918E2ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xD480F1A2A145402FULL + 0x80E3B6491A755773ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x88C1ACF966E060A3ULL + 0xCC06BF597FAD62A8ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xD088CC1C5AD9245FULL + 0xF11AB8F387AF6FF9ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x975394A4ED1F504BULL + 0xAA11E1A356AFD287ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xA7AA2AB3966D34EFULL + 0xA69BDC3F6C9671F8ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xD0B42D71C3CF14B9ULL + 0xEABCA207A6E214E1ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xB1EADB731BDC1387ULL + 0xC044715908A6985BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xA3CF7962C3830E2BULL + 0xF6FAF704208B8F95ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xB5A252317E70733BULL + 0xF665CABAF55DEC46ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xBFDCA5190FB929B7ULL + 0xE2F8B6EC47F42D8BULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xEC3CC504D6BB6635ULL + 0xF8EB7EA57EB4DFFAULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 4158U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneB[((aIndex + 2019U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 4738U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3884U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 673U)) & S_BLOCK1], 20U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 3864U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 43U)) ^ (RotL64(aCross, 28U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterH = ((aWandererI + RotL64(aCross, 4U)) + 5510690816044082200U) + aNonceWordG;
            aOrbiterK = (aWandererK + RotL64(aIngress, 35U)) + 15967820875033940530U;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 21U)) + 539348720848176221U;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 11U)) + 15779318183635560817U) + aNonceWordP;
            aOrbiterF = (((aWandererJ + RotL64(aCross, 53U)) + RotL64(aCarry, 11U)) + 14511058534424187469U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 60U)) + RotL64(aCarry, 35U)) + 5811130556873428391U;
            aOrbiterI = (((aWandererC + RotL64(aScatter, 39U)) + RotL64(aCarry, 43U)) + 1085928476499444025U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = (aWandererA + RotL64(aIngress, 47U)) + 6973335316600768130U;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 43U)) + 10747243745475009744U) + aNonceWordA;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 1072260008981349754U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 2018772405352495753U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10840562112080574241U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 1092091597048996547U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 15103140149542167197U) ^ aNonceWordL;
            aOrbiterF = RotL64((aOrbiterF * 621856991658027989U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 13194619321108681542U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 16749188603268621850U;
            aOrbiterK = RotL64((aOrbiterK * 9575408950550922039U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 7427959503086895166U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 9895804051379551393U) ^ aNonceWordE;
            aOrbiterB = RotL64((aOrbiterB * 2701997336201570715U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 4526020800679774259U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 4484850928870048176U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17556987520625677313U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 1837404844299040155U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 15213208978489570694U;
            aOrbiterI = RotL64((aOrbiterI * 7062740584650274133U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9615231781751396800U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 15872192167825648096U;
            aOrbiterD = RotL64((aOrbiterD * 2900526493682580729U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 12530672039655918903U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 10617836782870315804U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9716778004909794973U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 550750725406860977U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 3498554352021622907U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9846933294851238495U), 57U);
            //
            aIngress = RotL64(aOrbiterJ, 47U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterH, 21U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterC, 24U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aIngress, 10U) + RotL64(aOrbiterF, 22U)) + aOrbiterB);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterG, 5U)) + aOrbiterI);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 39U)) + aNonceWordM);
            aWandererC = aWandererC ^ ((((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterG, 53U)) + aNonceWordI) + aPhaseFWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 27U) + aOrbiterK) + RotL64(aOrbiterH, 41U)) + aPhaseFWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterK, 57U)) + aNonceWordB);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 51U) + RotL64(aOrbiterD, 27U)) + aOrbiterK) + RotL64(aCarry, 5U)) + aNonceWordJ);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 37U)) + aOrbiterH);
            aWandererA = aWandererA + ((RotL64(aCross, 42U) + aOrbiterB) + RotL64(aOrbiterC, 48U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + (RotL64(aWandererI, 46U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 13U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 9827U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneC[((aIndex + 6275U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 8096U)) & S_BLOCK1], 37U) ^ RotL64(aFireLaneC[((aIndex + 10693U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 9300U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7154U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 7772U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 43U) ^ RotL64(aPrevious, 23U)) + (RotL64(aCross, 56U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterG = (aWandererE + RotL64(aScatter, 43U)) + 10404808878585437255U;
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 36U)) + 10587858736301591439U) + aPhaseFOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = ((((aWandererI + RotL64(aIngress, 13U)) + RotL64(aCarry, 13U)) + 1430530909801644435U) + aPhaseFOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterI = (aWandererB + RotL64(aCross, 29U)) + 9090938022430118902U;
            aOrbiterD = (((aWandererG + RotL64(aScatter, 21U)) + RotL64(aCarry, 37U)) + 12936604311751121235U) + aNonceWordE;
            aOrbiterC = (aWandererC + RotL64(aCross, 53U)) + 1000583006020232032U;
            aOrbiterK = (((aWandererK + RotL64(aPrevious, 60U)) + RotL64(aCarry, 27U)) + 12352532088997042232U) + aNonceWordL;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 47U)) + 16723410947058502564U;
            aOrbiterH = (aWandererF + RotL64(aCross, 5U)) + 16614089235313154270U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 4245553025593349277U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 3353146318549477494U;
            aOrbiterF = RotL64((aOrbiterF * 14246377408238318091U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 5935727336135635196U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 10312187090293319667U;
            aOrbiterD = RotL64((aOrbiterD * 1395964500396711899U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 12192843181244744484U) + aNonceWordP;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 2542570124502586365U;
            aOrbiterK = RotL64((aOrbiterK * 17222847847573534963U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 3315472769469002444U) + aNonceWordC;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 17512858811783071174U;
            aOrbiterG = RotL64((aOrbiterG * 9070400454074283765U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 16633218007427888082U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 2502077714838858460U;
            aOrbiterA = RotL64((aOrbiterA * 970762420815997725U), 57U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterH) + 14792910273226469214U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordK;
            aOrbiterI = (((aOrbiterI ^ aOrbiterA) ^ 15739513291150783151U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterI = RotL64((aOrbiterI * 11896279674116906915U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 2192903544350345992U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 844428341223009295U;
            aOrbiterH = RotL64((aOrbiterH * 4768368713974002539U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 2998511458298901402U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 7790789639864783373U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9173097618440495497U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 4540735375055164995U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 13700342877362633034U;
            aOrbiterC = RotL64((aOrbiterC * 14730797752841670505U), 53U);
            //
            aIngress = RotL64(aOrbiterD, 13U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 58U));
            aIngress = aIngress + (RotL64(aOrbiterH, 37U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 23U)) + aOrbiterJ);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 53U) + aOrbiterC) + RotL64(aOrbiterF, 53U));
            aWandererH = aWandererH + (((RotL64(aCross, 27U) + aOrbiterA) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 11U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 46U) + aOrbiterG) + RotL64(aOrbiterF, 58U)) + aNonceWordA);
            aWandererE = aWandererE + ((((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterC, 47U)) + RotL64(aCarry, 37U)) + aPhaseFWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterK, 27U)) + aOrbiterD);
            aWandererI = aWandererI + ((RotL64(aIngress, 23U) + RotL64(aOrbiterH, 41U)) + aOrbiterD);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 41U) + aOrbiterK) + RotL64(aOrbiterF, 34U)) + aNonceWordG);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 4U) + RotL64(aOrbiterJ, 19U)) + aOrbiterG) + aNonceWordD) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + RotL64(aWandererE, 34U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 11387U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((aIndex + 14590U)) & S_BLOCK1], 20U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 11457U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 16016U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneC[((aIndex + 12505U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aIngress, 14U)) ^ (RotL64(aCross, 39U) + RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterI = ((aWandererA + RotL64(aScatter, 3U)) + 18087125778766689269U) + aNonceWordB;
            aOrbiterH = (((aWandererH + RotL64(aPrevious, 30U)) + RotL64(aCarry, 29U)) + 13710545066503235196U) + aNonceWordI;
            aOrbiterC = (aWandererE + RotL64(aCross, 35U)) + 1701939704736254645U;
            aOrbiterA = (aWandererB + RotL64(aIngress, 51U)) + 8064093611384019909U;
            aOrbiterG = ((aWandererF + RotL64(aCross, 41U)) + 16623332751533885431U) + aPhaseFOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aIngress, 26U)) + RotL64(aCarry, 53U)) + 15590129153794910109U;
            aOrbiterB = (((aWandererD + RotL64(aScatter, 57U)) + 7413312683079107383U) + aPhaseFOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1]) + aNonceWordK;
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 13U)) + 4186064478651458810U;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 19U)) + RotL64(aCarry, 43U)) + 5501191643940735954U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 11064645242200570835U) + aNonceWordC;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 13825922087298055833U;
            aOrbiterC = RotL64((aOrbiterC * 7529317892716108867U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 5944980709887369970U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 8181136916070569646U;
            aOrbiterD = RotL64((aOrbiterD * 395183021205661827U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 15442336949157292482U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 11580554435240641337U;
            aOrbiterG = RotL64((aOrbiterG * 6654637892858767739U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 11240018128174598322U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 2027565596050777471U) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 18048186560314431815U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 16425887196883725233U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 16828683527588834095U;
            aOrbiterA = RotL64((aOrbiterA * 17746289103235902485U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 9923829146479008804U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 6669171007279929454U) ^ aNonceWordH;
            aOrbiterH = RotL64((aOrbiterH * 681823450939955099U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 3902430046523165149U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 6739998149289590041U;
            aOrbiterB = RotL64((aOrbiterB * 2675037435528416821U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 16014401255534234075U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 14741857638680634564U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8723611021403369393U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 5064807861673260054U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 968747317273200299U) ^ aNonceWordD;
            aOrbiterI = RotL64((aOrbiterI * 14122304002722582329U), 57U);
            //
            aIngress = RotL64(aOrbiterA, 60U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + (RotL64(aOrbiterC, 27U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aScatter, 51U) + aOrbiterI) + RotL64(aOrbiterB, 47U)) + RotL64(aCarry, 47U)) + aNonceWordP);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 37U) + aOrbiterG) + RotL64(aOrbiterC, 36U));
            aWandererB = aWandererB + (((((RotL64(aPrevious, 30U) + aOrbiterG) + RotL64(aOrbiterB, 27U)) + RotL64(aCarry, 11U)) + aNonceWordG) + aPhaseFWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterD, 19U)) + aOrbiterK);
            aWandererA = aWandererA + ((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterF, 5U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterF, 53U)) + aOrbiterD);
            aWandererK = aWandererK + ((((RotL64(aCross, 5U) + RotL64(aOrbiterH, 57U)) + aOrbiterA) + aNonceWordL) + aPhaseFWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 60U) + aOrbiterH) + RotL64(aOrbiterC, 14U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 41U) + aOrbiterH) + RotL64(aOrbiterD, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (RotL64(aWandererA, 26U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 17273U)) & S_BLOCK1], 5U) ^ RotL64(aSnowLaneA[((aIndex + 17521U)) & S_BLOCK1], 30U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 20167U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 18188U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 18260U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCross, 35U)) + (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 52U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterD = (((aWandererA + RotL64(aCross, 47U)) + RotL64(aCarry, 27U)) + 12692813903177772178U) + aNonceWordI;
            aOrbiterI = ((aWandererH + RotL64(aIngress, 51U)) + 7112496446691277899U) + aNonceWordP;
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 22U)) + RotL64(aCarry, 5U)) + 2112247138290568813U;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 57U)) + 3699421080882855947U) + aNonceWordL;
            aOrbiterF = ((aWandererC + RotL64(aCross, 35U)) + 13761832028354380922U) + aPhaseFOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aIngress, 39U)) + 9243822514887600214U) + aNonceWordG;
            aOrbiterK = ((aWandererE + RotL64(aScatter, 3U)) + RotL64(aCarry, 53U)) + 6863833516853046129U;
            aOrbiterE = (aWandererG + RotL64(aPrevious, 43U)) + 8863897995943098018U;
            aOrbiterB = ((aWandererB + RotL64(aCross, 26U)) + 13346785686701467520U) + aPhaseFOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 15309543066305531619U) + aNonceWordE;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 17515530938817919111U;
            aOrbiterH = RotL64((aOrbiterH * 16625193986319048245U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 760493237816424254U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 7282586354117620860U;
            aOrbiterF = RotL64((aOrbiterF * 2327153408185290635U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 4129706068526969105U) + aNonceWordO;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 7020175432730888755U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10095158356907592239U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 9102258982216515596U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 10822031305361453690U;
            aOrbiterK = RotL64((aOrbiterK * 2036205056490578491U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 12571477440964330246U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterE) ^ 8436347026653095199U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterD = RotL64((aOrbiterD * 17930734781213681573U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 14214789872073941940U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterB) ^ 12915911919403385001U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 13161681603528031511U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 15443240166233851298U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 7311369180113240915U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13339195007946889423U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 12976516224995960015U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 7823308381434556721U;
            aOrbiterI = RotL64((aOrbiterI * 502385172763861451U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 4829417661664149137U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 16306394751966719700U;
            aOrbiterB = RotL64((aOrbiterB * 5294376579588592157U), 53U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 43U);
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 50U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + RotL64(aOrbiterK, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterC, 6U)) + aOrbiterE);
            aWandererD = aWandererD + ((RotL64(aScatter, 4U) + RotL64(aOrbiterC, 57U)) + aOrbiterI);
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 43U)) + aOrbiterH) + aNonceWordF) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 39U) + aOrbiterH) + RotL64(aOrbiterJ, 39U)) + RotL64(aCarry, 53U)) + aNonceWordN);
            aWandererA = aWandererA ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterF, 11U)) + aOrbiterK);
            aWandererG = aWandererG + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterF, 29U)) + aOrbiterC);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 11U) + aOrbiterK) + RotL64(aOrbiterI, 53U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterD, 35U)) + aOrbiterK) + RotL64(aCarry, 43U)) + aPhaseFWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 52U) + RotL64(aOrbiterJ, 48U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 50U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererG, 13U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 24326U)) & S_BLOCK1], 5U) ^ RotL64(aSnowLaneB[((aIndex + 25190U)) & S_BLOCK1], 22U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 22582U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27066U)) & S_BLOCK1], 40U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 21967U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 24U) ^ RotL64(aCross, 43U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterF = ((aWandererE + RotL64(aScatter, 24U)) + RotL64(aCarry, 51U)) + 5697928251815176134U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 53U)) + RotL64(aCarry, 11U)) + 337587740689259575U;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 43U)) + RotL64(aCarry, 39U)) + 4927686903263973950U;
            aOrbiterB = (((aWandererC + RotL64(aCross, 19U)) + 3742409032569801033U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordI;
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 47U)) + 1608092659172197650U;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 3U)) + 15848744267145717509U) + aPhaseFOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aCross, 35U)) + 15300174177963339253U;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 28U)) + 14162868453323648628U) + aNonceWordA;
            aOrbiterC = (aWandererF + RotL64(aCross, 13U)) + 12020167069983729869U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 16259538291658723956U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 8516686212464112245U;
            aOrbiterE = RotL64((aOrbiterE * 4731296903548893627U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 3722184575520553132U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 5663609293306386784U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14364218128780764749U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 15265344442454471986U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 3050323350098829515U;
            aOrbiterG = RotL64((aOrbiterG * 5890624677162388135U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 1093356813820599238U) + aNonceWordC;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 15167726103772238440U;
            aOrbiterB = RotL64((aOrbiterB * 5719466863561311069U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 15170797965325981472U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 17826286701992981628U;
            aOrbiterF = RotL64((aOrbiterF * 11186808881726573677U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 14710892030473425181U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 397194787697553904U) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 14368930300818752833U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 1273724124862533034U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 13018397560392545616U;
            aOrbiterC = RotL64((aOrbiterC * 4644812473262395329U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 9638716186445643730U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 7255587739807843785U;
            aOrbiterI = RotL64((aOrbiterI * 6055682981584011189U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 9272350563697399628U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 1040729335295009339U) ^ aNonceWordB;
            aOrbiterJ = RotL64((aOrbiterJ * 17825687660830291443U), 29U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterI, 47U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + (RotL64(aOrbiterE, 23U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 40U));
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterJ, 23U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterA, 30U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 13U)) + aOrbiterB) + aNonceWordH);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 60U) + aOrbiterD) + RotL64(aOrbiterC, 19U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterI, 35U)) + aOrbiterF) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ ((((RotL64(aCross, 19U) + RotL64(aOrbiterE, 47U)) + aOrbiterI) + aNonceWordL) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 27U) + aOrbiterA) + RotL64(aOrbiterC, 5U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 54U) + RotL64(aOrbiterC, 60U)) + aOrbiterG) + aNonceWordM);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 39U) + RotL64(aOrbiterB, 51U)) + aOrbiterC) + RotL64(aCarry, 35U)) + aNonceWordK);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 26U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 30401U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((aIndex + 30640U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aInvestLaneD[((aIndex + 29855U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28356U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((aIndex + 29536U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aIngress, 58U)) ^ (RotL64(aPrevious, 27U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 3U)) + RotL64(aCarry, 19U)) + 966899917801652720U;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 58U)) + 10996327672320748649U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = ((aWandererD + RotL64(aIngress, 29U)) + 4188171566846621107U) + aNonceWordG;
            aOrbiterH = (((aWandererA + RotL64(aCross, 47U)) + RotL64(aCarry, 11U)) + 5886209243097387959U) + aNonceWordO;
            aOrbiterG = (((aWandererK + RotL64(aIngress, 51U)) + RotL64(aCarry, 3U)) + 14940428957136728111U) + aNonceWordP;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 23U)) + 179187285531914832U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 36U)) + 6685351948936817752U;
            aOrbiterK = (aWandererC + RotL64(aCross, 19U)) + 1894506461704029700U;
            aOrbiterE = ((aWandererI + RotL64(aScatter, 43U)) + 4182760368636977082U) + aNonceWordD;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 12523318028514940790U) + aNonceWordE;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 5059306166973366892U;
            aOrbiterD = RotL64((aOrbiterD * 2857409765717296483U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 5890872367917643851U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 17747338389865221534U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5306740664798049267U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 13906227834259884100U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 7152105382899756368U;
            aOrbiterI = RotL64((aOrbiterI * 6772157117358310485U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 17868101884759619240U) + aNonceWordJ;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 11758843266314148347U;
            aOrbiterB = RotL64((aOrbiterB * 5919135169337501485U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 13950566197090324859U) + aNonceWordM;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 17278105609930477854U) ^ aNonceWordH;
            aOrbiterA = RotL64((aOrbiterA * 11431842718945107359U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 9556785965646738355U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 841298436857932987U;
            aOrbiterE = RotL64((aOrbiterE * 15077843186688841797U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 1951515285492133830U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 15775839819330588437U;
            aOrbiterK = RotL64((aOrbiterK * 7902654031401620995U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 5585458468816495436U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 17258586689032223623U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1652050227399194271U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 5254132659445988836U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 15440741734777060925U;
            aOrbiterJ = RotL64((aOrbiterJ * 17445581079035134067U), 11U);
            //
            aIngress = RotL64(aOrbiterK, 34U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 39U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 23U) + aOrbiterB) + RotL64(aOrbiterH, 4U)) + aPhaseFWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aCross, 34U) + aOrbiterJ) + RotL64(aOrbiterD, 35U)) + aNonceWordB) + aPhaseFWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterI, 27U)) + aOrbiterB);
            aWandererK = aWandererK + ((RotL64(aScatter, 19U) + RotL64(aOrbiterJ, 23U)) + aOrbiterG);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 53U) + aOrbiterG) + RotL64(aOrbiterK, 52U));
            aWandererD = aWandererD + (((RotL64(aCross, 41U) + aOrbiterE) + RotL64(aOrbiterG, 43U)) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 27U) + aOrbiterK) + RotL64(aOrbiterI, 19U));
            aWandererH = aWandererH + (((RotL64(aIngress, 57U) + aOrbiterA) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 10U) + aOrbiterD) + RotL64(aOrbiterA, 57U)) + aNonceWordF);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 41U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 54U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 51U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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

void TwistExpander_Boxing_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xFC6970C49EE8F881ULL + 0xE2286CEF77C5531DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x99E54E7CC4299BCBULL + 0x84EA6B6B443397E8ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xB6C89F3835D93C91ULL + 0xE3E6F866D3D7C298ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xA4ABC861E557DF71ULL + 0xE3340AFC4FC1436BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x9AAA9B1EF6EBD4FDULL + 0xE6C2F23BA129008CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x816D40E5E7473629ULL + 0xDB54805A715050DCULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xE9A012C9C43173B7ULL + 0xB33A438CAD3309F8ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xE9CB757952C373EFULL + 0x87F7EA9DBB516A9EULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xAAD8FCC357AA077BULL + 0xC48CB160D130AA7EULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xBC329A05EFCB78DBULL + 0xC9618B34136A2896ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xF385E8E2C8655DE7ULL + 0x9CA253D3BC0D9BC1ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xC29CFF30DFEA9275ULL + 0xF287E5CC52FE5C3BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x89F7E597E7F42FE5ULL + 0xCBFCACDB53883FACULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x8AE5BE5E8D6F5BFDULL + 0x845BE38E95EFAA56ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x9F098057123CFCDDULL + 0xF0BCEE2F0793FD4AULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xDD03DA980B613091ULL + 0xA37BA5C07BF25BDAULL);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 1160U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneB[((aIndex + 160U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 1650U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 2411U)) & S_BLOCK1], 35U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 2548U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 1227U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 51U) + RotL64(aCross, 27U)) ^ (RotL64(aCarry, 10U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterH = ((aWandererI + RotL64(aScatter, 47U)) + 12775735908960052604U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = ((aWandererG + RotL64(aIngress, 19U)) + RotL64(aCarry, 3U)) + 11791373812080296887U;
            aOrbiterD = (aWandererE + RotL64(aCross, 27U)) + 5537362877706057303U;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 5U)) + RotL64(aCarry, 19U)) + 2023912048504189380U;
            aOrbiterB = (aWandererH + RotL64(aScatter, 11U)) + 17668828109963766893U;
            aOrbiterE = (((aWandererD + RotL64(aIngress, 60U)) + 558908629933941224U) + aPhaseHOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1]) + aNonceWordK;
            aOrbiterG = (((aWandererK + RotL64(aCross, 53U)) + RotL64(aCarry, 41U)) + 1479633119685446888U) + aNonceWordF;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 15460320397843364063U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 10059749397555469054U;
            aOrbiterD = RotL64((aOrbiterD * 8671817118586065469U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 9987633811929693924U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 10087337844580228269U) ^ aNonceWordC;
            aOrbiterH = RotL64((aOrbiterH * 13817142288940843815U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 4446204415503364254U) + aNonceWordA;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 15106063243302192717U;
            aOrbiterJ = RotL64((aOrbiterJ * 13273756657334709803U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 9430197906134676162U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 1226048679997253363U;
            aOrbiterB = RotL64((aOrbiterB * 14247538885252664127U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 10611580584157624739U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 3137391249289641509U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5462682413239873181U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 9327201928815412810U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 7890659377013147073U;
            aOrbiterE = RotL64((aOrbiterE * 13827717178378062047U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 10675114832750356941U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 8804440385852327267U) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 8520671775587260601U), 23U);
            //
            aIngress = RotL64(aOrbiterD, 5U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 27U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 51U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((((RotL64(aScatter, 37U) + aOrbiterE) + RotL64(aOrbiterG, 5U)) + aNonceWordD) + aPhaseHWandererUpdateSaltD[((aIndex + 6U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 53U) + aOrbiterJ) + RotL64(aOrbiterE, 60U)) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterE, 53U)) + aOrbiterD);
            aWandererI = aWandererI + ((RotL64(aCross, 11U) + RotL64(aOrbiterD, 29U)) + aOrbiterH);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 3U) + aOrbiterB) + RotL64(aOrbiterD, 47U));
            aWandererD = aWandererD + (((RotL64(aCross, 23U) + RotL64(aOrbiterC, 13U)) + aOrbiterH) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 35U)) + aOrbiterD) + aNonceWordL) + aPhaseHWandererUpdateSaltB[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 12U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererI, 39U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 10734U)) & S_BLOCK1], 48U) ^ RotL64(aSnowLaneC[((aIndex + 9825U)) & S_BLOCK1], 39U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 10454U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneC[((aIndex + 10160U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 8250U)) & S_BLOCK1], 56U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 6513U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 8500U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aIngress, 3U)) ^ (RotL64(aCarry, 18U) ^ RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterK = (aWandererG + RotL64(aScatter, 13U)) + 11698283336767769359U;
            aOrbiterC = (((aWandererA + RotL64(aIngress, 29U)) + RotL64(aCarry, 5U)) + 13297826354831483872U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 37U)) + RotL64(aCarry, 57U)) + 15254999058287530795U;
            aOrbiterJ = (aWandererE + RotL64(aCross, 19U)) + 17474166585085346567U;
            aOrbiterI = (((aWandererH + RotL64(aScatter, 58U)) + RotL64(aCarry, 35U)) + 15684783498452840289U) + aNonceWordD;
            aOrbiterF = (((aWandererC + RotL64(aPrevious, 5U)) + 5061229733465216486U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordF;
            aOrbiterA = (aWandererB + RotL64(aCross, 51U)) + 15370981279168377944U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 17966672773619554092U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 14685092893994491068U;
            aOrbiterH = RotL64((aOrbiterH * 1627758964162892429U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 12798804186209406389U) + aNonceWordI;
            aOrbiterI = (((aOrbiterI ^ aOrbiterC) ^ 2848444181474221574U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterI = RotL64((aOrbiterI * 13730480364920876877U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 8551142075919636146U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 8833198159158950723U;
            aOrbiterK = RotL64((aOrbiterK * 7650289040764974737U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 7351473160893666232U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 14204899612487622222U;
            aOrbiterF = RotL64((aOrbiterF * 6317485031956448029U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 7008985178526543258U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 13576796403863120356U) ^ aNonceWordK;
            aOrbiterC = RotL64((aOrbiterC * 13745839827679114077U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 5769784656937900699U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 14075925808204936705U;
            aOrbiterJ = RotL64((aOrbiterJ * 5844894088757604713U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 17818667502858010896U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 16016922065572683130U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7525645833898085373U), 19U);
            //
            aIngress = RotL64(aOrbiterK, 28U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 53U) + aOrbiterI) + RotL64(aOrbiterK, 26U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterF, 3U)) + aOrbiterA) + aNonceWordG) + aPhaseHWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterJ, 11U)) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 41U)) + aOrbiterJ);
            aWandererH = aWandererH + (((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterJ, 19U)) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 10U) + RotL64(aOrbiterF, 35U)) + aOrbiterI) + aNonceWordA);
            aWandererC = aWandererC + ((RotL64(aScatter, 47U) + aOrbiterC) + RotL64(aOrbiterF, 51U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (RotL64(aWandererA, 42U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 15950U)) & S_BLOCK1], 37U) ^ RotL64(aSnowLaneA[((aIndex + 13936U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 14731U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12309U)) & S_BLOCK1], 6U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 15706U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCarry, 3U)) ^ (RotL64(aCross, 40U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterC = ((aWandererH + RotL64(aCross, 43U)) + RotL64(aCarry, 5U)) + 4751694786009671052U;
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 29U)) + 16362725160370844224U) + aPhaseHOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = (((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 19U)) + 6360885380915941057U) + aNonceWordH;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 6U)) + 5154536007972297036U) + aNonceWordP;
            aOrbiterG = ((aWandererD + RotL64(aCross, 53U)) + 9362540581874808253U) + aNonceWordG;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 23U)) + 13902493871525612934U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aIngress, 37U)) + RotL64(aCarry, 35U)) + 10208452885367546542U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 3117030377279160998U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 17286247690414027870U;
            aOrbiterD = RotL64((aOrbiterD * 4896931759653832095U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 3930314320040949141U) + aNonceWordE;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 7289525252391668404U;
            aOrbiterG = RotL64((aOrbiterG * 15452162299105112187U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 3434167955466809185U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 17852573095128575663U;
            aOrbiterC = RotL64((aOrbiterC * 1485660158767033425U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 6137259687928853253U) + aNonceWordC;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 13992510605237574698U;
            aOrbiterJ = RotL64((aOrbiterJ * 15346263295995333395U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 6470556523400123474U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 4333255670390099293U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11089933812030082647U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 7700424876430257995U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 16920736951239453071U;
            aOrbiterF = RotL64((aOrbiterF * 8920407493132380497U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 1635071690430295730U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 9966700845966398620U;
            aOrbiterE = RotL64((aOrbiterE * 17210048121896546867U), 19U);
            //
            aIngress = RotL64(aOrbiterF, 19U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 60U));
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aIngress, 37U) + aOrbiterE) + RotL64(aOrbiterF, 23U)) + aNonceWordL);
            aWandererA = aWandererA + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterG, 37U)) + aOrbiterA) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 30U) + aOrbiterE) + RotL64(aOrbiterJ, 50U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 5U) + aOrbiterJ) + RotL64(aOrbiterD, 57U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterJ, 11U)) + aOrbiterC) + aNonceWordK);
            aWandererH = aWandererH + ((((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterE, 5U)) + RotL64(aCarry, 41U)) + aNonceWordM);
            aWandererG = aWandererG ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterA, 29U)) + aOrbiterF) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererH, 52U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 19117U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((aIndex + 17352U)) & S_BLOCK1], 42U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 20337U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18374U)) & S_BLOCK1], 41U) ^ RotL64(aSnowLaneD[((aIndex + 20985U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 35U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 10U)) + 898812731947995389U) + aNonceWordG;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 29U)) + 8677347622525527167U) + aPhaseHOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = (((aWandererK + RotL64(aCross, 3U)) + RotL64(aCarry, 13U)) + 770321564027567654U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 53U)) + RotL64(aCarry, 29U)) + 11020474858081526395U;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 47U)) + 17289793580414993470U) + aNonceWordO;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 37U)) + RotL64(aCarry, 57U)) + 10111912559295118444U;
            aOrbiterB = ((aWandererJ + RotL64(aCross, 23U)) + 8083622125544542011U) + aNonceWordD;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 7149858558922988240U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 5919683821379905699U;
            aOrbiterI = RotL64((aOrbiterI * 16705119888884231567U), 53U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterF) + 6860902846079238714U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1]) + aNonceWordM;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 15083517836867542075U;
            aOrbiterE = RotL64((aOrbiterE * 4686657139237578325U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 14852868368708376381U) + aNonceWordB;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 9860233289028878323U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13418143547952204667U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 772406119079116272U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 7971141501337627589U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10168120622976358617U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 8478568022896691911U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 4027604850785607101U;
            aOrbiterJ = RotL64((aOrbiterJ * 4826627523578901467U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 17199331557841535430U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 7515957656979776361U;
            aOrbiterG = RotL64((aOrbiterG * 5468950152869656599U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 17138249294921502391U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 16236812863923234668U;
            aOrbiterF = RotL64((aOrbiterF * 2925542836624164807U), 13U);
            //
            aIngress = RotL64(aOrbiterE, 27U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterF, 12U)) + aNonceWordH) + aPhaseHWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 13U) + RotL64(aOrbiterF, 3U)) + aOrbiterJ) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterK, 53U)) + aOrbiterI);
            aWandererF = aWandererF + ((RotL64(aScatter, 22U) + RotL64(aOrbiterG, 29U)) + aOrbiterI);
            aWandererK = aWandererK ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterB, 41U)) + aOrbiterF);
            aWandererA = aWandererA + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 21U)) + aOrbiterI) + RotL64(aCarry, 27U)) + aNonceWordJ);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterB, 35U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 34U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererG, 13U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 22800U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneB[((aIndex + 22935U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 23414U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22725U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((aIndex + 24276U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 6U) ^ RotL64(aIngress, 41U)) ^ (RotL64(aCarry, 29U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterE = (aWandererI + RotL64(aIngress, 53U)) + 12046647397183218524U;
            aOrbiterG = (aWandererG + RotL64(aPrevious, 43U)) + 2760779375026461991U;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 19U)) + RotL64(aCarry, 37U)) + 13735454443176855650U;
            aOrbiterI = (((aWandererK + RotL64(aCross, 6U)) + RotL64(aCarry, 5U)) + 4370377000586647724U) + aNonceWordK;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 13U)) + 14566322384189969094U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterK = (aWandererE + RotL64(aScatter, 35U)) + 5056565959818422786U;
            aOrbiterJ = ((((aWandererJ + RotL64(aPrevious, 29U)) + RotL64(aCarry, 57U)) + 8795403810686579209U) + aPhaseHOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1]) + aNonceWordD;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 9625947666256011567U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 1703669290934254701U;
            aOrbiterC = RotL64((aOrbiterC * 5763881345676123583U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 6664070663184147951U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 2104148316797553431U;
            aOrbiterB = RotL64((aOrbiterB * 12887842067180975983U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 1197910004222596145U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 9922977170060903197U;
            aOrbiterI = RotL64((aOrbiterI * 13047828062605568603U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 2048376210852567829U) + aNonceWordJ;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 12568990647075931409U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9860242601194210927U), 35U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterC) + 15026894775772902751U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordM;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 3439447160137900629U;
            aOrbiterJ = RotL64((aOrbiterJ * 1813754963043785165U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 6532671388552829796U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 17261098369835997661U) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 568292591215203521U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 3171300991007459947U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 5935563269327662024U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11271790283157765003U), 3U);
            //
            aIngress = RotL64(aOrbiterI, 37U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterC, 12U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterI, 57U)) + aOrbiterE) + aNonceWordL);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 29U) + RotL64(aOrbiterJ, 41U)) + aOrbiterK) + RotL64(aCarry, 19U)) + aNonceWordN);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 35U)) + aOrbiterI);
            aWandererG = aWandererG + (((RotL64(aIngress, 53U) + RotL64(aOrbiterB, 11U)) + aOrbiterG) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterJ, 51U)) + aOrbiterG) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 22U) + aOrbiterC) + RotL64(aOrbiterK, 21U)) + aNonceWordC);
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterC, 4U)) + aNonceWordF) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 42U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + RotL64(aWandererE, 53U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28512U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 30717U)) & S_BLOCK1], 46U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 28540U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28164U)) & S_BLOCK1], 35U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 30230U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aIngress, 27U) + RotL64(aCross, 39U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCarry, 4U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterJ = ((((aWandererA + RotL64(aIngress, 35U)) + RotL64(aCarry, 41U)) + 15652862298542575895U) + aPhaseHOrbiterAssignSaltC[((aIndex + 18U)) & S_SALT1]) + aNonceWordA;
            aOrbiterI = (((aWandererH + RotL64(aScatter, 14U)) + RotL64(aCarry, 27U)) + 16925323928418184554U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aPrevious, 29U)) + 4413861484961668394U;
            aOrbiterB = (((aWandererI + RotL64(aCross, 57U)) + RotL64(aCarry, 13U)) + 2215946422098155969U) + aNonceWordJ;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 23U)) + 14975185533513111110U) + aNonceWordL;
            aOrbiterD = (aWandererF + RotL64(aCross, 43U)) + 9711613814905834552U;
            aOrbiterG = (aWandererK + RotL64(aIngress, 5U)) + 13154957291850149471U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 5058313016418534840U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 15011423472941211620U;
            aOrbiterE = RotL64((aOrbiterE * 6125316151731105673U), 21U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterJ) + 2030053257469580168U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordG;
            aOrbiterC = (((aOrbiterC ^ aOrbiterB) ^ 150530795186791193U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 11106050063717096073U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 10878237472104183427U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 11724672539469573109U;
            aOrbiterD = RotL64((aOrbiterD * 16158741837357985395U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 9589700906445846956U) + aNonceWordB;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 1367381624958248949U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8459515089081211977U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 12003215666757518106U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 11232479330848006729U;
            aOrbiterJ = RotL64((aOrbiterJ * 10993290955464593033U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 13013910456628561621U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 6092509838924105265U;
            aOrbiterI = RotL64((aOrbiterI * 805601154718006061U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 11999225836250312801U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 14421271973875748413U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9529010940887430157U), 27U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 29U);
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterD, 36U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 26U) + aOrbiterJ) + RotL64(aOrbiterI, 39U)) + aPhaseHWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterB, 28U)) + aOrbiterC);
            aWandererA = aWandererA + ((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterD, 51U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 3U)) + aOrbiterG) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 37U) + RotL64(aOrbiterB, 21U)) + aOrbiterI) + RotL64(aCarry, 11U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 57U)) + aOrbiterE) + aNonceWordN);
            aWandererI = aWandererI + ((((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterD, 13U)) + RotL64(aCarry, 29U)) + aNonceWordE);
            //
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 20U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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

void TwistExpander_Boxing_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE;
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
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF;
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 2256U)) & W_KEY1], 6U) ^ RotL64(aKeyRowReadB[((aIndex + 1578U)) & W_KEY1], 19U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 1566U)) & W_KEY1], 42U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 2447U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aPrevious, 37U)) ^ (RotL64(aIngress, 52U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = (aWandererC + RotL64(aScatter, 10U)) + 15910560457440369082U;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 27U)) + 17953072986407436888U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 37U)) + 15446940721193538669U) + aPhaseAOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = (aWandererA + RotL64(aCross, 5U)) + 3020785262774422009U;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 43U)) + RotL64(aCarry, 5U)) + 7001288645424994404U;
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 20U)) + 13385250665458462689U;
            aOrbiterG = ((aWandererE + RotL64(aCross, 53U)) + RotL64(aCarry, 21U)) + 4841895644623005949U;
            aOrbiterF = (aWandererK + RotL64(aIngress, 47U)) + 13053476783239482065U;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 57U)) + RotL64(aCarry, 35U)) + 641996979335975244U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 16211238020928688299U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 12715448751323279480U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2116880429675303291U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 17784406727699995290U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 16626339815786580778U;
            aOrbiterB = RotL64((aOrbiterB * 13940754474750138041U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 9035070625716345139U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 6085848172494001945U;
            aOrbiterK = RotL64((aOrbiterK * 10405728912339646693U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 1177103851507561053U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 2281901691017816407U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3142197009403602497U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 9040984343694325070U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 13334258224023902365U;
            aOrbiterJ = RotL64((aOrbiterJ * 4782523727707164869U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 1079824790138592518U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 14024082692012948652U;
            aOrbiterG = RotL64((aOrbiterG * 3219489374333737903U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 2966776524421278970U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 5510281854029308547U;
            aOrbiterA = RotL64((aOrbiterA * 9275402927591867297U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 7126632329316720048U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 1476827035602733472U;
            aOrbiterC = RotL64((aOrbiterC * 2217671289726794033U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 6470212302133184965U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 4172257438373147415U;
            aOrbiterH = RotL64((aOrbiterH * 4449314239630366533U), 53U);
            //
            aIngress = RotL64(aOrbiterB, 43U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 6U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + RotL64(aOrbiterG, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterB, 50U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 37U) + aOrbiterK) + RotL64(aOrbiterF, 13U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 11U) + aOrbiterG) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 41U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterK, 57U)) + aOrbiterH);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 47U) + RotL64(aOrbiterH, 46U)) + aOrbiterI) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterH, 23U)) + aOrbiterC);
            aWandererA = aWandererA + (((RotL64(aPrevious, 23U) + aOrbiterA) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 28U) + aOrbiterC) + RotL64(aOrbiterI, 5U));
            aWandererK = aWandererK + ((RotL64(aIngress, 51U) + aOrbiterA) + RotL64(aOrbiterB, 39U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 6U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 3577U)) & S_BLOCK1], 23U) ^ RotL64(aKeyRowReadA[((aIndex + 4405U)) & W_KEY1], 48U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 2969U)) & W_KEY1], 56U) ^ RotL64(mSource[((aIndex + 3638U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCarry, 47U)) + (RotL64(aIngress, 35U) ^ RotL64(aCross, 10U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = (aWandererB + RotL64(aScatter, 57U)) + 18319689184146942855U;
            aOrbiterC = (aWandererG + RotL64(aIngress, 29U)) + 8041304130090501019U;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 18U)) + RotL64(aCarry, 27U)) + 11347064191990897738U;
            aOrbiterA = ((aWandererC + RotL64(aCross, 41U)) + RotL64(aCarry, 57U)) + 15242243470024447468U;
            aOrbiterB = (aWandererJ + RotL64(aIngress, 47U)) + 10619749107163611105U;
            aOrbiterF = (aWandererK + RotL64(aCross, 37U)) + 14795614276221947128U;
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 3U)) + 1578095288886372393U) + aPhaseAOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aScatter, 52U)) + RotL64(aCarry, 41U)) + 13593906305770501684U;
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 13U)) + 8919815528334599172U) + aPhaseAOrbiterAssignSaltB[((aIndex + 8U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 17425548324720065145U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 11125018338392347335U;
            aOrbiterG = RotL64((aOrbiterG * 4377887040461528587U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 3779189180734244399U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 10958224663276134041U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6206963519509783781U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 4317305352561612995U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 4891139433808505355U;
            aOrbiterK = RotL64((aOrbiterK * 11507024985663120317U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 5166074784835930965U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 10080890270621589202U;
            aOrbiterF = RotL64((aOrbiterF * 13170894418184288695U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 4501071771615514619U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 6486573807774431753U;
            aOrbiterB = RotL64((aOrbiterB * 324029625116648669U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 15714881857668975753U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 3506619392820235900U;
            aOrbiterA = RotL64((aOrbiterA * 5707033870161224499U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 5295711072762443783U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 11192836530396570648U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4361810118382207039U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 7993389678399774574U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 12551394763541226695U;
            aOrbiterJ = RotL64((aOrbiterJ * 11903486656172026403U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 11553674370322129668U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 4459881583199320245U;
            aOrbiterH = RotL64((aOrbiterH * 2805857426321555685U), 35U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterI, 27U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 38U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterC, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 12U) + RotL64(aOrbiterK, 27U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aPrevious, 37U) + aOrbiterI) + RotL64(aOrbiterF, 14U)) + RotL64(aCarry, 29U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 5U) + aOrbiterC) + RotL64(aOrbiterH, 3U));
            aWandererB = aWandererB + ((RotL64(aIngress, 51U) + aOrbiterI) + RotL64(aOrbiterC, 23U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 20U) + RotL64(aOrbiterA, 53U)) + aOrbiterK) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 21U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 27U) + aOrbiterI) + RotL64(aOrbiterB, 60U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterJ, 47U)) + aOrbiterH);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterA, 41U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 18U));
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = RotL64(aFireLaneB[((aIndex + 7312U)) & S_BLOCK1], 51U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 8002U)) & W_KEY1], 4U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 6029U)) & W_KEY1], 5U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 5573U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 6500U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 28U)) + (RotL64(aIngress, 57U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = ((aWandererI + RotL64(aScatter, 57U)) + 5173905450211892891U) + aPhaseAOrbiterAssignSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = ((aWandererB + RotL64(aIngress, 22U)) + RotL64(aCarry, 19U)) + 3555542451908039957U;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 27U)) + RotL64(aCarry, 57U)) + 11559884700283861559U;
            aOrbiterF = ((aWandererD + RotL64(aCross, 37U)) + RotL64(aCarry, 43U)) + 1352524329968738673U;
            aOrbiterG = (aWandererG + RotL64(aPrevious, 5U)) + 8914206450420616349U;
            aOrbiterC = (aWandererH + RotL64(aIngress, 47U)) + 2251523378498463946U;
            aOrbiterB = (aWandererJ + RotL64(aScatter, 42U)) + 9541575923299247038U;
            aOrbiterK = ((aWandererK + RotL64(aCross, 51U)) + 1239854507907214595U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aScatter, 11U)) + 17698101462598498934U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 12305566971683256060U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 13804545036303215569U;
            aOrbiterJ = RotL64((aOrbiterJ * 10359543704152744971U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 10239749097704329264U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 4212214906286320308U;
            aOrbiterG = RotL64((aOrbiterG * 3661436621615751071U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 12192418916967430783U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 4475514289326450361U;
            aOrbiterF = RotL64((aOrbiterF * 17497164630368757887U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 17376102613298827459U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 18129393209955439341U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6404089025014118979U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 4014763724300253568U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 17325007199676828814U;
            aOrbiterC = RotL64((aOrbiterC * 1420888274815627083U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 15480474849292388685U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 14357924730184375449U;
            aOrbiterK = RotL64((aOrbiterK * 16723492259068034209U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 4335731868597970070U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 8296023680394303015U;
            aOrbiterH = RotL64((aOrbiterH * 14027415401430120543U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 2807312426993262800U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 15510369660839648501U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 18207954408298333959U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 12597844696606519907U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 7231012798553551535U;
            aOrbiterI = RotL64((aOrbiterI * 2841306785994479299U), 47U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 23U);
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 20U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterG, 51U));
            aWandererG = aWandererG + ((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterK, 56U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 51U) + aOrbiterE) + RotL64(aOrbiterI, 47U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 43U)) + aOrbiterJ) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 10U) + aOrbiterB) + RotL64(aOrbiterH, 13U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 57U) + aOrbiterC) + RotL64(aOrbiterF, 4U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 29U)) + aOrbiterG);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 41U) + aOrbiterI) + RotL64(aOrbiterG, 21U)) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 34U) + RotL64(aOrbiterJ, 35U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 54U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 10838U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadB[((aIndex + 8572U)) & W_KEY1], 26U));
            aIngress ^= (RotL64(mSource[((aIndex + 10368U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 9925U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 8858U)) & W_KEY1], 10U) ^ RotL64(aFireLaneB[((aIndex + 9814U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 4U) + RotL64(aIngress, 51U)) ^ (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = (aWandererK + RotL64(aPrevious, 47U)) + 1210605127156905516U;
            aOrbiterD = (aWandererI + RotL64(aIngress, 51U)) + 11964595428173569519U;
            aOrbiterK = (aWandererG + RotL64(aScatter, 3U)) + 16277319029916258482U;
            aOrbiterF = (aWandererH + RotL64(aCross, 14U)) + 12369497463101824572U;
            aOrbiterE = (((aWandererB + RotL64(aPrevious, 35U)) + RotL64(aCarry, 29U)) + 6201248574067068202U) + aPhaseBOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aScatter, 39U)) + 1727477025667206661U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = ((aWandererA + RotL64(aIngress, 23U)) + RotL64(aCarry, 43U)) + 1404510627789806851U;
            aOrbiterC = ((aWandererD + RotL64(aCross, 57U)) + RotL64(aCarry, 5U)) + 6948213591282018925U;
            aOrbiterI = (aWandererC + RotL64(aScatter, 30U)) + 6688865181284421478U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 3351130769402360855U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 12681032488906270823U;
            aOrbiterK = RotL64((aOrbiterK * 3680893896579741263U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 3591412591193726763U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 16153817571210878589U;
            aOrbiterE = RotL64((aOrbiterE * 4165137036092246349U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 3808228354421006630U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 1427373776207504205U;
            aOrbiterH = RotL64((aOrbiterH * 4534374093769595531U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 1831554180932501132U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 1114853085120949215U;
            aOrbiterI = RotL64((aOrbiterI * 4264176108298812905U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 2080935638828366835U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 16104777999646489828U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15205199362011777473U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 9782806013673440791U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 3721620299829386454U;
            aOrbiterF = RotL64((aOrbiterF * 6286765834910272409U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 4013706412064296527U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 5751022780695158579U;
            aOrbiterA = RotL64((aOrbiterA * 13766736471646116397U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 17684546333240329338U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 1106947111128020920U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3158839453318658951U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 11564229705849500598U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 1585817314460274286U;
            aOrbiterG = RotL64((aOrbiterG * 12687162159791577431U), 53U);
            //
            aIngress = RotL64(aOrbiterC, 12U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 23U) + RotL64(aOrbiterG, 3U)) + aOrbiterI) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterE, 57U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 10U) + aOrbiterF) + RotL64(aOrbiterE, 13U)) + RotL64(aCarry, 19U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterK, 24U)) + aOrbiterF);
            aWandererF = aWandererF + ((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 29U)) + aOrbiterA);
            aWandererH = aWandererH ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterH, 47U)) + aOrbiterI) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 35U)) + aOrbiterC) + aPhaseBWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterD, 39U)) + aOrbiterI);
            aWandererA = aWandererA + ((RotL64(aCross, 14U) + RotL64(aOrbiterF, 18U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 30U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 12618U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadA[((aIndex + 13095U)) & W_KEY1], 53U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 11160U)) & W_KEY1], 29U) ^ RotL64(mSource[((aIndex + 13477U)) & S_BLOCK1], 12U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 12886U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 10962U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneC[((aIndex + 11905U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 38U) ^ RotL64(aPrevious, 23U)) + (RotL64(aCross, 51U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = (aWandererH + RotL64(aCross, 3U)) + 4739486756133131180U;
            aOrbiterA = (aWandererD + RotL64(aScatter, 19U)) + 16089707555501328184U;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 46U)) + 15310047330238536453U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aPrevious, 57U)) + 7901411596386834955U;
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 11U)) + RotL64(aCarry, 43U)) + 4357555491060982163U;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 29U)) + 15667085602825720102U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aPrevious, 50U)) + 8520635334382269253U;
            aOrbiterD = ((aWandererJ + RotL64(aCross, 23U)) + RotL64(aCarry, 27U)) + 1772509779231068315U;
            aOrbiterF = ((aWandererF + RotL64(aScatter, 39U)) + RotL64(aCarry, 51U)) + 15336170957886025677U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 8628770833489469980U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 15469234024247246228U;
            aOrbiterE = RotL64((aOrbiterE * 8905266995119987947U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 10796430900884288328U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 10660110397012853289U;
            aOrbiterB = RotL64((aOrbiterB * 9140007610912037461U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 11202284258711214794U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 17509491802893182994U;
            aOrbiterA = RotL64((aOrbiterA * 9329107599972703671U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 16212572740740103554U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 2190030203761579226U;
            aOrbiterG = RotL64((aOrbiterG * 3101886685668871045U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 12014337082293041909U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 3733531010807001506U;
            aOrbiterI = RotL64((aOrbiterI * 5797362244066062299U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 7100994963061975529U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 17837541162838600258U;
            aOrbiterD = RotL64((aOrbiterD * 8745987361678166553U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 3311518938023146951U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 7709505172646831553U;
            aOrbiterJ = RotL64((aOrbiterJ * 7121143171245765213U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 4979968094554018443U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 16822214821463034107U;
            aOrbiterF = RotL64((aOrbiterF * 8618262120451291765U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 8376124175020587079U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 11084586282092424876U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5835632742522563537U), 43U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 24U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + RotL64(aOrbiterE, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 23U)) + aOrbiterD) + aPhaseBWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 60U) + RotL64(aOrbiterE, 51U)) + aOrbiterB);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 47U)) + aOrbiterK);
            aWandererC = aWandererC + ((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterK, 11U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterI, 56U)) + aOrbiterF);
            aWandererB = aWandererB + (((RotL64(aCross, 41U) + RotL64(aOrbiterB, 27U)) + aOrbiterA) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 14U) + RotL64(aOrbiterG, 19U)) + aOrbiterB) + aPhaseBWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 3U)) + aOrbiterJ) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterB, 38U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 18U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + RotL64(aWandererA, 11U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 16336U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneC[((aIndex + 13909U)) & S_BLOCK1], 42U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 14229U)) & W_KEY1], 27U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 15025U)) & W_KEY1], 46U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 14725U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 15016U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 15004U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 21U) ^ RotL64(aCross, 53U)) ^ (RotL64(aCarry, 36U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = ((aWandererD + RotL64(aIngress, 53U)) + 13481227414590594621U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aScatter, 60U)) + 17425964381118918026U;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 19U)) + RotL64(aCarry, 53U)) + 4792004356135956581U;
            aOrbiterE = (aWandererF + RotL64(aCross, 39U)) + 11926849936000639098U;
            aOrbiterA = (((aWandererB + RotL64(aIngress, 35U)) + RotL64(aCarry, 43U)) + 990697329347742142U) + aPhaseBOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aCross, 3U)) + 9307721505373076588U;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 12U)) + RotL64(aCarry, 35U)) + 17605732738841908719U;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 43U)) + 13110764518634187439U;
            aOrbiterF = (aWandererG + RotL64(aScatter, 27U)) + 17970109897810645911U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 10273133817644703654U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 11239046688920468137U;
            aOrbiterD = RotL64((aOrbiterD * 5197802934333553327U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 8355821483275763145U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 15522151127786049345U;
            aOrbiterB = RotL64((aOrbiterB * 4844278537850520413U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 5381663179722418112U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 9551368011768104906U;
            aOrbiterH = RotL64((aOrbiterH * 14202470972121732997U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 16264476585232221270U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 7721417776432288282U;
            aOrbiterI = RotL64((aOrbiterI * 10267770327791051869U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 339418090653475277U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 3247926250495935511U;
            aOrbiterA = RotL64((aOrbiterA * 16824669543765729097U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 3390560045236418590U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 3894024951542543635U;
            aOrbiterC = RotL64((aOrbiterC * 10599637790900418767U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 3878539166189668154U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 5617705593218220843U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 82771190372750823U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 12320861089148474544U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 14943790251625519550U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13758322022902008313U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 18119213517612562775U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 1413193144229486646U;
            aOrbiterF = RotL64((aOrbiterF * 14562375280658115687U), 39U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterD, 13U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 48U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 23U));
            aIngress = aIngress + RotL64(aOrbiterJ, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterF, 29U)) + aOrbiterH);
            aWandererD = aWandererD + (((RotL64(aScatter, 41U) + aOrbiterB) + RotL64(aOrbiterE, 12U)) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 24U) + RotL64(aOrbiterA, 57U)) + aOrbiterE) + aPhaseBWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 43U)) + aOrbiterB);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 35U) + aOrbiterJ) + RotL64(aOrbiterC, 39U));
            aWandererB = aWandererB + ((RotL64(aCross, 47U) + RotL64(aOrbiterB, 47U)) + aOrbiterD);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 10U) + RotL64(aOrbiterE, 24U)) + aOrbiterH) + aPhaseBWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 19U) + RotL64(aOrbiterJ, 53U)) + aOrbiterE) + RotL64(aCarry, 51U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterE, 5U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (RotL64(aWandererA, 30U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + RotL64(aWandererD, 51U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 18538U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadA[((aIndex + 18896U)) & W_KEY1], 41U));
            aIngress ^= (RotL64(mSource[((aIndex + 18407U)) & S_BLOCK1], 30U) ^ RotL64(aFireLaneA[((aIndex + 16677U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 17605U)) & W_KEY1], 43U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 17021U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 17892U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 6U) + RotL64(aPrevious, 53U)) + (RotL64(aCross, 23U) ^ RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 60U)) + RotL64(aCarry, 29U)) + 9751314027302668907U;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 5U)) + RotL64(aCarry, 47U)) + 12175450995523107056U;
            aOrbiterF = (aWandererF + RotL64(aIngress, 23U)) + 17519694958730119552U;
            aOrbiterJ = (aWandererE + RotL64(aCross, 35U)) + 9093525527925682263U;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 53U)) + 3713831321786810138U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aIngress, 28U)) + 10108355209191835040U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aCross, 11U)) + 12956307447311314768U;
            aOrbiterE = (aWandererH + RotL64(aScatter, 43U)) + 1904298513945877359U;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 39U)) + RotL64(aCarry, 11U)) + 4658049993308574460U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 9826333658248851902U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 12058666914724365134U;
            aOrbiterF = RotL64((aOrbiterF * 964233873188373939U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 2516574707110528099U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 13335308331049750235U;
            aOrbiterI = RotL64((aOrbiterI * 5880227828760598587U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 8230749255538495304U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 16536559486797811486U;
            aOrbiterA = RotL64((aOrbiterA * 7097036838156464969U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 12387639130570188998U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 8459259798142872020U;
            aOrbiterJ = RotL64((aOrbiterJ * 8001346480955847013U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 16083784052002800300U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 1957284290736468379U;
            aOrbiterG = RotL64((aOrbiterG * 5046501301740813065U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 7349538179311335863U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 16395170077006105258U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4230485452156662763U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 3317652065873784068U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 5517155804799120700U;
            aOrbiterK = RotL64((aOrbiterK * 9789270651974719183U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 5568525912112200094U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 9334250662962319598U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5034887614541768961U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 5641394627075994165U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 13524971148931512745U;
            aOrbiterD = RotL64((aOrbiterD * 3699457147759854357U), 47U);
            //
            aIngress = RotL64(aOrbiterF, 13U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterI, 53U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 23U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + RotL64(aOrbiterD, 48U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aIngress, 20U) + RotL64(aOrbiterF, 29U)) + aOrbiterG) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 5U)) + aOrbiterF) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterI, 10U)) + aPhaseCWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 11U) + RotL64(aOrbiterA, 39U)) + aOrbiterG);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 51U) + aOrbiterJ) + RotL64(aOrbiterF, 51U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterH, 35U)) + aOrbiterE) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 39U) + aOrbiterK) + RotL64(aOrbiterG, 43U));
            aWandererE = aWandererE + ((RotL64(aScatter, 30U) + RotL64(aOrbiterH, 47U)) + aOrbiterD);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterI, 56U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererI, 40U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererC, 37U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 20355U)) & S_BLOCK1], 19U) ^ RotL64(mSource[((aIndex + 20411U)) & S_BLOCK1], 39U));
            aIngress ^= (RotL64(aWorkLaneA[((aIndex + 21590U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneA[((aIndex + 20193U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 21239U)) & W_KEY1], 21U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 19886U)) & W_KEY1], 47U));
            aCross ^= (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20182U)) & S_BLOCK1], 38U) ^ RotL64(aFireLaneB[((aIndex + 19700U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 36U)) ^ (RotL64(aIngress, 57U) ^ RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = ((aWandererD + RotL64(aCross, 53U)) + 12136097566601676613U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 57U)) + RotL64(aCarry, 53U)) + 7969431322248040056U;
            aOrbiterB = (aWandererK + RotL64(aPrevious, 24U)) + 10530676021510553889U;
            aOrbiterG = (aWandererA + RotL64(aScatter, 47U)) + 8740777303075445264U;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 41U)) + RotL64(aCarry, 29U)) + 13249434169895564739U;
            aOrbiterF = (aWandererB + RotL64(aIngress, 3U)) + 15529577005925628472U;
            aOrbiterK = ((aWandererE + RotL64(aScatter, 11U)) + RotL64(aCarry, 37U)) + 344627093687331562U;
            aOrbiterD = (aWandererG + RotL64(aCross, 34U)) + 8824277416519988893U;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 19U)) + 5636276438449709875U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 2079413361031851552U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 7807998179168655561U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 961456853699784753U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 13589392896232029112U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 10733011474804473996U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 361749145931578805U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 15934162328347805968U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 7573511217796245232U;
            aOrbiterK = RotL64((aOrbiterK * 10694563909931636155U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 4828475187337891975U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 13284974329890393113U;
            aOrbiterG = RotL64((aOrbiterG * 10831075817642374287U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 13173869918669643112U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 15841507674783398167U;
            aOrbiterD = RotL64((aOrbiterD * 15632933198136963277U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 14168272451055700516U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 11134471485501999898U;
            aOrbiterA = RotL64((aOrbiterA * 8019507184494591705U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 2611858916687822610U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 17863271539727513641U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4987884722174985677U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 8874401993454249066U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 5131480593493950665U;
            aOrbiterI = RotL64((aOrbiterI * 8585874663602346121U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 9366563022381918996U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 7890729519928340296U;
            aOrbiterC = RotL64((aOrbiterC * 11428572374057899517U), 39U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 47U);
            aIngress = aIngress + (RotL64(aOrbiterA, 23U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + (RotL64(aOrbiterI, 10U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterK, 37U));
            aWandererI = aWandererI + (((RotL64(aCross, 19U) + RotL64(aOrbiterK, 51U)) + aOrbiterD) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterD, 26U)) + aOrbiterF);
            aWandererG = aWandererG + (((RotL64(aPrevious, 53U) + aOrbiterK) + RotL64(aOrbiterF, 47U)) + aPhaseCWandererUpdateSaltB[((aIndex + 4U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 12U) + RotL64(aOrbiterB, 43U)) + aOrbiterA) + aPhaseCWandererUpdateSaltC[((aIndex + 14U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterJ, 57U)) + aOrbiterI) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterA, 11U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 3U)) + aOrbiterC);
            aWandererE = aWandererE ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterJ, 22U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererF, 14U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 23688U)) & S_BLOCK1], 35U) ^ RotL64(aKeyRowReadA[((aIndex + 22804U)) & W_KEY1], 43U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 24287U)) & W_KEY1], 12U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 23709U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 24046U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24107U)) & S_BLOCK1], 44U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 24125U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneD[((aIndex + 21945U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aIngress, 39U)) ^ (RotL64(aCross, 6U) + RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 3U)) + RotL64(aCarry, 3U)) + 13714409587461539863U;
            aOrbiterK = (aWandererB + RotL64(aIngress, 57U)) + 14101156723903265839U;
            aOrbiterH = (((aWandererF + RotL64(aCross, 23U)) + RotL64(aCarry, 29U)) + 7063754562895369001U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aScatter, 34U)) + 12320578575245519386U) + aPhaseCOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aIngress, 51U)) + 11744826789631008424U;
            aOrbiterJ = (aWandererD + RotL64(aCross, 13U)) + 8744816505096675597U;
            aOrbiterD = (aWandererI + RotL64(aPrevious, 47U)) + 10405435520084528645U;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 27U)) + RotL64(aCarry, 21U)) + 1463157688070683543U;
            aOrbiterG = (aWandererA + RotL64(aPrevious, 18U)) + 12379603577919617703U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 1343439118031348146U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 16118850268070235540U;
            aOrbiterH = RotL64((aOrbiterH * 11184386483735388257U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 14116264435819277136U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 5251698273012432109U;
            aOrbiterF = RotL64((aOrbiterF * 1495818611622063967U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 14806408656041403829U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 11569345414052398227U;
            aOrbiterE = RotL64((aOrbiterE * 9913158908301414861U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 17063874769147888574U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 9927420478679581917U;
            aOrbiterJ = RotL64((aOrbiterJ * 9042782809534196563U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 2550285599827162167U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 17801534123304996448U;
            aOrbiterK = RotL64((aOrbiterK * 2160836889363614721U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 6456685241021762041U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 17064208177372969289U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13726627607233302493U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 18279938244131982650U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 8211002229712129419U;
            aOrbiterD = RotL64((aOrbiterD * 12931373380977640645U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 12795832560781931767U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 286378504074349650U;
            aOrbiterI = RotL64((aOrbiterI * 85453101173293509U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 5835304250436889513U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 12704972686724379659U;
            aOrbiterG = RotL64((aOrbiterG * 1198789639656336053U), 23U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterG, 13U);
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 53U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 18U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 53U) + aOrbiterD) + RotL64(aOrbiterH, 39U));
            aWandererD = aWandererD + (((RotL64(aScatter, 34U) + RotL64(aOrbiterI, 58U)) + aOrbiterK) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 35U)) + aOrbiterH);
            aWandererK = aWandererK + (((RotL64(aCross, 19U) + RotL64(aOrbiterD, 21U)) + aOrbiterJ) + RotL64(aCarry, 41U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterE, 29U)) + aOrbiterF);
            aWandererH = aWandererH + (((RotL64(aCross, 58U) + RotL64(aOrbiterK, 53U)) + aOrbiterG) + aPhaseCWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 11U)) + aOrbiterA);
            aWandererA = aWandererA + (((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterF, 47U)) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 43U) + aOrbiterI) + RotL64(aOrbiterG, 6U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 42U));
            aCarry = aCarry + RotL64(aWandererD, 23U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 25557U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadA[((aIndex + 25958U)) & W_KEY1], 29U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 26351U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneB[((aIndex + 27163U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 26849U)) & W_KEY1], 19U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26557U)) & S_BLOCK1], 52U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 26926U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 26353U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 3U)) ^ (RotL64(aIngress, 19U) + RotL64(aCross, 54U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = (aWandererC + RotL64(aCross, 10U)) + 5480870806135400132U;
            aOrbiterA = (aWandererB + RotL64(aScatter, 19U)) + 8034874599430768743U;
            aOrbiterD = (((aWandererI + RotL64(aIngress, 35U)) + RotL64(aCarry, 57U)) + 4006919843736863767U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aPrevious, 23U)) + 2988069748674633718U;
            aOrbiterJ = ((aWandererK + RotL64(aCross, 57U)) + 12347295651973135786U) + aPhaseDOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 53U)) + RotL64(aCarry, 43U)) + 14152683894431568192U;
            aOrbiterF = (aWandererD + RotL64(aScatter, 5U)) + 15765143815254196598U;
            aOrbiterB = (aWandererJ + RotL64(aIngress, 41U)) + 10473067082331244233U;
            aOrbiterH = ((aWandererA + RotL64(aCross, 14U)) + RotL64(aCarry, 23U)) + 1089466925383677249U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 13215039929873682230U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 3957997712247961479U;
            aOrbiterD = RotL64((aOrbiterD * 7631186240013784703U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 10023907397941685546U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 14593012591254614353U;
            aOrbiterK = RotL64((aOrbiterK * 17111300092082154687U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 13353797968154036726U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 9259966668512102858U;
            aOrbiterC = RotL64((aOrbiterC * 8326732574268308221U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 10757861831070349321U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 10530223113483866178U;
            aOrbiterJ = RotL64((aOrbiterJ * 11269177745265396583U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 7554320926405521865U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 6978052067277966996U;
            aOrbiterA = RotL64((aOrbiterA * 18020134738536217801U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 1053695861967171420U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 15980734683539854451U;
            aOrbiterF = RotL64((aOrbiterF * 3208466640010555357U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 17041258393808061556U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 12846551858751995530U;
            aOrbiterE = RotL64((aOrbiterE * 9303891433380993639U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 14617434286683320666U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 3999309956180741302U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15037707937050015205U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 13452627760403094126U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 2633241575260427158U;
            aOrbiterH = RotL64((aOrbiterH * 2638570213290747581U), 29U);
            //
            aIngress = RotL64(aOrbiterA, 19U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterE, 34U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterK, 6U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 11U) + aOrbiterJ) + RotL64(aOrbiterA, 51U)) + aPhaseDWandererUpdateSaltB[((aIndex + 14U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 3U) + RotL64(aOrbiterD, 47U)) + aOrbiterK);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterA, 11U)) + aOrbiterE) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 58U) + aOrbiterB) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 19U)) + aOrbiterD);
            aWandererC = aWandererC + (((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterF, 41U)) + aOrbiterB);
            aWandererK = aWandererK + ((RotL64(aPrevious, 54U) + RotL64(aOrbiterJ, 30U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 42U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 28245U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneD[((aIndex + 27955U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 27649U)) & W_KEY1], 53U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 27475U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 28803U)) & W_KEY1], 28U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29225U)) & S_BLOCK1], 53U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28906U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((aIndex + 28722U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCarry, 3U)) ^ (RotL64(aPrevious, 51U) + RotL64(aCross, 36U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 5U)) + RotL64(aCarry, 47U)) + 2177539223979303669U;
            aOrbiterJ = ((aWandererE + RotL64(aCross, 58U)) + RotL64(aCarry, 37U)) + 3962004686551521471U;
            aOrbiterD = (aWandererC + RotL64(aScatter, 11U)) + 8457602312617147662U;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 47U)) + RotL64(aCarry, 23U)) + 18011802451816510632U;
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 39U)) + 9046101759168876832U;
            aOrbiterF = ((aWandererF + RotL64(aCross, 23U)) + 11135620637431969597U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aScatter, 54U)) + 15913029940697999701U;
            aOrbiterH = ((aWandererH + RotL64(aIngress, 27U)) + 16304193109948135982U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (aWandererA + RotL64(aPrevious, 43U)) + 13208892298820080981U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 4182377898949419225U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 13970137023071326151U;
            aOrbiterD = RotL64((aOrbiterD * 9075061559681739865U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 8402396284835248583U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 8859190834060657829U;
            aOrbiterA = RotL64((aOrbiterA * 13552418608113716117U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 9760005337757990392U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 14108277760135744897U;
            aOrbiterJ = RotL64((aOrbiterJ * 4474681104256093885U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 12226316121949012350U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 3456392186754113960U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8704729827929941215U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 5004087958637038973U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 7176881295123125567U;
            aOrbiterC = RotL64((aOrbiterC * 15272157962928021009U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 10889800478505074438U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 13728832441482547824U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17588477761978646139U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 17345665880706866772U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 301139993853297566U;
            aOrbiterF = RotL64((aOrbiterF * 5812445396758354505U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 2061389844760610160U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 13631862266139238355U;
            aOrbiterG = RotL64((aOrbiterG * 143613352104722701U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 10767186080827509622U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 4893486019456886013U;
            aOrbiterH = RotL64((aOrbiterH * 5194746459545610901U), 43U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterA, 23U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 11U));
            aIngress = aIngress + (RotL64(aOrbiterC, 50U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 60U) + aOrbiterA) + RotL64(aOrbiterJ, 39U)) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterC, 34U)) + aOrbiterF);
            aWandererF = aWandererF + ((RotL64(aPrevious, 23U) + aOrbiterC) + RotL64(aOrbiterE, 11U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 51U) + aOrbiterB) + RotL64(aOrbiterC, 47U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterH, 51U)) + aOrbiterE) + RotL64(aCarry, 51U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 41U) + aOrbiterA) + RotL64(aOrbiterH, 4U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 47U) + aOrbiterG) + RotL64(aOrbiterJ, 29U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterH, 57U)) + aOrbiterC);
            aWandererA = aWandererA + ((RotL64(aCross, 18U) + RotL64(aOrbiterD, 21U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererK, 22U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + RotL64(aWandererA, 11U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 31404U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 32131U)) & W_KEY1], 52U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 32047U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32424U)) & S_BLOCK1], 27U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31837U)) & S_BLOCK1], 5U) ^ RotL64(aKeyRowReadB[((aIndex + 31590U)) & W_KEY1], 56U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 38U) ^ RotL64(aIngress, 3U)) + (RotL64(aCross, 21U) + RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = (aWandererI + RotL64(aScatter, 6U)) + 9133751643283278896U;
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 53U)) + 8971581804375380408U;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 57U)) + RotL64(aCarry, 21U)) + 12559650383714566592U;
            aOrbiterE = ((aWandererB + RotL64(aCross, 47U)) + RotL64(aCarry, 51U)) + 15753206088872859163U;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 23U)) + 7640756270450762350U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aScatter, 11U)) + RotL64(aCarry, 35U)) + 7340073357551376125U;
            aOrbiterH = ((aWandererG + RotL64(aCross, 43U)) + 5270256573644196046U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aIngress, 19U)) + 3567367996479995928U;
            aOrbiterG = (aWandererE + RotL64(aCross, 36U)) + 11939634537492733738U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 7051817732424527120U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 1730487669951837941U;
            aOrbiterC = RotL64((aOrbiterC * 15191634337956285841U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 18009252467909454817U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 2361024272031696442U;
            aOrbiterD = RotL64((aOrbiterD * 15215151562500226027U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 15902755877642960397U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 12243517544704116184U;
            aOrbiterI = RotL64((aOrbiterI * 2576071074148141447U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 16846181962302186187U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 636121425116506681U;
            aOrbiterH = RotL64((aOrbiterH * 17075030673338779993U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 6887385655828217318U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 3705834550934775862U;
            aOrbiterB = RotL64((aOrbiterB * 11275428284929594435U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 11165142437077969438U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 6426659930331618269U;
            aOrbiterG = RotL64((aOrbiterG * 17170640810530893705U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 12629082390899315789U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 4277510580069574724U;
            aOrbiterA = RotL64((aOrbiterA * 9829125163412708305U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 13814834144170469978U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 3698381854100295826U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5126359230872258015U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 11623170635983579937U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 7247413650388803796U;
            aOrbiterJ = RotL64((aOrbiterJ * 3403219499465560059U), 57U);
            //
            aIngress = RotL64(aOrbiterE, 6U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 39U));
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aIngress, 58U) + aOrbiterE) + RotL64(aOrbiterH, 3U)) + aPhaseDWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterE, 35U)) + RotL64(aCarry, 27U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterJ, 43U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 13U) + aOrbiterG) + RotL64(aOrbiterJ, 12U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterD, 39U)) + aOrbiterC);
            aWandererK = aWandererK + ((RotL64(aPrevious, 47U) + aOrbiterA) + RotL64(aOrbiterC, 57U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterB, 23U));
            aWandererH = aWandererH + (((RotL64(aScatter, 6U) + RotL64(aOrbiterA, 53U)) + aOrbiterG) + RotL64(aCarry, 35U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 23U) + aOrbiterC) + RotL64(aOrbiterI, 18U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (RotL64(aWandererK, 44U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 57U);
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

void TwistExpander_Boxing_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 6053U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((aIndex + 1439U)) & S_BLOCK1], 14U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 1995U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3229U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 1007U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 7268U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aIngress, 51U)) ^ (RotL64(aPrevious, 20U) ^ RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = (aWandererE + RotL64(aIngress, 35U)) + 18087125778766689269U;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 44U)) + RotL64(aCarry, 13U)) + 13710545066503235196U;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 57U)) + 1701939704736254645U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aCross, 19U)) + RotL64(aCarry, 51U)) + 8064093611384019909U;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 11U)) + RotL64(aCarry, 27U)) + 16623332751533885431U;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 51U)) + 15590129153794910109U;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 29U)) + 7413312683079107383U) + aPhaseEOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 4186064478651458810U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 5501191643940735954U;
            aOrbiterA = RotL64((aOrbiterA * 14254804649177125269U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 11064645242200570835U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 13825922087298055833U;
            aOrbiterF = RotL64((aOrbiterF * 7529317892716108867U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 5944980709887369970U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 8181136916070569646U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 395183021205661827U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 15442336949157292482U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 11580554435240641337U;
            aOrbiterC = RotL64((aOrbiterC * 6654637892858767739U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 11240018128174598322U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 2027565596050777471U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 18048186560314431815U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 16425887196883725233U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 16828683527588834095U;
            aOrbiterE = RotL64((aOrbiterE * 17746289103235902485U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 9923829146479008804U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 6669171007279929454U;
            aOrbiterK = RotL64((aOrbiterK * 681823450939955099U), 19U);
            //
            aIngress = RotL64(aOrbiterF, 14U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 47U)) + aOrbiterC);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 37U)) + aOrbiterH);
            aWandererG = aWandererG + ((RotL64(aScatter, 56U) + aOrbiterK) + RotL64(aOrbiterH, 5U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterF, 29U)) + aOrbiterE) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 11U) + aOrbiterA) + RotL64(aOrbiterB, 11U)) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterK, 21U)) + aOrbiterA);
            aWandererB = aWandererB + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterC, 56U)) + aOrbiterE) + RotL64(aCarry, 37U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 28U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 14151U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((aIndex + 13093U)) & S_BLOCK1], 39U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 11480U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 11491U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9280U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10466U)) & S_BLOCK1], 58U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 10962U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aPrevious, 6U)) ^ (RotL64(aCross, 29U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = (aWandererJ + RotL64(aIngress, 27U)) + 18319689184146942855U;
            aOrbiterF = (aWandererE + RotL64(aScatter, 11U)) + 8041304130090501019U;
            aOrbiterG = ((aWandererG + RotL64(aCross, 52U)) + 11347064191990897738U) + aPhaseEOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 5U)) + RotL64(aCarry, 27U)) + 15242243470024447468U;
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 21U)) + RotL64(aCarry, 11U)) + 10619749107163611105U;
            aOrbiterE = ((aWandererF + RotL64(aCross, 37U)) + 14795614276221947128U) + aPhaseEOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = ((aWandererB + RotL64(aScatter, 43U)) + RotL64(aCarry, 39U)) + 1578095288886372393U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 13593906305770501684U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 8919815528334599172U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2033810402808238127U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 17425548324720065145U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 11125018338392347335U;
            aOrbiterF = RotL64((aOrbiterF * 4377887040461528587U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 3779189180734244399U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 10958224663276134041U;
            aOrbiterJ = RotL64((aOrbiterJ * 6206963519509783781U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 4317305352561612995U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 4891139433808505355U;
            aOrbiterE = RotL64((aOrbiterE * 11507024985663120317U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 5166074784835930965U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 10080890270621589202U;
            aOrbiterK = RotL64((aOrbiterK * 13170894418184288695U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 4501071771615514619U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 6486573807774431753U;
            aOrbiterH = RotL64((aOrbiterH * 324029625116648669U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 15714881857668975753U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 3506619392820235900U;
            aOrbiterC = RotL64((aOrbiterC * 5707033870161224499U), 51U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterC, 21U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 58U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterH, 22U)) + aOrbiterF);
            aWandererB = aWandererB + (((RotL64(aIngress, 43U) + RotL64(aOrbiterC, 57U)) + aOrbiterF) + RotL64(aCarry, 41U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterK, 5U)) + aOrbiterE);
            aWandererF = aWandererF + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 51U)) + aOrbiterC) + RotL64(aCarry, 5U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 35U) + aOrbiterF) + RotL64(aOrbiterE, 41U)) + aPhaseEWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 27U) + aOrbiterK) + RotL64(aOrbiterJ, 13U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 10U) + RotL64(aOrbiterK, 29U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererE, 4U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 16654U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneA[((aIndex + 24188U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aExpandLaneB[((aIndex + 18014U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23490U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22156U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 22490U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18478U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCarry, 54U)) + (RotL64(aPrevious, 11U) ^ RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = ((aWandererF + RotL64(aCross, 37U)) + RotL64(aCarry, 39U)) + 3621877681473089725U;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 58U)) + 4451752751536414717U) + aPhaseEOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aIngress, 11U)) + 11371625415377772117U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = (aWandererA + RotL64(aPrevious, 43U)) + 6046792758881150619U;
            aOrbiterH = (aWandererD + RotL64(aIngress, 29U)) + 8213166120394461682U;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 3U)) + RotL64(aCarry, 51U)) + 4343156661140422645U;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 23U)) + RotL64(aCarry, 21U)) + 11105271483234947905U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 348904609985341372U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 12924652822526858767U;
            aOrbiterA = RotL64((aOrbiterA * 2801892489296408735U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 7461211697358520287U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 16551553555297890558U;
            aOrbiterE = RotL64((aOrbiterE * 16432952324635746293U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 11908056404140782995U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 9147367258259948715U;
            aOrbiterJ = RotL64((aOrbiterJ * 10777628928376261667U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 8876461054692728610U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 10546855952702525404U;
            aOrbiterC = RotL64((aOrbiterC * 10071104785895309677U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 4748636139110443794U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 783046909529525098U;
            aOrbiterH = RotL64((aOrbiterH * 8969157702460927215U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 16683965945838696665U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 12385412690177109575U;
            aOrbiterB = RotL64((aOrbiterB * 10795062772707143187U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 8210546822184469023U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 13146493623236979963U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13199947810161148155U), 57U);
            //
            aIngress = RotL64(aOrbiterE, 21U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterA, 39U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aPrevious, 47U) + aOrbiterH) + RotL64(aOrbiterK, 21U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 5U)) + aOrbiterK);
            aWandererE = aWandererE + (((RotL64(aScatter, 10U) + aOrbiterC) + RotL64(aOrbiterJ, 37U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 21U) + aOrbiterB) + RotL64(aOrbiterK, 27U)) + aPhaseEWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 41U) + RotL64(aOrbiterJ, 47U)) + aOrbiterB) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 11U)) + aOrbiterA);
            aWandererJ = aWandererJ + (((RotL64(aCross, 29U) + RotL64(aOrbiterB, 60U)) + aOrbiterA) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 10U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 51U);
            aCarry = aCarry + RotL64(aIngress, 42U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 28886U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneA[((aIndex + 30839U)) & S_BLOCK1], 18U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 27463U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 28908U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31424U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25324U)) & S_BLOCK1], 22U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 27351U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 41U) + RotL64(aIngress, 29U)) ^ (RotL64(aCross, 60U) ^ RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (aWandererG + RotL64(aPrevious, 10U)) + 5131645209694953015U;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 3U)) + RotL64(aCarry, 41U)) + 12070391048835379854U;
            aOrbiterE = (((aWandererH + RotL64(aScatter, 21U)) + RotL64(aCarry, 53U)) + 2604295836242338724U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aCross, 57U)) + 14042039029284001596U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aIngress, 47U)) + 8914654543854559327U;
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 27U)) + 2185619407969359869U;
            aOrbiterA = ((aWandererK + RotL64(aCross, 35U)) + RotL64(aCarry, 11U)) + 5187406295103352574U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 8022832481290871217U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 8783061916740573472U;
            aOrbiterE = RotL64((aOrbiterE * 3309891377744201773U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 10711028365596196301U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 13387065038269133571U;
            aOrbiterF = RotL64((aOrbiterF * 12444578026365205255U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 11187001318931801582U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 14191473173276034019U;
            aOrbiterA = RotL64((aOrbiterA * 2491253922434756431U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 16207761776716426435U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 9677408414452078760U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5487303383095129949U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 17812460332794370649U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 7736423148554132028U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15588733747232852555U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 17293203944059014763U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 13487243633338010243U;
            aOrbiterB = RotL64((aOrbiterB * 9468688858740539095U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 15979293016815060755U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 17645215484691359547U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1449450767288733995U), 35U);
            //
            aIngress = RotL64(aOrbiterJ, 39U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + (RotL64(aOrbiterA, 29U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterA, 21U));
            aWandererK = aWandererK + ((((RotL64(aCross, 43U) + RotL64(aOrbiterE, 35U)) + aOrbiterJ) + RotL64(aCarry, 43U)) + aPhaseEWandererUpdateSaltB[((aIndex + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 3U)) + aOrbiterB);
            aWandererE = aWandererE + ((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 57U)) + aOrbiterE);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 53U) + aOrbiterB) + RotL64(aOrbiterC, 29U));
            aWandererB = aWandererB + (((RotL64(aIngress, 12U) + aOrbiterF) + RotL64(aOrbiterJ, 44U)) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterH, 51U)) + aOrbiterA) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (RotL64(aWandererK, 14U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererB, 27U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_Boxing_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 146U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((aIndex + 7574U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 5258U)) & S_BLOCK1], 28U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4176U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 7542U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 3434U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 14U) + RotL64(aCross, 29U)) + (RotL64(aCarry, 43U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (aWandererA + RotL64(aIngress, 29U)) + 13350544654542863236U;
            aOrbiterD = (aWandererI + RotL64(aScatter, 18U)) + 12364346790125404372U;
            aOrbiterA = ((aWandererE + RotL64(aCross, 11U)) + RotL64(aCarry, 47U)) + 9738750172849512764U;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 53U)) + RotL64(aCarry, 51U)) + 3781373837635491421U;
            aOrbiterG = (aWandererD + RotL64(aCross, 41U)) + 16635020317512702337U;
            aOrbiterC = (((aWandererH + RotL64(aScatter, 5U)) + RotL64(aCarry, 19U)) + 5383653921676231276U) + aPhaseFOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (aWandererF + RotL64(aPrevious, 44U)) + 10181959815492056493U;
            aOrbiterB = (aWandererB + RotL64(aIngress, 47U)) + 10005510924273927017U;
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 51U)) + 9524687662265740565U) + aPhaseFOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aIngress, 39U)) + 4259138552009771014U;
            aOrbiterH = (aWandererJ + RotL64(aCross, 13U)) + 8973051213213726023U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 17602611840127337490U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 8218984546932905269U;
            aOrbiterA = RotL64((aOrbiterA * 17504305273683304231U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 18102186122213487888U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 2629927500298092976U;
            aOrbiterD = RotL64((aOrbiterD * 6983280164448292723U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 2491581597835795234U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 9506602492971620955U;
            aOrbiterE = RotL64((aOrbiterE * 9559829640915637163U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 13422942713680612924U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 15037354693234876601U;
            aOrbiterI = RotL64((aOrbiterI * 12692376075738621447U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 12896066842192894694U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 2202952306291905855U;
            aOrbiterF = RotL64((aOrbiterF * 6779368532763429997U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 12160313482450599313U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 10812986281270407756U;
            aOrbiterK = RotL64((aOrbiterK * 7786608700746771809U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 12474638293190144525U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 5882870951276225224U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15532427302173572457U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 3782896138051179209U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 10965680631059882311U;
            aOrbiterH = RotL64((aOrbiterH * 14060923998307082385U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 15650420683333746952U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 4110674660963676864U;
            aOrbiterJ = RotL64((aOrbiterJ * 11724979274890265275U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 694817156953099464U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 4402927404825116007U;
            aOrbiterG = RotL64((aOrbiterG * 579586789292520113U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 6849178151532923489U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 13350544654542863236U;
            aOrbiterC = RotL64((aOrbiterC * 2416097748778941523U), 51U);
            //
            aIngress = RotL64(aOrbiterF, 22U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 51U));
            aIngress = aIngress + (RotL64(aOrbiterK, 53U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 13U) + RotL64(aOrbiterI, 57U)) + aOrbiterK) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterA, 41U)) + aOrbiterB);
            aWandererE = aWandererE + (((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 47U)) + aOrbiterD) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 39U) + aOrbiterC) + RotL64(aOrbiterD, 3U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterK, 19U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 46U) + RotL64(aOrbiterG, 35U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 53U) + aOrbiterD) + RotL64(aOrbiterI, 50U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 43U) + aOrbiterH) + RotL64(aOrbiterC, 39U));
            aWandererC = aWandererC + ((RotL64(aCross, 37U) + aOrbiterE) + RotL64(aOrbiterG, 13U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 51U) + aOrbiterJ) + RotL64(aOrbiterB, 23U));
            aWandererH = aWandererH + ((RotL64(aIngress, 60U) + RotL64(aOrbiterF, 10U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 34U));
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 21U));
            aCarry = aCarry + (RotL64(aWandererG, 30U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 10546U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneC[((aIndex + 8979U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 15824U)) & S_BLOCK1], 43U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 11889U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 11615U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 11332U)) & S_BLOCK1], 10U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 15838U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCarry, 4U)) ^ (RotL64(aCross, 35U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = (aWandererF + RotL64(aIngress, 5U)) + 4970414922752555648U;
            aOrbiterF = (aWandererD + RotL64(aPrevious, 43U)) + 9462756592787669327U;
            aOrbiterK = (aWandererH + RotL64(aCross, 21U)) + 3948790686662213095U;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 36U)) + RotL64(aCarry, 53U)) + 14542857212241578311U;
            aOrbiterA = (aWandererK + RotL64(aCross, 53U)) + 3387479009827029547U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 47U)) + RotL64(aCarry, 41U)) + 1411421370057797877U;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 41U)) + 16894451466895681236U;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 60U)) + 12727136462290223542U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aPrevious, 13U)) + 4625389198191960525U;
            aOrbiterI = ((aWandererE + RotL64(aCross, 29U)) + RotL64(aCarry, 27U)) + 3471881403786164913U;
            aOrbiterH = ((aWandererI + RotL64(aIngress, 39U)) + 6433115856048534831U) + aPhaseFOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 9825592965466157982U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 1553125767261293088U;
            aOrbiterK = RotL64((aOrbiterK * 411535191177308781U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 9951616357109647617U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 11231080382787286889U;
            aOrbiterG = RotL64((aOrbiterG * 14024961994986659187U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 13419663264017317947U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 4835055642466215566U;
            aOrbiterE = RotL64((aOrbiterE * 17898065852351759171U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 14558747666410946768U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 13120938960926874504U;
            aOrbiterI = RotL64((aOrbiterI * 5681766019285559739U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 11910501376797343986U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 15074100100781785300U;
            aOrbiterA = RotL64((aOrbiterA * 228976960937473851U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 12415377930578091821U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 14882039078390681802U;
            aOrbiterB = RotL64((aOrbiterB * 13855446647753150713U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 8094338361713756895U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 5478280604704108822U;
            aOrbiterF = RotL64((aOrbiterF * 18062931724700600993U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 6977017654546871841U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 4131602217285988962U;
            aOrbiterC = RotL64((aOrbiterC * 11865422227883712419U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 9619228479582032318U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 13506679497441415586U;
            aOrbiterD = RotL64((aOrbiterD * 5789932662418992799U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 10180259475831448124U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 4721628773773094283U;
            aOrbiterJ = RotL64((aOrbiterJ * 10834196399754443771U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 7898137727558813688U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 4970414922752555648U;
            aOrbiterH = RotL64((aOrbiterH * 6651835668618579479U), 3U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterD, 19U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 14U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 27U));
            aIngress = aIngress + (RotL64(aOrbiterE, 51U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 41U) + aOrbiterI) + RotL64(aOrbiterD, 47U)) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterF, 21U));
            aWandererE = aWandererE + ((RotL64(aIngress, 5U) + aOrbiterA) + RotL64(aOrbiterE, 29U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 60U) + aOrbiterG) + RotL64(aOrbiterB, 56U));
            aWandererD = aWandererD + (((RotL64(aScatter, 43U) + aOrbiterC) + RotL64(aOrbiterG, 39U)) + aPhaseFWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 39U) + aOrbiterG) + RotL64(aOrbiterF, 19U));
            aWandererF = aWandererF + (((RotL64(aIngress, 21U) + RotL64(aOrbiterA, 51U)) + aOrbiterH) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterI, 27U)) + aOrbiterK);
            aWandererG = aWandererG + (((RotL64(aScatter, 47U) + RotL64(aOrbiterA, 13U)) + aOrbiterD) + RotL64(aCarry, 41U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 56U) + aOrbiterH) + RotL64(aOrbiterD, 11U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 44U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 24U));
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 60U));
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 21316U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((aIndex + 24373U)) & S_BLOCK1], 50U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 23305U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 22685U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18571U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 16781U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 22320U)) & S_BLOCK1], 42U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 56U) ^ RotL64(aIngress, 5U)) + (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = (aWandererI + RotL64(aPrevious, 23U)) + 13854738573712660276U;
            aOrbiterJ = (aWandererC + RotL64(aScatter, 10U)) + 16835460633412286294U;
            aOrbiterG = (aWandererH + RotL64(aIngress, 51U)) + 6785859293758091931U;
            aOrbiterF = (aWandererG + RotL64(aCross, 39U)) + 126317283127992659U;
            aOrbiterE = (aWandererB + RotL64(aScatter, 41U)) + 7568963536291415413U;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 27U)) + RotL64(aCarry, 37U)) + 12294016745653004819U;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 13U)) + RotL64(aCarry, 27U)) + 18269588932920281147U;
            aOrbiterK = ((aWandererA + RotL64(aCross, 5U)) + 5872406424994751026U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aScatter, 21U)) + 7764434758831474129U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = (aWandererJ + RotL64(aIngress, 29U)) + 4804168969415573371U;
            aOrbiterH = ((aWandererF + RotL64(aCross, 56U)) + RotL64(aCarry, 21U)) + 959601763507651280U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 9257644462479293048U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 14332699366894494579U;
            aOrbiterG = RotL64((aOrbiterG * 8829304078930625541U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 10487012596470786004U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 612729229562321440U;
            aOrbiterJ = RotL64((aOrbiterJ * 11380387280507726003U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 7845523921295625315U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 12742115479740024747U;
            aOrbiterI = RotL64((aOrbiterI * 15578543510683986421U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 10294667720904610944U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 14369711143154904567U;
            aOrbiterC = RotL64((aOrbiterC * 13753005602288309379U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 10918344717497681894U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 18136794828308636957U;
            aOrbiterE = RotL64((aOrbiterE * 17899418637978002409U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 14378638206724886404U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 7077588188450008059U;
            aOrbiterK = RotL64((aOrbiterK * 485375960462924335U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 8941870012851971932U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 15242087859620352399U;
            aOrbiterA = RotL64((aOrbiterA * 4963002810455992839U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 10395280254030875387U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 6826595516076975980U;
            aOrbiterH = RotL64((aOrbiterH * 6198886240333178001U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 10407910809564430664U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 6368255889263255730U;
            aOrbiterB = RotL64((aOrbiterB * 3809496492809859731U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 6365669830464231626U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 596785214258266904U;
            aOrbiterF = RotL64((aOrbiterF * 6338109335634389561U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 4807438574488830717U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 13854738573712660276U;
            aOrbiterD = RotL64((aOrbiterD * 6954368463489446551U), 19U);
            //
            aIngress = RotL64(aOrbiterB, 37U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterJ, 54U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + RotL64(aOrbiterG, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterJ, 5U)) + aOrbiterI);
            aWandererD = aWandererD + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 38U)) + aOrbiterE) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterH, 47U)) + aOrbiterF);
            aWandererG = aWandererG + ((RotL64(aCross, 30U) + RotL64(aOrbiterJ, 13U)) + aOrbiterD);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterA, 11U)) + aOrbiterB) + aPhaseFWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aScatter, 13U) + aOrbiterG) + RotL64(aOrbiterI, 41U)) + RotL64(aCarry, 29U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 18U)) + aOrbiterF);
            aWandererC = aWandererC + ((RotL64(aCross, 5U) + RotL64(aOrbiterC, 53U)) + aOrbiterE);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 50U) + aOrbiterK) + RotL64(aOrbiterI, 27U));
            aWandererH = aWandererH + ((RotL64(aCross, 19U) + RotL64(aOrbiterK, 23U)) + aOrbiterH);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterG, 35U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 6U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + RotL64(aWandererG, 51U);
            aCarry = aCarry + RotL64(aIngress, 58U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 32254U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneA[((aIndex + 27308U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 30975U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneC[((aIndex + 30215U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25416U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 25996U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 27703U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 54U) ^ RotL64(aCross, 27U)) + (RotL64(aCarry, 13U) + RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = ((aWandererD + RotL64(aCross, 29U)) + RotL64(aCarry, 41U)) + 13296600294247799698U;
            aOrbiterE = (aWandererB + RotL64(aIngress, 57U)) + 5818503518080877515U;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 27U)) + 6735784238734173597U;
            aOrbiterB = (aWandererF + RotL64(aScatter, 44U)) + 7368398209488856201U;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 51U)) + RotL64(aCarry, 29U)) + 961734029066455638U;
            aOrbiterJ = (aWandererG + RotL64(aCross, 13U)) + 797011946660892011U;
            aOrbiterF = (aWandererH + RotL64(aScatter, 53U)) + 12841876018396622350U;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 41U)) + 16213253970483895623U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = (aWandererI + RotL64(aCross, 5U)) + 15186950557113470375U;
            aOrbiterG = (aWandererJ + RotL64(aIngress, 38U)) + 5117930310827477341U;
            aOrbiterH = (((aWandererA + RotL64(aScatter, 21U)) + RotL64(aCarry, 47U)) + 12265429373166094162U) + aPhaseFOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 13920531346698601568U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 14695405206998211456U;
            aOrbiterD = RotL64((aOrbiterD * 13950964363414164279U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 7851960904825938443U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 9501511171732550190U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5614164120361489613U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 5663365182245722077U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 9607860124321315555U;
            aOrbiterJ = RotL64((aOrbiterJ * 3461820361914280601U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 18171052650586819280U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 3442698321538580861U;
            aOrbiterB = RotL64((aOrbiterB * 6317525514963824829U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 1491052813469258970U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 3956599824067616133U;
            aOrbiterK = RotL64((aOrbiterK * 2928600779267623085U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 10963841237346073453U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 2303020125591252534U;
            aOrbiterE = RotL64((aOrbiterE * 9969099842343321981U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 14503856057958162356U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 11147548150090597694U;
            aOrbiterI = RotL64((aOrbiterI * 11856382308792700441U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 9191681438318311481U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 13556072770381999852U;
            aOrbiterH = RotL64((aOrbiterH * 18316231099054203683U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 10103207278550444685U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 10415809965217261104U;
            aOrbiterG = RotL64((aOrbiterG * 16562732599511350217U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 17435033201864058457U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 5540494424887364682U;
            aOrbiterC = RotL64((aOrbiterC * 18230910315317249045U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 18020151683897013854U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 13296600294247799698U;
            aOrbiterF = RotL64((aOrbiterF * 10000194329456668845U), 53U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 58U);
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + (RotL64(aOrbiterH, 21U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + RotL64(aOrbiterJ, 30U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 39U) + RotL64(aOrbiterH, 44U)) + aOrbiterC) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 41U) + aOrbiterB) + RotL64(aOrbiterC, 21U));
            aWandererD = aWandererD + (((RotL64(aIngress, 4U) + aOrbiterG) + RotL64(aOrbiterE, 11U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterI, 57U)) + aOrbiterD);
            aWandererB = aWandererB + ((RotL64(aPrevious, 47U) + aOrbiterI) + RotL64(aOrbiterC, 3U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterF, 19U)) + aOrbiterG) + aPhaseFWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 43U) + aOrbiterC) + RotL64(aOrbiterA, 46U)) + RotL64(aCarry, 35U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 29U) + aOrbiterF) + RotL64(aOrbiterJ, 53U));
            aWandererK = aWandererK + ((RotL64(aCross, 56U) + aOrbiterD) + RotL64(aOrbiterB, 41U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterK, 35U)) + aOrbiterD);
            aWandererH = aWandererH + ((RotL64(aScatter, 21U) + aOrbiterK) + RotL64(aOrbiterF, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 48U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + RotL64(aWandererK, 60U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

void TwistExpander_Boxing_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 1559U)) & S_BLOCK1], 20U) ^ RotL64(aWorkLaneB[((aIndex + 2565U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 74U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 594U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 3948U)) & S_BLOCK1], 46U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 1589U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 52U)) + (RotL64(aIngress, 3U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 11U)) + RotL64(aCarry, 21U)) + 12849591986267890852U;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 21U)) + 8232614804696815750U;
            aOrbiterD = (((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 43U)) + 12141567259210877281U) + aPhaseGOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aScatter, 58U)) + RotL64(aCarry, 3U)) + 2928641981037885644U;
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 29U)) + 980733350554783938U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 2683985177993350746U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 14532148403815527355U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15985362037094864225U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 7736296629433884203U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 10428437770166310549U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 326634742742373401U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 18327174144859461029U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 6810436935194432002U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2715987179577753597U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 12606153309690753435U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 17123256945895150555U;
            aOrbiterG = RotL64((aOrbiterG * 13469111258504672565U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 9057777759026189541U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 16478485918911194442U;
            aOrbiterA = RotL64((aOrbiterA * 11054247078884894131U), 29U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterD, 48U);
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 47U) + aOrbiterF) + RotL64(aOrbiterD, 39U));
            aWandererF = aWandererF + ((((RotL64(aCross, 36U) + aOrbiterD) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 41U)) + aPhaseGWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 52U)) + aOrbiterF) + aPhaseGWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 19U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterG, 23U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererI, 21U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 9688U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((aIndex + 10696U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 9945U)) & S_BLOCK1], 20U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 8567U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 9655U)) & S_BLOCK1], 4U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15796U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 57U)) ^ (RotL64(aPrevious, 18U) + RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = (((aWandererH + RotL64(aIngress, 3U)) + RotL64(aCarry, 39U)) + 6973892330986118220U) + aPhaseGOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = (((aWandererK + RotL64(aPrevious, 57U)) + RotL64(aCarry, 53U)) + 9886813896272094864U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aScatter, 28U)) + 10996306582517553173U;
            aOrbiterD = (aWandererB + RotL64(aCross, 41U)) + 8490648283899856223U;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 11U)) + RotL64(aCarry, 23U)) + 105141713530704655U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 3114337422810562588U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 980857684690886131U;
            aOrbiterG = RotL64((aOrbiterG * 17407927633910728721U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 6562042345807072665U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 15665371138706353619U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8086237578564620623U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 18113013571374375028U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 17405346422601997299U;
            aOrbiterB = RotL64((aOrbiterB * 11162604605443005253U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 5130876096426182506U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 1813821672299154629U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15478100342425611875U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 15793814882743306728U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 13925299440495476399U;
            aOrbiterH = RotL64((aOrbiterH * 12049601510660117401U), 19U);
            //
            aIngress = RotL64(aOrbiterB, 5U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterD, 53U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterB, 43U)) + aOrbiterC) + RotL64(aCarry, 29U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 13U) + aOrbiterC) + RotL64(aOrbiterD, 29U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 21U) + aOrbiterD) + RotL64(aOrbiterH, 21U)) + RotL64(aCarry, 11U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 48U) + aOrbiterB) + RotL64(aOrbiterH, 10U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererJ, 37U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 21804U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 21584U)) & S_BLOCK1], 50U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 19300U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23316U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 16443U)) & S_BLOCK1], 52U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 23546U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 27U) + RotL64(aPrevious, 57U)) ^ (RotL64(aIngress, 43U) ^ RotL64(aCarry, 10U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (((aWandererI + RotL64(aPrevious, 3U)) + RotL64(aCarry, 43U)) + 3612110001869385068U) + aPhaseGOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = ((aWandererH + RotL64(aScatter, 43U)) + 16340824141280225936U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 21U)) + RotL64(aCarry, 23U)) + 15222338965130765231U;
            aOrbiterE = ((aWandererA + RotL64(aCross, 52U)) + RotL64(aCarry, 57U)) + 6649270508107155041U;
            aOrbiterI = (aWandererK + RotL64(aIngress, 11U)) + 768217258655426384U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 4481855259658861851U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 18318041934562434016U;
            aOrbiterG = RotL64((aOrbiterG * 14913761339765234979U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 4212457153804401807U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 16143621095636987628U;
            aOrbiterE = RotL64((aOrbiterE * 6576072860505961427U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 2095664232866642086U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 4339527736737366572U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17503569508822244125U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 13679353177869884790U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 11582168502846418236U;
            aOrbiterI = RotL64((aOrbiterI * 135539430034462861U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 10451330452898542191U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 12951448817640617841U;
            aOrbiterF = RotL64((aOrbiterF * 4141870904192742091U), 47U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 3U);
            aIngress = aIngress + (RotL64(aOrbiterF, 28U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 39U)) + aOrbiterC);
            aWandererI = aWandererI + (((RotL64(aCross, 57U) + RotL64(aOrbiterE, 47U)) + aOrbiterG) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterI, 28U)) + aOrbiterE) + aPhaseGWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 10U) + RotL64(aOrbiterF, 57U)) + aOrbiterI) + RotL64(aCarry, 37U)) + aPhaseGWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 41U) + aOrbiterC) + RotL64(aOrbiterG, 11U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 20U));
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 32583U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((aIndex + 27917U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aExpandLaneA[((aIndex + 29947U)) & S_BLOCK1], 38U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26527U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25971U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 32155U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCarry, 53U)) + (RotL64(aIngress, 39U) ^ RotL64(aCross, 26U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = (((aWandererH + RotL64(aCross, 23U)) + RotL64(aCarry, 21U)) + 12980104182836602177U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = ((aWandererF + RotL64(aIngress, 11U)) + RotL64(aCarry, 51U)) + 3172622203188863995U;
            aOrbiterA = (((aWandererE + RotL64(aScatter, 57U)) + RotL64(aCarry, 35U)) + 1170974132219980203U) + aPhaseGOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 47U)) + 6035201940965047490U;
            aOrbiterB = (aWandererD + RotL64(aIngress, 38U)) + 18033907118424996722U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 14604813424800580304U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 13720232492851066035U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8927246214721284759U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 3902659710585257448U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 8331560652661619868U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11418103770615560205U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 4485014147538689794U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 168202636924512424U;
            aOrbiterD = RotL64((aOrbiterD * 13711020666131492091U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 16227825670092707848U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 4792781933944671365U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15859849676231455283U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 12636865372722601282U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 18198291399585556632U;
            aOrbiterK = RotL64((aOrbiterK * 18155803890313399795U), 3U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterK, 47U);
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aCross, 51U) + aOrbiterA) + RotL64(aOrbiterD, 3U)) + aPhaseGWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 42U) + RotL64(aOrbiterD, 54U)) + aOrbiterK) + RotL64(aCarry, 35U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterB, 11U)) + aOrbiterE);
            aWandererD = aWandererD + (((RotL64(aPrevious, 11U) + aOrbiterB) + RotL64(aOrbiterD, 23U)) + RotL64(aCarry, 11U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterK, 37U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + RotL64(aWandererE, 43U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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

void TwistExpander_Boxing_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterJ = 0;

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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 4554U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((aIndex + 6177U)) & S_BLOCK1], 18U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 7190U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4778U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7821U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 2064U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCross, 43U)) ^ (RotL64(aCarry, 28U) ^ RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 19U)) + RotL64(aCarry, 51U)) + 9751314027302668907U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 37U)) + 12175450995523107056U;
            aOrbiterH = ((aWandererG + RotL64(aCross, 4U)) + 17519694958730119552U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aIngress, 43U)) + RotL64(aCarry, 5U)) + 9093525527925682263U;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 35U)) + 3713831321786810138U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 10108355209191835040U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 12956307447311314768U;
            aOrbiterH = RotL64((aOrbiterH * 9198936928658626667U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 1904298513945877359U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 4658049993308574460U;
            aOrbiterB = RotL64((aOrbiterB * 10482422152074338611U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 9826333658248851902U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 12058666914724365134U;
            aOrbiterE = RotL64((aOrbiterE * 964233873188373939U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 2516574707110528099U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 13335308331049750235U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5880227828760598587U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 8230749255538495304U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 16536559486797811486U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7097036838156464969U), 19U);
            //
            aIngress = RotL64(aOrbiterH, 47U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + RotL64(aOrbiterE, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aCross, 39U) + aOrbiterA) + RotL64(aOrbiterE, 23U)) + RotL64(aCarry, 53U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 21U) + aOrbiterE) + RotL64(aOrbiterH, 47U));
            aWandererA = aWandererA + ((RotL64(aIngress, 52U) + RotL64(aOrbiterH, 60U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 5U) + aOrbiterH) + RotL64(aOrbiterB, 37U)) + aPhaseHWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 13U) + aOrbiterC) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 58U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + RotL64(aWandererB, 3U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 10541U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((aIndex + 10555U)) & S_BLOCK1], 60U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 10379U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13618U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14050U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 11322U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 29U)) + (RotL64(aCross, 56U) ^ RotL64(aIngress, 13U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 23U)) + RotL64(aCarry, 19U)) + 12380376990224645149U;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 13U)) + 18296928500297384014U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aScatter, 3U)) + RotL64(aCarry, 57U)) + 3550626816361145100U;
            aOrbiterB = (((aWandererA + RotL64(aPrevious, 35U)) + RotL64(aCarry, 39U)) + 2667792936946706027U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = (aWandererB + RotL64(aCross, 56U)) + 12020969779370926953U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 737340727886903447U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 1681797651799760502U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11923920414802777451U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 2956186342689489064U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 1876852870402977177U;
            aOrbiterE = RotL64((aOrbiterE * 8875540081346621757U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 6433205819353555071U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 9065076854974222998U;
            aOrbiterB = RotL64((aOrbiterB * 5459675878087242021U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 3254410578766789992U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 2005081975473815576U;
            aOrbiterH = RotL64((aOrbiterH * 9947701153722014085U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 15992999234834560419U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 3458344156815120948U;
            aOrbiterJ = RotL64((aOrbiterJ * 1668460113964608051U), 11U);
            //
            aIngress = RotL64(aOrbiterB, 42U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterE, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 18U) + RotL64(aOrbiterJ, 3U)) + aOrbiterB) + RotL64(aCarry, 29U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 11U)) + aOrbiterG);
            aWandererF = aWandererF + (((RotL64(aCross, 47U) + aOrbiterH) + RotL64(aOrbiterJ, 53U)) + aPhaseHWandererUpdateSaltD[((aIndex + 12U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 27U) + aOrbiterG) + RotL64(aOrbiterB, 21U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 39U) + RotL64(aOrbiterG, 36U)) + aOrbiterJ) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 22878U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 21940U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16692U)) & S_BLOCK1], 38U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16606U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17462U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 20420U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aIngress, 22U)) ^ (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = ((aWandererK + RotL64(aIngress, 60U)) + 3238389262925516513U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = ((aWandererH + RotL64(aScatter, 51U)) + RotL64(aCarry, 3U)) + 12381787182611386995U;
            aOrbiterF = (((aWandererD + RotL64(aPrevious, 13U)) + RotL64(aCarry, 21U)) + 7883885539305181549U) + aPhaseHOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = ((aWandererA + RotL64(aCross, 21U)) + RotL64(aCarry, 39U)) + 1185413044597727092U;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 5U)) + 15219353497204773135U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 7533774715626734082U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 2599930450937763464U;
            aOrbiterF = RotL64((aOrbiterF * 13207380361960949159U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 16074720663961214284U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 15483613196360051221U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11717479088020532861U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 9396557867081376268U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 9668459976852660245U;
            aOrbiterG = RotL64((aOrbiterG * 11748505665890567063U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 9037269914643207212U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 16936742640861088240U;
            aOrbiterJ = RotL64((aOrbiterJ * 1040172193161012227U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 16481274825758546398U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 481851372837611166U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2225030139210599207U), 23U);
            //
            aIngress = RotL64(aOrbiterD, 39U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 5U)) + aOrbiterA);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 29U)) + aOrbiterF) + RotL64(aCarry, 13U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 46U) + aOrbiterJ) + RotL64(aOrbiterG, 60U));
            aWandererB = aWandererB + ((((RotL64(aCross, 35U) + RotL64(aOrbiterA, 39U)) + aOrbiterD) + RotL64(aCarry, 37U)) + aPhaseHWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterA, 21U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + RotL64(aWandererA, 34U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 28914U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((aIndex + 25510U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30948U)) & S_BLOCK1], 40U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32319U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32136U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 27071U)) & S_BLOCK1], 46U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aPrevious, 3U)) ^ (RotL64(aIngress, 20U) + RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = ((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 5U)) + 13174219512651137892U;
            aOrbiterA = (((aWandererE + RotL64(aPrevious, 29U)) + RotL64(aCarry, 19U)) + 2715455762789269341U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = (aWandererI + RotL64(aIngress, 37U)) + 1338018183235594313U;
            aOrbiterJ = ((aWandererH + RotL64(aCross, 4U)) + RotL64(aCarry, 57U)) + 16566866551729552930U;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 13U)) + 6901845297307236726U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 2476078302049201718U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 15531109473927052260U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1078804000420970559U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 4087849380858572351U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 5167830630098599644U;
            aOrbiterJ = RotL64((aOrbiterJ * 1982835131228146099U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 7275995452428627217U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 14794340370010024117U;
            aOrbiterA = RotL64((aOrbiterA * 8779497557416568379U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 8509217403041662849U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 2321522025240806996U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 113568101672878697U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 5676672952755594051U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 2304681269233504384U;
            aOrbiterE = RotL64((aOrbiterE * 15731441084605554497U), 27U);
            //
            aIngress = RotL64(aOrbiterG, 43U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + RotL64(aOrbiterD, 14U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 20U)) + aOrbiterG) + aPhaseHWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 51U) + aOrbiterG) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 37U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterJ, 53U)) + aOrbiterE) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 39U) + RotL64(aOrbiterD, 35U)) + aOrbiterJ) + RotL64(aCarry, 19U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 28U) + RotL64(aOrbiterA, 43U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + RotL64(aWandererA, 5U);
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
