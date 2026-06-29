#include "TwistExpander_FootBall_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_FootBall_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x9B81A39D09FC0F5DULL + 0xA5AAAA1B6739420BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x99E3E7E919562A59ULL + 0xA34EC8ACB93F3216ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x835DEA71DE449C15ULL + 0xCD3ED6F63D293A4CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x94E83A0DF839CDE7ULL + 0xB3CA9FC7535733DDULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xC740D915EA688B9FULL + 0xFE3CC93A84CC8074ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xBADF69143211FDCDULL + 0xEE5BCC4DBEA010FEULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xC662381F35D140E9ULL + 0xDA951D3048AE03A6ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xFD64D90A8090B4D7ULL + 0xB7B70E7E2B619E43ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xFCA1645CDD978881ULL + 0x8CB8B7D4624AD2CAULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xFBB5A06DA2A60EDDULL + 0xA9564E0569A38153ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xD8E945D7E2F4B30BULL + 0x9980E5FC99C7C91DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xEA4B88169A39EDD7ULL + 0x96638E2A0E3AACD4ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xAA75A55522DF5EB7ULL + 0xBB26D4DFF90A7407ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xE648707721504A8BULL + 0x8644819C0F08E15EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xB87B5940D8DEBD3FULL + 0xAC2E2674FE237B83ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x8559FF8E071B29A7ULL + 0xB1254E854E1FA9F2ULL);
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
            aIngress = RotL64(mSource[((aIndex + 4443U)) & S_BLOCK1], 43U) ^ RotL64(pSnow[((aIndex + 2263U)) & S_BLOCK1], 6U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 3271U)) & S_BLOCK1], 43U) ^ RotL64(mSource[((aIndex + 3386U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCarry, 21U)) + (RotL64(aCross, 54U) ^ RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterA = (((aWandererJ + RotL64(aCross, 57U)) + RotL64(aCarry, 47U)) + 898812731947995389U) + aNonceWordH;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 21U)) + 8677347622525527167U) + aOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aPrevious, 35U)) + 770321564027567654U;
            aOrbiterH = ((aWandererK + RotL64(aIngress, 48U)) + 11020474858081526395U) + aOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = (aWandererD + RotL64(aCross, 13U)) + 17289793580414993470U;
            aOrbiterK = (aWandererA + RotL64(aPrevious, 29U)) + 10111912559295118444U;
            aOrbiterD = (((aWandererB + RotL64(aIngress, 11U)) + RotL64(aCarry, 21U)) + 8083622125544542011U) + aNonceWordE;
            aOrbiterI = (aWandererC + RotL64(aScatter, 53U)) + 7149858558922988240U;
            aOrbiterE = ((aWandererF + RotL64(aIngress, 37U)) + 5919683821379905699U) + aNonceWordM;
            aOrbiterJ = (aWandererH + RotL64(aCross, 18U)) + 6860902846079238714U;
            aOrbiterG = (((aWandererE + RotL64(aScatter, 5U)) + RotL64(aCarry, 39U)) + 15083517836867542075U) + aNonceWordP;
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 14852868368708376381U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 9860233289028878323U) ^ aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13418143547952204667U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 772406119079116272U) + aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 7971141501337627589U;
            aOrbiterC = RotL64((aOrbiterC * 10168120622976358617U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 8478568022896691911U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 4027604850785607101U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4826627523578901467U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 17199331557841535430U) + aNonceWordG;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 7515957656979776361U;
            aOrbiterI = RotL64((aOrbiterI * 5468950152869656599U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 17138249294921502391U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 16236812863923234668U;
            aOrbiterK = RotL64((aOrbiterK * 2925542836624164807U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 16941524155859123682U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 11240343728857342866U;
            aOrbiterA = RotL64((aOrbiterA * 7281012444214294659U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 15163914964139858328U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 6673576554415729652U) ^ aNonceWordK;
            aOrbiterG = RotL64((aOrbiterG * 1558880328574736975U), 27U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterA) + 5399050402101642989U) + aOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1]) + aNonceWordO;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 11806006719060024615U;
            aOrbiterD = RotL64((aOrbiterD * 15782156615926092159U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 9812148913932011655U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 4737919734590584193U;
            aOrbiterB = RotL64((aOrbiterB * 2739737604370936959U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 3415477403346468057U) + aNonceWordD;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 5922725868927615919U;
            aOrbiterE = RotL64((aOrbiterE * 12390148483052777871U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 17435294951520465659U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 898812731947995389U;
            aOrbiterJ = RotL64((aOrbiterJ * 17248379279729365007U), 19U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterA, 39U);
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 34U));
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 24U) + RotL64(aOrbiterB, 27U)) + aOrbiterH);
            aWandererK = aWandererK + ((((RotL64(aIngress, 51U) + aOrbiterI) + RotL64(aOrbiterF, 29U)) + aNonceWordJ) + aWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 47U) + aOrbiterH) + RotL64(aOrbiterJ, 60U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 21U) + RotL64(aOrbiterJ, 47U)) + aOrbiterK) + aNonceWordA);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 27U) + aOrbiterG) + RotL64(aOrbiterC, 13U));
            aWandererC = aWandererC + (((RotL64(aCross, 56U) + RotL64(aOrbiterA, 37U)) + aOrbiterE) + RotL64(aCarry, 57U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 11U) + aOrbiterA) + RotL64(aOrbiterG, 44U)) + aNonceWordB);
            aWandererA = aWandererA + (((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 53U)) + aOrbiterA) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterF, 11U)) + aOrbiterD) + aWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterB, 19U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 43U) + aOrbiterK) + RotL64(aOrbiterC, 3U)) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 50U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + RotL64(aWandererI, 42U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 10853U)) & S_BLOCK1], 39U) ^ RotL64(mSource[((aIndex + 7232U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10776U)) & S_BLOCK1], 13U) ^ RotL64(pSnow[((aIndex + 5491U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 52U) ^ RotL64(aIngress, 11U)) ^ (RotL64(aCross, 39U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterH = ((aWandererD + RotL64(aCross, 51U)) + 5697928251815176134U) + aNonceWordI;
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 47U)) + 337587740689259575U) + aNonceWordK;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 11U)) + RotL64(aCarry, 19U)) + 4927686903263973950U;
            aOrbiterB = (aWandererF + RotL64(aIngress, 57U)) + 3742409032569801033U;
            aOrbiterF = (aWandererE + RotL64(aCross, 53U)) + 1608092659172197650U;
            aOrbiterD = (aWandererJ + RotL64(aScatter, 28U)) + 15848744267145717509U;
            aOrbiterI = (((aWandererC + RotL64(aPrevious, 41U)) + RotL64(aCarry, 3U)) + 15300174177963339253U) + aOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = ((aWandererH + RotL64(aIngress, 21U)) + RotL64(aCarry, 43U)) + 14162868453323648628U;
            aOrbiterA = (aWandererI + RotL64(aCross, 5U)) + 12020167069983729869U;
            aOrbiterK = (aWandererK + RotL64(aScatter, 30U)) + 16259538291658723956U;
            aOrbiterG = ((aWandererB + RotL64(aIngress, 39U)) + 8516686212464112245U) + aOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 3722184575520553132U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 5663609293306386784U;
            aOrbiterJ = RotL64((aOrbiterJ * 14364218128780764749U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 15265344442454471986U) + aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 3050323350098829515U;
            aOrbiterD = RotL64((aOrbiterD * 5890624677162388135U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 1093356813820599238U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 15167726103772238440U;
            aOrbiterE = RotL64((aOrbiterE * 5719466863561311069U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 15170797965325981472U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 17826286701992981628U) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 11186808881726573677U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 14710892030473425181U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 397194787697553904U;
            aOrbiterK = RotL64((aOrbiterK * 14368930300818752833U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 1273724124862533034U) + aNonceWordJ;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 13018397560392545616U;
            aOrbiterH = RotL64((aOrbiterH * 4644812473262395329U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 9638716186445643730U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 7255587739807843785U) ^ aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6055682981584011189U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 9272350563697399628U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 1040729335295009339U) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 17825687660830291443U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 12128124729613601747U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 2285238815562202219U;
            aOrbiterB = RotL64((aOrbiterB * 15398840993074390573U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 6339113298619163493U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 5911895708485037040U;
            aOrbiterC = RotL64((aOrbiterC * 3271006139923200439U), 39U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterK) + 7601399508218901328U) + aOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1]) + aNonceWordF;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 5697928251815176134U;
            aOrbiterI = RotL64((aOrbiterI * 8184257916861355735U), 3U);
            //
            aIngress = RotL64(aOrbiterE, 57U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterC, 30U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterD, 29U)) + aOrbiterC);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterI, 3U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 48U) + RotL64(aOrbiterI, 43U)) + aOrbiterB);
            aWandererE = aWandererE ^ ((((RotL64(aCross, 39U) + RotL64(aOrbiterE, 27U)) + aOrbiterB) + aNonceWordM) + aWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 11U) + aOrbiterA) + RotL64(aOrbiterK, 5U)) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterC, 38U)) + aOrbiterG) + aNonceWordE);
            aWandererD = aWandererD + ((RotL64(aIngress, 41U) + aOrbiterG) + RotL64(aOrbiterK, 51U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 23U) + aOrbiterJ) + RotL64(aOrbiterG, 53U));
            aWandererH = aWandererH + (((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterC, 41U)) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterD, 18U)) + aOrbiterB) + aWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 14U) + aOrbiterD) + RotL64(aOrbiterK, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 30U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 11598U)) & S_BLOCK1], 28U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 12340U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 11163U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneA[((aIndex + 13563U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 12U) ^ RotL64(aCarry, 39U)) + (RotL64(aIngress, 51U) ^ RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterE = (aWandererE + RotL64(aCross, 3U)) + 13687218104610230596U;
            aOrbiterF = (aWandererC + RotL64(aScatter, 13U)) + 6841550124960692709U;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 19U)) + 17418968668458764131U;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 23U)) + 8303537912696948204U) + aNonceWordG;
            aOrbiterD = (aWandererI + RotL64(aScatter, 57U)) + 12376614417285936537U;
            aOrbiterH = (aWandererB + RotL64(aIngress, 52U)) + 14215749063579232654U;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 35U)) + 4111736931433665347U;
            aOrbiterA = (((aWandererH + RotL64(aCross, 39U)) + RotL64(aCarry, 27U)) + 11250375934571631522U) + aOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = (((aWandererJ + RotL64(aScatter, 27U)) + RotL64(aCarry, 5U)) + 5367367837773331275U) + aNonceWordD;
            aOrbiterC = ((aWandererK + RotL64(aCross, 11U)) + 15514089192382674434U) + aOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = ((aWandererD + RotL64(aIngress, 54U)) + RotL64(aCarry, 21U)) + 1475991716685034960U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 5531622777788629748U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 8363822215908303335U;
            aOrbiterG = RotL64((aOrbiterG * 17850203366840994883U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 3741256932685720414U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 11634667238062155772U;
            aOrbiterE = RotL64((aOrbiterE * 15925089729784547403U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 18180546911210417155U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 5123234656838556335U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15362857462853398025U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 11215734271189250284U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 16863747802158398092U;
            aOrbiterC = RotL64((aOrbiterC * 1828035970246160023U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 9859050606636646323U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 9331300036643654675U) ^ aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2502263410556166281U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 15028845665427209759U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 8916444839488901676U;
            aOrbiterF = RotL64((aOrbiterF * 6646561894156038791U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 8024631140949068570U) + aNonceWordN;
            aOrbiterI = (((aOrbiterI ^ aOrbiterK) ^ 1116378858490660031U) ^ aOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 4247798531910227367U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 5066486214537899212U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 9346312092322423057U;
            aOrbiterJ = RotL64((aOrbiterJ * 13443190089768875191U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 11651011617027950122U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 11308862427412671711U;
            aOrbiterH = RotL64((aOrbiterH * 12167147966934334703U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 3850136281462840708U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 13461307727665667424U;
            aOrbiterK = RotL64((aOrbiterK * 10788040812090673421U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 17824744996404571928U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 13687218104610230596U;
            aOrbiterD = RotL64((aOrbiterD * 325803029547254631U), 35U);
            //
            aIngress = RotL64(aOrbiterF, 47U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 51U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 43U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + RotL64(aOrbiterG, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 53U) + aOrbiterH) + RotL64(aOrbiterK, 23U)) + aWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterB, 11U)) + aOrbiterK) + aNonceWordH);
            aWandererB = aWandererB + (((RotL64(aIngress, 43U) + RotL64(aOrbiterE, 35U)) + aOrbiterJ) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 60U) + RotL64(aOrbiterF, 18U)) + aOrbiterC) + aNonceWordJ);
            aWandererE = aWandererE + ((RotL64(aIngress, 29U) + RotL64(aOrbiterH, 5U)) + aOrbiterB);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterD, 53U)) + aOrbiterF);
            aWandererC = aWandererC + (((RotL64(aCross, 19U) + RotL64(aOrbiterG, 43U)) + aOrbiterJ) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 34U) + aOrbiterA) + RotL64(aOrbiterI, 50U)) + aNonceWordI);
            aWandererK = aWandererK + ((RotL64(aIngress, 51U) + RotL64(aOrbiterD, 21U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterA, 37U)) + aOrbiterJ) + aWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 41U) + aOrbiterJ) + RotL64(aOrbiterF, 47U)) + aNonceWordA);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 36U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 21U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (RotL64(aWandererB, 18U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 27U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 20477U)) & S_BLOCK1], 20U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18781U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 18094U)) & S_BLOCK1], 23U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 19486U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18285U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCross, 53U)) ^ (RotL64(aIngress, 21U) ^ RotL64(aCarry, 34U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterF = (aWandererH + RotL64(aScatter, 29U)) + 4622023259121087483U;
            aOrbiterK = (((aWandererD + RotL64(aIngress, 58U)) + RotL64(aCarry, 5U)) + 10253505250223501352U) + aNonceWordI;
            aOrbiterH = (aWandererG + RotL64(aCross, 19U)) + 17133877904420462669U;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 23U)) + 6162827793741796700U) + aNonceWordJ;
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 43U)) + 9610986424765907615U) + aOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 27U)) + 11210747154264753754U;
            aOrbiterD = (((aWandererK + RotL64(aScatter, 5U)) + RotL64(aCarry, 51U)) + 16554205219580654546U) + aOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = (((aWandererA + RotL64(aCross, 56U)) + RotL64(aCarry, 47U)) + 10352576357413766388U) + aNonceWordN;
            aOrbiterB = (aWandererF + RotL64(aPrevious, 11U)) + 3651845783283479752U;
            aOrbiterC = (aWandererE + RotL64(aIngress, 21U)) + 18145542190463500476U;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 35U)) + 5415609566767162857U) + aNonceWordF;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 2033734872464201570U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 3507213117125813345U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5453058336688881113U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 8716253393049851856U) + aNonceWordO;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 695984869565941856U) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 8377921610764044735U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 7661578828878284931U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 906654265099155956U;
            aOrbiterE = RotL64((aOrbiterE * 8117625377607536949U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 6050049984731254612U) + aNonceWordK;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 17882717590338190821U;
            aOrbiterC = RotL64((aOrbiterC * 10807367411402733215U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 4996521991532815957U) + aOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 4246460672800604436U;
            aOrbiterD = RotL64((aOrbiterD * 12047466401960824903U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 8700148116452518842U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 10039050281847466206U;
            aOrbiterG = RotL64((aOrbiterG * 11884791271239660157U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 4513844680425845372U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 3037563127442815153U;
            aOrbiterK = RotL64((aOrbiterK * 18363509277992292407U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 1005237931570968724U) + aNonceWordE;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 1373258132025712065U;
            aOrbiterF = RotL64((aOrbiterF * 10458020799382532395U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 12759144329395682277U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 5139371668116336931U;
            aOrbiterB = RotL64((aOrbiterB * 10761543179345026943U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 3211005174890625715U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 18045286961878287418U;
            aOrbiterJ = RotL64((aOrbiterJ * 4536094526540761611U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 4454078771279674978U) + aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 4622023259121087483U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8991756794989027019U), 13U);
            //
            aIngress = RotL64(aOrbiterH, 57U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 42U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + RotL64(aOrbiterB, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aScatter, 41U) + RotL64(aOrbiterI, 23U)) + aOrbiterB) + RotL64(aCarry, 3U)) + aNonceWordL);
            aWandererH = aWandererH ^ ((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterJ, 30U));
            aWandererK = aWandererK + ((RotL64(aIngress, 44U) + aOrbiterK) + RotL64(aOrbiterD, 3U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 5U) + aOrbiterJ) + RotL64(aOrbiterH, 35U));
            aWandererA = aWandererA + ((RotL64(aIngress, 39U) + aOrbiterE) + RotL64(aOrbiterJ, 19U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 57U) + aOrbiterK) + RotL64(aOrbiterF, 57U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 23U) + RotL64(aOrbiterG, 43U)) + aOrbiterB) + aWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterE, 53U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aIngress, 37U) + aOrbiterJ) + RotL64(aOrbiterB, 37U)) + RotL64(aCarry, 53U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 50U) + aOrbiterF) + RotL64(aOrbiterG, 46U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 29U) + aOrbiterK) + RotL64(aOrbiterA, 51U)) + aNonceWordP) + aWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 10U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererC, 18U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 22972U)) & S_BLOCK1], 58U) ^ RotL64(mSource[((aIndex + 27084U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(pSnow[((aIndex + 26056U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27205U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 25449U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21888U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 60U) ^ RotL64(aCross, 43U)) + (RotL64(aPrevious, 27U) + RotL64(aCarry, 13U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterI = ((aWandererC + RotL64(aCross, 57U)) + RotL64(aCarry, 37U)) + 9107326720193244489U;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 53U)) + RotL64(aCarry, 13U)) + 10868585484401664145U;
            aOrbiterH = (aWandererA + RotL64(aIngress, 20U)) + 13637736741437846622U;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 51U)) + 6130725216183918844U) + aNonceWordK;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 41U)) + 2063834478521338187U) + aOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aScatter, 13U)) + RotL64(aCarry, 21U)) + 8564870627911949158U;
            aOrbiterC = (aWandererK + RotL64(aCross, 46U)) + 6524015751064086390U;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 3U)) + 9874937766875388236U) + aNonceWordE;
            aOrbiterG = ((aWandererE + RotL64(aScatter, 39U)) + 14723718409522680894U) + aOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 37U)) + 13767059954741528279U;
            aOrbiterF = (aWandererF + RotL64(aCross, 23U)) + 6387608251033722169U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 5391425980008431000U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 11524218415655093779U;
            aOrbiterH = RotL64((aOrbiterH * 12508457981779189389U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 155510463350385905U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 10554591788433641311U) ^ aNonceWordC;
            aOrbiterJ = RotL64((aOrbiterJ * 5412084824127934293U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 8662160162966241542U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 5092555636369853727U;
            aOrbiterC = RotL64((aOrbiterC * 433807340167635499U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 7163345798448796101U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 695089002178413267U) ^ aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17302689458565434475U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 5409173939213468972U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 15349690077393827541U;
            aOrbiterB = RotL64((aOrbiterB * 10984681254001609841U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 12376011890751302027U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 7809614158898158383U;
            aOrbiterA = RotL64((aOrbiterA * 13845113198736843629U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 13031938699536449576U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 3983178190194056516U;
            aOrbiterG = RotL64((aOrbiterG * 1341678482929213405U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 5567935037909671790U) + aNonceWordP;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 17137042627663349797U;
            aOrbiterF = RotL64((aOrbiterF * 13535586899620672373U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 8726085717433137208U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 13154097637429217548U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5523758597936082363U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 4030516340575723215U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 7121696965917254968U;
            aOrbiterD = RotL64((aOrbiterD * 13569584361980228493U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 12079991626282752674U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 9107326720193244489U;
            aOrbiterI = RotL64((aOrbiterI * 7225937408665051799U), 23U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 6U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterC, 51U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterH, 37U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 13U) + aOrbiterJ) + RotL64(aOrbiterG, 29U)) + aNonceWordL);
            aWandererK = aWandererK + ((RotL64(aPrevious, 43U) + aOrbiterD) + RotL64(aOrbiterH, 58U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 11U) + aOrbiterH) + RotL64(aOrbiterB, 27U)) + aNonceWordG);
            aWandererE = aWandererE + ((((RotL64(aIngress, 48U) + RotL64(aOrbiterJ, 11U)) + aOrbiterE) + aNonceWordD) + aWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterK, 37U)) + aOrbiterA) + aNonceWordH);
            aWandererD = aWandererD + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterC, 23U)) + aOrbiterK) + RotL64(aCarry, 35U)) + aWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 21U) + aOrbiterG) + RotL64(aOrbiterA, 21U));
            aWandererF = aWandererF + (((RotL64(aScatter, 41U) + aOrbiterB) + RotL64(aOrbiterG, 47U)) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 37U) + aOrbiterC) + RotL64(aOrbiterB, 18U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 5U) + RotL64(aOrbiterJ, 53U)) + aOrbiterF);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 26U) + aOrbiterF) + RotL64(aOrbiterI, 35U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 10U));
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + RotL64(aWandererE, 23U);
            aCarry = aCarry + RotL64(aIngress, 42U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 31147U)) & S_BLOCK1], 19U) ^ RotL64(pSnow[((aIndex + 31248U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 27689U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 28694U)) & S_BLOCK1], 51U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 28245U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29631U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 37U) + RotL64(aPrevious, 21U)) ^ (RotL64(aIngress, 52U) + RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterB = ((aWandererA + RotL64(aScatter, 60U)) + RotL64(aCarry, 23U)) + 2915859148137000694U;
            aOrbiterE = (aWandererE + RotL64(aPrevious, 57U)) + 210680583721444425U;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 3U)) + 6668118118775650387U) + aNonceWordJ;
            aOrbiterI = (aWandererI + RotL64(aIngress, 19U)) + 15794200818099010989U;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 29U)) + RotL64(aCarry, 43U)) + 6565076707062828369U;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 10U)) + 16323164497808856719U) + aNonceWordC;
            aOrbiterA = (aWandererK + RotL64(aIngress, 23U)) + 7965435318816716560U;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 53U)) + 7390281030573369017U) + aOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = ((aWandererF + RotL64(aIngress, 21U)) + 2269738866911824875U) + aNonceWordH;
            aOrbiterD = ((aWandererH + RotL64(aCross, 37U)) + RotL64(aCarry, 5U)) + 9664014216039993873U;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 13U)) + 18284857398028357633U) + aOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 367667619795303009U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 7935945060956274197U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5481786693511955209U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 16683666162337789540U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 10655658270998102390U;
            aOrbiterF = RotL64((aOrbiterF * 15231596813382239841U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 8307037916581540297U) + aNonceWordD;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 3247742749860703524U;
            aOrbiterC = RotL64((aOrbiterC * 15052136713218656641U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 10446792483683818139U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 16374602929344972364U;
            aOrbiterB = RotL64((aOrbiterB * 12599903932725787599U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 2411334498322777183U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 1093701164116833765U;
            aOrbiterD = RotL64((aOrbiterD * 13129220206835381729U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 17018480952982840635U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 17348395690080029814U) ^ aNonceWordK;
            aOrbiterG = RotL64((aOrbiterG * 6212591395713433257U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 16111252311283623152U) + aOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 12776492920397785951U;
            aOrbiterE = RotL64((aOrbiterE * 6136009241593081821U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 12214538600808144816U) + aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 10043377462096783363U) ^ aNonceWordM;
            aOrbiterK = RotL64((aOrbiterK * 14639467375095185877U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 5101561512438055661U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 3683207847147603335U;
            aOrbiterI = RotL64((aOrbiterI * 14355438383379198639U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 14446947359104987749U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 7596096688268335354U) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 13522935803383107145U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 14015424109468938015U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 2915859148137000694U;
            aOrbiterA = RotL64((aOrbiterA * 3653144205211106817U), 5U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 29U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + (RotL64(aOrbiterA, 37U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + (RotL64(aOrbiterK, 6U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterB, 35U)) + aOrbiterC);
            aWandererE = aWandererE + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterJ, 27U)) + aOrbiterF) + RotL64(aCarry, 43U)) + aNonceWordF);
            aWandererI = aWandererI ^ ((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterE, 19U));
            aWandererK = aWandererK + ((RotL64(aIngress, 51U) + aOrbiterH) + RotL64(aOrbiterD, 43U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 56U) + RotL64(aOrbiterK, 10U)) + aOrbiterG) + aNonceWordA);
            aWandererA = aWandererA + ((((RotL64(aIngress, 41U) + RotL64(aOrbiterG, 51U)) + aOrbiterA) + RotL64(aCarry, 57U)) + aWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterK, 57U));
            aWandererB = aWandererB + ((RotL64(aCross, 35U) + RotL64(aOrbiterA, 21U)) + aOrbiterK);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 58U) + aOrbiterA) + RotL64(aOrbiterD, 13U)) + aNonceWordO);
            aWandererF = aWandererF + ((RotL64(aPrevious, 19U) + aOrbiterJ) + RotL64(aOrbiterG, 6U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterC, 41U)) + aOrbiterF) + aWandererUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 34U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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

void TwistExpander_FootBall_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xB11147C68D3C0D69ULL + 0x821B2625F5937EFEULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xEF51F43E8B0071A5ULL + 0x80E3A0B8D2F8060DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xCCF710FABF541D5FULL + 0xB592E440D9738B40ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xA97134620322AE07ULL + 0xC64B3DB06B53C7FDULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA28A17731BFA1DB9ULL + 0xBCC7D0403430CDBCULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xA40AB928B4929005ULL + 0xCBA02541376B3868ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xF333607761DB4819ULL + 0x905F11AFC1BA6210ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xFCBBE19FBA61A679ULL + 0xE1C1A0FE46323CACULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xA921AFAA66316179ULL + 0xD24C9BCDDFA5136FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xC0FCEC3A1D9DD0E3ULL + 0xAF9421723C7EB6DBULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xC206687ACAB0FB79ULL + 0xC2CED5906C3B5EEDULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xFA9A0C8C783373A7ULL + 0x8911FFF1988CCD9CULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xE9421638E092C96FULL + 0xC7497DB5E07EE1EDULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xD81B3D7B53736195ULL + 0xAAD77D12272C0F89ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xC092FAF19EB8D8BFULL + 0xDCC7F0394B372AEAULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xEE38785175691E3FULL + 0xA15470357C5ED9CCULL);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 5626U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneB[((aIndex + 1599U)) & S_BLOCK1], 24U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 5975U)) & S_BLOCK1], 18U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 6351U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 56U) ^ RotL64(aCarry, 11U)) ^ (RotL64(aIngress, 39U) + RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterH = ((aWandererG + RotL64(aIngress, 57U)) + RotL64(aCarry, 47U)) + 1888427424966603593U;
            aOrbiterI = (aWandererI + RotL64(aPrevious, 28U)) + 5436761445660415091U;
            aOrbiterG = (aWandererB + RotL64(aScatter, 53U)) + 17322876217962143270U;
            aOrbiterF = (((aWandererA + RotL64(aCross, 3U)) + RotL64(aCarry, 57U)) + 9728299982740564979U) + aOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aScatter, 37U)) + 301720335271716921U) + aNonceWordH;
            aOrbiterK = (((aWandererJ + RotL64(aPrevious, 43U)) + RotL64(aCarry, 35U)) + 8069685428854814396U) + aNonceWordB;
            aOrbiterB = (aWandererH + RotL64(aCross, 13U)) + 1973715500949100991U;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 48U)) + 87666408799854155U) + aOrbiterAssignSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = (aWandererD + RotL64(aPrevious, 19U)) + 12195436904339035245U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 4578742069143400295U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 7828776048774876484U) ^ aNonceWordG;
            aOrbiterG = RotL64((aOrbiterG * 4047964518501081039U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 17203146364542781833U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 16913369550858890466U;
            aOrbiterK = RotL64((aOrbiterK * 13534417587921978507U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 9632761514552265402U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 9106637671877341286U;
            aOrbiterB = RotL64((aOrbiterB * 9073709119482640391U), 57U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterF) + 15423680889126750876U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordK;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 6087310684583331882U) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 8964465129744898619U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 5420955876411796789U) + aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 14166807419730848032U;
            aOrbiterI = RotL64((aOrbiterI * 442659738632823751U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 8118312450347026824U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 4253043584558403086U;
            aOrbiterH = RotL64((aOrbiterH * 5651748455190536467U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 8810774678371762700U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 12218479555589447835U;
            aOrbiterF = RotL64((aOrbiterF * 11026364205248516355U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 11389930523582876358U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 16334420553471379915U;
            aOrbiterD = RotL64((aOrbiterD * 13830132212033904777U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 18201289372553710279U) + aOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 7196540389657785361U;
            aOrbiterE = RotL64((aOrbiterE * 13058135202554889791U), 3U);
            //
            aIngress = RotL64(aOrbiterI, 30U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 11U));
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 35U)) + aOrbiterI) + aNonceWordN);
            aWandererI = aWandererI + (((RotL64(aIngress, 42U) + aOrbiterA) + RotL64(aOrbiterB, 28U)) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterK, 13U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterG, 57U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 23U) + aOrbiterH) + RotL64(aOrbiterG, 53U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 27U) + aOrbiterG) + RotL64(aOrbiterF, 40U)) + RotL64(aCarry, 5U)) + aNonceWordD);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 60U) + aOrbiterD) + RotL64(aOrbiterE, 47U)) + aWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterF, 3U)) + aWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterD, 23U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererD, 50U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 37U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 11839U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneB[((aIndex + 16304U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 16058U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 13249U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneD[((aIndex + 13170U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 40U) + RotL64(aCross, 57U)) ^ (RotL64(aCarry, 21U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterH = ((aWandererG + RotL64(aCross, 23U)) + 1142447269198373880U) + aOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = ((((aWandererA + RotL64(aPrevious, 27U)) + RotL64(aCarry, 29U)) + 10581460640040336191U) + aOrbiterAssignSaltE[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordD;
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 43U)) + RotL64(aCarry, 43U)) + 14703062773878202900U;
            aOrbiterI = ((aWandererF + RotL64(aScatter, 14U)) + RotL64(aCarry, 19U)) + 15737525756286914746U;
            aOrbiterG = ((aWandererK + RotL64(aCross, 5U)) + 16178774478273186999U) + aNonceWordM;
            aOrbiterF = (aWandererE + RotL64(aScatter, 47U)) + 2514897053906809160U;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 19U)) + 13702496607592508464U;
            aOrbiterK = (aWandererB + RotL64(aIngress, 58U)) + 18030885275418337965U;
            aOrbiterB = (aWandererD + RotL64(aScatter, 51U)) + 5241783876161655984U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 2807052676283587925U) + aNonceWordP;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 8022804576763271327U) ^ aNonceWordA;
            aOrbiterJ = RotL64((aOrbiterJ * 11727096043219370577U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 15597099852232205860U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 1538435607932096400U;
            aOrbiterF = RotL64((aOrbiterF * 7900752511710516981U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 11147868774413615365U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 9325213746830411568U;
            aOrbiterG = RotL64((aOrbiterG * 561819005818948769U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 13792300423550555634U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 3134856508983945719U;
            aOrbiterA = RotL64((aOrbiterA * 4271845067763664863U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 8654966018053784882U) + aNonceWordI;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 8937113935476779267U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7386875687217705855U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 4135676350355234788U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 11407912615743682678U) ^ aOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2773506587480714695U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 10966950663872392059U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 6686634993700944582U;
            aOrbiterK = RotL64((aOrbiterK * 2509459942163678241U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 14154407529749257990U) + aNonceWordG;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 18054640398549782388U;
            aOrbiterH = RotL64((aOrbiterH * 7830759861389060149U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 14623473030642960240U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 1857945571104460086U;
            aOrbiterI = RotL64((aOrbiterI * 18039903315045620079U), 23U);
            //
            aIngress = RotL64(aOrbiterH, 11U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 34U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + RotL64(aOrbiterA, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterK, 23U)) + aOrbiterF) + aNonceWordN);
            aWandererG = aWandererG + ((((RotL64(aScatter, 10U) + aOrbiterH) + RotL64(aOrbiterI, 42U)) + RotL64(aCarry, 39U)) + aNonceWordJ);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterA, 19U)) + aOrbiterK) + aNonceWordF);
            aWandererF = aWandererF + (((RotL64(aCross, 23U) + aOrbiterF) + RotL64(aOrbiterD, 53U)) + aWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterG, 35U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 47U)) + aOrbiterF);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 43U) + aOrbiterB) + RotL64(aOrbiterA, 12U)) + aWandererUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 60U) + aOrbiterH) + RotL64(aOrbiterG, 27U)) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterJ, 5U)) + aOrbiterH) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 14U));
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 18889U)) & S_BLOCK1], 53U) ^ RotL64(aFireLaneD[((aIndex + 16680U)) & S_BLOCK1], 40U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 18269U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 21158U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 22916U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 17040U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 22U) ^ RotL64(aPrevious, 53U)) ^ (RotL64(aIngress, 39U) + RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterC = (aWandererC + RotL64(aIngress, 24U)) + 3612110001869385068U;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 29U)) + 16340824141280225936U;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 51U)) + 15222338965130765231U) + aNonceWordD;
            aOrbiterJ = (aWandererI + RotL64(aCross, 5U)) + 6649270508107155041U;
            aOrbiterK = (((aWandererH + RotL64(aScatter, 29U)) + RotL64(aCarry, 53U)) + 768217258655426384U) + aOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 43U)) + 4481855259658861851U) + aNonceWordM;
            aOrbiterG = (((aWandererF + RotL64(aCross, 60U)) + 18318041934562434016U) + aOrbiterAssignSaltC[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordI;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 39U)) + RotL64(aCarry, 21U)) + 4212457153804401807U;
            aOrbiterB = ((aWandererD + RotL64(aCross, 35U)) + 16143621095636987628U) + aNonceWordL;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 2095664232866642086U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 4339527736737366572U;
            aOrbiterE = RotL64((aOrbiterE * 17503569508822244125U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 13679353177869884790U) + aNonceWordO;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 11582168502846418236U;
            aOrbiterK = RotL64((aOrbiterK * 135539430034462861U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 10451330452898542191U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 12951448817640617841U) ^ aNonceWordA;
            aOrbiterG = RotL64((aOrbiterG * 4141870904192742091U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 15389161934419370747U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 4754886272708253014U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16638243718191281597U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 11746389873929280688U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 12042680172517298768U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3814780289755857543U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 2648103752465009244U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 451594673632597973U;
            aOrbiterD = RotL64((aOrbiterD * 8496763663271072425U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 5696534794094099710U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterF) ^ 14609435045257077395U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterI = RotL64((aOrbiterI * 14658408563237468407U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 11599395126850950133U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 12699598504604446664U;
            aOrbiterC = RotL64((aOrbiterC * 14313494063098111823U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 9398465148537154745U) + aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 12139736860648011256U;
            aOrbiterJ = RotL64((aOrbiterJ * 15257503229375247987U), 53U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterB, 44U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 43U)) + aOrbiterF);
            aWandererF = aWandererF + ((RotL64(aCross, 44U) + aOrbiterF) + RotL64(aOrbiterD, 39U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 39U) + aOrbiterK) + RotL64(aOrbiterG, 12U));
            aWandererI = aWandererI + (((RotL64(aScatter, 11U) + aOrbiterD) + RotL64(aOrbiterK, 21U)) + aWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterC, 51U)) + aOrbiterD) + aWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aCross, 48U) + RotL64(aOrbiterB, 29U)) + aOrbiterG) + RotL64(aCarry, 19U)) + aNonceWordK);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterI, 47U)) + aOrbiterG) + aNonceWordF);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 53U)) + aNonceWordP);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterF, 58U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (RotL64(aWandererC, 30U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + RotL64(aWandererF, 5U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 29692U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneC[((aIndex + 31181U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28241U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28764U)) & S_BLOCK1], 37U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 28510U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 25653U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aPrevious, 38U)) + (RotL64(aCarry, 23U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterC = ((aWandererK + RotL64(aCross, 18U)) + RotL64(aCarry, 11U)) + 2101601659597850213U;
            aOrbiterG = (aWandererH + RotL64(aPrevious, 41U)) + 2759794072560720121U;
            aOrbiterA = ((aWandererF + RotL64(aScatter, 57U)) + RotL64(aCarry, 53U)) + 9443562552411269339U;
            aOrbiterD = (aWandererE + RotL64(aIngress, 37U)) + 10801360546699857975U;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 51U)) + 8020716394829332019U) + aNonceWordH;
            aOrbiterF = ((aWandererG + RotL64(aCross, 29U)) + 1021894212367773801U) + aOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = (((aWandererA + RotL64(aIngress, 23U)) + RotL64(aCarry, 41U)) + 13346855534622490176U) + aOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 3U)) + 16359309548462953836U) + aNonceWordI;
            aOrbiterE = ((aWandererC + RotL64(aCross, 14U)) + 12642446944680783519U) + aNonceWordG;
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 8197424982767553380U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterC) ^ 14346334610901859094U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 16982899923227935679U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 14171304260534233539U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 334531601308283605U;
            aOrbiterI = RotL64((aOrbiterI * 5012968232749075075U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 10707856298471572695U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 18364775750091914766U;
            aOrbiterG = RotL64((aOrbiterG * 15735143943129143265U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 8531394793118363836U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 15352876929406908882U;
            aOrbiterC = RotL64((aOrbiterC * 475199047053777179U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 567682016232278157U) + aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 2068146551757663119U;
            aOrbiterH = RotL64((aOrbiterH * 1557877740957797555U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 7776122587613256525U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 16430938890724272256U) ^ aNonceWordC;
            aOrbiterD = RotL64((aOrbiterD * 4540270493783593257U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 11912000645055436094U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 16800749242578741498U) ^ aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17804584625034241737U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 5909199180260499150U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 5751089915336865588U;
            aOrbiterF = RotL64((aOrbiterF * 15376689503142397927U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 3478216857728853008U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 18007567146937338241U;
            aOrbiterE = RotL64((aOrbiterE * 6620498877303917855U), 41U);
            //
            aIngress = RotL64(aOrbiterK, 11U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + RotL64(aOrbiterE, 38U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 43U) + aOrbiterH) + RotL64(aOrbiterK, 35U));
            aWandererG = aWandererG + ((RotL64(aScatter, 60U) + aOrbiterH) + RotL64(aOrbiterE, 30U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterD, 53U)) + aOrbiterI) + aWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 57U)) + aWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterA, 43U)) + aNonceWordO);
            aWandererE = aWandererE + ((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterF, 57U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 18U) + RotL64(aOrbiterH, 39U)) + aOrbiterA);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 13U)) + aOrbiterG) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterI, 24U)) + aOrbiterG) + aNonceWordN);
            //
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 44U);
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

void TwistExpander_FootBall_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xA2B680A8C27E26CFULL + 0xD784516B9D71CD5DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xC617EFCA80E36C91ULL + 0xED811409D31AA971ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xCACB22E46402B029ULL + 0xCEFDE130B5160CB1ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x80180DDA9C624AABULL + 0xCD4AE8DA320EB988ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xCA71936952B33E89ULL + 0xE059A9346B3CB8E0ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xA3145D4D6CCF22A3ULL + 0xF2EE1F88C52C79CAULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xA3C6FF751CCFEFFBULL + 0xD1CF9489763BF788ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xA7175D59430A3345ULL + 0xBAC961829B512084ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xF50657EBA7E9BF83ULL + 0xAFF1266406204668ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xBE21EF9B7C0AB60FULL + 0xF7EC994F01581CD5ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xA2985E7DBCC1D9B3ULL + 0xFC42B2CF591142F8ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xD4AAB73E42512D0BULL + 0x913DF92A8E612B70ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x8BBC21398CDE8799ULL + 0xFAF3C6B3CE9A2BD5ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xF1AF57786B85584DULL + 0xEB55C8BB4AFDF315ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xA72B5E0AAF5C0753ULL + 0x9009879FA8D8B8C4ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xC34976C2002FECB3ULL + 0xF94075385CEC7390ULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneA, aOperationLaneC, aOperationLaneD, aWorkLaneA, aFireLaneB, aWorkLaneB, aFireLaneD, aWorkLaneC, aFireLaneC
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 7480U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((aIndex + 1363U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 4436U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3430U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 292U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 51U) + RotL64(aCarry, 19U)) ^ (RotL64(aCross, 6U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterH = (aWandererB + RotL64(aCross, 19U)) + 14157904117287696136U;
            aOrbiterG = (((aWandererF + RotL64(aPrevious, 29U)) + RotL64(aCarry, 19U)) + 7369512677371640676U) + aOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 60U)) + RotL64(aCarry, 47U)) + 8411250745902073798U;
            aOrbiterB = (((aWandererI + RotL64(aScatter, 39U)) + RotL64(aCarry, 5U)) + 5002041814539710275U) + aNonceWordI;
            aOrbiterC = (((aWandererH + RotL64(aCross, 51U)) + 9538041410816283124U) + aOrbiterAssignSaltD[((aIndex + 10U)) & S_SALT1]) + aNonceWordK;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 5210700103927513061U) + aNonceWordC;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 7600709399101287982U) ^ aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6777896926889560889U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 2366369466696580499U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 5544575244203019109U) ^ aOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16231219246786333057U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 8710073749110329779U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 15998211310115361630U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15275657696897688955U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 15354357553877376422U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 10657523549259276169U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13695239532898311073U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 10405750198355464768U) + aNonceWordP;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 3465819693133515142U;
            aOrbiterG = RotL64((aOrbiterG * 14678343718277562799U), 3U);
            //
            aIngress = RotL64(aOrbiterF, 37U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterB, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 57U) + RotL64(aOrbiterH, 51U)) + aOrbiterB) + aNonceWordE) + aWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 13U) + aOrbiterG) + RotL64(aOrbiterB, 4U)) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterH, 13U)) + aOrbiterF) + aWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aScatter, 35U) + aOrbiterC) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 21U)) + aNonceWordL);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 22U) + RotL64(aOrbiterC, 21U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + RotL64(aWandererF, 27U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 2
        // ingress from: aWorkLaneA, aOperationLaneC, aFireLaneB
        // ingress directions: aWorkLaneA forward forced, aOperationLaneC forward forced, aFireLaneB forward/backward random
        // cross from: aOperationLaneA, aOperationLaneD, aOperationLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneD backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 8407U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneC[((aIndex + 8303U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 12622U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 16247U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 12270U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 15272U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 19U) + RotL64(aIngress, 3U)) ^ (RotL64(aCross, 35U) ^ RotL64(aPrevious, 50U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterF = ((((aWandererC + RotL64(aPrevious, 37U)) + RotL64(aCarry, 21U)) + 12426357877879529292U) + aOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordD;
            aOrbiterA = (((aWandererG + RotL64(aCross, 29U)) + RotL64(aCarry, 37U)) + 12604900366173639176U) + aNonceWordK;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 6U)) + RotL64(aCarry, 3U)) + 13511119007338929401U;
            aOrbiterD = (((aWandererB + RotL64(aScatter, 53U)) + 9878720081166788060U) + aOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1]) + aNonceWordN;
            aOrbiterC = ((aWandererA + RotL64(aCross, 19U)) + 15463195409806395076U) + aNonceWordC;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 6407922778852833423U) + aOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 7690427254160734016U) ^ aNonceWordP;
            aOrbiterG = RotL64((aOrbiterG * 11841396512731990295U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 18030974031722143619U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 17983938038322737041U;
            aOrbiterC = RotL64((aOrbiterC * 12479365337221685413U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 16605512170117753884U) + aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = (((aOrbiterD ^ aOrbiterA) ^ 681802273302348322U) ^ aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterD = RotL64((aOrbiterD * 14608920184802647123U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 15550312921312083819U) + aNonceWordO;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 17824154101711884508U;
            aOrbiterA = RotL64((aOrbiterA * 7358612830654795357U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 1939207786756735430U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 3132864634777826569U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13606281919426730325U), 39U);
            //
            aIngress = RotL64(aOrbiterA, 3U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterC, 14U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((((RotL64(aPrevious, 13U) + RotL64(aOrbiterC, 27U)) + aOrbiterF) + RotL64(aCarry, 11U)) + aNonceWordL) + aWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterG, 3U)) + aOrbiterD) + aNonceWordB);
            aWandererG = aWandererG + ((((RotL64(aCross, 39U) + aOrbiterA) + RotL64(aOrbiterF, 41U)) + RotL64(aCarry, 51U)) + aNonceWordE);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 5U) + aOrbiterD) + RotL64(aOrbiterF, 19U)) + aWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 54U) + RotL64(aOrbiterC, 52U)) + aOrbiterD) + aNonceWordA);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 56U));
            aCarry = aCarry + RotL64(aWandererA, 19U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 3
        // ingress from: aWorkLaneB, aOperationLaneD, aFireLaneD
        // ingress directions: aWorkLaneB forward forced, aOperationLaneD forward forced, aFireLaneD forward/backward random
        // cross from: aWorkLaneA, aOperationLaneB, aOperationLaneC
        // cross directions: aWorkLaneA backward forced, aOperationLaneB backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 19250U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneD[((aIndex + 18149U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 20054U)) & S_BLOCK1], 24U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19192U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 20135U)) & S_BLOCK1], 28U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 24133U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 6U)) + (RotL64(aIngress, 27U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterI = ((((aWandererG + RotL64(aPrevious, 39U)) + RotL64(aCarry, 35U)) + 4752759164691497960U) + aOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordG;
            aOrbiterB = ((aWandererB + RotL64(aCross, 29U)) + 12088872623537639782U) + aNonceWordD;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 3U)) + RotL64(aCarry, 51U)) + 3734943577379734227U;
            aOrbiterA = (((aWandererA + RotL64(aScatter, 18U)) + RotL64(aCarry, 5U)) + 8854778183012444234U) + aNonceWordB;
            aOrbiterJ = (((aWandererF + RotL64(aPrevious, 51U)) + 16948373492893967275U) + aOrbiterAssignSaltE[((aIndex + 24U)) & S_SALT1]) + aNonceWordL;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 7962415690046184385U) + aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 1872682375669714454U;
            aOrbiterE = RotL64((aOrbiterE * 959061892772099785U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 7776801806943853566U) + aNonceWordE;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 16665439117257230732U;
            aOrbiterI = RotL64((aOrbiterI * 6866375628213114965U), 51U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterE) + 11088186766134265676U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 10850237991780969350U;
            aOrbiterA = RotL64((aOrbiterA * 7547414856143095121U), 29U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterI) + 6464817712131305812U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordK;
            aOrbiterB = (((aOrbiterB ^ aOrbiterJ) ^ 244557182884209844U) ^ aOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 2394270354887582889U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 13261563971157415841U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 2323811103717827362U;
            aOrbiterJ = RotL64((aOrbiterJ * 11483723582415081925U), 11U);
            //
            aIngress = RotL64(aOrbiterA, 47U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterJ, 60U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 39U) + aOrbiterA) + RotL64(aOrbiterE, 47U)) + aNonceWordC) + aWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 5U)) + aWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterJ, 37U)) + aNonceWordF);
            aWandererA = aWandererA + ((((RotL64(aCross, 6U) + RotL64(aOrbiterE, 13U)) + aOrbiterB) + RotL64(aCarry, 43U)) + aNonceWordI);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterJ, 22U)) + aNonceWordO);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aFireLaneC
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aFireLaneC forward/backward random
        // cross from: aWorkLaneB, aOperationLaneC, aOperationLaneD, aOperationLaneA
        // cross directions: aWorkLaneB backward forced, aOperationLaneC backward forced, aOperationLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 25545U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((aIndex + 30361U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 28455U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29180U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 28112U)) & S_BLOCK1], 3U));
            aCross ^= (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 24913U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31618U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 29U) ^ RotL64(aIngress, 43U)) + (RotL64(aPrevious, 60U) ^ RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 51U)) + 7651355040951791298U;
            aOrbiterG = (((aWandererE + RotL64(aCross, 37U)) + RotL64(aCarry, 5U)) + 13988210277931659312U) + aNonceWordB;
            aOrbiterC = (aWandererA + RotL64(aPrevious, 27U)) + 9846849412579537783U;
            aOrbiterI = ((((aWandererB + RotL64(aIngress, 60U)) + RotL64(aCarry, 51U)) + 12746719939495876158U) + aOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1]) + aNonceWordI;
            aOrbiterE = (((aWandererK + RotL64(aPrevious, 11U)) + RotL64(aCarry, 23U)) + 11498066185182895284U) + aOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 11101058955193080232U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 15513734459555672046U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6974281215677538561U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 15711108675349394643U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 4771231759949468556U;
            aOrbiterJ = RotL64((aOrbiterJ * 9806191054594333615U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 11449258010811305256U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterC) ^ 17036938391509986723U) ^ aOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 7411466953205347639U), 3U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterC) + 6999245666776654250U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 2106819066263369528U;
            aOrbiterI = RotL64((aOrbiterI * 13005885810757743129U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 12716183358903477216U) + aNonceWordC;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 16752724547046059889U) ^ aNonceWordP;
            aOrbiterG = RotL64((aOrbiterG * 11475905692393034141U), 47U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 13U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 37U));
            aIngress = aIngress + RotL64(aOrbiterG, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterC, 35U)) + aOrbiterG) + aWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA + (((((RotL64(aPrevious, 21U) + aOrbiterG) + RotL64(aOrbiterJ, 44U)) + RotL64(aCarry, 35U)) + aNonceWordA) + aWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterC, 57U)) + aOrbiterE) + aNonceWordN);
            aWandererK = aWandererK + ((((RotL64(aCross, 37U) + aOrbiterC) + RotL64(aOrbiterI, 11U)) + RotL64(aCarry, 51U)) + aNonceWordH);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterI, 3U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererE, 43U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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

void TwistExpander_FootBall_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x953D92398C9408C9ULL + 0x9942F78D5F73B00BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xAC2C598A190DB1A3ULL + 0x8DE945627026C692ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x987A2F7B73A153F7ULL + 0xBDCEB39129CA3C25ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x8D341630BB79C149ULL + 0xE0029D2984270048ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xF855CC6CAC20ADE3ULL + 0x80B53E5B02EEA6B7ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x847075CFBFA8CFEBULL + 0x9EC269F2F1C25BCCULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xED7228C71D730111ULL + 0xA2E2036159602071ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x8E999295DFACE50DULL + 0xBF2B0EE9650896A0ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xA98ED767B8506053ULL + 0xA522EF651956F2B5ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xF822B028661E349FULL + 0xA48C4EDABE066510ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x8D270226035C7C89ULL + 0xBA9AC18D3658193CULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xDC8A991A3447C8E3ULL + 0xD9CFDE538CAC88DAULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xC52699105BE85B67ULL + 0xFDA1E44738D6C35CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xB70342C5CF883E01ULL + 0xAB8DB47B5D9D374CULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xC9EC837C5691E52FULL + 0x90949F674EB6CD81ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x84EB68BEA879717BULL + 0xDAF7FE257804C5CAULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aOperationLaneB, aExpandLaneC, aExpandLaneD, aOperationLaneA, aWorkLaneA, aOperationLaneD, aFireLaneA, aWorkLaneB, aOperationLaneC, aFireLaneC, aWorkLaneC, aFireLaneD, aFireLaneB
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_d loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aOperationLaneB
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aOperationLaneB forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aOperationLaneA
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 1793U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((aIndex + 7989U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 918U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5842U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 5135U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aIngress, 57U)) + (RotL64(aCross, 43U) ^ RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterA = ((aWandererK + RotL64(aScatter, 5U)) + RotL64(aCarry, 13U)) + 4848316479321533394U;
            aOrbiterB = ((aWandererI + RotL64(aCross, 41U)) + RotL64(aCarry, 27U)) + 6919360256662636195U;
            aOrbiterF = (aWandererA + RotL64(aPrevious, 19U)) + 9897013582181108544U;
            aOrbiterK = (((aWandererB + RotL64(aIngress, 35U)) + RotL64(aCarry, 43U)) + 7319353809896158678U) + aNonceWordF;
            aOrbiterH = (((aWandererE + RotL64(aPrevious, 13U)) + 2848175435514849859U) + aOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterE = (aWandererC + RotL64(aScatter, 29U)) + 6967780718720437934U;
            aOrbiterC = ((aWandererH + RotL64(aCross, 50U)) + 10143884766603388136U) + aOrbiterAssignSaltD[((aIndex + 16U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 8675965006150972051U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 16350117755560994281U;
            aOrbiterF = RotL64((aOrbiterF * 15072308930382994425U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 17976597517118423760U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 1399631141355370237U;
            aOrbiterH = RotL64((aOrbiterH * 16537788276543236833U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 3590613762034716792U) + aNonceWordD;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 5134624314245932157U;
            aOrbiterB = RotL64((aOrbiterB * 13077589037975283371U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 10082236952942943654U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 4015535035905433450U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4961808568701908559U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 611474103801573800U) + aNonceWordE;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 5786708483794098001U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7694007039340089267U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 5201943497363274455U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 9282160506938328489U) ^ aOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5368182164239021367U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 4932320527498940158U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 11576526341731392916U;
            aOrbiterC = RotL64((aOrbiterC * 1712051774729439363U), 57U);
            //
            aIngress = RotL64(aOrbiterC, 27U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + RotL64(aOrbiterE, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterH, 5U)) + RotL64(aCarry, 51U)) + aWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterE, 53U)) + aNonceWordA);
            aWandererA = aWandererA + ((((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterH, 35U)) + aNonceWordH) + aWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 47U) + aOrbiterA) + RotL64(aOrbiterK, 27U));
            aWandererB = aWandererB + (((RotL64(aIngress, 53U) + RotL64(aOrbiterK, 47U)) + aOrbiterF) + RotL64(aCarry, 27U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 13U) + aOrbiterF) + RotL64(aOrbiterE, 14U));
            aWandererK = aWandererK + (((RotL64(aScatter, 4U) + RotL64(aOrbiterB, 41U)) + aOrbiterA) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 58U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererK, 27U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 2
        // ingress from: aWorkLaneA, aExpandLaneC, aOperationLaneD
        // ingress directions: aWorkLaneA forward forced, aExpandLaneC forward forced, aOperationLaneD forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aFireLaneA
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aFireLaneA backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 8727U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneC[((aIndex + 12694U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 15080U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 12175U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14441U)) & S_BLOCK1], 22U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 10738U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 57U)) + (RotL64(aCross, 5U) + RotL64(aIngress, 18U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterB = ((aWandererB + RotL64(aScatter, 14U)) + RotL64(aCarry, 19U)) + 5573188770530340913U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 5U)) + 1431772230889897111U) + aOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = ((((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 41U)) + 4809192776429682319U) + aOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordA;
            aOrbiterA = (((aWandererD + RotL64(aPrevious, 39U)) + RotL64(aCarry, 53U)) + 5576603692574369341U) + aNonceWordK;
            aOrbiterH = (aWandererA + RotL64(aScatter, 21U)) + 2720143226007220386U;
            aOrbiterG = ((aWandererG + RotL64(aCross, 27U)) + 17220328778565331629U) + aNonceWordF;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 51U)) + 9629485808442089423U) + aNonceWordN;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 1136998437010390983U) + aNonceWordP;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 11893390497814523841U) ^ aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5329621622743089531U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 1764986431917532370U) + aOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 1741014798007010376U;
            aOrbiterH = RotL64((aOrbiterH * 13414914086049500731U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 12221368453236547044U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 7694538641172350430U;
            aOrbiterA = RotL64((aOrbiterA * 8439120733670016501U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 17472344518811560603U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 3308740700728172984U;
            aOrbiterI = RotL64((aOrbiterI * 15290400462887712083U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 9535358833412446771U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 11192312491731312451U) ^ aOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17405609148475445743U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 14850451970047190039U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 11932493299452443256U;
            aOrbiterG = RotL64((aOrbiterG * 7964808728820467795U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 5972619895614731870U) + aNonceWordD;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 17174497535809891690U;
            aOrbiterB = RotL64((aOrbiterB * 15471084511364572533U), 29U);
            //
            aIngress = RotL64(aOrbiterF, 13U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterB, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 21U)) + aOrbiterA);
            aWandererD = aWandererD ^ ((((RotL64(aCross, 11U) + aOrbiterG) + RotL64(aOrbiterE, 43U)) + aNonceWordM) + aWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterH, 5U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 60U) + aOrbiterG) + RotL64(aOrbiterA, 29U)) + aWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aCross, 23U) + aOrbiterI) + RotL64(aOrbiterE, 13U)) + RotL64(aCarry, 43U)) + aNonceWordE);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 37U) + aOrbiterB) + RotL64(aOrbiterF, 35U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterF, 54U)) + aOrbiterH) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 56U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 3
        // ingress from: aWorkLaneB, aExpandLaneD, aOperationLaneC
        // ingress directions: aWorkLaneB forward forced, aExpandLaneD forward forced, aOperationLaneC forward/backward random
        // cross from: aWorkLaneA, aExpandLaneB, aFireLaneC
        // cross directions: aWorkLaneA backward forced, aExpandLaneB backward forced, aFireLaneC backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 16556U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((aIndex + 20980U)) & S_BLOCK1], 36U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 16822U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17775U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 16668U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 16790U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 41U) + RotL64(aPrevious, 20U)) ^ (RotL64(aCross, 57U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterH = ((((aWandererB + RotL64(aScatter, 11U)) + RotL64(aCarry, 43U)) + 15045917390223766480U) + aOrbiterAssignSaltA[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordK;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 19U)) + RotL64(aCarry, 57U)) + 10763054007033668758U;
            aOrbiterJ = (((aWandererH + RotL64(aCross, 51U)) + RotL64(aCarry, 23U)) + 13190170142593666607U) + aOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 57U)) + 9657025731441167065U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 26U)) + 11433367178975954211U) + aNonceWordF;
            aOrbiterG = (aWandererA + RotL64(aPrevious, 37U)) + 17904920143996810366U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 43U)) + 3244383020512113283U) + aNonceWordI;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 6538815775171139091U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 7195368312757976343U) ^ aNonceWordP;
            aOrbiterJ = RotL64((aOrbiterJ * 10515679176134176565U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 18134430713910279374U) + aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = (((aOrbiterG ^ aOrbiterA) ^ 6571776588427107976U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterG = RotL64((aOrbiterG * 11916502085252589161U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 11830778129647517758U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 9793702760907767365U) ^ aNonceWordA;
            aOrbiterE = RotL64((aOrbiterE * 4096246227968677179U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 2287235876793192036U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 8951959188326141794U;
            aOrbiterH = RotL64((aOrbiterH * 9968356718110753845U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 7583061790273240157U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 3571364625022806085U) ^ aOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6238360922735480669U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 13869345563551689212U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 277480328952975002U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1057564597096163085U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 4983735092494677578U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 9490022869381030928U;
            aOrbiterC = RotL64((aOrbiterC * 12926352917961703123U), 53U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 43U);
            aIngress = aIngress + (RotL64(aOrbiterE, 37U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterK, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterJ, 39U)) + aNonceWordL);
            aWandererH = aWandererH + (((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 11U)) + aOrbiterG) + RotL64(aCarry, 35U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 44U) + aOrbiterA) + RotL64(aOrbiterK, 27U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterC, 21U)) + aOrbiterK) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterK, 47U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterK, 58U)) + aOrbiterJ) + aWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 53U) + RotL64(aOrbiterE, 3U)) + aOrbiterJ) + aNonceWordO) + aWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 4U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + RotL64(aWandererG, 51U);
            aCarry = aCarry + RotL64(aIngress, 24U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aFireLaneD
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aFireLaneD forward/backward random
        // cross from: aWorkLaneB, aExpandLaneC, aFireLaneB
        // cross directions: aWorkLaneB backward forced, aExpandLaneC backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 28220U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneA[((aIndex + 29446U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 27875U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28973U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 28778U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 27028U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aPrevious, 52U)) + (RotL64(aIngress, 21U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 5U)) + 18180797995100240808U) + aNonceWordP;
            aOrbiterE = (aWandererC + RotL64(aCross, 37U)) + 6585906608223552885U;
            aOrbiterD = (((aWandererA + RotL64(aPrevious, 29U)) + RotL64(aCarry, 41U)) + 14088708930575939855U) + aOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aIngress, 23U)) + 468974153311516044U;
            aOrbiterG = (((aWandererI + RotL64(aCross, 58U)) + RotL64(aCarry, 21U)) + 12481951025619894110U) + aNonceWordI;
            aOrbiterH = (((aWandererE + RotL64(aIngress, 47U)) + RotL64(aCarry, 5U)) + 17227987923860711763U) + aOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aScatter, 13U)) + 4373962756657477139U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 2077576476565420951U) + aNonceWordH;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 17435011300234663764U;
            aOrbiterD = RotL64((aOrbiterD * 8910133867294004711U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 4118039398293246896U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 13724716599855216683U;
            aOrbiterE = RotL64((aOrbiterE * 17556333902751079677U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 12391461204689596339U) + aOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 9900605191533799627U;
            aOrbiterB = RotL64((aOrbiterB * 13553565332531046301U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 972946858824366125U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 17247681919694541215U;
            aOrbiterA = RotL64((aOrbiterA * 2974639094630445643U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 15442851427306771601U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 7303586227288294037U) ^ aOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15406402525021428799U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 12650358753454105119U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 1483710933373510492U;
            aOrbiterH = RotL64((aOrbiterH * 6531763256577221891U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 18065810162229740788U) + aNonceWordK;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 11311677121338794007U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15116367961682119467U), 47U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 29U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 60U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterJ, 19U)) + aOrbiterE);
            aWandererK = aWandererK + ((((RotL64(aScatter, 58U) + RotL64(aOrbiterJ, 43U)) + aOrbiterA) + RotL64(aCarry, 27U)) + aNonceWordF);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterB, 3U)) + aOrbiterG);
            aWandererF = aWandererF + (((RotL64(aPrevious, 11U) + aOrbiterD) + RotL64(aOrbiterJ, 51U)) + aWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 37U) + aOrbiterE) + RotL64(aOrbiterG, 13U)) + aNonceWordJ);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 37U)) + aOrbiterH) + RotL64(aCarry, 11U)) + aWandererUpdateSaltE[((aIndex + 22U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 43U) + aOrbiterB) + RotL64(aOrbiterD, 28U)) + aNonceWordE);
            //
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 34U));
            aCarry = aCarry + RotL64(aWandererK, 39U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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

void TwistExpander_FootBall_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x889824256219BC5DULL + 0xABA0C2DB374E0652ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xC32946D89D11BB59ULL + 0xF712DE330569781FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xA88899A14F31E85BULL + 0xC762BD4EE38A3C2EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xCFA652171629ADD7ULL + 0xF2C746588E3B251EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xAF645EC17CA63DF9ULL + 0x90D82EDC2A7AD86CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xBEC13DD8F3C780F9ULL + 0x9DF2ED1DACD1DF37ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xEDC3A48694E0616BULL + 0xE978DBEDDD573808ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xC636EBDDE45612D7ULL + 0xD625D903728AE0F2ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xA03DE7EA9BB24F0BULL + 0xB4E1B58D43B1C94CULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xCC66DC5BEE1080D1ULL + 0xC910FB1AF890DDC0ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xBEDE5648F5AAE28BULL + 0xE6239B2895E2E760ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xEB3015DC1BF3CA15ULL + 0xE915CCF495EAEC0DULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xC6452FD7477F5C79ULL + 0xB14740853104B70FULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x879E491860D493DBULL + 0xE98262D7C155AE8FULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x94E1F5E57713C0F7ULL + 0xF52263AE135E13A6ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xB50A7913F9AA4F23ULL + 0x80242E099765E080ULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aOperationLaneC, aWorkLaneC, aWorkLaneD, aFireLaneC, aExpandLaneA, aOperationLaneB, aFireLaneA, aExpandLaneB, aFireLaneD, aOperationLaneA, aExpandLaneC, aFireLaneB, aOperationLaneD
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_a loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aOperationLaneC
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aOperationLaneC forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aFireLaneC
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aFireLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 1368U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((aIndex + 2677U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 672U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 3773U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 5300U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 4329U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 14U)) + (RotL64(aPrevious, 27U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterF = ((aWandererF + RotL64(aCross, 3U)) + 10404808878585437255U) + aNonceWordE;
            aOrbiterC = (((aWandererH + RotL64(aPrevious, 47U)) + RotL64(aCarry, 39U)) + 10587858736301591439U) + aNonceWordG;
            aOrbiterG = ((((aWandererB + RotL64(aScatter, 19U)) + RotL64(aCarry, 57U)) + 1430530909801644435U) + aOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1]) + aNonceWordH;
            aOrbiterA = (((aWandererJ + RotL64(aIngress, 13U)) + 9090938022430118902U) + aOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1]) + aNonceWordA;
            aOrbiterK = (aWandererE + RotL64(aPrevious, 58U)) + 12936604311751121235U;
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 41U)) + RotL64(aCarry, 5U)) + 1000583006020232032U;
            aOrbiterD = (aWandererC + RotL64(aScatter, 29U)) + 12352532088997042232U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 16723410947058502564U) + aNonceWordK;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 16614089235313154270U) ^ aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11530998303573027827U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 4245553025593349277U) + aNonceWordP;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 3353146318549477494U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14246377408238318091U), 27U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterJ) + 5935727336135635196U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordM;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 10312187090293319667U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1395964500396711899U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 12192843181244744484U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 2542570124502586365U;
            aOrbiterK = RotL64((aOrbiterK * 17222847847573534963U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 3315472769469002444U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 17512858811783071174U;
            aOrbiterD = RotL64((aOrbiterD * 9070400454074283765U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 16633218007427888082U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 2502077714838858460U;
            aOrbiterF = RotL64((aOrbiterF * 970762420815997725U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 14792910273226469214U) + aNonceWordL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 15739513291150783151U;
            aOrbiterJ = RotL64((aOrbiterJ * 11896279674116906915U), 35U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterK, 58U);
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterG, 41U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aPrevious, 41U) + aOrbiterF) + RotL64(aOrbiterA, 21U));
            aWandererE = aWandererE ^ ((((RotL64(aScatter, 21U) + RotL64(aOrbiterG, 51U)) + aOrbiterK) + aNonceWordJ) + aWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterA, 44U)) + aNonceWordF);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterJ, 27U)) + aOrbiterF);
            aWandererC = aWandererC + ((((RotL64(aCross, 57U) + RotL64(aOrbiterC, 13U)) + aOrbiterF) + RotL64(aCarry, 51U)) + aWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 34U) + RotL64(aOrbiterA, 5U)) + aOrbiterK);
            aWandererH = aWandererH + (((RotL64(aIngress, 3U) + RotL64(aOrbiterA, 57U)) + aOrbiterG) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 26U));
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + RotL64(aWandererJ, 41U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aOperationLaneB
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aOperationLaneB forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aFireLaneA
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aFireLaneA backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 13242U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneC[((aIndex + 11330U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 9798U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10869U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8558U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 8511U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 43U) + RotL64(aPrevious, 57U)) ^ (RotL64(aIngress, 11U) ^ RotL64(aCross, 30U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterG = (aWandererF + RotL64(aScatter, 43U)) + 14823268998003220191U;
            aOrbiterH = ((((aWandererK + RotL64(aPrevious, 60U)) + RotL64(aCarry, 5U)) + 15295237288788213847U) + aOrbiterAssignSaltC[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterC = ((((aWandererI + RotL64(aIngress, 35U)) + RotL64(aCarry, 39U)) + 16434853402001133899U) + aOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordK;
            aOrbiterF = ((aWandererH + RotL64(aCross, 51U)) + RotL64(aCarry, 53U)) + 7555911304407871631U;
            aOrbiterE = (aWandererD + RotL64(aScatter, 5U)) + 14977248264994834620U;
            aOrbiterK = (aWandererB + RotL64(aIngress, 29U)) + 9707764144919392380U;
            aOrbiterB = (aWandererC + RotL64(aCross, 11U)) + 1277304385464681529U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 3089786220465849395U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 3700503853358695085U;
            aOrbiterC = RotL64((aOrbiterC * 2079089949442685421U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 3240054112993517371U) + aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 16897532076915366859U;
            aOrbiterH = RotL64((aOrbiterH * 4120874717534309035U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 18167359289798364307U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 8870819278575769863U) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 9334066154398059075U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 15363069206212330251U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 14858164441499725158U;
            aOrbiterB = RotL64((aOrbiterB * 14931933411393847915U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 5357144808788707522U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 2910681277417754860U) ^ aNonceWordI;
            aOrbiterK = RotL64((aOrbiterK * 13170868582159347059U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 9824408699018165151U) + aNonceWordC;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 368370224788793300U;
            aOrbiterG = RotL64((aOrbiterG * 14358982366258729959U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 7095398304588825115U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 11418879758164313554U) ^ aOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5983520332639771791U), 27U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterG, 53U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterE, 29U)) + aNonceWordH) + aWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 21U) + aOrbiterF) + RotL64(aOrbiterB, 43U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterK, 13U)) + aOrbiterH);
            aWandererF = aWandererF + (((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterC, 4U)) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterG, 37U)) + aOrbiterE);
            aWandererI = aWandererI + (((((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 53U)) + aOrbiterG) + RotL64(aCarry, 21U)) + aNonceWordE) + aWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 37U) + aOrbiterC) + RotL64(aOrbiterB, 19U)) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererD, 26U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aFireLaneD
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aOperationLaneA
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aOperationLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 18489U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneD[((aIndex + 16458U)) & S_BLOCK1], 14U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 19666U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 17530U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19150U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aOperationLaneA[((aIndex + 19947U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCross, 39U)) + (RotL64(aPrevious, 57U) + RotL64(aCarry, 26U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterC = (((aWandererI + RotL64(aPrevious, 5U)) + 12029393034357490020U) + aOrbiterAssignSaltF[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordF;
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 57U)) + RotL64(aCarry, 35U)) + 4526754731580694987U;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 47U)) + 17060419646421271853U) + aOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = (((aWandererG + RotL64(aCross, 13U)) + RotL64(aCarry, 21U)) + 4128488893837059683U) + aNonceWordD;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 20U)) + 12706894827547160110U) + aNonceWordE;
            aOrbiterD = ((aWandererF + RotL64(aCross, 27U)) + 12506324593645825056U) + aNonceWordN;
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 39U)) + RotL64(aCarry, 53U)) + 12581344490649250025U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 14357032418199130132U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 15341977701796331249U) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 6332369248718076031U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 7086602307544733241U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 12398300065276832486U;
            aOrbiterD = RotL64((aOrbiterD * 18157408831225635333U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 2499745046076601988U) + aOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 7249361592814001829U;
            aOrbiterA = RotL64((aOrbiterA * 14597139848072319685U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 3254456186337366437U) + aNonceWordH;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 3472973415969046680U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14583566953969168353U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 7905718972111691591U) + aNonceWordB;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 15941413652144021522U;
            aOrbiterH = RotL64((aOrbiterH * 3473779492962783565U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 10583964125960308762U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 13659925272340853715U) ^ aOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16708294803316630743U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 9487054537489454887U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 13287757570441887517U;
            aOrbiterC = RotL64((aOrbiterC * 17351439045329892107U), 23U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterF, 60U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 12U) + aOrbiterH) + RotL64(aOrbiterC, 53U)) + aNonceWordG) + aWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 21U)) + aNonceWordA);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 35U)) + aOrbiterB) + aWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 5U) + RotL64(aOrbiterD, 3U)) + aOrbiterJ) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterF, 44U)) + aOrbiterJ) + aNonceWordI);
            aWandererI = aWandererI + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterH, 11U)) + aOrbiterF);
            aWandererD = aWandererD ^ (((RotL64(aCross, 43U) + aOrbiterC) + RotL64(aOrbiterD, 21U)) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 22U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 39U);
            aCarry = aCarry + RotL64(aIngress, 34U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneB
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aOperationLaneD
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 29796U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((aIndex + 27902U)) & S_BLOCK1], 22U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 30732U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27795U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 28411U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 31551U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCarry, 54U)) ^ (RotL64(aCross, 23U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 34U)) + RotL64(aCarry, 47U)) + 6521330037475130256U;
            aOrbiterA = (((aWandererB + RotL64(aIngress, 41U)) + RotL64(aCarry, 21U)) + 12611880456055428940U) + aOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = ((aWandererI + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 12061611078130934708U;
            aOrbiterG = ((aWandererH + RotL64(aCross, 47U)) + 1558112410801116984U) + aNonceWordN;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 11U)) + 10509115227850160786U) + aNonceWordP;
            aOrbiterD = ((aWandererC + RotL64(aCross, 53U)) + 4045915960688792066U) + aNonceWordM;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 27U)) + 1196541286513243082U) + aOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1];
            //
            aOrbiterF = (((aOrbiterF + aOrbiterA) + 15564991032722373702U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordE;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 4897765238703641798U;
            aOrbiterH = RotL64((aOrbiterH * 9693901276712946763U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 12327429514907752733U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 6189189797708711636U;
            aOrbiterG = RotL64((aOrbiterG * 9017615866338877651U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 6374267075282018852U) + aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 1888758503831341439U) ^ aOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 74387714918264257U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 14956857689299491800U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 14879361107223331957U;
            aOrbiterA = RotL64((aOrbiterA * 9166712966729591953U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 16086885494838105042U) + aNonceWordH;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 8069724185844303923U;
            aOrbiterI = RotL64((aOrbiterI * 8878470736758734353U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 10854345917959911439U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 7078313614360332089U;
            aOrbiterF = RotL64((aOrbiterF * 9864025732292844871U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 15083669236062255011U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 594879695916679116U;
            aOrbiterE = RotL64((aOrbiterE * 9852515479152735283U), 41U);
            //
            aIngress = RotL64(aOrbiterD, 41U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterD, 54U)) + aOrbiterI) + aWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aIngress, 29U) + aOrbiterD) + RotL64(aOrbiterE, 27U)) + RotL64(aCarry, 5U)) + aNonceWordG);
            aWandererF = aWandererF ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterA, 35U)) + aOrbiterF);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 43U)) + aOrbiterH);
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 54U) + RotL64(aOrbiterF, 11U)) + aOrbiterG) + aNonceWordA) + aWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aScatter, 11U) + aOrbiterH) + RotL64(aOrbiterG, 21U)) + RotL64(aCarry, 53U)) + aNonceWordK);
            aWandererI = aWandererI ^ (((RotL64(aCross, 41U) + aOrbiterD) + RotL64(aOrbiterG, 3U)) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererC, 36U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 10U);
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

void TwistExpander_FootBall_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xA38165FA71DE9CD9ULL + 0x84D30CEE6303D7D3ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xF0E1AD30B51A8AADULL + 0xF035CB98FE24AD26ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC3FC3FDA5BEA960BULL + 0xF5F39F4D5F925790ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x95AC7A6E61B1AAB1ULL + 0xD8E97A384F6A9097ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xCD22C7352640EBA9ULL + 0xED471B6CB219DC08ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xE32FA0E8762F562DULL + 0x83807AF7EE643946ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x8515B7DAF554331DULL + 0x92166E1CFAEF5DA8ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xED908C9272352BF7ULL + 0xE16375DDACE0B35AULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x933D67F0ADAB7C53ULL + 0xF40A49B203FC135FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xE4A6EF31771A38EFULL + 0xA5FEBD2C2686A026ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xEA991CA4FA020F43ULL + 0x84DA77E803D77558ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xBE41BBD7C2CEA4F9ULL + 0xBEF2D9F28BBD77F6ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xFBB11716A3ED8F71ULL + 0xD28EEA539D290A57ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xCC08626A3E76E82BULL + 0xF63A11560E79198DULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xDA2E07B871CA7355ULL + 0xB7316957A60A617FULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xB8FE95FA6E7CF0D3ULL + 0xC24E2829BD355051ULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneA, aExpandLaneC, aExpandLaneD, aWorkLaneD, aOperationLaneA, aFireLaneC, aWorkLaneB, aOperationLaneB, aFireLaneD, aWorkLaneC, aOperationLaneC, aWorkLaneA, aFireLaneB
        // write to: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // kdf_b_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aWorkLaneD
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aWorkLaneD backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 4396U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneB[((aIndex + 384U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 2333U)) & S_BLOCK1], 28U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 610U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3759U)) & S_BLOCK1], 4U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 3236U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aPrevious, 6U)) + (RotL64(aCarry, 41U) ^ RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterF = ((aWandererH + RotL64(aScatter, 60U)) + RotL64(aCarry, 41U)) + 13204735390996728477U;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 47U)) + 851171359595647173U;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 3U)) + 16745304202825290723U) + aOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = (aWandererB + RotL64(aCross, 39U)) + 562392736584913979U;
            aOrbiterK = (((aWandererK + RotL64(aPrevious, 29U)) + RotL64(aCarry, 53U)) + 3244267012529053918U) + aNonceWordN;
            aOrbiterD = (aWandererG + RotL64(aIngress, 43U)) + 17282536111067869133U;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 27U)) + 14851130066471729068U) + aOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = (((aWandererJ + RotL64(aCross, 34U)) + RotL64(aCarry, 5U)) + 5256130407952363129U) + aNonceWordK;
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 5U)) + 2904742485828362001U;
            aOrbiterH = ((aWandererF + RotL64(aCross, 53U)) + 3723346325449225387U) + aNonceWordF;
            aOrbiterB = (aWandererI + RotL64(aIngress, 19U)) + 5344621093694027341U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 12919263300833603026U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 17989801264160996071U;
            aOrbiterE = RotL64((aOrbiterE * 15468293047311883751U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 5022175042377172157U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 16684822380107847758U;
            aOrbiterD = RotL64((aOrbiterD * 2834049270263837537U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 2740326510600876682U) + aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 13981423865219318820U;
            aOrbiterA = RotL64((aOrbiterA * 14593082145080056441U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 231945878229848395U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 14139797734944312580U) ^ aOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6492256080432266407U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 16704102101387552373U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 8506734780526852552U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4684566118627414659U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 2774630043988894695U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 12490034334296488127U;
            aOrbiterI = RotL64((aOrbiterI * 16765455396278233145U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 545238171291436006U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterB) ^ 1023872898002379590U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 8626333831510136515U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 5065187021047872560U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 10391809965648089863U) ^ aNonceWordO;
            aOrbiterB = RotL64((aOrbiterB * 10912471108849550469U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 5576919045471579002U) + aNonceWordP;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 9761904001375034639U) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 8612901811320541361U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 2001472279505185946U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 11576457012366242134U;
            aOrbiterH = RotL64((aOrbiterH * 1070815118051466731U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 17713147845216099336U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 13204735390996728477U;
            aOrbiterK = RotL64((aOrbiterK * 10889281795183444943U), 13U);
            //
            aIngress = RotL64(aOrbiterD, 3U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + (RotL64(aOrbiterF, 60U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterA, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterK, 3U));
            aWandererA = aWandererA + ((((RotL64(aCross, 19U) + RotL64(aOrbiterF, 51U)) + aOrbiterC) + RotL64(aCarry, 13U)) + aNonceWordD);
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 47U)) + aOrbiterD) + aNonceWordJ) + aWandererUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 38U) + RotL64(aOrbiterA, 29U)) + aOrbiterC) + RotL64(aCarry, 23U)) + aNonceWordG);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 12U)) + aOrbiterJ);
            aWandererC = aWandererC + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterB, 41U)) + aOrbiterI);
            aWandererH = aWandererH ^ ((RotL64(aCross, 41U) + aOrbiterA) + RotL64(aOrbiterD, 37U));
            aWandererF = aWandererF + ((RotL64(aIngress, 6U) + aOrbiterF) + RotL64(aOrbiterI, 39U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 57U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterH, 35U)) + aOrbiterK) + aWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterG, 10U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererF, 36U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 50U));
            aCarry = aCarry + RotL64(aWandererB, 21U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 2
        // ingress from: aOperationLaneA, aExpandLaneC, aFireLaneC
        // ingress directions: aOperationLaneA forward forced, aExpandLaneC forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aWorkLaneB
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aWorkLaneB backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 16077U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((aIndex + 12877U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 13471U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 8213U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13071U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 14098U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCarry, 23U)) + (RotL64(aPrevious, 11U) + RotL64(aCross, 56U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterE = ((aWandererE + RotL64(aScatter, 56U)) + RotL64(aCarry, 51U)) + 6163290588946759209U;
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 29U)) + 7342672468560105447U;
            aOrbiterH = (aWandererB + RotL64(aCross, 43U)) + 11574563167017282321U;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 3U)) + 2254820206194758964U;
            aOrbiterG = (((aWandererG + RotL64(aPrevious, 37U)) + RotL64(aCarry, 19U)) + 1469783447473099498U) + aOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aIngress, 13U)) + 14174828900676165088U) + aOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = (aWandererC + RotL64(aCross, 18U)) + 16277954291890598132U;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 11U)) + 14845750668693136766U) + aNonceWordG;
            aOrbiterK = (aWandererH + RotL64(aCross, 41U)) + 150099699692047766U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 53U)) + RotL64(aCarry, 43U)) + 1200784917165131703U;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 39U)) + 9469982764806754302U) + aNonceWordP;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 10956702761701710182U) + aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 7915506894975487807U;
            aOrbiterH = RotL64((aOrbiterH * 8874108311712727983U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 17335794183733623213U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 557028996286989506U;
            aOrbiterG = RotL64((aOrbiterG * 3993359298602424281U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 1597385667771002414U) + aOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 4376417959915162639U;
            aOrbiterJ = RotL64((aOrbiterJ * 4626236858205178149U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 549770198518993876U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 756554555648070919U;
            aOrbiterB = RotL64((aOrbiterB * 16272320259614325355U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 7298557532533152193U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 3336802611342112013U;
            aOrbiterC = RotL64((aOrbiterC * 14679103452120080499U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 2314938232094714365U) + aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 12215066333571149153U;
            aOrbiterF = RotL64((aOrbiterF * 10747052773052630601U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 7762752719356805046U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 6519429915769040078U;
            aOrbiterD = RotL64((aOrbiterD * 15548676502167938513U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 7556691736109752918U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 13731245903412646404U;
            aOrbiterI = RotL64((aOrbiterI * 15581965016668635409U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 5910925625723735162U) + aNonceWordF;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 16037704866415841869U) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 11628217027073824759U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 12605882248192797360U) + aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 9579778913978981884U;
            aOrbiterA = RotL64((aOrbiterA * 5372577227818787957U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 6063171520266734946U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 6163290588946759209U;
            aOrbiterE = RotL64((aOrbiterE * 291843698316138251U), 53U);
            //
            aIngress = RotL64(aOrbiterJ, 51U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 46U));
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterK, 51U)) + aOrbiterB);
            aWandererH = aWandererH + (((RotL64(aScatter, 27U) + aOrbiterE) + RotL64(aOrbiterA, 13U)) + aWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 13U) + aOrbiterA) + RotL64(aOrbiterK, 21U));
            aWandererA = aWandererA + (((RotL64(aCross, 43U) + RotL64(aOrbiterD, 53U)) + aOrbiterC) + aWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 5U) + aOrbiterD) + RotL64(aOrbiterJ, 10U));
            aWandererE = aWandererE + (((RotL64(aCross, 41U) + aOrbiterH) + RotL64(aOrbiterD, 19U)) + aNonceWordE);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterA, 47U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 39U) + RotL64(aOrbiterC, 41U)) + aOrbiterG) + RotL64(aCarry, 39U)) + aNonceWordL);
            aWandererI = aWandererI ^ ((RotL64(aCross, 54U) + aOrbiterF) + RotL64(aOrbiterJ, 43U));
            aWandererG = aWandererG + (((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterC, 58U)) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterJ, 35U)) + aOrbiterI) + aNonceWordB);
            //
            aCarry = aCarry + (RotL64(aWandererH, 24U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + (RotL64(aWandererE, 48U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 3
        // ingress from: aOperationLaneB, aExpandLaneD, aFireLaneD
        // ingress directions: aOperationLaneB forward forced, aExpandLaneD forward forced, aFireLaneD forward/backward random
        // cross from: aOperationLaneA, aExpandLaneB, aWorkLaneC
        // cross directions: aOperationLaneA backward forced, aExpandLaneB backward forced, aWorkLaneC backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 23852U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((aIndex + 23838U)) & S_BLOCK1], 60U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 18321U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 21827U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 19551U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 17812U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCross, 38U)) ^ (RotL64(aIngress, 57U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterB = ((aWandererJ + RotL64(aCross, 19U)) + RotL64(aCarry, 41U)) + 9133751643283278896U;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 39U)) + RotL64(aCarry, 27U)) + 8971581804375380408U;
            aOrbiterH = (((aWandererE + RotL64(aScatter, 23U)) + RotL64(aCarry, 5U)) + 12559650383714566592U) + aNonceWordG;
            aOrbiterG = (aWandererA + RotL64(aPrevious, 14U)) + 15753206088872859163U;
            aOrbiterI = (aWandererK + RotL64(aScatter, 53U)) + 7640756270450762350U;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 3U)) + 7340073357551376125U) + aOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 37U)) + 5270256573644196046U) + aNonceWordD;
            aOrbiterK = (aWandererG + RotL64(aCross, 11U)) + 3567367996479995928U;
            aOrbiterC = (((aWandererC + RotL64(aScatter, 29U)) + 11939634537492733738U) + aOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordC;
            aOrbiterF = (aWandererB + RotL64(aIngress, 57U)) + 7051817732424527120U;
            aOrbiterJ = (aWandererF + RotL64(aCross, 46U)) + 1730487669951837941U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 18009252467909454817U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 2361024272031696442U;
            aOrbiterH = RotL64((aOrbiterH * 15215151562500226027U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 15902755877642960397U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 12243517544704116184U) ^ aNonceWordE;
            aOrbiterA = RotL64((aOrbiterA * 2576071074148141447U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 16846181962302186187U) + aOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 636121425116506681U) ^ aNonceWordO;
            aOrbiterE = RotL64((aOrbiterE * 17075030673338779993U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 6887385655828217318U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 3705834550934775862U;
            aOrbiterG = RotL64((aOrbiterG * 11275428284929594435U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 11165142437077969438U) + aOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 6426659930331618269U;
            aOrbiterD = RotL64((aOrbiterD * 17170640810530893705U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 12629082390899315789U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 4277510580069574724U) ^ aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9829125163412708305U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 13814834144170469978U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 3698381854100295826U;
            aOrbiterK = RotL64((aOrbiterK * 5126359230872258015U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 11623170635983579937U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 7247413650388803796U;
            aOrbiterI = RotL64((aOrbiterI * 3403219499465560059U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 3129755194359521145U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 4081016725582134919U;
            aOrbiterJ = RotL64((aOrbiterJ * 11564414998539605389U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 15878346077922215753U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 2974440187796944059U;
            aOrbiterC = RotL64((aOrbiterC * 783253926537018373U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 3922344163443096356U) + aNonceWordB;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 9133751643283278896U) ^ aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16887991698415418429U), 35U);
            //
            aIngress = RotL64(aOrbiterB, 27U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 39U));
            aIngress = aIngress + (RotL64(aOrbiterA, 37U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 42U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 19U) + aOrbiterG) + RotL64(aOrbiterE, 57U));
            aWandererF = aWandererF + ((((RotL64(aCross, 23U) + RotL64(aOrbiterI, 18U)) + aOrbiterC) + RotL64(aCarry, 53U)) + aWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 21U)) + aOrbiterG) + aNonceWordL);
            aWandererB = aWandererB + (((RotL64(aIngress, 58U) + RotL64(aOrbiterF, 11U)) + aOrbiterE) + RotL64(aCarry, 37U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterC, 5U)) + aOrbiterA);
            aWandererE = aWandererE + (((RotL64(aCross, 53U) + RotL64(aOrbiterK, 41U)) + aOrbiterA) + aNonceWordM);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterC, 35U)) + aOrbiterB);
            aWandererA = aWandererA + (((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterB, 26U)) + aWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterB, 43U)) + aOrbiterG) + aNonceWordI);
            aWandererG = aWandererG + ((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterI, 29U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 6U) + RotL64(aOrbiterF, 13U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererI);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 12U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 30U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 4
        // ingress from: aOperationLaneC, aOperationLaneA, aWorkLaneA
        // ingress directions: aOperationLaneC forward forced, aOperationLaneA forward forced, aWorkLaneA forward/backward random
        // cross from: aOperationLaneB, aExpandLaneC, aFireLaneB
        // cross directions: aOperationLaneB backward forced, aExpandLaneC backward forced, aFireLaneB backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 29462U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneA[((aIndex + 26796U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29312U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26851U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 32758U)) & S_BLOCK1], 52U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 27116U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCross, 13U)) ^ (RotL64(aPrevious, 29U) + RotL64(aCarry, 60U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterF = (aWandererD + RotL64(aCross, 43U)) + 964165145848253292U;
            aOrbiterK = ((aWandererI + RotL64(aIngress, 3U)) + 10645976767204934746U) + aNonceWordG;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 13U)) + 8241612229349212650U) + aOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aScatter, 41U)) + 4159196033256913347U;
            aOrbiterC = (aWandererA + RotL64(aCross, 46U)) + 7194795864620233507U;
            aOrbiterI = (((aWandererF + RotL64(aIngress, 51U)) + 7638928444536778384U) + aOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1]) + aNonceWordE;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 29U)) + 11819105916503968109U;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 53U)) + RotL64(aCarry, 39U)) + 18052213302858186237U;
            aOrbiterG = ((aWandererC + RotL64(aCross, 23U)) + RotL64(aCarry, 47U)) + 8663575313970041570U;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 36U)) + 16644136720439299786U;
            aOrbiterE = (((aWandererE + RotL64(aPrevious, 57U)) + RotL64(aCarry, 3U)) + 16930316530442679864U) + aNonceWordO;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 16251107616988250593U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 7171986193609401665U;
            aOrbiterD = RotL64((aOrbiterD * 3543709971414550087U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 17885046834432626644U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 7757069274715713557U;
            aOrbiterC = RotL64((aOrbiterC * 15766885299397923879U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 2212805322061155615U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 6368539134638838822U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13383744883433594259U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 5264326094252925613U) + aNonceWordH;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 6126345334815012938U;
            aOrbiterI = RotL64((aOrbiterI * 17180934809764905307U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 13826731214018407061U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 6621261811613643620U;
            aOrbiterK = RotL64((aOrbiterK * 2823596473596114171U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 5964406317285863781U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 2167324450276308078U) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 1098346374733634905U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 16740710162977859724U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 8236083581048717923U;
            aOrbiterG = RotL64((aOrbiterG * 4364887787000704039U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 13967473987446124012U) + aNonceWordK;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 5136051802217149813U) ^ aOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13997246005108872883U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 5842999397215390366U) + aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 8621394946580065499U;
            aOrbiterH = RotL64((aOrbiterH * 11658023035736362355U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 18086875424872976900U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 7429246355923896047U;
            aOrbiterA = RotL64((aOrbiterA * 5077079237334961761U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 18123753993386959014U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 964165145848253292U;
            aOrbiterJ = RotL64((aOrbiterJ * 3178072569980307307U), 41U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterI, 30U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterA, 39U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 34U) + aOrbiterA) + RotL64(aOrbiterG, 40U));
            aWandererK = aWandererK + ((RotL64(aCross, 39U) + RotL64(aOrbiterI, 29U)) + aOrbiterC);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterD, 21U)) + aNonceWordI);
            aWandererH = aWandererH + (((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 41U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 37U)) + aOrbiterA);
            aWandererG = aWandererG + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 48U)) + aOrbiterJ) + aNonceWordJ);
            aWandererA = aWandererA ^ (((RotL64(aCross, 41U) + aOrbiterE) + RotL64(aOrbiterB, 23U)) + aWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aScatter, 52U) + aOrbiterF) + RotL64(aOrbiterE, 53U)) + RotL64(aCarry, 21U)) + aNonceWordN);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 19U)) + aOrbiterI);
            aWandererB = aWandererB + (((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterA, 13U)) + aWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 37U) + aOrbiterK) + RotL64(aOrbiterE, 43U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (RotL64(aWandererH, 28U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + RotL64(aWandererC, 22U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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

void TwistExpander_FootBall_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xB152C984F8D627C7ULL + 0xD2C61B35575517FCULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x8E6A960740B9F97BULL + 0x8B1936C1E4AFA3C2ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x852C15855F9FE58BULL + 0x9163E2A3BC6FDFF8ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xD92674EB1B5864A3ULL + 0xE7813F92B7C8C6CDULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xEC12CE9D7E0F8BA9ULL + 0xB49F84A036E866DEULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xAFD718B7E13FA0D5ULL + 0xBEA9483E7665C049ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xFAAAE17412C65435ULL + 0xEBFA2718251C1099ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xB600942170DBA143ULL + 0xA3A0CC8BC1D7BB12ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xC16B885D6380CDAFULL + 0x84A53A7FF189DC6BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x997B3D0B6C14E5B5ULL + 0xF1FE97407C83FE0AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xE153FE36AADFB8C3ULL + 0xEDB28FF928B5FBA6ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xDDD0EA39CC4DDEC3ULL + 0x8B837A2BCF6760EBULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xD548FD18A751CC01ULL + 0xD937C1A1DC798E09ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x8BF96F5359F650F9ULL + 0x8814C77C3BEF22AFULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x8C77BDAFD4111E97ULL + 0xEBF0EC129D5256D0ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xC9F13B19B6ABCAC1ULL + 0xB4E02E74485BA64BULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneA, aOperationLaneC, aOperationLaneD, aFireLaneC, aExpandLaneA, aFireLaneB, aWorkLaneB, aExpandLaneB, aWorkLaneC, aWorkLaneD, aExpandLaneC, aFireLaneD, aWorkLaneA
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aFireLaneC
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aFireLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 6107U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((aIndex + 5044U)) & S_BLOCK1], 18U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 469U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 1183U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 7310U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 1516U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCarry, 53U)) + (RotL64(aCross, 5U) + RotL64(aPrevious, 36U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterI = (aWandererB + RotL64(aScatter, 39U)) + 4773124477323378268U;
            aOrbiterA = (((aWandererF + RotL64(aCross, 29U)) + RotL64(aCarry, 43U)) + 16848723289435796005U) + aOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aIngress, 34U)) + 13846642134917107058U) + aOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = (aWandererE + RotL64(aPrevious, 21U)) + 6472057872482789939U;
            aOrbiterE = (aWandererC + RotL64(aIngress, 53U)) + 2747019500690707226U;
            aOrbiterC = (aWandererD + RotL64(aCross, 57U)) + 9003965289739733880U;
            aOrbiterH = (((aWandererK + RotL64(aPrevious, 4U)) + RotL64(aCarry, 57U)) + 3013390651936257377U) + aNonceWordO;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 13U)) + RotL64(aCarry, 5U)) + 3331004709895625067U;
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 43U)) + 15355010435553517129U) + aNonceWordF;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 7709870658004280052U) + aOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 13568728443963926564U) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 6736090830113688981U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 12409548853419307131U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 969183352023661537U;
            aOrbiterC = RotL64((aOrbiterC * 5549220554838837145U), 39U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterH) + 15370309834426476775U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordH;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 3896803894396631184U;
            aOrbiterB = RotL64((aOrbiterB * 11018830202891911603U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 10848873633291935766U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 12885336509190543440U;
            aOrbiterK = RotL64((aOrbiterK * 1487357252619221365U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 8252290890093788010U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 9201553615601641350U;
            aOrbiterH = RotL64((aOrbiterH * 420321130559162915U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 14014209645503188472U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 4015071464301844550U;
            aOrbiterI = RotL64((aOrbiterI * 17444195018239904971U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 16173085647514027347U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 16916627014974363360U) ^ aOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7699587344277490953U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 1591680303404522110U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 16499606051269327916U;
            aOrbiterE = RotL64((aOrbiterE * 814405848002794813U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 6932673635509444619U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 8745681160108707944U) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 14565255558668084787U), 27U);
            //
            aIngress = RotL64(aOrbiterC, 57U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterJ, 44U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 48U) + aOrbiterK) + RotL64(aOrbiterC, 27U)) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 13U) + aOrbiterB) + RotL64(aOrbiterJ, 37U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterB, 46U)) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterH, 3U)) + aOrbiterJ);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 44U) + aOrbiterA) + RotL64(aOrbiterI, 13U)) + aNonceWordA) + aWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 23U)) + aOrbiterI);
            aWandererH = aWandererH + (((RotL64(aCross, 39U) + RotL64(aOrbiterJ, 41U)) + aOrbiterC) + aNonceWordP);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 58U)) + aOrbiterJ) + aWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 19U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererK, 43U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 2
        // ingress from: aExpandLaneA, aOperationLaneC, aFireLaneB
        // ingress directions: aExpandLaneA forward forced, aOperationLaneC forward forced, aFireLaneB forward/backward random
        // cross from: aOperationLaneA, aOperationLaneD, aWorkLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneD backward forced, aWorkLaneB backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 12050U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((aIndex + 15756U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 14206U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 15044U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 12380U)) & S_BLOCK1], 12U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 14532U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCross, 57U)) ^ (RotL64(aCarry, 20U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterH = (aWandererA + RotL64(aScatter, 29U)) + 13650869943246163567U;
            aOrbiterG = ((((aWandererG + RotL64(aIngress, 47U)) + RotL64(aCarry, 51U)) + 3435284932011770999U) + aOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1]) + aNonceWordH;
            aOrbiterI = ((aWandererD + RotL64(aCross, 11U)) + 12388155658186776579U) + aNonceWordJ;
            aOrbiterD = (aWandererI + RotL64(aPrevious, 18U)) + 2374345913955712039U;
            aOrbiterB = (aWandererF + RotL64(aIngress, 53U)) + 6095094526980292156U;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 35U)) + 4965147025852444174U) + aOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = (aWandererK + RotL64(aPrevious, 5U)) + 3261881216269075298U;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 41U)) + RotL64(aCarry, 3U)) + 4939780217097329222U;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 60U)) + RotL64(aCarry, 27U)) + 3019862009792676287U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 901910626217143974U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 3647055146712366383U) ^ aNonceWordG;
            aOrbiterI = RotL64((aOrbiterI * 1792602402476450009U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 7731765438957392967U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 13409819457393479741U;
            aOrbiterE = RotL64((aOrbiterE * 3345078200262410715U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 5415832109107794258U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 8876738832313114471U;
            aOrbiterC = RotL64((aOrbiterC * 1304277600444504135U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 17135570542519390359U) + aNonceWordM;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 2373193062766802082U;
            aOrbiterB = RotL64((aOrbiterB * 4213691513185791519U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 16318403285501718552U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 8456043288604687045U) ^ aOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10556964529144571683U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 10572534930284516528U) + aOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 14616251186735204677U;
            aOrbiterJ = RotL64((aOrbiterJ * 2048651204265459805U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 2837006243817205610U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 5315917323622194254U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4080522050089666599U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 12084676282761185907U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 7922080344175593788U;
            aOrbiterH = RotL64((aOrbiterH * 7603522302708937379U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 17620847289789547792U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 12140386059533463650U;
            aOrbiterD = RotL64((aOrbiterD * 1443266480620969535U), 29U);
            //
            aIngress = RotL64(aOrbiterG, 20U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterA, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterC, 58U)) + aOrbiterE);
            aWandererD = aWandererD + ((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterD, 27U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 39U) + aOrbiterJ) + RotL64(aOrbiterH, 19U)) + aWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 18U) + aOrbiterC) + RotL64(aOrbiterB, 51U)) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 13U) + aOrbiterI) + RotL64(aOrbiterH, 36U));
            aWandererE = aWandererE + ((RotL64(aCross, 23U) + aOrbiterG) + RotL64(aOrbiterB, 11U));
            aWandererC = aWandererC ^ ((((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterC, 43U)) + aNonceWordC) + aWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 47U)) + aOrbiterA) + RotL64(aCarry, 51U)) + aNonceWordA);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 54U) + RotL64(aOrbiterG, 23U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 60U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererG, 23U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 3
        // ingress from: aExpandLaneB, aOperationLaneD, aWorkLaneC
        // ingress directions: aExpandLaneB forward forced, aOperationLaneD forward forced, aWorkLaneC forward/backward random
        // cross from: aExpandLaneA, aOperationLaneB, aWorkLaneD
        // cross directions: aExpandLaneA backward forced, aOperationLaneB backward forced, aWorkLaneD backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 21243U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneD[((aIndex + 22794U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 20524U)) & S_BLOCK1], 26U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24070U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 17754U)) & S_BLOCK1], 20U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 20794U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 44U) ^ RotL64(aCross, 57U)) + (RotL64(aCarry, 27U) + RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterI = (((aWandererA + RotL64(aCross, 44U)) + RotL64(aCarry, 23U)) + 16451272412693907816U) + aNonceWordM;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 11U)) + RotL64(aCarry, 53U)) + 10099485419723255462U;
            aOrbiterJ = (((aWandererG + RotL64(aPrevious, 57U)) + 17668900099534923192U) + aOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordA;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 53U)) + 5497093724143181753U) + aOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 27U)) + RotL64(aCarry, 43U)) + 10354044773550071706U;
            aOrbiterG = (aWandererJ + RotL64(aCross, 21U)) + 12728258851198019099U;
            aOrbiterD = (aWandererD + RotL64(aIngress, 48U)) + 4144050505314242618U;
            aOrbiterB = (aWandererI + RotL64(aScatter, 35U)) + 14133805325480076530U;
            aOrbiterC = (aWandererE + RotL64(aIngress, 3U)) + 308863673210602899U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 11741180130160569753U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 12926863156769180448U;
            aOrbiterJ = RotL64((aOrbiterJ * 9726030996091054939U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 211920854786494259U) + aOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 13234608842479411078U) ^ aOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2556747209733759467U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 9164711974854618892U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 6667377062281954219U;
            aOrbiterK = RotL64((aOrbiterK * 2603737166987437649U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 4559040002406721850U) + aNonceWordD;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 1749875480850675109U;
            aOrbiterB = RotL64((aOrbiterB * 15822640067349481089U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 9555365165561936366U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 18289733999504213574U;
            aOrbiterD = RotL64((aOrbiterD * 14156217554673229429U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 8727162691639622461U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 291406782452963706U;
            aOrbiterC = RotL64((aOrbiterC * 8413500075082350243U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 8294911802626492257U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 15853578397277298548U) ^ aOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13256191781365357747U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 11535146194939658681U) + aNonceWordL;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 2177540476748375661U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15791341922007841029U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 2705306323728084136U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 17617871830709148043U;
            aOrbiterI = RotL64((aOrbiterI * 3449981219502809255U), 47U);
            //
            aIngress = RotL64(aOrbiterA, 5U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 53U));
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterE, 14U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterD, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterJ, 47U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 39U) + RotL64(aOrbiterC, 19U)) + aOrbiterJ) + aNonceWordE) + aWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 23U)) + aOrbiterK);
            aWandererA = aWandererA ^ ((RotL64(aCross, 48U) + aOrbiterC) + RotL64(aOrbiterB, 42U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterG, 51U)) + aOrbiterK) + RotL64(aCarry, 27U)) + aNonceWordP);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 19U) + aOrbiterJ) + RotL64(aOrbiterA, 3U));
            aWandererG = aWandererG + (((RotL64(aCross, 57U) + RotL64(aOrbiterG, 29U)) + aOrbiterA) + aNonceWordH);
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 44U) + RotL64(aOrbiterD, 11U)) + aOrbiterE) + aNonceWordB) + aWandererUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterI, 60U)) + aOrbiterA) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 26U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 5U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneD
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneB, aOperationLaneC, aWorkLaneA
        // cross directions: aExpandLaneB backward forced, aOperationLaneC backward forced, aWorkLaneA backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 29570U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((aIndex + 30029U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 25954U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29699U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 30155U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 24921U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCarry, 57U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCross, 22U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterG = (((aWandererH + RotL64(aScatter, 57U)) + RotL64(aCarry, 21U)) + 3612110001869385068U) + aOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = (aWandererE + RotL64(aCross, 36U)) + 16340824141280225936U;
            aOrbiterD = (((aWandererG + RotL64(aIngress, 19U)) + RotL64(aCarry, 41U)) + 15222338965130765231U) + aNonceWordH;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 13U)) + 6649270508107155041U) + aNonceWordA;
            aOrbiterF = (aWandererD + RotL64(aIngress, 41U)) + 768217258655426384U;
            aOrbiterB = ((aWandererF + RotL64(aCross, 28U)) + 4481855259658861851U) + aNonceWordO;
            aOrbiterA = ((((aWandererI + RotL64(aPrevious, 53U)) + RotL64(aCarry, 29U)) + 18318041934562434016U) + aOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1]) + aNonceWordK;
            aOrbiterH = (aWandererA + RotL64(aScatter, 3U)) + 4212457153804401807U;
            aOrbiterC = (aWandererC + RotL64(aIngress, 23U)) + 16143621095636987628U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 2095664232866642086U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 4339527736737366572U;
            aOrbiterD = RotL64((aOrbiterD * 17503569508822244125U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 13679353177869884790U) + aOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 11582168502846418236U;
            aOrbiterF = RotL64((aOrbiterF * 135539430034462861U), 43U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterB) + 10451330452898542191U) + aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1]) + aNonceWordC;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 12951448817640617841U;
            aOrbiterA = RotL64((aOrbiterA * 4141870904192742091U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 15389161934419370747U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 4754886272708253014U) ^ aNonceWordM;
            aOrbiterK = RotL64((aOrbiterK * 16638243718191281597U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 11746389873929280688U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 12042680172517298768U) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 3814780289755857543U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 2648103752465009244U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 451594673632597973U;
            aOrbiterH = RotL64((aOrbiterH * 8496763663271072425U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 5696534794094099710U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 14609435045257077395U;
            aOrbiterB = RotL64((aOrbiterB * 14658408563237468407U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 11599395126850950133U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 12699598504604446664U) ^ aNonceWordJ;
            aOrbiterG = RotL64((aOrbiterG * 14313494063098111823U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 9398465148537154745U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 12139736860648011256U;
            aOrbiterI = RotL64((aOrbiterI * 15257503229375247987U), 27U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterG, 11U);
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterH, 24U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + RotL64(aOrbiterB, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aCross, 58U) + aOrbiterK) + RotL64(aOrbiterD, 18U)) + RotL64(aCarry, 37U)) + aNonceWordN);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 23U)) + aOrbiterC) + aNonceWordF);
            aWandererK = aWandererK + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 47U)) + aOrbiterB) + aNonceWordI);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 23U) + aOrbiterI) + RotL64(aOrbiterH, 27U)) + aWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 43U) + aOrbiterH) + RotL64(aOrbiterA, 37U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 57U)) + aOrbiterH);
            aWandererD = aWandererD + ((RotL64(aPrevious, 12U) + aOrbiterB) + RotL64(aOrbiterD, 3U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 39U) + aOrbiterK) + RotL64(aOrbiterI, 13U)) + aNonceWordG);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterF, 52U)) + aOrbiterC) + RotL64(aCarry, 19U)) + aWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + (RotL64(aWandererC, 54U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererI, 41U);
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

void TwistExpander_FootBall_Arx::KDF_B_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x9057BACCCD793087ULL + 0xAE2EBAD096197215ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x91DD52BF66F1BF67ULL + 0xAC55B3CFAC3ECE7AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x9544D0F66FFB3F61ULL + 0x97328F906AF651A9ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xB5A3A2D520DE9D31ULL + 0xA3FBE67D6193E55FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xAFAB24484FDF2433ULL + 0x9D5DFA2539581B11ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xEF1258CEE5616273ULL + 0xE0259DDC08290C33ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xFD5BE89E72537115ULL + 0xDCE83EF12864C5F7ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xBB1ACC17188CC2DFULL + 0x8899F6C576186639ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xFA40D12F71E27885ULL + 0xE998EFDD1F4CAFD0ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xA7A9F1CEBF6766FBULL + 0x94308553F7F5F93AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xFA0FDA99A55FB207ULL + 0xEDB975907479E387ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xD4C40C751FFDF8CBULL + 0xA77EACC7954AF7BCULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x9A463BAD59E24813ULL + 0xE5C164E8AE7E4910ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xB435F054C1AA0649ULL + 0xFED5DF69DA79D868ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xAAC9CC70CA3091FDULL + 0xFCC595FA7737DCD3ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xF198FEA318B43041ULL + 0xACB258E1B8C38488ULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aFireLaneB, aWorkLaneC, aWorkLaneD, aFireLaneA, aExpandLaneA, aFireLaneD, aOperationLaneD, aExpandLaneB, aFireLaneC, aOperationLaneB, aExpandLaneC, aOperationLaneA, aOperationLaneC
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_d loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aFireLaneB
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aFireLaneB forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aFireLaneA
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aFireLaneA backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 1340U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((aIndex + 4869U)) & S_BLOCK1], 52U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 2095U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7470U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 2882U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 8140U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCarry, 23U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCross, 40U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterC = (((aWandererD + RotL64(aIngress, 41U)) + RotL64(aCarry, 19U)) + 13880995121909552664U) + aNonceWordK;
            aOrbiterE = (((aWandererF + RotL64(aScatter, 19U)) + 14534942818069300546U) + aOrbiterAssignSaltD[((aIndex + 22U)) & S_SALT1]) + aNonceWordO;
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 57U)) + 17745973100886007133U) + aOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = ((aWandererB + RotL64(aCross, 13U)) + 2249805580771946872U) + aNonceWordG;
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 6U)) + RotL64(aCarry, 41U)) + 4460116116396439410U;
            aOrbiterK = ((aWandererG + RotL64(aCross, 27U)) + RotL64(aCarry, 53U)) + 3378683994078106878U;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 47U)) + 3992996501048809123U) + aNonceWordE;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 12057768808864451929U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 4115362079047921130U) ^ aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12263015903331031345U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 15297384955502206698U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 17623548383481905636U;
            aOrbiterJ = RotL64((aOrbiterJ * 7487278217901483685U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 3559213898000162417U) + aNonceWordH;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 12311605719074507335U) ^ aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3982199462062847697U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 14807313864347885885U) + aOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 11222085523291581822U;
            aOrbiterC = RotL64((aOrbiterC * 12580941911587215653U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 916681229436292462U) + aNonceWordN;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 2441350114032314686U;
            aOrbiterG = RotL64((aOrbiterG * 7336079498999018067U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 7361470539894653271U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 12153585147213579808U) ^ aNonceWordC;
            aOrbiterE = RotL64((aOrbiterE * 3040327545467672961U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 13566300726101613579U) + aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 14875254144748509128U;
            aOrbiterH = RotL64((aOrbiterH * 13699179902908972403U), 51U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 5U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + RotL64(aOrbiterJ, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterH, 37U)) + aOrbiterE) + aWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterG, 6U)) + aOrbiterK) + RotL64(aCarry, 35U)) + aNonceWordP);
            aWandererG = aWandererG ^ ((RotL64(aCross, 47U) + aOrbiterC) + RotL64(aOrbiterA, 43U));
            aWandererD = aWandererD + ((RotL64(aScatter, 14U) + RotL64(aOrbiterC, 57U)) + aOrbiterG);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterJ, 13U)) + aOrbiterG);
            aWandererH = aWandererH + (((RotL64(aScatter, 5U) + RotL64(aOrbiterH, 51U)) + aOrbiterK) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ ((((RotL64(aCross, 21U) + aOrbiterE) + RotL64(aOrbiterG, 23U)) + aNonceWordM) + aWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererC, 10U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aFireLaneD
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aFireLaneD forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aOperationLaneD
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 11168U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneC[((aIndex + 10306U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 9523U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13952U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8313U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 8392U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aPrevious, 4U)) + (RotL64(aIngress, 51U) + RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 13U)) + 3248574644570178787U) + aNonceWordA;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 21U)) + RotL64(aCarry, 27U)) + 4506961512959200024U;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 57U)) + 8423739774540738590U) + aNonceWordI;
            aOrbiterA = (((aWandererK + RotL64(aIngress, 44U)) + RotL64(aCarry, 13U)) + 6593975869641735337U) + aNonceWordC;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 51U)) + 16441716090557369103U) + aOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aCross, 37U)) + RotL64(aCarry, 53U)) + 7936601450453207914U;
            aOrbiterI = (((aWandererE + RotL64(aIngress, 29U)) + 13333752583560167065U) + aOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordN;
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 8013703284795432973U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 2349852779887439236U;
            aOrbiterF = RotL64((aOrbiterF * 2422888500648100783U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 5318539364763284138U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 11450957608502944376U) ^ aNonceWordJ;
            aOrbiterD = RotL64((aOrbiterD * 1957880366707810635U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 9058992558327552687U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 632095686920230926U) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 12460364388358520799U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 14734218428913777098U) + aNonceWordM;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 16344357661370784442U) ^ aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15049472842002138369U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 2981145363531184308U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 14176472085175714494U;
            aOrbiterA = RotL64((aOrbiterA * 2584623327412130939U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 11198457590069700889U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterF) ^ 952584436750426828U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 1165713888651280355U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 4311591763498985972U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 16194341833989936369U) ^ aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9997934560195932575U), 5U);
            //
            aIngress = RotL64(aOrbiterG, 27U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + RotL64(aOrbiterC, 4U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 37U) + aOrbiterE) + RotL64(aOrbiterG, 29U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 5U) + aOrbiterC) + RotL64(aOrbiterI, 43U)) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterG, 50U)) + aOrbiterC);
            aWandererB = aWandererB + ((((RotL64(aCross, 27U) + aOrbiterI) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 43U)) + aWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 44U) + RotL64(aOrbiterA, 35U)) + aOrbiterF);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 5U)) + aOrbiterG) + aNonceWordL) + aWandererUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterG, 21U)) + aOrbiterI) + aNonceWordH);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 14U));
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aFireLaneC
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aOperationLaneB
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 18915U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneD[((aIndex + 18884U)) & S_BLOCK1], 54U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 19347U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22758U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21718U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 16532U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 5U)) + (RotL64(aIngress, 19U) + RotL64(aCross, 52U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterK = (aWandererI + RotL64(aCross, 13U)) + 16160838483846078448U;
            aOrbiterB = (((aWandererE + RotL64(aIngress, 3U)) + 15404960896190227946U) + aOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordM;
            aOrbiterI = (((aWandererH + RotL64(aScatter, 51U)) + RotL64(aCarry, 11U)) + 16904160594024977199U) + aOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = (((aWandererB + RotL64(aPrevious, 37U)) + RotL64(aCarry, 39U)) + 17790460246821031802U) + aNonceWordE;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 26U)) + RotL64(aCarry, 23U)) + 16395168254086971959U;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 57U)) + 7484373204039901786U;
            aOrbiterG = (aWandererA + RotL64(aIngress, 19U)) + 18026814691322913510U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 15244817793136966450U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 5795491730356335666U;
            aOrbiterI = RotL64((aOrbiterI * 13253529465289332171U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 3163873518027801504U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 2690791759507349172U;
            aOrbiterE = RotL64((aOrbiterE * 16677948635136515083U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 17898067251167087906U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterJ) ^ 8028010015006604239U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterG = RotL64((aOrbiterG * 5601629670521300241U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 7304739457289910555U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 6476837815096530043U;
            aOrbiterK = RotL64((aOrbiterK * 16380545138701113267U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 14242499233467960602U) + aOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterI) ^ 17305645693017634630U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 14442976693206929569U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 9772864059444171908U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 7897200728282156408U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 816306719390807411U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 4890999319172950996U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 8165132649356094963U;
            aOrbiterD = RotL64((aOrbiterD * 17297706071263690189U), 11U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 41U);
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterE, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 37U) + RotL64(aOrbiterB, 39U)) + aOrbiterG) + aWandererUpdateSaltC[((aIndex + 14U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterD, 23U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 43U) + aOrbiterD) + RotL64(aOrbiterG, 3U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 46U)) + aOrbiterB);
            aWandererG = aWandererG + (((((RotL64(aScatter, 51U) + aOrbiterJ) + RotL64(aOrbiterI, 53U)) + RotL64(aCarry, 53U)) + aNonceWordB) + aWandererUpdateSaltD[((aIndex + 6U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterE, 11U)) + aOrbiterK);
            aWandererB = aWandererB + ((((RotL64(aIngress, 20U) + aOrbiterG) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 37U)) + aNonceWordA);
            //
            aCarry = aCarry + (RotL64(aWandererG, 48U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 34U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aOperationLaneA
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aOperationLaneA forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aOperationLaneC
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 24774U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneA[((aIndex + 26734U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29040U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26658U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 28610U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 25870U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 35U)) ^ (RotL64(aPrevious, 56U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterE = (((aWandererJ + RotL64(aIngress, 35U)) + RotL64(aCarry, 27U)) + 17264605017518259932U) + aOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = (((aWandererK + RotL64(aCross, 47U)) + RotL64(aCarry, 47U)) + 15209184354580778643U) + aNonceWordD;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 53U)) + 3299527965014731384U;
            aOrbiterC = ((((aWandererG + RotL64(aScatter, 18U)) + RotL64(aCarry, 3U)) + 16293096431816127821U) + aOrbiterAssignSaltD[((aIndex + 8U)) & S_SALT1]) + aNonceWordL;
            aOrbiterH = (aWandererE + RotL64(aCross, 11U)) + 11031983436878828337U;
            aOrbiterA = (aWandererC + RotL64(aIngress, 27U)) + 9188018632448236358U;
            aOrbiterF = (aWandererD + RotL64(aPrevious, 41U)) + 13420816400363406556U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 2485063384097917101U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 3089135816938128264U) ^ aOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8813152992957361153U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 10730544971770435788U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 10431767565618874806U;
            aOrbiterE = RotL64((aOrbiterE * 4723078464590561545U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 14883796491656899074U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 13465877783538483706U;
            aOrbiterA = RotL64((aOrbiterA * 14311686051108108503U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 13322163435314643713U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 3307316600284371955U;
            aOrbiterH = RotL64((aOrbiterH * 12337846092069506365U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 4950101626975919939U) + aNonceWordB;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 2596253994220103666U) ^ aNonceWordJ;
            aOrbiterC = RotL64((aOrbiterC * 7181706961838582889U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 17961706029559914243U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 10321902557977495175U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16189559888625084711U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 18146616411403012772U) + aOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 8414050129421955787U) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 14879448948196182863U), 53U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 11U);
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 41U));
            aIngress = aIngress + RotL64(aOrbiterC, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 3U)) + aOrbiterC) + aNonceWordC);
            aWandererE = aWandererE + (((RotL64(aPrevious, 23U) + aOrbiterJ) + RotL64(aOrbiterH, 58U)) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterA, 51U)) + aOrbiterC) + aNonceWordF);
            aWandererG = aWandererG + ((RotL64(aCross, 11U) + RotL64(aOrbiterA, 43U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 41U) + aOrbiterE) + RotL64(aOrbiterB, 37U));
            aWandererA = aWandererA + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterH, 27U)) + aOrbiterE) + RotL64(aCarry, 57U)) + aWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 60U) + aOrbiterF) + RotL64(aOrbiterH, 11U)) + aWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 12U));
            aCarry = aCarry + RotL64(aWandererK, 35U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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

void TwistExpander_FootBall_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC;
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
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xFC2FB02CA9B41C89ULL + 0x9289BCC758C5C184ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xF9E5E694533A8A97ULL + 0xA538D7AAA0B56A1FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x9DFC96C392C019D3ULL + 0xEE706ADA70269439ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xDE15C2B7B5D117B3ULL + 0xC5ECB61B7CE9C9A0ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xB598691F62703239ULL + 0xA6F350B91B0A9160ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xF3A62647D1A87859ULL + 0xE09CE6014575BEEDULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xDF2939D70ABA9899ULL + 0xABEF57607E1B352EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE3C208C2C189BF31ULL + 0xF0D7031E57282B06ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xE90737B850922B97ULL + 0x8731D1BEA9975A23ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xDEF30A237ACC83FFULL + 0xECD28AC99DF85610ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xF0B468ADDF6DDDC1ULL + 0x8DE26AF105888FB4ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xA8126FA2B9A8E023ULL + 0xAA6538CC688C8539ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xF568E2720E502A25ULL + 0xBC72C3D6FF5D5435ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xD47A9D21AD61F811ULL + 0xDCDD8BE8871D008EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xE8EF1DEBF143038FULL + 0xEEDBF1B1C1BBB34FULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xFA3031FE5CC8F735ULL + 0x91B3CB90A879ABD0ULL);
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 1763U)) & W_KEY1], 51U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 2454U)) & W_KEY1], 23U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 2379U)) & W_KEY1], 14U) ^ RotL64(mSource[((aIndex + 1378U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCross, 22U)) ^ (RotL64(aCarry, 3U) + RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterF = ((aWandererD + RotL64(aCross, 19U)) + 9471546960258473684U) + aPhaseEOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aScatter, 3U)) + 18050235435948942244U;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 11U)) + RotL64(aCarry, 5U)) + 3005107102671544641U;
            aOrbiterC = (((aWandererI + RotL64(aPrevious, 51U)) + RotL64(aCarry, 43U)) + 17898396434573801850U) + aNonceWordD;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 57U)) + RotL64(aCarry, 27U)) + 15071602525497771648U;
            aOrbiterJ = (aWandererC + RotL64(aCross, 35U)) + 5780119462702672108U;
            aOrbiterH = (((aWandererA + RotL64(aPrevious, 44U)) + 13301326224151025687U) + aPhaseEOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1]) + aNonceWordF;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 18129323022260575961U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 1199228670638790709U;
            aOrbiterK = RotL64((aOrbiterK * 1780426336211781025U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 1839199978088021020U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterI) ^ 4999517042246790165U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterB = RotL64((aOrbiterB * 4585813675677234577U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 8788607633376516299U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 15143903839930468749U;
            aOrbiterJ = RotL64((aOrbiterJ * 12735914889325422675U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 16674732686428431869U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 15908873150953195581U;
            aOrbiterH = RotL64((aOrbiterH * 18049755517524334107U), 13U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterJ) + 11204775359756474667U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordG;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 2525984309543939465U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3988529812023791571U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 4566345170476825512U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 14876612901557406267U;
            aOrbiterI = RotL64((aOrbiterI * 9047956948845135339U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 14926290877038883931U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 12710203178186614846U;
            aOrbiterC = RotL64((aOrbiterC * 14841163494801662515U), 29U);
            //
            aIngress = RotL64(aOrbiterF, 19U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 43U));
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterC, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((((RotL64(aCross, 51U) + aOrbiterJ) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 3U)) + aNonceWordL) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 28U)) + aOrbiterF) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 41U) + aOrbiterI) + RotL64(aOrbiterJ, 53U)) + aNonceWordB);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 26U) + RotL64(aOrbiterC, 41U)) + aOrbiterH);
            aWandererK = aWandererK + ((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterH, 13U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 11U) + aOrbiterH) + RotL64(aOrbiterB, 21U));
            aWandererH = aWandererH + (((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 6U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 21U));
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 28U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 5257U)) & S_BLOCK1], 39U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 4603U)) & W_KEY1], 48U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 5305U)) & W_KEY1], 39U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 5226U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 21U) + RotL64(aCarry, 3U)) ^ (RotL64(aCross, 37U) ^ RotL64(aPrevious, 50U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterF = (((aWandererK + RotL64(aCross, 41U)) + RotL64(aCarry, 53U)) + 17074147006464019918U) + aNonceWordE;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 11U)) + 10559516626129419928U) + aNonceWordJ;
            aOrbiterB = (aWandererB + RotL64(aIngress, 47U)) + 13280363679503946221U;
            aOrbiterH = (((aWandererA + RotL64(aPrevious, 21U)) + 17657115422132457413U) + aPhaseEOrbiterAssignSaltF[((aIndex + 6U)) & S_SALT1]) + aNonceWordN;
            aOrbiterG = ((((aWandererH + RotL64(aIngress, 54U)) + RotL64(aCarry, 29U)) + 13325837013304973008U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordP;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 35U)) + RotL64(aCarry, 11U)) + 3059707750486106037U;
            aOrbiterA = (aWandererD + RotL64(aScatter, 5U)) + 4529045702503050852U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 10726578475550904292U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 14832537837996659885U;
            aOrbiterB = RotL64((aOrbiterB * 808060368961520519U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 220094417441809246U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 15343130035105342194U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7984652435043810845U), 21U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterF) + 16592263353426409884U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1]) + aNonceWordM;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 15649290906447931918U;
            aOrbiterH = RotL64((aOrbiterH * 8405875177836650731U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 11437410545843708269U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 5859769136073011444U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1065016088086441107U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 15188064100307340341U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 4367466521843260049U) ^ aNonceWordF;
            aOrbiterI = RotL64((aOrbiterI * 15916715854192820923U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 8482617283860566845U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 2585745804937342972U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8267269625632139809U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 1687641344403425541U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 13667916445979421400U) ^ aNonceWordG;
            aOrbiterD = RotL64((aOrbiterD * 8191322670355590027U), 51U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterB, 5U);
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterB, 13U)) + aNonceWordB) + aPhaseEWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 41U) + aOrbiterA) + RotL64(aOrbiterH, 5U)) + aNonceWordK);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 56U) + aOrbiterG) + RotL64(aOrbiterD, 52U));
            aWandererD = aWandererD + (((RotL64(aScatter, 21U) + aOrbiterI) + RotL64(aOrbiterA, 43U)) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ ((((RotL64(aCross, 35U) + RotL64(aOrbiterG, 21U)) + aOrbiterA) + aNonceWordI) + aPhaseEWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 11U) + RotL64(aOrbiterH, 29U)) + aOrbiterI) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterI, 35U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 24U));
            aCarry = aCarry + RotL64(aWandererF, 37U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 6547U)) & S_BLOCK1], 29U) ^ RotL64(aKeyRowReadB[((aIndex + 5929U)) & W_KEY1], 42U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 7932U)) & W_KEY1], 47U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6177U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 5664U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 18U) ^ RotL64(aCross, 5U)) + (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterG = ((aWandererF + RotL64(aIngress, 13U)) + 8101351470141807662U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = (((aWandererH + RotL64(aPrevious, 35U)) + RotL64(aCarry, 3U)) + 6965474099521076705U) + aNonceWordJ;
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 20U)) + RotL64(aCarry, 47U)) + 6803828268885684784U;
            aOrbiterH = ((((aWandererG + RotL64(aCross, 3U)) + RotL64(aCarry, 23U)) + 13454235922950972488U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordL;
            aOrbiterI = (aWandererE + RotL64(aScatter, 27U)) + 11678091885751244777U;
            aOrbiterC = (aWandererC + RotL64(aIngress, 41U)) + 5307134544628507141U;
            aOrbiterA = ((aWandererD + RotL64(aCross, 53U)) + 4873703518950429353U) + aNonceWordB;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 8542156221858586039U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 3993726182905296513U;
            aOrbiterJ = RotL64((aOrbiterJ * 11331376012938127609U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 12113047622035464386U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 1944244448665721151U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7010050836758762003U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 12914188029425467576U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 2486762763475327024U) ^ aNonceWordK;
            aOrbiterA = RotL64((aOrbiterA * 12319769994433811617U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 14580191602982245481U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 12093414832400135066U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12720286833215690663U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 13623906997320021065U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 9977356009806428696U;
            aOrbiterI = RotL64((aOrbiterI * 2005536391712733499U), 23U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterA) + 3694954095397810851U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1]) + aNonceWordA;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 11453812627797091638U;
            aOrbiterG = RotL64((aOrbiterG * 13730420725113907161U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 542311345544726351U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 3024285045990499484U;
            aOrbiterH = RotL64((aOrbiterH * 5153745952148205645U), 35U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 12U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 21U));
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aScatter, 27U) + RotL64(aOrbiterH, 51U)) + aOrbiterB) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 57U) + aOrbiterC) + RotL64(aOrbiterB, 12U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterJ, 43U)) + aOrbiterI) + aNonceWordN);
            aWandererG = aWandererG ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterJ, 57U)) + aOrbiterB);
            aWandererF = aWandererF + (((RotL64(aScatter, 13U) + aOrbiterB) + RotL64(aOrbiterG, 19U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 51U) + aOrbiterC) + RotL64(aOrbiterG, 27U));
            aWandererD = aWandererD + (((((RotL64(aPrevious, 4U) + aOrbiterG) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 13U)) + aNonceWordD) + aPhaseEWandererUpdateSaltC[((aIndex + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 24U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 8993U)) & S_BLOCK1], 23U) ^ RotL64(aKeyRowReadB[((aIndex + 9217U)) & W_KEY1], 46U));
            aIngress ^= (RotL64(mSource[((aIndex + 9026U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8794U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 9014U)) & W_KEY1], 53U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 9457U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 37U) ^ RotL64(aIngress, 5U)) + (RotL64(aCross, 50U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterE = ((((aWandererJ + RotL64(aIngress, 13U)) + RotL64(aCarry, 23U)) + 2915859148137000694U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterK = (((aWandererG + RotL64(aCross, 35U)) + RotL64(aCarry, 47U)) + 210680583721444425U) + aNonceWordE;
            aOrbiterJ = (((aWandererA + RotL64(aScatter, 56U)) + RotL64(aCarry, 35U)) + 6668118118775650387U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aPrevious, 41U)) + 15794200818099010989U;
            aOrbiterC = (aWandererB + RotL64(aScatter, 29U)) + 6565076707062828369U;
            aOrbiterF = (aWandererC + RotL64(aIngress, 3U)) + 16323164497808856719U;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 19U)) + 7965435318816716560U) + aNonceWordD;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 7390281030573369017U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterE) ^ 2269738866911824875U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 1198697877998135567U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 9664014216039993873U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 18284857398028357633U;
            aOrbiterF = RotL64((aOrbiterF * 8402008251343393737U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 367667619795303009U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 7935945060956274197U) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 5481786693511955209U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 16683666162337789540U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 10655658270998102390U) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 15231596813382239841U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 8307037916581540297U) + aNonceWordP;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 3247742749860703524U;
            aOrbiterK = RotL64((aOrbiterK * 15052136713218656641U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 10446792483683818139U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 16374602929344972364U;
            aOrbiterE = RotL64((aOrbiterE * 12599903932725787599U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 2411334498322777183U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 1093701164116833765U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13129220206835381729U), 13U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 27U);
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + RotL64(aOrbiterA, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aCross, 44U) + aOrbiterF) + RotL64(aOrbiterK, 21U)) + aNonceWordC);
            aWandererK = aWandererK + (((RotL64(aPrevious, 53U) + aOrbiterE) + RotL64(aOrbiterJ, 56U)) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 41U)) + aOrbiterA);
            aWandererA = aWandererA + ((((RotL64(aScatter, 27U) + RotL64(aOrbiterE, 11U)) + aOrbiterC) + RotL64(aCarry, 41U)) + aNonceWordH);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterA, 35U)) + aPhaseFWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aCross, 37U) + aOrbiterK) + RotL64(aOrbiterD, 29U)) + aNonceWordB) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterC, 5U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 10U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 13275U)) & S_BLOCK1], 5U) ^ RotL64(aKeyRowReadA[((aIndex + 12914U)) & W_KEY1], 60U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 13202U)) & W_KEY1], 51U) ^ RotL64(mSource[((aIndex + 12437U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 12262U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13629U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 11728U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCarry, 3U)) ^ (RotL64(aCross, 53U) ^ RotL64(aIngress, 18U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterF = (aWandererD + RotL64(aCross, 23U)) + 12775735908960052604U;
            aOrbiterD = (aWandererJ + RotL64(aIngress, 43U)) + 11791373812080296887U;
            aOrbiterJ = (aWandererF + RotL64(aScatter, 3U)) + 5537362877706057303U;
            aOrbiterB = (((aWandererA + RotL64(aPrevious, 12U)) + RotL64(aCarry, 23U)) + 2023912048504189380U) + aNonceWordG;
            aOrbiterG = ((((aWandererC + RotL64(aScatter, 29U)) + RotL64(aCarry, 3U)) + 17668828109963766893U) + aPhaseFOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1]) + aNonceWordD;
            aOrbiterA = (((aWandererK + RotL64(aIngress, 35U)) + 558908629933941224U) + aPhaseFOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1]) + aNonceWordO;
            aOrbiterH = (((aWandererB + RotL64(aCross, 51U)) + RotL64(aCarry, 53U)) + 1479633119685446888U) + aNonceWordI;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 15460320397843364063U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 10059749397555469054U) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 8671817118586065469U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 9987633811929693924U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 10087337844580228269U;
            aOrbiterG = RotL64((aOrbiterG * 13817142288940843815U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 4446204415503364254U) + aNonceWordC;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 15106063243302192717U;
            aOrbiterF = RotL64((aOrbiterF * 13273756657334709803U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 9430197906134676162U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 1226048679997253363U;
            aOrbiterB = RotL64((aOrbiterB * 14247538885252664127U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 10611580584157624739U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 3137391249289641509U;
            aOrbiterH = RotL64((aOrbiterH * 5462682413239873181U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 9327201928815412810U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 7890659377013147073U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13827717178378062047U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 10675114832750356941U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 8804440385852327267U) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 8520671775587260601U), 3U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterD, 47U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterG, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterH, 57U)) + aNonceWordM);
            aWandererC = aWandererC + (((RotL64(aCross, 23U) + aOrbiterG) + RotL64(aOrbiterD, 37U)) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 58U) + RotL64(aOrbiterA, 43U)) + aOrbiterG) + aNonceWordN) + aPhaseFWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterD, 6U)) + aNonceWordJ) + aPhaseFWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterA, 13U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 35U) + aOrbiterJ) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 21U)) + aNonceWordA);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterB, 21U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 54U));
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererD, 13U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 16153U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 16230U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15785U)) & W_KEY1], 5U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 15379U)) & W_KEY1], 21U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 14865U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 14932U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15801U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 54U)) + (RotL64(aCarry, 19U) + RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterF = (((aWandererH + RotL64(aPrevious, 11U)) + RotL64(aCarry, 37U)) + 15316464782468770057U) + aNonceWordK;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 3U)) + 6642872057476351588U) + aNonceWordG;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 56U)) + RotL64(aCarry, 5U)) + 660732654689529192U;
            aOrbiterC = (aWandererD + RotL64(aScatter, 47U)) + 7235418086884000655U;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 41U)) + RotL64(aCarry, 53U)) + 14784518476694580493U;
            aOrbiterI = ((aWandererG + RotL64(aScatter, 29U)) + 12222433977933449375U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aCross, 35U)) + 8573001207708329927U) + aPhaseFOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 16035256260815013172U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 15767726974121910203U;
            aOrbiterJ = RotL64((aOrbiterJ * 719060452537759331U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 17712217935322939971U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 13488963456923357159U;
            aOrbiterG = RotL64((aOrbiterG * 16785285630840310405U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 10222949131965611079U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 1495561412321657209U;
            aOrbiterI = RotL64((aOrbiterI * 9706305581868526265U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 16156530750584361434U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 7773792489045606309U) ^ aNonceWordJ;
            aOrbiterF = RotL64((aOrbiterF * 10730624207715601393U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 11544578291333360613U) + aNonceWordC;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 3665587867634242865U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4840528190844842595U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 15248434984650998090U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 15487979645426567581U;
            aOrbiterE = RotL64((aOrbiterE * 10868107809356766183U), 53U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterB) + 6972347795052712690U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordD;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 16074994810010431338U) ^ aNonceWordN;
            aOrbiterC = RotL64((aOrbiterC * 1262655238856775853U), 13U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterE, 57U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 12U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 39U));
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterE, 35U)) + aOrbiterB);
            aWandererI = aWandererI + ((((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 39U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 47U) + aOrbiterG) + RotL64(aOrbiterJ, 5U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterE, 41U)) + aOrbiterI);
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 11U) + RotL64(aOrbiterC, 23U)) + aOrbiterJ) + aNonceWordP) + aPhaseFWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterC, 12U)) + RotL64(aCarry, 23U)) + aNonceWordM);
            aWandererA = aWandererA ^ (((RotL64(aCross, 28U) + aOrbiterJ) + RotL64(aOrbiterF, 53U)) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererG, 28U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + RotL64(aWandererB, 47U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 17918U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadA[((aIndex + 18776U)) & W_KEY1], 60U));
            aIngress ^= (RotL64(mSource[((aIndex + 16485U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18761U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 16939U)) & W_KEY1], 3U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 18489U)) & S_BLOCK1], 34U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 17333U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 18U) + RotL64(aCarry, 37U)) ^ (RotL64(aCross, 53U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterA = (((aWandererI + RotL64(aIngress, 29U)) + RotL64(aCarry, 43U)) + 2974056819475622600U) + aNonceWordO;
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 5U)) + 7345051759236356098U) + aNonceWordH;
            aOrbiterG = (((aWandererE + RotL64(aCross, 58U)) + RotL64(aCarry, 57U)) + 12738468816846628882U) + aNonceWordP;
            aOrbiterC = (((aWandererB + RotL64(aPrevious, 19U)) + 7694520596043297922U) + aPhaseGOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterE = (aWandererD + RotL64(aCross, 47U)) + 5530753590015084774U;
            aOrbiterI = (((aWandererC + RotL64(aScatter, 41U)) + RotL64(aCarry, 11U)) + 3776309161718383105U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = (aWandererG + RotL64(aPrevious, 11U)) + 784780304358106404U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 8999942326995036509U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 5194986506064092779U;
            aOrbiterG = RotL64((aOrbiterG * 15070787038006135963U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 7920040007459652762U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 11311997270710107937U;
            aOrbiterE = RotL64((aOrbiterE * 6227571709361790209U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 5365231114813547251U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 8630110234623825263U;
            aOrbiterF = RotL64((aOrbiterF * 2735881715888325759U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 2358235238039571072U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 18059414891616491807U;
            aOrbiterI = RotL64((aOrbiterI * 17150786106857185467U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 14526050556461782864U) + aNonceWordL;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 6937282036603272474U;
            aOrbiterH = RotL64((aOrbiterH * 14954512365270028029U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 10105832250694931310U) + aNonceWordI;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 3884223553012098137U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16340956813003906195U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 10385284339549648087U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 1257633893341505930U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2669950791270500977U), 29U);
            //
            aIngress = RotL64(aOrbiterA, 41U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterF, 3U)) + aOrbiterA) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aIngress, 57U) + aOrbiterA) + RotL64(aOrbiterC, 34U)) + RotL64(aCarry, 41U)) + aNonceWordB);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 43U)) + aOrbiterH) + aNonceWordE);
            aWandererD = aWandererD + ((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 27U)) + aOrbiterA);
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 5U) + RotL64(aOrbiterC, 57U)) + aOrbiterG) + aNonceWordD) + aPhaseGWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 20U) + aOrbiterE) + RotL64(aOrbiterI, 51U)) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 11U) + aOrbiterF) + RotL64(aOrbiterI, 13U)) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 60U));
            aCarry = aCarry + RotL64(aWandererJ, 37U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 21790U)) & S_BLOCK1], 3U) ^ RotL64(mSource[((aIndex + 21749U)) & S_BLOCK1], 23U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 20377U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19962U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 20024U)) & W_KEY1], 54U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 21840U)) & W_KEY1], 19U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 20548U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19174U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 10U) ^ RotL64(aIngress, 53U)) + (RotL64(aCross, 41U) ^ RotL64(aPrevious, 29U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterH = ((((aWandererH + RotL64(aCross, 29U)) + RotL64(aCarry, 35U)) + 11480359716598965890U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordH;
            aOrbiterI = (((aWandererA + RotL64(aIngress, 21U)) + RotL64(aCarry, 51U)) + 15431182525482873419U) + aNonceWordB;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 35U)) + RotL64(aCarry, 21U)) + 11360504974812776707U;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 4U)) + 9292576416573382769U) + aNonceWordG;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 53U)) + 1549257414531028975U) + aNonceWordN;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 11U)) + 5347769463033129317U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = (aWandererB + RotL64(aCross, 43U)) + 17019199177478377234U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 16558106007323125094U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 3976182233825939422U;
            aOrbiterB = RotL64((aOrbiterB * 4392162052317572289U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 2889047161195954395U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 2241831345026962605U;
            aOrbiterG = RotL64((aOrbiterG * 5757458560979927857U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 12850802412140579294U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 13541744735436450160U) ^ aNonceWordF;
            aOrbiterI = RotL64((aOrbiterI * 906089290000537439U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 2085863085516538212U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 2969034221711544086U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7768528124408400403U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 6482666944512391472U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 16969153556875844613U;
            aOrbiterJ = RotL64((aOrbiterJ * 9483462388353216219U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 5161314086757363678U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 7150282484670673211U) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 8522427002337918663U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 5465304381272305847U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 2344610773390354017U) ^ aNonceWordA;
            aOrbiterH = RotL64((aOrbiterH * 17010258514288089191U), 51U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterB, 35U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 6U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aIngress, 51U) + aOrbiterJ) + RotL64(aOrbiterH, 51U)) + aNonceWordD);
            aWandererG = aWandererG + ((RotL64(aCross, 43U) + RotL64(aOrbiterE, 5U)) + aOrbiterJ);
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterD, 44U)) + aNonceWordJ) + aPhaseGWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 58U) + aOrbiterD) + RotL64(aOrbiterJ, 11U)) + RotL64(aCarry, 47U)) + aNonceWordE);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 21U) + aOrbiterI) + RotL64(aOrbiterG, 37U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterI, 29U)) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 5U) + aOrbiterD) + RotL64(aOrbiterE, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (RotL64(aWandererI, 6U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 23670U)) & S_BLOCK1], 47U) ^ RotL64(aKeyRowReadA[((aIndex + 23285U)) & W_KEY1], 13U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 22163U)) & W_KEY1], 58U) ^ RotL64(aFireLaneC[((aIndex + 24173U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 22260U)) & S_BLOCK1], 50U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 22125U)) & S_BLOCK1], 29U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 22276U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneD[((aIndex + 22626U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 20U)) + (RotL64(aIngress, 37U) + RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterK = (aWandererG + RotL64(aPrevious, 21U)) + 14249093584376402677U;
            aOrbiterE = ((aWandererH + RotL64(aScatter, 48U)) + 8756965951816492264U) + aPhaseGOrbiterAssignSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aIngress, 57U)) + 11221139480258176330U) + aNonceWordF;
            aOrbiterF = ((aWandererD + RotL64(aCross, 41U)) + 17218894445564194851U) + aNonceWordI;
            aOrbiterC = ((((aWandererC + RotL64(aPrevious, 27U)) + RotL64(aCarry, 29U)) + 8064642692524949490U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = ((aWandererE + RotL64(aIngress, 13U)) + RotL64(aCarry, 51U)) + 5822093203710704646U;
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 3217799620158102238U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 2613757677892120843U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 13647481499551657237U;
            aOrbiterI = RotL64((aOrbiterI * 5517563514031899891U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 3545714196663685016U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 9735422670576621521U;
            aOrbiterK = RotL64((aOrbiterK * 7276207208162697249U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 3911046580637583767U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 9315984027042049203U;
            aOrbiterC = RotL64((aOrbiterC * 12568550776487242469U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 8926367674641729058U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 11035347490524961446U;
            aOrbiterE = RotL64((aOrbiterE * 10948288997163592463U), 35U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterD) + 10748158733051120339U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1]) + aNonceWordA;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 2467801787989056455U) ^ aNonceWordB;
            aOrbiterF = RotL64((aOrbiterF * 12621934274702358977U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 9244415080474351390U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 8517784887959492079U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17022899813765884147U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 8409307332803038455U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 11043806021873232950U) ^ aNonceWordK;
            aOrbiterD = RotL64((aOrbiterD * 8294888329708842989U), 3U);
            //
            aIngress = RotL64(aOrbiterK, 29U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + RotL64(aOrbiterD, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aCross, 3U) + RotL64(aOrbiterC, 48U)) + aOrbiterK);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 51U) + aOrbiterE) + RotL64(aOrbiterI, 23U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 41U)) + aOrbiterH) + RotL64(aCarry, 35U)) + aNonceWordD);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterD, 57U)) + aOrbiterF) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aScatter, 60U) + RotL64(aOrbiterH, 29U)) + aOrbiterI) + aNonceWordH) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 35U)) + aOrbiterF) + aNonceWordC);
            aWandererJ = aWandererJ + (((RotL64(aCross, 41U) + aOrbiterD) + RotL64(aOrbiterI, 11U)) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 41U));
            aCarry = aCarry + RotL64(aWandererD, 58U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 25773U)) & S_BLOCK1], 5U) ^ RotL64(aKeyRowReadA[((aIndex + 24793U)) & W_KEY1], 57U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 27171U)) & S_BLOCK1], 44U) ^ RotL64(aFireLaneB[((aIndex + 25157U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 25881U)) & W_KEY1], 39U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 24870U)) & S_BLOCK1], 48U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 26390U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneD[((aIndex + 25896U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCarry, 53U)) + (RotL64(aCross, 41U) ^ RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterD = (aWandererE + RotL64(aCross, 29U)) + 380024772508948442U;
            aOrbiterH = (((aWandererF + RotL64(aIngress, 23U)) + RotL64(aCarry, 19U)) + 7649029098162567210U) + aNonceWordH;
            aOrbiterB = (((aWandererC + RotL64(aPrevious, 5U)) + RotL64(aCarry, 37U)) + 5329304598870421851U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aScatter, 35U)) + RotL64(aCarry, 53U)) + 12306118665045151326U;
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 13U)) + 960751560457324256U) + aNonceWordC;
            aOrbiterA = (aWandererH + RotL64(aCross, 42U)) + 3244070254386191876U;
            aOrbiterC = ((aWandererI + RotL64(aScatter, 53U)) + 15733408571609521746U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 17623448932647018544U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 8787759896149035829U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7092515868845497573U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 14741681792348288162U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 8801731213568307302U) ^ aNonceWordP;
            aOrbiterA = RotL64((aOrbiterA * 12127126999570616489U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 9872248187499779222U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 15407371518644528235U) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 1245102406469471673U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 4242060317152943062U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 9942784962409917541U;
            aOrbiterC = RotL64((aOrbiterC * 888649755587764533U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 7296348796484458631U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 15061417216070157797U;
            aOrbiterF = RotL64((aOrbiterF * 10349554676953256231U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 3233185810644297433U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 9241229457641024287U;
            aOrbiterD = RotL64((aOrbiterD * 2728237515724597517U), 41U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterD) + 8464051359381554575U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1]) + aNonceWordI;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 3307872165699029375U) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 4859663401033023433U), 19U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterJ, 35U);
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterF, 23U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 51U) + RotL64(aOrbiterB, 14U)) + aOrbiterD) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterH, 29U));
            aWandererI = aWandererI + (((RotL64(aScatter, 19U) + aOrbiterH) + RotL64(aOrbiterB, 37U)) + RotL64(aCarry, 29U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 3U)) + aOrbiterD);
            aWandererA = aWandererA + ((((RotL64(aCross, 4U) + RotL64(aOrbiterJ, 23U)) + aOrbiterA) + aNonceWordJ) + aPhaseHWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterF, 43U));
            aWandererE = aWandererE + ((((RotL64(aPrevious, 43U) + aOrbiterC) + RotL64(aOrbiterF, 57U)) + aNonceWordL) + aPhaseHWandererUpdateSaltF[((aIndex + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (RotL64(aWandererE, 34U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 51U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 27461U)) & S_BLOCK1], 50U) ^ RotL64(aFireLaneD[((aIndex + 27905U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 28980U)) & W_KEY1], 19U) ^ RotL64(aFireLaneC[((aIndex + 29012U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 29346U)) & W_KEY1], 29U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29699U)) & S_BLOCK1], 48U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28112U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneB[((aIndex + 29906U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 26U) + RotL64(aPrevious, 39U)) + (RotL64(aCross, 11U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterA = (aWandererD + RotL64(aCross, 35U)) + 13204735390996728477U;
            aOrbiterI = (aWandererE + RotL64(aScatter, 5U)) + 851171359595647173U;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 20U)) + 16745304202825290723U) + aNonceWordN;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 29U)) + 562392736584913979U) + aNonceWordP;
            aOrbiterE = (((aWandererB + RotL64(aScatter, 47U)) + RotL64(aCarry, 29U)) + 3244267012529053918U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = ((((aWandererJ + RotL64(aCross, 11U)) + RotL64(aCarry, 47U)) + 17282536111067869133U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordD;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 57U)) + RotL64(aCarry, 5U)) + 14851130066471729068U;
            //
            aOrbiterA = (((aOrbiterA + aOrbiterI) + 5256130407952363129U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1]) + aNonceWordL;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 2904742485828362001U;
            aOrbiterG = RotL64((aOrbiterG * 12941135856735075457U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 3723346325449225387U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 5344621093694027341U) ^ aNonceWordC;
            aOrbiterE = RotL64((aOrbiterE * 9044881458629673499U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 12919263300833603026U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 17989801264160996071U;
            aOrbiterF = RotL64((aOrbiterF * 15468293047311883751U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 5022175042377172157U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 16684822380107847758U;
            aOrbiterA = RotL64((aOrbiterA * 2834049270263837537U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 2740326510600876682U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 13981423865219318820U) ^ aNonceWordO;
            aOrbiterB = RotL64((aOrbiterB * 14593082145080056441U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 231945878229848395U) + aNonceWordB;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 14139797734944312580U;
            aOrbiterK = RotL64((aOrbiterK * 6492256080432266407U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 16704102101387552373U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 8506734780526852552U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4684566118627414659U), 37U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterB, 29U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterK, 14U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterB, 29U)) + aOrbiterI) + aNonceWordF);
            aWandererD = aWandererD + ((((RotL64(aCross, 57U) + RotL64(aOrbiterB, 57U)) + aOrbiterG) + RotL64(aCarry, 41U)) + aNonceWordI);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 50U) + RotL64(aOrbiterF, 13U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterK, 44U)) + aOrbiterA) + RotL64(aCarry, 13U)) + aPhaseHWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 13U) + aOrbiterE) + RotL64(aOrbiterB, 35U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterI, 51U));
            aWandererB = aWandererB ^ ((((RotL64(aCross, 29U) + aOrbiterG) + RotL64(aOrbiterA, 23U)) + aNonceWordJ) + aPhaseHWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 58U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + RotL64(aWandererH, 21U);
            aCarry = aCarry + RotL64(aIngress, 4U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 32602U)) & S_BLOCK1], 43U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 31197U)) & W_KEY1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 31760U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30566U)) & S_BLOCK1], 27U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31031U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadB[((aIndex + 30794U)) & W_KEY1], 57U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCross, 35U)) ^ (RotL64(aCarry, 18U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterK = ((aWandererC + RotL64(aScatter, 29U)) + 18180797995100240808U) + aNonceWordD;
            aOrbiterJ = ((aWandererD + RotL64(aCross, 47U)) + RotL64(aCarry, 5U)) + 6585906608223552885U;
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 53U)) + 14088708930575939855U) + aPhaseHOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (((aWandererH + RotL64(aIngress, 41U)) + RotL64(aCarry, 23U)) + 468974153311516044U) + aNonceWordM;
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 5U)) + 12481951025619894110U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = (((aWandererK + RotL64(aScatter, 60U)) + RotL64(aCarry, 51U)) + 17227987923860711763U) + aNonceWordA;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 35U)) + 4373962756657477139U) + aNonceWordP;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 2077576476565420951U) + aNonceWordO;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 17435011300234663764U;
            aOrbiterC = RotL64((aOrbiterC * 8910133867294004711U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 4118039398293246896U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 13724716599855216683U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17556333902751079677U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 12391461204689596339U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 9900605191533799627U;
            aOrbiterD = RotL64((aOrbiterD * 13553565332531046301U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 972946858824366125U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 17247681919694541215U;
            aOrbiterK = RotL64((aOrbiterK * 2974639094630445643U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 15442851427306771601U) + aNonceWordC;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 7303586227288294037U;
            aOrbiterG = RotL64((aOrbiterG * 15406402525021428799U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 12650358753454105119U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 1483710933373510492U;
            aOrbiterH = RotL64((aOrbiterH * 6531763256577221891U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 18065810162229740788U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 11311677121338794007U;
            aOrbiterB = RotL64((aOrbiterB * 15116367961682119467U), 41U);
            //
            aIngress = RotL64(aOrbiterC, 27U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterD, 21U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + RotL64(aOrbiterK, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aPrevious, 58U) + aOrbiterC) + RotL64(aOrbiterB, 58U)) + RotL64(aCarry, 3U)) + aNonceWordJ);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 3U)) + aOrbiterK);
            aWandererC = aWandererC + ((RotL64(aCross, 19U) + aOrbiterH) + RotL64(aOrbiterC, 51U));
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 35U) + RotL64(aOrbiterB, 19U)) + aOrbiterG) + aNonceWordL) + aPhaseHWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 41U) + aOrbiterJ) + RotL64(aOrbiterD, 27U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterC, 41U)) + aNonceWordN);
            aWandererB = aWandererB + ((((RotL64(aCross, 5U) + aOrbiterK) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 37U)) + aPhaseHWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (RotL64(aWandererD, 4U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererA, 23U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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

void TwistExpander_FootBall_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xA0379A9DD8AE245FULL + 0xE2F871C2C896EF24ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xEBF9CCD6AD882A89ULL + 0xDD55C110A43C3C85ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xB77AAFA968BFAC6DULL + 0xA256A1D337E7A603ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x93BA351F1C37B961ULL + 0xB17C7520B5D2B009ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xCE88F3DA4B845365ULL + 0xB5893F8BE27643B1ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xF1496F2B74176E35ULL + 0xE6325CDAB2FA1CEFULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xFC918482EBA1CA29ULL + 0xDB22ACFDC8645FE5ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xDC2AF8A5AF1F90ADULL + 0xBD46616AA7CE9642ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xCF3D0EB18840D387ULL + 0xD5BCCCE7C3811B20ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xCD95D3F572EFE99FULL + 0xEF93587518464709ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xE6EEBC26B3E55903ULL + 0xCBF54A22A55D8405ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xF9615D52144ED5E7ULL + 0xA64ED3E3815C4CBFULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xFA5F70B0C881F87BULL + 0xB32994BE7F3FC16CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xE2DC074D3F01BD13ULL + 0xCE559ECF0A52F899ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xD61FF531718E683BULL + 0xA050BDD4D3A8F6DDULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xAEE0518F8FDCBF8BULL + 0xDCF6A1AB981860B8ULL);
    // GSeedRunSeed_B seed_loop_a (start)
    {
        // GSeedRunSeed_B seed_loop_a lane group
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneC, aExpandLaneC, aExpandLaneD, aInvestLaneA, aFireLaneD, aInvestLaneB, aFireLaneB, aOperationLaneA, aFireLaneA, aOperationLaneB, aOperationLaneC
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 1434U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((aIndex + 1763U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 4573U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 779U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 1458U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 24U) ^ RotL64(aIngress, 11U)) ^ (RotL64(aCarry, 39U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterB = ((aWandererD + RotL64(aScatter, 13U)) + RotL64(aCarry, 5U)) + 15045917390223766480U;
            aOrbiterA = (((aWandererG + RotL64(aPrevious, 3U)) + RotL64(aCarry, 21U)) + 10763054007033668758U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aCross, 22U)) + 13190170142593666607U) + aNonceWordA;
            aOrbiterH = (((aWandererA + RotL64(aIngress, 35U)) + RotL64(aCarry, 39U)) + 9657025731441167065U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = ((aWandererF + RotL64(aScatter, 51U)) + 11433367178975954211U) + aNonceWordB;
            //
            aOrbiterB = (((aOrbiterB + aOrbiterA) + 17904920143996810366U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordK;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 3244383020512113283U;
            aOrbiterG = RotL64((aOrbiterG * 552521443123433353U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 6538815775171139091U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 7195368312757976343U;
            aOrbiterA = RotL64((aOrbiterA * 10515679176134176565U), 11U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterG) + 18134430713910279374U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1]) + aNonceWordI;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 6571776588427107976U) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 11916502085252589161U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 11830778129647517758U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 9793702760907767365U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4096246227968677179U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 2287235876793192036U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 8951959188326141794U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9968356718110753845U), 3U);
            //
            aIngress = RotL64(aOrbiterG, 37U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterA, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 21U) + RotL64(aOrbiterI, 57U)) + aOrbiterB) + aNonceWordL) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererG = aWandererG + (((((RotL64(aPrevious, 5U) + RotL64(aOrbiterA, 22U)) + aOrbiterI) + RotL64(aCarry, 53U)) + aNonceWordJ) + aPhaseAWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 35U)) + aOrbiterA) + aNonceWordC);
            aWandererK = aWandererK + ((((RotL64(aCross, 51U) + RotL64(aOrbiterB, 43U)) + aOrbiterA) + RotL64(aCarry, 35U)) + aNonceWordF);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 34U) + aOrbiterG) + RotL64(aOrbiterB, 11U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + RotL64(aWandererG, 5U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aInvestLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 2
        // ingress from: aInvestLaneA, aExpandLaneC, aFireLaneD
        // ingress directions: aInvestLaneA forward forced, aExpandLaneC forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneA[((aIndex + 10738U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((aIndex + 5693U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 10498U)) & S_BLOCK1], 28U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 8072U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 8688U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 57U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCarry, 44U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 11U)) + 1210605127156905516U) + aNonceWordN;
            aOrbiterB = ((((aWandererH + RotL64(aPrevious, 29U)) + RotL64(aCarry, 57U)) + 11964595428173569519U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 3U)) + 16277319029916258482U) + aNonceWordG;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 20U)) + RotL64(aCarry, 43U)) + 12369497463101824572U;
            aOrbiterF = ((((aWandererA + RotL64(aIngress, 37U)) + RotL64(aCarry, 29U)) + 6201248574067068202U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordL;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 1727477025667206661U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 1404510627789806851U;
            aOrbiterC = RotL64((aOrbiterC * 4810039298122529021U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 6948213591282018925U) + aNonceWordF;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 6688865181284421478U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12619122841662247279U), 19U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterF) + 3351130769402360855U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1]) + aNonceWordD;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 12681032488906270823U;
            aOrbiterI = RotL64((aOrbiterI * 3680893896579741263U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 3591412591193726763U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 16153817571210878589U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4165137036092246349U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 3808228354421006630U) + aNonceWordP;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterF) ^ 1427373776207504205U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterJ = RotL64((aOrbiterJ * 4534374093769595531U), 53U);
            //
            aIngress = RotL64(aOrbiterI, 13U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterJ, 34U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterC, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 38U) + RotL64(aOrbiterB, 11U)) + aOrbiterF) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 29U)) + aOrbiterI) + RotL64(aCarry, 3U)) + aNonceWordM);
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterF, 60U)) + aNonceWordE) + aPhaseAWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aCross, 11U) + aOrbiterI) + RotL64(aOrbiterJ, 39U)) + RotL64(aCarry, 47U)) + aNonceWordA);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterJ, 21U)) + aOrbiterC) + aNonceWordO);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 56U));
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 12193U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((aIndex + 12400U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 13404U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 15296U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 12788U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 16358U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aPrevious, 37U) + RotL64(aCross, 5U)) ^ (RotL64(aIngress, 54U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterJ = (aWandererH + RotL64(aIngress, 3U)) + 12690502671561165478U;
            aOrbiterE = (((aWandererI + RotL64(aScatter, 57U)) + RotL64(aCarry, 11U)) + 17519943923428102801U) + aNonceWordK;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 39U)) + RotL64(aCarry, 53U)) + 10705515807975331385U;
            aOrbiterG = ((((aWandererK + RotL64(aCross, 26U)) + RotL64(aCarry, 39U)) + 16586447272278538179U) + aPhaseAOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1]) + aNonceWordE;
            aOrbiterK = (((aWandererC + RotL64(aIngress, 11U)) + 8006560996840971798U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordN;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 12928600185788857701U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterJ) ^ 14240723153798267172U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterC = RotL64((aOrbiterC * 7446040187505339853U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 8636219177994872072U) + aNonceWordA;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 7586790235186467512U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15052686382507614169U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 1103807034179512424U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 7547526530239498693U;
            aOrbiterK = RotL64((aOrbiterK * 3360295583636013509U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 8380239679344786397U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterE) ^ 5690809173787433519U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterG = RotL64((aOrbiterG * 5354724308093372953U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 8390902801141804609U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 3507306189192059486U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 18336280496510253103U), 19U);
            //
            aIngress = RotL64(aOrbiterE, 29U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterC, 56U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aIngress, 42U) + aOrbiterE) + RotL64(aOrbiterJ, 3U)) + aNonceWordG);
            aWandererA = aWandererA + (((((RotL64(aCross, 13U) + RotL64(aOrbiterG, 23U)) + aOrbiterC) + RotL64(aCarry, 5U)) + aNonceWordH) + aPhaseAWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterC, 41U)) + aOrbiterK);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterC, 57U)) + aOrbiterE) + RotL64(aCarry, 37U)) + aNonceWordI);
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 3U) + aOrbiterK) + RotL64(aOrbiterJ, 12U)) + aNonceWordM) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 36U));
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 4
        // ingress from: aOperationLaneA, aInvestLaneA, aFireLaneA
        // ingress directions: aOperationLaneA forward forced, aInvestLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aInvestLaneB, aExpandLaneD, aExpandLaneC
        // cross directions: aInvestLaneB backward forced, aExpandLaneD backward forced, aExpandLaneC backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 17215U)) & S_BLOCK1], 26U) ^ RotL64(aInvestLaneA[((aIndex + 20600U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 19731U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 17536U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18439U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 19340U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 37U) + RotL64(aIngress, 19U)) ^ (RotL64(aCross, 6U) + RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterA = (((aWandererG + RotL64(aPrevious, 43U)) + 3612110001869385068U) + aPhaseAOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1]) + aNonceWordI;
            aOrbiterC = (((aWandererK + RotL64(aScatter, 19U)) + RotL64(aCarry, 39U)) + 16340824141280225936U) + aNonceWordO;
            aOrbiterE = ((aWandererF + RotL64(aIngress, 29U)) + 15222338965130765231U) + aNonceWordJ;
            aOrbiterH = ((((aWandererC + RotL64(aCross, 54U)) + RotL64(aCarry, 23U)) + 6649270508107155041U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordN;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 11U)) + RotL64(aCarry, 5U)) + 768217258655426384U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 4481855259658861851U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 18318041934562434016U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14913761339765234979U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 4212457153804401807U) + aNonceWordL;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 16143621095636987628U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6576072860505961427U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 2095664232866642086U) + aNonceWordP;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 4339527736737366572U;
            aOrbiterC = RotL64((aOrbiterC * 17503569508822244125U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 13679353177869884790U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 11582168502846418236U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 135539430034462861U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 10451330452898542191U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 12951448817640617841U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4141870904192742091U), 41U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 26U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 47U)) + aOrbiterE) + RotL64(aCarry, 13U)) + aNonceWordE);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 39U) + aOrbiterC) + RotL64(aOrbiterE, 23U)) + aNonceWordB);
            aWandererI = aWandererI + (((RotL64(aIngress, 11U) + aOrbiterC) + RotL64(aOrbiterF, 11U)) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 19U) + aOrbiterA) + RotL64(aOrbiterC, 36U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aIngress, 52U) + RotL64(aOrbiterA, 57U)) + aOrbiterF) + aNonceWordG) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 56U));
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 23452U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((aIndex + 27193U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 22137U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 23617U)) & S_BLOCK1], 41U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 26156U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 26979U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 26U) + RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCross, 43U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterD = ((aWandererG + RotL64(aIngress, 3U)) + RotL64(aCarry, 13U)) + 15813325389431304548U;
            aOrbiterI = ((aWandererK + RotL64(aCross, 13U)) + 2223874171125403602U) + aPhaseAOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = (((aWandererI + RotL64(aScatter, 43U)) + RotL64(aCarry, 57U)) + 5510483568496824130U) + aNonceWordB;
            aOrbiterJ = ((((aWandererA + RotL64(aPrevious, 34U)) + RotL64(aCarry, 37U)) + 15474152493495661876U) + aPhaseAOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1]) + aNonceWordG;
            aOrbiterG = (aWandererC + RotL64(aIngress, 51U)) + 16846339705130829195U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 1289670576865739669U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 18017354919647006944U) ^ aNonceWordP;
            aOrbiterB = RotL64((aOrbiterB * 13103155460891498469U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 8539685539928984921U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 3333721400836704048U;
            aOrbiterD = RotL64((aOrbiterD * 3745286323481400085U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 2261560416623815491U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 4377786131746816567U) ^ aNonceWordO;
            aOrbiterI = RotL64((aOrbiterI * 9164777834392621157U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 18047393176583722719U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 8184724021940434631U) ^ aNonceWordN;
            aOrbiterG = RotL64((aOrbiterG * 9800116157750921119U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 10469895939183324807U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 14543391765109879223U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4817987697437667225U), 29U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterI, 47U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 13U)) + aOrbiterI) + aNonceWordC) + aPhaseAWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 50U) + RotL64(aOrbiterJ, 53U)) + aOrbiterB) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 37U) + RotL64(aOrbiterB, 30U)) + aOrbiterI) + aNonceWordM) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 21U)) + aOrbiterG) + RotL64(aCarry, 5U)) + aNonceWordF);
            aWandererA = aWandererA ^ (((RotL64(aCross, 11U) + aOrbiterB) + RotL64(aOrbiterG, 3U)) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + RotL64(aWandererI, 13U);
            aCarry = aCarry + RotL64(aIngress, 30U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 30271U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 27445U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 30912U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28116U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 32415U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 31890U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 39U)) ^ (RotL64(aPrevious, 27U) + RotL64(aCross, 52U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterG = (((aWandererE + RotL64(aCross, 41U)) + RotL64(aCarry, 19U)) + 14249093584376402677U) + aNonceWordM;
            aOrbiterD = ((((aWandererJ + RotL64(aScatter, 5U)) + RotL64(aCarry, 51U)) + 8756965951816492264U) + aPhaseAOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1]) + aNonceWordE;
            aOrbiterK = (((aWandererD + RotL64(aPrevious, 13U)) + RotL64(aCarry, 37U)) + 11221139480258176330U) + aPhaseAOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aIngress, 53U)) + 17218894445564194851U) + aNonceWordD;
            aOrbiterI = (aWandererG + RotL64(aCross, 22U)) + 8064642692524949490U;
            //
            aOrbiterG = (((aOrbiterG + aOrbiterD) + 5822093203710704646U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1]) + aNonceWordO;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 3217799620158102238U;
            aOrbiterK = RotL64((aOrbiterK * 2806328682494910635U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 2613757677892120843U) + aNonceWordC;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 13647481499551657237U;
            aOrbiterI = RotL64((aOrbiterI * 5517563514031899891U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 3545714196663685016U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 9735422670576621521U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7276207208162697249U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 3911046580637583767U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterI) ^ 9315984027042049203U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 12568550776487242469U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 8926367674641729058U) + aNonceWordP;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 11035347490524961446U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10948288997163592463U), 35U);
            //
            aIngress = RotL64(aOrbiterG, 41U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + RotL64(aOrbiterE, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aCross, 51U) + RotL64(aOrbiterI, 37U)) + aOrbiterK) + RotL64(aCarry, 19U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterE, 47U)) + aOrbiterD);
            aWandererD = aWandererD + (((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterE, 19U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 5U) + aOrbiterD) + RotL64(aOrbiterI, 58U)) + aNonceWordG);
            aWandererC = aWandererC + ((((RotL64(aScatter, 60U) + aOrbiterG) + RotL64(aOrbiterE, 27U)) + RotL64(aCarry, 41U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 30U));
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 3U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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

void TwistExpander_FootBall_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xA2594FE24B428027ULL + 0x921606B16B74A876ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x9F7E7C611E4C9B51ULL + 0xF2DD6FEA1533FE0DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x9221BF6F07AE6463ULL + 0xD3C7D8D66D23BF7FULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xFA61B952A68889F5ULL + 0xB70C262DE6EC0C85ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xAC94AB2AEF8E3599ULL + 0xC4432220DA1F7ACAULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xB9A9A5B96BA19E73ULL + 0x9941CE14E48986EDULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xD9E597680D5912B3ULL + 0x97D2A364892D6EC4ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xCC39308482BA4E2FULL + 0x862191693B88062AULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xA73E67130A409F49ULL + 0xCA3C4E7AF858A0C6ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xCCB866C99682FA41ULL + 0xC8D58C4FE4D37845ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xC59CA0CD74478C99ULL + 0x99785341026C6E26ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xA3B1CB9B2AC25787ULL + 0xE7317D5522FB29ECULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xC3F9BB129B917D83ULL + 0xC9049BB9E96FA4D2ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xE5DEC369B8203367ULL + 0x95E3316F5C842147ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x8B456C698C052BC3ULL + 0xF0770A6EA64A34BDULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xB668F2D8B3C926D9ULL + 0x9738D25184F7EC55ULL);
    // GSeedRunSeed_C seed_loop_b (start)
    {
        // GSeedRunSeed_C seed_loop_b lane group
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneA, aOperationLaneC, aOperationLaneD, aFireLaneD, aInvestLaneC, aExpandLaneC, aExpandLaneA, aInvestLaneD, aFireLaneC, aWorkLaneA, aExpandLaneB, aWorkLaneB, aExpandLaneD, aWorkLaneC, aFireLaneB
        // write to: aInvestLaneC, aInvestLaneD, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // seed_loop_b loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aFireLaneD
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aFireLaneD backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 1493U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((aIndex + 115U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 840U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 5194U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 3840U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 1622U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 35U)) + (RotL64(aCarry, 20U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterJ = ((aWandererA + RotL64(aCross, 47U)) + 7948891781097675369U) + aNonceWordI;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 14U)) + RotL64(aCarry, 21U)) + 13928362874228230226U;
            aOrbiterD = (aWandererJ + RotL64(aScatter, 23U)) + 10776180542602258926U;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 39U)) + 5735115172149470447U) + aNonceWordL;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 27U)) + 5353591822981766987U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = ((aWandererG + RotL64(aCross, 19U)) + 562301708107268570U) + aPhaseBOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = (aWandererC + RotL64(aPrevious, 56U)) + 10467810247578364868U;
            aOrbiterH = ((aWandererK + RotL64(aIngress, 43U)) + RotL64(aCarry, 57U)) + 14541630141152308564U;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 51U)) + RotL64(aCarry, 11U)) + 2350076897065139429U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 17519109078651162228U) + aNonceWordN;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 6061035173339902910U;
            aOrbiterD = RotL64((aOrbiterD * 10021905773432907835U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 15654836633731000065U) + aNonceWordE;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 13723521735153718904U) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 14459516479283070563U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 2849680038315532197U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 17336102435576647923U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10984689101753586739U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 7671010488872356142U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 11485114338165600777U;
            aOrbiterE = RotL64((aOrbiterE * 4162584865462407791U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 8759060657343458985U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 11009137869375286581U;
            aOrbiterH = RotL64((aOrbiterH * 8741417343929809115U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 15792999392743144135U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 6180808423175992479U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13681230339693676907U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 361487389591183005U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 15292753806514404853U) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 17478232597253311153U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 14929153438443362045U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 7904556383593914086U;
            aOrbiterG = RotL64((aOrbiterG * 2484130486635511403U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 3793180909904286848U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 10391957637467171320U;
            aOrbiterI = RotL64((aOrbiterI * 505484041943467117U), 11U);
            //
            aIngress = RotL64(aOrbiterJ, 19U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterI, 41U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterE, 10U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aIngress, 41U) + aOrbiterG) + RotL64(aOrbiterE, 22U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 23U) + aOrbiterJ) + RotL64(aOrbiterI, 43U)) + aNonceWordB);
            aWandererG = aWandererG + ((RotL64(aPrevious, 58U) + RotL64(aOrbiterJ, 35U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 27U) + aOrbiterH) + RotL64(aOrbiterC, 57U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 48U)) + aOrbiterG);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterC, 39U)) + aOrbiterG);
            aWandererF = aWandererF + (((RotL64(aScatter, 5U) + RotL64(aOrbiterD, 11U)) + aOrbiterH) + RotL64(aCarry, 37U));
            aWandererK = aWandererK ^ ((((RotL64(aCross, 53U) + aOrbiterF) + RotL64(aOrbiterC, 29U)) + aNonceWordM) + aPhaseBWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 12U) + aOrbiterD) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 19U)) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 26U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aInvestLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 2
        // ingress from: aInvestLaneC, aOperationLaneC, aOperationLaneD, aExpandLaneC
        // ingress directions: aInvestLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aExpandLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aExpandLaneA
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aExpandLaneA backward/forward random
        // write to: aInvestLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 5726U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneC[((aIndex + 6306U)) & S_BLOCK1], 4U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 6321U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((aIndex + 9450U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 8002U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7368U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 5679U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 54U) ^ RotL64(aCross, 21U)) + (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterH = (aWandererF + RotL64(aScatter, 57U)) + 6654158889644956636U;
            aOrbiterF = ((((aWandererI + RotL64(aIngress, 19U)) + RotL64(aCarry, 51U)) + 9045779659363991870U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordL;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 3U)) + 3888897662136993491U) + aNonceWordE;
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 46U)) + RotL64(aCarry, 21U)) + 6882016842864459345U;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 13U)) + 15601891715956172291U) + aPhaseBOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aPrevious, 53U)) + 5176811598629335350U;
            aOrbiterK = ((aWandererB + RotL64(aCross, 29U)) + RotL64(aCarry, 3U)) + 12519945150889074325U;
            aOrbiterG = (aWandererK + RotL64(aScatter, 41U)) + 4552583214397603278U;
            aOrbiterC = ((aWandererC + RotL64(aIngress, 24U)) + 14225482701804864688U) + aNonceWordF;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 5485298070606280363U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 11237713257388094289U;
            aOrbiterJ = RotL64((aOrbiterJ * 11032429223099413011U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 14340345895626142788U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 16275167270553643347U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7308578867128951199U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 14041860597556520250U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 1436068974197066343U;
            aOrbiterB = RotL64((aOrbiterB * 3938460345031496843U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 11483155566419547004U) + aNonceWordC;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 4608508534724289325U;
            aOrbiterF = RotL64((aOrbiterF * 13461385011638899485U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 2389196334288832895U) + aNonceWordK;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 4062682330273866602U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8787682133271101901U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 5655656046585592034U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 7977947821249746880U;
            aOrbiterC = RotL64((aOrbiterC * 10082104644185964787U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 11653718118543974168U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 5456429682072377614U;
            aOrbiterH = RotL64((aOrbiterH * 12504180638665296649U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 12457179652004203574U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 445821754230182952U;
            aOrbiterG = RotL64((aOrbiterG * 16043092621697786393U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 12429505513284703263U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterB) ^ 12480745784412363537U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterK = RotL64((aOrbiterK * 643617210585287593U), 3U);
            //
            aIngress = RotL64(aOrbiterJ, 4U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 19U));
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterG, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aIngress, 13U) + aOrbiterG) + RotL64(aOrbiterC, 37U)) + aNonceWordJ);
            aWandererI = aWandererI + ((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 6U)) + aOrbiterF);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 30U) + RotL64(aOrbiterE, 11U)) + aOrbiterJ) + aNonceWordH);
            aWandererD = aWandererD + ((((RotL64(aCross, 53U) + RotL64(aOrbiterF, 23U)) + aOrbiterH) + RotL64(aCarry, 21U)) + aNonceWordN);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 57U)) + aOrbiterJ);
            aWandererB = aWandererB + (((RotL64(aIngress, 47U) + RotL64(aOrbiterC, 51U)) + aOrbiterB) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 5U) + aOrbiterB) + RotL64(aOrbiterK, 18U)) + aNonceWordA) + aPhaseBWandererUpdateSaltA[((aIndex + 14U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterI, 29U)) + aPhaseBWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 34U) + RotL64(aOrbiterJ, 43U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 54U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererI, 43U);
            aCarry = aCarry + RotL64(aIngress, 36U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aInvestLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_b loop 3
        // ingress from: aInvestLaneD, aOperationLaneA, aFireLaneC
        // ingress directions: aInvestLaneD forward forced, aOperationLaneA forward forced, aFireLaneC forward/backward random
        // cross from: aInvestLaneC, aOperationLaneC
        // cross directions: aInvestLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneD[((aIndex + 14915U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneA[((aIndex + 14249U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 15806U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 11901U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneC[((aIndex + 11602U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 37U) + RotL64(aIngress, 53U)) ^ (RotL64(aPrevious, 22U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterK = ((aWandererH + RotL64(aCross, 40U)) + 18087125778766689269U) + aNonceWordO;
            aOrbiterG = ((aWandererB + RotL64(aScatter, 13U)) + 13710545066503235196U) + aNonceWordP;
            aOrbiterA = (aWandererF + RotL64(aIngress, 23U)) + 1701939704736254645U;
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 3U)) + 8064093611384019909U) + aPhaseBOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = ((aWandererK + RotL64(aScatter, 57U)) + 16623332751533885431U) + aPhaseBOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = (((aWandererI + RotL64(aCross, 27U)) + RotL64(aCarry, 21U)) + 15590129153794910109U) + aNonceWordI;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 18U)) + RotL64(aCarry, 47U)) + 7413312683079107383U;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 47U)) + RotL64(aCarry, 29U)) + 4186064478651458810U;
            aOrbiterI = (aWandererC + RotL64(aScatter, 51U)) + 5501191643940735954U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 11064645242200570835U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 13825922087298055833U;
            aOrbiterA = RotL64((aOrbiterA * 7529317892716108867U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 5944980709887369970U) + aNonceWordL;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 8181136916070569646U;
            aOrbiterD = RotL64((aOrbiterD * 395183021205661827U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 15442336949157292482U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 11580554435240641337U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6654637892858767739U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 11240018128174598322U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 2027565596050777471U;
            aOrbiterF = RotL64((aOrbiterF * 18048186560314431815U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 16425887196883725233U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 16828683527588834095U;
            aOrbiterI = RotL64((aOrbiterI * 17746289103235902485U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 9923829146479008804U) + aNonceWordG;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 6669171007279929454U;
            aOrbiterE = RotL64((aOrbiterE * 681823450939955099U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 3902430046523165149U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 6739998149289590041U;
            aOrbiterG = RotL64((aOrbiterG * 2675037435528416821U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 16014401255534234075U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 14741857638680634564U) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 8723611021403369393U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 5064807861673260054U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 968747317273200299U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14122304002722582329U), 53U);
            //
            aIngress = RotL64(aOrbiterI, 29U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterF, 18U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 43U) + RotL64(aOrbiterD, 35U)) + aOrbiterA) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 34U) + RotL64(aOrbiterE, 5U)) + aOrbiterK);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterB, 60U)) + aOrbiterE) + RotL64(aCarry, 57U)) + aNonceWordA);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 27U)) + aOrbiterK) + aNonceWordM);
            aWandererI = aWandererI + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 39U)) + aOrbiterB) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 39U) + aOrbiterD) + RotL64(aOrbiterJ, 13U));
            aWandererC = aWandererC + (((RotL64(aIngress, 47U) + RotL64(aOrbiterD, 21U)) + aOrbiterB) + aNonceWordK);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 26U) + aOrbiterA) + RotL64(aOrbiterI, 43U)) + aNonceWordC);
            aWandererH = aWandererH + (((RotL64(aPrevious, 21U) + aOrbiterD) + RotL64(aOrbiterG, 50U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 30U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + RotL64(aWandererK, 51U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 4
        // ingress from: aWorkLaneA, aInvestLaneC, aExpandLaneB
        // ingress directions: aWorkLaneA forward forced, aInvestLaneC forward forced, aExpandLaneB forward/backward random
        // cross from: aInvestLaneD, aOperationLaneD
        // cross directions: aInvestLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 20996U)) & S_BLOCK1], 43U) ^ RotL64(aInvestLaneC[((aIndex + 21468U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 18498U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 18681U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 21725U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 27U) ^ RotL64(aCross, 41U)) + (RotL64(aIngress, 10U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterH = ((aWandererH + RotL64(aScatter, 35U)) + 9023059520606551446U) + aNonceWordK;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 47U)) + RotL64(aCarry, 43U)) + 662441755115638133U;
            aOrbiterA = ((aWandererK + RotL64(aCross, 14U)) + 16957253361196144712U) + aNonceWordE;
            aOrbiterC = (aWandererE + RotL64(aPrevious, 51U)) + 7840955025765308605U;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 57U)) + RotL64(aCarry, 23U)) + 346855809270395799U;
            aOrbiterI = (aWandererD + RotL64(aIngress, 43U)) + 16099139781586668343U;
            aOrbiterF = (((aWandererA + RotL64(aPrevious, 39U)) + RotL64(aCarry, 53U)) + 3706457327118322098U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aCross, 19U)) + 12166825885547622870U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = ((aWandererC + RotL64(aScatter, 24U)) + 7792658665720344200U) + aNonceWordH;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 7128477606152986326U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 11116533962780290084U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11993485572912492297U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 10443889548568288532U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 4402387036946561017U;
            aOrbiterH = RotL64((aOrbiterH * 9032964741841833277U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 13002706161178447654U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 13929727277530310708U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7005639090871200285U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 10949073760696935106U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 15405923432006783533U;
            aOrbiterC = RotL64((aOrbiterC * 17989565878445202495U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 18096057968822208905U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 3032155040484574973U;
            aOrbiterE = RotL64((aOrbiterE * 448597307502544605U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 17462076466907467134U) + aNonceWordC;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 15471015427013701406U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6113474000571976139U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 3549031751266594344U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 14243218483842508113U;
            aOrbiterJ = RotL64((aOrbiterJ * 9041601306479302047U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 5803147589312920032U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterJ) ^ 5549470512227427855U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterK = RotL64((aOrbiterK * 12592362489263862879U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 10076661824293832189U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 3196799148974716550U;
            aOrbiterI = RotL64((aOrbiterI * 8183276968961467775U), 19U);
            //
            aIngress = RotL64(aOrbiterF, 26U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterG, 43U)) + aOrbiterE);
            aWandererF = aWandererF + (((RotL64(aPrevious, 18U) + aOrbiterF) + RotL64(aOrbiterI, 34U)) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterH, 29U)) + aOrbiterK);
            aWandererB = aWandererB + (((RotL64(aIngress, 5U) + RotL64(aOrbiterG, 3U)) + aOrbiterC) + aNonceWordI);
            aWandererA = aWandererA ^ ((RotL64(aCross, 23U) + aOrbiterJ) + RotL64(aOrbiterF, 51U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterJ, 14U)) + RotL64(aCarry, 19U)) + aPhaseBWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 39U)) + aOrbiterE) + aNonceWordJ);
            aWandererH = aWandererH + (((RotL64(aScatter, 37U) + RotL64(aOrbiterA, 57U)) + aOrbiterF) + aPhaseBWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 48U) + aOrbiterJ) + RotL64(aOrbiterG, 19U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 58U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 54U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_b loop 5
        // ingress from: aWorkLaneB, aInvestLaneD, aExpandLaneD
        // ingress directions: aWorkLaneB forward forced, aInvestLaneD forward forced, aExpandLaneD forward/backward random
        // cross from: aWorkLaneA, aInvestLaneC
        // cross directions: aWorkLaneA backward forced, aInvestLaneC backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 26590U)) & S_BLOCK1], 35U) ^ RotL64(aInvestLaneD[((aIndex + 22601U)) & S_BLOCK1], 46U));
            aIngress ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 23095U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25535U)) & S_BLOCK1], 53U) ^ RotL64(aInvestLaneC[((aIndex + 26426U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCarry, 37U)) ^ (RotL64(aIngress, 24U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 57U)) + 4848316479321533394U) + aNonceWordG;
            aOrbiterF = ((((aWandererA + RotL64(aIngress, 35U)) + RotL64(aCarry, 43U)) + 6919360256662636195U) + aPhaseBOrbiterAssignSaltF[((aIndex + 18U)) & S_SALT1]) + aNonceWordB;
            aOrbiterD = ((aWandererJ + RotL64(aCross, 23U)) + RotL64(aCarry, 29U)) + 9897013582181108544U;
            aOrbiterC = (aWandererC + RotL64(aScatter, 12U)) + 7319353809896158678U;
            aOrbiterB = (aWandererE + RotL64(aPrevious, 29U)) + 2848175435514849859U;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 39U)) + 6967780718720437934U) + aNonceWordF;
            aOrbiterG = (aWandererB + RotL64(aScatter, 47U)) + 10143884766603388136U;
            aOrbiterK = ((aWandererF + RotL64(aCross, 43U)) + 8675965006150972051U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = (((aWandererG + RotL64(aScatter, 52U)) + RotL64(aCarry, 21U)) + 16350117755560994281U) + aNonceWordK;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 17976597517118423760U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 1399631141355370237U;
            aOrbiterD = RotL64((aOrbiterD * 16537788276543236833U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 3590613762034716792U) + aNonceWordL;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 5134624314245932157U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13077589037975283371U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 10082236952942943654U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 4015535035905433450U;
            aOrbiterF = RotL64((aOrbiterF * 4961808568701908559U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 611474103801573800U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 5786708483794098001U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7694007039340089267U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 5201943497363274455U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 9282160506938328489U) ^ aNonceWordA;
            aOrbiterH = RotL64((aOrbiterH * 5368182164239021367U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 4932320527498940158U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 11576526341731392916U) ^ aNonceWordJ;
            aOrbiterK = RotL64((aOrbiterK * 1712051774729439363U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 10790691517638887125U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 16280649213607464422U;
            aOrbiterC = RotL64((aOrbiterC * 10756733801499471873U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 9553716940667712810U) + aNonceWordE;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 11827518270964003341U;
            aOrbiterE = RotL64((aOrbiterE * 1322489827908132831U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 16777463701235809321U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 3375489084588454149U;
            aOrbiterB = RotL64((aOrbiterB * 3335010977457647307U), 43U);
            //
            aIngress = RotL64(aOrbiterD, 21U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 54U));
            aIngress = aIngress + (RotL64(aOrbiterB, 11U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterC, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aCross, 3U) + RotL64(aOrbiterG, 12U)) + aOrbiterK);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 23U)) + aOrbiterH) + aNonceWordI);
            aWandererB = aWandererB + (((RotL64(aIngress, 60U) + aOrbiterC) + RotL64(aOrbiterE, 47U)) + RotL64(aCarry, 37U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterG, 57U)) + aOrbiterC);
            aWandererC = aWandererC + ((((RotL64(aCross, 13U) + RotL64(aOrbiterH, 5U)) + aOrbiterB) + RotL64(aCarry, 3U)) + aNonceWordP);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 39U) + aOrbiterJ) + RotL64(aOrbiterC, 35U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterH, 39U)) + aPhaseBWandererUpdateSaltD[((aIndex + 12U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 24U) + aOrbiterC) + RotL64(aOrbiterH, 27U)) + aPhaseBWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 29U) + RotL64(aOrbiterH, 18U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 40U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererI, 13U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 6
        // ingress from: aWorkLaneC, aWorkLaneA, aFireLaneB
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aFireLaneB forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 32265U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 30394U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 31489U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27746U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27984U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 13U) + RotL64(aIngress, 26U)) ^ (RotL64(aPrevious, 57U) ^ RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterG = ((aWandererD + RotL64(aScatter, 39U)) + RotL64(aCarry, 27U)) + 13481227414590594621U;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 30U)) + 17425964381118918026U;
            aOrbiterD = ((aWandererI + RotL64(aCross, 53U)) + RotL64(aCarry, 3U)) + 4792004356135956581U;
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 23U)) + 11926849936000639098U) + aNonceWordI;
            aOrbiterI = ((aWandererB + RotL64(aCross, 47U)) + 990697329347742142U) + aNonceWordE;
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 4U)) + 9307721505373076588U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 57U)) + RotL64(aCarry, 19U)) + 17605732738841908719U;
            aOrbiterH = (aWandererH + RotL64(aScatter, 11U)) + 13110764518634187439U;
            aOrbiterK = ((aWandererG + RotL64(aCross, 43U)) + 17970109897810645911U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 10273133817644703654U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 11239046688920468137U;
            aOrbiterD = RotL64((aOrbiterD * 5197802934333553327U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 8355821483275763145U) + aNonceWordP;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 15522151127786049345U;
            aOrbiterI = RotL64((aOrbiterI * 4844278537850520413U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 5381663179722418112U) + aNonceWordH;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 9551368011768104906U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14202470972121732997U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 16264476585232221270U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 7721417776432288282U;
            aOrbiterF = RotL64((aOrbiterF * 10267770327791051869U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 339418090653475277U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 3247926250495935511U) ^ aNonceWordF;
            aOrbiterJ = RotL64((aOrbiterJ * 16824669543765729097U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 3390560045236418590U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 3894024951542543635U;
            aOrbiterE = RotL64((aOrbiterE * 10599637790900418767U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 3878539166189668154U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 5617705593218220843U;
            aOrbiterG = RotL64((aOrbiterG * 82771190372750823U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 12320861089148474544U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 14943790251625519550U;
            aOrbiterH = RotL64((aOrbiterH * 13758322022902008313U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 18119213517612562775U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = (((aOrbiterK ^ aOrbiterJ) ^ 1413193144229486646U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterK = RotL64((aOrbiterK * 14562375280658115687U), 51U);
            //
            aIngress = RotL64(aOrbiterG, 29U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterH, 4U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterF, 18U)) + aOrbiterD) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 56U) + RotL64(aOrbiterE, 27U)) + aOrbiterK);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterK, 35U)) + aOrbiterG) + aNonceWordD);
            aWandererA = aWandererA + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterJ, 3U)) + aOrbiterG);
            aWandererD = aWandererD ^ ((RotL64(aCross, 13U) + aOrbiterJ) + RotL64(aOrbiterA, 47U));
            aWandererC = aWandererC + (((RotL64(aScatter, 37U) + aOrbiterF) + RotL64(aOrbiterH, 43U)) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterA, 12U)) + aOrbiterH);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 24U) + aOrbiterI) + RotL64(aOrbiterD, 23U)) + RotL64(aCarry, 23U)) + aPhaseBWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterI, 51U)) + aOrbiterA) + aNonceWordO);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + RotL64(aWandererG, 28U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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

void TwistExpander_FootBall_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xD340574BEE426AE7ULL + 0xD87762A95B832593ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xC0D862703791F4C5ULL + 0xCF48370B9B20A860ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xFB00C6EE72D8810DULL + 0x83F487DC8BC31C86ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x9C7D7093EDF3B531ULL + 0x90A0753AF73D6EBEULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xC83E3C779E0DF619ULL + 0xD1E6CC61EF244364ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x8615FDA6FC5F4C25ULL + 0x8E9A46EBB6CF81DFULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x9511845FE0162E45ULL + 0x960976514220FEF3ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xE1594E4BA033FFF9ULL + 0xC9AD3436010D664BULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xAB01686684B7316FULL + 0xC067A754EE3923ADULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xA15A081F0F29ED5FULL + 0xC46B1CBD178D104DULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xA1D3D24EFE91A39BULL + 0xF191ACCB972CE7C6ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x9FCA8D4F193E54D5ULL + 0x93C87B913C3B5CEAULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x9687247FDF1693BBULL + 0x92CF8D55E927AD85ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xBEA2B1F7F8831CC5ULL + 0xA90C74778B6D1033ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xF4499F76D6A243FFULL + 0x8B81D4C07627B063ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xE591E120735285D3ULL + 0xC022C3BAAA8A19FEULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 1697U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((aIndex + 4368U)) & S_BLOCK1], 12U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 4100U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2894U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 4766U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 3615U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCross, 19U)) + (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 6U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 35U)) + 11480359716598965890U) + aPhaseDOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aCross, 3U)) + 15431182525482873419U;
            aOrbiterB = ((((aWandererB + RotL64(aIngress, 13U)) + RotL64(aCarry, 21U)) + 11360504974812776707U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordG;
            aOrbiterJ = (((aWandererH + RotL64(aScatter, 21U)) + RotL64(aCarry, 37U)) + 9292576416573382769U) + aNonceWordN;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 51U)) + RotL64(aCarry, 3U)) + 1549257414531028975U;
            aOrbiterH = (aWandererE + RotL64(aScatter, 60U)) + 5347769463033129317U;
            aOrbiterG = (aWandererC + RotL64(aCross, 41U)) + 17019199177478377234U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 16558106007323125094U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 3976182233825939422U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4392162052317572289U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 2889047161195954395U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 2241831345026962605U;
            aOrbiterC = RotL64((aOrbiterC * 5757458560979927857U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 12850802412140579294U) + aNonceWordB;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 13541744735436450160U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 906089290000537439U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 2085863085516538212U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 2969034221711544086U;
            aOrbiterH = RotL64((aOrbiterH * 7768528124408400403U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 6482666944512391472U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 16969153556875844613U;
            aOrbiterJ = RotL64((aOrbiterJ * 9483462388353216219U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 5161314086757363678U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 7150282484670673211U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8522427002337918663U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 5465304381272305847U) + aNonceWordC;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 2344610773390354017U;
            aOrbiterK = RotL64((aOrbiterK * 17010258514288089191U), 43U);
            //
            aIngress = RotL64(aOrbiterK, 53U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 23U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 60U));
            aIngress = aIngress + RotL64(aOrbiterC, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 21U)) + aOrbiterB);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterB, 5U)) + aOrbiterK) + aNonceWordH);
            aWandererC = aWandererC + (((((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 27U)) + aOrbiterH) + RotL64(aCarry, 19U)) + aNonceWordM) + aPhaseDWandererUpdateSaltA[((aIndex + 12U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterG, 35U)) + aOrbiterK) + aNonceWordF);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 21U) + aOrbiterB) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 3U)) + aNonceWordI);
            aWandererA = aWandererA ^ ((RotL64(aCross, 54U) + RotL64(aOrbiterK, 12U)) + aOrbiterA);
            aWandererD = aWandererD + (((RotL64(aIngress, 13U) + aOrbiterJ) + RotL64(aOrbiterC, 47U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 10U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 8924U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((aIndex + 6508U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 6535U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 6197U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 7486U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9984U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 7533U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCarry, 37U)) ^ (RotL64(aPrevious, 18U) ^ RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterE = (aWandererD + RotL64(aCross, 47U)) + 2617613537256538553U;
            aOrbiterK = ((((aWandererH + RotL64(aScatter, 29U)) + RotL64(aCarry, 19U)) + 16642868916835132715U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordE;
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 23U)) + 10860291124337073254U) + aNonceWordC;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 37U)) + 6432511273906902472U;
            aOrbiterB = (aWandererJ + RotL64(aCross, 54U)) + 7505375005848241910U;
            aOrbiterF = ((((aWandererC + RotL64(aPrevious, 13U)) + RotL64(aCarry, 51U)) + 11086616004678821329U) + aPhaseDOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1]) + aNonceWordN;
            aOrbiterC = (((aWandererB + RotL64(aIngress, 3U)) + RotL64(aCarry, 5U)) + 3298830587569881951U) + aNonceWordO;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 9775143140064220979U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 4147601326580823120U;
            aOrbiterH = RotL64((aOrbiterH * 13462244678782260871U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 12245920269898100415U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 8391940489176734499U) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 9119606167674098007U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 17876893379544668477U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 18301882058180370541U;
            aOrbiterE = RotL64((aOrbiterE * 16680384667098921309U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 6869225862715140102U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 15404118372589259800U;
            aOrbiterK = RotL64((aOrbiterK * 5766851935950389915U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 17757381020518233814U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 17677969146092374455U;
            aOrbiterC = RotL64((aOrbiterC * 3469432916562405063U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 15783378556632870114U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterC) ^ 5792858258663697864U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 12008981883482080427U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 11737803388202260296U) + aNonceWordP;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 16001927091970715330U;
            aOrbiterF = RotL64((aOrbiterF * 3062030309852922061U), 21U);
            //
            aIngress = RotL64(aOrbiterF, 35U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterC, 18U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + RotL64(aOrbiterE, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 34U) + aOrbiterE) + RotL64(aOrbiterH, 5U)) + aNonceWordL);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 3U)) + aNonceWordA);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 41U) + aOrbiterJ) + RotL64(aOrbiterF, 23U));
            aWandererH = aWandererH + ((((RotL64(aScatter, 21U) + aOrbiterE) + RotL64(aOrbiterC, 54U)) + RotL64(aCarry, 53U)) + aPhaseDWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterB, 47U)) + aOrbiterK);
            aWandererK = aWandererK + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 35U)) + aOrbiterB) + aNonceWordK) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterH, 41U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + (RotL64(aWandererI, 50U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 13193U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneA[((aIndex + 15315U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 12984U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 11070U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15926U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCarry, 20U)) ^ (RotL64(aCross, 5U) + RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterI = (((aWandererG + RotL64(aCross, 23U)) + RotL64(aCarry, 29U)) + 3550722402315312207U) + aNonceWordA;
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 53U)) + 16724184551669522754U;
            aOrbiterB = (aWandererK + RotL64(aPrevious, 29U)) + 981751330116773021U;
            aOrbiterA = (((aWandererD + RotL64(aIngress, 11U)) + RotL64(aCarry, 11U)) + 7891159229704944868U) + aPhaseDOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aPrevious, 35U)) + 13618396711464799841U;
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 48U)) + 5969291018449003648U) + aNonceWordB;
            aOrbiterK = ((aWandererH + RotL64(aCross, 41U)) + 14595540413313640042U) + aPhaseDOrbiterAssignSaltF[((aIndex + 20U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 3287990436916111762U) + aNonceWordN;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 12534369400200483704U;
            aOrbiterB = RotL64((aOrbiterB * 2345945228434740707U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 2277312067930392274U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 10026320559261334353U;
            aOrbiterH = RotL64((aOrbiterH * 11020464940995912637U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 11258082063135659551U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 1445958517675746990U;
            aOrbiterI = RotL64((aOrbiterI * 10062265337488757971U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 1011298251290970844U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 6487834862470043744U;
            aOrbiterJ = RotL64((aOrbiterJ * 15477913837027179675U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 9966279022928268335U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 10285993486057704393U;
            aOrbiterK = RotL64((aOrbiterK * 15965714363201157535U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 16005362468813966136U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterJ) ^ 223843444699390781U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterA = RotL64((aOrbiterA * 665392038954573081U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 18178876294968532775U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 12490136112181806806U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16380841616662993709U), 57U);
            //
            aIngress = RotL64(aOrbiterH, 41U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterI, 26U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + RotL64(aOrbiterF, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 19U)) + aOrbiterA) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 3U) + RotL64(aOrbiterF, 36U)) + aOrbiterI) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterK, 57U)) + aOrbiterH) + aNonceWordK);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterJ, 27U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 12U) + aOrbiterH) + RotL64(aOrbiterF, 47U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 37U)) + aNonceWordP);
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 35U) + RotL64(aOrbiterB, 3U)) + aOrbiterH) + aNonceWordM) + aPhaseDWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 38U));
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererA, 53U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 20997U)) & S_BLOCK1], 11U) ^ RotL64(aSnowLaneA[((aIndex + 19067U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 17128U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 16649U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((aIndex + 17751U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 13U) ^ RotL64(aPrevious, 43U)) + (RotL64(aCross, 27U) + RotL64(aIngress, 58U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterJ = ((((aWandererE + RotL64(aPrevious, 29U)) + RotL64(aCarry, 21U)) + 11521331427196538632U) + aPhaseDOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1]) + aNonceWordP;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 11U)) + 16653824187682957632U) + aNonceWordI;
            aOrbiterK = ((aWandererF + RotL64(aCross, 47U)) + 11654676587350088289U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = (((aWandererA + RotL64(aScatter, 35U)) + RotL64(aCarry, 57U)) + 8010313317412193584U) + aNonceWordE;
            aOrbiterF = ((aWandererB + RotL64(aCross, 3U)) + RotL64(aCarry, 37U)) + 1108775560502907471U;
            aOrbiterI = (aWandererJ + RotL64(aScatter, 53U)) + 243952321439823521U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 20U)) + 2324945800401240403U) + aNonceWordO;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 9257554497543369657U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 16701314607244592540U) ^ aNonceWordJ;
            aOrbiterK = RotL64((aOrbiterK * 8790054741039817107U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 3900445848034341782U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 7652316487347103658U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11480123491361589799U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 14980368605272070578U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 2001165460948764796U;
            aOrbiterI = RotL64((aOrbiterI * 8110980921827107649U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 1911044015666991050U) + aNonceWordL;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 11366207111147818339U;
            aOrbiterC = RotL64((aOrbiterC * 17234439040652553865U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 16469329744002456607U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 8062793687044950815U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5856142259851144369U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 15364721421972807872U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 8979915611483540231U) ^ aNonceWordM;
            aOrbiterJ = RotL64((aOrbiterJ * 10899377466171153383U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 7654234623563110457U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterC) ^ 1526832460342135008U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterA = RotL64((aOrbiterA * 12766083052650723051U), 23U);
            //
            aIngress = RotL64(aOrbiterA, 29U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterG, 11U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aPrevious, 22U) + RotL64(aOrbiterF, 37U)) + aOrbiterA) + RotL64(aCarry, 37U)) + aNonceWordC);
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 43U) + aOrbiterK) + RotL64(aOrbiterJ, 57U)) + aNonceWordD) + aPhaseDWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 35U) + RotL64(aOrbiterJ, 19U)) + aOrbiterG);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterA, 12U)) + aOrbiterI) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 29U)) + aOrbiterC) + aNonceWordH);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterJ, 3U));
            aWandererC = aWandererC + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 47U)) + aOrbiterF) + RotL64(aCarry, 19U)) + aNonceWordB);
            //
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 50U));
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 24356U)) & S_BLOCK1], 39U) ^ RotL64(aSnowLaneB[((aIndex + 23842U)) & S_BLOCK1], 6U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 23478U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 25236U)) & S_BLOCK1], 11U) ^ RotL64(aSnowLaneA[((aIndex + 22393U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 56U) ^ RotL64(aCross, 5U)) + (RotL64(aPrevious, 21U) ^ RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterE = (aWandererH + RotL64(aIngress, 29U)) + 12122689833405846292U;
            aOrbiterB = (((aWandererJ + RotL64(aScatter, 60U)) + RotL64(aCarry, 5U)) + 9640400270962766788U) + aNonceWordI;
            aOrbiterC = ((aWandererF + RotL64(aCross, 13U)) + 9141937998266739071U) + aNonceWordO;
            aOrbiterG = (aWandererG + RotL64(aPrevious, 35U)) + 12899395770434090537U;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 47U)) + 13457918115408031842U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = (((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 57U)) + 15134784483576000943U) + aNonceWordA;
            aOrbiterF = ((((aWandererK + RotL64(aPrevious, 19U)) + RotL64(aCarry, 19U)) + 12540961268790055438U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordG;
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 6306886773092764230U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 13573343491337243121U) ^ aNonceWordC;
            aOrbiterC = RotL64((aOrbiterC * 15893457012357368707U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 8545588657348974413U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 10891410570357275120U;
            aOrbiterK = RotL64((aOrbiterK * 5399310978367842841U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 2877137119767060151U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 9178097682386595144U) ^ aNonceWordF;
            aOrbiterJ = RotL64((aOrbiterJ * 3524486002084427513U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 15528007881855616978U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 11368419529245281435U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12433207037378339309U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 5932738914934356645U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 5551842263864055419U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16093776759971522681U), 35U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterK) + 3824433359595690603U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1]) + aNonceWordL;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 17184628855571662441U;
            aOrbiterF = RotL64((aOrbiterF * 691208053136187317U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 8724462245014132623U) + aNonceWordM;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 7481349499528092352U;
            aOrbiterB = RotL64((aOrbiterB * 8212182934509617583U), 41U);
            //
            aIngress = RotL64(aOrbiterJ, 57U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + (RotL64(aOrbiterG, 10U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 56U) + RotL64(aOrbiterF, 57U)) + aOrbiterJ) + aPhaseDWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterF, 44U)) + aOrbiterC);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterF, 21U)) + aOrbiterG) + RotL64(aCarry, 57U)) + aNonceWordJ);
            aWandererF = aWandererF ^ (((RotL64(aCross, 43U) + aOrbiterB) + RotL64(aOrbiterG, 11U)) + aPhaseDWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterB, 51U)) + aNonceWordK);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterF, 3U)) + aNonceWordN);
            aWandererE = aWandererE + (((RotL64(aCross, 27U) + aOrbiterB) + RotL64(aOrbiterK, 37U)) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 58U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 30930U)) & S_BLOCK1], 29U) ^ RotL64(aInvestLaneA[((aIndex + 29412U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 32125U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 30790U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneB[((aIndex + 27833U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 36U)) ^ (RotL64(aIngress, 23U) + RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterF = (((aWandererD + RotL64(aCross, 19U)) + RotL64(aCarry, 21U)) + 4384716820085860551U) + aNonceWordJ;
            aOrbiterE = ((((aWandererK + RotL64(aScatter, 57U)) + RotL64(aCarry, 39U)) + 9715780315942116888U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordP;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 48U)) + 15963520052789178632U) + aNonceWordC;
            aOrbiterK = (aWandererA + RotL64(aPrevious, 5U)) + 14346700690686392938U;
            aOrbiterH = ((aWandererF + RotL64(aCross, 35U)) + 6005518012489966643U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = (((aWandererC + RotL64(aIngress, 41U)) + RotL64(aCarry, 5U)) + 2506732930310252119U) + aNonceWordI;
            aOrbiterD = (aWandererB + RotL64(aScatter, 29U)) + 16782163084851775826U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 823673076571076303U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 1634084509064077736U) ^ aNonceWordF;
            aOrbiterA = RotL64((aOrbiterA * 1128407326773234517U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 1288134975466877686U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 2998220403162908444U;
            aOrbiterE = RotL64((aOrbiterE * 4321412662318298283U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 220430672180734911U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = (((aOrbiterK ^ aOrbiterA) ^ 10223923547068528867U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterK = RotL64((aOrbiterK * 12577370238343872139U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 11696469696177647608U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 6545430420379636963U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8387163146257553773U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 79691451831797107U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 8971444023498649419U;
            aOrbiterG = RotL64((aOrbiterG * 7148919880477390009U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 5624403902454498793U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 9468064161002030997U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8243560528100864595U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 4619361544913629805U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 12682446273369750704U;
            aOrbiterF = RotL64((aOrbiterF * 10879074713156075641U), 53U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterK, 57U);
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 44U));
            aIngress = aIngress + RotL64(aOrbiterE, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aScatter, 43U) + aOrbiterF) + RotL64(aOrbiterD, 5U)) + aNonceWordA);
            aWandererC = aWandererC + (((((RotL64(aCross, 57U) + RotL64(aOrbiterE, 43U)) + aOrbiterD) + RotL64(aCarry, 21U)) + aNonceWordK) + aPhaseDWandererUpdateSaltB[((aIndex + 8U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 6U) + RotL64(aOrbiterD, 29U)) + aOrbiterH);
            aWandererF = aWandererF + (((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 35U)) + aOrbiterG) + aNonceWordB);
            aWandererA = aWandererA ^ (((RotL64(aCross, 21U) + aOrbiterA) + RotL64(aOrbiterK, 50U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 27U) + RotL64(aOrbiterG, 23U)) + aOrbiterA) + RotL64(aCarry, 41U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 13U) + aOrbiterG) + RotL64(aOrbiterE, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 54U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 28U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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

void TwistExpander_FootBall_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xCE75CCC7EBBFE4FFULL + 0xCB1F4FECCB9D7B45ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xDF5ECE2D3DE19C3FULL + 0xD8C618489ABC08A8ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xF5E3BF14AA38980DULL + 0xE1335393F80F1ACDULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xB7DBF2F5E444F6DBULL + 0xA5112552C733A351ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x97310017DFEDD40DULL + 0xFB66D94F8EAF739DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xEA58C57F178153D3ULL + 0xC7F6FF1CB73F7998ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x9464448350745E01ULL + 0x8B035AB94158DCE1ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x85F7E98ECE913B5BULL + 0xE01917298B3F9E35ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x8633253ACCCEFFE3ULL + 0x982A84105620F899ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xBF6F6D79194FB99BULL + 0xB1988A7C34AE548EULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xAD086308999AD927ULL + 0xFA09D6BD5F83D26AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x824A1C095CCB29E9ULL + 0xD8AF034AD13AA1B1ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xFF4EA59EE9D18489ULL + 0x8709AEE87821D99FULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xD64C35A44D30CE17ULL + 0xF7A48152E685E854ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xCAFE6E55E3425A93ULL + 0xB6BEEA4909F0EC2AULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xB17BCD5B97554BB7ULL + 0xAF64CE93C1909C9DULL);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 246U)) & S_BLOCK1], 37U) ^ RotL64(aInvestLaneB[((aIndex + 5160U)) & S_BLOCK1], 26U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 435U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 4590U)) & S_BLOCK1], 35U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 1574U)) & S_BLOCK1], 44U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 3947U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 54U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterD = (((aWandererK + RotL64(aScatter, 47U)) + RotL64(aCarry, 39U)) + 17019646486641172469U) + aPhaseEOrbiterAssignSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aIngress, 29U)) + 12276141179299971572U;
            aOrbiterE = ((aWandererH + RotL64(aCross, 21U)) + 3617241694029841555U) + aNonceWordF;
            aOrbiterC = (aWandererA + RotL64(aPrevious, 41U)) + 6967963401259371737U;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 57U)) + RotL64(aCarry, 47U)) + 6340709284279891017U;
            aOrbiterI = (aWandererF + RotL64(aPrevious, 12U)) + 456065368903896482U;
            aOrbiterJ = (aWandererJ + RotL64(aCross, 19U)) + 17686765719908116203U;
            aOrbiterB = (aWandererB + RotL64(aScatter, 51U)) + 1322045955429785736U;
            aOrbiterF = ((aWandererC + RotL64(aIngress, 23U)) + 5163772703302372887U) + aNonceWordJ;
            aOrbiterH = (aWandererE + RotL64(aPrevious, 3U)) + 13268431135020363252U;
            aOrbiterA = (((aWandererI + RotL64(aCross, 38U)) + RotL64(aCarry, 51U)) + 6538789950366849332U) + aPhaseEOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 10390344544314544893U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 5087084271300584267U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15149302947570776165U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 13423071121590981727U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 18324443012024134729U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15814349432207734533U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 4129091815978464507U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 17024797553831962245U;
            aOrbiterB = RotL64((aOrbiterB * 3137753479364378175U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 6501545108779991661U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 11930037791867597447U;
            aOrbiterC = RotL64((aOrbiterC * 4904739567549702851U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 4667298703308315851U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 6315980380900062127U;
            aOrbiterF = RotL64((aOrbiterF * 12080555704907924637U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 12732382340390769888U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 7792095326183864547U;
            aOrbiterK = RotL64((aOrbiterK * 12645556660611824631U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 17428384983571405782U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 3193205313177048443U;
            aOrbiterJ = RotL64((aOrbiterJ * 14488006565106259731U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 2813743367131107264U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 2742138679703780981U;
            aOrbiterA = RotL64((aOrbiterA * 18356569025783532225U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 6270291142961043031U) + aNonceWordN;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 3490174937775044998U;
            aOrbiterD = RotL64((aOrbiterD * 13879285210885619613U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 13182535825771438942U) + aNonceWordA;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 13047228760732694484U;
            aOrbiterG = RotL64((aOrbiterG * 10365428317468779549U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 17926326514553542739U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 17019646486641172469U;
            aOrbiterH = RotL64((aOrbiterH * 13978838314848228053U), 27U);
            //
            aIngress = RotL64(aOrbiterK, 43U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 39U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterD, 10U)) + aNonceWordH) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterH, 57U)) + aOrbiterC) + aNonceWordE);
            aWandererE = aWandererE + ((RotL64(aCross, 21U) + aOrbiterK) + RotL64(aOrbiterA, 23U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterA, 35U)) + aNonceWordD);
            aWandererG = aWandererG + (((RotL64(aCross, 26U) + aOrbiterI) + RotL64(aOrbiterF, 43U)) + aNonceWordK);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 53U) + aOrbiterE) + RotL64(aOrbiterI, 52U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 37U) + RotL64(aOrbiterH, 13U)) + aOrbiterK) + RotL64(aCarry, 19U)) + aPhaseEWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterD, 47U)) + aOrbiterK);
            aWandererB = aWandererB + (((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterG, 27U)) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterK, 5U)) + aOrbiterB);
            aWandererD = aWandererD + ((RotL64(aIngress, 48U) + aOrbiterA) + RotL64(aOrbiterJ, 41U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 48U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 52U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aFireLaneA[((aIndex + 9937U)) & S_BLOCK1], 41U) ^ RotL64(aInvestLaneC[((aIndex + 8211U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 7727U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneA[((aIndex + 5597U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 9550U)) & S_BLOCK1], 27U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 7199U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 10253U)) & S_BLOCK1], 42U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 38U) ^ RotL64(aCross, 5U)) + (RotL64(aPrevious, 21U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 5U)) + 5568146815535263910U) + aNonceWordF;
            aOrbiterA = (aWandererE + RotL64(aIngress, 19U)) + 7736084960873834666U;
            aOrbiterB = (((aWandererK + RotL64(aCross, 39U)) + RotL64(aCarry, 43U)) + 1336413621817562093U) + aNonceWordG;
            aOrbiterE = (aWandererG + RotL64(aPrevious, 54U)) + 5218462026934984692U;
            aOrbiterH = (aWandererJ + RotL64(aScatter, 27U)) + 7048890985969555935U;
            aOrbiterF = (((aWandererF + RotL64(aPrevious, 57U)) + RotL64(aCarry, 21U)) + 13415955213864702118U) + aPhaseEOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = (aWandererH + RotL64(aCross, 23U)) + 5657023257021528548U;
            aOrbiterI = (aWandererC + RotL64(aIngress, 44U)) + 14338310943137497116U;
            aOrbiterK = (aWandererB + RotL64(aScatter, 29U)) + 12305161641833950473U;
            aOrbiterD = (((aWandererD + RotL64(aIngress, 41U)) + RotL64(aCarry, 47U)) + 14514226578370459131U) + aPhaseEOrbiterAssignSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = ((aWandererI + RotL64(aCross, 11U)) + 12692904083266024340U) + aNonceWordM;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 11012959130001327964U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 7106471380403489078U;
            aOrbiterB = RotL64((aOrbiterB * 515626559384817223U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 3718101961355280891U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 13364192077222322664U;
            aOrbiterH = RotL64((aOrbiterH * 1411328915372590283U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 6720867800318913440U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 14497243926965866546U;
            aOrbiterI = RotL64((aOrbiterI * 13595058589060114653U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 5789056168233262435U) + aNonceWordC;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 14438482587495779937U;
            aOrbiterA = RotL64((aOrbiterA * 10593535547917767263U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 313917798940179945U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 15241845511889502917U;
            aOrbiterE = RotL64((aOrbiterE * 16483477103771326107U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 3591957424821693032U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 1559050939014453558U;
            aOrbiterD = RotL64((aOrbiterD * 17933346117866604725U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 15340590914441451383U) + aNonceWordB;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 5538037287390050110U;
            aOrbiterK = RotL64((aOrbiterK * 4082576643144951473U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 4151270491894969214U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 263593701314144898U;
            aOrbiterG = RotL64((aOrbiterG * 10372046955804512457U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 9025145270653080646U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 6867950904094870056U;
            aOrbiterJ = RotL64((aOrbiterJ * 9975247022340627751U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 3183454301841252109U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 3054904157641290615U;
            aOrbiterF = RotL64((aOrbiterF * 4092317552439599475U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 1768555574434776135U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 5568146815535263910U;
            aOrbiterC = RotL64((aOrbiterC * 12466957001078663927U), 43U);
            //
            aIngress = RotL64(aOrbiterI, 14U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + RotL64(aOrbiterE, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 13U)) + aOrbiterJ) + RotL64(aCarry, 41U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterI, 51U)) + aOrbiterD);
            aWandererB = aWandererB + (((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 27U)) + aOrbiterC) + aNonceWordP);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 28U) + aOrbiterG) + RotL64(aOrbiterC, 30U));
            aWandererA = aWandererA + ((RotL64(aCross, 53U) + aOrbiterG) + RotL64(aOrbiterH, 43U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterD, 19U)) + aOrbiterG) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterA, 47U)) + aOrbiterG) + aNonceWordE);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 21U) + aOrbiterK) + RotL64(aOrbiterF, 53U)) + aPhaseEWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 3U) + RotL64(aOrbiterA, 35U)) + aOrbiterB) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 46U) + RotL64(aOrbiterD, 37U)) + aOrbiterF);
            aWandererC = aWandererC + (((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterF, 40U)) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererI, 56U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererC, 52U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 11455U)) & S_BLOCK1], 19U) ^ RotL64(aInvestLaneA[((aIndex + 13230U)) & S_BLOCK1], 54U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 11329U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 14883U)) & S_BLOCK1], 29U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 11688U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aIngress, 26U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterC = ((aWandererK + RotL64(aIngress, 24U)) + 8604208734152026945U) + aNonceWordA;
            aOrbiterF = (aWandererF + RotL64(aPrevious, 11U)) + 1374329953253889829U;
            aOrbiterK = ((aWandererB + RotL64(aScatter, 13U)) + 5779278910548228339U) + aNonceWordB;
            aOrbiterD = ((aWandererI + RotL64(aCross, 29U)) + 17670451230882805140U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 47U)) + RotL64(aCarry, 41U)) + 8193848740764866860U;
            aOrbiterI = ((aWandererG + RotL64(aScatter, 26U)) + 15801168428145650104U) + aNonceWordH;
            aOrbiterH = ((aWandererC + RotL64(aIngress, 37U)) + RotL64(aCarry, 3U)) + 2584718176087499066U;
            aOrbiterA = (((aWandererA + RotL64(aCross, 39U)) + RotL64(aCarry, 19U)) + 14950366247822737997U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = (aWandererH + RotL64(aPrevious, 5U)) + 9779293225265670135U;
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 57U)) + 8688968319288372383U;
            aOrbiterB = (aWandererD + RotL64(aCross, 43U)) + 13665723186950342601U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 9395428688359973510U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 2152719218018108418U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15271961483518392671U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 1350324137411377992U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 8729317951386057921U;
            aOrbiterC = RotL64((aOrbiterC * 6008790836417785083U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 6317310451893678411U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 10175620379041384281U;
            aOrbiterH = RotL64((aOrbiterH * 14079679617394330781U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 1203082119358827708U) + aNonceWordE;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 523869107818193101U;
            aOrbiterE = RotL64((aOrbiterE * 4629501113595689157U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 4028324959540432983U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 15447631947468213912U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6037306615787729185U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 14225888694733041031U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 11925000696281947629U) ^ aNonceWordP;
            aOrbiterJ = RotL64((aOrbiterJ * 4337022940520411253U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 15015531024930608745U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 16752579225076943550U;
            aOrbiterB = RotL64((aOrbiterB * 15551083683579981439U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 2432733494869267901U) + aNonceWordI;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 10103430321388601485U;
            aOrbiterG = RotL64((aOrbiterG * 18372919379972432569U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 15943360147468638325U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 9782703760233558733U;
            aOrbiterD = RotL64((aOrbiterD * 685056980418243879U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 18345087852012669037U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 8897505040792027675U;
            aOrbiterI = RotL64((aOrbiterI * 14333687539092412967U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 7402581293947129667U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 8604208734152026945U) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 9965525485538037673U), 43U);
            //
            aIngress = RotL64(aOrbiterA, 37U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterK, 50U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterJ, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterG, 13U)) + aOrbiterB) + aNonceWordC);
            aWandererE = aWandererE + ((((RotL64(aCross, 19U) + RotL64(aOrbiterA, 23U)) + aOrbiterG) + RotL64(aCarry, 39U)) + aNonceWordG);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 5U) + aOrbiterE) + RotL64(aOrbiterD, 3U)) + aNonceWordJ);
            aWandererA = aWandererA + ((RotL64(aIngress, 14U) + aOrbiterJ) + RotL64(aOrbiterD, 37U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterF, 44U)) + aOrbiterE) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 3U) + RotL64(aOrbiterB, 47U)) + aOrbiterH) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterK, 11U)) + aOrbiterI);
            aWandererK = aWandererK + ((RotL64(aScatter, 26U) + RotL64(aOrbiterE, 19U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterG, 6U)) + aOrbiterI) + aNonceWordN);
            aWandererI = aWandererI + ((RotL64(aScatter, 57U) + aOrbiterI) + RotL64(aOrbiterB, 29U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterC, 27U)) + aPhaseEWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 4U));
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererE, 35U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 18922U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneA[((aIndex + 17005U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 18270U)) & S_BLOCK1], 52U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 16408U)) & S_BLOCK1], 47U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 19259U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 56U) + RotL64(aCross, 19U)) ^ (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterG = (aWandererE + RotL64(aIngress, 24U)) + 9435962834163239322U;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 35U)) + RotL64(aCarry, 11U)) + 10524704356081318973U;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 47U)) + 7403401305665208680U) + aNonceWordF;
            aOrbiterH = ((aWandererJ + RotL64(aCross, 27U)) + 7525414805023556493U) + aNonceWordP;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 56U)) + RotL64(aCarry, 57U)) + 1116686470029070951U;
            aOrbiterD = ((aWandererB + RotL64(aCross, 21U)) + 13257612299137802420U) + aPhaseEOrbiterAssignSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aScatter, 5U)) + 9181543003986598283U;
            aOrbiterF = (((aWandererA + RotL64(aIngress, 3U)) + 9739384852307501107U) + aPhaseEOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1]) + aNonceWordH;
            aOrbiterE = (aWandererI + RotL64(aPrevious, 11U)) + 11308402900229016057U;
            aOrbiterB = ((aWandererF + RotL64(aIngress, 19U)) + RotL64(aCarry, 27U)) + 14935167593705272337U;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 53U)) + 7171824007631943535U) + aNonceWordI;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 8068411284829563567U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 12350207458513447578U) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 813973258659041895U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 17039236343991574134U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 18291683592714999632U;
            aOrbiterG = RotL64((aOrbiterG * 7771718817924840713U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 6239616841884430968U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 10604527977569876774U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6972820410084939637U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 1707724300671717658U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 3802268808625297647U;
            aOrbiterI = RotL64((aOrbiterI * 11296811630387191563U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 9423064323799920219U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 242153923313096551U;
            aOrbiterF = RotL64((aOrbiterF * 12117679073775630197U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 945801070951928277U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 13094814302414492064U;
            aOrbiterH = RotL64((aOrbiterH * 14638176479878969775U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 7572219725951040117U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 16494986983782503428U;
            aOrbiterK = RotL64((aOrbiterK * 2739189408707408171U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 10949497978229234856U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 11219643352002119905U;
            aOrbiterD = RotL64((aOrbiterD * 16900635614259262873U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 14245670385849499678U) + aNonceWordK;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 13771155918235018585U;
            aOrbiterJ = RotL64((aOrbiterJ * 14121731385133220921U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 15722734439532828816U) + aNonceWordC;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 11032710342174118366U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16096465375397981585U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 2071496769185495150U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterA) ^ 9435962834163239322U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterE = RotL64((aOrbiterE * 10640995428633266765U), 41U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 39U);
            aIngress = aIngress + (RotL64(aOrbiterA, 46U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + RotL64(aOrbiterB, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterA, 52U)) + aOrbiterJ);
            aWandererD = aWandererD + (((RotL64(aPrevious, 26U) + RotL64(aOrbiterB, 27U)) + aOrbiterG) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterJ, 29U)) + aPhaseEWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 19U)) + aOrbiterD) + RotL64(aCarry, 47U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 23U) + aOrbiterH) + RotL64(aOrbiterI, 21U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 20U) + aOrbiterI) + RotL64(aOrbiterJ, 41U)) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 29U) + aOrbiterD) + RotL64(aOrbiterF, 3U)) + aNonceWordM);
            aWandererI = aWandererI + ((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 37U)) + aOrbiterD);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 41U) + aOrbiterD) + RotL64(aOrbiterC, 43U)) + aNonceWordJ);
            aWandererF = aWandererF + (((RotL64(aCross, 37U) + RotL64(aOrbiterF, 5U)) + aOrbiterG) + aNonceWordL);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterF, 24U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 12U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + RotL64(aWandererG, 30U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 24540U)) & S_BLOCK1], 14U) ^ RotL64(aFireLaneB[((aIndex + 21910U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 24090U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22412U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 27235U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 22022U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 37U) + RotL64(aPrevious, 51U)) ^ (RotL64(aCarry, 24U) ^ RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterD = ((aWandererF + RotL64(aIngress, 41U)) + 5088525177670191619U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 19U)) + RotL64(aCarry, 13U)) + 9966456257813932112U;
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 47U)) + RotL64(aCarry, 19U)) + 7707646574027146307U;
            aOrbiterB = (aWandererH + RotL64(aCross, 37U)) + 75480203757681173U;
            aOrbiterE = (((aWandererC + RotL64(aScatter, 50U)) + 384659134071835163U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordL;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 35U)) + 3158769775373307778U) + aNonceWordP;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 57U)) + 17360830943513941272U;
            aOrbiterH = (aWandererA + RotL64(aCross, 13U)) + 5317278822721604586U;
            aOrbiterK = (aWandererI + RotL64(aIngress, 39U)) + 1371427105215954781U;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 24U)) + 3162710551223553423U;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 11U)) + RotL64(aCarry, 47U)) + 5332921933853550756U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 10572462410297815854U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 10234389605554817892U;
            aOrbiterA = RotL64((aOrbiterA * 2130374833440291193U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 13421365517991380605U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 10186643614984034083U;
            aOrbiterC = RotL64((aOrbiterC * 8554471709467808453U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 4742438973260817120U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 6081590345899008846U;
            aOrbiterD = RotL64((aOrbiterD * 7069396301823124931U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 15360092808493795340U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 12186413069553132646U) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 3815981440611914267U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 16756221656224451552U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 12232880965861373143U;
            aOrbiterJ = RotL64((aOrbiterJ * 14196910735715726471U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 10090954323470840557U) + aNonceWordK;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 15615770271463853537U;
            aOrbiterG = RotL64((aOrbiterG * 13544181592829027283U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 556029032505658411U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 13311879111583579039U) ^ aNonceWordH;
            aOrbiterI = RotL64((aOrbiterI * 3924744868168749003U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 8646360871497847336U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 2064833941982069154U;
            aOrbiterB = RotL64((aOrbiterB * 10016546852137913163U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 1701847261278886621U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 9654208200019718374U;
            aOrbiterK = RotL64((aOrbiterK * 4398089490129603677U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 14276143262844412074U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 10738184916176200661U;
            aOrbiterE = RotL64((aOrbiterE * 8940267914440361883U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 2966052720680305600U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 5088525177670191619U;
            aOrbiterH = RotL64((aOrbiterH * 11621585388684456139U), 51U);
            //
            aIngress = RotL64(aOrbiterJ, 56U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 41U));
            aIngress = aIngress + RotL64(aOrbiterE, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 53U)) + aOrbiterI) + aNonceWordD);
            aWandererE = aWandererE + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 57U)) + aOrbiterB) + aPhaseEWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 60U) + RotL64(aOrbiterH, 21U)) + aOrbiterE) + aNonceWordI);
            aWandererF = aWandererF + ((RotL64(aCross, 27U) + aOrbiterB) + RotL64(aOrbiterE, 60U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterC, 39U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 39U) + aOrbiterI) + RotL64(aOrbiterD, 37U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterC, 51U)) + aOrbiterF) + aNonceWordC);
            aWandererI = aWandererI + (((RotL64(aPrevious, 37U) + aOrbiterD) + RotL64(aOrbiterK, 13U)) + RotL64(aCarry, 39U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 54U) + aOrbiterF) + RotL64(aOrbiterE, 6U)) + aNonceWordJ);
            aWandererD = aWandererD + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterG, 27U)) + aOrbiterB) + RotL64(aCarry, 29U)) + aPhaseEWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 41U) + aOrbiterJ) + RotL64(aOrbiterG, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 18U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererG, 53U);
            aCarry = aCarry + RotL64(aIngress, 50U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 30981U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((aIndex + 31207U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 28867U)) & S_BLOCK1], 6U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31686U)) & S_BLOCK1], 41U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 31598U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aPrevious, 57U)) ^ (RotL64(aIngress, 24U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterD = (aWandererJ + RotL64(aCross, 37U)) + 5906639480605353429U;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 51U)) + RotL64(aCarry, 19U)) + 5293518570213287605U;
            aOrbiterA = (aWandererB + RotL64(aPrevious, 43U)) + 15383185501428521377U;
            aOrbiterI = (((aWandererG + RotL64(aScatter, 53U)) + RotL64(aCarry, 11U)) + 15364072512743978902U) + aPhaseEOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aCross, 20U)) + 4525473357144014271U;
            aOrbiterH = (aWandererH + RotL64(aScatter, 41U)) + 10400911938125603074U;
            aOrbiterG = (aWandererA + RotL64(aIngress, 5U)) + 16417506293824627550U;
            aOrbiterK = (((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 51U)) + 2419329331753341815U) + aNonceWordB;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 10U)) + 14929222427923332069U) + aNonceWordJ;
            aOrbiterB = (aWandererI + RotL64(aScatter, 57U)) + 16771573504983922586U;
            aOrbiterC = ((aWandererF + RotL64(aCross, 47U)) + 1863466450051787622U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 12895350137096692415U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 3700979086526298327U;
            aOrbiterA = RotL64((aOrbiterA * 10279730254867618193U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 1977099106211282426U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 6144698304096915742U) ^ aNonceWordF;
            aOrbiterJ = RotL64((aOrbiterJ * 5039822990560519609U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 3858895556659724975U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 1283646340363435327U;
            aOrbiterG = RotL64((aOrbiterG * 11622421841377018069U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 6240532051889108891U) + aNonceWordD;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 757364889381634634U;
            aOrbiterF = RotL64((aOrbiterF * 943852137901972945U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 5272945693977418174U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 6850528198786172283U) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 1966383079897679953U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 14431587733859573714U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 16124590257870999553U;
            aOrbiterH = RotL64((aOrbiterH * 7755796211433191143U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 14912695018110241411U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 11098623474413346520U;
            aOrbiterB = RotL64((aOrbiterB * 15167688959990872051U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 3484847683376368686U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 2295388097292719800U;
            aOrbiterK = RotL64((aOrbiterK * 1240808318176106909U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 923199510066894111U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 311875852510926196U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9797881750305289335U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 3543141837224843684U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 12889943043568922084U;
            aOrbiterI = RotL64((aOrbiterI * 8682278766727990427U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 6105656539077757510U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 5906639480605353429U) ^ aNonceWordH;
            aOrbiterC = RotL64((aOrbiterC * 9555916235293954383U), 29U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterC, 39U);
            aIngress = aIngress + (RotL64(aOrbiterK, 30U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + RotL64(aOrbiterA, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aScatter, 30U) + RotL64(aOrbiterF, 39U)) + aOrbiterG);
            aWandererA = aWandererA ^ ((RotL64(aCross, 21U) + aOrbiterB) + RotL64(aOrbiterA, 35U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 18U)) + aOrbiterB) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterE, 11U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 43U) + aOrbiterE) + RotL64(aOrbiterH, 41U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 29U)) + aOrbiterK) + aPhaseEWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 37U) + RotL64(aOrbiterG, 53U)) + aOrbiterI) + aNonceWordG);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterH, 57U)) + aOrbiterJ);
            aWandererB = aWandererB + (((RotL64(aScatter, 27U) + RotL64(aOrbiterE, 6U)) + aOrbiterC) + RotL64(aCarry, 37U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 23U)) + aOrbiterD);
            aWandererC = aWandererC + ((((RotL64(aIngress, 50U) + RotL64(aOrbiterD, 13U)) + aOrbiterI) + aNonceWordE) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 46U));
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 36U);
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

void TwistExpander_FootBall_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xF36AEDCAFC258111ULL + 0xA9552A603BEEB17EULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xE91A96661AF1D99DULL + 0xEC3D79C157138043ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xE8300E5DC9C9CF4DULL + 0xF18292BED1533CE1ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xFB621C7EF5ADCBF5ULL + 0xE311D861EC08C184ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xCF374BD90D0D7BBDULL + 0x9DFE2BE160242082ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x97F781262FD71E03ULL + 0xAA9135479FD80357ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x91AE84040A6A2C41ULL + 0xBBE0CA52D20F0850ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xE467C25F88B9FAE3ULL + 0xA28ECEDA6A21731BULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x9382DD0697846B0FULL + 0xE64F38D43B9427FFULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xBB32CA181418471BULL + 0xD07ECF4DCB164CD7ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x95D1A2FD725C5C19ULL + 0x877061A43BF6AFDFULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x9B9162D48831756DULL + 0x8C2EBE1D5D7A671FULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x9DF3FFB0E0DF45A9ULL + 0xD50600D197B66D4EULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xD505AD78CA052873ULL + 0xA93C44969BDBCADAULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xF09F8129830BD759ULL + 0x95C280F351BD3C90ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x8DD7907CC02302CDULL + 0xCAFC3730D10CA951ULL);
    // GSeedRunSeed_F seed_loop_f (start)
    {
        // GSeedRunSeed_F seed_loop_f lane group
        // read from: aOperationLaneA, aOperationLaneB, aSnowLaneA, aOperationLaneC, aOperationLaneD, aInvestLaneB, aSnowLaneC, aWorkLaneD, aInvestLaneA, aSnowLaneD, aInvestLaneC, aExpandLaneA, aWorkLaneC, aExpandLaneB, aInvestLaneD, aExpandLaneC, aSnowLaneB
        // write to: aSnowLaneC, aSnowLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_f loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aSnowLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aSnowLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aInvestLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aInvestLaneB backward/forward random
        // write to: aSnowLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 3296U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneB[((aIndex + 866U)) & S_BLOCK1], 44U));
            aIngress ^= RotL64(aSnowLaneA[((aIndex + 4760U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4408U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 393U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 3567U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aIngress, 35U)) ^ (RotL64(aCross, 3U) + RotL64(aPrevious, 22U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 4U)) + 17454559218352016650U) + aNonceWordL;
            aOrbiterA = ((((aWandererJ + RotL64(aIngress, 21U)) + RotL64(aCarry, 21U)) + 8005709669325164803U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordC;
            aOrbiterK = (aWandererC + RotL64(aCross, 27U)) + 13393741948412816357U;
            aOrbiterC = (aWandererF + RotL64(aScatter, 39U)) + 3665865624348875553U;
            aOrbiterD = ((aWandererD + RotL64(aCross, 56U)) + RotL64(aCarry, 57U)) + 8334142570031883436U;
            aOrbiterH = (aWandererK + RotL64(aIngress, 47U)) + 17226066128706139657U;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 35U)) + 3319093033121522613U;
            aOrbiterG = ((((aWandererG + RotL64(aScatter, 43U)) + RotL64(aCarry, 5U)) + 6657535603401588798U) + aPhaseFOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1]) + aNonceWordG;
            aOrbiterE = ((aWandererI + RotL64(aCross, 51U)) + 5469746182326331147U) + aNonceWordJ;
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 17846791786050221418U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 15939541003714896288U;
            aOrbiterK = RotL64((aOrbiterK * 1400351482213119809U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 12076763190461077406U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 3594038213596405284U;
            aOrbiterH = RotL64((aOrbiterH * 10244002692575821495U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 8301291631324464622U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 8460406137668390582U;
            aOrbiterC = RotL64((aOrbiterC * 9117147929757711595U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 7612394867020871200U) + aNonceWordM;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 8525076134853103975U;
            aOrbiterE = RotL64((aOrbiterE * 5790440201072204659U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 11929899088215090379U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 7119509166360685726U) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 1662341427992528823U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 5081078459225240607U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 17149991983909906705U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 950223374568067343U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 8817303295675241994U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterA) ^ 7962039282652745113U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterJ = RotL64((aOrbiterJ * 12773588587795522121U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 13596273086338032370U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 8186297702278180956U;
            aOrbiterD = RotL64((aOrbiterD * 6226504769888753861U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 1696277861691580263U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 17360461831507082959U;
            aOrbiterI = RotL64((aOrbiterI * 1651378456022210983U), 27U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 43U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 10U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 27U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterJ, 37U)) + aOrbiterD) + aPhaseFWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 30U) + aOrbiterC) + RotL64(aOrbiterA, 5U)) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterH, 56U)) + aOrbiterA);
            aWandererD = aWandererD + ((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterG, 51U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterD, 23U)) + aOrbiterC);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 13U)) + aOrbiterJ) + RotL64(aCarry, 5U)) + aNonceWordE);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 41U)) + aOrbiterD) + aNonceWordA);
            aWandererF = aWandererF + (((RotL64(aIngress, 26U) + RotL64(aOrbiterD, 46U)) + aOrbiterI) + aPhaseFWandererUpdateSaltE[((aIndex + 8U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterE, 29U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 30U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aSnowLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 2
        // ingress from: aSnowLaneC, aOperationLaneC, aOperationLaneD, aWorkLaneD
        // ingress directions: aSnowLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aWorkLaneD forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aInvestLaneA
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aInvestLaneA backward/forward random
        // write to: aSnowLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneC[((aIndex + 9965U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((aIndex + 5884U)) & S_BLOCK1], 56U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 7161U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneD[((aIndex + 8003U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 10289U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10102U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aInvestLaneA[((aIndex + 7747U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCarry, 37U)) ^ (RotL64(aPrevious, 11U) ^ RotL64(aCross, 60U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterD = ((aWandererD + RotL64(aScatter, 51U)) + RotL64(aCarry, 11U)) + 5568146815535263910U;
            aOrbiterA = ((aWandererE + RotL64(aCross, 19U)) + RotL64(aCarry, 43U)) + 7736084960873834666U;
            aOrbiterI = (((aWandererG + RotL64(aPrevious, 23U)) + RotL64(aCarry, 19U)) + 1336413621817562093U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 35U)) + 5218462026934984692U) + aNonceWordG;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 58U)) + 7048890985969555935U) + aNonceWordP;
            aOrbiterF = (((aWandererA + RotL64(aCross, 43U)) + 13415955213864702118U) + aPhaseFOrbiterAssignSaltB[((aIndex + 8U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterH = (aWandererH + RotL64(aIngress, 27U)) + 5657023257021528548U;
            aOrbiterK = (aWandererC + RotL64(aScatter, 47U)) + 14338310943137497116U;
            aOrbiterC = (aWandererK + RotL64(aCross, 12U)) + 12305161641833950473U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 14514226578370459131U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterD) ^ 12692904083266024340U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterI = RotL64((aOrbiterI * 14800805065279908839U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 11012959130001327964U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 7106471380403489078U) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 515626559384817223U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 3718101961355280891U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 13364192077222322664U;
            aOrbiterJ = RotL64((aOrbiterJ * 1411328915372590283U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 6720867800318913440U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 14497243926965866546U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13595058589060114653U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 5789056168233262435U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 14438482587495779937U;
            aOrbiterC = RotL64((aOrbiterC * 10593535547917767263U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 313917798940179945U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 15241845511889502917U;
            aOrbiterH = RotL64((aOrbiterH * 16483477103771326107U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 3591957424821693032U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 1559050939014453558U;
            aOrbiterG = RotL64((aOrbiterG * 17933346117866604725U), 29U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterH) + 15340590914441451383U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordA;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 5538037287390050110U;
            aOrbiterA = RotL64((aOrbiterA * 4082576643144951473U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 4151270491894969214U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 263593701314144898U;
            aOrbiterF = RotL64((aOrbiterF * 10372046955804512457U), 35U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterF, 44U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + RotL64(aOrbiterJ, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterC, 6U)) + aOrbiterA) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 22U) + RotL64(aOrbiterC, 37U)) + aOrbiterI) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterD, 23U)) + aOrbiterG);
            aWandererI = aWandererI + (((RotL64(aCross, 47U) + RotL64(aOrbiterJ, 47U)) + aOrbiterF) + aNonceWordM);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 39U) + aOrbiterF) + RotL64(aOrbiterA, 28U)) + aNonceWordN);
            aWandererE = aWandererE + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterI, 41U)) + aOrbiterH) + RotL64(aCarry, 37U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterG, 57U)) + aOrbiterH);
            aWandererD = aWandererD + ((RotL64(aIngress, 13U) + RotL64(aOrbiterK, 19U)) + aOrbiterA);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 29U) + aOrbiterJ) + RotL64(aOrbiterG, 13U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 44U));
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererG, 41U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aSnowLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 3
        // ingress from: aSnowLaneD, aOperationLaneA, aInvestLaneC
        // ingress directions: aSnowLaneD forward forced, aOperationLaneA forward forced, aInvestLaneC forward/backward random
        // cross from: aSnowLaneC, aOperationLaneC
        // cross directions: aSnowLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneD[((aIndex + 15837U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((aIndex + 13898U)) & S_BLOCK1], 54U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 12739U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 16245U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneC[((aIndex + 12814U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 18U) ^ RotL64(aIngress, 35U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterJ = (((aWandererI + RotL64(aScatter, 28U)) + RotL64(aCarry, 37U)) + 11410829607777684449U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aCross, 47U)) + 7502698839700975347U;
            aOrbiterE = (((aWandererG + RotL64(aPrevious, 13U)) + RotL64(aCarry, 29U)) + 13267685058252106173U) + aNonceWordI;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 35U)) + 238242706996630625U) + aNonceWordD;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 5U)) + 8184695499511454281U) + aNonceWordN;
            aOrbiterK = ((((aWandererJ + RotL64(aIngress, 24U)) + RotL64(aCarry, 51U)) + 12767823220461985403U) + aPhaseFOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterF = (aWandererK + RotL64(aCross, 19U)) + 12293198423143850330U;
            aOrbiterA = (aWandererB + RotL64(aScatter, 43U)) + 11149495229952495939U;
            aOrbiterB = (aWandererD + RotL64(aIngress, 39U)) + 7556992689338382800U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 3431338808774134649U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 16863099140844995099U;
            aOrbiterE = RotL64((aOrbiterE * 752376661101787919U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 17872458049880677604U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 16760153457252546974U;
            aOrbiterD = RotL64((aOrbiterD * 11225037229069712805U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 3115544493537438408U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 4359882942759752958U;
            aOrbiterC = RotL64((aOrbiterC * 561477566995575801U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 13387113067202396536U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 12955690074544490161U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12449941770827974511U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 15614054443728226807U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 1939441328066616114U;
            aOrbiterF = RotL64((aOrbiterF * 4484917074808974359U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 4599016263007782537U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 9962305629016158048U;
            aOrbiterJ = RotL64((aOrbiterJ * 1496184427500037279U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 8428467674122750557U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 3938884087806393439U;
            aOrbiterA = RotL64((aOrbiterA * 12810531094050481761U), 39U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterB) + 6018636830758044658U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordF;
            aOrbiterK = (((aOrbiterK ^ aOrbiterG) ^ 1510372000641305416U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterK = RotL64((aOrbiterK * 9002834928626918247U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 17592782466215337843U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 8119921507606870360U;
            aOrbiterB = RotL64((aOrbiterB * 1299795061644535485U), 3U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterD, 35U);
            aIngress = aIngress + (RotL64(aOrbiterA, 39U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterJ, 24U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 19U) + aOrbiterD) + RotL64(aOrbiterA, 21U));
            aWandererI = aWandererI + (((RotL64(aIngress, 56U) + RotL64(aOrbiterG, 47U)) + aOrbiterJ) + RotL64(aCarry, 47U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterK, 28U)) + aOrbiterE);
            aWandererG = aWandererG + (((RotL64(aCross, 51U) + RotL64(aOrbiterC, 13U)) + aOrbiterA) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 43U) + aOrbiterK) + RotL64(aOrbiterF, 53U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 4U) + RotL64(aOrbiterB, 5U)) + aOrbiterC) + aNonceWordK);
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterK, 39U)) + aNonceWordL) + aPhaseFWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 27U) + RotL64(aOrbiterA, 57U)) + aOrbiterG) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterD, 34U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 41U));
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + (RotL64(aWandererA, 30U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererF, 27U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 4
        // ingress from: aExpandLaneA, aSnowLaneC, aWorkLaneC
        // ingress directions: aExpandLaneA forward forced, aSnowLaneC forward forced, aWorkLaneC forward/backward random
        // cross from: aSnowLaneD, aOperationLaneD
        // cross directions: aSnowLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 18119U)) & S_BLOCK1], 23U) ^ RotL64(aSnowLaneC[((aIndex + 20661U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 16938U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 17416U)) & S_BLOCK1], 46U) ^ RotL64(aOperationLaneD[((aIndex + 20896U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aIngress, 38U) ^ RotL64(aCross, 53U)) + (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterI = (((aWandererI + RotL64(aIngress, 6U)) + 11698283336767769359U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordK;
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 23U)) + 13297826354831483872U) + aPhaseFOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aCross, 57U)) + RotL64(aCarry, 27U)) + 15254999058287530795U;
            aOrbiterJ = (((aWandererH + RotL64(aPrevious, 11U)) + RotL64(aCarry, 11U)) + 17474166585085346567U) + aNonceWordE;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 39U)) + RotL64(aCarry, 57U)) + 15684783498452840289U;
            aOrbiterH = (aWandererD + RotL64(aScatter, 30U)) + 5061229733465216486U;
            aOrbiterF = (aWandererF + RotL64(aCross, 43U)) + 15370981279168377944U;
            aOrbiterG = (aWandererG + RotL64(aPrevious, 53U)) + 17966672773619554092U;
            aOrbiterC = (aWandererB + RotL64(aScatter, 35U)) + 14685092893994491068U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 12798804186209406389U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 2848444181474221574U) ^ aNonceWordA;
            aOrbiterE = RotL64((aOrbiterE * 13730480364920876877U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 8551142075919636146U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 8833198159158950723U;
            aOrbiterH = RotL64((aOrbiterH * 7650289040764974737U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 7351473160893666232U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 14204899612487622222U;
            aOrbiterI = RotL64((aOrbiterI * 6317485031956448029U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 7008985178526543258U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 13576796403863120356U;
            aOrbiterC = RotL64((aOrbiterC * 13745839827679114077U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 5769784656937900699U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 14075925808204936705U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5844894088757604713U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 17818667502858010896U) + aNonceWordD;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 16016922065572683130U;
            aOrbiterG = RotL64((aOrbiterG * 7525645833898085373U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 1582458237855075977U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 10830440354527138227U;
            aOrbiterJ = RotL64((aOrbiterJ * 10499386926982228251U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 10653964151654643772U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 11218475491129483859U) ^ aNonceWordI;
            aOrbiterF = RotL64((aOrbiterF * 3338108067044357141U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 9863649760189649255U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 13790281439048354358U;
            aOrbiterA = RotL64((aOrbiterA * 4682098083538482849U), 11U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterH, 3U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 58U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 60U)) + aOrbiterC);
            aWandererH = aWandererH + ((RotL64(aScatter, 30U) + aOrbiterI) + RotL64(aOrbiterC, 3U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterF, 47U)) + aOrbiterD);
            aWandererC = aWandererC + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 35U)) + aOrbiterJ) + aNonceWordJ);
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 23U) + aOrbiterH) + RotL64(aOrbiterJ, 19U)) + aNonceWordM) + aPhaseFWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aCross, 37U) + aOrbiterD) + RotL64(aOrbiterH, 23U)) + RotL64(aCarry, 29U)) + aNonceWordC);
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 3U) + aOrbiterJ) + RotL64(aOrbiterF, 53U)) + aNonceWordG) + aPhaseFWandererUpdateSaltF[((aIndex + 22U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 14U) + aOrbiterG) + RotL64(aOrbiterC, 39U)) + RotL64(aCarry, 51U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterD, 10U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 10U));
            aCarry = aCarry + RotL64(aWandererI, 39U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 5
        // ingress from: aExpandLaneB, aSnowLaneD, aInvestLaneD
        // ingress directions: aExpandLaneB forward forced, aSnowLaneD forward forced, aInvestLaneD forward/backward random
        // cross from: aExpandLaneA, aSnowLaneC
        // cross directions: aExpandLaneA backward forced, aSnowLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 25269U)) & S_BLOCK1], 14U) ^ RotL64(aSnowLaneD[((aIndex + 22880U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aInvestLaneD[((aIndex + 25067U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24473U)) & S_BLOCK1], 4U) ^ RotL64(aSnowLaneC[((aIndex + 22363U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aIngress, 35U)) ^ (RotL64(aCarry, 57U) + RotL64(aPrevious, 10U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterI = ((aWandererF + RotL64(aCross, 35U)) + RotL64(aCarry, 5U)) + 13278949403988203974U;
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 47U)) + RotL64(aCarry, 39U)) + 9213599924054673756U;
            aOrbiterA = (aWandererA + RotL64(aIngress, 58U)) + 1255746482932381798U;
            aOrbiterC = ((aWandererE + RotL64(aScatter, 13U)) + 11575321997144516122U) + aNonceWordC;
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 23U)) + 15881587525529432437U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aCross, 19U)) + 9846195809864862707U;
            aOrbiterF = ((aWandererH + RotL64(aIngress, 29U)) + 12319815691858217670U) + aPhaseFOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = (((aWandererC + RotL64(aScatter, 5U)) + RotL64(aCarry, 51U)) + 16322617427294439587U) + aNonceWordA;
            aOrbiterE = (aWandererK + RotL64(aCross, 52U)) + 16332130810525887437U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 4920951156015336794U) + aNonceWordK;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 16767126455124552329U;
            aOrbiterA = RotL64((aOrbiterA * 4440352337076842603U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 12553595911087945223U) + aNonceWordN;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 1437522202135436142U;
            aOrbiterB = RotL64((aOrbiterB * 2001992794165550905U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 12313100454852227143U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 2761983020631055729U;
            aOrbiterC = RotL64((aOrbiterC * 3874839760378039509U), 35U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterC) + 17635303588421554367U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1]) + aNonceWordB;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 788212489507463763U;
            aOrbiterI = RotL64((aOrbiterI * 17896475584538528059U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 5192552894670654434U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 6784748488807738811U;
            aOrbiterG = RotL64((aOrbiterG * 8077237651953896479U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 16113417046719114943U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 1096874945215225916U;
            aOrbiterE = RotL64((aOrbiterE * 17308604412622879833U), 13U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterF) + 7610274704570171595U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordG;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 10466070212284342550U;
            aOrbiterK = RotL64((aOrbiterK * 6449728258497920613U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 6777845928873855221U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 5251515022021984126U;
            aOrbiterH = RotL64((aOrbiterH * 9018277343404261611U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 13849343158824111498U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 7977711210181714021U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4182053966171053577U), 43U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterG, 27U);
            aIngress = aIngress + (RotL64(aOrbiterA, 20U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterF, 39U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterI, 53U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 21U) + aOrbiterG) + RotL64(aOrbiterB, 6U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 10U) + aOrbiterH) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 27U)) + aNonceWordF);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterC, 41U)) + aOrbiterK);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 11U)) + aOrbiterK) + RotL64(aCarry, 41U)) + aNonceWordJ);
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 35U) + RotL64(aOrbiterG, 57U)) + aOrbiterK) + aNonceWordO) + aPhaseFWandererUpdateSaltC[((aIndex + 24U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 47U) + aOrbiterF) + RotL64(aOrbiterG, 36U)) + aPhaseFWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterE, 29U)) + aOrbiterA);
            aWandererK = aWandererK + ((RotL64(aCross, 28U) + aOrbiterH) + RotL64(aOrbiterI, 19U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 23U)) + aOrbiterG) + aNonceWordM);
            //
            aCarry = aCarry + (RotL64(aWandererE, 44U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererC, 54U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 31442U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((aIndex + 32277U)) & S_BLOCK1], 10U));
            aIngress ^= RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 31831U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32746U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29582U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 6U) ^ RotL64(aPrevious, 23U)) + (RotL64(aCarry, 57U) + RotL64(aIngress, 43U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterH = ((((aWandererC + RotL64(aScatter, 52U)) + RotL64(aCarry, 5U)) + 14179205183062705133U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordK;
            aOrbiterB = (aWandererJ + RotL64(aCross, 47U)) + 210032324058740920U;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 11U)) + RotL64(aCarry, 37U)) + 7387115089142500152U;
            aOrbiterA = (aWandererA + RotL64(aIngress, 43U)) + 17583362781238061430U;
            aOrbiterJ = (((aWandererK + RotL64(aScatter, 57U)) + 4991442849150005943U) + aPhaseFOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1]) + aNonceWordI;
            aOrbiterK = (aWandererB + RotL64(aIngress, 3U)) + 2891376254689854555U;
            aOrbiterG = ((aWandererD + RotL64(aCross, 29U)) + RotL64(aCarry, 13U)) + 10523274382407446239U;
            aOrbiterD = (aWandererI + RotL64(aPrevious, 38U)) + 3861893764676218667U;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 23U)) + 3366674459852093746U) + aNonceWordC;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 5898492634386601145U) + aNonceWordP;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 7047353571244768721U;
            aOrbiterI = RotL64((aOrbiterI * 2257518291062508467U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 14374108805453186316U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 8763667021501226510U;
            aOrbiterB = RotL64((aOrbiterB * 7694695426430267863U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 18261523829316379575U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 650477532238860965U;
            aOrbiterJ = RotL64((aOrbiterJ * 8291758490821819851U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 2162326554604894042U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 5776546692501825278U;
            aOrbiterG = RotL64((aOrbiterG * 14911545784585246537U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 3501863793638415049U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 14853789267425352958U;
            aOrbiterK = RotL64((aOrbiterK * 10590325397179928739U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 15399673014671329743U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 12253428583438990426U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12052855472196447849U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 13202953937621953839U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 7547616636832698398U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9533399972562428073U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 15709801946594868318U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 12458677982746610971U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6662570874316418993U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 6957370791367530127U) + aNonceWordA;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 10511379961344950861U;
            aOrbiterA = RotL64((aOrbiterA * 15551333099264031337U), 3U);
            //
            aIngress = RotL64(aOrbiterK, 53U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 50U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 23U));
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterG, 3U)) + aOrbiterK) + aPhaseFWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aScatter, 57U) + aOrbiterH) + RotL64(aOrbiterD, 39U)) + RotL64(aCarry, 41U)) + aNonceWordF);
            aWandererA = aWandererA ^ ((RotL64(aCross, 18U) + aOrbiterA) + RotL64(aOrbiterJ, 51U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterK, 57U)) + RotL64(aCarry, 3U)) + aNonceWordB);
            aWandererD = aWandererD ^ ((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterJ, 14U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterI, 43U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 36U) + aOrbiterJ) + RotL64(aOrbiterD, 29U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 19U)) + aOrbiterJ);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 34U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 46U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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

void TwistExpander_FootBall_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xA0A789891EED8933ULL + 0xAD194DB9DE23237EULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xDC2EFA6AEE28FB29ULL + 0xC21A6E216267D969ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xC0666FF5AE11BF6FULL + 0xE8FC73815D875286ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xCE1041ADEEA23C2BULL + 0xB7770CB2E416689CULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x94C5947CD3DF21A9ULL + 0xF17D76C4005F55E4ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xC0D5C1C7AC37916DULL + 0x81D13DD8E2602C2EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xA3AB68CB7317A633ULL + 0xAAE48D72D5C6E9BDULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xCBB82CF43842036FULL + 0xEF27DCE616C9855AULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x9BF2DA74596792BBULL + 0x826DCAE3546F5D81ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xCF83D33159B0751DULL + 0xD6FA10E327D9BC3FULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xF6321ACD24F6927BULL + 0xDC55061D48134941ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xDBDA76BA92424E27ULL + 0x9F288C65B3FECA88ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xB3B06B1AA33CD163ULL + 0x8F0B9C080D716D1AULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xCA41278ECD275EFDULL + 0xBA5FF42138A4CCACULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xF93899405EB0373FULL + 0xC7E662DA89BB612FULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xA7A0E5672D04A851ULL + 0xFF23B02736C79E68ULL);
    // GSeedRunSeed_G seed_loop_h (start)
    {
        // GSeedRunSeed_G seed_loop_h lane group
        // read from: aSnowLaneA, aSnowLaneB, aInvestLaneC, aSnowLaneC, aSnowLaneD, aFireLaneA, aWorkLaneA, aFireLaneC, aFireLaneB, aWorkLaneB, aInvestLaneD, aExpandLaneA, aInvestLaneB, aExpandLaneB, aFireLaneD, aExpandLaneC, aInvestLaneA
        // write to: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_h loop 1
        // ingress from: aSnowLaneA, aSnowLaneB, aInvestLaneC
        // ingress directions: aSnowLaneA forward forced, aSnowLaneB forward forced, aInvestLaneC forward/backward random
        // cross from: aSnowLaneC, aSnowLaneD, aFireLaneA
        // cross directions: aSnowLaneC backward forced, aSnowLaneD backward forced, aFireLaneA backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 4632U)) & S_BLOCK1], 47U) ^ RotL64(aSnowLaneB[((aIndex + 124U)) & S_BLOCK1], 26U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 745U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 1707U)) & S_BLOCK1], 57U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 5169U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 2257U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 56U) ^ RotL64(aPrevious, 41U)) + (RotL64(aCross, 29U) ^ RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterC = (aWandererE + RotL64(aScatter, 19U)) + 5960680319644404115U;
            aOrbiterD = ((((aWandererG + RotL64(aCross, 51U)) + RotL64(aCarry, 3U)) + 16050752633567034185U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordE;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 43U)) + RotL64(aCarry, 19U)) + 8447503223226854741U;
            aOrbiterH = ((((aWandererF + RotL64(aPrevious, 27U)) + RotL64(aCarry, 47U)) + 14176813813397917591U) + aPhaseHOrbiterAssignSaltB[((aIndex + 22U)) & S_SALT1]) + aNonceWordO;
            aOrbiterG = (aWandererJ + RotL64(aCross, 12U)) + 10534915376130006644U;
            aOrbiterK = (aWandererD + RotL64(aScatter, 5U)) + 6866224454375302514U;
            aOrbiterB = (aWandererI + RotL64(aIngress, 57U)) + 16506374165041008396U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 7167814023968794098U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 13870852197416596664U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17015971222069856463U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 18064038854848993105U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 9869630811507771691U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13723164383800461387U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 863613100452759380U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 16597969741225436529U;
            aOrbiterC = RotL64((aOrbiterC * 2680793528887208903U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 6575347108051310653U) + aNonceWordH;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 17062262265485019063U;
            aOrbiterB = RotL64((aOrbiterB * 7601045488473620019U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 7193399224636409133U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 14146747818810433849U;
            aOrbiterH = RotL64((aOrbiterH * 5273185769989530041U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 9441449106442431427U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 4303295336545399503U;
            aOrbiterD = RotL64((aOrbiterD * 8829695296836242587U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 12604760768543193458U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 15779327512379787715U) ^ aNonceWordP;
            aOrbiterK = RotL64((aOrbiterK * 14000905201441272597U), 43U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterH, 3U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aCross, 41U) + aOrbiterC) + RotL64(aOrbiterH, 35U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterD, 22U)) + aNonceWordD);
            aWandererE = aWandererE + (((RotL64(aPrevious, 21U) + aOrbiterD) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 27U) + aOrbiterK) + RotL64(aOrbiterA, 29U)) + aNonceWordB) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 12U) + aOrbiterD) + RotL64(aOrbiterB, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 53U)) + aOrbiterK);
            aWandererG = aWandererG + (((((RotL64(aIngress, 5U) + RotL64(aOrbiterG, 13U)) + aOrbiterH) + RotL64(aCarry, 23U)) + aNonceWordA) + aPhaseHWandererUpdateSaltC[((aIndex + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + (RotL64(aWandererF, 46U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 2
        // ingress from: aWorkLaneA, aSnowLaneC, aSnowLaneD, aFireLaneC
        // ingress directions: aWorkLaneA forward forced, aSnowLaneC forward forced, aSnowLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aSnowLaneA, aSnowLaneB, aFireLaneB
        // cross directions: aSnowLaneA backward forced, aSnowLaneB backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 10325U)) & S_BLOCK1], 22U) ^ RotL64(aSnowLaneC[((aIndex + 8321U)) & S_BLOCK1], 53U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 10229U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 7227U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 5954U)) & S_BLOCK1], 10U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 7902U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 6367U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aPrevious, 35U)) + (RotL64(aCarry, 21U) ^ RotL64(aIngress, 50U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterI = ((aWandererH + RotL64(aScatter, 14U)) + 17711946802293254150U) + aNonceWordG;
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 47U)) + 16652362590489569378U) + aPhaseHOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = ((aWandererD + RotL64(aIngress, 3U)) + 6972810344198183097U) + aPhaseHOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = (((aWandererI + RotL64(aCross, 57U)) + RotL64(aCarry, 5U)) + 13117100889782940546U) + aNonceWordO;
            aOrbiterK = ((aWandererB + RotL64(aScatter, 29U)) + RotL64(aCarry, 35U)) + 13199305696782626591U;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 41U)) + RotL64(aCarry, 47U)) + 992156184392760945U;
            aOrbiterB = ((aWandererC + RotL64(aCross, 35U)) + 13791265442074543880U) + aNonceWordJ;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 17057087245252294859U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 13444195995883541046U;
            aOrbiterE = RotL64((aOrbiterE * 13067044288608808777U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 6723678233676059420U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 7913379431208430475U) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 2295062944289127123U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 4481887195529300665U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 11892724101424384078U;
            aOrbiterF = RotL64((aOrbiterF * 3468639499716604111U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 7700902083270424194U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 1888001433557140271U) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 8975562955027025349U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 14996753906788986929U) + aNonceWordP;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 939004845422123765U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2507090308972292313U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 11922230289291941807U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 15681187459741147199U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10124947739653819101U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 9119043713532718155U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 8327697433992362166U;
            aOrbiterB = RotL64((aOrbiterB * 11157657162184304567U), 57U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 51U);
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 12U));
            aIngress = aIngress + RotL64(aOrbiterB, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aPrevious, 5U) + aOrbiterF) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterB, 21U)) + aOrbiterK) + aNonceWordA);
            aWandererI = aWandererI + (((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterA, 50U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterA, 27U)) + aOrbiterI) + aNonceWordE);
            aWandererC = aWandererC + ((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterA, 43U));
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 20U) + aOrbiterC) + RotL64(aOrbiterF, 3U)) + aNonceWordB) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 58U));
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_h loop 3
        // ingress from: aWorkLaneB, aSnowLaneA, aInvestLaneD
        // ingress directions: aWorkLaneB forward forced, aSnowLaneA forward forced, aInvestLaneD forward/backward random
        // cross from: aWorkLaneA, aSnowLaneC
        // cross directions: aWorkLaneA backward forced, aSnowLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 11387U)) & S_BLOCK1], 23U) ^ RotL64(aSnowLaneA[((aIndex + 13115U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aInvestLaneD[((aIndex + 13769U)) & S_BLOCK1], 6U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13965U)) & S_BLOCK1], 12U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 14560U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aIngress, 51U)) + (RotL64(aCross, 23U) + RotL64(aPrevious, 4U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterH = ((aWandererG + RotL64(aCross, 39U)) + 10812151398716051703U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (aWandererI + RotL64(aPrevious, 19U)) + 18202551453336003710U;
            aOrbiterB = (aWandererH + RotL64(aScatter, 29U)) + 9434410809101973752U;
            aOrbiterG = ((((aWandererE + RotL64(aIngress, 5U)) + RotL64(aCarry, 47U)) + 12955829998028534045U) + aPhaseHOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1]) + aNonceWordB;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 58U)) + RotL64(aCarry, 5U)) + 12271740641929640181U;
            aOrbiterK = (aWandererJ + RotL64(aCross, 13U)) + 14009351527014534752U;
            aOrbiterF = (((aWandererB + RotL64(aScatter, 47U)) + RotL64(aCarry, 27U)) + 4316296955679133450U) + aNonceWordM;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 16473324966997442872U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 15735123324965019802U) ^ aNonceWordH;
            aOrbiterB = RotL64((aOrbiterB * 5624078184997601019U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 17656375090484080236U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterG) ^ 16066325053456055298U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterI = RotL64((aOrbiterI * 17912970706985130327U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 12908968778503516903U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = (((aOrbiterG ^ aOrbiterA) ^ 12761433987676836197U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterG = RotL64((aOrbiterG * 1023329467480907925U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 12737513138040664509U) + aNonceWordO;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 14535795767570998392U;
            aOrbiterA = RotL64((aOrbiterA * 15560519667062222269U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 14370908061811284364U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 7001358781208669795U;
            aOrbiterK = RotL64((aOrbiterK * 11641248025734015835U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 7298578161120090849U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 10498302152357484629U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13144110412179037175U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 11447343228638006767U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 18284143620422655675U;
            aOrbiterF = RotL64((aOrbiterF * 572862190073605651U), 13U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 60U);
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 23U));
            aIngress = aIngress + RotL64(aOrbiterF, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterH, 5U)) + aNonceWordI) + aPhaseHWandererUpdateSaltB[((aIndex + 14U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 53U) + aOrbiterG) + RotL64(aOrbiterK, 47U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 36U) + RotL64(aOrbiterI, 27U)) + aOrbiterG);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterI, 11U)) + aOrbiterB) + aPhaseHWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 60U)) + aOrbiterB) + RotL64(aCarry, 57U)) + aNonceWordJ);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterF, 21U)) + aOrbiterI) + aNonceWordL);
            aWandererG = aWandererG + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 35U)) + aOrbiterI) + RotL64(aCarry, 19U)) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererG, 42U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + RotL64(aWandererH, 53U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 4
        // ingress from: aExpandLaneA, aWorkLaneA, aInvestLaneB
        // ingress directions: aExpandLaneA forward forced, aWorkLaneA forward forced, aInvestLaneB forward/backward random
        // cross from: aWorkLaneB, aSnowLaneD
        // cross directions: aWorkLaneB backward forced, aSnowLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 16730U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 18977U)) & S_BLOCK1], 14U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 21139U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17193U)) & S_BLOCK1], 44U) ^ RotL64(aSnowLaneD[((aIndex + 21448U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 13U) ^ RotL64(aIngress, 27U)) ^ (RotL64(aCarry, 41U) + RotL64(aPrevious, 56U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterC = (aWandererC + RotL64(aScatter, 19U)) + 15813325389431304548U;
            aOrbiterB = ((((aWandererE + RotL64(aPrevious, 35U)) + RotL64(aCarry, 29U)) + 2223874171125403602U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordE;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 5U)) + 5510483568496824130U) + aPhaseHOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aIngress, 58U)) + RotL64(aCarry, 41U)) + 15474152493495661876U;
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 51U)) + 16846339705130829195U) + aNonceWordD;
            aOrbiterI = ((aWandererG + RotL64(aCross, 41U)) + RotL64(aCarry, 13U)) + 1289670576865739669U;
            aOrbiterF = (aWandererI + RotL64(aScatter, 27U)) + 18017354919647006944U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 8539685539928984921U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 3333721400836704048U) ^ aNonceWordC;
            aOrbiterJ = RotL64((aOrbiterJ * 3745286323481400085U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 2261560416623815491U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 4377786131746816567U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9164777834392621157U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 18047393176583722719U) + aNonceWordM;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 8184724021940434631U;
            aOrbiterB = RotL64((aOrbiterB * 9800116157750921119U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 10469895939183324807U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 14543391765109879223U;
            aOrbiterC = RotL64((aOrbiterC * 4817987697437667225U), 13U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterF) + 5757225781746158178U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1]) + aNonceWordH;
            aOrbiterI = (((aOrbiterI ^ aOrbiterA) ^ 3539000495894022869U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterI = RotL64((aOrbiterI * 1032298408884695925U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 11288971092707065923U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 2761384065186568294U;
            aOrbiterK = RotL64((aOrbiterK * 3323838837427471051U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 7120580145300417101U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 6977246291769372866U;
            aOrbiterF = RotL64((aOrbiterF * 15170353875184253779U), 3U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 23U);
            aIngress = aIngress + (RotL64(aOrbiterC, 51U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterB, 51U)) + aNonceWordA);
            aWandererC = aWandererC ^ ((((RotL64(aCross, 13U) + aOrbiterC) + RotL64(aOrbiterI, 3U)) + aNonceWordB) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 51U) + aOrbiterI) + RotL64(aOrbiterA, 41U)) + RotL64(aCarry, 5U)) + aNonceWordL);
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 19U) + RotL64(aOrbiterC, 27U)) + aOrbiterJ) + aNonceWordK) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 34U) + aOrbiterF) + RotL64(aOrbiterK, 35U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterA, 57U)) + aOrbiterF);
            aWandererG = aWandererG + (((RotL64(aScatter, 43U) + RotL64(aOrbiterI, 20U)) + aOrbiterF) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + (RotL64(aWandererI, 60U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 39U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_h loop 5
        // ingress from: aExpandLaneB, aWorkLaneB, aFireLaneD
        // ingress directions: aExpandLaneB forward forced, aWorkLaneB forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneA, aWorkLaneA
        // cross directions: aExpandLaneA backward forced, aWorkLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 25175U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((aIndex + 26623U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 25867U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25224U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((aIndex + 25523U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 27U) + RotL64(aIngress, 54U)) + (RotL64(aPrevious, 39U) ^ RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 3U)) + RotL64(aCarry, 19U)) + 966899917801652720U;
            aOrbiterK = ((aWandererA + RotL64(aCross, 29U)) + 10996327672320748649U) + aNonceWordM;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 11U)) + 4188171566846621107U) + aNonceWordA;
            aOrbiterD = (((aWandererJ + RotL64(aIngress, 57U)) + RotL64(aCarry, 3U)) + 5886209243097387959U) + aNonceWordK;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 22U)) + 14940428957136728111U) + aPhaseHOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aScatter, 39U)) + 179187285531914832U) + aNonceWordJ;
            aOrbiterI = (((aWandererH + RotL64(aCross, 47U)) + RotL64(aCarry, 53U)) + 6685351948936817752U) + aPhaseHOrbiterAssignSaltD[((aIndex + 16U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 1894506461704029700U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 4182760368636977082U;
            aOrbiterH = RotL64((aOrbiterH * 972988091869133921U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 12523318028514940790U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 5059306166973366892U;
            aOrbiterJ = RotL64((aOrbiterJ * 2857409765717296483U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 5890872367917643851U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 17747338389865221534U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5306740664798049267U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 13906227834259884100U) + aNonceWordN;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 7152105382899756368U;
            aOrbiterK = RotL64((aOrbiterK * 6772157117358310485U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 17868101884759619240U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 11758843266314148347U;
            aOrbiterD = RotL64((aOrbiterD * 5919135169337501485U), 19U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterD) + 13950566197090324859U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordO;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 17278105609930477854U;
            aOrbiterI = RotL64((aOrbiterI * 11431842718945107359U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 9556785965646738355U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 841298436857932987U;
            aOrbiterF = RotL64((aOrbiterF * 15077843186688841797U), 53U);
            //
            aIngress = RotL64(aOrbiterD, 41U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 54U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 21U));
            aIngress = aIngress + RotL64(aOrbiterF, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterF, 29U)) + aNonceWordB);
            aWandererG = aWandererG + (((RotL64(aPrevious, 30U) + aOrbiterF) + RotL64(aOrbiterH, 21U)) + aPhaseHWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterJ, 14U)) + aOrbiterK);
            aWandererH = aWandererH + ((((RotL64(aScatter, 23U) + aOrbiterK) + RotL64(aOrbiterG, 47U)) + RotL64(aCarry, 3U)) + aNonceWordD);
            aWandererK = aWandererK ^ ((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterG, 35U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 41U) + aOrbiterI) + RotL64(aOrbiterH, 41U)) + RotL64(aCarry, 19U)) + aNonceWordF);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterJ, 3U)) + aOrbiterD) + aPhaseHWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 46U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + RotL64(aWandererK, 23U);
            aCarry = aCarry + RotL64(aIngress, 36U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 6
        // ingress from: aExpandLaneC, aExpandLaneA, aInvestLaneA
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aInvestLaneA forward/backward random
        // cross from: aExpandLaneB, aSnowLaneB
        // cross directions: aExpandLaneB backward forced, aSnowLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 31021U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((aIndex + 29332U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 31228U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28216U)) & S_BLOCK1], 47U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 29521U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 50U)) + (RotL64(aIngress, 21U) ^ RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterI = (aWandererB + RotL64(aIngress, 57U)) + 14214886793361825363U;
            aOrbiterJ = ((aWandererI + RotL64(aCross, 43U)) + 17267959031078766320U) + aNonceWordI;
            aOrbiterG = (((aWandererF + RotL64(aPrevious, 51U)) + RotL64(aCarry, 29U)) + 16436067429484887644U) + aNonceWordC;
            aOrbiterE = (((aWandererK + RotL64(aScatter, 21U)) + RotL64(aCarry, 13U)) + 9885951769332633820U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aIngress, 3U)) + RotL64(aCarry, 57U)) + 12971711341813893304U;
            aOrbiterK = ((aWandererC + RotL64(aCross, 14U)) + 199970353398450154U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aPrevious, 37U)) + 1237341696444162094U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 7991128854417613360U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 14809029847149045833U;
            aOrbiterG = RotL64((aOrbiterG * 5940857360838299105U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 2559509556915775947U) + aNonceWordP;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 14336829730147834160U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15103242520064900873U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 8853631886733610440U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 13346159398673246914U;
            aOrbiterE = RotL64((aOrbiterE * 13660497151446983393U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 12121095718571872976U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 16239781125815589804U;
            aOrbiterK = RotL64((aOrbiterK * 5157009090454962231U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 9051377033794324106U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 13805815136723461780U;
            aOrbiterJ = RotL64((aOrbiterJ * 571129481747181357U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 14849157800322754413U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 18116651528452542634U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3638480428016835537U), 11U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterH) + 4105057226952948599U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1]) + aNonceWordE;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 5911714320560994391U;
            aOrbiterI = RotL64((aOrbiterI * 1796514171654961389U), 27U);
            //
            aIngress = RotL64(aOrbiterK, 51U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + (RotL64(aOrbiterI, 12U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterA, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 21U)) + aOrbiterJ) + RotL64(aCarry, 39U)) + aNonceWordM);
            aWandererC = aWandererC ^ (((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterJ, 37U)) + aPhaseHWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 51U) + aOrbiterI) + RotL64(aOrbiterG, 12U)) + RotL64(aCarry, 21U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterA, 43U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterJ, 27U)) + aPhaseHWandererUpdateSaltB[((aIndex + 16U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 57U) + aOrbiterJ) + RotL64(aOrbiterG, 5U)) + aNonceWordB);
            aWandererG = aWandererG + ((RotL64(aCross, 26U) + RotL64(aOrbiterE, 53U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (RotL64(aWandererB, 18U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 51U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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

void TwistExpander_FootBall_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB;
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
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC;
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 2161U)) & W_KEY1], 41U) ^ RotL64(aKeyRowReadB[((aIndex + 228U)) & W_KEY1], 6U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 1675U)) & W_KEY1], 56U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 1251U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 51U) ^ RotL64(aPrevious, 4U)) + (RotL64(aCross, 39U) + RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (aWandererD + RotL64(aPrevious, 46U)) + 4752759164691497960U;
            aOrbiterI = ((aWandererA + RotL64(aCross, 27U)) + RotL64(aCarry, 19U)) + 12088872623537639782U;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 53U)) + 3734943577379734227U) + aPhaseAOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aScatter, 13U)) + 8854778183012444234U;
            aOrbiterA = (aWandererK + RotL64(aPrevious, 35U)) + 16948373492893967275U;
            aOrbiterH = (aWandererG + RotL64(aIngress, 5U)) + 7962415690046184385U;
            aOrbiterG = (((aWandererH + RotL64(aScatter, 19U)) + RotL64(aCarry, 47U)) + 1872682375669714454U) + aPhaseAOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aCross, 23U)) + 7776801806943853566U;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 42U)) + RotL64(aCarry, 5U)) + 16665439117257230732U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 11088186766134265676U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 10850237991780969350U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7547414856143095121U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 6464817712131305812U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 244557182884209844U;
            aOrbiterF = RotL64((aOrbiterF * 2394270354887582889U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 13261563971157415841U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 2323811103717827362U;
            aOrbiterG = RotL64((aOrbiterG * 11483723582415081925U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 12338803568475493422U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 2811342930111104982U;
            aOrbiterB = RotL64((aOrbiterB * 5020981755203607757U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 5554497011738996057U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 12712169745460598698U;
            aOrbiterH = RotL64((aOrbiterH * 1985586486150377769U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 17415058661427002973U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 9430421222715343818U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10321140659099470811U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 3926618548181233180U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 6172453297026957838U;
            aOrbiterA = RotL64((aOrbiterA * 1161551082037835233U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 8633288765997226004U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 17270881130844274342U;
            aOrbiterD = RotL64((aOrbiterD * 8888559940161770791U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 12232950994807835262U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 15352600312956742750U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6140396356904933003U), 57U);
            //
            aIngress = RotL64(aOrbiterH, 43U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterB, 48U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + RotL64(aOrbiterG, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aScatter, 53U) + aOrbiterJ) + RotL64(aOrbiterA, 51U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 60U)) + aOrbiterA);
            aWandererG = aWandererG + (((RotL64(aCross, 23U) + aOrbiterK) + RotL64(aOrbiterA, 19U)) + RotL64(aCarry, 11U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 44U) + aOrbiterF) + RotL64(aOrbiterI, 41U));
            aWandererE = aWandererE + ((RotL64(aScatter, 19U) + RotL64(aOrbiterB, 11U)) + aOrbiterG);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 11U) + aOrbiterG) + RotL64(aOrbiterA, 27U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 27U) + aOrbiterK) + RotL64(aOrbiterF, 36U)) + RotL64(aCarry, 47U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterD, 3U)) + aOrbiterK) + aPhaseAWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 6U) + aOrbiterA) + RotL64(aOrbiterI, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + RotL64(aWandererB, 6U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 3068U)) & S_BLOCK1], 48U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 4010U)) & W_KEY1], 39U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 2746U)) & W_KEY1], 53U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 4116U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 5U)) + (RotL64(aCross, 42U) ^ RotL64(aIngress, 29U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = ((aWandererB + RotL64(aScatter, 46U)) + RotL64(aCarry, 23U)) + 10805654776556844351U;
            aOrbiterI = (aWandererG + RotL64(aPrevious, 23U)) + 582794182442795335U;
            aOrbiterK = (aWandererE + RotL64(aCross, 11U)) + 2858343650974681068U;
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 19U)) + 8189584049022064284U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = (((aWandererD + RotL64(aPrevious, 51U)) + RotL64(aCarry, 11U)) + 1565100751996962893U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 35U)) + RotL64(aCarry, 35U)) + 8062028016947611891U;
            aOrbiterG = (aWandererH + RotL64(aCross, 40U)) + 8280504280578451745U;
            aOrbiterC = (aWandererA + RotL64(aScatter, 3U)) + 11326869194491655350U;
            aOrbiterH = (aWandererI + RotL64(aCross, 57U)) + 1671695656567777163U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 2349843105293943452U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 13015545152052004254U;
            aOrbiterK = RotL64((aOrbiterK * 1316662811685429983U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 16703354404749291869U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 8713231044374305801U;
            aOrbiterD = RotL64((aOrbiterD * 9242480982197688625U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 11118401674497783533U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 14857556493734710364U;
            aOrbiterJ = RotL64((aOrbiterJ * 3452566050389715195U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 12953419670951660965U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 12666121730825089017U;
            aOrbiterE = RotL64((aOrbiterE * 14049925256934142519U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 11075249639473053423U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 9374217688244187867U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5261156325627117877U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 17608340953291367867U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 13159437499327086340U;
            aOrbiterC = RotL64((aOrbiterC * 4882100944453534805U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 4304700511322366815U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 10172544755256706767U;
            aOrbiterB = RotL64((aOrbiterB * 4013006212154771797U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 17340067939877432472U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 14130447570008179105U;
            aOrbiterH = RotL64((aOrbiterH * 8178075071208718915U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 2652532710498072378U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 10384945384238518296U;
            aOrbiterI = RotL64((aOrbiterI * 17137694272394304045U), 47U);
            //
            aIngress = RotL64(aOrbiterJ, 43U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterB, 26U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 21U));
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterH, 18U)) + aOrbiterE) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 23U) + aOrbiterD) + RotL64(aOrbiterB, 27U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 53U)) + aOrbiterG);
            aWandererG = aWandererG + ((RotL64(aPrevious, 12U) + RotL64(aOrbiterG, 3U)) + aOrbiterB);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 43U)) + aOrbiterB);
            aWandererH = aWandererH + (((RotL64(aPrevious, 43U) + aOrbiterD) + RotL64(aOrbiterE, 14U)) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterI, 23U));
            aWandererK = aWandererK + ((((RotL64(aCross, 36U) + aOrbiterI) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 21U)) + aPhaseAWandererUpdateSaltF[((aIndex + 28U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterI, 37U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 60U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 30U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 5515U)) & S_BLOCK1], 41U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 8072U)) & W_KEY1], 20U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 7499U)) & W_KEY1], 47U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6122U)) & S_BLOCK1], 6U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 6780U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aIngress, 52U)) ^ (RotL64(aCarry, 37U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 39U)) + RotL64(aCarry, 27U)) + 9023059520606551446U;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 21U)) + RotL64(aCarry, 13U)) + 662441755115638133U;
            aOrbiterF = (((aWandererC + RotL64(aCross, 60U)) + RotL64(aCarry, 3U)) + 16957253361196144712U) + aPhaseAOrbiterAssignSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = (aWandererB + RotL64(aIngress, 29U)) + 7840955025765308605U;
            aOrbiterG = (aWandererI + RotL64(aCross, 3U)) + 346855809270395799U;
            aOrbiterA = (aWandererK + RotL64(aIngress, 51U)) + 16099139781586668343U;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 35U)) + 3706457327118322098U) + aPhaseAOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = (aWandererD + RotL64(aScatter, 14U)) + 12166825885547622870U;
            aOrbiterK = (aWandererE + RotL64(aIngress, 43U)) + 7792658665720344200U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 7128477606152986326U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 11116533962780290084U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11993485572912492297U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 10443889548568288532U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 4402387036946561017U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9032964741841833277U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 13002706161178447654U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 13929727277530310708U;
            aOrbiterE = RotL64((aOrbiterE * 7005639090871200285U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 10949073760696935106U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 15405923432006783533U;
            aOrbiterD = RotL64((aOrbiterD * 17989565878445202495U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 18096057968822208905U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 3032155040484574973U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 448597307502544605U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 17462076466907467134U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 15471015427013701406U;
            aOrbiterJ = RotL64((aOrbiterJ * 6113474000571976139U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 3549031751266594344U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 14243218483842508113U;
            aOrbiterI = RotL64((aOrbiterI * 9041601306479302047U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 5803147589312920032U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 5549470512227427855U;
            aOrbiterC = RotL64((aOrbiterC * 12592362489263862879U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 10076661824293832189U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 3196799148974716550U;
            aOrbiterA = RotL64((aOrbiterA * 8183276968961467775U), 23U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterJ, 35U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 30U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterG, 35U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 39U) + aOrbiterC) + RotL64(aOrbiterI, 13U));
            aWandererH = aWandererH + ((RotL64(aScatter, 11U) + aOrbiterA) + RotL64(aOrbiterK, 51U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 19U) + aOrbiterD) + RotL64(aOrbiterA, 20U));
            aWandererD = aWandererD + (((RotL64(aScatter, 48U) + RotL64(aOrbiterE, 39U)) + aOrbiterC) + RotL64(aCarry, 23U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterD, 3U)) + aOrbiterF) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 23U) + aOrbiterJ) + RotL64(aOrbiterI, 27U)) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 43U) + aOrbiterC) + RotL64(aOrbiterK, 60U)) + aPhaseAWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 54U) + aOrbiterF) + RotL64(aOrbiterK, 43U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 40U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + RotL64(aWandererE, 11U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 8226U)) & S_BLOCK1], 34U) ^ RotL64(aKeyRowReadB[((aIndex + 8959U)) & W_KEY1], 53U));
            aIngress ^= (RotL64(mSource[((aIndex + 8598U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 10147U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 9918U)) & W_KEY1], 20U) ^ RotL64(aWorkLaneB[((aIndex + 9896U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 26U) ^ RotL64(aIngress, 57U)) ^ (RotL64(aPrevious, 41U) + RotL64(aCross, 13U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 53U)) + 3621877681473089725U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aCross, 24U)) + 4451752751536414717U;
            aOrbiterG = (aWandererG + RotL64(aScatter, 47U)) + 11371625415377772117U;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 29U)) + 6046792758881150619U) + aPhaseBOrbiterAssignSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = ((aWandererB + RotL64(aCross, 57U)) + RotL64(aCarry, 39U)) + 8213166120394461682U;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 11U)) + RotL64(aCarry, 19U)) + 4343156661140422645U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 41U)) + RotL64(aCarry, 51U)) + 11105271483234947905U;
            aOrbiterB = (aWandererH + RotL64(aIngress, 37U)) + 348904609985341372U;
            aOrbiterA = (aWandererK + RotL64(aScatter, 20U)) + 12924652822526858767U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 7461211697358520287U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 16551553555297890558U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16432952324635746293U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 11908056404140782995U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 9147367258259948715U;
            aOrbiterC = RotL64((aOrbiterC * 10777628928376261667U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 8876461054692728610U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 10546855952702525404U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10071104785895309677U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 4748636139110443794U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 783046909529525098U;
            aOrbiterK = RotL64((aOrbiterK * 8969157702460927215U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 16683965945838696665U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 12385412690177109575U;
            aOrbiterJ = RotL64((aOrbiterJ * 10795062772707143187U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 8210546822184469023U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 13146493623236979963U;
            aOrbiterA = RotL64((aOrbiterA * 13199947810161148155U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 13857628148804187115U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 7241297989337473475U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16223448508809614229U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 773904571213804946U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 7660676598236419707U;
            aOrbiterE = RotL64((aOrbiterE * 14467390638468925567U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 16822672435156055469U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 6514707119190640433U;
            aOrbiterD = RotL64((aOrbiterD * 7097496727567460535U), 43U);
            //
            aIngress = RotL64(aOrbiterG, 47U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterE, 56U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterH, 28U)) + aOrbiterG);
            aWandererD = aWandererD + ((RotL64(aScatter, 5U) + aOrbiterD) + RotL64(aOrbiterK, 39U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterC, 19U)) + aOrbiterH);
            aWandererH = aWandererH + (((RotL64(aIngress, 36U) + RotL64(aOrbiterD, 11U)) + aOrbiterC) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 34U)) + aOrbiterK) + aPhaseBWandererUpdateSaltE[((aIndex + 6U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 47U)) + aOrbiterB) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 23U)) + aOrbiterD);
            aWandererI = aWandererI + (((RotL64(aCross, 19U) + RotL64(aOrbiterD, 53U)) + aOrbiterJ) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 60U) + aOrbiterB) + RotL64(aOrbiterC, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 34U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + RotL64(aWandererG, 50U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 12806U)) & S_BLOCK1], 35U) ^ RotL64(aKeyRowReadA[((aIndex + 13269U)) & W_KEY1], 21U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 11041U)) & W_KEY1], 54U) ^ RotL64(mSource[((aIndex + 12374U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 12680U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12884U)) & S_BLOCK1], 10U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 11774U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 13U) + RotL64(aCross, 57U)) + (RotL64(aCarry, 42U) ^ RotL64(aPrevious, 29U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = (((aWandererB + RotL64(aIngress, 36U)) + RotL64(aCarry, 53U)) + 77518479758428414U) + aPhaseBOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = (aWandererA + RotL64(aPrevious, 29U)) + 4832061802166300011U;
            aOrbiterK = ((aWandererG + RotL64(aCross, 3U)) + RotL64(aCarry, 37U)) + 11695291171006574112U;
            aOrbiterG = (aWandererK + RotL64(aScatter, 23U)) + 7467412817843260094U;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 51U)) + RotL64(aCarry, 23U)) + 17801484124471154757U;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 43U)) + 5555455638503958639U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = (aWandererE + RotL64(aIngress, 47U)) + 5669470540733721606U;
            aOrbiterI = (aWandererJ + RotL64(aCross, 60U)) + 3042388456327784163U;
            aOrbiterB = (aWandererH + RotL64(aScatter, 11U)) + 2236734925228156691U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 14459720401528685450U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 4814967631216658856U;
            aOrbiterK = RotL64((aOrbiterK * 18288097536171386643U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 16950679344449075945U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 6262238639302011050U;
            aOrbiterH = RotL64((aOrbiterH * 9942659897425088183U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 3522256359074996724U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 12524717897707074242U;
            aOrbiterF = RotL64((aOrbiterF * 6787771338063891989U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 13891759914865623828U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 11910250571469028666U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12311343917878428995U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 2240189915640314069U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 5365912986308810837U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15133972552032469957U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 9323732721344489753U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 13087326560957916553U;
            aOrbiterE = RotL64((aOrbiterE * 14659491687401151733U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 16398238057564892809U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 11517870519285159224U;
            aOrbiterB = RotL64((aOrbiterB * 1501848878469712681U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 7758285512254776734U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 17475149091906684720U;
            aOrbiterD = RotL64((aOrbiterD * 6015816725428299273U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 2051631493975035243U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 11684740065349595315U;
            aOrbiterJ = RotL64((aOrbiterJ * 10918975496337269197U), 37U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterJ, 60U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + RotL64(aOrbiterE, 44U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aCross, 53U) + RotL64(aOrbiterE, 60U)) + aOrbiterI);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 5U) + aOrbiterD) + RotL64(aOrbiterB, 5U));
            aWandererK = aWandererK + (((RotL64(aScatter, 30U) + aOrbiterB) + RotL64(aOrbiterF, 29U)) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 11U)) + aOrbiterB) + aPhaseBWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 43U) + aOrbiterD) + RotL64(aOrbiterF, 54U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 19U) + aOrbiterE) + RotL64(aOrbiterG, 37U));
            aWandererB = aWandererB + ((((RotL64(aCross, 39U) + aOrbiterI) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 57U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterE, 23U)) + aOrbiterK);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterE, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 48U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + RotL64(aWandererG, 51U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 15784U)) & S_BLOCK1], 23U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 14266U)) & S_BLOCK1], 12U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15721U)) & W_KEY1], 53U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 15134U)) & W_KEY1], 3U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 15943U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 15212U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 13696U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 21U) ^ RotL64(aCarry, 6U)) ^ (RotL64(aCross, 57U) + RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (aWandererD + RotL64(aScatter, 27U)) + 10726035965553989335U;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 43U)) + 967354339530195662U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 47U)) + 10834593005478605624U;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 3U)) + RotL64(aCarry, 3U)) + 1012888282838656933U;
            aOrbiterH = (aWandererA + RotL64(aScatter, 12U)) + 15283530351725183253U;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 21U)) + RotL64(aCarry, 23U)) + 11724495956731703750U;
            aOrbiterB = ((aWandererK + RotL64(aIngress, 39U)) + RotL64(aCarry, 39U)) + 4288330117317505776U;
            aOrbiterI = (aWandererI + RotL64(aCross, 35U)) + 10894778070022873473U;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 60U)) + 15563886747621617467U) + aPhaseBOrbiterAssignSaltE[((aIndex + 18U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 11182488628562891937U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 10420140066310588580U;
            aOrbiterJ = RotL64((aOrbiterJ * 13898299782819948719U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 11775138062167543111U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 16545391898578161683U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14588306527161321535U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 1550144656312299266U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 14903504853138279883U;
            aOrbiterI = RotL64((aOrbiterI * 8003033561266164387U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 309935535526750396U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 13991265868040011411U;
            aOrbiterB = RotL64((aOrbiterB * 2887531132228588441U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 1755976294857114222U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 2259275858478396846U;
            aOrbiterG = RotL64((aOrbiterG * 7416165760067878161U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 4838175912944552936U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 12307900457200936013U;
            aOrbiterF = RotL64((aOrbiterF * 14719363144850838805U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 18025411832912225805U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 981375022769564523U;
            aOrbiterD = RotL64((aOrbiterD * 15869361544011831483U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 3174014054982742562U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 8119692378748963609U;
            aOrbiterH = RotL64((aOrbiterH * 3072354179707448489U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 14502863160788675807U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 1207582534593709516U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3045412087535529357U), 19U);
            //
            aIngress = RotL64(aOrbiterI, 41U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 23U));
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterD, 56U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterA, 29U));
            aWandererH = aWandererH + ((RotL64(aIngress, 23U) + RotL64(aOrbiterD, 58U)) + aOrbiterG);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 28U) + RotL64(aOrbiterK, 41U)) + aOrbiterF);
            aWandererE = aWandererE + (((RotL64(aScatter, 39U) + aOrbiterD) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterH, 23U)) + aOrbiterG);
            aWandererA = aWandererA + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 6U)) + aOrbiterK) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterF, 37U)) + aOrbiterA) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 6U) + aOrbiterB) + RotL64(aOrbiterJ, 53U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 47U)) + aOrbiterI) + aPhaseBWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + RotL64(aWandererJ, 60U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 16768U)) & S_BLOCK1], 13U) ^ RotL64(aKeyRowReadA[((aIndex + 16930U)) & W_KEY1], 56U));
            aIngress ^= (RotL64(mSource[((aIndex + 18961U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((aIndex + 17385U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 18022U)) & W_KEY1], 6U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 18702U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 17852U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 51U) + RotL64(aCarry, 37U)) ^ (RotL64(aIngress, 3U) ^ RotL64(aCross, 20U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = (aWandererG + RotL64(aIngress, 14U)) + 7270044678408187242U;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 47U)) + RotL64(aCarry, 35U)) + 10192278965379756766U;
            aOrbiterH = (aWandererD + RotL64(aPrevious, 27U)) + 17568666746676060748U;
            aOrbiterD = (((aWandererJ + RotL64(aCross, 57U)) + RotL64(aCarry, 23U)) + 14312927531124963037U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aIngress, 37U)) + 9825825726152087706U;
            aOrbiterI = (aWandererF + RotL64(aScatter, 51U)) + 9696778570255265896U;
            aOrbiterK = ((aWandererE + RotL64(aCross, 19U)) + 17657841352013417228U) + aPhaseCOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 10U)) + 16207815085909628439U;
            aOrbiterC = ((aWandererC + RotL64(aIngress, 41U)) + RotL64(aCarry, 53U)) + 1752979206374514227U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 10456310689643905854U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 16127830548663742550U;
            aOrbiterH = RotL64((aOrbiterH * 4355938404839045417U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 2940917376003930842U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 7353596864777649953U;
            aOrbiterG = RotL64((aOrbiterG * 7499468723171042005U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 12725092740446150705U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 5791296650856037010U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 760379251950502133U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 1200130368046206150U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 16689604428598558547U;
            aOrbiterK = RotL64((aOrbiterK * 13815324235939996623U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 14359561591103730856U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 3975025843599045263U;
            aOrbiterE = RotL64((aOrbiterE * 5025047888533298617U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 14017901732955607601U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 10431526786489555196U;
            aOrbiterD = RotL64((aOrbiterD * 10181915874476132407U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 7320527073559849223U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 15333411223710709907U;
            aOrbiterF = RotL64((aOrbiterF * 3488684905528068775U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 14302474063321663801U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 2104154521019935187U;
            aOrbiterC = RotL64((aOrbiterC * 12944382959742278055U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 5167600586916325228U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 4566823109447208716U;
            aOrbiterI = RotL64((aOrbiterI * 9997799807454267443U), 57U);
            //
            aIngress = RotL64(aOrbiterE, 41U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 24U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 35U) + RotL64(aOrbiterJ, 13U)) + aOrbiterD) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterE, 43U)) + aOrbiterJ) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 48U) + RotL64(aOrbiterH, 6U)) + aOrbiterF) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterE, 35U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 19U) + aOrbiterF) + RotL64(aOrbiterC, 29U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterJ, 19U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterE, 52U)) + aOrbiterD);
            aWandererC = aWandererC ^ ((RotL64(aCross, 13U) + aOrbiterK) + RotL64(aOrbiterI, 57U));
            aWandererA = aWandererA + ((RotL64(aScatter, 44U) + RotL64(aOrbiterC, 47U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 6U));
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererF, 51U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 20961U)) & S_BLOCK1], 40U) ^ RotL64(mSource[((aIndex + 20673U)) & S_BLOCK1], 27U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 19481U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20333U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 20055U)) & W_KEY1], 13U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 19611U)) & W_KEY1], 36U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 20720U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((aIndex + 20022U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCross, 26U)) ^ (RotL64(aIngress, 5U) + RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 27U)) + RotL64(aCarry, 51U)) + 1087148170018530502U;
            aOrbiterK = (aWandererK + RotL64(aIngress, 57U)) + 15530846874509311414U;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 50U)) + RotL64(aCarry, 29U)) + 16987358651515511212U;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 19U)) + 12504143181007924259U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aIngress, 13U)) + RotL64(aCarry, 5U)) + 393322117322732418U;
            aOrbiterG = (aWandererG + RotL64(aCross, 3U)) + 14325937299241887166U;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 34U)) + 9395262907017475742U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (aWandererA + RotL64(aPrevious, 23U)) + 13658510441418344769U;
            aOrbiterF = (aWandererI + RotL64(aScatter, 41U)) + 6410754322737005336U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 9257290738538818434U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 7489828960857692286U;
            aOrbiterA = RotL64((aOrbiterA * 16519674788777989043U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 4118778591214588387U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 16619215231168796563U;
            aOrbiterI = RotL64((aOrbiterI * 14876884956536265157U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 11326283811003573430U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 1865401866017614604U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8378326058282460073U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 670150121105733604U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 1499331510641068749U;
            aOrbiterC = RotL64((aOrbiterC * 16623742535540383107U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 1116410848560838532U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 2696841341036281779U;
            aOrbiterE = RotL64((aOrbiterE * 9598953298074904869U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 5487352391229549881U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 12008243050943342979U;
            aOrbiterF = RotL64((aOrbiterF * 9087261224804582459U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 552859665927882960U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 8426942688524814473U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10916963622695549105U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 1613287981244830815U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 15592897923468694288U;
            aOrbiterG = RotL64((aOrbiterG * 6600750586743893303U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 7629853970631002676U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 13778028957247561272U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4063798788229605659U), 5U);
            //
            aIngress = RotL64(aOrbiterF, 53U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 14U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 57U) + RotL64(aOrbiterD, 39U)) + aOrbiterE) + aPhaseCWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 52U) + RotL64(aOrbiterD, 5U)) + aOrbiterG);
            aWandererD = aWandererD + (((RotL64(aScatter, 37U) + aOrbiterC) + RotL64(aOrbiterF, 53U)) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterI, 10U)) + aOrbiterG);
            aWandererA = aWandererA + ((RotL64(aScatter, 41U) + aOrbiterE) + RotL64(aOrbiterH, 23U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterK, 19U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterC, 27U)) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 23U) + aOrbiterI) + RotL64(aOrbiterE, 57U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 30U) + aOrbiterA) + RotL64(aOrbiterF, 14U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + RotL64(aWandererA, 48U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 23289U)) & S_BLOCK1], 39U) ^ RotL64(aKeyRowReadA[((aIndex + 23654U)) & W_KEY1], 30U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 23367U)) & W_KEY1], 13U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 24214U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 21852U)) & S_BLOCK1], 53U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23977U)) & S_BLOCK1], 12U));
            aCross ^= (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 23015U)) & S_BLOCK1], 23U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 24527U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 36U) ^ RotL64(aPrevious, 57U)) + (RotL64(aCarry, 5U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = (aWandererE + RotL64(aIngress, 60U)) + 13960289014350612206U;
            aOrbiterF = ((aWandererB + RotL64(aCross, 47U)) + RotL64(aCarry, 21U)) + 3483331015269589730U;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 35U)) + RotL64(aCarry, 5U)) + 6873299241002444518U;
            aOrbiterD = (aWandererD + RotL64(aScatter, 39U)) + 3562094007125534229U;
            aOrbiterH = (aWandererC + RotL64(aPrevious, 52U)) + 11422367439932782705U;
            aOrbiterC = ((aWandererK + RotL64(aCross, 43U)) + 532453428514259816U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 19U)) + RotL64(aCarry, 41U)) + 17810941465810193088U;
            aOrbiterA = ((aWandererF + RotL64(aScatter, 23U)) + 11869759058631106331U) + aPhaseCOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aCross, 27U)) + 8837581071876177566U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 17185378327053837778U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 7578253375676981500U;
            aOrbiterI = RotL64((aOrbiterI * 13371647568758721729U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 17112646434432814442U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 14949096407295697881U;
            aOrbiterH = RotL64((aOrbiterH * 14770977858283051753U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 4259590620758467836U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 6534899413644542303U;
            aOrbiterB = RotL64((aOrbiterB * 7987609419215568661U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 2637407498893694243U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 15819295597921425711U;
            aOrbiterJ = RotL64((aOrbiterJ * 5202015597375051399U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 6373559542002699718U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 11694562937392022505U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9311557972331218597U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 3308736483775453062U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 12749929710650475901U;
            aOrbiterE = RotL64((aOrbiterE * 248428400724560945U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 1569528215675579656U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 1044077933631689572U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6443796233912755143U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 8393422728124537471U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 2002732612516530754U;
            aOrbiterD = RotL64((aOrbiterD * 13702146823622364279U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 13469191942843147943U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 7633171368709520560U;
            aOrbiterA = RotL64((aOrbiterA * 9713514012478203047U), 27U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterD, 54U);
            aIngress = aIngress + (RotL64(aOrbiterA, 29U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterB, 11U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterF, 57U)) + aOrbiterB) + aPhaseCWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 51U) + aOrbiterF) + RotL64(aOrbiterH, 44U)) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 5U)) + aOrbiterE);
            aWandererF = aWandererF + (((RotL64(aCross, 60U) + aOrbiterE) + RotL64(aOrbiterB, 53U)) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 5U) + aOrbiterF) + RotL64(aOrbiterJ, 35U));
            aWandererA = aWandererA + ((RotL64(aIngress, 13U) + aOrbiterD) + RotL64(aOrbiterF, 27U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterF, 13U)) + aOrbiterI);
            aWandererH = aWandererH + (((RotL64(aCross, 39U) + RotL64(aOrbiterI, 23U)) + aOrbiterC) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 44U) + aOrbiterJ) + RotL64(aOrbiterA, 18U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + RotL64(aWandererJ, 48U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 24646U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadA[((aIndex + 25115U)) & W_KEY1], 41U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 24680U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 24924U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 26683U)) & W_KEY1], 60U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26887U)) & S_BLOCK1], 29U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 25885U)) & S_BLOCK1], 41U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 24767U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aPrevious, 3U)) ^ (RotL64(aIngress, 19U) ^ RotL64(aCross, 54U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = (aWandererA + RotL64(aIngress, 29U)) + 13583136155674166402U;
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 47U)) + RotL64(aCarry, 5U)) + 12830472187484919497U;
            aOrbiterK = (aWandererH + RotL64(aCross, 3U)) + 18081197909484522509U;
            aOrbiterG = ((aWandererB + RotL64(aScatter, 20U)) + RotL64(aCarry, 19U)) + 8680634051297891550U;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 13U)) + 13939998767458656823U;
            aOrbiterJ = ((aWandererI + RotL64(aCross, 43U)) + 1795730579103692594U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (aWandererE + RotL64(aIngress, 39U)) + 17369751719734069999U;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 51U)) + 224769585901248068U) + aPhaseDOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = ((aWandererC + RotL64(aCross, 60U)) + RotL64(aCarry, 35U)) + 4133547085925268180U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 7022512056309567391U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 10319484359046945495U;
            aOrbiterK = RotL64((aOrbiterK * 3400140531307001933U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 10483878349412282069U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 6481381149199985736U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9701719367082506253U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 13721077228796934509U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 9704818014314175007U;
            aOrbiterA = RotL64((aOrbiterA * 760445624027740287U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 6253040047758584339U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 16890211690273641226U;
            aOrbiterG = RotL64((aOrbiterG * 5622534399866057841U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 6216227831265032436U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 2023609047004658739U;
            aOrbiterH = RotL64((aOrbiterH * 3252332895698310147U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 9201669637050388263U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 5106927540934338576U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6368134569042291431U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 10080368957861445998U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 10784789383436485808U;
            aOrbiterD = RotL64((aOrbiterD * 3794918350254445939U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 15426339824951793026U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 17637144549368340331U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10971293914614704441U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 9941300382181962134U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 8118046374121322097U;
            aOrbiterB = RotL64((aOrbiterB * 8481945819050983127U), 57U);
            //
            aIngress = RotL64(aOrbiterK, 6U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + (RotL64(aOrbiterG, 39U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterD, 34U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aCross, 53U) + RotL64(aOrbiterH, 39U)) + aOrbiterB);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 60U) + aOrbiterJ) + RotL64(aOrbiterD, 47U));
            aWandererK = aWandererK + (((RotL64(aScatter, 47U) + aOrbiterK) + RotL64(aOrbiterG, 4U)) + RotL64(aCarry, 35U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 43U)) + aOrbiterA);
            aWandererE = aWandererE + ((((RotL64(aCross, 27U) + RotL64(aOrbiterJ, 19U)) + aOrbiterC) + RotL64(aCarry, 11U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 40U) + aOrbiterH) + RotL64(aOrbiterJ, 23U));
            aWandererA = aWandererA + (((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterJ, 35U)) + aPhaseDWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 53U)) + aOrbiterK);
            aWandererD = aWandererD + ((RotL64(aIngress, 23U) + aOrbiterC) + RotL64(aOrbiterG, 10U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 30U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 27692U)) & S_BLOCK1], 20U) ^ RotL64(aFireLaneD[((aIndex + 28324U)) & S_BLOCK1], 39U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 27730U)) & W_KEY1], 51U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 27594U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 29754U)) & W_KEY1], 6U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 27567U)) & S_BLOCK1], 35U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27818U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneB[((aIndex + 28172U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCarry, 50U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = (aWandererJ + RotL64(aScatter, 42U)) + 3238389262925516513U;
            aOrbiterB = (aWandererI + RotL64(aCross, 13U)) + 12381787182611386995U;
            aOrbiterA = (((aWandererB + RotL64(aPrevious, 47U)) + RotL64(aCarry, 23U)) + 7883885539305181549U) + aPhaseDOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aIngress, 3U)) + 1185413044597727092U;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 60U)) + RotL64(aCarry, 5U)) + 15219353497204773135U;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 53U)) + 7533774715626734082U;
            aOrbiterF = (aWandererG + RotL64(aCross, 29U)) + 2599930450937763464U;
            aOrbiterE = (((aWandererH + RotL64(aIngress, 35U)) + RotL64(aCarry, 13U)) + 16074720663961214284U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aPrevious, 19U)) + 15483613196360051221U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 9396557867081376268U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 9668459976852660245U;
            aOrbiterA = RotL64((aOrbiterA * 11748505665890567063U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 9037269914643207212U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 16936742640861088240U;
            aOrbiterD = RotL64((aOrbiterD * 1040172193161012227U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 16481274825758546398U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 481851372837611166U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2225030139210599207U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 13608921517203544108U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 16930740723286214636U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2605108503821980865U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 902242902582149908U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 1510861213079342977U;
            aOrbiterE = RotL64((aOrbiterE * 3309753895727400707U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 7116243600304980310U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 6631412278359709602U;
            aOrbiterJ = RotL64((aOrbiterJ * 11452627691392637463U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 9246698682265275165U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 8594373032014031450U;
            aOrbiterG = RotL64((aOrbiterG * 2550138341089957033U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 15912837963877821048U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 11404583513022627609U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17715204726760125357U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 17295214920690244319U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 18315664494984189344U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17398893532076312945U), 51U);
            //
            aIngress = RotL64(aOrbiterK, 53U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 40U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 53U) + aOrbiterE) + RotL64(aOrbiterD, 58U));
            aWandererH = aWandererH + (((RotL64(aScatter, 58U) + RotL64(aOrbiterE, 35U)) + aOrbiterF) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterB, 51U)) + aOrbiterG);
            aWandererF = aWandererF + (((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 29U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterK, 39U)) + aOrbiterA);
            aWandererI = aWandererI + ((RotL64(aIngress, 29U) + aOrbiterI) + RotL64(aOrbiterK, 30U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 21U)) + aOrbiterD) + aPhaseDWandererUpdateSaltF[((aIndex + 10U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterF, 5U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 10U) + aOrbiterE) + RotL64(aOrbiterJ, 47U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 38U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + RotL64(aWandererJ, 23U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 30277U)) & S_BLOCK1], 53U) ^ RotL64(aKeyRowReadA[((aIndex + 30135U)) & W_KEY1], 20U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 31432U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31171U)) & S_BLOCK1], 21U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31766U)) & S_BLOCK1], 41U) ^ RotL64(aKeyRowReadB[((aIndex + 31352U)) & W_KEY1], 13U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aPrevious, 41U)) ^ (RotL64(aCarry, 14U) + RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = (aWandererF + RotL64(aScatter, 19U)) + 4773124477323378268U;
            aOrbiterJ = (((aWandererD + RotL64(aPrevious, 4U)) + RotL64(aCarry, 3U)) + 16848723289435796005U) + aPhaseDOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = (((aWandererH + RotL64(aCross, 27U)) + RotL64(aCarry, 37U)) + 13846642134917107058U) + aPhaseDOrbiterAssignSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aIngress, 23U)) + 6472057872482789939U;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 35U)) + 2747019500690707226U;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 51U)) + RotL64(aCarry, 27U)) + 9003965289739733880U;
            aOrbiterD = (aWandererI + RotL64(aIngress, 44U)) + 3013390651936257377U;
            aOrbiterB = (aWandererG + RotL64(aCross, 39U)) + 3331004709895625067U;
            aOrbiterG = (aWandererA + RotL64(aScatter, 57U)) + 15355010435553517129U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 7709870658004280052U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 13568728443963926564U;
            aOrbiterE = RotL64((aOrbiterE * 6736090830113688981U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 12409548853419307131U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 969183352023661537U;
            aOrbiterF = RotL64((aOrbiterF * 5549220554838837145U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 15370309834426476775U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 3896803894396631184U;
            aOrbiterB = RotL64((aOrbiterB * 11018830202891911603U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 10848873633291935766U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 12885336509190543440U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1487357252619221365U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 8252290890093788010U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 9201553615601641350U;
            aOrbiterD = RotL64((aOrbiterD * 420321130559162915U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 14014209645503188472U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 4015071464301844550U;
            aOrbiterH = RotL64((aOrbiterH * 17444195018239904971U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 16173085647514027347U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 16916627014974363360U;
            aOrbiterK = RotL64((aOrbiterK * 7699587344277490953U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 1591680303404522110U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 16499606051269327916U;
            aOrbiterG = RotL64((aOrbiterG * 814405848002794813U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 6932673635509444619U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 8745681160108707944U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14565255558668084787U), 43U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 23U);
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 42U));
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 51U) + aOrbiterF) + RotL64(aOrbiterJ, 56U)) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterE, 19U)) + aOrbiterK);
            aWandererI = aWandererI + (((RotL64(aIngress, 43U) + RotL64(aOrbiterE, 23U)) + aOrbiterH) + RotL64(aCarry, 37U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 12U) + RotL64(aOrbiterJ, 13U)) + aOrbiterD) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 19U) + RotL64(aOrbiterG, 3U)) + aOrbiterB);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 37U) + aOrbiterD) + RotL64(aOrbiterG, 47U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterF, 52U)) + aOrbiterI);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 58U) + aOrbiterB) + RotL64(aOrbiterD, 37U));
            aWandererD = aWandererD + ((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 29U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererG, 60U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 35U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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

void TwistExpander_FootBall_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneD, aExpandLaneC, aExpandLaneD, aInvestLaneC, aFireLaneA, aInvestLaneD, aFireLaneC, aOperationLaneA, aFireLaneB, aOperationLaneB, aOperationLaneC
        // write to: aInvestLaneC, aInvestLaneD, aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // twist_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneD
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 4544U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((aIndex + 606U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 3134U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2636U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneD[((aIndex + 1998U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 51U)) + (RotL64(aIngress, 39U) ^ RotL64(aCross, 24U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = (aWandererI + RotL64(aIngress, 13U)) + 12535417189990029950U;
            aOrbiterG = (aWandererA + RotL64(aPrevious, 21U)) + 6204401443676390273U;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 37U)) + 869613505613154672U) + aPhaseEOrbiterAssignSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aCross, 43U)) + RotL64(aCarry, 5U)) + 15053590879563855802U;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 3U)) + 13338989605204591428U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 51U)) + RotL64(aCarry, 35U)) + 18306470022403825392U;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 60U)) + RotL64(aCarry, 47U)) + 1150696349434090218U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 13549541786420596437U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 14302878430259588461U;
            aOrbiterC = RotL64((aOrbiterC * 16813606782134305513U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 4660437084477165225U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 1653628537860912069U;
            aOrbiterJ = RotL64((aOrbiterJ * 2624835201155303123U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 5594199757006711631U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 11008472193138708891U;
            aOrbiterE = RotL64((aOrbiterE * 13645764762027798301U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 3668516817279364310U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 128159531749679984U;
            aOrbiterB = RotL64((aOrbiterB * 4523246859249826987U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 6378674346113979108U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 11438762460659123362U;
            aOrbiterF = RotL64((aOrbiterF * 2733309638158283953U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 10624263004446482910U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 12546839706919241411U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11468326687628079347U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 8466639576503293921U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 5828694979857951504U;
            aOrbiterD = RotL64((aOrbiterD * 7835487310289634515U), 23U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterD, 43U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 34U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + RotL64(aOrbiterB, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aCross, 35U) + RotL64(aOrbiterC, 53U)) + aOrbiterF) + RotL64(aCarry, 29U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 43U)) + aOrbiterB);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 14U) + RotL64(aOrbiterG, 37U)) + aOrbiterF) + RotL64(aCarry, 3U)) + aPhaseEWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 47U) + aOrbiterC) + RotL64(aOrbiterJ, 3U));
            aWandererA = aWandererA + ((RotL64(aIngress, 21U) + aOrbiterE) + RotL64(aOrbiterD, 19U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 11U)) + aOrbiterD) + aPhaseEWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 53U) + aOrbiterE) + RotL64(aOrbiterC, 30U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 12U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 6587U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((aIndex + 5473U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 5570U)) & S_BLOCK1], 22U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 8316U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((aIndex + 9395U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 26U) ^ RotL64(aIngress, 43U)) + (RotL64(aCarry, 11U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = ((aWandererE + RotL64(aIngress, 11U)) + RotL64(aCarry, 5U)) + 7960325128608297381U;
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 57U)) + 12773836012104052042U) + aPhaseEOrbiterAssignSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aCross, 19U)) + 3173972621347773016U;
            aOrbiterJ = (aWandererC + RotL64(aScatter, 43U)) + 3708401356314308171U;
            aOrbiterG = (aWandererD + RotL64(aCross, 51U)) + 950774285720019449U;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 5U)) + RotL64(aCarry, 19U)) + 4170092315705438265U;
            aOrbiterA = (((aWandererH + RotL64(aPrevious, 34U)) + RotL64(aCarry, 43U)) + 17000449130864980747U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 8793910540062893860U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 520277969543516469U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4150613128885828229U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 12762214857389827271U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 2932451184340207695U;
            aOrbiterG = RotL64((aOrbiterG * 7513337346940091655U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 11062179998786293839U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 7919119215271524178U;
            aOrbiterE = RotL64((aOrbiterE * 9053677007180081359U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 1774988449597115155U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 3799792889466518953U;
            aOrbiterJ = RotL64((aOrbiterJ * 17512791286490623455U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 1815062051307896589U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 15260373951371654483U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2208604434669491625U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 12867546628945676853U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 7772820973895846946U;
            aOrbiterB = RotL64((aOrbiterB * 7581704643538761985U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 14213957831821966834U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 16561105721170419454U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2540533987337175367U), 5U);
            //
            aIngress = RotL64(aOrbiterJ, 41U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterB, 43U)) + aOrbiterG);
            aWandererE = aWandererE + (((RotL64(aScatter, 56U) + aOrbiterJ) + RotL64(aOrbiterE, 28U)) + RotL64(aCarry, 23U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterC, 11U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterI, 35U)) + aPhaseEWandererUpdateSaltB[((aIndex + 14U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 29U) + aOrbiterG) + RotL64(aOrbiterJ, 53U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterA, 5U)) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterA, 21U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererH, 58U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 35U);
            aCarry = aCarry + RotL64(aIngress, 24U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aInvestLaneD[((aIndex + 14091U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneD[((aIndex + 11865U)) & S_BLOCK1], 34U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 11122U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 14130U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 14818U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aExpandLaneA[((aIndex + 15783U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCross, 44U)) ^ (RotL64(aPrevious, 11U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = ((aWandererI + RotL64(aIngress, 11U)) + RotL64(aCarry, 27U)) + 15036852811491820366U;
            aOrbiterB = (((aWandererB + RotL64(aCross, 29U)) + RotL64(aCarry, 39U)) + 305637140752898475U) + aPhaseEOrbiterAssignSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aScatter, 21U)) + RotL64(aCarry, 51U)) + 11948631574496129610U;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 3U)) + 5321623592482991426U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = (aWandererD + RotL64(aScatter, 57U)) + 4075270159062690728U;
            aOrbiterC = (aWandererK + RotL64(aCross, 37U)) + 15111580500356908928U;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 50U)) + 7244150695504160363U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 5131563519577488862U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 5881954992088651371U;
            aOrbiterG = RotL64((aOrbiterG * 2424421828597294607U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 12780935808751507998U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 12599159643925470226U;
            aOrbiterB = RotL64((aOrbiterB * 17690046932587062701U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 9466589929741834066U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 6093158735705189789U;
            aOrbiterD = RotL64((aOrbiterD * 7453778295800853653U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 17461243886150519249U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 15456408913739900718U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16093292401746174671U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 11260643903290392780U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 7870342756041882616U;
            aOrbiterI = RotL64((aOrbiterI * 2431528656086173419U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 134484990005888936U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 10626896209992890407U;
            aOrbiterF = RotL64((aOrbiterF * 12034131076645285597U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 14031164129515132292U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 1771835705730244212U;
            aOrbiterA = RotL64((aOrbiterA * 186981668443596623U), 13U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterB, 57U);
            aIngress = aIngress + (RotL64(aOrbiterD, 40U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterF, 51U)) + aOrbiterI) + RotL64(aCarry, 29U)) + aPhaseEWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 57U) + aOrbiterC) + RotL64(aOrbiterA, 43U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterC, 19U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 37U) + aOrbiterA) + RotL64(aOrbiterB, 28U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 37U)) + aOrbiterD) + RotL64(aCarry, 53U)) + aPhaseEWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 26U) + RotL64(aOrbiterD, 5U)) + aOrbiterI);
            aWandererE = aWandererE + ((RotL64(aIngress, 47U) + RotL64(aOrbiterG, 57U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 26U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_b loop 4
        // ingress from: aOperationLaneA, aInvestLaneC, aFireLaneB
        // ingress directions: aOperationLaneA forward forced, aInvestLaneC forward forced, aFireLaneB forward/backward random
        // cross from: aInvestLaneD, aExpandLaneD, aExpandLaneC
        // cross directions: aInvestLaneD backward forced, aExpandLaneD backward forced, aExpandLaneC backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 17539U)) & S_BLOCK1], 58U) ^ RotL64(aInvestLaneC[((aIndex + 19260U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21671U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 17575U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20377U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 17351U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aPrevious, 37U)) ^ (RotL64(aCarry, 5U) + RotL64(aIngress, 50U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 60U)) + 77518479758428414U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = ((aWandererG + RotL64(aScatter, 3U)) + RotL64(aCarry, 39U)) + 4832061802166300011U;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 29U)) + RotL64(aCarry, 5U)) + 11695291171006574112U;
            aOrbiterH = (aWandererD + RotL64(aCross, 19U)) + 7467412817843260094U;
            aOrbiterD = (aWandererB + RotL64(aIngress, 13U)) + 17801484124471154757U;
            aOrbiterE = (aWandererK + RotL64(aPrevious, 37U)) + 5555455638503958639U;
            aOrbiterB = (((aWandererC + RotL64(aCross, 53U)) + RotL64(aCarry, 19U)) + 5669470540733721606U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 3042388456327784163U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 2236734925228156691U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10076582424701705531U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 14459720401528685450U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 4814967631216658856U;
            aOrbiterG = RotL64((aOrbiterG * 18288097536171386643U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 16950679344449075945U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 6262238639302011050U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9942659897425088183U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 3522256359074996724U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 12524717897707074242U;
            aOrbiterE = RotL64((aOrbiterE * 6787771338063891989U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 13891759914865623828U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 11910250571469028666U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12311343917878428995U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 2240189915640314069U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 5365912986308810837U;
            aOrbiterB = RotL64((aOrbiterB * 15133972552032469957U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 9323732721344489753U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 13087326560957916553U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14659491687401151733U), 41U);
            //
            aIngress = RotL64(aOrbiterB, 37U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 6U));
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterE, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aCross, 57U) + aOrbiterB) + RotL64(aOrbiterD, 39U)) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 10U) + aOrbiterA) + RotL64(aOrbiterD, 60U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterA, 13U)) + aOrbiterI);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterA, 47U)) + aOrbiterG) + aPhaseEWandererUpdateSaltC[((aIndex + 4U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 5U)) + aOrbiterG) + RotL64(aCarry, 27U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterE, 29U)) + aOrbiterA) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 19U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 34U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 51U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 26165U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneA[((aIndex + 26093U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 23216U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 24031U)) & S_BLOCK1], 23U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 22418U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 22212U)) & S_BLOCK1], 42U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCross, 27U)) ^ (RotL64(aCarry, 57U) + RotL64(aPrevious, 12U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = (aWandererK + RotL64(aCross, 5U)) + 7651355040951791298U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 13U)) + RotL64(aCarry, 43U)) + 13988210277931659312U;
            aOrbiterE = (aWandererE + RotL64(aPrevious, 37U)) + 9846849412579537783U;
            aOrbiterH = (((aWandererJ + RotL64(aIngress, 29U)) + RotL64(aCarry, 3U)) + 12746719939495876158U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aCross, 56U)) + 11498066185182895284U;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 43U)) + 11101058955193080232U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 21U)) + RotL64(aCarry, 29U)) + 15513734459555672046U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 15711108675349394643U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 4771231759949468556U;
            aOrbiterE = RotL64((aOrbiterE * 9806191054594333615U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 11449258010811305256U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 17036938391509986723U;
            aOrbiterG = RotL64((aOrbiterG * 7411466953205347639U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 6999245666776654250U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 2106819066263369528U;
            aOrbiterF = RotL64((aOrbiterF * 13005885810757743129U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 12716183358903477216U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 16752724547046059889U;
            aOrbiterK = RotL64((aOrbiterK * 11475905692393034141U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 17623077680983093163U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 6726003022297274986U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14709385877103232653U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 2842410225096524740U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 9235178377537910514U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11813751114775673845U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 2619888019860844610U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 6295481948199619613U;
            aOrbiterJ = RotL64((aOrbiterJ * 15429161806953951205U), 51U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 3U);
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterH, 28U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 19U)) + aOrbiterH);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 27U) + aOrbiterG) + RotL64(aOrbiterF, 43U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 39U) + aOrbiterK) + RotL64(aOrbiterJ, 34U)) + RotL64(aCarry, 51U)) + aPhaseEWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 21U) + aOrbiterA) + RotL64(aOrbiterE, 5U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 51U)) + aOrbiterF) + aPhaseEWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 27U)) + aOrbiterA);
            aWandererG = aWandererG + (((RotL64(aIngress, 46U) + RotL64(aOrbiterE, 57U)) + aOrbiterJ) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + RotL64(aWandererD, 18U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 28919U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneA[((aIndex + 27998U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27753U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31310U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31715U)) & S_BLOCK1], 20U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 31052U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 29U) ^ RotL64(aIngress, 41U)) + (RotL64(aCarry, 12U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = (aWandererE + RotL64(aCross, 19U)) + 4068921616130916949U;
            aOrbiterA = (aWandererA + RotL64(aPrevious, 43U)) + 12077715273915151726U;
            aOrbiterC = (aWandererF + RotL64(aIngress, 57U)) + 16047546802670596833U;
            aOrbiterJ = (((aWandererB + RotL64(aScatter, 26U)) + RotL64(aCarry, 23U)) + 9690277462716999763U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aPrevious, 13U)) + 14484814700447992628U;
            aOrbiterK = (((aWandererI + RotL64(aCross, 35U)) + RotL64(aCarry, 35U)) + 17089267243053958210U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = ((aWandererG + RotL64(aIngress, 5U)) + RotL64(aCarry, 53U)) + 9138746214446211147U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 10181001536979097045U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 6657458969093373191U;
            aOrbiterC = RotL64((aOrbiterC * 4311019792293202747U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 7515983477876590988U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 3039935555863947600U;
            aOrbiterH = RotL64((aOrbiterH * 12511160550780270119U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 16209389224740851136U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 725253312098083182U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17535989492095522597U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 13307041115748941383U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 7159572004825238263U;
            aOrbiterJ = RotL64((aOrbiterJ * 4855009895002398449U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 12027236743251643820U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 8717826175991286553U;
            aOrbiterB = RotL64((aOrbiterB * 1175614802543098451U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 4769096034227659937U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 11201226563992939616U;
            aOrbiterI = RotL64((aOrbiterI * 15595355978388159931U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 17295978531215563256U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 11850923890626719833U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3854851059897397075U), 47U);
            //
            aIngress = RotL64(aOrbiterB, 13U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aScatter, 57U) + aOrbiterH) + RotL64(aOrbiterI, 41U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aCross, 20U) + RotL64(aOrbiterB, 13U)) + aOrbiterI) + RotL64(aCarry, 5U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterK, 19U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterK, 5U)) + aOrbiterI);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 47U)) + aOrbiterI);
            aWandererG = aWandererG + (((RotL64(aPrevious, 11U) + aOrbiterA) + RotL64(aOrbiterJ, 53U)) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 60U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 4U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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

void TwistExpander_FootBall_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
        // read from: aOperationLaneA, aOperationLaneB, aExpandLaneC, aOperationLaneC, aOperationLaneD, aInvestLaneC, aSnowLaneA, aInvestLaneD, aInvestLaneB, aSnowLaneB, aInvestLaneA, aWorkLaneA, aExpandLaneB, aWorkLaneB, aExpandLaneA, aWorkLaneC, aExpandLaneD
        // write to: aSnowLaneA, aSnowLaneB, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // twist_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aExpandLaneC
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aExpandLaneC forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aInvestLaneC
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aInvestLaneC backward/forward random
        // write to: aSnowLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 3380U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((aIndex + 75U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 3282U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 1945U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 4958U)) & S_BLOCK1], 40U));
            aCross ^= RotL64(aInvestLaneC[((aIndex + 455U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCross, 24U)) ^ (RotL64(aCarry, 39U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 21U)) + 8375305456876489425U;
            aOrbiterI = (aWandererE + RotL64(aIngress, 12U)) + 16193562952772453047U;
            aOrbiterE = ((aWandererC + RotL64(aCross, 5U)) + RotL64(aCarry, 11U)) + 18088652458594816223U;
            aOrbiterC = (aWandererK + RotL64(aScatter, 29U)) + 767344788620249944U;
            aOrbiterF = ((aWandererA + RotL64(aCross, 39U)) + 7705194930396368752U) + aPhaseFOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 27U)) + 3829736891311272834U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aScatter, 41U)) + RotL64(aCarry, 3U)) + 9881681671347640061U;
            aOrbiterK = (aWandererG + RotL64(aIngress, 51U)) + 1721196560190164264U;
            aOrbiterJ = (aWandererB + RotL64(aCross, 57U)) + 3002652618388454213U;
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 48U)) + RotL64(aCarry, 41U)) + 9811621464004005202U;
            aOrbiterB = (aWandererF + RotL64(aScatter, 19U)) + 5652598941069986530U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 6250499348327316328U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 16025054277615264530U;
            aOrbiterE = RotL64((aOrbiterE * 16446892258704281903U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 13800298546867243172U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 12256104592865905782U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16983140179497142713U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 17817225416918329229U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 17738671327352776217U;
            aOrbiterK = RotL64((aOrbiterK * 393488251327705063U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 6816031224188400541U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 16989563985059237014U;
            aOrbiterJ = RotL64((aOrbiterJ * 8677884225771717797U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 16891524847268207549U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 1833508573940405571U;
            aOrbiterF = RotL64((aOrbiterF * 9709196587703979539U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 12729999421507068973U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 6839758643521968957U;
            aOrbiterA = RotL64((aOrbiterA * 16350557395881283975U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 8524167125469267428U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 14741523560290472617U;
            aOrbiterB = RotL64((aOrbiterB * 4367850822282205897U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 10983798459868424892U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 5649250846622078964U;
            aOrbiterC = RotL64((aOrbiterC * 7149612714806023987U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 8587302028325090061U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 17457129226030333666U;
            aOrbiterG = RotL64((aOrbiterG * 18107356450566915215U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 15600113588474915690U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 6595247491374683783U;
            aOrbiterI = RotL64((aOrbiterI * 1432432381540098765U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 13246325856585534283U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 8375305456876489425U;
            aOrbiterH = RotL64((aOrbiterH * 8331406038795786099U), 39U);
            //
            aIngress = RotL64(aOrbiterF, 11U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + (RotL64(aOrbiterC, 6U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + (RotL64(aOrbiterD, 39U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aPrevious, 54U) + RotL64(aOrbiterB, 27U)) + aOrbiterD);
            aWandererF = aWandererF ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterG, 46U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 39U) + RotL64(aOrbiterJ, 23U)) + aOrbiterE);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 41U) + aOrbiterE) + RotL64(aOrbiterH, 13U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 29U)) + aOrbiterD) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 3U)) + aOrbiterG);
            aWandererB = aWandererB + (((RotL64(aScatter, 5U) + aOrbiterD) + RotL64(aOrbiterK, 43U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterJ, 19U)) + aOrbiterI);
            aWandererA = aWandererA + ((RotL64(aIngress, 60U) + RotL64(aOrbiterI, 21U)) + aOrbiterK);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 21U) + aOrbiterC) + RotL64(aOrbiterE, 53U));
            aWandererD = aWandererD + (((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterF, 38U)) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 50U));
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 18U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aSnowLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 2
        // ingress from: aSnowLaneA, aOperationLaneC, aOperationLaneD, aInvestLaneD
        // ingress directions: aSnowLaneA forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aInvestLaneD forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aInvestLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aInvestLaneB backward/forward random
        // write to: aSnowLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 7135U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((aIndex + 5891U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 8674U)) & S_BLOCK1], 46U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 6923U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 10634U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 5862U)) & S_BLOCK1], 30U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 10353U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 50U) + RotL64(aPrevious, 23U)) + (RotL64(aCross, 35U) ^ RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = (aWandererH + RotL64(aPrevious, 3U)) + 13915875634607599122U;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 57U)) + 1695770381382411673U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aIngress, 35U)) + RotL64(aCarry, 21U)) + 3709105579778295511U;
            aOrbiterF = (aWandererA + RotL64(aCross, 51U)) + 7673376335333251804U;
            aOrbiterD = (aWandererE + RotL64(aIngress, 11U)) + 8814147709738503518U;
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 26U)) + RotL64(aCarry, 13U)) + 13451412605350381172U;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 13U)) + RotL64(aCarry, 37U)) + 6447870234069609538U;
            aOrbiterK = (aWandererG + RotL64(aCross, 5U)) + 13419487997946496825U;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 39U)) + 5478309847615220345U;
            aOrbiterC = (aWandererC + RotL64(aPrevious, 54U)) + 3635184969215610049U;
            aOrbiterI = ((aWandererD + RotL64(aCross, 23U)) + 12527903812035294828U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 1684685110885338814U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 12860354576326835090U;
            aOrbiterE = RotL64((aOrbiterE * 12743745087733307255U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 9081823570147481835U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 14369321778210049109U;
            aOrbiterD = RotL64((aOrbiterD * 17865953349448767035U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 11518132079084873250U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 11893535026126957389U;
            aOrbiterK = RotL64((aOrbiterK * 15751374986135615095U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 7084079180579206226U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 2999676609847603277U;
            aOrbiterF = RotL64((aOrbiterF * 14602698397511266403U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 17683445810614029153U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 11576460512964896969U;
            aOrbiterG = RotL64((aOrbiterG * 5243651036457051155U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 13429800604736567949U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 14661785761747367546U;
            aOrbiterH = RotL64((aOrbiterH * 4765843989277333421U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 12837164345582888950U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 6222666313184669392U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17402483466567712319U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 5358647039491079457U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 12459911673401497180U;
            aOrbiterC = RotL64((aOrbiterC * 13605465035256188065U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 3333017644772803587U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 15501587702102554928U;
            aOrbiterI = RotL64((aOrbiterI * 4921693371641768339U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 8492287653837766613U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 3432736785678875404U;
            aOrbiterB = RotL64((aOrbiterB * 7326419883291516513U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 2841486107704281869U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 13915875634607599122U;
            aOrbiterA = RotL64((aOrbiterA * 707861617246345083U), 11U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 57U);
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + RotL64(aOrbiterH, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aScatter, 46U) + RotL64(aOrbiterB, 35U)) + aOrbiterD);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 39U)) + aOrbiterI);
            aWandererG = aWandererG + (((RotL64(aCross, 19U) + RotL64(aOrbiterH, 47U)) + aOrbiterF) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterA, 37U));
            aWandererI = aWandererI + (((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterG, 20U)) + aPhaseFWandererUpdateSaltB[((aIndex + 28U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 54U) + RotL64(aOrbiterB, 13U)) + aOrbiterA);
            aWandererD = aWandererD + (((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterI, 5U)) + aPhaseFWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterK, 51U)) + aOrbiterC);
            aWandererK = aWandererK + (((RotL64(aPrevious, 37U) + aOrbiterK) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 51U) + aOrbiterI) + RotL64(aOrbiterH, 24U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 39U) + aOrbiterE) + RotL64(aOrbiterC, 27U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + (RotL64(aWandererD, 10U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + RotL64(aWandererI, 21U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aSnowLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 3
        // ingress from: aSnowLaneB, aOperationLaneA, aInvestLaneA
        // ingress directions: aSnowLaneB forward forced, aOperationLaneA forward forced, aInvestLaneA forward/backward random
        // cross from: aSnowLaneA, aOperationLaneC
        // cross directions: aSnowLaneA backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneB[((aIndex + 11010U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneA[((aIndex + 15014U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 15950U)) & S_BLOCK1], 54U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 12582U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 11295U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 6U) ^ RotL64(aCarry, 37U)) + (RotL64(aIngress, 57U) ^ RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = (aWandererB + RotL64(aPrevious, 35U)) + 14499676118633326000U;
            aOrbiterE = (aWandererG + RotL64(aScatter, 6U)) + 17191273593018552288U;
            aOrbiterC = (aWandererF + RotL64(aIngress, 37U)) + 4085176294948097737U;
            aOrbiterG = ((aWandererI + RotL64(aCross, 41U)) + RotL64(aCarry, 27U)) + 11112671474158908186U;
            aOrbiterF = ((aWandererH + RotL64(aIngress, 13U)) + RotL64(aCarry, 41U)) + 8745787969012266485U;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 21U)) + 18074049663777707948U) + aPhaseFOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aCross, 51U)) + 2543758649719164688U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aPrevious, 29U)) + 4659584749412700523U;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 27U)) + RotL64(aCarry, 37U)) + 974639159259871273U;
            aOrbiterK = (aWandererA + RotL64(aPrevious, 47U)) + 9211220687971081987U;
            aOrbiterH = (aWandererC + RotL64(aIngress, 58U)) + 8567024626862182714U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 5803002132294840900U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 11968489432878148467U;
            aOrbiterC = RotL64((aOrbiterC * 4501441062617123165U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 9470807228394903442U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 1692347973120388469U;
            aOrbiterF = RotL64((aOrbiterF * 17433393164156231575U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 16510815732690193145U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 755159406833096510U;
            aOrbiterI = RotL64((aOrbiterI * 14091736464659561165U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 1518824876475937620U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 701225390867330446U;
            aOrbiterG = RotL64((aOrbiterG * 12264618860580199927U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 8425976693733003889U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 7182176375442410367U;
            aOrbiterE = RotL64((aOrbiterE * 8860605703761731859U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 4546566785167467924U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 2593340999038753749U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10152461487764567563U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 9756331608356622299U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 5511625814747641978U;
            aOrbiterJ = RotL64((aOrbiterJ * 4806076157539829529U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 8694400787420160733U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 12648969491371382682U;
            aOrbiterD = RotL64((aOrbiterD * 5346585704222643759U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 15261238546696118531U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 14236129054778329471U;
            aOrbiterA = RotL64((aOrbiterA * 11789581469516267749U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 16251500056378064213U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 790320176607605195U;
            aOrbiterB = RotL64((aOrbiterB * 15706130623435648555U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 17114773669444878655U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 14499676118633326000U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8095707555083587081U), 41U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterE, 3U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + (RotL64(aOrbiterA, 23U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterD, 57U)) + aOrbiterK);
            aWandererB = aWandererB + (((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 6U)) + aOrbiterG) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterD, 41U)) + aOrbiterJ);
            aWandererE = aWandererE + (((RotL64(aIngress, 23U) + RotL64(aOrbiterF, 35U)) + aOrbiterH) + aPhaseFWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterI, 21U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 37U) + RotL64(aOrbiterI, 3U)) + aOrbiterF) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 29U) + aOrbiterA) + RotL64(aOrbiterD, 19U));
            aWandererF = aWandererF + ((RotL64(aScatter, 27U) + aOrbiterF) + RotL64(aOrbiterG, 11U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 5U) + aOrbiterB) + RotL64(aOrbiterF, 23U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 54U)) + aOrbiterI);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 48U) + RotL64(aOrbiterK, 37U)) + aOrbiterF) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 44U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + RotL64(aWandererJ, 30U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 4
        // ingress from: aWorkLaneA, aSnowLaneA, aExpandLaneB
        // ingress directions: aWorkLaneA forward forced, aSnowLaneA forward forced, aExpandLaneB forward/backward random
        // cross from: aSnowLaneB, aOperationLaneD
        // cross directions: aSnowLaneB backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 18409U)) & S_BLOCK1], 50U) ^ RotL64(aSnowLaneA[((aIndex + 21794U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 17062U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 21739U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 19104U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aPrevious, 60U)) + (RotL64(aIngress, 47U) ^ RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = (aWandererC + RotL64(aIngress, 60U)) + 6361545377408870615U;
            aOrbiterE = (((aWandererJ + RotL64(aScatter, 41U)) + RotL64(aCarry, 37U)) + 2967245486744774933U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 35U)) + 3836634268482850139U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aCross, 19U)) + RotL64(aCarry, 13U)) + 7691642115360086297U;
            aOrbiterD = (aWandererF + RotL64(aScatter, 37U)) + 16479280384178279281U;
            aOrbiterI = (aWandererB + RotL64(aIngress, 43U)) + 2901468732552539249U;
            aOrbiterA = (aWandererH + RotL64(aCross, 12U)) + 2600353867755647475U;
            aOrbiterK = (aWandererK + RotL64(aPrevious, 47U)) + 5666596904781510956U;
            aOrbiterG = (aWandererG + RotL64(aScatter, 23U)) + 16108791609267427553U;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 27U)) + 8389926875737312112U;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 5U)) + RotL64(aCarry, 19U)) + 1689501721163024426U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 11721701506949917719U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 3963842745030140473U;
            aOrbiterF = RotL64((aOrbiterF * 6692473494944919373U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 8510538243472109368U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 18281865214102080387U;
            aOrbiterI = RotL64((aOrbiterI * 1351546966368884609U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 2259725140963665123U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 11652011949557979650U;
            aOrbiterH = RotL64((aOrbiterH * 11260100762113295037U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 1116085424226174473U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 4725260319270802912U;
            aOrbiterD = RotL64((aOrbiterD * 4697109059565450269U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 7348945429843437036U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 1249234309180653260U;
            aOrbiterA = RotL64((aOrbiterA * 3136745255820405881U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 12463505532573389603U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 2304125977906510386U;
            aOrbiterG = RotL64((aOrbiterG * 9960816714791454421U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 2178037443783425551U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 11712110130079307683U;
            aOrbiterC = RotL64((aOrbiterC * 9797864956200779505U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 10703510612147312252U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 18155460326242413483U;
            aOrbiterE = RotL64((aOrbiterE * 6903953708987478723U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 5753486645345036069U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 2314216774606770444U;
            aOrbiterB = RotL64((aOrbiterB * 14002639533287566667U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 9662599462788305323U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 3805101172359199209U;
            aOrbiterK = RotL64((aOrbiterK * 10669315962181581543U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 1073926575064224947U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 6361545377408870615U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10685650563722188837U), 39U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterE, 60U);
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + (RotL64(aOrbiterK, 21U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 10U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterI, 46U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 47U) + aOrbiterI) + RotL64(aOrbiterG, 3U));
            aWandererE = aWandererE + ((RotL64(aScatter, 13U) + aOrbiterE) + RotL64(aOrbiterK, 51U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 42U) + RotL64(aOrbiterF, 43U)) + aOrbiterH);
            aWandererK = aWandererK + (((RotL64(aCross, 23U) + aOrbiterF) + RotL64(aOrbiterD, 40U)) + aPhaseFWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterH, 53U)) + aPhaseFWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 3U) + aOrbiterA) + RotL64(aOrbiterG, 19U)) + RotL64(aCarry, 13U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 27U) + aOrbiterH) + RotL64(aOrbiterC, 13U));
            aWandererD = aWandererD + (((RotL64(aCross, 34U) + RotL64(aOrbiterJ, 27U)) + aOrbiterB) + RotL64(aCarry, 43U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterH, 37U)) + aOrbiterK);
            aWandererC = aWandererC + ((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterC, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 34U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + RotL64(aWandererB, 5U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 5
        // ingress from: aWorkLaneB, aSnowLaneB, aExpandLaneA
        // ingress directions: aWorkLaneB forward forced, aSnowLaneB forward forced, aExpandLaneA forward/backward random
        // cross from: aWorkLaneA, aSnowLaneA
        // cross directions: aWorkLaneA backward forced, aSnowLaneA backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 27083U)) & S_BLOCK1], 10U) ^ RotL64(aSnowLaneB[((aIndex + 24406U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24916U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23412U)) & S_BLOCK1], 44U) ^ RotL64(aSnowLaneA[((aIndex + 25993U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aIngress, 23U)) + (RotL64(aCarry, 50U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = (aWandererC + RotL64(aIngress, 23U)) + 6069475454765660321U;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 37U)) + RotL64(aCarry, 57U)) + 11483704742497268068U;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 18U)) + RotL64(aCarry, 47U)) + 11055697447388986418U;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 57U)) + RotL64(aCarry, 29U)) + 10897095046039997004U;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 35U)) + 4731637118230457840U;
            aOrbiterI = ((aWandererG + RotL64(aScatter, 53U)) + 13855839187084986751U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = ((aWandererA + RotL64(aIngress, 47U)) + 5328208115460188239U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = (aWandererH + RotL64(aCross, 13U)) + 12479538544291412985U;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 28U)) + 10740165998792608231U;
            aOrbiterF = (aWandererB + RotL64(aScatter, 43U)) + 6492798157284955373U;
            aOrbiterA = (aWandererK + RotL64(aCross, 21U)) + 13056825957483891921U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 2068184064919194657U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 5656302738780746294U;
            aOrbiterK = RotL64((aOrbiterK * 16493021179127646345U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 11193756120230763294U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 17306750816837208999U;
            aOrbiterB = RotL64((aOrbiterB * 7949360041241439741U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 12952818800389361804U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 15380412293642628312U;
            aOrbiterH = RotL64((aOrbiterH * 2914662289178925547U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 7706090204767242996U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 14598802276412649570U;
            aOrbiterJ = RotL64((aOrbiterJ * 4821408736292041399U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 17819762117328075515U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 6481384240915075101U;
            aOrbiterI = RotL64((aOrbiterI * 4836701121865783029U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 754936290510338717U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 15510875946573720154U;
            aOrbiterA = RotL64((aOrbiterA * 2994718968852184303U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 9245381722813944586U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 2629847912019726214U;
            aOrbiterF = RotL64((aOrbiterF * 6718795794951106961U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 3909987749797113773U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 9277056074757335265U;
            aOrbiterG = RotL64((aOrbiterG * 11580847505996697115U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 12577180954515966707U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 9144513680789115458U;
            aOrbiterD = RotL64((aOrbiterD * 8880777678193004979U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 1544232962956974411U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 2658275904714859636U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1926083316365175327U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 5733515391293514025U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 6069475454765660321U;
            aOrbiterC = RotL64((aOrbiterC * 9627476106108146391U), 43U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 53U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 37U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 24U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterC, 53U)) + aOrbiterK);
            aWandererF = aWandererF + (((RotL64(aCross, 41U) + aOrbiterA) + RotL64(aOrbiterC, 19U)) + aPhaseFWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 19U) + aOrbiterH) + RotL64(aOrbiterK, 57U)) + aPhaseFWandererUpdateSaltB[((aIndex + 20U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 60U) + RotL64(aOrbiterF, 44U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterJ, 27U)) + aOrbiterI);
            aWandererD = aWandererD + (((RotL64(aScatter, 39U) + RotL64(aOrbiterE, 13U)) + aOrbiterJ) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 23U) + aOrbiterB) + RotL64(aOrbiterF, 21U));
            aWandererB = aWandererB + (((RotL64(aCross, 5U) + RotL64(aOrbiterD, 51U)) + aOrbiterI) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 34U) + RotL64(aOrbiterA, 47U)) + aOrbiterB);
            aWandererK = aWandererK + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterB, 10U)) + aOrbiterD);
            aWandererH = aWandererH ^ ((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterG, 35U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 30U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 41U);
            aCarry = aCarry + RotL64(aIngress, 50U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 6
        // ingress from: aWorkLaneC, aWorkLaneA, aExpandLaneD
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aExpandLaneD forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 29219U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((aIndex + 30792U)) & S_BLOCK1], 60U));
            aIngress ^= RotL64(aExpandLaneD[((aIndex + 28892U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28947U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28475U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 48U) + RotL64(aIngress, 35U)) + (RotL64(aCross, 3U) ^ RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = (aWandererF + RotL64(aCross, 43U)) + 4848316479321533394U;
            aOrbiterI = (aWandererB + RotL64(aIngress, 21U)) + 6919360256662636195U;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 14U)) + RotL64(aCarry, 37U)) + 9897013582181108544U;
            aOrbiterB = (aWandererJ + RotL64(aScatter, 39U)) + 7319353809896158678U;
            aOrbiterC = (((aWandererG + RotL64(aIngress, 11U)) + RotL64(aCarry, 47U)) + 2848175435514849859U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aCross, 57U)) + 6967780718720437934U;
            aOrbiterK = (aWandererD + RotL64(aScatter, 37U)) + 10143884766603388136U;
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 24U)) + 8675965006150972051U) + aPhaseFOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = (aWandererI + RotL64(aIngress, 19U)) + 16350117755560994281U;
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 3U)) + RotL64(aCarry, 11U)) + 17976597517118423760U;
            aOrbiterD = (aWandererA + RotL64(aCross, 5U)) + 1399631141355370237U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 3590613762034716792U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 5134624314245932157U;
            aOrbiterG = RotL64((aOrbiterG * 13077589037975283371U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 10082236952942943654U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 4015535035905433450U;
            aOrbiterC = RotL64((aOrbiterC * 4961808568701908559U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 611474103801573800U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 5786708483794098001U;
            aOrbiterK = RotL64((aOrbiterK * 7694007039340089267U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 5201943497363274455U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 9282160506938328489U;
            aOrbiterH = RotL64((aOrbiterH * 5368182164239021367U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 4932320527498940158U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 11576526341731392916U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1712051774729439363U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 10790691517638887125U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 16280649213607464422U;
            aOrbiterB = RotL64((aOrbiterB * 10756733801499471873U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 9553716940667712810U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 11827518270964003341U;
            aOrbiterJ = RotL64((aOrbiterJ * 1322489827908132831U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 16777463701235809321U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 3375489084588454149U;
            aOrbiterD = RotL64((aOrbiterD * 3335010977457647307U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 8129898095524287632U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 14496406641486541929U;
            aOrbiterI = RotL64((aOrbiterI * 10077246205532940301U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 17968163292907132345U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 2431407778543471402U;
            aOrbiterF = RotL64((aOrbiterF * 407105842057624537U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 18330313613898211889U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 4848316479321533394U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3462735144109152811U), 3U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 34U);
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aCross, 13U) + aOrbiterD) + RotL64(aOrbiterB, 60U)) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 52U) + RotL64(aOrbiterC, 41U)) + aOrbiterI) + aPhaseFWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterG, 21U)) + aOrbiterB);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 5U) + aOrbiterC) + RotL64(aOrbiterJ, 37U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 41U) + aOrbiterG) + RotL64(aOrbiterH, 11U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 3U) + aOrbiterF) + RotL64(aOrbiterD, 35U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterA, 46U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 38U) + aOrbiterD) + RotL64(aOrbiterC, 39U));
            aWandererH = aWandererH + (((RotL64(aScatter, 57U) + aOrbiterE) + RotL64(aOrbiterG, 51U)) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 43U)) + aOrbiterG);
            aWandererG = aWandererG + ((RotL64(aPrevious, 21U) + aOrbiterK) + RotL64(aOrbiterA, 53U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 6U));
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 24U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_FootBall_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 2331U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneB[((aIndex + 1222U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 2408U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 7854U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7496U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 2574U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aIngress, 39U)) + (RotL64(aPrevious, 54U) ^ RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = ((aWandererD + RotL64(aCross, 19U)) + RotL64(aCarry, 57U)) + 7632760812370906911U;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 51U)) + RotL64(aCarry, 21U)) + 6007174525479723089U;
            aOrbiterB = ((aWandererI + RotL64(aIngress, 27U)) + 3362829642521821048U) + aPhaseGOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 60U)) + RotL64(aCarry, 5U)) + 18009548556107978286U;
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 5U)) + 17880909432272697327U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 15961567935420752568U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 10136559064656837921U;
            aOrbiterB = RotL64((aOrbiterB * 14473810261421912849U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 17622019364405410277U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 6927494824421416306U;
            aOrbiterK = RotL64((aOrbiterK * 2686290883767829973U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 7125170407794874847U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 12342273503071032250U;
            aOrbiterE = RotL64((aOrbiterE * 867417849555857179U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 14997696377476124836U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 14874498694181230698U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4026127545746010937U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 2549397729130885686U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 4217995818662767955U;
            aOrbiterI = RotL64((aOrbiterI * 5525525344485251063U), 3U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterI, 3U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 56U));
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 3U)) + aOrbiterE) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterI, 37U)) + aOrbiterB);
            aWandererF = aWandererF + (((RotL64(aScatter, 30U) + aOrbiterC) + RotL64(aOrbiterB, 21U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterC, 52U)) + aOrbiterK) + aPhaseGWandererUpdateSaltD[((aIndex + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 51U) + RotL64(aOrbiterI, 11U)) + aOrbiterK) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 48U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 15375U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((aIndex + 12283U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 10894U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 10883U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 9797U)) & S_BLOCK1], 18U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 13835U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCarry, 39U)) ^ (RotL64(aPrevious, 22U) + RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = ((aWandererB + RotL64(aCross, 19U)) + 8367680518550579791U) + aPhaseGOrbiterAssignSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aScatter, 53U)) + RotL64(aCarry, 53U)) + 11491674725611181241U;
            aOrbiterD = (aWandererI + RotL64(aIngress, 44U)) + 16673861720782164214U;
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 35U)) + RotL64(aCarry, 27U)) + 9786610124108350855U;
            aOrbiterI = (((aWandererG + RotL64(aIngress, 5U)) + RotL64(aCarry, 3U)) + 5745080601557577637U) + aPhaseGOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 1959402215131684684U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 6121650036079196522U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13375345606276198671U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 12016309761037342392U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 5986936646177049603U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3585650475703294895U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 1000367700904043468U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 17425288243569101032U;
            aOrbiterG = RotL64((aOrbiterG * 2174614006719048535U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 4856917474950325209U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 16312111093223166419U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11046477664487805241U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 456110002032422270U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 11393724374787795662U;
            aOrbiterH = RotL64((aOrbiterH * 1176984359123668389U), 47U);
            //
            aIngress = RotL64(aOrbiterD, 29U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterG, 47U)) + aOrbiterI);
            aWandererG = aWandererG + ((((RotL64(aScatter, 57U) + aOrbiterG) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 35U)) + aPhaseGWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterH, 11U)) + aOrbiterD);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 36U) + RotL64(aOrbiterE, 58U)) + aOrbiterH) + RotL64(aCarry, 51U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 21U) + aOrbiterE) + RotL64(aOrbiterI, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 20849U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneA[((aIndex + 21726U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 20801U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 16646U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 19199U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 21814U)) & S_BLOCK1], 40U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 18U) ^ RotL64(aCross, 53U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = ((aWandererK + RotL64(aIngress, 35U)) + 77518479758428414U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = ((aWandererD + RotL64(aScatter, 43U)) + RotL64(aCarry, 35U)) + 4832061802166300011U;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 23U)) + 11695291171006574112U;
            aOrbiterA = (((aWandererG + RotL64(aCross, 10U)) + RotL64(aCarry, 3U)) + 7467412817843260094U) + aPhaseGOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 51U)) + RotL64(aCarry, 47U)) + 17801484124471154757U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 5555455638503958639U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 5669470540733721606U;
            aOrbiterG = RotL64((aOrbiterG * 17219613748084498879U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 3042388456327784163U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 2236734925228156691U;
            aOrbiterA = RotL64((aOrbiterA * 10076582424701705531U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 14459720401528685450U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 4814967631216658856U;
            aOrbiterB = RotL64((aOrbiterB * 18288097536171386643U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 16950679344449075945U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 6262238639302011050U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9942659897425088183U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 3522256359074996724U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 12524717897707074242U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6787771338063891989U), 3U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterE, 41U);
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterB, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 14U)) + aOrbiterD);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 37U) + aOrbiterG) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 13U)) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 4U) + RotL64(aOrbiterB, 47U)) + aOrbiterE);
            aWandererI = aWandererI + (((RotL64(aCross, 51U) + RotL64(aOrbiterA, 27U)) + aOrbiterB) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 21U) + aOrbiterD) + RotL64(aOrbiterE, 37U)) + aPhaseGWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + RotL64(aWandererG, 5U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28891U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((aIndex + 32552U)) & S_BLOCK1], 26U));
            aIngress ^= RotL64(aExpandLaneA[((aIndex + 30269U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31985U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30146U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 31981U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aIngress, 21U)) + (RotL64(aPrevious, 56U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 39U)) + 10915618884692072446U) + aPhaseGOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = (((aWandererD + RotL64(aCross, 3U)) + RotL64(aCarry, 43U)) + 12634922308499254909U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 12U)) + 6533934734564499389U;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 53U)) + RotL64(aCarry, 5U)) + 6744203303756105181U;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 21U)) + RotL64(aCarry, 29U)) + 13086782386652045658U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 5693840533331397822U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 1803663542535024611U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8511046986156781857U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 3597219300593287708U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 1429753448204448904U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10927459251773273143U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 17229017825587322715U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 1137574712801062932U;
            aOrbiterB = RotL64((aOrbiterB * 3645832160939819415U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 2401991077004083378U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 1332473247826139292U;
            aOrbiterF = RotL64((aOrbiterF * 15029831858261506447U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 11730946340796899885U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 15319163439700390962U;
            aOrbiterG = RotL64((aOrbiterG * 1349242001887975499U), 3U);
            //
            aIngress = RotL64(aOrbiterB, 57U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + RotL64(aOrbiterF, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 37U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aIngress, 12U) + RotL64(aOrbiterB, 28U)) + aOrbiterJ) + RotL64(aCarry, 41U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterG, 47U)) + aOrbiterC);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 23U) + aOrbiterF) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 13U)) + aPhaseGWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 51U) + aOrbiterF) + RotL64(aOrbiterG, 3U)) + aPhaseGWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 46U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererI, 23U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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

void TwistExpander_FootBall_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 7923U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneB[((aIndex + 6767U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2079U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7094U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2815U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 5340U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 19U) + RotL64(aCross, 52U)) ^ (RotL64(aCarry, 5U) + RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = (aWandererD + RotL64(aCross, 35U)) + 15383045568644941552U;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 51U)) + RotL64(aCarry, 47U)) + 17452811657750910067U;
            aOrbiterD = (((aWandererK + RotL64(aPrevious, 23U)) + RotL64(aCarry, 35U)) + 15660117718455155603U) + aPhaseHOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = (((aWandererI + RotL64(aScatter, 43U)) + RotL64(aCarry, 19U)) + 10396441207743665753U) + aPhaseHOrbiterAssignSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aIngress, 14U)) + 3708971058200841442U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 7000673057768598750U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 9886354469011131596U;
            aOrbiterD = RotL64((aOrbiterD * 296615166652808759U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 16018065329058043467U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 5024756166109352320U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11660932185479046483U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 6587818720728886652U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 3652672354944162319U;
            aOrbiterK = RotL64((aOrbiterK * 10807121230791716109U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 6307315649915348048U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 16405347331742979258U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7183142442906743699U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 5427299664054601957U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 4983381733483185898U;
            aOrbiterJ = RotL64((aOrbiterJ * 14646556236306407673U), 41U);
            //
            aIngress = RotL64(aOrbiterD, 37U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 29U)) + aOrbiterK);
            aWandererE = aWandererE + ((((RotL64(aScatter, 23U) + RotL64(aOrbiterE, 14U)) + aOrbiterC) + RotL64(aCarry, 53U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 38U) + aOrbiterC) + RotL64(aOrbiterK, 3U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 53U) + aOrbiterD) + RotL64(aOrbiterJ, 47U)) + RotL64(aCarry, 37U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 11U) + aOrbiterJ) + RotL64(aOrbiterK, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + RotL64(aWandererE, 19U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 10483U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((aIndex + 11155U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 10426U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15719U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11729U)) & S_BLOCK1], 30U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 15691U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 47U) + RotL64(aCarry, 35U)) ^ (RotL64(aIngress, 10U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 29U)) + RotL64(aCarry, 23U)) + 10812151398716051703U;
            aOrbiterG = ((aWandererB + RotL64(aCross, 20U)) + 18202551453336003710U) + aPhaseHOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = ((aWandererE + RotL64(aScatter, 37U)) + RotL64(aCarry, 39U)) + 9434410809101973752U;
            aOrbiterI = (((aWandererC + RotL64(aPrevious, 11U)) + RotL64(aCarry, 53U)) + 12955829998028534045U) + aPhaseHOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aIngress, 47U)) + 12271740641929640181U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 14009351527014534752U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 4316296955679133450U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11582128345511775161U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 16473324966997442872U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 15735123324965019802U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5624078184997601019U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 17656375090484080236U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 16066325053456055298U;
            aOrbiterK = RotL64((aOrbiterK * 17912970706985130327U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 12908968778503516903U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 12761433987676836197U;
            aOrbiterI = RotL64((aOrbiterI * 1023329467480907925U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 12737513138040664509U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 14535795767570998392U;
            aOrbiterG = RotL64((aOrbiterG * 15560519667062222269U), 35U);
            //
            aIngress = RotL64(aOrbiterI, 3U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterG, 44U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aScatter, 60U) + RotL64(aOrbiterG, 26U)) + aOrbiterF) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterD, 13U)) + RotL64(aCarry, 43U)) + aPhaseHWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 5U) + aOrbiterK) + RotL64(aOrbiterI, 39U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 39U) + aOrbiterF) + RotL64(aOrbiterK, 53U)) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 51U) + aOrbiterI) + RotL64(aOrbiterF, 5U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 52U));
            aCarry = aCarry + RotL64(aWandererC, 37U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 22040U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneA[((aIndex + 17869U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aExpandLaneD[((aIndex + 19049U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19666U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17269U)) & S_BLOCK1], 40U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 17788U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 19U) ^ RotL64(aPrevious, 56U)) + (RotL64(aCross, 41U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (((aWandererE + RotL64(aIngress, 11U)) + RotL64(aCarry, 23U)) + 6024062041314952357U) + aPhaseHOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aPrevious, 43U)) + 18340757093658015585U;
            aOrbiterI = (aWandererJ + RotL64(aCross, 60U)) + 11911120493880346751U;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 27U)) + RotL64(aCarry, 35U)) + 17428074353884654439U;
            aOrbiterA = (((aWandererC + RotL64(aPrevious, 51U)) + RotL64(aCarry, 51U)) + 12790849760814795936U) + aPhaseHOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 12633397052172117800U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 11946150433665237945U;
            aOrbiterI = RotL64((aOrbiterI * 10324089534873171291U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 16842157900909419285U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 14186235783224155962U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10521157787073684417U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 13284904542579767591U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 11609181965078844357U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5455780554452453513U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 9628562297095374984U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 7850281529011259759U;
            aOrbiterD = RotL64((aOrbiterD * 17611485102925470357U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 257458718073794527U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 10693404545773519306U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14821443722828498323U), 37U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 13U);
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterD, 35U)) + aOrbiterF) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 51U) + RotL64(aOrbiterB, 48U)) + aOrbiterD) + RotL64(aCarry, 41U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 10U) + aOrbiterF) + RotL64(aOrbiterA, 57U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 5U)) + aOrbiterF) + RotL64(aCarry, 23U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 29U) + aOrbiterI) + RotL64(aOrbiterB, 21U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + RotL64(aWandererE, 57U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 31944U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneB[((aIndex + 26474U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29690U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25920U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31505U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 29144U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCross, 11U)) + (RotL64(aCarry, 26U) ^ RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 21U)) + RotL64(aCarry, 39U)) + 3550722402315312207U;
            aOrbiterA = ((aWandererI + RotL64(aCross, 11U)) + 16724184551669522754U) + aPhaseHOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aIngress, 3U)) + RotL64(aCarry, 5U)) + 981751330116773021U;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 44U)) + 7891159229704944868U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aCross, 29U)) + RotL64(aCarry, 23U)) + 13618396711464799841U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 5969291018449003648U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 14595540413313640042U;
            aOrbiterH = RotL64((aOrbiterH * 8151104319012840963U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 3287990436916111762U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 12534369400200483704U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2345945228434740707U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 2277312067930392274U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 10026320559261334353U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11020464940995912637U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 11258082063135659551U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 1445958517675746990U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10062265337488757971U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 1011298251290970844U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 6487834862470043744U;
            aOrbiterB = RotL64((aOrbiterB * 15477913837027179675U), 21U);
            //
            aIngress = RotL64(aOrbiterF, 40U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aScatter, 21U) + RotL64(aOrbiterG, 37U)) + aOrbiterF) + RotL64(aCarry, 41U)) + aPhaseHWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 6U) + aOrbiterH) + RotL64(aOrbiterF, 13U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterA, 23U)) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterG, 5U)) + aOrbiterB) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterB, 52U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + RotL64(aWandererF, 37U);
            aCarry = aCarry + RotL64(aIngress, 56U);
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
