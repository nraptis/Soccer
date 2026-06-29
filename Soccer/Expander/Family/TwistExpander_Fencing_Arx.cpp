#include "TwistExpander_Fencing_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Fencing_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xC4D265E52A69F70DULL + 0x8D664887BC5568AEULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x91C01F58D0208331ULL + 0xADD0622D4E881D09ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC85ED20B92376561ULL + 0x9E7695CB9D174FA4ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xA46A09DF8A34EB1BULL + 0x8CD9E237702D2405ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xC257B538D4BF9755ULL + 0x94AD3CC00141B803ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xAB8C1C0F5E28AFE9ULL + 0xFBA603463D5D7AC3ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xB1890E97C0E1E9C9ULL + 0xFB84F07989431D51ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xCE4D6F5FDEEA6357ULL + 0xF8A4EE782237E7B8ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xA38ACB4D51E59647ULL + 0x88C714147113BAF1ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xE01A2BD25196EADBULL + 0xBC251ABBA999A46FULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xDB6EAF6B70BBFBEDULL + 0x8DE6B6EEA0D3B46FULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xE04AD8604BCB9D83ULL + 0xED9575FAFC071D65ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xD763126961A9EFF1ULL + 0x8F62E600B0240A16ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xB3826B4C7B813FDFULL + 0xCF33449C3122F885ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xB1B43DCFFA682169ULL + 0xFD3ECCB62FE7616DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x8C2FBB20E6675C67ULL + 0xFD574E25995D5F99ULL);
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
            aIngress = RotL64(mSource[((aIndex + 3770U)) & S_BLOCK1], 26U) ^ RotL64(pSnow[((aIndex + 2097U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 160U)) & S_BLOCK1], 29U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 2714U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 27U) ^ RotL64(aPrevious, 11U)) + (RotL64(aIngress, 41U) ^ RotL64(aCarry, 58U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterH = (aWandererA + RotL64(aIngress, 14U)) + 6163290588946759209U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 19U)) + 7342672468560105447U) + aOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 23U)) + RotL64(aCarry, 13U)) + 11574563167017282321U;
            aOrbiterE = ((aWandererK + RotL64(aCross, 53U)) + 2254820206194758964U) + aNonceWordG;
            aOrbiterG = (aWandererE + RotL64(aScatter, 47U)) + 1469783447473099498U;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 57U)) + 14174828900676165088U;
            aOrbiterB = ((aWandererC + RotL64(aCross, 29U)) + 16277954291890598132U) + aNonceWordB;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 51U)) + RotL64(aCarry, 43U)) + 14845750668693136766U;
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 41U)) + 150099699692047766U) + aOrbiterAssignSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 35U)) + RotL64(aCarry, 57U)) + 1200784917165131703U;
            aOrbiterA = (aWandererD + RotL64(aCross, 44U)) + 9469982764806754302U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 10956702761701710182U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 7915506894975487807U) ^ aOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8874108311712727983U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 17335794183733623213U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 557028996286989506U;
            aOrbiterC = RotL64((aOrbiterC * 3993359298602424281U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 1597385667771002414U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 4376417959915162639U;
            aOrbiterK = RotL64((aOrbiterK * 4626236858205178149U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 549770198518993876U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 756554555648070919U;
            aOrbiterI = RotL64((aOrbiterI * 16272320259614325355U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 7298557532533152193U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 3336802611342112013U;
            aOrbiterD = RotL64((aOrbiterD * 14679103452120080499U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 2314938232094714365U) + aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 12215066333571149153U;
            aOrbiterE = RotL64((aOrbiterE * 10747052773052630601U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 7762752719356805046U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 6519429915769040078U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15548676502167938513U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 7556691736109752918U) + aNonceWordN;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 13731245903412646404U;
            aOrbiterG = RotL64((aOrbiterG * 15581965016668635409U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 5910925625723735162U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 16037704866415841869U;
            aOrbiterF = RotL64((aOrbiterF * 11628217027073824759U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 12605882248192797360U) + aOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 9579778913978981884U;
            aOrbiterH = RotL64((aOrbiterH * 5372577227818787957U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 6063171520266734946U) + aNonceWordJ;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 6163290588946759209U;
            aOrbiterA = RotL64((aOrbiterA * 291843698316138251U), 43U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 23U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 40U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + RotL64(aOrbiterA, 54U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aIngress, 51U) + RotL64(aOrbiterH, 19U)) + aOrbiterG) + RotL64(aCarry, 57U)) + aNonceWordP);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterK, 35U)) + aOrbiterD);
            aWandererB = aWandererB + ((((RotL64(aCross, 43U) + RotL64(aOrbiterI, 11U)) + aOrbiterA) + RotL64(aCarry, 21U)) + aWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterB, 56U)) + aOrbiterG);
            aWandererK = aWandererK + (((RotL64(aPrevious, 27U) + aOrbiterE) + RotL64(aOrbiterK, 13U)) + aNonceWordK);
            aWandererG = aWandererG ^ ((((RotL64(aCross, 35U) + RotL64(aOrbiterJ, 21U)) + aOrbiterK) + aNonceWordM) + aWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 54U) + RotL64(aOrbiterJ, 5U)) + aOrbiterI);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 37U) + aOrbiterI) + RotL64(aOrbiterF, 51U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterC, 29U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterJ, 38U)) + aOrbiterG);
            aWandererH = aWandererH + ((RotL64(aIngress, 46U) + RotL64(aOrbiterF, 43U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 18U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 51U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 5810U)) & S_BLOCK1], 57U) ^ RotL64(pSnow[((aIndex + 9583U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 9727U)) & S_BLOCK1], 22U) ^ RotL64(mSource[((aIndex + 6276U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 29U) ^ RotL64(aPrevious, 6U)) + (RotL64(aCarry, 57U) ^ RotL64(aIngress, 43U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterC = ((aWandererJ + RotL64(aCross, 30U)) + 3561491146322798260U) + aNonceWordL;
            aOrbiterB = ((aWandererI + RotL64(aIngress, 11U)) + RotL64(aCarry, 3U)) + 7075025056181885339U;
            aOrbiterE = (((aWandererF + RotL64(aScatter, 47U)) + RotL64(aCarry, 47U)) + 9230910887904171613U) + aNonceWordH;
            aOrbiterI = (aWandererA + RotL64(aPrevious, 43U)) + 4119781172609908917U;
            aOrbiterH = ((aWandererG + RotL64(aCross, 57U)) + 17155609083870983149U) + aOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = ((aWandererE + RotL64(aScatter, 22U)) + 2423018561430181695U) + aOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 53U)) + 12957280305617615744U;
            aOrbiterG = (aWandererD + RotL64(aIngress, 5U)) + 2461704174772065813U;
            aOrbiterF = (((aWandererH + RotL64(aPrevious, 13U)) + RotL64(aCarry, 35U)) + 7907123257849391997U) + aNonceWordE;
            aOrbiterA = (aWandererC + RotL64(aIngress, 35U)) + 7257868138318960007U;
            aOrbiterD = (aWandererK + RotL64(aScatter, 41U)) + 16425903703085702285U;
            //
            aOrbiterC = (((aOrbiterC + aOrbiterB) + 2990822664594079467U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordP;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 5654819006718953817U;
            aOrbiterE = RotL64((aOrbiterE * 4465096036756887801U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 12183676471235678779U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 15026286960542123922U;
            aOrbiterK = RotL64((aOrbiterK * 17199049329995315279U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 12169080607071830522U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 2906296852254787499U;
            aOrbiterH = RotL64((aOrbiterH * 6754514406846040163U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 3029858695410344584U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 14406410317495954566U;
            aOrbiterF = RotL64((aOrbiterF * 9663780721657983421U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 11048818178401163861U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 13622063920319445043U) ^ aOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2516025554421589857U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 2642646089141233277U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 12761571777929273548U) ^ aOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5518252696078700127U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 7753802695131502382U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 8510425459525030222U;
            aOrbiterG = RotL64((aOrbiterG * 12412361423636026483U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 13522645164493316722U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 1437430302489702713U;
            aOrbiterB = RotL64((aOrbiterB * 14019316635365783545U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 14745189473423751499U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 16968328257002103715U;
            aOrbiterD = RotL64((aOrbiterD * 17915588590593471981U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 5001838243344386314U) + aNonceWordA;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 13506188720092630563U;
            aOrbiterC = RotL64((aOrbiterC * 7010027510838271877U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 16902624500530747723U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 3561491146322798260U) ^ aNonceWordD;
            aOrbiterI = RotL64((aOrbiterI * 95761172090277669U), 53U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterK, 5U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 37U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 14U));
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 35U) + RotL64(aOrbiterC, 14U)) + aOrbiterH) + RotL64(aCarry, 37U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterG, 3U)) + aOrbiterF);
            aWandererH = aWandererH + ((RotL64(aPrevious, 24U) + aOrbiterB) + RotL64(aOrbiterF, 51U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterI, 27U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 37U) + aOrbiterJ) + RotL64(aOrbiterK, 23U)) + aWandererUpdateSaltC[((aIndex + 24U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 19U)) + aOrbiterA) + aWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterF, 39U)) + aOrbiterA);
            aWandererB = aWandererB ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterJ, 37U)) + aOrbiterG);
            aWandererF = aWandererF + ((((RotL64(aScatter, 27U) + RotL64(aOrbiterK, 21U)) + aOrbiterF) + RotL64(aCarry, 5U)) + aNonceWordI);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 22U) + RotL64(aOrbiterD, 29U)) + aOrbiterB) + aNonceWordB);
            aWandererE = aWandererE + (((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterA, 48U)) + aNonceWordJ);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 46U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + RotL64(aWandererG, 35U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aFireLaneB[((aIndex + 11926U)) & S_BLOCK1], 35U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 13178U)) & S_BLOCK1], 24U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 12821U)) & S_BLOCK1], 13U) ^ RotL64(pSnow[((aIndex + 14796U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCarry, 37U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCross, 18U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterE = (aWandererC + RotL64(aPrevious, 35U)) + 18087125778766689269U;
            aOrbiterF = (aWandererG + RotL64(aIngress, 51U)) + 13710545066503235196U;
            aOrbiterH = ((aWandererE + RotL64(aCross, 47U)) + 1701939704736254645U) + aNonceWordF;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 12U)) + 8064093611384019909U) + aNonceWordK;
            aOrbiterG = (((aWandererD + RotL64(aIngress, 41U)) + RotL64(aCarry, 21U)) + 16623332751533885431U) + aOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aScatter, 37U)) + 15590129153794910109U) + aOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = ((aWandererH + RotL64(aCross, 43U)) + 7413312683079107383U) + aNonceWordB;
            aOrbiterK = (aWandererA + RotL64(aPrevious, 29U)) + 4186064478651458810U;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 21U)) + 5501191643940735954U) + aNonceWordA;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 4U)) + RotL64(aCarry, 51U)) + 11064645242200570835U;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 53U)) + RotL64(aCarry, 57U)) + 13825922087298055833U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 5944980709887369970U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 8181136916070569646U) ^ aNonceWordP;
            aOrbiterH = RotL64((aOrbiterH * 395183021205661827U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 15442336949157292482U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 11580554435240641337U;
            aOrbiterG = RotL64((aOrbiterG * 6654637892858767739U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 11240018128174598322U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 2027565596050777471U) ^ aNonceWordJ;
            aOrbiterD = RotL64((aOrbiterD * 18048186560314431815U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 16425887196883725233U) + aOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 16828683527588834095U;
            aOrbiterB = RotL64((aOrbiterB * 17746289103235902485U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 9923829146479008804U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 6669171007279929454U) ^ aNonceWordO;
            aOrbiterC = RotL64((aOrbiterC * 681823450939955099U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 3902430046523165149U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 6739998149289590041U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2675037435528416821U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 16014401255534234075U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 14741857638680634564U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8723611021403369393U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 5064807861673260054U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 968747317273200299U;
            aOrbiterK = RotL64((aOrbiterK * 14122304002722582329U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 5282686212362051427U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 6902253563196129760U;
            aOrbiterA = RotL64((aOrbiterA * 7682808024658992049U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 4995580401402368332U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 14949762584793646470U;
            aOrbiterE = RotL64((aOrbiterE * 3539183342072953803U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 2378815735788107402U) + aNonceWordL;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 18087125778766689269U;
            aOrbiterF = RotL64((aOrbiterF * 16799380528404446281U), 37U);
            //
            aIngress = RotL64(aOrbiterF, 5U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterJ, 39U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterD, 21U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 60U));
            aIngress = aIngress + RotL64(aOrbiterE, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterB, 41U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 58U) + RotL64(aOrbiterA, 21U)) + aOrbiterF);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 3U) + aOrbiterD) + RotL64(aOrbiterJ, 37U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterI, 53U)) + aOrbiterC);
            aWandererH = aWandererH ^ (((RotL64(aCross, 21U) + aOrbiterK) + RotL64(aOrbiterE, 12U)) + aNonceWordD);
            aWandererE = aWandererE + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterF, 47U)) + aOrbiterE);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterA, 57U));
            aWandererB = aWandererB + (((RotL64(aScatter, 23U) + RotL64(aOrbiterJ, 29U)) + aOrbiterG) + RotL64(aCarry, 23U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterF, 27U)) + aNonceWordI);
            aWandererC = aWandererC + ((((RotL64(aIngress, 60U) + RotL64(aOrbiterE, 34U)) + aOrbiterH) + RotL64(aCarry, 41U)) + aWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 51U) + aOrbiterI) + RotL64(aOrbiterB, 3U)) + aNonceWordG) + aWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 60U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 56U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 17637U)) & S_BLOCK1], 53U) ^ RotL64(pSnow[((aIndex + 21446U)) & S_BLOCK1], 40U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 16645U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(mSource[((S_BLOCK1 - aIndex + 20275U)) & S_BLOCK1], 26U) ^ RotL64(aFireLaneB[((aIndex + 18343U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCross, 51U)) ^ (RotL64(aCarry, 10U) ^ RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterF = ((aWandererH + RotL64(aCross, 13U)) + 5573188770530340913U) + aOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = (((aWandererG + RotL64(aPrevious, 54U)) + RotL64(aCarry, 29U)) + 1431772230889897111U) + aNonceWordG;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 3U)) + RotL64(aCarry, 5U)) + 4809192776429682319U;
            aOrbiterJ = (aWandererD + RotL64(aScatter, 41U)) + 5576603692574369341U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 47U)) + 2720143226007220386U) + aOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aScatter, 11U)) + 17220328778565331629U;
            aOrbiterE = (aWandererI + RotL64(aIngress, 19U)) + 9629485808442089423U;
            aOrbiterB = ((aWandererB + RotL64(aCross, 57U)) + 1136998437010390983U) + aNonceWordP;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 38U)) + 11893390497814523841U;
            aOrbiterA = ((aWandererE + RotL64(aCross, 43U)) + RotL64(aCarry, 41U)) + 1764986431917532370U;
            aOrbiterK = (aWandererK + RotL64(aScatter, 21U)) + 1741014798007010376U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 12221368453236547044U) + aNonceWordJ;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 7694538641172350430U;
            aOrbiterD = RotL64((aOrbiterD * 8439120733670016501U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 17472344518811560603U) + aNonceWordC;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 3308740700728172984U;
            aOrbiterI = RotL64((aOrbiterI * 15290400462887712083U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 9535358833412446771U) + aNonceWordD;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 11192312491731312451U;
            aOrbiterB = RotL64((aOrbiterB * 17405609148475445743U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 14850451970047190039U) + aOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 11932493299452443256U;
            aOrbiterG = RotL64((aOrbiterG * 7964808728820467795U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 5972619895614731870U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 17174497535809891690U;
            aOrbiterK = RotL64((aOrbiterK * 15471084511364572533U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 17412894714378898351U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 14675615208706549810U;
            aOrbiterJ = RotL64((aOrbiterJ * 7864845089606499769U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 16116792108013658523U) + aNonceWordE;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 9702262005960966336U;
            aOrbiterF = RotL64((aOrbiterF * 970452849653781703U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 17337264966818542841U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 7004462033775827275U;
            aOrbiterH = RotL64((aOrbiterH * 11943575980344402681U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 17499850384482055438U) + aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 1839357713256560566U) ^ aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12943750650487416281U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 8144238113917577524U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 888195876227325908U;
            aOrbiterA = RotL64((aOrbiterA * 7941506708630993709U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 5081763359501717653U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 5573188770530340913U;
            aOrbiterE = RotL64((aOrbiterE * 9699901099898698965U), 39U);
            //
            aIngress = RotL64(aOrbiterH, 42U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterI, 48U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 60U) + aOrbiterB) + RotL64(aOrbiterK, 51U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 47U)) + aOrbiterI);
            aWandererD = aWandererD ^ ((((RotL64(aCross, 39U) + aOrbiterC) + RotL64(aOrbiterH, 10U)) + aNonceWordB) + aWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 23U) + RotL64(aOrbiterC, 29U)) + aOrbiterB);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 43U)) + aOrbiterI) + aWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 41U) + RotL64(aOrbiterB, 21U)) + aOrbiterH) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 53U) + aOrbiterA) + RotL64(aOrbiterB, 13U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 43U) + aOrbiterG) + RotL64(aOrbiterF, 38U)) + RotL64(aCarry, 21U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 5U)) + aOrbiterE);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 35U) + aOrbiterA) + RotL64(aOrbiterJ, 19U)) + aNonceWordH);
            aWandererC = aWandererC ^ ((RotL64(aCross, 20U) + aOrbiterC) + RotL64(aOrbiterD, 57U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 14U));
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 30U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 25866U)) & S_BLOCK1], 13U) ^ RotL64(mSource[((aIndex + 26039U)) & S_BLOCK1], 34U));
            aIngress ^= (RotL64(pSnow[((aIndex + 25889U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 26106U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22030U)) & S_BLOCK1], 44U) ^ RotL64(aFireLaneB[((aIndex + 25879U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 54U) + RotL64(aPrevious, 29U)) ^ (RotL64(aIngress, 41U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterH = (((aWandererK + RotL64(aScatter, 4U)) + RotL64(aCarry, 11U)) + 3621877681473089725U) + aNonceWordM;
            aOrbiterC = (aWandererH + RotL64(aIngress, 53U)) + 4451752751536414717U;
            aOrbiterD = ((aWandererG + RotL64(aCross, 21U)) + RotL64(aCarry, 39U)) + 11371625415377772117U;
            aOrbiterG = (aWandererC + RotL64(aPrevious, 41U)) + 6046792758881150619U;
            aOrbiterF = (aWandererA + RotL64(aIngress, 56U)) + 8213166120394461682U;
            aOrbiterK = (aWandererD + RotL64(aScatter, 51U)) + 4343156661140422645U;
            aOrbiterE = ((aWandererE + RotL64(aCross, 23U)) + 11105271483234947905U) + aOrbiterAssignSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 35U)) + RotL64(aCarry, 19U)) + 348904609985341372U;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 19U)) + 12924652822526858767U) + aNonceWordJ;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 29U)) + 7461211697358520287U) + aNonceWordI;
            aOrbiterJ = (((aWandererF + RotL64(aCross, 37U)) + 16551553555297890558U) + aOrbiterAssignSaltC[((aIndex + 16U)) & S_SALT1]) + aNonceWordH;
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 11908056404140782995U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 9147367258259948715U;
            aOrbiterD = RotL64((aOrbiterD * 10777628928376261667U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 8876461054692728610U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 10546855952702525404U;
            aOrbiterF = RotL64((aOrbiterF * 10071104785895309677U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 4748636139110443794U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 783046909529525098U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8969157702460927215U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 16683965945838696665U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 12385412690177109575U) ^ aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10795062772707143187U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 8210546822184469023U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 13146493623236979963U;
            aOrbiterB = RotL64((aOrbiterB * 13199947810161148155U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 13857628148804187115U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 7241297989337473475U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16223448508809614229U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 773904571213804946U) + aNonceWordD;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 7660676598236419707U) ^ aNonceWordE;
            aOrbiterH = RotL64((aOrbiterH * 14467390638468925567U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 16822672435156055469U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 6514707119190640433U;
            aOrbiterC = RotL64((aOrbiterC * 7097496727567460535U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 17784153215885060832U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 16027189961519690419U) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 3248782394761733169U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 821916530432611671U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 8764650990196504963U;
            aOrbiterK = RotL64((aOrbiterK * 6269514974278082251U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 5987370764866753332U) + aNonceWordP;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 3621877681473089725U;
            aOrbiterI = RotL64((aOrbiterI * 14763908964222787377U), 21U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterI, 4U);
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterH, 37U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterG, 39U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterH, 23U)) + aNonceWordF);
            aWandererA = aWandererA + ((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 27U)) + aOrbiterI);
            aWandererE = aWandererE ^ ((((RotL64(aScatter, 23U) + aOrbiterH) + RotL64(aOrbiterG, 43U)) + aNonceWordC) + aWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 30U) + aOrbiterF) + RotL64(aOrbiterK, 5U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterD, 11U)) + aOrbiterA);
            aWandererB = aWandererB + ((((RotL64(aCross, 39U) + aOrbiterE) + RotL64(aOrbiterJ, 40U)) + RotL64(aCarry, 43U)) + aNonceWordG);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterB, 21U)) + aOrbiterG);
            aWandererG = aWandererG + ((RotL64(aIngress, 47U) + RotL64(aOrbiterC, 57U)) + aOrbiterE);
            aWandererH = aWandererH ^ ((RotL64(aCross, 27U) + aOrbiterD) + RotL64(aOrbiterI, 13U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 54U)) + aOrbiterK) + RotL64(aCarry, 57U)) + aWandererUpdateSaltF[((aIndex + 26U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 34U) + aOrbiterK) + RotL64(aOrbiterC, 47U)) + aNonceWordB);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 24U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + RotL64(aWandererH, 27U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28546U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((aIndex + 31095U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 28648U)) & S_BLOCK1], 30U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28856U)) & S_BLOCK1], 51U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 30280U)) & S_BLOCK1], 23U));
            aCross ^= (RotL64(pSnow[((S_BLOCK1 - aIndex + 30978U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneB[((aIndex + 31940U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aPrevious, 57U)) ^ (RotL64(aIngress, 40U) + RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterF = (aWandererK + RotL64(aScatter, 11U)) + 8375305456876489425U;
            aOrbiterG = (((aWandererH + RotL64(aPrevious, 27U)) + 16193562952772453047U) + aOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1]) + aNonceWordA;
            aOrbiterE = (aWandererD + RotL64(aCross, 50U)) + 18088652458594816223U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 5U)) + 767344788620249944U) + aNonceWordJ;
            aOrbiterH = (aWandererE + RotL64(aScatter, 29U)) + 7705194930396368752U;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 21U)) + RotL64(aCarry, 35U)) + 3829736891311272834U;
            aOrbiterA = (((aWandererB + RotL64(aIngress, 37U)) + RotL64(aCarry, 41U)) + 9881681671347640061U) + aOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = (aWandererA + RotL64(aCross, 47U)) + 1721196560190164264U;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 57U)) + 3002652618388454213U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 24U)) + 9811621464004005202U) + aNonceWordK;
            aOrbiterC = (((aWandererG + RotL64(aCross, 39U)) + RotL64(aCarry, 13U)) + 5652598941069986530U) + aNonceWordO;
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 6250499348327316328U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 16025054277615264530U;
            aOrbiterE = RotL64((aOrbiterE * 16446892258704281903U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 13800298546867243172U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 12256104592865905782U;
            aOrbiterD = RotL64((aOrbiterD * 16983140179497142713U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 17817225416918329229U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterA) ^ 17738671327352776217U) ^ aOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 393488251327705063U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 6816031224188400541U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 16989563985059237014U;
            aOrbiterA = RotL64((aOrbiterA * 8677884225771717797U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 16891524847268207549U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 1833508573940405571U;
            aOrbiterF = RotL64((aOrbiterF * 9709196587703979539U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 12729999421507068973U) + aNonceWordD;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 6839758643521968957U) ^ aOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16350557395881283975U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 8524167125469267428U) + aNonceWordF;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 14741523560290472617U;
            aOrbiterG = RotL64((aOrbiterG * 4367850822282205897U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 10983798459868424892U) + aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 5649250846622078964U;
            aOrbiterH = RotL64((aOrbiterH * 7149612714806023987U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 8587302028325090061U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 17457129226030333666U;
            aOrbiterB = RotL64((aOrbiterB * 18107356450566915215U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 15600113588474915690U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 6595247491374683783U) ^ aNonceWordL;
            aOrbiterK = RotL64((aOrbiterK * 1432432381540098765U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 13246325856585534283U) + aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 8375305456876489425U;
            aOrbiterC = RotL64((aOrbiterC * 8331406038795786099U), 5U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 57U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 38U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + RotL64(aOrbiterG, 10U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterC, 42U)) + aOrbiterE) + aWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterH, 5U)) + aOrbiterG);
            aWandererD = aWandererD + ((RotL64(aIngress, 39U) + RotL64(aOrbiterJ, 29U)) + aOrbiterG);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 44U) + RotL64(aOrbiterJ, 19U)) + aOrbiterA) + aNonceWordN);
            aWandererG = aWandererG + (((RotL64(aCross, 21U) + aOrbiterE) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 51U) + aOrbiterD) + RotL64(aOrbiterF, 21U)) + aNonceWordG);
            aWandererE = aWandererE + (((RotL64(aScatter, 27U) + aOrbiterK) + RotL64(aOrbiterA, 13U)) + aNonceWordB);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterI, 50U)) + aOrbiterJ);
            aWandererC = aWandererC + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterE, 11U)) + aOrbiterD);
            aWandererH = aWandererH ^ (((RotL64(aCross, 6U) + aOrbiterB) + RotL64(aOrbiterH, 37U)) + aNonceWordP);
            aWandererI = aWandererI + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 47U)) + aOrbiterK) + RotL64(aCarry, 5U)) + aWandererUpdateSaltD[((aIndex + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 44U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + RotL64(aWandererD, 42U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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

void TwistExpander_Fencing_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xC73960A5211DD2E5ULL + 0x82CB6D7413716610ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xF1E8E384D17934FDULL + 0xE93F59BB66F8B056ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x9DDD1412BD4976CDULL + 0xA4B033E6C2C05C61ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xD6931040A0827B99ULL + 0xF485A2713B9159E1ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xD37E2E97BF4D228FULL + 0xC86C9D4184604B71ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xD486EF19E7AC3541ULL + 0x8492A528ACF11B6DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xA1A3682F53184A13ULL + 0xA48E065213604353ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xE62A7F7799FF871BULL + 0x820B1C20EE0756D8ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x9851E01BED66187DULL + 0xD1CA63E2BCDED9A4ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xC69824F2BD9C8ED7ULL + 0x88BDC56ED60D8456ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x89123AC409CFCBE5ULL + 0xCDFFFF495296921FULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xF1D6CC1F5EAE3C33ULL + 0x8FD9585D994B5068ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xFE8445AA06FCB623ULL + 0xB89D5CBE11C561A3ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xB635382EDA473727ULL + 0xF6B01D01AE01163DULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xD70755C8C6E98FCBULL + 0xD236345AF86737A1ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x9F0A61653D26E593ULL + 0xDBB1E8D8F1A30C7AULL);
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
            aIngress = RotL64(aExpandLaneA[((aIndex + 2523U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneB[((aIndex + 4161U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4127U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 4043U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 40U) + RotL64(aCross, 11U)) ^ (RotL64(aIngress, 23U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterI = (aWandererE + RotL64(aPrevious, 40U)) + 3238389262925516513U;
            aOrbiterF = (aWandererC + RotL64(aIngress, 3U)) + 12381787182611386995U;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 27U)) + RotL64(aCarry, 5U)) + 7883885539305181549U;
            aOrbiterB = (((aWandererK + RotL64(aCross, 47U)) + RotL64(aCarry, 19U)) + 1185413044597727092U) + aOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 52U)) + 15219353497204773135U) + aNonceWordA;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 57U)) + 7533774715626734082U) + aOrbiterAssignSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = (aWandererD + RotL64(aCross, 35U)) + 2599930450937763464U;
            aOrbiterH = (((aWandererG + RotL64(aIngress, 19U)) + RotL64(aCarry, 57U)) + 16074720663961214284U) + aNonceWordC;
            aOrbiterA = (aWandererH + RotL64(aCross, 11U)) + 15483613196360051221U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 9396557867081376268U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 9668459976852660245U) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 11748505665890567063U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 9037269914643207212U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 16936742640861088240U;
            aOrbiterG = RotL64((aOrbiterG * 1040172193161012227U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 16481274825758546398U) + aOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 481851372837611166U;
            aOrbiterF = RotL64((aOrbiterF * 2225030139210599207U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 13608921517203544108U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 16930740723286214636U;
            aOrbiterA = RotL64((aOrbiterA * 2605108503821980865U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 902242902582149908U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 1510861213079342977U;
            aOrbiterB = RotL64((aOrbiterB * 3309753895727400707U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 7116243600304980310U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 6631412278359709602U;
            aOrbiterH = RotL64((aOrbiterH * 11452627691392637463U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 9246698682265275165U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 8594373032014031450U;
            aOrbiterE = RotL64((aOrbiterE * 2550138341089957033U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 15912837963877821048U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 11404583513022627609U;
            aOrbiterI = RotL64((aOrbiterI * 17715204726760125357U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 17295214920690244319U) + aNonceWordE;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 18315664494984189344U;
            aOrbiterJ = RotL64((aOrbiterJ * 17398893532076312945U), 5U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterH, 13U);
            aIngress = aIngress + (RotL64(aOrbiterB, 56U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 53U));
            aIngress = aIngress + RotL64(aOrbiterD, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterH, 56U)) + aNonceWordH) + aWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 28U) + aOrbiterF) + RotL64(aOrbiterB, 23U));
            aWandererC = aWandererC ^ ((((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterE, 29U)) + aNonceWordD) + aWandererUpdateSaltF[((aIndex + 16U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 51U) + aOrbiterA) + RotL64(aOrbiterI, 43U)) + aNonceWordP);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 21U) + aOrbiterE) + RotL64(aOrbiterH, 39U));
            aWandererE = aWandererE + ((((RotL64(aCross, 5U) + RotL64(aOrbiterH, 18U)) + aOrbiterJ) + RotL64(aCarry, 37U)) + aNonceWordM);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 35U) + aOrbiterG) + RotL64(aOrbiterB, 11U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterH, 47U)) + aOrbiterA) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 10U) + aOrbiterH) + RotL64(aOrbiterG, 51U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 14U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 6275U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneB[((aIndex + 7525U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5926U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 6852U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((aIndex + 6009U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aIngress, 58U)) + (RotL64(aCross, 23U) ^ RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 57U)) + 3973833383430652211U) + aNonceWordD;
            aOrbiterF = (aWandererJ + RotL64(aCross, 29U)) + 5760227042747169187U;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 34U)) + 4923009065139227286U) + aOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = ((aWandererD + RotL64(aIngress, 3U)) + 1477807307009107590U) + aOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 19U)) + 5707194514329007301U) + aNonceWordI;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 39U)) + RotL64(aCarry, 39U)) + 5340439728375269724U;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 10U)) + RotL64(aCarry, 47U)) + 17080457898946572387U;
            aOrbiterI = ((aWandererA + RotL64(aCross, 23U)) + RotL64(aCarry, 27U)) + 281559150259472813U;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 53U)) + 16160633048230910560U;
            //
            aOrbiterK = (((aOrbiterK + aOrbiterF) + 9003989610509592121U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordN;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 10579322462808454333U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 100832431598087235U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 15059383289528723069U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 10417647757852880956U;
            aOrbiterH = RotL64((aOrbiterH * 1457919230286043137U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 14484665027393813330U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 12344463053485837974U;
            aOrbiterD = RotL64((aOrbiterD * 5762654194001525041U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 5826453246659297805U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 12547902286376986223U;
            aOrbiterJ = RotL64((aOrbiterJ * 2982850000322672789U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 9637855144278126174U) + aOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 2132744427444501938U;
            aOrbiterK = RotL64((aOrbiterK * 5911587798564836199U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 9248933938130311231U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 13274297928717090383U;
            aOrbiterF = RotL64((aOrbiterF * 2901398809555237563U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 3690262236918560930U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 3626005326410800344U;
            aOrbiterI = RotL64((aOrbiterI * 13030443356669355355U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 10801089744186148218U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 5446653082176311031U) ^ aNonceWordH;
            aOrbiterA = RotL64((aOrbiterA * 4594267575901248321U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 3205541585889107366U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterJ) ^ 4532327942368884436U) ^ aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterE = RotL64((aOrbiterE * 16287094987689326229U), 13U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 47U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 28U));
            aIngress = aIngress + RotL64(aOrbiterI, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aIngress, 39U) + aOrbiterD) + RotL64(aOrbiterI, 54U)) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 53U) + RotL64(aOrbiterH, 11U)) + aOrbiterD) + aNonceWordP) + aWandererUpdateSaltC[((aIndex + 4U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 27U) + aOrbiterA) + RotL64(aOrbiterE, 5U)) + RotL64(aCarry, 21U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 39U)) + aOrbiterB);
            aWandererD = aWandererD + ((RotL64(aIngress, 60U) + RotL64(aOrbiterD, 23U)) + aOrbiterJ);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterF, 35U)) + aOrbiterD);
            aWandererE = aWandererE + (((RotL64(aCross, 21U) + RotL64(aOrbiterH, 29U)) + aOrbiterJ) + aNonceWordJ);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterF, 48U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 14U) + RotL64(aOrbiterB, 19U)) + aOrbiterE) + aNonceWordL) + aWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 14U));
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 43U);
            aCarry = aCarry + RotL64(aIngress, 6U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 13794U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((aIndex + 12139U)) & S_BLOCK1], 30U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 11852U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 14226U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneC[((aIndex + 14845U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCross, 3U)) + (RotL64(aCarry, 20U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterK = (aWandererE + RotL64(aPrevious, 5U)) + 4752759164691497960U;
            aOrbiterJ = (((aWandererG + RotL64(aCross, 14U)) + 12088872623537639782U) + aOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordB;
            aOrbiterH = (aWandererF + RotL64(aScatter, 37U)) + 3734943577379734227U;
            aOrbiterF = (aWandererH + RotL64(aIngress, 23U)) + 8854778183012444234U;
            aOrbiterD = (((aWandererI + RotL64(aCross, 51U)) + 16948373492893967275U) + aOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordP;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 41U)) + RotL64(aCarry, 23U)) + 7962415690046184385U;
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 18U)) + 1872682375669714454U) + aNonceWordN;
            aOrbiterA = (((aWandererJ + RotL64(aIngress, 29U)) + RotL64(aCarry, 51U)) + 7776801806943853566U) + aNonceWordL;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 47U)) + RotL64(aCarry, 43U)) + 16665439117257230732U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 11088186766134265676U) + aNonceWordC;
            aOrbiterH = (((aOrbiterH ^ aOrbiterK) ^ 10850237991780969350U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterH = RotL64((aOrbiterH * 7547414856143095121U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 6464817712131305812U) + aNonceWordA;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 244557182884209844U) ^ aOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2394270354887582889U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 13261563971157415841U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 2323811103717827362U;
            aOrbiterF = RotL64((aOrbiterF * 11483723582415081925U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 12338803568475493422U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 2811342930111104982U;
            aOrbiterD = RotL64((aOrbiterD * 5020981755203607757U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 5554497011738996057U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 12712169745460598698U;
            aOrbiterG = RotL64((aOrbiterG * 1985586486150377769U), 23U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterF) + 17415058661427002973U) + aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1]) + aNonceWordG;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 9430421222715343818U;
            aOrbiterK = RotL64((aOrbiterK * 10321140659099470811U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 3926618548181233180U) + aOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 6172453297026957838U;
            aOrbiterA = RotL64((aOrbiterA * 1161551082037835233U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 8633288765997226004U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 17270881130844274342U;
            aOrbiterE = RotL64((aOrbiterE * 8888559940161770791U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 12232950994807835262U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 15352600312956742750U;
            aOrbiterC = RotL64((aOrbiterC * 6140396356904933003U), 57U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 39U);
            aIngress = aIngress + (RotL64(aOrbiterE, 50U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterC, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 51U) + aOrbiterD) + RotL64(aOrbiterF, 10U)) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 18U) + aOrbiterG) + RotL64(aOrbiterH, 29U));
            aWandererH = aWandererH + (((RotL64(aCross, 27U) + RotL64(aOrbiterC, 5U)) + aOrbiterJ) + aWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 5U) + aOrbiterK) + RotL64(aOrbiterF, 39U)) + aNonceWordF);
            aWandererF = aWandererF + (((RotL64(aScatter, 43U) + aOrbiterJ) + RotL64(aOrbiterH, 56U)) + aWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterA, 43U)) + aOrbiterG) + aNonceWordH);
            aWandererG = aWandererG + (((RotL64(aIngress, 23U) + RotL64(aOrbiterK, 51U)) + aOrbiterA) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 39U) + aOrbiterG) + RotL64(aOrbiterK, 19U)) + aNonceWordJ);
            aWandererK = aWandererK + (((RotL64(aScatter, 14U) + RotL64(aOrbiterE, 35U)) + aOrbiterC) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererG, 41U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 26U));
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 18223U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((aIndex + 18504U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 19871U)) & S_BLOCK1], 6U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21258U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneD[((aIndex + 17041U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aIngress, 3U)) ^ (RotL64(aPrevious, 39U) ^ RotL64(aCross, 52U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterA = ((aWandererI + RotL64(aScatter, 18U)) + 439898681482066326U) + aNonceWordI;
            aOrbiterJ = (((aWandererH + RotL64(aPrevious, 23U)) + RotL64(aCarry, 3U)) + 17362083676671776094U) + aOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aIngress, 35U)) + 6418499837265155024U;
            aOrbiterG = ((aWandererF + RotL64(aCross, 5U)) + 17262244253027454972U) + aOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aPrevious, 39U)) + 2382066162993139503U;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 51U)) + RotL64(aCarry, 27U)) + 14345808395587174135U;
            aOrbiterK = ((aWandererE + RotL64(aCross, 57U)) + 7534743166385552851U) + aNonceWordL;
            aOrbiterF = ((aWandererC + RotL64(aIngress, 44U)) + RotL64(aCarry, 11U)) + 16994453324688523966U;
            aOrbiterI = (aWandererG + RotL64(aPrevious, 27U)) + 7079553728544045092U;
            //
            aOrbiterA = (((aOrbiterA + aOrbiterJ) + 3562822704508440641U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordF;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 13990892681975857821U;
            aOrbiterH = RotL64((aOrbiterH * 8352929306654078795U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 1796728922368577238U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 6605161260520067178U;
            aOrbiterJ = RotL64((aOrbiterJ * 8147537646591674091U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 13994083795942328918U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 6144523182899107711U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4153879991344611283U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 12247462325297436642U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 1065809332002012789U) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 5496601177032953251U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 10147919864511540753U) + aNonceWordD;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 17138553441127273354U;
            aOrbiterI = RotL64((aOrbiterI * 5773875596275267871U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 2653924016109573974U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 6254416952351699582U;
            aOrbiterE = RotL64((aOrbiterE * 12756861659704947257U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 813046408080197079U) + aNonceWordK;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 9624466135414123483U;
            aOrbiterA = RotL64((aOrbiterA * 6960320253124395015U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 972586705850825744U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 155283774901960223U;
            aOrbiterG = RotL64((aOrbiterG * 9928051687724257041U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 18200100644751360406U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 1168426822045686004U;
            aOrbiterB = RotL64((aOrbiterB * 5867027156069481313U), 53U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 27U);
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 60U));
            aIngress = aIngress + RotL64(aOrbiterJ, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterE, 23U)) + RotL64(aCarry, 35U));
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 10U) + aOrbiterK) + RotL64(aOrbiterI, 5U)) + aNonceWordH) + aWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 19U) + RotL64(aOrbiterB, 53U)) + aOrbiterE);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterJ, 18U)) + aOrbiterH) + aWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 39U) + aOrbiterE) + RotL64(aOrbiterI, 57U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterJ, 35U));
            aWandererC = aWandererC + (((RotL64(aScatter, 23U) + RotL64(aOrbiterF, 11U)) + aOrbiterJ) + aNonceWordP);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 39U)) + aOrbiterH);
            aWandererA = aWandererA + (((RotL64(aIngress, 52U) + aOrbiterF) + RotL64(aOrbiterH, 46U)) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 22U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererG, 11U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = RotL64(aOperationLaneB[((aIndex + 26018U)) & S_BLOCK1], 56U) ^ RotL64(aFireLaneD[((aIndex + 22372U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23330U)) & S_BLOCK1], 42U) ^ RotL64(aExpandLaneA[((aIndex + 24230U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 42U) ^ RotL64(aIngress, 21U)) + (RotL64(aPrevious, 5U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterD = ((aWandererG + RotL64(aIngress, 39U)) + 826930775230515406U) + aNonceWordI;
            aOrbiterJ = (aWandererD + RotL64(aScatter, 14U)) + 5137814617363250861U;
            aOrbiterA = ((aWandererI + RotL64(aCross, 29U)) + RotL64(aCarry, 41U)) + 14761561947426681616U;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 5U)) + 12773023438753662590U;
            aOrbiterF = (aWandererA + RotL64(aCross, 21U)) + 7331345852207096322U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 51U)) + 3899381212671247460U) + aOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aScatter, 10U)) + RotL64(aCarry, 13U)) + 10072004147620068599U;
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 57U)) + RotL64(aCarry, 57U)) + 3424585039401897560U;
            aOrbiterC = (((aWandererE + RotL64(aScatter, 35U)) + 8246760141625966321U) + aOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1]) + aNonceWordK;
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 3655992860610853290U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 11154618022505863898U) ^ aOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4791494171286145231U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 15629361991059709973U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 10842068502278489664U;
            aOrbiterE = RotL64((aOrbiterE * 17223002513104960799U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 5571312349016336686U) + aNonceWordA;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 589313823745748879U;
            aOrbiterF = RotL64((aOrbiterF * 1356685926549786027U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 13633457935771935260U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 12684602052812183096U;
            aOrbiterB = RotL64((aOrbiterB * 4689206269919806711U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 5711307583717354204U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 7181854170553728211U;
            aOrbiterG = RotL64((aOrbiterG * 9835601115561325911U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 1884620014396115821U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 1471516373272364262U;
            aOrbiterJ = RotL64((aOrbiterJ * 5126319375714848029U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 742739371092077733U) + aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 8075893317715227838U;
            aOrbiterC = RotL64((aOrbiterC * 11208274111743259795U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 8179547722249281263U) + aOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = (((aOrbiterD ^ aOrbiterF) ^ 15305282712174742323U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 7951986906055462929U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 1430543231751281079U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 14585341768267283387U;
            aOrbiterK = RotL64((aOrbiterK * 313213844964269133U), 35U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 47U);
            aIngress = aIngress + (RotL64(aOrbiterA, 34U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterC, 41U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 36U)) + aOrbiterJ) + aNonceWordD);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 56U) + RotL64(aOrbiterA, 43U)) + aOrbiterG);
            aWandererK = aWandererK + ((RotL64(aCross, 41U) + aOrbiterB) + RotL64(aOrbiterE, 47U));
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 51U) + aOrbiterC) + RotL64(aOrbiterK, 5U)) + aNonceWordJ) + aWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 37U) + aOrbiterJ) + RotL64(aOrbiterC, 29U)) + aNonceWordE);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 19U)) + aOrbiterF);
            aWandererD = aWandererD + (((RotL64(aPrevious, 24U) + aOrbiterF) + RotL64(aOrbiterG, 13U)) + RotL64(aCarry, 35U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterC, 24U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterC, 53U)) + RotL64(aCarry, 51U)) + aWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 26U));
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 36U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aOperationLaneC[((aIndex + 32590U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneA[((aIndex + 28183U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30531U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((aIndex + 31920U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCross, 57U)) + (RotL64(aCarry, 12U) ^ RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterH = ((((aWandererB + RotL64(aCross, 53U)) + RotL64(aCarry, 13U)) + 5721224134332887360U) + aOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordL;
            aOrbiterF = (aWandererC + RotL64(aPrevious, 21U)) + 6892749729775049095U;
            aOrbiterG = (aWandererF + RotL64(aIngress, 10U)) + 3884839462099556836U;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 47U)) + 4365431706830216193U) + aNonceWordO;
            aOrbiterD = (aWandererH + RotL64(aCross, 27U)) + 15501528746571578773U;
            aOrbiterC = (((aWandererD + RotL64(aScatter, 5U)) + RotL64(aCarry, 27U)) + 4505911326320650606U) + aNonceWordI;
            aOrbiterB = ((aWandererI + RotL64(aIngress, 34U)) + RotL64(aCarry, 51U)) + 1865129050927879580U;
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 57U)) + 2011737665969640369U) + aOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = (aWandererA + RotL64(aScatter, 39U)) + 611672935827062688U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 663547038310431047U) + aNonceWordF;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 5468932264754299556U) ^ aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11968657455484578525U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 17920294117231191705U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterJ) ^ 486058453837528110U) ^ aOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterD = RotL64((aOrbiterD * 8851102552244026737U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 2789178451938129313U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 420772587981211184U;
            aOrbiterB = RotL64((aOrbiterB * 17402987842294006667U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 16196774774442181825U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 16264169656793713547U;
            aOrbiterH = RotL64((aOrbiterH * 6900221986041638783U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 10207659833859860796U) + aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 8593749091183323678U;
            aOrbiterC = RotL64((aOrbiterC * 10696776033512404927U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 7224922076047787384U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 15366267474865172373U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10134187073321814217U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 4235342515820080294U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 5239480080426950612U;
            aOrbiterA = RotL64((aOrbiterA * 12077621553561927079U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 10891752830598395582U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 7797358829694471108U;
            aOrbiterK = RotL64((aOrbiterK * 7621206775460997431U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 3755715857903753416U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 3172069024987421726U) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 16048490837178650865U), 57U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterG, 50U);
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterF, 39U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterA, 23U)) + aOrbiterD);
            aWandererH = aWandererH + ((((RotL64(aCross, 58U) + RotL64(aOrbiterH, 3U)) + aOrbiterJ) + RotL64(aCarry, 23U)) + aNonceWordA);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterH, 34U)) + aOrbiterA) + aNonceWordN);
            aWandererD = aWandererD + (((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 47U)) + aOrbiterK) + aNonceWordC);
            aWandererI = aWandererI ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterF, 11U)) + aOrbiterG) + aWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterC, 19U)) + RotL64(aCarry, 57U)) + aWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 27U) + aOrbiterB) + RotL64(aOrbiterH, 30U));
            aWandererB = aWandererB + ((RotL64(aScatter, 44U) + RotL64(aOrbiterF, 53U)) + aOrbiterH);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 53U) + aOrbiterA) + RotL64(aOrbiterB, 41U)) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 10U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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

void TwistExpander_Fencing_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x94CE3D75E46611E3ULL + 0xE859EE7B35AF2EE6ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xBBD68E497A511067ULL + 0xAC60977E0AB2384FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xC9B5DAD5FE6E5EB1ULL + 0x88187EB89C017266ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x9CFAD6BB44EF04D9ULL + 0xC702D0CE7520FDFFULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xDE56B76142E84F3DULL + 0xE07FCA792A6EB2B5ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xE4B116668DF2DDA9ULL + 0xD9E724DE644F4D00ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xF1390CD7DD99E54BULL + 0xB2F9D2371826A7E9ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xA2B935FD8F104D09ULL + 0xB2060DCF481FDD82ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x9DE24687C9AF6845ULL + 0xD1D70FA13B07AB52ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xA0C50FBBF8E721C3ULL + 0xAA0DD8C842C6D32FULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xDFF1697B83B64F53ULL + 0x8DA70FDEF531DB96ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xD12C9AD362985B5DULL + 0xFF3458AFF570D698ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xABC19E595E8108BBULL + 0xBEB2E37E6FAC3181ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xF885063186FE29F5ULL + 0x80B90DA277871313ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xBC40FEA04A32BFD5ULL + 0xDBF8E53DBFBA735DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xC7814F805E1A67A1ULL + 0xCFC74D11A02A0205ULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 4859U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneB[((aIndex + 3371U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 2998U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 6551U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 1203U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 6330U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 19U)) + (RotL64(aIngress, 51U) + RotL64(aCarry, 36U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterG = (((aWandererI + RotL64(aCross, 39U)) + RotL64(aCarry, 3U)) + 12136097566601676613U) + aNonceWordF;
            aOrbiterE = (((aWandererC + RotL64(aIngress, 13U)) + RotL64(aCarry, 47U)) + 7969431322248040056U) + aNonceWordK;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 47U)) + 10530676021510553889U) + aOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aScatter, 57U)) + RotL64(aCarry, 27U)) + 8740777303075445264U;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 28U)) + 13249434169895564739U) + aOrbiterAssignSaltF[((aIndex + 4U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 15529577005925628472U) + aNonceWordN;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 344627093687331562U;
            aOrbiterD = RotL64((aOrbiterD * 3226087371456521323U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 8824277416519988893U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterI) ^ 5636276438449709875U) ^ aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterE = RotL64((aOrbiterE * 222817930773618893U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 2079413361031851552U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 7807998179168655561U;
            aOrbiterG = RotL64((aOrbiterG * 961456853699784753U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 13589392896232029112U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 10733011474804473996U) ^ aOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 361749145931578805U), 3U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterD) + 15934162328347805968U) + aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1]) + aNonceWordH;
            aOrbiterH = (((aOrbiterH ^ aOrbiterE) ^ 7573511217796245232U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterH = RotL64((aOrbiterH * 10694563909931636155U), 41U);
            //
            aIngress = RotL64(aOrbiterG, 41U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterD, 13U)) + aOrbiterE) + aWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aScatter, 4U) + RotL64(aOrbiterD, 37U)) + aOrbiterG) + RotL64(aCarry, 41U)) + aNonceWordL);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterI, 21U)) + aOrbiterD) + aNonceWordE);
            aWandererC = aWandererC + ((((RotL64(aCross, 43U) + RotL64(aOrbiterG, 48U)) + aOrbiterH) + RotL64(aCarry, 5U)) + aNonceWordO);
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterE, 5U)) + aOrbiterG) + aNonceWordA) + aWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 29U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 12137U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneC[((aIndex + 8307U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 13602U)) & S_BLOCK1], 56U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 14793U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 11948U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 13819U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 14297U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 53U)) + (RotL64(aCarry, 40U) ^ RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterC = (((aWandererH + RotL64(aScatter, 21U)) + RotL64(aCarry, 3U)) + 12380376990224645149U) + aNonceWordJ;
            aOrbiterG = (aWandererG + RotL64(aIngress, 37U)) + 18296928500297384014U;
            aOrbiterA = (((aWandererF + RotL64(aPrevious, 13U)) + 3550626816361145100U) + aOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1]) + aNonceWordG;
            aOrbiterF = (((aWandererJ + RotL64(aCross, 47U)) + RotL64(aCarry, 53U)) + 2667792936946706027U) + aOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 56U)) + RotL64(aCarry, 21U)) + 12020969779370926953U;
            //
            aOrbiterC = (((aOrbiterC + aOrbiterG) + 737340727886903447U) + aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1]) + aNonceWordH;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 1681797651799760502U;
            aOrbiterA = RotL64((aOrbiterA * 11923920414802777451U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 2956186342689489064U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 1876852870402977177U) ^ aNonceWordP;
            aOrbiterJ = RotL64((aOrbiterJ * 8875540081346621757U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 6433205819353555071U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 9065076854974222998U) ^ aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5459675878087242021U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 3254410578766789992U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterJ) ^ 2005081975473815576U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterF = RotL64((aOrbiterF * 9947701153722014085U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 15992999234834560419U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterF) ^ 3458344156815120948U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 1668460113964608051U), 39U);
            //
            aIngress = RotL64(aOrbiterF, 30U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((((RotL64(aScatter, 41U) + aOrbiterG) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 29U)) + aNonceWordC) + aWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 11U) + aOrbiterF) + RotL64(aOrbiterA, 24U)) + aNonceWordK);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 19U) + aOrbiterC) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 56U) + aOrbiterA) + RotL64(aOrbiterJ, 11U));
            aWandererF = aWandererF + (((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 53U)) + aOrbiterC) + aWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 10U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 22332U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((aIndex + 17192U)) & S_BLOCK1], 39U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 24260U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((aIndex + 23948U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21155U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 24200U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aExpandLaneB[((aIndex + 24316U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aPrevious, 35U)) ^ (RotL64(aCarry, 54U) ^ RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 39U)) + 9133751643283278896U) + aNonceWordM;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 60U)) + RotL64(aCarry, 41U)) + 8971581804375380408U;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 19U)) + RotL64(aCarry, 57U)) + 12559650383714566592U;
            aOrbiterI = (((aWandererG + RotL64(aCross, 27U)) + 15753206088872859163U) + aOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordK;
            aOrbiterF = (((aWandererE + RotL64(aPrevious, 51U)) + RotL64(aCarry, 13U)) + 7640756270450762350U) + aOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 7340073357551376125U) + aOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 5270256573644196046U) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 13286406906662922841U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 3567367996479995928U) + aNonceWordH;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 11939634537492733738U) ^ aNonceWordI;
            aOrbiterF = RotL64((aOrbiterF * 5640541900117183639U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 7051817732424527120U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 1730487669951837941U;
            aOrbiterB = RotL64((aOrbiterB * 15191634337956285841U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 18009252467909454817U) + aNonceWordL;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 2361024272031696442U) ^ aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15215151562500226027U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 15902755877642960397U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 12243517544704116184U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2576071074148141447U), 37U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterC, 47U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 4U));
            aIngress = aIngress + RotL64(aOrbiterF, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((((RotL64(aIngress, 28U) + aOrbiterC) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 3U)) + aNonceWordO) + aWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 53U) + aOrbiterB) + RotL64(aOrbiterD, 29U));
            aWandererE = aWandererE + (((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 43U)) + aOrbiterI) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 39U) + aOrbiterB) + RotL64(aOrbiterF, 51U)) + aWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 14U)) + aOrbiterB) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererG, 56U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 29475U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((aIndex + 26462U)) & S_BLOCK1], 27U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 29372U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((aIndex + 29451U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27512U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31916U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 31576U)) & S_BLOCK1], 46U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 19U)) + (RotL64(aPrevious, 6U) ^ RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterH = ((aWandererB + RotL64(aScatter, 26U)) + 17936518874386450467U) + aNonceWordI;
            aOrbiterG = (((aWandererJ + RotL64(aIngress, 5U)) + RotL64(aCarry, 35U)) + 13722737841589910344U) + aNonceWordL;
            aOrbiterI = ((((aWandererA + RotL64(aCross, 13U)) + RotL64(aCarry, 47U)) + 11774969167948715796U) + aOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordG;
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 57U)) + RotL64(aCarry, 21U)) + 3640101505680493777U;
            aOrbiterJ = (((aWandererE + RotL64(aIngress, 39U)) + 1369495382725650822U) + aOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1]) + aNonceWordE;
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 11827310354654653345U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 186037671377175394U;
            aOrbiterI = RotL64((aOrbiterI * 829791264853993897U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 11428829344234627340U) + aNonceWordC;
            aOrbiterK = (((aOrbiterK ^ aOrbiterG) ^ 2275016369870029068U) ^ aOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterK = RotL64((aOrbiterK * 14936799202145280833U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 15471646673734798328U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterI) ^ 12172082573115640145U) ^ aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 9629417882787847753U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 6626736341348283154U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 12220614992483863623U) ^ aOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8137086205714097487U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 13157102324253760215U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 4143587482368093601U;
            aOrbiterH = RotL64((aOrbiterH * 5060677690991506895U), 37U);
            //
            aIngress = RotL64(aOrbiterH, 46U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterH, 54U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 11U) + aOrbiterG) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterJ, 3U)) + aNonceWordP);
            aWandererE = aWandererE + (((((RotL64(aScatter, 44U) + aOrbiterI) + RotL64(aOrbiterK, 23U)) + RotL64(aCarry, 53U)) + aNonceWordJ) + aWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterG, 41U)) + aWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 27U);
            aCarry = aCarry + RotL64(aIngress, 36U);
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

void TwistExpander_Fencing_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x9C171DC84054F8F3ULL + 0x9E619C813AA77321ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xED0D0DB5CB97CA95ULL + 0x8CC96F5F067299F2ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xE48E1661703AB7EDULL + 0x88B583F396D27C4CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xDA46653DB07C79DDULL + 0xDE3A1BDB8854F68AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xBFB3A1E43AD3D1A1ULL + 0xCC1800C722A0F863ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x8C8EF2A554CA9589ULL + 0xADD5407417C18DDCULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xFA60FE8EA3FDC7FBULL + 0xA8DCCF31D8428F4FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xD050C730F58EF94DULL + 0xCD4344AD062DD560ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xFA63D3DA6451BAE3ULL + 0xFA636D31239F447CULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xE63F969F9923D7DDULL + 0xF998F97402CF4183ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x8AECCC978DEBE9D5ULL + 0xFB0F471E0CFB2914ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xE053532279CD4551ULL + 0xDEC979A52105F3CFULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xD27AFAF8EC619F7BULL + 0xC46609A0A13F5C85ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xC1AC7A97916B5FD7ULL + 0x825355F27FE83BE4ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xA1FE92B6E89570B7ULL + 0x97156CE43325140EULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xC1F415CA2BE07C45ULL + 0x940840C7CF9FC152ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3490U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneB[((aIndex + 1163U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 4349U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1892U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3836U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 4497U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aPrevious, 56U) + RotL64(aCarry, 13U)) + (RotL64(aCross, 41U) ^ RotL64(aIngress, 29U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterA = ((aWandererA + RotL64(aIngress, 13U)) + RotL64(aCarry, 57U)) + 15549114274303128055U;
            aOrbiterK = (((aWandererH + RotL64(aCross, 29U)) + 16466750056388063241U) + aOrbiterAssignSaltA[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordI;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 21U)) + 12209449840836787142U) + aNonceWordM;
            aOrbiterI = ((((aWandererC + RotL64(aPrevious, 6U)) + RotL64(aCarry, 39U)) + 14551496099734294336U) + aOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordH;
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 57U)) + 6266576428679808622U;
            aOrbiterB = ((aWandererG + RotL64(aCross, 51U)) + RotL64(aCarry, 27U)) + 16892841575635668152U;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 41U)) + 7375966221423362125U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 11926105302821753530U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 16219253791550461124U;
            aOrbiterE = RotL64((aOrbiterE * 2117550758226173419U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 7299056065319248160U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 15234001484933728439U) ^ aNonceWordO;
            aOrbiterK = RotL64((aOrbiterK * 8182244796017018911U), 57U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterI) + 6615802589932632120U) + aOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1]) + aNonceWordG;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 5481176858895819247U;
            aOrbiterA = RotL64((aOrbiterA * 3604590158551984877U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 17220507586542139380U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 14137921473739415340U;
            aOrbiterB = RotL64((aOrbiterB * 10634645686035907603U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 16981960446540932787U) + aNonceWordC;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 10897565927079518588U;
            aOrbiterI = RotL64((aOrbiterI * 418843936329303571U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 2746889569299593263U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 4894117146736361379U;
            aOrbiterG = RotL64((aOrbiterG * 2656750612042673191U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 18294823016957137777U) + aOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 86828501068883383U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11432686669235402365U), 11U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterJ, 3U);
            aIngress = aIngress + (RotL64(aOrbiterA, 26U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterG, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 43U)) + aWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 13U) + aOrbiterK) + RotL64(aOrbiterA, 51U)) + aNonceWordE);
            aWandererF = aWandererF + (((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterJ, 43U)) + aNonceWordB);
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 29U) + aOrbiterB) + RotL64(aOrbiterA, 3U)) + aNonceWordD) + aWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 40U) + RotL64(aOrbiterE, 29U)) + aOrbiterA) + aNonceWordL);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 60U)) + aOrbiterK);
            aWandererA = aWandererA + (((RotL64(aCross, 47U) + RotL64(aOrbiterJ, 23U)) + aOrbiterE) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 6U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 13983U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneC[((aIndex + 11998U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 13588U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 11303U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 10136U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 15916U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 13217U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCarry, 18U)) + (RotL64(aPrevious, 47U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterJ = (aWandererC + RotL64(aIngress, 27U)) + 3255291173184001106U;
            aOrbiterI = (((aWandererA + RotL64(aCross, 21U)) + RotL64(aCarry, 29U)) + 15308468160116255528U) + aNonceWordG;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 51U)) + 18186972408589866656U) + aOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (((aWandererJ + RotL64(aPrevious, 35U)) + RotL64(aCarry, 57U)) + 4439324265978331914U) + aNonceWordB;
            aOrbiterD = (((aWandererE + RotL64(aCross, 57U)) + 13099263173016322486U) + aOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordK;
            aOrbiterB = (aWandererI + RotL64(aScatter, 44U)) + 7041561081767500660U;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 5U)) + RotL64(aCarry, 41U)) + 6196422612687812971U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 7664260932541281413U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 17802347823020441056U;
            aOrbiterH = RotL64((aOrbiterH * 2220679459017369255U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 4253107484061190446U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 13799496534030645312U;
            aOrbiterD = RotL64((aOrbiterD * 9167675060053848207U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 14252892847595951926U) + aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 5663527578664291422U) ^ aOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 18314294235895182465U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 11148755959699137661U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 17036900929333594592U;
            aOrbiterB = RotL64((aOrbiterB * 16041243617369003291U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 2403828181385259549U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 17813580350434928194U) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 13666780980793857831U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 5623611126885414523U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterG) ^ 7293224381174846969U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterE = RotL64((aOrbiterE * 7032561584670788117U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 10602620906929686163U) + aNonceWordF;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 18015916257203385982U;
            aOrbiterI = RotL64((aOrbiterI * 10684090189688871993U), 47U);
            //
            aIngress = RotL64(aOrbiterH, 35U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterB, 14U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterJ, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 41U) + aOrbiterI) + RotL64(aOrbiterB, 51U));
            aWandererA = aWandererA + ((RotL64(aIngress, 51U) + aOrbiterB) + RotL64(aOrbiterD, 19U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterD, 6U)) + aOrbiterG);
            aWandererE = aWandererE + (((RotL64(aCross, 35U) + RotL64(aOrbiterH, 35U)) + aOrbiterJ) + RotL64(aCarry, 11U));
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 22U) + aOrbiterJ) + RotL64(aOrbiterG, 27U)) + aNonceWordP) + aWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 41U)) + aOrbiterH) + RotL64(aCarry, 51U)) + aWandererUpdateSaltC[((aIndex + 6U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterH, 57U)) + aOrbiterE) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 28U));
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 18455U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((aIndex + 18150U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aExpandLaneB[((aIndex + 22340U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((aIndex + 21098U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22527U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 23521U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 18637U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCross, 54U)) ^ (RotL64(aCarry, 21U) + RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 53U)) + RotL64(aCarry, 3U)) + 15652862298542575895U;
            aOrbiterE = ((aWandererC + RotL64(aScatter, 47U)) + 16925323928418184554U) + aNonceWordC;
            aOrbiterH = ((((aWandererE + RotL64(aCross, 29U)) + RotL64(aCarry, 19U)) + 4413861484961668394U) + aOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordF;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 5U)) + 2215946422098155969U) + aNonceWordP;
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 40U)) + 14975185533513111110U) + aOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = (((aWandererA + RotL64(aIngress, 13U)) + RotL64(aCarry, 43U)) + 9711613814905834552U) + aNonceWordL;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 23U)) + 13154957291850149471U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 5058313016418534840U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 15011423472941211620U) ^ aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6125316151731105673U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 2030053257469580168U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 150530795186791193U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11106050063717096073U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 10878237472104183427U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 11724672539469573109U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16158741837357985395U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 9589700906445846956U) + aNonceWordD;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 1367381624958248949U;
            aOrbiterI = RotL64((aOrbiterI * 8459515089081211977U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 12003215666757518106U) + aNonceWordI;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 11232479330848006729U;
            aOrbiterC = RotL64((aOrbiterC * 10993290955464593033U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 13013910456628561621U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 6092509838924105265U;
            aOrbiterK = RotL64((aOrbiterK * 805601154718006061U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 11999225836250312801U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 14421271973875748413U;
            aOrbiterA = RotL64((aOrbiterA * 9529010940887430157U), 47U);
            //
            aIngress = RotL64(aOrbiterJ, 29U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + (RotL64(aOrbiterK, 53U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 19U) + aOrbiterA) + RotL64(aOrbiterC, 41U));
            aWandererK = aWandererK + (((RotL64(aScatter, 41U) + aOrbiterA) + RotL64(aOrbiterH, 54U)) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 21U)) + aOrbiterH);
            aWandererA = aWandererA + (((RotL64(aCross, 27U) + RotL64(aOrbiterJ, 35U)) + aOrbiterK) + aNonceWordG);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 48U) + RotL64(aOrbiterE, 13U)) + aOrbiterI) + aNonceWordK);
            aWandererE = aWandererE + ((((RotL64(aCross, 35U) + RotL64(aOrbiterE, 47U)) + aOrbiterC) + RotL64(aCarry, 11U)) + aWandererUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 11U) + aOrbiterA) + RotL64(aOrbiterI, 27U)) + aWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 30U));
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 26749U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((aIndex + 26122U)) & S_BLOCK1], 47U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 31645U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 26023U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32299U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32676U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 29533U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCross, 5U)) ^ (RotL64(aPrevious, 44U) ^ RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 29U)) + RotL64(aCarry, 11U)) + 439898681482066326U;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 5U)) + 17362083676671776094U) + aOrbiterAssignSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = ((aWandererC + RotL64(aIngress, 43U)) + 6418499837265155024U) + aNonceWordK;
            aOrbiterH = ((aWandererI + RotL64(aCross, 19U)) + 17262244253027454972U) + aNonceWordH;
            aOrbiterB = ((aWandererG + RotL64(aIngress, 50U)) + RotL64(aCarry, 47U)) + 2382066162993139503U;
            aOrbiterC = ((aWandererB + RotL64(aCross, 35U)) + 14345808395587174135U) + aNonceWordI;
            aOrbiterG = ((((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 23U)) + 7534743166385552851U) + aOrbiterAssignSaltF[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordC;
            //
            aOrbiterK = (((aOrbiterK + aOrbiterE) + 16994453324688523966U) + aOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1]) + aNonceWordB;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 7079553728544045092U;
            aOrbiterA = RotL64((aOrbiterA * 10104892188895367489U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 3562822704508440641U) + aOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 13990892681975857821U) ^ aNonceWordL;
            aOrbiterB = RotL64((aOrbiterB * 8352929306654078795U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 1796728922368577238U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 6605161260520067178U;
            aOrbiterE = RotL64((aOrbiterE * 8147537646591674091U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 13994083795942328918U) + aNonceWordE;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 6144523182899107711U) ^ aOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4153879991344611283U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 12247462325297436642U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 1065809332002012789U) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 5496601177032953251U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 10147919864511540753U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 17138553441127273354U;
            aOrbiterH = RotL64((aOrbiterH * 5773875596275267871U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 2653924016109573974U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 6254416952351699582U;
            aOrbiterG = RotL64((aOrbiterG * 12756861659704947257U), 5U);
            //
            aIngress = RotL64(aOrbiterK, 11U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 21U));
            aIngress = aIngress + RotL64(aOrbiterA, 50U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aIngress, 54U) + RotL64(aOrbiterE, 19U)) + aOrbiterA) + RotL64(aCarry, 5U)) + aNonceWordA);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterK, 37U)) + aOrbiterC) + aWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 13U) + RotL64(aOrbiterK, 27U)) + aOrbiterH);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 37U) + aOrbiterH) + RotL64(aOrbiterG, 57U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterG, 48U)) + aOrbiterK) + RotL64(aCarry, 41U)) + aNonceWordO);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 3U)) + aOrbiterB);
            aWandererC = aWandererC + (((RotL64(aCross, 27U) + aOrbiterB) + RotL64(aOrbiterG, 11U)) + aWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 60U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererA, 19U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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

void TwistExpander_Fencing_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x9E03CA118894C9AFULL + 0xE58E2305F4282379ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xCCFD45B7FA8F09E5ULL + 0x89F35E0C63ECC537ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xE360937962512D01ULL + 0xFA0C7A9824D94613ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xBC5D6482160C9C0FULL + 0xDD09DCED4B67EFFBULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xFC2E943F6C98C501ULL + 0xEEEBD3BD614D68D4ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xE548AE2B3A89E249ULL + 0xEDBCE9846A6C6265ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x98FA5AD21D96BF75ULL + 0xA6C7FDE613C78542ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF10DDACB3972BD53ULL + 0x800B462068305639ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xE2F3C629BBA063FBULL + 0xDC2DDBDBD6E9DE53ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xB0CD9DACAEB6594FULL + 0xE068AF864334F755ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xF8C065808E97E91DULL + 0xEFBB9B446ED1DBB8ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xA985BF312450ECE7ULL + 0x807E3A53E61B9FC4ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xC04872A89FE1AD1DULL + 0xBC0DCCC0F9855176ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x98E55CAB2C8C9317ULL + 0x878CAD51B725BB87ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xB9DD803AE53BE1AFULL + 0x9FC3D6C8F78C6A13ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xA4D77A421014963FULL + 0x9E3B9FEA1D8846FDULL);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 3651U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((aIndex + 3585U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 2438U)) & S_BLOCK1], 28U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 2166U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 3849U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCross, 24U) ^ RotL64(aIngress, 53U)) + (RotL64(aCarry, 11U) + RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterB = ((aWandererK + RotL64(aCross, 13U)) + 8866844335448071821U) + aNonceWordL;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 21U)) + 15159698739856430085U) + aNonceWordC;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 41U)) + RotL64(aCarry, 39U)) + 9582805772989594633U;
            aOrbiterF = ((((aWandererF + RotL64(aIngress, 27U)) + RotL64(aCarry, 3U)) + 1438538239931588373U) + aOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1]) + aNonceWordE;
            aOrbiterC = (aWandererA + RotL64(aPrevious, 58U)) + 10862044156620436139U;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 35U)) + 13682173320058164615U) + aOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = ((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 21U)) + 8351013291045977592U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 15777857431516633916U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 16178966745333885377U) ^ aOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7545129923202147703U), 13U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterC) + 9031889187993001617U) + aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1]) + aNonceWordI;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 6308472367425865347U;
            aOrbiterG = RotL64((aOrbiterG * 17118710301967158153U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 642109145903321046U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 9186268569255318035U;
            aOrbiterE = RotL64((aOrbiterE * 10714674348507516749U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 6091345356803675860U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 13218507921880873749U) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 15415157927185637717U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 4266652275234474616U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 4391422098164506195U;
            aOrbiterK = RotL64((aOrbiterK * 17634679403195085867U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 5160682323243635577U) + aNonceWordM;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 10351728852161347404U;
            aOrbiterB = RotL64((aOrbiterB * 11105410036471745951U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 3950932176454814023U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 9536466386833427441U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 18064984243491293435U), 43U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 3U);
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 60U));
            aIngress = aIngress + RotL64(aOrbiterC, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 58U)) + aOrbiterC) + RotL64(aCarry, 37U)) + aNonceWordK);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterG, 19U)) + aOrbiterK);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 43U) + RotL64(aOrbiterG, 51U)) + aOrbiterE) + RotL64(aCarry, 19U)) + aWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 37U) + aOrbiterD) + RotL64(aOrbiterK, 29U)) + aNonceWordG);
            aWandererF = aWandererF + ((((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterC, 37U)) + aNonceWordP) + aWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterE, 3U)) + aOrbiterC);
            aWandererE = aWandererE + ((RotL64(aScatter, 4U) + aOrbiterB) + RotL64(aOrbiterK, 13U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 46U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererE, 23U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aFireLaneA[((aIndex + 9333U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneC[((aIndex + 10840U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 7294U)) & S_BLOCK1], 30U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10241U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8809U)) & S_BLOCK1], 36U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 5993U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCross, 3U)) ^ (RotL64(aCarry, 21U) + RotL64(aIngress, 38U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterE = (((aWandererD + RotL64(aCross, 29U)) + RotL64(aCarry, 5U)) + 4970414922752555648U) + aNonceWordH;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 57U)) + RotL64(aCarry, 57U)) + 9462756592787669327U;
            aOrbiterF = (((aWandererH + RotL64(aPrevious, 37U)) + 3948790686662213095U) + aOrbiterAssignSaltD[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordL;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 11U)) + 14542857212241578311U) + aOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 23U)) + RotL64(aCarry, 23U)) + 3387479009827029547U;
            aOrbiterC = ((aWandererG + RotL64(aCross, 3U)) + 1411421370057797877U) + aNonceWordB;
            aOrbiterD = (aWandererI + RotL64(aScatter, 50U)) + 16894451466895681236U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 12727136462290223542U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 4625389198191960525U;
            aOrbiterF = RotL64((aOrbiterF * 5726474430977810191U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 3471881403786164913U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterH) ^ 6433115856048534831U) ^ aOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterE = RotL64((aOrbiterE * 9363233870194144053U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 9825592965466157982U) + aNonceWordO;
            aOrbiterD = (((aOrbiterD ^ aOrbiterC) ^ 1553125767261293088U) ^ aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterD = RotL64((aOrbiterD * 411535191177308781U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 9951616357109647617U) + aOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 11231080382787286889U;
            aOrbiterG = RotL64((aOrbiterG * 14024961994986659187U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 13419663264017317947U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 4835055642466215566U;
            aOrbiterC = RotL64((aOrbiterC * 17898065852351759171U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 14558747666410946768U) + aNonceWordA;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 13120938960926874504U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5681766019285559739U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 11910501376797343986U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 15074100100781785300U;
            aOrbiterB = RotL64((aOrbiterB * 228976960937473851U), 3U);
            //
            aIngress = RotL64(aOrbiterG, 13U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 21U));
            aIngress = aIngress + RotL64(aOrbiterB, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aIngress, 13U) + RotL64(aOrbiterC, 35U)) + aOrbiterG);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterG, 13U)) + aOrbiterE) + aWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterH, 41U)) + aOrbiterB) + RotL64(aCarry, 19U)) + aNonceWordM);
            aWandererK = aWandererK ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterF, 47U)) + aOrbiterC);
            aWandererA = aWandererA + ((((RotL64(aScatter, 37U) + aOrbiterB) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 51U)) + aNonceWordF);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 43U) + aOrbiterD) + RotL64(aOrbiterF, 57U)) + aWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 21U) + aOrbiterH) + RotL64(aOrbiterG, 4U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 60U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 39U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 14261U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneD[((aIndex + 11767U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 11872U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 14994U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneA[((aIndex + 13723U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aPrevious, 38U) ^ RotL64(aCross, 23U)) + (RotL64(aCarry, 11U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 41U)) + 6469584119078165548U) + aNonceWordO;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 53U)) + RotL64(aCarry, 37U)) + 14329756366517987910U;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 3U)) + 12890831797059772123U) + aOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = (((aWandererH + RotL64(aCross, 19U)) + RotL64(aCarry, 21U)) + 3164503807500018990U) + aNonceWordM;
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 11U)) + 177531431387646836U) + aNonceWordJ;
            aOrbiterB = (((aWandererA + RotL64(aScatter, 60U)) + RotL64(aCarry, 57U)) + 3167421392893561015U) + aOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 47U)) + 2813174781844753460U) + aNonceWordB;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 10953270419153249857U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 16911518309710356951U;
            aOrbiterC = RotL64((aOrbiterC * 13162785997686570445U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 6616750447844893150U) + aNonceWordD;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 10276741398025985982U;
            aOrbiterB = RotL64((aOrbiterB * 6824712685896987133U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 6206043608461213208U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 12021552904553405793U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10023362889960174909U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 15283586234744144846U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 5923238786775948571U) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 8200882393521882651U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 11044014510971660078U) + aOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 9351141024085076044U;
            aOrbiterI = RotL64((aOrbiterI * 13316079344614432317U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 17703395981862992420U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 10154548848376027087U;
            aOrbiterJ = RotL64((aOrbiterJ * 12324478347590509035U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 8836420852291617425U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 10193385413543886344U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 824935982418585449U), 27U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 41U);
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterE, 20U)) + aOrbiterJ);
            aWandererK = aWandererK + (((RotL64(aIngress, 38U) + aOrbiterF) + RotL64(aOrbiterI, 35U)) + aNonceWordG);
            aWandererC = aWandererC ^ ((((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterI, 57U)) + aNonceWordK) + aWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aScatter, 27U) + RotL64(aOrbiterE, 51U)) + aOrbiterB) + RotL64(aCarry, 23U)) + aWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterK, 13U));
            aWandererE = aWandererE + (((RotL64(aIngress, 21U) + RotL64(aOrbiterI, 29U)) + aOrbiterB) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterC, 5U)) + aNonceWordF);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 48U));
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererJ, 21U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 18129U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneC[((aIndex + 18217U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 18870U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 20107U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneD[((aIndex + 17243U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aPrevious, 41U)) + (RotL64(aIngress, 24U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterD = (((aWandererC + RotL64(aCross, 5U)) + RotL64(aCarry, 11U)) + 2915859148137000694U) + aNonceWordG;
            aOrbiterB = (((aWandererH + RotL64(aScatter, 12U)) + 210680583721444425U) + aOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1]) + aNonceWordF;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 29U)) + RotL64(aCarry, 47U)) + 6668118118775650387U;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 39U)) + RotL64(aCarry, 35U)) + 15794200818099010989U;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 47U)) + 6565076707062828369U;
            aOrbiterE = (((aWandererD + RotL64(aCross, 53U)) + 16323164497808856719U) + aOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordM;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 23U)) + 7965435318816716560U) + aNonceWordA;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 7390281030573369017U) + aOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 2269738866911824875U;
            aOrbiterI = RotL64((aOrbiterI * 1198697877998135567U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 9664014216039993873U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 18284857398028357633U;
            aOrbiterE = RotL64((aOrbiterE * 8402008251343393737U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 367667619795303009U) + aNonceWordO;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 7935945060956274197U) ^ aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5481786693511955209U), 19U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterD) + 16683666162337789540U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordD;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 10655658270998102390U;
            aOrbiterB = RotL64((aOrbiterB * 15231596813382239841U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 8307037916581540297U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 3247742749860703524U) ^ aOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15052136713218656641U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 10446792483683818139U) + aNonceWordN;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 16374602929344972364U;
            aOrbiterA = RotL64((aOrbiterA * 12599903932725787599U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 2411334498322777183U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 1093701164116833765U;
            aOrbiterF = RotL64((aOrbiterF * 13129220206835381729U), 3U);
            //
            aIngress = RotL64(aOrbiterE, 21U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterF, 60U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 53U));
            aIngress = aIngress + RotL64(aOrbiterJ, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterE, 29U)) + aOrbiterF);
            aWandererC = aWandererC ^ (((RotL64(aCross, 22U) + aOrbiterB) + RotL64(aOrbiterF, 12U)) + aWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterB, 37U)) + aOrbiterA) + RotL64(aCarry, 43U)) + aNonceWordJ);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterA, 23U)) + aWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 47U) + RotL64(aOrbiterJ, 47U)) + aOrbiterI) + aNonceWordB);
            aWandererF = aWandererF ^ ((RotL64(aCross, 57U) + aOrbiterI) + RotL64(aOrbiterD, 3U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 53U)) + aOrbiterF) + RotL64(aCarry, 5U)) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + RotL64(aWandererK, 42U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = RotL64(aExpandLaneB[((aIndex + 25963U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 22608U)) & S_BLOCK1], 18U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23107U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25586U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 29U) ^ RotL64(aIngress, 54U)) ^ (RotL64(aPrevious, 41U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterA = ((aWandererA + RotL64(aCross, 11U)) + 8020711767807230555U) + aNonceWordP;
            aOrbiterF = (((aWandererD + RotL64(aPrevious, 3U)) + RotL64(aCarry, 21U)) + 15368693777246341570U) + aOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (((aWandererJ + RotL64(aIngress, 60U)) + 5117523734225562401U) + aOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordF;
            aOrbiterC = ((aWandererI + RotL64(aScatter, 53U)) + RotL64(aCarry, 3U)) + 13155269151097507808U;
            aOrbiterI = (((aWandererK + RotL64(aCross, 23U)) + RotL64(aCarry, 39U)) + 9879303753623578272U) + aNonceWordH;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 37U)) + 1165799257173794826U) + aNonceWordM;
            aOrbiterE = (aWandererH + RotL64(aScatter, 43U)) + 930641942062732091U;
            //
            aOrbiterA = (((aOrbiterA + aOrbiterF) + 11330571332221123153U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordB;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 2862963158282518899U) ^ aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13782195862525974199U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 6019186399361476659U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 1924419843785161958U;
            aOrbiterI = RotL64((aOrbiterI * 9485557122500346869U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 12618629043591380461U) + aOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 9334176504266512405U;
            aOrbiterF = RotL64((aOrbiterF * 18239109235362925739U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 16829692481030013551U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 5604784396927022709U) ^ aNonceWordL;
            aOrbiterC = RotL64((aOrbiterC * 2833893610883508353U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 16124030106598549644U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 16571659812830230677U;
            aOrbiterG = RotL64((aOrbiterG * 4668250364992383549U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 15171089673591843703U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 2826755560293849328U) ^ aOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9397017963457655287U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 9976785768283589291U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 11845100564714691809U;
            aOrbiterE = RotL64((aOrbiterE * 4935139932585319251U), 27U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterG, 3U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 14U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 60U)) + aOrbiterJ) + aWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aIngress, 11U) + RotL64(aOrbiterF, 47U)) + aOrbiterG) + RotL64(aCarry, 41U)) + aNonceWordA);
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 43U) + aOrbiterI) + RotL64(aOrbiterJ, 3U)) + aNonceWordE) + aWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 51U) + RotL64(aOrbiterA, 41U)) + aOrbiterF) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterG, 11U));
            aWandererI = aWandererI + (((RotL64(aCross, 27U) + aOrbiterI) + RotL64(aOrbiterA, 53U)) + aNonceWordO);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 36U) + RotL64(aOrbiterJ, 35U)) + aOrbiterC) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererD, 46U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 29546U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31951U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28809U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((aIndex + 30909U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 27U)) + (RotL64(aIngress, 10U) ^ RotL64(aCross, 43U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterE = (((aWandererG + RotL64(aIngress, 13U)) + RotL64(aCarry, 21U)) + 10038936806177516123U) + aOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 37U)) + RotL64(aCarry, 37U)) + 1773168435195292638U;
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 51U)) + 10655711161526628072U) + aNonceWordI;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 60U)) + 14422295664639740437U) + aNonceWordM;
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 3U)) + 4125228715513159576U) + aOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aScatter, 27U)) + RotL64(aCarry, 53U)) + 3670449653158650845U;
            aOrbiterH = (aWandererH + RotL64(aIngress, 21U)) + 17553727567180813057U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 5111401772713882743U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterE) ^ 7688573124662314413U) ^ aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 10846442063022821393U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 9438375825507814395U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 14177477039902118886U) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 6467406626985022537U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 16329942595859623928U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 3990536794006836672U;
            aOrbiterE = RotL64((aOrbiterE * 579024714339065373U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 5072881436583180756U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 16789727877867289997U;
            aOrbiterG = RotL64((aOrbiterG * 8766246302636197905U), 53U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterJ) + 17313956922306689438U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordC;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 11530878396329822041U;
            aOrbiterD = RotL64((aOrbiterD * 11356860047841383129U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 3612616532321160196U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 4172189825359187763U;
            aOrbiterH = RotL64((aOrbiterH * 12938945495299393177U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 8677279703778052804U) + aNonceWordJ;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 1912172980909479362U;
            aOrbiterF = RotL64((aOrbiterF * 10053289257955474143U), 27U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterD, 35U);
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aIngress, 5U) + aOrbiterA) + RotL64(aOrbiterH, 60U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 12U) + aOrbiterJ) + RotL64(aOrbiterH, 27U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 35U)) + aOrbiterE) + aNonceWordB) + aWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterD, 11U)) + aOrbiterH);
            aWandererH = aWandererH + (((RotL64(aIngress, 47U) + RotL64(aOrbiterJ, 5U)) + aOrbiterE) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterG, 21U)) + aOrbiterF);
            aWandererC = aWandererC + (((((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterF, 43U)) + RotL64(aCarry, 5U)) + aNonceWordD) + aWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 56U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + RotL64(aWandererK, 19U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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

void TwistExpander_Fencing_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xF0860B6F864976D7ULL + 0xF022F7A254861BE0ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xE629EE582E0CADFBULL + 0xF32D731D3704139FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x8C5319C7D3826FFFULL + 0xE5E738B4DED9F3C1ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xAA3933B7A8932C93ULL + 0xF05CAC3E491E4FC9ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xD6CA8D5644D959EBULL + 0xDB21692D942E1ACBULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xA2E716EEE95C379BULL + 0xDAF0AADBE4B59C93ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xAB8F8AE84A42F241ULL + 0xB218625EB298DBB9ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x929C83AE308807D5ULL + 0x96591A6B3674592DULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x87F06A1156AEE1DFULL + 0xCF8E543114923EAFULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xC6AB65F5A59D05D1ULL + 0xFF0E091D3524393FULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xE6F7866895F15E69ULL + 0xCCC91D207F7A6638ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x995375CB31324AB9ULL + 0xC9543048D6F787AFULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xC0F7155EB739C251ULL + 0x8444680EA87C473EULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xB9CD54FD140D8425ULL + 0x97B10CF3263E44DAULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xA72E90E7E22C53A5ULL + 0xBB43122E71A4E841ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xA75814E5533B8741ULL + 0xCCC550D1D5189717ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 8171U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneB[((aIndex + 4057U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 5247U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1575U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 1327U)) & S_BLOCK1], 52U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 7594U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 29U) ^ RotL64(aPrevious, 11U)) + (RotL64(aIngress, 58U) + RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterF = (aWandererB + RotL64(aPrevious, 24U)) + 9107326720193244489U;
            aOrbiterH = (aWandererH + RotL64(aIngress, 21U)) + 10868585484401664145U;
            aOrbiterK = ((aWandererC + RotL64(aScatter, 3U)) + 13637736741437846622U) + aNonceWordD;
            aOrbiterJ = (aWandererA + RotL64(aCross, 47U)) + 6130725216183918844U;
            aOrbiterG = (((aWandererE + RotL64(aIngress, 13U)) + RotL64(aCarry, 27U)) + 2063834478521338187U) + aNonceWordE;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 51U)) + RotL64(aCarry, 5U)) + 8564870627911949158U;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 19U)) + RotL64(aCarry, 11U)) + 6524015751064086390U;
            aOrbiterA = ((aWandererK + RotL64(aCross, 34U)) + 9874937766875388236U) + aOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = (aWandererG + RotL64(aScatter, 39U)) + 14723718409522680894U;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 43U)) + 13767059954741528279U) + aOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aCross, 37U)) + 6387608251033722169U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 5391425980008431000U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 11524218415655093779U) ^ aNonceWordP;
            aOrbiterK = RotL64((aOrbiterK * 12508457981779189389U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 155510463350385905U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 10554591788433641311U;
            aOrbiterG = RotL64((aOrbiterG * 5412084824127934293U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 8662160162966241542U) + aNonceWordB;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 5092555636369853727U;
            aOrbiterE = RotL64((aOrbiterE * 433807340167635499U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 7163345798448796101U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 695089002178413267U) ^ aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17302689458565434475U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 5409173939213468972U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 15349690077393827541U;
            aOrbiterC = RotL64((aOrbiterC * 10984681254001609841U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 12376011890751302027U) + aOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 7809614158898158383U) ^ aOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13845113198736843629U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 13031938699536449576U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 3983178190194056516U;
            aOrbiterB = RotL64((aOrbiterB * 1341678482929213405U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 5567935037909671790U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 17137042627663349797U;
            aOrbiterD = RotL64((aOrbiterD * 13535586899620672373U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 8726085717433137208U) + aNonceWordF;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 13154097637429217548U) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 5523758597936082363U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 4030516340575723215U) + aOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 7121696965917254968U;
            aOrbiterH = RotL64((aOrbiterH * 13569584361980228493U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 12079991626282752674U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 9107326720193244489U;
            aOrbiterA = RotL64((aOrbiterA * 7225937408665051799U), 29U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 41U);
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + RotL64(aOrbiterG, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aScatter, 48U) + aOrbiterK) + RotL64(aOrbiterF, 27U)) + aNonceWordA);
            aWandererA = aWandererA + ((((RotL64(aIngress, 37U) + aOrbiterB) + RotL64(aOrbiterG, 34U)) + RotL64(aCarry, 13U)) + aNonceWordK);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterF, 39U)) + aOrbiterI);
            aWandererI = aWandererI + (((RotL64(aCross, 51U) + RotL64(aOrbiterD, 19U)) + aOrbiterK) + aWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 37U)) + aOrbiterE);
            aWandererB = aWandererB + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 47U)) + aOrbiterD);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterB, 51U)) + aOrbiterD) + aWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 57U) + RotL64(aOrbiterA, 11U)) + aOrbiterC) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterE, 29U));
            aWandererC = aWandererC + ((RotL64(aCross, 12U) + aOrbiterH) + RotL64(aOrbiterC, 24U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterF, 53U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 22U));
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 10U));
            aCarry = aCarry + RotL64(aWandererH, 13U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 8713U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((aIndex + 13486U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 9524U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneC[((aIndex + 12311U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 15729U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 13285U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 12280U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 14U) ^ RotL64(aCross, 27U)) + (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterB = (aWandererD + RotL64(aPrevious, 53U)) + 12222235191147985484U;
            aOrbiterA = (((aWandererA + RotL64(aCross, 27U)) + RotL64(aCarry, 3U)) + 16367317014523328414U) + aNonceWordC;
            aOrbiterK = ((aWandererI + RotL64(aIngress, 44U)) + RotL64(aCarry, 43U)) + 3511378091284703789U;
            aOrbiterH = (((aWandererG + RotL64(aScatter, 5U)) + RotL64(aCarry, 11U)) + 15247492830966725949U) + aOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = (aWandererF + RotL64(aCross, 51U)) + 7745995913390407897U;
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 19U)) + 6463593307540108810U) + aNonceWordL;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 21U)) + 1101669311005268630U;
            aOrbiterI = (aWandererB + RotL64(aScatter, 39U)) + 12988052764067518580U;
            aOrbiterD = (aWandererK + RotL64(aIngress, 41U)) + 17717179747434679772U;
            aOrbiterG = (((aWandererH + RotL64(aScatter, 36U)) + 11662190906682400416U) + aOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterF = (aWandererE + RotL64(aPrevious, 29U)) + 6563014073547628748U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 13099094932059419219U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 16342730862261868847U) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 10988124108686164829U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 16855346813127524624U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 6570063128502306944U;
            aOrbiterA = RotL64((aOrbiterA * 4571570049463124831U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 11328352033809240501U) + aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 11640986648833160901U;
            aOrbiterB = RotL64((aOrbiterB * 2895830492089678919U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 2675226158571501666U) + aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 17700531248266458165U;
            aOrbiterD = RotL64((aOrbiterD * 2231403813970188657U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 7729597396731910874U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 15172374484412053756U;
            aOrbiterG = RotL64((aOrbiterG * 149009041406406517U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 9178769489257842683U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 9020154972097834926U;
            aOrbiterE = RotL64((aOrbiterE * 8910504667566521429U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 1317403761217790562U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 17151528554929201571U) ^ aNonceWordH;
            aOrbiterI = RotL64((aOrbiterI * 3735945655450625203U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 11621882033959669977U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 10289504450815075623U) ^ aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13365982786836243195U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 16178772981106335703U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 16896130772325866910U;
            aOrbiterC = RotL64((aOrbiterC * 6993524735412868965U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 9573223644675562575U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 17552463713786507189U;
            aOrbiterH = RotL64((aOrbiterH * 16103431656424881779U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 4801852246698369631U) + aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 12222235191147985484U;
            aOrbiterJ = RotL64((aOrbiterJ * 2835204872125428065U), 47U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterI, 35U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 58U));
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterG, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aScatter, 53U) + aOrbiterJ) + RotL64(aOrbiterA, 44U)) + RotL64(aCarry, 29U)) + aWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 43U) + aOrbiterK) + RotL64(aOrbiterG, 3U)) + aNonceWordG);
            aWandererK = aWandererK + (((RotL64(aCross, 6U) + RotL64(aOrbiterB, 11U)) + aOrbiterJ) + aNonceWordN);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterI, 39U)) + aOrbiterK);
            aWandererF = aWandererF + ((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterH, 42U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 47U) + aOrbiterF) + RotL64(aOrbiterE, 29U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 20U) + aOrbiterA) + RotL64(aOrbiterB, 47U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 39U) + aOrbiterE) + RotL64(aOrbiterB, 5U));
            aWandererB = aWandererB + (((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterG, 37U)) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterC, 51U)) + aOrbiterK) + aWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 53U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 44U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererB, 46U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 24284U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((aIndex + 22502U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aExpandLaneB[((aIndex + 22199U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((aIndex + 17327U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19367U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 19596U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 22810U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 19U) ^ RotL64(aIngress, 54U)) + (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterG = (((aWandererH + RotL64(aScatter, 27U)) + RotL64(aCarry, 39U)) + 13174219512651137892U) + aOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = (((aWandererC + RotL64(aPrevious, 41U)) + 2715455762789269341U) + aOrbiterAssignSaltF[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordD;
            aOrbiterE = (aWandererE + RotL64(aIngress, 52U)) + 1338018183235594313U;
            aOrbiterD = (aWandererJ + RotL64(aCross, 39U)) + 16566866551729552930U;
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 29U)) + 6901845297307236726U) + aNonceWordF;
            aOrbiterC = (aWandererF + RotL64(aIngress, 21U)) + 2476078302049201718U;
            aOrbiterH = (aWandererB + RotL64(aScatter, 23U)) + 15531109473927052260U;
            aOrbiterJ = ((aWandererK + RotL64(aCross, 5U)) + RotL64(aCarry, 47U)) + 4087849380858572351U;
            aOrbiterF = (aWandererI + RotL64(aPrevious, 37U)) + 5167830630098599644U;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 19U)) + RotL64(aCarry, 13U)) + 7275995452428627217U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 48U)) + 14794340370010024117U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 8509217403041662849U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 2321522025240806996U;
            aOrbiterE = RotL64((aOrbiterE * 113568101672878697U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 5676672952755594051U) + aNonceWordK;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 2304681269233504384U;
            aOrbiterK = RotL64((aOrbiterK * 15731441084605554497U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 8383399721062437300U) + aOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 13181984036942227666U;
            aOrbiterJ = RotL64((aOrbiterJ * 1648761328771932069U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 13602604532551684210U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 12725687663616352843U) ^ aOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4684699861686199753U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 5831790822416009806U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 4535048543735457407U;
            aOrbiterC = RotL64((aOrbiterC * 12076777878870257053U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 10617608605149381858U) + aNonceWordE;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 5244225377862618630U) ^ aNonceWordG;
            aOrbiterD = RotL64((aOrbiterD * 15307177251167023999U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 18229989093139888456U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 9728120630096192811U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16052574428163231023U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 1312233443099767304U) + aNonceWordB;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 8043115602160128619U;
            aOrbiterA = RotL64((aOrbiterA * 9365756845731616963U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 4679339316686216023U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 211799535650113758U;
            aOrbiterG = RotL64((aOrbiterG * 1478368466990144107U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 13307123762743628190U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 7093673238704478497U) ^ aOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13273906568866802561U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 16396459072175632290U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 13174219512651137892U;
            aOrbiterB = RotL64((aOrbiterB * 7581008806810219369U), 19U);
            //
            aIngress = RotL64(aOrbiterH, 47U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 11U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 39U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 22U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aCross, 21U) + RotL64(aOrbiterB, 39U)) + aOrbiterG);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterE, 51U)) + aNonceWordN);
            aWandererE = aWandererE + (((RotL64(aIngress, 19U) + aOrbiterC) + RotL64(aOrbiterK, 13U)) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterC, 11U)) + aOrbiterH);
            aWandererD = aWandererD + (((RotL64(aIngress, 51U) + RotL64(aOrbiterD, 57U)) + aOrbiterA) + aNonceWordL);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 37U) + aOrbiterI) + RotL64(aOrbiterK, 44U));
            aWandererC = aWandererC + (((RotL64(aCross, 58U) + aOrbiterJ) + RotL64(aOrbiterF, 35U)) + aWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterJ, 21U)) + aOrbiterD) + aWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 41U)) + aOrbiterC);
            aWandererI = aWandererI ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterE, 37U)) + aOrbiterG);
            aWandererH = aWandererH + (((RotL64(aPrevious, 34U) + aOrbiterC) + RotL64(aOrbiterB, 6U)) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 48U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + (RotL64(aWandererK, 34U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 29426U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneA[((aIndex + 26108U)) & S_BLOCK1], 53U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 28875U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 30175U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28541U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26074U)) & S_BLOCK1], 46U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 24852U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 37U) ^ RotL64(aCross, 23U)) + (RotL64(aPrevious, 56U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterK = (((aWandererI + RotL64(aScatter, 11U)) + RotL64(aCarry, 41U)) + 479672811032092393U) + aNonceWordH;
            aOrbiterC = (aWandererK + RotL64(aCross, 57U)) + 18061121631394564425U;
            aOrbiterG = (aWandererG + RotL64(aPrevious, 39U)) + 14237400452740566065U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 19U)) + 6723123812257706134U) + aNonceWordJ;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 47U)) + RotL64(aCarry, 29U)) + 4247997188026499248U;
            aOrbiterA = ((aWandererF + RotL64(aCross, 6U)) + RotL64(aCarry, 57U)) + 1939107415066134869U;
            aOrbiterE = ((aWandererH + RotL64(aScatter, 43U)) + 3912640123546395979U) + aNonceWordK;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 35U)) + 8295478436553964298U) + aOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aScatter, 23U)) + 3218960600711526885U;
            aOrbiterB = ((aWandererB + RotL64(aCross, 28U)) + 5874096203353388890U) + aOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = ((aWandererA + RotL64(aIngress, 53U)) + 10294536533673023358U) + aNonceWordE;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 11268561953904130747U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 16693201256788898423U;
            aOrbiterG = RotL64((aOrbiterG * 16291987237693567209U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 7550969634681894654U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 9501647424602245869U) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 11265865222096866605U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 8881869255994319423U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 16770136406906800016U;
            aOrbiterF = RotL64((aOrbiterF * 1782039587385512923U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 16185384746435761363U) + aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 13841034186650721627U) ^ aNonceWordO;
            aOrbiterI = RotL64((aOrbiterI * 12000155593277035447U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 15229062695864608309U) + aNonceWordA;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 3576122704615303733U;
            aOrbiterJ = RotL64((aOrbiterJ * 2433987493885779279U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 13898167174453181224U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 12878032061609524049U;
            aOrbiterE = RotL64((aOrbiterE * 18104665741338251495U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 12719156051299028649U) + aNonceWordB;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 8640980843376950769U;
            aOrbiterC = RotL64((aOrbiterC * 10242616778390983333U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 12133332160916004365U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 8743563985229104484U;
            aOrbiterK = RotL64((aOrbiterK * 4575129690615054691U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 7362223873479167793U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 4230720394788635807U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3658720603716856293U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 5095842824285329272U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 7483469517256234638U;
            aOrbiterH = RotL64((aOrbiterH * 9782114499878763883U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 17426017004856399653U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 479672811032092393U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14921028515589317919U), 41U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 21U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + (RotL64(aOrbiterF, 36U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + RotL64(aOrbiterI, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 35U)) + aOrbiterD);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterC, 42U)) + aOrbiterE);
            aWandererH = aWandererH + (((RotL64(aCross, 5U) + RotL64(aOrbiterB, 13U)) + aOrbiterJ) + aWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 53U) + aOrbiterK) + RotL64(aOrbiterF, 23U));
            aWandererE = aWandererE + ((((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterI, 27U)) + RotL64(aCarry, 27U)) + aNonceWordG);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterG, 3U)) + aOrbiterI);
            aWandererC = aWandererC + (((RotL64(aScatter, 10U) + aOrbiterJ) + RotL64(aOrbiterE, 5U)) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterF, 57U)) + aNonceWordC);
            aWandererG = aWandererG + (((RotL64(aCross, 27U) + RotL64(aOrbiterA, 39U)) + aOrbiterH) + aWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterI, 18U));
            aWandererK = aWandererK + (((RotL64(aScatter, 18U) + RotL64(aOrbiterE, 21U)) + aOrbiterA) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 14U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 48U);
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

void TwistExpander_Fencing_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x9313A2CBA0F9771DULL + 0xB0B16C3F56158008ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xAFBDFCBAFF8F0FE7ULL + 0xC36FD2BC8E39C3D7ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xF4B9CAAF5FD7A99FULL + 0x923916C3DFDE63B2ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xBD0557696DCC551FULL + 0xBC80D70E87FF25F9ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x8AEDB6E84E2772C3ULL + 0x8EB91A177F52EA74ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x9BD473C86FD7C85DULL + 0xC9B2E4CC47FEC1B9ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xD73EBBBD73B3D5F5ULL + 0x80398AAC8DD53018ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x8163D05C9B35D8C5ULL + 0xCE6BF03CCBD61F93ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x97430BBBA69521C5ULL + 0xAB42957010E1C54AULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xDA0FC9A4F808943FULL + 0xC82769AABE804D39ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xD91B8D0168F01BB9ULL + 0xFB79CC88312F1CBEULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xF8E395AC6930E6DDULL + 0x806D2B2775D3845FULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xDFD9F945314E9171ULL + 0xB4D8A8BBA9C5A101ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xB3F0608FBABA72E1ULL + 0x95FAD695729CAD55ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x9EB24448B49C17BBULL + 0xF8AE6289BA24A6EAULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xC97F27BFC180AC3BULL + 0xBFC720EEA547C235ULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 1604U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((aIndex + 897U)) & S_BLOCK1], 6U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 389U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7498U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 460U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 3032U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCarry, 50U)) + (RotL64(aCross, 5U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterD = (aWandererA + RotL64(aPrevious, 53U)) + 6318740973868639425U;
            aOrbiterE = ((aWandererH + RotL64(aCross, 12U)) + RotL64(aCarry, 21U)) + 5487840061430920881U;
            aOrbiterI = (aWandererF + RotL64(aScatter, 57U)) + 10258706763248072672U;
            aOrbiterJ = (aWandererK + RotL64(aIngress, 35U)) + 18356875269730338208U;
            aOrbiterK = ((aWandererB + RotL64(aScatter, 19U)) + 12883160282903147010U) + aOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (((aWandererI + RotL64(aPrevious, 30U)) + RotL64(aCarry, 5U)) + 1010140474942697730U) + aNonceWordL;
            aOrbiterG = ((aWandererG + RotL64(aIngress, 39U)) + 17733939421700898293U) + aOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aCross, 5U)) + 13693055887924981201U) + aNonceWordE;
            aOrbiterH = (((aWandererE + RotL64(aScatter, 23U)) + RotL64(aCarry, 35U)) + 14574732452793385269U) + aNonceWordP;
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 10832873941223609012U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 8212600587135328040U) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 5334613996794796145U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 5312744319781971178U) + aNonceWordO;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 6173741211706546923U;
            aOrbiterF = RotL64((aOrbiterF * 12854414066390848249U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 3693249147883790810U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 18365859989736602556U;
            aOrbiterG = RotL64((aOrbiterG * 3348463719324104997U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 10645056678337549771U) + aNonceWordC;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 1175668356822251045U;
            aOrbiterK = RotL64((aOrbiterK * 6579675292775345579U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 13556844570541823717U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 4790355739411849736U;
            aOrbiterD = RotL64((aOrbiterD * 4083544011788850307U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 14905575502272644116U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 17047244574558476634U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2356386971503880047U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 10161614295718414869U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 13413914082651612468U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16224039093981079491U), 11U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterJ) + 6072693130156927774U) + aOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1]) + aNonceWordF;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 4333656233793103787U;
            aOrbiterE = RotL64((aOrbiterE * 9374745547133955709U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 17209776289202130250U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 11752001118070361543U;
            aOrbiterH = RotL64((aOrbiterH * 4416523594812872339U), 43U);
            //
            aIngress = RotL64(aOrbiterF, 57U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterH, 43U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterJ, 19U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 54U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aPrevious, 47U) + aOrbiterD) + RotL64(aOrbiterF, 37U)) + aNonceWordG) + aWandererUpdateSaltB[((aIndex + 8U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterF, 44U)) + aNonceWordN);
            aWandererK = aWandererK + (((RotL64(aCross, 26U) + aOrbiterI) + RotL64(aOrbiterF, 23U)) + RotL64(aCarry, 47U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterE, 51U)) + aOrbiterF);
            aWandererA = aWandererA + (((RotL64(aIngress, 35U) + RotL64(aOrbiterJ, 5U)) + aOrbiterK) + RotL64(aCarry, 35U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 53U) + aOrbiterG) + RotL64(aOrbiterK, 11U)) + aWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 19U) + aOrbiterI) + RotL64(aOrbiterC, 28U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 58U) + RotL64(aOrbiterG, 57U)) + aOrbiterH);
            aWandererB = aWandererB + (((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterF, 19U)) + aNonceWordH);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 6U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 9344U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((aIndex + 13820U)) & S_BLOCK1], 43U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 10946U)) & S_BLOCK1], 58U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 13776U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 8995U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 9584U)) & S_BLOCK1], 30U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 10635U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 5U)) + (RotL64(aIngress, 18U) ^ RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterB = (((aWandererE + RotL64(aCross, 6U)) + RotL64(aCarry, 23U)) + 898812731947995389U) + aNonceWordH;
            aOrbiterG = (((aWandererB + RotL64(aScatter, 23U)) + RotL64(aCarry, 47U)) + 8677347622525527167U) + aNonceWordC;
            aOrbiterE = (((aWandererK + RotL64(aPrevious, 39U)) + RotL64(aCarry, 13U)) + 770321564027567654U) + aOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aIngress, 11U)) + 11020474858081526395U;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 34U)) + 17289793580414993470U;
            aOrbiterH = (aWandererF + RotL64(aCross, 43U)) + 10111912559295118444U;
            aOrbiterD = (((aWandererC + RotL64(aIngress, 57U)) + 8083622125544542011U) + aOrbiterAssignSaltB[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordD;
            aOrbiterJ = (aWandererI + RotL64(aScatter, 19U)) + 7149858558922988240U;
            aOrbiterI = (aWandererA + RotL64(aIngress, 47U)) + 5919683821379905699U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 6860902846079238714U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 15083517836867542075U) ^ aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4686657139237578325U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 14852868368708376381U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 9860233289028878323U;
            aOrbiterC = RotL64((aOrbiterC * 13418143547952204667U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 772406119079116272U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 7971141501337627589U) ^ aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10168120622976358617U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 8478568022896691911U) + aNonceWordK;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 4027604850785607101U) ^ aNonceWordB;
            aOrbiterJ = RotL64((aOrbiterJ * 4826627523578901467U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 17199331557841535430U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 7515957656979776361U) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 5468950152869656599U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 17138249294921502391U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 16236812863923234668U;
            aOrbiterF = RotL64((aOrbiterF * 2925542836624164807U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 16941524155859123682U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 11240343728857342866U) ^ aNonceWordI;
            aOrbiterH = RotL64((aOrbiterH * 7281012444214294659U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 15163914964139858328U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 6673576554415729652U;
            aOrbiterI = RotL64((aOrbiterI * 1558880328574736975U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 5399050402101642989U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 11806006719060024615U;
            aOrbiterG = RotL64((aOrbiterG * 15782156615926092159U), 3U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterB, 37U);
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterC, 56U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aScatter, 47U) + aOrbiterC) + RotL64(aOrbiterH, 29U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 28U) + aOrbiterH) + RotL64(aOrbiterG, 52U)) + aNonceWordJ);
            aWandererC = aWandererC + (((RotL64(aCross, 3U) + aOrbiterF) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 37U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterD, 13U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 37U) + aOrbiterJ) + RotL64(aOrbiterE, 39U)) + aWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 52U) + aOrbiterB) + RotL64(aOrbiterC, 24U));
            aWandererB = aWandererB + (((RotL64(aIngress, 11U) + RotL64(aOrbiterC, 19U)) + aOrbiterG) + aNonceWordL);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 43U) + aOrbiterI) + RotL64(aOrbiterC, 5U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 21U) + aOrbiterE) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 11U)) + aWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 50U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + RotL64(aWandererB, 30U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 22389U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((aIndex + 22185U)) & S_BLOCK1], 56U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 20025U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21720U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20635U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 18486U)) & S_BLOCK1], 40U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20316U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aIngress, 21U)) ^ (RotL64(aPrevious, 54U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterE = ((aWandererF + RotL64(aCross, 58U)) + RotL64(aCarry, 23U)) + 1042610313571524121U;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 43U)) + 3505725321008825582U) + aNonceWordO;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 21U)) + RotL64(aCarry, 35U)) + 12584654563843782991U;
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 11U)) + 6645399144515770935U) + aOrbiterAssignSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aCross, 39U)) + 3608978423753715584U) + aNonceWordM;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 26U)) + 8089198857670370983U;
            aOrbiterK = ((((aWandererG + RotL64(aScatter, 35U)) + RotL64(aCarry, 51U)) + 15207251813516399879U) + aOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1]) + aNonceWordK;
            aOrbiterB = (aWandererA + RotL64(aIngress, 47U)) + 9579268660105824516U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 53U)) + 16055044469473802812U) + aNonceWordP;
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 583811872609805949U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 7027491967970873942U) ^ aOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12686754713465826139U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 18256061823189677508U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 12708429127816136937U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12593886633108075321U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 12169216645156306078U) + aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 12694325407567795065U) ^ aNonceWordF;
            aOrbiterJ = RotL64((aOrbiterJ * 3711789483877261899U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 16109994660203297503U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 4234704064165718913U;
            aOrbiterA = RotL64((aOrbiterA * 730085881474787681U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 14119541943554602878U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 8777769004811352951U;
            aOrbiterK = RotL64((aOrbiterK * 2556957257736134223U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 15642663488392549609U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 11594468530833278624U;
            aOrbiterE = RotL64((aOrbiterE * 6639306656361601143U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 7365350535791499871U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterB) ^ 5965170981970155956U) ^ aOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterI = RotL64((aOrbiterI * 1898702752753066851U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 9115232101451815522U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 9433983580038990072U;
            aOrbiterD = RotL64((aOrbiterD * 1951249217843992179U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 8810565477444156140U) + aNonceWordB;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 12081286530401844859U;
            aOrbiterB = RotL64((aOrbiterB * 1991383259486140229U), 23U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterK, 41U);
            aIngress = aIngress + (RotL64(aOrbiterB, 60U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 51U));
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterH, 53U)) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 30U)) + aOrbiterE) + aNonceWordC);
            aWandererD = aWandererD + (((RotL64(aPrevious, 30U) + RotL64(aOrbiterE, 39U)) + aOrbiterD) + aWandererUpdateSaltD[((aIndex + 6U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 57U) + aOrbiterA) + RotL64(aOrbiterE, 11U)) + aWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 53U) + aOrbiterI) + RotL64(aOrbiterC, 57U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterC, 35U)) + aOrbiterK);
            aWandererF = aWandererF + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterH, 3U)) + aOrbiterA) + aNonceWordI);
            aWandererH = aWandererH ^ (((RotL64(aCross, 21U) + aOrbiterK) + RotL64(aOrbiterA, 20U)) + aNonceWordH);
            aWandererK = aWandererK + (((RotL64(aScatter, 48U) + aOrbiterA) + RotL64(aOrbiterB, 47U)) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 60U));
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 31203U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((aIndex + 31297U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 27830U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneC[((aIndex + 27056U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29141U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30359U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 25215U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aIngress, 51U)) ^ (RotL64(aPrevious, 10U) + RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterG = (aWandererK + RotL64(aIngress, 23U)) + 12222235191147985484U;
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 42U)) + RotL64(aCarry, 5U)) + 16367317014523328414U;
            aOrbiterB = (aWandererA + RotL64(aCross, 5U)) + 3511378091284703789U;
            aOrbiterD = ((aWandererI + RotL64(aScatter, 27U)) + 15247492830966725949U) + aNonceWordM;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 53U)) + 7745995913390407897U) + aOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = (((aWandererC + RotL64(aIngress, 38U)) + 6463593307540108810U) + aOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1]) + aNonceWordI;
            aOrbiterI = ((aWandererE + RotL64(aCross, 47U)) + RotL64(aCarry, 29U)) + 1101669311005268630U;
            aOrbiterJ = (((aWandererH + RotL64(aScatter, 57U)) + RotL64(aCarry, 41U)) + 12988052764067518580U) + aNonceWordH;
            aOrbiterE = ((aWandererD + RotL64(aIngress, 19U)) + 17717179747434679772U) + aNonceWordA;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 11662190906682400416U) + aOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 6563014073547628748U;
            aOrbiterB = RotL64((aOrbiterB * 16967910471722117761U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 13099094932059419219U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 16342730862261868847U;
            aOrbiterG = RotL64((aOrbiterG * 10988124108686164829U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 16855346813127524624U) + aNonceWordJ;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 6570063128502306944U) ^ aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4571570049463124831U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 11328352033809240501U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 11640986648833160901U) ^ aNonceWordP;
            aOrbiterJ = RotL64((aOrbiterJ * 2895830492089678919U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 2675226158571501666U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 17700531248266458165U;
            aOrbiterD = RotL64((aOrbiterD * 2231403813970188657U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 7729597396731910874U) + aNonceWordB;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 15172374484412053756U;
            aOrbiterI = RotL64((aOrbiterI * 149009041406406517U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 9178769489257842683U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 9020154972097834926U;
            aOrbiterE = RotL64((aOrbiterE * 8910504667566521429U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 1317403761217790562U) + aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 17151528554929201571U;
            aOrbiterK = RotL64((aOrbiterK * 3735945655450625203U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 11621882033959669977U) + aNonceWordE;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 10289504450815075623U;
            aOrbiterH = RotL64((aOrbiterH * 13365982786836243195U), 37U);
            //
            aIngress = RotL64(aOrbiterK, 38U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 34U)) + aOrbiterD);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterK, 13U)) + aOrbiterH);
            aWandererF = aWandererF + ((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterE, 43U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterF, 47U)) + aNonceWordO);
            aWandererE = aWandererE + (((RotL64(aScatter, 42U) + aOrbiterJ) + RotL64(aOrbiterH, 5U)) + aWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 57U) + aOrbiterF) + RotL64(aOrbiterI, 51U));
            aWandererK = aWandererK + (((((RotL64(aPrevious, 23U) + aOrbiterF) + RotL64(aOrbiterD, 28U)) + RotL64(aCarry, 29U)) + aNonceWordN) + aWandererUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterB, 23U)) + aOrbiterD);
            aWandererI = aWandererI + ((((RotL64(aIngress, 6U) + RotL64(aOrbiterG, 39U)) + aOrbiterB) + RotL64(aCarry, 53U)) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 41U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererK, 18U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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

void TwistExpander_Fencing_Arx::KDF_B_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xC90E04B8E644F2C9ULL + 0xB595EB8A824B93DAULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xBA58A416C4BC6703ULL + 0xFD02A76BDAAEA086ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xA512FEA94023843FULL + 0xA4E3FD94A4DE40E6ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x898EBA2FEF97F0F5ULL + 0xF27B32176B200006ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xE9B681ABCA38F79DULL + 0xE4BC53BB6BF0645FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xCF2531EF12FA387FULL + 0xCB5123D406E639BCULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x9C3301460483EECFULL + 0xA3B497A74A2E36C5ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x964D4065688331C9ULL + 0xB91095EBDB4D511DULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xCD4980C4A8F3BE41ULL + 0xD97A7EF01EF3364BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xC0E7388AA917C175ULL + 0xA93E327FE78A15BAULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xEE5DF4EBFF43CC1FULL + 0xABD99ABF8CBE3269ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x8FA9D70FA58CD209ULL + 0x94FEF8C45B679373ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xA3A044F8DDCE1A2DULL + 0xF014BC06E6FE4614ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xFD5D9B2D7846EBAFULL + 0x9BBA627DFFB5B0F4ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x971968AC1C5AEACBULL + 0xD60E53E69A38CB3CULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x910E57DA215A30F5ULL + 0xA8FB894D9E74FFEFULL);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 4400U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((aIndex + 497U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 6251U)) & S_BLOCK1], 26U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7201U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 7176U)) & S_BLOCK1], 50U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 3941U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 12U) + RotL64(aPrevious, 51U)) ^ (RotL64(aIngress, 27U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterD = (((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 10915618884692072446U) + aNonceWordH;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 29U)) + 12634922308499254909U) + aNonceWordC;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 57U)) + 6533934734564499389U) + aOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 51U)) + RotL64(aCarry, 47U)) + 6744203303756105181U;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 37U)) + 13086782386652045658U) + aOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = (((aWandererA + RotL64(aIngress, 13U)) + RotL64(aCarry, 19U)) + 5693840533331397822U) + aNonceWordD;
            aOrbiterK = ((aWandererC + RotL64(aCross, 20U)) + 1803663542535024611U) + aNonceWordN;
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 3597219300593287708U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 1429753448204448904U) ^ aNonceWordP;
            aOrbiterG = RotL64((aOrbiterG * 10927459251773273143U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 17229017825587322715U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 1137574712801062932U;
            aOrbiterC = RotL64((aOrbiterC * 3645832160939819415U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 2401991077004083378U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 1332473247826139292U) ^ aNonceWordM;
            aOrbiterJ = RotL64((aOrbiterJ * 15029831858261506447U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 11730946340796899885U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 15319163439700390962U;
            aOrbiterA = RotL64((aOrbiterA * 1349242001887975499U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 4744141870145159917U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 6067132201862688684U) ^ aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6046100687757836027U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 14991509179286371800U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 4342608825699398682U;
            aOrbiterK = RotL64((aOrbiterK * 10240526103933275875U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 3727521409410742075U) + aNonceWordB;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 3302027219498304367U) ^ aOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12153634588200479559U), 5U);
            //
            aIngress = RotL64(aOrbiterC, 5U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 43U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 12U));
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aScatter, 37U) + aOrbiterC) + RotL64(aOrbiterG, 51U)) + aNonceWordI);
            aWandererG = aWandererG + (((RotL64(aIngress, 43U) + aOrbiterE) + RotL64(aOrbiterK, 37U)) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterD, 21U)) + aOrbiterC) + aNonceWordA) + aWandererUpdateSaltE[((aIndex + 22U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 11U) + aOrbiterA) + RotL64(aOrbiterK, 12U)) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterJ, 29U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 60U) + RotL64(aOrbiterE, 57U)) + aOrbiterA) + aWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterD, 5U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 22U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + RotL64(aWandererC, 53U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 14957U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneC[((aIndex + 12584U)) & S_BLOCK1], 43U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 14752U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneC[((aIndex + 15582U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11621U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 13868U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 11009U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 54U) ^ RotL64(aCross, 3U)) + (RotL64(aPrevious, 29U) ^ RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 47U)) + RotL64(aCarry, 5U)) + 13915875634607599122U;
            aOrbiterF = ((((aWandererH + RotL64(aCross, 35U)) + RotL64(aCarry, 37U)) + 1695770381382411673U) + aOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordC;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 19U)) + 3709105579778295511U) + aNonceWordI;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 27U)) + RotL64(aCarry, 21U)) + 7673376335333251804U;
            aOrbiterE = ((aWandererF + RotL64(aCross, 11U)) + 8814147709738503518U) + aNonceWordL;
            aOrbiterJ = (((aWandererG + RotL64(aPrevious, 58U)) + 13451412605350381172U) + aOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordB;
            aOrbiterI = (aWandererJ + RotL64(aIngress, 3U)) + 6447870234069609538U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 13419487997946496825U) + aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 5478309847615220345U) ^ aNonceWordH;
            aOrbiterD = RotL64((aOrbiterD * 12953043149543448765U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 3635184969215610049U) + aNonceWordD;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 12527903812035294828U;
            aOrbiterE = RotL64((aOrbiterE * 12540800512035534967U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 1684685110885338814U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 12860354576326835090U) ^ aOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12743745087733307255U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 9081823570147481835U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 14369321778210049109U) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 17865953349448767035U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 11518132079084873250U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 11893535026126957389U;
            aOrbiterI = RotL64((aOrbiterI * 15751374986135615095U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 7084079180579206226U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 2999676609847603277U;
            aOrbiterF = RotL64((aOrbiterF * 14602698397511266403U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 17683445810614029153U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 11576460512964896969U) ^ aNonceWordP;
            aOrbiterJ = RotL64((aOrbiterJ * 5243651036457051155U), 19U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 28U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterD, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterI, 27U)) + aOrbiterG);
            aWandererI = aWandererI ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterA, 57U)) + aOrbiterF);
            aWandererF = aWandererF + ((((RotL64(aIngress, 35U) + aOrbiterA) + RotL64(aOrbiterD, 34U)) + aNonceWordF) + aWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterJ, 47U)) + aOrbiterD) + aNonceWordN);
            aWandererE = aWandererE + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterF, 19U)) + aOrbiterJ) + RotL64(aCarry, 37U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 12U) + aOrbiterG) + RotL64(aOrbiterA, 11U)) + aWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterE, 41U)) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 12U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + RotL64(aWandererG, 47U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 21672U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((aIndex + 24149U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aWorkLaneB[((aIndex + 20841U)) & S_BLOCK1], 20U) ^ RotL64(aOperationLaneA[((aIndex + 17288U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22626U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 20177U)) & S_BLOCK1], 48U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 16411U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aIngress, 37U)) ^ (RotL64(aCarry, 22U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 3U)) + RotL64(aCarry, 57U)) + 8685374557928800912U;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 35U)) + 3482312691892161229U) + aNonceWordE;
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 54U)) + 6948130297389161165U) + aOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = (((aWandererK + RotL64(aCross, 21U)) + RotL64(aCarry, 35U)) + 5506385663788942690U) + aOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 47U)) + 17859982009307397161U;
            aOrbiterH = (aWandererB + RotL64(aCross, 13U)) + 9178488809207094043U;
            aOrbiterC = (((aWandererA + RotL64(aIngress, 41U)) + RotL64(aCarry, 19U)) + 1835479501226057169U) + aNonceWordC;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 5368101733632614939U) + aOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 9050459666576835422U;
            aOrbiterJ = RotL64((aOrbiterJ * 10351719549990259551U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 9042186993119635078U) + aNonceWordI;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 17528342580198295025U;
            aOrbiterD = RotL64((aOrbiterD * 14316671546614386775U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 6495418332558436882U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 8834495762667327342U;
            aOrbiterA = RotL64((aOrbiterA * 10783141541937645995U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 4364314196965690905U) + aOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 6357485231062120459U) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 289429584586504995U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 3321488322626415347U) + aOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 10817330671781848737U;
            aOrbiterH = RotL64((aOrbiterH * 15875919466358823335U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 17974092279281611763U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 2871472057292789157U;
            aOrbiterE = RotL64((aOrbiterE * 16104199340711015181U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 15187929795092006849U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 13482063681546475923U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14466266308157364963U), 13U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterJ, 54U);
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 47U) + aOrbiterD) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 3U));
            aWandererB = aWandererB ^ ((((RotL64(aCross, 53U) + RotL64(aOrbiterH, 6U)) + aOrbiterE) + aNonceWordL) + aWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 13U) + aOrbiterG) + RotL64(aOrbiterE, 35U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 30U) + RotL64(aOrbiterD, 41U)) + aOrbiterA);
            aWandererD = aWandererD + (((RotL64(aCross, 39U) + aOrbiterC) + RotL64(aOrbiterE, 21U)) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterC, 53U)) + aWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterJ, 27U)) + aOrbiterD) + aNonceWordB);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 34U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererG, 5U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 24940U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((aIndex + 28229U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 31649U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneC[((aIndex + 30866U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31989U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26893U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 28131U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 30U) ^ RotL64(aCarry, 5U)) + (RotL64(aPrevious, 57U) + RotL64(aCross, 43U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterF = (((aWandererI + RotL64(aPrevious, 29U)) + RotL64(aCarry, 35U)) + 5960680319644404115U) + aOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = (aWandererF + RotL64(aScatter, 57U)) + 16050752633567034185U;
            aOrbiterH = (aWandererE + RotL64(aIngress, 3U)) + 8447503223226854741U;
            aOrbiterJ = (((aWandererC + RotL64(aCross, 13U)) + RotL64(aCarry, 47U)) + 14176813813397917591U) + aOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aIngress, 47U)) + RotL64(aCarry, 13U)) + 10534915376130006644U;
            aOrbiterC = ((aWandererH + RotL64(aScatter, 19U)) + 6866224454375302514U) + aNonceWordN;
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 40U)) + 16506374165041008396U) + aNonceWordG;
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 7167814023968794098U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 13870852197416596664U;
            aOrbiterH = RotL64((aOrbiterH * 17015971222069856463U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 18064038854848993105U) + aNonceWordI;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 9869630811507771691U) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 13723164383800461387U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 863613100452759380U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 16597969741225436529U;
            aOrbiterK = RotL64((aOrbiterK * 2680793528887208903U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 6575347108051310653U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 17062262265485019063U;
            aOrbiterF = RotL64((aOrbiterF * 7601045488473620019U), 11U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterB) + 7193399224636409133U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordK;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 14146747818810433849U;
            aOrbiterC = RotL64((aOrbiterC * 5273185769989530041U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 9441449106442431427U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 4303295336545399503U) ^ aOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8829695296836242587U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 12604760768543193458U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 15779327512379787715U) ^ aNonceWordP;
            aOrbiterG = RotL64((aOrbiterG * 14000905201441272597U), 35U);
            //
            aIngress = RotL64(aOrbiterK, 53U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 56U) + RotL64(aOrbiterG, 41U)) + aOrbiterK) + aNonceWordA);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterK, 23U));
            aWandererE = aWandererE + ((RotL64(aIngress, 47U) + RotL64(aOrbiterC, 13U)) + aOrbiterF);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterH, 53U)) + aOrbiterJ);
            aWandererH = aWandererH + ((((RotL64(aCross, 35U) + RotL64(aOrbiterC, 29U)) + aOrbiterB) + RotL64(aCarry, 41U)) + aNonceWordE);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 41U) + aOrbiterH) + RotL64(aOrbiterB, 4U)) + aWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aIngress, 23U) + aOrbiterJ) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 11U)) + aWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 34U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 21U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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

void TwistExpander_Fencing_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE;
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
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltC;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xE0561996D5FA3E7FULL + 0xE39FCE32EECA30A1ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xACB2C6720B1646C9ULL + 0xB4870668D1B04BCBULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x9C5A96520B60E073ULL + 0xED23C625C1AE3D89ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xF2B84E63E4803B63ULL + 0xF5CA3C7C735BC17EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xB56B5F99C1EE302BULL + 0x91AE539A5BB98627ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xCDB8DF16AD157DE1ULL + 0xF2FB7AFC96EBD3F4ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xC0F39F8DFC668DB5ULL + 0xA0F7DDCF6219EC5AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x96BF7D64E1166A17ULL + 0xEAB6799F6A5D52B8ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x8FB833FF58A9B5F7ULL + 0x8D2D4A617B2FCD6EULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xA6A45C09191F1EA5ULL + 0xE82AF7BB471D02A5ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xDE955561F5F3AFB3ULL + 0x90510DF2580DD820ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xB2693D9EF08F8D03ULL + 0x9B06FACB86D650C8ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x9511AA3CEF566C8DULL + 0xF9576414B9184C24ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xBEE30CC3FA5C0859ULL + 0xADC92B7A8AC786AEULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xD1E9464E06D2D6E3ULL + 0xA5C4ADA88C24DD32ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xCA12372EE0AD88BFULL + 0xC60D17BE6EB974A0ULL);
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 737U)) & W_KEY1], 51U) ^ RotL64(aKeyRowReadB[((aIndex + 1706U)) & W_KEY1], 42U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 1147U)) & W_KEY1], 3U) ^ RotL64(mSource[((aIndex + 2326U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 6U) + RotL64(aCarry, 57U)) ^ (RotL64(aCross, 23U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 51U)) + RotL64(aCarry, 51U)) + 13296600294247799698U;
            aOrbiterK = ((((aWandererH + RotL64(aScatter, 57U)) + RotL64(aCarry, 21U)) + 5818503518080877515U) + aPhaseEOrbiterAssignSaltD[((aIndex + 20U)) & S_SALT1]) + aNonceWordP;
            aOrbiterB = (aWandererB + RotL64(aCross, 21U)) + 6735784238734173597U;
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 14U)) + RotL64(aCarry, 5U)) + 7368398209488856201U;
            aOrbiterH = (((aWandererG + RotL64(aScatter, 39U)) + 961734029066455638U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordE;
            aOrbiterC = ((aWandererC + RotL64(aCross, 27U)) + 797011946660892011U) + aNonceWordO;
            aOrbiterD = (aWandererD + RotL64(aIngress, 3U)) + 12841876018396622350U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 16213253970483895623U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 15186950557113470375U;
            aOrbiterB = RotL64((aOrbiterB * 4647470430467908107U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 5117930310827477341U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 12265429373166094162U;
            aOrbiterJ = RotL64((aOrbiterJ * 1522823535151532249U), 35U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterJ) + 13920531346698601568U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1]) + aNonceWordG;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 14695405206998211456U;
            aOrbiterD = RotL64((aOrbiterD * 13950964363414164279U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 7851960904825938443U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 9501511171732550190U) ^ aNonceWordK;
            aOrbiterC = RotL64((aOrbiterC * 5614164120361489613U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 5663365182245722077U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 9607860124321315555U;
            aOrbiterH = RotL64((aOrbiterH * 3461820361914280601U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 18171052650586819280U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 3442698321538580861U;
            aOrbiterK = RotL64((aOrbiterK * 6317525514963824829U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 1491052813469258970U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 3956599824067616133U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2928600779267623085U), 13U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 51U);
            aIngress = aIngress + (RotL64(aOrbiterD, 30U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterF, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterC, 39U)) + aOrbiterD) + aPhaseEWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 5U) + aOrbiterD) + RotL64(aOrbiterH, 3U)) + aNonceWordA);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 19U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aCross, 41U) + aOrbiterD) + RotL64(aOrbiterB, 47U)) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterJ, 13U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 34U) + aOrbiterC) + RotL64(aOrbiterK, 28U)) + RotL64(aCarry, 35U)) + aPhaseEWandererUpdateSaltF[((aIndex + 8U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterF, 57U)) + aNonceWordF);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (RotL64(aWandererC, 56U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 39U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 4376U)) & S_BLOCK1], 52U) ^ RotL64(aKeyRowReadA[((aIndex + 5460U)) & W_KEY1], 13U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 3686U)) & W_KEY1], 13U) ^ RotL64(mSource[((aIndex + 5325U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 10U) + RotL64(aPrevious, 29U)) ^ (RotL64(aCarry, 57U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterC = ((((aWandererC + RotL64(aIngress, 13U)) + RotL64(aCarry, 35U)) + 6916817163240024692U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordO;
            aOrbiterD = (((aWandererF + RotL64(aPrevious, 5U)) + RotL64(aCarry, 21U)) + 14554930751292077817U) + aPhaseEOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 23U)) + 1098305064484336101U) + aNonceWordD;
            aOrbiterH = (((aWandererI + RotL64(aCross, 29U)) + RotL64(aCarry, 5U)) + 12192821172420471527U) + aNonceWordM;
            aOrbiterA = (aWandererH + RotL64(aPrevious, 57U)) + 2435134991707318845U;
            aOrbiterB = (aWandererG + RotL64(aIngress, 50U)) + 1896745368738512624U;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 39U)) + 1114996424222923873U) + aNonceWordA;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 9839135798371512656U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 8037967239603177043U;
            aOrbiterK = RotL64((aOrbiterK * 7848951103759663025U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 15185468738487237432U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 4912098316394854543U) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 3072785550384399929U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 13142688607850380888U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 4507379759608945839U;
            aOrbiterD = RotL64((aOrbiterD * 2989332387754215967U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 7299006009652289342U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 5390655277207053627U;
            aOrbiterH = RotL64((aOrbiterH * 10973744708856143715U), 29U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterK) + 6744737023577785725U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 15539737698867067285U;
            aOrbiterB = RotL64((aOrbiterB * 4686092035261336911U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 13329866734681377952U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 13284937458969166257U;
            aOrbiterE = RotL64((aOrbiterE * 3965985432462699445U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 8695002088915702168U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 3858059421620839286U) ^ aNonceWordE;
            aOrbiterC = RotL64((aOrbiterC * 9559783727301092937U), 53U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterD, 13U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + RotL64(aOrbiterK, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 13U) + RotL64(aOrbiterC, 35U)) + aOrbiterE) + aNonceWordI) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 4U) + aOrbiterH) + RotL64(aOrbiterE, 3U)) + RotL64(aCarry, 51U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 29U) + aOrbiterC) + RotL64(aOrbiterD, 46U)) + aPhaseEWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 57U) + aOrbiterE) + RotL64(aOrbiterB, 27U)) + RotL64(aCarry, 29U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 57U)) + aOrbiterC);
            aWandererC = aWandererC + ((RotL64(aCross, 39U) + aOrbiterH) + RotL64(aOrbiterK, 13U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 21U)) + aOrbiterK) + aNonceWordB);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 18U));
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 39U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = RotL64(aFireLaneB[((aIndex + 6966U)) & S_BLOCK1], 37U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 7218U)) & W_KEY1], 21U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 7637U)) & W_KEY1], 57U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6872U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 6388U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 13U)) ^ (RotL64(aCarry, 30U) ^ RotL64(aIngress, 43U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterD = (((aWandererF + RotL64(aIngress, 29U)) + 5041131702736607991U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordC;
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 57U)) + RotL64(aCarry, 11U)) + 9295010428212681446U;
            aOrbiterJ = ((aWandererE + RotL64(aCross, 51U)) + 6235875895358766017U) + aNonceWordH;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 13U)) + RotL64(aCarry, 23U)) + 2622227802531866918U;
            aOrbiterH = (((aWandererK + RotL64(aIngress, 4U)) + RotL64(aCarry, 41U)) + 3888894734834524972U) + aNonceWordG;
            aOrbiterI = (aWandererA + RotL64(aCross, 37U)) + 241682012014701753U;
            aOrbiterK = ((aWandererI + RotL64(aScatter, 43U)) + 15758000422451568079U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 2061944548396976912U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 8177144990755754531U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12702392689484397947U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 554978075608818497U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 250408260560714933U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1295379390497107727U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 8700027645880997552U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 10026130047465480902U;
            aOrbiterF = RotL64((aOrbiterF * 12417270861933696623U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 9785843014096326696U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 9998582683258411251U;
            aOrbiterH = RotL64((aOrbiterH * 7197956237569462269U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 13817734599383455151U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 6647207154174092691U;
            aOrbiterA = RotL64((aOrbiterA * 1578528131687283531U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 4957715980509035719U) + aNonceWordN;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 4994885315786213197U;
            aOrbiterK = RotL64((aOrbiterK * 5676683798126497011U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 5072908311783966503U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterI) ^ 5535039946192891515U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterD = RotL64((aOrbiterD * 2989412783482309753U), 21U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterK, 42U);
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 5U) + aOrbiterD) + RotL64(aOrbiterK, 57U));
            aWandererE = aWandererE + (((((RotL64(aScatter, 21U) + RotL64(aOrbiterF, 5U)) + aOrbiterH) + RotL64(aCarry, 5U)) + aNonceWordF) + aPhaseEWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterF, 40U)) + aOrbiterA);
            aWandererI = aWandererI + (((RotL64(aCross, 58U) + RotL64(aOrbiterD, 21U)) + aOrbiterJ) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 29U)) + aOrbiterI) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterJ, 47U)) + aNonceWordA);
            aWandererC = aWandererC ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 11U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 44U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 10454U)) & S_BLOCK1], 35U) ^ RotL64(aKeyRowReadB[((aIndex + 10402U)) & W_KEY1], 3U));
            aIngress ^= (RotL64(mSource[((aIndex + 10551U)) & S_BLOCK1], 24U) ^ RotL64(aFireLaneA[((aIndex + 10454U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 8591U)) & W_KEY1], 21U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 9278U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 21U) + RotL64(aCross, 39U)) ^ (RotL64(aPrevious, 6U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterJ = (((aWandererD + RotL64(aScatter, 43U)) + RotL64(aCarry, 3U)) + 1297415699043177788U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = (aWandererC + RotL64(aIngress, 29U)) + 17583786534509260153U;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 13U)) + RotL64(aCarry, 39U)) + 643197858925708798U;
            aOrbiterH = (aWandererJ + RotL64(aCross, 57U)) + 5062653766915694874U;
            aOrbiterD = (((aWandererA + RotL64(aIngress, 6U)) + RotL64(aCarry, 27U)) + 7034273638367180511U) + aNonceWordG;
            aOrbiterC = (aWandererE + RotL64(aCross, 37U)) + 2026909726972916996U;
            aOrbiterB = (((aWandererB + RotL64(aPrevious, 51U)) + 2785690475553211646U) + aPhaseFOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1]) + aNonceWordE;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 2910341716302991892U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 2834181605200829791U;
            aOrbiterG = RotL64((aOrbiterG * 1510617068750957651U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 13323052600571281928U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 10434901530315760460U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2042210188346767033U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 247903955625194782U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 5196515747387257163U;
            aOrbiterB = RotL64((aOrbiterB * 1799024689023272275U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 7196305682377987476U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 14777739876892587484U;
            aOrbiterD = RotL64((aOrbiterD * 95220583948241581U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 10609060796540136671U) + aNonceWordM;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 8386027207212484155U) ^ aNonceWordJ;
            aOrbiterA = RotL64((aOrbiterA * 4855610536246556893U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 729659744301903424U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 2350564261412606157U;
            aOrbiterJ = RotL64((aOrbiterJ * 16713856782349084977U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 16611987556673864177U) + aNonceWordD;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 1525195188708550503U;
            aOrbiterH = RotL64((aOrbiterH * 10045858602151004553U), 47U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterG, 5U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 60U));
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterH, 51U)) + aOrbiterG);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 57U)) + aOrbiterJ) + RotL64(aCarry, 57U)) + aNonceWordN);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterG, 43U)) + aNonceWordA);
            aWandererJ = aWandererJ + (((RotL64(aCross, 43U) + RotL64(aOrbiterC, 29U)) + aOrbiterD) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterC, 37U)) + aOrbiterB) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 50U) + aOrbiterA) + RotL64(aOrbiterH, 20U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 13U) + aOrbiterD) + RotL64(aOrbiterB, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + RotL64(aWandererC, 44U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 11727U)) & S_BLOCK1], 39U) ^ RotL64(aKeyRowReadA[((aIndex + 12731U)) & W_KEY1], 13U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 13640U)) & W_KEY1], 21U) ^ RotL64(mSource[((aIndex + 13640U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 13306U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 11169U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 11169U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 14U) ^ RotL64(aCross, 39U)) ^ (RotL64(aPrevious, 27U) + RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterA = (((aWandererA + RotL64(aPrevious, 43U)) + RotL64(aCarry, 3U)) + 12222235191147985484U) + aPhaseFOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = (((aWandererD + RotL64(aIngress, 27U)) + RotL64(aCarry, 27U)) + 16367317014523328414U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = (((aWandererC + RotL64(aCross, 37U)) + RotL64(aCarry, 51U)) + 3511378091284703789U) + aNonceWordF;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 21U)) + 15247492830966725949U) + aNonceWordE;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 51U)) + 7745995913390407897U;
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 13U)) + 6463593307540108810U) + aNonceWordH;
            aOrbiterH = ((aWandererE + RotL64(aCross, 60U)) + 1101669311005268630U) + aNonceWordJ;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 12988052764067518580U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 17717179747434679772U;
            aOrbiterI = RotL64((aOrbiterI * 10820310705487638793U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 11662190906682400416U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 6563014073547628748U) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 16967910471722117761U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 13099094932059419219U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 16342730862261868847U;
            aOrbiterJ = RotL64((aOrbiterJ * 10988124108686164829U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 16855346813127524624U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 6570063128502306944U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4571570049463124831U), 11U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterC) + 11328352033809240501U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1]) + aNonceWordL;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 11640986648833160901U;
            aOrbiterB = RotL64((aOrbiterB * 2895830492089678919U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 2675226158571501666U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 17700531248266458165U;
            aOrbiterA = RotL64((aOrbiterA * 2231403813970188657U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 7729597396731910874U) + aNonceWordC;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 15172374484412053756U;
            aOrbiterH = RotL64((aOrbiterH * 149009041406406517U), 47U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 39U);
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterE, 56U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterC, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 27U) + aOrbiterH) + RotL64(aOrbiterB, 14U));
            aWandererD = aWandererD + (((RotL64(aCross, 5U) + RotL64(aOrbiterJ, 21U)) + aOrbiterA) + aPhaseFWandererUpdateSaltE[((aIndex + 22U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterA, 43U)) + aOrbiterI);
            aWandererE = aWandererE + (((((RotL64(aScatter, 60U) + aOrbiterH) + RotL64(aOrbiterE, 5U)) + RotL64(aCarry, 13U)) + aNonceWordM) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 53U)) + aOrbiterE);
            aWandererG = aWandererG + ((((RotL64(aCross, 41U) + aOrbiterA) + RotL64(aOrbiterC, 29U)) + RotL64(aCarry, 27U)) + aNonceWordG);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterE, 35U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 41U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + RotL64(aWandererG, 18U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 14268U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneC[((aIndex + 14230U)) & S_BLOCK1], 42U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 14470U)) & W_KEY1], 27U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 14732U)) & W_KEY1], 54U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 14115U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 13947U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 16015U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 20U)) ^ (RotL64(aCross, 35U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterF = (((aWandererC + RotL64(aCross, 21U)) + RotL64(aCarry, 53U)) + 13350544654542863236U) + aNonceWordK;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 43U)) + 12364346790125404372U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = (((aWandererK + RotL64(aIngress, 13U)) + RotL64(aCarry, 23U)) + 9738750172849512764U) + aPhaseFOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = (((aWandererI + RotL64(aScatter, 29U)) + RotL64(aCarry, 37U)) + 3781373837635491421U) + aNonceWordN;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 35U)) + 16635020317512702337U) + aNonceWordD;
            aOrbiterA = (aWandererF + RotL64(aScatter, 6U)) + 5383653921676231276U;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 51U)) + 10181959815492056493U) + aNonceWordE;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 10005510924273927017U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 9524687662265740565U;
            aOrbiterJ = RotL64((aOrbiterJ * 13687380438646756931U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 4259138552009771014U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 8973051213213726023U;
            aOrbiterE = RotL64((aOrbiterE * 12625091476068190979U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 17602611840127337490U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 8218984546932905269U;
            aOrbiterA = RotL64((aOrbiterA * 17504305273683304231U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 18102186122213487888U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 2629927500298092976U;
            aOrbiterI = RotL64((aOrbiterI * 6983280164448292723U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 2491581597835795234U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 9506602492971620955U) ^ aNonceWordG;
            aOrbiterG = RotL64((aOrbiterG * 9559829640915637163U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 13422942713680612924U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 15037354693234876601U;
            aOrbiterF = RotL64((aOrbiterF * 12692376075738621447U), 41U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterE) + 12896066842192894694U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 2202952306291905855U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6779368532763429997U), 35U);
            //
            aIngress = RotL64(aOrbiterI, 57U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterH, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 4U) + RotL64(aOrbiterJ, 3U)) + aOrbiterI) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 23U) + aOrbiterG) + RotL64(aOrbiterA, 13U)) + aNonceWordM);
            aWandererI = aWandererI + (((((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 27U)) + aOrbiterH) + RotL64(aCarry, 41U)) + aNonceWordB) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterH, 21U)) + aOrbiterA) + aNonceWordO);
            aWandererG = aWandererG + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterI, 37U)) + aOrbiterH) + aNonceWordC);
            aWandererE = aWandererE ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterA, 43U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterG, 54U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 54U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + RotL64(aWandererD, 35U);
            aCarry = aCarry + RotL64(aIngress, 28U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 17636U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadA[((aIndex + 17238U)) & W_KEY1], 11U));
            aIngress ^= (RotL64(mSource[((aIndex + 16508U)) & S_BLOCK1], 53U) ^ RotL64(aFireLaneA[((aIndex + 16503U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 16699U)) & W_KEY1], 11U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 18927U)) & S_BLOCK1], 42U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 16462U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCross, 53U)) ^ (RotL64(aCarry, 10U) + RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterJ = (((aWandererJ + RotL64(aIngress, 13U)) + RotL64(aCarry, 57U)) + 1898718075389870739U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = (((aWandererB + RotL64(aCross, 6U)) + RotL64(aCarry, 39U)) + 5631794889237247403U) + aPhaseGOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = (((aWandererH + RotL64(aPrevious, 57U)) + RotL64(aCarry, 27U)) + 18219714659484524607U) + aNonceWordC;
            aOrbiterF = (aWandererG + RotL64(aScatter, 21U)) + 15419581386225732921U;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 29U)) + 9125575431710198210U) + aNonceWordF;
            aOrbiterG = (aWandererE + RotL64(aIngress, 51U)) + 12205871520544965505U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 43U)) + 7617534300497343422U;
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterD) + 18017579105368135814U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1]) + aNonceWordK;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 10693882161946020042U;
            aOrbiterH = RotL64((aOrbiterH * 2326507900303932855U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 11669615701700895306U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 11045110212889232165U;
            aOrbiterC = RotL64((aOrbiterC * 5965171269273719849U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 18019107802806469913U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 12315940560472528716U;
            aOrbiterD = RotL64((aOrbiterD * 4505122470351404065U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 4899009736070044310U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 17412253404253730364U) ^ aNonceWordL;
            aOrbiterG = RotL64((aOrbiterG * 10791901166391946485U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 4826286251927854181U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 4523455921321845084U;
            aOrbiterA = RotL64((aOrbiterA * 14534103906736598099U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 4132514462154182215U) + aNonceWordM;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 7164745605985109269U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14107325508977225261U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 6297434295807635654U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 8813887638672996646U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17495632530773158201U), 5U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterA, 57U);
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterG, 21U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterC, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 46U) + RotL64(aOrbiterF, 11U)) + aOrbiterD);
            aWandererG = aWandererG + (((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 5U)) + aOrbiterG) + aNonceWordE);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 19U)) + aOrbiterH) + aPhaseGWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 29U) + aOrbiterD) + RotL64(aOrbiterA, 28U)) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterA, 35U)) + aOrbiterC) + aNonceWordI);
            aWandererB = aWandererB + (((((RotL64(aCross, 13U) + RotL64(aOrbiterD, 51U)) + aOrbiterJ) + RotL64(aCarry, 29U)) + aNonceWordJ) + aPhaseGWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 19U) + aOrbiterC) + RotL64(aOrbiterD, 43U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 46U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 35U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 21061U)) & S_BLOCK1], 14U) ^ RotL64(mSource[((aIndex + 19177U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aWorkLaneA[((aIndex + 20234U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 21420U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 20209U)) & W_KEY1], 39U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 20943U)) & W_KEY1], 3U));
            aCross ^= (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20456U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneB[((aIndex + 19331U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aIngress, 41U)) ^ (RotL64(aPrevious, 28U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterC = (((aWandererE + RotL64(aCross, 58U)) + RotL64(aCarry, 11U)) + 10805654776556844351U) + aPhaseGOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aScatter, 3U)) + 582794182442795335U) + aNonceWordO;
            aOrbiterF = ((((aWandererJ + RotL64(aPrevious, 41U)) + RotL64(aCarry, 29U)) + 2858343650974681068U) + aPhaseGOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1]) + aNonceWordH;
            aOrbiterD = (aWandererH + RotL64(aIngress, 13U)) + 8189584049022064284U;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 29U)) + RotL64(aCarry, 43U)) + 1565100751996962893U;
            aOrbiterI = (aWandererF + RotL64(aIngress, 47U)) + 8062028016947611891U;
            aOrbiterB = (aWandererG + RotL64(aPrevious, 21U)) + 8280504280578451745U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 11326869194491655350U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 1671695656567777163U;
            aOrbiterF = RotL64((aOrbiterF * 7511554500524257921U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 2349843105293943452U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 13015545152052004254U;
            aOrbiterA = RotL64((aOrbiterA * 1316662811685429983U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 16703354404749291869U) + aNonceWordF;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 8713231044374305801U;
            aOrbiterC = RotL64((aOrbiterC * 9242480982197688625U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 11118401674497783533U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 14857556493734710364U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3452566050389715195U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 12953419670951660965U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 12666121730825089017U) ^ aNonceWordA;
            aOrbiterH = RotL64((aOrbiterH * 14049925256934142519U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 11075249639473053423U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 9374217688244187867U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5261156325627117877U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 17608340953291367867U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 13159437499327086340U;
            aOrbiterD = RotL64((aOrbiterD * 4882100944453534805U), 47U);
            //
            aIngress = RotL64(aOrbiterB, 53U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterF, 60U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aIngress, 27U) + aOrbiterA) + RotL64(aOrbiterC, 13U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterI, 29U)) + aNonceWordP);
            aWandererA = aWandererA + ((RotL64(aCross, 41U) + RotL64(aOrbiterB, 23U)) + aOrbiterI);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 37U)) + aOrbiterA) + aNonceWordI);
            aWandererF = aWandererF + (((((RotL64(aPrevious, 34U) + aOrbiterC) + RotL64(aOrbiterI, 58U)) + RotL64(aCarry, 41U)) + aNonceWordM) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 47U) + aOrbiterB) + RotL64(aOrbiterH, 43U)) + aNonceWordJ) + aPhaseGWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 21U) + RotL64(aOrbiterI, 5U)) + aOrbiterD) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 14U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 23643U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadA[((aIndex + 21977U)) & W_KEY1], 43U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 21975U)) & W_KEY1], 35U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 22148U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 23262U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23744U)) & S_BLOCK1], 51U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 22774U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneD[((aIndex + 22048U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aPrevious, 36U)) ^ (RotL64(aCarry, 23U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterC = (aWandererA + RotL64(aIngress, 27U)) + 8375305456876489425U;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 5U)) + 16193562952772453047U) + aNonceWordG;
            aOrbiterB = (((aWandererE + RotL64(aPrevious, 19U)) + RotL64(aCarry, 23U)) + 18088652458594816223U) + aNonceWordK;
            aOrbiterJ = (aWandererF + RotL64(aCross, 47U)) + 767344788620249944U;
            aOrbiterG = ((((aWandererH + RotL64(aScatter, 57U)) + RotL64(aCarry, 11U)) + 7705194930396368752U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordF;
            aOrbiterK = (aWandererD + RotL64(aCross, 13U)) + 3829736891311272834U;
            aOrbiterA = (((aWandererJ + RotL64(aIngress, 40U)) + RotL64(aCarry, 35U)) + 9881681671347640061U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 1721196560190164264U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 3002652618388454213U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15289749311593032657U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 9811621464004005202U) + aNonceWordJ;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 5652598941069986530U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4797973356708091621U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 6250499348327316328U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 16025054277615264530U;
            aOrbiterG = RotL64((aOrbiterG * 16446892258704281903U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 13800298546867243172U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 12256104592865905782U) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 16983140179497142713U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 17817225416918329229U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 17738671327352776217U;
            aOrbiterC = RotL64((aOrbiterC * 393488251327705063U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 6816031224188400541U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 16989563985059237014U;
            aOrbiterF = RotL64((aOrbiterF * 8677884225771717797U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 16891524847268207549U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 1833508573940405571U) ^ aNonceWordL;
            aOrbiterJ = RotL64((aOrbiterJ * 9709196587703979539U), 35U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterF, 13U);
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + RotL64(aOrbiterJ, 60U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 47U)) + aOrbiterG) + aNonceWordO);
            aWandererD = aWandererD + (((RotL64(aScatter, 19U) + RotL64(aOrbiterG, 3U)) + aOrbiterK) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterC, 12U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 6U) + aOrbiterG) + RotL64(aOrbiterA, 21U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 51U) + aOrbiterF) + RotL64(aOrbiterJ, 57U));
            aWandererF = aWandererF + (((((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 47U)) + aNonceWordN) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 13U) + aOrbiterC) + RotL64(aOrbiterG, 27U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 10U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + RotL64(aWandererA, 21U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 25070U)) & S_BLOCK1], 29U) ^ RotL64(aKeyRowReadA[((aIndex + 25098U)) & W_KEY1], 10U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 26432U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27193U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 24628U)) & W_KEY1], 29U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 24669U)) & S_BLOCK1], 46U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 25832U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 27143U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 4U) + RotL64(aIngress, 23U)) ^ (RotL64(aCross, 39U) + RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterF = (((aWandererD + RotL64(aPrevious, 51U)) + RotL64(aCarry, 57U)) + 17019646486641172469U) + aNonceWordE;
            aOrbiterB = (aWandererA + RotL64(aCross, 27U)) + 12276141179299971572U;
            aOrbiterH = (aWandererE + RotL64(aScatter, 38U)) + 3617241694029841555U;
            aOrbiterE = (((aWandererB + RotL64(aIngress, 57U)) + RotL64(aCarry, 27U)) + 6967963401259371737U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = ((aWandererF + RotL64(aScatter, 3U)) + RotL64(aCarry, 39U)) + 6340709284279891017U;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 13U)) + 456065368903896482U) + aPhaseHOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aIngress, 21U)) + 17686765719908116203U) + aNonceWordB;
            //
            aOrbiterF = (((aOrbiterF + aOrbiterB) + 1322045955429785736U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1]) + aNonceWordI;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 5163772703302372887U;
            aOrbiterH = RotL64((aOrbiterH * 3193272189179082313U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 13268431135020363252U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterE) ^ 6538789950366849332U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 5352960308459065837U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 10390344544314544893U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 5087084271300584267U;
            aOrbiterE = RotL64((aOrbiterE * 15149302947570776165U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 13423071121590981727U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 18324443012024134729U;
            aOrbiterF = RotL64((aOrbiterF * 15814349432207734533U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 4129091815978464507U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 17024797553831962245U) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 3137753479364378175U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 6501545108779991661U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 11930037791867597447U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4904739567549702851U), 41U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterG) + 4667298703308315851U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1]) + aNonceWordN;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 6315980380900062127U;
            aOrbiterI = RotL64((aOrbiterI * 12080555704907924637U), 51U);
            //
            aIngress = RotL64(aOrbiterF, 19U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterB, 60U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 43U) + aOrbiterA) + RotL64(aOrbiterG, 57U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 13U) + aOrbiterF) + RotL64(aOrbiterA, 43U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 4U) + aOrbiterG) + RotL64(aOrbiterE, 50U)) + aNonceWordG) + aPhaseHWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 35U) + aOrbiterF) + RotL64(aOrbiterB, 27U)) + aNonceWordA);
            aWandererB = aWandererB + (((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterI, 5U)) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 19U) + aOrbiterB) + RotL64(aOrbiterI, 19U)) + aNonceWordH);
            aWandererF = aWandererF + (((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 13U)) + aOrbiterH) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 36U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 28705U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneD[((aIndex + 29869U)) & S_BLOCK1], 60U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 27805U)) & W_KEY1], 41U) ^ RotL64(aWorkLaneC[((aIndex + 28746U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 28412U)) & W_KEY1], 19U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29610U)) & S_BLOCK1], 43U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29231U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((aIndex + 28106U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 18U)) + (RotL64(aPrevious, 35U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterC = ((aWandererG + RotL64(aCross, 29U)) + 16016931609704150191U) + aNonceWordD;
            aOrbiterD = (((aWandererD + RotL64(aPrevious, 11U)) + 14511433515861302636U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordI;
            aOrbiterA = (((aWandererJ + RotL64(aIngress, 3U)) + RotL64(aCarry, 51U)) + 11691237442613269593U) + aNonceWordJ;
            aOrbiterG = ((aWandererF + RotL64(aScatter, 39U)) + RotL64(aCarry, 39U)) + 16383220587320484649U;
            aOrbiterK = ((((aWandererK + RotL64(aCross, 21U)) + RotL64(aCarry, 23U)) + 14293015313458219868U) + aPhaseHOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1]) + aNonceWordM;
            aOrbiterI = (aWandererE + RotL64(aPrevious, 54U)) + 4407695248205526670U;
            aOrbiterH = (aWandererA + RotL64(aScatter, 47U)) + 1158323195324398372U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 6577683409653864555U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 171080079472863843U;
            aOrbiterA = RotL64((aOrbiterA * 3063978974927752653U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 5766333425872228205U) + aNonceWordC;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 16173508656917582960U;
            aOrbiterD = RotL64((aOrbiterD * 12187968015372936695U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 11781450063402219202U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 13033139686637576694U;
            aOrbiterG = RotL64((aOrbiterG * 4331137994135472025U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 4006310759400926020U) + aNonceWordK;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 13156817947481574467U;
            aOrbiterH = RotL64((aOrbiterH * 563189239835001483U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 12791290558893516411U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 989729955679243234U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8757228712495095017U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 838379839663022790U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterK) ^ 2830743864262313606U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 10173947177104802797U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 2146646527331684652U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 4629168181742174906U;
            aOrbiterC = RotL64((aOrbiterC * 9046124907945045131U), 47U);
            //
            aIngress = RotL64(aOrbiterK, 41U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 21U));
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aScatter, 27U) + RotL64(aOrbiterC, 19U)) + aOrbiterD) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterH, 43U)) + aOrbiterD) + aNonceWordG);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 13U)) + aOrbiterA) + RotL64(aCarry, 51U)) + aPhaseHWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 41U) + aOrbiterG) + RotL64(aOrbiterI, 57U)) + aPhaseHWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 54U) + RotL64(aOrbiterC, 36U)) + aOrbiterK) + aNonceWordP);
            aWandererA = aWandererA ^ (((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterA, 27U)) + aNonceWordF);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterI, 5U)) + aNonceWordB);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererD, 24U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 32280U)) & S_BLOCK1], 35U) ^ RotL64(aKeyRowReadA[((aIndex + 32520U)) & W_KEY1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 32765U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31548U)) & S_BLOCK1], 21U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32652U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 31870U)) & W_KEY1], 35U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 42U) + RotL64(aCarry, 57U)) + (RotL64(aCross, 11U) ^ RotL64(aPrevious, 29U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterJ = ((((aWandererA + RotL64(aCross, 53U)) + RotL64(aCarry, 19U)) + 6381335981879993247U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordC;
            aOrbiterK = (aWandererC + RotL64(aPrevious, 11U)) + 15595429101600023172U;
            aOrbiterD = (aWandererF + RotL64(aScatter, 27U)) + 5449234297249826461U;
            aOrbiterH = ((((aWandererB + RotL64(aIngress, 19U)) + RotL64(aCarry, 57U)) + 11213734849329731168U) + aPhaseHOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1]) + aNonceWordO;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 42U)) + RotL64(aCarry, 41U)) + 16438473952464514248U;
            aOrbiterC = (aWandererI + RotL64(aCross, 3U)) + 7357872882115186976U;
            aOrbiterB = ((aWandererK + RotL64(aIngress, 35U)) + 394402075160738643U) + aNonceWordB;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 11112941985410283532U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 14955125011182736212U;
            aOrbiterD = RotL64((aOrbiterD * 10711684773326395603U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 14770727009821304070U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 11286366598129204910U) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 15884310771003021989U), 21U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterJ) + 7358400908565425780U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordE;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 15635109923749114761U;
            aOrbiterC = RotL64((aOrbiterC * 12415152149408700329U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 13826842523738623579U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 1072811298828325231U;
            aOrbiterH = RotL64((aOrbiterH * 9662800288646215083U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 4017334196009350776U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 8812213572751410831U;
            aOrbiterJ = RotL64((aOrbiterJ * 12744171921566782795U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 6723457786170634403U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 9785583533999417673U) ^ aNonceWordK;
            aOrbiterK = RotL64((aOrbiterK * 7776915427605471097U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 10265132640322153964U) + aNonceWordF;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 8435670887514808087U;
            aOrbiterB = RotL64((aOrbiterB * 2706263045620662131U), 43U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterD, 47U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + RotL64(aOrbiterI, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 5U) + aOrbiterD) + RotL64(aOrbiterB, 37U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 57U) + aOrbiterJ) + RotL64(aOrbiterI, 23U)) + RotL64(aCarry, 23U)) + aNonceWordJ);
            aWandererB = aWandererB ^ (((RotL64(aCross, 50U) + aOrbiterK) + RotL64(aOrbiterB, 3U)) + aPhaseHWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 11U) + aOrbiterI) + RotL64(aOrbiterC, 29U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 47U)) + aOrbiterH);
            aWandererH = aWandererH + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 53U)) + aOrbiterI) + RotL64(aCarry, 43U)) + aNonceWordD);
            aWandererC = aWandererC ^ (((RotL64(aCross, 29U) + aOrbiterJ) + RotL64(aOrbiterH, 10U)) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 4U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_Fencing_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xCF0ECB2CE0C9E231ULL + 0xC8734E1AC7C5DB98ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x9DF7DB08C8C012A7ULL + 0xF617C71B6CFD9327ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x9FD9D7E7CF47DDE7ULL + 0x854239DDC466DBA9ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xBBC31B5E1F477ECBULL + 0xE783E0993CC02F0AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x8F3F44B9D2473311ULL + 0xCE05F8D78AE400A6ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xAEF55280E825221FULL + 0xC5B9B626F40158DDULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xC30024A0A94E4BA1ULL + 0xF81F30440B28C1BAULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x9E9F4DDE6AB134D1ULL + 0xE806B65E1D9AFAC0ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xB73FE7056F3F197DULL + 0xD7E11BBDD9E83CA5ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xA30426CA827C9109ULL + 0xF03A9E0C56E1B982ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xCB6859369DA63575ULL + 0x960ECFDDD1774563ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x93DD32EDCCB61B0FULL + 0xC0F8EF5B3787A195ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x93DCD16DF5AC93A3ULL + 0xAD001309ABC33DE6ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xF761F0A9641E4FBBULL + 0xEC49D38191934A65ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xD880874B89419187ULL + 0xA5469C1AB9228925ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xF7304CEDA0796A2DULL + 0xCC25369BB494E7ADULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 1742U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((aIndex + 4802U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 4916U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3966U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 344U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 690U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 38U) + RotL64(aCarry, 51U)) ^ (RotL64(aCross, 23U) ^ RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterH = (aWandererJ + RotL64(aIngress, 27U)) + 16519040829220310189U;
            aOrbiterF = ((((aWandererH + RotL64(aScatter, 47U)) + RotL64(aCarry, 53U)) + 6888002778416941825U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordG;
            aOrbiterK = (((aWandererA + RotL64(aPrevious, 19U)) + RotL64(aCarry, 41U)) + 1310832187746534025U) + aNonceWordC;
            aOrbiterC = ((((aWandererE + RotL64(aCross, 35U)) + RotL64(aCarry, 13U)) + 5890888009051281674U) + aPhaseAOrbiterAssignSaltE[((aIndex + 4U)) & S_SALT1]) + aNonceWordE;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 60U)) + 5143864838362464857U) + aNonceWordO;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 15591534069452660003U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 1466867671765325096U) ^ aNonceWordP;
            aOrbiterK = RotL64((aOrbiterK * 1277202105237572301U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 13931443680107902488U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterF) ^ 15400747367673245552U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterC = RotL64((aOrbiterC * 7011651369456453127U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 2836975369734495759U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 2370720358274970117U) ^ aNonceWordD;
            aOrbiterH = RotL64((aOrbiterH * 4615571902817575375U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 3470677184188006133U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 7175584278499266723U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10067096593682482345U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 6095078817776863055U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 2176637999243513070U;
            aOrbiterA = RotL64((aOrbiterA * 12215701810843975501U), 19U);
            //
            aIngress = RotL64(aOrbiterC, 3U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 52U));
            aIngress = aIngress + RotL64(aOrbiterF, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 27U)) + aOrbiterH) + aNonceWordN);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 21U) + RotL64(aOrbiterC, 35U)) + aOrbiterA) + RotL64(aCarry, 3U)) + aPhaseAWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 39U) + aOrbiterK) + RotL64(aOrbiterH, 13U)) + aNonceWordH) + aPhaseAWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aIngress, 58U) + RotL64(aOrbiterK, 57U)) + aOrbiterA) + RotL64(aCarry, 21U)) + aNonceWordK);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 48U)) + aOrbiterA) + aNonceWordB);
            //
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 4U));
            aCarry = aCarry + RotL64(aWandererH, 37U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 9923U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneC[((aIndex + 10823U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 5940U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneC[((aIndex + 8945U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 7859U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 8365U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 6174U)) & S_BLOCK1], 40U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aPrevious, 41U)) ^ (RotL64(aIngress, 54U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterD = (((aWandererA + RotL64(aIngress, 11U)) + RotL64(aCarry, 27U)) + 6469584119078165548U) + aNonceWordH;
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 43U)) + 14329756366517987910U) + aNonceWordJ;
            aOrbiterE = (((aWandererJ + RotL64(aScatter, 29U)) + 12890831797059772123U) + aPhaseAOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1]) + aNonceWordM;
            aOrbiterB = ((((aWandererD + RotL64(aCross, 19U)) + RotL64(aCarry, 41U)) + 3164503807500018990U) + aPhaseAOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1]) + aNonceWordK;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 58U)) + RotL64(aCarry, 5U)) + 177531431387646836U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 3167421392893561015U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 2813174781844753460U) ^ aNonceWordA;
            aOrbiterE = RotL64((aOrbiterE * 9760688894575305115U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 10953270419153249857U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 16911518309710356951U) ^ aNonceWordI;
            aOrbiterD = RotL64((aOrbiterD * 13162785997686570445U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 6616750447844893150U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 10276741398025985982U;
            aOrbiterI = RotL64((aOrbiterI * 6824712685896987133U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 6206043608461213208U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 12021552904553405793U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10023362889960174909U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 15283586234744144846U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 5923238786775948571U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8200882393521882651U), 3U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterI, 57U);
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterI, 37U)) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ ((((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterE, 3U)) + aNonceWordG) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 40U) + aOrbiterB) + RotL64(aOrbiterE, 50U)) + RotL64(aCarry, 3U));
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterB, 13U)) + aOrbiterI) + aNonceWordP) + aPhaseAWandererUpdateSaltB[((aIndex + 20U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 5U) + RotL64(aOrbiterB, 29U)) + aOrbiterF) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 53U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 15646U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((aIndex + 12193U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12905U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 14745U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14615U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCarry, 34U)) + (RotL64(aCross, 19U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterB = (((aWandererI + RotL64(aIngress, 39U)) + RotL64(aCarry, 39U)) + 10915618884692072446U) + aNonceWordE;
            aOrbiterC = (((aWandererJ + RotL64(aScatter, 26U)) + 12634922308499254909U) + aPhaseAOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1]) + aNonceWordN;
            aOrbiterK = ((aWandererD + RotL64(aCross, 13U)) + RotL64(aCarry, 5U)) + 6533934734564499389U;
            aOrbiterJ = (((aWandererG + RotL64(aPrevious, 47U)) + RotL64(aCarry, 19U)) + 6744203303756105181U) + aPhaseAOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aCross, 57U)) + 13086782386652045658U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 5693840533331397822U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 1803663542535024611U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8511046986156781857U), 21U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterK) + 3597219300593287708U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordC;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 1429753448204448904U;
            aOrbiterJ = RotL64((aOrbiterJ * 10927459251773273143U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 17229017825587322715U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 1137574712801062932U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3645832160939819415U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 2401991077004083378U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 1332473247826139292U) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 15029831858261506447U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 11730946340796899885U) + aNonceWordG;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 15319163439700390962U;
            aOrbiterI = RotL64((aOrbiterI * 1349242001887975499U), 29U);
            //
            aIngress = RotL64(aOrbiterI, 23U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 58U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterI, 57U)) + aOrbiterB) + aNonceWordD);
            aWandererG = aWandererG + ((((RotL64(aCross, 4U) + RotL64(aOrbiterJ, 29U)) + aOrbiterK) + RotL64(aCarry, 57U)) + aNonceWordO);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 51U) + aOrbiterC) + RotL64(aOrbiterB, 12U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 41U)) + aOrbiterK) + RotL64(aCarry, 23U)) + aNonceWordK);
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 39U) + RotL64(aOrbiterK, 3U)) + aOrbiterB) + aNonceWordH) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (RotL64(aWandererJ, 56U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererD, 13U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 20374U)) & S_BLOCK1], 13U) ^ RotL64(aInvestLaneA[((aIndex + 19727U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 20103U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 21261U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16533U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 19U)) ^ (RotL64(aPrevious, 52U) + RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterC = (((aWandererF + RotL64(aScatter, 41U)) + RotL64(aCarry, 53U)) + 12583180859826261500U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aIngress, 51U)) + 9067093488553721468U;
            aOrbiterF = (((aWandererC + RotL64(aPrevious, 19U)) + RotL64(aCarry, 37U)) + 12173106198862881754U) + aNonceWordC;
            aOrbiterD = (((aWandererD + RotL64(aCross, 28U)) + RotL64(aCarry, 21U)) + 11333491014394592654U) + aNonceWordL;
            aOrbiterB = (((aWandererK + RotL64(aScatter, 11U)) + 3511883526940919554U) + aPhaseAOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1]) + aNonceWordI;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 7416810692106273044U) + aNonceWordP;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 8341174972619784110U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17722163445765437279U), 21U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterF) + 2220852854836962979U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1]) + aNonceWordB;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 8090781422229383825U) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 578293950675644397U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 2338801236599102223U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 12484514711848308104U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10364216764253366067U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 13684861340589131816U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 12796636819991873058U;
            aOrbiterH = RotL64((aOrbiterH * 5533508014234835669U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 7634198650894837690U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 10240326122201201762U) ^ aNonceWordJ;
            aOrbiterB = RotL64((aOrbiterB * 8758703497719125901U), 57U);
            //
            aIngress = RotL64(aOrbiterB, 23U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 54U));
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aCross, 13U) + aOrbiterB) + RotL64(aOrbiterD, 30U)) + aNonceWordM);
            aWandererG = aWandererG + (((((RotL64(aScatter, 27U) + aOrbiterH) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 5U)) + aNonceWordK) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 43U) + aOrbiterH) + RotL64(aOrbiterC, 13U)) + aPhaseAWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 53U) + RotL64(aOrbiterF, 39U)) + aOrbiterB) + RotL64(aCarry, 23U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 4U) + RotL64(aOrbiterD, 5U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 4U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 25445U)) & S_BLOCK1], 51U) ^ RotL64(aInvestLaneB[((aIndex + 23871U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 25504U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26618U)) & S_BLOCK1], 42U) ^ RotL64(aInvestLaneA[((aIndex + 24227U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 60U) ^ RotL64(aPrevious, 13U)) ^ (RotL64(aIngress, 27U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterG = (((aWandererA + RotL64(aScatter, 21U)) + RotL64(aCarry, 51U)) + 17454559218352016650U) + aNonceWordL;
            aOrbiterK = (((aWandererF + RotL64(aCross, 5U)) + 8005709669325164803U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordK;
            aOrbiterF = ((((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 39U)) + 13393741948412816357U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterA = (((aWandererE + RotL64(aPrevious, 56U)) + RotL64(aCarry, 11U)) + 3665865624348875553U) + aNonceWordM;
            aOrbiterE = (aWandererH + RotL64(aCross, 47U)) + 8334142570031883436U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 17226066128706139657U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 3319093033121522613U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17961784341097933029U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 6657535603401588798U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 5469746182326331147U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11315450342347794329U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 17846791786050221418U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 15939541003714896288U) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 1400351482213119809U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 12076763190461077406U) + aNonceWordF;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 3594038213596405284U) ^ aNonceWordE;
            aOrbiterA = RotL64((aOrbiterA * 10244002692575821495U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 8301291631324464622U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 8460406137668390582U) ^ aNonceWordN;
            aOrbiterE = RotL64((aOrbiterE * 9117147929757711595U), 29U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 30U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + RotL64(aOrbiterK, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 21U) + aOrbiterG) + RotL64(aOrbiterE, 35U)) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 13U) + RotL64(aOrbiterG, 21U)) + aOrbiterK) + aNonceWordD) + aPhaseAWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 60U) + aOrbiterK) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 5U) + aOrbiterG) + RotL64(aOrbiterA, 11U)) + aNonceWordI) + aPhaseAWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterF, 50U)) + aNonceWordH);
            //
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererA, 27U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 30873U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneA[((aIndex + 32666U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 28286U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31810U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31795U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 18U)) ^ (RotL64(aCarry, 57U) + RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterF = ((((aWandererF + RotL64(aCross, 23U)) + RotL64(aCarry, 57U)) + 13499155707765393469U) + aPhaseAOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 11U)) + 3740324981823726185U) + aNonceWordN;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 52U)) + RotL64(aCarry, 5U)) + 5470765363949735652U;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 43U)) + RotL64(aCarry, 19U)) + 3446436171274452326U;
            aOrbiterA = (((aWandererJ + RotL64(aCross, 3U)) + 1778929412631211933U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordL;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 14666308799855220954U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 4548410236791175055U) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 6822908616815218501U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 5829739767694190372U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 14319231414903675748U;
            aOrbiterF = RotL64((aOrbiterF * 4966501102515775601U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 1513851750246111405U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 1685620217748986019U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9286548037413609445U), 29U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterC) + 16284162182006054402U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordB;
            aOrbiterK = (((aOrbiterK ^ aOrbiterE) ^ 6271539598462003309U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterK = RotL64((aOrbiterK * 13923286694131331137U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 12669312437565969473U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 11894755313393001665U;
            aOrbiterA = RotL64((aOrbiterA * 12556759675372354075U), 47U);
            //
            aIngress = RotL64(aOrbiterK, 27U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterA, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterC, 30U)) + aOrbiterA);
            aWandererK = aWandererK + (((((RotL64(aPrevious, 53U) + RotL64(aOrbiterC, 39U)) + aOrbiterF) + RotL64(aCarry, 47U)) + aNonceWordI) + aPhaseAWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 14U) + RotL64(aOrbiterF, 53U)) + aOrbiterK) + aPhaseAWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 21U)) + aOrbiterE) + RotL64(aCarry, 23U)) + aNonceWordC);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterC, 11U)) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 58U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + RotL64(aWandererB, 23U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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

void TwistExpander_Fencing_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xE68CE6A0F0DB9A7DULL + 0xCF1A4AF35D95724CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xFB0CF9DE7D16008BULL + 0xBFF6DF035A08FEF0ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xA4ABF8A919FC8169ULL + 0xA48ED83E5CB03B16ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xBB4C263371AD68DDULL + 0x9B092D43B5DECA1FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x81F7B7A8F1C78E05ULL + 0x8D8BDDBD590392C4ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xA494E324EF22C5ADULL + 0xCD18EB35AF79F2CEULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xA088DDE60A28990BULL + 0xAA29488DB5E7CF24ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xEE512A55E3546C17ULL + 0xCA59FFFD56A71767ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xA16F9655D11245FFULL + 0xBC845E400A4CBB50ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xEACE98EEDAC4A7A9ULL + 0xC37F66F6CAE21255ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x80F1C6ACA382B5F1ULL + 0xAAB81BD397212F1BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xA5BEB9D3E81B3CCBULL + 0x8A635340D6EBBFA5ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xDA753071B303F6D1ULL + 0x921959064E989287ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xCB48582B7417EFBBULL + 0xA9870D503EF4D011ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x957A9D0C935268AFULL + 0xD3FAEA82BBEF2C68ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x8B4E247FC90C64E1ULL + 0xC4FECD22BB606FB9ULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 8036U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneB[((aIndex + 2167U)) & S_BLOCK1], 24U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 6083U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7972U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 1920U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 2059U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 19U) + RotL64(aCarry, 3U)) ^ (RotL64(aIngress, 54U) ^ RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 23U)) + RotL64(aCarry, 13U)) + 14249093584376402677U;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 4U)) + 8756965951816492264U) + aNonceWordN;
            aOrbiterH = ((aWandererG + RotL64(aCross, 19U)) + 11221139480258176330U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = (aWandererJ + RotL64(aIngress, 11U)) + 17218894445564194851U;
            aOrbiterB = (aWandererC + RotL64(aCross, 29U)) + 8064642692524949490U;
            aOrbiterJ = (aWandererB + RotL64(aIngress, 42U)) + 5822093203710704646U;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 57U)) + 3217799620158102238U) + aPhaseBOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = ((aWandererI + RotL64(aScatter, 53U)) + RotL64(aCarry, 37U)) + 2613757677892120843U;
            aOrbiterA = (((aWandererF + RotL64(aIngress, 37U)) + RotL64(aCarry, 5U)) + 13647481499551657237U) + aNonceWordK;
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 3545714196663685016U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 9735422670576621521U;
            aOrbiterH = RotL64((aOrbiterH * 7276207208162697249U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 3911046580637583767U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 9315984027042049203U;
            aOrbiterB = RotL64((aOrbiterB * 12568550776487242469U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 8926367674641729058U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 11035347490524961446U;
            aOrbiterD = RotL64((aOrbiterD * 10948288997163592463U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 10748158733051120339U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 2467801787989056455U;
            aOrbiterI = RotL64((aOrbiterI * 12621934274702358977U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 9244415080474351390U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 8517784887959492079U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17022899813765884147U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 8409307332803038455U) + aNonceWordO;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 11043806021873232950U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8294888329708842989U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 17512395828450251457U) + aNonceWordP;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 16849067939795823992U;
            aOrbiterA = RotL64((aOrbiterA * 9361991804481514337U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 17541946638063238056U) + aNonceWordG;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 11430501673960586718U;
            aOrbiterG = RotL64((aOrbiterG * 15074409630605450091U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 78307505705383302U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 4834528975263832983U;
            aOrbiterF = RotL64((aOrbiterF * 17245673681686752861U), 13U);
            //
            aIngress = RotL64(aOrbiterA, 51U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterJ, 40U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aIngress, 44U) + RotL64(aOrbiterD, 3U)) + aOrbiterH) + RotL64(aCarry, 51U)) + aPhaseBWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterF, 24U)) + aOrbiterE) + aNonceWordE);
            aWandererF = aWandererF + ((RotL64(aScatter, 53U) + RotL64(aOrbiterF, 41U)) + aOrbiterA);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterA, 57U)) + aNonceWordD);
            aWandererB = aWandererB + (((RotL64(aScatter, 23U) + RotL64(aOrbiterE, 47U)) + aOrbiterG) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 57U) + aOrbiterI) + RotL64(aOrbiterG, 19U)) + aNonceWordC) + aPhaseBWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterJ, 52U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 48U) + RotL64(aOrbiterD, 37U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aPrevious, 19U) + aOrbiterB) + RotL64(aOrbiterE, 11U)) + aNonceWordH);
            //
            aCarry = aCarry + (RotL64(aWandererF, 56U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + RotL64(aWandererG, 27U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 12464U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneC[((aIndex + 12116U)) & S_BLOCK1], 37U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 14292U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 10276U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 8853U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10431U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 15799U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 6U) ^ RotL64(aCross, 57U)) ^ (RotL64(aPrevious, 43U) + RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterA = (((aWandererA + RotL64(aCross, 11U)) + RotL64(aCarry, 21U)) + 3970829908171131502U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = (aWandererD + RotL64(aPrevious, 34U)) + 7040283759419531991U;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 57U)) + 11856292169397052901U) + aNonceWordI;
            aOrbiterB = (aWandererI + RotL64(aIngress, 51U)) + 819598588791819022U;
            aOrbiterG = (aWandererB + RotL64(aPrevious, 27U)) + 2176451710970866848U;
            aOrbiterE = (aWandererE + RotL64(aIngress, 22U)) + 6454704928613390494U;
            aOrbiterH = ((aWandererG + RotL64(aCross, 5U)) + 11792122387218053841U) + aNonceWordP;
            aOrbiterC = (((aWandererH + RotL64(aScatter, 41U)) + RotL64(aCarry, 13U)) + 9254780213489752211U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = (((aWandererC + RotL64(aPrevious, 47U)) + RotL64(aCarry, 51U)) + 16591812589999846482U) + aNonceWordC;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 1471246223935074832U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 1424843083106386453U) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 15020536982657410783U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 1856469958050891629U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 6331743690452052712U;
            aOrbiterE = RotL64((aOrbiterE * 15327924647897459645U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 10351075711345476487U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 9518585245330480185U;
            aOrbiterG = RotL64((aOrbiterG * 3792179827396760391U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 17787514620244712033U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 14182328067398162557U) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 18107337388659070197U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 12798088948801072444U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 9563215159275202323U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7058145016617349141U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 9904919772580498232U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 16579777394992143043U;
            aOrbiterB = RotL64((aOrbiterB * 10516761340320196661U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 6344049286854588503U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 3531503618941046788U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10855385899703024105U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 11334308840132700377U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 11093833870078787770U;
            aOrbiterJ = RotL64((aOrbiterJ * 16105889714648555755U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 3831491136025364271U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterG) ^ 12505259454860591372U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterA = RotL64((aOrbiterA * 6135450888433504093U), 5U);
            //
            aIngress = RotL64(aOrbiterG, 47U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 44U));
            aIngress = aIngress + RotL64(aOrbiterE, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 23U) + aOrbiterH) + RotL64(aOrbiterF, 35U));
            aWandererI = aWandererI + ((RotL64(aCross, 57U) + RotL64(aOrbiterI, 27U)) + aOrbiterG);
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 11U) + aOrbiterB) + RotL64(aOrbiterG, 53U)) + aNonceWordD) + aPhaseBWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterA, 12U)) + RotL64(aCarry, 19U)) + aNonceWordN);
            aWandererD = aWandererD ^ (((RotL64(aCross, 36U) + aOrbiterA) + RotL64(aOrbiterG, 41U)) + aNonceWordG);
            aWandererH = aWandererH + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 57U)) + aOrbiterJ);
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 5U)) + aOrbiterG) + aNonceWordL) + aPhaseBWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterI, 18U)) + RotL64(aCarry, 11U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 40U) + aOrbiterF) + RotL64(aOrbiterE, 47U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 60U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 17010U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((aIndex + 22182U)) & S_BLOCK1], 41U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 21903U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneA[((aIndex + 17811U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18202U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 17821U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 17885U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aPrevious, 52U)) + (RotL64(aCarry, 23U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterF = (aWandererE + RotL64(aScatter, 53U)) + 826930775230515406U;
            aOrbiterA = (aWandererC + RotL64(aIngress, 48U)) + 5137814617363250861U;
            aOrbiterE = (((aWandererK + RotL64(aPrevious, 23U)) + 14761561947426681616U) + aPhaseBOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1]) + aNonceWordF;
            aOrbiterD = ((aWandererJ + RotL64(aCross, 57U)) + RotL64(aCarry, 41U)) + 12773023438753662590U;
            aOrbiterB = (((aWandererI + RotL64(aScatter, 19U)) + RotL64(aCarry, 11U)) + 7331345852207096322U) + aNonceWordI;
            aOrbiterK = ((aWandererA + RotL64(aIngress, 39U)) + RotL64(aCarry, 57U)) + 3899381212671247460U;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 13U)) + 10072004147620068599U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = (aWandererF + RotL64(aCross, 5U)) + 3424585039401897560U;
            aOrbiterJ = (aWandererD + RotL64(aIngress, 44U)) + 8246760141625966321U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 3655992860610853290U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterF) ^ 11154618022505863898U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterE = RotL64((aOrbiterE * 4791494171286145231U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 15629361991059709973U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 10842068502278489664U;
            aOrbiterK = RotL64((aOrbiterK * 17223002513104960799U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 5571312349016336686U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 589313823745748879U;
            aOrbiterC = RotL64((aOrbiterC * 1356685926549786027U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 13633457935771935260U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 12684602052812183096U;
            aOrbiterJ = RotL64((aOrbiterJ * 4689206269919806711U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 5711307583717354204U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 7181854170553728211U;
            aOrbiterG = RotL64((aOrbiterG * 9835601115561325911U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 1884620014396115821U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 1471516373272364262U;
            aOrbiterD = RotL64((aOrbiterD * 5126319375714848029U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 742739371092077733U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterG) ^ 8075893317715227838U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 11208274111743259795U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 8179547722249281263U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 15305282712174742323U;
            aOrbiterB = RotL64((aOrbiterB * 7951986906055462929U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 1430543231751281079U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 14585341768267283387U;
            aOrbiterA = RotL64((aOrbiterA * 313213844964269133U), 43U);
            //
            aIngress = RotL64(aOrbiterJ, 18U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 23U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 42U) + RotL64(aOrbiterC, 47U)) + aOrbiterE) + aNonceWordK);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 23U) + aOrbiterE) + RotL64(aOrbiterA, 36U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 53U) + aOrbiterJ) + RotL64(aOrbiterK, 5U)) + aNonceWordB);
            aWandererI = aWandererI ^ ((RotL64(aCross, 29U) + aOrbiterA) + RotL64(aOrbiterK, 27U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 58U) + aOrbiterJ) + RotL64(aOrbiterF, 11U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 57U)) + aOrbiterA);
            aWandererK = aWandererK + ((((RotL64(aScatter, 37U) + RotL64(aOrbiterD, 40U)) + aOrbiterA) + RotL64(aCarry, 21U)) + aNonceWordC);
            aWandererD = aWandererD ^ ((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterK, 21U));
            aWandererF = aWandererF + (((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterE, 51U)) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 40U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 5U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 26447U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((aIndex + 28561U)) & S_BLOCK1], 56U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 28919U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((aIndex + 29558U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29845U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26831U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 32758U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 10U) + RotL64(aCarry, 23U)) ^ (RotL64(aCross, 37U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterB = ((aWandererE + RotL64(aCross, 23U)) + 785861751704720606U) + aPhaseBOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = (((aWandererB + RotL64(aIngress, 13U)) + RotL64(aCarry, 51U)) + 15968088718435606299U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = (((aWandererF + RotL64(aPrevious, 60U)) + RotL64(aCarry, 37U)) + 1393976526590347151U) + aNonceWordK;
            aOrbiterJ = (aWandererC + RotL64(aScatter, 19U)) + 17240750947292745884U;
            aOrbiterA = (aWandererD + RotL64(aIngress, 43U)) + 4921576136163183137U;
            aOrbiterH = ((aWandererA + RotL64(aCross, 37U)) + RotL64(aCarry, 3U)) + 3334047873553153032U;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 56U)) + 15086509978458408698U) + aNonceWordJ;
            aOrbiterD = (aWandererI + RotL64(aPrevious, 27U)) + 892391205397581998U;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 47U)) + 2965686403183767521U) + aNonceWordF;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 14632215393655706170U) + aNonceWordN;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 15740589515342377322U;
            aOrbiterF = RotL64((aOrbiterF * 15677716942904794913U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 11131164813943086445U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 6988080581278900960U;
            aOrbiterA = RotL64((aOrbiterA * 6412189142344044255U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 16021254613117657178U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 6183615599897921154U;
            aOrbiterH = RotL64((aOrbiterH * 9976411093264211033U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 12533992547026652747U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 3104325358982904219U;
            aOrbiterD = RotL64((aOrbiterD * 14977348108778147265U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 3878525937957474644U) + aNonceWordO;
            aOrbiterB = (((aOrbiterB ^ aOrbiterH) ^ 2120435259884368445U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterB = RotL64((aOrbiterB * 15964718652193073177U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 14928658302694194856U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 9121310461310309348U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17304439784647477491U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 3715693239100476493U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 7336577492932262490U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11074754160002665253U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 2312452827448455675U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 4322756069651934618U) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 6908893297397073539U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 4962079617577705818U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 5072727464750706525U;
            aOrbiterC = RotL64((aOrbiterC * 4947670001221089155U), 27U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 30U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 27U));
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 20U) + aOrbiterH) + RotL64(aOrbiterF, 58U)) + aNonceWordG);
            aWandererE = aWandererE ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterG, 43U)) + aOrbiterI);
            aWandererK = aWandererK + (((RotL64(aPrevious, 35U) + aOrbiterD) + RotL64(aOrbiterH, 11U)) + aNonceWordA);
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 23U)) + aOrbiterA) + aNonceWordB) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 51U) + RotL64(aOrbiterF, 6U)) + aOrbiterB) + RotL64(aCarry, 21U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterH, 51U)) + aPhaseBWandererUpdateSaltA[((aIndex + 20U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 5U) + RotL64(aOrbiterI, 29U)) + aOrbiterD);
            aWandererB = aWandererB ^ (((RotL64(aCross, 11U) + aOrbiterC) + RotL64(aOrbiterH, 19U)) + aNonceWordD);
            aWandererI = aWandererI + (((RotL64(aIngress, 44U) + RotL64(aOrbiterA, 37U)) + aOrbiterJ) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 44U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 37U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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

void TwistExpander_Fencing_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xADCD8970F6C421A3ULL + 0xAA9A2AEAC905425FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xC3E283538739508FULL + 0xCDC5503FD5453718ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xDCF80241FA969EC1ULL + 0xE7210FD02A1FF8D5ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xDCDC6615ABA154BDULL + 0xC71C3B6227BFBDB1ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x97569DA2CF9F605BULL + 0xCB44ACC4572E502EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xFD4D56BC18D6F421ULL + 0xE194CC62D1A11C5EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xB5ED44D6CFBB4CAFULL + 0xC52E3D95CF7ADC79ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xDCA2CCCF9DF14659ULL + 0x90E194792011E45DULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xCBE88724D69CB66DULL + 0xB28EDC0A67F7610CULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xBED9E62053BA3FB5ULL + 0x9EAFAAA5C5968DEBULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xB1CC36AC44AF4F99ULL + 0xB5B17E2E12D6C281ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xD894365E12FF6843ULL + 0x82DE745AFD010ECBULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x9836B5C017EC5DDBULL + 0xB08EB101E0DF5276ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xB53BD9977144C84BULL + 0xA0601510328C7BF6ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x9631027976B778C5ULL + 0x891C90C5EFF0AA9FULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x92F171A08298205BULL + 0xE2148E3D89926192ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 2065U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((aIndex + 2696U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 3276U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3688U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3516U)) & S_BLOCK1], 58U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 3926U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCarry, 52U)) ^ (RotL64(aIngress, 21U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterA = ((aWandererI + RotL64(aCross, 21U)) + 13333509828310369865U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aIngress, 11U)) + 7645352517103840797U;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 53U)) + 5310766306660062655U;
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 5U)) + RotL64(aCarry, 27U)) + 5165635069832352932U;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 34U)) + 15684141764734281849U) + aNonceWordD;
            aOrbiterJ = ((((aWandererK + RotL64(aCross, 47U)) + RotL64(aCarry, 11U)) + 3327963374225061738U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 27U)) + RotL64(aCarry, 51U)) + 8625811794878848871U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 7598657468430485291U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterA) ^ 2881171216276746485U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterI = RotL64((aOrbiterI * 3331350584102843605U), 5U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterA) + 10237691227222918101U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1]) + aNonceWordP;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 6419254255884834497U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3816625473642865305U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 4238455444646479956U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 14936613353493061492U;
            aOrbiterA = RotL64((aOrbiterA * 3544216916806292273U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 15324699725208372627U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 9506640480601832011U) ^ aNonceWordJ;
            aOrbiterE = RotL64((aOrbiterE * 12819564111348390227U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 3709149613660215641U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 1724290199312754307U;
            aOrbiterJ = RotL64((aOrbiterJ * 12597580418257897965U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 13191172833570139194U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 3686087945377837886U;
            aOrbiterD = RotL64((aOrbiterD * 10883609557429936283U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 10418330386245397022U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 5383531313632347245U;
            aOrbiterB = RotL64((aOrbiterB * 2987755379396160073U), 23U);
            //
            aIngress = RotL64(aOrbiterE, 13U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + RotL64(aOrbiterB, 36U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 27U) + aOrbiterA) + RotL64(aOrbiterI, 23U));
            aWandererD = aWandererD + ((RotL64(aScatter, 57U) + aOrbiterJ) + RotL64(aOrbiterD, 57U));
            aWandererA = aWandererA ^ ((((RotL64(aCross, 11U) + RotL64(aOrbiterB, 47U)) + aOrbiterA) + aNonceWordB) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 35U) + aOrbiterF) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 50U) + RotL64(aOrbiterA, 40U)) + aOrbiterE);
            aWandererF = aWandererF + (((((RotL64(aIngress, 41U) + RotL64(aOrbiterD, 11U)) + aOrbiterE) + RotL64(aCarry, 43U)) + aNonceWordA) + aPhaseDWandererUpdateSaltD[((aIndex + 4U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 29U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 18U));
            aCarry = aCarry + RotL64(aWandererA, 39U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 9002U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneC[((aIndex + 6243U)) & S_BLOCK1], 51U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 10125U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneC[((aIndex + 9321U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9031U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6936U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 8323U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCross, 54U)) ^ (RotL64(aCarry, 3U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterK = ((aWandererB + RotL64(aCross, 47U)) + RotL64(aCarry, 51U)) + 1457104756581596530U;
            aOrbiterC = (aWandererE + RotL64(aIngress, 23U)) + 6127240317844622874U;
            aOrbiterB = (((aWandererI + RotL64(aPrevious, 29U)) + 16492290056044189421U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordD;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 53U)) + RotL64(aCarry, 35U)) + 10963676850938416468U;
            aOrbiterH = (((aWandererH + RotL64(aPrevious, 5U)) + RotL64(aCarry, 5U)) + 4872917367399752405U) + aPhaseDOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aScatter, 14U)) + 15218882377875616148U;
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 35U)) + 5934166612122118251U) + aNonceWordJ;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 14215280930872003003U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 11428034799044600979U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12162528943733976177U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 5453003654321728726U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 14273775120265649389U;
            aOrbiterH = RotL64((aOrbiterH * 5139018128323795309U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 328723770018440271U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 13032190719588211088U) ^ aNonceWordC;
            aOrbiterC = RotL64((aOrbiterC * 13363368478932798315U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 2386881543033598494U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 1649501123340887116U;
            aOrbiterD = RotL64((aOrbiterD * 11148976582360499033U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 16462401546754210583U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 1510579201823042227U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16287912400104043275U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 6889066000014251983U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 11324594596597724357U) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 15344987814648586023U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 12237796033168436537U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 17306069670330000343U;
            aOrbiterF = RotL64((aOrbiterF * 3167451351403385259U), 57U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterD, 19U);
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterE, 40U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aScatter, 20U) + RotL64(aOrbiterD, 29U)) + aOrbiterF);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterB, 6U)) + aOrbiterE);
            aWandererH = aWandererH + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 19U)) + aOrbiterK) + aNonceWordG) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 57U) + aOrbiterF) + RotL64(aOrbiterC, 13U));
            aWandererB = aWandererB + (((((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 35U)) + aOrbiterE) + RotL64(aCarry, 39U)) + aNonceWordP) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterF, 47U)) + aNonceWordM);
            aWandererK = aWandererK + (((RotL64(aPrevious, 51U) + aOrbiterC) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 34U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 15738U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneA[((aIndex + 14086U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 15030U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13573U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13372U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCarry, 5U)) + (RotL64(aCross, 56U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterB = ((aWandererA + RotL64(aIngress, 57U)) + 10812151398716051703U) + aNonceWordB;
            aOrbiterE = (aWandererB + RotL64(aScatter, 11U)) + 18202551453336003710U;
            aOrbiterJ = (((aWandererH + RotL64(aPrevious, 37U)) + 9434410809101973752U) + aPhaseDOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1]) + aNonceWordE;
            aOrbiterA = ((aWandererE + RotL64(aCross, 23U)) + 12955829998028534045U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 30U)) + RotL64(aCarry, 57U)) + 12271740641929640181U;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 47U)) + RotL64(aCarry, 29U)) + 14009351527014534752U;
            aOrbiterI = (((aWandererJ + RotL64(aCross, 5U)) + RotL64(aCarry, 41U)) + 4316296955679133450U) + aNonceWordI;
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 16473324966997442872U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 15735123324965019802U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5624078184997601019U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 17656375090484080236U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 16066325053456055298U;
            aOrbiterB = RotL64((aOrbiterB * 17912970706985130327U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 12908968778503516903U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 12761433987676836197U) ^ aNonceWordL;
            aOrbiterG = RotL64((aOrbiterG * 1023329467480907925U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 12737513138040664509U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 14535795767570998392U;
            aOrbiterH = RotL64((aOrbiterH * 15560519667062222269U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 14370908061811284364U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 7001358781208669795U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11641248025734015835U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 7298578161120090849U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 10498302152357484629U;
            aOrbiterE = RotL64((aOrbiterE * 13144110412179037175U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 11447343228638006767U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterG) ^ 18284143620422655675U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterA = RotL64((aOrbiterA * 572862190073605651U), 19U);
            //
            aIngress = RotL64(aOrbiterB, 57U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + RotL64(aOrbiterG, 26U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 27U)) + aOrbiterG);
            aWandererI = aWandererI + (((((RotL64(aScatter, 13U) + aOrbiterJ) + RotL64(aOrbiterE, 51U)) + RotL64(aCarry, 41U)) + aNonceWordH) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterG, 44U)) + aOrbiterE) + aPhaseDWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 35U)) + aOrbiterG) + RotL64(aCarry, 19U)) + aNonceWordA);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterJ, 3U)) + aNonceWordK);
            aWandererE = aWandererE + ((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterI, 57U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 48U) + RotL64(aOrbiterH, 21U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererI, 60U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 16802U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((aIndex + 17246U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 18134U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18741U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneD[((aIndex + 17968U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aIngress, 37U) ^ RotL64(aCarry, 21U)) + (RotL64(aPrevious, 3U) + RotL64(aCross, 52U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterG = ((aWandererB + RotL64(aCross, 53U)) + RotL64(aCarry, 23U)) + 8975885703279267062U;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 5U)) + 8664844915562660637U) + aNonceWordG;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 22U)) + RotL64(aCarry, 39U)) + 12281774799736296726U;
            aOrbiterJ = (((aWandererF + RotL64(aIngress, 47U)) + RotL64(aCarry, 5U)) + 15347461352311329726U) + aPhaseDOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 11U)) + 12967500561828907834U) + aNonceWordB;
            aOrbiterF = (aWandererI + RotL64(aScatter, 29U)) + 5002833859280402726U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 37U)) + 11908257536954668983U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 17017174811949227162U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 16851323125613931180U;
            aOrbiterD = RotL64((aOrbiterD * 12446990992858763577U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 13469326957728686706U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 5228638551056105241U;
            aOrbiterG = RotL64((aOrbiterG * 13369947664646167255U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 11945166198089308564U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 16268645041872996022U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5391448793718370911U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 14781204627695095701U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 5365325354838101092U;
            aOrbiterF = RotL64((aOrbiterF * 8017284997946310807U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 563147416025715953U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 14660867395395625851U) ^ aNonceWordL;
            aOrbiterJ = RotL64((aOrbiterJ * 4769458126865307103U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 3168989056355712105U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 16179131669773665579U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5641461617066671723U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 4160220074225527179U) + aNonceWordD;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 8597134686962559111U;
            aOrbiterK = RotL64((aOrbiterK * 639572585431474015U), 3U);
            //
            aIngress = RotL64(aOrbiterK, 47U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + RotL64(aOrbiterG, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterA, 21U)) + aOrbiterJ);
            aWandererI = aWandererI + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 3U)) + aOrbiterD) + RotL64(aCarry, 3U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterD, 29U)) + aOrbiterF) + aNonceWordF);
            aWandererF = aWandererF + ((RotL64(aCross, 22U) + RotL64(aOrbiterG, 47U)) + aOrbiterK);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 29U) + aOrbiterK) + RotL64(aOrbiterI, 14U)) + aNonceWordN);
            aWandererH = aWandererH + (((RotL64(aCross, 37U) + RotL64(aOrbiterD, 37U)) + aOrbiterA) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 43U) + aOrbiterK) + RotL64(aOrbiterJ, 53U)) + aPhaseDWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 18U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 51U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 25112U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneB[((aIndex + 26409U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 24486U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 27085U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23724U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aPrevious, 19U)) + (RotL64(aIngress, 41U) + RotL64(aCarry, 4U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterG = (aWandererK + RotL64(aIngress, 39U)) + 15652862298542575895U;
            aOrbiterH = (((aWandererE + RotL64(aScatter, 29U)) + 16925323928418184554U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordB;
            aOrbiterK = ((aWandererD + RotL64(aCross, 21U)) + 4413861484961668394U) + aPhaseDOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 47U)) + RotL64(aCarry, 57U)) + 2215946422098155969U;
            aOrbiterB = (((aWandererI + RotL64(aScatter, 3U)) + RotL64(aCarry, 29U)) + 14975185533513111110U) + aNonceWordL;
            aOrbiterI = (aWandererG + RotL64(aCross, 53U)) + 9711613814905834552U;
            aOrbiterF = (((aWandererF + RotL64(aIngress, 14U)) + RotL64(aCarry, 11U)) + 13154957291850149471U) + aNonceWordD;
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 5058313016418534840U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 15011423472941211620U;
            aOrbiterK = RotL64((aOrbiterK * 6125316151731105673U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 2030053257469580168U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 150530795186791193U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11106050063717096073U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 10878237472104183427U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 11724672539469573109U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16158741837357985395U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 9589700906445846956U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 1367381624958248949U) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 8459515089081211977U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 12003215666757518106U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 11232479330848006729U) ^ aNonceWordN;
            aOrbiterI = RotL64((aOrbiterI * 10993290955464593033U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 13013910456628561621U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 6092509838924105265U;
            aOrbiterG = RotL64((aOrbiterG * 805601154718006061U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 11999225836250312801U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 14421271973875748413U;
            aOrbiterF = RotL64((aOrbiterF * 9529010940887430157U), 19U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 14U);
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 27U));
            aIngress = aIngress + RotL64(aOrbiterI, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aCross, 35U) + aOrbiterH) + RotL64(aOrbiterG, 27U));
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 27U) + aOrbiterI) + RotL64(aOrbiterG, 19U)) + aNonceWordI) + aPhaseDWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 43U) + aOrbiterB) + RotL64(aOrbiterK, 37U)) + RotL64(aCarry, 21U)) + aNonceWordE);
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 19U) + RotL64(aOrbiterB, 13U)) + aOrbiterF) + aNonceWordH) + aPhaseDWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 58U) + RotL64(aOrbiterI, 43U)) + aOrbiterH) + RotL64(aCarry, 47U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterH, 53U));
            aWandererG = aWandererG + (((RotL64(aScatter, 11U) + aOrbiterC) + RotL64(aOrbiterG, 60U)) + aNonceWordO);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 22U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + RotL64(aWandererE, 3U);
            aCarry = aCarry + RotL64(aIngress, 12U);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 30115U)) & S_BLOCK1], 11U) ^ RotL64(aInvestLaneA[((aIndex + 27865U)) & S_BLOCK1], 28U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 31852U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 29481U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((aIndex + 27510U)) & S_BLOCK1], 40U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aPrevious, 35U)) ^ (RotL64(aIngress, 11U) + RotL64(aCarry, 56U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterI = (((aWandererI + RotL64(aPrevious, 29U)) + RotL64(aCarry, 21U)) + 9133751643283278896U) + aNonceWordA;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 19U)) + 8971581804375380408U) + aNonceWordN;
            aOrbiterF = (((aWandererA + RotL64(aScatter, 3U)) + RotL64(aCarry, 39U)) + 12559650383714566592U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = (((aWandererG + RotL64(aCross, 51U)) + RotL64(aCarry, 3U)) + 15753206088872859163U) + aNonceWordP;
            aOrbiterH = ((aWandererH + RotL64(aIngress, 13U)) + 7640756270450762350U) + aPhaseDOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = (aWandererE + RotL64(aScatter, 37U)) + 7340073357551376125U;
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 58U)) + 5270256573644196046U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 3567367996479995928U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 11939634537492733738U;
            aOrbiterF = RotL64((aOrbiterF * 5640541900117183639U), 47U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterD) + 7051817732424527120U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordD;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 1730487669951837941U;
            aOrbiterH = RotL64((aOrbiterH * 15191634337956285841U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 18009252467909454817U) + aNonceWordL;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 2361024272031696442U;
            aOrbiterB = RotL64((aOrbiterB * 15215151562500226027U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 15902755877642960397U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 12243517544704116184U;
            aOrbiterC = RotL64((aOrbiterC * 2576071074148141447U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 16846181962302186187U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 636121425116506681U) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 17075030673338779993U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 6887385655828217318U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 3705834550934775862U;
            aOrbiterA = RotL64((aOrbiterA * 11275428284929594435U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 11165142437077969438U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 6426659930331618269U;
            aOrbiterD = RotL64((aOrbiterD * 17170640810530893705U), 53U);
            //
            aIngress = RotL64(aOrbiterI, 27U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 18U) + aOrbiterB) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterB, 35U)) + aOrbiterC);
            aWandererB = aWandererB + ((RotL64(aScatter, 5U) + aOrbiterC) + RotL64(aOrbiterD, 41U));
            aWandererH = aWandererH ^ ((((RotL64(aCross, 11U) + aOrbiterI) + RotL64(aOrbiterC, 13U)) + aNonceWordF) + aPhaseDWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterH, 47U)) + aNonceWordM) + aPhaseDWandererUpdateSaltA[((aIndex + 20U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterA, 53U)) + aOrbiterH);
            aWandererG = aWandererG + (((RotL64(aIngress, 51U) + RotL64(aOrbiterF, 6U)) + aOrbiterH) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 58U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 39U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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

void TwistExpander_Fencing_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xB9F43EAB9D63069FULL + 0xDD95B7EE1EC0556AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xC8B939F0F6F973FBULL + 0xC124197197FD35F4ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x92F2D9158E2CA351ULL + 0xF8A5729DB6362C9DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB2B25DCEA71F58D3ULL + 0xA1969F0E2E28E7BBULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xA549F1985862770DULL + 0xBC7BA86001750D03ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xBD2DB8E6F86FBC49ULL + 0xDED5D5A6BA060B9BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xB7E87B1241E20BA1ULL + 0x886A746043E0D7FBULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x88D572E74FF0F7AFULL + 0xE62A6AE9D01F5B0AULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xDFE7F91149E416CBULL + 0xF8D3F27ADEF036F5ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x9BC25A347A20634BULL + 0xCDDC8C8F9182B47DULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x9C9829CD60959495ULL + 0x978F238E99BE6CD2ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x918CD20779F6E81FULL + 0xDCCD6957B63245C1ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xDCFBED6BACAA0B69ULL + 0xC59C3521888BD3BFULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xBDD1EC9EE0C57437ULL + 0xC1E0F42337E83628ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xACB2912AFAC4BC87ULL + 0xED3697860CA8505CULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xA1D90D4D7DAE041FULL + 0xB61C6A6F9F8492DBULL);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 3414U)) & S_BLOCK1], 37U) ^ RotL64(aInvestLaneB[((aIndex + 5203U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 25U)) & S_BLOCK1], 6U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 2991U)) & S_BLOCK1], 21U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 1993U)) & S_BLOCK1], 48U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 2404U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCross, 23U)) ^ (RotL64(aPrevious, 48U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterD = (((aWandererH + RotL64(aPrevious, 47U)) + RotL64(aCarry, 53U)) + 16451272412693907816U) + aNonceWordI;
            aOrbiterH = (aWandererA + RotL64(aIngress, 41U)) + 10099485419723255462U;
            aOrbiterB = ((aWandererK + RotL64(aScatter, 57U)) + 17668900099534923192U) + aPhaseEOrbiterAssignSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = (aWandererB + RotL64(aCross, 23U)) + 5497093724143181753U;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 28U)) + RotL64(aCarry, 39U)) + 10354044773550071706U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 3U)) + 12728258851198019099U) + aNonceWordL;
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 35U)) + 4144050505314242618U;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 21U)) + RotL64(aCarry, 47U)) + 14133805325480076530U;
            aOrbiterK = (aWandererD + RotL64(aIngress, 19U)) + 308863673210602899U;
            aOrbiterI = (aWandererE + RotL64(aScatter, 37U)) + 11741180130160569753U;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 12U)) + 12926863156769180448U) + aPhaseEOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 211920854786494259U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 13234608842479411078U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2556747209733759467U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 9164711974854618892U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 6667377062281954219U;
            aOrbiterH = RotL64((aOrbiterH * 2603737166987437649U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 4559040002406721850U) + aNonceWordA;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 1749875480850675109U;
            aOrbiterJ = RotL64((aOrbiterJ * 15822640067349481089U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 9555365165561936366U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 18289733999504213574U;
            aOrbiterK = RotL64((aOrbiterK * 14156217554673229429U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 8727162691639622461U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 291406782452963706U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8413500075082350243U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 8294911802626492257U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 15853578397277298548U;
            aOrbiterG = RotL64((aOrbiterG * 13256191781365357747U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 11535146194939658681U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 2177540476748375661U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15791341922007841029U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 2705306323728084136U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 17617871830709148043U;
            aOrbiterC = RotL64((aOrbiterC * 3449981219502809255U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 3699834746313613206U) + aNonceWordN;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 17952609181629473245U;
            aOrbiterI = RotL64((aOrbiterI * 6103160209028988839U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 8016694658897707674U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 6971251395823324489U;
            aOrbiterA = RotL64((aOrbiterA * 13483776115929040277U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 17467528888050817915U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 16451272412693907816U;
            aOrbiterF = RotL64((aOrbiterF * 13689734638238895071U), 5U);
            //
            aIngress = RotL64(aOrbiterA, 47U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 53U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 10U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + RotL64(aOrbiterI, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterJ, 14U)) + aOrbiterK) + aNonceWordB);
            aWandererB = aWandererB + (((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterD, 51U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 18U) + RotL64(aOrbiterJ, 35U)) + aOrbiterF);
            aWandererI = aWandererI + ((RotL64(aPrevious, 29U) + aOrbiterA) + RotL64(aOrbiterF, 27U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 27U) + aOrbiterG) + RotL64(aOrbiterH, 57U)) + aNonceWordM);
            aWandererE = aWandererE + (((RotL64(aIngress, 21U) + RotL64(aOrbiterB, 37U)) + aOrbiterF) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 34U) + RotL64(aOrbiterG, 47U)) + aOrbiterE);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterD, 40U)) + RotL64(aCarry, 37U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 57U) + aOrbiterF) + RotL64(aOrbiterK, 29U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 23U)) + aOrbiterG);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterC, 21U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererI, 4U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererD, 60U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 8102U)) & S_BLOCK1], 47U) ^ RotL64(aInvestLaneC[((aIndex + 7505U)) & S_BLOCK1], 39U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 8316U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneC[((aIndex + 10654U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 5893U)) & S_BLOCK1], 47U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 6489U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 8124U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCross, 5U)) + (RotL64(aIngress, 23U) ^ RotL64(aCarry, 52U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 46U)) + RotL64(aCarry, 23U)) + 6318740973868639425U;
            aOrbiterE = (aWandererI + RotL64(aCross, 41U)) + 5487840061430920881U;
            aOrbiterC = ((((aWandererB + RotL64(aIngress, 21U)) + RotL64(aCarry, 29U)) + 10258706763248072672U) + aPhaseEOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1]) + aNonceWordF;
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 23U)) + 18356875269730338208U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aCross, 60U)) + 12883160282903147010U;
            aOrbiterA = (aWandererA + RotL64(aScatter, 11U)) + 1010140474942697730U;
            aOrbiterG = (aWandererE + RotL64(aPrevious, 27U)) + 17733939421700898293U;
            aOrbiterH = (aWandererK + RotL64(aIngress, 39U)) + 13693055887924981201U;
            aOrbiterF = ((aWandererG + RotL64(aCross, 29U)) + 14574732452793385269U) + aNonceWordC;
            aOrbiterB = (((aWandererH + RotL64(aScatter, 35U)) + RotL64(aCarry, 5U)) + 10832873941223609012U) + aNonceWordA;
            aOrbiterI = (aWandererJ + RotL64(aIngress, 53U)) + 8212600587135328040U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 5312744319781971178U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 6173741211706546923U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12854414066390848249U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 3693249147883790810U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 18365859989736602556U;
            aOrbiterK = RotL64((aOrbiterK * 3348463719324104997U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 10645056678337549771U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 1175668356822251045U) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 6579675292775345579U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 13556844570541823717U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 4790355739411849736U;
            aOrbiterF = RotL64((aOrbiterF * 4083544011788850307U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 14905575502272644116U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 17047244574558476634U;
            aOrbiterD = RotL64((aOrbiterD * 2356386971503880047U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 10161614295718414869U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 13413914082651612468U;
            aOrbiterA = RotL64((aOrbiterA * 16224039093981079491U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 6072693130156927774U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 4333656233793103787U) ^ aNonceWordD;
            aOrbiterH = RotL64((aOrbiterH * 9374745547133955709U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 17209776289202130250U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 11752001118070361543U;
            aOrbiterG = RotL64((aOrbiterG * 4416523594812872339U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 15367365111105608277U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 8650687767097460704U;
            aOrbiterB = RotL64((aOrbiterB * 11430451559660578667U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 18074648514448405693U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 10857586858462237581U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3722891011080095849U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 17219932344278345591U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 6318740973868639425U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8846295038878812229U), 57U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 47U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + (RotL64(aOrbiterI, 60U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + RotL64(aOrbiterC, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 19U) + aOrbiterJ) + RotL64(aOrbiterC, 30U)) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 34U) + RotL64(aOrbiterF, 35U)) + aOrbiterK);
            aWandererG = aWandererG + ((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 3U)) + aOrbiterJ);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 29U) + aOrbiterJ) + RotL64(aOrbiterB, 53U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterB, 13U)) + aOrbiterE);
            aWandererH = aWandererH ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterF, 5U)) + aOrbiterB);
            aWandererC = aWandererC + (((RotL64(aIngress, 27U) + RotL64(aOrbiterF, 43U)) + aOrbiterG) + RotL64(aCarry, 23U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 39U)) + aOrbiterA);
            aWandererI = aWandererI + (((RotL64(aPrevious, 11U) + aOrbiterH) + RotL64(aOrbiterD, 48U)) + aPhaseEWandererUpdateSaltC[((aIndex + 12U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 37U) + aOrbiterD) + RotL64(aOrbiterK, 51U)) + aNonceWordG);
            aWandererB = aWandererB + ((((RotL64(aIngress, 6U) + RotL64(aOrbiterI, 27U)) + aOrbiterC) + aNonceWordM) + aPhaseEWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 24U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 14U);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 16139U)) & S_BLOCK1], 19U) ^ RotL64(aInvestLaneA[((aIndex + 11323U)) & S_BLOCK1], 40U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12971U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 15058U)) & S_BLOCK1], 35U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 14782U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aIngress, 39U)) ^ (RotL64(aPrevious, 26U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterD = (((aWandererI + RotL64(aIngress, 18U)) + 13296600294247799698U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 11U)) + 5818503518080877515U) + aNonceWordB;
            aOrbiterB = (aWandererD + RotL64(aCross, 13U)) + 6735784238734173597U;
            aOrbiterA = (aWandererC + RotL64(aPrevious, 53U)) + 7368398209488856201U;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 27U)) + RotL64(aCarry, 41U)) + 961734029066455638U;
            aOrbiterE = (aWandererH + RotL64(aCross, 51U)) + 797011946660892011U;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 3U)) + RotL64(aCarry, 21U)) + 12841876018396622350U;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 47U)) + 16213253970483895623U;
            aOrbiterK = (aWandererJ + RotL64(aScatter, 35U)) + 15186950557113470375U;
            aOrbiterF = (aWandererE + RotL64(aIngress, 60U)) + 5117930310827477341U;
            aOrbiterC = ((((aWandererB + RotL64(aPrevious, 43U)) + RotL64(aCarry, 37U)) + 12265429373166094162U) + aPhaseEOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1]) + aNonceWordO;
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 13920531346698601568U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 14695405206998211456U;
            aOrbiterB = RotL64((aOrbiterB * 13950964363414164279U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 7851960904825938443U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 9501511171732550190U;
            aOrbiterH = RotL64((aOrbiterH * 5614164120361489613U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 5663365182245722077U) + aNonceWordC;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 9607860124321315555U) ^ aNonceWordF;
            aOrbiterG = RotL64((aOrbiterG * 3461820361914280601U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 18171052650586819280U) + aNonceWordH;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 3442698321538580861U;
            aOrbiterK = RotL64((aOrbiterK * 6317525514963824829U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 1491052813469258970U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 3956599824067616133U;
            aOrbiterI = RotL64((aOrbiterI * 2928600779267623085U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 10963841237346073453U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 2303020125591252534U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9969099842343321981U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 14503856057958162356U) + aNonceWordN;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 11147548150090597694U;
            aOrbiterE = RotL64((aOrbiterE * 11856382308792700441U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 9191681438318311481U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 13556072770381999852U;
            aOrbiterF = RotL64((aOrbiterF * 18316231099054203683U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 10103207278550444685U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 10415809965217261104U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16562732599511350217U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 17435033201864058457U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 5540494424887364682U;
            aOrbiterC = RotL64((aOrbiterC * 18230910315317249045U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 18020151683897013854U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 13296600294247799698U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10000194329456668845U), 51U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterD, 35U);
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 60U));
            aIngress = aIngress + (RotL64(aOrbiterI, 39U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 14U) + RotL64(aOrbiterF, 3U)) + aOrbiterA) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ ((((RotL64(aCross, 37U) + RotL64(aOrbiterG, 47U)) + aOrbiterI) + aNonceWordE) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 51U) + RotL64(aOrbiterK, 35U)) + aOrbiterD);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 27U) + aOrbiterB) + RotL64(aOrbiterA, 56U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 34U) + RotL64(aOrbiterH, 23U)) + aOrbiterJ);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 41U)) + aOrbiterG);
            aWandererB = aWandererB + (((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterJ, 19U)) + aNonceWordA);
            aWandererG = aWandererG ^ (((RotL64(aCross, 43U) + aOrbiterB) + RotL64(aOrbiterK, 51U)) + aPhaseEWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterA, 5U)) + aOrbiterE) + RotL64(aCarry, 53U)) + aNonceWordD);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterK, 12U)) + aOrbiterC) + aNonceWordL);
            aWandererA = aWandererA + ((RotL64(aScatter, 11U) + RotL64(aOrbiterC, 37U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererG, 54U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + RotL64(aWandererB, 6U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 19362U)) & S_BLOCK1], 47U) ^ RotL64(aSnowLaneA[((aIndex + 18825U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 18831U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 21829U)) & S_BLOCK1], 26U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 17562U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 58U) + RotL64(aIngress, 11U)) ^ (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterG = (aWandererG + RotL64(aCross, 41U)) + 14823268998003220191U;
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 29U)) + 15295237288788213847U;
            aOrbiterE = (aWandererH + RotL64(aScatter, 43U)) + 16434853402001133899U;
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 14U)) + 7555911304407871631U) + aPhaseEOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 27U)) + RotL64(aCarry, 53U)) + 14977248264994834620U;
            aOrbiterC = ((aWandererA + RotL64(aCross, 3U)) + 9707764144919392380U) + aNonceWordC;
            aOrbiterA = (aWandererC + RotL64(aIngress, 39U)) + 1277304385464681529U;
            aOrbiterD = (((aWandererF + RotL64(aScatter, 60U)) + 3089786220465849395U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordH;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 21U)) + RotL64(aCarry, 23U)) + 3700503853358695085U;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 57U)) + 3240054112993517371U) + aNonceWordO;
            aOrbiterK = (((aWandererI + RotL64(aScatter, 11U)) + RotL64(aCarry, 47U)) + 16897532076915366859U) + aNonceWordN;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 18167359289798364307U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 8870819278575769863U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9334066154398059075U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 15363069206212330251U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 14858164441499725158U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14931933411393847915U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 5357144808788707522U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 2910681277417754860U;
            aOrbiterD = RotL64((aOrbiterD * 13170868582159347059U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 9824408699018165151U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 368370224788793300U;
            aOrbiterJ = RotL64((aOrbiterJ * 14358982366258729959U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 7095398304588825115U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 11418879758164313554U) ^ aNonceWordK;
            aOrbiterH = RotL64((aOrbiterH * 5983520332639771791U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 2171599720681913272U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 17593730219647495033U;
            aOrbiterG = RotL64((aOrbiterG * 12926053208918563087U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 17755947635188715523U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 14565740605227022106U) ^ aNonceWordL;
            aOrbiterK = RotL64((aOrbiterK * 15866418354612945335U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 14538017880915584414U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 6174566474851449123U;
            aOrbiterA = RotL64((aOrbiterA * 179569008593475683U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 3806438394748643441U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 13737114463856719285U;
            aOrbiterF = RotL64((aOrbiterF * 13439346068497710151U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 3698379331577470045U) + aNonceWordM;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 1097081284062708554U) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 3498627643013255777U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 215117138867597766U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 14823268998003220191U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12131828437975771377U), 51U);
            //
            aIngress = RotL64(aOrbiterI, 23U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 34U));
            aIngress = aIngress + RotL64(aOrbiterE, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterK, 37U)) + aOrbiterD) + RotL64(aCarry, 21U)) + aNonceWordJ);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 26U) + aOrbiterF) + RotL64(aOrbiterD, 3U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterG, 26U)) + aNonceWordA) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 43U) + aOrbiterB) + RotL64(aOrbiterK, 39U)) + aPhaseEWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterE, 53U)) + aOrbiterF) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 5U) + aOrbiterI) + RotL64(aOrbiterE, 57U));
            aWandererE = aWandererE + ((RotL64(aCross, 3U) + RotL64(aOrbiterD, 21U)) + aOrbiterA);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterK, 51U)) + aOrbiterC) + aNonceWordD);
            aWandererI = aWandererI + ((RotL64(aCross, 23U) + RotL64(aOrbiterC, 35U)) + aOrbiterD);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 47U) + aOrbiterB) + RotL64(aOrbiterH, 41U));
            aWandererF = aWandererF + ((RotL64(aIngress, 38U) + RotL64(aOrbiterH, 14U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + (RotL64(aWandererJ, 42U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + RotL64(aWandererE, 37U);
            aCarry = aCarry + RotL64(aIngress, 44U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 22446U)) & S_BLOCK1], 4U) ^ RotL64(aSnowLaneB[((aIndex + 25454U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 25571U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22137U)) & S_BLOCK1], 42U) ^ RotL64(aSnowLaneA[((aIndex + 25820U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aIngress, 4U)) + (RotL64(aPrevious, 41U) + RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterC = ((aWandererD + RotL64(aCross, 60U)) + 5510690816044082200U) + aNonceWordF;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 23U)) + 15967820875033940530U) + aNonceWordB;
            aOrbiterI = (aWandererH + RotL64(aIngress, 47U)) + 539348720848176221U;
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 37U)) + 15779318183635560817U;
            aOrbiterB = ((aWandererK + RotL64(aCross, 29U)) + RotL64(aCarry, 13U)) + 14511058534424187469U;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 56U)) + 5811130556873428391U;
            aOrbiterK = (aWandererC + RotL64(aScatter, 53U)) + 1085928476499444025U;
            aOrbiterH = (((aWandererF + RotL64(aIngress, 11U)) + 6973335316600768130U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordL;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 27U)) + RotL64(aCarry, 5U)) + 10747243745475009744U;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 19U)) + RotL64(aCarry, 41U)) + 1072260008981349754U;
            aOrbiterD = ((aWandererA + RotL64(aCross, 35U)) + 2018772405352495753U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 1092091597048996547U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 15103140149542167197U;
            aOrbiterI = RotL64((aOrbiterI * 621856991658027989U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 13194619321108681542U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 16749188603268621850U) ^ aNonceWordA;
            aOrbiterG = RotL64((aOrbiterG * 9575408950550922039U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 7427959503086895166U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 9895804051379551393U;
            aOrbiterB = RotL64((aOrbiterB * 2701997336201570715U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 4526020800679774259U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 4484850928870048176U;
            aOrbiterA = RotL64((aOrbiterA * 17556987520625677313U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 1837404844299040155U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 15213208978489570694U) ^ aNonceWordO;
            aOrbiterK = RotL64((aOrbiterK * 7062740584650274133U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 9615231781751396800U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 15872192167825648096U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2900526493682580729U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 12530672039655918903U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 10617836782870315804U;
            aOrbiterF = RotL64((aOrbiterF * 9716778004909794973U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 550750725406860977U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 3498554352021622907U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9846933294851238495U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 4059346317776216057U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 14161853870874499023U) ^ aNonceWordH;
            aOrbiterH = RotL64((aOrbiterH * 8601560894939097781U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 4088411647683253905U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 9321241420172776158U;
            aOrbiterD = RotL64((aOrbiterD * 4167888281125330225U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 8527337525861632945U) + aNonceWordI;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 5510690816044082200U;
            aOrbiterE = RotL64((aOrbiterE * 12464836001483233379U), 41U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterA, 57U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 39U));
            aIngress = aIngress + RotL64(aOrbiterI, 26U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 26U) + RotL64(aOrbiterC, 39U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterC, 46U)) + aOrbiterA);
            aWandererI = aWandererI + (((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 23U)) + aOrbiterB) + RotL64(aCarry, 29U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterF, 43U)) + aOrbiterG) + aNonceWordP);
            aWandererK = aWandererK + ((RotL64(aIngress, 57U) + aOrbiterA) + RotL64(aOrbiterG, 37U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterE, 53U)) + aOrbiterI);
            aWandererC = aWandererC + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 11U)) + aOrbiterB);
            aWandererE = aWandererE ^ (((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterJ, 13U)) + aNonceWordD);
            aWandererA = aWandererA + (((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 57U)) + aOrbiterA) + aNonceWordM);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 5U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 11U) + aOrbiterK) + RotL64(aOrbiterH, 26U)) + RotL64(aCarry, 3U)) + aPhaseEWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 10U));
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 36U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 31904U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneA[((aIndex + 29556U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 27712U)) & S_BLOCK1], 6U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28001U)) & S_BLOCK1], 56U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 29379U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 41U)) ^ (RotL64(aIngress, 57U) + RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterG = (((aWandererH + RotL64(aCross, 37U)) + RotL64(aCarry, 5U)) + 9471546960258473684U) + aNonceWordM;
            aOrbiterB = (((aWandererK + RotL64(aIngress, 14U)) + RotL64(aCarry, 13U)) + 18050235435948942244U) + aNonceWordK;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 21U)) + 3005107102671544641U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = (((aWandererA + RotL64(aPrevious, 41U)) + 17898396434573801850U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordG;
            aOrbiterC = (aWandererC + RotL64(aIngress, 53U)) + 15071602525497771648U;
            aOrbiterD = (aWandererG + RotL64(aCross, 57U)) + 5780119462702672108U;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 48U)) + RotL64(aCarry, 29U)) + 13301326224151025687U;
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 3U)) + 18129323022260575961U;
            aOrbiterI = (aWandererE + RotL64(aCross, 43U)) + 1199228670638790709U;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 23U)) + 1839199978088021020U) + aNonceWordH;
            aOrbiterE = (aWandererD + RotL64(aIngress, 11U)) + 4999517042246790165U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 8788607633376516299U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 15143903839930468749U;
            aOrbiterH = RotL64((aOrbiterH * 12735914889325422675U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 16674732686428431869U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 15908873150953195581U;
            aOrbiterC = RotL64((aOrbiterC * 18049755517524334107U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 11204775359756474667U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 2525984309543939465U;
            aOrbiterK = RotL64((aOrbiterK * 3988529812023791571U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 4566345170476825512U) + aNonceWordF;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 14876612901557406267U;
            aOrbiterA = RotL64((aOrbiterA * 9047956948845135339U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 14926290877038883931U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 12710203178186614846U;
            aOrbiterJ = RotL64((aOrbiterJ * 14841163494801662515U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 7315094513967387996U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 11050116830482816766U;
            aOrbiterE = RotL64((aOrbiterE * 3702999495721152019U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 4505368486032503953U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 17905748055257551092U;
            aOrbiterD = RotL64((aOrbiterD * 14775870175093453197U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 5728886950801376350U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 17998141690182325170U;
            aOrbiterB = RotL64((aOrbiterB * 16008599930125391379U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 4325978018819134558U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterJ) ^ 13526905108565989379U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 14121321495714166291U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 10597169665474269506U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 7500801022830471869U) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 3702717219742363777U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 17063616328548689935U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 9471546960258473684U;
            aOrbiterG = RotL64((aOrbiterG * 3029748230803396737U), 19U);
            //
            aIngress = RotL64(aOrbiterE, 37U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + RotL64(aOrbiterC, 14U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 30U) + RotL64(aOrbiterF, 37U)) + aOrbiterE) + aNonceWordE);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 3U)) + aPhaseEWandererUpdateSaltB[((aIndex + 28U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterD, 57U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterA, 23U)) + aOrbiterE) + RotL64(aCarry, 53U)) + aNonceWordN);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 27U) + aOrbiterH) + RotL64(aOrbiterD, 26U));
            aWandererF = aWandererF + ((RotL64(aScatter, 60U) + RotL64(aOrbiterH, 51U)) + aOrbiterG);
            aWandererG = aWandererG ^ ((RotL64(aCross, 41U) + aOrbiterF) + RotL64(aOrbiterK, 5U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 5U) + aOrbiterJ) + RotL64(aOrbiterI, 53U));
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 41U)) + aOrbiterC) + aNonceWordI) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 37U) + aOrbiterI) + RotL64(aOrbiterH, 48U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterB, 29U)) + aOrbiterF) + aNonceWordA);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 60U));
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + RotL64(aWandererI, 39U);
            aCarry = aCarry + RotL64(aIngress, 24U);
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

void TwistExpander_Fencing_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x8F08395DBD7FBB95ULL + 0x987DAC0D2101AEF5ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x9574FCD331169AEDULL + 0xDC20D3BAE2DB14C7ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xF711F5A3B6725621ULL + 0xE7C305E48243A9F7ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xA43BA6F8477EAD09ULL + 0xAA983DC0461A8CF9ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xD15763DFBD3C3953ULL + 0x9784CCBC64D40018ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xF026495AF3B3D8EFULL + 0x8B8EFB2A5F826C8EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xEE8733BC6BB28E29ULL + 0xA05D733094E6A745ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x930E73D023AA2593ULL + 0x986C4A07E7EE758AULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xB9D5390377594A4DULL + 0xAF0DFD786E822A7BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xE88478E4C0A5ECD7ULL + 0xB242D9EA2B767DD7ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xEA4BAFD237DF0159ULL + 0xB00C20213D4298ACULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x93E6235794E29D8DULL + 0xCF978D3056538855ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xF8D14A22D9970D4BULL + 0xF09BE9FEFB5292A0ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x8BD5034E9B3C37C7ULL + 0xD93666D5D834FF59ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xDFB58618968A2BF7ULL + 0xCBD519951625A62DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x89E169A25BB2C663ULL + 0xDC2C5FDD5B19F399ULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 5104U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((aIndex + 1385U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 2505U)) & S_BLOCK1], 50U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 1407U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 109U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 4300U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aPrevious, 11U)) ^ (RotL64(aIngress, 24U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterD = (((aWandererD + RotL64(aIngress, 60U)) + RotL64(aCarry, 27U)) + 9654059367478508868U) + aNonceWordN;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 3U)) + 6473006635864677427U;
            aOrbiterC = (((aWandererB + RotL64(aCross, 47U)) + RotL64(aCarry, 47U)) + 6944184481315853243U) + aNonceWordC;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 19U)) + RotL64(aCarry, 35U)) + 4061496421939102306U;
            aOrbiterB = (aWandererC + RotL64(aCross, 29U)) + 15791809275719085463U;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 53U)) + 14050798802646323055U) + aPhaseFOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aIngress, 10U)) + 12072905924741758266U) + aNonceWordL;
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 39U)) + 17639076509231343896U;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 43U)) + 12195388285571234715U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 4325404419499496529U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 5910567888204238382U;
            aOrbiterC = RotL64((aOrbiterC * 11503787177122206937U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 13092940059929942699U) + aNonceWordK;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 13381962590820308761U;
            aOrbiterK = RotL64((aOrbiterK * 6345904465930943295U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 15622862439323440527U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 14027151901132249793U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2273573821630510087U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 4584410023907605157U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 15763755180625487157U;
            aOrbiterH = RotL64((aOrbiterH * 6755736130607297639U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 17023059745666559199U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 5298529579288492971U;
            aOrbiterE = RotL64((aOrbiterE * 2483562793328357721U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 2870152867331654736U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 12017191100173748848U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9958191466506480519U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 15899529176182436062U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 16482713846343388735U) ^ aNonceWordG;
            aOrbiterA = RotL64((aOrbiterA * 719465695044265601U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 12943393531812774449U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 9881108254540483225U;
            aOrbiterB = RotL64((aOrbiterB * 8011108108007885059U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 3532054586199716750U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 7142230313294797435U) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 14154176174768868421U), 29U);
            //
            aIngress = RotL64(aOrbiterE, 20U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 23U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 39U));
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 58U) + aOrbiterK) + RotL64(aOrbiterA, 47U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterK, 28U)) + aOrbiterC) + RotL64(aCarry, 37U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 5U) + aOrbiterC) + RotL64(aOrbiterD, 11U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterH, 3U)) + aNonceWordD);
            aWandererC = aWandererC ^ ((RotL64(aCross, 51U) + aOrbiterA) + RotL64(aOrbiterE, 39U));
            aWandererA = aWandererA + (((RotL64(aIngress, 27U) + aOrbiterC) + RotL64(aOrbiterJ, 24U)) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 12U) + aOrbiterK) + RotL64(aOrbiterB, 53U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 43U) + aOrbiterH) + RotL64(aOrbiterA, 57U)) + aNonceWordB) + aPhaseFWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterG, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 40U));
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 10765U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneC[((aIndex + 5582U)) & S_BLOCK1], 23U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 10722U)) & S_BLOCK1], 56U) ^ RotL64(aFireLaneC[((aIndex + 9932U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 9698U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8582U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 9579U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCarry, 41U)) ^ (RotL64(aCross, 26U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterG = ((((aWandererF + RotL64(aPrevious, 35U)) + RotL64(aCarry, 29U)) + 2571116506511057880U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordK;
            aOrbiterF = (((aWandererK + RotL64(aCross, 48U)) + RotL64(aCarry, 57U)) + 13112435411509707292U) + aNonceWordB;
            aOrbiterA = (((aWandererD + RotL64(aIngress, 19U)) + RotL64(aCarry, 11U)) + 10403251762787357256U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = (aWandererI + RotL64(aScatter, 57U)) + 8461951095541400405U;
            aOrbiterB = (aWandererC + RotL64(aCross, 39U)) + 9890793478557463815U;
            aOrbiterI = (aWandererJ + RotL64(aScatter, 12U)) + 3030229465991783707U;
            aOrbiterH = (aWandererB + RotL64(aPrevious, 43U)) + 7273848154043719247U;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 53U)) + 10681774862516028276U) + aNonceWordO;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 23U)) + 7105082755586853104U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 6588579345319551129U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 14616333550242386092U) ^ aNonceWordH;
            aOrbiterA = RotL64((aOrbiterA * 2934574715879306337U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 15439666290229654921U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 3360304356760164799U;
            aOrbiterI = RotL64((aOrbiterI * 5164191920584106237U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 14438730801970761889U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 14515616787452085729U;
            aOrbiterF = RotL64((aOrbiterF * 2041601927968559821U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 4167853822635132419U) + aNonceWordJ;
            aOrbiterE = (((aOrbiterE ^ aOrbiterB) ^ 8950982233003320239U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterE = RotL64((aOrbiterE * 887144270884244907U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 12391327853728029953U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 7100871010552394421U;
            aOrbiterD = RotL64((aOrbiterD * 16552349374101955967U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 15381697462381887944U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 6801677551341079401U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13325954438427340703U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 947011315719204867U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterI) ^ 6356920162398333481U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 5566721941682667419U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 8910262020598577378U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 8778455415977526457U;
            aOrbiterG = RotL64((aOrbiterG * 4092470497616637283U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 5585696961453127223U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 9670655481681494412U;
            aOrbiterB = RotL64((aOrbiterB * 7863197168965036383U), 27U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterA, 47U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 6U));
            aIngress = aIngress + (RotL64(aOrbiterF, 53U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterH, 51U)) + aOrbiterC);
            aWandererI = aWandererI + ((((RotL64(aIngress, 57U) + aOrbiterA) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 27U)) + aNonceWordN);
            aWandererD = aWandererD ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterB, 13U)) + aOrbiterC);
            aWandererB = aWandererB + (((RotL64(aScatter, 4U) + RotL64(aOrbiterA, 60U)) + aOrbiterB) + RotL64(aCarry, 11U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterI, 19U)) + aOrbiterD) + aNonceWordP);
            aWandererC = aWandererC + ((RotL64(aIngress, 27U) + aOrbiterH) + RotL64(aOrbiterG, 37U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 19U) + aOrbiterB) + RotL64(aOrbiterF, 47U));
            aWandererF = aWandererF + (((RotL64(aScatter, 43U) + aOrbiterE) + RotL64(aOrbiterF, 56U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 50U) + RotL64(aOrbiterC, 5U)) + aOrbiterI) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 18U));
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + RotL64(aWandererI, 13U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 11401U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((aIndex + 14746U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 14635U)) & S_BLOCK1], 46U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 11936U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 13744U)) & S_BLOCK1], 46U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 37U) + RotL64(aPrevious, 53U)) + (RotL64(aIngress, 6U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterF = (aWandererE + RotL64(aCross, 3U)) + 1087148170018530502U;
            aOrbiterA = (((aWandererJ + RotL64(aPrevious, 58U)) + RotL64(aCarry, 3U)) + 15530846874509311414U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = ((aWandererG + RotL64(aIngress, 53U)) + RotL64(aCarry, 41U)) + 16987358651515511212U;
            aOrbiterJ = ((((aWandererF + RotL64(aScatter, 47U)) + RotL64(aCarry, 27U)) + 12504143181007924259U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordL;
            aOrbiterD = (aWandererI + RotL64(aIngress, 41U)) + 393322117322732418U;
            aOrbiterG = (aWandererH + RotL64(aPrevious, 29U)) + 14325937299241887166U;
            aOrbiterC = ((aWandererD + RotL64(aCross, 35U)) + 9395262907017475742U) + aNonceWordF;
            aOrbiterI = (aWandererB + RotL64(aScatter, 13U)) + 13658510441418344769U;
            aOrbiterE = (aWandererA + RotL64(aCross, 22U)) + 6410754322737005336U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 9257290738538818434U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 7489828960857692286U;
            aOrbiterB = RotL64((aOrbiterB * 16519674788777989043U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 4118778591214588387U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 16619215231168796563U;
            aOrbiterA = RotL64((aOrbiterA * 14876884956536265157U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 11326283811003573430U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 1865401866017614604U;
            aOrbiterF = RotL64((aOrbiterF * 8378326058282460073U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 670150121105733604U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 1499331510641068749U;
            aOrbiterI = RotL64((aOrbiterI * 16623742535540383107U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 1116410848560838532U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 2696841341036281779U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9598953298074904869U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 5487352391229549881U) + aNonceWordD;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 12008243050943342979U;
            aOrbiterJ = RotL64((aOrbiterJ * 9087261224804582459U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 552859665927882960U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 8426942688524814473U) ^ aNonceWordP;
            aOrbiterE = RotL64((aOrbiterE * 10916963622695549105U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 1613287981244830815U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 15592897923468694288U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6600750586743893303U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 7629853970631002676U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 13778028957247561272U;
            aOrbiterG = RotL64((aOrbiterG * 4063798788229605659U), 23U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterD, 57U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 60U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aScatter, 11U) + aOrbiterA) + RotL64(aOrbiterD, 19U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterE, 23U)) + aOrbiterF) + aPhaseFWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 4U) + aOrbiterF) + RotL64(aOrbiterB, 27U)) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 23U) + aOrbiterB) + RotL64(aOrbiterG, 58U)) + aNonceWordG);
            aWandererG = aWandererG + (((RotL64(aCross, 53U) + RotL64(aOrbiterF, 53U)) + aOrbiterG) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterI, 47U)) + aOrbiterD) + aNonceWordM) + aPhaseFWandererUpdateSaltD[((aIndex + 12U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 34U) + aOrbiterJ) + RotL64(aOrbiterG, 37U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 57U) + aOrbiterE) + RotL64(aOrbiterC, 5U)) + aNonceWordB);
            aWandererB = aWandererB + ((RotL64(aIngress, 29U) + RotL64(aOrbiterI, 42U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererA);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + RotL64(aWandererI, 60U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 16655U)) & S_BLOCK1], 56U) ^ RotL64(aSnowLaneA[((aIndex + 18418U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 17922U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 19053U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneD[((aIndex + 17930U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 22U)) ^ (RotL64(aIngress, 57U) + RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterE = ((aWandererG + RotL64(aScatter, 24U)) + 1888427424966603593U) + aNonceWordG;
            aOrbiterB = (aWandererC + RotL64(aIngress, 29U)) + 5436761445660415091U;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 43U)) + RotL64(aCarry, 57U)) + 17322876217962143270U;
            aOrbiterK = ((aWandererA + RotL64(aCross, 51U)) + 9728299982740564979U) + aNonceWordK;
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 35U)) + 301720335271716921U) + aNonceWordE;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 39U)) + RotL64(aCarry, 5U)) + 8069685428854814396U;
            aOrbiterC = (((aWandererB + RotL64(aPrevious, 4U)) + 1973715500949100991U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordP;
            aOrbiterI = ((aWandererE + RotL64(aCross, 19U)) + RotL64(aCarry, 37U)) + 87666408799854155U;
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 11U)) + 12195436904339035245U) + aPhaseFOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 4578742069143400295U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 7828776048774876484U) ^ aNonceWordL;
            aOrbiterF = RotL64((aOrbiterF * 4047964518501081039U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 17203146364542781833U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 16913369550858890466U) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 13534417587921978507U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 9632761514552265402U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 9106637671877341286U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9073709119482640391U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 15423680889126750876U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 6087310684583331882U;
            aOrbiterD = RotL64((aOrbiterD * 8964465129744898619U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 5420955876411796789U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 14166807419730848032U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 442659738632823751U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 8118312450347026824U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 4253043584558403086U;
            aOrbiterC = RotL64((aOrbiterC * 5651748455190536467U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 8810774678371762700U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 12218479555589447835U) ^ aNonceWordA;
            aOrbiterE = RotL64((aOrbiterE * 11026364205248516355U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 11389930523582876358U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 16334420553471379915U;
            aOrbiterK = RotL64((aOrbiterK * 13830132212033904777U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 18201289372553710279U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 7196540389657785361U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13058135202554889791U), 3U);
            //
            aIngress = RotL64(aOrbiterB, 50U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 39U));
            aIngress = aIngress + (RotL64(aOrbiterA, 53U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + RotL64(aOrbiterF, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 11U) + RotL64(aOrbiterK, 35U)) + aOrbiterJ) + aNonceWordO);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterA, 47U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 46U) + aOrbiterF) + RotL64(aOrbiterE, 12U)) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterK, 43U)) + aOrbiterI);
            aWandererB = aWandererB + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterK, 27U)) + aOrbiterB) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterE, 19U));
            aWandererG = aWandererG + (((RotL64(aIngress, 57U) + aOrbiterA) + RotL64(aOrbiterD, 52U)) + aPhaseFWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 40U) + aOrbiterA) + RotL64(aOrbiterF, 5U));
            aWandererH = aWandererH + (((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 39U)) + aOrbiterC) + aNonceWordM);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 36U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 22329U)) & S_BLOCK1], 13U) ^ RotL64(aSnowLaneB[((aIndex + 26076U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 24971U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25780U)) & S_BLOCK1], 11U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 22397U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCarry, 37U)) ^ (RotL64(aCross, 20U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 19U)) + RotL64(aCarry, 37U)) + 10336802574069791273U;
            aOrbiterI = (((aWandererJ + RotL64(aIngress, 37U)) + RotL64(aCarry, 23U)) + 169025388197058936U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aCross, 11U)) + 6541354188379168846U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = (((aWandererK + RotL64(aScatter, 28U)) + RotL64(aCarry, 3U)) + 16223920526599306104U) + aNonceWordE;
            aOrbiterA = (aWandererI + RotL64(aPrevious, 5U)) + 12756613707692514808U;
            aOrbiterC = (aWandererF + RotL64(aCross, 43U)) + 5082475548176484035U;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 47U)) + 4907435526952698526U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 23U)) + 14236627073831834337U) + aNonceWordH;
            aOrbiterH = (aWandererG + RotL64(aPrevious, 54U)) + 11502511046130497584U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 3679044835550219497U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 11254838916686736746U;
            aOrbiterG = RotL64((aOrbiterG * 8631695922983532915U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 10582608424233200966U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 10449735026385340313U;
            aOrbiterA = RotL64((aOrbiterA * 7363770199734997411U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 4628253464169957835U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 17664454668473204465U;
            aOrbiterJ = RotL64((aOrbiterJ * 4234720298731378527U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 3798386391743884889U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 1379331161819246587U;
            aOrbiterB = RotL64((aOrbiterB * 13086160171095077295U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 9816600392407327227U) + aNonceWordC;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 16781971616348376878U;
            aOrbiterD = RotL64((aOrbiterD * 12503867584828289879U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 4807797577690520554U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 2492057261148595922U;
            aOrbiterK = RotL64((aOrbiterK * 9453302540675483005U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 7909676419643119585U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 256053568910383007U;
            aOrbiterC = RotL64((aOrbiterC * 11965085163352053161U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 16179914439220412472U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = (((aOrbiterH ^ aOrbiterC) ^ 3968867762761955845U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 7473632378251893139U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 7474832923901283742U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 4736994731050735779U;
            aOrbiterI = RotL64((aOrbiterI * 9839654409121414047U), 23U);
            //
            aIngress = RotL64(aOrbiterC, 5U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterG, 40U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterH, 60U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterJ, 39U)) + aOrbiterA) + RotL64(aCarry, 35U)) + aNonceWordA);
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 10U) + RotL64(aOrbiterK, 53U)) + aOrbiterG) + aNonceWordI) + aPhaseFWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 47U) + RotL64(aOrbiterA, 47U)) + aOrbiterG);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 13U)) + aOrbiterC) + aNonceWordN);
            aWandererK = aWandererK + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 5U)) + aOrbiterH) + RotL64(aCarry, 51U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterH, 43U)) + aOrbiterJ);
            aWandererC = aWandererC + ((RotL64(aScatter, 6U) + aOrbiterJ) + RotL64(aOrbiterD, 28U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 51U) + aOrbiterI) + RotL64(aOrbiterB, 19U)) + aNonceWordB);
            //
            aCarry = aCarry + (RotL64(aWandererG, 6U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + RotL64(aWandererK, 13U);
            aCarry = aCarry + RotL64(aIngress, 46U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 30493U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((aIndex + 28240U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aInvestLaneD[((aIndex + 31904U)) & S_BLOCK1], 36U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29296U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31042U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 54U) + RotL64(aPrevious, 3U)) + (RotL64(aCarry, 19U) ^ RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterB = ((aWandererI + RotL64(aScatter, 11U)) + 17668251151213543491U) + aNonceWordE;
            aOrbiterA = (aWandererB + RotL64(aPrevious, 6U)) + 16101602509895104517U;
            aOrbiterC = (((aWandererK + RotL64(aCross, 29U)) + RotL64(aCarry, 57U)) + 9083915270773304935U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aIngress, 39U)) + 12810720730318214811U;
            aOrbiterD = (aWandererC + RotL64(aCross, 47U)) + 18113428002071925621U;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 18U)) + RotL64(aCarry, 37U)) + 1582208899354109878U;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 35U)) + RotL64(aCarry, 13U)) + 4180688104819188154U;
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 53U)) + 8954598189262820611U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aScatter, 57U)) + 15360094153175355879U) + aNonceWordO;
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 8383954114668216260U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 15626783326234049197U) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 15058420415480073793U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 10609978564404958066U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 17656516608997517984U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4590620354119899777U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 760077259110786536U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 3597338735888033063U;
            aOrbiterE = RotL64((aOrbiterE * 6548831472863517621U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 4431777844935985157U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 10710423172154671296U;
            aOrbiterI = RotL64((aOrbiterI * 16267496318491473315U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 10240882795242085185U) + aNonceWordI;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 7826053487019825891U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15053729937684375907U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 9418883403715727353U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 11507423614799075545U;
            aOrbiterG = RotL64((aOrbiterG * 16189463984557044693U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 11545217316421066655U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 617921402135485341U;
            aOrbiterB = RotL64((aOrbiterB * 8182920764965471653U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 14456933220749921009U) + aNonceWordA;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 7990243583564535387U;
            aOrbiterK = RotL64((aOrbiterK * 5994900368027985469U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 14023633125757654751U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 11319146808574958827U;
            aOrbiterA = RotL64((aOrbiterA * 13676159969338309307U), 13U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterG, 51U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + (RotL64(aOrbiterD, 6U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterC, 35U)) + aOrbiterI) + aNonceWordL);
            aWandererC = aWandererC + (((RotL64(aIngress, 37U) + aOrbiterD) + RotL64(aOrbiterF, 41U)) + RotL64(aCarry, 43U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 30U) + aOrbiterB) + RotL64(aOrbiterF, 14U));
            aWandererH = aWandererH + (((((RotL64(aCross, 51U) + aOrbiterA) + RotL64(aOrbiterB, 29U)) + RotL64(aCarry, 29U)) + aNonceWordM) + aPhaseFWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterK, 47U));
            aWandererI = aWandererI + ((RotL64(aIngress, 57U) + RotL64(aOrbiterA, 23U)) + aOrbiterE);
            aWandererF = aWandererF ^ ((((RotL64(aCross, 26U) + RotL64(aOrbiterE, 18U)) + aOrbiterI) + aNonceWordD) + aPhaseFWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 43U) + aOrbiterF) + RotL64(aOrbiterI, 5U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterE, 53U)) + aOrbiterG) + aNonceWordN);
            //
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererH, 38U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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

void TwistExpander_Fencing_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xFE7520F111F4A2ADULL + 0xA28127373FDB4917ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xD73E175C4B0C68DBULL + 0xBA1FCEDF5B66FC23ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xE2146A3EBC52CEFDULL + 0x8677EA135C8FCE8FULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xB9086E4F5D8A1A6FULL + 0xBAAEA1DE4F2DB745ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x8F6D9006B5D6D841ULL + 0xE9839F80D36F173FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xE888878EBD985B8DULL + 0xFBB122A9822E3DA9ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xF216B886B5684493ULL + 0xF90BFB056707B184ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x96650888D2886BC9ULL + 0xB2F970E6072906AFULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xA268F25951B0590DULL + 0x89A7CF89C2BCB188ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xDBA980A4C206AE55ULL + 0x8E22E7A82AD6E08FULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xD2FCC88E5BC27799ULL + 0x9E7F25F2B5841490ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xA4F37BF5CB0E4801ULL + 0xF2752693FA2F7000ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xF4B29ACC78B4F0A7ULL + 0x8004576E92309403ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xD601C1F9AAE90987ULL + 0xC906C3A530044D4DULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xA445B43D5F55B71FULL + 0xF8E7B1F5BB385230ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xE0E60AE88CC44D77ULL + 0xA820C70BE907CB25ULL);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 1095U)) & S_BLOCK1], 13U) ^ RotL64(aSnowLaneB[((aIndex + 369U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 5133U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 1022U)) & S_BLOCK1], 6U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 3243U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 2669U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCross, 3U)) + (RotL64(aCarry, 21U) + RotL64(aPrevious, 38U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterK = (aWandererJ + RotL64(aScatter, 5U)) + 3238389262925516513U;
            aOrbiterC = (aWandererH + RotL64(aCross, 23U)) + 12381787182611386995U;
            aOrbiterF = (((aWandererG + RotL64(aIngress, 47U)) + RotL64(aCarry, 23U)) + 7883885539305181549U) + aPhaseHOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aPrevious, 14U)) + 1185413044597727092U;
            aOrbiterE = (((aWandererK + RotL64(aCross, 41U)) + RotL64(aCarry, 57U)) + 15219353497204773135U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 35U)) + 7533774715626734082U) + aNonceWordA;
            aOrbiterH = (((aWandererA + RotL64(aScatter, 29U)) + RotL64(aCarry, 11U)) + 2599930450937763464U) + aNonceWordJ;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 16074720663961214284U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 15483613196360051221U;
            aOrbiterF = RotL64((aOrbiterF * 11717479088020532861U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 9396557867081376268U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 9668459976852660245U;
            aOrbiterE = RotL64((aOrbiterE * 11748505665890567063U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 9037269914643207212U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = (((aOrbiterH ^ aOrbiterJ) ^ 16936742640861088240U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 1040172193161012227U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 16481274825758546398U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 481851372837611166U;
            aOrbiterJ = RotL64((aOrbiterJ * 2225030139210599207U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 13608921517203544108U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 16930740723286214636U;
            aOrbiterK = RotL64((aOrbiterK * 2605108503821980865U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 902242902582149908U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 1510861213079342977U) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 3309753895727400707U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 7116243600304980310U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 6631412278359709602U) ^ aNonceWordD;
            aOrbiterC = RotL64((aOrbiterC * 11452627691392637463U), 43U);
            //
            aIngress = RotL64(aOrbiterJ, 51U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aCross, 11U) + RotL64(aOrbiterH, 60U)) + aOrbiterJ) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 47U)) + aOrbiterC) + aNonceWordI);
            aWandererA = aWandererA + (((((RotL64(aPrevious, 53U) + RotL64(aOrbiterC, 27U)) + aOrbiterK) + RotL64(aCarry, 37U)) + aNonceWordO) + aPhaseHWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterJ, 41U)) + aOrbiterF);
            aWandererH = aWandererH + ((RotL64(aCross, 5U) + aOrbiterK) + RotL64(aOrbiterH, 35U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 30U) + aOrbiterF) + RotL64(aOrbiterA, 19U)) + aNonceWordL);
            aWandererE = aWandererE + (((RotL64(aScatter, 23U) + aOrbiterC) + RotL64(aOrbiterH, 11U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 24U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + RotL64(aWandererG, 13U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 5919U)) & S_BLOCK1], 41U) ^ RotL64(aSnowLaneC[((aIndex + 6918U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 9158U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 8065U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 7184U)) & S_BLOCK1], 11U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 8973U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 8934U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 37U) + RotL64(aCarry, 57U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 51U)) + 16462052553719977502U) + aNonceWordJ;
            aOrbiterI = (((aWandererG + RotL64(aScatter, 27U)) + RotL64(aCarry, 13U)) + 12337064059566619581U) + aNonceWordE;
            aOrbiterH = (((aWandererF + RotL64(aIngress, 43U)) + 15801005007094515447U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordK;
            aOrbiterK = (aWandererB + RotL64(aCross, 3U)) + 8228706742665081656U;
            aOrbiterB = (aWandererC + RotL64(aPrevious, 60U)) + 11006723027845190869U;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 37U)) + RotL64(aCarry, 43U)) + 18173765337829177450U;
            aOrbiterJ = ((((aWandererA + RotL64(aCross, 19U)) + RotL64(aCarry, 57U)) + 530215083653542558U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordL;
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 6608611827035564511U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 2246051826221626809U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6333352641495253539U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 5228575308895381421U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 10999213210689606857U;
            aOrbiterB = RotL64((aOrbiterB * 5467601259546342925U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 3773371037240485696U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 8887985779436152504U) ^ aNonceWordI;
            aOrbiterD = RotL64((aOrbiterD * 698713082830739677U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 11150566414723818350U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 8336366151003049546U) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 9033771197242493699U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 13233968794237090787U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 8172558473508478819U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17837070423649268435U), 21U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterD) + 133564480283347997U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1]) + aNonceWordB;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 15104810248883567064U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 706802420642303533U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 9138629520201127075U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 13993086066341664080U;
            aOrbiterJ = RotL64((aOrbiterJ * 4875046427147105077U), 5U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 3U);
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterJ, 60U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 11U) + aOrbiterE) + RotL64(aOrbiterB, 13U)) + aPhaseHWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 53U) + RotL64(aOrbiterD, 19U)) + aOrbiterK) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 5U)) + aOrbiterI) + aNonceWordH) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterE, 57U)) + aOrbiterJ) + aNonceWordP);
            aWandererB = aWandererB + ((RotL64(aScatter, 20U) + aOrbiterH) + RotL64(aOrbiterK, 27U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterD, 42U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + (RotL64(aWandererB, 46U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 41U));
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 14304U)) & S_BLOCK1], 5U) ^ RotL64(aSnowLaneA[((aIndex + 13084U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 12834U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16257U)) & S_BLOCK1], 53U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 11074U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aPrevious, 5U)) + (RotL64(aCarry, 44U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 27U)) + RotL64(aCarry, 39U)) + 12027839670755583592U;
            aOrbiterK = (((aWandererF + RotL64(aCross, 11U)) + RotL64(aCarry, 5U)) + 15380130703509859843U) + aNonceWordF;
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 21U)) + 4590907433867798074U) + aPhaseHOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = (((aWandererG + RotL64(aScatter, 51U)) + RotL64(aCarry, 19U)) + 1754574023602519724U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = (aWandererE + RotL64(aCross, 35U)) + 9832756659564903767U;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 41U)) + 5035088494491470403U) + aNonceWordN;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 58U)) + 14199170923323644638U) + aNonceWordP;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 8325619421264440438U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 969534320779067977U;
            aOrbiterG = RotL64((aOrbiterG * 17767548306355264705U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 270575869402913847U) + aNonceWordK;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 13344806516599578910U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10193544126281901579U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 15143147951139409101U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 14425582489214169238U;
            aOrbiterJ = RotL64((aOrbiterJ * 16893787086337916355U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 13951127523239064584U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterB) ^ 14177925225918293579U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 13079514031864998485U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 8258920744278218901U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 7408161179397242453U) ^ aNonceWordI;
            aOrbiterH = RotL64((aOrbiterH * 975737128100519169U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 8581481606764773468U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 10078416198417433133U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1102721083915858247U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 18299772198826189580U) + aNonceWordB;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 18304668908084397946U;
            aOrbiterK = RotL64((aOrbiterK * 10589455451200578687U), 53U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 3U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aCross, 21U) + aOrbiterF) + RotL64(aOrbiterH, 60U));
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 60U) + aOrbiterK) + RotL64(aOrbiterI, 3U)) + aNonceWordD) + aPhaseHWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterJ, 39U));
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 51U) + aOrbiterH) + RotL64(aOrbiterB, 53U)) + aNonceWordA) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 57U)) + aNonceWordJ);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 37U) + aOrbiterB) + RotL64(aOrbiterK, 47U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterG, 13U)) + aOrbiterH) + RotL64(aCarry, 39U)) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererF, 48U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 20303U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((aIndex + 19052U)) & S_BLOCK1], 50U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 21074U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19866U)) & S_BLOCK1], 27U) ^ RotL64(aSnowLaneD[((aIndex + 19616U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 22U) ^ RotL64(aPrevious, 35U)) + (RotL64(aIngress, 47U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterA = ((aWandererH + RotL64(aCross, 50U)) + RotL64(aCarry, 53U)) + 17936518874386450467U;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 5U)) + RotL64(aCarry, 29U)) + 13722737841589910344U;
            aOrbiterE = (((aWandererF + RotL64(aIngress, 29U)) + 11774969167948715796U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordG;
            aOrbiterB = (((aWandererC + RotL64(aScatter, 37U)) + RotL64(aCarry, 41U)) + 3640101505680493777U) + aNonceWordO;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 43U)) + 1369495382725650822U) + aNonceWordP;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 23U)) + 11827310354654653345U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aIngress, 11U)) + 186037671377175394U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 11428829344234627340U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 2275016369870029068U) ^ aNonceWordC;
            aOrbiterE = RotL64((aOrbiterE * 14936799202145280833U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 15471646673734798328U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 12172082573115640145U) ^ aNonceWordI;
            aOrbiterF = RotL64((aOrbiterF * 9629417882787847753U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 6626736341348283154U) + aNonceWordE;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 12220614992483863623U;
            aOrbiterI = RotL64((aOrbiterI * 8137086205714097487U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 13157102324253760215U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 4143587482368093601U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5060677690991506895U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 11007575246013796426U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 11721585930088637162U;
            aOrbiterB = RotL64((aOrbiterB * 15009627907125738519U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 5720789204450196217U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 3094696226821431648U;
            aOrbiterC = RotL64((aOrbiterC * 4412033981712165541U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 14675830108100986773U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 9444071495289719645U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10983136361953366557U), 39U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterC, 4U);
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + RotL64(aOrbiterF, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 51U) + aOrbiterC) + RotL64(aOrbiterJ, 19U)) + aNonceWordJ);
            aWandererF = aWandererF + (((((RotL64(aPrevious, 58U) + aOrbiterI) + RotL64(aOrbiterA, 46U)) + RotL64(aCarry, 39U)) + aNonceWordN) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 13U) + aOrbiterE) + RotL64(aOrbiterC, 29U)) + aNonceWordD);
            aWandererH = aWandererH + ((RotL64(aScatter, 27U) + aOrbiterF) + RotL64(aOrbiterB, 13U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 21U) + aOrbiterA) + RotL64(aOrbiterE, 39U)) + aNonceWordA);
            aWandererA = aWandererA + (((RotL64(aScatter, 43U) + aOrbiterC) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 13U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterE, 5U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (RotL64(aWandererG, 41U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 60U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 35U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 22862U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((aIndex + 26359U)) & S_BLOCK1], 6U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 21882U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22630U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneA[((aIndex + 25028U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 10U) + RotL64(aIngress, 51U)) + (RotL64(aCross, 35U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterC = (aWandererH + RotL64(aIngress, 57U)) + 2786079456995203065U;
            aOrbiterF = ((aWandererI + RotL64(aScatter, 29U)) + 7237256119153857253U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aPrevious, 13U)) + 9310834010563647604U;
            aOrbiterA = ((((aWandererG + RotL64(aCross, 23U)) + RotL64(aCarry, 3U)) + 17361734905706517877U) + aPhaseHOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1]) + aNonceWordM;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 41U)) + RotL64(aCarry, 51U)) + 15837111231884647451U;
            aOrbiterB = (((aWandererF + RotL64(aIngress, 50U)) + RotL64(aCarry, 19U)) + 18065431964418026445U) + aNonceWordI;
            aOrbiterH = (aWandererC + RotL64(aScatter, 3U)) + 3029123922999952652U;
            //
            aOrbiterC = (((aOrbiterC + aOrbiterF) + 5166926595573507837U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordC;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 1918425684273807598U) ^ aNonceWordA;
            aOrbiterG = RotL64((aOrbiterG * 16616641579714896719U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 4724551751012661440U) + aNonceWordG;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 1818014487579644390U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14904092108647864911U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 6670090372241084216U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 8485757110007268693U;
            aOrbiterF = RotL64((aOrbiterF * 11876760095108618363U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 4928130251509514742U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 2528788422725346792U;
            aOrbiterK = RotL64((aOrbiterK * 1855982047967756661U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 2860387120895147503U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 12927802338151379368U) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 8876144125458603029U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 18029699867733207083U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 13361836994951253312U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5349767426256597073U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 11957294454794128079U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 3755417922063414648U;
            aOrbiterB = RotL64((aOrbiterB * 13896364063651241401U), 29U);
            //
            aIngress = RotL64(aOrbiterF, 21U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 42U) + RotL64(aOrbiterA, 43U)) + aOrbiterF) + aNonceWordP);
            aWandererK = aWandererK + (((((RotL64(aPrevious, 29U) + aOrbiterB) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 53U)) + aNonceWordJ) + aPhaseHWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 19U)) + aOrbiterG);
            aWandererC = aWandererC + (((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 57U)) + aOrbiterG) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 23U) + aOrbiterA) + RotL64(aOrbiterC, 12U)) + aNonceWordL);
            aWandererG = aWandererG + ((RotL64(aScatter, 11U) + aOrbiterF) + RotL64(aOrbiterH, 51U));
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterK, 5U)) + aNonceWordB) + aPhaseHWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 54U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererG, 13U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28899U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 28983U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 28532U)) & S_BLOCK1], 40U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31866U)) & S_BLOCK1], 19U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 31443U)) & S_BLOCK1], 40U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 60U) ^ RotL64(aCarry, 11U)) ^ (RotL64(aCross, 43U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterH = ((((aWandererE + RotL64(aScatter, 23U)) + RotL64(aCarry, 57U)) + 9888431329297626900U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordP;
            aOrbiterK = (((aWandererJ + RotL64(aIngress, 37U)) + RotL64(aCarry, 43U)) + 2937735167534624403U) + aNonceWordF;
            aOrbiterB = ((((aWandererF + RotL64(aCross, 29U)) + RotL64(aCarry, 5U)) + 17626022970343789617U) + aPhaseHOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1]) + aNonceWordL;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 43U)) + 5665660859333693743U;
            aOrbiterE = ((aWandererD + RotL64(aIngress, 13U)) + 1060537034632076669U) + aNonceWordK;
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 53U)) + 743777763907175800U;
            aOrbiterI = (aWandererK + RotL64(aCross, 60U)) + 5744905970181808845U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 3545351394494002180U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 4877547088414106007U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5416792889338547109U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 11669378338379598445U) + aNonceWordN;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 2961072441706158212U) ^ aNonceWordH;
            aOrbiterE = RotL64((aOrbiterE * 2677988507090705371U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 13984945589234919765U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 1433097875470903205U;
            aOrbiterJ = RotL64((aOrbiterJ * 451996840039906781U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 716415411025451152U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 8542286150858297810U;
            aOrbiterK = RotL64((aOrbiterK * 9139015340823332449U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 12932391786479661299U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 14005503313299177013U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 802663466907819743U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 9382792812676318046U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 5138554251079724724U) ^ aNonceWordJ;
            aOrbiterD = RotL64((aOrbiterD * 6386016499265056247U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 8522380066269546172U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 11825536408101906458U;
            aOrbiterI = RotL64((aOrbiterI * 17042837108792016849U), 57U);
            //
            aIngress = RotL64(aOrbiterK, 13U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterB, 37U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterD, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 3U)) + aOrbiterD) + aNonceWordM);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 20U) + aOrbiterK) + RotL64(aOrbiterI, 11U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 51U) + aOrbiterJ) + RotL64(aOrbiterE, 35U)) + aNonceWordO) + aPhaseHWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterD, 51U)) + aOrbiterJ) + aNonceWordC);
            aWandererK = aWandererK + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterB, 58U)) + aOrbiterH) + RotL64(aCarry, 11U)) + aNonceWordB);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterI, 41U)) + aOrbiterE);
            aWandererH = aWandererH + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterB, 23U)) + aOrbiterE) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 60U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererF, 5U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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

void TwistExpander_Fencing_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA;
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
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC;
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 274U)) & W_KEY1], 18U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 291U)) & W_KEY1], 53U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 2452U)) & W_KEY1], 12U) ^ RotL64(mSource[((aIndex + 2539U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCarry, 57U)) ^ (RotL64(aIngress, 6U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (aWandererF + RotL64(aCross, 51U)) + 9630214189402543339U;
            aOrbiterK = (aWandererB + RotL64(aIngress, 24U)) + 4072576573737526819U;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 29U)) + 15994787452709618869U) + aPhaseAOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 37U)) + 6403240137132259482U;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 43U)) + RotL64(aCarry, 19U)) + 10229266900170507720U;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 13U)) + 5025294577989748989U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aIngress, 19U)) + 16696461238217956883U;
            aOrbiterD = ((aWandererC + RotL64(aCross, 5U)) + RotL64(aCarry, 5U)) + 9878318855341719119U;
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 58U)) + RotL64(aCarry, 41U)) + 16086635438116177346U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 12295437783084203730U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 7681150419912842402U;
            aOrbiterJ = RotL64((aOrbiterJ * 7289497379725191451U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 2639104034287637448U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 12298170009332243573U;
            aOrbiterB = RotL64((aOrbiterB * 9397919591171238575U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 3485932317267669626U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 16569551670038752475U;
            aOrbiterG = RotL64((aOrbiterG * 8139802826402217631U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 4448490103784103954U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 14510534073046885941U;
            aOrbiterD = RotL64((aOrbiterD * 7777192047386438305U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 4286195398675733451U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 15790355933840266463U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13342257823027075501U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 6362891510370156055U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 15121822034579983174U;
            aOrbiterI = RotL64((aOrbiterI * 7268045994574844937U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 13817341015719915628U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 14113474087906143783U;
            aOrbiterA = RotL64((aOrbiterA * 12838910141533126059U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 9988301252236121106U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 11287477288382171758U;
            aOrbiterK = RotL64((aOrbiterK * 4979297247881426383U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 9491727010910328644U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 7961202721830514030U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16300364540313620767U), 51U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 38U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterA, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 18U) + aOrbiterD) + RotL64(aOrbiterB, 10U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 39U) + aOrbiterD) + RotL64(aOrbiterG, 21U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 43U)) + aOrbiterE);
            aWandererB = aWandererB + (((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterI, 29U)) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterF, 52U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterF, 57U)) + aOrbiterE) + RotL64(aCarry, 35U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterF, 39U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 48U) + RotL64(aOrbiterG, 5U)) + aOrbiterI);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 3U) + aOrbiterJ) + RotL64(aOrbiterE, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 26U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + RotL64(aWandererD, 53U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 4687U)) & S_BLOCK1], 36U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 4062U)) & W_KEY1], 57U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 4596U)) & W_KEY1], 37U) ^ RotL64(mSource[((aIndex + 2867U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aIngress, 43U)) + (RotL64(aPrevious, 56U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 47U)) + RotL64(aCarry, 29U)) + 5573188770530340913U;
            aOrbiterA = (((aWandererE + RotL64(aCross, 23U)) + RotL64(aCarry, 57U)) + 1431772230889897111U) + aPhaseAOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = (aWandererI + RotL64(aScatter, 3U)) + 4809192776429682319U;
            aOrbiterG = (aWandererH + RotL64(aIngress, 52U)) + 5576603692574369341U;
            aOrbiterE = (aWandererF + RotL64(aPrevious, 39U)) + 2720143226007220386U;
            aOrbiterB = (aWandererB + RotL64(aScatter, 29U)) + 17220328778565331629U;
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 11U)) + 9629485808442089423U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = (aWandererA + RotL64(aCross, 19U)) + 1136998437010390983U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 58U)) + RotL64(aCarry, 19U)) + 11893390497814523841U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 1764986431917532370U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 1741014798007010376U;
            aOrbiterC = RotL64((aOrbiterC * 13414914086049500731U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 12221368453236547044U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 7694538641172350430U;
            aOrbiterE = RotL64((aOrbiterE * 8439120733670016501U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 17472344518811560603U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 3308740700728172984U;
            aOrbiterA = RotL64((aOrbiterA * 15290400462887712083U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 9535358833412446771U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 11192312491731312451U;
            aOrbiterH = RotL64((aOrbiterH * 17405609148475445743U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 14850451970047190039U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 11932493299452443256U;
            aOrbiterD = RotL64((aOrbiterD * 7964808728820467795U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 5972619895614731870U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 17174497535809891690U;
            aOrbiterB = RotL64((aOrbiterB * 15471084511364572533U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 17412894714378898351U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 14675615208706549810U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7864845089606499769U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 16116792108013658523U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 9702262005960966336U;
            aOrbiterK = RotL64((aOrbiterK * 970452849653781703U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 17337264966818542841U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 7004462033775827275U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11943575980344402681U), 5U);
            //
            aIngress = RotL64(aOrbiterA, 6U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterE, 19U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aScatter, 51U) + RotL64(aOrbiterC, 53U)) + aOrbiterB) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterH, 5U)) + aPhaseAWandererUpdateSaltB[((aIndex + 14U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 28U) + RotL64(aOrbiterJ, 23U)) + aOrbiterG) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterJ, 46U));
            aWandererK = aWandererK + ((RotL64(aCross, 39U) + aOrbiterJ) + RotL64(aOrbiterA, 11U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 13U) + aOrbiterJ) + RotL64(aOrbiterC, 29U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 46U) + aOrbiterE) + RotL64(aOrbiterH, 39U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 60U)) + aOrbiterD) + aPhaseAWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterG, 35U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 58U));
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 5U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aFireLaneB[((aIndex + 7162U)) & S_BLOCK1], 24U) ^ RotL64(aKeyRowReadB[((aIndex + 7331U)) & W_KEY1], 13U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 6369U)) & W_KEY1], 47U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6690U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 5550U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aIngress, 39U)) ^ (RotL64(aCarry, 24U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = (aWandererJ + RotL64(aScatter, 3U)) + 3248574644570178787U;
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 46U)) + 4506961512959200024U;
            aOrbiterE = ((aWandererK + RotL64(aCross, 35U)) + RotL64(aCarry, 5U)) + 8423739774540738590U;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 27U)) + RotL64(aCarry, 13U)) + 6593975869641735337U;
            aOrbiterF = ((aWandererD + RotL64(aCross, 23U)) + 16441716090557369103U) + aPhaseAOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = ((aWandererI + RotL64(aIngress, 10U)) + 7936601450453207914U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aScatter, 19U)) + 13333752583560167065U;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 51U)) + RotL64(aCarry, 57U)) + 8013703284795432973U;
            aOrbiterC = (aWandererH + RotL64(aCross, 41U)) + 2349852779887439236U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 5318539364763284138U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 11450957608502944376U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1957880366707810635U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 9058992558327552687U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 632095686920230926U;
            aOrbiterF = RotL64((aOrbiterF * 12460364388358520799U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 14734218428913777098U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 16344357661370784442U;
            aOrbiterJ = RotL64((aOrbiterJ * 15049472842002138369U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 2981145363531184308U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 14176472085175714494U;
            aOrbiterK = RotL64((aOrbiterK * 2584623327412130939U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 11198457590069700889U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 952584436750426828U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1165713888651280355U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 4311591763498985972U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 16194341833989936369U;
            aOrbiterC = RotL64((aOrbiterC * 9997934560195932575U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 7560794022401107431U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 10683789740265711603U;
            aOrbiterD = RotL64((aOrbiterD * 15637823045351977883U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 11614366395125937178U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 10750771385100564416U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4987921274272444283U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 2934697034132204529U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 4646873794658020363U;
            aOrbiterB = RotL64((aOrbiterB * 10555456865641580175U), 11U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterB, 57U);
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + RotL64(aOrbiterI, 60U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 43U) + aOrbiterC) + RotL64(aOrbiterF, 19U));
            aWandererD = aWandererD + (((RotL64(aScatter, 4U) + RotL64(aOrbiterE, 57U)) + aOrbiterI) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterH, 24U)) + aOrbiterE);
            aWandererF = aWandererF + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterJ, 43U)) + aOrbiterB) + aPhaseAWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 39U) + aOrbiterJ) + RotL64(aOrbiterD, 51U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 47U)) + aOrbiterF) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 26U) + RotL64(aOrbiterD, 39U)) + aOrbiterF) + aPhaseAWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 11U) + aOrbiterC) + RotL64(aOrbiterB, 3U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 51U) + aOrbiterI) + RotL64(aOrbiterK, 12U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (RotL64(aWandererI, 10U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 3U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 10087U)) & S_BLOCK1], 37U) ^ RotL64(aKeyRowReadB[((aIndex + 10439U)) & W_KEY1], 4U));
            aIngress ^= (RotL64(mSource[((aIndex + 10164U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneA[((aIndex + 9139U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 10803U)) & W_KEY1], 20U) ^ RotL64(aFireLaneB[((aIndex + 8661U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 12U) + RotL64(aCross, 57U)) ^ (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = ((aWandererD + RotL64(aScatter, 41U)) + RotL64(aCarry, 5U)) + 77518479758428414U;
            aOrbiterI = (aWandererF + RotL64(aCross, 5U)) + 4832061802166300011U;
            aOrbiterH = (aWandererH + RotL64(aIngress, 19U)) + 11695291171006574112U;
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 60U)) + RotL64(aCarry, 47U)) + 7467412817843260094U;
            aOrbiterK = (aWandererB + RotL64(aCross, 53U)) + 17801484124471154757U;
            aOrbiterG = ((aWandererC + RotL64(aIngress, 23U)) + RotL64(aCarry, 29U)) + 5555455638503958639U;
            aOrbiterJ = (aWandererA + RotL64(aScatter, 11U)) + 5669470540733721606U;
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 30U)) + 3042388456327784163U) + aPhaseBOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aCross, 35U)) + 2236734925228156691U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 14459720401528685450U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 4814967631216658856U;
            aOrbiterH = RotL64((aOrbiterH * 18288097536171386643U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 16950679344449075945U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 6262238639302011050U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9942659897425088183U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 3522256359074996724U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 12524717897707074242U;
            aOrbiterE = RotL64((aOrbiterE * 6787771338063891989U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 13891759914865623828U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 11910250571469028666U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12311343917878428995U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 2240189915640314069U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 5365912986308810837U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15133972552032469957U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 9323732721344489753U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 13087326560957916553U;
            aOrbiterD = RotL64((aOrbiterD * 14659491687401151733U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 16398238057564892809U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 11517870519285159224U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1501848878469712681U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 7758285512254776734U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 17475149091906684720U;
            aOrbiterC = RotL64((aOrbiterC * 6015816725428299273U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 2051631493975035243U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 11684740065349595315U;
            aOrbiterJ = RotL64((aOrbiterJ * 10918975496337269197U), 5U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterE, 57U);
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterK, 42U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterH, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aScatter, 51U) + aOrbiterK) + RotL64(aOrbiterB, 27U)) + RotL64(aCarry, 23U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 30U) + RotL64(aOrbiterJ, 57U)) + aOrbiterK);
            aWandererF = aWandererF + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterI, 34U)) + aOrbiterK) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterC, 3U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterD, 19U)) + aPhaseBWandererUpdateSaltB[((aIndex + 8U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterI, 43U)) + aOrbiterG);
            aWandererG = aWandererG + ((RotL64(aScatter, 35U) + RotL64(aOrbiterD, 48U)) + aOrbiterC);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 4U) + aOrbiterE) + RotL64(aOrbiterK, 39U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 39U) + RotL64(aOrbiterJ, 11U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 50U));
            aCarry = aCarry + RotL64(aWandererC, 11U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 13022U)) & S_BLOCK1], 56U) ^ RotL64(aKeyRowReadA[((aIndex + 12498U)) & W_KEY1], 37U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 11190U)) & W_KEY1], 3U) ^ RotL64(mSource[((aIndex + 11218U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 12845U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 13627U)) & S_BLOCK1], 26U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 12050U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 52U) + RotL64(aCarry, 23U)) ^ (RotL64(aCross, 39U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = (aWandererG + RotL64(aIngress, 58U)) + 16922357079016918108U;
            aOrbiterC = (aWandererF + RotL64(aCross, 11U)) + 11771749797137599131U;
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 29U)) + RotL64(aCarry, 41U)) + 4635668433708036077U;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 51U)) + RotL64(aCarry, 51U)) + 15827952719230577008U;
            aOrbiterB = (aWandererA + RotL64(aIngress, 18U)) + 1495675306110023086U;
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 23U)) + 7294835466949728365U;
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 3U)) + 179122461212041978U) + aPhaseBOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = (((aWandererI + RotL64(aCross, 39U)) + RotL64(aCarry, 5U)) + 545981421632236251U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aPrevious, 35U)) + 15338259639814630535U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 12924313840290895215U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 17846785921286020610U;
            aOrbiterA = RotL64((aOrbiterA * 18309347016029917133U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 5721472794107057875U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 16359630793856870319U;
            aOrbiterJ = RotL64((aOrbiterJ * 14186771515526698907U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 10614102110239037308U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 16421992251278236531U;
            aOrbiterD = RotL64((aOrbiterD * 2561232904676068089U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 8668149834861244963U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 12699331834360948734U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2249360824172616357U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 4470693178142950471U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 526000656022724741U;
            aOrbiterC = RotL64((aOrbiterC * 16688501462334673493U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 6880246132270094141U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 7126466778855297013U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5692237926830293205U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 6436404501390442054U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 1213633065612242699U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17604454985534439259U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 8186529105901185854U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 10607460957358250935U;
            aOrbiterB = RotL64((aOrbiterB * 17172191011625677861U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 9743278964993305169U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 14007577681873418075U;
            aOrbiterE = RotL64((aOrbiterE * 4231122580398039133U), 3U);
            //
            aIngress = RotL64(aOrbiterB, 29U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 23U));
            aIngress = aIngress + (RotL64(aOrbiterG, 60U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterE, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 46U) + RotL64(aOrbiterA, 35U)) + aOrbiterG);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 3U) + RotL64(aOrbiterI, 21U)) + aOrbiterA) + RotL64(aCarry, 41U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 23U) + aOrbiterC) + RotL64(aOrbiterB, 3U));
            aWandererF = aWandererF + (((RotL64(aCross, 35U) + RotL64(aOrbiterE, 26U)) + aOrbiterJ) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterG, 39U)) + aOrbiterD);
            aWandererD = aWandererD + ((RotL64(aScatter, 53U) + aOrbiterH) + RotL64(aOrbiterI, 13U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 29U) + aOrbiterC) + RotL64(aOrbiterH, 51U));
            aWandererH = aWandererH + (((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterG, 56U)) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 58U) + aOrbiterH) + RotL64(aOrbiterJ, 47U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 44U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 13835U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 15202U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15528U)) & W_KEY1], 53U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 14910U)) & W_KEY1], 29U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 14762U)) & S_BLOCK1], 41U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 13948U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 15363U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 50U) + RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 35U) + RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = (aWandererG + RotL64(aPrevious, 57U)) + 16424657151168221875U;
            aOrbiterA = (aWandererD + RotL64(aScatter, 51U)) + 17150123681886380361U;
            aOrbiterK = ((aWandererI + RotL64(aIngress, 29U)) + RotL64(aCarry, 27U)) + 16041993588694572757U;
            aOrbiterF = ((aWandererK + RotL64(aCross, 47U)) + 9871185846434828537U) + aPhaseBOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 6U)) + RotL64(aCarry, 53U)) + 11227236398354430757U;
            aOrbiterJ = (aWandererB + RotL64(aIngress, 39U)) + 5399325217402192631U;
            aOrbiterC = ((aWandererC + RotL64(aCross, 13U)) + 9248828789282890454U) + aPhaseBOrbiterAssignSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aScatter, 43U)) + RotL64(aCarry, 37U)) + 9041370494203701062U;
            aOrbiterH = (aWandererH + RotL64(aIngress, 20U)) + 14944424084524970764U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 5481938174456671041U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 14783648629543752715U;
            aOrbiterK = RotL64((aOrbiterK * 7260164783191886395U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 12355573914530445723U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 9863991559011968318U;
            aOrbiterD = RotL64((aOrbiterD * 8495251211794343179U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 16149688605937250965U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 106041828692026825U;
            aOrbiterC = RotL64((aOrbiterC * 12199934305374582599U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 8076098639554567792U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 11155119311895580013U;
            aOrbiterI = RotL64((aOrbiterI * 1495180896564818647U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 6847612160595917702U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 16094377920388017367U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4875801863643206333U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 13584719866672696684U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 13446209321646234607U;
            aOrbiterA = RotL64((aOrbiterA * 9945349065094781529U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 15829806645369560988U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 12573767256739062550U;
            aOrbiterE = RotL64((aOrbiterE * 5649504278826069077U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 3850030870300393809U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 11857593987748189858U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15942863910931814193U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 5505918410521728373U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 12949653497121247860U;
            aOrbiterH = RotL64((aOrbiterH * 90944913639560027U), 35U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 28U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aPrevious, 46U) + aOrbiterJ) + RotL64(aOrbiterA, 38U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterK, 13U)) + aOrbiterF) + aPhaseBWandererUpdateSaltA[((aIndex + 20U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 47U)) + aOrbiterH);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterA, 19U));
            aWandererG = aWandererG + ((RotL64(aCross, 23U) + aOrbiterC) + RotL64(aOrbiterI, 5U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 51U)) + aOrbiterA);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 57U)) + aOrbiterD) + RotL64(aCarry, 57U)) + aPhaseBWandererUpdateSaltC[((aIndex + 28U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 42U) + RotL64(aOrbiterF, 23U)) + aOrbiterH);
            aWandererI = aWandererI + (((RotL64(aCross, 53U) + aOrbiterE) + RotL64(aOrbiterA, 34U)) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 12U));
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + RotL64(aWandererH, 51U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 16527U)) & S_BLOCK1], 47U) ^ RotL64(aKeyRowReadA[((aIndex + 18968U)) & W_KEY1], 19U));
            aIngress ^= (RotL64(mSource[((aIndex + 18785U)) & S_BLOCK1], 30U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 18224U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 18700U)) & W_KEY1], 56U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 18599U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17308U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aPrevious, 23U)) + (RotL64(aIngress, 52U) ^ RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = (aWandererD + RotL64(aCross, 30U)) + 3612110001869385068U;
            aOrbiterD = (((aWandererG + RotL64(aIngress, 13U)) + RotL64(aCarry, 41U)) + 16340824141280225936U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 43U)) + 15222338965130765231U) + aPhaseCOrbiterAssignSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = (aWandererE + RotL64(aScatter, 23U)) + 6649270508107155041U;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 3U)) + RotL64(aCarry, 29U)) + 768217258655426384U;
            aOrbiterK = (aWandererI + RotL64(aIngress, 51U)) + 4481855259658861851U;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 38U)) + RotL64(aCarry, 5U)) + 18318041934562434016U;
            aOrbiterG = (aWandererA + RotL64(aCross, 47U)) + 4212457153804401807U;
            aOrbiterB = (aWandererB + RotL64(aScatter, 19U)) + 16143621095636987628U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 2095664232866642086U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 4339527736737366572U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17503569508822244125U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 13679353177869884790U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 11582168502846418236U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 135539430034462861U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 10451330452898542191U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 12951448817640617841U;
            aOrbiterF = RotL64((aOrbiterF * 4141870904192742091U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 15389161934419370747U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 4754886272708253014U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16638243718191281597U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 11746389873929280688U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 12042680172517298768U;
            aOrbiterJ = RotL64((aOrbiterJ * 3814780289755857543U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 2648103752465009244U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 451594673632597973U;
            aOrbiterB = RotL64((aOrbiterB * 8496763663271072425U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 5696534794094099710U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 14609435045257077395U;
            aOrbiterC = RotL64((aOrbiterC * 14658408563237468407U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 11599395126850950133U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 12699598504604446664U;
            aOrbiterA = RotL64((aOrbiterA * 14313494063098111823U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 9398465148537154745U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 12139736860648011256U;
            aOrbiterK = RotL64((aOrbiterK * 15257503229375247987U), 27U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 37U);
            aIngress = aIngress + (RotL64(aOrbiterI, 26U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aCross, 13U) + aOrbiterJ) + RotL64(aOrbiterD, 10U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterJ, 47U)) + aOrbiterC);
            aWandererE = aWandererE + ((RotL64(aScatter, 28U) + aOrbiterJ) + RotL64(aOrbiterA, 3U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterF, 43U)) + aOrbiterA);
            aWandererA = aWandererA + (((RotL64(aIngress, 19U) + RotL64(aOrbiterB, 34U)) + aOrbiterA) + RotL64(aCarry, 37U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterD, 39U)) + aOrbiterF) + aPhaseCWandererUpdateSaltE[((aIndex + 10U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 37U) + aOrbiterK) + RotL64(aOrbiterG, 23U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 23U) + aOrbiterK) + RotL64(aOrbiterF, 53U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 46U) + RotL64(aOrbiterI, 57U)) + aOrbiterJ) + RotL64(aCarry, 13U)) + aPhaseCWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 46U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 20489U)) & S_BLOCK1], 29U) ^ RotL64(mSource[((aIndex + 19954U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aWorkLaneA[((aIndex + 20363U)) & S_BLOCK1], 38U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 20332U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 21091U)) & W_KEY1], 53U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 19462U)) & W_KEY1], 19U));
            aCross ^= (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19485U)) & S_BLOCK1], 44U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 20885U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCross, 53U)) + (RotL64(aPrevious, 4U) + RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = ((aWandererJ + RotL64(aCross, 20U)) + 18255347001097480328U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = ((aWandererG + RotL64(aScatter, 43U)) + RotL64(aCarry, 13U)) + 13679246790311505735U;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 53U)) + 10565839529765027116U;
            aOrbiterB = (((aWandererK + RotL64(aIngress, 29U)) + RotL64(aCarry, 27U)) + 14327172566224769901U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aScatter, 35U)) + 16239024612038195174U;
            aOrbiterH = (aWandererF + RotL64(aIngress, 57U)) + 13800012174212131890U;
            aOrbiterE = (aWandererE + RotL64(aCross, 47U)) + 13900288860157577583U;
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 14U)) + RotL64(aCarry, 5U)) + 4144386119777112740U;
            aOrbiterI = (aWandererB + RotL64(aScatter, 5U)) + 3154558262670631372U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 7456728543137614001U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 11709519851158935384U;
            aOrbiterG = RotL64((aOrbiterG * 7016689518570071587U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 15607438907832240304U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 9276575329661725624U;
            aOrbiterH = RotL64((aOrbiterH * 8879744070762412745U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 6459435969129449226U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 6442382118416542275U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2921027306686588233U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 12117432107282150865U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 6831279293184793243U;
            aOrbiterI = RotL64((aOrbiterI * 2435360641135249073U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 9520022957804572889U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 8322178689474588679U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1627707191467537115U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 4162401591586869316U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 8994015844714895961U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15421910378057951895U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 10038095909727959633U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 17756404450592957616U;
            aOrbiterA = RotL64((aOrbiterA * 14255952184627347295U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 3379089265413427719U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 11341713098678108441U;
            aOrbiterB = RotL64((aOrbiterB * 2500587373161411961U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 4030296130743454165U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 6332387792111212064U;
            aOrbiterJ = RotL64((aOrbiterJ * 16490982218150897861U), 39U);
            //
            aIngress = RotL64(aOrbiterH, 60U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterB, 10U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aCross, 35U) + aOrbiterH) + RotL64(aOrbiterA, 53U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterI, 5U)) + aOrbiterJ);
            aWandererB = aWandererB + ((RotL64(aPrevious, 51U) + aOrbiterB) + RotL64(aOrbiterA, 10U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 6U) + aOrbiterG) + RotL64(aOrbiterB, 35U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 23U) + aOrbiterB) + RotL64(aOrbiterE, 23U)) + RotL64(aCarry, 41U)) + aPhaseCWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 57U)) + aOrbiterI);
            aWandererK = aWandererK + (((RotL64(aCross, 27U) + RotL64(aOrbiterG, 14U)) + aOrbiterA) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 10U) + aOrbiterB) + RotL64(aOrbiterF, 19U)) + aPhaseCWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 39U) + aOrbiterI) + RotL64(aOrbiterF, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 46U));
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + RotL64(aWandererC, 57U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 23061U)) & S_BLOCK1], 37U) ^ RotL64(aKeyRowReadA[((aIndex + 21988U)) & W_KEY1], 5U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 23103U)) & W_KEY1], 18U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 22692U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 23355U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22674U)) & S_BLOCK1], 13U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 22022U)) & S_BLOCK1], 52U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 23750U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aPrevious, 24U)) + (RotL64(aCarry, 37U) ^ RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 43U)) + RotL64(aCarry, 51U)) + 13204735390996728477U;
            aOrbiterG = (aWandererC + RotL64(aIngress, 5U)) + 851171359595647173U;
            aOrbiterA = (aWandererE + RotL64(aScatter, 14U)) + 16745304202825290723U;
            aOrbiterE = ((aWandererI + RotL64(aCross, 23U)) + 562392736584913979U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aIngress, 39U)) + 3244267012529053918U;
            aOrbiterC = ((aWandererG + RotL64(aCross, 27U)) + RotL64(aCarry, 29U)) + 17282536111067869133U;
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 19U)) + 14851130066471729068U) + aPhaseCOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aScatter, 54U)) + RotL64(aCarry, 13U)) + 5256130407952363129U;
            aOrbiterK = (aWandererD + RotL64(aCross, 35U)) + 2904742485828362001U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 3723346325449225387U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 5344621093694027341U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9044881458629673499U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 12919263300833603026U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 17989801264160996071U;
            aOrbiterG = RotL64((aOrbiterG * 15468293047311883751U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 5022175042377172157U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 16684822380107847758U;
            aOrbiterE = RotL64((aOrbiterE * 2834049270263837537U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 2740326510600876682U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 13981423865219318820U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14593082145080056441U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 231945878229848395U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 14139797734944312580U;
            aOrbiterC = RotL64((aOrbiterC * 6492256080432266407U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 16704102101387552373U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 8506734780526852552U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4684566118627414659U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 2774630043988894695U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 12490034334296488127U;
            aOrbiterK = RotL64((aOrbiterK * 16765455396278233145U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 545238171291436006U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 1023872898002379590U;
            aOrbiterD = RotL64((aOrbiterD * 8626333831510136515U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 5065187021047872560U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 10391809965648089863U;
            aOrbiterH = RotL64((aOrbiterH * 10912471108849550469U), 19U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 43U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 14U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 39U));
            aIngress = aIngress + (RotL64(aOrbiterH, 23U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aPrevious, 34U) + aOrbiterA) + RotL64(aOrbiterD, 47U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 51U) + aOrbiterB) + RotL64(aOrbiterK, 52U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 21U) + aOrbiterH) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterI, 19U)) + aOrbiterD);
            aWandererD = aWandererD + (((RotL64(aIngress, 27U) + RotL64(aOrbiterG, 29U)) + aOrbiterK) + aPhaseCWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 37U)) + aOrbiterA);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 58U) + aOrbiterG) + RotL64(aOrbiterB, 23U)) + RotL64(aCarry, 21U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterE, 43U));
            aWandererE = aWandererE + ((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 56U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 24U));
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 50U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 26190U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadA[((aIndex + 24766U)) & W_KEY1], 3U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 24979U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((aIndex + 27225U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 26190U)) & W_KEY1], 21U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26767U)) & S_BLOCK1], 57U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 25186U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 25421U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aIngress, 28U)) + (RotL64(aCross, 13U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (aWandererH + RotL64(aScatter, 27U)) + 3970829908171131502U;
            aOrbiterB = (((aWandererG + RotL64(aCross, 51U)) + RotL64(aCarry, 57U)) + 7040283759419531991U) + aPhaseDOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aIngress, 47U)) + RotL64(aCarry, 23U)) + 11856292169397052901U;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 13U)) + 819598588791819022U;
            aOrbiterA = (aWandererI + RotL64(aCross, 22U)) + 2176451710970866848U;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 37U)) + RotL64(aCarry, 11U)) + 6454704928613390494U;
            aOrbiterG = (aWandererB + RotL64(aIngress, 5U)) + 11792122387218053841U;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 41U)) + 9254780213489752211U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aCross, 60U)) + 16591812589999846482U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 1471246223935074832U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 1424843083106386453U;
            aOrbiterH = RotL64((aOrbiterH * 15020536982657410783U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 1856469958050891629U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 6331743690452052712U;
            aOrbiterD = RotL64((aOrbiterD * 15327924647897459645U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 10351075711345476487U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 9518585245330480185U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3792179827396760391U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 17787514620244712033U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 14182328067398162557U;
            aOrbiterG = RotL64((aOrbiterG * 18107337388659070197U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 12798088948801072444U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 9563215159275202323U;
            aOrbiterI = RotL64((aOrbiterI * 7058145016617349141U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 9904919772580498232U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 16579777394992143043U;
            aOrbiterA = RotL64((aOrbiterA * 10516761340320196661U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 6344049286854588503U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 3531503618941046788U;
            aOrbiterK = RotL64((aOrbiterK * 10855385899703024105U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 11334308840132700377U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 11093833870078787770U;
            aOrbiterF = RotL64((aOrbiterF * 16105889714648555755U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 3831491136025364271U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 12505259454860591372U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6135450888433504093U), 39U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterD, 37U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 51U));
            aIngress = aIngress + (RotL64(aOrbiterC, 44U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + RotL64(aOrbiterF, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 26U) + aOrbiterD) + RotL64(aOrbiterK, 47U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterG, 19U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 41U) + aOrbiterK) + RotL64(aOrbiterB, 23U));
            aWandererI = aWandererI + (((RotL64(aScatter, 47U) + aOrbiterF) + RotL64(aOrbiterC, 28U)) + RotL64(aCarry, 35U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterF, 13U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 30U) + RotL64(aOrbiterI, 39U)) + aOrbiterC) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 5U)) + aOrbiterD);
            aWandererA = aWandererA + ((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterH, 34U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 11U) + aOrbiterC) + RotL64(aOrbiterH, 57U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 4U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 29507U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneD[((aIndex + 28818U)) & S_BLOCK1], 48U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 28581U)) & W_KEY1], 19U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 27509U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 27432U)) & W_KEY1], 13U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29232U)) & S_BLOCK1], 39U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28835U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneB[((aIndex + 28864U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCarry, 53U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCross, 10U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = (aWandererF + RotL64(aPrevious, 27U)) + 5960680319644404115U;
            aOrbiterC = (((aWandererC + RotL64(aIngress, 58U)) + RotL64(aCarry, 5U)) + 16050752633567034185U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = ((aWandererH + RotL64(aCross, 23U)) + 8447503223226854741U) + aPhaseDOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aScatter, 47U)) + 14176813813397917591U;
            aOrbiterH = (aWandererA + RotL64(aIngress, 5U)) + 10534915376130006644U;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 53U)) + RotL64(aCarry, 53U)) + 6866224454375302514U;
            aOrbiterF = ((aWandererI + RotL64(aCross, 43U)) + RotL64(aCarry, 23U)) + 16506374165041008396U;
            aOrbiterD = (aWandererK + RotL64(aPrevious, 34U)) + 7167814023968794098U;
            aOrbiterG = (aWandererG + RotL64(aCross, 13U)) + 13870852197416596664U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 18064038854848993105U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 9869630811507771691U;
            aOrbiterJ = RotL64((aOrbiterJ * 13723164383800461387U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 863613100452759380U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 16597969741225436529U;
            aOrbiterI = RotL64((aOrbiterI * 2680793528887208903U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 6575347108051310653U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 17062262265485019063U;
            aOrbiterH = RotL64((aOrbiterH * 7601045488473620019U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 7193399224636409133U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 14146747818810433849U;
            aOrbiterD = RotL64((aOrbiterD * 5273185769989530041U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 9441449106442431427U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 4303295336545399503U;
            aOrbiterG = RotL64((aOrbiterG * 8829695296836242587U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 12604760768543193458U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 15779327512379787715U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14000905201441272597U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 15553000781122708728U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 17162740616060079717U;
            aOrbiterF = RotL64((aOrbiterF * 9458662233556750239U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 1032374679817715156U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 16413393156165548232U;
            aOrbiterK = RotL64((aOrbiterK * 549659738811935015U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 14056855000013992045U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 7399202019042538829U;
            aOrbiterC = RotL64((aOrbiterC * 6103508549612077695U), 47U);
            //
            aIngress = RotL64(aOrbiterF, 40U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterD, 53U)) + aOrbiterB) + aPhaseDWandererUpdateSaltC[((aIndex + 14U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aIngress, 46U) + aOrbiterF) + RotL64(aOrbiterJ, 23U)) + RotL64(aCarry, 19U)) + aPhaseDWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 41U) + aOrbiterG) + RotL64(aOrbiterJ, 5U));
            aWandererB = aWandererB + (((RotL64(aScatter, 13U) + aOrbiterC) + RotL64(aOrbiterK, 58U)) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterI, 27U)) + aOrbiterK);
            aWandererF = aWandererF + ((RotL64(aIngress, 53U) + RotL64(aOrbiterD, 43U)) + aOrbiterK);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 30U) + RotL64(aOrbiterJ, 35U)) + aOrbiterI);
            aWandererG = aWandererG + ((RotL64(aCross, 21U) + RotL64(aOrbiterB, 47U)) + aOrbiterH);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 18U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 34U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererA, 44U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 31816U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 30874U)) & W_KEY1], 48U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 31849U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30967U)) & S_BLOCK1], 48U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32428U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadB[((aIndex + 30091U)) & W_KEY1], 29U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aPrevious, 4U)) ^ (RotL64(aCarry, 47U) ^ RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = ((aWandererA + RotL64(aIngress, 12U)) + RotL64(aCarry, 21U)) + 13499155707765393469U;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 29U)) + RotL64(aCarry, 5U)) + 3740324981823726185U;
            aOrbiterH = (aWandererG + RotL64(aScatter, 57U)) + 5470765363949735652U;
            aOrbiterJ = (aWandererF + RotL64(aCross, 19U)) + 3446436171274452326U;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 6U)) + 1778929412631211933U) + aPhaseDOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (aWandererE + RotL64(aCross, 47U)) + 14666308799855220954U;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 39U)) + 4548410236791175055U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aScatter, 35U)) + 5829739767694190372U;
            aOrbiterF = ((aWandererI + RotL64(aCross, 43U)) + RotL64(aCarry, 57U)) + 14319231414903675748U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 1513851750246111405U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 1685620217748986019U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9286548037413609445U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 16284162182006054402U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 6271539598462003309U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13923286694131331137U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 12669312437565969473U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 11894755313393001665U;
            aOrbiterA = RotL64((aOrbiterA * 12556759675372354075U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 6315983824634946566U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 17106616474222892782U;
            aOrbiterE = RotL64((aOrbiterE * 167205520766791073U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 13350266700180455548U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 4608846311203767162U;
            aOrbiterB = RotL64((aOrbiterB * 2504857468837437365U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 14195866746143604365U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 7917977448256795054U;
            aOrbiterJ = RotL64((aOrbiterJ * 5927771378657284557U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 10707336923305131629U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 17122696159336995392U;
            aOrbiterG = RotL64((aOrbiterG * 13953518568670659191U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 5182322763573586116U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 6503754948502556246U;
            aOrbiterF = RotL64((aOrbiterF * 14749002194140663519U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 14907832047832987341U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 6258064448676621346U;
            aOrbiterK = RotL64((aOrbiterK * 4407960312705621487U), 19U);
            //
            aIngress = RotL64(aOrbiterE, 46U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 60U) + RotL64(aOrbiterA, 30U)) + aOrbiterK) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 21U)) + aOrbiterF);
            aWandererA = aWandererA + ((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 43U)) + aOrbiterH);
            aWandererE = aWandererE ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterE, 39U)) + aOrbiterG) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 41U) + aOrbiterB) + RotL64(aOrbiterE, 11U)) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterK, 47U)) + aOrbiterJ) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 24U) + RotL64(aOrbiterE, 54U)) + aOrbiterA);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterH, 3U)) + aOrbiterA);
            aWandererF = aWandererF + ((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterF, 35U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + (RotL64(aWandererK, 24U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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

void TwistExpander_Fencing_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 8044U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((aIndex + 2791U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 3959U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5533U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 4013U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 4803U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 10U) + RotL64(aIngress, 53U)) ^ (RotL64(aCross, 39U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = (aWandererG + RotL64(aIngress, 47U)) + 2330952702412094686U;
            aOrbiterE = (((aWandererJ + RotL64(aPrevious, 13U)) + RotL64(aCarry, 53U)) + 7820188225935060799U) + aPhaseEOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = ((aWandererC + RotL64(aScatter, 27U)) + RotL64(aCarry, 37U)) + 9347644591709839145U;
            aOrbiterD = (aWandererA + RotL64(aCross, 37U)) + 2288624878446846870U;
            aOrbiterC = (aWandererE + RotL64(aScatter, 5U)) + 9358977729492824128U;
            aOrbiterK = (((aWandererK + RotL64(aCross, 60U)) + RotL64(aCarry, 5U)) + 1858511275052455039U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = (aWandererF + RotL64(aPrevious, 21U)) + 13715478509322292552U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 16413396625604260455U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 17714322215518432705U;
            aOrbiterI = RotL64((aOrbiterI * 1904184102419934333U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 16188315436202861122U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 5564445841368207813U;
            aOrbiterE = RotL64((aOrbiterE * 14125834616162835983U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 13717068949900594673U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 14143659432287313765U;
            aOrbiterK = RotL64((aOrbiterK * 17281441046722262917U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 5729546141908425670U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 4297827922736712074U;
            aOrbiterD = RotL64((aOrbiterD * 13631630436759768885U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 829520109395163673U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 11547160328525174295U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4759690159673049775U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 2907177944512117206U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 11100346409065275671U;
            aOrbiterJ = RotL64((aOrbiterJ * 17927994356809011637U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 1344592529249949068U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 6470438516791143572U;
            aOrbiterF = RotL64((aOrbiterF * 13339390828725370475U), 3U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterK, 35U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 14U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 29U) + aOrbiterD) + RotL64(aOrbiterK, 21U));
            aWandererG = aWandererG + (((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterE, 60U)) + RotL64(aCarry, 23U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 13U)) + aOrbiterK);
            aWandererF = aWandererF + ((RotL64(aIngress, 41U) + RotL64(aOrbiterD, 35U)) + aOrbiterE);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 53U) + aOrbiterI) + RotL64(aOrbiterD, 47U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 20U) + RotL64(aOrbiterJ, 3U)) + aOrbiterI) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterF, 53U)) + aPhaseEWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 6U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 8324U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneC[((aIndex + 15848U)) & S_BLOCK1], 34U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 12052U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneC[((aIndex + 12943U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 15808U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9299U)) & S_BLOCK1], 6U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 9302U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 27U) + RotL64(aPrevious, 41U)) ^ (RotL64(aCross, 57U) + RotL64(aIngress, 14U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = ((aWandererB + RotL64(aCross, 53U)) + RotL64(aCarry, 11U)) + 10881271196314989997U;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 21U)) + 6406461249988567558U) + aPhaseEOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 35U)) + 17255067918280095959U;
            aOrbiterI = (aWandererA + RotL64(aScatter, 11U)) + 16690850682497718411U;
            aOrbiterG = (((aWandererJ + RotL64(aIngress, 47U)) + RotL64(aCarry, 37U)) + 5576201059361086866U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aScatter, 60U)) + RotL64(aCarry, 23U)) + 11991259685693687554U;
            aOrbiterD = (aWandererD + RotL64(aPrevious, 3U)) + 14652535244217836909U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 1701789037170782122U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 953429054903473833U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13482379459700651427U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 12064513610469714211U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 7993881398822002424U;
            aOrbiterF = RotL64((aOrbiterF * 11572884842788918377U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 14421313768013320050U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 11112386845630998889U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11771526352030371669U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 17069630896535699015U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 3308240081138623373U;
            aOrbiterI = RotL64((aOrbiterI * 10449509484417835159U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 17615529807112933619U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 11782807146851563541U;
            aOrbiterG = RotL64((aOrbiterG * 12992075832343669221U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 14401645829607611983U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 6736397344219993532U;
            aOrbiterD = RotL64((aOrbiterD * 1667287547938175641U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 6446974060524700550U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 7840991992443308254U;
            aOrbiterC = RotL64((aOrbiterC * 6891023544882740107U), 51U);
            //
            aIngress = RotL64(aOrbiterD, 14U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + (RotL64(aOrbiterF, 41U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterI, 29U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterF, 41U));
            aWandererF = aWandererF + (((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterG, 57U)) + RotL64(aCarry, 27U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterC, 5U)) + aOrbiterJ);
            aWandererC = aWandererC + (((RotL64(aCross, 40U) + RotL64(aOrbiterF, 19U)) + aOrbiterC) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 51U) + aOrbiterG) + RotL64(aOrbiterD, 11U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterD, 48U)) + aOrbiterB) + aPhaseEWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 42U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 17314U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((aIndex + 18215U)) & S_BLOCK1], 47U));
            aIngress ^= (RotL64(aExpandLaneB[((aIndex + 17703U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20592U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 20131U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 22195U)) & S_BLOCK1], 14U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20978U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 4U) ^ RotL64(aCross, 23U)) ^ (RotL64(aIngress, 53U) + RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = (aWandererC + RotL64(aPrevious, 3U)) + 16189787374324972735U;
            aOrbiterA = (aWandererD + RotL64(aCross, 29U)) + 17563763730956242224U;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 19U)) + 10572803498593789385U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aScatter, 12U)) + RotL64(aCarry, 3U)) + 7713105232072974166U;
            aOrbiterD = ((aWandererF + RotL64(aCross, 35U)) + RotL64(aCarry, 39U)) + 10760839534772718139U;
            aOrbiterG = (((aWandererI + RotL64(aPrevious, 53U)) + RotL64(aCarry, 53U)) + 13397069448391230253U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = (aWandererK + RotL64(aScatter, 47U)) + 4569255679998375682U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 9888769350817876949U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 11351796060878856300U;
            aOrbiterK = RotL64((aOrbiterK * 13356749147334008399U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 18153775071965707204U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 1282846411145853435U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12294455920906257823U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 16457743979262460660U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 173493260775251032U;
            aOrbiterD = RotL64((aOrbiterD * 4935807229040883505U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 3927345926316409630U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 5158769729850853623U;
            aOrbiterI = RotL64((aOrbiterI * 2446452358663812945U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 12331351600010165154U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 3940794200348684050U;
            aOrbiterG = RotL64((aOrbiterG * 13248997263062075043U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 11248514843822945425U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 1391497323278226522U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8376841806072565005U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 13265623528678787307U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 2802033745265647317U;
            aOrbiterB = RotL64((aOrbiterB * 3437626962562016147U), 51U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterI, 5U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 21U) + aOrbiterG) + RotL64(aOrbiterD, 53U)) + aPhaseEWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 53U) + aOrbiterA) + RotL64(aOrbiterK, 23U));
            aWandererK = aWandererK + (((RotL64(aCross, 11U) + RotL64(aOrbiterI, 6U)) + aOrbiterE) + RotL64(aCarry, 57U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 46U) + RotL64(aOrbiterD, 13U)) + aOrbiterA);
            aWandererH = aWandererH + (((RotL64(aScatter, 5U) + RotL64(aOrbiterA, 47U)) + aOrbiterB) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterI, 37U)) + aOrbiterG);
            aWandererD = aWandererD + (((RotL64(aCross, 27U) + aOrbiterK) + RotL64(aOrbiterD, 29U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 18U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + RotL64(aWandererK, 53U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 26118U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((aIndex + 27414U)) & S_BLOCK1], 39U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 26751U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 31684U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29764U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27270U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 27114U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCarry, 11U)) ^ (RotL64(aCross, 53U) + RotL64(aPrevious, 28U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = (aWandererD + RotL64(aIngress, 41U)) + 12426357877879529292U;
            aOrbiterC = (((aWandererF + RotL64(aPrevious, 60U)) + RotL64(aCarry, 41U)) + 12604900366173639176U) + aPhaseEOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aScatter, 21U)) + 13511119007338929401U;
            aOrbiterJ = (((aWandererB + RotL64(aCross, 35U)) + RotL64(aCarry, 3U)) + 9878720081166788060U) + aPhaseEOrbiterAssignSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = (aWandererG + RotL64(aScatter, 51U)) + 15463195409806395076U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 27U)) + RotL64(aCarry, 27U)) + 6407922778852833423U;
            aOrbiterH = (aWandererC + RotL64(aPrevious, 11U)) + 7690427254160734016U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 18030974031722143619U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 17983938038322737041U;
            aOrbiterG = RotL64((aOrbiterG * 12479365337221685413U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 16605512170117753884U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 681802273302348322U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14608920184802647123U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 15550312921312083819U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 17824154101711884508U;
            aOrbiterK = RotL64((aOrbiterK * 7358612830654795357U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 1939207786756735430U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 3132864634777826569U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13606281919426730325U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 12822929773923954849U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 16576106045887115660U;
            aOrbiterC = RotL64((aOrbiterC * 16370914370769903051U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 2398825881649235260U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 13700821892926092479U;
            aOrbiterH = RotL64((aOrbiterH * 10830623703416956043U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 2439833784883391606U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 15870638514107637833U;
            aOrbiterE = RotL64((aOrbiterE * 3797380922767479287U), 29U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterH, 5U);
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 12U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterF, 41U)) + aOrbiterK);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 5U) + aOrbiterH) + RotL64(aOrbiterG, 22U)) + RotL64(aCarry, 39U)) + aPhaseEWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterG, 3U)) + aOrbiterC);
            aWandererF = aWandererF + ((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 13U)) + aOrbiterH);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 30U) + aOrbiterF) + RotL64(aOrbiterC, 29U));
            aWandererC = aWandererC + (((RotL64(aCross, 13U) + aOrbiterE) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterJ, 51U)) + aOrbiterC) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 44U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 3U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

void TwistExpander_Fencing_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 701U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneB[((aIndex + 7662U)) & S_BLOCK1], 34U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 4618U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7461U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 6621U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 7698U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCross, 6U)) + (RotL64(aIngress, 53U) + RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = (aWandererK + RotL64(aScatter, 53U)) + 15652862298542575895U;
            aOrbiterF = (aWandererB + RotL64(aIngress, 60U)) + 16925323928418184554U;
            aOrbiterB = (((aWandererF + RotL64(aPrevious, 21U)) + RotL64(aCarry, 13U)) + 4413861484961668394U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = ((aWandererI + RotL64(aCross, 27U)) + 2215946422098155969U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aScatter, 43U)) + 14975185533513111110U;
            aOrbiterA = (aWandererH + RotL64(aCross, 18U)) + 9711613814905834552U;
            aOrbiterE = (aWandererE + RotL64(aPrevious, 23U)) + 13154957291850149471U;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 41U)) + RotL64(aCarry, 29U)) + 5058313016418534840U;
            aOrbiterG = (aWandererJ + RotL64(aCross, 35U)) + 15011423472941211620U;
            aOrbiterD = (aWandererD + RotL64(aIngress, 13U)) + 2030053257469580168U;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 5U)) + RotL64(aCarry, 41U)) + 150530795186791193U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 10878237472104183427U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 11724672539469573109U;
            aOrbiterB = RotL64((aOrbiterB * 16158741837357985395U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 9589700906445846956U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 1367381624958248949U;
            aOrbiterJ = RotL64((aOrbiterJ * 8459515089081211977U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 12003215666757518106U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 11232479330848006729U;
            aOrbiterE = RotL64((aOrbiterE * 10993290955464593033U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 13013910456628561621U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 6092509838924105265U;
            aOrbiterG = RotL64((aOrbiterG * 805601154718006061U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 11999225836250312801U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 14421271973875748413U;
            aOrbiterD = RotL64((aOrbiterD * 9529010940887430157U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 15536288285741825272U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 2071793889925436679U;
            aOrbiterF = RotL64((aOrbiterF * 1526376970151714589U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 5622386476463436967U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 16147972771639168516U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11826916832825159095U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 4519892856053952290U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 12059500374938843538U;
            aOrbiterI = RotL64((aOrbiterI * 14987533625537956299U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 4547335128847992282U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 15378473334472216418U;
            aOrbiterH = RotL64((aOrbiterH * 13907560285280544037U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 14644123269581735633U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 6434315615480805381U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4335857173941645355U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 14241680137158382296U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 15652862298542575895U;
            aOrbiterK = RotL64((aOrbiterK * 4190840063924551519U), 37U);
            //
            aIngress = RotL64(aOrbiterI, 13U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 50U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 39U));
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterB, 11U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aPrevious, 19U) + aOrbiterB) + RotL64(aOrbiterD, 50U)) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 56U) + aOrbiterC) + RotL64(aOrbiterF, 13U));
            aWandererH = aWandererH + ((RotL64(aIngress, 51U) + RotL64(aOrbiterH, 29U)) + aOrbiterJ);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 19U)) + aOrbiterG);
            aWandererA = aWandererA + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterG, 5U)) + aOrbiterA) + RotL64(aCarry, 35U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterA, 57U));
            aWandererK = aWandererK + ((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 3U)) + aOrbiterH);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 58U) + RotL64(aOrbiterE, 21U)) + aOrbiterI);
            aWandererG = aWandererG + ((RotL64(aIngress, 3U) + aOrbiterI) + RotL64(aOrbiterK, 42U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 13U) + aOrbiterB) + RotL64(aOrbiterI, 39U)) + aPhaseFWandererUpdateSaltC[((aIndex + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 50U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 14U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererJ, 21U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 13886U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneC[((aIndex + 11682U)) & S_BLOCK1], 38U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 9675U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 13728U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 10606U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 11398U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 11155U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 41U)) + (RotL64(aCarry, 19U) + RotL64(aPrevious, 54U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = ((aWandererI + RotL64(aCross, 37U)) + 17225673071833726819U) + aPhaseFOrbiterAssignSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = ((aWandererF + RotL64(aScatter, 57U)) + RotL64(aCarry, 19U)) + 10301458382103627331U;
            aOrbiterC = (aWandererK + RotL64(aPrevious, 35U)) + 3960233050857362414U;
            aOrbiterH = (((aWandererE + RotL64(aIngress, 6U)) + RotL64(aCarry, 23U)) + 17768665685046605837U) + aPhaseFOrbiterAssignSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aCross, 19U)) + RotL64(aCarry, 47U)) + 14471018461213959767U;
            aOrbiterD = (aWandererB + RotL64(aIngress, 51U)) + 10730597892721340453U;
            aOrbiterE = (aWandererD + RotL64(aScatter, 47U)) + 14863394003122760542U;
            aOrbiterB = (aWandererH + RotL64(aPrevious, 26U)) + 9948587274816688296U;
            aOrbiterJ = (aWandererJ + RotL64(aCross, 21U)) + 3573569431435100993U;
            aOrbiterG = (aWandererC + RotL64(aPrevious, 53U)) + 8153670675740450590U;
            aOrbiterI = (aWandererG + RotL64(aIngress, 11U)) + 16438856577722561424U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 15765587867581925041U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 1082039522061775213U;
            aOrbiterC = RotL64((aOrbiterC * 17023740047246402641U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 4202521649260798876U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 15877659681260461141U;
            aOrbiterF = RotL64((aOrbiterF * 11369910758551088173U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 2551560426129646123U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 3005102326163906320U;
            aOrbiterH = RotL64((aOrbiterH * 4241583192662435107U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 1675501058857208089U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 12774812270956702043U;
            aOrbiterB = RotL64((aOrbiterB * 5488437008504905105U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 1044886020922563597U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 4857445127457225171U;
            aOrbiterG = RotL64((aOrbiterG * 13223560654459705259U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 11548725551787560962U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 2434677823189765161U;
            aOrbiterK = RotL64((aOrbiterK * 4283026044563670969U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 9606875320524736294U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 13732615866277657704U;
            aOrbiterI = RotL64((aOrbiterI * 3905528919281629775U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 13921743663803299567U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 13350829301153929899U;
            aOrbiterJ = RotL64((aOrbiterJ * 11858642286713079795U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 9473349030551400156U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 7446792050826434742U;
            aOrbiterE = RotL64((aOrbiterE * 6619682184124713031U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 17970527747978977453U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 2326714817603921480U;
            aOrbiterA = RotL64((aOrbiterA * 14581676978186226887U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 7875511075130474136U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 17225673071833726819U;
            aOrbiterD = RotL64((aOrbiterD * 1196024136909896027U), 23U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterE, 5U);
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 43U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + RotL64(aOrbiterC, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 26U) + RotL64(aOrbiterD, 58U)) + aOrbiterE);
            aWandererI = aWandererI + ((RotL64(aIngress, 39U) + aOrbiterC) + RotL64(aOrbiterD, 21U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterB, 5U)) + aOrbiterF);
            aWandererH = aWandererH + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 39U)) + aOrbiterK) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterH, 43U)) + aOrbiterK);
            aWandererB = aWandererB + (((RotL64(aIngress, 35U) + aOrbiterH) + RotL64(aOrbiterG, 41U)) + aPhaseFWandererUpdateSaltE[((aIndex + 6U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterC, 23U)) + aOrbiterJ);
            aWandererD = aWandererD + ((RotL64(aCross, 53U) + RotL64(aOrbiterB, 52U)) + aOrbiterD);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterE, 37U)) + aOrbiterI);
            aWandererE = aWandererE + (((RotL64(aIngress, 3U) + RotL64(aOrbiterB, 29U)) + aOrbiterG) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 58U) + RotL64(aOrbiterK, 3U)) + aOrbiterA) + aPhaseFWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 30U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + RotL64(aWandererJ, 60U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 19358U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 19507U)) & S_BLOCK1], 38U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 19403U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22913U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17496U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 21586U)) & S_BLOCK1], 60U));
            aCross ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 20129U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 43U) + RotL64(aIngress, 11U)) + (RotL64(aCarry, 30U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 53U)) + RotL64(aCarry, 23U)) + 9023059520606551446U;
            aOrbiterC = (aWandererK + RotL64(aScatter, 60U)) + 662441755115638133U;
            aOrbiterB = ((aWandererJ + RotL64(aCross, 23U)) + 16957253361196144712U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = (aWandererD + RotL64(aPrevious, 39U)) + 7840955025765308605U;
            aOrbiterK = (aWandererI + RotL64(aCross, 19U)) + 346855809270395799U;
            aOrbiterI = (aWandererE + RotL64(aIngress, 48U)) + 16099139781586668343U;
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 3U)) + 3706457327118322098U) + aPhaseFOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aScatter, 43U)) + RotL64(aCarry, 43U)) + 12166825885547622870U;
            aOrbiterG = (aWandererB + RotL64(aIngress, 35U)) + 7792658665720344200U;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 51U)) + 7128477606152986326U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 29U)) + RotL64(aCarry, 35U)) + 11116533962780290084U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 10443889548568288532U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 4402387036946561017U;
            aOrbiterB = RotL64((aOrbiterB * 9032964741841833277U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 13002706161178447654U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 13929727277530310708U;
            aOrbiterC = RotL64((aOrbiterC * 7005639090871200285U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 10949073760696935106U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 15405923432006783533U;
            aOrbiterF = RotL64((aOrbiterF * 17989565878445202495U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 18096057968822208905U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 3032155040484574973U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 448597307502544605U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 17462076466907467134U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 15471015427013701406U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6113474000571976139U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 3549031751266594344U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 14243218483842508113U;
            aOrbiterH = RotL64((aOrbiterH * 9041601306479302047U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 5803147589312920032U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 5549470512227427855U;
            aOrbiterA = RotL64((aOrbiterA * 12592362489263862879U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 10076661824293832189U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 3196799148974716550U;
            aOrbiterD = RotL64((aOrbiterD * 8183276968961467775U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 5245559903456662243U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 5907555542861339984U;
            aOrbiterJ = RotL64((aOrbiterJ * 10224549416454347583U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 12670710096595941569U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 655047039452620836U;
            aOrbiterG = RotL64((aOrbiterG * 9717552134857988153U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 2654837870443908572U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 9023059520606551446U;
            aOrbiterK = RotL64((aOrbiterK * 170905364378771841U), 13U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterI, 11U);
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 41U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 56U));
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 41U) + RotL64(aOrbiterB, 10U)) + aOrbiterJ) + RotL64(aCarry, 37U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterJ, 39U)) + aOrbiterG) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterC, 3U)) + aOrbiterF);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 5U) + aOrbiterK) + RotL64(aOrbiterB, 41U));
            aWandererG = aWandererG + ((RotL64(aScatter, 23U) + aOrbiterD) + RotL64(aOrbiterI, 13U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 56U) + aOrbiterH) + RotL64(aOrbiterC, 23U));
            aWandererD = aWandererD + (((RotL64(aIngress, 29U) + aOrbiterD) + RotL64(aOrbiterB, 19U)) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterJ, 47U)) + aOrbiterH);
            aWandererK = aWandererK + ((RotL64(aCross, 37U) + RotL64(aOrbiterB, 29U)) + aOrbiterA);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 12U) + RotL64(aOrbiterC, 37U)) + aOrbiterG);
            aWandererH = aWandererH + (((RotL64(aScatter, 53U) + RotL64(aOrbiterD, 26U)) + aOrbiterE) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 4U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 34U));
            aCarry = aCarry + RotL64(aWandererI, 29U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 26414U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((aIndex + 31731U)) & S_BLOCK1], 28U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 26686U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 27983U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30059U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27754U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 26393U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aPrevious, 38U)) ^ (RotL64(aCarry, 11U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = (aWandererK + RotL64(aScatter, 41U)) + 1393781663398437180U;
            aOrbiterI = (aWandererG + RotL64(aCross, 35U)) + 17414594746688585273U;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 47U)) + 2823888497053071250U;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 10U)) + RotL64(aCarry, 11U)) + 17032631958617884859U;
            aOrbiterF = (aWandererE + RotL64(aScatter, 29U)) + 15222697630461125019U;
            aOrbiterC = (aWandererB + RotL64(aPrevious, 39U)) + 15737414920751551780U;
            aOrbiterE = (aWandererF + RotL64(aIngress, 13U)) + 1357196111055783001U;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 56U)) + RotL64(aCarry, 23U)) + 5315122321649251691U;
            aOrbiterD = (aWandererD + RotL64(aIngress, 23U)) + 7893744655508595974U;
            aOrbiterA = (((aWandererI + RotL64(aScatter, 19U)) + RotL64(aCarry, 39U)) + 16721939414324611738U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aCross, 37U)) + 3444375866323610848U) + aPhaseFOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 1825716513674511632U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 15582066843912467318U;
            aOrbiterB = RotL64((aOrbiterB * 12765146555943757373U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 15673590949193923915U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 13887365046280406413U;
            aOrbiterF = RotL64((aOrbiterF * 3169061375011420121U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 12730414371734709356U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 4819112390640821927U;
            aOrbiterC = RotL64((aOrbiterC * 8782547948627685451U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 3089925954422937464U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 7180179304678622530U;
            aOrbiterJ = RotL64((aOrbiterJ * 16118051565147747413U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 17030269962085008657U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 6675917351883004046U;
            aOrbiterA = RotL64((aOrbiterA * 14134335325316949687U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 12572022803491077491U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 2801421744689267375U;
            aOrbiterG = RotL64((aOrbiterG * 315045745990934023U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 4335148696780313055U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 12526298573395110141U;
            aOrbiterD = RotL64((aOrbiterD * 11276803410698178607U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 6984239833558496091U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 12195433952105336808U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8642600547427664495U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 6392683095502982341U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 18047201953488013325U;
            aOrbiterH = RotL64((aOrbiterH * 16151795290455603489U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 15433458942878109208U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 1700365768743794306U;
            aOrbiterK = RotL64((aOrbiterK * 16151638348775286903U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 10951473638533187729U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 1393781663398437180U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2661447713922232789U), 13U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterG, 29U);
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 21U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 60U));
            aIngress = aIngress + RotL64(aOrbiterH, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aCross, 29U) + aOrbiterE) + RotL64(aOrbiterB, 27U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 10U) + aOrbiterG) + RotL64(aOrbiterE, 57U));
            aWandererH = aWandererH + (((RotL64(aIngress, 47U) + RotL64(aOrbiterD, 42U)) + aOrbiterC) + aPhaseFWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterB, 35U)) + aOrbiterH);
            aWandererG = aWandererG + ((RotL64(aIngress, 41U) + RotL64(aOrbiterA, 29U)) + aOrbiterG);
            aWandererD = aWandererD ^ ((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterK, 19U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterG, 23U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 24U) + aOrbiterF) + RotL64(aOrbiterA, 47U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterI, 11U)) + aOrbiterG) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterD, 3U)) + aOrbiterA);
            aWandererA = aWandererA + (((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterD, 50U)) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 40U));
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + RotL64(aWandererJ, 29U);
            aCarry = aCarry + RotL64(aIngress, 48U);
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

void TwistExpander_Fencing_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 1458U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((aIndex + 4936U)) & S_BLOCK1], 30U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 1899U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 211U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7385U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 6142U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCross, 5U)) ^ (RotL64(aIngress, 19U) ^ RotL64(aCarry, 56U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = ((aWandererD + RotL64(aScatter, 19U)) + RotL64(aCarry, 41U)) + 15726877954695761686U;
            aOrbiterD = ((aWandererH + RotL64(aIngress, 34U)) + RotL64(aCarry, 3U)) + 14187652171881943587U;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 43U)) + 8420423151313882782U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = (((aWandererC + RotL64(aCross, 3U)) + RotL64(aCarry, 27U)) + 14942322692433259283U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aIngress, 11U)) + 7272331475919796255U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 154504365041805840U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 17475491222554948786U;
            aOrbiterI = RotL64((aOrbiterI * 2095330528612694779U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 5759181483165339605U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 5993060214499322845U;
            aOrbiterD = RotL64((aOrbiterD * 10799489831896153301U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 10901786237875941844U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 17135786595614068473U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15923538730142047043U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 5208202073886811165U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 6821452921018900631U;
            aOrbiterE = RotL64((aOrbiterE * 13119330055184115669U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 13348064837402206969U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 8967943922403445136U;
            aOrbiterF = RotL64((aOrbiterF * 300168481725373093U), 53U);
            //
            aIngress = RotL64(aOrbiterE, 51U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterH, 40U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 5U) + aOrbiterH) + RotL64(aOrbiterF, 57U));
            aWandererC = aWandererC + (((RotL64(aIngress, 39U) + RotL64(aOrbiterI, 11U)) + aOrbiterH) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 54U) + RotL64(aOrbiterD, 29U)) + aOrbiterE) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterI, 3U)) + aOrbiterE) + RotL64(aCarry, 51U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 27U) + aOrbiterF) + RotL64(aOrbiterD, 48U)) + aPhaseGWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + RotL64(aWandererF, 14U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 11424U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((aIndex + 8435U)) & S_BLOCK1], 24U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 8908U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 8990U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 15129U)) & S_BLOCK1], 36U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 9057U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 21U)) + (RotL64(aIngress, 36U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = (aWandererD + RotL64(aScatter, 13U)) + 2786079456995203065U;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 43U)) + 7237256119153857253U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aCross, 60U)) + RotL64(aCarry, 41U)) + 9310834010563647604U;
            aOrbiterK = (((aWandererI + RotL64(aPrevious, 5U)) + RotL64(aCarry, 27U)) + 17361734905706517877U) + aPhaseGOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = ((aWandererC + RotL64(aScatter, 29U)) + RotL64(aCarry, 13U)) + 15837111231884647451U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 18065431964418026445U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 3029123922999952652U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16309219658285890145U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 5166926595573507837U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 1918425684273807598U;
            aOrbiterD = RotL64((aOrbiterD * 16616641579714896719U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 4724551751012661440U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 1818014487579644390U;
            aOrbiterK = RotL64((aOrbiterK * 14904092108647864911U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 6670090372241084216U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 8485757110007268693U;
            aOrbiterG = RotL64((aOrbiterG * 11876760095108618363U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 4928130251509514742U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 2528788422725346792U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1855982047967756661U), 47U);
            //
            aIngress = RotL64(aOrbiterD, 39U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + RotL64(aOrbiterG, 28U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aScatter, 51U) + RotL64(aOrbiterG, 60U)) + aOrbiterF) + RotL64(aCarry, 11U)) + aPhaseGWandererUpdateSaltF[((aIndex + 26U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 14U) + RotL64(aOrbiterH, 41U)) + aOrbiterG);
            aWandererI = aWandererI + (((RotL64(aIngress, 27U) + RotL64(aOrbiterK, 27U)) + aOrbiterF) + aPhaseGWandererUpdateSaltB[((aIndex + 14U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterF, 5U)) + aOrbiterD);
            aWandererB = aWandererB + (((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 51U)) + aOrbiterH) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererG, 5U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 17506U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((aIndex + 20317U)) & S_BLOCK1], 14U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 24406U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 19207U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 21653U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 22788U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 36U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 35U)) + RotL64(aCarry, 11U)) + 12849591986267890852U;
            aOrbiterK = ((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 29U)) + 8232614804696815750U;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 47U)) + 12141567259210877281U) + aPhaseGOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = (((aWandererF + RotL64(aIngress, 13U)) + RotL64(aCarry, 41U)) + 2928641981037885644U) + aPhaseGOrbiterAssignSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aScatter, 58U)) + 980733350554783938U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 2683985177993350746U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 14532148403815527355U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15985362037094864225U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 7736296629433884203U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 10428437770166310549U;
            aOrbiterH = RotL64((aOrbiterH * 326634742742373401U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 18327174144859461029U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 6810436935194432002U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2715987179577753597U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 12606153309690753435U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 17123256945895150555U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13469111258504672565U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 9057777759026189541U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 16478485918911194442U;
            aOrbiterB = RotL64((aOrbiterB * 11054247078884894131U), 3U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterG, 23U);
            aIngress = aIngress + (RotL64(aOrbiterB, 34U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 53U) + aOrbiterB) + RotL64(aOrbiterA, 47U)) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 35U) + aOrbiterH) + RotL64(aOrbiterK, 3U));
            aWandererI = aWandererI + (((RotL64(aScatter, 3U) + aOrbiterB) + RotL64(aOrbiterG, 11U)) + aPhaseGWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 44U) + aOrbiterG) + RotL64(aOrbiterH, 57U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterG, 38U)) + aOrbiterK) + RotL64(aCarry, 11U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 28U));
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 30221U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((aIndex + 26277U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31028U)) & S_BLOCK1], 54U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27544U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28307U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 29706U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 27U) + RotL64(aPrevious, 11U)) + (RotL64(aIngress, 53U) ^ RotL64(aCross, 40U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = (aWandererI + RotL64(aPrevious, 37U)) + 3970829908171131502U;
            aOrbiterF = (((aWandererK + RotL64(aCross, 20U)) + RotL64(aCarry, 35U)) + 7040283759419531991U) + aPhaseGOrbiterAssignSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = ((aWandererF + RotL64(aIngress, 47U)) + 11856292169397052901U) + aPhaseGOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = ((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 47U)) + 819598588791819022U;
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 29U)) + RotL64(aCarry, 13U)) + 2176451710970866848U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 6454704928613390494U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 11792122387218053841U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17994898985794518565U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 9254780213489752211U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 16591812589999846482U;
            aOrbiterG = RotL64((aOrbiterG * 5425771603523423167U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 1471246223935074832U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 1424843083106386453U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15020536982657410783U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 1856469958050891629U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 6331743690452052712U;
            aOrbiterJ = RotL64((aOrbiterJ * 15327924647897459645U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 10351075711345476487U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 9518585245330480185U;
            aOrbiterA = RotL64((aOrbiterA * 3792179827396760391U), 19U);
            //
            aIngress = RotL64(aOrbiterA, 57U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterJ, 40U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 51U)) + aOrbiterG) + RotL64(aCarry, 57U)) + aPhaseGWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterI, 11U)) + aOrbiterF) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterJ, 21U)) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 26U) + RotL64(aOrbiterF, 3U)) + aOrbiterA);
            aWandererK = aWandererK + ((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterF, 30U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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

void TwistExpander_Fencing_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 6571U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((aIndex + 5793U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6473U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5625U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6578U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 8104U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 54U)) + (RotL64(aIngress, 21U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = ((aWandererI + RotL64(aIngress, 29U)) + 6068543441070417854U) + aPhaseHOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = (aWandererB + RotL64(aScatter, 41U)) + 2995980468193441856U;
            aOrbiterA = (((aWandererE + RotL64(aPrevious, 21U)) + RotL64(aCarry, 37U)) + 18020277482171594003U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = ((aWandererJ + RotL64(aCross, 5U)) + RotL64(aCarry, 23U)) + 4293807434721230702U;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 54U)) + RotL64(aCarry, 57U)) + 7980599111583893156U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 8593141111851052016U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 5903487523900084325U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2508618861111356699U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 15112035513447930209U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 9854037263057006439U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 396276470208637283U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 16759760289688823193U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 12622628933030601390U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2151912984825538321U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 1264668857268123425U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 16302812053619101593U;
            aOrbiterE = RotL64((aOrbiterE * 18291400055836111547U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 16087995784896123610U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 7970269262800468363U;
            aOrbiterB = RotL64((aOrbiterB * 14924752223305807461U), 43U);
            //
            aIngress = RotL64(aOrbiterE, 11U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + RotL64(aOrbiterG, 22U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 20U)) + aOrbiterB);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterA, 5U)) + aOrbiterG) + RotL64(aCarry, 57U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 43U)) + aOrbiterH);
            aWandererB = aWandererB + (((RotL64(aCross, 56U) + RotL64(aOrbiterG, 53U)) + aOrbiterB) + RotL64(aCarry, 29U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterG, 29U)) + aOrbiterH) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 21U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 56U));
            aCarry = aCarry + RotL64(aWandererE, 39U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 10589U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((aIndex + 15850U)) & S_BLOCK1], 52U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 10872U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14606U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12731U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 12887U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aIngress, 35U)) + (RotL64(aPrevious, 56U) ^ RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 51U)) + RotL64(aCarry, 39U)) + 13481227414590594621U;
            aOrbiterI = (aWandererI + RotL64(aCross, 28U)) + 17425964381118918026U;
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 11U)) + RotL64(aCarry, 53U)) + 4792004356135956581U;
            aOrbiterD = (((aWandererH + RotL64(aPrevious, 19U)) + RotL64(aCarry, 5U)) + 11926849936000639098U) + aPhaseHOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aCross, 37U)) + 990697329347742142U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 9307721505373076588U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 17605732738841908719U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13123627214143336281U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 13110764518634187439U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 17970109897810645911U;
            aOrbiterA = RotL64((aOrbiterA * 10395095143998920213U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 10273133817644703654U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 11239046688920468137U;
            aOrbiterI = RotL64((aOrbiterI * 5197802934333553327U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 8355821483275763145U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 15522151127786049345U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4844278537850520413U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 5381663179722418112U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 9551368011768104906U;
            aOrbiterD = RotL64((aOrbiterD * 14202470972121732997U), 57U);
            //
            aIngress = RotL64(aOrbiterD, 13U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + RotL64(aOrbiterJ, 54U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 37U) + aOrbiterI) + RotL64(aOrbiterD, 60U)) + RotL64(aCarry, 51U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterI, 41U)) + aOrbiterF);
            aWandererH = aWandererH + ((RotL64(aScatter, 48U) + RotL64(aOrbiterF, 51U)) + aOrbiterA);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterJ, 27U));
            aWandererE = aWandererE + ((((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 11U)) + aOrbiterD) + RotL64(aCarry, 35U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 22121U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((aIndex + 20955U)) & S_BLOCK1], 28U));
            aIngress ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18950U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18032U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21653U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 23626U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 26U) + RotL64(aPrevious, 11U)) ^ (RotL64(aIngress, 53U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = (((aWandererI + RotL64(aCross, 34U)) + RotL64(aCarry, 39U)) + 13499155707765393469U) + aPhaseHOrbiterAssignSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = (((aWandererF + RotL64(aPrevious, 51U)) + RotL64(aCarry, 51U)) + 3740324981823726185U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = (aWandererB + RotL64(aIngress, 11U)) + 5470765363949735652U;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 19U)) + RotL64(aCarry, 3U)) + 3446436171274452326U;
            aOrbiterH = (aWandererH + RotL64(aIngress, 43U)) + 1778929412631211933U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 14666308799855220954U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 4548410236791175055U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6822908616815218501U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 5829739767694190372U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 14319231414903675748U;
            aOrbiterE = RotL64((aOrbiterE * 4966501102515775601U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 1513851750246111405U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 1685620217748986019U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9286548037413609445U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 16284162182006054402U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 6271539598462003309U;
            aOrbiterH = RotL64((aOrbiterH * 13923286694131331137U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 12669312437565969473U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 11894755313393001665U;
            aOrbiterA = RotL64((aOrbiterA * 12556759675372354075U), 21U);
            //
            aIngress = RotL64(aOrbiterE, 26U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterK, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aIngress, 30U) + aOrbiterA) + RotL64(aOrbiterK, 37U)) + aPhaseHWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 21U)) + aOrbiterH) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterH, 52U)) + aOrbiterE);
            aWandererB = aWandererB + ((((RotL64(aCross, 51U) + RotL64(aOrbiterA, 11U)) + aOrbiterI) + RotL64(aCarry, 35U)) + aPhaseHWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 21U) + aOrbiterK) + RotL64(aOrbiterI, 3U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererB, 37U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 28897U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((aIndex + 27454U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31213U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32686U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26139U)) & S_BLOCK1], 30U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 28203U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aPrevious, 36U)) + (RotL64(aCarry, 23U) ^ RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = ((aWandererE + RotL64(aIngress, 5U)) + RotL64(aCarry, 5U)) + 13204735390996728477U;
            aOrbiterC = ((aWandererG + RotL64(aCross, 51U)) + RotL64(aCarry, 35U)) + 851171359595647173U;
            aOrbiterG = (((aWandererK + RotL64(aScatter, 39U)) + RotL64(aCarry, 21U)) + 16745304202825290723U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 60U)) + 562392736584913979U) + aPhaseHOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = (aWandererF + RotL64(aScatter, 23U)) + 3244267012529053918U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 17282536111067869133U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 14851130066471729068U;
            aOrbiterG = RotL64((aOrbiterG * 6308165353504550619U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 5256130407952363129U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 2904742485828362001U;
            aOrbiterA = RotL64((aOrbiterA * 12941135856735075457U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 3723346325449225387U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 5344621093694027341U;
            aOrbiterC = RotL64((aOrbiterC * 9044881458629673499U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 12919263300833603026U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 17989801264160996071U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15468293047311883751U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 5022175042377172157U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 16684822380107847758U;
            aOrbiterB = RotL64((aOrbiterB * 2834049270263837537U), 57U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 57U);
            aIngress = aIngress + (RotL64(aOrbiterE, 36U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 37U) + aOrbiterC) + RotL64(aOrbiterA, 19U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterG, 57U)) + aOrbiterA) + RotL64(aCarry, 5U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 20U) + RotL64(aOrbiterE, 5U)) + aOrbiterA) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 5U) + RotL64(aOrbiterC, 34U)) + aOrbiterB) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 47U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererF, 12U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
