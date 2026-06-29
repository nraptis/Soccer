#include "TwistExpander_VolleyBall_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_VolleyBall_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xF2B1DD5AF64FB89BULL + 0xC90753CF26A207D1ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xFF87BD6A3A960F4DULL + 0x8ACBBF1A410AACA4ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xDBB14456148EFBF3ULL + 0xC69BCBFAAEA4C883ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xF89B909A7DA8ECF9ULL + 0xEF70813741CEA960ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x9B51BE6E57D96A8BULL + 0x87F0B1FA726EB01DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xDEFAD34AF6534B39ULL + 0xA9960183557BE1ECULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xB368FA0E31A3EB83ULL + 0xCE2F59DDC9692011ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xD9B8EFA93D0DC957ULL + 0x86C23CEC28E381B0ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xC71066D431C31EF5ULL + 0xB514ED5F82399FAFULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xDBEA636961B2F8D3ULL + 0x9192436EF8E4A6E8ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xAFA9AC0AAAD56AA7ULL + 0xE18F86314125AD97ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x991E2518E7B86975ULL + 0xB2B942B07E968E23ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xE6711F18AFCAF59DULL + 0x9226603CE042E263ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x9652D10867D210E3ULL + 0xD2632B775EC0EF94ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xD3686F21B1964E93ULL + 0xAF0DE664417240AEULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xE57497C275A6E843ULL + 0x9EB0A2366EFD4051ULL);
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
            aIngress = RotL64(mSource[((aIndex + 73U)) & S_BLOCK1], 43U) ^ RotL64(pSnow[((aIndex + 2122U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 4528U)) & S_BLOCK1], 11U) ^ RotL64(mSource[((aIndex + 1660U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aPrevious, 19U)) ^ (RotL64(aIngress, 36U) + RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterC = ((aWandererI + RotL64(aScatter, 41U)) + 5131645209694953015U) + aNonceWordH;
            aOrbiterI = (aWandererH + RotL64(aCross, 56U)) + 12070391048835379854U;
            aOrbiterF = (aWandererE + RotL64(aIngress, 47U)) + 2604295836242338724U;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 27U)) + RotL64(aCarry, 13U)) + 14042039029284001596U;
            aOrbiterG = (aWandererA + RotL64(aScatter, 19U)) + 8914654543854559327U;
            aOrbiterA = (((aWandererK + RotL64(aCross, 21U)) + 2185619407969359869U) + aOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordK;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 11U)) + RotL64(aCarry, 41U)) + 5187406295103352574U;
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 37U)) + 8022832481290871217U) + aNonceWordF;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 53U)) + 8783061916740573472U) + aOrbiterAssignSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aCross, 50U)) + RotL64(aCarry, 35U)) + 10711028365596196301U;
            aOrbiterB = ((aWandererG + RotL64(aIngress, 35U)) + 13387065038269133571U) + aNonceWordM;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 11187001318931801582U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 14191473173276034019U;
            aOrbiterF = RotL64((aOrbiterF * 2491253922434756431U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 16207761776716426435U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 9677408414452078760U;
            aOrbiterI = RotL64((aOrbiterI * 5487303383095129949U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 17812460332794370649U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterG) ^ 7736423148554132028U) ^ aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 15588733747232852555U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 17293203944059014763U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 13487243633338010243U;
            aOrbiterG = RotL64((aOrbiterG * 9468688858740539095U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 15979293016815060755U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 17645215484691359547U;
            aOrbiterH = RotL64((aOrbiterH * 1449450767288733995U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 11635961468586927692U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 10530136578329059784U;
            aOrbiterC = RotL64((aOrbiterC * 8785021493374398437U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 4900370530116992731U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 15952900504821599445U;
            aOrbiterE = RotL64((aOrbiterE * 5413316082800365261U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 9938000151832814778U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 14170277411106520726U;
            aOrbiterA = RotL64((aOrbiterA * 5058343552974910737U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 14091010427448547620U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 13658560822164111421U;
            aOrbiterJ = RotL64((aOrbiterJ * 9523184040517290629U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 13954269172267844623U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 3921811946419945868U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6839440867046147039U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 14296483810577739898U) + aNonceWordC;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 5131645209694953015U;
            aOrbiterB = RotL64((aOrbiterB * 10190969526209064367U), 39U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 39U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 30U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 43U));
            aIngress = aIngress + RotL64(aOrbiterG, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 43U) + RotL64(aOrbiterA, 3U)) + aOrbiterG) + aNonceWordE);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 27U) + aOrbiterH) + RotL64(aOrbiterA, 23U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 12U) + aOrbiterK) + RotL64(aOrbiterA, 21U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 21U) + aOrbiterE) + RotL64(aOrbiterK, 60U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterH, 13U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterH, 19U)) + aOrbiterI);
            aWandererG = aWandererG + (((RotL64(aScatter, 24U) + RotL64(aOrbiterF, 11U)) + aOrbiterH) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterB, 57U)) + aOrbiterD);
            aWandererC = aWandererC + (((RotL64(aScatter, 53U) + RotL64(aOrbiterG, 34U)) + aOrbiterC) + aWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 37U) + RotL64(aOrbiterG, 37U)) + aOrbiterE) + aNonceWordJ) + aWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 35U) + aOrbiterD) + RotL64(aOrbiterJ, 43U)) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 26U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 24U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 39U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 7365U)) & S_BLOCK1], 42U) ^ RotL64(mSource[((aIndex + 9677U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9747U)) & S_BLOCK1], 20U) ^ RotL64(pSnow[((aIndex + 9529U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCross, 11U)) + (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 38U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 23U)) + RotL64(aCarry, 27U)) + 10404808878585437255U;
            aOrbiterH = ((aWandererF + RotL64(aCross, 35U)) + RotL64(aCarry, 41U)) + 10587858736301591439U;
            aOrbiterF = (aWandererA + RotL64(aScatter, 3U)) + 1430530909801644435U;
            aOrbiterC = (aWandererK + RotL64(aPrevious, 5U)) + 9090938022430118902U;
            aOrbiterA = (aWandererD + RotL64(aIngress, 53U)) + 12936604311751121235U;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 56U)) + 1000583006020232032U) + aNonceWordH;
            aOrbiterE = (((aWandererJ + RotL64(aCross, 19U)) + 12352532088997042232U) + aOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterK = (aWandererC + RotL64(aPrevious, 21U)) + 16723410947058502564U;
            aOrbiterB = ((aWandererB + RotL64(aCross, 29U)) + 16614089235313154270U) + aOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = (aWandererH + RotL64(aIngress, 58U)) + 4245553025593349277U;
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 39U)) + RotL64(aCarry, 13U)) + 3353146318549477494U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 5935727336135635196U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 10312187090293319667U;
            aOrbiterF = RotL64((aOrbiterF * 1395964500396711899U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 12192843181244744484U) + aNonceWordO;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 2542570124502586365U;
            aOrbiterA = RotL64((aOrbiterA * 17222847847573534963U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 3315472769469002444U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 17512858811783071174U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9070400454074283765U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 16633218007427888082U) + aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 2502077714838858460U;
            aOrbiterK = RotL64((aOrbiterK * 970762420815997725U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 14792910273226469214U) + aNonceWordF;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 15739513291150783151U;
            aOrbiterB = RotL64((aOrbiterB * 11896279674116906915U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 2192903544350345992U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 844428341223009295U) ^ aOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4768368713974002539U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 2998511458298901402U) + aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 7790789639864783373U;
            aOrbiterG = RotL64((aOrbiterG * 9173097618440495497U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 4540735375055164995U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 13700342877362633034U) ^ aNonceWordB;
            aOrbiterJ = RotL64((aOrbiterJ * 14730797752841670505U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 16966725424259324323U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 5945539295893015935U;
            aOrbiterI = RotL64((aOrbiterI * 12226268057062268981U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 12560355243513521281U) + aNonceWordM;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 2104086086480258265U;
            aOrbiterD = RotL64((aOrbiterD * 17989755118752755577U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 4476697099257280568U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 10404808878585437255U;
            aOrbiterH = RotL64((aOrbiterH * 6245415417832089357U), 27U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterF, 43U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 18U));
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterE, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterD, 35U)) + aOrbiterI);
            aWandererF = aWandererF + ((RotL64(aIngress, 21U) + aOrbiterC) + RotL64(aOrbiterH, 47U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 11U) + aOrbiterH) + RotL64(aOrbiterA, 51U)) + aNonceWordA);
            aWandererE = aWandererE + (((RotL64(aPrevious, 60U) + RotL64(aOrbiterK, 20U)) + aOrbiterG) + aNonceWordL);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 51U) + aOrbiterB) + RotL64(aOrbiterH, 41U)) + aNonceWordP);
            aWandererB = aWandererB + (((RotL64(aCross, 35U) + RotL64(aOrbiterE, 43U)) + aOrbiterA) + aWandererUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 27U)) + aOrbiterK);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 18U) + aOrbiterC) + RotL64(aOrbiterA, 30U)) + RotL64(aCarry, 19U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterD, 39U)) + aOrbiterC);
            aWandererC = aWandererC + (((RotL64(aCross, 27U) + aOrbiterH) + RotL64(aOrbiterJ, 23U)) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterF, 13U)) + aOrbiterA) + aWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (RotL64(aWandererK, 4U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + RotL64(aWandererH, 39U);
            aCarry = aCarry + RotL64(aIngress, 24U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 13373U)) & S_BLOCK1], 36U) ^ RotL64(mSource[((aIndex + 12695U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 15865U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15277U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 34U)) ^ (RotL64(aCross, 47U) + RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterI = (((aWandererC + RotL64(aScatter, 28U)) + RotL64(aCarry, 23U)) + 479672811032092393U) + aNonceWordJ;
            aOrbiterF = ((aWandererA + RotL64(aCross, 57U)) + RotL64(aCarry, 47U)) + 18061121631394564425U;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 53U)) + 14237400452740566065U;
            aOrbiterD = (((aWandererI + RotL64(aIngress, 35U)) + RotL64(aCarry, 57U)) + 6723123812257706134U) + aOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aCross, 5U)) + 4247997188026499248U;
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 3U)) + 1939107415066134869U;
            aOrbiterG = (aWandererE + RotL64(aScatter, 21U)) + 3912640123546395979U;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 39U)) + 8295478436553964298U) + aNonceWordP;
            aOrbiterJ = ((aWandererD + RotL64(aCross, 37U)) + 3218960600711526885U) + aOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aScatter, 48U)) + 5874096203353388890U) + aNonceWordL;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 11U)) + 10294536533673023358U) + aNonceWordI;
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 11268561953904130747U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 16693201256788898423U) ^ aOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16291987237693567209U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 7550969634681894654U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 9501647424602245869U;
            aOrbiterB = RotL64((aOrbiterB * 11265865222096866605U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 8881869255994319423U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 16770136406906800016U;
            aOrbiterG = RotL64((aOrbiterG * 1782039587385512923U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 16185384746435761363U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 13841034186650721627U) ^ aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12000155593277035447U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 15229062695864608309U) + aNonceWordD;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 3576122704615303733U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2433987493885779279U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 13898167174453181224U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 12878032061609524049U;
            aOrbiterA = RotL64((aOrbiterA * 18104665741338251495U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 12719156051299028649U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 8640980843376950769U;
            aOrbiterC = RotL64((aOrbiterC * 10242616778390983333U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 12133332160916004365U) + aNonceWordO;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 8743563985229104484U;
            aOrbiterI = RotL64((aOrbiterI * 4575129690615054691U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 7362223873479167793U) + aOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 4230720394788635807U;
            aOrbiterK = RotL64((aOrbiterK * 3658720603716856293U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 5095842824285329272U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 7483469517256234638U;
            aOrbiterD = RotL64((aOrbiterD * 9782114499878763883U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 17426017004856399653U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 479672811032092393U;
            aOrbiterE = RotL64((aOrbiterE * 14921028515589317919U), 21U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 23U);
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterE, 10U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aScatter, 28U) + aOrbiterA) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 5U)) + aNonceWordG);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 29U)) + aOrbiterC);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterH, 57U)) + aNonceWordC) + aWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterI, 20U)) + aOrbiterA) + aNonceWordA);
            aWandererE = aWandererE + (((RotL64(aIngress, 11U) + RotL64(aOrbiterJ, 39U)) + aOrbiterE) + aWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterF, 3U)) + aOrbiterI);
            aWandererC = aWandererC + ((RotL64(aScatter, 53U) + aOrbiterI) + RotL64(aOrbiterG, 43U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterF, 22U)) + aOrbiterD);
            aWandererI = aWandererI + ((RotL64(aScatter, 47U) + RotL64(aOrbiterG, 37U)) + aOrbiterH);
            aWandererF = aWandererF ^ ((RotL64(aCross, 60U) + aOrbiterD) + RotL64(aOrbiterB, 11U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 51U) + aOrbiterJ) + RotL64(aOrbiterB, 27U)) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 46U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + RotL64(aWandererA, 56U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 18952U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 17393U)) & S_BLOCK1], 40U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 16766U)) & S_BLOCK1], 6U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 21126U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 19025U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 57U)) + (RotL64(aIngress, 6U) ^ RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterF = (((aWandererE + RotL64(aPrevious, 35U)) + RotL64(aCarry, 53U)) + 16189787374324972735U) + aOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aIngress, 22U)) + 17563763730956242224U) + aNonceWordK;
            aOrbiterC = ((aWandererB + RotL64(aCross, 29U)) + 10572803498593789385U) + aNonceWordA;
            aOrbiterI = ((aWandererD + RotL64(aScatter, 5U)) + 7713105232072974166U) + aOrbiterAssignSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = (aWandererA + RotL64(aIngress, 51U)) + 10760839534772718139U;
            aOrbiterG = ((aWandererF + RotL64(aCross, 47U)) + 13397069448391230253U) + aNonceWordM;
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 27U)) + 4569255679998375682U;
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 39U)) + 9888769350817876949U;
            aOrbiterD = ((aWandererH + RotL64(aCross, 11U)) + RotL64(aCarry, 21U)) + 11351796060878856300U;
            aOrbiterH = (aWandererG + RotL64(aPrevious, 13U)) + 18153775071965707204U;
            aOrbiterK = (aWandererI + RotL64(aScatter, 24U)) + 1282846411145853435U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 16457743979262460660U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 173493260775251032U;
            aOrbiterC = RotL64((aOrbiterC * 4935807229040883505U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 3927345926316409630U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 5158769729850853623U;
            aOrbiterA = RotL64((aOrbiterA * 2446452358663812945U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 12331351600010165154U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 3940794200348684050U) ^ aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13248997263062075043U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 11248514843822945425U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 1391497323278226522U) ^ aNonceWordO;
            aOrbiterG = RotL64((aOrbiterG * 8376841806072565005U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 13265623528678787307U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 2802033745265647317U;
            aOrbiterD = RotL64((aOrbiterD * 3437626962562016147U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 6938444301018051844U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 1086544666755559028U;
            aOrbiterK = RotL64((aOrbiterK * 16039728388882079889U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 16156443117365816536U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 3619942859562697142U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7589346043159112151U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 17681848914912743292U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 8848238631758130416U) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 810402256099500607U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 6019192027793541890U) + aOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 16917288363166352778U;
            aOrbiterE = RotL64((aOrbiterE * 17673667086593738207U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 5598218150530046752U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 17285995539011279010U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15621233176885995065U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 12380627610747299268U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 16189787374324972735U;
            aOrbiterI = RotL64((aOrbiterI * 2144714828503219209U), 35U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 24U);
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + RotL64(aOrbiterH, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 10U) + aOrbiterG) + RotL64(aOrbiterK, 34U));
            aWandererF = aWandererF + ((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 37U)) + aOrbiterG);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 39U)) + aOrbiterD) + aWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 21U)) + aOrbiterC);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterE, 13U)) + aOrbiterA) + aNonceWordC);
            aWandererJ = aWandererJ + (((RotL64(aCross, 43U) + aOrbiterH) + RotL64(aOrbiterJ, 19U)) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterK, 43U)) + aOrbiterA);
            aWandererB = aWandererB + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 23U)) + aOrbiterH) + RotL64(aCarry, 13U)) + aNonceWordH);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 18U) + aOrbiterB) + RotL64(aOrbiterH, 41U)) + aNonceWordL);
            aWandererC = aWandererC + ((RotL64(aScatter, 21U) + aOrbiterE) + RotL64(aOrbiterI, 29U));
            aWandererH = aWandererH ^ ((((RotL64(aCross, 57U) + RotL64(aOrbiterD, 56U)) + aOrbiterG) + aNonceWordJ) + aWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 54U));
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererI, 50U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 24418U)) & S_BLOCK1], 5U) ^ RotL64(mSource[((aIndex + 25056U)) & S_BLOCK1], 37U));
            aIngress ^= (RotL64(pSnow[((aIndex + 24008U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23842U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23821U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((aIndex + 24764U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCross, 52U)) ^ (RotL64(aIngress, 37U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterF = ((aWandererI + RotL64(aIngress, 50U)) + 15383045568644941552U) + aOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 39U)) + 17452811657750910067U;
            aOrbiterI = (aWandererE + RotL64(aCross, 3U)) + 15660117718455155603U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 5U)) + 10396441207743665753U;
            aOrbiterE = (((aWandererB + RotL64(aCross, 5U)) + RotL64(aCarry, 29U)) + 3708971058200841442U) + aOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aScatter, 19U)) + 7000673057768598750U) + aNonceWordL;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 29U)) + 9886354469011131596U;
            aOrbiterB = (((aWandererC + RotL64(aIngress, 21U)) + RotL64(aCarry, 35U)) + 16018065329058043467U) + aNonceWordG;
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 53U)) + 5024756166109352320U;
            aOrbiterK = (aWandererG + RotL64(aIngress, 60U)) + 6587818720728886652U;
            aOrbiterA = (aWandererK + RotL64(aCross, 27U)) + 3652672354944162319U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 6307315649915348048U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 16405347331742979258U;
            aOrbiterI = RotL64((aOrbiterI * 7183142442906743699U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 5427299664054601957U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 4983381733483185898U;
            aOrbiterE = RotL64((aOrbiterE * 14646556236306407673U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 10182995521328377487U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 8694282877540593550U;
            aOrbiterJ = RotL64((aOrbiterJ * 14614602561910403893U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 4085927978153269932U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 6176195962815240877U;
            aOrbiterG = RotL64((aOrbiterG * 16792916528959579875U), 47U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterF) + 6966742100601433005U) + aOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 9920952446921247521U;
            aOrbiterD = RotL64((aOrbiterD * 1879821050131820933U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 11958734477518336014U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 2058335903640404380U;
            aOrbiterH = RotL64((aOrbiterH * 6986170159285417789U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 77366119537297816U) + aNonceWordC;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 12072894199692855000U;
            aOrbiterB = RotL64((aOrbiterB * 9083781120514635987U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 11874297832446385377U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 13715562531763053196U;
            aOrbiterK = RotL64((aOrbiterK * 12822488258322963187U), 57U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterD) + 13664465415354326653U) + aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1]) + aNonceWordF;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 10365386643010882315U;
            aOrbiterA = RotL64((aOrbiterA * 3687934567254955761U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 2003863843075564853U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 8864134110143237364U;
            aOrbiterF = RotL64((aOrbiterF * 4586162015675320985U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 8055736412403126985U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 15383045568644941552U;
            aOrbiterC = RotL64((aOrbiterC * 5175405553995854715U), 43U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 12U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 53U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 60U));
            aIngress = aIngress + RotL64(aOrbiterF, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aScatter, 23U) + aOrbiterF) + RotL64(aOrbiterJ, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 29U)) + aOrbiterI);
            aWandererC = aWandererC + (((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterB, 27U)) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 27U) + aOrbiterH) + RotL64(aOrbiterC, 21U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 37U) + aOrbiterD) + RotL64(aOrbiterH, 4U)) + aNonceWordK);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 18U) + aOrbiterE) + RotL64(aOrbiterB, 35U));
            aWandererK = aWandererK + (((RotL64(aCross, 57U) + aOrbiterB) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterG, 23U)) + aOrbiterA) + aWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 11U) + aOrbiterA) + RotL64(aOrbiterH, 41U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 6U) + RotL64(aOrbiterH, 54U)) + aOrbiterF) + aNonceWordI);
            aWandererH = aWandererH + (((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterD, 19U)) + aWandererUpdateSaltE[((aIndex + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 50U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 58U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 29159U)) & S_BLOCK1], 14U) ^ RotL64(pSnow[((aIndex + 27392U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 32325U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 32643U)) & S_BLOCK1], 26U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 30903U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 31204U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 52U) + RotL64(aCarry, 5U)) ^ (RotL64(aCross, 39U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterE = (aWandererI + RotL64(aIngress, 13U)) + 13296600294247799698U;
            aOrbiterH = (aWandererF + RotL64(aCross, 19U)) + 5818503518080877515U;
            aOrbiterI = (aWandererB + RotL64(aPrevious, 22U)) + 6735784238734173597U;
            aOrbiterB = (aWandererD + RotL64(aScatter, 43U)) + 7368398209488856201U;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 41U)) + 961734029066455638U;
            aOrbiterG = (aWandererJ + RotL64(aCross, 37U)) + 797011946660892011U;
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 35U)) + RotL64(aCarry, 3U)) + 12841876018396622350U;
            aOrbiterD = (aWandererE + RotL64(aIngress, 3U)) + 16213253970483895623U;
            aOrbiterA = (((aWandererC + RotL64(aScatter, 11U)) + 15186950557113470375U) + aOrbiterAssignSaltA[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordK;
            aOrbiterF = ((((aWandererK + RotL64(aPrevious, 28U)) + RotL64(aCarry, 37U)) + 5117930310827477341U) + aOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1]) + aNonceWordN;
            aOrbiterK = ((aWandererH + RotL64(aCross, 5U)) + RotL64(aCarry, 43U)) + 12265429373166094162U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 13920531346698601568U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 14695405206998211456U;
            aOrbiterI = RotL64((aOrbiterI * 13950964363414164279U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 7851960904825938443U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 9501511171732550190U;
            aOrbiterC = RotL64((aOrbiterC * 5614164120361489613U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 5663365182245722077U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 9607860124321315555U;
            aOrbiterD = RotL64((aOrbiterD * 3461820361914280601U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 18171052650586819280U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 3442698321538580861U) ^ aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6317525514963824829U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 1491052813469258970U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 3956599824067616133U;
            aOrbiterE = RotL64((aOrbiterE * 2928600779267623085U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 10963841237346073453U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 2303020125591252534U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9969099842343321981U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 14503856057958162356U) + aNonceWordH;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 11147548150090597694U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11856382308792700441U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 9191681438318311481U) + aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 13556072770381999852U;
            aOrbiterB = RotL64((aOrbiterB * 18316231099054203683U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 10103207278550444685U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 10415809965217261104U;
            aOrbiterK = RotL64((aOrbiterK * 16562732599511350217U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 17435033201864058457U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 5540494424887364682U;
            aOrbiterJ = RotL64((aOrbiterJ * 18230910315317249045U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 18020151683897013854U) + aNonceWordO;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 13296600294247799698U;
            aOrbiterG = RotL64((aOrbiterG * 10000194329456668845U), 27U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 39U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 51U));
            aIngress = aIngress + (RotL64(aOrbiterB, 60U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 37U));
            aIngress = aIngress + RotL64(aOrbiterH, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 52U) + RotL64(aOrbiterF, 41U)) + aOrbiterG) + aNonceWordG) + aWandererUpdateSaltF[((aIndex + 28U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterH, 13U)) + aOrbiterC) + aNonceWordB);
            aWandererH = aWandererH + (((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterA, 38U)) + aNonceWordF);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 29U) + aOrbiterG) + RotL64(aOrbiterH, 53U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 41U) + aOrbiterD) + RotL64(aOrbiterI, 43U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterK, 3U));
            aWandererC = aWandererC + (((RotL64(aIngress, 34U) + RotL64(aOrbiterA, 11U)) + aOrbiterD) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 23U) + aOrbiterA) + RotL64(aOrbiterF, 21U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 5U) + RotL64(aOrbiterB, 29U)) + aOrbiterD) + aWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterJ, 58U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 60U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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

void TwistExpander_VolleyBall_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x8584253982D84BBBULL + 0xC28D5D8C60DD658CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xA73DA5AF9443C07DULL + 0xDBC679B6080798ADULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xE779B84C9F5C025DULL + 0xF5C6B763FB8BCE54ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xCDC501C22AC32F2BULL + 0xE6EC19ED7CB8D80BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xC7864165E3EE47D9ULL + 0xEC61B4A5BB07F170ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xD6DD1C74A8A58547ULL + 0xE0D17757B9997845ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xE3B180A5ECCC07E3ULL + 0xA2997849F083EB29ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xDDDA37D1EDC053ADULL + 0xF99D483356AB26F2ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xCA21CC45DC1A55BDULL + 0xBBAFF64FB20041F6ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xFB91253C1051CA75ULL + 0xA90C5EDA03BD70AEULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xD08DFAB60304CB67ULL + 0xC7E242CC9A129A5BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xCB98188C9AC281E7ULL + 0xA03D83D2B8FC165BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xB5BCA3D9815148B5ULL + 0xC337FD497A383E7EULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xDFF984D2ECF4E285ULL + 0xD086B93885303AD5ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xB6A5198C50CFC687ULL + 0x8CC9E2F52CD11CBDULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x9ABDF85626136F39ULL + 0xB215FB585154ABE4ULL);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 781U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneB[((aIndex + 482U)) & S_BLOCK1], 6U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 725U)) & S_BLOCK1], 12U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 6143U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 27U) + RotL64(aCross, 43U)) + (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterI = ((aWandererI + RotL64(aIngress, 53U)) + RotL64(aCarry, 5U)) + 8402620908307642697U;
            aOrbiterA = (aWandererC + RotL64(aCross, 3U)) + 11347672014525086047U;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 11U)) + RotL64(aCarry, 13U)) + 2816462912503401876U;
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 44U)) + 6940159795470696093U;
            aOrbiterC = ((aWandererD + RotL64(aIngress, 35U)) + 9134692490095883851U) + aOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (((aWandererA + RotL64(aScatter, 57U)) + 4999455497008026526U) + aOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1]) + aNonceWordG;
            aOrbiterD = (((aWandererB + RotL64(aPrevious, 27U)) + RotL64(aCarry, 43U)) + 5992451460350651332U) + aNonceWordB;
            aOrbiterG = (aWandererF + RotL64(aCross, 40U)) + 3417087346651371924U;
            aOrbiterK = (aWandererH + RotL64(aIngress, 23U)) + 3612773820086198270U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 463398077083428570U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 11249391303705089012U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7106735772303292983U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 17027535139825739501U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 568131384979596481U;
            aOrbiterB = RotL64((aOrbiterB * 5683451044852895957U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 4793712537158004047U) + aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 10415170179135963622U) ^ aOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13729564030210361415U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 2391473979460065630U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 4240058362680064261U;
            aOrbiterG = RotL64((aOrbiterG * 12375884373396400889U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 9963957011090031698U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 3325305624067445525U) ^ aNonceWordC;
            aOrbiterE = RotL64((aOrbiterE * 3128542681461806309U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 2094945647665114693U) + aNonceWordA;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 10703615640774042674U;
            aOrbiterA = RotL64((aOrbiterA * 12641986098450423751U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 3768738815518590289U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 15021301790376706827U;
            aOrbiterI = RotL64((aOrbiterI * 14445850924223550339U), 43U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterF) + 10571246886181608316U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordK;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 5130325144599151793U;
            aOrbiterK = RotL64((aOrbiterK * 3185251943547657467U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 8617523421720966373U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 16574597770835250074U;
            aOrbiterD = RotL64((aOrbiterD * 1759209403428937799U), 47U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 5U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 22U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 23U)) + aOrbiterD);
            aWandererC = aWandererC + ((((RotL64(aIngress, 26U) + aOrbiterK) + RotL64(aOrbiterE, 10U)) + RotL64(aCarry, 43U)) + aNonceWordD);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 39U) + aOrbiterC) + RotL64(aOrbiterF, 47U)) + aNonceWordH);
            aWandererI = aWandererI + ((RotL64(aCross, 43U) + RotL64(aOrbiterB, 51U)) + aOrbiterE);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterI, 41U)) + aOrbiterK);
            aWandererD = aWandererD + (((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 5U)) + aOrbiterF) + aWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterA, 35U)) + aOrbiterI);
            aWandererH = aWandererH + (((RotL64(aCross, 35U) + RotL64(aOrbiterI, 56U)) + aOrbiterF) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 18U) + RotL64(aOrbiterF, 27U)) + aOrbiterE) + aWandererUpdateSaltA[((aIndex + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 18U));
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 21U));
            aCarry = aCarry + RotL64(aWandererB, 27U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 12306U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneB[((aIndex + 9417U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 11518U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 16073U)) & S_BLOCK1], 43U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 15867U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCarry, 10U)) + (RotL64(aPrevious, 43U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 6U)) + 14157904117287696136U) + aNonceWordJ;
            aOrbiterJ = (((aWandererJ + RotL64(aScatter, 19U)) + RotL64(aCarry, 11U)) + 7369512677371640676U) + aNonceWordK;
            aOrbiterB = ((aWandererI + RotL64(aIngress, 27U)) + 8411250745902073798U) + aNonceWordN;
            aOrbiterF = ((aWandererK + RotL64(aCross, 39U)) + RotL64(aCarry, 27U)) + 5002041814539710275U;
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 43U)) + RotL64(aCarry, 41U)) + 9538041410816283124U;
            aOrbiterI = (aWandererF + RotL64(aCross, 23U)) + 5210700103927513061U;
            aOrbiterG = (aWandererA + RotL64(aIngress, 35U)) + 7600709399101287982U;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 53U)) + 2366369466696580499U) + aOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = ((aWandererG + RotL64(aIngress, 48U)) + 5544575244203019109U) + aOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 8710073749110329779U) + aOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 15998211310115361630U;
            aOrbiterB = RotL64((aOrbiterB * 15275657696897688955U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 15354357553877376422U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 10657523549259276169U;
            aOrbiterA = RotL64((aOrbiterA * 13695239532898311073U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 10405750198355464768U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 3465819693133515142U;
            aOrbiterI = RotL64((aOrbiterI * 14678343718277562799U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 16724189641701408630U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 3484340153620198872U;
            aOrbiterG = RotL64((aOrbiterG * 17247547677520703125U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 7420442404884871126U) + aNonceWordD;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 11138445997256757636U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11167543379937571127U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 1428191560884663125U) + aNonceWordF;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 16950093140800653985U;
            aOrbiterJ = RotL64((aOrbiterJ * 4423012306984814805U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 17288299075036481960U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 13793597915359681028U) ^ aOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9639204979982125757U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 5017972942710079726U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 12409957957614320964U;
            aOrbiterC = RotL64((aOrbiterC * 10273295741911545745U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 12487994181992095174U) + aOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 1573393166996612118U;
            aOrbiterE = RotL64((aOrbiterE * 13364311829104520751U), 29U);
            //
            aIngress = RotL64(aOrbiterB, 30U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + RotL64(aOrbiterA, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aIngress, 11U) + aOrbiterB) + RotL64(aOrbiterE, 39U)) + aNonceWordO);
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 19U) + aOrbiterH) + RotL64(aOrbiterJ, 34U)) + aNonceWordE) + aWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 56U) + aOrbiterC) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 27U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterC, 19U)) + aOrbiterF);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 41U) + aOrbiterG) + RotL64(aOrbiterB, 11U)) + aWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterE, 27U));
            aWandererF = aWandererF + (((RotL64(aIngress, 5U) + aOrbiterC) + RotL64(aOrbiterA, 52U)) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterE, 3U)) + aOrbiterH);
            aWandererE = aWandererE + ((RotL64(aCross, 52U) + RotL64(aOrbiterI, 47U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 28U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererK, 19U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 21677U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneD[((aIndex + 21937U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 22151U)) & S_BLOCK1], 22U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23103U)) & S_BLOCK1], 60U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 24539U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 18373U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 54U) ^ RotL64(aIngress, 23U)) + (RotL64(aPrevious, 11U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterE = ((aWandererK + RotL64(aScatter, 36U)) + 3561491146322798260U) + aOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = (aWandererI + RotL64(aIngress, 47U)) + 7075025056181885339U;
            aOrbiterB = (((aWandererA + RotL64(aCross, 5U)) + RotL64(aCarry, 41U)) + 9230910887904171613U) + aOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 27U)) + 4119781172609908917U) + aNonceWordP;
            aOrbiterH = (((aWandererE + RotL64(aScatter, 23U)) + RotL64(aCarry, 53U)) + 17155609083870983149U) + aNonceWordG;
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 11U)) + RotL64(aCarry, 29U)) + 2423018561430181695U;
            aOrbiterA = (aWandererD + RotL64(aCross, 40U)) + 12957280305617615744U;
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 19U)) + 2461704174772065813U) + aNonceWordK;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 57U)) + 7907123257849391997U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 7257868138318960007U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterE) ^ 16425903703085702285U) ^ aOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 7996935869077231999U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 2990822664594079467U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 5654819006718953817U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4465096036756887801U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 12183676471235678779U) + aNonceWordM;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 15026286960542123922U;
            aOrbiterF = RotL64((aOrbiterF * 17199049329995315279U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 12169080607071830522U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 2906296852254787499U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6754514406846040163U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 3029858695410344584U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 14406410317495954566U;
            aOrbiterH = RotL64((aOrbiterH * 9663780721657983421U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 11048818178401163861U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 13622063920319445043U;
            aOrbiterE = RotL64((aOrbiterE * 2516025554421589857U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 2642646089141233277U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 12761571777929273548U;
            aOrbiterI = RotL64((aOrbiterI * 5518252696078700127U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 7753802695131502382U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 8510425459525030222U) ^ aNonceWordA;
            aOrbiterJ = RotL64((aOrbiterJ * 12412361423636026483U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 13522645164493316722U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterB) ^ 1437430302489702713U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterK = RotL64((aOrbiterK * 14019316635365783545U), 35U);
            //
            aIngress = RotL64(aOrbiterF, 11U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterA, 23U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterB, 14U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterI, 35U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 51U) + aOrbiterI) + RotL64(aOrbiterA, 30U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 30U) + aOrbiterJ) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 19U)) + aWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterH, 5U));
            aWandererD = aWandererD + (((RotL64(aScatter, 21U) + aOrbiterD) + RotL64(aOrbiterB, 53U)) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 39U) + RotL64(aOrbiterA, 43U)) + aOrbiterH) + aNonceWordE) + aWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 26U) + aOrbiterE) + RotL64(aOrbiterD, 57U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterI, 39U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 35U) + aOrbiterD) + RotL64(aOrbiterI, 24U)) + aNonceWordJ);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 34U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 11U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 27056U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneC[((aIndex + 26468U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 31300U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32246U)) & S_BLOCK1], 56U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 27224U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 28831U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 10U) + RotL64(aCarry, 51U)) + (RotL64(aIngress, 27U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterE = (aWandererJ + RotL64(aScatter, 5U)) + 1087148170018530502U;
            aOrbiterJ = ((aWandererK + RotL64(aCross, 23U)) + RotL64(aCarry, 5U)) + 15530846874509311414U;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 53U)) + 16987358651515511212U) + aNonceWordN;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 40U)) + 12504143181007924259U) + aOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aCross, 35U)) + 393322117322732418U) + aNonceWordB;
            aOrbiterF = ((((aWandererA + RotL64(aScatter, 13U)) + RotL64(aCarry, 23U)) + 14325937299241887166U) + aOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterC = (((aWandererE + RotL64(aPrevious, 29U)) + RotL64(aCarry, 13U)) + 9395262907017475742U) + aNonceWordE;
            aOrbiterG = (aWandererC + RotL64(aIngress, 18U)) + 13658510441418344769U;
            aOrbiterK = (aWandererI + RotL64(aCross, 57U)) + 6410754322737005336U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 9257290738538818434U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 7489828960857692286U) ^ aOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16519674788777989043U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 4118778591214588387U) + aNonceWordO;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 16619215231168796563U;
            aOrbiterJ = RotL64((aOrbiterJ * 14876884956536265157U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 11326283811003573430U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 1865401866017614604U;
            aOrbiterC = RotL64((aOrbiterC * 8378326058282460073U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 670150121105733604U) + aNonceWordM;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 1499331510641068749U;
            aOrbiterE = RotL64((aOrbiterE * 16623742535540383107U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 1116410848560838532U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 2696841341036281779U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9598953298074904869U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 5487352391229549881U) + aNonceWordK;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 12008243050943342979U;
            aOrbiterF = RotL64((aOrbiterF * 9087261224804582459U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 552859665927882960U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 8426942688524814473U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10916963622695549105U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 1613287981244830815U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 15592897923468694288U) ^ aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6600750586743893303U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 7629853970631002676U) + aNonceWordH;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 13778028957247561272U;
            aOrbiterK = RotL64((aOrbiterK * 4063798788229605659U), 39U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterI, 40U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterG, 11U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterH, 4U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 44U) + RotL64(aOrbiterJ, 13U)) + aOrbiterC) + aNonceWordD);
            aWandererE = aWandererE + ((((RotL64(aCross, 3U) + aOrbiterF) + RotL64(aOrbiterI, 35U)) + aNonceWordA) + aWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 23U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterE, 39U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 23U) + aOrbiterI) + RotL64(aOrbiterJ, 51U)) + aNonceWordF);
            aWandererK = aWandererK + (((RotL64(aPrevious, 60U) + RotL64(aOrbiterJ, 47U)) + aOrbiterD) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterG, 30U)) + aOrbiterK);
            aWandererI = aWandererI + (((((RotL64(aCross, 29U) + RotL64(aOrbiterD, 19U)) + aOrbiterC) + RotL64(aCarry, 27U)) + aNonceWordG) + aWandererUpdateSaltA[((aIndex + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 4U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + RotL64(aWandererC, 27U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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

void TwistExpander_VolleyBall_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;
    std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xD4FAB8481E650D41ULL + 0x9FE6E6F3DD3177A4ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xF393B8A93BA39243ULL + 0xBBD27D5D45749C6CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xBED8B64ED1A4948DULL + 0xDD27DE6369888549ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xBCCCFFA2EFE080B3ULL + 0xF2C0B3ED112EC4F9ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x855ACE4EFF364073ULL + 0xABF6018296C681AAULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xD77745F06C35999FULL + 0xA0534D614AAFB911ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xE6380C55966C6EFFULL + 0x8AA7A7036236695FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xE136E77C36AE7E85ULL + 0xC72FCF1BF313A0A1ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xB560EBABAAC1FB1FULL + 0xC8FB496936A41E09ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xDDB8BC7AD2790C47ULL + 0xEA09F09E3AEE70E2ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xE419A47F0CCE683FULL + 0xEE4F17C7CC700B74ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xFD631BA77665ED31ULL + 0x9E8E4FA990AEBE86ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xC046402838BAF6E3ULL + 0xAF68C6938EB8C822ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x89125340AFC63A63ULL + 0x869DA04FBA1CAA34ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xFE912786F251F86FULL + 0xDD89447E70082138ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x91CC2841CC6549DFULL + 0xEBB32BF482B89F8BULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneD, aOperationLaneC, aOperationLaneD, aWorkLaneA, aFireLaneB, aWorkLaneB, aFireLaneA, aWorkLaneC, aFireLaneC
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneD
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneD forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 4120U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneB[((aIndex + 3958U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 6083U)) & S_BLOCK1], 34U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2307U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 4436U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 52U) + RotL64(aCross, 21U)) ^ (RotL64(aIngress, 39U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterE = (aWandererF + RotL64(aCross, 19U)) + 18319689184146942855U;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 28U)) + 8041304130090501019U) + aNonceWordN;
            aOrbiterK = (((aWandererC + RotL64(aIngress, 11U)) + RotL64(aCarry, 53U)) + 11347064191990897738U) + aOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = ((((aWandererG + RotL64(aScatter, 47U)) + RotL64(aCarry, 27U)) + 15242243470024447468U) + aOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1]) + aNonceWordE;
            aOrbiterC = (((aWandererH + RotL64(aCross, 37U)) + RotL64(aCarry, 41U)) + 10619749107163611105U) + aNonceWordM;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 14795614276221947128U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 1578095288886372393U) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 9953192041564147241U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 13593906305770501684U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 8919815528334599172U;
            aOrbiterF = RotL64((aOrbiterF * 2033810402808238127U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 17425548324720065145U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 11125018338392347335U) ^ aOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4377887040461528587U), 5U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterC) + 3779189180734244399U) + aOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 10958224663276134041U;
            aOrbiterE = RotL64((aOrbiterE * 6206963519509783781U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 4317305352561612995U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 4891139433808505355U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11507024985663120317U), 19U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterK, 29U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 18U));
            aIngress = aIngress + RotL64(aOrbiterJ, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterJ, 38U)) + aOrbiterF) + aWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 37U) + aOrbiterE) + RotL64(aOrbiterK, 13U)) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterK, 3U)) + aOrbiterC) + aWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aScatter, 29U) + aOrbiterC) + RotL64(aOrbiterJ, 21U)) + RotL64(aCarry, 19U)) + aNonceWordC);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 54U) + aOrbiterE) + RotL64(aOrbiterF, 29U)) + aNonceWordD);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 22U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 35U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 11053U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneC[((aIndex + 13046U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 11464U)) & S_BLOCK1], 20U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 8429U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 15477U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 11026U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 37U) + RotL64(aIngress, 24U)) ^ (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterI = (((aWandererB + RotL64(aPrevious, 29U)) + RotL64(aCarry, 13U)) + 16160838483846078448U) + aNonceWordB;
            aOrbiterB = ((aWandererJ + RotL64(aCross, 4U)) + 15404960896190227946U) + aOrbiterAssignSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aScatter, 21U)) + 16904160594024977199U) + aNonceWordK;
            aOrbiterJ = (((aWandererH + RotL64(aIngress, 51U)) + RotL64(aCarry, 29U)) + 17790460246821031802U) + aNonceWordO;
            aOrbiterF = (((aWandererF + RotL64(aScatter, 41U)) + RotL64(aCarry, 51U)) + 16395168254086971959U) + aOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterI = (((aOrbiterI + aOrbiterB) + 7484373204039901786U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordE;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 18026814691322913510U;
            aOrbiterK = RotL64((aOrbiterK * 12688155753775099489U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 15244817793136966450U) + aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = (((aOrbiterB ^ aOrbiterK) ^ 5795491730356335666U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterB = RotL64((aOrbiterB * 13253529465289332171U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 3163873518027801504U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 2690791759507349172U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16677948635136515083U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 17898067251167087906U) + aNonceWordA;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 8028010015006604239U;
            aOrbiterF = RotL64((aOrbiterF * 5601629670521300241U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 7304739457289910555U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 6476837815096530043U;
            aOrbiterI = RotL64((aOrbiterI * 16380545138701113267U), 5U);
            //
            aIngress = RotL64(aOrbiterJ, 34U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + RotL64(aOrbiterB, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 21U) + RotL64(aOrbiterI, 19U)) + aOrbiterJ) + aNonceWordF) + aWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 19U)) + aNonceWordC);
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 42U) + RotL64(aOrbiterK, 27U)) + aOrbiterJ) + aNonceWordL) + aWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 51U) + aOrbiterF) + RotL64(aOrbiterK, 11U)) + RotL64(aCarry, 51U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 11U) + aOrbiterB) + RotL64(aOrbiterJ, 44U)) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 39U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 18965U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneD[((aIndex + 17764U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 22918U)) & S_BLOCK1], 40U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17940U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 19575U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 23431U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 19U) + RotL64(aCarry, 5U)) ^ (RotL64(aIngress, 51U) ^ RotL64(aCross, 34U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterA = (((aWandererB + RotL64(aScatter, 35U)) + RotL64(aCarry, 43U)) + 5131645209694953015U) + aNonceWordI;
            aOrbiterF = ((aWandererE + RotL64(aCross, 43U)) + RotL64(aCarry, 11U)) + 12070391048835379854U;
            aOrbiterG = (((aWandererA + RotL64(aPrevious, 6U)) + RotL64(aCarry, 57U)) + 2604295836242338724U) + aOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (((aWandererC + RotL64(aIngress, 21U)) + 14042039029284001596U) + aOrbiterAssignSaltB[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 53U)) + 8914654543854559327U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 2185619407969359869U) + aNonceWordE;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 5187406295103352574U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10497064008152537837U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 8022832481290871217U) + aNonceWordD;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 8783061916740573472U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3309891377744201773U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 10711028365596196301U) + aOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 13387065038269133571U) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 12444578026365205255U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 11187001318931801582U) + aNonceWordP;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 14191473173276034019U;
            aOrbiterJ = RotL64((aOrbiterJ * 2491253922434756431U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 16207761776716426435U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 9677408414452078760U;
            aOrbiterA = RotL64((aOrbiterA * 5487303383095129949U), 39U);
            //
            aIngress = RotL64(aOrbiterA, 3U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterF, 53U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterC, 38U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 50U) + aOrbiterA) + RotL64(aOrbiterJ, 43U));
            aWandererC = aWandererC + ((((RotL64(aCross, 5U) + aOrbiterF) + RotL64(aOrbiterA, 35U)) + RotL64(aCarry, 47U)) + aNonceWordO);
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 29U) + aOrbiterC) + RotL64(aOrbiterA, 53U)) + aNonceWordC) + aWandererUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterG, 11U)) + aOrbiterJ) + RotL64(aCarry, 13U)) + aWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 39U) + aOrbiterC) + RotL64(aOrbiterJ, 20U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 22U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 28880U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneA[((aIndex + 26073U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 27975U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27136U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 30449U)) & S_BLOCK1], 41U));
            aCross ^= (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 28763U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((aIndex + 30079U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aPrevious, 41U)) ^ (RotL64(aIngress, 3U) + RotL64(aCarry, 20U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterI = (((aWandererJ + RotL64(aScatter, 19U)) + 16424657151168221875U) + aOrbiterAssignSaltD[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordP;
            aOrbiterF = (((aWandererG + RotL64(aIngress, 53U)) + RotL64(aCarry, 41U)) + 17150123681886380361U) + aNonceWordL;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 29U)) + RotL64(aCarry, 53U)) + 16041993588694572757U;
            aOrbiterA = (((aWandererE + RotL64(aPrevious, 42U)) + RotL64(aCarry, 11U)) + 9871185846434828537U) + aNonceWordH;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 5U)) + 11227236398354430757U) + aOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 5399325217402192631U) + aNonceWordO;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 9248828789282890454U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6733832755349139621U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 9041370494203701062U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 14944424084524970764U;
            aOrbiterI = RotL64((aOrbiterI * 10283363059424655079U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 5481938174456671041U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterJ) ^ 14783648629543752715U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterG = RotL64((aOrbiterG * 7260164783191886395U), 3U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterI) + 12355573914530445723U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordD;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 9863991559011968318U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8495251211794343179U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 16149688605937250965U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 106041828692026825U) ^ aNonceWordJ;
            aOrbiterA = RotL64((aOrbiterA * 12199934305374582599U), 21U);
            //
            aIngress = RotL64(aOrbiterF, 57U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterI, 26U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterJ, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterG, 13U)) + aWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aIngress, 10U) + aOrbiterF) + RotL64(aOrbiterJ, 43U)) + RotL64(aCarry, 47U)) + aNonceWordA);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterA, 3U)) + aNonceWordE);
            aWandererA = aWandererA + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 22U)) + aOrbiterG) + RotL64(aCarry, 5U)) + aNonceWordI);
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 57U)) + aOrbiterJ) + aNonceWordC) + aWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 60U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_VolleyBall_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xEEE4E96C2D3E30C1ULL + 0xFFA95E4616D3DF96ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xBF0B383B2A1A664BULL + 0xD31B645201CCD188ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xF084F49D3C19A6E3ULL + 0xF8E556ED98E25FB3ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xA835EC21373D2369ULL + 0xCB8F765FDBE417D6ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xD86B3E9F0C87DE47ULL + 0x8EE7A7C7A1E058A1ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xB8E8BFD8D7C13DC1ULL + 0xCFB1A7A7EB7034ACULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x966A467BF64729B3ULL + 0xE5C1D7C32F8D14DAULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xCD660BB7EE5EEF01ULL + 0x9CE0F48535CA8F10ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xECE887C8FB5399F7ULL + 0xB2B04C44102BCBD8ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x94B6563BAABE4359ULL + 0xBBAB5A536304A139ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xBCD78504362913E7ULL + 0xE1C2DEC10FE08137ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xEC0C93554C190783ULL + 0xDE5134394F997093ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xAF5E37C5D21AB227ULL + 0xCDC8425F130F62B3ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xFC6E4954D38927C1ULL + 0xA2172BAA2E67DFB4ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xA610BF4FCF923413ULL + 0xA58CDF2CB8E5C0A2ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xE02D729AD8CAF2CDULL + 0xAD40C4A9B7E773FDULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneA, aExpandLaneC, aExpandLaneD, aOperationLaneA, aWorkLaneA, aOperationLaneD, aOperationLaneC, aWorkLaneB, aOperationLaneB, aFireLaneB, aWorkLaneC, aFireLaneC, aFireLaneD
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_d loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aOperationLaneA
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 4391U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((aIndex + 125U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 5636U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1812U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 1410U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 4789U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aPrevious, 3U)) + (RotL64(aIngress, 23U) + RotL64(aCarry, 50U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterI = (aWandererJ + RotL64(aScatter, 58U)) + 9023059520606551446U;
            aOrbiterF = (((aWandererK + RotL64(aIngress, 3U)) + RotL64(aCarry, 39U)) + 662441755115638133U) + aNonceWordI;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 11U)) + RotL64(aCarry, 53U)) + 16957253361196144712U;
            aOrbiterH = ((((aWandererD + RotL64(aPrevious, 41U)) + RotL64(aCarry, 13U)) + 7840955025765308605U) + aOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordF;
            aOrbiterE = (((aWandererB + RotL64(aIngress, 35U)) + 346855809270395799U) + aOrbiterAssignSaltF[((aIndex + 20U)) & S_SALT1]) + aNonceWordP;
            aOrbiterG = (aWandererG + RotL64(aPrevious, 29U)) + 16099139781586668343U;
            aOrbiterK = (aWandererH + RotL64(aScatter, 19U)) + 3706457327118322098U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 12166825885547622870U) + aNonceWordH;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 7792658665720344200U;
            aOrbiterJ = RotL64((aOrbiterJ * 16305542632794270697U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 7128477606152986326U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterH) ^ 11116533962780290084U) ^ aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 11993485572912492297U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 10443889548568288532U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 4402387036946561017U) ^ aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9032964741841833277U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 13002706161178447654U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 13929727277530310708U;
            aOrbiterH = RotL64((aOrbiterH * 7005639090871200285U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 10949073760696935106U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 15405923432006783533U) ^ aOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17989565878445202495U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 18096057968822208905U) + aNonceWordL;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 3032155040484574973U;
            aOrbiterI = RotL64((aOrbiterI * 448597307502544605U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 17462076466907467134U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 15471015427013701406U) ^ aNonceWordB;
            aOrbiterE = RotL64((aOrbiterE * 6113474000571976139U), 13U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterI, 11U);
            aIngress = aIngress + (RotL64(aOrbiterF, 21U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 43U)) + aOrbiterE) + aNonceWordA);
            aWandererK = aWandererK + ((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterF, 27U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterK, 60U)) + aOrbiterI) + aNonceWordJ);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterG, 5U)) + aOrbiterF) + RotL64(aCarry, 3U)) + aWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 27U) + RotL64(aOrbiterF, 13U)) + aOrbiterH) + aNonceWordK) + aWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 19U)) + aOrbiterE) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 34U) + RotL64(aOrbiterE, 37U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 10U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 53U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 2
        // ingress from: aWorkLaneA, aExpandLaneC, aOperationLaneD
        // ingress directions: aWorkLaneA forward forced, aExpandLaneC forward forced, aOperationLaneD forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aOperationLaneC
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 10411U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneC[((aIndex + 11641U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 8310U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 12544U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11150U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 11866U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 38U) + RotL64(aCross, 53U)) ^ (RotL64(aIngress, 23U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterF = (aWandererI + RotL64(aScatter, 35U)) + 2783898056762489197U;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 27U)) + RotL64(aCarry, 57U)) + 7177192902873343053U;
            aOrbiterJ = (aWandererC + RotL64(aCross, 42U)) + 12254703232691980774U;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 57U)) + 15446547245691219559U) + aOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = (((aWandererK + RotL64(aPrevious, 3U)) + 888475203006174856U) + aOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordG;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 11U)) + RotL64(aCarry, 27U)) + 3649183529366307877U;
            aOrbiterH = (((aWandererJ + RotL64(aScatter, 51U)) + RotL64(aCarry, 43U)) + 4642631047518805167U) + aNonceWordB;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 6108329730724782250U) + aNonceWordA;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 8334054653023816636U) ^ aNonceWordP;
            aOrbiterJ = RotL64((aOrbiterJ * 9352516059501924393U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 5891895375031474350U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 3176720746238477862U;
            aOrbiterF = RotL64((aOrbiterF * 1869961473768307911U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 6111038696865301675U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 11914998302228682704U) ^ aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11738924766359642853U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 17005063057791320948U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 18333780598768130670U) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 5416759844884107303U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 2056115016443263153U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 10245512728872962677U;
            aOrbiterI = RotL64((aOrbiterI * 707106795383284903U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 4810366069422162351U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterH) ^ 3051442983125942469U) ^ aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 13558537578054436423U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 9285068547223654308U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 13067251130180968842U) ^ aOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7000687697769766605U), 57U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterJ, 57U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + RotL64(aOrbiterD, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aCross, 20U) + aOrbiterE) + RotL64(aOrbiterD, 3U)) + aNonceWordD);
            aWandererB = aWandererB + (((RotL64(aScatter, 43U) + aOrbiterJ) + RotL64(aOrbiterF, 23U)) + RotL64(aCarry, 47U));
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 51U) + RotL64(aOrbiterF, 13U)) + aOrbiterB) + aNonceWordN) + aWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterD, 51U)) + aNonceWordO);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 30U)) + aOrbiterD);
            aWandererF = aWandererF + (((((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterI, 43U)) + RotL64(aCarry, 11U)) + aNonceWordJ) + aWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 57U) + aOrbiterE) + RotL64(aOrbiterI, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 52U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 3
        // ingress from: aWorkLaneB, aExpandLaneD, aOperationLaneB
        // ingress directions: aWorkLaneB forward forced, aExpandLaneD forward forced, aOperationLaneB forward/backward random
        // cross from: aWorkLaneA, aExpandLaneB, aFireLaneB
        // cross directions: aWorkLaneA backward forced, aExpandLaneB backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 21392U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneD[((aIndex + 18523U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 17635U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21345U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 21433U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 23424U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 43U) + RotL64(aCarry, 29U)) ^ (RotL64(aIngress, 10U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterF = ((aWandererB + RotL64(aIngress, 37U)) + 17454559218352016650U) + aOrbiterAssignSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 5U)) + 8005709669325164803U;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 47U)) + 13393741948412816357U) + aNonceWordP;
            aOrbiterH = (((aWandererH + RotL64(aCross, 53U)) + RotL64(aCarry, 43U)) + 3665865624348875553U) + aOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = (((aWandererI + RotL64(aPrevious, 29U)) + RotL64(aCarry, 19U)) + 8334142570031883436U) + aNonceWordA;
            aOrbiterI = (((aWandererC + RotL64(aScatter, 12U)) + RotL64(aCarry, 5U)) + 17226066128706139657U) + aNonceWordJ;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 23U)) + 3319093033121522613U) + aNonceWordK;
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 6657535603401588798U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 5469746182326331147U;
            aOrbiterD = RotL64((aOrbiterD * 11315450342347794329U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 17846791786050221418U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 15939541003714896288U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1400351482213119809U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 12076763190461077406U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 3594038213596405284U) ^ aNonceWordF;
            aOrbiterH = RotL64((aOrbiterH * 10244002692575821495U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 8301291631324464622U) + aOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 8460406137668390582U;
            aOrbiterF = RotL64((aOrbiterF * 9117147929757711595U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 7612394867020871200U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 8525076134853103975U;
            aOrbiterC = RotL64((aOrbiterC * 5790440201072204659U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 11929899088215090379U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 7119509166360685726U) ^ aOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1662341427992528823U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 5081078459225240607U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterB) ^ 17149991983909906705U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterJ = RotL64((aOrbiterJ * 950223374568067343U), 5U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 47U);
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 56U));
            aIngress = aIngress + RotL64(aOrbiterH, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aIngress, 22U) + RotL64(aOrbiterF, 29U)) + aOrbiterB) + aNonceWordB);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterI, 23U)) + aWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aCross, 47U) + RotL64(aOrbiterD, 43U)) + aOrbiterJ) + RotL64(aCarry, 27U)) + aNonceWordD);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterJ, 5U)) + aOrbiterC) + aWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 37U)) + aOrbiterF) + RotL64(aCarry, 47U)) + aNonceWordO);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterI, 56U)) + aOrbiterJ);
            aWandererI = aWandererI + ((RotL64(aIngress, 41U) + aOrbiterD) + RotL64(aOrbiterC, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 60U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aFireLaneC
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aFireLaneC forward/backward random
        // cross from: aWorkLaneB, aExpandLaneC, aFireLaneD
        // cross directions: aWorkLaneB backward forced, aExpandLaneC backward forced, aFireLaneD backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 28590U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 31934U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 25232U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25552U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 25020U)) & S_BLOCK1], 48U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 29101U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 53U)) + (RotL64(aCross, 10U) ^ RotL64(aIngress, 29U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterB = ((aWandererE + RotL64(aScatter, 51U)) + 9107326720193244489U) + aNonceWordE;
            aOrbiterG = (aWandererA + RotL64(aPrevious, 13U)) + 10868585484401664145U;
            aOrbiterF = (((aWandererI + RotL64(aCross, 27U)) + RotL64(aCarry, 19U)) + 13637736741437846622U) + aOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = ((aWandererF + RotL64(aIngress, 41U)) + RotL64(aCarry, 41U)) + 6130725216183918844U;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 6U)) + 2063834478521338187U) + aNonceWordP;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 35U)) + 8564870627911949158U) + aOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aScatter, 57U)) + RotL64(aCarry, 53U)) + 6524015751064086390U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 9874937766875388236U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 14723718409522680894U;
            aOrbiterF = RotL64((aOrbiterF * 17379140128833323431U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 13767059954741528279U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 6387608251033722169U) ^ aNonceWordB;
            aOrbiterK = RotL64((aOrbiterK * 6601902195707980693U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 5391425980008431000U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 11524218415655093779U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12508457981779189389U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 155510463350385905U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 10554591788433641311U) ^ aOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5412084824127934293U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 8662160162966241542U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 5092555636369853727U;
            aOrbiterA = RotL64((aOrbiterA * 433807340167635499U), 53U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterA) + 7163345798448796101U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordG;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 695089002178413267U) ^ aNonceWordC;
            aOrbiterB = RotL64((aOrbiterB * 17302689458565434475U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 5409173939213468972U) + aNonceWordH;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 15349690077393827541U;
            aOrbiterG = RotL64((aOrbiterG * 10984681254001609841U), 29U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterB, 13U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 27U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + RotL64(aOrbiterF, 48U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 21U)) + aOrbiterB) + aWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterG, 47U)) + aOrbiterF) + aWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 51U) + RotL64(aOrbiterA, 56U)) + aOrbiterB) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 35U)) + aOrbiterA) + aNonceWordK);
            aWandererH = aWandererH + (((RotL64(aCross, 10U) + RotL64(aOrbiterK, 41U)) + aOrbiterC) + aNonceWordJ);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterI, 3U)) + aOrbiterC) + aNonceWordI);
            aWandererD = aWandererD + (((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 14U));
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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

void TwistExpander_VolleyBall_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xE41257D09A06FA13ULL + 0x815BF15E1E25A509ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xBB8E6138DFFBB7A9ULL + 0xC649F2E31911E3BCULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xE585958DD3523CE5ULL + 0xF05586FD58CDD09CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xA74F02016EB1C65FULL + 0xE4B24D4CC2C19376ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xDB232BF37FC4F98BULL + 0xC57994039CAF843BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x935A467BD28DF80DULL + 0xC24F99EC24C495B2ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x98A11D501F8B8D8DULL + 0xBD8AA4D31A91A0A4ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xE4A844DBF0A3BA1BULL + 0x8BE337244A128749ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xFB9D7C72273505B7ULL + 0x97B8143FD0CE479EULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xE8D21B1589C45429ULL + 0xCC364154940CF297ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x840E31DED03EFF6BULL + 0x98C21EA060354FB7ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x9AA72C1384030DD1ULL + 0xF014B17B5F3D2A16ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xAF3638C359F7D841ULL + 0xD86FC366FA0DCA10ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xDDE734F9CB19556FULL + 0xADD8C979DF137AD1ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xE446B736A05559F9ULL + 0xF15D85F55F5F747EULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xE0E0DBF14A62AF2FULL + 0xAB05E18365E4BEF7ULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aFireLaneC, aWorkLaneC, aWorkLaneD, aFireLaneD, aExpandLaneA, aOperationLaneB, aFireLaneB, aExpandLaneB, aOperationLaneD, aOperationLaneC, aExpandLaneC, aOperationLaneA, aFireLaneA
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_a loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aFireLaneC
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aFireLaneC forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aFireLaneD
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 7497U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((aIndex + 2324U)) & S_BLOCK1], 38U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 7665U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 2072U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 213U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 7567U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 13U) ^ RotL64(aCross, 58U)) + (RotL64(aCarry, 29U) ^ RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterJ = (aWandererJ + RotL64(aCross, 19U)) + 15036852811491820366U;
            aOrbiterA = ((((aWandererE + RotL64(aScatter, 35U)) + RotL64(aCarry, 53U)) + 305637140752898475U) + aOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordE;
            aOrbiterB = (((aWandererC + RotL64(aPrevious, 56U)) + RotL64(aCarry, 23U)) + 11948631574496129610U) + aNonceWordK;
            aOrbiterF = (((aWandererK + RotL64(aIngress, 47U)) + RotL64(aCarry, 41U)) + 5321623592482991426U) + aNonceWordG;
            aOrbiterG = (aWandererD + RotL64(aCross, 3U)) + 4075270159062690728U;
            aOrbiterK = (((aWandererB + RotL64(aScatter, 29U)) + 15111580500356908928U) + aOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1]) + aNonceWordP;
            aOrbiterI = (aWandererF + RotL64(aPrevious, 13U)) + 7244150695504160363U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 5131563519577488862U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 5881954992088651371U) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 2424421828597294607U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 12780935808751507998U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 12599159643925470226U) ^ aNonceWordL;
            aOrbiterG = RotL64((aOrbiterG * 17690046932587062701U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 9466589929741834066U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 6093158735705189789U;
            aOrbiterA = RotL64((aOrbiterA * 7453778295800853653U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 17461243886150519249U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 15456408913739900718U;
            aOrbiterK = RotL64((aOrbiterK * 16093292401746174671U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 11260643903290392780U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 7870342756041882616U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2431528656086173419U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 134484990005888936U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 10626896209992890407U) ^ aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12034131076645285597U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 14031164129515132292U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 1771835705730244212U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 186981668443596623U), 37U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterJ, 57U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + RotL64(aOrbiterK, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 11U)) + aOrbiterG);
            aWandererF = aWandererF + (((RotL64(aCross, 60U) + RotL64(aOrbiterI, 5U)) + aOrbiterK) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 43U)) + aOrbiterA) + aNonceWordI);
            aWandererC = aWandererC + ((RotL64(aPrevious, 29U) + aOrbiterB) + RotL64(aOrbiterJ, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterK, 53U)) + aOrbiterA);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterG, 21U)) + aOrbiterB) + RotL64(aCarry, 5U)) + aWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 60U)) + aOrbiterF) + aNonceWordF) + aWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 18U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 3U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aOperationLaneB
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aOperationLaneB forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aFireLaneB
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 13608U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneC[((aIndex + 15078U)) & S_BLOCK1], 22U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8748U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9852U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8786U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 16113U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCross, 52U)) + (RotL64(aCarry, 37U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 37U)) + 12122689833405846292U) + aOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = (((aWandererI + RotL64(aCross, 13U)) + RotL64(aCarry, 39U)) + 9640400270962766788U) + aNonceWordE;
            aOrbiterA = (aWandererH + RotL64(aScatter, 5U)) + 9141937998266739071U;
            aOrbiterE = (((aWandererA + RotL64(aIngress, 21U)) + RotL64(aCarry, 27U)) + 12899395770434090537U) + aNonceWordC;
            aOrbiterD = (aWandererF + RotL64(aScatter, 50U)) + 13457918115408031842U;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 43U)) + RotL64(aCarry, 11U)) + 15134784483576000943U;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 29U)) + 12540961268790055438U) + aOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 6306886773092764230U) + aNonceWordO;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 13573343491337243121U;
            aOrbiterA = RotL64((aOrbiterA * 15893457012357368707U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 8545588657348974413U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 10891410570357275120U;
            aOrbiterH = RotL64((aOrbiterH * 5399310978367842841U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 2877137119767060151U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 9178097682386595144U) ^ aOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3524486002084427513U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 15528007881855616978U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 11368419529245281435U) ^ aOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12433207037378339309U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 5932738914934356645U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 5551842263864055419U;
            aOrbiterG = RotL64((aOrbiterG * 16093776759971522681U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 3824433359595690603U) + aNonceWordF;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 17184628855571662441U;
            aOrbiterE = RotL64((aOrbiterE * 691208053136187317U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 8724462245014132623U) + aNonceWordN;
            aOrbiterB = (((aOrbiterB ^ aOrbiterH) ^ 7481349499528092352U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 8212182934509617583U), 27U);
            //
            aIngress = RotL64(aOrbiterA, 21U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterD, 37U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterB, 54U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterE, 21U)) + aOrbiterG) + aWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 34U) + RotL64(aOrbiterB, 3U)) + aOrbiterH) + RotL64(aCarry, 57U)) + aWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterG, 53U)) + aOrbiterA) + aNonceWordB);
            aWandererD = aWandererD + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterG, 46U)) + aOrbiterD) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterE, 27U));
            aWandererB = aWandererB + (((RotL64(aCross, 43U) + RotL64(aOrbiterD, 39U)) + aOrbiterI) + aNonceWordG);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterI, 13U)) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 30U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aOperationLaneD
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aOperationLaneD forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aOperationLaneC
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 16704U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneD[((aIndex + 16395U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20121U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20604U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19546U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 16723U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCarry, 6U)) ^ (RotL64(aCross, 41U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterB = (((aWandererH + RotL64(aCross, 4U)) + RotL64(aCarry, 53U)) + 12136097566601676613U) + aNonceWordB;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 21U)) + RotL64(aCarry, 23U)) + 7969431322248040056U;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 11U)) + RotL64(aCarry, 5U)) + 10530676021510553889U;
            aOrbiterG = ((aWandererE + RotL64(aIngress, 43U)) + 8740777303075445264U) + aNonceWordA;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 35U)) + 13249434169895564739U) + aOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = (((aWandererJ + RotL64(aPrevious, 51U)) + 15529577005925628472U) + aOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterF = (aWandererD + RotL64(aIngress, 29U)) + 344627093687331562U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 8824277416519988893U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 5636276438449709875U;
            aOrbiterJ = RotL64((aOrbiterJ * 222817930773618893U), 47U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterI) + 2079413361031851552U) + aOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1]) + aNonceWordN;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 7807998179168655561U;
            aOrbiterH = RotL64((aOrbiterH * 961456853699784753U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 13589392896232029112U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 10733011474804473996U;
            aOrbiterF = RotL64((aOrbiterF * 361749145931578805U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 15934162328347805968U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 7573511217796245232U) ^ aOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10694563909931636155U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 4828475187337891975U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 13284974329890393113U) ^ aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10831075817642374287U), 53U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterF) + 13173869918669643112U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordC;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 15841507674783398167U;
            aOrbiterB = RotL64((aOrbiterB * 15632933198136963277U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 14168272451055700516U) + aNonceWordD;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 11134471485501999898U) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 8019507184494591705U), 29U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 41U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 48U));
            aIngress = aIngress + RotL64(aOrbiterB, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterJ, 58U)) + aOrbiterC);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 13U) + aOrbiterH) + RotL64(aOrbiterB, 19U));
            aWandererC = aWandererC + ((((RotL64(aIngress, 5U) + aOrbiterC) + RotL64(aOrbiterF, 37U)) + RotL64(aCarry, 23U)) + aWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterG, 29U)) + aOrbiterC) + aNonceWordO);
            aWandererK = aWandererK + (((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterH, 51U)) + aNonceWordI);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterB, 13U)) + aWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aCross, 44U) + aOrbiterI) + RotL64(aOrbiterG, 43U)) + RotL64(aCarry, 5U)) + aNonceWordG);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (RotL64(aWandererC, 56U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aOperationLaneA
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aOperationLaneA forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aFireLaneA
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aFireLaneA backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 32242U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneA[((aIndex + 25035U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 32438U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31816U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 27232U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 31921U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 57U)) + (RotL64(aCarry, 20U) ^ RotL64(aIngress, 43U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterA = ((aWandererA + RotL64(aIngress, 47U)) + 16462052553719977502U) + aOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aCross, 53U)) + 12337064059566619581U) + aNonceWordJ;
            aOrbiterF = (((aWandererG + RotL64(aScatter, 19U)) + RotL64(aCarry, 3U)) + 15801005007094515447U) + aNonceWordN;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 3U)) + 8228706742665081656U;
            aOrbiterE = (aWandererF + RotL64(aScatter, 37U)) + 11006723027845190869U;
            aOrbiterJ = (((aWandererH + RotL64(aIngress, 11U)) + RotL64(aCarry, 53U)) + 18173765337829177450U) + aNonceWordD;
            aOrbiterK = ((((aWandererI + RotL64(aCross, 60U)) + RotL64(aCarry, 41U)) + 530215083653542558U) + aOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordI;
            //
            aOrbiterA = (((aOrbiterA + aOrbiterB) + 6608611827035564511U) + aOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1]) + aNonceWordC;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 2246051826221626809U;
            aOrbiterF = RotL64((aOrbiterF * 6333352641495253539U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 5228575308895381421U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 10999213210689606857U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5467601259546342925U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 3773371037240485696U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 8887985779436152504U;
            aOrbiterG = RotL64((aOrbiterG * 698713082830739677U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 11150566414723818350U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 8336366151003049546U;
            aOrbiterE = RotL64((aOrbiterE * 9033771197242493699U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 13233968794237090787U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterJ) ^ 8172558473508478819U) ^ aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterA = RotL64((aOrbiterA * 17837070423649268435U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 133564480283347997U) + aNonceWordF;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 15104810248883567064U) ^ aOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 706802420642303533U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 9138629520201127075U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 13993086066341664080U;
            aOrbiterJ = RotL64((aOrbiterJ * 4875046427147105077U), 13U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterK, 13U);
            aIngress = aIngress + (RotL64(aOrbiterE, 36U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aScatter, 56U) + RotL64(aOrbiterA, 13U)) + aOrbiterG) + aWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterB, 6U)) + RotL64(aCarry, 43U)) + aWandererUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterK, 41U)) + aNonceWordA);
            aWandererG = aWandererG + ((((RotL64(aCross, 41U) + aOrbiterJ) + RotL64(aOrbiterA, 51U)) + RotL64(aCarry, 29U)) + aNonceWordH);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterF, 21U)) + aOrbiterB);
            aWandererH = aWandererH + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterB, 57U)) + aOrbiterA);
            aWandererF = aWandererF ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterG, 35U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (RotL64(aWandererF, 30U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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

void TwistExpander_VolleyBall_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x81C5B726169C8E31ULL + 0x9C66AFAF7E6C7F43ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x8783B9CB4AE25B97ULL + 0x82ECB50D971FFDADULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xC3968186904CEDA1ULL + 0xCC0AF0C3F84DF2CBULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xE138ED86CC59907BULL + 0xE646BFF5BD7D9E06ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xB0ECF7063B2843D7ULL + 0xFEE64627558DAA3AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xD94807F0F00AC771ULL + 0xA5DDA71B951C15A0ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xF2445388E7199EDDULL + 0xFD90BFCA1A52BB51ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x83606160F8323141ULL + 0xCA485734448B3C40ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xB504F32D2527A8A5ULL + 0xEA5962FAD448306CULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xE694063F1A915215ULL + 0xFCD8AE99DA42135CULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xAEE225080F8BD91DULL + 0xE2991EDAEC0654E5ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xAEBFF5A787E8FA81ULL + 0xF74CBA032952456FULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xD14299F819D0AF61ULL + 0xF69E3DEAA662996CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x9421929BE61F55BFULL + 0xA16EB99E5F727C83ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xE4539F8CC926B81FULL + 0x957799ACB0F3EA72ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xB0073238751EB655ULL + 0x9C81E7DCA6C592D6ULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneB, aExpandLaneC, aExpandLaneD, aFireLaneD, aOperationLaneA, aWorkLaneB, aFireLaneA, aOperationLaneB, aFireLaneC, aWorkLaneD, aOperationLaneC, aWorkLaneC, aWorkLaneA
        // write to: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // kdf_b_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneB
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aFireLaneD
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aFireLaneD backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3051U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((aIndex + 5615U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 7520U)) & S_BLOCK1], 38U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4917U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 7699U)) & S_BLOCK1], 12U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 5289U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 34U) + RotL64(aIngress, 19U)) ^ (RotL64(aCarry, 47U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterH = ((aWandererD + RotL64(aIngress, 34U)) + RotL64(aCarry, 39U)) + 6916817163240024692U;
            aOrbiterC = (aWandererI + RotL64(aCross, 19U)) + 14554930751292077817U;
            aOrbiterE = (aWandererG + RotL64(aPrevious, 41U)) + 1098305064484336101U;
            aOrbiterD = (aWandererH + RotL64(aScatter, 5U)) + 12192821172420471527U;
            aOrbiterF = (((aWandererE + RotL64(aCross, 38U)) + RotL64(aCarry, 29U)) + 2435134991707318845U) + aNonceWordH;
            aOrbiterB = (aWandererA + RotL64(aScatter, 21U)) + 1896745368738512624U;
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 43U)) + 1114996424222923873U) + aNonceWordK;
            aOrbiterA = (aWandererK + RotL64(aPrevious, 27U)) + 9839135798371512656U;
            aOrbiterI = (((aWandererB + RotL64(aScatter, 51U)) + RotL64(aCarry, 51U)) + 8037967239603177043U) + aOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aCross, 53U)) + 15185468738487237432U) + aOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aIngress, 3U)) + 4912098316394854543U) + aNonceWordF;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 13142688607850380888U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 4507379759608945839U;
            aOrbiterE = RotL64((aOrbiterE * 2989332387754215967U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 7299006009652289342U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 5390655277207053627U;
            aOrbiterF = RotL64((aOrbiterF * 10973744708856143715U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 6744737023577785725U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 15539737698867067285U;
            aOrbiterA = RotL64((aOrbiterA * 4686092035261336911U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 13329866734681377952U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 13284937458969166257U;
            aOrbiterI = RotL64((aOrbiterI * 3965985432462699445U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 8695002088915702168U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterA) ^ 3858059421620839286U) ^ aOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 9559783727301092937U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 6609163873243179836U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 9416165620556710540U) ^ aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 240385043740268229U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 1578449067529000433U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 14309000104419489303U;
            aOrbiterG = RotL64((aOrbiterG * 7599078306153684729U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 15785180680737461320U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 10099222679918382021U;
            aOrbiterJ = RotL64((aOrbiterJ * 2012232597046182581U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 10666287769220108179U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 13648647399222807034U) ^ aOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10772381733103127201U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 9292207828896796810U) + aNonceWordI;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 9155130791347443553U;
            aOrbiterC = RotL64((aOrbiterC * 16838229790655977057U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 11334395119119245556U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 6916817163240024692U;
            aOrbiterH = RotL64((aOrbiterH * 9640906826978028183U), 51U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterD, 20U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterH, 52U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterK, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 50U) + RotL64(aOrbiterA, 3U)) + aOrbiterD) + aNonceWordJ);
            aWandererH = aWandererH + (((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterC, 19U)) + aWandererUpdateSaltF[((aIndex + 22U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 53U) + aOrbiterH) + RotL64(aOrbiterI, 21U));
            aWandererD = aWandererD + (((RotL64(aCross, 43U) + RotL64(aOrbiterF, 41U)) + aOrbiterJ) + RotL64(aCarry, 23U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterG, 43U)) + aNonceWordB);
            aWandererC = aWandererC + ((RotL64(aCross, 11U) + RotL64(aOrbiterD, 58U)) + aOrbiterG);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 27U) + aOrbiterJ) + RotL64(aOrbiterE, 5U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 21U) + aOrbiterK) + RotL64(aOrbiterE, 29U)) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 23U) + aOrbiterI) + RotL64(aOrbiterA, 37U)) + aNonceWordO) + aWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterE, 10U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 6U) + RotL64(aOrbiterA, 27U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + (RotL64(aWandererE, 22U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + RotL64(aWandererJ, 50U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 2
        // ingress from: aOperationLaneA, aExpandLaneC, aWorkLaneB
        // ingress directions: aOperationLaneA forward forced, aExpandLaneC forward forced, aWorkLaneB forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aFireLaneA
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aFireLaneA backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 13698U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneC[((aIndex + 11945U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 14523U)) & S_BLOCK1], 10U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 12513U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11942U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 15292U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 6U) + RotL64(aIngress, 19U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 58U)) + 18087125778766689269U;
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 39U)) + 13710545066503235196U) + aOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aCross, 41U)) + 1701939704736254645U;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 47U)) + RotL64(aCarry, 23U)) + 8064093611384019909U;
            aOrbiterC = (aWandererI + RotL64(aIngress, 5U)) + 16623332751533885431U;
            aOrbiterK = (aWandererA + RotL64(aScatter, 24U)) + 15590129153794910109U;
            aOrbiterB = ((((aWandererG + RotL64(aCross, 27U)) + RotL64(aCarry, 53U)) + 7413312683079107383U) + aOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordA;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 35U)) + 4186064478651458810U;
            aOrbiterE = (aWandererE + RotL64(aCross, 29U)) + 5501191643940735954U;
            aOrbiterI = (((aWandererF + RotL64(aIngress, 13U)) + RotL64(aCarry, 37U)) + 11064645242200570835U) + aNonceWordL;
            aOrbiterD = (aWandererB + RotL64(aPrevious, 43U)) + 13825922087298055833U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 5944980709887369970U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 8181136916070569646U;
            aOrbiterG = RotL64((aOrbiterG * 395183021205661827U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 15442336949157292482U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 11580554435240641337U;
            aOrbiterK = RotL64((aOrbiterK * 6654637892858767739U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 11240018128174598322U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 2027565596050777471U;
            aOrbiterB = RotL64((aOrbiterB * 18048186560314431815U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 16425887196883725233U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 16828683527588834095U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17746289103235902485U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 9923829146479008804U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 6669171007279929454U;
            aOrbiterE = RotL64((aOrbiterE * 681823450939955099U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 3902430046523165149U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 6739998149289590041U;
            aOrbiterI = RotL64((aOrbiterI * 2675037435528416821U), 43U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterI) + 16014401255534234075U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordG;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 14741857638680634564U;
            aOrbiterC = RotL64((aOrbiterC * 8723611021403369393U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 5064807861673260054U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 968747317273200299U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14122304002722582329U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 5282686212362051427U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 6902253563196129760U) ^ aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7682808024658992049U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 4995580401402368332U) + aNonceWordM;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 14949762584793646470U;
            aOrbiterF = RotL64((aOrbiterF * 3539183342072953803U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 2378815735788107402U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 18087125778766689269U;
            aOrbiterJ = RotL64((aOrbiterJ * 16799380528404446281U), 53U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterG, 41U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 56U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + RotL64(aOrbiterD, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 58U)) + aOrbiterI);
            aWandererH = aWandererH ^ (((RotL64(aCross, 60U) + RotL64(aOrbiterB, 39U)) + aOrbiterI) + aNonceWordF);
            aWandererC = aWandererC + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterB, 37U)) + aOrbiterE);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 21U)) + aOrbiterE);
            aWandererF = aWandererF + ((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 41U)) + aOrbiterF);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 39U) + aOrbiterJ) + RotL64(aOrbiterG, 35U)) + aWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aCross, 11U) + RotL64(aOrbiterK, 10U)) + aOrbiterA) + RotL64(aCarry, 43U)) + aWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 19U) + aOrbiterC) + RotL64(aOrbiterA, 51U)) + aNonceWordC);
            aWandererK = aWandererK + (((RotL64(aScatter, 46U) + RotL64(aOrbiterK, 53U)) + aOrbiterE) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterF, 19U)) + aNonceWordB);
            aWandererI = aWandererI + (((RotL64(aCross, 37U) + RotL64(aOrbiterB, 3U)) + aOrbiterC) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 56U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + RotL64(aWandererJ, 35U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 3
        // ingress from: aOperationLaneB, aExpandLaneD, aFireLaneC
        // ingress directions: aOperationLaneB forward forced, aExpandLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aOperationLaneA, aExpandLaneB, aWorkLaneD
        // cross directions: aOperationLaneA backward forced, aExpandLaneB backward forced, aWorkLaneD backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 17396U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneD[((aIndex + 22217U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 19514U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 17122U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 19493U)) & S_BLOCK1], 26U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 22449U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 27U) ^ RotL64(aPrevious, 14U)) ^ (RotL64(aCarry, 51U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 41U)) + RotL64(aCarry, 21U)) + 8506388683755208267U;
            aOrbiterC = (((aWandererF + RotL64(aCross, 39U)) + 2179323259055019735U) + aOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordK;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 5U)) + 3345902531140983016U) + aNonceWordG;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 47U)) + RotL64(aCarry, 39U)) + 17456139311481306584U;
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 36U)) + 14587864088462311164U;
            aOrbiterD = ((aWandererH + RotL64(aCross, 53U)) + 13178947246650647057U) + aNonceWordF;
            aOrbiterI = (aWandererD + RotL64(aIngress, 51U)) + 12866578138946916962U;
            aOrbiterG = ((aWandererE + RotL64(aScatter, 19U)) + 13098524333655118173U) + aOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = (aWandererG + RotL64(aIngress, 44U)) + 15451329483787541982U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 3U)) + 9494299579678389385U) + aNonceWordJ;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 23U)) + RotL64(aCarry, 13U)) + 15581954810375490643U;
            //
            aOrbiterH = (((aOrbiterH + aOrbiterC) + 4487042505730624892U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordH;
            aOrbiterA = (((aOrbiterA ^ aOrbiterH) ^ 2774455928791636186U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 15847933919136777451U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 12435319582397755819U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 10077180055177766823U;
            aOrbiterC = RotL64((aOrbiterC * 3924363471701748703U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 10391963896910956455U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 6149237416725301794U;
            aOrbiterD = RotL64((aOrbiterD * 10115917698918612823U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 15673402771629639978U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 14729117178956592426U;
            aOrbiterE = RotL64((aOrbiterE * 9070464269215820531U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 14492001279368870240U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 6278248084483259952U;
            aOrbiterF = RotL64((aOrbiterF * 16731228350971263873U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 15727518866499740411U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 8652631010810965473U) ^ aOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9508484121620912715U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 13660890300188313775U) + aOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 14699253534935936300U;
            aOrbiterB = RotL64((aOrbiterB * 3978135617259934869U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 1621689916308271346U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 5651399428852950385U) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 12220143634120124133U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 9833573729127477238U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 11171647423058940388U) ^ aNonceWordC;
            aOrbiterJ = RotL64((aOrbiterJ * 9692915620701425697U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 10346908196429120039U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 11972183669378621435U;
            aOrbiterG = RotL64((aOrbiterG * 12364429258926549335U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 11063215816236490488U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 8506388683755208267U;
            aOrbiterK = RotL64((aOrbiterK * 11514304191652750181U), 57U);
            //
            aIngress = RotL64(aOrbiterG, 51U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 34U));
            aIngress = aIngress + RotL64(aOrbiterJ, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aCross, 54U) + RotL64(aOrbiterI, 23U)) + aOrbiterJ) + RotL64(aCarry, 11U)) + aNonceWordE);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterC, 48U)) + aOrbiterG);
            aWandererF = aWandererF + ((((RotL64(aScatter, 21U) + RotL64(aOrbiterB, 21U)) + aOrbiterJ) + RotL64(aCarry, 3U)) + aWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 39U)) + aOrbiterD) + aNonceWordN);
            aWandererA = aWandererA + (((RotL64(aCross, 12U) + aOrbiterG) + RotL64(aOrbiterA, 5U)) + aNonceWordL);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterA, 56U)) + aOrbiterH) + aNonceWordD);
            aWandererC = aWandererC + ((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 11U)) + aOrbiterE);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 13U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aCross, 37U) + RotL64(aOrbiterB, 41U)) + aOrbiterF) + aWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 39U) + aOrbiterB) + RotL64(aOrbiterG, 43U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterB, 29U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 56U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererG, 41U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 4
        // ingress from: aOperationLaneC, aOperationLaneA, aWorkLaneC
        // ingress directions: aOperationLaneC forward forced, aOperationLaneA forward forced, aWorkLaneC forward/backward random
        // cross from: aOperationLaneB, aExpandLaneC, aWorkLaneA
        // cross directions: aOperationLaneB backward forced, aExpandLaneC backward forced, aWorkLaneA backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 24882U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((aIndex + 30857U)) & S_BLOCK1], 10U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 24773U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26201U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 26486U)) & S_BLOCK1], 52U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 32355U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 29U) + RotL64(aCarry, 53U)) ^ (RotL64(aPrevious, 14U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 11U)) + 1042610313571524121U;
            aOrbiterK = (((aWandererF + RotL64(aIngress, 39U)) + RotL64(aCarry, 43U)) + 3505725321008825582U) + aOrbiterAssignSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aScatter, 41U)) + 12584654563843782991U;
            aOrbiterH = ((aWandererI + RotL64(aCross, 48U)) + 6645399144515770935U) + aOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 27U)) + 3608978423753715584U) + aNonceWordO;
            aOrbiterF = (aWandererH + RotL64(aCross, 19U)) + 8089198857670370983U;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 53U)) + RotL64(aCarry, 11U)) + 15207251813516399879U;
            aOrbiterC = (aWandererE + RotL64(aPrevious, 5U)) + 9579268660105824516U;
            aOrbiterE = ((aWandererA + RotL64(aCross, 43U)) + RotL64(aCarry, 39U)) + 16055044469473802812U;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 36U)) + 583811872609805949U) + aNonceWordP;
            aOrbiterG = (aWandererB + RotL64(aPrevious, 57U)) + 7027491967970873942U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 18256061823189677508U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 12708429127816136937U;
            aOrbiterD = RotL64((aOrbiterD * 12593886633108075321U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 12169216645156306078U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 12694325407567795065U;
            aOrbiterJ = RotL64((aOrbiterJ * 3711789483877261899U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 16109994660203297503U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 4234704064165718913U;
            aOrbiterI = RotL64((aOrbiterI * 730085881474787681U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 14119541943554602878U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 8777769004811352951U;
            aOrbiterE = RotL64((aOrbiterE * 2556957257736134223U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 15642663488392549609U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 11594468530833278624U) ^ aNonceWordC;
            aOrbiterC = RotL64((aOrbiterC * 6639306656361601143U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 7365350535791499871U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 5965170981970155956U;
            aOrbiterK = RotL64((aOrbiterK * 1898702752753066851U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 9115232101451815522U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 9433983580038990072U;
            aOrbiterB = RotL64((aOrbiterB * 1951249217843992179U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 8810565477444156140U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 12081286530401844859U;
            aOrbiterH = RotL64((aOrbiterH * 1991383259486140229U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 7498045374283306625U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 13095973566401200720U) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 2657451581036351987U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 18205793828042507364U) + aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 3339020890428651569U;
            aOrbiterG = RotL64((aOrbiterG * 10195916881103252701U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 16957913958369950483U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 1042610313571524121U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11206619213970727629U), 19U);
            //
            aIngress = RotL64(aOrbiterH, 37U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterJ, 46U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 42U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 41U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 38U) + aOrbiterG) + RotL64(aOrbiterA, 47U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 23U) + aOrbiterK) + RotL64(aOrbiterE, 21U));
            aWandererB = aWandererB + (((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterC, 43U)) + aNonceWordB);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterI, 6U)) + aNonceWordD);
            aWandererC = aWandererC + ((RotL64(aCross, 29U) + RotL64(aOrbiterB, 29U)) + aOrbiterJ);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 11U) + aOrbiterC) + RotL64(aOrbiterD, 23U));
            aWandererH = aWandererH + (((((RotL64(aScatter, 13U) + aOrbiterF) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 5U)) + aNonceWordL) + aWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 43U) + aOrbiterH) + RotL64(aOrbiterE, 27U));
            aWandererK = aWandererK + (((RotL64(aIngress, 21U) + aOrbiterD) + RotL64(aOrbiterE, 34U)) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 6U) + RotL64(aOrbiterJ, 57U)) + aOrbiterK) + aWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 46U));
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 6U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererF, 27U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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

void TwistExpander_VolleyBall_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xFAC1E067C593F283ULL + 0x929FB5321458C78FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xDD301FB098C092B3ULL + 0x8AE22981A244E319ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xB2F596251DB161F7ULL + 0xDDC0DCACA53AE7C8ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x9B5D3EB038EDEAB7ULL + 0x8B00BE2A310E92BBULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xEC4D92E59C019C0DULL + 0xEECD7B176C033219ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x8C31C8435B3A3707ULL + 0xA79271CF29424625ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xCA20FBD67EE3A23BULL + 0x93676D538D0ADCF4ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF80EC43C3229D761ULL + 0xA07A58EEC163110AULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x8CE416BCF28EDBB3ULL + 0xC560D51AF0C4C035ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xA3E56EF11DFBF5F9ULL + 0xD4EEA0F09D1D9B14ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xFFC569D6DDDA52A9ULL + 0x85DA0DBC67545275ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xE0BBE00A07668EBFULL + 0xE13F55190DDDE7F8ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xFD940569CA0579B9ULL + 0x97311ED1DAD355BBULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xB3C75E75D6C9751BULL + 0xBEEF13733E471ADFULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xD365351685E56201ULL + 0xDF6BD2F9F38E6BEEULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xB6D51DA061D9A5B5ULL + 0xE3EF294C7ACBCF8EULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneB, aOperationLaneC, aOperationLaneD, aWorkLaneD, aExpandLaneA, aWorkLaneC, aWorkLaneA, aExpandLaneB, aFireLaneC, aFireLaneD, aExpandLaneC, aWorkLaneB, aFireLaneA
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneB
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneB forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aWorkLaneD
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aWorkLaneD backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 743U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((aIndex + 1433U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 1348U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3406U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 2165U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 3290U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aPrevious, 51U)) ^ (RotL64(aCarry, 11U) ^ RotL64(aIngress, 36U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterI = (aWandererA + RotL64(aScatter, 58U)) + 17668251151213543491U;
            aOrbiterB = ((((aWandererF + RotL64(aPrevious, 47U)) + RotL64(aCarry, 57U)) + 16101602509895104517U) + aOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1]) + aNonceWordA;
            aOrbiterF = (aWandererB + RotL64(aCross, 19U)) + 9083915270773304935U;
            aOrbiterK = (aWandererH + RotL64(aIngress, 11U)) + 12810720730318214811U;
            aOrbiterC = ((aWandererK + RotL64(aCross, 29U)) + RotL64(aCarry, 35U)) + 18113428002071925621U;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 34U)) + RotL64(aCarry, 27U)) + 1582208899354109878U;
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 39U)) + 4180688104819188154U;
            aOrbiterD = (((aWandererI + RotL64(aIngress, 43U)) + 8954598189262820611U) + aOrbiterAssignSaltB[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordF;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 3U)) + 15360094153175355879U) + aNonceWordI;
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 8383954114668216260U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 15626783326234049197U;
            aOrbiterF = RotL64((aOrbiterF * 15058420415480073793U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 10609978564404958066U) + aNonceWordG;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 17656516608997517984U;
            aOrbiterC = RotL64((aOrbiterC * 4590620354119899777U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 760077259110786536U) + aOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 3597338735888033063U) ^ aNonceWordP;
            aOrbiterB = RotL64((aOrbiterB * 6548831472863517621U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 4431777844935985157U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 10710423172154671296U;
            aOrbiterD = RotL64((aOrbiterD * 16267496318491473315U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 10240882795242085185U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 7826053487019825891U) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 15053729937684375907U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 9418883403715727353U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 11507423614799075545U;
            aOrbiterE = RotL64((aOrbiterE * 16189463984557044693U), 23U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterC) + 11545217316421066655U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordE;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 617921402135485341U;
            aOrbiterI = RotL64((aOrbiterI * 8182920764965471653U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 14456933220749921009U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 7990243583564535387U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5994900368027985469U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 14023633125757654751U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 11319146808574958827U;
            aOrbiterG = RotL64((aOrbiterG * 13676159969338309307U), 19U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 57U);
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterA, 44U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterK, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterE, 51U)) + aOrbiterK);
            aWandererD = aWandererD + (((((RotL64(aIngress, 43U) + aOrbiterA) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 35U)) + aNonceWordJ) + aWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 53U) + aOrbiterD) + RotL64(aOrbiterC, 3U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 19U) + aOrbiterB) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 43U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 24U) + aOrbiterE) + RotL64(aOrbiterG, 10U)) + aWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 35U) + aOrbiterC) + RotL64(aOrbiterB, 27U)) + aNonceWordN);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 23U)) + aOrbiterF) + aNonceWordM);
            aWandererI = aWandererI + (((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterI, 57U)) + aNonceWordD);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterE, 34U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 10U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 2
        // ingress from: aExpandLaneA, aOperationLaneC, aWorkLaneC
        // ingress directions: aExpandLaneA forward forced, aOperationLaneC forward forced, aWorkLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneD, aWorkLaneA
        // cross directions: aOperationLaneA backward forced, aOperationLaneD backward forced, aWorkLaneA backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 8864U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneC[((aIndex + 10268U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 14444U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 9111U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 10016U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8975U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 22U) + RotL64(aCarry, 39U)) ^ (RotL64(aCross, 57U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterE = (aWandererK + RotL64(aPrevious, 48U)) + 1297415699043177788U;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 19U)) + 17583786534509260153U) + aNonceWordG;
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 3U)) + 643197858925708798U) + aNonceWordB;
            aOrbiterF = ((aWandererC + RotL64(aCross, 57U)) + RotL64(aCarry, 57U)) + 5062653766915694874U;
            aOrbiterA = (((aWandererH + RotL64(aIngress, 41U)) + RotL64(aCarry, 47U)) + 7034273638367180511U) + aNonceWordD;
            aOrbiterD = ((aWandererE + RotL64(aScatter, 53U)) + RotL64(aCarry, 19U)) + 2026909726972916996U;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 23U)) + 2785690475553211646U) + aNonceWordJ;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 29U)) + 2910341716302991892U) + aOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 12U)) + 2834181605200829791U) + aOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 13323052600571281928U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 10434901530315760460U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2042210188346767033U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 247903955625194782U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 5196515747387257163U;
            aOrbiterD = RotL64((aOrbiterD * 1799024689023272275U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 7196305682377987476U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 14777739876892587484U;
            aOrbiterK = RotL64((aOrbiterK * 95220583948241581U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 10609060796540136671U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 8386027207212484155U;
            aOrbiterF = RotL64((aOrbiterF * 4855610536246556893U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 729659744301903424U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 2350564261412606157U;
            aOrbiterB = RotL64((aOrbiterB * 16713856782349084977U), 51U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterC) + 16611987556673864177U) + aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1]) + aNonceWordF;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 1525195188708550503U;
            aOrbiterE = RotL64((aOrbiterE * 10045858602151004553U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 4654808490980989596U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 8189569777087686263U;
            aOrbiterJ = RotL64((aOrbiterJ * 17278657566389299577U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 10932857495004451792U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 1833880112534916813U;
            aOrbiterA = RotL64((aOrbiterA * 8004341577533825681U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 13100236350175516423U) + aNonceWordI;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 2773759534195186313U;
            aOrbiterC = RotL64((aOrbiterC * 3194954066097323161U), 29U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterC, 23U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 34U));
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterD, 23U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 35U) + aOrbiterA) + RotL64(aOrbiterF, 46U)) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterB, 13U)) + aNonceWordA);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 18U) + RotL64(aOrbiterJ, 57U)) + aOrbiterA) + RotL64(aCarry, 23U)) + aWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterE, 3U)) + aOrbiterA);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterJ, 18U)) + aOrbiterK) + aNonceWordP) + aWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 41U)) + aOrbiterF);
            aWandererD = aWandererD + ((RotL64(aScatter, 22U) + aOrbiterF) + RotL64(aOrbiterC, 51U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 27U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 50U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + RotL64(aWandererK, 19U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 3
        // ingress from: aExpandLaneB, aOperationLaneD, aFireLaneC
        // ingress directions: aExpandLaneB forward forced, aOperationLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneA, aOperationLaneB, aFireLaneD
        // cross directions: aExpandLaneA backward forced, aOperationLaneB backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 21114U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneD[((aIndex + 24525U)) & S_BLOCK1], 26U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 21161U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23026U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 16532U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 16559U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCarry, 22U)) ^ (RotL64(aCross, 3U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterA = (aWandererC + RotL64(aCross, 29U)) + 13442819395490639310U;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 37U)) + 8187292523194120936U;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 57U)) + 11469697159823131388U) + aNonceWordJ;
            aOrbiterC = (((aWandererF + RotL64(aScatter, 42U)) + RotL64(aCarry, 3U)) + 13414083692375929653U) + aNonceWordE;
            aOrbiterD = (((aWandererG + RotL64(aCross, 47U)) + RotL64(aCarry, 13U)) + 11404010733687907517U) + aOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aScatter, 51U)) + 6783212827186218247U;
            aOrbiterK = (aWandererD + RotL64(aPrevious, 23U)) + 8561131439340372614U;
            aOrbiterB = (((aWandererJ + RotL64(aIngress, 12U)) + RotL64(aCarry, 27U)) + 6252609642004429113U) + aOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = (aWandererE + RotL64(aScatter, 19U)) + 12804867444200448952U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 2739648749603690781U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 14808861217017399752U;
            aOrbiterG = RotL64((aOrbiterG * 373911885694012101U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 17588866502571268888U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 5882260142735642980U;
            aOrbiterI = RotL64((aOrbiterI * 7688252946143263869U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 15493099088132862949U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 5175647411532429582U;
            aOrbiterK = RotL64((aOrbiterK * 15226544495598541883U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 14279707376173642767U) + aOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 6826363572161275158U;
            aOrbiterJ = RotL64((aOrbiterJ * 5263708315440161809U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 13267185753040999992U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 9980987858092888720U) ^ aNonceWordN;
            aOrbiterC = RotL64((aOrbiterC * 13210290848800728635U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 3582972937645514549U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 10140409019562890804U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 6944490201647678479U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 6160444117287330557U) + aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 16344602960561293113U;
            aOrbiterF = RotL64((aOrbiterF * 2319964919335633293U), 51U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterK) + 3497141036108337171U) + aOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1]) + aNonceWordC;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 91269118352540308U;
            aOrbiterD = RotL64((aOrbiterD * 5160060720189045505U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 12739932748793144857U) + aNonceWordP;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 12820180915064791197U;
            aOrbiterB = RotL64((aOrbiterB * 5843849637411948699U), 47U);
            //
            aIngress = RotL64(aOrbiterJ, 37U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 26U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + RotL64(aOrbiterB, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aScatter, 48U) + RotL64(aOrbiterA, 52U)) + aOrbiterF) + aWandererUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 35U) + aOrbiterB) + RotL64(aOrbiterI, 13U)) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterK, 39U)) + aOrbiterA) + aNonceWordL);
            aWandererE = aWandererE + (((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 29U)) + aOrbiterA) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterA, 35U)) + aOrbiterG) + aNonceWordA);
            aWandererI = aWandererI + ((RotL64(aPrevious, 13U) + aOrbiterG) + RotL64(aOrbiterJ, 4U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterD, 21U)) + aOrbiterC);
            aWandererD = aWandererD + (((RotL64(aCross, 57U) + aOrbiterA) + RotL64(aOrbiterD, 47U)) + aNonceWordH);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 42U) + RotL64(aOrbiterC, 43U)) + aOrbiterI) + aWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + (RotL64(aWandererE, 58U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 35U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aWorkLaneB
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aWorkLaneB forward/backward random
        // cross from: aExpandLaneB, aOperationLaneC, aFireLaneA
        // cross directions: aExpandLaneB backward forced, aOperationLaneC backward forced, aFireLaneA backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 25908U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((aIndex + 27822U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27663U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27640U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 30251U)) & S_BLOCK1], 4U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 31811U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 13U) + RotL64(aPrevious, 56U)) ^ (RotL64(aCross, 41U) + RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterG = ((aWandererI + RotL64(aIngress, 13U)) + 8020711767807230555U) + aNonceWordP;
            aOrbiterE = ((aWandererK + RotL64(aScatter, 57U)) + RotL64(aCarry, 3U)) + 15368693777246341570U;
            aOrbiterH = (aWandererJ + RotL64(aCross, 34U)) + 5117523734225562401U;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 43U)) + RotL64(aCarry, 21U)) + 13155269151097507808U;
            aOrbiterI = (((aWandererD + RotL64(aCross, 3U)) + 9879303753623578272U) + aOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordK;
            aOrbiterA = (aWandererG + RotL64(aScatter, 39U)) + 1165799257173794826U;
            aOrbiterC = ((aWandererC + RotL64(aIngress, 27U)) + 930641942062732091U) + aNonceWordF;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 51U)) + 11330571332221123153U;
            aOrbiterF = (((aWandererF + RotL64(aCross, 22U)) + RotL64(aCarry, 57U)) + 2862963158282518899U) + aOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 6019186399361476659U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 1924419843785161958U;
            aOrbiterH = RotL64((aOrbiterH * 9485557122500346869U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 12618629043591380461U) + aNonceWordL;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 9334176504266512405U) ^ aNonceWordG;
            aOrbiterI = RotL64((aOrbiterI * 18239109235362925739U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 16829692481030013551U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 5604784396927022709U;
            aOrbiterG = RotL64((aOrbiterG * 2833893610883508353U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 16124030106598549644U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 16571659812830230677U;
            aOrbiterC = RotL64((aOrbiterC * 4668250364992383549U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 15171089673591843703U) + aNonceWordJ;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 2826755560293849328U;
            aOrbiterD = RotL64((aOrbiterD * 9397017963457655287U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 9976785768283589291U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 11845100564714691809U;
            aOrbiterF = RotL64((aOrbiterF * 4935139932585319251U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 7318560453127859950U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 3039196878830506712U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3140508261330698717U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 8850992055588337843U) + aOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 4219373528176869146U;
            aOrbiterE = RotL64((aOrbiterE * 1310964742529956743U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 1341474458715938799U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 15937557372891732898U;
            aOrbiterJ = RotL64((aOrbiterJ * 11437307017920192915U), 35U);
            //
            aIngress = RotL64(aOrbiterF, 27U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterJ, 24U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterH, 43U)) + aOrbiterE) + aNonceWordM);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 6U) + aOrbiterC) + RotL64(aOrbiterE, 18U)) + RotL64(aCarry, 3U)) + aNonceWordC);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 37U) + aOrbiterD) + RotL64(aOrbiterJ, 29U));
            aWandererD = aWandererD + (((RotL64(aScatter, 47U) + aOrbiterC) + RotL64(aOrbiterG, 57U)) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 23U)) + aOrbiterI) + aNonceWordI);
            aWandererB = aWandererB + (((RotL64(aIngress, 23U) + aOrbiterI) + RotL64(aOrbiterE, 12U)) + aWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 60U) + aOrbiterD) + RotL64(aOrbiterI, 39U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 19U) + RotL64(aOrbiterJ, 35U)) + aOrbiterF) + aNonceWordO);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 11U) + aOrbiterE) + RotL64(aOrbiterD, 51U)) + aWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 44U));
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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

void TwistExpander_VolleyBall_Arx::KDF_B_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xB96BE6223447E21BULL + 0x8D78D49016B2A0F3ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x8F6599CEF07591D9ULL + 0xD7A4B5D43CFACD46ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xB794A8716D1A9963ULL + 0xEF7E9ACE1B6F418EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xABA099DD6FEE0DA3ULL + 0xABB3052C569C7D72ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xD7598F31D564BF45ULL + 0xBA4A16DB5D0AE63EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xBCA23D2730F83315ULL + 0x9A2CCA34B780EE94ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x9999FDB972698C57ULL + 0xF2C7B0D22D9CF1FAULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xFB329C7FBFD1BDEBULL + 0x96004D1687E42F41ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x82F7F4B825416B05ULL + 0x9700371568426959ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x9B53968B2209476DULL + 0xFF68677F7E21CE8DULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xABE1CE9FFAC458D5ULL + 0xC71806DEE820AD24ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xDB0627CA161CF50DULL + 0x830BA9E8AB875ABDULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xD8076FA4C6FBCED9ULL + 0xBCAB82CB447FAC0AULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x8888852D07B93C59ULL + 0xDBB58C9618A9689AULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xAD7393288B033109ULL + 0xEF4014DD2440341AULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x984556AEB915BF79ULL + 0xFAF1636C5A732ECEULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aOperationLaneD, aWorkLaneC, aWorkLaneD, aFireLaneD, aExpandLaneA, aFireLaneB, aFireLaneC, aExpandLaneB, aFireLaneA, aOperationLaneA, aExpandLaneC, aOperationLaneB, aOperationLaneC
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_d loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aOperationLaneD
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aOperationLaneD forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aFireLaneD
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 6029U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((aIndex + 7746U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 1379U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 3343U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8166U)) & S_BLOCK1], 14U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 2657U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 10U) ^ RotL64(aIngress, 29U)) ^ (RotL64(aPrevious, 41U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterA = ((aWandererB + RotL64(aIngress, 13U)) + RotL64(aCarry, 3U)) + 6381335981879993247U;
            aOrbiterG = (aWandererE + RotL64(aPrevious, 4U)) + 15595429101600023172U;
            aOrbiterK = ((aWandererF + RotL64(aCross, 41U)) + 5449234297249826461U) + aNonceWordA;
            aOrbiterD = (aWandererG + RotL64(aScatter, 57U)) + 11213734849329731168U;
            aOrbiterB = ((aWandererH + RotL64(aCross, 27U)) + RotL64(aCarry, 41U)) + 16438473952464514248U;
            aOrbiterH = ((((aWandererA + RotL64(aScatter, 47U)) + RotL64(aCarry, 53U)) + 7357872882115186976U) + aOrbiterAssignSaltA[((aIndex + 24U)) & S_SALT1]) + aNonceWordD;
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 19U)) + 394402075160738643U) + aOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 11112941985410283532U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 14955125011182736212U) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 10711684773326395603U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 14770727009821304070U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 11286366598129204910U) ^ aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15884310771003021989U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 7358400908565425780U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 15635109923749114761U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12415152149408700329U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 13826842523738623579U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 1072811298828325231U;
            aOrbiterJ = RotL64((aOrbiterJ * 9662800288646215083U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 4017334196009350776U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 8812213572751410831U) ^ aNonceWordF;
            aOrbiterH = RotL64((aOrbiterH * 12744171921566782795U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 6723457786170634403U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 9785583533999417673U;
            aOrbiterA = RotL64((aOrbiterA * 7776915427605471097U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 10265132640322153964U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 8435670887514808087U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2706263045620662131U), 27U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterK, 5U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 60U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 11U)) + aOrbiterG) + RotL64(aCarry, 53U)) + aNonceWordP);
            aWandererG = aWandererG ^ (((RotL64(aCross, 37U) + aOrbiterB) + RotL64(aOrbiterD, 37U)) + aWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterH, 30U)) + aNonceWordC);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterB, 19U)) + aOrbiterA);
            aWandererE = aWandererE + (((RotL64(aIngress, 21U) + aOrbiterD) + RotL64(aOrbiterK, 53U)) + aNonceWordI);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 47U)) + aOrbiterJ) + aWandererUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 46U) + aOrbiterB) + RotL64(aOrbiterG, 5U)) + RotL64(aCarry, 37U)) + aNonceWordB);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (RotL64(aWandererH, 34U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 39U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aFireLaneB
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aFireLaneB forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aFireLaneC
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aFireLaneC backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 10091U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneC[((aIndex + 11448U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 13029U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12238U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8893U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 14586U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 54U)) ^ (RotL64(aCross, 41U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterK = (((aWandererJ + RotL64(aScatter, 57U)) + RotL64(aCarry, 53U)) + 4751694786009671052U) + aOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aCross, 12U)) + 16362725160370844224U;
            aOrbiterJ = (((aWandererE + RotL64(aPrevious, 37U)) + RotL64(aCarry, 5U)) + 6360885380915941057U) + aNonceWordG;
            aOrbiterG = (((aWandererF + RotL64(aIngress, 27U)) + RotL64(aCarry, 37U)) + 5154536007972297036U) + aOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = (aWandererD + RotL64(aScatter, 5U)) + 9362540581874808253U;
            aOrbiterE = (aWandererG + RotL64(aIngress, 43U)) + 13902493871525612934U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 19U)) + 10208452885367546542U) + aNonceWordN;
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 3117030377279160998U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 17286247690414027870U;
            aOrbiterJ = RotL64((aOrbiterJ * 4896931759653832095U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 3930314320040949141U) + aNonceWordJ;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 7289525252391668404U) ^ aNonceWordO;
            aOrbiterC = RotL64((aOrbiterC * 15452162299105112187U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 3434167955466809185U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 17852573095128575663U;
            aOrbiterF = RotL64((aOrbiterF * 1485660158767033425U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 6137259687928853253U) + aOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 13992510605237574698U;
            aOrbiterK = RotL64((aOrbiterK * 15346263295995333395U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 6470556523400123474U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 4333255670390099293U) ^ aOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11089933812030082647U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 7700424876430257995U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 16920736951239453071U) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 8920407493132380497U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 1635071690430295730U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 9966700845966398620U;
            aOrbiterG = RotL64((aOrbiterG * 17210048121896546867U), 29U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 51U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 27U));
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterJ, 11U)) + aOrbiterI) + RotL64(aCarry, 57U)) + aWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 21U)) + aOrbiterG);
            aWandererI = aWandererI + (((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterG, 57U)) + aWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterJ, 43U)) + aNonceWordI);
            aWandererF = aWandererF + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterF, 37U)) + aOrbiterC) + aNonceWordF);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 26U) + RotL64(aOrbiterK, 4U)) + aOrbiterE);
            aWandererK = aWandererK + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 51U)) + aOrbiterI) + RotL64(aCarry, 21U)) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 26U));
            aCarry = aCarry + RotL64(aWandererK, 21U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aFireLaneA
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aOperationLaneA
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aOperationLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 17784U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneD[((aIndex + 22508U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 22809U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 19586U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20128U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aOperationLaneA[((aIndex + 23289U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCarry, 18U)) ^ (RotL64(aPrevious, 51U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterF = (aWandererI + RotL64(aCross, 51U)) + 2783898056762489197U;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 21U)) + 7177192902873343053U) + aNonceWordB;
            aOrbiterE = (((aWandererD + RotL64(aIngress, 37U)) + RotL64(aCarry, 41U)) + 12254703232691980774U) + aOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 28U)) + RotL64(aCarry, 11U)) + 15446547245691219559U;
            aOrbiterK = ((aWandererC + RotL64(aIngress, 11U)) + 888475203006174856U) + aNonceWordJ;
            aOrbiterD = ((aWandererE + RotL64(aScatter, 5U)) + RotL64(aCarry, 53U)) + 3649183529366307877U;
            aOrbiterC = (((aWandererA + RotL64(aCross, 43U)) + 4642631047518805167U) + aOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1]) + aNonceWordO;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 6108329730724782250U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 8334054653023816636U) ^ aOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9352516059501924393U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 5891895375031474350U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 3176720746238477862U;
            aOrbiterD = RotL64((aOrbiterD * 1869961473768307911U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 6111038696865301675U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 11914998302228682704U) ^ aNonceWordK;
            aOrbiterC = RotL64((aOrbiterC * 11738924766359642853U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 17005063057791320948U) + aNonceWordH;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 18333780598768130670U) ^ aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5416759844884107303U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 2056115016443263153U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 10245512728872962677U;
            aOrbiterH = RotL64((aOrbiterH * 707106795383284903U), 41U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterC) + 4810366069422162351U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordE;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 3051442983125942469U) ^ aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13558537578054436423U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 9285068547223654308U) + aNonceWordI;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 13067251130180968842U;
            aOrbiterF = RotL64((aOrbiterF * 7000687697769766605U), 47U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterK, 37U);
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 26U));
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aCross, 37U) + aOrbiterK) + RotL64(aOrbiterC, 29U)) + aWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 43U) + aOrbiterH) + RotL64(aOrbiterF, 35U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 30U) + RotL64(aOrbiterH, 5U)) + aOrbiterJ) + aNonceWordL);
            aWandererH = aWandererH + (((RotL64(aIngress, 51U) + RotL64(aOrbiterE, 13U)) + aOrbiterC) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterH, 42U)) + aOrbiterD) + aNonceWordG);
            aWandererA = aWandererA + (((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 53U)) + aOrbiterD) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 21U) + aOrbiterJ) + RotL64(aOrbiterC, 23U)) + aNonceWordF) + aWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 18U));
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aOperationLaneB
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aOperationLaneB forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aOperationLaneC
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 31597U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((aIndex + 29019U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26228U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26971U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 26995U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 29604U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aIngress, 50U)) + (RotL64(aPrevious, 5U) + RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 11U)) + 8101351470141807662U) + aNonceWordL;
            aOrbiterA = (((aWandererF + RotL64(aCross, 41U)) + RotL64(aCarry, 51U)) + 6965474099521076705U) + aOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = (((aWandererA + RotL64(aIngress, 3U)) + RotL64(aCarry, 13U)) + 6803828268885684784U) + aOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = (((aWandererE + RotL64(aScatter, 29U)) + RotL64(aCarry, 37U)) + 13454235922950972488U) + aNonceWordO;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 54U)) + 11678091885751244777U;
            aOrbiterF = (aWandererK + RotL64(aCross, 47U)) + 5307134544628507141U;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 35U)) + 4873703518950429353U) + aNonceWordB;
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 8542156221858586039U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 3993726182905296513U) ^ aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11331376012938127609U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 12113047622035464386U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 1944244448665721151U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7010050836758762003U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 12914188029425467576U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 2486762763475327024U) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 12319769994433811617U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 14580191602982245481U) + aNonceWordJ;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 12093414832400135066U) ^ aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12720286833215690663U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 13623906997320021065U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 9977356009806428696U) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 2005536391712733499U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 3694954095397810851U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 11453812627797091638U) ^ aOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13730420725113907161U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 542311345544726351U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 3024285045990499484U) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 5153745952148205645U), 13U);
            //
            aIngress = RotL64(aOrbiterC, 23U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 50U));
            aIngress = aIngress + (RotL64(aOrbiterH, 39U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterE, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 13U)) + aNonceWordH) + aWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 10U) + RotL64(aOrbiterF, 11U)) + aOrbiterK);
            aWandererF = aWandererF + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterC, 41U)) + aOrbiterE) + aNonceWordN);
            aWandererK = aWandererK ^ (((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterE, 18U)) + aWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterH, 3U)) + aOrbiterC) + aNonceWordD);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 51U)) + aOrbiterB);
            aWandererE = aWandererE + (((RotL64(aCross, 47U) + RotL64(aOrbiterB, 35U)) + aOrbiterC) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 10U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 3U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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

void TwistExpander_VolleyBall_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA;
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
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE;
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
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF;
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
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltD;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x84A66B6F1EB69BB5ULL + 0xA733287B39F8F5EAULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xCEA648812DAD17F3ULL + 0xD0D2C3C26A932246ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xE3E8C228EE457F81ULL + 0x91F5141E3D6F4C09ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xA2A321B5599588DFULL + 0x84E05C4F60C8DCD1ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x9FA98B11018AE0E1ULL + 0xDFCF0CEF7F19C79BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xF230D29B2E0DC68FULL + 0xC8649DD0283066F3ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x8C8020749ECAFA0DULL + 0xB9D3089977B1EF6EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xCBC3A777BB613CA9ULL + 0x98FA3E785C2CB5A4ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xF4EDACAC7F5D140FULL + 0xF5A0E607AC52698BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xA1A3AEE885E33697ULL + 0xE532ADB7E69C0DD7ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x8E4EDA20200957E7ULL + 0xF57C1DC10D040B76ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xB09F2DB5AB2DB75DULL + 0xD595AD56D6D2FBBEULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xA0263E7B5EF8DEE1ULL + 0xC8D17F4CE3542DE9ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xC6B3CCA05AD39E43ULL + 0xCC32AB9CA37CEC7EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xC0282DE0BAA3CBB1ULL + 0xFADADC56049120E5ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xC78858A2DA44D777ULL + 0xAF9191ADB5CB327EULL);
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 887U)) & W_KEY1], 43U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 1357U)) & W_KEY1], 51U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 754U)) & W_KEY1], 6U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 1911U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 29U) ^ RotL64(aCross, 41U)) + (RotL64(aCarry, 14U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterD = (((aWandererB + RotL64(aIngress, 3U)) + RotL64(aCarry, 57U)) + 1142447269198373880U) + aNonceWordM;
            aOrbiterK = ((aWandererI + RotL64(aCross, 23U)) + 10581460640040336191U) + aPhaseEOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 10U)) + RotL64(aCarry, 27U)) + 14703062773878202900U;
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 51U)) + 15737525756286914746U) + aNonceWordD;
            aOrbiterG = (aWandererH + RotL64(aPrevious, 41U)) + 16178774478273186999U;
            aOrbiterE = ((aWandererD + RotL64(aCross, 57U)) + 2514897053906809160U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = (((aWandererF + RotL64(aScatter, 29U)) + RotL64(aCarry, 13U)) + 13702496607592508464U) + aNonceWordE;
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 18030885275418337965U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 5241783876161655984U;
            aOrbiterA = RotL64((aOrbiterA * 10970981186787227937U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 2807052676283587925U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 8022804576763271327U) ^ aNonceWordN;
            aOrbiterG = RotL64((aOrbiterG * 11727096043219370577U), 43U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterE) + 15597099852232205860U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1]) + aNonceWordP;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 1538435607932096400U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7900752511710516981U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 11147868774413615365U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 9325213746830411568U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 561819005818948769U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 13792300423550555634U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 3134856508983945719U) ^ aNonceWordJ;
            aOrbiterE = RotL64((aOrbiterE * 4271845067763664863U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 8654966018053784882U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 8937113935476779267U) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 7386875687217705855U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 4135676350355234788U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 11407912615743682678U;
            aOrbiterD = RotL64((aOrbiterD * 2773506587480714695U), 57U);
            //
            aIngress = RotL64(aOrbiterA, 43U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + RotL64(aOrbiterD, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 41U)) + aOrbiterJ) + aNonceWordG);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 51U) + aOrbiterA) + RotL64(aOrbiterB, 27U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 30U) + aOrbiterD) + RotL64(aOrbiterJ, 19U)) + aNonceWordL);
            aWandererE = aWandererE ^ (((RotL64(aCross, 57U) + aOrbiterB) + RotL64(aOrbiterK, 57U)) + aPhaseEWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 37U) + aOrbiterE) + RotL64(aOrbiterG, 50U)) + RotL64(aCarry, 37U)) + aNonceWordC);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterE, 13U)) + aOrbiterA);
            aWandererI = aWandererI + ((((RotL64(aCross, 19U) + RotL64(aOrbiterK, 35U)) + aOrbiterD) + RotL64(aCarry, 13U)) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererF, 4U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + RotL64(aWandererI, 53U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 4298U)) & S_BLOCK1], 53U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 5300U)) & W_KEY1], 27U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 4469U)) & W_KEY1], 56U) ^ RotL64(mSource[((aIndex + 3287U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 52U) ^ RotL64(aCross, 3U)) ^ (RotL64(aCarry, 39U) + RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 29U)) + 3448371607470865612U) + aNonceWordH;
            aOrbiterG = ((((aWandererF + RotL64(aCross, 20U)) + RotL64(aCarry, 27U)) + 3743742913651580573U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordL;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 35U)) + 13069491287948807280U) + aNonceWordF;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 51U)) + 16872779275586545632U) + aNonceWordP;
            aOrbiterF = (aWandererD + RotL64(aScatter, 43U)) + 17945792656755062795U;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 11U)) + RotL64(aCarry, 57U)) + 18199747196793731853U;
            aOrbiterI = (((aWandererE + RotL64(aIngress, 5U)) + RotL64(aCarry, 13U)) + 15953311878379809513U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 941268763494588338U) + aNonceWordM;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 10090221530365796809U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14035236086292997613U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 8335698093307607001U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 6147498804734306100U;
            aOrbiterG = RotL64((aOrbiterG * 6904444049941211327U), 13U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterH) + 5980246079567570090U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1]) + aNonceWordC;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 4152167624425912978U;
            aOrbiterI = RotL64((aOrbiterI * 10019421651535123573U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 14990418790239735916U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 3418668387496597219U) ^ aNonceWordJ;
            aOrbiterF = RotL64((aOrbiterF * 12814077238529863119U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 4206650904177199425U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 3905470780938996069U) ^ aNonceWordK;
            aOrbiterE = RotL64((aOrbiterE * 16030122739273137005U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 9968672788233080924U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 602258075661864866U;
            aOrbiterC = RotL64((aOrbiterC * 2615726693066300065U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 17751667243048041383U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 2414054413585296027U;
            aOrbiterH = RotL64((aOrbiterH * 1049512574773201893U), 35U);
            //
            aIngress = RotL64(aOrbiterC, 3U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + RotL64(aOrbiterE, 28U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 57U) + RotL64(aOrbiterG, 35U)) + aOrbiterI) + aNonceWordE);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterG, 53U)) + aOrbiterE);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterH, 27U)) + aOrbiterC) + RotL64(aCarry, 47U)) + aNonceWordD);
            aWandererI = aWandererI ^ ((RotL64(aCross, 48U) + aOrbiterF) + RotL64(aOrbiterH, 41U));
            aWandererH = aWandererH + ((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterB, 11U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 21U) + aOrbiterI) + RotL64(aOrbiterE, 3U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 20U)) + aOrbiterF) + RotL64(aCarry, 23U)) + aPhaseEWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 28U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + RotL64(aWandererG, 11U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 5980U)) & S_BLOCK1], 35U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 6331U)) & W_KEY1], 18U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 6942U)) & W_KEY1], 51U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 7338U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 7525U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 6U) ^ RotL64(aCarry, 53U)) + (RotL64(aCross, 27U) ^ RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 21U)) + 479672811032092393U;
            aOrbiterH = ((((aWandererG + RotL64(aIngress, 35U)) + RotL64(aCarry, 19U)) + 18061121631394564425U) + aPhaseEOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1]) + aNonceWordN;
            aOrbiterC = ((aWandererH + RotL64(aCross, 27U)) + 14237400452740566065U) + aNonceWordH;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 53U)) + RotL64(aCarry, 3U)) + 6723123812257706134U;
            aOrbiterK = ((((aWandererB + RotL64(aPrevious, 3U)) + RotL64(aCarry, 35U)) + 4247997188026499248U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordP;
            aOrbiterJ = (aWandererC + RotL64(aScatter, 11U)) + 1939107415066134869U;
            aOrbiterF = (aWandererF + RotL64(aCross, 42U)) + 3912640123546395979U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 8295478436553964298U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterG) ^ 3218960600711526885U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterC = RotL64((aOrbiterC * 15443507655470278069U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 5874096203353388890U) + aNonceWordO;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 10294536533673023358U;
            aOrbiterH = RotL64((aOrbiterH * 15561710414949058923U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 11268561953904130747U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 16693201256788898423U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16291987237693567209U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 7550969634681894654U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 9501647424602245869U) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 11265865222096866605U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 8881869255994319423U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 16770136406906800016U) ^ aNonceWordL;
            aOrbiterF = RotL64((aOrbiterF * 1782039587385512923U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 16185384746435761363U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 13841034186650721627U;
            aOrbiterG = RotL64((aOrbiterG * 12000155593277035447U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 15229062695864608309U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 3576122704615303733U;
            aOrbiterK = RotL64((aOrbiterK * 2433987493885779279U), 53U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 37U);
            aIngress = aIngress + (RotL64(aOrbiterB, 11U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterF, 60U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterC, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 53U) + aOrbiterG) + RotL64(aOrbiterF, 37U));
            aWandererC = aWandererC + (((RotL64(aCross, 5U) + aOrbiterF) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 60U)) + aOrbiterJ) + aNonceWordB) + aPhaseEWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 46U) + aOrbiterK) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterJ, 53U)) + aNonceWordA);
            aWandererH = aWandererH + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterJ, 47U)) + aOrbiterK);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterK, 21U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 58U));
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 10256U)) & S_BLOCK1], 28U) ^ RotL64(aKeyRowReadB[((aIndex + 9293U)) & W_KEY1], 19U));
            aIngress ^= (RotL64(mSource[((aIndex + 9959U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 9334U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 9599U)) & W_KEY1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 9474U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 38U) ^ RotL64(aCross, 3U)) + (RotL64(aCarry, 51U) + RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterC = ((aWandererF + RotL64(aCross, 27U)) + RotL64(aCarry, 51U)) + 5171470532667965920U;
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 47U)) + 750549462358682403U) + aNonceWordG;
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 21U)) + 3325689257577120525U) + aNonceWordF;
            aOrbiterA = ((((aWandererA + RotL64(aIngress, 53U)) + RotL64(aCarry, 3U)) + 18031575461559790826U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordP;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 11U)) + RotL64(aCarry, 37U)) + 13874739537012288677U;
            aOrbiterF = ((aWandererE + RotL64(aCross, 37U)) + 4250029868785016865U) + aNonceWordO;
            aOrbiterE = ((aWandererI + RotL64(aScatter, 4U)) + 8211158803112611161U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 1083939790236786027U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 3446525462376962464U) ^ aNonceWordA;
            aOrbiterJ = RotL64((aOrbiterJ * 13603702473750888213U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 6973817815000417325U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 15230876489676945543U;
            aOrbiterA = RotL64((aOrbiterA * 7737039082964537651U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 9359727659738755880U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 8775170107816327654U;
            aOrbiterE = RotL64((aOrbiterE * 6910680458261008653U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 11958941755525038545U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 16966819714283167348U) ^ aNonceWordJ;
            aOrbiterB = RotL64((aOrbiterB * 16363457661846050749U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 14556087985619763243U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 17915047508377045221U) ^ aNonceWordN;
            aOrbiterC = RotL64((aOrbiterC * 6727635453185130109U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 8578745677485367222U) + aNonceWordL;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 7002181668717618866U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12329703532414955235U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 3569939503066735457U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 2956247934282522184U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9946650822131152531U), 13U);
            //
            aIngress = RotL64(aOrbiterF, 35U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aCross, 29U) + RotL64(aOrbiterF, 47U)) + aOrbiterC);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterB, 41U)) + aNonceWordC);
            aWandererI = aWandererI + (((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterH, 6U)) + aPhaseFWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 56U) + RotL64(aOrbiterF, 19U)) + aOrbiterA) + aNonceWordD);
            aWandererF = aWandererF + ((((RotL64(aScatter, 41U) + aOrbiterC) + RotL64(aOrbiterJ, 27U)) + RotL64(aCarry, 57U)) + aNonceWordH);
            aWandererH = aWandererH ^ ((RotL64(aCross, 11U) + aOrbiterB) + RotL64(aOrbiterF, 57U));
            aWandererC = aWandererC + (((((RotL64(aIngress, 21U) + RotL64(aOrbiterB, 35U)) + aOrbiterA) + RotL64(aCarry, 13U)) + aNonceWordB) + aPhaseFWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 44U));
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 57U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 11599U)) & S_BLOCK1], 35U) ^ RotL64(aKeyRowReadA[((aIndex + 13555U)) & W_KEY1], 11U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 13622U)) & W_KEY1], 43U) ^ RotL64(mSource[((aIndex + 12252U)) & S_BLOCK1], 54U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 12876U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13461U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 10956U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 56U) + RotL64(aCross, 5U)) ^ (RotL64(aCarry, 19U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterF = (aWandererJ + RotL64(aIngress, 51U)) + 12122689833405846292U;
            aOrbiterA = ((aWandererE + RotL64(aCross, 19U)) + 9640400270962766788U) + aNonceWordH;
            aOrbiterG = (((aWandererA + RotL64(aScatter, 29U)) + RotL64(aCarry, 13U)) + 9141937998266739071U) + aNonceWordO;
            aOrbiterE = (aWandererK + RotL64(aPrevious, 3U)) + 12899395770434090537U;
            aOrbiterB = (((aWandererC + RotL64(aIngress, 57U)) + RotL64(aCarry, 53U)) + 13457918115408031842U) + aPhaseFOrbiterAssignSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = (((aWandererD + RotL64(aScatter, 13U)) + 15134784483576000943U) + aPhaseFOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterD = ((aWandererG + RotL64(aCross, 36U)) + RotL64(aCarry, 27U)) + 12540961268790055438U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 6306886773092764230U) + aNonceWordF;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 13573343491337243121U) ^ aNonceWordB;
            aOrbiterG = RotL64((aOrbiterG * 15893457012357368707U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 8545588657348974413U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 10891410570357275120U;
            aOrbiterB = RotL64((aOrbiterB * 5399310978367842841U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 2877137119767060151U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 9178097682386595144U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3524486002084427513U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 15528007881855616978U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 11368419529245281435U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12433207037378339309U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 5932738914934356645U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 5551842263864055419U;
            aOrbiterF = RotL64((aOrbiterF * 16093776759971522681U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 3824433359595690603U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 17184628855571662441U;
            aOrbiterD = RotL64((aOrbiterD * 691208053136187317U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 8724462245014132623U) + aNonceWordE;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 7481349499528092352U;
            aOrbiterA = RotL64((aOrbiterA * 8212182934509617583U), 47U);
            //
            aIngress = RotL64(aOrbiterJ, 57U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + RotL64(aOrbiterF, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 5U) + RotL64(aOrbiterD, 29U)) + aOrbiterB) + RotL64(aCarry, 41U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterE, 21U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 13U) + aOrbiterE) + RotL64(aOrbiterA, 60U)) + aNonceWordN);
            aWandererC = aWandererC ^ (((RotL64(aCross, 27U) + aOrbiterA) + RotL64(aOrbiterF, 5U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 19U) + RotL64(aOrbiterJ, 41U)) + aOrbiterF);
            aWandererE = aWandererE ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterB, 47U)) + aOrbiterA) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 52U) + aOrbiterF) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 53U)) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 36U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + RotL64(aWandererK, 21U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 15133U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneC[((aIndex + 13850U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 16065U)) & W_KEY1], 13U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 16275U)) & W_KEY1], 58U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 14203U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 15042U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14287U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 27U)) + (RotL64(aIngress, 53U) + RotL64(aCross, 10U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterF = (aWandererA + RotL64(aIngress, 43U)) + 13924571355038625040U;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 14U)) + 16328300979357156658U) + aNonceWordC;
            aOrbiterA = (aWandererF + RotL64(aScatter, 35U)) + 3947771961206012461U;
            aOrbiterK = (((aWandererJ + RotL64(aCross, 51U)) + 15428284250569311285U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordK;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 29U)) + RotL64(aCarry, 3U)) + 5777369485254032486U;
            aOrbiterJ = (((aWandererI + RotL64(aScatter, 5U)) + RotL64(aCarry, 23U)) + 16813320300717644673U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = (((aWandererB + RotL64(aPrevious, 21U)) + RotL64(aCarry, 51U)) + 16689933050200758251U) + aNonceWordP;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 1856422419049390708U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 18214498743831925517U;
            aOrbiterA = RotL64((aOrbiterA * 10744120577560529379U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 18278550878494094923U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 797712062039591797U;
            aOrbiterF = RotL64((aOrbiterF * 7212998747080137625U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 15854849439012341347U) + aNonceWordG;
            aOrbiterG = (((aOrbiterG ^ aOrbiterJ) ^ 996882939768167773U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterG = RotL64((aOrbiterG * 14936703950807908575U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 3005829974130671692U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 8793495343509953906U;
            aOrbiterD = RotL64((aOrbiterD * 14065479348374612031U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 7710453029930631112U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 9511995836117707047U;
            aOrbiterK = RotL64((aOrbiterK * 7250766204781428201U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 670902975693341744U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 9045820304668279777U;
            aOrbiterJ = RotL64((aOrbiterJ * 18373074917532639027U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 12417212387607119470U) + aNonceWordI;
            aOrbiterE = (((aOrbiterE ^ aOrbiterD) ^ 12816983560669985622U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterE = RotL64((aOrbiterE * 8406003970221889847U), 27U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterE, 58U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + RotL64(aOrbiterD, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aPrevious, 27U) + aOrbiterK) + RotL64(aOrbiterE, 29U)) + RotL64(aCarry, 57U)) + aPhaseFWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterG, 37U)) + aNonceWordH);
            aWandererE = aWandererE + (((RotL64(aIngress, 14U) + RotL64(aOrbiterE, 11U)) + aOrbiterD) + aNonceWordL);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterF, 20U)) + aOrbiterK) + aPhaseFWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 43U) + aOrbiterA) + RotL64(aOrbiterD, 47U)) + RotL64(aCarry, 11U)) + aNonceWordF);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterJ, 57U)) + aOrbiterA);
            aWandererF = aWandererF + (((RotL64(aCross, 57U) + aOrbiterA) + RotL64(aOrbiterF, 5U)) + aNonceWordE);
            //
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 56U));
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 29U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 18419U)) & S_BLOCK1], 30U) ^ RotL64(aKeyRowReadA[((aIndex + 17607U)) & W_KEY1], 11U));
            aIngress ^= (RotL64(mSource[((aIndex + 16526U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneA[((aIndex + 17467U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 17557U)) & W_KEY1], 6U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 18094U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 19005U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 52U) + RotL64(aPrevious, 3U)) ^ (RotL64(aCarry, 19U) ^ RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterH = ((((aWandererD + RotL64(aIngress, 13U)) + RotL64(aCarry, 57U)) + 12849591986267890852U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterG = ((aWandererB + RotL64(aScatter, 21U)) + RotL64(aCarry, 35U)) + 8232614804696815750U;
            aOrbiterA = (aWandererI + RotL64(aCross, 40U)) + 12141567259210877281U;
            aOrbiterJ = (((aWandererC + RotL64(aPrevious, 51U)) + RotL64(aCarry, 11U)) + 2928641981037885644U) + aNonceWordO;
            aOrbiterI = (aWandererA + RotL64(aIngress, 57U)) + 980733350554783938U;
            aOrbiterD = (((aWandererG + RotL64(aPrevious, 29U)) + 2683985177993350746U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordD;
            aOrbiterK = ((aWandererH + RotL64(aCross, 3U)) + 14532148403815527355U) + aNonceWordA;
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 7736296629433884203U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 10428437770166310549U) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 326634742742373401U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 18327174144859461029U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 6810436935194432002U;
            aOrbiterH = RotL64((aOrbiterH * 2715987179577753597U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 12606153309690753435U) + aNonceWordE;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 17123256945895150555U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13469111258504672565U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 9057777759026189541U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 16478485918911194442U) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 11054247078884894131U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 18064460487552100483U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterA) ^ 11477276762421684083U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 3886501230380184395U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 18318375441973295081U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 13849305985380030986U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12962140243967824959U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 10240409420338313641U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 18360586077779529086U;
            aOrbiterJ = RotL64((aOrbiterJ * 18196875422391501927U), 37U);
            //
            aIngress = RotL64(aOrbiterK, 47U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + RotL64(aOrbiterI, 20U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 53U)) + aOrbiterD);
            aWandererD = aWandererD + (((((RotL64(aCross, 3U) + RotL64(aOrbiterG, 11U)) + aOrbiterI) + RotL64(aCarry, 35U)) + aNonceWordC) + aPhaseGWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 41U) + aOrbiterH) + RotL64(aOrbiterA, 30U)) + aNonceWordN);
            aWandererC = aWandererC + (((RotL64(aIngress, 11U) + RotL64(aOrbiterJ, 47U)) + aOrbiterK) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 18U) + RotL64(aOrbiterK, 21U)) + aOrbiterI);
            aWandererI = aWandererI + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterA, 39U)) + aOrbiterK);
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 51U) + RotL64(aOrbiterJ, 3U)) + aOrbiterH) + aNonceWordK) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 60U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 21259U)) & S_BLOCK1], 39U) ^ RotL64(mSource[((aIndex + 20228U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 20302U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 21614U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 20570U)) & W_KEY1], 23U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 20405U)) & W_KEY1], 34U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 19550U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((aIndex + 21570U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCross, 5U)) ^ (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 20U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterG = (aWandererD + RotL64(aScatter, 44U)) + 12380376990224645149U;
            aOrbiterB = ((((aWandererE + RotL64(aCross, 51U)) + RotL64(aCarry, 29U)) + 18296928500297384014U) + aPhaseGOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1]) + aNonceWordN;
            aOrbiterI = (((aWandererK + RotL64(aPrevious, 5U)) + RotL64(aCarry, 11U)) + 3550626816361145100U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aIngress, 11U)) + 2667792936946706027U;
            aOrbiterE = (aWandererG + RotL64(aCross, 57U)) + 12020969779370926953U;
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 37U)) + 737340727886903447U) + aNonceWordL;
            aOrbiterK = (((aWandererI + RotL64(aScatter, 19U)) + RotL64(aCarry, 51U)) + 1681797651799760502U) + aNonceWordM;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 2956186342689489064U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 1876852870402977177U) ^ aNonceWordO;
            aOrbiterI = RotL64((aOrbiterI * 8875540081346621757U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 6433205819353555071U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 9065076854974222998U;
            aOrbiterE = RotL64((aOrbiterE * 5459675878087242021U), 5U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterJ) + 3254410578766789992U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordD;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 2005081975473815576U) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 9947701153722014085U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 15992999234834560419U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 3458344156815120948U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1668460113964608051U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 17069783053664877727U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 1260234710193913099U) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 4561226779897414381U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 3825186451876061335U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 2905344294992827535U;
            aOrbiterJ = RotL64((aOrbiterJ * 2469896090698580795U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 18141402347899180617U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 8760129857609925066U;
            aOrbiterF = RotL64((aOrbiterF * 2507999156108123047U), 19U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterG, 43U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterB, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 5U) + RotL64(aOrbiterE, 11U)) + aOrbiterJ) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterJ, 60U)) + aNonceWordJ);
            aWandererA = aWandererA + (((RotL64(aScatter, 37U) + RotL64(aOrbiterJ, 29U)) + aOrbiterF) + aPhaseGWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 19U)) + aOrbiterI);
            aWandererK = aWandererK + (((RotL64(aCross, 13U) + RotL64(aOrbiterG, 35U)) + aOrbiterB) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterK, 53U)) + aOrbiterF);
            aWandererD = aWandererD + ((((RotL64(aScatter, 21U) + aOrbiterE) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 43U)) + aNonceWordB);
            //
            aCarry = aCarry + (RotL64(aWandererG, 28U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererI, 13U);
            aCarry = aCarry + RotL64(aIngress, 22U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 22050U)) & S_BLOCK1], 27U) ^ RotL64(aKeyRowReadA[((aIndex + 23130U)) & W_KEY1], 58U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 24276U)) & W_KEY1], 5U) ^ RotL64(aFireLaneC[((aIndex + 24414U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 23117U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 24047U)) & S_BLOCK1], 27U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 23271U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 23022U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aPrevious, 41U)) + (RotL64(aIngress, 14U) + RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterH = ((aWandererE + RotL64(aScatter, 52U)) + RotL64(aCarry, 37U)) + 7651355040951791298U;
            aOrbiterJ = (((aWandererF + RotL64(aIngress, 21U)) + RotL64(aCarry, 11U)) + 13988210277931659312U) + aNonceWordH;
            aOrbiterD = (aWandererK + RotL64(aPrevious, 29U)) + 9846849412579537783U;
            aOrbiterI = ((aWandererA + RotL64(aCross, 35U)) + 12746719939495876158U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = (((aWandererC + RotL64(aPrevious, 13U)) + 11498066185182895284U) + aPhaseGOrbiterAssignSaltB[((aIndex + 14U)) & S_SALT1]) + aNonceWordF;
            aOrbiterF = (aWandererJ + RotL64(aIngress, 3U)) + 11101058955193080232U;
            aOrbiterK = ((aWandererB + RotL64(aCross, 43U)) + RotL64(aCarry, 51U)) + 15513734459555672046U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 15711108675349394643U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 4771231759949468556U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9806191054594333615U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 11449258010811305256U) + aNonceWordB;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 17036938391509986723U;
            aOrbiterA = RotL64((aOrbiterA * 7411466953205347639U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 6999245666776654250U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 2106819066263369528U;
            aOrbiterJ = RotL64((aOrbiterJ * 13005885810757743129U), 19U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterD) + 12716183358903477216U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordK;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 16752724547046059889U) ^ aNonceWordL;
            aOrbiterI = RotL64((aOrbiterI * 11475905692393034141U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 17623077680983093163U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 6726003022297274986U;
            aOrbiterH = RotL64((aOrbiterH * 14709385877103232653U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 2842410225096524740U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 9235178377537910514U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11813751114775673845U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 2619888019860844610U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 6295481948199619613U) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 15429161806953951205U), 57U);
            //
            aIngress = RotL64(aOrbiterD, 5U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + RotL64(aOrbiterJ, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aIngress, 3U) + aOrbiterI) + RotL64(aOrbiterJ, 19U)) + aNonceWordI);
            aWandererE = aWandererE ^ (((RotL64(aCross, 23U) + aOrbiterD) + RotL64(aOrbiterI, 29U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 60U) + RotL64(aOrbiterF, 57U)) + aOrbiterA) + RotL64(aCarry, 23U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterI, 43U)) + aOrbiterK) + aNonceWordJ);
            aWandererB = aWandererB + (((RotL64(aIngress, 35U) + aOrbiterH) + RotL64(aOrbiterD, 35U)) + aNonceWordG);
            aWandererA = aWandererA ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterH, 51U)) + aOrbiterF) + aNonceWordP);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 51U) + aOrbiterK) + RotL64(aOrbiterF, 4U)) + RotL64(aCarry, 35U)) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 18U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererA, 11U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 26963U)) & S_BLOCK1], 58U) ^ RotL64(aKeyRowReadA[((aIndex + 25447U)) & W_KEY1], 29U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 27000U)) & S_BLOCK1], 41U) ^ RotL64(aFireLaneB[((aIndex + 25416U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 27199U)) & W_KEY1], 39U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 25740U)) & S_BLOCK1], 57U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 25862U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneD[((aIndex + 26713U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCross, 41U)) + (RotL64(aCarry, 54U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterA = (((aWandererA + RotL64(aIngress, 35U)) + RotL64(aCarry, 21U)) + 12690502671561165478U) + aNonceWordL;
            aOrbiterG = ((aWandererH + RotL64(aScatter, 5U)) + 17519943923428102801U) + aNonceWordI;
            aOrbiterD = (((aWandererD + RotL64(aCross, 13U)) + RotL64(aCarry, 57U)) + 10705515807975331385U) + aNonceWordB;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 43U)) + RotL64(aCarry, 41U)) + 16586447272278538179U;
            aOrbiterB = (((aWandererK + RotL64(aScatter, 27U)) + 8006560996840971798U) + aPhaseHOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1]) + aNonceWordF;
            aOrbiterH = (aWandererG + RotL64(aPrevious, 51U)) + 12928600185788857701U;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 60U)) + 14240723153798267172U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 8636219177994872072U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 7586790235186467512U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15052686382507614169U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 1103807034179512424U) + aNonceWordE;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 7547526530239498693U;
            aOrbiterH = RotL64((aOrbiterH * 3360295583636013509U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 8380239679344786397U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 5690809173787433519U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5354724308093372953U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 8390902801141804609U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 3507306189192059486U;
            aOrbiterB = RotL64((aOrbiterB * 18336280496510253103U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 6190745292098482871U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 8065418693975056902U) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 6414621418430102589U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 12111755051718111803U) + aNonceWordG;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 7605877769709909297U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17525248694315944599U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 5969794501112646237U) + aNonceWordO;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 5127559299360591476U;
            aOrbiterG = RotL64((aOrbiterG * 4521563633438853069U), 37U);
            //
            aIngress = RotL64(aOrbiterH, 11U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + (RotL64(aOrbiterA, 34U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aIngress, 3U) + RotL64(aOrbiterA, 13U)) + aOrbiterJ) + RotL64(aCarry, 21U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterG, 50U)) + aOrbiterH) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 36U) + aOrbiterA) + RotL64(aOrbiterH, 23U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterI, 3U)) + aOrbiterG) + aNonceWordK);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 19U) + aOrbiterA) + RotL64(aOrbiterG, 43U)) + RotL64(aCarry, 41U)) + aNonceWordP);
            aWandererG = aWandererG ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterI, 29U)) + aOrbiterD) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 43U) + RotL64(aOrbiterI, 35U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 50U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + RotL64(aWandererD, 35U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 28116U)) & S_BLOCK1], 43U) ^ RotL64(aFireLaneD[((aIndex + 29511U)) & S_BLOCK1], 58U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 28829U)) & W_KEY1], 5U) ^ RotL64(aFireLaneC[((aIndex + 28944U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 28522U)) & W_KEY1], 43U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 27466U)) & S_BLOCK1], 57U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27919U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 29673U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 43U) ^ RotL64(aCross, 57U)) + (RotL64(aCarry, 27U) ^ RotL64(aIngress, 14U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterH = ((((aWandererJ + RotL64(aScatter, 12U)) + RotL64(aCarry, 37U)) + 701291026547470433U) + aPhaseHOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1]) + aNonceWordE;
            aOrbiterK = (aWandererA + RotL64(aIngress, 21U)) + 17283292650462111643U;
            aOrbiterI = (((aWandererI + RotL64(aCross, 57U)) + RotL64(aCarry, 53U)) + 9969124091931303406U) + aNonceWordC;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 3U)) + RotL64(aCarry, 21U)) + 889176772718046988U;
            aOrbiterD = (((aWandererB + RotL64(aCross, 47U)) + 6054541844643748084U) + aPhaseHOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1]) + aNonceWordI;
            aOrbiterA = (aWandererF + RotL64(aIngress, 41U)) + 14703226235143028132U;
            aOrbiterJ = (aWandererE + RotL64(aScatter, 35U)) + 7977975878522921062U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 16894322614172266274U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 12160451749345900570U;
            aOrbiterI = RotL64((aOrbiterI * 18055355572903901749U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 10870847008043897470U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 8159920947172520247U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4833194641611011805U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 2440099120969517932U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 2428396147731468007U;
            aOrbiterJ = RotL64((aOrbiterJ * 9363073341539598441U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 2213226274394673479U) + aNonceWordP;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 7079731443427765333U;
            aOrbiterA = RotL64((aOrbiterA * 16918930776877030559U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 958896789550478970U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 10788682955708075458U;
            aOrbiterD = RotL64((aOrbiterD * 913321215613559729U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 2003386579317564870U) + aNonceWordM;
            aOrbiterG = (((aOrbiterG ^ aOrbiterA) ^ 8419686358774204999U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterG = RotL64((aOrbiterG * 6547052526438697621U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 6989167615157578904U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 17636634003643824148U;
            aOrbiterH = RotL64((aOrbiterH * 11038576417283732937U), 41U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterD, 21U);
            aIngress = aIngress + (RotL64(aOrbiterI, 53U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterG, 30U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aScatter, 21U) + aOrbiterI) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 35U)) + aPhaseHWandererUpdateSaltB[((aIndex + 8U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterG, 23U)) + aOrbiterD) + aNonceWordA);
            aWandererE = aWandererE + ((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 6U)) + aOrbiterD);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 29U)) + aOrbiterK) + aNonceWordO);
            aWandererJ = aWandererJ + (((((RotL64(aIngress, 27U) + RotL64(aOrbiterJ, 51U)) + aOrbiterH) + RotL64(aCarry, 51U)) + aNonceWordJ) + aPhaseHWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 38U) + aOrbiterI) + RotL64(aOrbiterH, 37U)) + aNonceWordH);
            aWandererF = aWandererF + ((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 43U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 60U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 32504U)) & S_BLOCK1], 6U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 32058U)) & W_KEY1], 51U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 30789U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30892U)) & S_BLOCK1], 57U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30389U)) & S_BLOCK1], 37U) ^ RotL64(aKeyRowReadB[((aIndex + 31185U)) & W_KEY1], 6U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 21U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCross, 36U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterE = (((aWandererB + RotL64(aCross, 35U)) + RotL64(aCarry, 5U)) + 5576732410244514238U) + aNonceWordM;
            aOrbiterJ = ((((aWandererG + RotL64(aPrevious, 21U)) + RotL64(aCarry, 19U)) + 2833808925935929629U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterG = (aWandererD + RotL64(aIngress, 43U)) + 3670188682914544792U;
            aOrbiterA = ((aWandererF + RotL64(aScatter, 51U)) + RotL64(aCarry, 37U)) + 15759072378887814995U;
            aOrbiterH = (aWandererE + RotL64(aIngress, 13U)) + 13934007231137439994U;
            aOrbiterD = (aWandererI + RotL64(aPrevious, 6U)) + 11022225696007690512U;
            aOrbiterB = (((aWandererH + RotL64(aCross, 57U)) + 16989177104453635790U) + aPhaseHOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1]) + aNonceWordP;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 9256930045263527091U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 17788596104417068290U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 675554110563253305U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 17044369456673337625U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 1310908395523250343U;
            aOrbiterH = RotL64((aOrbiterH * 16305084373037705921U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 12067065689034065422U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 15130844248737512262U) ^ aNonceWordF;
            aOrbiterE = RotL64((aOrbiterE * 9409499577465934107U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 14532689204495587494U) + aNonceWordI;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 8198147292120244178U;
            aOrbiterJ = RotL64((aOrbiterJ * 1418356389507740991U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 5485494458627163347U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 10830008207150307611U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6526039534042499457U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 17770065502486618029U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 6397859353395335459U) ^ aNonceWordG;
            aOrbiterD = RotL64((aOrbiterD * 14286997752368893825U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 5128700697381508319U) + aNonceWordO;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 7103394110057060499U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5053680689949149633U), 21U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 29U);
            aIngress = aIngress + (RotL64(aOrbiterB, 11U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 19U));
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aScatter, 27U) + aOrbiterA) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 11U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterD, 27U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 36U)) + aOrbiterG);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 11U) + aOrbiterA) + RotL64(aOrbiterE, 19U)) + aNonceWordD);
            aWandererI = aWandererI + (((RotL64(aScatter, 20U) + aOrbiterG) + RotL64(aOrbiterD, 11U)) + aNonceWordB);
            aWandererF = aWandererF ^ ((RotL64(aCross, 5U) + aOrbiterB) + RotL64(aOrbiterH, 43U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 37U) + aOrbiterE) + RotL64(aOrbiterG, 51U)) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 48U));
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + RotL64(aWandererI, 43U);
            aCarry = aCarry + RotL64(aIngress, 24U);
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

void TwistExpander_VolleyBall_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xA9E6716E7C308F3BULL + 0x914BF7699BEFECD6ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xA5214935E7C41669ULL + 0xCC580AFF96C51CDEULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xB42038B260DE1BCDULL + 0x8C5DAFBAF1BAFA06ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xB331E4FBC1574E31ULL + 0xB09BB7D9D045A7D6ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xBDB909CF4531981DULL + 0xACF52FF64D78534FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xFAA535A2BB27CB7DULL + 0xB665D48B5980F56DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x9249CFC71EFF738BULL + 0xB7B19D2AA48B0C2AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xB7509222D745B029ULL + 0xBC9F09E09FDBDAB8ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xD4CFD1860033E7FFULL + 0x93BCDFE01EAA7E9FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xB0976AE2A78D59B1ULL + 0xF22D0D14C1280B3BULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x94A45769FB670869ULL + 0x8B3E2CCFED345F61ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xBAA0C73AAAAA8DEDULL + 0xB0C9B6F898500F07ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x89246AD9DB067B4FULL + 0xFE15BA35CE7A8FF2ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xC8296E1C61D89D25ULL + 0xD1AF5647DCEBFB5DULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xF95A92D430AF5DA9ULL + 0xC89D76FBC482DA55ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x951E19576FCB8EC9ULL + 0xDB5397B3346EAC7BULL);
    // GSeedRunSeed_B seed_loop_a (start)
    {
        // GSeedRunSeed_B seed_loop_a lane group
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneA, aFireLaneB, aInvestLaneB, aFireLaneD, aOperationLaneA, aFireLaneC, aOperationLaneB, aOperationLaneC
        // write to: aInvestLaneA, aInvestLaneB, aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // seed_loop_a loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 2343U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((aIndex + 2715U)) & S_BLOCK1], 18U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 3484U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4783U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneD[((aIndex + 4204U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aIngress, 3U)) ^ (RotL64(aPrevious, 22U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 52U)) + RotL64(aCarry, 57U)) + 13650869943246163567U;
            aOrbiterK = ((aWandererD + RotL64(aCross, 23U)) + RotL64(aCarry, 11U)) + 3435284932011770999U;
            aOrbiterF = ((((aWandererF + RotL64(aIngress, 3U)) + RotL64(aCarry, 27U)) + 12388155658186776579U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordL;
            aOrbiterI = (((aWandererH + RotL64(aPrevious, 35U)) + 2374345913955712039U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordP;
            aOrbiterB = (aWandererK + RotL64(aScatter, 43U)) + 6095094526980292156U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 4965147025852444174U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 3261881216269075298U) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 4874733445914960785U), 19U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterI) + 4939780217097329222U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1]) + aNonceWordO;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 3019862009792676287U;
            aOrbiterB = RotL64((aOrbiterB * 2452316208025448747U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 901910626217143974U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 3647055146712366383U;
            aOrbiterI = RotL64((aOrbiterI * 1792602402476450009U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 7731765438957392967U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterB) ^ 13409819457393479741U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 3345078200262410715U), 57U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterB) + 5415832109107794258U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1]) + aNonceWordI;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 8876738832313114471U;
            aOrbiterJ = RotL64((aOrbiterJ * 1304277600444504135U), 35U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterJ, 5U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 23U)) + aOrbiterF) + aNonceWordH) + aPhaseAWandererUpdateSaltC[((aIndex + 12U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterJ, 14U)) + RotL64(aCarry, 43U)) + aNonceWordJ);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 44U) + RotL64(aOrbiterI, 51U)) + aOrbiterJ) + aNonceWordE);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterB, 37U)) + aOrbiterK) + RotL64(aCarry, 19U)) + aNonceWordC);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterI, 5U)) + aOrbiterK) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 58U));
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aInvestLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 2
        // ingress from: aInvestLaneA, aExpandLaneC, aFireLaneB
        // ingress directions: aInvestLaneA forward forced, aExpandLaneC forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneA[((aIndex + 9084U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((aIndex + 10396U)) & S_BLOCK1], 52U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 8023U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9882U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((aIndex + 10072U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aPrevious, 43U)) + (RotL64(aIngress, 29U) ^ RotL64(aCross, 12U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterF = ((((aWandererG + RotL64(aScatter, 3U)) + RotL64(aCarry, 3U)) + 252059974543142812U) + aPhaseAOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = ((((aWandererH + RotL64(aIngress, 29U)) + RotL64(aCarry, 19U)) + 11690823093681457368U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordP;
            aOrbiterB = ((aWandererC + RotL64(aCross, 12U)) + RotL64(aCarry, 53U)) + 13282189752890971123U;
            aOrbiterK = (aWandererI + RotL64(aPrevious, 51U)) + 9507416294305708435U;
            aOrbiterG = (aWandererB + RotL64(aCross, 21U)) + 14053038174390776539U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 14605253312318725009U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 18138286582677863671U) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 10595905899691011321U), 41U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterB) + 8530091235978489988U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordH;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 14381731677571170073U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11675896999665768253U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 13316413456378978456U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 3910529530149320706U;
            aOrbiterK = RotL64((aOrbiterK * 16000139333493588429U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 6302070286831566901U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 12324134652758551396U;
            aOrbiterG = RotL64((aOrbiterG * 17136438281540250165U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 4773478557638475048U) + aNonceWordJ;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 4031153435446078944U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3876928995240982769U), 53U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 37U);
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 6U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterF, 10U)) + RotL64(aCarry, 23U)) + aNonceWordK) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 27U)) + aOrbiterB) + aNonceWordO) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 22U) + aOrbiterK) + RotL64(aOrbiterG, 51U)) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterK, 43U)) + aOrbiterD) + aNonceWordD);
            aWandererI = aWandererI + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterG, 35U)) + aOrbiterD) + aNonceWordB);
            //
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + RotL64(aWandererG, 41U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aInvestLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 3
        // ingress from: aInvestLaneB, aExpandLaneD, aFireLaneD
        // ingress directions: aInvestLaneB forward forced, aExpandLaneD forward forced, aFireLaneD forward/backward random
        // cross from: aInvestLaneA, aExpandLaneB, aExpandLaneA
        // cross directions: aInvestLaneA backward forced, aExpandLaneB backward forced, aExpandLaneA backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneB[((aIndex + 12442U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneD[((aIndex + 12214U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 12226U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 11118U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 15236U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 14856U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCross, 39U)) + (RotL64(aCarry, 13U) ^ RotL64(aIngress, 56U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterC = ((aWandererI + RotL64(aIngress, 47U)) + RotL64(aCarry, 19U)) + 13296600294247799698U;
            aOrbiterA = (((aWandererH + RotL64(aCross, 19U)) + RotL64(aCarry, 3U)) + 5818503518080877515U) + aNonceWordP;
            aOrbiterD = ((((aWandererE + RotL64(aPrevious, 11U)) + RotL64(aCarry, 53U)) + 6735784238734173597U) + aPhaseAOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1]) + aNonceWordB;
            aOrbiterE = (aWandererJ + RotL64(aScatter, 57U)) + 7368398209488856201U;
            aOrbiterH = ((aWandererC + RotL64(aCross, 30U)) + 961734029066455638U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 797011946660892011U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 12841876018396622350U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14056540056414153277U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 16213253970483895623U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 15186950557113470375U;
            aOrbiterE = RotL64((aOrbiterE * 4647470430467908107U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 5117930310827477341U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 12265429373166094162U;
            aOrbiterA = RotL64((aOrbiterA * 1522823535151532249U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 13920531346698601568U) + aNonceWordJ;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 14695405206998211456U) ^ aNonceWordK;
            aOrbiterH = RotL64((aOrbiterH * 13950964363414164279U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 7851960904825938443U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 9501511171732550190U) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 5614164120361489613U), 47U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterH, 29U);
            aIngress = aIngress + (RotL64(aOrbiterC, 53U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterD, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aCross, 11U) + aOrbiterH) + RotL64(aOrbiterC, 19U)) + RotL64(aCarry, 5U)) + aNonceWordA);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterA, 37U)) + aOrbiterD) + aNonceWordI);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 21U) + aOrbiterE) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 37U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 56U) + aOrbiterD) + RotL64(aOrbiterC, 27U)) + aPhaseAWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 50U)) + aOrbiterC) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 48U));
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 4
        // ingress from: aOperationLaneA, aInvestLaneA, aFireLaneC
        // ingress directions: aOperationLaneA forward forced, aInvestLaneA forward forced, aFireLaneC forward/backward random
        // cross from: aInvestLaneB, aExpandLaneD, aExpandLaneC
        // cross directions: aInvestLaneB backward forced, aExpandLaneD backward forced, aExpandLaneC backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 20925U)) & S_BLOCK1], 23U) ^ RotL64(aInvestLaneA[((aIndex + 21536U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 18484U)) & S_BLOCK1], 40U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 20077U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19731U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 20200U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCross, 51U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCarry, 36U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterI = (aWandererB + RotL64(aScatter, 41U)) + 11450949896247900941U;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 51U)) + RotL64(aCarry, 47U)) + 3905542253538116335U;
            aOrbiterG = (aWandererG + RotL64(aIngress, 20U)) + 9529740545977785305U;
            aOrbiterF = ((((aWandererH + RotL64(aCross, 11U)) + RotL64(aCarry, 29U)) + 1856876631533143492U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordP;
            aOrbiterK = ((((aWandererI + RotL64(aScatter, 3U)) + RotL64(aCarry, 3U)) + 84253466320181686U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordC;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 12577480918745432444U) + aNonceWordA;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 5625703170397704029U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13583960724598036659U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 694608607323629282U) + aNonceWordE;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 3993981243536262204U;
            aOrbiterJ = RotL64((aOrbiterJ * 2502835860198146381U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 4119215953484892051U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 8785040118556157146U;
            aOrbiterI = RotL64((aOrbiterI * 17113521266125471625U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 16234403619456882890U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 10398727475672860610U;
            aOrbiterK = RotL64((aOrbiterK * 5086871400049644715U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 18327987141759096769U) + aNonceWordM;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 2645964788056875452U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8778681366114628045U), 3U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 52U);
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 57U) + aOrbiterG) + RotL64(aOrbiterK, 21U)) + aNonceWordO);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 29U)) + aNonceWordL);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 36U) + RotL64(aOrbiterI, 5U)) + aOrbiterF) + aPhaseAWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 11U) + RotL64(aOrbiterI, 34U)) + aOrbiterJ) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterJ, 53U)) + aNonceWordG) + aPhaseAWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + RotL64(aWandererH, 57U);
            aCarry = aCarry + RotL64(aIngress, 38U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 23129U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneA[((aIndex + 26757U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 23227U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 23291U)) & S_BLOCK1], 57U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 25092U)) & S_BLOCK1], 24U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 25482U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 10U) ^ RotL64(aCross, 41U)) + (RotL64(aCarry, 53U) ^ RotL64(aIngress, 29U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterE = (((aWandererA + RotL64(aCross, 3U)) + 2974056819475622600U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordI;
            aOrbiterF = ((((aWandererB + RotL64(aScatter, 11U)) + RotL64(aCarry, 21U)) + 7345051759236356098U) + aPhaseAOrbiterAssignSaltA[((aIndex + 18U)) & S_SALT1]) + aNonceWordE;
            aOrbiterB = (((aWandererJ + RotL64(aPrevious, 43U)) + RotL64(aCarry, 3U)) + 12738468816846628882U) + aNonceWordH;
            aOrbiterG = ((aWandererE + RotL64(aIngress, 34U)) + RotL64(aCarry, 47U)) + 7694520596043297922U;
            aOrbiterD = ((aWandererI + RotL64(aCross, 53U)) + 5530753590015084774U) + aNonceWordC;
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 3776309161718383105U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 784780304358106404U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1503119308251871519U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 8999942326995036509U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 5194986506064092779U;
            aOrbiterF = RotL64((aOrbiterF * 15070787038006135963U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 7920040007459652762U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 11311997270710107937U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6227571709361790209U), 27U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterB) + 5365231114813547251U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1]) + aNonceWordF;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 8630110234623825263U;
            aOrbiterE = RotL64((aOrbiterE * 2735881715888325759U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 2358235238039571072U) + aNonceWordO;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 18059414891616491807U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17150786106857185467U), 53U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterD, 47U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + RotL64(aOrbiterF, 10U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aPrevious, 26U) + aOrbiterD) + RotL64(aOrbiterB, 53U)) + RotL64(aCarry, 3U)) + aNonceWordM);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 11U) + aOrbiterB) + RotL64(aOrbiterG, 10U));
            aWandererB = aWandererB + (((((RotL64(aIngress, 37U) + RotL64(aOrbiterG, 27U)) + aOrbiterE) + RotL64(aCarry, 37U)) + aNonceWordP) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterE, 39U)) + aOrbiterF) + aNonceWordA);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 19U)) + aOrbiterD) + aNonceWordJ) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 60U));
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 37U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 29332U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((aIndex + 31208U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28873U)) & S_BLOCK1], 6U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31043U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28436U)) & S_BLOCK1], 4U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 29868U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCross, 3U)) ^ (RotL64(aCarry, 22U) + RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterC = (aWandererK + RotL64(aIngress, 5U)) + 4848316479321533394U;
            aOrbiterI = ((((aWandererI + RotL64(aPrevious, 19U)) + RotL64(aCarry, 43U)) + 6919360256662636195U) + aPhaseAOrbiterAssignSaltB[((aIndex + 20U)) & S_SALT1]) + aNonceWordK;
            aOrbiterF = (((aWandererH + RotL64(aCross, 46U)) + RotL64(aCarry, 5U)) + 9897013582181108544U) + aNonceWordD;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 37U)) + RotL64(aCarry, 23U)) + 7319353809896158678U;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 57U)) + 2848175435514849859U) + aPhaseAOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 6967780718720437934U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 10143884766603388136U;
            aOrbiterF = RotL64((aOrbiterF * 17346772745745835895U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 8675965006150972051U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 16350117755560994281U) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 15072308930382994425U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 17976597517118423760U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 1399631141355370237U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16537788276543236833U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 3590613762034716792U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterB) ^ 5134624314245932157U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterC = RotL64((aOrbiterC * 13077589037975283371U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 10082236952942943654U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 4015535035905433450U) ^ aNonceWordC;
            aOrbiterD = RotL64((aOrbiterD * 4961808568701908559U), 57U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterC, 53U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 35U));
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 14U)) + aOrbiterF) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererI = aWandererI + (((((RotL64(aCross, 58U) + RotL64(aOrbiterB, 5U)) + aOrbiterI) + RotL64(aCarry, 35U)) + aNonceWordF) + aPhaseAWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterB, 51U)) + aOrbiterC);
            aWandererB = aWandererB + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 41U)) + aOrbiterD) + RotL64(aCarry, 51U)) + aNonceWordA);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 19U) + aOrbiterB) + RotL64(aOrbiterF, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 3U);
            aCarry = aCarry + RotL64(aIngress, 54U);
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

void TwistExpander_VolleyBall_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xE850EEEF71315279ULL + 0x8270497DC0C72CBAULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xE4694B315C4387C7ULL + 0xB8A5951AB1C7FBA2ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xF55C05159C16F601ULL + 0xFEA14B0047801602ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xC6500056B70C490FULL + 0xD8F6FD942836F630ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xE097DC1911C762ABULL + 0xFCED827175A15E65ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xD75E181258DEE393ULL + 0xCC840457B28A1FB1ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xE7E3D87C1FFFCC43ULL + 0xA2C336AF871BD39BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x978B935DC90B1ED7ULL + 0xB311D573DE191804ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xCA54170534B2B0C5ULL + 0xC68FBFE07FECFA47ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xF8887DBB2715F80BULL + 0x92B919AABB943AD0ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xA41B4AF22FAC7DAFULL + 0x99D39EADFB8E3779ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xEFB8E292779E9191ULL + 0xBB37635DCAF6A4D6ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xF4538CA7D14C5C7DULL + 0xAE96E491324640EDULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xACC87611BD75280DULL + 0xC6830D76035490E8ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xCB78AB6B092D5DFDULL + 0xF3BC6ED7A9FC8F86ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xD24E596FB3257305ULL + 0xDBE127CE852024C2ULL);
    // GSeedRunSeed_C seed_loop_b (start)
    {
        // GSeedRunSeed_C seed_loop_b lane group
        // read from: aOperationLaneA, aOperationLaneB, aExpandLaneC, aOperationLaneC, aOperationLaneD, aFireLaneA, aInvestLaneC, aExpandLaneA, aFireLaneC, aInvestLaneD, aFireLaneB, aWorkLaneA, aFireLaneD, aWorkLaneB, aExpandLaneD, aWorkLaneC, aExpandLaneB
        // write to: aInvestLaneC, aInvestLaneD, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // seed_loop_b loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aExpandLaneC
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aExpandLaneC forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aFireLaneA
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aFireLaneA backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 3991U)) & S_BLOCK1], 20U) ^ RotL64(aOperationLaneB[((aIndex + 3389U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 5224U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 1555U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 3723U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 54U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 13U) + RotL64(aIngress, 27U)) ^ (RotL64(aPrevious, 42U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 57U)) + RotL64(aCarry, 3U)) + 3255291173184001106U;
            aOrbiterA = ((aWandererE + RotL64(aCross, 52U)) + 15308468160116255528U) + aPhaseBOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aIngress, 23U)) + RotL64(aCarry, 41U)) + 18186972408589866656U;
            aOrbiterB = (aWandererB + RotL64(aScatter, 47U)) + 4439324265978331914U;
            aOrbiterI = ((aWandererH + RotL64(aCross, 3U)) + RotL64(aCarry, 19U)) + 13099263173016322486U;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 37U)) + 7041561081767500660U) + aNonceWordC;
            aOrbiterG = (aWandererK + RotL64(aIngress, 18U)) + 6196422612687812971U;
            aOrbiterH = (((aWandererA + RotL64(aPrevious, 11U)) + 7664260932541281413U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordA;
            aOrbiterF = (aWandererG + RotL64(aScatter, 43U)) + 17802347823020441056U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 4253107484061190446U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 13799496534030645312U;
            aOrbiterE = RotL64((aOrbiterE * 9167675060053848207U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 14252892847595951926U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 5663527578664291422U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 18314294235895182465U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 11148755959699137661U) + aNonceWordH;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 17036900929333594592U;
            aOrbiterI = RotL64((aOrbiterI * 16041243617369003291U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 2403828181385259549U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 17813580350434928194U;
            aOrbiterC = RotL64((aOrbiterC * 13666780980793857831U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 5623611126885414523U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 7293224381174846969U;
            aOrbiterA = RotL64((aOrbiterA * 7032561584670788117U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 10602620906929686163U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 18015916257203385982U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10684090189688871993U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 13592915735376305773U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 13995866908043417505U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3802175869395887331U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 8200465989447697618U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 9866671660800629464U;
            aOrbiterB = RotL64((aOrbiterB * 2138851839905326265U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 11557528777230608777U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterE) ^ 131060617338185060U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 11068705423012265209U), 19U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 26U);
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterB, 3U)) + aOrbiterA);
            aWandererA = aWandererA + ((((RotL64(aIngress, 34U) + aOrbiterD) + RotL64(aOrbiterB, 39U)) + RotL64(aCarry, 39U)) + aNonceWordN);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterD, 10U));
            aWandererH = aWandererH + (((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 41U) + aOrbiterC) + RotL64(aOrbiterI, 53U));
            aWandererD = aWandererD + ((RotL64(aIngress, 53U) + RotL64(aOrbiterD, 43U)) + aOrbiterC);
            aWandererG = aWandererG ^ ((((RotL64(aCross, 48U) + aOrbiterI) + RotL64(aOrbiterH, 23U)) + aNonceWordE) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 23U) + aOrbiterD) + RotL64(aOrbiterE, 57U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 34U)) + aOrbiterH) + aPhaseBWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 60U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 19U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aInvestLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 2
        // ingress from: aInvestLaneC, aOperationLaneC, aOperationLaneD, aExpandLaneA
        // ingress directions: aInvestLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aExpandLaneA forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aFireLaneC
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aFireLaneC backward/forward random
        // write to: aInvestLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 10613U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneC[((aIndex + 6418U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 7630U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 6484U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 5972U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 9209U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 7453U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 10U) ^ RotL64(aPrevious, 41U)) + (RotL64(aCarry, 57U) ^ RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterI = (aWandererD + RotL64(aPrevious, 39U)) + 1457104756581596530U;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 14U)) + 6127240317844622874U) + aNonceWordE;
            aOrbiterA = (((aWandererF + RotL64(aIngress, 57U)) + RotL64(aCarry, 5U)) + 16492290056044189421U) + aNonceWordO;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 29U)) + 10963676850938416468U) + aNonceWordA;
            aOrbiterC = ((aWandererC + RotL64(aIngress, 19U)) + 4872917367399752405U) + aPhaseBOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = (((aWandererB + RotL64(aCross, 35U)) + 15218882377875616148U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordK;
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 3U)) + 5934166612122118251U;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 53U)) + RotL64(aCarry, 21U)) + 14215280930872003003U;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 48U)) + RotL64(aCarry, 13U)) + 11428034799044600979U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 5453003654321728726U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 14273775120265649389U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5139018128323795309U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 328723770018440271U) + aNonceWordB;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 13032190719588211088U;
            aOrbiterC = RotL64((aOrbiterC * 13363368478932798315U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 2386881543033598494U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 1649501123340887116U) ^ aNonceWordL;
            aOrbiterF = RotL64((aOrbiterF * 11148976582360499033U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 16462401546754210583U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 1510579201823042227U;
            aOrbiterB = RotL64((aOrbiterB * 16287912400104043275U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 6889066000014251983U) + aNonceWordH;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 11324594596597724357U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15344987814648586023U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 12237796033168436537U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 17306069670330000343U;
            aOrbiterK = RotL64((aOrbiterK * 3167451351403385259U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 14197284538008811658U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 4754134852883071927U) ^ aNonceWordC;
            aOrbiterE = RotL64((aOrbiterE * 3484427259538998699U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 17201907781639753736U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 8318419319239859855U;
            aOrbiterJ = RotL64((aOrbiterJ * 10320390501983802091U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 16012488623961565780U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 15583721012865354925U;
            aOrbiterD = RotL64((aOrbiterD * 10656414363201743961U), 35U);
            //
            aIngress = RotL64(aOrbiterI, 57U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 26U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + (RotL64(aOrbiterF, 21U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aCross, 13U) + RotL64(aOrbiterC, 23U)) + aOrbiterK) + RotL64(aCarry, 51U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterD, 56U)) + aOrbiterA);
            aWandererE = aWandererE + ((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterE, 47U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 35U)) + aOrbiterA);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 23U) + RotL64(aOrbiterI, 3U)) + aOrbiterC) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 43U) + aOrbiterJ) + RotL64(aOrbiterF, 27U)) + aNonceWordJ);
            aWandererA = aWandererA + ((RotL64(aScatter, 53U) + RotL64(aOrbiterJ, 60U)) + aOrbiterD);
            aWandererF = aWandererF ^ (((RotL64(aCross, 6U) + RotL64(aOrbiterF, 51U)) + aOrbiterB) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 27U) + aOrbiterB) + RotL64(aOrbiterI, 41U)) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + RotL64(aWandererE, 48U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aInvestLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_b loop 3
        // ingress from: aInvestLaneD, aOperationLaneA, aFireLaneB
        // ingress directions: aInvestLaneD forward forced, aOperationLaneA forward forced, aFireLaneB forward/backward random
        // cross from: aInvestLaneC, aOperationLaneC
        // cross directions: aInvestLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneD[((aIndex + 13240U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((aIndex + 16302U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 13773U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 13915U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 11084U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 6U) + RotL64(aCross, 41U)) + (RotL64(aCarry, 21U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterK = (((aWandererH + RotL64(aScatter, 43U)) + 12809562813316740345U) + aPhaseBOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1]) + aNonceWordI;
            aOrbiterD = (aWandererJ + RotL64(aCross, 47U)) + 17084212535326321199U;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 23U)) + RotL64(aCarry, 3U)) + 16074921689983846769U;
            aOrbiterF = (aWandererC + RotL64(aIngress, 60U)) + 14027986153007120145U;
            aOrbiterB = (((aWandererK + RotL64(aCross, 13U)) + RotL64(aCarry, 11U)) + 7633455951809250227U) + aNonceWordE;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 19U)) + RotL64(aCarry, 37U)) + 340989348513370174U;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 39U)) + 5307820377645020116U) + aNonceWordL;
            aOrbiterE = (aWandererA + RotL64(aPrevious, 56U)) + 5605285015771527274U;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 27U)) + 5293500434746182790U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 7263156475892261811U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 10672879570907433005U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2506338667179450741U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 16659226780900986107U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 9774892622769850665U;
            aOrbiterB = RotL64((aOrbiterB * 7487477727543183211U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 10728057184108279042U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 5032485856947407217U;
            aOrbiterA = RotL64((aOrbiterA * 16651577903809154285U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 14642241075374862345U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 8386481273395203518U;
            aOrbiterC = RotL64((aOrbiterC * 11649977733867003445U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 2874153265304098104U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 11519900149177261000U;
            aOrbiterK = RotL64((aOrbiterK * 2010158758971864505U), 29U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterI) + 8885690878540115768U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1]) + aNonceWordK;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 4482143389870987714U;
            aOrbiterJ = RotL64((aOrbiterJ * 7105332459437434281U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 17469068567801886615U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 5121422018622394837U;
            aOrbiterD = RotL64((aOrbiterD * 14823827133212643467U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 3130788210672745618U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 6139244627510113216U) ^ aNonceWordC;
            aOrbiterE = RotL64((aOrbiterE * 2640754184921507389U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 10488511756324474710U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 1760223670304953696U;
            aOrbiterF = RotL64((aOrbiterF * 4007062295003769311U), 23U);
            //
            aIngress = RotL64(aOrbiterJ, 47U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 40U));
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aScatter, 36U) + aOrbiterC) + RotL64(aOrbiterK, 29U)) + aNonceWordO);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterA, 36U)) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 27U) + aOrbiterJ) + RotL64(aOrbiterE, 47U));
            aWandererB = aWandererB + ((((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterI, 51U)) + aNonceWordG) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterB, 21U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 11U) + aOrbiterA) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 37U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 51U) + aOrbiterB) + RotL64(aOrbiterD, 13U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterF, 3U)) + aOrbiterJ) + aNonceWordF);
            aWandererH = aWandererH ^ ((RotL64(aCross, 60U) + aOrbiterK) + RotL64(aOrbiterE, 42U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 44U));
            aCarry = aCarry + RotL64(aWandererH, 57U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 4
        // ingress from: aWorkLaneA, aInvestLaneC, aFireLaneD
        // ingress directions: aWorkLaneA forward forced, aInvestLaneC forward forced, aFireLaneD forward/backward random
        // cross from: aInvestLaneD, aOperationLaneD
        // cross directions: aInvestLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 16405U)) & S_BLOCK1], 13U) ^ RotL64(aInvestLaneC[((aIndex + 18746U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 21700U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 18199U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 19258U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 18U) ^ RotL64(aCarry, 57U)) + (RotL64(aCross, 41U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 27U)) + RotL64(aCarry, 53U)) + 6318740973868639425U;
            aOrbiterB = (((aWandererG + RotL64(aScatter, 41U)) + 5487840061430920881U) + aPhaseBOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1]) + aNonceWordH;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 34U)) + 10258706763248072672U) + aNonceWordF;
            aOrbiterF = (((aWandererA + RotL64(aCross, 23U)) + RotL64(aCarry, 35U)) + 18356875269730338208U) + aPhaseBOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 57U)) + 12883160282903147010U;
            aOrbiterD = (aWandererI + RotL64(aIngress, 19U)) + 1010140474942697730U;
            aOrbiterK = ((aWandererK + RotL64(aScatter, 53U)) + RotL64(aCarry, 23U)) + 17733939421700898293U;
            aOrbiterC = ((aWandererH + RotL64(aCross, 47U)) + 13693055887924981201U) + aNonceWordI;
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 4U)) + 14574732452793385269U) + aNonceWordP;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 10832873941223609012U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 8212600587135328040U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 5334613996794796145U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 5312744319781971178U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 6173741211706546923U;
            aOrbiterD = RotL64((aOrbiterD * 12854414066390848249U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 3693249147883790810U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterK) ^ 18365859989736602556U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterB = RotL64((aOrbiterB * 3348463719324104997U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 10645056678337549771U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 1175668356822251045U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6579675292775345579U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 13556844570541823717U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 4790355739411849736U;
            aOrbiterK = RotL64((aOrbiterK * 4083544011788850307U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 14905575502272644116U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 17047244574558476634U;
            aOrbiterE = RotL64((aOrbiterE * 2356386971503880047U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 10161614295718414869U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 13413914082651612468U) ^ aNonceWordN;
            aOrbiterC = RotL64((aOrbiterC * 16224039093981079491U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 6072693130156927774U) + aNonceWordM;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 4333656233793103787U;
            aOrbiterG = RotL64((aOrbiterG * 9374745547133955709U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 17209776289202130250U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 11752001118070361543U;
            aOrbiterF = RotL64((aOrbiterF * 4416523594812872339U), 37U);
            //
            aIngress = RotL64(aOrbiterE, 11U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterG, 26U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 28U) + aOrbiterI) + RotL64(aOrbiterD, 14U)) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 13U) + aOrbiterG) + RotL64(aOrbiterA, 43U)) + aNonceWordE);
            aWandererK = aWandererK + ((RotL64(aIngress, 19U) + aOrbiterB) + RotL64(aOrbiterE, 21U));
            aWandererG = aWandererG ^ ((((RotL64(aCross, 53U) + aOrbiterB) + RotL64(aOrbiterD, 29U)) + aNonceWordJ) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 39U) + aOrbiterI) + RotL64(aOrbiterG, 47U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 37U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aCross, 5U) + RotL64(aOrbiterB, 56U)) + aOrbiterC) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 48U) + aOrbiterE) + RotL64(aOrbiterF, 51U));
            aWandererA = aWandererA + (((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterC, 5U)) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + (RotL64(aWandererF, 24U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + RotL64(aWandererG, 11U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 25855U)) & S_BLOCK1], 22U) ^ RotL64(aInvestLaneD[((aIndex + 24431U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aExpandLaneD[((aIndex + 23878U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22435U)) & S_BLOCK1], 19U) ^ RotL64(aInvestLaneC[((aIndex + 24240U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 57U)) + (RotL64(aCross, 41U) + RotL64(aIngress, 22U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterD = ((aWandererE + RotL64(aScatter, 5U)) + RotL64(aCarry, 47U)) + 4384716820085860551U;
            aOrbiterH = ((((aWandererJ + RotL64(aIngress, 56U)) + RotL64(aCarry, 19U)) + 9715780315942116888U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordE;
            aOrbiterK = (aWandererD + RotL64(aCross, 23U)) + 15963520052789178632U;
            aOrbiterB = (((aWandererF + RotL64(aPrevious, 41U)) + RotL64(aCarry, 11U)) + 14346700690686392938U) + aPhaseBOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aScatter, 51U)) + 6005518012489966643U;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 46U)) + 2506732930310252119U) + aNonceWordF;
            aOrbiterE = (aWandererC + RotL64(aCross, 35U)) + 16782163084851775826U;
            aOrbiterG = (aWandererB + RotL64(aIngress, 11U)) + 823673076571076303U;
            aOrbiterI = (aWandererG + RotL64(aScatter, 19U)) + 1634084509064077736U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 1288134975466877686U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 2998220403162908444U;
            aOrbiterK = RotL64((aOrbiterK * 4321412662318298283U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 220430672180734911U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 10223923547068528867U;
            aOrbiterF = RotL64((aOrbiterF * 12577370238343872139U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 11696469696177647608U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 6545430420379636963U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8387163146257553773U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 79691451831797107U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 8971444023498649419U;
            aOrbiterG = RotL64((aOrbiterG * 7148919880477390009U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 5624403902454498793U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterF) ^ 9468064161002030997U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 8243560528100864595U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 4619361544913629805U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 12682446273369750704U;
            aOrbiterH = RotL64((aOrbiterH * 10879074713156075641U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 8728730962617599223U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 9099675924074253030U) ^ aNonceWordI;
            aOrbiterD = RotL64((aOrbiterD * 5525644236954497523U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 3298303921318288541U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 5953276499411658358U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10565471305001292693U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 6725769507592688539U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 1057277456510215817U;
            aOrbiterI = RotL64((aOrbiterI * 8269412198279297075U), 53U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 39U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + (RotL64(aOrbiterI, 30U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterF, 53U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterH, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aScatter, 52U) + aOrbiterE) + RotL64(aOrbiterJ, 13U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterK, 5U)) + aNonceWordB);
            aWandererA = aWandererA + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 51U)) + aOrbiterJ) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterB, 29U)) + aOrbiterE);
            aWandererK = aWandererK + ((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterK, 24U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterI, 39U)) + aOrbiterF) + aNonceWordC);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 13U) + aOrbiterB) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 57U)) + aPhaseBWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 26U) + RotL64(aOrbiterG, 35U)) + aOrbiterF) + aPhaseBWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterD, 46U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 20U));
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 6
        // ingress from: aWorkLaneC, aWorkLaneA, aExpandLaneB
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aExpandLaneB forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 30127U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((aIndex + 29103U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 28520U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28523U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31230U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aPrevious, 52U)) + (RotL64(aCross, 39U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterE = ((aWandererB + RotL64(aCross, 4U)) + RotL64(aCarry, 39U)) + 2915859148137000694U;
            aOrbiterD = (aWandererC + RotL64(aScatter, 57U)) + 210680583721444425U;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 35U)) + 6668118118775650387U) + aNonceWordA;
            aOrbiterK = (((aWandererF + RotL64(aIngress, 23U)) + RotL64(aCarry, 11U)) + 15794200818099010989U) + aPhaseBOrbiterAssignSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = (((aWandererA + RotL64(aCross, 39U)) + 6565076707062828369U) + aPhaseBOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1]) + aNonceWordK;
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 28U)) + 16323164497808856719U;
            aOrbiterF = (aWandererD + RotL64(aIngress, 19U)) + 7965435318816716560U;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 43U)) + RotL64(aCarry, 53U)) + 7390281030573369017U;
            aOrbiterH = (aWandererI + RotL64(aCross, 11U)) + 2269738866911824875U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 9664014216039993873U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 18284857398028357633U;
            aOrbiterC = RotL64((aOrbiterC * 8402008251343393737U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 367667619795303009U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 7935945060956274197U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5481786693511955209U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 16683666162337789540U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 10655658270998102390U;
            aOrbiterJ = RotL64((aOrbiterJ * 15231596813382239841U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 8307037916581540297U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 3247742749860703524U) ^ aNonceWordE;
            aOrbiterF = RotL64((aOrbiterF * 15052136713218656641U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 10446792483683818139U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 16374602929344972364U;
            aOrbiterH = RotL64((aOrbiterH * 12599903932725787599U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 2411334498322777183U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 1093701164116833765U;
            aOrbiterE = RotL64((aOrbiterE * 13129220206835381729U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 17018480952982840635U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 17348395690080029814U;
            aOrbiterD = RotL64((aOrbiterD * 6212591395713433257U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 16111252311283623152U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 12776492920397785951U;
            aOrbiterI = RotL64((aOrbiterI * 6136009241593081821U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 12214538600808144816U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 10043377462096783363U) ^ aNonceWordP;
            aOrbiterK = RotL64((aOrbiterK * 14639467375095185877U), 27U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterI, 39U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 48U));
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterD, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aIngress, 28U) + aOrbiterC) + RotL64(aOrbiterH, 34U)) + aNonceWordI);
            aWandererK = aWandererK ^ ((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterI, 19U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 11U)) + aOrbiterA) + aPhaseBWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterH, 47U)) + aNonceWordN);
            aWandererC = aWandererC + ((RotL64(aIngress, 23U) + aOrbiterE) + RotL64(aOrbiterJ, 58U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterC, 5U)) + aOrbiterE) + aPhaseBWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aCross, 35U) + RotL64(aOrbiterE, 39U)) + aOrbiterK) + RotL64(aCarry, 5U)) + aNonceWordF);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 10U) + aOrbiterF) + RotL64(aOrbiterI, 53U)) + aNonceWordH);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 39U) + aOrbiterI) + RotL64(aOrbiterA, 27U)) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 24U));
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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

void TwistExpander_VolleyBall_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xAA93DACDD18AE0ABULL + 0xEC7A68403BFEEA7FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xDB74CD2FB039F5B7ULL + 0x9328F9BC8BAB72F2ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xB0A11C5CE8C2E791ULL + 0xD6012A527A25179AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xD1CB00A4EF114E15ULL + 0xE0AA8CB972DC77D8ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xBEE967C5113FEBA5ULL + 0xF4DFF825F89CD807ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xE8E84F431BBEBF9DULL + 0xCB155239312ECDC8ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xF610A55D199A43D5ULL + 0x9005B6CFAC87CE66ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xC58AB1F305FB0DA9ULL + 0xDAD1967269253143ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x9A03D0448956C67BULL + 0x882463658FD55E44ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xA857472B1510FD4FULL + 0xFD3A1906389ED900ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x8BCA5DCD78756D2BULL + 0xA1B2B71879639D38ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x801D7C07FCC62B03ULL + 0xBD7CED32643D4722ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xF89942AAC33A932BULL + 0xB53D3EEDB1047CCBULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xD00D12811B17DA87ULL + 0xDC4F1AF0FD0214B8ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xF3EB9D354E6B0B41ULL + 0xDBD9295BADFF6CCFULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xB9A9962E4C2DADF3ULL + 0xFFEDEB8403CBB7A6ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3594U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((aIndex + 340U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 3080U)) & S_BLOCK1], 36U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1921U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 2391U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 3896U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 53U)) + (RotL64(aCarry, 26U) ^ RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterH = (aWandererC + RotL64(aCross, 35U)) + 12262991801139086177U;
            aOrbiterD = (aWandererH + RotL64(aScatter, 27U)) + 7963038771924890197U;
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 21U)) + 15540520327933568896U;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 60U)) + RotL64(aCarry, 13U)) + 8745565892055020722U;
            aOrbiterE = (((aWandererE + RotL64(aPrevious, 43U)) + RotL64(aCarry, 53U)) + 16619329199683755286U) + aNonceWordJ;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 53U)) + 10865705026433867260U) + aPhaseDOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = ((((aWandererA + RotL64(aScatter, 3U)) + RotL64(aCarry, 35U)) + 2743368697984518059U) + aPhaseDOrbiterAssignSaltD[((aIndex + 24U)) & S_SALT1]) + aNonceWordE;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 5556006271515473135U) + aNonceWordN;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 5355833281353498588U;
            aOrbiterB = RotL64((aOrbiterB * 4190140212757841511U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 8313616108963479829U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 16657121016801866434U;
            aOrbiterH = RotL64((aOrbiterH * 331533349428472477U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 16532226425013000833U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterE) ^ 5800465874932467232U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 5966395771690704577U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 17882948163883121328U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 15029375310296563175U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17021415832288477713U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 10170682648007918739U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 11829089574189398773U;
            aOrbiterF = RotL64((aOrbiterF * 15755874363488568849U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 1746524867389196322U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 10217423427886742775U;
            aOrbiterG = RotL64((aOrbiterG * 9166162099575333519U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 1338457710729082656U) + aNonceWordO;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 1319981417675542556U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9518448254565489715U), 29U);
            //
            aIngress = RotL64(aOrbiterG, 3U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterB, 14U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 5U) + aOrbiterB) + RotL64(aOrbiterA, 3U));
            aWandererE = aWandererE + (((((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 29U)) + aOrbiterD) + RotL64(aCarry, 11U)) + aNonceWordA) + aPhaseDWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 58U)) + aOrbiterG) + aNonceWordG);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 18U) + aOrbiterH) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 29U)) + aNonceWordP);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterD, 35U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterG, 13U)) + aOrbiterE) + aPhaseDWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 37U) + aOrbiterB) + RotL64(aOrbiterE, 41U)) + aNonceWordD);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 18U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 7571U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((aIndex + 10108U)) & S_BLOCK1], 58U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 8580U)) & S_BLOCK1], 21U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 10380U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 7608U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10229U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 8111U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 56U) + RotL64(aCarry, 41U)) + (RotL64(aCross, 27U) ^ RotL64(aIngress, 13U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 57U)) + 14157904117287696136U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aScatter, 50U)) + 7369512677371640676U) + aNonceWordD;
            aOrbiterJ = (aWandererH + RotL64(aCross, 11U)) + 8411250745902073798U;
            aOrbiterI = (((aWandererC + RotL64(aIngress, 19U)) + RotL64(aCarry, 23U)) + 5002041814539710275U) + aNonceWordK;
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 35U)) + 9538041410816283124U) + aNonceWordA;
            aOrbiterF = (((aWandererB + RotL64(aScatter, 3U)) + RotL64(aCarry, 53U)) + 5210700103927513061U) + aNonceWordG;
            aOrbiterA = (((aWandererG + RotL64(aCross, 27U)) + RotL64(aCarry, 35U)) + 7600709399101287982U) + aPhaseDOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 2366369466696580499U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 5544575244203019109U) ^ aNonceWordM;
            aOrbiterJ = RotL64((aOrbiterJ * 16231219246786333057U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 8710073749110329779U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 15998211310115361630U;
            aOrbiterK = RotL64((aOrbiterK * 15275657696897688955U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 15354357553877376422U) + aNonceWordC;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 10657523549259276169U) ^ aNonceWordL;
            aOrbiterB = RotL64((aOrbiterB * 13695239532898311073U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 10405750198355464768U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 3465819693133515142U;
            aOrbiterI = RotL64((aOrbiterI * 14678343718277562799U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 16724189641701408630U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 3484340153620198872U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17247547677520703125U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 7420442404884871126U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 11138445997256757636U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 11167543379937571127U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 1428191560884663125U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 16950093140800653985U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4423012306984814805U), 21U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterI, 57U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + RotL64(aOrbiterF, 14U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterJ, 46U)) + aOrbiterA) + aNonceWordJ);
            aWandererA = aWandererA + (((((RotL64(aPrevious, 23U) + RotL64(aOrbiterJ, 37U)) + aOrbiterB) + RotL64(aCarry, 21U)) + aNonceWordP) + aPhaseDWandererUpdateSaltC[((aIndex + 4U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((((RotL64(aCross, 39U) + RotL64(aOrbiterI, 13U)) + aOrbiterF) + aNonceWordE) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 56U) + aOrbiterE) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterE, 53U));
            aWandererH = aWandererH + ((RotL64(aIngress, 11U) + RotL64(aOrbiterK, 19U)) + aOrbiterF);
            aWandererC = aWandererC ^ ((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterE, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 28U));
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 53U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 13092U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 14051U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 14604U)) & S_BLOCK1], 44U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 11197U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((aIndex + 11989U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 37U)) ^ (RotL64(aIngress, 51U) ^ RotL64(aCross, 18U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterB = (((aWandererC + RotL64(aScatter, 37U)) + RotL64(aCarry, 51U)) + 15036852811491820366U) + aPhaseDOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = ((aWandererG + RotL64(aCross, 30U)) + RotL64(aCarry, 29U)) + 305637140752898475U;
            aOrbiterC = (((aWandererI + RotL64(aPrevious, 3U)) + 11948631574496129610U) + aPhaseDOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1]) + aNonceWordB;
            aOrbiterI = (((aWandererA + RotL64(aIngress, 19U)) + RotL64(aCarry, 13U)) + 5321623592482991426U) + aNonceWordE;
            aOrbiterG = ((aWandererF + RotL64(aCross, 51U)) + 4075270159062690728U) + aNonceWordC;
            aOrbiterK = (aWandererB + RotL64(aPrevious, 11U)) + 15111580500356908928U;
            aOrbiterF = (aWandererK + RotL64(aScatter, 43U)) + 7244150695504160363U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 5131563519577488862U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 5881954992088651371U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2424421828597294607U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 12780935808751507998U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 12599159643925470226U;
            aOrbiterK = RotL64((aOrbiterK * 17690046932587062701U), 27U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterB) + 9466589929741834066U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordN;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 6093158735705189789U;
            aOrbiterE = RotL64((aOrbiterE * 7453778295800853653U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 17461243886150519249U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 15456408913739900718U;
            aOrbiterB = RotL64((aOrbiterB * 16093292401746174671U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 11260643903290392780U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 7870342756041882616U;
            aOrbiterG = RotL64((aOrbiterG * 2431528656086173419U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 134484990005888936U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 10626896209992890407U;
            aOrbiterF = RotL64((aOrbiterF * 12034131076645285597U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 14031164129515132292U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 1771835705730244212U) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 186981668443596623U), 53U);
            //
            aIngress = RotL64(aOrbiterK, 37U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterC, 58U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterE, 19U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 21U) + RotL64(aOrbiterF, 21U)) + aOrbiterE) + RotL64(aCarry, 29U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterC, 3U)) + aNonceWordA);
            aWandererA = aWandererA + (((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 57U)) + aOrbiterG) + aNonceWordD);
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 29U)) + aOrbiterC) + aNonceWordH) + aPhaseDWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 5U) + aOrbiterF) + RotL64(aOrbiterG, 43U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 52U) + RotL64(aOrbiterB, 35U)) + aOrbiterG);
            aWandererG = aWandererG + (((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterF, 14U)) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 38U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + RotL64(aWandererG, 27U);
            aCarry = aCarry + RotL64(aIngress, 48U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 17742U)) & S_BLOCK1], 41U) ^ RotL64(aSnowLaneA[((aIndex + 21577U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 17996U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 16594U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((aIndex + 16386U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 26U)) ^ (RotL64(aCarry, 39U) + RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterD = ((((aWandererG + RotL64(aIngress, 27U)) + RotL64(aCarry, 27U)) + 6771552164800695068U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordI;
            aOrbiterJ = (aWandererA + RotL64(aScatter, 35U)) + 12131763371571322040U;
            aOrbiterK = (aWandererE + RotL64(aCross, 53U)) + 3326182381395522013U;
            aOrbiterB = (((aWandererC + RotL64(aPrevious, 3U)) + RotL64(aCarry, 47U)) + 12288775097697156383U) + aPhaseDOrbiterAssignSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aCross, 20U)) + RotL64(aCarry, 3U)) + 5195948373449796741U;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 41U)) + 14404044002250137144U) + aNonceWordM;
            aOrbiterG = (aWandererD + RotL64(aScatter, 47U)) + 11142382920035825426U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 2967149520256475485U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 1470907369577818097U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9398653295177725883U), 11U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterB) + 9231668148004163910U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordP;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 13078929163913892386U;
            aOrbiterH = RotL64((aOrbiterH * 7509829068700523627U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 9485274692075657877U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 12216951187543631673U;
            aOrbiterG = RotL64((aOrbiterG * 6571066246507310805U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 6933334652581744234U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 17260276102423580920U) ^ aNonceWordF;
            aOrbiterD = RotL64((aOrbiterD * 7796879893790990605U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 387767848169714392U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 8597538259308082638U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4888054690557707241U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 7996708724489146033U) + aNonceWordH;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 15357384191688149939U;
            aOrbiterJ = RotL64((aOrbiterJ * 9827691726832491373U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 17739222908739454637U) + aNonceWordG;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 1614322333281471170U;
            aOrbiterB = RotL64((aOrbiterB * 7063116837752240891U), 43U);
            //
            aIngress = RotL64(aOrbiterG, 57U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterK, 40U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterH, 23U)) + aOrbiterC) + aPhaseDWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 11U) + aOrbiterH) + RotL64(aOrbiterD, 37U)) + aNonceWordC);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterB, 3U)) + aOrbiterK);
            aWandererD = aWandererD + (((((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 11U)) + aOrbiterK) + RotL64(aCarry, 27U)) + aNonceWordB) + aPhaseDWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 47U)) + aOrbiterC) + aNonceWordN);
            aWandererG = aWandererG + ((((RotL64(aScatter, 21U) + RotL64(aOrbiterG, 57U)) + aOrbiterH) + RotL64(aCarry, 43U)) + aNonceWordJ);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 40U) + aOrbiterK) + RotL64(aOrbiterJ, 30U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 4U));
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 25565U)) & S_BLOCK1], 35U) ^ RotL64(aSnowLaneB[((aIndex + 26251U)) & S_BLOCK1], 18U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 24318U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 24313U)) & S_BLOCK1], 29U) ^ RotL64(aSnowLaneA[((aIndex + 23700U)) & S_BLOCK1], 40U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 22U) ^ RotL64(aCarry, 39U)) + (RotL64(aPrevious, 3U) + RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterK = ((((aWandererB + RotL64(aPrevious, 39U)) + RotL64(aCarry, 53U)) + 1393781663398437180U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordI;
            aOrbiterI = (aWandererK + RotL64(aScatter, 19U)) + 17414594746688585273U;
            aOrbiterE = (aWandererD + RotL64(aCross, 29U)) + 2823888497053071250U;
            aOrbiterA = (aWandererH + RotL64(aIngress, 3U)) + 17032631958617884859U;
            aOrbiterC = (((aWandererF + RotL64(aScatter, 47U)) + RotL64(aCarry, 37U)) + 15222697630461125019U) + aPhaseDOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aCross, 10U)) + 15737414920751551780U) + aNonceWordP;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 57U)) + RotL64(aCarry, 13U)) + 1357196111055783001U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 5315122321649251691U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 7893744655508595974U) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 17863000246694319149U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 16721939414324611738U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 3444375866323610848U;
            aOrbiterI = RotL64((aOrbiterI * 10874157227815775661U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 1825716513674511632U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 15582066843912467318U;
            aOrbiterD = RotL64((aOrbiterD * 12765146555943757373U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 15673590949193923915U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 13887365046280406413U;
            aOrbiterC = RotL64((aOrbiterC * 3169061375011420121U), 57U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterK) + 12730414371734709356U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1]) + aNonceWordG;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 4819112390640821927U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8782547948627685451U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 3089925954422937464U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 7180179304678622530U;
            aOrbiterK = RotL64((aOrbiterK * 16118051565147747413U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 17030269962085008657U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 6675917351883004046U;
            aOrbiterA = RotL64((aOrbiterA * 14134335325316949687U), 11U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterC, 57U);
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterE, 23U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 35U)) + aOrbiterE) + aPhaseDWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 21U) + RotL64(aOrbiterA, 53U)) + aOrbiterK) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 5U)) + aOrbiterI) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 27U) + aOrbiterD) + RotL64(aOrbiterA, 27U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterE, 60U)) + aNonceWordE);
            aWandererB = aWandererB + ((((RotL64(aIngress, 51U) + aOrbiterC) + RotL64(aOrbiterA, 41U)) + RotL64(aCarry, 11U)) + aNonceWordK);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 36U) + aOrbiterA) + RotL64(aOrbiterI, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 42U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + RotL64(aWandererD, 29U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 28327U)) & S_BLOCK1], 13U) ^ RotL64(aInvestLaneA[((aIndex + 30135U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 31724U)) & S_BLOCK1], 52U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 29125U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28908U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 56U) ^ RotL64(aCarry, 29U)) + (RotL64(aPrevious, 41U) + RotL64(aCross, 13U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterE = ((aWandererA + RotL64(aIngress, 34U)) + RotL64(aCarry, 5U)) + 18191288703716505885U;
            aOrbiterC = (((aWandererF + RotL64(aScatter, 53U)) + 9824014524910417136U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordH;
            aOrbiterB = (((aWandererB + RotL64(aCross, 19U)) + RotL64(aCarry, 21U)) + 11953012029254917548U) + aNonceWordN;
            aOrbiterG = (((aWandererE + RotL64(aPrevious, 11U)) + RotL64(aCarry, 51U)) + 6297568011027199089U) + aNonceWordG;
            aOrbiterK = (((aWandererJ + RotL64(aScatter, 3U)) + 2576999400457367975U) + aPhaseDOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1]) + aNonceWordF;
            aOrbiterJ = (aWandererD + RotL64(aIngress, 43U)) + 13176139160575558254U;
            aOrbiterF = (aWandererI + RotL64(aPrevious, 27U)) + 9978408174563621810U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 16765834875061607142U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 16534507305459121344U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8943988574248229067U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 3114710944346151807U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 10240517868726718592U) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 4645691562915606463U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 10721450637990777883U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 16689590768796583952U;
            aOrbiterE = RotL64((aOrbiterE * 3046344179729901637U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 2427422768928450209U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 13495584061816457831U;
            aOrbiterG = RotL64((aOrbiterG * 6670984773768885119U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 7058636403765106682U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 9897341853944713767U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14286816859999869231U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 17749559755733386064U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 12515645083926326659U;
            aOrbiterC = RotL64((aOrbiterC * 6582878478865838245U), 19U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterF) + 2625692458813609962U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1]) + aNonceWordD;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 10596240255026143019U;
            aOrbiterJ = RotL64((aOrbiterJ * 11605800195771080135U), 41U);
            //
            aIngress = RotL64(aOrbiterE, 5U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + RotL64(aOrbiterG, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aCross, 29U) + aOrbiterJ) + RotL64(aOrbiterB, 23U)) + aNonceWordJ) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterK, 30U)) + aOrbiterJ);
            aWandererA = aWandererA + (((RotL64(aIngress, 12U) + RotL64(aOrbiterK, 37U)) + aOrbiterC) + aNonceWordB);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 37U) + aOrbiterJ) + RotL64(aOrbiterG, 47U));
            aWandererE = aWandererE + (((RotL64(aScatter, 53U) + aOrbiterB) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 11U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterF, 11U)) + aOrbiterC);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 5U)) + aOrbiterE) + RotL64(aCarry, 51U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 30U));
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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

void TwistExpander_VolleyBall_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xDE5FC3C9BD4DC1B9ULL + 0xDC2BDE9BCF548A58ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xB73F67B6DF7C3943ULL + 0xCB86E9B89F922F66ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xA5F55C11758E6959ULL + 0x8E8BBAEFA5EA463AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xE2DB4911D37609E3ULL + 0xB95D92CF218810EDULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xAF57BD7E6740102DULL + 0xE0064B94A1734003ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xC813462BD42A83A1ULL + 0xE2604CC4958B4072ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xBDF2DB6E852589CFULL + 0x8F106786F5AFF23EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xDFD1A78111450CBBULL + 0xBC9F94FE6D234733ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x905E1C36059B3713ULL + 0xAF97444AFED4F6AEULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xB958E617AC56EE99ULL + 0xBD42183158D7DD94ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xD2163C4E8431170DULL + 0xBD584731BFDC98E1ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xC76491D4B37977C1ULL + 0xD533D062508B9EABULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xB65829031BE03CF9ULL + 0xC12A13B3B26A4BCAULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xA29A65247479534BULL + 0xBD69F88664E1E5E4ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x9EE58D225ECFF679ULL + 0xD7F1A22D4446A7B1ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xFC9AD8067CE58E2DULL + 0xC263E19C864B85DAULL);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 3726U)) & S_BLOCK1], 19U) ^ RotL64(aInvestLaneB[((aIndex + 581U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 1050U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 5183U)) & S_BLOCK1], 57U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 1190U)) & S_BLOCK1], 14U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 1262U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCross, 42U)) + (RotL64(aCarry, 11U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterG = ((aWandererI + RotL64(aScatter, 11U)) + 4384716820085860551U) + aNonceWordO;
            aOrbiterB = ((aWandererG + RotL64(aCross, 27U)) + 9715780315942116888U) + aNonceWordD;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 47U)) + 15963520052789178632U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 35U)) + RotL64(aCarry, 13U)) + 14346700690686392938U;
            aOrbiterE = ((aWandererH + RotL64(aCross, 57U)) + RotL64(aCarry, 35U)) + 6005518012489966643U;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 40U)) + 2506732930310252119U) + aNonceWordM;
            aOrbiterA = (aWandererB + RotL64(aScatter, 51U)) + 16782163084851775826U;
            aOrbiterF = (((aWandererF + RotL64(aPrevious, 23U)) + 823673076571076303U) + aPhaseEOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1]) + aNonceWordL;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 43U)) + RotL64(aCarry, 57U)) + 1634084509064077736U;
            aOrbiterC = (aWandererA + RotL64(aCross, 14U)) + 1288134975466877686U;
            aOrbiterJ = (aWandererD + RotL64(aIngress, 19U)) + 2998220403162908444U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 220430672180734911U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 10223923547068528867U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12577370238343872139U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 11696469696177647608U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 6545430420379636963U;
            aOrbiterK = RotL64((aOrbiterK * 8387163146257553773U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 79691451831797107U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 8971444023498649419U;
            aOrbiterF = RotL64((aOrbiterF * 7148919880477390009U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 5624403902454498793U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 9468064161002030997U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8243560528100864595U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 4619361544913629805U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 12682446273369750704U;
            aOrbiterI = RotL64((aOrbiterI * 10879074713156075641U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 8728730962617599223U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 9099675924074253030U) ^ aNonceWordI;
            aOrbiterC = RotL64((aOrbiterC * 5525644236954497523U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 3298303921318288541U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 5953276499411658358U;
            aOrbiterH = RotL64((aOrbiterH * 10565471305001292693U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 6725769507592688539U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 1057277456510215817U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8269412198279297075U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 11317925732206917722U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 17814749417006079067U) ^ aNonceWordJ;
            aOrbiterE = RotL64((aOrbiterE * 4369209051015735925U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 9258362135343403308U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterJ) ^ 4873837345446960113U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterG = RotL64((aOrbiterG * 14223381466269503273U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 7863380865835889675U) + aNonceWordK;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 4384716820085860551U;
            aOrbiterJ = RotL64((aOrbiterJ * 2003891033298374621U), 5U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterD, 10U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterK, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 35U) + aOrbiterA) + RotL64(aOrbiterJ, 11U));
            aWandererG = aWandererG + (((RotL64(aCross, 27U) + aOrbiterD) + RotL64(aOrbiterF, 58U)) + RotL64(aCarry, 21U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterF, 47U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 37U) + aOrbiterH) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 5U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterJ, 29U)) + aOrbiterB) + aPhaseEWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 14U) + aOrbiterG) + RotL64(aOrbiterK, 53U)) + aNonceWordA);
            aWandererD = aWandererD ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterI, 44U)) + aOrbiterK);
            aWandererI = aWandererI + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 27U)) + aOrbiterJ);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterH, 19U));
            aWandererH = aWandererH + (((RotL64(aScatter, 60U) + RotL64(aOrbiterA, 35U)) + aOrbiterH) + aNonceWordH);
            aWandererK = aWandererK ^ (((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterJ, 39U)) + aNonceWordB);
            //
            aCarry = aCarry + (RotL64(aWandererF, 28U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererD, 39U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aFireLaneA[((aIndex + 6925U)) & S_BLOCK1], 39U) ^ RotL64(aInvestLaneC[((aIndex + 5695U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 10232U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((aIndex + 10497U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 6711U)) & S_BLOCK1], 11U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 10676U)) & S_BLOCK1], 38U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 8907U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aIngress, 26U)) + (RotL64(aCross, 39U) ^ RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterK = ((aWandererG + RotL64(aIngress, 41U)) + 13204735390996728477U) + aNonceWordP;
            aOrbiterG = ((aWandererF + RotL64(aScatter, 26U)) + 851171359595647173U) + aNonceWordJ;
            aOrbiterC = (aWandererH + RotL64(aCross, 11U)) + 16745304202825290723U;
            aOrbiterH = (aWandererI + RotL64(aPrevious, 29U)) + 562392736584913979U;
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 37U)) + RotL64(aCarry, 41U)) + 3244267012529053918U;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 47U)) + 17282536111067869133U) + aNonceWordM;
            aOrbiterI = ((aWandererK + RotL64(aCross, 43U)) + RotL64(aCarry, 37U)) + 14851130066471729068U;
            aOrbiterB = (((aWandererC + RotL64(aScatter, 34U)) + RotL64(aCarry, 23U)) + 5256130407952363129U) + aPhaseEOrbiterAssignSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aIngress, 39U)) + 2904742485828362001U;
            aOrbiterE = (aWandererJ + RotL64(aScatter, 21U)) + 3723346325449225387U;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 53U)) + 5344621093694027341U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 12919263300833603026U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 17989801264160996071U;
            aOrbiterC = RotL64((aOrbiterC * 15468293047311883751U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 5022175042377172157U) + aNonceWordI;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 16684822380107847758U) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 2834049270263837537U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 2740326510600876682U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 13981423865219318820U;
            aOrbiterG = RotL64((aOrbiterG * 14593082145080056441U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 231945878229848395U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 14139797734944312580U) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 6492256080432266407U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 16704102101387552373U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 8506734780526852552U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4684566118627414659U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 2774630043988894695U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 12490034334296488127U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16765455396278233145U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 545238171291436006U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 1023872898002379590U) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 8626333831510136515U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 5065187021047872560U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 10391809965648089863U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10912471108849550469U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 5576919045471579002U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 9761904001375034639U;
            aOrbiterI = RotL64((aOrbiterI * 8612901811320541361U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 2001472279505185946U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 11576457012366242134U;
            aOrbiterK = RotL64((aOrbiterK * 1070815118051466731U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 17713147845216099336U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 13204735390996728477U;
            aOrbiterE = RotL64((aOrbiterE * 10889281795183444943U), 21U);
            //
            aIngress = RotL64(aOrbiterI, 3U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + (RotL64(aOrbiterH, 21U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterE, 50U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + RotL64(aOrbiterB, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 57U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 51U)) + aOrbiterD);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 27U) + aOrbiterG) + RotL64(aOrbiterI, 39U));
            aWandererI = aWandererI + (((RotL64(aCross, 60U) + RotL64(aOrbiterF, 35U)) + aOrbiterK) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterI, 26U)) + aOrbiterK);
            aWandererK = aWandererK + (((((RotL64(aScatter, 11U) + aOrbiterH) + RotL64(aOrbiterK, 21U)) + RotL64(aCarry, 3U)) + aNonceWordH) + aPhaseEWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 39U) + aOrbiterH) + RotL64(aOrbiterA, 37U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 37U) + aOrbiterD) + RotL64(aOrbiterB, 53U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 51U) + aOrbiterJ) + RotL64(aOrbiterC, 60U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterB, 29U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 4U) + RotL64(aOrbiterA, 47U)) + aOrbiterK) + aNonceWordB);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 10U));
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 46U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 11110U)) & S_BLOCK1], 27U) ^ RotL64(aInvestLaneA[((aIndex + 12959U)) & S_BLOCK1], 14U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 13728U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 12523U)) & S_BLOCK1], 27U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 13632U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 50U) + RotL64(aPrevious, 11U)) + (RotL64(aCarry, 23U) ^ RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterA = ((aWandererB + RotL64(aIngress, 27U)) + 6771552164800695068U) + aNonceWordG;
            aOrbiterB = (aWandererF + RotL64(aCross, 21U)) + 12131763371571322040U;
            aOrbiterK = (((aWandererE + RotL64(aPrevious, 42U)) + 3326182381395522013U) + aPhaseEOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1]) + aNonceWordD;
            aOrbiterH = (((aWandererA + RotL64(aScatter, 11U)) + RotL64(aCarry, 47U)) + 12288775097697156383U) + aNonceWordO;
            aOrbiterE = ((aWandererD + RotL64(aCross, 13U)) + 5195948373449796741U) + aPhaseEOrbiterAssignSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = (((aWandererI + RotL64(aPrevious, 3U)) + RotL64(aCarry, 13U)) + 14404044002250137144U) + aNonceWordF;
            aOrbiterC = (aWandererC + RotL64(aScatter, 47U)) + 11142382920035825426U;
            aOrbiterF = ((aWandererH + RotL64(aIngress, 23U)) + RotL64(aCarry, 19U)) + 2967149520256475485U;
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 60U)) + 1470907369577818097U;
            aOrbiterI = (aWandererK + RotL64(aCross, 35U)) + 9231668148004163910U;
            aOrbiterD = (aWandererJ + RotL64(aIngress, 37U)) + 13078929163913892386U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 9485274692075657877U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 12216951187543631673U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6571066246507310805U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 6933334652581744234U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 17260276102423580920U;
            aOrbiterE = RotL64((aOrbiterE * 7796879893790990605U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 387767848169714392U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 8597538259308082638U;
            aOrbiterA = RotL64((aOrbiterA * 4888054690557707241U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 7996708724489146033U) + aNonceWordB;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 15357384191688149939U;
            aOrbiterF = RotL64((aOrbiterF * 9827691726832491373U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 17739222908739454637U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 1614322333281471170U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7063116837752240891U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 4531604274893197209U) + aNonceWordA;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 3453280714992341288U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8390029711127907805U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 116623650872661533U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 6565636510115095988U;
            aOrbiterC = RotL64((aOrbiterC * 9691897067492501177U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 10303258439817808058U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 10917642773040237611U;
            aOrbiterB = RotL64((aOrbiterB * 10232856828372963363U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 2087058228468680821U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 3691125545393861889U;
            aOrbiterG = RotL64((aOrbiterG * 1768745056298937903U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 9240209357066002219U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 7645250700232422804U) ^ aNonceWordI;
            aOrbiterJ = RotL64((aOrbiterJ * 6762116797395687607U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 9859862257084218280U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 6771552164800695068U;
            aOrbiterH = RotL64((aOrbiterH * 11063630807191661109U), 3U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterI, 35U);
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + (RotL64(aOrbiterE, 48U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aCross, 57U) + aOrbiterF) + RotL64(aOrbiterA, 35U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 30U) + RotL64(aOrbiterG, 3U)) + aOrbiterH) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 40U)) + aOrbiterC);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 13U)) + aOrbiterH) + aPhaseEWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 41U) + aOrbiterB) + RotL64(aOrbiterF, 57U)) + aNonceWordN);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterA, 37U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 39U) + aOrbiterJ) + RotL64(aOrbiterI, 52U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterI, 27U)) + aOrbiterD) + aNonceWordP);
            aWandererF = aWandererF + (((RotL64(aScatter, 47U) + aOrbiterB) + RotL64(aOrbiterI, 43U)) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 27U) + aOrbiterK) + RotL64(aOrbiterG, 29U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 50U) + aOrbiterC) + RotL64(aOrbiterK, 5U)) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 60U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 41U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 50U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 20194U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneA[((aIndex + 17570U)) & S_BLOCK1], 44U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 17365U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 16502U)) & S_BLOCK1], 11U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 18638U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aPrevious, 37U)) + (RotL64(aCross, 5U) ^ RotL64(aIngress, 20U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterB = (aWandererB + RotL64(aPrevious, 37U)) + 14823268998003220191U;
            aOrbiterG = ((aWandererE + RotL64(aCross, 19U)) + 15295237288788213847U) + aNonceWordJ;
            aOrbiterH = (aWandererF + RotL64(aIngress, 51U)) + 16434853402001133899U;
            aOrbiterF = (aWandererD + RotL64(aScatter, 22U)) + 7555911304407871631U;
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 35U)) + 14977248264994834620U) + aPhaseEOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = ((((aWandererK + RotL64(aCross, 13U)) + RotL64(aCarry, 35U)) + 9707764144919392380U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordD;
            aOrbiterE = ((aWandererI + RotL64(aScatter, 47U)) + RotL64(aCarry, 53U)) + 1277304385464681529U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 39U)) + 3089786220465849395U) + aNonceWordG;
            aOrbiterC = (aWandererJ + RotL64(aCross, 10U)) + 3700503853358695085U;
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 3U)) + RotL64(aCarry, 57U)) + 3240054112993517371U;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 57U)) + 16897532076915366859U) + aNonceWordL;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 18167359289798364307U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 8870819278575769863U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9334066154398059075U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 15363069206212330251U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 14858164441499725158U;
            aOrbiterJ = RotL64((aOrbiterJ * 14931933411393847915U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 5357144808788707522U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 2910681277417754860U;
            aOrbiterK = RotL64((aOrbiterK * 13170868582159347059U), 43U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterJ) + 9824408699018165151U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1]) + aNonceWordA;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 368370224788793300U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14358982366258729959U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 7095398304588825115U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 11418879758164313554U;
            aOrbiterI = RotL64((aOrbiterI * 5983520332639771791U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 2171599720681913272U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 17593730219647495033U;
            aOrbiterG = RotL64((aOrbiterG * 12926053208918563087U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 17755947635188715523U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 14565740605227022106U;
            aOrbiterE = RotL64((aOrbiterE * 15866418354612945335U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 14538017880915584414U) + aNonceWordN;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 6174566474851449123U;
            aOrbiterB = RotL64((aOrbiterB * 179569008593475683U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 3806438394748643441U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 13737114463856719285U;
            aOrbiterA = RotL64((aOrbiterA * 13439346068497710151U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 3698379331577470045U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 1097081284062708554U;
            aOrbiterD = RotL64((aOrbiterD * 3498627643013255777U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 215117138867597766U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 14823268998003220191U;
            aOrbiterF = RotL64((aOrbiterF * 12131828437975771377U), 41U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterF, 5U);
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 21U));
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 37U) + aOrbiterG) + RotL64(aOrbiterD, 42U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 27U) + aOrbiterE) + RotL64(aOrbiterA, 23U)) + RotL64(aCarry, 41U)) + aNonceWordH);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 29U) + aOrbiterI) + RotL64(aOrbiterE, 5U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterJ, 13U)) + aOrbiterH);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 11U)) + aOrbiterF);
            aWandererB = aWandererB + ((((RotL64(aIngress, 46U) + aOrbiterA) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 3U)) + aPhaseEWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 53U) + aOrbiterA) + RotL64(aOrbiterI, 58U)) + aNonceWordE);
            aWandererG = aWandererG + (((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterI, 29U)) + aPhaseEWandererUpdateSaltB[((aIndex + 16U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterK, 51U));
            aWandererH = aWandererH + ((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 19U)) + aOrbiterD);
            aWandererE = aWandererE ^ (((RotL64(aCross, 20U) + aOrbiterC) + RotL64(aOrbiterF, 35U)) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererD, 60U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (RotL64(aWandererC, 30U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererJ, 13U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 21890U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneB[((aIndex + 25645U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 25842U)) & S_BLOCK1], 6U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25422U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 26921U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 24521U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aIngress, 39U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCross, 24U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterC = (aWandererF + RotL64(aCross, 21U)) + 3973833383430652211U;
            aOrbiterE = (aWandererH + RotL64(aPrevious, 13U)) + 5760227042747169187U;
            aOrbiterF = (((aWandererE + RotL64(aIngress, 18U)) + 4923009065139227286U) + aPhaseEOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1]) + aNonceWordD;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 35U)) + RotL64(aCarry, 47U)) + 1477807307009107590U;
            aOrbiterA = (((aWandererG + RotL64(aPrevious, 47U)) + RotL64(aCarry, 21U)) + 5707194514329007301U) + aNonceWordE;
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 27U)) + 5340439728375269724U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = (((aWandererB + RotL64(aIngress, 29U)) + RotL64(aCarry, 53U)) + 17080457898946572387U) + aNonceWordA;
            aOrbiterI = (aWandererI + RotL64(aCross, 53U)) + 281559150259472813U;
            aOrbiterD = (aWandererC + RotL64(aScatter, 43U)) + 16160633048230910560U;
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 24U)) + 9003989610509592121U;
            aOrbiterK = ((aWandererA + RotL64(aIngress, 5U)) + 10579322462808454333U) + aNonceWordF;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 15059383289528723069U) + aNonceWordC;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 10417647757852880956U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1457919230286043137U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 14484665027393813330U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 12344463053485837974U;
            aOrbiterJ = RotL64((aOrbiterJ * 5762654194001525041U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 5826453246659297805U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 12547902286376986223U) ^ aNonceWordG;
            aOrbiterI = RotL64((aOrbiterI * 2982850000322672789U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 9637855144278126174U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 2132744427444501938U;
            aOrbiterD = RotL64((aOrbiterD * 5911587798564836199U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 9248933938130311231U) + aNonceWordP;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 13274297928717090383U) ^ aNonceWordJ;
            aOrbiterB = RotL64((aOrbiterB * 2901398809555237563U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 3690262236918560930U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 3626005326410800344U;
            aOrbiterA = RotL64((aOrbiterA * 13030443356669355355U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 10801089744186148218U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 5446653082176311031U;
            aOrbiterE = RotL64((aOrbiterE * 4594267575901248321U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 3205541585889107366U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 4532327942368884436U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16287094987689326229U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 9755333481079721632U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 722154154363571049U;
            aOrbiterK = RotL64((aOrbiterK * 11002432494248958957U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 8071668483354405205U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 8770466248803121315U;
            aOrbiterC = RotL64((aOrbiterC * 12780438190628717807U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 1999251593502332271U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 3973833383430652211U;
            aOrbiterH = RotL64((aOrbiterH * 5325244982474631559U), 35U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterC, 58U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 39U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 30U));
            aIngress = aIngress + RotL64(aOrbiterB, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterH, 6U)) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 24U) + aOrbiterD) + RotL64(aOrbiterK, 3U)) + aNonceWordN);
            aWandererK = aWandererK + (((RotL64(aIngress, 39U) + RotL64(aOrbiterJ, 37U)) + aOrbiterB) + RotL64(aCarry, 37U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterC, 41U)) + aOrbiterD) + aPhaseEWandererUpdateSaltC[((aIndex + 12U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterK, 35U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 60U)) + aOrbiterA);
            aWandererD = aWandererD + (((RotL64(aIngress, 53U) + RotL64(aOrbiterF, 39U)) + aOrbiterI) + aPhaseEWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 42U) + aOrbiterJ) + RotL64(aOrbiterC, 53U));
            aWandererB = aWandererB + (((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterE, 27U)) + aNonceWordM);
            aWandererC = aWandererC ^ ((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterH, 19U));
            aWandererA = aWandererA + ((RotL64(aIngress, 19U) + aOrbiterK) + RotL64(aOrbiterJ, 13U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 50U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 39U);
            aCarry = aCarry + RotL64(aIngress, 48U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 31391U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((aIndex + 30585U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 30871U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27794U)) & S_BLOCK1], 51U) ^ RotL64(aInvestLaneB[((aIndex + 30310U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 56U) ^ RotL64(aCross, 23U)) + (RotL64(aPrevious, 11U) ^ RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterD = (aWandererD + RotL64(aCross, 53U)) + 11700815697312060726U;
            aOrbiterK = (aWandererK + RotL64(aIngress, 5U)) + 11808423452327465441U;
            aOrbiterC = (aWandererH + RotL64(aScatter, 27U)) + 8670503858631730886U;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 50U)) + 2400061067991988544U) + aNonceWordC;
            aOrbiterE = ((((aWandererE + RotL64(aScatter, 43U)) + RotL64(aCarry, 43U)) + 16163118178366229686U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordL;
            aOrbiterG = (((aWandererB + RotL64(aCross, 39U)) + RotL64(aCarry, 19U)) + 3280178595904941068U) + aNonceWordN;
            aOrbiterF = (aWandererG + RotL64(aIngress, 13U)) + 3298683600817047727U;
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 19U)) + 16321624053445183574U) + aPhaseEOrbiterAssignSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aIngress, 47U)) + RotL64(aCarry, 3U)) + 6730229877611375225U;
            aOrbiterJ = (aWandererC + RotL64(aCross, 30U)) + 10162830636713641322U;
            aOrbiterI = (aWandererA + RotL64(aScatter, 11U)) + 15646771327759599256U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 14841751262270544102U) + aNonceWordA;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 9545541117228834895U;
            aOrbiterC = RotL64((aOrbiterC * 11529769874752969377U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 14676615635857599982U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 1231768638470558855U;
            aOrbiterG = RotL64((aOrbiterG * 2716808508509014677U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 1945905595345404833U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 1406171421638586846U;
            aOrbiterD = RotL64((aOrbiterD * 4577864352425476233U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 1970292335806697198U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 12309719390375013297U;
            aOrbiterH = RotL64((aOrbiterH * 16540660957923687327U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 5352135521358954576U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 15465675376193501658U;
            aOrbiterB = RotL64((aOrbiterB * 16385761112921041387U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 2842123638916600369U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 3544764287036748668U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3360772950777850115U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 6038297172906492282U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 10249342332287140970U;
            aOrbiterF = RotL64((aOrbiterF * 16701083081566042277U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 1662076777040529446U) + aNonceWordH;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 1949705569959740274U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11340691546658994529U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 13934194245417822360U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 5720408806425535958U;
            aOrbiterK = RotL64((aOrbiterK * 15237561081637415383U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 2209251362417210658U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 4917447930929521699U;
            aOrbiterE = RotL64((aOrbiterE * 17489570156694692569U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 14817115766683623486U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 11700815697312060726U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16982411053956669181U), 41U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterC, 19U);
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 38U));
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 21U) + aOrbiterF) + RotL64(aOrbiterK, 4U)) + aNonceWordG);
            aWandererI = aWandererI + (((RotL64(aPrevious, 38U) + aOrbiterJ) + RotL64(aOrbiterF, 23U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 35U) + aOrbiterA) + RotL64(aOrbiterJ, 43U));
            aWandererB = aWandererB + (((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 29U)) + aOrbiterF) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 53U)) + aOrbiterC) + aNonceWordB);
            aWandererF = aWandererF + ((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterD, 57U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterJ, 41U)) + aOrbiterH);
            aWandererD = aWandererD + ((((RotL64(aCross, 53U) + aOrbiterB) + RotL64(aOrbiterF, 35U)) + RotL64(aCarry, 11U)) + aPhaseEWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 21U)) + aOrbiterI);
            aWandererJ = aWandererJ + (((RotL64(aCross, 57U) + RotL64(aOrbiterG, 38U)) + aOrbiterI) + aNonceWordE);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 50U) + aOrbiterB) + RotL64(aOrbiterG, 47U)) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 50U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 20U));
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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

void TwistExpander_VolleyBall_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xC7BFF06EC1544843ULL + 0xF59746338A5AD648ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xF749C4530E8668BFULL + 0xFAA93741701EA1B6ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x99720673402CA85BULL + 0xF2484713D3563A2BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xBF5AD478E6C16A23ULL + 0xE27650A63B73CAF4ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xB1BBE20889855D99ULL + 0xD6A92B86E573EBECULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x8BD4B481DB4876DFULL + 0xFE4FA23EBD3C9E0AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xA77368302D0921B1ULL + 0xF706491232013435ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xB2CF5553F3904071ULL + 0xE4F8883A049E20D0ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xEDCB7D1420C6CBF3ULL + 0xFC69CC7C5711615FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xA0117A66E5B7E527ULL + 0x8F5E0FD9A9F0C172ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xFB9AEBCD83721A61ULL + 0x9D7F72AD6640251DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x9A9E7F515110EB9FULL + 0x8D7CE4731AC96CE1ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xBC4C9905973336A5ULL + 0xFE99E686BFECB7F3ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x9D1FF8960A4C2D59ULL + 0xC3E3DD20E4E3960DULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xC0212B6BC1D15637ULL + 0xDA1C7FC22A7DB0BAULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xBE3063E4502FC56DULL + 0x92F5D6CBD952A5BDULL);
    // GSeedRunSeed_F seed_loop_f (start)
    {
        // GSeedRunSeed_F seed_loop_f lane group
        // read from: aOperationLaneA, aOperationLaneB, aInvestLaneD, aOperationLaneC, aOperationLaneD, aInvestLaneB, aSnowLaneC, aWorkLaneD, aWorkLaneC, aSnowLaneD, aSnowLaneA, aExpandLaneA, aInvestLaneA, aExpandLaneB, aSnowLaneB, aExpandLaneC, aInvestLaneC
        // write to: aSnowLaneC, aSnowLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_f loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aInvestLaneD
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aInvestLaneD forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aInvestLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aInvestLaneB backward/forward random
        // write to: aSnowLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 527U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneB[((aIndex + 1754U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aInvestLaneD[((aIndex + 3895U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 1717U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 3003U)) & S_BLOCK1], 6U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 4307U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 57U)) ^ (RotL64(aCarry, 27U) + RotL64(aIngress, 42U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 53U)) + RotL64(aCarry, 51U)) + 3105313968748067810U;
            aOrbiterH = (aWandererG + RotL64(aCross, 34U)) + 9977249451119627064U;
            aOrbiterE = (((aWandererC + RotL64(aPrevious, 19U)) + 17941392803495349366U) + aPhaseFOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1]) + aNonceWordE;
            aOrbiterI = (aWandererH + RotL64(aScatter, 23U)) + 4279533326705471133U;
            aOrbiterA = ((aWandererF + RotL64(aCross, 27U)) + RotL64(aCarry, 41U)) + 13983828966811580039U;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 11U)) + 3983490984234810378U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aScatter, 3U)) + RotL64(aCarry, 13U)) + 308786542215259956U;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 58U)) + 8443607695364427037U) + aNonceWordA;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 41U)) + 14939626441464340668U) + aNonceWordC;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 9350693577306121110U) + aNonceWordK;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 1717071159396961752U;
            aOrbiterE = RotL64((aOrbiterE * 11062480662625054525U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 15911765265202100610U) + aNonceWordM;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 14898546272333182767U;
            aOrbiterA = RotL64((aOrbiterA * 2674900543810733067U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 3560903518513465868U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 5367062725726860234U;
            aOrbiterI = RotL64((aOrbiterI * 8521908836601319553U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 15233321480618877327U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 9288449812290126074U;
            aOrbiterF = RotL64((aOrbiterF * 6815298520404038519U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 5504840529511585676U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 6825598386801620046U) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 11666542445846250077U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 6433024450721339470U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 97934156644929458U;
            aOrbiterK = RotL64((aOrbiterK * 8630530773006923215U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 3260053604798744515U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 16539416623243059076U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12199577351166064503U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 9814290051339038920U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 13280156404507444041U;
            aOrbiterD = RotL64((aOrbiterD * 15269010043398910061U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 11853942590993546833U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 13207869904312989977U;
            aOrbiterB = RotL64((aOrbiterB * 15503461937625795969U), 3U);
            //
            aIngress = RotL64(aOrbiterG, 29U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterD, 24U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + RotL64(aOrbiterA, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 47U)) + aOrbiterH) + RotL64(aCarry, 27U)) + aPhaseFWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 29U) + aOrbiterE) + RotL64(aOrbiterA, 38U)) + aNonceWordO);
            aWandererF = aWandererF + (((RotL64(aCross, 60U) + RotL64(aOrbiterK, 23U)) + aOrbiterG) + aNonceWordH);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterH, 53U)) + aPhaseFWandererUpdateSaltD[((aIndex + 6U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 19U) + RotL64(aOrbiterI, 3U)) + aOrbiterG);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterB, 19U));
            aWandererG = aWandererG + ((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterK, 27U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 53U) + aOrbiterH) + RotL64(aOrbiterD, 60U)) + aNonceWordF);
            aWandererH = aWandererH + ((((RotL64(aCross, 42U) + RotL64(aOrbiterA, 13U)) + aOrbiterB) + RotL64(aCarry, 3U)) + aNonceWordG);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 18U));
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererC, 43U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aSnowLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 2
        // ingress from: aSnowLaneC, aOperationLaneC, aOperationLaneD, aWorkLaneD
        // ingress directions: aSnowLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aWorkLaneD forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aWorkLaneC
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aWorkLaneC backward/forward random
        // write to: aSnowLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneC[((aIndex + 6466U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((aIndex + 9595U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 9995U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneD[((aIndex + 7667U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 10471U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7708U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 7568U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 40U)) + (RotL64(aIngress, 27U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterG = (aWandererG + RotL64(aScatter, 51U)) + 11521331427196538632U;
            aOrbiterC = (aWandererB + RotL64(aIngress, 3U)) + 16653824187682957632U;
            aOrbiterI = (((aWandererI + RotL64(aCross, 18U)) + RotL64(aCarry, 57U)) + 11654676587350088289U) + aPhaseFOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = (((aWandererJ + RotL64(aPrevious, 57U)) + 8010313317412193584U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordB;
            aOrbiterJ = (aWandererE + RotL64(aScatter, 47U)) + 1108775560502907471U;
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 27U)) + 243952321439823521U) + aNonceWordD;
            aOrbiterE = ((aWandererD + RotL64(aIngress, 22U)) + RotL64(aCarry, 29U)) + 2324945800401240403U;
            aOrbiterA = (aWandererF + RotL64(aCross, 35U)) + 9257554497543369657U;
            aOrbiterD = (((aWandererH + RotL64(aPrevious, 11U)) + RotL64(aCarry, 41U)) + 16701314607244592540U) + aNonceWordM;
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 3900445848034341782U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 7652316487347103658U;
            aOrbiterI = RotL64((aOrbiterI * 11480123491361589799U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 14980368605272070578U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 2001165460948764796U;
            aOrbiterJ = RotL64((aOrbiterJ * 8110980921827107649U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 1911044015666991050U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 11366207111147818339U) ^ aNonceWordF;
            aOrbiterG = RotL64((aOrbiterG * 17234439040652553865U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 16469329744002456607U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 8062793687044950815U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5856142259851144369U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 15364721421972807872U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 8979915611483540231U) ^ aNonceWordI;
            aOrbiterD = RotL64((aOrbiterD * 10899377466171153383U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 7654234623563110457U) + aNonceWordL;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 1526832460342135008U;
            aOrbiterC = RotL64((aOrbiterC * 12766083052650723051U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 1596625448797520938U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 15723912914858523080U;
            aOrbiterK = RotL64((aOrbiterK * 6003857787643420337U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 7664226719746532168U) + aNonceWordG;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 13767298788411473401U;
            aOrbiterE = RotL64((aOrbiterE * 15663266144965532019U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 8371251860069346385U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 10143279934304029980U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12764966547132248131U), 35U);
            //
            aIngress = RotL64(aOrbiterJ, 35U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 24U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + RotL64(aOrbiterG, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aPrevious, 5U) + aOrbiterF) + RotL64(aOrbiterC, 43U)) + RotL64(aCarry, 53U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterK, 52U)) + aOrbiterD);
            aWandererI = aWandererI + ((RotL64(aScatter, 18U) + RotL64(aOrbiterJ, 57U)) + aOrbiterD);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterJ, 47U)) + aOrbiterK) + aNonceWordH);
            aWandererH = aWandererH + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 27U)) + aOrbiterA) + RotL64(aCarry, 39U)) + aNonceWordA);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 43U) + aOrbiterG) + RotL64(aOrbiterC, 4U));
            aWandererE = aWandererE + (((RotL64(aCross, 57U) + RotL64(aOrbiterE, 21U)) + aOrbiterG) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 24U) + aOrbiterF) + RotL64(aOrbiterK, 39U));
            aWandererA = aWandererA + ((RotL64(aScatter, 37U) + RotL64(aOrbiterI, 35U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 50U));
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aSnowLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 3
        // ingress from: aSnowLaneD, aOperationLaneA, aSnowLaneA
        // ingress directions: aSnowLaneD forward forced, aOperationLaneA forward forced, aSnowLaneA forward/backward random
        // cross from: aSnowLaneC, aOperationLaneC
        // cross directions: aSnowLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneD[((aIndex + 14267U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneA[((aIndex + 12623U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 16144U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 11849U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 12674U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 5U)) ^ (RotL64(aIngress, 19U) + RotL64(aCarry, 44U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterC = (aWandererE + RotL64(aIngress, 13U)) + 6243113109470883144U;
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 60U)) + 3891552123999605832U;
            aOrbiterF = (((aWandererK + RotL64(aScatter, 47U)) + 8758797898587019128U) + aPhaseFOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1]) + aNonceWordI;
            aOrbiterB = ((aWandererC + RotL64(aCross, 29U)) + RotL64(aCarry, 21U)) + 1005891374086408851U;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 53U)) + RotL64(aCarry, 3U)) + 3713426782180050764U;
            aOrbiterK = (aWandererA + RotL64(aIngress, 23U)) + 18358143862391573534U;
            aOrbiterE = ((aWandererB + RotL64(aCross, 36U)) + 17504394029693712404U) + aPhaseFOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (((aWandererF + RotL64(aPrevious, 19U)) + RotL64(aCarry, 35U)) + 5312729289027417014U) + aNonceWordF;
            aOrbiterG = (aWandererG + RotL64(aIngress, 43U)) + 2560873623431186029U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 16309322822806704211U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 10195513918020652600U;
            aOrbiterF = RotL64((aOrbiterF * 14569219741824123715U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 2552116263258744287U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 7732784879810980089U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15041929399477790999U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 16499127570665381507U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 10890036715535519036U;
            aOrbiterJ = RotL64((aOrbiterJ * 9065115450010475187U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 16288944603478791554U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 14542766121469312846U) ^ aNonceWordB;
            aOrbiterE = RotL64((aOrbiterE * 8435383464425875209U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 5973595239494084696U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 1820492719977197097U;
            aOrbiterB = RotL64((aOrbiterB * 16164917159141304405U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 10489529555776381736U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 6392552206958240484U) ^ aNonceWordG;
            aOrbiterG = RotL64((aOrbiterG * 11761477994533503307U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 10163241948999404556U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 16054678853554707148U;
            aOrbiterK = RotL64((aOrbiterK * 10570418210789350091U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 3606021702108590330U) + aNonceWordP;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 16920568417324295852U;
            aOrbiterD = RotL64((aOrbiterD * 5222656554577625385U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 13889995689147406315U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 7908387312354285092U;
            aOrbiterC = RotL64((aOrbiterC * 7995682580514280949U), 43U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterJ, 53U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 58U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterF, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aCross, 10U) + aOrbiterA) + RotL64(aOrbiterB, 19U)) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 23U) + aOrbiterG) + RotL64(aOrbiterE, 41U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 27U) + aOrbiterJ) + RotL64(aOrbiterG, 47U)) + aNonceWordD) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterA, 35U)) + aOrbiterD) + aNonceWordN);
            aWandererE = aWandererE + (((RotL64(aCross, 47U) + RotL64(aOrbiterF, 10U)) + aOrbiterA) + aNonceWordE);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 3U)) + aOrbiterG) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aScatter, 38U) + RotL64(aOrbiterK, 57U)) + aOrbiterB) + RotL64(aCarry, 11U)) + aNonceWordH);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 19U) + aOrbiterC) + RotL64(aOrbiterA, 51U));
            aWandererK = aWandererK + ((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterB, 14U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererG, 54U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 4
        // ingress from: aExpandLaneA, aSnowLaneC, aInvestLaneA
        // ingress directions: aExpandLaneA forward forced, aSnowLaneC forward forced, aInvestLaneA forward/backward random
        // cross from: aSnowLaneD, aOperationLaneD
        // cross directions: aSnowLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 18892U)) & S_BLOCK1], 47U) ^ RotL64(aSnowLaneC[((aIndex + 20290U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 17483U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 19368U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 16616U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aIngress, 23U)) + (RotL64(aPrevious, 40U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterG = (aWandererK + RotL64(aScatter, 58U)) + 8685374557928800912U;
            aOrbiterI = (((aWandererB + RotL64(aIngress, 53U)) + 3482312691892161229U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordA;
            aOrbiterA = (aWandererH + RotL64(aCross, 13U)) + 6948130297389161165U;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 19U)) + 5506385663788942690U) + aNonceWordI;
            aOrbiterK = ((((aWandererD + RotL64(aScatter, 39U)) + RotL64(aCarry, 11U)) + 17859982009307397161U) + aPhaseFOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1]) + aNonceWordO;
            aOrbiterH = (aWandererF + RotL64(aIngress, 29U)) + 9178488809207094043U;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 34U)) + RotL64(aCarry, 37U)) + 1835479501226057169U;
            aOrbiterF = (aWandererG + RotL64(aCross, 5U)) + 5368101733632614939U;
            aOrbiterC = ((aWandererC + RotL64(aIngress, 43U)) + RotL64(aCarry, 21U)) + 9050459666576835422U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 9042186993119635078U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 17528342580198295025U;
            aOrbiterA = RotL64((aOrbiterA * 14316671546614386775U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 6495418332558436882U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 8834495762667327342U) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 10783141541937645995U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 4364314196965690905U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 6357485231062120459U;
            aOrbiterD = RotL64((aOrbiterD * 289429584586504995U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 3321488322626415347U) + aNonceWordB;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 10817330671781848737U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15875919466358823335U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 17974092279281611763U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 2871472057292789157U;
            aOrbiterK = RotL64((aOrbiterK * 16104199340711015181U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 15187929795092006849U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 13482063681546475923U;
            aOrbiterB = RotL64((aOrbiterB * 14466266308157364963U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 6232152545071397380U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 17488906002621373262U;
            aOrbiterC = RotL64((aOrbiterC * 4719340606442742577U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 12444819880507588549U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 13808941689757772497U;
            aOrbiterH = RotL64((aOrbiterH * 6541360905282412317U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 8049361354387692374U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 7137831335606542401U;
            aOrbiterF = RotL64((aOrbiterF * 11022231291507235007U), 35U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterI, 42U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterD, 51U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterB, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterF, 51U)) + aOrbiterA) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 18U) + aOrbiterC) + RotL64(aOrbiterI, 47U));
            aWandererC = aWandererC + ((RotL64(aIngress, 35U) + RotL64(aOrbiterF, 42U)) + aOrbiterK);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterK, 57U));
            aWandererI = aWandererI + (((RotL64(aCross, 13U) + RotL64(aOrbiterC, 29U)) + aOrbiterB) + aNonceWordC);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 53U) + aOrbiterD) + RotL64(aOrbiterI, 35U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 40U) + RotL64(aOrbiterI, 23U)) + aOrbiterG) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterF, 12U)) + aNonceWordE);
            aWandererK = aWandererK + ((((RotL64(aCross, 27U) + RotL64(aOrbiterI, 19U)) + aOrbiterH) + RotL64(aCarry, 35U)) + aPhaseFWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 60U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 36U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 5
        // ingress from: aExpandLaneB, aSnowLaneD, aSnowLaneB
        // ingress directions: aExpandLaneB forward forced, aSnowLaneD forward forced, aSnowLaneB forward/backward random
        // cross from: aExpandLaneA, aSnowLaneC
        // cross directions: aExpandLaneA backward forced, aSnowLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 23464U)) & S_BLOCK1], 5U) ^ RotL64(aSnowLaneD[((aIndex + 22728U)) & S_BLOCK1], 40U));
            aIngress ^= RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 25567U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23425U)) & S_BLOCK1], 5U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 25997U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 43U) + RotL64(aIngress, 13U)) ^ (RotL64(aPrevious, 60U) ^ RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterG = (((aWandererI + RotL64(aScatter, 39U)) + 5721224134332887360U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordN;
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 51U)) + 6892749729775049095U) + aNonceWordE;
            aOrbiterI = (aWandererF + RotL64(aPrevious, 34U)) + 3884839462099556836U;
            aOrbiterE = (aWandererK + RotL64(aCross, 29U)) + 4365431706830216193U;
            aOrbiterH = (aWandererB + RotL64(aScatter, 13U)) + 15501528746571578773U;
            aOrbiterK = ((aWandererC + RotL64(aCross, 5U)) + RotL64(aCarry, 29U)) + 4505911326320650606U;
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 56U)) + 1865129050927879580U) + aNonceWordG;
            aOrbiterB = (((aWandererH + RotL64(aIngress, 47U)) + RotL64(aCarry, 37U)) + 2011737665969640369U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 23U)) + RotL64(aCarry, 3U)) + 611672935827062688U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 663547038310431047U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 5468932264754299556U) ^ aNonceWordO;
            aOrbiterI = RotL64((aOrbiterI * 11968657455484578525U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 17920294117231191705U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 486058453837528110U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8851102552244026737U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 2789178451938129313U) + aNonceWordA;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 420772587981211184U;
            aOrbiterE = RotL64((aOrbiterE * 17402987842294006667U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 16196774774442181825U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 16264169656793713547U) ^ aNonceWordK;
            aOrbiterA = RotL64((aOrbiterA * 6900221986041638783U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 10207659833859860796U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 8593749091183323678U;
            aOrbiterJ = RotL64((aOrbiterJ * 10696776033512404927U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 7224922076047787384U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 15366267474865172373U;
            aOrbiterB = RotL64((aOrbiterB * 10134187073321814217U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 4235342515820080294U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 5239480080426950612U;
            aOrbiterG = RotL64((aOrbiterG * 12077621553561927079U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 10891752830598395582U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 7797358829694471108U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7621206775460997431U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 3755715857903753416U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 3172069024987421726U;
            aOrbiterK = RotL64((aOrbiterK * 16048490837178650865U), 47U);
            //
            aIngress = RotL64(aOrbiterE, 38U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 23U));
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 39U) + RotL64(aOrbiterB, 51U)) + aOrbiterH) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 23U) + aOrbiterG) + RotL64(aOrbiterI, 12U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 54U) + RotL64(aOrbiterF, 29U)) + aOrbiterH) + aNonceWordD) + aPhaseFWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterG, 19U)) + aOrbiterA);
            aWandererB = aWandererB + ((RotL64(aScatter, 47U) + RotL64(aOrbiterG, 35U)) + aOrbiterB);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 43U) + aOrbiterA) + RotL64(aOrbiterK, 47U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 11U) + aOrbiterE) + RotL64(aOrbiterH, 56U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 43U)) + aOrbiterI);
            aWandererK = aWandererK + (((((RotL64(aPrevious, 28U) + aOrbiterF) + RotL64(aOrbiterE, 39U)) + RotL64(aCarry, 19U)) + aNonceWordB) + aPhaseFWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 30U));
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + RotL64(aWandererD, 39U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 6
        // ingress from: aExpandLaneC, aExpandLaneA, aInvestLaneC
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aInvestLaneC forward/backward random
        // cross from: aExpandLaneB, aOperationLaneB
        // cross directions: aExpandLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 29988U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneA[((aIndex + 29835U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 32578U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29558U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29955U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 43U) ^ RotL64(aIngress, 5U)) + (RotL64(aCross, 27U) + RotL64(aPrevious, 56U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterG = ((aWandererE + RotL64(aCross, 28U)) + RotL64(aCarry, 29U)) + 15036852811491820366U;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 57U)) + 305637140752898475U) + aPhaseFOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = (((aWandererF + RotL64(aScatter, 43U)) + RotL64(aCarry, 3U)) + 11948631574496129610U) + aNonceWordC;
            aOrbiterC = (((aWandererA + RotL64(aIngress, 47U)) + 5321623592482991426U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordN;
            aOrbiterE = (((aWandererB + RotL64(aPrevious, 53U)) + RotL64(aCarry, 39U)) + 4075270159062690728U) + aNonceWordE;
            aOrbiterB = (aWandererC + RotL64(aCross, 36U)) + 15111580500356908928U;
            aOrbiterJ = (aWandererD + RotL64(aIngress, 5U)) + 7244150695504160363U;
            aOrbiterF = (aWandererH + RotL64(aScatter, 21U)) + 5131563519577488862U;
            aOrbiterK = (aWandererI + RotL64(aIngress, 13U)) + 5881954992088651371U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 12780935808751507998U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 12599159643925470226U;
            aOrbiterI = RotL64((aOrbiterI * 17690046932587062701U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 9466589929741834066U) + aNonceWordI;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 6093158735705189789U;
            aOrbiterE = RotL64((aOrbiterE * 7453778295800853653U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 17461243886150519249U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 15456408913739900718U;
            aOrbiterJ = RotL64((aOrbiterJ * 16093292401746174671U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 11260643903290392780U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 7870342756041882616U;
            aOrbiterH = RotL64((aOrbiterH * 2431528656086173419U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 134484990005888936U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 10626896209992890407U;
            aOrbiterK = RotL64((aOrbiterK * 12034131076645285597U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 14031164129515132292U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterC) ^ 1771835705730244212U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 186981668443596623U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 16395472745067254664U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 1455944290845294254U) ^ aNonceWordH;
            aOrbiterC = RotL64((aOrbiterC * 6757824754363319079U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 17866422769075350837U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 10226884082632410805U;
            aOrbiterB = RotL64((aOrbiterB * 206035536985843815U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 14474587247775371703U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 8501763445324525303U;
            aOrbiterG = RotL64((aOrbiterG * 5298694643596784007U), 37U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 43U);
            aIngress = aIngress + (RotL64(aOrbiterG, 22U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterJ, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 47U) + aOrbiterC) + RotL64(aOrbiterH, 35U));
            aWandererD = aWandererD + (((RotL64(aIngress, 30U) + RotL64(aOrbiterF, 53U)) + aOrbiterC) + aNonceWordO);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 48U)) + aOrbiterJ);
            aWandererC = aWandererC + ((RotL64(aCross, 5U) + aOrbiterB) + RotL64(aOrbiterK, 3U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterJ, 43U));
            aWandererA = aWandererA + (((((RotL64(aPrevious, 60U) + RotL64(aOrbiterB, 27U)) + aOrbiterC) + RotL64(aCarry, 39U)) + aNonceWordB) + aPhaseFWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterF, 11U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 39U) + RotL64(aOrbiterI, 39U)) + aOrbiterE) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterH, 18U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 22U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 39U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_VolleyBall_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;

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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xBE2F4A5FAFBBE0A1ULL + 0xC1B9EBD97BC67E92ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xAB7287D907A00EEBULL + 0xDA1C3E3ABF0149F8ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xFBE5D9AB9C165AE9ULL + 0xCD9985DA4317108CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xE167871D5663B4DDULL + 0x8F7F8CE47E5329EAULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xACA56F85442022FBULL + 0xC66162B3A9C34F3CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xA4884077E66AF5C3ULL + 0xFA69CDF74823DA30ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xB720394A81714681ULL + 0xE6E06BDB36A4E9CCULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xFDE22C8BA3EF108BULL + 0xE6C72E0705FE6BC3ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xCCCC1BA42DE5E1C7ULL + 0xDA9D68608E30205DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xA6220694664BF101ULL + 0x8F4AD830371C3721ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xE7BAB56DA2220233ULL + 0xB473F2E8C73D4435ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xA7C09D7C397825B3ULL + 0xC716B2C31F6B43AFULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xB33ADDF08D528EB5ULL + 0xA382BFDA273CB22AULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xB48810FFA3D86313ULL + 0xED85BB0F24FAF4BAULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xE163E649539E8E15ULL + 0xF56D584A0B9A31F5ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xC7CA8780C4A33297ULL + 0xC8B53BE866C97781ULL);
    // GSeedRunSeed_G seed_loop_h (start)
    {
        // GSeedRunSeed_G seed_loop_h lane group
        // read from: aSnowLaneA, aSnowLaneB, aInvestLaneA, aSnowLaneC, aSnowLaneD, aInvestLaneC, aWorkLaneA, aFireLaneC, aFireLaneD, aWorkLaneB, aFireLaneA, aExpandLaneA, aInvestLaneD, aExpandLaneB, aInvestLaneB, aExpandLaneC, aFireLaneB
        // write to: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_h loop 1
        // ingress from: aSnowLaneA, aSnowLaneB, aInvestLaneA
        // ingress directions: aSnowLaneA forward forced, aSnowLaneB forward forced, aInvestLaneA forward/backward random
        // cross from: aSnowLaneC, aSnowLaneD, aInvestLaneC
        // cross directions: aSnowLaneC backward forced, aSnowLaneD backward forced, aInvestLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 4568U)) & S_BLOCK1], 6U) ^ RotL64(aSnowLaneB[((aIndex + 2606U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 2857U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 1323U)) & S_BLOCK1], 5U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 5022U)) & S_BLOCK1], 54U));
            aCross ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 4062U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCarry, 29U)) ^ (RotL64(aCross, 13U) + RotL64(aPrevious, 56U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterD = (aWandererD + RotL64(aCross, 11U)) + 17225673071833726819U;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 57U)) + 10301458382103627331U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aScatter, 37U)) + RotL64(aCarry, 21U)) + 3960233050857362414U;
            aOrbiterC = (((aWandererE + RotL64(aIngress, 43U)) + RotL64(aCarry, 53U)) + 17768665685046605837U) + aNonceWordN;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 5U)) + 14471018461213959767U) + aPhaseHOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = (((aWandererG + RotL64(aCross, 51U)) + RotL64(aCarry, 39U)) + 10730597892721340453U) + aNonceWordG;
            aOrbiterB = (aWandererJ + RotL64(aIngress, 22U)) + 14863394003122760542U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 9948587274816688296U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 3573569431435100993U) ^ aNonceWordE;
            aOrbiterA = RotL64((aOrbiterA * 2303922230056523077U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 8153670675740450590U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 16438856577722561424U;
            aOrbiterI = RotL64((aOrbiterI * 4689247488336908827U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 15765587867581925041U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 1082039522061775213U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17023740047246402641U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 4202521649260798876U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 15877659681260461141U;
            aOrbiterJ = RotL64((aOrbiterJ * 11369910758551088173U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 2551560426129646123U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 3005102326163906320U) ^ aNonceWordD;
            aOrbiterH = RotL64((aOrbiterH * 4241583192662435107U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 1675501058857208089U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 12774812270956702043U) ^ aNonceWordH;
            aOrbiterD = RotL64((aOrbiterD * 5488437008504905105U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 1044886020922563597U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterH) ^ 4857445127457225171U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterB = RotL64((aOrbiterB * 13223560654459705259U), 11U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterA, 3U);
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 50U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aScatter, 44U) + RotL64(aOrbiterH, 13U)) + aOrbiterB) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 46U)) + aOrbiterA) + aNonceWordC);
            aWandererJ = aWandererJ + (((RotL64(aCross, 13U) + RotL64(aOrbiterA, 29U)) + aOrbiterD) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 57U)) + aOrbiterJ) + aNonceWordM) + aPhaseHWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 51U) + aOrbiterB) + RotL64(aOrbiterI, 23U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterJ, 39U)) + aOrbiterA);
            aWandererA = aWandererA + ((((RotL64(aScatter, 19U) + aOrbiterD) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 13U)) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererG, 56U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 36U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 8909U)) & S_BLOCK1], 43U) ^ RotL64(aSnowLaneC[((aIndex + 10688U)) & S_BLOCK1], 12U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 8510U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 6090U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 6035U)) & S_BLOCK1], 37U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 8516U)) & S_BLOCK1], 60U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 6711U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 21U)) + (RotL64(aIngress, 44U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterF = ((aWandererC + RotL64(aIngress, 57U)) + 14008824488073394623U) + aPhaseHOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 26U)) + 13317978415866411468U) + aNonceWordH;
            aOrbiterA = (aWandererJ + RotL64(aScatter, 47U)) + 13209180141897453900U;
            aOrbiterG = ((aWandererG + RotL64(aCross, 5U)) + RotL64(aCarry, 51U)) + 11870521586865233578U;
            aOrbiterE = (((aWandererK + RotL64(aPrevious, 19U)) + RotL64(aCarry, 5U)) + 8052156380448047385U) + aNonceWordM;
            aOrbiterI = (aWandererE + RotL64(aCross, 39U)) + 12158131176743680605U;
            aOrbiterD = ((((aWandererI + RotL64(aScatter, 13U)) + RotL64(aCarry, 23U)) + 14674467487607719347U) + aPhaseHOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1]) + aNonceWordN;
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 18055496790566231147U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 3838105585041578784U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1075709247574580091U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 2839568255183054418U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 11933612922864258179U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7571964469321160347U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 6289849094151630580U) + aNonceWordK;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 2640344350528492271U;
            aOrbiterD = RotL64((aOrbiterD * 16197726750829369365U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 16306175266267657791U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 3339898380394883600U;
            aOrbiterF = RotL64((aOrbiterF * 7105436590182982373U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 15017076663742800002U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 8973064296077602496U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9309462227233615761U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 17580319233338139859U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 14063208878807603874U;
            aOrbiterG = RotL64((aOrbiterG * 16601475239075164585U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 13326130855721009942U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 12843186026737544416U) ^ aNonceWordE;
            aOrbiterB = RotL64((aOrbiterB * 4975848122837321619U), 41U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 51U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 35U)) + aOrbiterA) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterF, 29U)) + aOrbiterB) + aNonceWordI);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 41U)) + aOrbiterD) + RotL64(aCarry, 41U)) + aNonceWordG);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 38U) + RotL64(aOrbiterD, 47U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 51U) + RotL64(aOrbiterF, 5U)) + aOrbiterD) + aNonceWordJ) + aPhaseHWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 11U)) + aOrbiterB);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 3U) + aOrbiterA) + RotL64(aOrbiterD, 22U)) + aNonceWordD) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 20U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + RotL64(aWandererJ, 35U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_h loop 3
        // ingress from: aWorkLaneB, aSnowLaneA, aFireLaneA
        // ingress directions: aWorkLaneB forward forced, aSnowLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aWorkLaneA, aSnowLaneC
        // cross directions: aWorkLaneA backward forced, aSnowLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 14523U)) & S_BLOCK1], 24U) ^ RotL64(aSnowLaneA[((aIndex + 13383U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 14296U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11000U)) & S_BLOCK1], 56U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 13234U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 13U) + RotL64(aCarry, 40U)) ^ (RotL64(aPrevious, 27U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterI = ((aWandererK + RotL64(aIngress, 13U)) + 9435962834163239322U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aCross, 57U)) + 10524704356081318973U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (aWandererH + RotL64(aPrevious, 37U)) + 7403401305665208680U;
            aOrbiterD = (aWandererG + RotL64(aScatter, 6U)) + 7525414805023556493U;
            aOrbiterF = ((aWandererI + RotL64(aCross, 19U)) + RotL64(aCarry, 21U)) + 1116686470029070951U;
            aOrbiterJ = (((aWandererD + RotL64(aPrevious, 27U)) + RotL64(aCarry, 39U)) + 13257612299137802420U) + aNonceWordJ;
            aOrbiterH = (((aWandererF + RotL64(aScatter, 43U)) + RotL64(aCarry, 5U)) + 9181543003986598283U) + aNonceWordP;
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 9739384852307501107U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 11308402900229016057U) ^ aNonceWordA;
            aOrbiterE = RotL64((aOrbiterE * 12690186771773188967U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 14935167593705272337U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 7171824007631943535U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4839974427616194289U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 8068411284829563567U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 12350207458513447578U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 813973258659041895U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 17039236343991574134U) + aNonceWordD;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 18291683592714999632U;
            aOrbiterJ = RotL64((aOrbiterJ * 7771718817924840713U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 6239616841884430968U) + aNonceWordM;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 10604527977569876774U;
            aOrbiterH = RotL64((aOrbiterH * 6972820410084939637U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 1707724300671717658U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 3802268808625297647U;
            aOrbiterD = RotL64((aOrbiterD * 11296811630387191563U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 9423064323799920219U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 242153923313096551U) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 12117679073775630197U), 47U);
            //
            aIngress = RotL64(aOrbiterD, 53U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + RotL64(aOrbiterJ, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterJ, 34U)) + aOrbiterH);
            aWandererG = aWandererG + ((((RotL64(aCross, 51U) + aOrbiterG) + RotL64(aOrbiterE, 23U)) + RotL64(aCarry, 3U)) + aNonceWordF);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterE, 47U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 10U) + RotL64(aOrbiterI, 41U)) + aOrbiterF) + RotL64(aCarry, 27U)) + aPhaseHWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterD, 53U)) + aOrbiterH);
            aWandererF = aWandererF + (((RotL64(aPrevious, 41U) + aOrbiterJ) + RotL64(aOrbiterG, 13U)) + aNonceWordE);
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterI, 3U)) + aNonceWordK) + aPhaseHWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 56U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 41U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 4
        // ingress from: aExpandLaneA, aWorkLaneA, aInvestLaneD
        // ingress directions: aExpandLaneA forward forced, aWorkLaneA forward forced, aInvestLaneD forward/backward random
        // cross from: aWorkLaneB, aSnowLaneD
        // cross directions: aWorkLaneB backward forced, aSnowLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 20007U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((aIndex + 18828U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 16521U)) & S_BLOCK1], 44U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17917U)) & S_BLOCK1], 20U) ^ RotL64(aSnowLaneD[((aIndex + 16583U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCarry, 48U)) + (RotL64(aCross, 3U) ^ RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterI = ((aWandererG + RotL64(aCross, 34U)) + 2783898056762489197U) + aNonceWordJ;
            aOrbiterJ = (((aWandererF + RotL64(aIngress, 41U)) + RotL64(aCarry, 51U)) + 7177192902873343053U) + aPhaseHOrbiterAssignSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = (((aWandererB + RotL64(aPrevious, 21U)) + RotL64(aCarry, 21U)) + 12254703232691980774U) + aPhaseHOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = (aWandererD + RotL64(aScatter, 47U)) + 15446547245691219559U;
            aOrbiterD = (aWandererC + RotL64(aCross, 3U)) + 888475203006174856U;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 13U)) + 3649183529366307877U) + aNonceWordG;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 53U)) + RotL64(aCarry, 35U)) + 4642631047518805167U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 6108329730724782250U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 8334054653023816636U;
            aOrbiterE = RotL64((aOrbiterE * 9352516059501924393U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 5891895375031474350U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 3176720746238477862U;
            aOrbiterH = RotL64((aOrbiterH * 1869961473768307911U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 6111038696865301675U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = (((aOrbiterD ^ aOrbiterF) ^ 11914998302228682704U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 11738924766359642853U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 17005063057791320948U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 18333780598768130670U) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 5416759844884107303U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 2056115016443263153U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 10245512728872962677U;
            aOrbiterI = RotL64((aOrbiterI * 707106795383284903U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 4810366069422162351U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 3051442983125942469U;
            aOrbiterF = RotL64((aOrbiterF * 13558537578054436423U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 9285068547223654308U) + aNonceWordD;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 13067251130180968842U;
            aOrbiterB = RotL64((aOrbiterB * 7000687697769766605U), 27U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterI, 20U);
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + RotL64(aOrbiterF, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterF, 39U)) + aNonceWordL) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererD = aWandererD + (((((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 29U)) + aOrbiterI) + RotL64(aCarry, 3U)) + aNonceWordO) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 29U) + aOrbiterE) + RotL64(aOrbiterJ, 11U)) + aNonceWordA);
            aWandererG = aWandererG + (((RotL64(aPrevious, 60U) + RotL64(aOrbiterB, 58U)) + aOrbiterF) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 3U)) + aOrbiterH) + aNonceWordC);
            aWandererI = aWandererI + ((RotL64(aIngress, 39U) + aOrbiterI) + RotL64(aOrbiterE, 19U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterF, 51U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (RotL64(aWandererC, 4U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_h loop 5
        // ingress from: aExpandLaneB, aWorkLaneB, aInvestLaneB
        // ingress directions: aExpandLaneB forward forced, aWorkLaneB forward forced, aInvestLaneB forward/backward random
        // cross from: aExpandLaneA, aWorkLaneA
        // cross directions: aExpandLaneA backward forced, aWorkLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 26544U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneB[((aIndex + 22465U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 25348U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23733U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneA[((aIndex + 25366U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCross, 27U)) + (RotL64(aCarry, 53U) ^ RotL64(aIngress, 4U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterB = (aWandererD + RotL64(aIngress, 14U)) + 5160910997561396461U;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 39U)) + RotL64(aCarry, 57U)) + 14920764751058512062U;
            aOrbiterH = (aWandererJ + RotL64(aScatter, 47U)) + 6080952401749660022U;
            aOrbiterF = (aWandererC + RotL64(aPrevious, 21U)) + 17667234330526298627U;
            aOrbiterI = ((((aWandererK + RotL64(aScatter, 53U)) + RotL64(aCarry, 27U)) + 760630072638686756U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordK;
            aOrbiterC = (aWandererE + RotL64(aPrevious, 5U)) + 3504157162816997476U;
            aOrbiterG = ((((aWandererI + RotL64(aIngress, 27U)) + RotL64(aCarry, 41U)) + 9489022223422585882U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordI;
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 1149898536879968964U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 10492284328940025310U;
            aOrbiterH = RotL64((aOrbiterH * 7893416766300156495U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 13213275606286399312U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 10557118912847180413U;
            aOrbiterJ = RotL64((aOrbiterJ * 10077877991284587845U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 15618980209023994776U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterH) ^ 5268600749854045564U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterI = RotL64((aOrbiterI * 3849660559223919613U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 8011552687609649990U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 3148133096349525066U;
            aOrbiterF = RotL64((aOrbiterF * 5245156554959620007U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 12032847944237867285U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 14999005703490824673U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6631584955208646049U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 5426735969392906710U) + aNonceWordM;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 3593177531650386729U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12997284886192717043U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 1701444719333347373U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 15928731228196894960U) ^ aNonceWordL;
            aOrbiterG = RotL64((aOrbiterG * 1919318226904213433U), 19U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterF, 53U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 21U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 11U));
            aIngress = aIngress + RotL64(aOrbiterG, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aCross, 19U) + RotL64(aOrbiterI, 11U)) + aOrbiterG) + aNonceWordF) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterC, 51U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterI, 30U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterH, 37U)) + aOrbiterC) + aNonceWordJ);
            aWandererE = aWandererE + (((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterB, 43U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 10U) + aOrbiterG) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 48U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererK, 13U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 6
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneB
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneB, aSnowLaneB
        // cross directions: aExpandLaneB backward forced, aSnowLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28861U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((aIndex + 30969U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 28152U)) & S_BLOCK1], 54U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30467U)) & S_BLOCK1], 18U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 30439U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 24U) + RotL64(aCross, 11U)) + (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterD = (aWandererF + RotL64(aCross, 27U)) + 16424657151168221875U;
            aOrbiterB = (aWandererH + RotL64(aPrevious, 3U)) + 17150123681886380361U;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 53U)) + 16041993588694572757U) + aNonceWordN;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 37U)) + RotL64(aCarry, 27U)) + 9871185846434828537U;
            aOrbiterI = ((((aWandererJ + RotL64(aScatter, 19U)) + RotL64(aCarry, 51U)) + 11227236398354430757U) + aPhaseHOrbiterAssignSaltA[((aIndex + 16U)) & S_SALT1]) + aNonceWordI;
            aOrbiterG = (((aWandererD + RotL64(aCross, 11U)) + RotL64(aCarry, 5U)) + 5399325217402192631U) + aPhaseHOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 60U)) + 9248828789282890454U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 9041370494203701062U) + aNonceWordF;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 14944424084524970764U;
            aOrbiterC = RotL64((aOrbiterC * 10283363059424655079U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 5481938174456671041U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 14783648629543752715U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7260164783191886395U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 12355573914530445723U) + aNonceWordD;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 9863991559011968318U;
            aOrbiterG = RotL64((aOrbiterG * 8495251211794343179U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 16149688605937250965U) + aNonceWordM;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 106041828692026825U;
            aOrbiterD = RotL64((aOrbiterD * 12199934305374582599U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 8076098639554567792U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 11155119311895580013U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1495180896564818647U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 6847612160595917702U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 16094377920388017367U) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 4875801863643206333U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 13584719866672696684U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 13446209321646234607U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9945349065094781529U), 3U);
            //
            aIngress = RotL64(aOrbiterG, 11U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 60U));
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterI, 10U));
            aWandererH = aWandererH + (((((RotL64(aCross, 51U) + RotL64(aOrbiterC, 47U)) + aOrbiterG) + RotL64(aCarry, 5U)) + aNonceWordP) + aPhaseHWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 37U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterD, 23U)) + aOrbiterB) + RotL64(aCarry, 41U)) + aNonceWordL);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 36U) + RotL64(aOrbiterE, 3U)) + aOrbiterD);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 23U) + aOrbiterB) + RotL64(aOrbiterG, 29U)) + aNonceWordG) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 57U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 44U));
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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

void TwistExpander_VolleyBall_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE;
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
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD;
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 2037U)) & W_KEY1], 39U) ^ RotL64(aKeyRowReadB[((aIndex + 1333U)) & W_KEY1], 6U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 2615U)) & W_KEY1], 22U) ^ RotL64(mSource[((aIndex + 1582U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aIngress, 3U)) ^ (RotL64(aPrevious, 18U) ^ RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = (aWandererC + RotL64(aScatter, 23U)) + 15920462086654025436U;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 14U)) + RotL64(aCarry, 35U)) + 487844076858004017U;
            aOrbiterC = ((aWandererF + RotL64(aCross, 3U)) + 14502883786442630566U) + aPhaseAOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aIngress, 51U)) + RotL64(aCarry, 27U)) + 3787107318658233674U;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 39U)) + 12548777544693755491U;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 19U)) + RotL64(aCarry, 19U)) + 4907309444075181683U;
            aOrbiterK = (aWandererD + RotL64(aScatter, 43U)) + 18342396700266492072U;
            aOrbiterH = (aWandererH + RotL64(aIngress, 35U)) + 13503051997624242670U;
            aOrbiterI = ((aWandererI + RotL64(aCross, 30U)) + 17845742460521374571U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 8640887211877858169U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 5273913123709097537U;
            aOrbiterC = RotL64((aOrbiterC * 1661149444148461791U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 17756844173695563883U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 6713055830729302951U;
            aOrbiterD = RotL64((aOrbiterD * 2832836748513174311U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 5106468334224035972U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 10228769728713526172U;
            aOrbiterF = RotL64((aOrbiterF * 9760310686414358435U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 7687649520668883142U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 7757480627354711605U;
            aOrbiterH = RotL64((aOrbiterH * 7222553727737349209U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 10876291698508634557U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 8149278085586014186U;
            aOrbiterK = RotL64((aOrbiterK * 8577133863470695381U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 15592893988925610485U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 8639028256640537165U;
            aOrbiterG = RotL64((aOrbiterG * 1880655276432963955U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 475660347892196219U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 1903736092401853832U;
            aOrbiterE = RotL64((aOrbiterE * 8486318978769094799U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 12463250192809450953U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 7253918448601703982U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3821034106528009129U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 5171661020093804486U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 11627344933828324146U;
            aOrbiterI = RotL64((aOrbiterI * 5388047063152043277U), 47U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterG, 57U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 53U));
            aIngress = aIngress + (RotL64(aOrbiterH, 44U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterG, 29U)) + aOrbiterH);
            aWandererD = aWandererD + (((RotL64(aPrevious, 39U) + aOrbiterE) + RotL64(aOrbiterG, 57U)) + RotL64(aCarry, 39U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 30U) + aOrbiterC) + RotL64(aOrbiterE, 18U));
            aWandererI = aWandererI + ((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterG, 41U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterH, 5U)) + aOrbiterI);
            aWandererA = aWandererA + (((RotL64(aIngress, 11U) + aOrbiterF) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 53U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 58U) + aOrbiterC) + RotL64(aOrbiterK, 53U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 23U)) + aOrbiterJ);
            aWandererF = aWandererF ^ (((RotL64(aCross, 53U) + aOrbiterE) + RotL64(aOrbiterF, 36U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 14U));
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererA, 60U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 4894U)) & S_BLOCK1], 34U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 3578U)) & W_KEY1], 21U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 4399U)) & W_KEY1], 3U) ^ RotL64(mSource[((aIndex + 3642U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aPrevious, 5U)) + (RotL64(aCarry, 27U) + RotL64(aIngress, 42U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = (aWandererF + RotL64(aScatter, 35U)) + 1888427424966603593U;
            aOrbiterE = (((aWandererA + RotL64(aPrevious, 23U)) + RotL64(aCarry, 5U)) + 5436761445660415091U) + aPhaseAOrbiterAssignSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aCross, 3U)) + 17322876217962143270U;
            aOrbiterC = (aWandererD + RotL64(aIngress, 42U)) + 9728299982740564979U;
            aOrbiterJ = (aWandererK + RotL64(aCross, 29U)) + 301720335271716921U;
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 51U)) + RotL64(aCarry, 35U)) + 8069685428854814396U;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 11U)) + RotL64(aCarry, 51U)) + 1973715500949100991U;
            aOrbiterD = (aWandererE + RotL64(aPrevious, 56U)) + 87666408799854155U;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 19U)) + 12195436904339035245U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 4578742069143400295U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 7828776048774876484U;
            aOrbiterA = RotL64((aOrbiterA * 4047964518501081039U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 17203146364542781833U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 16913369550858890466U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13534417587921978507U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 9632761514552265402U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 9106637671877341286U;
            aOrbiterG = RotL64((aOrbiterG * 9073709119482640391U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 15423680889126750876U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 6087310684583331882U;
            aOrbiterC = RotL64((aOrbiterC * 8964465129744898619U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 5420955876411796789U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 14166807419730848032U;
            aOrbiterD = RotL64((aOrbiterD * 442659738632823751U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 8118312450347026824U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 4253043584558403086U;
            aOrbiterJ = RotL64((aOrbiterJ * 5651748455190536467U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 8810774678371762700U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 12218479555589447835U;
            aOrbiterK = RotL64((aOrbiterK * 11026364205248516355U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 11389930523582876358U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 16334420553471379915U;
            aOrbiterH = RotL64((aOrbiterH * 13830132212033904777U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 18201289372553710279U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 7196540389657785361U;
            aOrbiterF = RotL64((aOrbiterF * 13058135202554889791U), 53U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterC, 54U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 21U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aScatter, 4U) + aOrbiterF) + RotL64(aOrbiterE, 12U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterK, 19U)) + aOrbiterA);
            aWandererA = aWandererA + ((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterA, 23U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 19U) + aOrbiterJ) + RotL64(aOrbiterF, 3U));
            aWandererF = aWandererF + (((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 47U)) + aOrbiterD) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 13U) + aOrbiterG) + RotL64(aOrbiterC, 58U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 35U)) + aOrbiterC) + RotL64(aCarry, 21U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 40U) + RotL64(aOrbiterJ, 29U)) + aOrbiterA);
            aWandererI = aWandererI + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterD, 41U)) + aOrbiterH) + aPhaseAWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 52U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 27U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 6906U)) & S_BLOCK1], 18U) ^ RotL64(aKeyRowReadB[((aIndex + 7296U)) & W_KEY1], 3U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 7567U)) & W_KEY1], 37U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 5990U)) & S_BLOCK1], 6U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 7257U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aPrevious, 35U)) ^ (RotL64(aCross, 23U) ^ RotL64(aIngress, 10U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 57U)) + RotL64(aCarry, 27U)) + 380024772508948442U;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 23U)) + 7649029098162567210U) + aPhaseAOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = ((aWandererC + RotL64(aCross, 29U)) + RotL64(aCarry, 19U)) + 5329304598870421851U;
            aOrbiterA = (aWandererA + RotL64(aScatter, 41U)) + 12306118665045151326U;
            aOrbiterF = (aWandererJ + RotL64(aCross, 14U)) + 960751560457324256U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 51U)) + RotL64(aCarry, 11U)) + 3244070254386191876U;
            aOrbiterK = (aWandererI + RotL64(aScatter, 5U)) + 15733408571609521746U;
            aOrbiterB = (aWandererG + RotL64(aPrevious, 19U)) + 17623448932647018544U;
            aOrbiterH = ((aWandererE + RotL64(aCross, 46U)) + 8787759896149035829U) + aPhaseAOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 14741681792348288162U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 8801731213568307302U;
            aOrbiterJ = RotL64((aOrbiterJ * 12127126999570616489U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 9872248187499779222U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 15407371518644528235U;
            aOrbiterF = RotL64((aOrbiterF * 1245102406469471673U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 4242060317152943062U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 9942784962409917541U;
            aOrbiterG = RotL64((aOrbiterG * 888649755587764533U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 7296348796484458631U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 15061417216070157797U;
            aOrbiterD = RotL64((aOrbiterD * 10349554676953256231U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 3233185810644297433U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 9241229457641024287U;
            aOrbiterE = RotL64((aOrbiterE * 2728237515724597517U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 8464051359381554575U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 3307872165699029375U;
            aOrbiterK = RotL64((aOrbiterK * 4859663401033023433U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 5482617843966711997U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 4442149210462943872U;
            aOrbiterA = RotL64((aOrbiterA * 8979352218576515647U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 10591636597580147381U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 14925122230279312217U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15038171961638724013U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 9772367878232735350U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 15800661165607190092U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10493976952980533589U), 13U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 5U);
            aIngress = aIngress + (RotL64(aOrbiterH, 23U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 60U));
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aScatter, 19U) + RotL64(aOrbiterF, 47U)) + aOrbiterG);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 46U) + aOrbiterH) + RotL64(aOrbiterF, 21U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterK, 56U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 5U) + aOrbiterH) + RotL64(aOrbiterK, 39U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterB, 43U)) + aOrbiterF) + RotL64(aCarry, 3U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterJ, 3U));
            aWandererB = aWandererB + ((RotL64(aScatter, 52U) + aOrbiterA) + RotL64(aOrbiterB, 51U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterE, 10U)) + aOrbiterA);
            aWandererF = aWandererF + (((RotL64(aScatter, 39U) + RotL64(aOrbiterB, 27U)) + aOrbiterK) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 44U));
            aCarry = aCarry + RotL64(aWandererB, 11U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 8862U)) & S_BLOCK1], 29U) ^ RotL64(aKeyRowReadB[((aIndex + 10068U)) & W_KEY1], 37U));
            aIngress ^= (RotL64(mSource[((aIndex + 10910U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10884U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 8489U)) & W_KEY1], 14U) ^ RotL64(aWorkLaneB[((aIndex + 9197U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 29U) ^ RotL64(aCarry, 5U)) ^ (RotL64(aCross, 54U) + RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = ((aWandererF + RotL64(aCross, 40U)) + RotL64(aCarry, 35U)) + 9774364261626083532U;
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 57U)) + 18059001521926116420U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 19U)) + RotL64(aCarry, 11U)) + 10615626210406381148U;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 29U)) + 10536484278007898620U) + aPhaseBOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (aWandererG + RotL64(aCross, 5U)) + 13320663045139972700U;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 47U)) + 17127001787268166583U;
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 14U)) + RotL64(aCarry, 3U)) + 16742574590844166551U;
            aOrbiterA = (aWandererE + RotL64(aScatter, 51U)) + 8347719720758228053U;
            aOrbiterG = (aWandererC + RotL64(aIngress, 23U)) + 13502468705946051986U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 3512687886188904904U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 495660316165795934U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6724596801190194913U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 5092722552034477356U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 15641128019608284015U;
            aOrbiterH = RotL64((aOrbiterH * 3621036395703527059U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 15421873776811085458U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 17978775513204574125U;
            aOrbiterK = RotL64((aOrbiterK * 18359600395119440183U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 16617179197537669849U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 1931805387534012528U;
            aOrbiterF = RotL64((aOrbiterF * 3400139345857733775U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 9544923119559308431U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 12930999400470173353U;
            aOrbiterA = RotL64((aOrbiterA * 16791006919271490005U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 13673733276226249890U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 2032263473309124738U;
            aOrbiterJ = RotL64((aOrbiterJ * 3088728329261360607U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 14868502349358414206U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 10116495537187552321U;
            aOrbiterG = RotL64((aOrbiterG * 1380512121796709469U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 5341113995358179244U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 8415417980279705731U;
            aOrbiterD = RotL64((aOrbiterD * 8521501372683793821U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 2462819265072352463U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 7657062767608441931U;
            aOrbiterB = RotL64((aOrbiterB * 15554638801273540163U), 57U);
            //
            aIngress = RotL64(aOrbiterB, 47U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterK, 54U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 39U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 38U) + RotL64(aOrbiterA, 12U)) + aOrbiterE) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterF, 47U));
            aWandererF = aWandererF + ((RotL64(aIngress, 13U) + aOrbiterG) + RotL64(aOrbiterJ, 23U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterH, 51U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 27U) + aOrbiterK) + RotL64(aOrbiterF, 5U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 43U) + aOrbiterE) + RotL64(aOrbiterK, 56U));
            aWandererA = aWandererA + (((RotL64(aCross, 34U) + RotL64(aOrbiterB, 39U)) + aOrbiterG) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 43U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + (RotL64(aWandererC, 48U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 27U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 12638U)) & S_BLOCK1], 39U) ^ RotL64(aKeyRowReadA[((aIndex + 13392U)) & W_KEY1], 47U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 13113U)) & W_KEY1], 11U) ^ RotL64(mSource[((aIndex + 13254U)) & S_BLOCK1], 30U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 13282U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12673U)) & S_BLOCK1], 51U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 13066U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 51U) ^ RotL64(aCarry, 19U)) ^ (RotL64(aIngress, 39U) + RotL64(aCross, 4U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = (aWandererI + RotL64(aIngress, 50U)) + 13333509828310369865U;
            aOrbiterH = (((aWandererD + RotL64(aScatter, 19U)) + RotL64(aCarry, 47U)) + 7645352517103840797U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 35U)) + 5310766306660062655U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aCross, 5U)) + RotL64(aCarry, 5U)) + 5165635069832352932U;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 23U)) + RotL64(aCarry, 35U)) + 15684141764734281849U;
            aOrbiterI = (aWandererF + RotL64(aIngress, 46U)) + 3327963374225061738U;
            aOrbiterA = (aWandererH + RotL64(aCross, 29U)) + 8625811794878848871U;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 57U)) + 7598657468430485291U;
            aOrbiterG = (aWandererA + RotL64(aIngress, 13U)) + 2881171216276746485U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 10237691227222918101U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 6419254255884834497U;
            aOrbiterK = RotL64((aOrbiterK * 3816625473642865305U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 4238455444646479956U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 14936613353493061492U;
            aOrbiterB = RotL64((aOrbiterB * 3544216916806292273U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 15324699725208372627U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 9506640480601832011U;
            aOrbiterJ = RotL64((aOrbiterJ * 12819564111348390227U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 3709149613660215641U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 1724290199312754307U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12597580418257897965U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 13191172833570139194U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 3686087945377837886U;
            aOrbiterG = RotL64((aOrbiterG * 10883609557429936283U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 10418330386245397022U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 5383531313632347245U;
            aOrbiterC = RotL64((aOrbiterC * 2987755379396160073U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 7414716553072652212U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 11301761123966206201U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1546727321088592187U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 8570229732236388847U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 8773754460060264773U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3251360788932563495U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 13636929800504199371U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 5486599841558573720U;
            aOrbiterE = RotL64((aOrbiterE * 2867914211589815153U), 57U);
            //
            aIngress = RotL64(aOrbiterB, 36U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + RotL64(aOrbiterJ, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aPrevious, 18U) + RotL64(aOrbiterH, 30U)) + aOrbiterE) + RotL64(aCarry, 29U)) + aPhaseBWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 21U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aIngress, 39U) + aOrbiterE) + RotL64(aOrbiterK, 13U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 23U) + aOrbiterA) + RotL64(aOrbiterJ, 53U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterK, 35U)) + aOrbiterB);
            aWandererH = aWandererH ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterG, 57U)) + aOrbiterE);
            aWandererK = aWandererK + (((RotL64(aScatter, 43U) + aOrbiterI) + RotL64(aOrbiterB, 43U)) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 27U) + aOrbiterB) + RotL64(aOrbiterG, 47U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 56U) + RotL64(aOrbiterJ, 6U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 50U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererH, 53U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 14780U)) & S_BLOCK1], 12U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 13686U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 14503U)) & W_KEY1], 37U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 16227U)) & W_KEY1], 11U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 14743U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 15638U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15980U)) & S_BLOCK1], 46U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 6U)) + (RotL64(aIngress, 43U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 36U)) + 13499155707765393469U;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 57U)) + RotL64(aCarry, 39U)) + 3740324981823726185U;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 27U)) + RotL64(aCarry, 53U)) + 5470765363949735652U;
            aOrbiterI = (((aWandererI + RotL64(aCross, 51U)) + RotL64(aCarry, 11U)) + 3446436171274452326U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aIngress, 12U)) + 1778929412631211933U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aPrevious, 43U)) + 14666308799855220954U;
            aOrbiterE = (aWandererE + RotL64(aScatter, 21U)) + 4548410236791175055U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 47U)) + 5829739767694190372U;
            aOrbiterB = (aWandererF + RotL64(aIngress, 5U)) + 14319231414903675748U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 1513851750246111405U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 1685620217748986019U;
            aOrbiterC = RotL64((aOrbiterC * 9286548037413609445U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 16284162182006054402U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 6271539598462003309U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13923286694131331137U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 12669312437565969473U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 11894755313393001665U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12556759675372354075U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 6315983824634946566U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 17106616474222892782U;
            aOrbiterA = RotL64((aOrbiterA * 167205520766791073U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 13350266700180455548U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 4608846311203767162U;
            aOrbiterK = RotL64((aOrbiterK * 2504857468837437365U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 14195866746143604365U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 7917977448256795054U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5927771378657284557U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 10707336923305131629U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 17122696159336995392U;
            aOrbiterF = RotL64((aOrbiterF * 13953518568670659191U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 5182322763573586116U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 6503754948502556246U;
            aOrbiterB = RotL64((aOrbiterB * 14749002194140663519U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 14907832047832987341U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 6258064448676621346U;
            aOrbiterJ = RotL64((aOrbiterJ * 4407960312705621487U), 41U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 19U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 42U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aCross, 47U) + aOrbiterC) + RotL64(aOrbiterE, 24U)) + RotL64(aCarry, 35U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterI, 35U)) + aOrbiterG);
            aWandererC = aWandererC + ((RotL64(aPrevious, 56U) + aOrbiterE) + RotL64(aOrbiterK, 3U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterE, 29U)) + aOrbiterB);
            aWandererI = aWandererI + (((RotL64(aScatter, 11U) + aOrbiterK) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterJ, 44U)) + aOrbiterB);
            aWandererE = aWandererE + ((RotL64(aCross, 23U) + aOrbiterG) + RotL64(aOrbiterA, 53U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterJ, 57U)) + aOrbiterA);
            aWandererD = aWandererD + (((RotL64(aPrevious, 4U) + RotL64(aOrbiterC, 19U)) + aOrbiterF) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 44U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + RotL64(aWandererD, 39U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 17059U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadA[((aIndex + 18386U)) & W_KEY1], 53U));
            aIngress ^= (RotL64(mSource[((aIndex + 18191U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneA[((aIndex + 17322U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 16957U)) & W_KEY1], 37U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 17883U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 18706U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 51U) ^ RotL64(aPrevious, 21U)) + (RotL64(aIngress, 5U) + RotL64(aCross, 38U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 35U)) + 5160910997561396461U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aScatter, 27U)) + 14920764751058512062U;
            aOrbiterH = ((aWandererG + RotL64(aCross, 18U)) + RotL64(aCarry, 43U)) + 6080952401749660022U;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 43U)) + RotL64(aCarry, 11U)) + 17667234330526298627U;
            aOrbiterD = (aWandererD + RotL64(aCross, 5U)) + 760630072638686756U;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 39U)) + RotL64(aCarry, 23U)) + 3504157162816997476U;
            aOrbiterE = (aWandererF + RotL64(aIngress, 11U)) + 9489022223422585882U;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 58U)) + 1149898536879968964U) + aPhaseCOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aPrevious, 53U)) + 10492284328940025310U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 13213275606286399312U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 10557118912847180413U;
            aOrbiterH = RotL64((aOrbiterH * 10077877991284587845U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 15618980209023994776U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 5268600749854045564U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3849660559223919613U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 8011552687609649990U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 3148133096349525066U;
            aOrbiterJ = RotL64((aOrbiterJ * 5245156554959620007U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 12032847944237867285U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 14999005703490824673U;
            aOrbiterD = RotL64((aOrbiterD * 6631584955208646049U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 5426735969392906710U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 3593177531650386729U;
            aOrbiterG = RotL64((aOrbiterG * 12997284886192717043U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 1701444719333347373U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 15928731228196894960U;
            aOrbiterF = RotL64((aOrbiterF * 1919318226904213433U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 5960179456039157036U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 5716434224061596483U;
            aOrbiterE = RotL64((aOrbiterE * 3731976564761202801U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 2136841536293340279U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 12969550408652728526U;
            aOrbiterC = RotL64((aOrbiterC * 7612191387451455137U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 3641997570461447114U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 4677572491523684525U;
            aOrbiterI = RotL64((aOrbiterI * 2730358077882211651U), 39U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterE, 38U);
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 43U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 51U));
            aIngress = aIngress + RotL64(aOrbiterH, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 42U) + RotL64(aOrbiterF, 53U)) + aOrbiterG);
            aWandererE = aWandererE + (((RotL64(aCross, 13U) + RotL64(aOrbiterG, 12U)) + aOrbiterH) + RotL64(aCarry, 29U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterD, 27U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 51U) + aOrbiterH) + RotL64(aOrbiterJ, 37U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 56U) + aOrbiterC) + RotL64(aOrbiterB, 23U)) + aPhaseCWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 35U) + RotL64(aOrbiterC, 43U)) + aOrbiterE) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 18U)) + aOrbiterJ) + aPhaseCWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterI, 5U)) + aOrbiterJ);
            aWandererC = aWandererC ^ ((RotL64(aCross, 21U) + aOrbiterJ) + RotL64(aOrbiterD, 57U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 60U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererJ, 27U);
            aCarry = aCarry + RotL64(aIngress, 46U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 20165U)) & S_BLOCK1], 43U) ^ RotL64(mSource[((aIndex + 19964U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 20210U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((aIndex + 19958U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 21349U)) & W_KEY1], 41U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 19568U)) & W_KEY1], 21U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21616U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20504U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aIngress, 19U)) ^ (RotL64(aCross, 37U) + RotL64(aPrevious, 52U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 58U)) + 13650869943246163567U;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 13U)) + RotL64(aCarry, 43U)) + 3435284932011770999U;
            aOrbiterI = (aWandererD + RotL64(aCross, 21U)) + 12388155658186776579U;
            aOrbiterA = (aWandererC + RotL64(aPrevious, 39U)) + 2374345913955712039U;
            aOrbiterE = (((aWandererE + RotL64(aCross, 51U)) + RotL64(aCarry, 21U)) + 6095094526980292156U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aScatter, 43U)) + 4965147025852444174U;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 27U)) + 3261881216269075298U) + aPhaseCOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 47U)) + RotL64(aCarry, 51U)) + 4939780217097329222U;
            aOrbiterB = (aWandererF + RotL64(aScatter, 34U)) + 3019862009792676287U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 901910626217143974U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 3647055146712366383U;
            aOrbiterI = RotL64((aOrbiterI * 1792602402476450009U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 7731765438957392967U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 13409819457393479741U;
            aOrbiterK = RotL64((aOrbiterK * 3345078200262410715U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 5415832109107794258U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 8876738832313114471U;
            aOrbiterD = RotL64((aOrbiterD * 1304277600444504135U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 17135570542519390359U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 2373193062766802082U;
            aOrbiterB = RotL64((aOrbiterB * 4213691513185791519U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 16318403285501718552U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 8456043288604687045U;
            aOrbiterA = RotL64((aOrbiterA * 10556964529144571683U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 10572534930284516528U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 14616251186735204677U;
            aOrbiterC = RotL64((aOrbiterC * 2048651204265459805U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 2837006243817205610U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 5315917323622194254U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4080522050089666599U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 12084676282761185907U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 7922080344175593788U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7603522302708937379U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 17620847289789547792U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 12140386059533463650U;
            aOrbiterE = RotL64((aOrbiterE * 1443266480620969535U), 47U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterB, 30U);
            aIngress = aIngress + (RotL64(aOrbiterA, 41U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aPrevious, 39U) + aOrbiterA) + RotL64(aOrbiterE, 29U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterE, 19U)) + aOrbiterF);
            aWandererF = aWandererF + ((RotL64(aScatter, 5U) + aOrbiterI) + RotL64(aOrbiterD, 5U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 53U) + aOrbiterA) + RotL64(aOrbiterD, 12U)) + aPhaseCWandererUpdateSaltF[((aIndex + 10U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 20U) + aOrbiterI) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 29U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 47U)) + aOrbiterF);
            aWandererH = aWandererH + (((RotL64(aCross, 35U) + RotL64(aOrbiterA, 57U)) + aOrbiterK) + RotL64(aCarry, 19U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 57U) + aOrbiterI) + RotL64(aOrbiterK, 41U));
            aWandererA = aWandererA + ((RotL64(aScatter, 10U) + aOrbiterC) + RotL64(aOrbiterB, 52U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 38U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 24107U)) & S_BLOCK1], 39U) ^ RotL64(aKeyRowReadA[((aIndex + 23113U)) & W_KEY1], 19U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 24050U)) & W_KEY1], 30U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 22875U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 24168U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23257U)) & S_BLOCK1], 35U));
            aCross ^= (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 22499U)) & S_BLOCK1], 43U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 22827U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCarry, 5U)) + (RotL64(aPrevious, 35U) + RotL64(aCross, 50U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = (aWandererD + RotL64(aPrevious, 27U)) + 12809562813316740345U;
            aOrbiterC = ((aWandererB + RotL64(aCross, 14U)) + 17084212535326321199U) + aPhaseCOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aIngress, 23U)) + 16074921689983846769U;
            aOrbiterD = (aWandererH + RotL64(aScatter, 39U)) + 14027986153007120145U;
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 57U)) + RotL64(aCarry, 47U)) + 7633455951809250227U;
            aOrbiterF = (aWandererF + RotL64(aIngress, 10U)) + 340989348513370174U;
            aOrbiterH = ((aWandererK + RotL64(aCross, 47U)) + RotL64(aCarry, 13U)) + 5307820377645020116U;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 3U)) + RotL64(aCarry, 3U)) + 5605285015771527274U;
            aOrbiterB = ((aWandererI + RotL64(aIngress, 19U)) + 5293500434746182790U) + aPhaseCOrbiterAssignSaltB[((aIndex + 14U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 7263156475892261811U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 10672879570907433005U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2506338667179450741U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 16659226780900986107U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 9774892622769850665U;
            aOrbiterE = RotL64((aOrbiterE * 7487477727543183211U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 10728057184108279042U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 5032485856947407217U;
            aOrbiterD = RotL64((aOrbiterD * 16651577903809154285U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 14642241075374862345U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 8386481273395203518U;
            aOrbiterF = RotL64((aOrbiterF * 11649977733867003445U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 2874153265304098104U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 11519900149177261000U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2010158758971864505U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 8885690878540115768U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 4482143389870987714U;
            aOrbiterC = RotL64((aOrbiterC * 7105332459437434281U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 17469068567801886615U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 5121422018622394837U;
            aOrbiterA = RotL64((aOrbiterA * 14823827133212643467U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 3130788210672745618U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 6139244627510113216U;
            aOrbiterG = RotL64((aOrbiterG * 2640754184921507389U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 10488511756324474710U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 1760223670304953696U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4007062295003769311U), 19U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 23U);
            aIngress = aIngress + (RotL64(aOrbiterG, 39U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterC, 10U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 43U) + aOrbiterJ) + RotL64(aOrbiterH, 18U));
            aWandererA = aWandererA + (((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 5U)) + aOrbiterB) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterD, 57U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 58U) + RotL64(aOrbiterB, 13U)) + aOrbiterG) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterE, 52U)) + aOrbiterJ);
            aWandererI = aWandererI + ((RotL64(aIngress, 37U) + RotL64(aOrbiterD, 23U)) + aOrbiterJ);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 43U)) + aOrbiterG) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 52U) + aOrbiterC) + RotL64(aOrbiterF, 39U)) + aPhaseCWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 29U) + aOrbiterD) + RotL64(aOrbiterF, 35U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 48U));
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + RotL64(aWandererI, 23U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 26785U)) & S_BLOCK1], 34U) ^ RotL64(aKeyRowReadA[((aIndex + 24637U)) & W_KEY1], 57U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 27233U)) & S_BLOCK1], 23U) ^ RotL64(aFireLaneB[((aIndex + 25538U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 26908U)) & W_KEY1], 29U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 25467U)) & S_BLOCK1], 11U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 24838U)) & S_BLOCK1], 53U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 25449U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 54U) + RotL64(aIngress, 23U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = (aWandererE + RotL64(aCross, 47U)) + 16183871922837164759U;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 52U)) + RotL64(aCarry, 51U)) + 7002058258090219055U;
            aOrbiterE = ((aWandererK + RotL64(aScatter, 35U)) + 5650868611888303705U) + aPhaseDOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aIngress, 21U)) + RotL64(aCarry, 39U)) + 11899839660943876690U;
            aOrbiterH = (aWandererB + RotL64(aCross, 5U)) + 15349649504488111111U;
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 28U)) + 14060149569086744970U;
            aOrbiterG = (aWandererF + RotL64(aScatter, 39U)) + 12920917574225030112U;
            aOrbiterB = ((aWandererI + RotL64(aIngress, 11U)) + 2831994965175330135U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = ((aWandererG + RotL64(aScatter, 43U)) + RotL64(aCarry, 11U)) + 18312543585028439192U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 11657562205118394239U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 10850792819281246052U;
            aOrbiterE = RotL64((aOrbiterE * 10663100544207879337U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 17810371216216125323U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 7963413941144223128U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 534217972450595401U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 5498715358793875584U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 9256727548911651373U;
            aOrbiterG = RotL64((aOrbiterG * 10498848323914000989U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 17246360111302191699U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 18309978718113983369U;
            aOrbiterD = RotL64((aOrbiterD * 18267472694666221077U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 3100998994319502921U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 8129301860291235970U;
            aOrbiterC = RotL64((aOrbiterC * 17847033539279176187U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 1889641029473279114U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 16538494307002917945U;
            aOrbiterF = RotL64((aOrbiterF * 8081488217920885783U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 5432230549146849322U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 2634437941396090817U;
            aOrbiterH = RotL64((aOrbiterH * 7612999214758935211U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 16940172599174185058U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 13151669140593952203U;
            aOrbiterI = RotL64((aOrbiterI * 16225319638131723487U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 3995064294869931681U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 913081077665768816U;
            aOrbiterB = RotL64((aOrbiterB * 9299514648768060453U), 51U);
            //
            aIngress = RotL64(aOrbiterE, 53U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterB, 50U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 18U) + RotL64(aOrbiterC, 57U)) + aOrbiterI);
            aWandererH = aWandererH + ((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterD, 43U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterG, 48U)) + aPhaseDWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 5U) + RotL64(aOrbiterA, 19U)) + aOrbiterF);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 13U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aScatter, 23U) + RotL64(aOrbiterH, 53U)) + aOrbiterB) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 38U) + RotL64(aOrbiterI, 6U)) + aOrbiterE);
            aWandererI = aWandererI + ((((RotL64(aCross, 43U) + aOrbiterE) + RotL64(aOrbiterF, 37U)) + RotL64(aCarry, 51U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterA, 29U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 29829U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneD[((aIndex + 28349U)) & S_BLOCK1], 26U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 29344U)) & W_KEY1], 5U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 29080U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 28317U)) & W_KEY1], 3U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 27558U)) & S_BLOCK1], 27U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27733U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 27682U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCross, 57U)) + (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = ((aWandererE + RotL64(aIngress, 43U)) + 1042610313571524121U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = (aWandererJ + RotL64(aScatter, 37U)) + 3505725321008825582U;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 58U)) + 12584654563843782991U;
            aOrbiterH = (aWandererC + RotL64(aCross, 53U)) + 6645399144515770935U;
            aOrbiterD = (aWandererI + RotL64(aPrevious, 19U)) + 3608978423753715584U;
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 5U)) + RotL64(aCarry, 37U)) + 8089198857670370983U;
            aOrbiterE = (((aWandererD + RotL64(aCross, 27U)) + RotL64(aCarry, 57U)) + 15207251813516399879U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aIngress, 23U)) + 9579268660105824516U;
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 48U)) + RotL64(aCarry, 21U)) + 16055044469473802812U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 583811872609805949U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 7027491967970873942U;
            aOrbiterK = RotL64((aOrbiterK * 12686754713465826139U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 18256061823189677508U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 12708429127816136937U;
            aOrbiterJ = RotL64((aOrbiterJ * 12593886633108075321U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 12169216645156306078U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 12694325407567795065U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3711789483877261899U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 16109994660203297503U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 4234704064165718913U;
            aOrbiterE = RotL64((aOrbiterE * 730085881474787681U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 14119541943554602878U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 8777769004811352951U;
            aOrbiterD = RotL64((aOrbiterD * 2556957257736134223U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 15642663488392549609U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 11594468530833278624U;
            aOrbiterG = RotL64((aOrbiterG * 6639306656361601143U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 7365350535791499871U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 5965170981970155956U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1898702752753066851U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 9115232101451815522U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 9433983580038990072U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1951249217843992179U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 8810565477444156140U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 12081286530401844859U;
            aOrbiterA = RotL64((aOrbiterA * 1991383259486140229U), 43U);
            //
            aIngress = RotL64(aOrbiterK, 11U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 6U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + RotL64(aOrbiterF, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 39U) + aOrbiterJ) + RotL64(aOrbiterH, 20U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 48U) + RotL64(aOrbiterK, 13U)) + aOrbiterC);
            aWandererA = aWandererA + (((RotL64(aScatter, 27U) + RotL64(aOrbiterD, 43U)) + aOrbiterE) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterK, 51U));
            aWandererC = aWandererC + (((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterJ, 47U)) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 35U)) + aOrbiterJ) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterH, 56U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterD, 3U)) + aOrbiterA);
            aWandererK = aWandererK + ((RotL64(aPrevious, 52U) + aOrbiterF) + RotL64(aOrbiterC, 27U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 41U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 22U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 31912U)) & S_BLOCK1], 43U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 32300U)) & W_KEY1], 60U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 31710U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30494U)) & S_BLOCK1], 21U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32245U)) & S_BLOCK1], 10U) ^ RotL64(aKeyRowReadB[((aIndex + 32347U)) & W_KEY1], 53U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aIngress, 27U)) ^ (RotL64(aPrevious, 40U) + RotL64(aCarry, 13U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = (aWandererB + RotL64(aPrevious, 27U)) + 9471546960258473684U;
            aOrbiterI = ((aWandererI + RotL64(aCross, 53U)) + RotL64(aCarry, 47U)) + 18050235435948942244U;
            aOrbiterA = (aWandererH + RotL64(aScatter, 19U)) + 3005107102671544641U;
            aOrbiterK = (aWandererG + RotL64(aIngress, 42U)) + 17898396434573801850U;
            aOrbiterG = (aWandererJ + RotL64(aCross, 47U)) + 15071602525497771648U;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 5U)) + RotL64(aCarry, 27U)) + 5780119462702672108U;
            aOrbiterE = (((aWandererD + RotL64(aPrevious, 11U)) + RotL64(aCarry, 5U)) + 13301326224151025687U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = (aWandererA + RotL64(aIngress, 35U)) + 18129323022260575961U;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 60U)) + 1199228670638790709U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 1839199978088021020U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 4999517042246790165U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4585813675677234577U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 8788607633376516299U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 15143903839930468749U;
            aOrbiterH = RotL64((aOrbiterH * 12735914889325422675U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 16674732686428431869U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 15908873150953195581U;
            aOrbiterB = RotL64((aOrbiterB * 18049755517524334107U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 11204775359756474667U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 2525984309543939465U;
            aOrbiterD = RotL64((aOrbiterD * 3988529812023791571U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 4566345170476825512U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 14876612901557406267U;
            aOrbiterE = RotL64((aOrbiterE * 9047956948845135339U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 14926290877038883931U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 12710203178186614846U;
            aOrbiterI = RotL64((aOrbiterI * 14841163494801662515U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 7315094513967387996U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 11050116830482816766U;
            aOrbiterK = RotL64((aOrbiterK * 3702999495721152019U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 4505368486032503953U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 17905748055257551092U;
            aOrbiterF = RotL64((aOrbiterF * 14775870175093453197U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 5728886950801376350U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 17998141690182325170U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16008599930125391379U), 37U);
            //
            aIngress = RotL64(aOrbiterD, 57U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + (RotL64(aOrbiterH, 6U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aCross, 14U) + RotL64(aOrbiterI, 48U)) + aOrbiterE) + aPhaseDWandererUpdateSaltD[((aIndex + 20U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 51U) + aOrbiterH) + RotL64(aOrbiterD, 19U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterD, 35U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 23U) + aOrbiterG) + RotL64(aOrbiterF, 53U)) + aPhaseDWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterK, 57U)) + aOrbiterB);
            aWandererJ = aWandererJ + (((RotL64(aCross, 58U) + RotL64(aOrbiterK, 13U)) + aOrbiterF) + RotL64(aCarry, 37U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterI, 39U)) + aOrbiterG);
            aWandererA = aWandererA + ((RotL64(aPrevious, 43U) + aOrbiterI) + RotL64(aOrbiterB, 26U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 6U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + RotL64(aWandererB, 29U);
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

void TwistExpander_VolleyBall_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneC, aExpandLaneC, aExpandLaneD, aInvestLaneC, aFireLaneD, aInvestLaneD, aFireLaneB, aOperationLaneA, aFireLaneA, aOperationLaneB, aOperationLaneC
        // write to: aInvestLaneC, aInvestLaneD, aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // twist_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneC
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 401U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((aIndex + 2633U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 2212U)) & S_BLOCK1], 12U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 53U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneD[((aIndex + 340U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCarry, 26U)) ^ (RotL64(aPrevious, 3U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = (((aWandererK + RotL64(aCross, 19U)) + RotL64(aCarry, 43U)) + 4204560462077827182U) + aPhaseEOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 53U)) + RotL64(aCarry, 57U)) + 6572370199668594039U;
            aOrbiterE = (aWandererG + RotL64(aScatter, 13U)) + 15958999876732622825U;
            aOrbiterI = (((aWandererJ + RotL64(aIngress, 43U)) + RotL64(aCarry, 27U)) + 9969349486879280377U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = (aWandererH + RotL64(aScatter, 60U)) + 15450238998293956181U;
            aOrbiterJ = (aWandererA + RotL64(aCross, 37U)) + 9128619863683138259U;
            aOrbiterF = (aWandererC + RotL64(aIngress, 3U)) + 5691270563628979565U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 5901029710568933106U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 10442738941988588834U;
            aOrbiterE = RotL64((aOrbiterE * 7386621444831603817U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 3508116020325721993U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 13221917083569767259U;
            aOrbiterB = RotL64((aOrbiterB * 6845108555710135357U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 11627915460377128176U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 17858261365514253433U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7535577636975884641U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 4294837988806295989U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 11242915481585070249U;
            aOrbiterG = RotL64((aOrbiterG * 17540688242763829319U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 13030663829236027109U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 7451948220723185149U;
            aOrbiterC = RotL64((aOrbiterC * 5191778587712222029U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 5575508866505031037U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 5161096033789876794U;
            aOrbiterF = RotL64((aOrbiterF * 16843827915802461797U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 3980482740649505122U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 11188906150207270241U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 408550837615188413U), 29U);
            //
            aIngress = RotL64(aOrbiterE, 57U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterC, 14U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterF, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterG, 35U)) + aOrbiterJ);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 13U)) + aOrbiterG);
            aWandererJ = aWandererJ + (((RotL64(aCross, 41U) + aOrbiterC) + RotL64(aOrbiterB, 42U)) + aPhaseEWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterI, 21U)) + aOrbiterC);
            aWandererK = aWandererK + (((RotL64(aCross, 60U) + aOrbiterJ) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 47U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterI, 29U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 13U) + aOrbiterG) + RotL64(aOrbiterE, 51U)) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 60U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 37U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aInvestLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_b loop 2
        // ingress from: aInvestLaneC, aExpandLaneC, aFireLaneD
        // ingress directions: aInvestLaneC forward forced, aExpandLaneC forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 5956U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((aIndex + 5674U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 8236U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 5584U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneD[((aIndex + 9858U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 43U) + RotL64(aCarry, 60U)) ^ (RotL64(aPrevious, 27U) ^ RotL64(aCross, 13U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = ((aWandererA + RotL64(aIngress, 3U)) + RotL64(aCarry, 39U)) + 16424657151168221875U;
            aOrbiterF = (aWandererH + RotL64(aPrevious, 57U)) + 17150123681886380361U;
            aOrbiterG = (((aWandererB + RotL64(aScatter, 35U)) + RotL64(aCarry, 5U)) + 16041993588694572757U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = ((aWandererK + RotL64(aCross, 20U)) + RotL64(aCarry, 51U)) + 9871185846434828537U;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 47U)) + 11227236398354430757U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = (aWandererC + RotL64(aPrevious, 27U)) + 5399325217402192631U;
            aOrbiterK = (aWandererE + RotL64(aCross, 41U)) + 9248828789282890454U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 9041370494203701062U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 14944424084524970764U;
            aOrbiterG = RotL64((aOrbiterG * 10283363059424655079U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 5481938174456671041U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 14783648629543752715U;
            aOrbiterF = RotL64((aOrbiterF * 7260164783191886395U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 12355573914530445723U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 9863991559011968318U;
            aOrbiterI = RotL64((aOrbiterI * 8495251211794343179U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 16149688605937250965U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 106041828692026825U;
            aOrbiterK = RotL64((aOrbiterK * 12199934305374582599U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 8076098639554567792U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 11155119311895580013U;
            aOrbiterD = RotL64((aOrbiterD * 1495180896564818647U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 6847612160595917702U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 16094377920388017367U;
            aOrbiterE = RotL64((aOrbiterE * 4875801863643206333U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 13584719866672696684U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 13446209321646234607U;
            aOrbiterH = RotL64((aOrbiterH * 9945349065094781529U), 51U);
            //
            aIngress = RotL64(aOrbiterG, 35U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterH, 47U)) + aOrbiterF) + RotL64(aCarry, 43U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 20U) + aOrbiterD) + RotL64(aOrbiterG, 5U)) + aPhaseEWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterI, 41U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterI, 14U));
            aWandererC = aWandererC + ((RotL64(aCross, 53U) + aOrbiterF) + RotL64(aOrbiterE, 35U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterI, 53U)) + aOrbiterF);
            aWandererE = aWandererE + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 29U)) + aOrbiterF) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 18U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aInvestLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_b loop 3
        // ingress from: aInvestLaneD, aExpandLaneD, aFireLaneB
        // ingress directions: aInvestLaneD forward forced, aExpandLaneD forward forced, aFireLaneB forward/backward random
        // cross from: aInvestLaneC, aExpandLaneB, aExpandLaneA
        // cross directions: aInvestLaneC backward forced, aExpandLaneB backward forced, aExpandLaneA backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneD[((aIndex + 15322U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((aIndex + 12091U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 13242U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 11347U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 13082U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aExpandLaneA[((aIndex + 13328U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 19U) ^ RotL64(aPrevious, 38U)) + (RotL64(aCross, 51U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = (aWandererC + RotL64(aCross, 11U)) + 11039986441331892533U;
            aOrbiterE = (((aWandererD + RotL64(aScatter, 53U)) + RotL64(aCarry, 43U)) + 6256024955965426119U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = (aWandererH + RotL64(aIngress, 41U)) + 9857443189988995666U;
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 19U)) + RotL64(aCarry, 57U)) + 11900944813380998208U;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 47U)) + 8422577734978875541U) + aPhaseEOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aCross, 34U)) + RotL64(aCarry, 29U)) + 3100835100713928724U;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 3U)) + 11871553509810206993U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 17614749493763417027U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 3638372131856199916U;
            aOrbiterD = RotL64((aOrbiterD * 480683274898147025U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 6582275259281025770U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 17016882418498941958U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4269869255230867823U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 1747214688658984715U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 9356088987044015278U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16221733545319753695U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 4056238112133473456U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 16013150119949532998U;
            aOrbiterH = RotL64((aOrbiterH * 12913648646318115315U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 16076621211111834889U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 9940824359571581765U;
            aOrbiterG = RotL64((aOrbiterG * 11624767861336495331U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 15624084004784515753U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 7630989544834680335U;
            aOrbiterA = RotL64((aOrbiterA * 12261063237156822067U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 18003586430673313786U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 1654118743290334161U;
            aOrbiterC = RotL64((aOrbiterC * 1153250137357176071U), 19U);
            //
            aIngress = RotL64(aOrbiterH, 47U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 4U));
            aIngress = aIngress + RotL64(aOrbiterD, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 19U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 60U) + aOrbiterE) + RotL64(aOrbiterJ, 41U)) + aPhaseEWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 3U) + aOrbiterH) + RotL64(aOrbiterJ, 23U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterJ, 5U)) + aOrbiterD);
            aWandererE = aWandererE + ((RotL64(aScatter, 11U) + RotL64(aOrbiterE, 47U)) + aOrbiterA);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 41U) + aOrbiterD) + RotL64(aOrbiterG, 60U));
            aWandererF = aWandererF + (((RotL64(aCross, 47U) + RotL64(aOrbiterG, 29U)) + aOrbiterC) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 12U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 53U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_b loop 4
        // ingress from: aOperationLaneA, aInvestLaneC, aFireLaneA
        // ingress directions: aOperationLaneA forward forced, aInvestLaneC forward forced, aFireLaneA forward/backward random
        // cross from: aInvestLaneD, aExpandLaneD, aExpandLaneC
        // cross directions: aInvestLaneD backward forced, aExpandLaneD backward forced, aExpandLaneC backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 21693U)) & S_BLOCK1], 43U) ^ RotL64(aInvestLaneC[((aIndex + 16639U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 18977U)) & S_BLOCK1], 54U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 16504U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17716U)) & S_BLOCK1], 30U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 16579U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aIngress, 6U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = (aWandererH + RotL64(aScatter, 19U)) + 8367680518550579791U;
            aOrbiterE = (((aWandererA + RotL64(aPrevious, 27U)) + RotL64(aCarry, 35U)) + 11491674725611181241U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aIngress, 13U)) + 16673861720782164214U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aCross, 43U)) + RotL64(aCarry, 47U)) + 9786610124108350855U;
            aOrbiterJ = (aWandererE + RotL64(aScatter, 34U)) + 5745080601557577637U;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 3U)) + 1959402215131684684U;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 57U)) + RotL64(aCarry, 21U)) + 6121650036079196522U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 12016309761037342392U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 5986936646177049603U;
            aOrbiterG = RotL64((aOrbiterG * 3585650475703294895U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 1000367700904043468U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 17425288243569101032U;
            aOrbiterK = RotL64((aOrbiterK * 2174614006719048535U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 4856917474950325209U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 16312111093223166419U;
            aOrbiterI = RotL64((aOrbiterI * 11046477664487805241U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 456110002032422270U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 11393724374787795662U;
            aOrbiterE = RotL64((aOrbiterE * 1176984359123668389U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 8378176867715697176U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 8086186452345234815U;
            aOrbiterJ = RotL64((aOrbiterJ * 8450438271765985235U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 8470349167474173245U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 2528229938740192694U;
            aOrbiterD = RotL64((aOrbiterD * 8717790851266520943U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 13247168811545753141U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 8745293957516815264U;
            aOrbiterA = RotL64((aOrbiterA * 14270617180621072619U), 23U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterA, 35U);
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aCross, 29U) + RotL64(aOrbiterD, 11U)) + aOrbiterI) + RotL64(aCarry, 23U)) + aPhaseEWandererUpdateSaltE[((aIndex + 16U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterJ, 58U)) + aOrbiterK);
            aWandererI = aWandererI + (((RotL64(aScatter, 41U) + RotL64(aOrbiterG, 19U)) + aOrbiterE) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 47U)) + aOrbiterE) + aPhaseEWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 57U) + aOrbiterA) + RotL64(aOrbiterJ, 29U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 48U) + RotL64(aOrbiterJ, 5U)) + aOrbiterG);
            aWandererE = aWandererE + ((RotL64(aPrevious, 11U) + aOrbiterI) + RotL64(aOrbiterG, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 58U));
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 37U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 26674U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((aIndex + 25471U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27298U)) & S_BLOCK1], 52U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 26179U)) & S_BLOCK1], 50U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 26783U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 21887U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 22U) ^ RotL64(aCross, 53U)) + (RotL64(aPrevious, 3U) + RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = (aWandererD + RotL64(aCross, 43U)) + 1557680213571812384U;
            aOrbiterI = (((aWandererA + RotL64(aIngress, 34U)) + RotL64(aCarry, 27U)) + 7387349725778021121U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = (aWandererE + RotL64(aPrevious, 21U)) + 15379264067601586976U;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 13U)) + 3730195724576043708U) + aPhaseEOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 51U)) + RotL64(aCarry, 51U)) + 9637070085323827066U;
            aOrbiterE = (aWandererJ + RotL64(aIngress, 27U)) + 1170865717363676184U;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 2750833653175252030U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 15118992811225568305U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 4974092922102988451U;
            aOrbiterF = RotL64((aOrbiterF * 10575977398702460975U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 10625719096296719514U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 855167122475471865U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7441090331293158773U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 11322911068958340262U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 4334591909425429835U;
            aOrbiterJ = RotL64((aOrbiterJ * 10059025861172038183U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 14263701737208936392U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 678723206735649084U;
            aOrbiterC = RotL64((aOrbiterC * 10823239851733632227U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 15652053114252065230U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 1705225940224061401U;
            aOrbiterE = RotL64((aOrbiterE * 3626023093533713579U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 6826394665732900206U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 11902946775066981141U;
            aOrbiterI = RotL64((aOrbiterI * 18300629262162694137U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 9802212958998591310U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 14001358545610206524U;
            aOrbiterK = RotL64((aOrbiterK * 13172645840788327099U), 47U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterE, 29U);
            aIngress = aIngress + (RotL64(aOrbiterF, 53U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterC, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 13U) + aOrbiterF) + RotL64(aOrbiterK, 41U)) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterH, 29U));
            aWandererF = aWandererF + ((RotL64(aIngress, 42U) + aOrbiterJ) + RotL64(aOrbiterI, 11U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterE, 50U));
            aWandererA = aWandererA + (((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 19U)) + aOrbiterF) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterE, 3U)) + aOrbiterH) + aPhaseEWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 57U) + aOrbiterE) + RotL64(aOrbiterK, 35U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 48U));
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 13U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 32682U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneA[((aIndex + 27632U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 27745U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31683U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31594U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 31692U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aPrevious, 6U)) + (RotL64(aIngress, 41U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = (((aWandererG + RotL64(aPrevious, 11U)) + RotL64(aCarry, 23U)) + 13499155707765393469U) + aPhaseEOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aScatter, 29U)) + 3740324981823726185U;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 5U)) + RotL64(aCarry, 39U)) + 5470765363949735652U;
            aOrbiterA = (aWandererK + RotL64(aCross, 35U)) + 3446436171274452326U;
            aOrbiterD = (aWandererJ + RotL64(aScatter, 18U)) + 1778929412631211933U;
            aOrbiterH = (aWandererI + RotL64(aIngress, 41U)) + 14666308799855220954U;
            aOrbiterC = (((aWandererE + RotL64(aCross, 53U)) + RotL64(aCarry, 11U)) + 4548410236791175055U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 5829739767694190372U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 14319231414903675748U;
            aOrbiterB = RotL64((aOrbiterB * 4966501102515775601U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 1513851750246111405U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 1685620217748986019U;
            aOrbiterJ = RotL64((aOrbiterJ * 9286548037413609445U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 16284162182006054402U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 6271539598462003309U;
            aOrbiterH = RotL64((aOrbiterH * 13923286694131331137U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 12669312437565969473U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 11894755313393001665U;
            aOrbiterF = RotL64((aOrbiterF * 12556759675372354075U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 6315983824634946566U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 17106616474222892782U;
            aOrbiterA = RotL64((aOrbiterA * 167205520766791073U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 13350266700180455548U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 4608846311203767162U;
            aOrbiterC = RotL64((aOrbiterC * 2504857468837437365U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 14195866746143604365U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 7917977448256795054U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5927771378657284557U), 13U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterH, 53U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterH, 3U)) + aOrbiterF);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 13U) + aOrbiterB) + RotL64(aOrbiterC, 51U));
            aWandererB = aWandererB + (((RotL64(aCross, 4U) + RotL64(aOrbiterJ, 19U)) + aOrbiterB) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterH, 35U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 21U) + aOrbiterD) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 43U)) + aPhaseEWandererUpdateSaltC[((aIndex + 6U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterF, 42U)) + aPhaseEWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 57U) + aOrbiterA) + RotL64(aOrbiterC, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + RotL64(aWandererE, 4U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_VolleyBall_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
        // read from: aOperationLaneA, aOperationLaneB, aInvestLaneD, aOperationLaneC, aOperationLaneD, aInvestLaneC, aSnowLaneA, aInvestLaneB, aInvestLaneA, aSnowLaneB, aExpandLaneA, aWorkLaneA, aExpandLaneD, aWorkLaneB, aExpandLaneB, aWorkLaneC, aExpandLaneC
        // write to: aSnowLaneA, aSnowLaneB, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // twist_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aInvestLaneD
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aInvestLaneD forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aInvestLaneC
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aInvestLaneC backward/forward random
        // write to: aSnowLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 724U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneB[((aIndex + 2449U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 2151U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4145U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 5064U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aInvestLaneC[((aIndex + 445U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aPrevious, 39U)) ^ (RotL64(aCarry, 14U) + RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = (aWandererK + RotL64(aPrevious, 56U)) + 9080426856729228705U;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 47U)) + 7851218321653539276U) + aPhaseFOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aScatter, 51U)) + RotL64(aCarry, 41U)) + 7023344692919298036U;
            aOrbiterD = (aWandererA + RotL64(aCross, 27U)) + 9772846154227440734U;
            aOrbiterG = (aWandererC + RotL64(aIngress, 35U)) + 12008298632429608431U;
            aOrbiterH = (aWandererH + RotL64(aCross, 5U)) + 12201090455849562875U;
            aOrbiterJ = (aWandererE + RotL64(aScatter, 44U)) + 9498721803411445471U;
            aOrbiterC = (aWandererB + RotL64(aPrevious, 23U)) + 351203764023093632U;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 29U)) + RotL64(aCarry, 51U)) + 4966360430644539250U;
            aOrbiterB = ((aWandererJ + RotL64(aCross, 41U)) + 9194167899071345693U) + aPhaseFOrbiterAssignSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 11U)) + RotL64(aCarry, 23U)) + 4922477697284269116U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 15742625291642356429U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 7528703106518431730U;
            aOrbiterK = RotL64((aOrbiterK * 11530049278751507567U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 15279053574704935317U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 2425839793660355555U;
            aOrbiterH = RotL64((aOrbiterH * 11486964816849830667U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 13209849392400008898U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 9041500097716231309U;
            aOrbiterF = RotL64((aOrbiterF * 340661035700748739U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 7885423750878814599U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 1992993999902904603U;
            aOrbiterA = RotL64((aOrbiterA * 1478629826632201617U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 6120758615019314102U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 8529621625846992066U;
            aOrbiterE = RotL64((aOrbiterE * 8485991471612862467U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 9125182130757385320U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 15691232622970220043U;
            aOrbiterG = RotL64((aOrbiterG * 16517916951054758147U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 11413090085435424697U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 11563151001080914939U;
            aOrbiterI = RotL64((aOrbiterI * 16828196274450408201U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 1778975369262558069U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 3232132443557192010U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17132823737792200981U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 277456309842614908U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 10470076566806421600U;
            aOrbiterJ = RotL64((aOrbiterJ * 7526503789282158285U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 12466953663713418197U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 15871548472936716844U;
            aOrbiterD = RotL64((aOrbiterD * 11788139245249205765U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 12322317028530419228U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 9080426856729228705U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4204042134412769955U), 23U);
            //
            aIngress = RotL64(aOrbiterC, 13U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 22U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 27U)) + aOrbiterH);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 27U) + aOrbiterH) + RotL64(aOrbiterA, 24U));
            aWandererB = aWandererB + ((RotL64(aCross, 35U) + RotL64(aOrbiterI, 37U)) + aOrbiterB);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterE, 21U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterH, 43U)) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterJ, 3U)) + aOrbiterF);
            aWandererI = aWandererI + ((RotL64(aScatter, 54U) + aOrbiterE) + RotL64(aOrbiterB, 18U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterC, 41U)) + aOrbiterK);
            aWandererK = aWandererK + ((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterJ, 53U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterD, 51U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 38U) + aOrbiterI) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 14U));
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 4U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aSnowLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 2
        // ingress from: aSnowLaneA, aOperationLaneC, aOperationLaneD, aInvestLaneB
        // ingress directions: aSnowLaneA forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aInvestLaneB forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aInvestLaneA
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aInvestLaneA backward/forward random
        // write to: aSnowLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 9088U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((aIndex + 6035U)) & S_BLOCK1], 60U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 5828U)) & S_BLOCK1], 21U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 7352U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 10910U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 9658U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aInvestLaneA[((aIndex + 8651U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCross, 53U)) + (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 26U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = (aWandererA + RotL64(aPrevious, 37U)) + 18087125778766689269U;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 46U)) + RotL64(aCarry, 3U)) + 13710545066503235196U;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 51U)) + RotL64(aCarry, 39U)) + 1701939704736254645U;
            aOrbiterJ = (aWandererF + RotL64(aCross, 11U)) + 8064093611384019909U;
            aOrbiterE = ((aWandererC + RotL64(aScatter, 23U)) + 16623332751533885431U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = (aWandererK + RotL64(aCross, 21U)) + 15590129153794910109U;
            aOrbiterD = (aWandererG + RotL64(aIngress, 53U)) + 7413312683079107383U;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 26U)) + RotL64(aCarry, 29U)) + 4186064478651458810U;
            aOrbiterB = (aWandererJ + RotL64(aIngress, 3U)) + 5501191643940735954U;
            aOrbiterI = (aWandererE + RotL64(aScatter, 57U)) + 11064645242200570835U;
            aOrbiterH = ((aWandererH + RotL64(aCross, 35U)) + 13825922087298055833U) + aPhaseFOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 5944980709887369970U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 8181136916070569646U;
            aOrbiterA = RotL64((aOrbiterA * 395183021205661827U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 15442336949157292482U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 11580554435240641337U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6654637892858767739U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 11240018128174598322U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 2027565596050777471U;
            aOrbiterG = RotL64((aOrbiterG * 18048186560314431815U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 16425887196883725233U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 16828683527588834095U;
            aOrbiterI = RotL64((aOrbiterI * 17746289103235902485U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9923829146479008804U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 6669171007279929454U;
            aOrbiterD = RotL64((aOrbiterD * 681823450939955099U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 3902430046523165149U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 6739998149289590041U;
            aOrbiterK = RotL64((aOrbiterK * 2675037435528416821U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 16014401255534234075U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 14741857638680634564U;
            aOrbiterB = RotL64((aOrbiterB * 8723611021403369393U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 5064807861673260054U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 968747317273200299U;
            aOrbiterF = RotL64((aOrbiterF * 14122304002722582329U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 5282686212362051427U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 6902253563196129760U;
            aOrbiterJ = RotL64((aOrbiterJ * 7682808024658992049U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 4995580401402368332U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 14949762584793646470U;
            aOrbiterH = RotL64((aOrbiterH * 3539183342072953803U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 2378815735788107402U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 18087125778766689269U;
            aOrbiterE = RotL64((aOrbiterE * 16799380528404446281U), 35U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 41U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 10U));
            aIngress = aIngress + (RotL64(aOrbiterC, 37U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + RotL64(aOrbiterH, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterC, 39U)) + aOrbiterK);
            aWandererA = aWandererA + ((RotL64(aScatter, 50U) + aOrbiterA) + RotL64(aOrbiterD, 24U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterJ, 29U)) + aOrbiterC);
            aWandererI = aWandererI + (((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterE, 11U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterG, 53U)) + aOrbiterF);
            aWandererD = aWandererD + ((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterG, 43U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 27U)) + aOrbiterA) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 18U) + RotL64(aOrbiterC, 5U)) + aOrbiterH) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 21U)) + aOrbiterD);
            aWandererB = aWandererB + (((RotL64(aScatter, 5U) + RotL64(aOrbiterG, 56U)) + aOrbiterI) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 3U) + aOrbiterE) + RotL64(aOrbiterB, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 60U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + RotL64(aWandererG, 27U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aSnowLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 3
        // ingress from: aSnowLaneB, aOperationLaneA, aExpandLaneA
        // ingress directions: aSnowLaneB forward forced, aOperationLaneA forward forced, aExpandLaneA forward/backward random
        // cross from: aSnowLaneA, aOperationLaneC
        // cross directions: aSnowLaneA backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneB[((aIndex + 15071U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneA[((aIndex + 11190U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aExpandLaneA[((aIndex + 11299U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 15364U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneC[((aIndex + 12953U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 13U) + RotL64(aPrevious, 27U)) ^ (RotL64(aIngress, 39U) + RotL64(aCarry, 58U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = (aWandererG + RotL64(aCross, 23U)) + 6024062041314952357U;
            aOrbiterI = (aWandererK + RotL64(aScatter, 40U)) + 18340757093658015585U;
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 27U)) + 11911120493880346751U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 53U)) + RotL64(aCarry, 27U)) + 17428074353884654439U;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 13U)) + RotL64(aCarry, 57U)) + 12790849760814795936U;
            aOrbiterB = (aWandererI + RotL64(aPrevious, 3U)) + 12633397052172117800U;
            aOrbiterH = (aWandererA + RotL64(aIngress, 5U)) + 11946150433665237945U;
            aOrbiterJ = (aWandererD + RotL64(aCross, 47U)) + 16842157900909419285U;
            aOrbiterA = (aWandererH + RotL64(aScatter, 19U)) + 14186235783224155962U;
            aOrbiterK = (((aWandererC + RotL64(aIngress, 58U)) + RotL64(aCarry, 11U)) + 13284904542579767591U) + aPhaseFOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = (aWandererF + RotL64(aPrevious, 43U)) + 11609181965078844357U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 9628562297095374984U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 7850281529011259759U;
            aOrbiterD = RotL64((aOrbiterD * 17611485102925470357U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 257458718073794527U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 10693404545773519306U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14821443722828498323U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 3430519236533871460U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 6183054506953198055U;
            aOrbiterJ = RotL64((aOrbiterJ * 6121082743789970911U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 2905610989884221654U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 4472163910775333862U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7770678426310856745U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 16870142883133769663U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 1403692060594816451U;
            aOrbiterF = RotL64((aOrbiterF * 9740854430251597879U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 16904169913507057108U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 4773518591580333357U;
            aOrbiterB = RotL64((aOrbiterB * 5306070307776061267U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 6528141733853494275U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 11254806909313951442U;
            aOrbiterC = RotL64((aOrbiterC * 6316669786405548827U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 6857506858448143407U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 2855763534355983644U;
            aOrbiterK = RotL64((aOrbiterK * 16881334940165182415U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 12328391751024624740U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 16475072086109949522U;
            aOrbiterH = RotL64((aOrbiterH * 15218626930666825883U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 15505670341076785424U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 6972128419331939330U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12206069109180246067U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 7151546362283646210U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 6024062041314952357U;
            aOrbiterI = RotL64((aOrbiterI * 10243806128059850493U), 51U);
            //
            aIngress = RotL64(aOrbiterI, 23U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterE, 34U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 37U));
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterB, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 27U) + RotL64(aOrbiterI, 53U)) + aOrbiterK) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 39U) + aOrbiterD) + RotL64(aOrbiterE, 41U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterJ, 60U)) + aOrbiterG) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 48U) + RotL64(aOrbiterC, 29U)) + aOrbiterG);
            aWandererC = aWandererC + ((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterA, 51U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterJ, 13U));
            aWandererF = aWandererF + (((RotL64(aCross, 19U) + aOrbiterB) + RotL64(aOrbiterH, 26U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 11U) + aOrbiterC) + RotL64(aOrbiterJ, 3U));
            aWandererG = aWandererG + ((RotL64(aScatter, 46U) + aOrbiterF) + RotL64(aOrbiterC, 21U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterJ, 19U)) + aOrbiterB);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 41U) + aOrbiterK) + RotL64(aOrbiterJ, 37U)) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 18U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 21U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 40U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 4
        // ingress from: aWorkLaneA, aSnowLaneA, aExpandLaneD
        // ingress directions: aWorkLaneA forward forced, aSnowLaneA forward forced, aExpandLaneD forward/backward random
        // cross from: aSnowLaneB, aOperationLaneD
        // cross directions: aSnowLaneB backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 21373U)) & S_BLOCK1], 41U) ^ RotL64(aSnowLaneA[((aIndex + 20836U)) & S_BLOCK1], 30U));
            aIngress ^= RotL64(aExpandLaneD[((aIndex + 19828U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 19115U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 18046U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 6U) ^ RotL64(aPrevious, 53U)) + (RotL64(aIngress, 21U) + RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = (aWandererI + RotL64(aIngress, 23U)) + 6916817163240024692U;
            aOrbiterC = (aWandererD + RotL64(aCross, 30U)) + 14554930751292077817U;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 5U)) + RotL64(aCarry, 13U)) + 1098305064484336101U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 43U)) + 12192821172420471527U) + aPhaseFOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aCross, 39U)) + 2435134991707318845U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = (aWandererA + RotL64(aPrevious, 21U)) + 1896745368738512624U;
            aOrbiterF = (aWandererK + RotL64(aScatter, 41U)) + 1114996424222923873U;
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 11U)) + RotL64(aCarry, 23U)) + 9839135798371512656U;
            aOrbiterD = (aWandererB + RotL64(aScatter, 51U)) + 8037967239603177043U;
            aOrbiterK = (aWandererC + RotL64(aPrevious, 54U)) + 15185468738487237432U;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 35U)) + RotL64(aCarry, 19U)) + 4912098316394854543U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 13142688607850380888U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 4507379759608945839U;
            aOrbiterG = RotL64((aOrbiterG * 2989332387754215967U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 7299006009652289342U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 5390655277207053627U;
            aOrbiterC = RotL64((aOrbiterC * 10973744708856143715U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 6744737023577785725U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 15539737698867067285U;
            aOrbiterE = RotL64((aOrbiterE * 4686092035261336911U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 13329866734681377952U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 13284937458969166257U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3965985432462699445U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 8695002088915702168U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 3858059421620839286U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9559783727301092937U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 6609163873243179836U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 9416165620556710540U;
            aOrbiterB = RotL64((aOrbiterB * 240385043740268229U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 1578449067529000433U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 14309000104419489303U;
            aOrbiterK = RotL64((aOrbiterK * 7599078306153684729U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 15785180680737461320U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 10099222679918382021U;
            aOrbiterJ = RotL64((aOrbiterJ * 2012232597046182581U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 10666287769220108179U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 13648647399222807034U;
            aOrbiterI = RotL64((aOrbiterI * 10772381733103127201U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 9292207828896796810U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 9155130791347443553U;
            aOrbiterF = RotL64((aOrbiterF * 16838229790655977057U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 11334395119119245556U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 6916817163240024692U;
            aOrbiterA = RotL64((aOrbiterA * 9640906826978028183U), 51U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 54U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 43U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterF, 58U)) + aOrbiterG) + aPhaseFWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 51U) + aOrbiterE) + RotL64(aOrbiterK, 53U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterA, 37U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 22U) + aOrbiterB) + RotL64(aOrbiterF, 51U)) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterK, 3U)) + aOrbiterA);
            aWandererH = aWandererH + ((RotL64(aIngress, 43U) + RotL64(aOrbiterG, 48U)) + aOrbiterB);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterC, 43U)) + aOrbiterJ);
            aWandererC = aWandererC + ((RotL64(aScatter, 29U) + RotL64(aOrbiterE, 41U)) + aOrbiterD);
            aWandererB = aWandererB ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterI, 39U)) + aOrbiterD) + aPhaseFWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterJ, 19U)) + RotL64(aCarry, 37U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 46U) + RotL64(aOrbiterH, 13U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (RotL64(aWandererD, 24U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererC, 41U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 5
        // ingress from: aWorkLaneB, aSnowLaneB, aExpandLaneB
        // ingress directions: aWorkLaneB forward forced, aSnowLaneB forward forced, aExpandLaneB forward/backward random
        // cross from: aWorkLaneA, aSnowLaneA
        // cross directions: aWorkLaneA backward forced, aSnowLaneA backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 23320U)) & S_BLOCK1], 5U) ^ RotL64(aSnowLaneB[((aIndex + 24038U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 24442U)) & S_BLOCK1], 24U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23061U)) & S_BLOCK1], 50U) ^ RotL64(aSnowLaneA[((aIndex + 24174U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aIngress, 21U)) + (RotL64(aCarry, 4U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = ((aWandererH + RotL64(aCross, 29U)) + 16424657151168221875U) + aPhaseFOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = (aWandererB + RotL64(aScatter, 27U)) + 17150123681886380361U;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 41U)) + 16041993588694572757U;
            aOrbiterF = (aWandererC + RotL64(aIngress, 10U)) + 9871185846434828537U;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 19U)) + RotL64(aCarry, 29U)) + 11227236398354430757U;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 43U)) + RotL64(aCarry, 37U)) + 5399325217402192631U;
            aOrbiterK = ((aWandererA + RotL64(aCross, 53U)) + RotL64(aCarry, 51U)) + 9248828789282890454U;
            aOrbiterH = (aWandererJ + RotL64(aScatter, 38U)) + 9041370494203701062U;
            aOrbiterA = (aWandererI + RotL64(aCross, 51U)) + 14944424084524970764U;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 5U)) + 5481938174456671041U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aPrevious, 13U)) + 14783648629543752715U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 12355573914530445723U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 9863991559011968318U;
            aOrbiterC = RotL64((aOrbiterC * 8495251211794343179U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 16149688605937250965U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 106041828692026825U;
            aOrbiterB = RotL64((aOrbiterB * 12199934305374582599U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 8076098639554567792U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 11155119311895580013U;
            aOrbiterF = RotL64((aOrbiterF * 1495180896564818647U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 6847612160595917702U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 16094377920388017367U;
            aOrbiterE = RotL64((aOrbiterE * 4875801863643206333U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 13584719866672696684U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 13446209321646234607U;
            aOrbiterA = RotL64((aOrbiterA * 9945349065094781529U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 15829806645369560988U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 12573767256739062550U;
            aOrbiterJ = RotL64((aOrbiterJ * 5649504278826069077U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 3850030870300393809U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 11857593987748189858U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15942863910931814193U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 5505918410521728373U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 12949653497121247860U;
            aOrbiterG = RotL64((aOrbiterG * 90944913639560027U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 2448323375614082955U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 4386059032042654583U;
            aOrbiterH = RotL64((aOrbiterH * 11730132905525317201U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 108129028178045299U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 18292666533864994149U;
            aOrbiterK = RotL64((aOrbiterK * 2599590507178673531U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 10771402979550786312U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 16424657151168221875U;
            aOrbiterI = RotL64((aOrbiterI * 6255743082177474607U), 39U);
            //
            aIngress = RotL64(aOrbiterG, 26U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 23U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + RotL64(aOrbiterC, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aScatter, 37U) + aOrbiterG) + RotL64(aOrbiterB, 37U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterA, 54U));
            aWandererI = aWandererI + (((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 19U)) + aOrbiterF) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterH, 43U)) + aPhaseFWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 60U) + RotL64(aOrbiterH, 57U)) + aOrbiterI) + RotL64(aCarry, 13U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterB, 41U)) + aOrbiterH) + aPhaseFWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 47U) + aOrbiterI) + RotL64(aOrbiterF, 11U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterG, 23U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 27U)) + aOrbiterC);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 56U) + aOrbiterC) + RotL64(aOrbiterK, 3U));
            aWandererA = aWandererA + ((RotL64(aCross, 39U) + RotL64(aOrbiterD, 14U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 18U));
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 41U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + (RotL64(aWandererA, 46U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererK, 53U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 6
        // ingress from: aWorkLaneC, aWorkLaneA, aExpandLaneC
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aExpandLaneC forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 30874U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 31578U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 27509U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31876U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28933U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 29U) + RotL64(aCross, 6U)) ^ (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = (((aWandererC + RotL64(aPrevious, 57U)) + RotL64(aCarry, 53U)) + 4739486756133131180U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 41U)) + RotL64(aCarry, 19U)) + 16089707555501328184U;
            aOrbiterB = (aWandererA + RotL64(aCross, 19U)) + 15310047330238536453U;
            aOrbiterC = (aWandererD + RotL64(aScatter, 38U)) + 7901411596386834955U;
            aOrbiterK = (aWandererH + RotL64(aCross, 47U)) + 4357555491060982163U;
            aOrbiterJ = (aWandererK + RotL64(aIngress, 53U)) + 15667085602825720102U;
            aOrbiterG = (aWandererI + RotL64(aScatter, 3U)) + 8520635334382269253U;
            aOrbiterD = (aWandererE + RotL64(aPrevious, 51U)) + 1772509779231068315U;
            aOrbiterI = (aWandererF + RotL64(aIngress, 27U)) + 15336170957886025677U;
            aOrbiterE = (((aWandererG + RotL64(aCross, 36U)) + RotL64(aCarry, 27U)) + 8628770833489469980U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aScatter, 23U)) + 15469234024247246228U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 10796430900884288328U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 10660110397012853289U;
            aOrbiterB = RotL64((aOrbiterB * 9140007610912037461U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 11202284258711214794U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 17509491802893182994U;
            aOrbiterK = RotL64((aOrbiterK * 9329107599972703671U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 16212572740740103554U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 2190030203761579226U;
            aOrbiterD = RotL64((aOrbiterD * 3101886685668871045U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 12014337082293041909U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 3733531010807001506U;
            aOrbiterE = RotL64((aOrbiterE * 5797362244066062299U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 7100994963061975529U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 17837541162838600258U;
            aOrbiterH = RotL64((aOrbiterH * 8745987361678166553U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 3311518938023146951U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 7709505172646831553U;
            aOrbiterG = RotL64((aOrbiterG * 7121143171245765213U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 4979968094554018443U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 16822214821463034107U;
            aOrbiterC = RotL64((aOrbiterC * 8618262120451291765U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 8376124175020587079U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 11084586282092424876U;
            aOrbiterF = RotL64((aOrbiterF * 5835632742522563537U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 7816368455027681621U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 10893292019060642422U;
            aOrbiterJ = RotL64((aOrbiterJ * 3995821210667317677U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 13602875505184178486U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 5425735673005681983U;
            aOrbiterI = RotL64((aOrbiterI * 12667085597129312079U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 5995385043278810987U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 4739486756133131180U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15709273328685013399U), 21U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterB, 3U);
            aIngress = aIngress + (RotL64(aOrbiterH, 14U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterG, 11U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + RotL64(aOrbiterC, 56U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 37U) + RotL64(aOrbiterF, 41U)) + aOrbiterK) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterG, 13U)) + aOrbiterC);
            aWandererD = aWandererD + ((RotL64(aScatter, 24U) + aOrbiterC) + RotL64(aOrbiterH, 39U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterC, 51U)) + aOrbiterD);
            aWandererG = aWandererG + (((RotL64(aCross, 13U) + aOrbiterB) + RotL64(aOrbiterJ, 27U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 53U) + aOrbiterH) + RotL64(aOrbiterA, 60U)) + aPhaseFWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 27U) + RotL64(aOrbiterK, 37U)) + aOrbiterI) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 43U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((RotL64(aCross, 58U) + RotL64(aOrbiterE, 21U)) + aOrbiterB);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterC, 46U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 53U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 46U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererA, 13U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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

void TwistExpander_VolleyBall_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterJ = 0;
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
        // ingress from: aWorkLaneA, aWorkLaneB, aWorkLaneC
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aWorkLaneC forward/backward random
        // cross from: aWorkLaneB, aWorkLaneC, aWorkLaneD
        // cross directions: aWorkLaneB backward forced, aWorkLaneC backward forced, aWorkLaneD backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 7961U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneB[((aIndex + 6548U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 3348U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 7175U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 1678U)) & S_BLOCK1], 52U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 5425U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCross, 5U)) ^ (RotL64(aCarry, 18U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (aWandererI + RotL64(aScatter, 37U)) + 4068921616130916949U;
            aOrbiterJ = (((aWandererD + RotL64(aPrevious, 56U)) + RotL64(aCarry, 3U)) + 12077715273915151726U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = ((aWandererC + RotL64(aIngress, 5U)) + RotL64(aCarry, 23U)) + 16047546802670596833U;
            aOrbiterG = ((aWandererH + RotL64(aCross, 29U)) + RotL64(aCarry, 47U)) + 9690277462716999763U;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 19U)) + 14484814700447992628U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 17089267243053958210U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 9138746214446211147U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8244950097712975043U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 10181001536979097045U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 6657458969093373191U;
            aOrbiterG = RotL64((aOrbiterG * 4311019792293202747U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 7515983477876590988U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 3039935555863947600U;
            aOrbiterJ = RotL64((aOrbiterJ * 12511160550780270119U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 16209389224740851136U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 725253312098083182U;
            aOrbiterF = RotL64((aOrbiterF * 17535989492095522597U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 13307041115748941383U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 7159572004825238263U;
            aOrbiterC = RotL64((aOrbiterC * 4855009895002398449U), 13U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 14U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aIngress, 48U) + aOrbiterF) + RotL64(aOrbiterG, 18U)) + aPhaseGWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 11U) + aOrbiterC) + RotL64(aOrbiterK, 37U)) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterJ, 5U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterJ, 27U)) + RotL64(aCarry, 47U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterF, 51U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererE, 54U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererC, 11U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 10912U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneB[((aIndex + 8509U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 9444U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 12211U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 12945U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 13950U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCross, 11U)) ^ (RotL64(aCarry, 35U) ^ RotL64(aIngress, 50U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = (((aWandererF + RotL64(aPrevious, 58U)) + RotL64(aCarry, 5U)) + 16462052553719977502U) + aPhaseGOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aIngress, 11U)) + RotL64(aCarry, 57U)) + 12337064059566619581U;
            aOrbiterF = (((aWandererI + RotL64(aCross, 19U)) + RotL64(aCarry, 41U)) + 15801005007094515447U) + aPhaseGOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (aWandererE + RotL64(aScatter, 35U)) + 8228706742665081656U;
            aOrbiterD = (aWandererC + RotL64(aIngress, 47U)) + 11006723027845190869U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 18173765337829177450U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 530215083653542558U;
            aOrbiterF = RotL64((aOrbiterF * 8938680024265564887U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 6608611827035564511U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 2246051826221626809U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6333352641495253539U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 5228575308895381421U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 10999213210689606857U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5467601259546342925U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 3773371037240485696U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 8887985779436152504U;
            aOrbiterA = RotL64((aOrbiterA * 698713082830739677U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 11150566414723818350U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 8336366151003049546U;
            aOrbiterD = RotL64((aOrbiterD * 9033771197242493699U), 19U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 23U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + RotL64(aOrbiterB, 36U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 23U) + aOrbiterB) + RotL64(aOrbiterA, 29U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 37U) + aOrbiterK) + RotL64(aOrbiterA, 43U)) + RotL64(aCarry, 5U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterD, 52U));
            aWandererC = aWandererC + ((((RotL64(aCross, 13U) + RotL64(aOrbiterF, 21U)) + aOrbiterB) + RotL64(aCarry, 27U)) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 4U) + RotL64(aOrbiterF, 13U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererE, 18U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererK, 57U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 17442U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((aIndex + 17796U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 20727U)) & S_BLOCK1], 54U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21255U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 21765U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 20670U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 58U) ^ RotL64(aIngress, 11U)) + (RotL64(aCross, 27U) ^ RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 51U)) + 12583180859826261500U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aPrevious, 13U)) + 9067093488553721468U;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 26U)) + RotL64(aCarry, 43U)) + 12173106198862881754U;
            aOrbiterA = (((aWandererH + RotL64(aCross, 3U)) + RotL64(aCarry, 5U)) + 11333491014394592654U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 41U)) + RotL64(aCarry, 57U)) + 3511883526940919554U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 7416810692106273044U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 8341174972619784110U;
            aOrbiterK = RotL64((aOrbiterK * 17722163445765437279U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 2220852854836962979U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 8090781422229383825U;
            aOrbiterG = RotL64((aOrbiterG * 578293950675644397U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 2338801236599102223U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 12484514711848308104U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10364216764253366067U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 13684861340589131816U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 12796636819991873058U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5533508014234835669U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 7634198650894837690U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 10240326122201201762U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8758703497719125901U), 39U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 5U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 21U));
            aIngress = aIngress + RotL64(aOrbiterK, 46U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterG, 18U)) + aOrbiterA);
            aWandererF = aWandererF + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 29U)) + aOrbiterC) + RotL64(aCarry, 19U)) + aPhaseGWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterK, 39U)) + aOrbiterA);
            aWandererA = aWandererA + (((RotL64(aScatter, 21U) + RotL64(aOrbiterC, 57U)) + aOrbiterE) + RotL64(aCarry, 35U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 12U) + aOrbiterC) + RotL64(aOrbiterK, 47U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (RotL64(aWandererD, 58U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererA, 29U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 29142U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((aIndex + 27812U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25640U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24655U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25746U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 30713U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCross, 13U)) + (RotL64(aCarry, 27U) ^ RotL64(aIngress, 54U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = (((aWandererD + RotL64(aIngress, 4U)) + RotL64(aCarry, 37U)) + 13350544654542863236U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = ((aWandererG + RotL64(aScatter, 53U)) + RotL64(aCarry, 57U)) + 12364346790125404372U;
            aOrbiterJ = (aWandererA + RotL64(aCross, 27U)) + 9738750172849512764U;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 35U)) + 3781373837635491421U) + aPhaseGOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = ((aWandererE + RotL64(aCross, 43U)) + RotL64(aCarry, 19U)) + 16635020317512702337U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 5383653921676231276U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 10181959815492056493U;
            aOrbiterJ = RotL64((aOrbiterJ * 14784636206508715141U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 10005510924273927017U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 9524687662265740565U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13687380438646756931U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 4259138552009771014U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 8973051213213726023U;
            aOrbiterA = RotL64((aOrbiterA * 12625091476068190979U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 17602611840127337490U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 8218984546932905269U;
            aOrbiterD = RotL64((aOrbiterD * 17504305273683304231U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 18102186122213487888U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 2629927500298092976U;
            aOrbiterG = RotL64((aOrbiterG * 6983280164448292723U), 57U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterD, 19U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 43U));
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterG, 14U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 27U)) + aOrbiterF);
            aWandererG = aWandererG + ((((RotL64(aCross, 51U) + RotL64(aOrbiterA, 51U)) + aOrbiterG) + RotL64(aCarry, 19U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 18U) + aOrbiterJ) + RotL64(aOrbiterD, 35U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterA, 5U)) + aOrbiterJ) + RotL64(aCarry, 37U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 22U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererA, 51U);
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

void TwistExpander_VolleyBall_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
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
        // ingress from: aExpandLaneA, aExpandLaneB, aExpandLaneC
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aExpandLaneC forward/backward random
        // cross from: aExpandLaneB, aExpandLaneC, aExpandLaneD
        // cross directions: aExpandLaneB backward forced, aExpandLaneC backward forced, aExpandLaneD backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 5698U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((aIndex + 2504U)) & S_BLOCK1], 28U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1090U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 477U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5145U)) & S_BLOCK1], 14U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 7059U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aIngress, 41U)) + (RotL64(aCross, 11U) ^ RotL64(aPrevious, 28U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = (((aWandererI + RotL64(aIngress, 11U)) + RotL64(aCarry, 51U)) + 12809562813316740345U) + aPhaseHOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aScatter, 28U)) + 17084212535326321199U) + aPhaseHOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 37U)) + RotL64(aCarry, 27U)) + 16074921689983846769U;
            aOrbiterI = ((aWandererB + RotL64(aCross, 3U)) + RotL64(aCarry, 13U)) + 14027986153007120145U;
            aOrbiterC = (aWandererG + RotL64(aScatter, 53U)) + 7633455951809250227U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 340989348513370174U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 5307820377645020116U;
            aOrbiterH = RotL64((aOrbiterH * 8402492604131262157U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 5605285015771527274U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 5293500434746182790U;
            aOrbiterC = RotL64((aOrbiterC * 17674669610895537063U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 7263156475892261811U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 10672879570907433005U;
            aOrbiterG = RotL64((aOrbiterG * 2506338667179450741U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 16659226780900986107U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 9774892622769850665U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7487477727543183211U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 10728057184108279042U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 5032485856947407217U;
            aOrbiterB = RotL64((aOrbiterB * 16651577903809154285U), 47U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterH, 23U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 44U));
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 12U) + RotL64(aOrbiterH, 13U)) + aOrbiterB);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 37U) + aOrbiterG) + RotL64(aOrbiterC, 21U)) + RotL64(aCarry, 53U)) + aPhaseHWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 51U) + aOrbiterB) + RotL64(aOrbiterI, 35U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 21U) + RotL64(aOrbiterC, 57U)) + aOrbiterH) + RotL64(aCarry, 27U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterC, 44U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + RotL64(aWandererE, 52U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 10213U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneB[((aIndex + 8274U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 11384U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9652U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9758U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13953U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 57U)) + (RotL64(aCross, 13U) ^ RotL64(aIngress, 26U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = ((aWandererD + RotL64(aScatter, 14U)) + RotL64(aCarry, 53U)) + 2225397913940961213U;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 5U)) + RotL64(aCarry, 5U)) + 8342544893601343643U;
            aOrbiterC = ((aWandererC + RotL64(aCross, 51U)) + 162922186381417187U) + aPhaseHOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = (((aWandererG + RotL64(aIngress, 27U)) + RotL64(aCarry, 41U)) + 11660218373710972210U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aCross, 43U)) + 14909034764605802354U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 16776955237009701511U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 5834487809188925253U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4458820879204327709U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 1498492772767040320U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 4161765458781579617U;
            aOrbiterJ = RotL64((aOrbiterJ * 15535994410289065281U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 10511923076962447765U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 8575954471692620021U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12526744988828982731U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 6536325446331340573U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 1790628986900286346U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5262997114200816715U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 2623814807619278590U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 11676970995834706612U;
            aOrbiterI = RotL64((aOrbiterI * 10057461115132434901U), 21U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 6U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + RotL64(aOrbiterC, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aCross, 11U) + aOrbiterC) + RotL64(aOrbiterJ, 4U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 56U) + aOrbiterH) + RotL64(aOrbiterA, 51U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterH, 13U)) + aOrbiterI) + RotL64(aCarry, 21U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterJ, 35U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 37U) + RotL64(aOrbiterJ, 23U)) + aOrbiterA) + RotL64(aCarry, 47U)) + aPhaseHWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + RotL64(aWandererD, 35U);
            aCarry = aCarry + RotL64(aIngress, 44U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 19865U)) & S_BLOCK1], 40U) ^ RotL64(aWorkLaneA[((aIndex + 19087U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aExpandLaneD[((aIndex + 23554U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20139U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16858U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 20065U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 26U) ^ RotL64(aIngress, 41U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = (((aWandererG + RotL64(aIngress, 60U)) + RotL64(aCarry, 53U)) + 16160838483846078448U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = ((aWandererC + RotL64(aCross, 13U)) + RotL64(aCarry, 35U)) + 15404960896190227946U;
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 21U)) + RotL64(aCarry, 23U)) + 16904160594024977199U;
            aOrbiterH = (aWandererB + RotL64(aScatter, 47U)) + 17790460246821031802U;
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 29U)) + 16395168254086971959U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 7484373204039901786U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 18026814691322913510U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12688155753775099489U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 15244817793136966450U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 5795491730356335666U;
            aOrbiterC = RotL64((aOrbiterC * 13253529465289332171U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 3163873518027801504U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 2690791759507349172U;
            aOrbiterH = RotL64((aOrbiterH * 16677948635136515083U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 17898067251167087906U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 8028010015006604239U;
            aOrbiterE = RotL64((aOrbiterE * 5601629670521300241U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 7304739457289910555U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 6476837815096530043U;
            aOrbiterK = RotL64((aOrbiterK * 16380545138701113267U), 53U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 23U);
            aIngress = aIngress + (RotL64(aOrbiterB, 34U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 3U)) + aOrbiterC);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 5U) + aOrbiterC) + RotL64(aOrbiterB, 43U)) + RotL64(aCarry, 27U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 21U) + aOrbiterE) + RotL64(aOrbiterH, 27U));
            aWandererC = aWandererC + (((RotL64(aIngress, 50U) + aOrbiterH) + RotL64(aOrbiterK, 11U)) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterK, 56U)) + aOrbiterB) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 25550U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((aIndex + 31665U)) & S_BLOCK1], 46U));
            aIngress ^= RotL64(aWorkLaneA[((aIndex + 27373U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25544U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25530U)) & S_BLOCK1], 60U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 28646U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCross, 3U)) ^ (RotL64(aCarry, 19U) + RotL64(aIngress, 50U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = ((aWandererK + RotL64(aCross, 29U)) + RotL64(aCarry, 11U)) + 12029393034357490020U;
            aOrbiterK = (((aWandererB + RotL64(aScatter, 58U)) + RotL64(aCarry, 23U)) + 4526754731580694987U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = ((aWandererC + RotL64(aIngress, 3U)) + RotL64(aCarry, 39U)) + 17060419646421271853U;
            aOrbiterB = (aWandererE + RotL64(aPrevious, 47U)) + 4128488893837059683U;
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 21U)) + 12706894827547160110U) + aPhaseHOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 12506324593645825056U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 12581344490649250025U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16311882267466003291U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 14357032418199130132U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 15341977701796331249U;
            aOrbiterD = RotL64((aOrbiterD * 6332369248718076031U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 7086602307544733241U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 12398300065276832486U;
            aOrbiterJ = RotL64((aOrbiterJ * 18157408831225635333U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 2499745046076601988U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 7249361592814001829U;
            aOrbiterK = RotL64((aOrbiterK * 14597139848072319685U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 3254456186337366437U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 3472973415969046680U;
            aOrbiterB = RotL64((aOrbiterB * 14583566953969168353U), 3U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 35U);
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterB, 47U)) + aOrbiterI) + RotL64(aCarry, 47U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 21U)) + aOrbiterJ);
            aWandererD = aWandererD + ((((RotL64(aIngress, 44U) + aOrbiterD) + RotL64(aOrbiterK, 3U)) + RotL64(aCarry, 11U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterD, 57U)) + aOrbiterJ);
            aWandererE = aWandererE + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 36U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + RotL64(aWandererB, 34U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
